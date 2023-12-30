
// dlgcalDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "dlgcal.h"
#include "dlgcalDlg.h"
#include "afxdialogex.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CdlgcalDlg 对话框




CdlgcalDlg::CdlgcalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CdlgcalDlg::IDD, pParent)
	, calnum1(0)
	, answer(_T("计算结果\r\n仅支持double范围内的合法计算\r\n默认操作数为0"))
	, ransw(0)
	, calstart(false)
	, waitkey(-1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdlgcalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, calnum1);
	//DDX_Text(pDX, IDC_EDIT2, calnum2);
	DDX_Text(pDX, IDC_EDIT3, answer);
}

BEGIN_MESSAGE_MAP(CdlgcalDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CdlgcalDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CdlgcalDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT2, &CdlgcalDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON3, &CdlgcalDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CdlgcalDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &CdlgcalDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CdlgcalDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON1, &CdlgcalDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &CdlgcalDlg::OnBnClickedButton6)
	ON_EN_CHANGE(IDC_EDIT1, &CdlgcalDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CdlgcalDlg 消息处理程序

BOOL CdlgcalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CdlgcalDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CdlgcalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CdlgcalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CdlgcalDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	UpdateData(TRUE);
	calculate(waitkey);
	waitkey=-1;
}


void CdlgcalDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CdlgcalDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CdlgcalDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	calculate(waitkey);
	waitkey=2;
}


void CdlgcalDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	calculate(waitkey);
	waitkey=3;
}
void CdlgcalDlg::calculate(int key)
{
	double prev=ransw;
	char temp1[100];
	char temp2[100];
	memset(temp1,'\0',100);
	switch(key)
	{
	case -1:
		ransw=calnum1;
		calnum1=0;
		UpdateData(FALSE);
		return;
	case 0:
		ransw+=calnum1;
		sprintf(temp1,"%lf+%lf\r\n=%lf",prev,calnum1,ransw);
		strcpy(temp2,temp1);
		break;
	case 1:
		ransw-=calnum1;
		sprintf(temp1,"%lf-%lf\r\n=%lf",prev,calnum1,ransw);
		strcpy(temp2,temp1);
		break;
	case 2:
		ransw*=calnum1;
		sprintf(temp1,"%lf*%lf\r\n=%lf",prev,calnum1,ransw);
		strcpy(temp2,temp1);
		break;
	case 3:
		if(calnum1==0)
		{
			sprintf(temp2,"除数不可为0！");
		}
		else
		{
			ransw/=calnum1;
			sprintf(temp1,"%lf/%lf\r\n=%lf",prev,calnum1,ransw);
			strcpy(temp2,temp1);
		}
		break;
	case 5:
		if(calnum1<0&&ransw==0)
		{
			sprintf(temp2,"0不可求负次幂！");
		}
		else
		{
			double prev=ransw;
			ransw=pow(ransw, calnum1);
			sprintf(temp1,"%lf^%lf\r\n=%lf",prev,calnum1,ransw);
			strcpy(temp2,temp1);
		}
		break;
	default:
		answer.Format(_T("Shouldn't reach"));
	}
	answer=temp2;
	calnum1=0;
	UpdateData(FALSE);
}
void CdlgcalDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	calculate(waitkey);
	waitkey=1;
}


void CdlgcalDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	calstart=false;
	calnum1=0;
	ransw=0;
	waitkey=-1;
	answer="计算结果\r\n仅支持double范围内的合法计算\r\n默认操作数为0";
	UpdateData(FALSE);
}


void CdlgcalDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	calculate(waitkey);
	waitkey=0;
}


void CdlgcalDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	calculate(waitkey);
	waitkey=5;
}


void CdlgcalDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
