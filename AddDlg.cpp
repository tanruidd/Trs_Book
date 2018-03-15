// AddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Trs_Book.h"
#include "AddDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddDlg dialog

CAddDlg::CAddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddDlg)
	m_CNewName = _T("");
	m_CNewPhone = _T("");
	m_CNewMail = _T("");
	m_AddRemark = _T("");
	//}}AFX_DATA_INIT
}


void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddDlg)
	DDX_Control(pDX, IDC_COMBO1, m_CNewGroup);
	DDX_Text(pDX, IDC_EDIT1, m_CNewName);
	DDX_Text(pDX, IDC_EDIT2, m_CNewPhone);
	DDX_Text(pDX, IDC_EDIT3, m_CNewMail);
	DDX_Text(pDX, IDC_EDIT4, m_AddRemark);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddDlg, CDialog)
	//{{AFX_MSG_MAP(CAddDlg)
	ON_EN_CHANGE(IDC_EDIT1, OnEditName)
	ON_EN_CHANGE(IDC_EDIT2, OnEditPhone)
	ON_EN_CHANGE(IDC_EDIT3, OnADDMail)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddDlg message handlers

void CAddDlg::OnOK() 
{
	// TODO: Add extra validation here
	m_CGroup = m_CNewGroup.GetCurSel();
	CDialog::OnOK();
}

void CAddDlg::OnEditName() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CAddDlg::OnEditPhone() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CAddDlg::OnADDMail() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

BOOL CAddDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();	
	// TODO: Add extra initialization here
	m_CNewGroup.SetCurSel(m_CGroup);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
