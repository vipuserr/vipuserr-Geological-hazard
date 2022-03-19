#pragma once
#include <string>
#include "s3d_geomodellib_global.h"
#include "HoleModelProtoStru.h"

#include <qwidget.h>


class S3D_GEOMODELLIB_EXPORT S3d_GeoModelLib
{
public:
	static S3d_GeoModelLib* getSingletonPtr();

	//��׽�ģ
	void excuteHoleModel();
	void excuteProtoHoleModel(HoleModelProto protoStr, int &model_id);
	//�ṹ��ģ
	void excuteAutoModel();
	//���Խ�ģ
	void excuteOctFieldModel();
	//�ϲ㽨ģ
	void excuteFaultModel();
	//��߶�DEM��ģ
	void excuteLodDemModel();
	//���Ͻ����ｨģ
	void excuteUdgdBuildModel();
	//׮����ģ/���½����ｨģ
	void excutePileModel(bool useUndBuild);
	//ê�˽�ģ
	void excuteBoltModel();
	//��ˮ�彨ģ
	void excuteSaltWaterModel();

	//����ͼת�������
	void excuteSect2VHole();

	//����ͼ��ģ
	void excuteGeomapBuildModel();

	//ģ������
	void excuteModelEvaluation();

	//���潨ģ
	void excuteBuildSurfaceModel();

private:
	S3d_GeoModelLib();
	~S3d_GeoModelLib();

private:
	QWidget* m_parentWidget;
};

