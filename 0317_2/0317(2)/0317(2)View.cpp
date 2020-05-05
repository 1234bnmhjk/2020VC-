
// 0317(2)View.cpp: CMy03172View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0317(2).h"
#endif

#include "0317(2)Doc.h"
#include "0317(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03172View

IMPLEMENT_DYNCREATE(CMy03172View, CView)

BEGIN_MESSAGE_MAP(CMy03172View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
//	ON_WM_MOUSEMOVE()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy03172View 构造/析构

CMy03172View::CMy03172View() noexcept
{
	
}

CMy03172View::~CMy03172View()
{
}

BOOL CMy03172View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03172View 绘图

void CMy03172View::OnDraw(CDC* pDC)
{
	CMy03172Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->Rectangle(pDoc->rect);
	// TODO: 在此处为本机数据添加绘制代码
}


// CMy03172View 打印

BOOL CMy03172View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03172View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03172View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03172View 诊断

#ifdef _DEBUG
void CMy03172View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03172View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03172Doc* CMy03172View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03172Doc)));
	return (CMy03172Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03172View 消息处理程序


void CMy03172View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy03172Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	
	switch (nChar) {
	case VK_LEFT: {
		if (pDoc->rect.left > 0) {
			pDoc->rect.left -= 5;
			pDoc->rect.right -= 5;
		}
		break;
	}
	case VK_RIGHT: {
		if (pDoc->rect.right <= (clientRect.right - clientRect.left)) {
			pDoc->rect.left += 5;
			pDoc->rect.right += 5;
		}
		break;
	}
	case VK_UP: {
		if (pDoc->rect.top > 0) {
			pDoc->rect.top -= 5;
			pDoc->rect.bottom -= 5;
		}
		break;
	}
	case VK_DOWN: {
		if (pDoc->rect.bottom <= (clientRect.bottom - clientRect.top)) {
			pDoc->rect.top += 5;
			pDoc->rect.bottom += 5;
		}
		break;
	}
	case VK_HOME: {
		pDoc->rect.left -= 10;
		pDoc->rect.top -= 5;
		break;
	}
	case VK_END: {
		pDoc->rect.left += 10;
		pDoc->rect.top += 5;
		break;
	}

	}
	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy03172View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMy03172Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	
	GetClientRect(&clientRect);
	pDoc->cpoint.x = clientRect.left + (clientRect.right - clientRect.left) / 2;
	pDoc->cpoint.y = clientRect.top + (clientRect.bottom - clientRect.top) / 2;
	pDoc->rect.left = pDoc->cpoint.x - 200;
	pDoc->rect.top = pDoc->cpoint.y - 100;
	pDoc->rect.right = pDoc->cpoint.x + 200;
	pDoc->rect.bottom = pDoc->cpoint.y + 100;

	InvalidateRect(NULL, TRUE);

	CView::OnLButtonDown(nFlags, point);
}
