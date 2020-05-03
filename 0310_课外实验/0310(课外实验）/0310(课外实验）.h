
// 0310(课外实验）.h: 0310(课外实验） 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号


// CMy0310课外实验App:
// 有关此类的实现，请参阅 0310(课外实验）.cpp
//

class CMy0310课外实验App : public CWinApp
{
public:
	CMy0310课外实验App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0310课外实验App theApp;
