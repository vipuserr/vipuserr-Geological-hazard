#pragma once
#include "s3d_geommaplib_global.h"
#include "qwidget.h"
#include "gme_vector2.h"
#include "gmeStru.h"
#include "gmeEntity.h"
#include "G2DToolDef.h"
#include "RgnMapProtoStru.h"
#include "GeoSectionGenProtoStru.h" // ProtocolBuffers����������ͼ�ӿڵĲ������� -- LH.2021.09.15 17:26 added.
#include "IsoMapProtoStru.h"
#include "GenHoleColumnMapProto.h"

class S3D_GEOMMAPLIB_EXPORT S3d_GeomMapLib
{
public:
	static S3d_GeomMapLib* getSingletonPtr();

	//�����״ͼ
	void excuteMakeBoreHoleMap();
	bool excuteMakeBoreHoleMap(const GenHoleColumnMapProto& protoStr, const std::string& fileFileName);
	//�����״ͼ�༭��
	void excuteBoreHoleMapEditor();
	//����ͼ
	void excuteMakeSectionMap();
	//����ͼ grpc interface -- LH.2021.09.15 14:53 added.
	void excuteMakeSectionMap(int &result, const GeoSectionGenProtoStru& params);
	//��ά����ת��ά����
	void excute3dTo2dSectionMap(__int64 wParam);

	//�ز����ͼ
	//����˽ӿ�
	void excuteStratRgnMap();
	//grpc�ӿ�
	void excuteProtoRgnMap(const RgnMapProto& GenRgnMapProto, int& mapId);
	//����ͼ
	//�����
	void excuteGeoMap();
	//grpc
	void excuteProtoGeoMap(const RgnMapProto& GeoRgnMapProto, int& mapId);
	//��ֵ��ͼ
	//�����
	void excuteIsoplethMap(vector<Smart3dMap::gmeSurface*> pSurface);
	//grpc
	void excuteProtoIsoMap(const IsoMapProto& IsoMapProto, int& mapId);

	//Tiff����(��ʱʹ��-zhuyh)
	void excuteTiffEvalation();

	void forTest();
private:
	S3d_GeomMapLib();
	~S3d_GeomMapLib();

private:
	QWidget* m_parentWidget;
};
