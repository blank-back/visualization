// infodlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "perinfo.h"
#include "infodlg.h"
#include "afxdialogex.h"
#include "perinfoDoc.h"
#include "perinfoView.h"

// infodlg �Ի���

IMPLEMENT_DYNAMIC(infodlg, CDialogEx)

infodlg::infodlg(CDocument*pdoc,CWnd* pParent /*=NULL*/)
	: CDialogEx(infodlg::IDD, pParent)
	, dlgname(_T("��"))
	, dlgage(_T("18"))
	, dlgcombo(_T("��"))
	, dlgnation(_T("��"))
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


// infodlg ��Ϣ�������


void infodlg::OnBnClickedOk2()
{
	// TODO: 
	((CperinfoDoc*)doc)->get(dlgname,dlgage,dlgcombo,dlgnation,radio,check1);
	UpdateData(FALSE);
}


void infodlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	((CperinfoDoc*)doc)->start1=true;
	((CperinfoDoc*)doc)->set(dlgname,dlgage,dlgcombo,dlgnation,radio,check1);
	CDialogEx::OnOK();
}


void infodlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


//void infodlg::OnEnChangeEdit3()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}


void infodlg::OnBnClickedCheck1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void infodlg::OnBnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void infodlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
