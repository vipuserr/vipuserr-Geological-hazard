#ifndef VECSPATIALANALYS_H
#define VECSPATIALANALYS_H

#include "Geo3dSpatialAnalysDef.h"
#include"gmeStru.h"
#include"gme_Pointer.h"
#include"gmeEntity.h"
#include"s3d_GeomDefine.h"
#include<vector>
using namespace std;
using namespace Smart3dMap;
class QGisS3dGeoTrans;
class VECSPATIALANALYS_EXPORT VecSpatialAnalys
{
public:
	enum EndCapStyle//结束端点样式
	{
		CapRound = 1, //圆角
		CapFlat, //扁平
		CapSquare, //方角
	};
	enum JoinStyle//连接样式
	{
		JoinStyleRound = 1, //圆角
		JoinStyleMiter, //尖角
		JoinStyleBevel, //斜角
	};
	VecSpatialAnalys();
	virtual ~VecSpatialAnalys();

	//裁剪 点线面与面要素进行空间几何运算
	void Intersection(const vector<s3d_Point*> &inputVec, const gme_rect_2d &dRect, vector<s3d_Point*>& outVec);
	// 功能:     裁剪几何点图形（矩形内的被保留下来）
	//InputVec         In      所需裁剪的几何图形列表
	//dRect             In      裁剪矩形范围

	void Intersection(const vector<s3d_Point*> &inputVec, const vector<gme_vector2d> &dPolygon, vector<s3d_Point*>& outVec);
	// 功能:     多边形裁剪几何点图形（内裁）
	//InputVec         In      所需裁剪的几何图形列表
	//dPolygon          In      裁剪范围（首尾封闭）

	void Intersection(const vector<s3d_Polyline*> &inputVec, const gme_rect_2d &dRect, vector<s3d_Polyline*> &outVec);
	// 功能:     裁剪几何线图形（矩形内的被保留下来）
	//InputVec         In      所需裁剪的几何图形列表
	//dRect             In      裁剪矩形范围

	void Intersection(const vector<s3d_Polyline*> &InputVec, const vector<gme_vector2d> &dPolygon, vector<s3d_Polyline*>&outVec);
	// 功能:     多边形裁剪几何线图形（内裁）
	//InputVec         In      所需裁剪的几何图形列表
	//dPolygon          In      裁剪范围（首尾封闭）

	void Intersection(const vector<s3d_Polygon*> &InputVec, const gme_rect_2d &dRect, vector<s3d_Polygon*>&outVec);
	// 功能:     裁剪几何面图形（内裁）
	//InputVec         In      所需裁剪的几何图形列表
	//dRect             In      裁剪范围

	void Intersection(const vector<s3d_Polygon*> &inputVec, const vector<gme_vector2d> &dPolygon, vector<s3d_Polygon*>&outVec);
	// 功能:     裁剪几何面图形（内裁）
	//InputVec         In      所需裁剪的几何图形列表
	//dPolygon          In      裁剪范围（首尾封闭）

	void Intersection(const vector<s3d_Polygon*> &inputVec, const vector<s3d_Polygon*> &inputVec1, vector<s3d_Polygon*>&outVec);
	// 功能:     裁剪几何面图形（内裁）
	//InputVec         In      所需裁剪的几何图形列表
	//inputVec1          In      裁剪范围

	//凸包:计算点线面的凸包
	/*该算法计算输入图层中的每个要素的凸包。
		请查看“最小边界几何图形”算法，了解涵盖整个图层或要素分组子集的凸包计算方法。*/
	void  convexHull(const vector < s3d_Point*> &inputVec, s3d_Polygon*& outPolygon);
	void  convexHull(const vector<s3d_Polyline*> &inputVec, s3d_Polygon*& outPolygon);
	void  convexHull(const vector<s3d_Polygon*> &inputVec, s3d_Polygon*& outPolygon);
	void  convexHull(s3d_GeomBase* inputVec, s3d_Polygon*& outGeoBase);

