
// inputView.h : CinputView ��Ľӿ�
//

#pragma once


class CinputView : public CView
{
protected: // �������л�����
	CinputView();
	DECLARE_DYNCREATE(CinputView)

// ����
public:
	CinputDoc* GetDocument() const;

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
	virtual ~CinputView();
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
	
	afx_msg void On32772();
};

#ifndef _DEBUG  // inputView.cpp �еĵ��԰汾
inline CinputDoc* CinputView::GetDocument() const
   { return reinterpret_cast<CinputDoc*>(m_pDocument); }
#endif

