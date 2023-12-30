
// perinfoView.h : CperinfoView ��Ľӿ�
//
#pragma once


class CperinfoView : public CView
{
protected: // �������л�����
	CperinfoView();
	DECLARE_DYNCREATE(CperinfoView)

// ����
public:
	CperinfoDoc* GetDocument() const;
// ����
public:
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CperinfoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnButton32772();
	afx_msg void OnBnClickedOk();
};

#ifndef _DEBUG  // perinfoView.cpp �еĵ��԰汾
inline CperinfoDoc* CperinfoView::GetDocument() const
   { return reinterpret_cast<CperinfoDoc*>(m_pDocument); }
#endif

