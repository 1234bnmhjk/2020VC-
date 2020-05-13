
// 0413(1)View.h: CMy04131View 类的接口
//

#pragma once


class CMy04131View : public CView
{
protected: // 仅从序列化创建
	CMy04131View() noexcept;
	DECLARE_DYNCREATE(CMy04131View)

// 特性
public:
	CMy04131Doc* GetDocument() const;

// 操作
public:

	bool judge;
	CPoint m_point;

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
	virtual ~CMy04131View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
//	afx_msg void OnPaint();
};

#ifndef _DEBUG  // 0413(1)View.cpp 中的调试版本
inline CMy04131Doc* CMy04131View::GetDocument() const
   { return reinterpret_cast<CMy04131Doc*>(m_pDocument); }
#endif

