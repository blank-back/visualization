
// homework3View.h : Chomework3View ��Ľӿ�
//

#pragma once


class Chomework3View : public CView
{
protected: // �������л�����
	Chomework3View();
	DECLARE_DYNCREATE(Chomework3View)

// ����
public:
	Chomework3Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Chomework3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // homework3View.cpp �еĵ��԰汾
inline Chomework3Doc* Chomework3View::GetDocument() const
   { return reinterpret_cast<Chomework3Doc*>(m_pDocument); }
#endif

