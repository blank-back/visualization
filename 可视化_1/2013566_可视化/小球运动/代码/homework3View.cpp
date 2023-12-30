
// homework3View.cpp : Chomework3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
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

// Chomework3View ����/����

Chomework3View::Chomework3View()
{
	// TODO: �ڴ˴���ӹ������

}

Chomework3View::~Chomework3View()
{
}

BOOL Chomework3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	return CView::PreCreateWindow(cs);
}

// Chomework3View ����

void Chomework3View::OnDraw(CDC* /*pDC*/)
{
	Chomework3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Chomework3View ��ӡ

BOOL Chomework3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Chomework3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Chomework3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}
//��ɫ�л�����
bool flage = 0;
// ��ɫ�洢
std::vector<std::vector<int>>  rgb_store;
//ԭ�����
int x=0,y=0;
int begint=300;
double moveX=5*sqrt(2.0);
double moveY=5*sqrt(2.0);
void Chomework3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ


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
		//���������ɫ
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
		// ����
		CBrush brush;
		brush.CreateSolidBrush(RGB(red,green,blue));
		pDC->SelectObject(&brush);
		pDC->Ellipse(x, y, x + 30, y + 30);
	}
	
	CView::OnTimer(nIDEvent);
}
//ֹͣ



// Chomework3View ���

#ifdef _DEBUG
void Chomework3View::AssertValid() const
{
	CView::AssertValid();
}

void Chomework3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Chomework3Doc* Chomework3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Chomework3Doc)));
	return (Chomework3Doc*)m_pDocument;
}
#endif //_DEBUG


// Chomework3View ��Ϣ�������




void Chomework3View::OnSmallballPause()
{
	// TODO: �ڴ���������������
	KillTimer(1);
}
//����
void Chomework3View::OnSmallballAcc()
{
	begint-=50;
	OnSmallballPause();
	OnSmallballBegin();
}
//����
void Chomework3View::OnSmallballSlow()
{
	begint+=50;
	OnSmallballPause();
	OnSmallballBegin();
}
//��ʼ
void Chomework3View::OnSmallballBegin()
{
	// TODO: �ڴ���������������
	SetTimer(1, begint, NULL);
}

void Chomework3View::OnAfxIdsScmove()
{

	// TODO: �ڴ���������������
	SetWindowPos(&wndTopMost, 100, 500, 0, 0,  SWP_NOSIZE /*| SWP_NOMOVE*/);
	SetWindowPos(&wndTopMost, 100, 500, 0, 0,  SWP_NOMOVE /*| SWP_NOMOVE*/);
}


void Chomework3View::OnAfxIdsScsize()
{
	// TODO: �ڴ���������������
	SetWindowPos(&wndTopMost,800,700, 0, 0,  SWP_NOSIZE /*| SWP_NOMOVE*/);
	SetWindowPos(&wndTopMost,800, 700, 0, 0,  SWP_NOMOVE /*| SWP_NOMOVE*/);

}


void Chomework3View::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	
}
