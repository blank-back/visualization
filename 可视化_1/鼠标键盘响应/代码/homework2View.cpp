
// homework2View.cpp : Chomework2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
//�����������Ϣ����
BEGIN_MESSAGE_MAP(Chomework2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_MESSAGE(WM_MY_MESSAGE, OnMyMessage)//�Զ���
	ON_WM_LBUTTONDOWN()//��갴��
	ON_WM_LBUTTONUP()//������ָ�
	ON_WM_CHAR()//�����ַ�
END_MESSAGE_MAP()

// Chomework2View ����/����

Chomework2View::Chomework2View()
{
	// TODO: �ڴ˴���ӹ������

}

Chomework2View::~Chomework2View()
{
}

BOOL Chomework2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Chomework2View ����

void Chomework2View::OnDraw(CDC* /*pDC*/)
{
	Chomework2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Chomework2View ��ӡ

BOOL Chomework2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Chomework2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Chomework2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Chomework2View ���

#ifdef _DEBUG
void Chomework2View::AssertValid() const
{
	CView::AssertValid();
}

void Chomework2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Chomework2Doc* Chomework2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Chomework2Doc)));
	return (Chomework2Doc*)m_pDocument;
}
#endif //_DEBUG


// Chomework2View ��Ϣ�������
void Chomework2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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

//�Զ�����Ϣ����
LRESULT Chomework2View::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	// TODO: �ڴ˴����ʵ�ִ���.
	CString str;
	str.Format(L"personal message is %d and %d", wParam, lParam);
	MessageBox(str);
	return 0;
}
//ʵ�ֵ��������������Ƿ�ʹ��Ctrl����
void Chomework2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString str;
	//����Ctrl��������
	if((MK_CONTROL & nFlags)&& !(MK_SHIFT & nFlags))
		str.Format(L"������+Ctrl λ��(%d,%d)", point.x, point.y);
	//����Shift��������
	else if (!(MK_CONTROL & nFlags) && (MK_SHIFT & nFlags))
		str.Format(L"������+Shift λ��(%d,%d)", point.x, point.y);
	//ͬʱ����Ctrl��Shift��������
	else if ((MK_CONTROL & nFlags) && (MK_SHIFT & nFlags))
		str.Format(L"������+Ctrl+Shift λ��(%d,%d)", point.x, point.y);
	//����������
	else
		str.Format(L"������ λ��(%d,%d)", point.x, point.y);
	MessageBox(str);
	CView::OnLButtonDown(nFlags, point);
}
// ��Ӧ���ܼ�
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
	// ���»��ƿͻ���
	CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	CBrush brush;
	brush.CreateSolidBrush(RGB(255, 255, 255));
	pDC->SelectObject(&brush);
	pDC->Rectangle(rect);
	CView::OnLButtonUp(nFlags, point);
}

