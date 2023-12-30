
// perinfoView.cpp : CperinfoView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "perinfo.h"
#endif

#include "perinfoDoc.h"
#include "perinfoView.h"
#include "infodlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CperinfoView

IMPLEMENT_DYNCREATE(CperinfoView, CView)

BEGIN_MESSAGE_MAP(CperinfoView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_BUTTON32772, &CperinfoView::OnButton32772)
	ON_BN_CLICKED(IDOK, &CperinfoView::OnBnClickedOk)
END_MESSAGE_MAP()

// CperinfoView ����/����

CperinfoView::CperinfoView()
{
	// TODO: �ڴ˴���ӹ������

}

CperinfoView::~CperinfoView()
{
}

BOOL CperinfoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CperinfoView ����

void CperinfoView::OnDraw(CDC* pDC)
{
	CperinfoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//if(this->GetDocument()->start1)
	{
		CString temp1,temp2,temp,temp3,temp5,temp7;
		int temp4,temp6;
		this->GetDocument()->get(temp,temp1,temp2,temp3,temp4,temp6);
		if(temp4==0)
		temp5.Format(_T("�Ƿ��й���̾���:��"));
		else
		temp5.Format(_T("�Ƿ��й���̾���:��"));
		if(temp6==1)
		temp7.Format(_T("�Ƿ���ѧ:��"));
		else
		temp7.Format(_T("�Ƿ���ѧ:��"));
		pDC->TextOutW(0,0,_T("����:")+temp);
		pDC->TextOutW(0,50,_T("����:")+temp1);
		pDC->TextOutW(0,100,_T("�Ա�:")+temp2);
		pDC->TextOutW(0,150,_T("����:")+temp3);
		pDC->TextOutW(0,200,temp7);
		pDC->TextOutW(0,250,temp5);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CperinfoView ��ӡ

BOOL CperinfoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CperinfoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CperinfoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CperinfoView ���

#ifdef _DEBUG
void CperinfoView::AssertValid() const
{
	CView::AssertValid();
}

void CperinfoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CperinfoDoc* CperinfoView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CperinfoDoc)));
	return (CperinfoDoc*)m_pDocument;
}
#endif //_DEBUG


// CperinfoView ��Ϣ�������


void CperinfoView::OnButton32772()
{
	// TODO: �ڴ���������������
	infodlg*dlg=new infodlg(this->GetDocument(),this);
	dlg->DoModal();
}


void CperinfoView::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

}
