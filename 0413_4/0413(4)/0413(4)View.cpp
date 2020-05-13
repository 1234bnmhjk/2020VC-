
// 0413(4)View.cpp: CMy04134View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0413(4).h"
#endif

#include "0413(4)Doc.h"
#include "0413(4)View.h"
#include "ShowString.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04134View

IMPLEMENT_DYNCREATE(CMy04134View, CView)

BEGIN_MESSAGE_MAP(CMy04134View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_ShowS, &CMy04134View::OnShows)
END_MESSAGE_MAP()

// CMy04134View 构造/析构

CMy04134View::CMy04134View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy04134View::~CMy04134View()
{
}

BOOL CMy04134View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy04134View 绘图

void CMy04134View::OnDraw(CDC* /*pDC*/)
{
	CMy04134Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy04134View 打印

BOOL CMy04134View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy04134View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy04134View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy04134View 诊断

#ifdef _DEBUG
void CMy04134View::AssertValid() const
{
	CView::AssertValid();
}

void CMy04134View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy04134Doc* CMy04134View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04134Doc)));
	return (CMy04134Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy04134View 消息处理程序


void CMy04134View::OnShows()
{
	// TODO: 在此添加命令处理程序代码
	ShowString dlg;
	dlg.DoModal();
}
