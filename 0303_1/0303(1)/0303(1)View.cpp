
// 0303(1)View.cpp: CMy03031View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0303(1).h"
#endif

#include "0303(1)Doc.h"
#include "0303(1)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03031View

IMPLEMENT_DYNCREATE(CMy03031View, CView)

BEGIN_MESSAGE_MAP(CMy03031View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy03031View 构造/析构

CMy03031View::CMy03031View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy03031View::~CMy03031View()
{
}

BOOL CMy03031View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03031View 绘图

void CMy03031View::OnDraw(CDC* pDC)
{
	CMy03031Doc* pDoc = GetDocument();

	CString S = _T("我是***");
	int A = 39;
	CString str;
	str.Format(L"%d", A);

	pDC->TextOutW(200, 200, S);
	pDC->TextOutW(200, 300, str);

	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy03031View 打印

BOOL CMy03031View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03031View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03031View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03031View 诊断

#ifdef _DEBUG
void CMy03031View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03031View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03031Doc* CMy03031View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03031Doc)));
	return (CMy03031Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03031View 消息处理程序
