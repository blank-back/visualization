
// perinfo.h : perinfo Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CperinfoApp:
// �йش����ʵ�֣������ perinfo.cpp
//

class CperinfoApp : public CWinApp
{
public:
	CperinfoApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CperinfoApp theApp;
