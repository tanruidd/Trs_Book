#if !defined(AFX_LINEVIEWDLG_H__A77ABC6D_10B4_4DBC_9E99_57350541906F__INCLUDED_)
#define AFX_LINEVIEWDLG_H__A77ABC6D_10B4_4DBC_9E99_57350541906F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LineViewDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLineViewDlg dialog

class CLineViewDlg : public CDialog
{
// Construction
public:
	CLineViewDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLineViewDlg)
	enum { IDD = IDD_DILineView };
	CString	m_ViewPhone;
	CString	m_ViewName;
	CString	m_ViewMail;
	CString	m_ViewRemark;
	CString	m_ViewGroup;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineViewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLineViewDlg)
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINEVIEWDLG_H__A77ABC6D_10B4_4DBC_9E99_57350541906F__INCLUDED_)
