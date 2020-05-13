
// 7课堂实验2View.cpp : CMy7课堂实验2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "7课堂实验2.h"
#endif

#include "7课堂实验2Doc.h"
#include "7课堂实验2View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy7课堂实验2View

IMPLEMENT_DYNCREATE(CMy7课堂实验2View, CView)

BEGIN_MESSAGE_MAP(CMy7课堂实验2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy7课堂实验2View 构造/析构

CMy7课堂实验2View::CMy7课堂实验2View()
{
	// TODO:  在此处添加构造代码
	MyDlg dlg;
	dlg.DoModal();

}

CMy7课堂实验2View::~CMy7课堂实验2View()
{
}

BOOL CMy7课堂实验2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy7课堂实验2View 绘制

void CMy7课堂实验2View::OnDraw(CDC* /*pDC*/)
{
	CMy7课堂实验2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMy7课堂实验2View 打印

BOOL CMy7课堂实验2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy7课堂实验2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMy7课堂实验2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMy7课堂实验2View 诊断

#ifdef _DEBUG
void CMy7课堂实验2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy7课堂实验2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy7课堂实验2Doc* CMy7课堂实验2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy7课堂实验2Doc)));
	return (CMy7课堂实验2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy7课堂实验2View 消息处理程序
