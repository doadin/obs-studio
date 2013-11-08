///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct  8 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "OBSWindows.h"

#include "res/delete.ico.h"
#include "res/down.ico.h"
#include "res/htmledit_icon22_properties.gif.h"
#include "res/list_add.png.h"
#include "res/up.ico.h"

///////////////////////////////////////////////////////////////////////////

OBSBasicBase::OBSBasicBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetFont( wxFont( 8, 70, 90, 90, false, wxT("Tahoma") ) );
	
	mainMenu = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* file_new;
	file_new = new wxMenuItem( fileMenu, ID_FILE_NEW, wxString( _("MainMenu.File.New") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( file_new );
	
	wxMenuItem* file_open;
	file_open = new wxMenuItem( fileMenu, IF_FILE_OPEN, wxString( _("MainMenu.File.Open") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( file_open );
	
	wxMenuItem* file_save;
	file_save = new wxMenuItem( fileMenu, IF_FILE_SAVE, wxString( _("MainMenu.File.Save") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( file_save );
	
	fileMenu->AppendSeparator();
	
	wxMenuItem* file_exit;
	file_exit = new wxMenuItem( fileMenu, ID_FILE_EXIT, wxString( _("MainMenu.File.Exit") ) , wxEmptyString, wxITEM_NORMAL );
	fileMenu->Append( file_exit );
	
	mainMenu->Append( fileMenu, _("MainMenu.File") ); 
	
	this->SetMenuBar( mainMenu );
	
	wxBoxSizer* mainContainer;
	mainContainer = new wxBoxSizer( wxVERTICAL );
	
	mainPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* panelContainer;
	panelContainer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* topContainer;
	topContainer = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* previewContainer;
	previewContainer = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );
	
	previewPanel = new wxPanel( mainPanel, ID_PROGRAM, wxDefaultPosition, wxSize( 480,270 ), wxTAB_TRAVERSAL );
	previewPanel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	bSizer35->Add( previewPanel, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	previewContainer->Add( bSizer35, 1, wxEXPAND, 5 );
	
	
	topContainer->Add( previewContainer, 1, wxALIGN_CENTER, 5 );
	
	
	panelContainer->Add( topContainer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bottomContainer;
	bottomContainer = new wxBoxSizer( wxVERTICAL );
	
	bottomContainer->SetMinSize( wxSize( -1,155 ) ); 
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bottomCenterContainer;
	bottomCenterContainer = new wxBoxSizer( wxHORIZONTAL );
	
	bottomCenterContainer->SetMinSize( wxSize( 625,-1 ) ); 
	wxBoxSizer* scenesContainer;
	scenesContainer = new wxBoxSizer( wxVERTICAL );
	
	scenesLabel = new wxStaticText( mainPanel, wxID_ANY, _("MainWindow.Scenes"), wxDefaultPosition, wxDefaultSize, 0 );
	scenesLabel->Wrap( -1 );
	scenesContainer->Add( scenesLabel, 0, wxALL|wxEXPAND, 2 );
	
	scenesPanel = new wxPanel( mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER );
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	scenes = new wxListBox( scenesPanel, ID_SCENES, wxDefaultPosition, wxDefaultSize, 0, NULL, 0|wxNO_BORDER ); 
	bSizer16->Add( scenes, 1, wxALL|wxEXPAND, 0 );
	
	scenesToolbar = new wxToolBar( scenesPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL ); 
	scenesToolbar->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	scenesToolbar->AddTool( ID_SCENE_ADD, _("tool"), list_add_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	scenesToolbar->AddTool( ID_SCENE_DELETE, _("tool"), delete_ico_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	scenesToolbar->AddTool( ID_SCENE_PROPERTIES, _("tool"), htmledit_icon22_properties_gif_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	scenesToolbar->AddSeparator(); 
	
	scenesToolbar->AddSeparator(); 
	
	scenesToolbar->AddTool( ID_SCENE_MOVEUP, _("tool"), up_ico_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	scenesToolbar->AddTool( ID_SCENE_MOVEDOWN, _("tool"), down_ico_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	scenesToolbar->Realize(); 
	
	bSizer16->Add( scenesToolbar, 0, wxEXPAND, 5 );
	
	
	scenesPanel->SetSizer( bSizer16 );
	scenesPanel->Layout();
	bSizer16->Fit( scenesPanel );
	scenesContainer->Add( scenesPanel, 1, wxEXPAND | wxALL, 2 );
	
	
	bottomCenterContainer->Add( scenesContainer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* sourcesContainer;
	sourcesContainer = new wxBoxSizer( wxVERTICAL );
	
	sourcesLabel = new wxStaticText( mainPanel, wxID_ANY, _("MainWindow.Sources"), wxDefaultPosition, wxDefaultSize, 0 );
	sourcesLabel->Wrap( -1 );
	sourcesContainer->Add( sourcesLabel, 0, wxALL|wxEXPAND, 2 );
	
	sourcesPanel = new wxPanel( mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER );
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	wxArrayString sourcesChoices;
	sources = new wxCheckListBox( sourcesPanel, ID_SOURCES, wxDefaultPosition, wxDefaultSize, sourcesChoices, 0|wxNO_BORDER );
	bSizer17->Add( sources, 1, wxALL, 0 );
	
	sourcesToolbar = new wxToolBar( sourcesPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL ); 
	sourcesToolbar->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	sourcesToolbar->AddTool( ID_SOURCE_ADD, _("tool"), list_add_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	sourcesToolbar->AddTool( ID_SOURCE_DELETE, _("tool"), delete_ico_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	sourcesToolbar->AddTool( ID_SOURCE_PROPERTIES, _("tool"), htmledit_icon22_properties_gif_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	sourcesToolbar->AddSeparator(); 
	
	sourcesToolbar->AddSeparator(); 
	
	sourcesToolbar->AddTool( ID_SOURCE_MOVEUP, _("tool"), up_ico_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	sourcesToolbar->AddTool( ID_SOURCE_MOVEDOWN, _("tool"), down_ico_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	sourcesToolbar->Realize(); 
	
	bSizer17->Add( sourcesToolbar, 0, wxEXPAND, 5 );
	
	
	sourcesPanel->SetSizer( bSizer17 );
	sourcesPanel->Layout();
	bSizer17->Fit( sourcesPanel );
	sourcesContainer->Add( sourcesPanel, 1, wxEXPAND | wxALL, 2 );
	
	
	bottomCenterContainer->Add( sourcesContainer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* leftButtonsContainer;
	leftButtonsContainer = new wxBoxSizer( wxVERTICAL );
	
	positionSizeButton = new wxButton( mainPanel, ID_SETPOSSIZE, _("MainWindow.SetPosSize"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	leftButtonsContainer->Add( positionSizeButton, 0, wxALL|wxEXPAND, 2 );
	
	cropButton = new wxButton( mainPanel, ID_CROP, _("MainWindow.Crop"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	leftButtonsContainer->Add( cropButton, 0, wxALL|wxEXPAND, 2 );
	
	lockPreview = new wxCheckBox( mainPanel, ID_LOCK, _("MainWindow.Lock"), wxDefaultPosition, wxDefaultSize, 0 );
	lockPreview->SetValue(true); 
	leftButtonsContainer->Add( lockPreview, 0, wxALL|wxEXPAND, 5 );
	
	enablePreview = new wxCheckBox( mainPanel, ID_PREVIEW, _("MainWindow.Preview"), wxDefaultPosition, wxDefaultSize, 0 );
	enablePreview->SetValue(true); 
	leftButtonsContainer->Add( enablePreview, 0, wxALL, 5 );
	
	
	bottomCenterContainer->Add( leftButtonsContainer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* rightButtonsContainer;
	rightButtonsContainer = new wxBoxSizer( wxVERTICAL );
	
	toggleStream = new wxButton( mainPanel, ID_STARTSTREAM, _("MainWindow.StartStream"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	rightButtonsContainer->Add( toggleStream, 0, wxALL|wxEXPAND, 2 );
	
	TogglePreview = new wxButton( mainPanel, ID_RECORD, _("MainWindow.Record"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	rightButtonsContainer->Add( TogglePreview, 0, wxALL|wxEXPAND, 2 );
	
	settingsButton = new wxButton( mainPanel, ID_SETTINGS, _("MainWindow.Settings"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	rightButtonsContainer->Add( settingsButton, 0, wxALL|wxEXPAND, 2 );
	
	exitButton = new wxButton( mainPanel, ID_EXIT, _("MainWindow.Exit"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	rightButtonsContainer->Add( exitButton, 0, wxALL|wxEXPAND, 2 );
	
	
	bottomCenterContainer->Add( rightButtonsContainer, 1, wxEXPAND, 5 );
	
	
	bSizer36->Add( bottomCenterContainer, 1, wxALIGN_CENTER, 5 );
	
	
	bottomContainer->Add( bSizer36, 1, wxALIGN_CENTER|wxEXPAND, 5 );
	
	
	panelContainer->Add( bottomContainer, 0, wxEXPAND, 5 );
	
	
	mainPanel->SetSizer( panelContainer );
	mainPanel->Layout();
	panelContainer->Fit( mainPanel );
	mainContainer->Add( mainPanel, 1, wxEXPAND | wxALL, 0 );
	
	
	this->SetSizer( mainContainer );
	this->Layout();
	statusBar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( file_new->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OBSBasicBase::file_newOnMenuSelection ) );
	this->Connect( file_open->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OBSBasicBase::file_openOnMenuSelection ) );
	this->Connect( file_save->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OBSBasicBase::file_saveOnMenuSelection ) );
	this->Connect( file_exit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OBSBasicBase::file_exitOnMenuSelection ) );
	scenes->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( OBSBasicBase::scenesOnRightDown ), NULL, this );
	this->Connect( ID_SCENE_ADD, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sceneAddOnToolClicked ) );
	this->Connect( ID_SCENE_DELETE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sceneRemoveOnToolClicked ) );
	this->Connect( ID_SCENE_PROPERTIES, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::scenePropertiesOnToolClicked ) );
	this->Connect( ID_SCENE_MOVEUP, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sceneUpOnToolClicked ) );
	this->Connect( ID_SCENE_MOVEDOWN, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sceneDownOnToolClicked ) );
	sources->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( OBSBasicBase::sourcesOnRightDown ), NULL, this );
	this->Connect( ID_SOURCE_ADD, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sourceAddOnToolClicked ) );
	this->Connect( ID_SOURCE_DELETE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sourceRemoveOnToolClicked ) );
	this->Connect( ID_SOURCE_PROPERTIES, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sourcePropertiesOnToolClicked ) );
	this->Connect( ID_SOURCE_MOVEUP, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sourceUpOnToolClicked ) );
	this->Connect( ID_SOURCE_MOVEDOWN, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sourceDownOnToolClicked ) );
}

OBSBasicBase::~OBSBasicBase()
{
	// Disconnect Events
	this->Disconnect( ID_FILE_NEW, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OBSBasicBase::file_newOnMenuSelection ) );
	this->Disconnect( IF_FILE_OPEN, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OBSBasicBase::file_openOnMenuSelection ) );
	this->Disconnect( IF_FILE_SAVE, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OBSBasicBase::file_saveOnMenuSelection ) );
	this->Disconnect( ID_FILE_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( OBSBasicBase::file_exitOnMenuSelection ) );
	scenes->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( OBSBasicBase::scenesOnRightDown ), NULL, this );
	this->Disconnect( ID_SCENE_ADD, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sceneAddOnToolClicked ) );
	this->Disconnect( ID_SCENE_DELETE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sceneRemoveOnToolClicked ) );
	this->Disconnect( ID_SCENE_PROPERTIES, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::scenePropertiesOnToolClicked ) );
	this->Disconnect( ID_SCENE_MOVEUP, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sceneUpOnToolClicked ) );
	this->Disconnect( ID_SCENE_MOVEDOWN, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sceneDownOnToolClicked ) );
	sources->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( OBSBasicBase::sourcesOnRightDown ), NULL, this );
	this->Disconnect( ID_SOURCE_ADD, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sourceAddOnToolClicked ) );
	this->Disconnect( ID_SOURCE_DELETE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sourceRemoveOnToolClicked ) );
	this->Disconnect( ID_SOURCE_PROPERTIES, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sourcePropertiesOnToolClicked ) );
	this->Disconnect( ID_SOURCE_MOVEUP, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sourceUpOnToolClicked ) );
	this->Disconnect( ID_SOURCE_MOVEDOWN, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( OBSBasicBase::sourceDownOnToolClicked ) );
	
}

OBSStudioBase::OBSStudioBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 900,400 ), wxDefaultSize );
	this->SetFont( wxFont( 8, 70, 90, 90, false, wxT("Tahoma") ) );
	
	wxBoxSizer* clientSIzer;
	clientSIzer = new wxBoxSizer( wxVERTICAL );
	
	mainPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* mainSizer;
	mainSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* topSizer;
	topSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer191;
	bSizer191 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText6 = new wxStaticText( mainPanel, wxID_ANY, _("MainWindow.Preview"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer191->Add( m_staticText6, 0, wxALL, 3 );
	
	m_panel2 = new wxPanel( mainPanel, wxID_ANY, wxDefaultPosition, wxSize( 480,270 ), wxTAB_TRAVERSAL );
	m_panel2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	bSizer191->Add( m_panel2, 0, wxALIGN_CENTER|wxALL, 3 );
	
	
	bSizer33->Add( bSizer191, 0, wxALIGN_CENTER, 0 );
	
	
	bSizer8->Add( bSizer33, 0, wxALIGN_CENTER|wxEXPAND, 5 );
	
	
	bSizer5->Add( bSizer8, 1, wxALIGN_CENTER, 5 );
	
	
	topSizer->Add( bSizer5, 1, wxEXPAND, 5 );
	
	transitionContainer = new wxBoxSizer( wxVERTICAL );
	
	m_button7 = new wxButton( mainPanel, wxID_ANY, _("MainWindow.Cut"), wxDefaultPosition, wxDefaultSize, 0 );
	transitionContainer->Add( m_button7, 0, wxALL, 5 );
	
	
	topSizer->Add( transitionContainer, 0, wxALIGN_CENTER, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer201;
	bSizer201 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText7 = new wxStaticText( mainPanel, wxID_ANY, _("MainWindow.Program"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer201->Add( m_staticText7, 0, wxALL, 3 );
	
	m_panel3 = new wxPanel( mainPanel, wxID_ANY, wxDefaultPosition, wxSize( 480,270 ), wxTAB_TRAVERSAL );
	m_panel3->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	bSizer201->Add( m_panel3, 0, wxALIGN_CENTER|wxALL, 3 );
	
	
	bSizer34->Add( bSizer201, 0, wxALIGN_CENTER, 0 );
	
	
	bSizer13->Add( bSizer34, 0, wxALIGN_CENTER|wxEXPAND, 5 );
	
	
	bSizer6->Add( bSizer13, 1, wxALIGN_CENTER, 5 );
	
	
	topSizer->Add( bSizer6, 1, wxEXPAND, 5 );
	
	
	mainSizer->Add( topSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bottomSizer;
	bottomSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );
	
	bSizer20->SetMinSize( wxSize( 900,170 ) ); 
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText1 = new wxStaticText( mainPanel, wxID_ANY, _("MainWindow.Channels"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer16->Add( m_staticText1, 0, wxALL, 3 );
	
	m_panel13 = new wxPanel( mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER );
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxVERTICAL );
	
	m_listBox1 = new wxListBox( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0|wxNO_BORDER ); 
	bSizer38->Add( m_listBox1, 1, wxEXPAND, 0 );
	
	m_toolBar1 = new wxToolBar( m_panel13, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER ); 
	m_toolBar1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	m_toolBar1->AddTool( wxID_ANY, _("tool"), list_add_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( wxID_ANY, _("tool"), delete_ico_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBar1->AddSeparator(); 
	
	m_toolBar1->AddSeparator(); 
	
	m_toolBar1->AddTool( wxID_ANY, _("tool"), up_ico_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBar1->AddTool( wxID_ANY, _("tool"), down_ico_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBar1->Realize(); 
	
	bSizer38->Add( m_toolBar1, 0, wxEXPAND, 0 );
	
	
	m_panel13->SetSizer( bSizer38 );
	m_panel13->Layout();
	bSizer38->Fit( m_panel13 );
	bSizer16->Add( m_panel13, 1, wxEXPAND | wxALL, 2 );
	
	
	bSizer20->Add( bSizer16, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText2 = new wxStaticText( mainPanel, wxID_ANY, _("MainWindow.Scenes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer17->Add( m_staticText2, 0, wxALL, 3 );
	
	m_panel12 = new wxPanel( mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER );
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxVERTICAL );
	
	m_listBox2 = new wxListBox( m_panel12, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0|wxNO_BORDER ); 
	bSizer37->Add( m_listBox2, 1, wxALL|wxEXPAND, 0 );
	
	m_toolBar11 = new wxToolBar( m_panel12, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER ); 
	m_toolBar11->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	m_toolBar11->AddTool( wxID_ANY, _("tool"), list_add_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBar11->AddTool( wxID_ANY, _("tool"), delete_ico_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBar11->AddTool( wxID_ANY, _("tool"), htmledit_icon22_properties_gif_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBar11->AddSeparator(); 
	
	m_toolBar11->AddSeparator(); 
	
	m_toolBar11->Realize(); 
	
	bSizer37->Add( m_toolBar11, 0, wxEXPAND, 5 );
	
	
	m_panel12->SetSizer( bSizer37 );
	m_panel12->Layout();
	bSizer37->Fit( m_panel12 );
	bSizer17->Add( m_panel12, 1, wxEXPAND | wxALL, 2 );
	
	
	bSizer20->Add( bSizer17, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText3 = new wxStaticText( mainPanel, wxID_ANY, _("MainWindow.Sources"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer18->Add( m_staticText3, 0, wxALL, 3 );
	
	m_panel14 = new wxPanel( mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER );
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxVERTICAL );
	
	wxArrayString m_checkList1Choices;
	m_checkList1 = new wxCheckListBox( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_checkList1Choices, 0|wxNO_BORDER );
	bSizer39->Add( m_checkList1, 1, wxALL|wxEXPAND, 0 );
	
	m_toolBar12 = new wxToolBar( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER ); 
	m_toolBar12->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	m_toolBar12->AddTool( wxID_ANY, _("tool"), list_add_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBar12->AddTool( wxID_ANY, _("tool"), delete_ico_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBar12->AddTool( wxID_ANY, _("tool"), htmledit_icon22_properties_gif_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBar12->AddSeparator(); 
	
	m_toolBar12->AddSeparator(); 
	
	m_toolBar12->AddTool( wxID_ANY, _("tool"), up_ico_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBar12->AddTool( wxID_ANY, _("tool"), down_ico_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBar12->Realize(); 
	
	bSizer39->Add( m_toolBar12, 0, wxEXPAND, 5 );
	
	
	m_panel14->SetSizer( bSizer39 );
	m_panel14->Layout();
	bSizer39->Fit( m_panel14 );
	bSizer18->Add( m_panel14, 1, wxEXPAND | wxALL, 2 );
	
	
	bSizer20->Add( bSizer18, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText4 = new wxStaticText( mainPanel, wxID_ANY, _("MainWindow.Streams"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer19->Add( m_staticText4, 0, wxALL, 3 );
	
	m_panel15 = new wxPanel( mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER );
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxVERTICAL );
	
	m_listCtrl1 = new wxListCtrl( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL|wxNO_BORDER );
	m_listCtrl1->SetMinSize( wxSize( 400,-1 ) );
	
	bSizer40->Add( m_listCtrl1, 1, wxEXPAND|wxTOP|wxBOTTOM|wxLEFT, 0 );
	
	m_toolBar13 = new wxToolBar( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER ); 
	m_toolBar13->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	m_toolBar13->AddTool( wxID_ANY, _("tool"), list_add_png_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBar13->AddTool( wxID_ANY, _("tool"), delete_ico_to_wx_bitmap(), wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	m_toolBar13->AddSeparator(); 
	
	m_toolBar13->AddSeparator(); 
	
	m_toolBar13->Realize(); 
	
	bSizer40->Add( m_toolBar13, 0, wxEXPAND, 5 );
	
	
	m_panel15->SetSizer( bSizer40 );
	m_panel15->Layout();
	bSizer40->Fit( m_panel15 );
	bSizer19->Add( m_panel15, 1, wxEXPAND | wxALL, 2 );
	
	
	bSizer20->Add( bSizer19, 0, wxEXPAND, 5 );
	
	
	bottomSizer->Add( bSizer20, 0, wxALIGN_CENTER, 5 );
	
	
	mainSizer->Add( bottomSizer, 0, wxEXPAND, 5 );
	
	
	mainPanel->SetSizer( mainSizer );
	mainPanel->Layout();
	mainSizer->Fit( mainPanel );
	clientSIzer->Add( mainPanel, 1, wxEXPAND, 0 );
	
	
	this->SetSizer( clientSIzer );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( m_menu1, wxID_ANY, wxString( _("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem1 );
	
	m_menubar1->Append( m_menu1, _("MainMenu.File") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
}

OBSStudioBase::~OBSStudioBase()
{
}