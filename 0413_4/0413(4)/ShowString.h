#pragma once


// ShowString 对话框

class ShowString : public CDialog
{
	DECLARE_DYNAMIC(ShowString)

public:
	ShowString(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ShowString();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString str1;
	int num;
	CString str2;
	afx_msg void OnBnClickedButton1();
};
