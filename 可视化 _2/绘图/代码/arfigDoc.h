
// arfigDoc.h : CarfigDoc ��Ľӿ�
//


#pragma once


class CarfigDoc : public CDocument
{
private:
	CPoint m_a;
	CSize m_b;
	CString m_c;
protected: // �������л�����
	CarfigDoc();
	DECLARE_DYNCREATE(CarfigDoc)

// ����
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	bool readover;
// ����
public:
	void set(CString&c,CPoint& a,CSize& b);
	void get(CString&c,CPoint& a,CSize& b);
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CarfigDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
