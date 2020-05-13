// ShowString.cpp: 实现文件
//

#include "pch.h"
#include "0413(4).h"
#include "ShowString.h"
#include "afxdialogex.h"


// ShowString 对话框

IMPLEMENT_DYNAMIC(ShowString, CDialog)

ShowString::ShowString(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, str1(_T(""))
	, num(0)
	, str2(_T(""))
{

}

ShowString::~ShowString()
{
}

void ShowString::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STR1, str1);
	DDX_Text(pDX, IDC_INT1, num);
	DDX_Text(pDX, IDC_STR2, str2);
}


BEGIN_MESSAGE_MAP(ShowString, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &ShowString::OnBnClickedButton1)
END_MESSAGE_MAP()


// ShowString 消息处理程序


void ShowString::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str_1, str_2, str_3;
	GetDlgItem(IDC_STR1)->GetWindowText(str_1);
	GetDlgItem(IDC_INT1)->GetWindowText(str_2);

	str_3 = str_1 + str_2;
	SetDlgItemText(IDC_STR2, str_3);
}
