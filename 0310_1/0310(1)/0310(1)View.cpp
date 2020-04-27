
// 0310(1)View.cpp: CMy03101View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0310(1).h"
#endif

#include "0310(1)Doc.h"
#include "0310(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03101View

IMPLEMENT_DYNCREATE(CMy03101View, CView)

BEGIN_MESSAGE_MAP(CMy03101View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMy03101View 构造/析构

CMy03101View::CMy03101View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03101View::~CMy03101View()
{
}

BOOL CMy03101View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03101View 绘图

void CMy03101View::OnDraw(CDC* /*pDC*/)
{
	CMy03101Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy03101View 打印

BOOL CMy03101View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03101View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03101View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03101View 诊断

#ifdef _DEBUG
void CMy03101View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03101View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03101Doc* CMy03101View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03101Doc)));
	return (CMy03101Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03101View 消息处理程序


void CMy03101View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CString str;
	str.Format(_T("左键正被按下"));

	CClientDC dc(this);
	dc.TextOutW(200, 200, str);
	CView::OnLButtonDown(nFlags, point);
}


void CMy03101View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	str.Format(_T("左键正在抬起"));

	CClientDC dc(this);
	dc.TextOutW(200, 200, str);
	CView::OnLButtonUp(nFlags, point);
}
