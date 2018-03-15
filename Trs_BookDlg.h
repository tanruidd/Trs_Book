// Trs_BookDlg.h : header file
//

#if !defined(AFX_TRS_BOOKDLG_H__2067A666_7EC2_440E_BB44_C34D8BF6B60E__INCLUDED_)
#define AFX_TRS_BOOKDLG_H__2067A666_7EC2_440E_BB44_C34D8BF6B60E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTrs_BookDlg dialog

class CTrs_BookDlg : public CDialog
{
public:
	struct SContact {
		CString strName;
		CString strPhone;
		CString strMail;
		CString strRemark;
		int strGroup;
		int tot;
	public:
	}People[1000];
	struct Copy {
		int pos[1000];
		int tot;
	}SFind;
	CString Remark[10];
// Construction
public:
	CString ReadBook();
	bool m_Flag;
	CTrs_BookDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTrs_BookDlg)
	enum { IDD = IDD_TRS_BOOK_DIALOG };
	CComboBox	m_FindGroup;
	CListCtrl	m_ListBx;
	CString	m_EditRemark;
	CString	m_FindName;
	CString	m_FindPhone;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrs_BookDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTrs_BookDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnEdit();
	afx_msg void OnLinkView(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFind();
	afx_msg void OnRestor();
	virtual void OnCancel();
	afx_msg void OnBanben();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRS_BOOKDLG_H__2067A666_7EC2_440E_BB44_C34D8BF6B60E__INCLUDED_)
