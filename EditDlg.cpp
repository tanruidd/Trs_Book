// EditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Trs_Book.h"
#include "EditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditDlg dialog


CEditDlg::CEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditDlg)
	m_EditName = _T("");
	m_EditPhone = _T("");
	m_EditMail = _T("");
	m_EditRemark = _T("");
	//}}AFX_DATA_INIT
}


void CEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditDlg)
	DDX_Control(pDX, IDC_COMBO1, m_EditGroup);
	DDX_Text(pDX, IDC_EDIT1, m_EditName);
	DDX_Text(pDX, IDC_EDIT2, m_EditPhone);
	DDX_Text(pDX, IDC_EDIT3, m_EditMail);
	DDX_Text(pDX, IDC_EDIT4, m_EditRemark);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditDlg, CDialog)
	//{{AFX_MSG_MAP(CEditDlg)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEditName)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEditPhone)
	ON_EN_CHANGE(IDC_EDIT3, OnChangeEditMail)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditDlg message handlers

void CEditDlg::OnOK() 
{
	// TODO: Add extra validation here
	m_Group = m_EditGroup.GetCurSel();
	CDialog::OnOK();
}

void CEditDlg::OnChangeEditName() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnChangeEditPhone() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CEditDlg::OnChangeEditMail() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

BOOL CEditDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_EditGroup.SetCurSel(m_Group - 1);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
