
// 0302(1).h: 0302(1) 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMy03021App:
// 有关此类的实现，请参阅 0302(1).cpp
//

class CMy03021App : public CWinApp
{
public:
	CMy03021App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy03021App theApp;
