#if !defined(AFX_SKYSET_H__DB7C4215_D91F_42C6_981B_4C505A36028C__INCLUDED_)
#define AFX_SKYSET_H__DB7C4215_D91F_42C6_981B_4C505A36028C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SkySet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSkySet dialog

class CSkySet : public CDialog
{
// Construction
public:
	CSkySet(CWnd* pParent = NULL);   // standard constructor
	HENHMETAFILE m_hMetaFileColorView;
	virtual BOOL OnInitDialog( );


// Dialog Data
	//{{AFX_DATA(CSkySet)
	enum { IDD = IDD_DIALOG_SKYSET };
	CSliderCtrl	m_SliderTransCtrl;
	CButton	m_CButtonTransparentCtrl;
	CSliderCtrl	m_SliderCountCtrl;
	CSpinButtonCtrl	m_SpinCountCtrl;
	CSliderCtrl	m_SliderBlueCtrl;
	CSliderCtrl	m_SliderGreenCtrl;
	CSliderCtrl	m_SliderRedCtrl;
	CStatic	m_ColorView;
	int		m_SliderRedValue;
	int		m_SliderGreenValue;
	int		m_SliderBlueValue;
	int		m_SliderCountValue;
	UINT	m_EditSizeIncrementValue;
	int		m_nColor;
	int		m_SliderTransValue;
	BOOL	m_PureStyle;
	//}}AFX_DATA


	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkySet)
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	
	// Generated message map functions
	//{{AFX_MSG(CSkySet)
	afx_msg void OnSetSave();
	afx_msg void OnSetCancel();
	afx_msg void OnSetReset();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnCustomdrawSlider(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnColor();
	afx_msg void OnChangeEditCount();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedTransparentPurl();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKYSET_H__DB7C4215_D91F_42C6_981B_4C505A36028C__INCLUDED_)
