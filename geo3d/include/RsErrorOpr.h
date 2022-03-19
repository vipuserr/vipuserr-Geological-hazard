#pragma once

#include "atlstr.h"

class CRSErrorOpr
{
public:
	CRSErrorOpr() {}
	~CRSErrorOpr() {}

	void ShowErrorInfoDlg(long ID, char* text) {}
	void ShowErrorInfoDlg(long ID, CString text) {}

	static 	CRSErrorOpr* GetInstencePtr() {}
};

