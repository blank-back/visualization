
// 2023fi.h : 2023fi Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy2023fiApp:
// �йش����ʵ�֣������ 2023fi.cpp
//

class CMy2023fiApp : public CWinApp
{
public:
	CMy2023fiApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2023fiApp theApp;
