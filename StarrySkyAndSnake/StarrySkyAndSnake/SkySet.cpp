// SkySet.cpp : implementation file
//

#include "stdafx.h"
#include "StarrySkyAndSnake.h"
#include "StarrySkyAndSnakeDlg.h"
#include "SkySet.h"
#include "Star.h"
#include ".\skyset.h"

extern CStar Star;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkySet dialog


CSkySet::CSkySet(CWnd* pParent /*=NULL*/)
	: CDialog(CSkySet::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSkySet)
	m_SliderRedValue = 0;
	m_SliderGreenValue = 0;
	m_SliderBlueValue = 0;
	m_SliderCountValue = 0;
	m_EditSizeIncrementValue = 0;
	m_nColor = -1;
	m_SliderTransValue = 0;
	m_PureStyle = FALSE;
	//}}AFX_DATA_INIT
}


void CSkySet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSkySet)
	DDX_Control(pDX, IDC_SLIDER_TRANSPARENT, m_SliderTransCtrl);
	DDX_Control(pDX, IDC_TRANSPARENT, m_CButtonTransparentCtrl);
	DDX_Control(pDX, IDC_SLIDER_COUNT, m_SliderCountCtrl);
	DDX_Control(pDX, IDC_SPIN_COUNT, m_SpinCountCtrl);
	DDX_Control(pDX, IDC_SLIDER_BLUE, m_SliderBlueCtrl);
	DDX_Control(pDX, IDC_SLIDER_GREEN, m_SliderGreenCtrl);
	DDX_Control(pDX, IDC_SLIDER_RED, m_SliderRedCtrl);
	DDX_Control(pDX, IDC_COLORVIEW, m_ColorView);
	DDX_Slider(pDX, IDC_SLIDER_RED, m_SliderRedValue);
	DDX_Slider(pDX, IDC_SLIDER_GREEN, m_SliderGreenValue);
	DDX_Slider(pDX, IDC_SLIDER_BLUE, m_SliderBlueValue);
	DDX_Slider(pDX, IDC_SLIDER_COUNT, m_SliderCountValue);
	DDX_Text(pDX, IDC_EDIT_SIZEINCREMENT, m_EditSizeIncrementValue);
	DDV_MinMaxUInt(pDX, m_EditSizeIncrementValue, 0, 200);
	DDX_Radio(pDX, IDC_RED, m_nColor);
	DDX_Slider(pDX, IDC_SLIDER_TRANSPARENT, m_SliderTransValue);
	DDX_Check(pDX, IDC_TRANSPARENT_PURL, m_PureStyle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSkySet, CDialog)
	//{{AFX_MSG_MAP(CSkySet)
	ON_BN_CLICKED(IDC_SET_SAVE, OnSetSave)
	ON_BN_CLICKED(IDC_SET_CANCEL, OnSetCancel)
	ON_BN_CLICKED(IDC_SET_RESET, OnSetReset)
	ON_WM_CREATE()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_RED, OnCustomdrawSlider)
	ON_BN_CLICKED(IDC_RED, OnColor)
	ON_EN_CHANGE(IDC_EDIT_COUNT, OnChangeEditCount)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_GREEN, OnCustomdrawSlider)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_BLUE, OnCustomdrawSlider)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_COUNT, OnCustomdrawSlider)
	ON_BN_CLICKED(IDC_MULTIPLECOLOR, OnColor)
	ON_BN_CLICKED(IDC_GREEN, OnColor)
	ON_BN_CLICKED(IDC_CUSTOMCOLOR, OnColor)
	ON_BN_CLICKED(IDC_BLUE, OnColor)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER_TRANSPARENT, OnCustomdrawSlider)
//	ON_BN_CLICKED(IDC_TRANSPARENT_PURL, OnCustomdrawSlider)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_TRANSPARENT_PURL, OnBnClickedTransparentPurl)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkySet message handlers

void CSkySet::OnSetSave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	//switch (GetCheckedRadioButton(IDC_RED, IDC_CUSTOMCOLOR))
	switch(m_nColor)
	{
	case 0:
		Star.SetStarStyle(S_RED, IsDlgButtonChecked(IDC_FLASH));
		break;	
	case 1:
		Star.SetStarStyle(S_GREEN, IsDlgButtonChecked(IDC_FLASH));
		break;
	case 2:
		Star.SetStarStyle(S_BLUE, IsDlgButtonChecked(IDC_FLASH));
		break;
	case 3:
		Star.SetStarStyle(S_WHITE, IsDlgButtonChecked(IDC_FLASH));
		break;
	case 4:
		Star.SetStarStyle(S_MULTIPLECOLOR, IsDlgButtonChecked(IDC_FLASH));
		break;
	case 5:
		Star.SetStarStyle(S_CUSTOMCOLOR, IsDlgButtonChecked(IDC_FLASH));
		Star.SetCustomColor(RGB(m_SliderRedValue,m_SliderGreenValue,m_SliderBlueValue));
		break;
	}
	if (m_SliderCountValue == 10000)
	{
		AfxMessageBox("够狠的啊~~~~");
	}
	Star.SetMaxCount(m_SliderCountValue);
	Star.SetSizeIncrement(m_EditSizeIncrementValue);
	if (m_CButtonTransparentCtrl.GetCheck())	{
		Star.SetTransparent(m_SliderTransValue);
		((CStarrySkyAndSnakeDlg*)AfxGetMainWnd())->SetTransparent(m_SliderTransValue);
	}else{
		Star.SetTransparent(0);
		((CStarrySkyAndSnakeDlg*)AfxGetMainWnd())->SetTransparent(255);
	}
	if (m_PureStyle){
		Star.SetPureStyle(m_PureStyle);
		((CStarrySkyAndSnakeDlg*)AfxGetMainWnd())->SetTransparent(m_SliderTransValue, 1);
	}else{
		Star.SetPureStyle(m_PureStyle);
	}
	//EndDialog(0);
	CSkySet::OnOK();
}

