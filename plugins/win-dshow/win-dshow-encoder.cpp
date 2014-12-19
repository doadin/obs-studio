#include <obs-module.h>
#include <obs-avc.h>
#include <util/darray.h>
#include <util/dstr.hpp>
#include "libdshowcapture/dshowcapture.hpp"

using namespace DShow;
using namespace std;

struct DShowEncoder {
	obs_encoder_t          *context;
	VideoEncoder           encoder;

	VideoEncoderConfig     config;

	const wchar_t          *device;
	video_format           format;
	long long              frameInterval;

	bool                   first = true;
	DARRAY(uint8_t)        firstPacket;
	DARRAY(uint8_t)        header;

	inline DShowEncoder(obs_encoder_t *context_, const wchar_t *device_)
		: context(context_),
		  device(device_)
	{
		da_init(firstPacket);
		da_init(header);
	}

	inline ~DShowEncoder()
	{
		da_free(firstPacket);
		da_free(header);
	}

	inline void ParseFirstPacket(const uint8_t *data, size_t size);

	inline bool Update(obs_data_t *settings);
	inline bool Encode(struct encoder_frame *frame,
			struct encoder_packet *packet, bool *received_packet);
};

static const char *GetDShowEncoderName(void)
{
	return "DShow Encoder (temp)";
}

static inline void FindDevice(DeviceId &id, const wchar_t *name)
{
	vector<DeviceId> ids;
	DShow::VideoEncoder::EnumEncoders(ids);

	for (const DeviceId &curId : ids) {
		if (curId.name.find(name) != string::npos) {
			id = curId;
			break;
		}
	}
}

inline bool DShowEncoder::Update(obs_data_t *settings)
{
	DStr deviceName;
	DeviceId id;

	FindDevice(id, device);

	video_t *video = obs_encoder_video(context);
	const struct video_output_info *voi = video_output_get_info(video);

	int bitrate            = (int)obs_data_get_int(settings, "bitrate");
	int keyint_sec         = (int)obs_data_get_int(settings, "keyint_sec");
	int width              = (int)obs_encoder_get_width(context);
	int height             = (int)obs_encoder_get_height(context);

	if (keyint_sec == 0)
		keyint_sec = 2;
	if (width > 1280)
		width = 1280;
	if (height > 720)
		height = 720;

	int keyint = keyint_sec * voi->fps_num / voi->fps_den;

	frameInterval = voi->fps_den * 10000000 / voi->fps_num;

	config.fpsNumerator           = voi->fps_num;
	config.fpsDenominator         = voi->fps_den;
	config.bitrate                = bitrate;
	config.keyframeInterval       = keyint;
	config.cx                     = width;
	config.cy                     = height;
	config.name                   = id.name;
	config.path                   = id.path;

	first = true;
	da_resize(firstPacket, 0);
	da_resize(header, 0);

	dstr_from_wcs(deviceName, id.name.c_str());

	DStr encoder_name;
	dstr_from_wcs(encoder_name, config.name.c_str());
	blog(LOG_DEBUG, "win-dshow-encoder:\n"
			"\tencoder: %s\n"
			"\twidth:   %d\n"
			"\theight:  %d\n"
			"\tfps_num: %d\n"
			"\tfps_den: %d",
			deviceName->array,
			(int)width,
			(int)height,
			(int)voi->fps_num,
			(int)voi->fps_den);

	return encoder.SetConfig(config);
}

static bool UpdateDShowEncoder(void *data, obs_data_t *settings)
{
	return reinterpret_cast<DShowEncoder*>(data)->Update(settings);
}

static inline void *CreateDShowEncoder(obs_data_t *settings,
		obs_encoder_t *context, const wchar_t *device)
{
	DShowEncoder *encoder = nullptr;

	try {
		encoder = new DShowEncoder(context, device);
		UpdateDShowEncoder(encoder, settings);

	} catch (const char *error) {
		blog(LOG_ERROR, "Could not create DirectShow encoder '%s': %s",
				obs_encoder_get_name(context), error);
	}

	UNUSED_PARAMETER(settings);
	return encoder;
}

static void *CreateC985Encoder(obs_data_t *settings, obs_encoder_t *context)
{
	return CreateDShowEncoder(settings, context, L"C985");
}

static void *CreateC353Encoder(obs_data_t *settings, obs_encoder_t *context)
{
	return CreateDShowEncoder(settings, context, L"C353");
}

static void DestroyDShowEncoder(void *data)
{
	delete reinterpret_cast<DShowEncoder*>(data);
}

/* the first packet contains the SPS/PPS (header) NALs, so parse the first
 * packet and separate the NALs */
inline void DShowEncoder::ParseFirstPacket(const uint8_t *data, size_t size)
{
	const uint8_t *nal_start, *nal_end, *nal_codestart;
	const uint8_t *end = data + size;
	int type;

	nal_start = obs_avc_find_startcode(data, end);
	nal_end = nullptr;
	while (nal_end != end) {
		nal_codestart = nal_start;

		while (nal_start < end && !*(nal_start++));

		if (nal_start == end)
			break;

		type = nal_start[0] & 0x1F;

		nal_end = obs_avc_find_startcode(nal_start, end);
		if (!nal_end)
			nal_end = end;

		if (type == OBS_NAL_SPS || type == OBS_NAL_PPS) {
			da_push_back_array(header, nal_codestart,
					nal_end - nal_codestart);

		} else {
			da_push_back_array(firstPacket, nal_codestart,
					nal_end - nal_codestart);
		}

		nal_start = nal_end;
	}
}

