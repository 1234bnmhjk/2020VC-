
// 0303(课外实验)View.cpp : CMy0303课外实验View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0303(课外实验).h"
#endif

#include "0303(课外实验)Doc.h"
#include "0303(课外实验)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0303课外实验View

IMPLEMENT_DYNCREATE(CMy0303课外实验View, CView)

BEGIN_MESSAGE_MAP(CMy0303课外实验View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy0303课外实验View 构造/析构

CMy0303课外实验View::CMy0303课外实验View()
{
	// TODO:  在此处添加构造代码
	name.Format(_T("郭韵萧"));
}

CMy0303课外实验View::~CMy0303课外实验View()
{
}

BOOL CMy0303课外实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0303课外实验View 绘制

void CMy0303课外实验View::OnDraw(CDC* pDC)
{
	CMy0303课外实验Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	CString str;
	str = name + pDoc->number;
	pDC->TextOutW(100, 100, str);
}


// CMy0303课外实验View 打印

BOOL CMy0303课外实验View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0303课外实验View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy0303课外实验View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy0303课外实验View 诊断

#ifdef _DEBUG
void CMy0303课外实验View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0303课外实验View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0303课外实验Doc* CMy0303课外实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0303课外实验Doc)));
	return (CMy0303课外实验Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0303课外实验View 消息处理程序
