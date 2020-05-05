
// 0323(1)View.h: CMy03231View 类的接口
//

#pragma once


class CMy03231View : public CView
{
protected: // 仅从序列化创建
	CMy03231View() noexcept;
	DECLARE_DYNCREATE(CMy03231View)

// 特性
public:
	CMy03231Doc* GetDocument() const;

// 操作
public:

	CPoint point;
	CRect rect;
	int r = 0;
	int t = 1;

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
	virtual ~CMy03231View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnGradualcircle();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 0323(1)View.cpp 中的调试版本
inline CMy03231Doc* CMy03231View::GetDocument() const
   { return reinterpret_cast<CMy03231Doc*>(m_pDocument); }
#endif

