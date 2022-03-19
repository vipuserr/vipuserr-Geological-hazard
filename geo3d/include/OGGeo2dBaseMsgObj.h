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
	//��Ϣ��Ӧ
	void registerIntMsg();
	virtual long OnMessagePro(long nMsg, __int64 wParam, __int64 lParam);	

private:
	BOOL GetOpenElementList(long **ppElement,long *plElementNum);


private:
	long	*m_plElement;//Ԫ���б�
	long	m_lNum;		 //Ԫ�ظ���
};
