#pragma once
//#include "perinfoDoc.h"

// infodlg �Ի���

class infodlg : public CDialogEx
{
	DECLARE_DYNAMIC(infodlg)
	CDocument*doc;
public:
	infodlg(CDocument*pdoc, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~infodlg();
	//CperinfoView *paptr;
// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangeCombo1();
	CString dlgname, dlgage, dlgcombo, dlgnation;
//	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	int radio;
	BOOL check1;
};
