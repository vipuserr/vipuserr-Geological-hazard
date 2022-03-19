#pragma once

#include "s3d_stylemanagerlib_global.h"

class S3D_STYLEMANAGERLIB_EXPORT S3d_StyleManagerLib
{
public:
	static S3d_StyleManagerLib* getSingletonPtr();

	//系统符号管理器
	void excuteSysStyleManager();
	//添加风格到管理器
	void excuteAddSymbol();
	//生成材质库
	void excuteGeneraMatScript(__int64 geoCon);
	//图层样式设置
	void excuteLayerStyleSet(__int64 qgsVectorLayer);

private:
	S3d_StyleManagerLib();
	~S3d_StyleManagerLib();
};
