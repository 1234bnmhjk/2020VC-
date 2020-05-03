
// 0310(3)View.h: CMy03103View 类的接口
//

#pragma once


class CMy03103View : public CView
{
protected: // 仅从序列化创建
	CMy03103View() noexcept;
	DECLARE_DYNCREATE(CMy03103View)

// 特性
public:
	CMy03103Doc* GetDocument() const;

// 操作
public:

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
	virtual ~CMy03103View();
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
};

#ifndef _DEBUG  // 0310(3)View.cpp 中的调试版本
inline CMy03103Doc* CMy03103View::GetDocument() const
   { return reinterpret_cast<CMy03103Doc*>(m_pDocument); }
#endif

