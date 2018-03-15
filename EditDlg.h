#if !defined(AFX_EDITDLG_H__9B010186_959F_49AF_9B76_C7D7BF469105__INCLUDED_)
#define AFX_EDITDLG_H__9B010186_959F_49AF_9B76_C7D7BF469105__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditDlg dialog

class CEditDlg : public CDialog
{
// Construction
public:
	int m_Group;
	CEditDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditDlg)
	enum { IDD = IDD_DIEDIT };
	CComboBox	m_EditGroup;
	CString	m_EditName;
	CString	m_EditPhone;
	CString	m_EditMail;
	CString	m_EditRemark;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditDlg)
	virtual void OnOK();
	afx_msg void OnChangeEditName();
	afx_msg void OnChangeEditPhone();
	afx_msg void OnChangeEditMail();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITDLG_H__9B010186_959F_49AF_9B76_C7D7BF469105__INCLUDED_)
