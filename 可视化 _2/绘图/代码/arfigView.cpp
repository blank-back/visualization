
// arfigView.cpp : CarfigView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "arfig.h"
#endif

#include "arfigDoc.h"
#include "arfigView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CarfigView

IMPLEMENT_DYNCREATE(CarfigView, CView)

BEGIN_MESSAGE_MAP(CarfigView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CarfigView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CarfigView::On32771)
	ON_COMMAND(ID_32772, &CarfigView::On32772)
END_MESSAGE_MAP()

// CarfigView 构造/析构

CarfigView::CarfigView()
{
	// TODO: 在此处添加构造代码
}

CarfigView::~CarfigView()
{
}

BOOL CarfigView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CarfigView 绘制

void CarfigView::OnDraw(CDC* /*pDC*/)
{
	CarfigDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC* pDc = GetDC();
	CarfigDoc*pdoc=GetDocument();
	CRect rect1;
	CPoint m_a;
	CSize m_b;
	CString m_c;
	pdoc->get(m_c,m_a,m_b);
	this->GetClientRect(rect1);	
	CRect rect(m_a,m_b);
	if(m_c=="椭圆")
		pDc->Ellipse(rect);
	else
	pDc->Rectangle(rect);
	ReleaseDC(pDc);
}


// CarfigView 打印


void CarfigView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CarfigView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CarfigView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CarfigView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CarfigView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CarfigView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CarfigView 诊断

#ifdef _DEBUG
void CarfigView::AssertValid() const
{
	CView::AssertValid();
}

void CarfigView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CarfigDoc* CarfigView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CarfigDoc)));
	return (CarfigDoc*)m_pDocument;
}
#endif //_DEBUG


// CarfigView 消息处理程序


void CarfigView::On32771()
{
	// TODO: 在此添加命令处理程序代码
	this->Invalidate();
	this->UpdateWindow();
	CDC* pDc = GetDC();
	CarfigDoc*pdoc=GetDocument();
	CRect rect1;
	this->GetClientRect(rect1);
	int ra=max((rand()%(rect1.right-rect1.left/2)/4)*4,200);
	pdoc->set(CString("椭圆"),CPoint(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y-ra/4),CSize(ra,ra/2));	
	CRect rect(CPoint(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y-ra/4),CSize(ra,ra/2));
	pDc->Ellipse(rect);
	ReleaseDC(pDc);                                                                       

}
void CarfigView::drawimg()
{
	this->Invalidate();
	this->UpdateWindow();
	CDC* pDc = GetDC();
	CarfigDoc*pdoc=GetDocument();
	CRect rect1;
	CPoint m_a;
	CSize m_b;
	CString m_c;
	pdoc->get(m_c,m_a,m_b);
	this->GetClientRect(rect1);	
	CRect rect(m_a,m_b);
	if(m_c=="椭圆")
		pDc->Ellipse(rect);
	else
	pDc->Rectangle(rect);
	ReleaseDC(pDc);
}

void CarfigView::On32772()
{
	// TODO: 在此添加命令处理程序代码
	this->Invalidate();
	this->UpdateWindow();
	CDC* pDc = GetDC();
	CarfigDoc*pdoc=GetDocument();
	CRect rect1;
	this->GetClientRect(rect1);

	
	int ra=max((rand()%(rect1.right-rect1.left/2)/4)*4,200);
	pdoc->set(CString("矩形"),CPoint(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y-ra/4),CSize(ra,ra/2));	
	CRect rect(CPoint(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y-ra/4),CSize(ra,ra/2));
	pDc->Rectangle(rect);
	ReleaseDC(pDc);
}

