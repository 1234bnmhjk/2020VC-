
// 0323(2)View.cpp: CMy03232View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0323(2).h"
#endif

#include "0323(2)Doc.h"
#include "0323(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03232View

IMPLEMENT_DYNCREATE(CMy03232View, CView)

BEGIN_MESSAGE_MAP(CMy03232View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ChCircle, &CMy03232View::OnChcircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy03232View 构造/析构

CMy03232View::CMy03232View() noexcept
{
	// TODO: 在此处添加构造代码
	
	set = true;
}

CMy03232View::~CMy03232View()
{
}

BOOL CMy03232View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03232View 绘图

void CMy03232View::OnDraw(CDC* pDC)
{
	CMy03232Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect cr;
	this->GetClientRect(&cr);
	CPoint point;
	point.x = (cr.right - cr.left) / 2;
	point.y = (cr.bottom - cr.top) / 2;

	CRect rect1(point.x - r,point.y - r, point.x + r, point.y + r);
	rect = rect1;
	CPen pen;
	a = rand() % 255;
	b = rand() % 255;
	c = rand() % 255;
	pen.CreatePen(PS_SOLID, 5, RGB(a, b, c));
	CPen* oldpen = pDC->SelectObject(&pen);
	pDC->Ellipse(rect);
	pen.DeleteObject();
}


// CMy03232View 打印

BOOL CMy03232View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03232View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03232View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03232View 诊断

#ifdef _DEBUG
void CMy03232View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03232View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03232Doc* CMy03232View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03232Doc)));
	return (CMy03232Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03232View 消息处理程序


void CMy03232View::OnChcircle()
{
	// TODO: 在此添加命令处理程序代码
	//pen.CreatePen(PS_SOLID, 1, RGB(a, b, c));
	SetTimer(0, 500, NULL);
}


void CMy03232View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	r = t * 10;
	t++;
	//pen.CreatePen(PS_SOLID, 1, RGB(a, b, c));
	Invalidate();
	CView::OnTimer(nIDEvent);
}
