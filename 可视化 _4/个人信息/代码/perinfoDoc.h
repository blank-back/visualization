
// perinfoDoc.h : CperinfoDoc ��Ľӿ�
//


#pragma once


class CperinfoDoc : public CDocument
{
	CString name, age, sex, nation;
	int radio, check1;
protected: // �������л�����
	CperinfoDoc();
	DECLARE_DYNCREATE(CperinfoDoc)
	
// ����
public:
	bool start1;
// ����
public:
	void CperinfoDoc::set(CString&a,CString&b,CString&c,CString&d,int&e,int&f);
	void CperinfoDoc::get(CString&a,CString&b,CString&c,CString&d,int&e,int&f);
// ��д
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CperinfoDoc();
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
