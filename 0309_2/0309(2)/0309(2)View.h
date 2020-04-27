
// 0309(2)View.h: CMy03092View 类的接口
//

#pragma once


class CMy03092View : public CView
{
protected: // 仅从序列化创建
	CMy03092View() noexcept;
	DECLARE_DYNCREATE(CMy03092View)

// 特性
public:
	CMy03092Doc* GetDocument() const;

// 操作
public:
	CArray <CRect, CRect&> ca;
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
	virtual ~CMy03092View();
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
};

#ifndef _DEBUG  // 0309(2)View.cpp 中的调试版本
inline CMy03092Doc* CMy03092View::GetDocument() const
   { return reinterpret_cast<CMy03092Doc*>(m_pDocument); }
#endif

