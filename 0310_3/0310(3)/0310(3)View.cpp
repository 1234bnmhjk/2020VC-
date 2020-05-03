
// 0310(3)View.cpp: CMy03103View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0310(3).h"
#endif

#include "0310(3)Doc.h"
#include "0310(3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03103View

IMPLEMENT_DYNCREATE(CMy03103View, CView)

BEGIN_MESSAGE_MAP(CMy03103View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy03103View 构造/析构

CMy03103View::CMy03103View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03103View::~CMy03103View()
{
}

BOOL CMy03103View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03103View 绘图

void CMy03103View::OnDraw(CDC* pDC)
{
	CMy03103Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect_1(30, 30, 200, 200);
	CRect rect_2(260, 30, 360, 200);
	CRect rect_3(110, 260, 310, 360);

	pDC->Rectangle(&rect_1);
	pDC->Rectangle(&rect_2);
	pDC->Rectangle(&rect_3);

	CString str1 ,str2 ,str3;
	str1 = _T("A");
	str2 = _T("B");
	str3 = _T("C");

	pDC->TextOutW(30, 30, str1);
	pDC->TextOutW(260, 30, str2);
	pDC->TextOutW(110, 260, str3);


	pDoc->A = rect_1;
	pDoc->B = rect_2;
	pDoc->C = rect_3;
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy03103View 打印

BOOL CMy03103View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03103View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03103View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03103View 诊断

#ifdef _DEBUG
void CMy03103View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03103View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03103Doc* CMy03103View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03103Doc)));
	return (CMy03103Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03103View 消息处理程序


void CMy03103View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy03103Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	//在矩形A中显示随机数
	if ((point.y >= pDoc->A.top) && (point.y <= pDoc->A.bottom)
		&& (point.x >= pDoc->A.left) && (point.x <= pDoc->A.right)) {
		pDoc->a = rand() % 100 + 1;
		CString str;
		str.Format(_T("%d"), pDoc->a);
		CClientDC dc(this);
		dc.TextOutW(point.x, point.y, str);
	}
	else if ((point.y >= pDoc->B.top) && (point.y <= pDoc->B.bottom)
		&& (point.x >= pDoc->B.left) && (point.x <= pDoc->B.right)) {//在矩形B中显示随机数
		pDoc->b = rand() % 100 + 1;
		CString str;
		str.Format(_T("%d"), pDoc->b);
		CClientDC dc(this);
		dc.TextOutW(point.x, point.y, str);
	}
	else if ((point.y >= pDoc->C.top) && (point.y <= pDoc->C.bottom)
		&& (point.x >= pDoc->C.left) && (point.x <= pDoc->C.right)) {//在矩形B中显示随机数
		int a = pDoc->a + pDoc->b;
		CString str;
		str.Format(_T("%d"), a);
		CClientDC dc(this);
		dc.TextOutW(point.x, point.y, str);
	}
	else {
		CString str;
		str.Format(_T("点击无效"));
		CClientDC dc(this);
		dc.TextOutW(point.x, point.y, str);
	}

	

	CView::OnLButtonDown(nFlags, point);
}


void CMy03103View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy03103Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (((point.y <= pDoc->A.top) || (point.y >= pDoc->A.bottom)
		|| (point.x <= pDoc->A.left) || (point.x >= pDoc->A.right))
		&& ((point.y <= pDoc->B.top) || (point.y >= pDoc->B.bottom)
		|| (point.x <= pDoc->B.left) || (point.x >= pDoc->B.right))
		&& ((point.y <= pDoc->C.top) || (point.y >= pDoc->C.bottom)
		|| (point.x <= pDoc->C.left) || (point.x >= pDoc->C.right))) {

		Invalidate();
	}
	CView::OnLButtonUp(nFlags, point);
}
