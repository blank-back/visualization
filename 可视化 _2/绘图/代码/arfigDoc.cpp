
// arfigDoc.cpp : CarfigDoc ���ʵ��
//

#include "stdafx.h"
//#include "arfigView.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "arfig.h"
#endif

#include "arfigDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CarfigDoc

IMPLEMENT_DYNCREATE(CarfigDoc, CDocument)

BEGIN_MESSAGE_MAP(CarfigDoc, CDocument)
END_MESSAGE_MAP()


// CarfigDoc ����/����

CarfigDoc::CarfigDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CarfigDoc::~CarfigDoc()
{
}

BOOL CarfigDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}



void CarfigDoc::set(CString&c,CPoint& a,CSize& b)
{
	m_a=a;
	m_b=b;
	m_c=c;
}
void CarfigDoc::get(CString&c,CPoint& a,CSize& b)
{
	a=m_a;
	b=m_b;
	c=m_c;
}
BOOL CarfigDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	CFile file;
	file.Open(lpszPathName, CFile::modeReadWrite);
	CArchive loadar(&file,CArchive::load);
	Serialize(loadar);
	this->UpdateAllViews(NULL);
	return true;
}
BOOL CarfigDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	CFile file;
	file.Open(lpszPathName,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
	CArchive savear(&file,CArchive::store);
	Serialize(savear);
	return true;
}
// CarfigDoc ���л�

void CarfigDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar<<m_c<<m_a.x<<m_a.y<<m_b.cx<<m_b.cy;
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		ar>>m_c>>m_a.x>>m_a.y>>m_b.cx>>m_b.cy;
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CarfigDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CarfigDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CarfigDoc::SetSearchContent(const CString& value)
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

// CarfigDoc ���

#ifdef _DEBUG
void CarfigDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CarfigDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CarfigDoc ����
