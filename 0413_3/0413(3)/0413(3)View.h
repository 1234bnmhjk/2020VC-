
// 0413(3)View.h: CMy04133View 类的接口
//

#pragma once


class CMy04133View : public CView
{
protected: // 仅从序列化创建
	CMy04133View() noexcept;
	DECLARE_DYNCREATE(CMy04133View)

// 特性
public:
	CMy04133Doc* GetDocument() const;

// 操作
public:

	CRect rect;
	bool set, m_move, m_LorR, judge;
	CPoint point;

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
	virtual ~CMy04133View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 0413(3)View.cpp 中的调试版本
inline CMy04133Doc* CMy04133View::GetDocument() const
   { return reinterpret_cast<CMy04133Doc*>(m_pDocument); }
#endif

