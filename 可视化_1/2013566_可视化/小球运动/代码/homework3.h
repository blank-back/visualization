
// homework3.h : homework3 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// Chomework3App:
// 有关此类的实现，请参阅 homework3.cpp
//

class Chomework3App : public CWinApp
{
public:
	Chomework3App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Chomework3App theApp;
