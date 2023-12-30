
// inputDoc.cpp : CinputDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CinputDoc 构造/析构

CinputDoc::CinputDoc()
{
	// TODO: 在此添加一次性构造代码

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

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}



void CinputDoc::get(CString&a)
{
	a=m_a;
}
// CinputDoc 序列化

void CinputDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		ar<<m_a;
	}
	else
	{
		// TODO: 在此添加加载代码
		ar>>m_a;
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CinputDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CinputDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CinputDoc 诊断

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


// CinputDoc 命令


void CinputDoc::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	
}
