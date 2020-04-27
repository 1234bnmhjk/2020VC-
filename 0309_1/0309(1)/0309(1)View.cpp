
// 0309(1)View.cpp: CMy03091View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0309(1).h"
#endif

#include "0309(1)Doc.h"
#include "0309(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03091View

IMPLEMENT_DYNCREATE(CMy03091View, CView)

BEGIN_MESSAGE_MAP(CMy03091View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy03091View 构造/析构

CMy03091View::CMy03091View() noexcept
{
	// TODO: 在此处添加构造代码
	ca.SetSize(100);
}

CMy03091View::~CMy03091View()
{
}

BOOL CMy03091View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03091View 绘图

void CMy03091View::OnDraw(CDC* pDC)
{
	CMy03091Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca.GetAt(i));
}


// CMy03091View 打印

BOOL CMy03091View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03091View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03091View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03091View 诊断

#ifdef _DEBUG
void CMy03091View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03091View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03091Doc* CMy03091View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03091Doc)));
	return (CMy03091Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03091View 消息处理程序


void CMy03091View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect cr;
	this->GetClientRect(cr);
	CPoint cpoint;
	cpoint.x = cr.left + (cr.right - cr.left) / 2;
	cpoint.y = cr.top + (cr.bottom - cr.top) / 2;

	int r;
	if ((cr.right - cr.left) >= (cr.bottom - cr.top))
		r = (cr.bottom - cr.top) / 2;
	else
		r = (cr.right - cr.left) / 2;
	CRect rect(cpoint.x - r, cpoint.y - r, cpoint.x + r, cpoint.y + r);
	ca.Add(rect);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
