
// 2023fi.h : 2023fi 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMy2023fiApp:
// 有关此类的实现，请参阅 2023fi.cpp
//

class CMy2023fiApp : public CWinApp
{
public:
	CMy2023fiApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy2023fiApp theApp;
