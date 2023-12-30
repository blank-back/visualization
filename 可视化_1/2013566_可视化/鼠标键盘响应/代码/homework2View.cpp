
// homework2View.cpp : Chomework2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "homework2.h"
#endif

#include "homework2Doc.h"
#include "homework2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Chomework2View

IMPLEMENT_DYNCREATE(Chomework2View, CView)
//加入所需的消息命令
BEGIN_MESSAGE_MAP(Chomework2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_MESSAGE(WM_MY_MESSAGE, OnMyMessage)//自定义
	ON_WM_LBUTTONDOWN()//鼠标按下
	ON_WM_LBUTTONUP()//鼠标点击恢复
	ON_WM_CHAR()//按键字符
END_MESSAGE_MAP()

// Chomework2View 构造/析构

Chomework2View::Chomework2View()
{
	// TODO: 在此处添加构造代码

}

Chomework2View::~Chomework2View()
{
}

BOOL Chomework2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Chomework2View 绘制

void Chomework2View::OnDraw(CDC* /*pDC*/)
{
	Chomework2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Chomework2View 打印

BOOL Chomework2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Chomework2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Chomework2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Chomework2View 诊断

#ifdef _DEBUG
void Chomework2View::AssertValid() const
{
	CView::AssertValid();
}

void Chomework2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Chomework2Doc* Chomework2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Chomework2Doc)));
	return (Chomework2Doc*)m_pDocument;
}
#endif //_DEBUG


// Chomework2View 消息处理程序
void Chomework2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nChar == 35)
	{
		SendMessage(WM_MY_MESSAGE, 100, 200);
	}
	else {
		CString str;
		str.Format(L"%c Key Entered", nChar);
		MessageBox(str);
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}

//自定义消息处理
LRESULT Chomework2View::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	// TODO: 在此处添加实现代码.
	CString str;
	str.Format(L"personal message is %d and %d", wParam, lParam);
	MessageBox(str);
	return 0;
}
//实现点击左键输出坐标和是否使用Ctrl按键
void Chomework2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	//按下Ctrl和鼠标左键
	if((MK_CONTROL & nFlags)&& !(MK_SHIFT & nFlags))
		str.Format(L"鼠标左键+Ctrl 位于(%d,%d)", point.x, point.y);
	//按下Shift和鼠标左键
	else if (!(MK_CONTROL & nFlags) && (MK_SHIFT & nFlags))
		str.Format(L"鼠标左键+Shift 位于(%d,%d)", point.x, point.y);
	//同时按下Ctrl、Shift和鼠标左键
	else if ((MK_CONTROL & nFlags) && (MK_SHIFT & nFlags))
		str.Format(L"鼠标左键+Ctrl+Shift 位于(%d,%d)", point.x, point.y);
	//按下鼠标左键
	else
		str.Format(L"鼠标左键 位于(%d,%d)", point.x, point.y);
	MessageBox(str);
	CView::OnLButtonDown(nFlags, point);
}
// 响应功能键
BOOL Chomework2View::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN) {
		if (pMsg->wParam == VK_UP)
			MessageBox(L"up key Entered");
		if (pMsg->wParam == VK_DOWN)
			MessageBox(L"down key Entered");
		if (pMsg->wParam == VK_LEFT)
			MessageBox(L"left key Entered");
		if (pMsg->wParam == VK_RIGHT)
			MessageBox(L"right key Entered");
		else if (pMsg->wParam == VK_F1)
			MessageBox(L"F1 key Entered");
		else if (pMsg->wParam == VK_F2)
			MessageBox(L"F2 key Entered");
		else if (pMsg->wParam == VK_F3)
			MessageBox(L"F3 key Entered");
		else if (pMsg->wParam == VK_F4)
			MessageBox(L"F4 key Entered");
		else if (pMsg->wParam == VK_F5)
			MessageBox(L"F5 key Entered");
		else if (pMsg->wParam == VK_F6)
			MessageBox(L"F6 key Entered");
		else if (pMsg->wParam == VK_F7)
			MessageBox(L"F7 key Entered");
		else if (pMsg->wParam == VK_F8)
			MessageBox(L"F8 key Entered");
		else if (pMsg->wParam == VK_F9)
			MessageBox(L"F9 key Entered");
		else if (pMsg->wParam == VK_F10)
			MessageBox(L"F10 key Entered");
		else if (pMsg->wParam == VK_F11)
			MessageBox(L"F11 key Entered");
		else if (pMsg->wParam == VK_F12)
			MessageBox(L"F12 key Entered");
	}
	return CView::PreTranslateMessage(pMsg);
}
void Chomework2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// 重新绘制客户区
	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	CBrush brush;
	brush.CreateSolidBrush(RGB(255, 255, 255));
	pDC->SelectObject(&brush);
	pDC->Rectangle(rect);
	CView::OnLButtonUp(nFlags, point);
}

