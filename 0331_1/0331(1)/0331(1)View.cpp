
// 0331(1)View.cpp: CMy03311View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0331(1).h"
#endif

#include "0331(1)Doc.h"
#include "0331(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03311View

IMPLEMENT_DYNCREATE(CMy03311View, CView)

BEGIN_MESSAGE_MAP(CMy03311View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy03311View 构造/析构

CMy03311View::CMy03311View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03311View::~CMy03311View()
{
}

BOOL CMy03311View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03311View 绘图

void CMy03311View::OnDraw(CDC* /*pDC*/)
{
	CMy03311Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy03311View 打印

BOOL CMy03311View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03311View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03311View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03311View 诊断

#ifdef _DEBUG
void CMy03311View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03311View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03311Doc* CMy03311View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03311Doc)));
	return (CMy03311Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03311View 消息处理程序
