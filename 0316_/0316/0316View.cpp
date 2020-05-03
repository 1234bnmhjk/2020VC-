
// 0316View.cpp: CMy0316View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0316.h"
#endif

#include "0316Doc.h"
#include "0316View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0316View

IMPLEMENT_DYNCREATE(CMy0316View, CView)

BEGIN_MESSAGE_MAP(CMy0316View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy0316View 构造/析构

CMy0316View::CMy0316View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy0316View::~CMy0316View()
{
}

BOOL CMy0316View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0316View 绘图

void CMy0316View::OnDraw(CDC* /*pDC*/)
{
	CMy0316Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy0316View 打印

BOOL CMy0316View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0316View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0316View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0316View 诊断

#ifdef _DEBUG
void CMy0316View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0316View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0316Doc* CMy0316View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0316Doc)));
	return (CMy0316Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0316View 消息处理程序


void CMy0316View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (judge) {
		CClientDC dc(this);
		CString str;
		str.Format(_T("X = %d Y = %d"), point.x, point.y);
		dc.TextOutW(20, 20, str);

		CBrush brush = dc.GetBkColor();
		CBrush *newbrush = dc.SelectObject(&brush);

		int oldMove = dc.SetROP2(R2_NOTXORPEN);

		dc.Rectangle(&CRect(begin,now));
		dc.Rectangle(&CRect(begin,point));

		now = point;

		dc.SelectObject(newbrush);
		dc.SetROP2(oldMove);
	}
	CView::OnMouseMove(nFlags, point);
}


void CMy0316View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	judge = true;
	begin = point;
	now = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMy0316View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (judge) {
		judge = false;
	}
	CView::OnLButtonUp(nFlags, point);
}
