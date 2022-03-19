#pragma once

#include"qgspallabeling.h"
#include "qgsvectorlayer.h"
#include "qgsproject.h"
#include "QgsSingleSymbolRenderer.h"
#include "qgscategorizedsymbolrenderer.h"
#include "qgsgraduatedsymbolrenderer.h"

#include "s3d_mapgisfile_slib.h"



#ifdef _GEO2D_VEC_TRANS_APP
#define _GEO2D_VEC_TRANS_DLL __declspec(dllexport)
#else
#define _GEO2D_VEC_TRANS_DLL __declspec(dllimport)
#endif
 

#ifndef _GEO2D_VEC_TRANS_APP
	#pragma comment(lib, "S3dApp2DVecTrans.lib")
#endif

namespace Smart3dMap
{
	// 多源数据约束下的显式三维地质建模类
	class _GEO2D_VEC_TRANS_DLL VecFileConv
	{
	public:
		VecFileConv();
	public:
		virtual ~VecFileConv();

	public:
		bool setSlibPath(string strSlib);

	public:
		void qgis2map(string qgis, string prj);
		void qgis2map(QgsProject* qgis, gm_mapgis_prj* prj);
		void qgis2map(QgsProject* qgis, string shp, string map);
		void qgis2map(QgsProject* qgis, QgsVectorLayer* qgisvec, gm_mapgis_vector* mapvec);

		void map2qgis(string prj, string qgis);
		void map2qgis(gm_mapgis_prj* prj, QgsProject* qgis);
		void map2qgis(string map, string qgis, string shp);
		void map2qgis(gm_mapgis_vector* mapvec, QgsProject* qgis, QgsVectorLayer*& qgisvec);



	private:
		//map2qgis
		QgsWkbTypes::Type getLayerType(gm_mapgis_vector *mapgisVec);
		void getProperty(gm_mapgis_vector* mapvec, QgsWkbTypes::Type layerType, QList < QPair<QString, QString> >&fields);
		QgsVectorLayer* newVecLayer(QgsWkbTypes::Type &type, QList<QPair<QString, QString>>& fields);
		void addPointFeature(gm_mapgis_vector* mapvec, QgsVectorLayer*qgisvec, double scale);
		void addLabelRule(gm_mapgis_vector* mapvec, QgsVectorLayer*qgisvec);
		void addLineFeature(gm_mapgis_vector* mapvec, QgsVectorLayer*qgisvec, double scale);
		void addPolyFeature(gm_mapgis_vector* mapvec, QgsVectorLayer*qgisvec, double scale);
		void addVecGeometry(gm_mapgis_vector* mapvec, QgsVectorLayer*qgisvec, QgsWkbTypes::Type &type, double scale);
		void setAttributes(QgsAttributes &atrs, gmeFieldValues fieldVals);
		double getScale(gm_mapgis_vector* mapvec);
		void clearQGISPrj();

		//qgis2map
		void getVecFields(QgsVectorLayer* shpLayer, gmeFields& fields);
		void getVecRecords(QgsVectorLayer* shpLayer, gmeRecordSet& records);
		void getPointFeature(QgsVectorLayer* shpLayer, vector<_D_DOT>& pntsCoord, vector<GM_PNT_INFO>& pntsInfo);
		void getLineFeature(QgsVectorLayer* shpLayer, vector<vector<_D_DOT>>& lineCoord, vector<GM_LIN_INFO>& linesInfo, gmeRecordSet& records);
		void getRegFeature(QgsVectorLayer* shpLayer,vector<GM_REG_INFO>* regsInfo, vector<GM_REG_SEG>* regsSeg,
						   vector<GM_LIN_INFO>* regLinsInfo, vector<vector<_D_DOT>>* regLinsCoord, vector<GM_LIN_TOP>* regLinsTop, 
						   vector<GM_LIN_NODE>* regLinsNode, gmeRecordSet& records);

		void getSymbolClr(QgsSymbol* symbol, GM_CLRLIB_RGB& mapRGB);

		void getSimpleClr(QgsSingleSymbolRenderer* render, GM_CLRLIB_RGB& mapRGB);

		void getCategory(QgsCategorizedSymbolRenderer* render, pair<string, map<QVariant, GM_CLRLIB_RGB>>& cates);
		void getCateClr(pair<string, map<QVariant, GM_CLRLIB_RGB>>* cates, gmeRecord* mapRecord, GM_CLRLIB_RGB& mapRGB);

		void getGraduated(QgsGraduatedSymbolRenderer* render,pair<string,map<pair<double,double>,GM_CLRLIB_RGB>>& grads);
		void getGraduateClr(pair<string, map<pair<double, double>, GM_CLRLIB_RGB>>* grads, gmeRecord* mapRecord, GM_CLRLIB_RGB& mapRGB);

	private:
		gm_mapgis_slib m_slib;				//符号库
		gm_mapgis_prj m_mapgisPro;			//mapgis工程文件内存级
		QgsProject*     m_pQgsPrj = nullptr;// Qgis工程
		string m_mapgisPathfile="";
		string m_qgisPathfile = "";
		string m_qgisVecfile = "";
		QString m_typeName = "";//标注渲染字段
		QString m_annotationName = "";//添加注记字段
	};

	//flag<0需要对数组进行反序...
	void _GEO2D_VEC_TRANS_DLL reverseVec(vector<gme_vector2d>& vec, long flag=1);
}