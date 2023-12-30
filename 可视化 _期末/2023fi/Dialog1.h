#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CDialog1 对话框

class CDialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDialog1)

public:
	CDialog1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialog1();
	void putget();
// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	int age;
	CSpinButtonCtrl spin1;
	int major;
	CComboBox combobox1;
	CString output;
};
