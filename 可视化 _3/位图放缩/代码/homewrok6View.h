
// homewrok6View.h : Chomewrok6View ��Ľӿ�
//

#pragma once


class Chomewrok6View : public CScrollView
{
protected: // �������л�����
	Chomewrok6View();
	DECLARE_DYNCREATE(Chomewrok6View)

// ����
public:
	Chomewrok6Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Chomewrok6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32775();
};

#ifndef _DEBUG  // homewrok6View.cpp �еĵ��԰汾
inline Chomewrok6Doc* Chomewrok6View::GetDocument() const
   { return reinterpret_cast<Chomewrok6Doc*>(m_pDocument); }
#endif

