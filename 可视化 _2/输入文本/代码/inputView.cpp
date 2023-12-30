
// inputView.cpp : CinputView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CinputView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	
	ON_COMMAND(ID_32772, &CinputView::On32772)
END_MESSAGE_MAP()

// CinputView ����/����

CinputView::CinputView()
{
	// TODO: �ڴ˴���ӹ������

}

CinputView::~CinputView()
{
}

BOOL CinputView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CinputView ����

void CinputView::OnDraw(CDC* /*pDC*/)
{
	CDC* pDc=GetDC();
	CinputDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect rect1;
	this->GetClientRect(rect1);
	pDc->TextOut(0, rect1.bottom-rect1.top-20, pDoc->m_a);

	
}


// CinputView ��ӡ


void CinputView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CinputView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CinputView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CinputView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CinputView ���

#ifdef _DEBUG
void CinputView::AssertValid() const
{
	CView::AssertValid();
}

void CinputView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CinputDoc* CinputView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CinputDoc)));
	return (CinputDoc*)m_pDocument;
}
#endif //_DEBUG


// CinputView ��Ϣ�������




void CinputView::On32772()
{
	// TODO: �ڴ���������������
	newdialog a1;
	a1.DoModal();
}
