
// 0413(1)View.cpp: CMy04131View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0413(1).h"
#endif

#include "0413(1)Doc.h"
#include "0413(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04131View

IMPLEMENT_DYNCREATE(CMy04131View, CView)

BEGIN_MESSAGE_MAP(CMy04131View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
//	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMy04131View 构造/析构

CMy04131View::CMy04131View() noexcept
{
	// TODO: 在此处添加构造代码
	judge = false;

}

CMy04131View::~CMy04131View()
{
}

BOOL CMy04131View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy04131View 绘图

void CMy04131View::OnDraw(CDC* pDC)
{
	CMy04131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(&pDoc->rect);
}


// CMy04131View 打印

BOOL CMy04131View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy04131View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy04131View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy04131View 诊断

#ifdef _DEBUG
void CMy04131View::AssertValid() const
{
	CView::AssertValid();
}

void CMy04131View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy04131Doc* CMy04131View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04131Doc)));
	return (CMy04131Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy04131View 消息处理程序


void CMy04131View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	judge = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMy04131View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	judge = false;
	CView::OnLButtonUp(nFlags, point);
}


void CMy04131View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy04131Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (judge) {
		pDoc->rect.top = point.y - 100;
		pDoc->rect.left = point.x - 200;
		pDoc->rect.bottom = point.y + 100;
		pDoc->rect.right = point.x + 200;

		CClientDC dc(this);
		dc.Rectangle(&pDoc->rect);
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}


//void CMy04131View::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//					   // TODO: 在此处添加消息处理程序代码
//					   // 不为绘图消息调用 CView::OnPaint()
//	
//
//	dc.Rectangle(&rect);
//}
