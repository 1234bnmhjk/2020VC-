
// 0324(3)View.h: CMy03243View 类的接口
//

#pragma once


class CMy03243View : public CView
{
protected: // 仅从序列化创建
	CMy03243View() noexcept;
	DECLARE_DYNCREATE(CMy03243View)

// 特性
public:
	CMy03243Doc* GetDocument() const;

// 操作
public:

	bool judge;
	int set;
	CPoint startpoint, endpoint;
	CRect rect;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMy03243View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCross();
	afx_msg void OnDrawellipse();
	afx_msg void OnDrawrectangle();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0324(3)View.cpp 中的调试版本
inline CMy03243Doc* CMy03243View::GetDocument() const
   { return reinterpret_cast<CMy03243Doc*>(m_pDocument); }
#endif

