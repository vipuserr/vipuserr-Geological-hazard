#pragma once
#include<vector>

#include "s3dSpatialDBEngine_exp.h"
#include"QString.h"
#include"qgsvectorlayer.h"
#include"gmeStru.h"
using namespace std;
using namespace Smart3dMap;


class S3D_SPATIAL_DBENGINE_API GetDemData
{
public:
	/**
	 * 获取指定shp文件（点、线）在给定范围内的高程点集
	 * @param dots  (in)		给定的范围，类型为二维点集，即范围线的转折点集合。
	 * @param filePath (in)		shp文件路径
	 * @param results  (out)	gme_vector3d类型的点集(返回结果)
	 * @author wwx
	 */
	static void getShpData(vector<gme_vector2d> &dots, QString &filePath, vector<gme_vector3d> &results);

	/**
	 * 获取指定wt、wl文件 在给定范围内的高程点集
	 * @param dots  (in)		给定的范围，类型为二维点集，即范围线的转折点集合。
	 * @param filePath (in)		wt、wl文件路径
	 * @param results  (out)	gme_vector3d类型的点集(返回结果)
	 * @author wwx
	 */
	static void getWtNWlData(vector<gme_vector2d> &dots, QString &filePath, vector<gme_vector3d> &results);

	/**
	 * 获取指定tif文件 在给定范围内的高程点集
	 * @param dots  (in)		给定的范围，类型为二维点集，即范围线的转折点集合。
	 * @param filePath (in)		tiff文件路径
	 * @param results  (out)	gme_vector3d类型的点集(返回结果)
	 * @author wwx
	 */
	static void getDemTiffData(vector<gme_vector2d> &dots, QString &filePath, vector<gme_vector3d> &results);

	/**
	 * 获取指定tif文件 的高程点集
	 * @param filePath (in)		tiff文件路径
	 * @param results  (out)	gme_vector3d类型的点集(返回结果)
	 * @author wwx
	 */
	static gme_vector2i getDemTiffData(const QString &filePath, vector<gme_vector3d> &results);

	/**
	 * 获取指定RSMtif文件 返回图像范围和文件名
	 * @param filePath (in)				tiff文件路径
	 * @param fileBaseName  (out)		文件名
	 * @param demImgBox  (out)			gme_rect_2d类型的范围
	 * @author wwx
	 */
	static void getRMSTiffData(QString &filePath, QString &fileBaseName, Smart3dMap::gme_rect_2d &demImgBox);

	/**
	 * 写入内存到Tiff文件中
	 * @param nRow      (in)			行数
	 * @param nCol      (in)			列数
	 * @param filePath  (in)			tiff输出目录
	 * @param rect		(in)			tiff坐标范围
	 * @author wwx
	 */
	static void writeBuffer2Tiff(int nRow, int nCol, double *height, QString filePath, QgsRectangle &rect);
};