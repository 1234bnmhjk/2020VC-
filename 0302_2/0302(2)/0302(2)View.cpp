
// 0302(2)View.cpp: CMy03022View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0302(2).h"
#endif

#include "0302(2)Doc.h"
#include "0302(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03022View

IMPLEMENT_DYNCREATE(CMy03022View, CView)

BEGIN_MESSAGE_MAP(CMy03022View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
//	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CMy03022View 构造/析构

CMy03022View::CMy03022View() noexcept
{
	// TODO: 在此处添加构造代码
	dc_.SetSize(100);
}

CMy03022View::~CMy03022View()
{
}

BOOL CMy03022View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03022View 绘图

void CMy03022View::OnDraw(CDC* pDC)
{
	CMy03022Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < dc_.GetSize(); i++)
		pDC->Ellipse(dc_.GetAt(i));
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy03022View 打印

BOOL CMy03022View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03022View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03022View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03022View 诊断

#ifdef _DEBUG
void CMy03022View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03022View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03022Doc* CMy03022View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03022Doc)));
	return (CMy03022Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03022View 消息处理程序


void CMy03022View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % 50 + 5;
	CRect cr(point.x - r, point.y - r, point.x + r, point.y + r);
	dc_.Add(cr);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

