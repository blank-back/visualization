
// homework4View.h : Chomework4View 类的接口
//

#pragma once
#include "atltypes.h"


class Chomework4View : public CView
{
protected: // 仅从序列化创建
	Chomework4View();
	DECLARE_DYNCREATE(Chomework4View)

// 特性
public:
	Chomework4Doc* GetDocument() const;
	void bitrun();
	double offset;
// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Chomework4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // homework4View.cpp 中的调试版本
inline Chomework4Doc* Chomework4View::GetDocument() const
   { return reinterpret_cast<Chomework4Doc*>(m_pDocument); }
#endif

