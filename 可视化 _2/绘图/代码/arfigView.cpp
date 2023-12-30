
// arfigView.cpp : CarfigView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CarfigView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CarfigView::On32771)
	ON_COMMAND(ID_32772, &CarfigView::On32772)
END_MESSAGE_MAP()

// CarfigView ����/����

CarfigView::CarfigView()
{
	// TODO: �ڴ˴���ӹ������
}

CarfigView::~CarfigView()
{
}

BOOL CarfigView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CarfigView ����

void CarfigView::OnDraw(CDC* /*pDC*/)
{
	CarfigDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CDC* pDc = GetDC();
	CarfigDoc*pdoc=GetDocument();
	CRect rect1;
	CPoint m_a;
	CSize m_b;
	CString m_c;
	pdoc->get(m_c,m_a,m_b);
	this->GetClientRect(rect1);	
	CRect rect(m_a,m_b);
	if(m_c=="��Բ")
		pDc->Ellipse(rect);
	else
	pDc->Rectangle(rect);
	ReleaseDC(pDc);
}


// CarfigView ��ӡ


void CarfigView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CarfigView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CarfigView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CarfigView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
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


// CarfigView ���

#ifdef _DEBUG
void CarfigView::AssertValid() const
{
	CView::AssertValid();
}

void CarfigView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CarfigDoc* CarfigView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CarfigDoc)));
	return (CarfigDoc*)m_pDocument;
}
#endif //_DEBUG


// CarfigView ��Ϣ�������


void CarfigView::On32771()
{
	// TODO: �ڴ���������������
	this->Invalidate();
	this->UpdateWindow();
	CDC* pDc = GetDC();
	CarfigDoc*pdoc=GetDocument();
	CRect rect1;
	this->GetClientRect(rect1);
	int ra=max((rand()%(rect1.right-rect1.left/2)/4)*4,200);
	pdoc->set(CString("��Բ"),CPoint(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y-ra/4),CSize(ra,ra/2));	
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
	if(m_c=="��Բ")
		pDc->Ellipse(rect);
	else
	pDc->Rectangle(rect);
	ReleaseDC(pDc);
}

void CarfigView::On32772()
{
	// TODO: �ڴ���������������
	this->Invalidate();
	this->UpdateWindow();
	CDC* pDc = GetDC();
	CarfigDoc*pdoc=GetDocument();
	CRect rect1;
	this->GetClientRect(rect1);

	
	int ra=max((rand()%(rect1.right-rect1.left/2)/4)*4,200);
	pdoc->set(CString("����"),CPoint(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y-ra/4),CSize(ra,ra/2));	
	CRect rect(CPoint(rect1.CenterPoint().x-ra/2,rect1.CenterPoint().y-ra/4),CSize(ra,ra/2));
	pDc->Rectangle(rect);
	ReleaseDC(pDc);
}

