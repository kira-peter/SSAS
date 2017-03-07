// StarrySkyAndSnakeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StarrySkyAndSnake.h"
#include "StarrySkyAndSnakeDlg.h"
#include "Star.h"
#include "Snake.h"
#include "SkySet.h"
#include "SnakeSet.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CStar Star;
CSnake Snake;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStarrySkyAndSnakeDlg dialog

CStarrySkyAndSnakeDlg::CStarrySkyAndSnakeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStarrySkyAndSnakeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStarrySkyAndSnakeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStarrySkyAndSnakeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStarrySkyAndSnakeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStarrySkyAndSnakeDlg, CDialog)
	//{{AFX_MSG_MAP(CStarrySkyAndSnakeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStarrySkyAndSnakeDlg message handlers

BOOL CStarrySkyAndSnakeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	MoveWindow(0,0,GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	Snake.SetpWnd(this);
	Snake.InitSanke();
	SetTimer(2, 1, ChangeRgn);
	((CStarrySkyAndSnakeDlg*)AfxGetMainWnd())->SetTransparent(222);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStarrySkyAndSnakeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStarrySkyAndSnakeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStarrySkyAndSnakeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CALLBACK EXPORT ChangeRgn(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	CWindowDC dc(AfxGetMainWnd());
	((CStarrySkyAndSnakeDlg*)AfxGetMainWnd())->OnEraseBkgnd(&dc);
	CRgn rgn1, rgn2, rgn3;
	CRect rect;
	AfxGetMainWnd()->GetWindowRect( &rect);
	int x = rect.right/2;
	int y = rect.bottom/2;
	static int radius = 0;
	rgn1.CreateEllipticRgn(x - radius, y - radius, x +radius, y + radius);
	radius += 40;
	AfxGetMainWnd()->SetWindowRgn(rgn1, TRUE);
	if (radius > 900)
	{
		KillTimer(AfxGetApp()->m_pMainWnd->m_hWnd, 2);
		Star.SetTransparent(222);
		((CStarrySkyAndSnakeDlg*)AfxGetMainWnd())->SetTransparent(222);
		((CStarrySkyAndSnakeDlg*)AfxGetMainWnd())->SetTimer(1, 100, NULL);
	}
}

void CStarrySkyAndSnakeDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CWindowDC dc(this);
	OnEraseBkgnd(&dc);
	Star.Show();
	Snake.Move(&dc);
	CDialog::OnTimer(nIDEvent);
}

void CStarrySkyAndSnakeDlg::OnEraseBkgnd(CDC *pDC)
{
	CBrush *pOldBrush = (CBrush*)pDC->SelectStockObject(BLACK_BRUSH);
	CPen *pOldPen = (CPen*)pDC->SelectStockObject(BLACK_PEN);
	RECT rect;
	GetWindowRect(&rect);
	pDC->Rectangle(0, 0, rect.right, rect.bottom);
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CStarrySkyAndSnakeDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu menu;
	menu.CreateMenu();
	CMenu menupopup;
	menupopup.CreatePopupMenu();
	menu.AppendMenu(MF_POPUP,(UINT)menupopup.m_hMenu, "右键菜单");
	menupopup.AppendMenu(MF_STRING, 1001, "星空设置");
	menupopup.AppendMenu(MF_STRING, 1002, "游戏设置");
	menupopup.AppendMenu(MF_STRING, 1003, "开始游戏");
	TrackPopupMenu(menupopup.m_hMenu, MF_POPUP, point.x, point.y, NULL, pWnd->m_hWnd, NULL);
}

BOOL CStarrySkyAndSnakeDlg::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	//wParam 
	//	The low-order word of wParam identifies the command ID of the menu item, control, or accelerator. 
	//	The high-order word of wParam specifies the notification message if the message is from a control. 
	//	If the message is from an accelerator, the high-order word is 1. 
	//	If the message is from a menu, the high-order word is 0. 
	//lParam 
	//	Identifies the control that sends the message if the message is from a control. Otherwise, lParam is 0. 
	
	if(HIWORD(wParam) == 0){
		switch(LOWORD(wParam)){
		case 1001:
			{
				CSkySet SkySet;
				SkySet.DoModal();
			}
			break;
		case 1002:
			{
				CSnakeSet SnakeSet;
				SnakeSet.DoModal();
			}	
			break;
		case 1003:
			Snake.GameStart();
			break;
		}
	}
	return CDialog::OnCommand(wParam, lParam);
}


BOOL CStarrySkyAndSnakeDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN){
		Snake.Veer(pMsg->wParam);
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CStarrySkyAndSnakeDlg::SetTransparent(BYTE nTrans, int style)
{
	SetWindowLong(GetSafeHwnd(), GWL_EXSTYLE, GetWindowLong(GetSafeHwnd(), GWL_EXSTYLE)|0x80000);
	typedef BOOL (WINAPI *FSetLayeredWindowAttributes)(HWND, COLORREF, BYTE, DWORD);
	HINSTANCE hInst = LoadLibrary("User32.DLL");
	FSetLayeredWindowAttributes SetLayeredWindowAttributes;
	SetLayeredWindowAttributes = (FSetLayeredWindowAttributes)GetProcAddress(hInst, "SetLayeredWindowAttributes");
	if(SetLayeredWindowAttributes){
		SetLayeredWindowAttributes(GetSafeHwnd(), RGB(0,0,0), nTrans, style);
	}
	FreeLibrary(hInst);
}
