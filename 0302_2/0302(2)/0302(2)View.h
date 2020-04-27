
// 0302(2)View.h: CMy03022View 类的接口
//

#pragma once


class CMy03022View : public CView
{
protected: // 仅从序列化创建
	CMy03022View() noexcept;
	DECLARE_DYNCREATE(CMy03022View)

// 特性
public:
	CMy03022Doc* GetDocument() const;

// 操作
public:
	CArray<CRect, CRect &> dc_;
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
	virtual ~CMy03022View();
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
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // 0302(2)View.cpp 中的调试版本
inline CMy03022Doc* CMy03022View::GetDocument() const
   { return reinterpret_cast<CMy03022Doc*>(m_pDocument); }
#endif

