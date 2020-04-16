
// 0302(3)View.cpp: CMy03023View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0302(3).h"
#endif

#include "0302(3)Doc.h"
#include "0302(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03023View

IMPLEMENT_DYNCREATE(CMy03023View, CView)

BEGIN_MESSAGE_MAP(CMy03023View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy03023View 构造/析构

CMy03023View::CMy03023View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03023View::~CMy03023View()
{
}

BOOL CMy03023View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03023View 绘图

void CMy03023View::OnDraw(CDC* pDC)
{
	CMy03023Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	CRect rect;
	this->GetClientRect(rect);
	pDC->Ellipse(rect);
}


// CMy03023View 打印

BOOL CMy03023View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03023View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03023View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03023View 诊断

#ifdef _DEBUG
void CMy03023View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03023View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03023Doc* CMy03023View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03023Doc)));
	return (CMy03023Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03023View 消息处理程序
