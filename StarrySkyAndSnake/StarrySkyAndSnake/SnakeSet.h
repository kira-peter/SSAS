#if !defined(AFX_SNAKESET_H__6EE2FB14_1D30_4750_AC25_E93699DAAF28__INCLUDED_)
#define AFX_SNAKESET_H__6EE2FB14_1D30_4750_AC25_E93699DAAF28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SnakeSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSnakeSet dialog

class CSnakeSet : public CDialog
{
	// Construction
public:
	CSnakeSet(CWnd* pParent = NULL);   // standard constructor
	
	// Dialog Data
	//{{AFX_DATA(CSnakeSet)
	enum { IDD = IDD_DIALOG_SNAKESET };
	CButton	m_UnDeadCtrl;
	int		m_difficulty;
	BOOL	m_UnDeadvalue;
	//}}AFX_DATA
	
	
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSnakeSet)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	
	// Generated message map functions
	//{{AFX_MSG(CSnakeSet)
	afx_msg void OnSave();
	afx_msg void OnCancel();
	afx_msg void OnReset();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNAKESET_H__6EE2FB14_1D30_4750_AC25_E93699DAAF28__INCLUDED_)
