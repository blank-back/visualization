#pragma once
#include "afxwin.h"


// newdialog �Ի���

class newdialog : public CDialogEx
{
	DECLARE_DYNAMIC(newdialog)

public:
	newdialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~newdialog();
	CString str;
// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	CEdit m_edit;
};
