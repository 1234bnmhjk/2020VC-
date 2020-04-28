
// 0310(2)View.cpp: CMy03102View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0310(2).h"
#endif

#include "0310(2)Doc.h"
#include "0310(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03102View

IMPLEMENT_DYNCREATE(CMy03102View, CView)

BEGIN_MESSAGE_MAP(CMy03102View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy03102View 构造/析构

CMy03102View::CMy03102View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03102View::~CMy03102View()
{
}

BOOL CMy03102View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03102View 绘图

void CMy03102View::OnDraw(CDC* /*pDC*/)
{
	CMy03102Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy03102View 打印

BOOL CMy03102View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03102View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03102View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03102View 诊断

#ifdef _DEBUG
void CMy03102View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03102View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03102Doc* CMy03102View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03102Doc)));
	return (CMy03102Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03102View 消息处理程序


void CMy03102View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy03102Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int C = pDoc->A + pDoc->B;
	CString str;
	str.Format(_T("A + B = %d"), C);

	CClientDC dc(this);
	dc.TextOutW(300, 200, str);

	CView::OnLButtonDown(nFlags, point);
}
