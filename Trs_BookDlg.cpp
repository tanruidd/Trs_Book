// Trs_BookDlg.cpp : implementation file
//

#include "stdafx.h"//报错请删掉Debug文件夹重新编译
#include "Trs_Book.h"
#include "Trs_BookDlg.h"
#include "AddDlg.h"
#include "EditDlg.h"
#include "LineViewDlg.h"
#include "SaveDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	afx_msg void OnBanben();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_COMMAND(ID_BANBEN, OnBanben)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrs_BookDlg dialog

CTrs_BookDlg::CTrs_BookDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTrs_BookDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTrs_BookDlg)
	m_EditRemark = _T("");
	m_FindName = _T("");
	m_FindPhone = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrs_BookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTrs_BookDlg)
	DDX_Control(pDX, IDC_COMBO1, m_FindGroup);
	DDX_Control(pDX, IDC_LIST1, m_ListBx);
	DDX_Text(pDX, IDC_EDIT2, m_EditRemark);
	DDX_Text(pDX, IDC_EDIT1, m_FindName);
	DDX_Text(pDX, IDC_EDIT3, m_FindPhone);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTrs_BookDlg, CDialog)
	//{{AFX_MSG_MAP(CTrs_BookDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_BN_CLICKED(IDC_BUTTON1, OnAdd)
	ON_BN_CLICKED(IDC_BUTTON4, OnDelete)
	ON_BN_CLICKED(IDC_BUTTON2, OnEdit)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnLinkView)
	ON_BN_CLICKED(IDC_BUTTON3, OnFind)
	ON_BN_CLICKED(IDC_BUTTON5, OnRestor)
	ON_COMMAND(ID_BANBEN, OnBanben)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrs_BookDlg message handlers

BOOL CTrs_BookDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	CMenu menu;  
	menu.LoadMenu(IDR_MENU1);  //IDR_MENU1为菜单栏ID号  
	SetMenu(&menu); 
	m_Flag = FALSE;
	People[0].tot = 0;//初始化
	Remark[1] = "无";
	Remark[2] = "同学";
	Remark[3] = "家人";
	Remark[4] = "朋友";
	//一坨获取列表控件设置行列什么的
	CListCtrl* Init = (CListCtrl*)GetDlgItem(IDC_LIST1);
	DWORD dwStyle = GetWindowLong(Init->m_hWnd, GWL_STYLE);
	SetWindowLong(Init->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);
	DWORD styles = Init->GetExtendedStyle();
	Init->SetExtendedStyle(styles|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	CRect rect;
	Init->GetWindowRect(&rect);
	m_ListBx.InsertColumn(0, "姓名", LVCFMT_CENTER, rect.Width() / 6);
	m_ListBx.InsertColumn(1, "电话号码", LVCFMT_CENTER, rect.Width() / 3);
	m_ListBx.InsertColumn(2, "邮箱", LVCFMT_CENTER, rect.Width() / 3);
	m_ListBx.InsertColumn(3, "分组", LVCFMT_CENTER, rect.Width() / 6);
	ReadBook();
	for(int i = 1; i <= People[0].tot; i++) {
		m_ListBx.InsertItem(i - 1, People[i].strName);
		m_ListBx.SetItemText(i - 1, 1, People[i].strPhone);
		m_ListBx.SetItemText(i - 1, 2, People[i].strMail);
		m_ListBx.SetItemText(i - 1, 3, Remark[People[i].strGroup]);
	}
	/*
	int nRow = m_ListBx.InsertItem(0, "严嘉豪");// 插入行 
	m_ListBx.InsertItem(1, "谭瑞");// 插入行
	m_ListBx.InsertItem(2, "马博");
	m_ListBx.SetItemText(nRow, 1, "110");// 设置其它列数据
	m_ListBx.SetItemText(nRow, 2, "87*****@qq.om");
	m_ListBx.SetItemText(nRow, 3, "同学");
	m_ListBx.SetItemText(nRow + 1, 1, "1154330");
	m_ListBx.SetItemText(nRow + 1, 2, "87****54343om");
	m_ListBx.SetItemText(nRow + 1, 3, "无");
	m_ListBx.SetItemText(nRow + 2, 1, "11254");
	m_ListBx.SetItemText(nRow + 2, 2, "87***fdfd43om");
	m_ListBx.SetItemText(nRow + 2, 3, "无");
	People[++People[0].tot].strName = "严嘉豪";
	People[People[0].tot].strPhone = "110";
	People[People[0].tot].strMail = "87*****@qq.om";
	People[People[0].tot].strGroup = 2;
	People[++People[0].tot].strName = "谭瑞";
	People[People[0].tot].strPhone = "1154330";
	People[People[0].tot].strMail = "87****54343om";
	People[People[0].tot].strGroup = 1;
	People[++People[0].tot].strName = "马博";
	People[People[0].tot].strPhone = "11254";
	People[People[0].tot].strMail = "87***fdfd43om";
	People[People[0].tot].strGroup = 1;
	*/
	CStdioFile file;
    CString str;
    file.Open("test.txt", CFile::modeRead);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTrs_BookDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTrs_BookDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTrs_BookDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTrs_BookDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_ListBx.GetNextItem(-1, LVNI_SELECTED);
	/*
	CString t;
	t.Format("%d", nIndex);
	MessageBox(t);
	*/
	if(nIndex != -1) {
		if(m_Flag == TRUE)nIndex = SFind.pos[nIndex + 1] - 1;
		m_EditRemark = People[nIndex + 1].strRemark;
		SContact Contact = People[nIndex + 1];
		if(Contact.strRemark.IsEmpty())m_EditRemark = People[nIndex + 1].strName + "无备注";
		UpdateData(FALSE);
	}
	*pResult = 0;
}

