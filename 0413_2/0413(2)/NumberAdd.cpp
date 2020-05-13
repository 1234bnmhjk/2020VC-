// NumberAdd.cpp: 实现文件
//

#include "pch.h"
#include "0413(2).h"
#include "NumberAdd.h"
#include "afxdialogex.h"


// NumberAdd 对话框

IMPLEMENT_DYNAMIC(NumberAdd, CDialog)

NumberAdd::NumberAdd(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, augend(0)
	, num2(0)
	, end(0)
{

}

NumberAdd::~NumberAdd()
{
}

void NumberAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, augend);
	DDX_Text(pDX, IDC_EDIT3, num2);
	DDX_Text(pDX, IDC_EDIT2, end);
}


BEGIN_MESSAGE_MAP(NumberAdd, CDialog)
	ON_EN_CHANGE(IDC_EDIT3, &NumberAdd::OnEnChangeEdit3)
	ON_BN_CLICKED(IDCANCEL, &NumberAdd::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON, &NumberAdd::OnBnClickedButton1)
END_MESSAGE_MAP()


// NumberAdd 消息处理程序


void NumberAdd::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void NumberAdd::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}


void NumberAdd::OnBnClickedButton1()
{
	
	// TODO: 在此添加控件通知处理程序代码
	CString str1, str2, str3;
	GetDlgItem(IDC_EDIT1)->GetWindowText(str1);
	GetDlgItem(IDC_EDIT3)->GetWindowText(str2);
	int a, b, c;
	a = _ttol(str1);
	b = _ttol(str2);
	c = a + b;
	str3.Format(_T("%d"), c);
	SetDlgItemText(IDC_EDIT2, str3);
}
