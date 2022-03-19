 #pragma once

#pragma once


#include "ogMessageListener.h"

using namespace Smart3dMap;


class CGeo2dBaseMsgObj : public Smart3dMap::COGListener
{
public:
	CGeo2dBaseMsgObj(void);
public:
	~CGeo2dBaseMsgObj(void);

public:
	//消息响应
	void registerIntMsg();
	virtual long OnMessagePro(long nMsg, __int64 wParam, __int64 lParam);	

private:
	BOOL GetOpenElementList(long **ppElement,long *plElementNum);


private:
	long	*m_plElement;//元素列表
	long	m_lNum;		 //元素个数
};
