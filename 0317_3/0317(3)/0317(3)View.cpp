
// 0317(3)View.cpp: CMy03173View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0317(3).h"
#endif

#include "0317(3)Doc.h"
#include "0317(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03173View

IMPLEMENT_DYNCREATE(CMy03173View, CView)

BEGIN_MESSAGE_MAP(CMy03173View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy03173View 构造/析构

CMy03173View::CMy03173View() noexcept
{
	// TODO: 在此处添加构造代码
	set = true;
	c = true;
	CRect rect1(100, 0, 120, 20);
	rect = rect1;
}

CMy03173View::~CMy03173View()
{
}

BOOL CMy03173View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03173View 绘图

void CMy03173View::OnDraw(CDC* pDC)
{
	CMy03173Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set) {
		SetTimer(0,20, NULL);
		set = false;
	}
	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(rect);
}


// CMy03173View 打印

BOOL CMy03173View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03173View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03173View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03173View 诊断

#ifdef _DEBUG
void CMy03173View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03173View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03173Doc* CMy03173View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03173Doc)));
	return (CMy03173Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03173View 消息处理程序


void CMy03173View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect cr;
	this->GetClientRect(&cr);
	if (c) {
		if ((rect.bottom <= cr.bottom)) {
			rect.top += 10;
			rect.bottom += 10;
		}
		else c = false;
	}
	else {
		if ((rect.top >= cr.top)) {
			rect.top -= 10;
			rect.bottom -= 10;
		}
		else c = true;
	}
	

	Invalidate();
	CView::OnTimer(nIDEvent);
}
