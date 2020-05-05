
// 0317(3)View.h: CMy03173View 类的接口
//

#pragma once


class CMy03173View : public CView
{
protected: // 仅从序列化创建
	CMy03173View() noexcept;
	DECLARE_DYNCREATE(CMy03173View)

// 特性
public:
	CMy03173Doc* GetDocument() const;

// 操作
public:
	CRect rect;
	bool set;
	bool c;
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
	virtual ~CMy03173View();
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
};

#ifndef _DEBUG  // 0317(3)View.cpp 中的调试版本
inline CMy03173Doc* CMy03173View::GetDocument() const
   { return reinterpret_cast<CMy03173Doc*>(m_pDocument); }
#endif