void CTrs_BookDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	CAddDlg Add;
	Add.m_CGroup = -1;
	while(IDOK == Add.DoModal()) {
		SContact Contact;
		Contact.strName = Add.m_CNewName;
		Contact.strPhone = Add.m_CNewPhone;
		Contact.strMail = Add.m_CNewMail;
		Contact.strRemark = Add.m_AddRemark;
		Contact.strGroup = Add.m_CGroup + 1;
		if(Contact.strName.IsEmpty())MessageBox("联系人姓名不能为空!");
		else if(Contact.strPhone.IsEmpty())MessageBox("联系人电话不能为空!");
		else if(Contact.strGroup == -1)MessageBox("联系人分组不能为空!");
		else {
			bool flag = TRUE;
			for(int i = 1; i <= People[0].tot; i++) {
				if(Contact.strPhone == People[i].strPhone) {
					flag = FALSE;
					break;
				}
			}
			if(flag == FALSE)MessageBox("该联系人电话号码已存在!");
			else {
				People[++People[0].tot].strName = Contact.strName;
				People[People[0].tot].strPhone = Contact.strPhone;
				People[People[0].tot].strMail = Contact.strMail;
				People[People[0].tot].strRemark = Contact.strRemark;
				People[People[0].tot].strGroup = Contact.strGroup;
				int nCnt = m_ListBx.GetItemCount();
				m_ListBx.InsertItem(nCnt, Contact.strName);
				m_ListBx.SetItemText(nCnt, 1, Contact.strPhone);
				m_ListBx.SetItemText(nCnt, 2, Contact.strMail);
				m_ListBx.SetItemText(nCnt, 3, Remark[Contact.strGroup]);
				if(m_Flag == TRUE) {
					SFind.pos[++SFind.tot] = People[0].tot;
				}
			}
			break;
		}
	}
}