inline bool DShowEncoder::Encode(struct encoder_frame *frame,
		struct encoder_packet *packet, bool *received_packet)
{
	unsigned char *frame_data[DSHOW_MAX_PLANES] = {};
	size_t frame_sizes[DSHOW_MAX_PLANES] = {};
	EncoderPacket dshowPacket;
	bool new_packet = false;

	/* The encoders expect YV12, so swap the chroma planes for encoding */
	if (format == VIDEO_FORMAT_I420) {
		frame_data[0] = frame->data[0];
		frame_data[1] = frame->data[2];
		frame_data[2] = frame->data[1];
		frame_sizes[0] = frame->linesize[0] * config.cy;
		frame_sizes[1] = frame->linesize[2] * config.cy / 2;
		frame_sizes[2] = frame->linesize[1] * config.cy / 2;
	}

	long long actualPTS = frame->pts * frameInterval;

	bool success = encoder.Encode(frame_data, frame_sizes,
			actualPTS, actualPTS + frameInterval,
			dshowPacket, new_packet);
	if (!success)
		return false;

	if (new_packet && !!dshowPacket.data && !!dshowPacket.size) {
		packet->data     = dshowPacket.data;
		packet->size     = dshowPacket.size;
		packet->type     = OBS_ENCODER_VIDEO;
		packet->pts      = dshowPacket.pts / frameInterval;
		packet->dts      = dshowPacket.dts / frameInterval;
		packet->keyframe = obs_avc_keyframe(packet->data, packet->size);

		/* first packet must be parsed in order to retrieve header */
		if (first) {
			first = false;
			ParseFirstPacket(packet->data, packet->size);
			packet->data = firstPacket.array;
			packet->size = firstPacket.num;
		}

		*received_packet = true;
	}

	return true;
}

static bool DShowEncode(void *data, struct encoder_frame *frame,
		struct encoder_packet *packet, bool *received_packet)
{
	return reinterpret_cast<DShowEncoder*>(data)->Encode(frame, packet,
			received_packet);
}

static bool GetDShowExtraData(void *data, uint8_t **extra_data, size_t *size)
{
	DShowEncoder *encoder = reinterpret_cast<DShowEncoder*>(data);

	*extra_data = encoder->header.array;
	*size = encoder->header.num;

	return *size > 0;
}

static bool GetDShowVideoInfo(void *data, struct video_scale_info *info)
{
	DShowEncoder *encoder = reinterpret_cast<DShowEncoder*>(data);
	video_t *video = obs_encoder_video(encoder->context);
	const struct video_output_info *vid_info = video_output_get_info(video);

	encoder->format = VIDEO_FORMAT_I420;

	if (vid_info->format == VIDEO_FORMAT_I420 &&
	    vid_info->width <= 1280 && vid_info->height <= 720)
		return false;

	info->format     = VIDEO_FORMAT_I420;
	info->width      = vid_info->width;
	info->height     = vid_info->height;
	info->range      = VIDEO_RANGE_DEFAULT;
	info->colorspace = VIDEO_CS_DEFAULT;

	/* these encoders do not support higher resolutions */
	if (info->width > 1280)
		info->width = 1280;
	if (info->height > 720)
		info->height = 720;

	return true;
}

static void GetDShowEncoderDefauts(obs_data_t *settings)
{
	obs_data_set_default_int(settings, "bitrate", 1000);
}

static obs_properties_t *GetDShowEncoderProperties(void *data)
{
	obs_properties_t *ppts = obs_properties_create();

	obs_properties_add_int(ppts, "bitrate", obs_module_text("Bitrate"),
			1000, 60000, 1);

	UNUSED_PARAMETER(data);
	return ppts;
}

void RegisterDShowEncoders()
{
	obs_encoder_info info  = {};
	info.type              = OBS_ENCODER_VIDEO;
	info.codec             = "h264";
	info.get_name          = GetDShowEncoderName;
	info.destroy           = DestroyDShowEncoder;
	info.encode            = DShowEncode;
	info.update            = UpdateDShowEncoder;
	info.get_defaults      = GetDShowEncoderDefauts;
	info.get_properties    = GetDShowEncoderProperties;
	info.get_extra_data    = GetDShowExtraData;
	info.get_video_info    = GetDShowVideoInfo;

	vector<DeviceId> ids;
	DShow::VideoEncoder::EnumEncoders(ids);

	for (const DeviceId &id : ids) {
		if (id.name.find(L"C985") != string::npos) {
			info.id = "dshow_c985_h264";
			info.create = CreateC985Encoder;
			obs_register_encoder(&info);

		} else if (id.name.find(L"C353") != string::npos) {
			info.id = "dshow_c353_h264";
			info.create = CreateC353Encoder;
			obs_register_encoder(&info);
		}
	}
}
