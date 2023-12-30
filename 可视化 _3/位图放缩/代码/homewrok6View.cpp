
// homewrok6View.cpp : Chomewrok6View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &Chomewrok6View::On32771)
	ON_COMMAND(ID_32772, &Chomewrok6View::On32772)
	ON_COMMAND(ID_32773, &Chomewrok6View::On32773)
	ON_COMMAND(ID_32775, &Chomewrok6View::On32775)
END_MESSAGE_MAP()

// Chomewrok6View ����/����

Chomewrok6View::Chomewrok6View()
{
	// TODO: �ڴ˴���ӹ������

}

Chomewrok6View::~Chomewrok6View()
{
}

BOOL Chomewrok6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CScrollView::PreCreateWindow(cs);
}

// Chomewrok6View ����

void Chomewrok6View::OnDraw(CDC* /*pDC*/)
{
	Chomewrok6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void Chomewrok6View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = 800;
	sizeTotal.cy = 600;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Chomewrok6View ��ӡ

BOOL Chomewrok6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Chomewrok6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Chomewrok6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Chomewrok6View ���

#ifdef _DEBUG
void Chomewrok6View::AssertValid() const
{
	CScrollView::AssertValid();
}

void Chomewrok6View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Chomewrok6Doc* Chomewrok6View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Chomewrok6Doc)));
	return (Chomewrok6Doc*)m_pDocument;
}
#endif //_DEBUG


// Chomewrok6View ��Ϣ�������


void Chomewrok6View::On32771()
{
	// TODO: �ڴ���������������
	this->Invalidate();
	this->UpdateWindow();
	CDC*dc=GetDC();   //��ʾ�豸
	CBitmap bitmap;
	CBitmap *pOldBitmap;
	CDC memDC;
	memDC.CreateCompatibleDC(dc);   //�����豸����������ʾ�豸����
	bitmap.LoadBitmap(IDB_BITMAP5);  //ȡ��λͼ��Դ
	pOldBitmap = memDC.SelectObject(&bitmap);  //��λͼѡ���ڴ滷��
	dc->StretchBlt(0, 0, 320, 240, &memDC, 0, 0, 320, 240, SRCCOPY);  //��ʾ
	memDC.SelectObject(pOldBitmap);
	this->UpdateWindow();
}


void Chomewrok6View::On32772()
{
	// TODO: �ڴ���������������
	this->Invalidate();
	this->UpdateWindow();
	CDC*dc=GetDC();   //��ʾ�豸
	CBitmap bitmap;
	CBitmap *pOldBitmap;
	CDC memDC;
	memDC.CreateCompatibleDC(dc);   //�����豸����������ʾ�豸����
	bitmap.LoadBitmap(IDB_BITMAP5);  //ȡ��λͼ��Դ
	pOldBitmap = memDC.SelectObject(&bitmap);  //��λͼѡ���ڴ滷��
	dc->StretchBlt(0, 0, 640, 480, &memDC, 0, 0, 320, 240, SRCCOPY);  //��ʾ
	memDC.SelectObject(pOldBitmap);
	this->UpdateWindow();
}


void Chomewrok6View::On32773()
{
	// TODO: �ڴ���������������
	this->Invalidate();
	this->UpdateWindow();
	CDC*dc=GetDC();   //��ʾ�豸
	CBitmap bitmap;
	CBitmap *pOldBitmap;
	CDC memDC;
	memDC.CreateCompatibleDC(dc);   //�����豸����������ʾ�豸����
	bitmap.LoadBitmap(IDB_BITMAP5);  //ȡ��λͼ��Դ
	pOldBitmap = memDC.SelectObject(&bitmap);  //��λͼѡ���ڴ滷��
	dc->StretchBlt(0, 0, 160, 120, &memDC, 0, 0, 320, 240, SRCCOPY);  //��ʾ
	memDC.SelectObject(pOldBitmap);
	this->UpdateWindow();
}


void Chomewrok6View::On32775()
{
	// TODO: �ڴ���������������
		this->Invalidate();
	this->UpdateWindow();
	CDC*dc=GetDC();   //��ʾ�豸
	CBitmap bitmap;
	CBitmap *pOldBitmap;
	CDC memDC;
	memDC.CreateCompatibleDC(dc);   //�����豸����������ʾ�豸����
	bitmap.LoadBitmap(IDB_BITMAP5);  //ȡ��λͼ��Դ
	pOldBitmap = memDC.SelectObject(&bitmap);  //��λͼѡ���ڴ滷��
	dc->StretchBlt(0, 0, 1280, 960, &memDC, 0, 0, 320, 240, SRCCOPY);  //��ʾ
	memDC.SelectObject(pOldBitmap);
	this->UpdateWindow();
}
