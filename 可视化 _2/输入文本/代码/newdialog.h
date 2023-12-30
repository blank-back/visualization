#pragma once
#include "afxwin.h"


// newdialog 对话框

class newdialog : public CDialogEx
{
	DECLARE_DYNAMIC(newdialog)

public:
	newdialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~newdialog();
	CString str;
// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	CEdit m_edit;
};
