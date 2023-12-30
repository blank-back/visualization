
// homework3View.h : Chomework3View 类的接口
//

#pragma once


class Chomework3View : public CView
{
protected: // 仅从序列化创建
	Chomework3View();
	DECLARE_DYNCREATE(Chomework3View)

// 特性
public:
	Chomework3Doc* GetDocument() const;

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
	virtual ~Chomework3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void Chomework3View::OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStart();
	afx_msg void OnPause();
	afx_msg void On32777();
	afx_msg void On32778();
	afx_msg void OnSmallballAcc();
	afx_msg void OnSmallballBegin();
	afx_msg void OnSmallballPause();
	afx_msg void OnSmallballSlow();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAfxIdsScmove();
	afx_msg void OnAfxIdsScsize();
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
};

#ifndef _DEBUG  // homework3View.cpp 中的调试版本
inline Chomework3Doc* Chomework3View::GetDocument() const
   { return reinterpret_cast<Chomework3Doc*>(m_pDocument); }
#endif

