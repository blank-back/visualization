
// homewrok6.h : homewrok6 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Chomewrok6App:
// �йش����ʵ�֣������ homewrok6.cpp
//

class Chomewrok6App : public CWinApp
{
public:
	Chomewrok6App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Chomewrok6App theApp;
