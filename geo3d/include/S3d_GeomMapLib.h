#pragma once
#include "s3d_geommaplib_global.h"
#include "qwidget.h"
#include "gme_vector2.h"
#include "gmeStru.h"
#include "gmeEntity.h"
#include "G2DToolDef.h"
#include "RgnMapProtoStru.h"
#include "GeoSectionGenProtoStru.h" // ProtocolBuffers到生成剖面图接口的参数桥梁 -- LH.2021.09.15 17:26 added.
#include "IsoMapProtoStru.h"
#include "GenHoleColumnMapProto.h"

class S3D_GEOMMAPLIB_EXPORT S3d_GeomMapLib
{
public:
	static S3d_GeomMapLib* getSingletonPtr();

	//钻孔柱状图
	void excuteMakeBoreHoleMap();
	bool excuteMakeBoreHoleMap(const GenHoleColumnMapProto& protoStr, const std::string& fileFileName);
	//钻孔柱状图编辑器
	void excuteBoreHoleMapEditor();
	//剖面图
	void excuteMakeSectionMap();
	//剖面图 grpc interface -- LH.2021.09.15 14:53 added.
	void excuteMakeSectionMap(int &result, const GeoSectionGenProtoStru& params);
	//三维剖面转二维剖面
	void excute3dTo2dSectionMap(__int64 wParam);

	//地层分区图
	//桌面端接口
	void excuteStratRgnMap();
	//grpc接口
	void excuteProtoRgnMap(const RgnMapProto& GenRgnMapProto, int& mapId);
	//地质图
	//桌面端
	void excuteGeoMap();
	//grpc
	void excuteProtoGeoMap(const RgnMapProto& GeoRgnMapProto, int& mapId);
	//等值线图
	//桌面端
	void excuteIsoplethMap(vector<Smart3dMap::gmeSurface*> pSurface);
	//grpc
	void excuteProtoIsoMap(const IsoMapProto& IsoMapProto, int& mapId);

	//Tiff评价(临时使用-zhuyh)
	void excuteTiffEvalation();

	void forTest();
private:
	S3d_GeomMapLib();
	~S3d_GeomMapLib();

private:
	QWidget* m_parentWidget;
};
