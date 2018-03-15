// LineViewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Trs_Book.h"
#include "LineViewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLineViewDlg dialog


CLineViewDlg::CLineViewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLineViewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLineViewDlg)
	m_ViewPhone = _T("");
	m_ViewName = _T("");
	m_ViewMail = _T("");
	m_ViewRemark = _T("");
	m_ViewGroup = _T("");
	//}}AFX_DATA_INIT
}


void CLineViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLineViewDlg)
	DDX_Text(pDX, IDC_EDIT2, m_ViewPhone);
	DDX_Text(pDX, IDC_EDIT1, m_ViewName);
	DDX_Text(pDX, IDC_EDIT3, m_ViewMail);
	DDX_Text(pDX, IDC_EDIT4, m_ViewRemark);
	DDX_Text(pDX, IDC_EDIT5, m_ViewGroup);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLineViewDlg, CDialog)
	//{{AFX_MSG_MAP(CLineViewDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineViewDlg message handlers

void CLineViewDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
