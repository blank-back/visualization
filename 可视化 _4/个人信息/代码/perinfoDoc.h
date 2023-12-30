
// perinfoDoc.h : CperinfoDoc 类的接口
//


#pragma once


class CperinfoDoc : public CDocument
{
	CString name, age, sex, nation;
	int radio, check1;
protected: // 仅从序列化创建
	CperinfoDoc();
	DECLARE_DYNCREATE(CperinfoDoc)
	
// 特性
public:
	bool start1;
// 操作
public:
	void CperinfoDoc::set(CString&a,CString&b,CString&c,CString&d,int&e,int&f);
	void CperinfoDoc::get(CString&a,CString&b,CString&c,CString&d,int&e,int&f);
// 重写
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CperinfoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
