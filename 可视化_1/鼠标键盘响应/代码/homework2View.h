
// homework2View.h : Chomework2View ��Ľӿ�
//
#define WM_MY_MESSAGE WM_USER+200
#pragma once


class Chomework2View : public CView
{
protected: // �������л�����
	Chomework2View();
	DECLARE_DYNCREATE(Chomework2View)

// ����
public:
	Chomework2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
	BOOL PreTranslateMessage(MSG* pMsg);

	
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Chomework2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // homework2View.cpp �еĵ��԰汾
inline Chomework2Doc* Chomework2View::GetDocument() const
   { return reinterpret_cast<Chomework2Doc*>(m_pDocument); }
#endif

