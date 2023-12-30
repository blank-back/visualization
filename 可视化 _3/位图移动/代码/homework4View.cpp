
// homework4View.cpp : Chomework4View 类的实现
//

#include "stdafx.h"
#include "math.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "homework4.h"
#endif

#include "homework4Doc.h"
#include "homework4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Chomework4View

IMPLEMENT_DYNCREATE(Chomework4View, CView)
BEGIN_MESSAGE_MAP(Chomework4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_ACCLINE, &Chomework4View::On32774)
	ON_COMMAND(ID_32779, &Chomework4View::On32774)
	ON_COMMAND(ID_32772, &Chomework4View::On32772)
	ON_COMMAND(ID_32773, &Chomework4View::On32773)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Chomework4View 构造/析构

Chomework4View::Chomework4View()
	: destpos(0)
{
	// TODO: 在此处添加构造代码
	offset=8;
}

Chomework4View::~Chomework4View()
{
}

BOOL Chomework4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Chomework4View 绘制

void Chomework4View::OnDraw(CDC* /*pDC*/)
{
	Chomework4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Chomework4View 打印

BOOL Chomework4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Chomework4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void Chomework4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// Chomework4View 诊断

#ifdef _DEBUG
void Chomework4View::AssertValid() const
{
	CView::AssertValid();
}

void Chomework4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Chomework4Doc* Chomework4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Chomework4Doc)));
	return (Chomework4Doc*)m_pDocument;
}
#endif //_DEBUG
void Chomework4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
CMenu menu;
	menu.LoadMenu(IDR_MENU1);
	CMenu *pMenu = menu.GetSubMenu(0);
	pMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
}


// Chomework4View 消息处理程序


void Chomework4View::On32772()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
	MSG msg;
	PeekMessage(&msg, NULL, WM_TIMER, WM_TIMER, PM_REMOVE);
	this->Invalidate();
	this->UpdateWindow();
	CDC* pDc = GetDC();
	Chomework4Doc*pdoc=GetDocument();
	CRect rect1;
	this->GetClientRect(rect1);
	int ra=min((rand()%(rect1.right-rect1.left/2)/4)*4,200);
	ra=max(ra,150);
	destpos.x=rect1.CenterPoint().x-ra/2+4;
	destpos.y=rect1.CenterPoint().y-ra/2-4;
	destre.right=destpos.x+4;
	destre.left=destpos.x-4;
	destre.top=destpos.y-4;
	destre.bottom=destpos.y+4;
	pdoc->set(CString("矩形"),CPoint(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y-ra/2),CSize(ra,ra));	
	CRect rect(CPoint(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y-ra/2),CSize(ra,ra));
	pDc->Rectangle(rect);
	ReleaseDC(pDc);
}

BOOL Chomework4View::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message==WM_KEYDOWN)
	{
		if (pMsg->wParam==86)
		{
			bitrun();
		}
	}
	return CView::PreTranslateMessage(pMsg);
}
void Chomework4View::bitrun()
{
	SetTimer(1,70,NULL);
}
void Chomework4View::On32773()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
	MSG msg;