	//差值：该算法从输入图层提取叠加图层要素之外或部分重叠的要素。 在叠加图层中部分重叠要素的输入图层要素将沿着这些要素的边界进行分割，并且仅保留叠加图层要素之外的部分。
	//该算法从输入图层提取叠加图层要素之外或部分重叠的要素。 在叠加图层中部分重叠要素的输入图层要素将沿着这些要素的边界进行分割，并且仅保留叠加图层要素之外的部分。
	//尽管差异操作会修改要素的面积或长度等属性，但不会修改属性值。如果此类属性储存为属性，则必须手动更新这些属性。
	//有意义的差值运算：点和面 点和线 点和点 线和面 线和线 面和面
	void difference(const vector<s3d_Point*> &inputVec1, const vector<s3d_Polygon*> &inputVec2, vector<s3d_Point*> &outVec);
	void difference(const vector<s3d_Point*> &inputVec1, const vector<s3d_Polyline*> &inputVec2, vector<s3d_Point*>&outVec);
	void difference(const vector<s3d_Point*> &inputVec1, const vector<s3d_Point*> &inputVec2, vector<s3d_Point*> &outVec);
	void difference(const vector<s3d_Polyline*> &inputVec1, const vector<s3d_Polygon*> &inputVec2, vector<s3d_Polyline*> &outVec);
	void difference(const vector<s3d_Polyline*> &inputVec1, const vector<s3d_Polyline*> &inputVec2, vector<s3d_Polyline*>&outVec);
	void difference(const vector<s3d_Polygon*> &inputVec1, const vector<s3d_Polygon*> &inputVec2, vector<s3d_Polygon*> &outVec);

	void  GetCenter(const s3d_GeomBase * pGeo, gme_vector2d &outV2d);
	void  GetCenter(const vector<s3d_GeomBase*> &inputVec, gme_vector2d &outV2d);
	// 功能:     求多边形的中心
	double  GetArea(const s3d_Polygon * pPolygon);
	// 功能:     计算多边形面积

	double  GetDistance(const s3d_GeomBase * pLGeo, const s3d_GeomBase * pRGeo);
	// 功能:     计算两个要素间的距离长度

	void Buffer(const s3d_GeomBase * pGeo,  s3d_Polygon *&outPolygon,double distance=10, int segments = 5
		, EndCapStyle endCapStyle = EndCapStyle::CapRound, JoinStyle joinStyle = JoinStyle::JoinStyleRound, double miterLimit = 2);
	// 功能:     计算点、线、面缓冲区
	//参数说明：segments 线段 miterLimit 尖角限制 distance缓冲距离

	void simplify(const vector<s3d_Polygon*> &inputVec,vector<s3d_Polygon*> &outVec, double tolerance=1);
	void simplify(const vector<s3d_Polyline*> &inputVec,vector<s3d_Polyline*> &outVec, double tolerance=1);

	void SplitPolygon(const vector<s3d_Polygon*> &inputVec, const vector<s3d_Polyline*> &dLinVec, vector<s3d_Polygon*>&outVec);
	// 功能:     用多条线分割多个面
	//InputVec         In      所需分割的几何图形列表
	//dLinVec          In      分割线列表

	void SplitPolygon(const vector<s3d_Polygon*> &inputVec, const s3d_Polyline* pLin, vector<s3d_Polygon*> &outVec);
	// 功能:     用一条条线分割面
	//InputVec         In      所需分割的几何图形点列表
	//dLinVec          In      分割线列表

	void SplitLin(const s3d_Polyline* pLin1, const s3d_Polyline* pLin2, vector<s3d_Polyline*> &outVec);
	// 功能:     用pLin2分割pLin1
	//InputVec         In      所需分割的几何图形列表
	//dLinVec          In      分割线列表


	void Smooth(const vector<gme_vector2d> &inputVec,  vector<gme_vector2d> &outVec,int iterations = 5, double offset = 0.25);
	// 功能:     平滑处理


	void   Smooth(const s3d_GeomBase * pGeo, s3d_GeomBase *outGeoBase, int iterations = 5, double offset = 0.25);
	// 功能:     平滑处理



	void  Combine(const s3d_Polygon* pFirst, const s3d_Polygon* pSecond, vector<s3d_Polygon*>& outPolygon);
	// 功能:     合并多边形

	void  Combine(const vector<s3d_Polygon*> pFirst, const vector<s3d_Polygon*> pSecond, vector<s3d_Polygon*>& outPolygon);
	// 功能:     合并多边形

	
	void release(s3d_GeomBase * pGeo);
	void release(vector<s3d_GeomBase*> &geoVec);
private:
	QGisS3dGeoTrans *m_trans;
};
#endif // VECSPATIALANALYS_H

