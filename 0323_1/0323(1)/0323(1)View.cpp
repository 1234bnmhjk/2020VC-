
// 0323(1)View.cpp: CMy03231View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0323(1).h"
#endif

#include "0323(1)Doc.h"
#include "0323(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03231View

IMPLEMENT_DYNCREATE(CMy03231View, CView)

BEGIN_MESSAGE_MAP(CMy03231View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_GradualCircle, &CMy03231View::OnGradualcircle)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy03231View 构造/析构

CMy03231View::CMy03231View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03231View::~CMy03231View()
{
}

BOOL CMy03231View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03231View 绘图

void CMy03231View::OnDraw(CDC* pDC)
{
	CMy03231Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	this->GetClientRect(&rect);

	point.x = (rect.right - rect.left) / 2;
	point.y = (rect.bottom - rect.top) / 2;

	CRect rect1(point.x - r, point.y - r, point.x + r, point.y + r);
	rect = rect1;

	pDC->Ellipse(rect);
}


// CMy03231View 打印

BOOL CMy03231View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03231View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03231View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03231View 诊断

#ifdef _DEBUG
void CMy03231View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03231View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03231Doc* CMy03231View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03231Doc)));
	return (CMy03231Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03231View 消息处理程序


void CMy03231View::OnGradualcircle()
{
	// TODO: 在此添加命令处理程序代码
	SetTimer(0, 100, NULL);
	
}


void CMy03231View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	r = t * 10;
	t++;
	Invalidate();
	CView::OnTimer(nIDEvent);
}