BOOL CSkySet::OnInitDialog()
{
	CDialog::OnInitDialog();
	CheckRadioButton(IDC_RED, IDC_CUSTOMCOLOR, Star.GetStarStyle()+1003);
	m_nColor = Star.GetStarStyle();
	if(Star.GetStarStyle() == S_CUSTOMCOLOR){
		m_SliderRedValue = GetRValue(Star.GetCustomColor());
		m_SliderGreenValue = GetGValue(Star.GetCustomColor());
		m_SliderBlueValue = GetBValue(Star.GetCustomColor());
	}else{
		m_SliderRedCtrl.EnableWindow(FALSE);
		m_SliderGreenCtrl.EnableWindow(FALSE);
		m_SliderBlueCtrl.EnableWindow(FALSE);
	}
	m_SliderRedCtrl.SetRange(0, 255, TRUE);
	m_SliderGreenCtrl.SetRange(0, 255, TRUE);
	m_SliderBlueCtrl.SetRange(0, 255, TRUE);
	m_SliderCountCtrl.SetRange(0, 10000, TRUE);
	m_SpinCountCtrl.SetRange(0, 10000);
	m_SliderTransCtrl.SetRange(0,255,TRUE);
	//设置流行个数初始参数
	m_SliderTransValue = Star.GetTransparent();
	if(m_SliderTransValue) 
		m_CButtonTransparentCtrl.SetCheck(BST_CHECKED);
	m_PureStyle = Star.GetPureStyle();
	//设置透明相关设置
	m_SliderCountValue = Star.GetMaxCount();
	m_EditSizeIncrementValue = Star.GetSizeIncrement();
	UpdateData(FALSE);
	return TRUE;
}

void CSkySet::OnSetCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void CSkySet::OnSetReset() 
{
	// TODO: Add your control notification handler code here
	//CheckRadioButton(IDC_RED, IDC_CUSTOMCOLOR, IDC_WHITE);
	m_nColor = 3;
	m_SliderTransValue = Star.GetTransparent();
	if(m_SliderTransValue) 
		m_CButtonTransparentCtrl.SetCheck(BST_CHECKED);
	m_PureStyle = Star.GetPureStyle();
	//设置透明相关设置
	m_SliderCountValue = Star.GetMaxCount();
	m_EditSizeIncrementValue = Star.GetSizeIncrement();
	UpdateData(FALSE);
	//设置流星个数
	m_SpinCountCtrl.SetPos(m_SliderCountValue);

}

int CSkySet::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here
	CMetaFileDC dc;
	dc.CreateEnhanced(NULL, NULL, NULL, NULL);
	CBrush cBrush(Star.GetCustomColor());
	CBrush* pOldBrush = (CBrush*)dc.SelectObject(&cBrush);
	dc.Rectangle(0,0, 2, 2);
	dc.SelectObject(pOldBrush);
	m_hMetaFileColorView = dc.CloseEnhanced();
	return 0;
}

void CSkySet::OnCustomdrawSlider(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CMetaFileDC dc;
	dc.CreateEnhanced(NULL, NULL, NULL, NULL);
	//设置自定义颜色
	UpdateData(TRUE);
	CBrush cBrush(RGB(m_SliderRedValue, m_SliderGreenValue, m_SliderBlueValue));
	CBrush* pOldBrush = (CBrush*)dc.SelectObject(&cBrush);
	dc.Rectangle(0,0, 2, 2);
	dc.SelectObject(pOldBrush);
	m_hMetaFileColorView = dc.CloseEnhanced();
	m_ColorView.SetEnhMetaFile(m_hMetaFileColorView);
	//设置流星个数
	m_SpinCountCtrl.SetPos(m_SliderCountValue);
	*pResult = 0;
	//设置透明度
	if (m_PureStyle){
		Star.SetPureStyle(m_PureStyle);
		((CStarrySkyAndSnakeDlg*)AfxGetMainWnd())->SetTransparent(m_SliderTransValue, 1);
	}else{
		Star.SetPureStyle(m_PureStyle);
		if (m_CButtonTransparentCtrl.GetCheck())	{
			Star.SetTransparent(m_SliderTransValue);
			((CStarrySkyAndSnakeDlg*)AfxGetMainWnd())->SetTransparent(m_SliderTransValue);
		}else{
			Star.SetTransparent(0);
			((CStarrySkyAndSnakeDlg*)AfxGetMainWnd())->SetTransparent(255);
		}
	}
}

void CSkySet::OnColor() 
{
	// TODO: Add your control notification handler code here
	if(((CButton*)GetDlgItem(IDC_CUSTOMCOLOR))->GetCheck()){
		m_SliderRedCtrl.EnableWindow(TRUE);
		m_SliderGreenCtrl.EnableWindow(TRUE);
		m_SliderBlueCtrl.EnableWindow(TRUE);
	}else{
		m_SliderRedCtrl.EnableWindow(FALSE);
		m_SliderGreenCtrl.EnableWindow(FALSE);
		m_SliderBlueCtrl.EnableWindow(FALSE);
	}
}

void CSkySet::OnChangeEditCount() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	if (m_SliderCountCtrl)
	{
		m_SliderCountCtrl.SetPos(m_SpinCountCtrl.GetPos());
	}
}

void CSkySet::OnBnClickedTransparentPurl()
{
	// TODO: Add your control notification handler code here
}
