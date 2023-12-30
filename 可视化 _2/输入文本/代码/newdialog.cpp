// newdialog.cpp : 实现文件
//

#include "stdafx.h"
#include "input.h"
#include "newdialog.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "inputdoc.h"

// newdialog 对话框

IMPLEMENT_DYNAMIC(newdialog, CDialogEx)

newdialog::newdialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(newdialog::IDD, pParent)
{

}

newdialog::~newdialog()
{
}

void newdialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(newdialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &newdialog::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &newdialog::OnBnClickedOk)
END_MESSAGE_MAP()


// newdialog 消息处理程序


void newdialog::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void newdialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	
	
	CinputApp* pApp=(CinputApp*)AfxGetApp();
	CMainFrame*pAppFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	ASSERT_KINDOF(CMainFrame, pAppFrame);
	CinputDoc* pDoc=(CinputDoc*) pAppFrame->GetActiveDocument();
	ASSERT_VALID(pDoc);  
	m_edit.GetWindowText(pDoc->m_a);
	pDoc->UpdateAllViews(NULL);
	CDialogEx::OnOK();
}
