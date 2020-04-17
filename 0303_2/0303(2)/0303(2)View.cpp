
// 0303(2)View.cpp: CMy03032View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0303(2).h"
#endif

#include "0303(2)Doc.h"
#include "0303(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03032View

IMPLEMENT_DYNCREATE(CMy03032View, CView)

BEGIN_MESSAGE_MAP(CMy03032View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy03032View 构造/析构

CMy03032View::CMy03032View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03032View::~CMy03032View()
{
}

BOOL CMy03032View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03032View 绘图

void CMy03032View::OnDraw(CDC* pDC)
{
	CMy03032Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString str;
	str.Format(L"%d", pDoc->A);

	pDC->TextOutW(200, 200, pDoc->S);
	pDC->TextOutW(200, 300, str);
}


// CMy03032View 打印

BOOL CMy03032View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03032View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03032View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03032View 诊断

#ifdef _DEBUG
void CMy03032View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03032View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03032Doc* CMy03032View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03032Doc)));
	return (CMy03032Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03032View 消息处理程序
