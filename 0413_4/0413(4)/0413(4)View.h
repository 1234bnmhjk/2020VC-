
// 0413(4)View.h: CMy04134View 类的接口
//

#pragma once


class CMy04134View : public CView
{
protected: // 仅从序列化创建
	CMy04134View() noexcept;
	DECLARE_DYNCREATE(CMy04134View)

// 特性
public:
	CMy04134Doc* GetDocument() const;

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
	virtual ~CMy04134View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShows();
};

#ifndef _DEBUG  // 0413(4)View.cpp 中的调试版本
inline CMy04134Doc* CMy04134View::GetDocument() const
   { return reinterpret_cast<CMy04134Doc*>(m_pDocument); }
#endif

