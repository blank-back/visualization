
// homework4.h : homework4 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Chomework4App:
// �йش����ʵ�֣������ homework4.cpp
//

class Chomework4App : public CWinAppEx
{
public:
	Chomework4App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Chomework4App theApp;