void CTrs_BookDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_ListBx.GetNextItem(-1, LVNI_SELECTED);
	if(nIndex != LB_ERR) {
		//delete (SContact*)m_ListBx.
		m_ListBx.DeleteItem(nIndex);
		if(m_Flag == TRUE)nIndex = SFind.pos[nIndex + 1];
		else nIndex++;
		for(int i = nIndex; i < People[0].tot; i++)People[i] = People[i + 1];
		People[0].tot--;
		UpdateData(FALSE);
	}
	else MessageBox("请选择要删除的联系人!");
}

void CTrs_BookDlg::OnEdit() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_ListBx.GetNextItem(-1, LVNI_SELECTED);
	if(nIndex == -1)MessageBox("请选要修改的择联系人!");
	else {
		SContact Contact = People[nIndex + 1];
		if(m_Flag == TRUE)Contact = People[SFind.pos[nIndex + 1]];
		CEditDlg Edit;
		UpdateData(TRUE);
	//	int List = Edit.m_EditGroup.GetCurSel();	
		Edit.m_EditName = Contact.strName;
		Edit.m_EditPhone = Contact.strPhone;
		Edit.m_EditMail = Contact.strMail;
		Edit.m_EditRemark = Contact.strRemark;
		Edit.m_Group = Contact.strGroup;
		//Edit.m_EditGroup = Contact.strGroup;
		//MessageBox(Edit.m_EditName);
		if(IDOK == Edit.DoModal()) {
			SContact Contact;
			Contact.strName = Edit.m_EditName;
			Contact.strPhone = Edit.m_EditPhone;
			Contact.strMail = Edit.m_EditMail;
			Contact.strRemark = Edit.m_EditRemark;
			Contact.strGroup = Edit.m_Group + 1;
			bool flag = TRUE;
			if(Contact.strName.IsEmpty())MessageBox("联系人姓名不能为空!");
			else if(Contact.strPhone.IsEmpty())MessageBox("联系人电话不能为空!");
			else {
				if(m_Flag == FALSE) {
				for(int i = 1; i <= People[0].tot; i++) {
					if(Contact.strPhone == People[i].strPhone && i != (nIndex + 1)) {
						flag = FALSE;
						break;
					}
				}
				}
				else {
					for(int i = 1; i <= People[0].tot; i++) {
						if(Contact.strPhone == People[i].strPhone && i != (SFind.pos[nIndex + 1])) {
							flag = FALSE;
							break;
						}
					}
				}
			}
			if(flag == FALSE)MessageBox("该联系人电话号码已存在!");
			else if(!Contact.strName.IsEmpty() && !Contact.strPhone.IsEmpty()){
				if(m_Flag == FALSE) {
					int tot = People[0].tot;
					People[0].tot++;
					People[nIndex + 1] = Contact;
					for(int i = People[0].tot; i > nIndex + 1; i--)People[i] = People[i - 1];
					m_ListBx.InsertItem(nIndex + 1, Contact.strName);
					m_ListBx.SetItemText(nIndex + 1, 1, Contact.strPhone);
					m_ListBx.SetItemText(nIndex + 1, 2, Contact.strMail);
					m_ListBx.SetItemText(nIndex + 1, 3, Remark[Contact.strGroup]);
					m_ListBx.DeleteItem(nIndex);
					for(i = nIndex + 1; i < People[0].tot; i++)People[i] = People[i + 1];
					People[0].tot = tot;
				}
				else {
					int tot = SFind.tot;
					SFind.tot++;
					People[SFind.pos[nIndex + 1]] = Contact;
					CString t;
					t.Format("%d", nIndex);
					MessageBox(t);
				//	for(int i = SFind.tot; i > nIndex + 1; i--)SFind.pos[i] = SFind.pos[i - 1];
					m_ListBx.InsertItem(nIndex, Contact.strName);
					m_ListBx.SetItemText(nIndex, 1, Contact.strPhone);
					m_ListBx.SetItemText(nIndex, 2, Contact.strMail);
					m_ListBx.SetItemText(nIndex, 3, Remark[Contact.strGroup]);
					m_ListBx.DeleteItem(nIndex + 1);
				//	for(i = nIndex + 1; i < SFind.tot; i++)SFind.pos[i] = SFind.pos[i + 1];
					SFind.tot = tot;
				}
			}
		}
	}
}

