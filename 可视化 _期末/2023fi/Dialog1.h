#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CDialog1 �Ի���

class CDialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog1)

public:
	CDialog1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialog1();
	void putget();
// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	int age;
	CSpinButtonCtrl spin1;
	int major;
	CComboBox combobox1;
	CString output;
};
