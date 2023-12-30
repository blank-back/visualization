
// arfigDoc.cpp : CarfigDoc 类的实现
//

#include "stdafx.h"
//#include "arfigView.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CarfigDoc 构造/析构

CarfigDoc::CarfigDoc()
{
	// TODO: 在此添加一次性构造代码

}

CarfigDoc::~CarfigDoc()
{
}

BOOL CarfigDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

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
// CarfigDoc 序列化

void CarfigDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		ar<<m_c<<m_a.x<<m_a.y<<m_b.cx<<m_b.cy;
	}
	else
	{
		// TODO: 在此添加加载代码
		ar>>m_c>>m_a.x>>m_a.y>>m_b.cx>>m_b.cy;
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CarfigDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CarfigDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CarfigDoc 诊断

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


// CarfigDoc 命令
