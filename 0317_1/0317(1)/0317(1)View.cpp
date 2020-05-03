
// 0317(1)View.cpp: CMy03171View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0317(1).h"
#endif

#include "0317(1)Doc.h"
#include "0317(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03171View

IMPLEMENT_DYNCREATE(CMy03171View, CView)

BEGIN_MESSAGE_MAP(CMy03171View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy03171View 构造/析构

CMy03171View::CMy03171View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03171View::~CMy03171View()
{
}

BOOL CMy03171View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03171View 绘图

void CMy03171View::OnDraw(CDC* /*pDC*/)
{
	CMy03171Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy03171View 打印

BOOL CMy03171View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03171View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03171View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03171View 诊断

#ifdef _DEBUG
void CMy03171View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03171View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03171Doc* CMy03171View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03171Doc)));
	return (CMy03171Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03171View 消息处理程序


void CMy03171View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	judge = true;
	startpoint = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMy03171View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int x;
	endpoint = point;
	if (judge) {
		judge = false;
		CClientDC dc(this);
		
		CString str;
		str.Format(_T("MouseMove移动了%d次"), count);
		dc.TextOutW(20, 20, str);

		if ((startpoint.x - endpoint.x) > 0)
			x = startpoint.x - endpoint.x;
		else x = endpoint.x - startpoint.x;
		str.Format(_T("横向移动了%d个像素"), x);
		dc.TextOutW(20, 50, str);
		count = 0;
	}
	CView::OnLButtonUp(nFlags, point);
}


void CMy03171View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (judge) {
		count++;
	}
	CView::OnMouseMove(nFlags, point);
}
