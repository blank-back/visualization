
// perinfoView.h : CperinfoView 类的接口
//
#pragma once


class CperinfoView : public CView
{
protected: // 仅从序列化创建
	CperinfoView();
	DECLARE_DYNCREATE(CperinfoView)

// 特性
public:
	CperinfoDoc* GetDocument() const;
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
	virtual ~CperinfoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnButton32772();
	afx_msg void OnBnClickedOk();
};

#ifndef _DEBUG  // perinfoView.cpp 中的调试版本
inline CperinfoDoc* CperinfoView::GetDocument() const
   { return reinterpret_cast<CperinfoDoc*>(m_pDocument); }
#endif

