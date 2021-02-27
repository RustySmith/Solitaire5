
// Solitaire.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "Solitaire.h"
#include "Board.h"

#include "SaveRestore.h"
#include "Card.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// SolitaireApp

BEGIN_MESSAGE_MAP(SolitaireApp, CWinAppEx)
	//_COMMAND(ID_APP_ABOUT, &SolitaireApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
END_MESSAGE_MAP()


// SolitaireApp construction

SolitaireApp::SolitaireApp() noexcept
{
	m_bHiColorIcons = TRUE;

	// Recommended format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("Rusty Smith.Solitaire.NoVersion"));

}

// The one and only SolitaireApp object

SolitaireApp theApp;


// SolitaireApp initialization

BOOL SolitaireApp::InitInstance()
{
	CWinAppEx::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// Standard initialization
	SetRegistryKey(_T("Rusty Smith"));
	//adStdProfileSettings(4);  // Load standard INI file options (including MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(SaveRestore),
		RUNTIME_CLASS(Board),       // main SDI frame window
		RUNTIME_CLASS(Card));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

// SolitaireApp message handlers


//// CAboutDlg dialog used for App About
//
//class CAboutDlg : public CDialogEx
//{
//public:
//	CAboutDlg() noexcept;
//
//// Dialog Data
//#ifdef AFX_DESIGN_TIME
//	enum { IDD = IDD_ABOUTBOX };
//#endif
//
//protected:
//	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//
//// Implementation
//protected:
//	DECLARE_MESSAGE_MAP()
//};
//
//CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
//{
//}
//
//void CAboutDlg::DoDataExchange(CDataExchange* pDX)
//{
//	CDialogEx::DoDataExchange(pDX);
//}
//
//BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//END_MESSAGE_MAP()
//
//// App command to run the dialog
//void SolitaireApp::OnAppAbout()
//{
//	CAboutDlg aboutDlg;
//	aboutDlg.DoModal();
//}

// SolitaireApp customization load/save methods

void SolitaireApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void SolitaireApp::LoadCustomState()
{
}

void SolitaireApp::SaveCustomState()
{
}

// SolitaireApp message handlers



