
// 0303(����ʵ��)View.h : CMy0303����ʵ��View ��Ľӿ�
//

#pragma once


class CMy0303����ʵ��View : public CView
{
protected: // �������л�����
	CMy0303����ʵ��View();
	DECLARE_DYNCREATE(CMy0303����ʵ��View)

// ����
public:
	CMy0303����ʵ��Doc* GetDocument() const;

// ����
public:

	CString name;

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
	virtual ~CMy0303����ʵ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 0303(����ʵ��)View.cpp �еĵ��԰汾
inline CMy0303����ʵ��Doc* CMy0303����ʵ��View::GetDocument() const
   { return reinterpret_cast<CMy0303����ʵ��Doc*>(m_pDocument); }
#endif

