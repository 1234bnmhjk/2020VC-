
// 7����ʵ��2View.cpp : CMy7����ʵ��2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "7����ʵ��2.h"
#endif

#include "7����ʵ��2Doc.h"
#include "7����ʵ��2View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy7����ʵ��2View

IMPLEMENT_DYNCREATE(CMy7����ʵ��2View, CView)

BEGIN_MESSAGE_MAP(CMy7����ʵ��2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy7����ʵ��2View ����/����

CMy7����ʵ��2View::CMy7����ʵ��2View()
{
	// TODO:  �ڴ˴���ӹ������
	MyDlg dlg;
	dlg.DoModal();

}

CMy7����ʵ��2View::~CMy7����ʵ��2View()
{
}

BOOL CMy7����ʵ��2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy7����ʵ��2View ����

void CMy7����ʵ��2View::OnDraw(CDC* /*pDC*/)
{
	CMy7����ʵ��2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy7����ʵ��2View ��ӡ

BOOL CMy7����ʵ��2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy7����ʵ��2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy7����ʵ��2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy7����ʵ��2View ���

#ifdef _DEBUG
void CMy7����ʵ��2View::AssertValid() const
{
	CView::AssertValid();
}

void CMy7����ʵ��2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy7����ʵ��2Doc* CMy7����ʵ��2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy7����ʵ��2Doc)));
	return (CMy7����ʵ��2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy7����ʵ��2View ��Ϣ�������
