#pragma once

#include "s3d_stylemanagerlib_global.h"

class S3D_STYLEMANAGERLIB_EXPORT S3d_StyleManagerLib
{
public:
	static S3d_StyleManagerLib* getSingletonPtr();

	//ϵͳ���Ź�����
	void excuteSysStyleManager();
	//��ӷ�񵽹�����
	void excuteAddSymbol();
	//���ɲ��ʿ�
	void excuteGeneraMatScript(__int64 geoCon);
	//ͼ����ʽ����
	void excuteLayerStyleSet(__int64 qgsVectorLayer);

private:
	S3d_StyleManagerLib();
	~S3d_StyleManagerLib();
};
