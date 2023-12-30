
// homework3View.cpp : Chomework3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "homework3.h"
#endif

#include "homework3Doc.h"
#include "homework3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Chomework3View

IMPLEMENT_DYNCREATE(Chomework3View, CView)

BEGIN_MESSAGE_MAP(Chomework3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	
	ON_COMMAND(SmallballAcc, &Chomework3View::OnSmallballAcc)
	ON_COMMAND(SmallballBegin, &Chomework3View::OnSmallballBegin)
	ON_COMMAND(SmallballPause, &Chomework3View::OnSmallballPause)
	ON_COMMAND(SmallballSlow, &Chomework3View::OnSmallballSlow)
	ON_COMMAND(AFX_IDS_SCMOVE, &Chomework3View::OnAfxIdsScmove)
	ON_COMMAND(AFX_IDS_SCSIZE, &Chomework3View::OnAfxIdsScsize)
	ON_WM_NCLBUTTONDOWN()
END_MESSAGE_MAP()

// Chomework3View 构造/析构

Chomework3View::Chomework3View()
{
	// TODO: 在此处添加构造代码

}

Chomework3View::~Chomework3View()
{
}

BOOL Chomework3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	return CView::PreCreateWindow(cs);
}

// Chomework3View 绘制

void Chomework3View::OnDraw(CDC* /*pDC*/)
{
	Chomework3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Chomework3View 打印

BOOL Chomework3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Chomework3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Chomework3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}
//颜色切换参数
bool flage = 0;
// 颜色存储
std::vector<std::vector<int>>  rgb_store;
//原点出发
int x=0,y=0;
int begint=300;
double moveX=5*sqrt(2.0);
double moveY=5*sqrt(2.0);
void Chomework3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值


	if (nIDEvent == 1) {
		CDC *pDC = GetDC();
		CRect rect;
		GetClientRect(&rect);
		if (flage == 0)
		{
			std::vector<int> rgb2;
			rgb2.push_back(0);
			rgb2.push_back(0);
			rgb2.push_back(0);
			rgb_store.push_back(rgb2);
		}

		std::vector<int> rgb;
		//随机生成颜色
		int red = rand() % 255;
		int green = rand() % 255;
		int blue = rand() % 255;

		rgb.push_back(red);
		rgb.push_back(green);
		rgb.push_back(blue);

		if (flage == 0)
		{
			rgb_store.push_back(rgb);
			flage = 1;
		}
		else {
			rgb_store[0] = rgb_store[1];
			rgb_store[1] = rgb;
		}
		int red2 = rgb_store[0][0];
		int green2 = rgb_store[0][1];
		int blue2 = rgb_store[0][2];
		CBrush brush2;
		brush2.CreateSolidBrush(RGB(red2,green2,blue2));
		pDC->SelectObject(&brush2);
		pDC->SetROP2(R2_XORPEN);
		pDC->Ellipse(x,y, x+30, y+30);
		if (y<0 || y>rect.bottom - 30)
			moveY = 0 - moveY;
		if (x<0 || x>rect.right - 30)
			moveX = 0 - moveX;
		x+=moveX;
		y+=moveY;
		// 画球
		CBrush brush;
		brush.CreateSolidBrush(RGB(red,green,blue));
		pDC->SelectObject(&brush);
		pDC->Ellipse(x, y, x + 30, y + 30);
	}
	
	CView::OnTimer(nIDEvent);
}
//停止



// Chomework3View 诊断

#ifdef _DEBUG
void Chomework3View::AssertValid() const
{
	CView::AssertValid();
}

void Chomework3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Chomework3Doc* Chomework3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Chomework3Doc)));
	return (Chomework3Doc*)m_pDocument;
}
#endif //_DEBUG


// Chomework3View 消息处理程序




void Chomework3View::OnSmallballPause()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
}
//加速
void Chomework3View::OnSmallballAcc()
{
	begint-=50;
	OnSmallballPause();
	OnSmallballBegin();
}
//减速
void Chomework3View::OnSmallballSlow()
{
	begint+=50;
	OnSmallballPause();
	OnSmallballBegin();
}
//开始
void Chomework3View::OnSmallballBegin()
{
	// TODO: 在此添加命令处理程序代码
	SetTimer(1, begint, NULL);
}

void Chomework3View::OnAfxIdsScmove()
{

	// TODO: 在此添加命令处理程序代码
	SetWindowPos(&wndTopMost, 100, 500, 0, 0,  SWP_NOSIZE /*| SWP_NOMOVE*/);
	SetWindowPos(&wndTopMost, 100, 500, 0, 0,  SWP_NOMOVE /*| SWP_NOMOVE*/);
}


void Chomework3View::OnAfxIdsScsize()
{
	// TODO: 在此添加命令处理程序代码
	SetWindowPos(&wndTopMost,800,700, 0, 0,  SWP_NOSIZE /*| SWP_NOMOVE*/);
	SetWindowPos(&wndTopMost,800, 700, 0, 0,  SWP_NOMOVE /*| SWP_NOMOVE*/);

}


void Chomework3View::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	
}
