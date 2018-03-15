#if !defined(AFX_ADDDLG_H__1BA27AAE_C082_4866_95C3_B41387442033__INCLUDED_)
#define AFX_ADDDLG_H__1BA27AAE_C082_4866_95C3_B41387442033__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddDlg dialog

class CAddDlg : public CDialog
{
// Construction
public:
	int m_CGroup;
	CAddDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddDlg)
	enum { IDD = IDD_DIADD };
	CComboBox	m_CNewGroup;
	CString	m_CNewName;
	CString	m_CNewPhone;
	CString	m_CNewMail;
	CString	m_AddRemark;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddDlg)
	virtual void OnOK();
	afx_msg void OnEditName();
	afx_msg void OnEditPhone();
	afx_msg void OnADDMail();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDLG_H__1BA27AAE_C082_4866_95C3_B41387442033__INCLUDED_)
