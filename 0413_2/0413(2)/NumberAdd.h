#pragma once


// NumberAdd 对话框

class NumberAdd : public CDialog
{
	DECLARE_DYNAMIC(NumberAdd)

public:
	NumberAdd(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~NumberAdd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedCancel();
	int augend;
	int num2;
	int end;
	afx_msg void OnBnClickedButton1();
};
