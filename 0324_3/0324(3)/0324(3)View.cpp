
// 0324(3)View.cpp: CMy03243View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0324(3).h"
#endif

#include "0324(3)Doc.h"
#include "0324(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03243View

IMPLEMENT_DYNCREATE(CMy03243View, CView)

BEGIN_MESSAGE_MAP(CMy03243View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_Cross, &CMy03243View::OnCross)
	ON_COMMAND(ID_DrawEllipse, &CMy03243View::OnDrawellipse)
	ON_COMMAND(ID_DrawRectangle, &CMy03243View::OnDrawrectangle)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy03243View 构造/析构

CMy03243View::CMy03243View() noexcept
{
	// TODO: 在此处添加构造代码
	judge = false;

}

CMy03243View::~CMy03243View()
{
}

BOOL CMy03243View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03243View 绘图

void CMy03243View::OnDraw(CDC* /*pDC*/)
{
	CMy03243Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy03243View 打印

BOOL CMy03243View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03243View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03243View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03243View 诊断

#ifdef _DEBUG
void CMy03243View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03243View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03243Doc* CMy03243View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03243Doc)));
	return (CMy03243Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03243View 消息处理程序


void CMy03243View::OnCross()
{
	// TODO: 在此添加命令处理程序代码
	set = 2;
}


void CMy03243View::OnDrawellipse()
{
	// TODO: 在此添加命令处理程序代码
	set = 3;
}


void CMy03243View::OnDrawrectangle()
{
	// TODO: 在此添加命令处理程序代码
	set = 1;
}


void CMy03243View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	startpoint = point;
	endpoint = point;
	judge = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMy03243View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	judge = false;
	CView::OnLButtonUp(nFlags, point);
}


void CMy03243View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (judge) {
		CClientDC dc(this);

		CBrush brush = dc.GetBkColor();
		CBrush *newbrush = dc.SelectObject(&brush);
		int oldMove = dc.SetROP2(R2_NOTXORPEN);

		switch (set) {
		case 1:
			dc.MoveTo(startpoint);
			dc.LineTo(endpoint);
			dc.MoveTo(startpoint);
			dc.LineTo(point);
			endpoint = point;
			break;
		case 2:
			dc.Rectangle(&CRect(startpoint, endpoint));
			dc.Rectangle(&CRect(startpoint, point));
			endpoint = point;
			break;
		case 3:
			dc.Ellipse(&CRect(startpoint, endpoint));
			dc.Ellipse(&CRect(startpoint, point));
			endpoint = point;
			break;
		}

		dc.SelectObject(newbrush);
		dc.SetROP2(oldMove);
	}
	CView::OnMouseMove(nFlags, point);
}
