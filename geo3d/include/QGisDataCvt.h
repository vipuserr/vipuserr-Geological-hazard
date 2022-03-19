#ifndef QGISDATACVT_H
#define QGISDATACVT_H

#include "s3dSpatialDBEngine_exp.h"
#include"gmeStru.h"
#include"gme_Pointer.h"
#include"gmeEntity.h"
#include"s3d_GeomDefine.h"
#include"qgsgeometry.h"
#include "qgsabstractgeometry.h"
using namespace std;
using namespace Smart3dMap;


class S3D_SPATIAL_DBENGINE_API QGisS3dGeoTrans
{
public:
	void S3dGeoToQgsGeo(const vector<s3d_GeomBase*>& inS3dGeos, QgsGeometry &outQgsGeo);
	void QgsGeoToS3dGeo(const QgsGeometry &inQgsGeo, vector<s3d_GeomBase*>&outS3dGeos);
	void S3dGeoToQgsGeo(const s3d_GeomBase* inS3dGeo, QgsGeometry&outQgsGeo);

	void PointToQgis(const s3d_Point *inS3dPoint, QgsGeometry &outQgsGeo);//����Ҫ��ת��
	void PointToQgis(const vector < s3d_Point *> &inS3dPoints, QgsGeometry &outQgsGeo);//���Ҫ��ת��
	void LineToQgis(const s3d_Polyline *inS3dPolyline, QgsGeometry &outQgsGeo);//��Ҫ��ת��
	void LineToQgis(const vector < s3d_Polyline *> &inS3dPolylines, QgsGeometry &outQgsGeo);//����Ҫ��ת��
	void PolygonToQgis(const s3d_Polygon *inS3dPolygon, QgsGeometry &outQgsGeo);//��Ҫ��ת��
	void PolygonToQgis(const vector<s3d_Polygon *> &inS3dPolygon, QgsGeometry &outQgsGeo);//����Ҫ��ת��
	void RectToQgis(const gme_rect_2d * inS3dRect, QgsGeometry &outQgsGeo);//����ת��ΪҪ��
	void PolygonToQgis(const vector<gme_vector2d> &inS3dPolygon, QgsGeometry &outQgsGeo);//�㼯ת��
};


#endif // QGISDATACVT_H