PeekMessage(&msg,NULL, WM_TIMER, WM_TIMER, PM_REMOVE);
	this->Invalidate();
	this->UpdateWindow();
	CDC* pDc = GetDC();
	Chomework4Doc*pdoc=GetDocument();
	CRect rect1;
	this->GetClientRect(rect1);
	int ra=min((rand()%(rect1.right-rect1.left/2)/4)*4,200);
	ra=max(ra,100);
	destpos.x=rect1.CenterPoint().x-ra-8;
	destpos.y=rect1.CenterPoint().y+4;
	destre.right=destpos.x+4;
	destre.left=destpos.x-4;
	destre.top=destpos.y-4;
	destre.bottom=destpos.y+4;
	pdoc->set(CString("六边形"),CPoint(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y-ra/4),CSize(ra,ra/2));	
	pDc->MoveTo(rect1.CenterPoint().x-ra,rect1.CenterPoint().y);
	pDc->LineTo(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y+ra*sqrt(3.0)/2);
	pDc->MoveTo(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y+ra*sqrt(3.0)/2);
	pDc->LineTo(rect1.CenterPoint().x+ra/2,rect1.CenterPoint().y+ra/2*sqrt(3.0));
	pDc->MoveTo(rect1.CenterPoint().x+ra/2,rect1.CenterPoint().y+ra/2*sqrt(3.0));
	pDc->LineTo(rect1.CenterPoint().x+ra,rect1.CenterPoint().y);
	pDc->MoveTo(rect1.CenterPoint().x+ra,rect1.CenterPoint().y);
	pDc->LineTo(rect1.CenterPoint().x+ra/2,rect1.CenterPoint().y-ra*sqrt(3.0)/2);
	pDc->MoveTo(rect1.CenterPoint().x+ra/2,rect1.CenterPoint().y-ra*sqrt(3.0)/2);
	pDc->LineTo(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y-ra/2*sqrt(3.0));
	pDc->MoveTo(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y-ra/2*sqrt(3.0));
	pDc->LineTo(rect1.CenterPoint().x-ra,rect1.CenterPoint().y);
	ReleaseDC(pDc); 
}
void Chomework4View::On32774()
{
	// TODO: 在此添加命令处理程序代码
	KillTimer(1);
	MSG msg;
PeekMessage(&msg, NULL, WM_TIMER, WM_TIMER, PM_REMOVE);
	this->Invalidate();
	this->UpdateWindow();
	CDC* pDc = GetDC();
	Chomework4Doc*pdoc=GetDocument();
	CRect rect1;
	this->GetClientRect(rect1);
	int ra=min((rand()%(rect1.right-rect1.left/2)/4)*4,200);
	ra=max(ra,100);
	destpos.x=rect1.CenterPoint().x-ra/2+4;
	destpos.y=rect1.CenterPoint().y-ra/2-4;
	destre.right=destpos.x+4;
	destre.left=destpos.x-4;
	destre.top=destpos.y-4;
	destre.bottom=destpos.y+4;
	pdoc->set(CString("直线"),CPoint(rect1.CenterPoint().x-ra,rect1.CenterPoint().y-ra),CSize(ra,ra));	
	pDc->MoveTo(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y-ra/2);
	pDc->LineTo(rect1.CenterPoint().x+ra/2,rect1.CenterPoint().y+ra/2);
	ReleaseDC(pDc); 
}

