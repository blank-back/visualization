
// perinfoView.cpp : CperinfoView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "perinfo.h"
#endif

#include "perinfoDoc.h"
#include "perinfoView.h"
#include "infodlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CperinfoView

IMPLEMENT_DYNCREATE(CperinfoView, CView)

BEGIN_MESSAGE_MAP(CperinfoView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_BUTTON32772, &CperinfoView::OnButton32772)
	ON_BN_CLICKED(IDOK, &CperinfoView::OnBnClickedOk)
END_MESSAGE_MAP()

// CperinfoView 构造/析构

CperinfoView::CperinfoView()
{
	// TODO: 在此处添加构造代码

}

CperinfoView::~CperinfoView()
{
}

BOOL CperinfoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CperinfoView 绘制

void CperinfoView::OnDraw(CDC* pDC)
{
	CperinfoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//if(this->GetDocument()->start1)
	{
		CString temp1,temp2,temp,temp3,temp5,temp7;
		int temp4,temp6;
		this->GetDocument()->get(temp,temp1,temp2,temp3,temp4,temp6);
		if(temp4==0)
		temp5.Format(_T("是否有过编程经验:是"));
		else
		temp5.Format(_T("是否有过编程经验:否"));
		if(temp6==1)
		temp7.Format(_T("是否入学:是"));
		else
		temp7.Format(_T("是否入学:否"));
		pDC->TextOutW(0,0,_T("姓名:")+temp);
		pDC->TextOutW(0,50,_T("年龄:")+temp1);
		pDC->TextOutW(0,100,_T("性别:")+temp2);
		pDC->TextOutW(0,150,_T("民族:")+temp3);
		pDC->TextOutW(0,200,temp7);
		pDC->TextOutW(0,250,temp5);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CperinfoView 打印

BOOL CperinfoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CperinfoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CperinfoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CperinfoView 诊断

#ifdef _DEBUG
void CperinfoView::AssertValid() const
{
	CView::AssertValid();
}

void CperinfoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CperinfoDoc* CperinfoView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CperinfoDoc)));
	return (CperinfoDoc*)m_pDocument;
}
#endif //_DEBUG


// CperinfoView 消息处理程序


void CperinfoView::OnButton32772()
{
	// TODO: 在此添加命令处理程序代码
	infodlg*dlg=new infodlg(this->GetDocument(),this);
	dlg->DoModal();
}


void CperinfoView::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

}
