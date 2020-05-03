
// 0310(课外实验）View.cpp: CMy0310课外实验View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0310(课外实验）.h"
#endif

#include "0310(课外实验）Doc.h"
#include "0310(课外实验）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0310课外实验View

IMPLEMENT_DYNCREATE(CMy0310课外实验View, CView)

BEGIN_MESSAGE_MAP(CMy0310课外实验View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy0310课外实验View 构造/析构

CMy0310课外实验View::CMy0310课外实验View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy0310课外实验View::~CMy0310课外实验View()
{
}

BOOL CMy0310课外实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0310课外实验View 绘图

void CMy0310课外实验View::OnDraw(CDC* pDC)
{
	CMy0310课外实验Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect_1(30, 30, 200, 200);
	CRect rect_2(220, 30, 390, 200);
	CRect rect_3(30, 220, 200, 390);
	CRect rect_4(220, 220, 390, 390);

	pDC->Rectangle(&rect_1);
	pDC->Rectangle(&rect_2);
	pDC->Rectangle(&rect_3);
	pDC->Rectangle(&rect_4);

	CString str1, str2, str3, str4;
	str1 = _T("A");
	str2 = _T("B");
	str3 = _T("C");
	str4 = _T("D");

	pDC->TextOutW(20, 30, str1);
	pDC->TextOutW(210, 30, str2);
	pDC->TextOutW(20, 220, str3);
	pDC->TextOutW(210, 220, str4);


	pDoc->A = rect_1;
	pDoc->B = rect_2;
	pDoc->C = rect_3;
	pDoc->D = rect_4;
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy0310课外实验View 打印

BOOL CMy0310课外实验View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0310课外实验View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0310课外实验View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0310课外实验View 诊断

#ifdef _DEBUG
void CMy0310课外实验View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0310课外实验View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0310课外实验Doc* CMy0310课外实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0310课外实验Doc)));
	return (CMy0310课外实验Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0310课外实验View 消息处理程序


void CMy0310课外实验View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy0310课外实验Doc* pDoc = GetDocument();
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
		&& (point.x >= pDoc->C.left) && (point.x <= pDoc->C.right)) {//在矩形C中显示随机数
		int a;
		if (pDoc->count == 1) a = pDoc->a + pDoc->b;
		else if(pDoc->count == 2) a = pDoc->a - pDoc->b;
		else if (pDoc->count == 3) a = pDoc->a * pDoc->b;
		else if (pDoc->count == 4) a = pDoc->a / pDoc->b;
		CString str;
		str.Format(_T("%d"), a);
		CClientDC dc(this);
		dc.TextOutW(point.x, point.y, str);
	}
	else if ((point.y >= pDoc->D.top) && (point.y <= pDoc->D.bottom)
		&& (point.x >= pDoc->D.left) && (point.x <= pDoc->D.right)) {//在矩形D中显示算术符号
		++pDoc->count;
		CString str;
		if (pDoc->count == 1) str = _T("+");
		else if (pDoc->count == 2) str = _T("-");
		else if (pDoc->count == 3) str = _T("*");
		else if (pDoc->count == 4) str = _T("/");
		CClientDC dc(this);
		CBrush brush = dc.GetBkColor();
		CBrush *newbrush = dc.SelectObject(&brush);
		dc.Rectangle(pDoc->D.top, pDoc->D.left, pDoc->D.bottom, pDoc->D.right);
		dc.SelectObject(newbrush);
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


void CMy0310课外实验View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy0310课外实验Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (((point.y <= pDoc->A.top) || (point.y >= pDoc->A.bottom)
		|| (point.x <= pDoc->A.left) || (point.x >= pDoc->A.right))
		&& ((point.y <= pDoc->B.top) || (point.y >= pDoc->B.bottom)
			|| (point.x <= pDoc->B.left) || (point.x >= pDoc->B.right))
		&& ((point.y <= pDoc->C.top) || (point.y >= pDoc->C.bottom)
			|| (point.x <= pDoc->C.left) || (point.x >= pDoc->C.right))
		&& ((point.y <= pDoc->D.top) || (point.y >= pDoc->D.bottom)
			|| (point.x <= pDoc->D.left) || (point.x >= pDoc->D.right))) {

		Invalidate();
	}
	CView::OnLButtonUp(nFlags, point);
}
