
// 0303(1)View.h: CMy03031View 类的接口
//

#pragma once


class CMy03031View : public CView
{
protected: // 仅从序列化创建
	CMy03031View() noexcept;
	DECLARE_DYNCREATE(CMy03031View)

// 特性
public:
	CMy03031Doc* GetDocument() const;

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
	virtual ~CMy03031View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 0303(1)View.cpp 中的调试版本
inline CMy03031Doc* CMy03031View::GetDocument() const
   { return reinterpret_cast<CMy03031Doc*>(m_pDocument); }
#endif

