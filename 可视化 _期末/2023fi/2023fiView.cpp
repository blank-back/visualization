
// 2023fiView.cpp : CMy2023fiView ���ʵ��
//
#include"Resource.h"
#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "2023fi.h"
#endif

#include "2023fiDoc.h"
#include "2023fiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy2023fiView

IMPLEMENT_DYNCREATE(CMy2023fiView, CView)

BEGIN_MESSAGE_MAP(CMy2023fiView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(testbtn, &CMy2023fiView::Ontestbtn)
	ON_COMMAND(testtool, &CMy2023fiView::OnTesttool)
	ON_WM_TIMER()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(IDR_POPUP_MENU, &CMy2023fiView::OnPopupMenu)
	ON_COMMAND(ID_POPUP_32776, &CMy2023fiView::OnPopup32776)
END_MESSAGE_MAP()

// CMy2023fiView ����/����

CMy2023fiView::CMy2023fiView()
{
	// TODO: �ڴ˴���ӹ������
}

CMy2023fiView::~CMy2023fiView()
{
}

BOOL CMy2023fiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy2023fiView ����

void CMy2023fiView::Drawbmp()
{
	CRect rect;
		GetClientRect(&rect);
		CMy2023fiDoc* pDoc = GetDocument();
 CDC*pDC=GetDC();
  CBitmap wtj_bitmap;
  CDC dcMemory;
  wtj_bitmap.LoadBitmap(IDB_BITMAP3);
  BITMAP bmInfo;
  wtj_bitmap.GetObject(sizeof(bmInfo),&bmInfo);
  dcMemory.CreateCompatibleDC(pDC);
  dcMemory.SelectObject(&wtj_bitmap);
  pDC->BitBlt(0,0, bmInfo.bmWidth,bmInfo.bmHeight, &dcMemory,0,0,SRCCOPY);
  pDoc->begin=true;
} 
void CMy2023fiView::changebmp()
{
	CRect rect;
	GetClientRect(&rect);
	CRect rectem(0,0,101,49);
	InvalidateRect(rectem,true);
	CRect rectem1;
		GetClientRect(&rectem1);
		CMy2023fiDoc* pDoc = GetDocument();
 CDC*pDC=GetDC();
  CBitmap wtj_bitmap;
  CDC dcMemory;
  wtj_bitmap.LoadBitmap(IDB_BITMAP3);
  BITMAP bmInfo;
  wtj_bitmap.GetObject(sizeof(bmInfo),&bmInfo);
  dcMemory.CreateCompatibleDC(pDC);
  dcMemory.SelectObject(&wtj_bitmap);
  pDC->BitBlt(rect.Width()-101,0, bmInfo.bmWidth,bmInfo.bmHeight, &dcMemory,0,0,SRCCOPY);
  pDoc->begin=true;
  this->UpdateWindow();
} 
void CMy2023fiView::Drawrectpen()
{
    CRect rect;
	CDC*pDC=GetDC();
    GetClientRect(&rect);

    /*CPen pen;
    pen.CreatePen(PS_SOLID, 1, RGB(169, 169, 169));
    HPEN oldPen = hdc->SelectPen(pen);
    rect.InflateRect(-2, -2, -12, -51);
    hdc.Rectangle(rect);
    hdc.SelectPen(oldPen);*/
	CBrush brush, *pOldbrush;
	brush.CreateHatchBrush(HS_CROSS, RGB(0, 0, 255));
	pOldbrush = pDC->SelectObject(&brush);
	pDC->Rectangle(rect.CenterPoint().x-80 , rect.CenterPoint().y-80, rect.CenterPoint().x+80, rect.CenterPoint().y+80);
	pDC->SelectObject(&brush);
	pDC->SelectObject(pOldbrush);
	brush.DeleteObject();
}
void CMy2023fiView::Drawrectpen1()
{
    CRect rect;
	CDC*pDC=GetDC();
    GetClientRect(&rect);

    /*CPen pen;
    pen.CreatePen(PS_SOLID, 1, RGB(169, 169, 169));
    HPEN oldPen = hdc->SelectPen(pen);
    rect.InflateRect(-2, -2, -12, -51);
    hdc.Rectangle(rect);
    hdc.SelectPen(oldPen);*/
	CBrush brush, *pOldbrush;
	brush.CreateSolidBrush(RGB(0, 0, 255));
	pOldbrush = pDC->SelectObject(&brush);
	pDC->Rectangle(rect.CenterPoint().x-80 , rect.CenterPoint().y-80, rect.CenterPoint().x+80, rect.CenterPoint().y+80);
	pDC->SelectObject(&brush);
	pDC->SelectObject(pOldbrush);
	brush.DeleteObject();
}
void CMy2023fiView::OnDraw(CDC* pDC)
{
	CMy2023fiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString a=CString("����������");
	pDC->SetTextColor(RGB(0, 128, 0));
	pDC->TextOutW(0,360,a);
	if(pDoc->begin==false)
	{
		Drawbmp();
		Drawrectpen();
	}
 ReleaseDC(pDC);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy2023fiView ��ӡ

BOOL CMy2023fiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy2023fiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy2023fiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy2023fiView ���

#ifdef _DEBUG
void CMy2023fiView::AssertValid() const
{
	CView::AssertValid();
}

void CMy2023fiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy2023fiDoc* CMy2023fiView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy2023fiDoc)));
	return (CMy2023fiDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy2023fiView ��Ϣ�������


void CMy2023fiView::Ontestbtn()
{
	// TODO: �ڴ���������������
	CDialog1 dlg;
	dlg.DoModal();
}


void CMy2023fiView::OnTesttool()
{
	// TODO: �ڴ���������������
	CDialog1 dlg;
	dlg.DoModal();
}

void CMy2023fiView::bmpmove()
{
	KillTimer(1);
		CRect rect;
	GetClientRect(&rect);
	newrect=CRect(rect.Width()-101,0,rect.Width(),49);
	destre=CRect(newrect);
	CRect rectem(0,0,101,49);
	InvalidateRect(rectem,true);
	//Drawbmp();
	SetTimer(1,70,NULL);
}

void CMy2023fiView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
  
	if(nIDEvent==1)
	{
		CDC*pDC=GetDC();
		CDC dcMemory;
		CBitmap *pOldBitmap;
		dcMemory.CreateCompatibleDC(pDC);
		  CBitmap bitmap;
		   bitmap.LoadBitmap(IDB_BITMAP3); 
		  pOldBitmap=dcMemory.SelectObject(&bitmap);
		  pDC->BitBlt(destre.left,destre.top,101,49, &dcMemory,0,0,SRCCOPY);
		  dcMemory.SelectObject(pOldBitmap);
		  newrect=destre;
		 UpdateWindow();
		newrect.left-=20;
		newrect.right-=20;
		if(newrect.left<0)
			newrect.left=0;
		Sleep(70);
  InvalidateRect(destre,true);
 destre.left=newrect.left;
 destre.right=newrect.right;
	}
	CView::OnTimer(nIDEvent);
}
BOOL CMy2023fiView::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message==WM_KEYDOWN)
	{
		if (pMsg->wParam==83||pMsg->wParam==115)
		{
			bmpmove();
		}
		if (pMsg->wParam==75||pMsg->wParam==107)
		{
			changebmp();
		}
	}
	return CView::PreTranslateMessage(pMsg);
}


void CMy2023fiView::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	// TODO: �ڴ˴������Ϣ����������
	CMenu menu;
    menu.LoadMenuW(IDR_MENU1);
    CMenu *pMenu=menu.GetSubMenu(0);
    pMenu->TrackPopupMenu(TPM_LEFTALIGN,point.x,point.y,this);
}


void CMy2023fiView::OnPopupMenu()
{
	// TODO: �ڴ���������������
	CRect rect;
    GetClientRect(&rect);
	InvalidateRect(CRect(rect.CenterPoint().x-80 , rect.CenterPoint().y-80, rect.CenterPoint().x+80, rect.CenterPoint().y+80),true);
	this->UpdateWindow();
	Drawrectpen1();
	this->UpdateWindow();
}


void CMy2023fiView::OnPopup32776()
{
	// TODO: �ڴ���������������
	CRect rect;
    GetClientRect(&rect);
	InvalidateRect(CRect(rect.CenterPoint().x-80 , rect.CenterPoint().y-80, rect.CenterPoint().x+80, rect.CenterPoint().y+80),true);
	this->UpdateWindow();
	Drawrectpen();
	this->UpdateWindow();
}