void CTrs_BookDlg::OnLinkView(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_ListBx.GetNextItem(-1,LVNI_ALL | LVNI_SELECTED);
	if(nIndex != -1) {
		SContact Contact;
		if(m_Flag == TRUE)nIndex = SFind.pos[nIndex + 1] - 1;
			Contact = People[nIndex + 1];
			CString p = nIndex + '0';
			//MessageBox(p);
			//MessageBox(Remark[Contact.strGroup]);
			CLineViewDlg View;
			View.m_ViewName = Contact.strName;
			View.m_ViewPhone = Contact.strPhone;
			View.m_ViewMail = Contact.strMail;
			View.m_ViewRemark = Contact.strRemark;
			View.m_ViewGroup = Remark[Contact.strGroup];
			View.DoModal();
	}
	*pResult = 0;
}

void CTrs_BookDlg::OnFind() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_FindName.TrimLeft();
	m_FindName.TrimRight();
	m_FindPhone.TrimLeft();
	m_FindPhone.TrimRight();
	int nIndex = m_FindGroup.GetCurSel() - 1;
/*	CString s;
	s.Format("%d", nIndex);
	MessageBox(s);
	*/
	if(m_FindName.IsEmpty() && m_FindPhone.IsEmpty() && nIndex <= -1)MessageBox("请输入查找信息!");
	else {
		SFind.tot = 0;
		if(!m_FindName.IsEmpty()) {
			for(int i = 1; i <= People[0].tot; i++) {
				if(People[i].strName.Find(m_FindName) != -1) {
					if(!m_FindPhone.IsEmpty()) {
						if(People[i].strPhone.Find(m_FindPhone) != -1) {
							if(nIndex > -1) {
								if(People[i].strGroup == nIndex + 1)SFind.pos[++SFind.tot] = i;
							}
							else SFind.pos[++SFind.tot] = i;
						}
					}
					else if(nIndex > -1) {
						if(People[i].strGroup == nIndex + 1)SFind.pos[++SFind.tot] = i;
					}
					else SFind.pos[++SFind.tot] = i;
				}
			}
		}
		else if(!m_FindPhone.IsEmpty()) {
			for(int i = 1; i <= People[0].tot; i++) {
				if(People[i].strPhone.Find(m_FindPhone) != -1) {
					if(nIndex > -1) {
						if(People[i].strGroup == nIndex + 1) SFind.pos[++SFind.tot] = i;
					}
					else SFind.pos[++SFind.tot] = i;
				}
			}
		}
		else if(nIndex > -1) {
			for(int i = 1; i <= People[0].tot; i++) {
				if(People[i].strGroup == nIndex + 1) SFind.pos[++SFind.tot] = i;
			}
		}
		CString str = "共查到";
		str += (SFind.tot + '0');
		str += "条联系人信息";
		MessageBox(str);
		while(m_ListBx.DeleteItem(0));
		for(int nCnt = 0; nCnt < SFind.tot; nCnt++) {
			m_ListBx.InsertItem(nCnt, People[SFind.pos[nCnt + 1]].strName);
			m_ListBx.SetItemText(nCnt, 1, People[SFind.pos[nCnt + 1]].strPhone);
			m_ListBx.SetItemText(nCnt, 2, People[SFind.pos[nCnt + 1]].strMail);
			m_ListBx.SetItemText(nCnt, 3, Remark[People[SFind.pos[nCnt + 1]].strGroup]);
		}
		m_Flag = TRUE;
		m_FindName = "";
		m_FindPhone = "";
		UpdateData(FALSE);
	}
}

