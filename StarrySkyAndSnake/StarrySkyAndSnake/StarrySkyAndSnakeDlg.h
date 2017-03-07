// StarrySkyAndSnakeDlg.h : header file
//

#if !defined(AFX_STARRYSKYANDSNAKEDLG_H__EFC90A8B_02D2_4B82_897B_E96D345868F1__INCLUDED_)
#define AFX_STARRYSKYANDSNAKEDLG_H__EFC90A8B_02D2_4B82_897B_E96D345868F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStarrySkyAndSnakeDlg dialog

class CStarrySkyAndSnakeDlg : public CDialog
{
// Construction
public:
	void SetTransparent(BYTE nTrans, int style=2);
	void OnEraseBkgnd(CDC* pDC);
	friend void CALLBACK EXPORT ChangeRgn(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);
	CStarrySkyAndSnakeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStarrySkyAndSnakeDlg)
	enum { IDD = IDD_STARRYSKYANDSNAKE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStarrySkyAndSnakeDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStarrySkyAndSnakeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARRYSKYANDSNAKEDLG_H__EFC90A8B_02D2_4B82_897B_E96D345868F1__INCLUDED_)
