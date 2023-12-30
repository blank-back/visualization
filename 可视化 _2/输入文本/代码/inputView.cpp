
// inputView.cpp : CinputView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "input.h"
#include "newdialog.h"
#endif

#include "inputDoc.h"
#include "inputView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CinputView

IMPLEMENT_DYNCREATE(CinputView, CView)

BEGIN_MESSAGE_MAP(CinputView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CinputView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	
	ON_COMMAND(ID_32772, &CinputView::On32772)
END_MESSAGE_MAP()

// CinputView 构造/析构

CinputView::CinputView()
{
	// TODO: 在此处添加构造代码

}

CinputView::~CinputView()
{
}

BOOL CinputView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CinputView 绘制

void CinputView::OnDraw(CDC* /*pDC*/)
{
	CDC* pDc=GetDC();
	CinputDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	CRect rect1;
	this->GetClientRect(rect1);
	pDc->TextOut(0, rect1.bottom-rect1.top-20, pDoc->m_a);

	
}


// CinputView 打印


void CinputView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CinputView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CinputView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CinputView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CinputView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CinputView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CinputView 诊断

#ifdef _DEBUG
void CinputView::AssertValid() const
{
	CView::AssertValid();
}

void CinputView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CinputDoc* CinputView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CinputDoc)));
	return (CinputDoc*)m_pDocument;
}
#endif //_DEBUG


// CinputView 消息处理程序




void CinputView::On32772()
{
	// TODO: 在此添加命令处理程序代码
	newdialog a1;
	a1.DoModal();
}
