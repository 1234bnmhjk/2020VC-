
// 0302(1)View.cpp: CMy03021View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0302(1).h"
#endif

#include "0302(1)Doc.h"
#include "0302(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03021View

IMPLEMENT_DYNCREATE(CMy03021View, CView)

BEGIN_MESSAGE_MAP(CMy03021View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy03021View 构造/析构

CMy03021View::CMy03021View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03021View::~CMy03021View()
{
}

BOOL CMy03021View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03021View 绘图

void CMy03021View::OnDraw(CDC* /*pDC*/)
{
	CMy03021Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy03021View 打印

BOOL CMy03021View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03021View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03021View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03021View 诊断

#ifdef _DEBUG
void CMy03021View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03021View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03021Doc* CMy03021View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03021Doc)));
	return (CMy03021Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03021View 消息处理程序


void CMy03021View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	dc.SetViewportOrg(point);
	CPoint pointOri;
	int m_rand = 100;//半径随机的最大范围为100
	int r = rand() % m_rand;
	dc.Ellipse(pointOri.x - r, pointOri.y - r, pointOri.x + r, pointOri.y + r);
	OnDraw(&dc);
	CView::OnLButtonDown(nFlags, point);
}
