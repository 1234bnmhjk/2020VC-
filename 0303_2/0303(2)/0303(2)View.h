
// 0303(2)View.h: CMy03032View 类的接口
//

#pragma once


class CMy03032View : public CView
{
protected: // 仅从序列化创建
	CMy03032View() noexcept;
	DECLARE_DYNCREATE(CMy03032View)

// 特性
public:
	CMy03032Doc* GetDocument() const;

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
	virtual ~CMy03032View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 0303(2)View.cpp 中的调试版本
inline CMy03032Doc* CMy03032View::GetDocument() const
   { return reinterpret_cast<CMy03032Doc*>(m_pDocument); }
#endif

