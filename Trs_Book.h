// Trs_Book.h : main header file for the TRS_BOOK application
//

#if !defined(AFX_TRS_BOOK_H__A430D390_9AAE_470A_BE81_CAE3F0DC2C44__INCLUDED_)
#define AFX_TRS_BOOK_H__A430D390_9AAE_470A_BE81_CAE3F0DC2C44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTrs_BookApp:
// See Trs_Book.cpp for the implementation of this class
//

class CTrs_BookApp : public CWinApp
{
public:
	CTrs_BookApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrs_BookApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTrs_BookApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRS_BOOK_H__A430D390_9AAE_470A_BE81_CAE3F0DC2C44__INCLUDED_)
