#pragma once

#include "s3d_querystatistlib_global.h"

class S3D_QUERYSTATISTLIB_EXPORT S3d_QueryStatistLib
{
public:
	static S3d_QueryStatistLib* getSingletonPtr();
	//钻孔信息查询
	void excuteHoleInfoQuery();
	//岩性统计
	void excuteLithStatis();
	//指标统计
	void excuteStatinfo();

private:
	S3d_QueryStatistLib();
	~S3d_QueryStatistLib();

	__int64 m_parentWidget;
};
