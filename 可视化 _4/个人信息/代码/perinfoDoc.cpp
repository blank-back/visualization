
// perinfoDoc.cpp : CperinfoDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "perinfo.h"
#endif

#include "perinfoDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW 
#endif

// CperinfoDoc

IMPLEMENT_DYNCREATE(CperinfoDoc, CDocument)

BEGIN_MESSAGE_MAP(CperinfoDoc, CDocument)
END_MESSAGE_MAP()


// CperinfoDoc ����/����

CperinfoDoc::CperinfoDoc()
{
	// TODO: �ڴ����һ���Թ������
	start1=false;
}

CperinfoDoc::~CperinfoDoc()
{
}

BOOL CperinfoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}
void CperinfoDoc::set(CString&a,CString&b,CString&c,CString&d,int&e,int&f)
{
	name=a;
	age=b;
	sex=c;
	nation=d;
	radio=e;
	check1=f;
	this->UpdateAllViews(NULL);
}
void CperinfoDoc::get(CString&a,CString&b,CString&c,CString&d,int&e,int&f)
{
	a=name;
	b=age;
	c=sex;
	d=nation;
	e=radio;
	f=check1;
}
BOOL CperinfoDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	CFile file;
	file.Open(lpszPathName, CFile::modeReadWrite);
	CArchive loadar(&file,CArchive::load);
	Serialize(loadar);
	this->UpdateAllViews(NULL);
	return true;
}
BOOL CperinfoDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	CFile file;
	file.Open(lpszPathName,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
	CArchive savear(&file,CArchive::store);
	Serialize(savear);
	return true;
}



// CperinfoDoc ���л�

void CperinfoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar<<name<<age<<sex<<nation<<radio<<check1;
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		ar>>name>>age>>sex>>nation>>radio>>check1;
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CperinfoDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CperinfoDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CperinfoDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CperinfoDoc ���

#ifdef _DEBUG
void CperinfoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CperinfoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CperinfoDoc ����
