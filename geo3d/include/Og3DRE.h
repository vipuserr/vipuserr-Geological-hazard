// Og3DRE.h: Og3DRE DLL 的主标头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// 主符号


// COg3DREApp
// 有关此类实现的信息，请参阅 Og3DRE.cpp
//

class COg3DREApp : public CWinApp
{
public:
	COg3DREApp();

// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();


	DECLARE_MESSAGE_MAP()

public:
	bool bNeedModify;
	bool bCanModify;
};

void	SetRenderThreadLock(bool bLocked);

BOOL	IsRendering();

bool	FinishedRender();