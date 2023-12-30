
// perinfoDoc.cpp : CperinfoDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CperinfoDoc 构造/析构

CperinfoDoc::CperinfoDoc()
{
	// TODO: 在此添加一次性构造代码
	start1=false;
}

CperinfoDoc::~CperinfoDoc()
{
}

BOOL CperinfoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

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



// CperinfoDoc 序列化

void CperinfoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		ar<<name<<age<<sex<<nation<<radio<<check1;
	}
	else
	{
		// TODO: 在此添加加载代码
		ar>>name>>age>>sex>>nation>>radio>>check1;
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CperinfoDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CperinfoDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CperinfoDoc 诊断

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


// CperinfoDoc 命令