void Chomework4View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Chomework4Doc*pdoc=GetDocument();
	CString c1;CPoint a1;CSize b1;
	pdoc->get(c1,a1,b1);
	if(nIDEvent==1)
	if(c1=="六边形")
	{
		CRect rect,newRect;
		GetClientRect(&rect);
		CDC*dc=GetDC();   //显示设备
		CBitmap bitmap;
		CBitmap *pOldBitmap;
		CDC memDC;
		memDC.CreateCompatibleDC(dc);   //建立设备场景，与显示设备兼容
		bitmap.LoadBitmap(IDB_BITMAP1);  //取出位图资源
		pOldBitmap = memDC.SelectObject(&bitmap);  //将位图选入内存环境
		dc->BitBlt(destre.left, destre.top, 8, 8, &memDC, 0, 0, SRCCOPY);  //显示
		memDC.SelectObject(pOldBitmap);
		this->UpdateWindow();
		// newRect区域移动
		newRect=destre;
		// left up
		if(destpos.y>rect.CenterPoint().y-(b1.cx/2)*sqrt(3.0)-4&&destpos.x<rect.CenterPoint().x-(b1.cx/2)+4&&destpos.y<=rect.CenterPoint().y+4)
		{
			if(destpos.x>rect.CenterPoint().x-b1.cy)
			{
				destpos.x=rect.CenterPoint().x-b1.cx/2+4;
				destpos.y=rect.CenterPoint().y-(b1.cx/2)*sqrt(3.0)-5;
				newRect.left=destpos.x-4;
				newRect.right=destpos.x+4;
				newRect.top=destpos.y-4;
				newRect.bottom=destpos.y+4;
			}
			else
			{
				destpos.x+=offset;
				destpos.y-=offset*sqrt(3.0);
				newRect.right+=offset;
				newRect.left+=offset;
				newRect.top-=offset*sqrt(3.0);
				newRect.bottom-=offset*sqrt(3.0);
			}
		}
		//up str
		else if(destpos.x<rect.CenterPoint().x+b1.cy+1&&destpos.y<rect.CenterPoint().y-b1.cy*sqrt(3.0))
		{

			if(destpos.x>rect.CenterPoint().x+b1.cy)
			{
				destpos.x=rect.CenterPoint().x+b1.cx/2+4.0/3*sqrt(3.0);
				destpos.y=rect.CenterPoint().y-b1.cx/2*sqrt(3.00)-2;
				newRect.left=destpos.x-4;
				newRect.right=destpos.x+4;
				newRect.top=destpos.y-4;
				newRect.bottom=destpos.y+4;
			}
			else
			{
				newRect.right+=offset;
				newRect.left+=offset;
				destpos.x+=offset;
				/*newRect.top+=offset*sqrt(3.0);
				newRect.bottom+=offset*sqrt(3.0);*/
			}
		}
		//right down
		else if(destpos.y<rect.CenterPoint().y+4&&destpos.x>=rect.CenterPoint().x+b1.cy)
		{
			if(destpos.y>rect.CenterPoint().y)
			{	
				destpos.x=rect.CenterPoint().x+b1.cx-4;
				destpos.y=rect.CenterPoint().y+2;
				newRect.left=destpos.x-4;
				newRect.right=destpos.x+4;
				newRect.top=destpos.y-4;
				newRect.bottom=destpos.y+4;
			}
			else
			{
				destpos.x+=offset;
				destpos.y+=offset*sqrt(3.0);
				newRect.right+=offset;
				newRect.left+=offset;
				newRect.top+=offset*sqrt(3.0);
				newRect.bottom+=offset*sqrt(3.0);
			}
		}
		//left down
		else if(destpos.x>rect.CenterPoint().x+b1.cy&&destpos.y>rect.CenterPoint().y)
		{
			if(destpos.y>rect.CenterPoint().y+b1.cx/2*sqrt(3.0))
			{
				destpos.x=rect.CenterPoint().x+b1.cx/2-4;
				destpos.y=rect.CenterPoint().y+b1.cx/2*sqrt(3.0)+6;
				newRect.left=destpos.x-4;
				newRect.right=destpos.x+4;
				newRect.top=destpos.y-4;
				newRect.bottom=destpos.y+4;
			}
			else
			{
				newRect.right-=offset;
				newRect.left-=offset;
				destpos.x-=offset;
				destpos.y+=offset*sqrt(3.0);
				newRect.top+=offset*sqrt(3.0);
				newRect.bottom+=offset*sqrt(3.0);
			}
		}
		//down str
		else if(destpos.x>rect.CenterPoint().x-b1.cy-6&&destpos.y>=rect.CenterPoint().y+b1.cy*sqrt(3.0)+4)
		{
			if(destpos.x<rect.CenterPoint().x-b1.cx/2)
			{
				destpos.x=rect.CenterPoint().x-b1.cy-7;
				destpos.y=rect.CenterPoint().y+b1.cy*sqrt(3.0)-4;
				newRect.left=destpos.x-4;
				newRect.right=destpos.x+4;
				newRect.top=destpos.y-4;
				newRect.bottom=destpos.y+4;
			}
			else
			{
				newRect.right-=offset;
				newRect.left-=offset;
				destpos.x-=offset;
				/*newRect.top+=offset*sqrt(3.0);
				newRect.bottom+=offset*sqrt(3.0);*/
			}
		}
		else //if(destpos.x<rect.CenterPoint().x-b1.cx&&destpos.y>=rect.CenterPoint().y-4)
		{
			if(destpos.y-offset*sqrt(3.0)<rect.CenterPoint().y+4)
			{
				destpos.x=rect.CenterPoint().x-b1.cx-8;
				destpos.y=rect.CenterPoint().y+4;
				newRect.right=destpos.x+4;
				newRect.left=destpos.x-4;
				newRect.top=destpos.y-4;
				newRect.bottom=destpos.y+4;
			}
			else
			{
				newRect.right-=offset;
				newRect.left-=offset;
				destpos.x-=offset;
				destpos.y-=offset*sqrt(3.0);
				newRect.top-=offset*sqrt(3.0);
				newRect.bottom-=offset*sqrt(3.0);
			}
		}
		// 重绘icon_rect区域
		Sleep(70);
		InvalidateRect(destre,true);
		// 更新icon_rect
		destre=newRect;
		/*bitmap.DeleteObject();//，释放所有与该对象有关的系统资源
		dc->DeleteDC();//删除指定的设备上下文环境
		memDC.DeleteDC();
		this->ReleaseDC(dc);//释放设备上下文环境（DC）供其他应用程序使用。
		this->ReleaseDC(&memDC);*/
	}
	else if(c1=="直线")
	{
			CRect rect,newRect;
			GetClientRect(&rect);
			CDC*dc=GetDC();   //显示设备
			CBitmap bitmap;
			CBitmap *pOldBitmap;
			CDC memDC;
			memDC.CreateCompatibleDC(dc);   //建立设备场景，与显示设备兼容
			bitmap.LoadBitmap(IDB_BITMAP1);  //取出位图资源
			pOldBitmap = memDC.SelectObject(&bitmap);  //将位图选入内存环境
			dc->BitBlt(destre.left, destre.top, 8, 8, &memDC, 0, 0, SRCCOPY);  //显示
			memDC.SelectObject(pOldBitmap);
			newRect=destre;
			this->UpdateWindow();
			//system("pause");
			// newRect区域移动
			newRect.right+=offset;
			newRect.left+=offset;
			newRect.top+=offset;
			newRect.bottom+=offset;
			// 到边界时反向
			if(destpos.x<rect.CenterPoint().x-b1.cx/2||destpos.x>rect.CenterPoint().x+b1.cx/2-4)
				offset=-offset;
			// 重绘icon_rect区域
			Sleep(70);
			InvalidateRect(destre,true);
			
			//this->UpdateWindow();
			// 更新icon_rect
			destre=newRect;
			// icon向左移动
			/*bitmap.DeleteObject();//，释放所有与该对象有关的系统资源
			dc->DeleteDC();//删除指定的设备上下文环境
			memDC.DeleteDC();
			this->ReleaseDC(dc);//释放设备上下文环境（DC）供其他应用程序使用。
			this->ReleaseDC(&memDC);*/
			destpos.x+=offset;
			destpos.y+=offset;
	}
	else if(c1=="矩形")
	{
			CRect rect,newRect;
			GetClientRect(&rect);
			CDC*dc=GetDC();   //显示设备
			CBitmap bitmap;
			CBitmap *pOldBitmap;
			CDC memDC;
			memDC.CreateCompatibleDC(dc);   //建立设备场景，与显示设备兼容
			bitmap.LoadBitmap(IDB_BITMAP1);  //取出位图资源
			pOldBitmap = memDC.SelectObject(&bitmap);  //将位图选入内存环境
			dc->BitBlt(destre.left, destre.top, 8, 8, &memDC, 0, 0, SRCCOPY);  //显示
			memDC.SelectObject(pOldBitmap);
			this->UpdateWindow();
			// newRect区域移动
			newRect=destre;
			// 到边界时反向
			if(destpos.y<=rect.CenterPoint().y-b1.cx/2-4)
			{
				newRect.top=rect.CenterPoint().y-b1.cx/2-8;
				newRect.bottom=rect.CenterPoint().y-b1.cx/2;
				if(destpos.x>rect.CenterPoint().x+b1.cx/2+4)
				{
					destpos.x=rect.CenterPoint().x+b1.cx/2+4;
					destpos.y=rect.CenterPoint().y-b1.cx/2+4;
					newRect.left=destpos.x-4;
					newRect.right=destpos.x+4;
				}
				else
				{
					destpos.x+=offset;
					newRect.right+=offset;
					newRect.left+=offset;
					/*newRect.top+=offset;
					newRect.bottom+=offset;*/
				}
			}
			else if(destpos.x>rect.CenterPoint().x+b1.cx/2)
			{
				if(destpos.y>rect.CenterPoint().y+b1.cx/2+4)
				{
					destpos.x=rect.CenterPoint().x+b1.cx/2-4;
					destpos.y=rect.CenterPoint().y+b1.cx/2+4;
					newRect.top=destpos.y-4;
					newRect.bottom=destpos.y+4;
				}
				else
				{
					/*newRect.right+=offset;
					newRect.left+=offset;*/
					destpos.y+=offset;
					newRect.top+=offset;
					newRect.bottom+=offset;
				}
			}
			else if(destpos.y>rect.CenterPoint().y+b1.cx/2)
			{
				if(destpos.x<rect.CenterPoint().x-b1.cx/2-4)
				{
					destpos.x=rect.CenterPoint().x-b1.cx/2-4;
					destpos.y=rect.CenterPoint().y+b1.cx/2-4;
					newRect.left=destpos.x-4;
					newRect.right=destpos.x+4;
				}
				else
				{
					destpos.x-=offset;
					newRect.right-=offset;
					newRect.left-=offset;
					/*newRect.top+=offset;
					newRect.bottom+=offset;*/
				}
			}
			else if(destpos.x<rect.CenterPoint().x-b1.cx/2)
			{
				if(destpos.y<rect.CenterPoint().y-b1.cx/2)
				{
					destpos.x=rect.CenterPoint().x-b1.cx/2+4;
					destpos.y=rect.CenterPoint().y-b1.cx/2-4;
					newRect.top=destpos.y-4;
					newRect.bottom=destpos.y+4;
				}
				else
				{
					/*newRect.right-=offset;
					newRect.left-=offset;*/
					destpos.y-=offset;
					newRect.top-=offset;
					newRect.bottom-=offset;
				}
			}
			// 重绘icon_rect区域
			Sleep(70);
			InvalidateRect(destre,true);
			// 更新icon_rect
			destre=newRect;
			/*bitmap.DeleteObject();//，释放所有与该对象有关的系统资源
			dc->DeleteDC();//删除指定的设备上下文环境
			memDC.DeleteDC();
			ReleaseDC(dc);//释放设备上下文环境（DC）供其他应用程序使用。
			ReleaseDC(&memDC);*/
	}
	CView::OnTimer(nIDEvent);
}
