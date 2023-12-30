// Dialog1.cpp : 实现文件
//

#include "stdafx.h"
#include "2023fi.h"
#include "Dialog1.h"
#include "afxdialogex.h"


// CDialog1 对话框

IMPLEMENT_DYNAMIC(CDialog1, CDialogEx)

CDialog1::CDialog1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog1::IDD, pParent)
	, name(_T("汪晨"))
	, age(20)
	, major(0)
	, output(_T("尚未实现"))
{
}

CDialog1::~CDialog1()
{
}

void CDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, age);
	DDV_MinMaxInt(pDX, age, 20, 25);
	DDX_Control(pDX, IDC_SPIN1, spin1);
	spin1.SetRange32(20, 25);
	DDX_Radio(pDX, IDC_RADIO1, major);
	DDX_Control(pDX, IDC_COMBO1, combobox1);
	combobox1.InsertString(0, L"椭圆");
	combobox1.InsertString(1, L"矩形");
	combobox1.SetCurSel(0);
	DDX_Text(pDX, IDC_EDIT3, output);
}
void CDialog1::putget()
{
	//output=CString();
}

BEGIN_MESSAGE_MAP(CDialog1, CDialogEx)
END_MESSAGE_MAP()


// CDialog1 消息处理程序
