
// 7����ʵ��View.cpp : CMy7����ʵ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "7����ʵ��.h"
#endif

#include "7����ʵ��Doc.h"
#include "7����ʵ��View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy7����ʵ��View

IMPLEMENT_DYNCREATE(CMy7����ʵ��View, CView)

BEGIN_MESSAGE_MAP(CMy7����ʵ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHOW, &CMy7����ʵ��View::OnShow)
END_MESSAGE_MAP()

// CMy7����ʵ��View ����/����

CMy7����ʵ��View::CMy7����ʵ��View()
{
	// TODO:  �ڴ˴���ӹ������

}

CMy7����ʵ��View::~CMy7����ʵ��View()
{
}

BOOL CMy7����ʵ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy7����ʵ��View ����

void CMy7����ʵ��View::OnDraw(CDC* /*pDC*/)
{
	CMy7����ʵ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy7����ʵ��View ��ӡ

BOOL CMy7����ʵ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy7����ʵ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy7����ʵ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMy7����ʵ��View ���

#ifdef _DEBUG
void CMy7����ʵ��View::AssertValid() const
{
	CView::AssertValid();
}

void CMy7����ʵ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy7����ʵ��Doc* CMy7����ʵ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy7����ʵ��Doc)));
	return (CMy7����ʵ��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy7����ʵ��View ��Ϣ�������


void CMy7����ʵ��View::OnShow()
{
	// TODO:  �ڴ���������������
	MyDlg dlg;
	
	if (dlg.DoModal() == IDCANCEL){
		CClientDC dc(this);
		CString str;
		str.Format(_T("�����˳��Ի���"));

		dc.TextOutW(50, 50, str);
	}
}
