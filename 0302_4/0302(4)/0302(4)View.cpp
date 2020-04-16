
// 0302(4)View.cpp: CMy03024View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0302(4).h"
#endif

#include "0302(4)Doc.h"
#include "0302(4)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03024View

IMPLEMENT_DYNCREATE(CMy03024View, CView)

BEGIN_MESSAGE_MAP(CMy03024View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy03024View 构造/析构

CMy03024View::CMy03024View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03024View::~CMy03024View()
{
}

BOOL CMy03024View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03024View 绘图

void CMy03024View::OnDraw(CDC* pDC)
{
	CMy03024Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect rect;
	this->GetClientRect(rect);
	CBrush newbrush(RGB(200,0,200));
	CBrush *poldbrush;
	poldbrush = pDC->SelectObject(&newbrush);
	pDC->Ellipse(rect);

}


// CMy03024View 打印

BOOL CMy03024View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03024View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03024View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03024View 诊断

#ifdef _DEBUG
void CMy03024View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03024View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03024Doc* CMy03024View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03024Doc)));
	return (CMy03024Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03024View 消息处理程序
