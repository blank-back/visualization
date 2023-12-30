
// dlgcalDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "dlgcal.h"
#include "dlgcalDlg.h"
#include "afxdialogex.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CdlgcalDlg �Ի���




CdlgcalDlg::CdlgcalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CdlgcalDlg::IDD, pParent)
	, calnum1(0)
	, answer(_T("������\r\n��֧��double��Χ�ڵĺϷ�����\r\nĬ�ϲ�����Ϊ0"))
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


// CdlgcalDlg ��Ϣ�������

BOOL CdlgcalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CdlgcalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CdlgcalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CdlgcalDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
	UpdateData(TRUE);
	calculate(waitkey);
	waitkey=-1;
}


void CdlgcalDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CdlgcalDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CdlgcalDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	calculate(waitkey);
	waitkey=2;
}


void CdlgcalDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
			sprintf(temp2,"��������Ϊ0��");
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
			sprintf(temp2,"0�����󸺴��ݣ�");
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	calculate(waitkey);
	waitkey=1;
}


void CdlgcalDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	calstart=false;
	calnum1=0;
	ransw=0;
	waitkey=-1;
	answer="������\r\n��֧��double��Χ�ڵĺϷ�����\r\nĬ�ϲ�����Ϊ0";
	UpdateData(FALSE);
}


void CdlgcalDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	calculate(waitkey);
	waitkey=0;
}


void CdlgcalDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	calculate(waitkey);
	waitkey=5;
}


void CdlgcalDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
