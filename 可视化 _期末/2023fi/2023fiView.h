
// 2023fiView.h : CMy2023fiView ��Ľӿ�
//
#include"Dialog1.h"
#pragma once


class CMy2023fiView : public CView
{
protected: // �������л�����
	CMy2023fiView();
	DECLARE_DYNCREATE(CMy2023fiView)

// ����
public:
	CMy2023fiDoc* GetDocument() const;

// ����
public:
	void bmpmove();
	void Drawbmp();
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL CMy2023fiView::PreTranslateMessage(MSG* pMsg);
	void changebmp();
	void Drawrectpen();
	void Drawrectpen1();
	CRect newrect,destre;
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy2023fiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Ontestbtn();
	afx_msg void OnTesttool();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnPopupMenu();
	afx_msg void OnPopup32776();
};

#ifndef _DEBUG  // 2023fiView.cpp �еĵ��԰汾
inline CMy2023fiDoc* CMy2023fiView::GetDocument() const
   { return reinterpret_cast<CMy2023fiDoc*>(m_pDocument); }
#endif

