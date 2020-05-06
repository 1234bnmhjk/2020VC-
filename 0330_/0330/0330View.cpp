
// 0330View.cpp: CMy0330View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "0330.h"
#endif

#include "0330Doc.h"
#include "0330View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0330View

IMPLEMENT_DYNCREATE(CMy0330View, CView)

BEGIN_MESSAGE_MAP(CMy0330View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CMy0330View::OnFileOpen)
END_MESSAGE_MAP()

// CMy0330View 构造/析构

CMy0330View::CMy0330View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMy0330View::~CMy0330View()
{
}

BOOL CMy0330View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMy0330View 绘图

void CMy0330View::OnDraw(CDC* /*pDC*/)
{
	CMy0330Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMy0330View 打印

BOOL CMy0330View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMy0330View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMy0330View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMy0330View 诊断

#ifdef _DEBUG
void CMy0330View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0330View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0330Doc* CMy0330View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0330Doc)));
	return (CMy0330Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0330View 消息处理程序


void CMy0330View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();

	CClientDC dc(this);

	if (r == IDOK) {

		CString filename = cfd.GetPathName();
		CImage img;
		img.Load(filename);//先与文件建立关联
		int w, h, sx, sy;
		{
			CRect rect;
			GetClientRect(&rect);
			float rect_ratio = 1.0 * rect.Width() / rect.Height();
			float img_ratio = 1.0 * img.GetWidth() / img.GetHeight();

			if (rect_ratio > img_ratio) {
				h = rect.Height();
				w = img_ratio * h;
				sx = (rect.Width() - w) / 2;
				sy = 0;
			}
			else {
				w = rect.Width();
				h = w / img_ratio;
				sx = 0;
				sy = (rect.Height() - h) / 2;
			}
		}
		
		img.Draw(dc.m_hDC, sx, sy, w, h);
	}
}
