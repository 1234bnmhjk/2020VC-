
// 7����ʵ��.h : 7����ʵ�� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy7����ʵ��App:
// �йش����ʵ�֣������ 7����ʵ��.cpp
//

class CMy7����ʵ��App : public CWinAppEx
{
public:
	CMy7����ʵ��App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy7����ʵ��App theApp;
