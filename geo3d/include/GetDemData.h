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
	 * ��ȡָ��shp�ļ����㡢�ߣ��ڸ�����Χ�ڵĸ̵߳㼯
	 * @param dots  (in)		�����ķ�Χ������Ϊ��ά�㼯������Χ�ߵ�ת�۵㼯�ϡ�
	 * @param filePath (in)		shp�ļ�·��
	 * @param results  (out)	gme_vector3d���͵ĵ㼯(���ؽ��)
	 * @author wwx
	 */
	static void getShpData(vector<gme_vector2d> &dots, QString &filePath, vector<gme_vector3d> &results);

	/**
	 * ��ȡָ��wt��wl�ļ� �ڸ�����Χ�ڵĸ̵߳㼯
	 * @param dots  (in)		�����ķ�Χ������Ϊ��ά�㼯������Χ�ߵ�ת�۵㼯�ϡ�
	 * @param filePath (in)		wt��wl�ļ�·��
	 * @param results  (out)	gme_vector3d���͵ĵ㼯(���ؽ��)
	 * @author wwx
	 */
	static void getWtNWlData(vector<gme_vector2d> &dots, QString &filePath, vector<gme_vector3d> &results);

	/**
	 * ��ȡָ��tif�ļ� �ڸ�����Χ�ڵĸ̵߳㼯
	 * @param dots  (in)		�����ķ�Χ������Ϊ��ά�㼯������Χ�ߵ�ת�۵㼯�ϡ�
	 * @param filePath (in)		tiff�ļ�·��
	 * @param results  (out)	gme_vector3d���͵ĵ㼯(���ؽ��)
	 * @author wwx
	 */
	static void getDemTiffData(vector<gme_vector2d> &dots, QString &filePath, vector<gme_vector3d> &results);

	/**
	 * ��ȡָ��tif�ļ� �ĸ̵߳㼯
	 * @param filePath (in)		tiff�ļ�·��
	 * @param results  (out)	gme_vector3d���͵ĵ㼯(���ؽ��)
	 * @author wwx
	 */
	static gme_vector2i getDemTiffData(const QString &filePath, vector<gme_vector3d> &results);

	/**
	 * ��ȡָ��RSMtif�ļ� ����ͼ��Χ���ļ���
	 * @param filePath (in)				tiff�ļ�·��
	 * @param fileBaseName  (out)		�ļ���
	 * @param demImgBox  (out)			gme_rect_2d���͵ķ�Χ
	 * @author wwx
	 */
	static void getRMSTiffData(QString &filePath, QString &fileBaseName, Smart3dMap::gme_rect_2d &demImgBox);

	/**
	 * д���ڴ浽Tiff�ļ���
	 * @param nRow      (in)			����
	 * @param nCol      (in)			����
	 * @param filePath  (in)			tiff���Ŀ¼
	 * @param rect		(in)			tiff���귶Χ
	 * @author wwx
	 */
	static void writeBuffer2Tiff(int nRow, int nCol, double *height, QString filePath, QgsRectangle &rect);
};