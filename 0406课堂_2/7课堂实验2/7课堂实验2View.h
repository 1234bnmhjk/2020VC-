
// 7����ʵ��2View.h : CMy7����ʵ��2View ��Ľӿ�
//

#pragma once


class CMy7����ʵ��2View : public CView
{
protected: // �������л�����
	CMy7����ʵ��2View();
	DECLARE_DYNCREATE(CMy7����ʵ��2View)

// ����
public:
	CMy7����ʵ��2Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy7����ʵ��2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 7����ʵ��2View.cpp �еĵ��԰汾
inline CMy7����ʵ��2Doc* CMy7����ʵ��2View::GetDocument() const
   { return reinterpret_cast<CMy7����ʵ��2Doc*>(m_pDocument); }
#endif

