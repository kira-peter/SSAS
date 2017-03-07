// SnakeSet.cpp : implementation file
//

#include "stdafx.h"
#include "StarrySkyAndSnake.h"
#include "SnakeSet.h"
#include "Snake.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CSnake Snake;
/////////////////////////////////////////////////////////////////////////////
// CSnakeSet dialog


CSnakeSet::CSnakeSet(CWnd* pParent /*=NULL*/)
: CDialog(CSnakeSet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSnakeSet)
	m_difficulty = -1;
	m_UnDeadvalue = FALSE;
	//}}AFX_DATA_INIT
}


void CSnakeSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSnakeSet)
	DDX_Control(pDX, IDC_UNDEAD, m_UnDeadCtrl);
	DDX_Radio(pDX, IDC_EASY, m_difficulty);
	DDX_Check(pDX, IDC_UNDEAD, m_UnDeadvalue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSnakeSet, CDialog)
//{{AFX_MSG_MAP(CSnakeSet)
ON_BN_CLICKED(IDC_SAVE, OnSave)
ON_BN_CLICKED(IDC_RESET, OnReset)
ON_BN_CLICKED(IDC_CANCEL, OnCancel)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnakeSet message handlers

void CSnakeSet::OnSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	Snake.SetGameDifficulty(m_difficulty);
	Snake.SetUnDead(m_UnDeadvalue);
	CDialog::OnOK();
}

void CSnakeSet::OnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void CSnakeSet::OnReset() 
{
	// TODO: Add your control notification handler code here
	CheckRadioButton(IDC_EASY, IDC_HARD, IDC_NORMAL);
}

BOOL CSnakeSet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CheckRadioButton(IDC_EASY, IDC_HARD, Snake.GetGameDifficulty()+1019);
	CheckDlgButton(IDC_UNDEAD, Snake.GetUndead());
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