void CTrs_BookDlg::OnRestor() 
{
	// TODO: Add your control notification handler code here
	while(m_ListBx.DeleteItem(0));
	for(int nCnt = 0; nCnt < People[0].tot; nCnt++) {
		m_ListBx.InsertItem(nCnt, People[nCnt + 1].strName);
		m_ListBx.SetItemText(nCnt, 1, People[nCnt + 1].strPhone);
		m_ListBx.SetItemText(nCnt, 2, People[nCnt + 1].strMail);
		m_ListBx.SetItemText(nCnt, 3, Remark[People[nCnt + 1].strGroup]);
	}
	m_FindName = "";
	m_FindPhone = "";
	UpdateData(FALSE);
	m_Flag = FALSE;
}

void CTrs_BookDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	CSaveDlg Save;
	if(IDOK == Save.DoModal()) {
		CStdioFile file;
		file.Open("test.txt",CFile::modeCreate|CFile::modeWrite);
		CString str;
		for(int i = 1; i <= People[0].tot; i++){
		   People[i].strName += "\n";
	       file.WriteString(People[i].strName);
		   People[i].strPhone += "\n";
	       file.WriteString(People[i].strPhone);
		   People[i].strMail += "\n";
	       file.WriteString(People[i].strMail);
		   str.Format("%d\n", People[i].strGroup);
		   file.WriteString(str);
		   str = "";
		   CString str2(People[i].strRemark);
		   int Length = str2.GetLength();
		   CString ch = ('0' + 80);
		   int pos = People[i].strRemark.Find("\r\n", 0);
		   int pre = 0, len;
		 //  CString str3 = "";
		  // str3.Format("%d", pos);
		   while(pos != -1) {
			//   MessageBox(str3);
			   //str.Format("%d", pre);
			   //MessageBox(str);
			   for(len = pre; len < pos; len++)str += People[i].strRemark[len];
			   str += ch[0];
			   if(pos != -1)pre = pos + 2;
			   pos = People[i].strRemark.Find("\r\n", pos + 1);
			//   str3.Format("%d", pos);
		   }
		   for(len = pre; len < Length; len++)str += People[i].strRemark[len];
		   str += '\n';
		   //MessageBox(str3);
		 //  MessageBox(str);
           file.WriteString(str);
		}
		MessageBox("保存成功");
	}
	CDialog::OnCancel();
}

CString CTrs_BookDlg::ReadBook()
{
	CStdioFile file;
    CString str;
    file.Open("test.txt", CFile::modeRead);
    int now = 0;
    while (file.ReadString(str) != NULL)
    {
	//	MessageBox(str);
        if(now == 0) {
			People[0].tot++;
			People[People[0].tot].strName = str;
        }
        else if(now == 1){
			People[People[0].tot].strPhone = str;
        }
        else if(now == 2){
			People[People[0].tot].strMail = str;
        }
        else if(now == 3){
            People[People[0].tot].strGroup = str[0] - '0';
        }
        else if(now == 4){
			CString str2(str);
			CString tmp = "";
		    int Length = str2.GetLength();
			CString ch = ('0' + 80);
		    int pos = str.Find(ch, 0);
	 	    int pre = 0, len;
		    while(pos != -1) {
			   //MessageBox();
			   for(len = pre; len < pos; len++)tmp += str[len];
			   tmp += "\r\n";
			   if(pos != -1)pre = pos + 1;
			   pos = str.Find(ch, pos + 1);
		   }
		   for(len = pre; len < Length; len++)tmp += str[len];
		   People[People[0].tot].strRemark = tmp;
        }
        now++; 
		now %= 5;
    }
	return TRUE;
}

void CTrs_BookDlg::OnBanben() 
{
	// TODO: Add your command handler code here
	CAboutDlg *pDlg=new CAboutDlg ;
    pDlg->Create(IDD_ABOUTBOX,this);
    pDlg->ShowWindow(SW_SHOW);
}

void CAboutDlg::OnBanben() 
{
	// TODO: Add your command handler code here

}


void CTrs_BookDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_EditRemark = "";
	UpdateData(FALSE);
	CDialog::OnLButtonDown(nFlags, point);
}
