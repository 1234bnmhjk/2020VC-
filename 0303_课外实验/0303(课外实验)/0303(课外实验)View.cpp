
// 0303(����ʵ��)View.cpp : CMy0303����ʵ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "0303(����ʵ��).h"
#endif

#include "0303(����ʵ��)Doc.h"
#include "0303(����ʵ��)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy0303����ʵ��View

IMPLEMENT_DYNCREATE(CMy0303����ʵ��View, CView)

BEGIN_MESSAGE_MAP(CMy0303����ʵ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy0303����ʵ��View ����/����

CMy0303����ʵ��View::CMy0303����ʵ��View()
{
	// TODO:  �ڴ˴���ӹ������
	name.Format(_T("������"));
}

CMy0303����ʵ��View::~CMy0303����ʵ��View()
{
}

BOOL CMy0303����ʵ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy0303����ʵ��View ����

void CMy0303����ʵ��View::OnDraw(CDC* pDC)
{
	CMy0303����ʵ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CString str;
	str = name + pDoc->number;
	pDC->TextOutW(100, 100, str);
}


// CMy0303����ʵ��View ��ӡ

BOOL CMy0303����ʵ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy0303����ʵ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy0303����ʵ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy0303����ʵ��View ���

#ifdef _DEBUG
void CMy0303����ʵ��View::AssertValid() const
{
	CView::AssertValid();
}

void CMy0303����ʵ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy0303����ʵ��Doc* CMy0303����ʵ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy0303����ʵ��Doc)));
	return (CMy0303����ʵ��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy0303����ʵ��View ��Ϣ�������
