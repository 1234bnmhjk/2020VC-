
// 0413(3)View.cpp: CMy04133View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0413(3).h"
#endif

#include "0413(3)Doc.h"
#include "0413(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04133View

IMPLEMENT_DYNCREATE(CMy04133View, CView)

BEGIN_MESSAGE_MAP(CMy04133View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy04133View 构造/析构

CMy04133View::CMy04133View() noexcept
{
	// TODO: 在此处添加构造代码
	set = true;
	m_move = true;
	m_LorR = true;
	judge = true;

	//CRect rt(100, 0, 120, 20);
	//rect = rt;

}

CMy04133View::~CMy04133View()
{
}

BOOL CMy04133View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy04133View 绘图

void CMy04133View::OnDraw(CDC* pDC)
{
	CMy04133Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (judge) {
		CRect rc;
		this->GetClientRect(&rc);
		point.x = 0;
		point.y = (rc.bottom - rc.top) / 2;

		rect.left = point.x;
		rect.top = point.y - 20;
		rect.right = point.x + 40;
		rect.bottom = point.y + 20;

		judge = false;
	}
	if (set) {
		SetTimer(0, 50, NULL);
		set = false;
	}
	pDC->Ellipse(rect);
}


// CMy04133View 打印

BOOL CMy04133View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy04133View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy04133View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy04133View 诊断

#ifdef _DEBUG
void CMy04133View::AssertValid() const
{
	CView::AssertValid();
}

void CMy04133View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy04133Doc* CMy04133View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04133Doc)));
	return (CMy04133Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy04133View 消息处理程序


void CMy04133View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect cr;
	this->GetClientRect(&cr);
	if (m_LorR && m_move) {
		if ((rect.right <= cr.right)) {
			rect.left += 10;
			rect.right += 10;
		}
		else m_LorR = false;
	}
	else if(m_move) {
		if ((rect.left >= cr.left)) {
			rect.left -= 10;
			rect.right -= 10;
		}
		else m_LorR = true;
	}
	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMy04133View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_move = false;
	CView::OnLButtonDblClk(nFlags, point);
}


void CMy04133View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_move = true;
	CView::OnLButtonDown(nFlags, point);
}
