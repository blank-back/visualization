
// homework4View.h : Chomework4View ��Ľӿ�
//

#pragma once
#include "atltypes.h"


class Chomework4View : public CView
{
protected: // �������л�����
	Chomework4View();
	DECLARE_DYNCREATE(Chomework4View)

// ����
public:
	Chomework4Doc* GetDocument() const;
	void bitrun();
	double offset;
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Chomework4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
public:
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CRect destre;
	CPoint destpos;
};

#ifndef _DEBUG  // homework4View.cpp �еĵ��԰汾
inline Chomework4Doc* Chomework4View::GetDocument() const
   { return reinterpret_cast<Chomework4Doc*>(m_pDocument); }
#endif

