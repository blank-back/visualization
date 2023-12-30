
// arfigView.h : CarfigView 类的接口
//

#pragma once


class CarfigView : public CView
{
protected: // 仅从序列化创建
	CarfigView();
	DECLARE_DYNCREATE(CarfigView);

// 特性
public:
	CarfigDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CarfigView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // arfigView.cpp 中的调试版本
inline CarfigDoc* CarfigView::GetDocument() const
   { return reinterpret_cast<CarfigDoc*>(m_pDocument); }
#endif

