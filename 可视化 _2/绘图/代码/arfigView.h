
// arfigView.h : CarfigView ��Ľӿ�
//

#pragma once


class CarfigView : public CView
{
protected: // �������л�����
	CarfigView();
	DECLARE_DYNCREATE(CarfigView);

// ����
public:
	CarfigDoc* GetDocument() const;

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
	virtual ~CarfigView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	void drawimg();
	afx_msg void On32771();
	afx_msg void On32772();
};

#ifndef _DEBUG  // arfigView.cpp �еĵ��԰汾
inline CarfigDoc* CarfigView::GetDocument() const
   { return reinterpret_cast<CarfigDoc*>(m_pDocument); }
#endif

