
// 0303(3)View.cpp: CMy03033View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0303(3).h"
#endif

#include "0303(3)Doc.h"
#include "0303(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03033View

IMPLEMENT_DYNCREATE(CMy03033View, CView)

BEGIN_MESSAGE_MAP(CMy03033View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy03033View 构造/析构

CMy03033View::CMy03033View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03033View::~CMy03033View()
{
}

BOOL CMy03033View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03033View 绘图

void CMy03033View::OnDraw(CDC* /*pDC*/)
{
	CMy03033Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码

}


// CMy03033View 打印

BOOL CMy03033View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03033View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03033View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03033View 诊断

#ifdef _DEBUG
void CMy03033View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03033View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03033Doc* CMy03033View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03033Doc)));
	return (CMy03033Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03033View 消息处理程序


void CMy03033View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy03033Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString str;
	str.Format(_T("count的值:%d"), pDoc->count);

	CClientDC dc(this);
	dc.TextOutW(300, 300, str);
	CView::OnRButtonDown(nFlags, point);
}


void CMy03033View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy03033Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDoc->count++;

	CView::OnLButtonDown(nFlags, point);
}


void CMy03033View::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Invalidate();
	CView::OnRButtonUp(nFlags, point);
}
