
// homework2View.h : Chomework2View 类的接口
//
#define WM_MY_MESSAGE WM_USER+200
#pragma once


class Chomework2View : public CView
{
protected: // 仅从序列化创建
	Chomework2View();
	DECLARE_DYNCREATE(Chomework2View)

// 特性
public:
	Chomework2Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
	BOOL PreTranslateMessage(MSG* pMsg);

	
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Chomework2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // homework2View.cpp 中的调试版本
inline Chomework2Doc* Chomework2View::GetDocument() const
   { return reinterpret_cast<Chomework2Doc*>(m_pDocument); }
#endif

