
// inputDoc.cpp : CinputDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "input.h"
#endif

#include "inputDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CinputDoc

IMPLEMENT_DYNCREATE(CinputDoc, CDocument)

BEGIN_MESSAGE_MAP(CinputDoc, CDocument)
END_MESSAGE_MAP()


// CinputDoc ����/����

CinputDoc::CinputDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CinputDoc::~CinputDoc()
{
}
BOOL CinputDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	CFile file;
	file.Open(lpszPathName, CFile::modeReadWrite);
	CArchive loadar(&file,CArchive::load);
	Serialize(loadar);
	this->UpdateAllViews(NULL);
	return true;
}
BOOL CinputDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	CFile file;
	file.Open(lpszPathName,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
	CArchive savear(&file,CArchive::store);
	Serialize(savear);
	return true;
}
BOOL CinputDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}



void CinputDoc::get(CString&a)
{
	a=m_a;
}
// CinputDoc ���л�

void CinputDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar<<m_a;
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		ar>>m_a;
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CinputDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CinputDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CinputDoc::SetSearchContent(const CString& value)
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

// CinputDoc ���

#ifdef _DEBUG
void CinputDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CinputDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CinputDoc ����


void CinputDoc::OnFileOpen()
{
	// TODO: �ڴ���������������
	
}
