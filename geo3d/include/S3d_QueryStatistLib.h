#pragma once

#include "s3d_querystatistlib_global.h"

class S3D_QUERYSTATISTLIB_EXPORT S3d_QueryStatistLib
{
public:
	static S3d_QueryStatistLib* getSingletonPtr();
	//�����Ϣ��ѯ
	void excuteHoleInfoQuery();
	//����ͳ��
	void excuteLithStatis();
	//ָ��ͳ��
	void excuteStatinfo();

private:
	S3d_QueryStatistLib();
	~S3d_QueryStatistLib();

	__int64 m_parentWidget;
};
