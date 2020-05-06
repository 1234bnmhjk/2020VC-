
// 0324(2)View.cpp: CMy03242View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0324(2).h"
#endif

#include "0324(2)Doc.h"
#include "0324(2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03242View

IMPLEMENT_DYNCREATE(CMy03242View, CView)

BEGIN_MESSAGE_MAP(CMy03242View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy03242View 构造/析构

CMy03242View::CMy03242View() noexcept
{
	// TODO: 在此处添加构造代码

	BITMAP BM;
	bitmap.LoadBitmapW(IDB_BITMAP1);
	bitmap.GetBitmap(&BM);
	b_width = BM.bmWidth;
	b_height = BM.bmHeight;

}

CMy03242View::~CMy03242View()
{
}

BOOL CMy03242View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy03242View 绘图

void CMy03242View::OnDraw(CDC* pDC)
{
	CMy03242Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC MenDC;
	MenDC.CreateCompatibleDC(NULL);
	MenDC.SelectObject(bitmap);
	pDC->BitBlt(0, 0, b_width, b_height, &MenDC, 0, 0, SRCCOPY);
}


// CMy03242View 打印

BOOL CMy03242View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy03242View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy03242View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy03242View 诊断

#ifdef _DEBUG
void CMy03242View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03242View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03242Doc* CMy03242View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03242Doc)));
	return (CMy03242Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03242View 消息处理程序
