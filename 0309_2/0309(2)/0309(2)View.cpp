
// 0309(2)View.cpp: CMy03092View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0309(2).h"
#endif

#include "0309(2)Doc.h"
#include "0309(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03092View

IMPLEMENT_DYNCREATE(CMy03092View, CView)

BEGIN_MESSAGE_MAP(CMy03092View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy03092View 构造/析构

CMy03092View::CMy03092View() noexcept
{
	// TODO: 在此处添加构造代码
	ca.SetSize(100);
}

CMy03092View::~CMy03092View()
{
}

BOOL CMy03092View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03092View 绘图

void CMy03092View::OnDraw(CDC* pDC)
{
	CMy03092Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < ca.GetSize(); i++)
		pDC->Ellipse(ca.GetAt(i));
}


// CMy03092View 打印

BOOL CMy03092View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03092View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03092View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03092View 诊断

#ifdef _DEBUG
void CMy03092View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03092View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03092Doc* CMy03092View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03092Doc)));
	return (CMy03092Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03092View 消息处理程序


void CMy03092View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r1 = rand() % 50 + 5;
	int r2 = rand() % 50 + 5;

	CRect rect(point.x - r1, point.y - r2, point.x + r1, point.y + r2);
	ca.Add(rect);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
