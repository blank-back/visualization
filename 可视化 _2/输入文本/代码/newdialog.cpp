// newdialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "input.h"
#include "newdialog.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "inputdoc.h"

// newdialog �Ի���

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


// newdialog ��Ϣ�������


void newdialog::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void newdialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	
	CinputApp* pApp=(CinputApp*)AfxGetApp();
	CMainFrame*pAppFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	ASSERT_KINDOF(CMainFrame, pAppFrame);
	CinputDoc* pDoc=(CinputDoc*) pAppFrame->GetActiveDocument();
	ASSERT_VALID(pDoc);  
	m_edit.GetWindowText(pDoc->m_a);
	pDoc->UpdateAllViews(NULL);
	CDialogEx::OnOK();
}
