
// dlgcalDlg.h : 头文件
//

#pragma once


// CdlgcalDlg 对话框
class CdlgcalDlg : public CDialogEx
{
// 构造
public:
	CdlgcalDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DLGCAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	double calnum1;
	afx_msg void OnEnChangeEdit2();
	double calnum2;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	CString answer;
	double ransw;
	bool calstart;
	int waitkey;
	void CdlgcalDlg::calculate(int key);
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnEnChangeEdit1();
};
