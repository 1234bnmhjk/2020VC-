
// 0303(����ʵ��).h : 0303(����ʵ��) Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy0303����ʵ��App:
// �йش����ʵ�֣������ 0303(����ʵ��).cpp
//

class CMy0303����ʵ��App : public CWinAppEx
{
public:
	CMy0303����ʵ��App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy0303����ʵ��App theApp;
