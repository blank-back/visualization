
// homewrok6View.cpp : Chomewrok6View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "homewrok6.h"
#endif

#include "homewrok6Doc.h"
#include "homewrok6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Chomewrok6View

IMPLEMENT_DYNCREATE(Chomewrok6View, CScrollView)

BEGIN_MESSAGE_MAP(Chomewrok6View, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &Chomewrok6View::On32771)
	ON_COMMAND(ID_32772, &Chomewrok6View::On32772)
	ON_COMMAND(ID_32773, &Chomewrok6View::On32773)
	ON_COMMAND(ID_32775, &Chomewrok6View::On32775)
END_MESSAGE_MAP()

// Chomewrok6View 构造/析构

Chomewrok6View::Chomewrok6View()
{
	// TODO: 在此处添加构造代码

}

Chomewrok6View::~Chomewrok6View()
{
}

BOOL Chomewrok6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// Chomewrok6View 绘制

void Chomewrok6View::OnDraw(CDC* /*pDC*/)
{
	Chomewrok6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void Chomewrok6View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = 800;
	sizeTotal.cy = 600;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Chomewrok6View 打印

BOOL Chomewrok6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Chomewrok6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Chomewrok6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Chomewrok6View 诊断

#ifdef _DEBUG
void Chomewrok6View::AssertValid() const
{
	CScrollView::AssertValid();
}

void Chomewrok6View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Chomewrok6Doc* Chomewrok6View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Chomewrok6Doc)));
	return (Chomewrok6Doc*)m_pDocument;
}
#endif //_DEBUG


// Chomewrok6View 消息处理程序


void Chomewrok6View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	this->Invalidate();
	this->UpdateWindow();
	CDC*dc=GetDC();   //显示设备
	CBitmap bitmap;
	CBitmap *pOldBitmap;
	CDC memDC;
	memDC.CreateCompatibleDC(dc);   //建立设备场景，与显示设备兼容
	bitmap.LoadBitmap(IDB_BITMAP5);  //取出位图资源
	pOldBitmap = memDC.SelectObject(&bitmap);  //将位图选入内存环境
	dc->StretchBlt(0, 0, 320, 240, &memDC, 0, 0, 320, 240, SRCCOPY);  //显示
	memDC.SelectObject(pOldBitmap);
	this->UpdateWindow();
}


void Chomewrok6View::On32772()
{
	// TODO: 在此添加命令处理程序代码
	this->Invalidate();
	this->UpdateWindow();
	CDC*dc=GetDC();   //显示设备
	CBitmap bitmap;
	CBitmap *pOldBitmap;
	CDC memDC;
	memDC.CreateCompatibleDC(dc);   //建立设备场景，与显示设备兼容
	bitmap.LoadBitmap(IDB_BITMAP5);  //取出位图资源
	pOldBitmap = memDC.SelectObject(&bitmap);  //将位图选入内存环境
	dc->StretchBlt(0, 0, 640, 480, &memDC, 0, 0, 320, 240, SRCCOPY);  //显示
	memDC.SelectObject(pOldBitmap);
	this->UpdateWindow();
}


void Chomewrok6View::On32773()
{
	// TODO: 在此添加命令处理程序代码
	this->Invalidate();
	this->UpdateWindow();
	CDC*dc=GetDC();   //显示设备
	CBitmap bitmap;
	CBitmap *pOldBitmap;
	CDC memDC;
	memDC.CreateCompatibleDC(dc);   //建立设备场景，与显示设备兼容
	bitmap.LoadBitmap(IDB_BITMAP5);  //取出位图资源
	pOldBitmap = memDC.SelectObject(&bitmap);  //将位图选入内存环境
	dc->StretchBlt(0, 0, 160, 120, &memDC, 0, 0, 320, 240, SRCCOPY);  //显示
	memDC.SelectObject(pOldBitmap);
	this->UpdateWindow();
}


void Chomewrok6View::On32775()
{
	// TODO: 在此添加命令处理程序代码
		this->Invalidate();
	this->UpdateWindow();
	CDC*dc=GetDC();   //显示设备
	CBitmap bitmap;
	CBitmap *pOldBitmap;
	CDC memDC;
	memDC.CreateCompatibleDC(dc);   //建立设备场景，与显示设备兼容
	bitmap.LoadBitmap(IDB_BITMAP5);  //取出位图资源
	pOldBitmap = memDC.SelectObject(&bitmap);  //将位图选入内存环境
	dc->StretchBlt(0, 0, 1280, 960, &memDC, 0, 0, 320, 240, SRCCOPY);  //显示
	memDC.SelectObject(pOldBitmap);
	this->UpdateWindow();
}
