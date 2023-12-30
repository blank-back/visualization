// infodlg.cpp : 实现文件
//

#include "stdafx.h"
#include "perinfo.h"
#include "infodlg.h"
#include "afxdialogex.h"
#include "perinfoDoc.h"
#include "perinfoView.h"

// infodlg 对话框

IMPLEMENT_DYNAMIC(infodlg, CDialogEx)

infodlg::infodlg(CDocument*pdoc,CWnd* pParent /*=NULL*/)
	: CDialogEx(infodlg::IDD, pParent)
	, dlgname(_T("无"))
	, dlgage(_T("18"))
	, dlgcombo(_T("男"))
	, dlgnation(_T("汉"))
	, radio(0)
	, check1(FALSE)
{
	this->doc=pdoc;
}

infodlg::~infodlg()
{
}

void infodlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, dlgname);
	DDX_Text(pDX, IDC_EDIT2, dlgage);
	DDX_CBString(pDX, IDC_COMBO1, dlgcombo);
	DDX_Text(pDX, IDC_EDIT3, dlgnation);
	DDX_Radio(pDX, 1006, radio);
	DDX_Check(pDX, 1005, check1);
}


BEGIN_MESSAGE_MAP(infodlg, CDialogEx)
	ON_BN_CLICKED(IDOK2, &infodlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDOK, &infodlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, &infodlg::OnCbnSelchangeCombo1)
	//ON_EN_CHANGE(IDC_EDIT3, &infodlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_CHECK1, &infodlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_RADIO1, &infodlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &infodlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// infodlg 消息处理程序


void infodlg::OnBnClickedOk2()
{
	// TODO: 
	((CperinfoDoc*)doc)->get(dlgname,dlgage,dlgcombo,dlgnation,radio,check1);
	UpdateData(FALSE);
}


void infodlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	((CperinfoDoc*)doc)->start1=true;
	((CperinfoDoc*)doc)->set(dlgname,dlgage,dlgcombo,dlgnation,radio,check1);
	CDialogEx::OnOK();
}


void infodlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


//void infodlg::OnEnChangeEdit3()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//}


void infodlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void infodlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void infodlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
}
