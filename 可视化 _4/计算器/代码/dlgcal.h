
// dlgcal.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CdlgcalApp:
// �йش����ʵ�֣������ dlgcal.cpp
//

class CdlgcalApp : public CWinApp
{
public:
	CdlgcalApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CdlgcalApp theApp;