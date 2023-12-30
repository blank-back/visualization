
// homewrok6View.h : Chomewrok6View 类的接口
//

#pragma once


class Chomewrok6View : public CScrollView
{
protected: // 仅从序列化创建
	Chomewrok6View();
	DECLARE_DYNCREATE(Chomewrok6View)

// 特性
public:
	Chomewrok6Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Chomewrok6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32775();
};

#ifndef _DEBUG  // homewrok6View.cpp 中的调试版本
inline Chomewrok6Doc* Chomewrok6View::GetDocument() const
   { return reinterpret_cast<Chomewrok6Doc*>(m_pDocument); }
#endif

