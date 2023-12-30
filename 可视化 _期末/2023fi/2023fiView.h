
// 2023fiView.h : CMy2023fiView 类的接口
//
#include"Dialog1.h"
#pragma once


class CMy2023fiView : public CView
{
protected: // 仅从序列化创建
	CMy2023fiView();
	DECLARE_DYNCREATE(CMy2023fiView)

// 特性
public:
	CMy2023fiDoc* GetDocument() const;

// 操作
public:
	void bmpmove();
	void Drawbmp();
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
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

// 实现
public:
	virtual ~CMy2023fiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // 2023fiView.cpp 中的调试版本
inline CMy2023fiDoc* CMy2023fiView::GetDocument() const
   { return reinterpret_cast<CMy2023fiDoc*>(m_pDocument); }
#endif

