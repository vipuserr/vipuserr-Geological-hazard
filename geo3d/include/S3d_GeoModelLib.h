#pragma once
#include <string>
#include "s3d_geomodellib_global.h"
#include "HoleModelProtoStru.h"

#include <qwidget.h>


class S3D_GEOMODELLIB_EXPORT S3d_GeoModelLib
{
public:
	static S3d_GeoModelLib* getSingletonPtr();

	//钻孔建模
	void excuteHoleModel();
	void excuteProtoHoleModel(HoleModelProto protoStr, int &model_id);
	//结构建模
	void excuteAutoModel();
	//属性建模
	void excuteOctFieldModel();
	//断层建模
	void excuteFaultModel();
	//多尺度DEM建模
	void excuteLodDemModel();
	//地上建筑物建模
	void excuteUdgdBuildModel();
	//桩基建模/地下建筑物建模
	void excutePileModel(bool useUndBuild);
	//锚杆建模
	void excuteBoltModel();
	//咸水体建模
	void excuteSaltWaterModel();

	//剖面图转虚拟钻孔
	void excuteSect2VHole();

	//地质图建模
	void excuteGeomapBuildModel();

	//模型评价
	void excuteModelEvaluation();

	//曲面建模
	void excuteBuildSurfaceModel();

private:
	S3d_GeoModelLib();
	~S3d_GeoModelLib();

private:
	QWidget* m_parentWidget;
};

