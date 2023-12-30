
// arfigDoc.h : CarfigDoc 类的接口
//


#pragma once


class CarfigDoc : public CDocument
{
private:
	CPoint m_a;
	CSize m_b;
	CString m_c;
protected: // 仅从序列化创建
	CarfigDoc();
	DECLARE_DYNCREATE(CarfigDoc)

// 特性
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	bool readover;
// 操作
public:
	void set(CString&c,CPoint& a,CSize& b);
	void get(CString&c,CPoint& a,CSize& b);
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CarfigDoc();
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
