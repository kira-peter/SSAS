// StarrySkyAndSnake.h : main header file for the STARRYSKYANDSNAKE application
//

#if !defined(AFX_STARRYSKYANDSNAKE_H__D1A27AC3_7D5C_4F6B_B294_775AEF206042__INCLUDED_)
#define AFX_STARRYSKYANDSNAKE_H__D1A27AC3_7D5C_4F6B_B294_775AEF206042__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStarrySkyAndSnakeApp:
// See StarrySkyAndSnake.cpp for the implementation of this class
//

class CStarrySkyAndSnakeApp : public CWinApp
{
public:
	CStarrySkyAndSnakeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStarrySkyAndSnakeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStarrySkyAndSnakeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARRYSKYANDSNAKE_H__D1A27AC3_7D5C_4F6B_B294_775AEF206042__INCLUDED_)
