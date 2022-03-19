#pragma once
#include <s3d_KerGeomodelDef.h>

#include "qgsvectorlayer.h"
#include "G2DToolDef.h"
#include "FieldStructDef.h"
#include <map>
#include <string>
#include <vector>
#include <ogr_core.h>
#include <ogr_feature.h>

#include "s3dSpatialDBEngine_exp.h"
#include "MapFieldMng.h"
#include "s3dSpatialDB.h"

class SAConnection;
class GDALDataset;

namespace Smart3dMap {

	struct StruOriPnt
	{
		double dir;
		double dip;
		gme_vector3d pntData;

		StruOriPnt()
		{
			dir = 0.0;
			dip = 0.0;
			pntData = { 0.0,0.0,0.0 };
		}

		StruOriPnt(double dir_, double dip_, gme_vector3d p3d)
			: dir(dir_), dip(dip_), pntData(p3d)
		{}

	};

	class S3D_SPATIAL_DBENGINE_API GeoDataMng : public QObject
	{
		Q_OBJECT
	private:
		GeoDataMng();
		~GeoDataMng();

	public:
		static GeoDataMng* getSingletonPtr();
		static GeoDataMng& getSingleton();

		// ����ͼ(һ����������)
		QgsVectorLayer* create_GeoMap_GeoReg(const std::string& fullPathFile);			// �ز���ͼ��
		gm_a_rgns read_GeoMap_GeoReg(const std::string& fullPathFile);
		gm_a_rgns read_GeoMap_GeoReg(QgsVectorLayer* layer);
		gm_a_rgns add_GeoMap_GeoReg(const std::string& newFullPathFile, QgsVectorLayer* layer);
		gm_a_rgns add_GeoMap_GeoReg(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);

		QgsVectorLayer* create_GeoMap_GeoPnt(const std::string& fullPathFile);			// ���ʵ�ͼ��
		gmeGeoPnts read_GeoMap_GeoPnt(const std::string& fullPathFile);
		gmeGeoPnts read_GeoMap_GeoPnt(QgsVectorLayer* layer);
		gmeGeoPnts add_GeoMap_GeoPnt(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gmeGeoPnts add_GeoMap_GeoPnt(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_GeoMap_OriPnt(const std::string& fullPathFile);			// ��״��ͼ��
		gmeGeoOriPnts read_GeoMap_OriPnt(const std::string& fullPathFile);
		gmeGeoOriPnts read_GeoMap_OriPnt(QgsVectorLayer* layer);
		gmeGeoOriPnts add_GeoMap_OriPnt(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gmeGeoOriPnts add_GeoMap_OriPnt(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_GeoMap_GeoLine(const std::string& fullPathFile);			// ���ʽ���ͼ��
		gm_geomap_lines read_GeoMap_GeoLine(const std::string& fullPathFile);
		gm_geomap_lines read_GeoMap_GeoLine(QgsVectorLayer* layer);
		gm_geomap_lines add_GeoMap_GeoLine(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_geomap_lines add_GeoMap_GeoLine(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_GeoMap_GeoFault(const std::string& fullPathFile);			// �ϲ���ͼ��
		gme_faults read_GeoMap_GeoFault(const std::string& fullPathFile);
		gme_faults read_GeoMap_GeoFault(QgsVectorLayer* layer);
		gme_faults add_GeoMap_GeoFault(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gme_faults add_GeoMap_GeoFault(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_GeoMap_Dyke(const std::string& fullPathFile);				// ������ͼ��
		gm_geomap_lines read_GeoMap_Dyke(const std::string& fullPathFile);
		gm_geomap_lines read_GeoMap_Dyke(QgsVectorLayer* layer);
		gm_geomap_lines add_GeoMap_Dyke(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_geomap_lines add_GeoMap_Dyke(const std::string& newFullPathFile, QgsVectorLayer* layer);

		// �ж�ͼ(һ����������)(�ж�ͼͼ�������ͼͼ��һ�£��������ֶ�Ҳһ��)
		QgsVectorLayer* create_MiningLevel_GeoReg(const std::string& fullPathFile);		// �ز���ͼ��
		gm_a_rgns read_MiningLevel_GeoReg(const std::string& fullPathFile);
		gm_a_rgns read_MiningLevel_GeoReg(QgsVectorLayer* layer);
		gm_a_rgns add_MiningLevel_GeoReg(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_a_rgns add_MiningLevel_GeoReg(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_MiningLevel_GeoPnt(const std::string& fullPathFile);		// ���ʵ�ͼ��
		gmeGeoPnts read_MiningLevel_GeoPnt(const std::string& fullPathFile);
		gmeGeoPnts read_MiningLevel_GeoPnt(QgsVectorLayer* layer);
		gmeGeoPnts add_MiningLevel_GeoPnt(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gmeGeoPnts add_MiningLevel_GeoPnt(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_MiningLevel_OriPnt(const std::string& fullPathFile);		// ��״��ͼ��
		gmeGeoOriPnts read_MiningLevel_OriPnt(const std::string& fullPathFile);
		gmeGeoOriPnts read_MiningLevel_OriPnt(QgsVectorLayer* layer);
		gmeGeoOriPnts add_MiningLevel_OriPnt(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gmeGeoOriPnts add_MiningLevel_OriPnt(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_MiningLevel_GeoLine(const std::string& fullPathFile);		// ���ʽ���ͼ��
		gm_geomap_lines read_MiningLevel_GeoLine(const std::string& fullPathFile);
		gm_geomap_lines read_MiningLevel_GeoLine(QgsVectorLayer* layer);
		gm_geomap_lines add_MiningLevel_GeoLine(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_geomap_lines add_MiningLevel_GeoLine(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_MiningLevel_GeoFault(const std::string& fullPathFile);		// �ϲ���ͼ��
		gme_faults read_MiningLevel_GeoFault(const std::string& fullPathFile);
		gme_faults read_MiningLevel_GeoFault(QgsVectorLayer* layer);
		gme_faults add_MiningLevel_GeoFault(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gme_faults add_MiningLevel_GeoFault(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_MiningLevel_Dyke(const std::string& fullPathFile);			// ������ͼ��
		gm_geomap_lines read_MiningLevel_Dyke(const std::string& fullPathFile);
		gm_geomap_lines read_MiningLevel_Dyke(QgsVectorLayer* layer);
		gm_geomap_lines add_MiningLevel_Dyke(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_geomap_lines add_MiningLevel_Dyke(const std::string& newFullPathFile, QgsVectorLayer* layer);

		// ����ͼ(һ����������)
		bool read_SectionMap(const QgsProject* qgsPrj, gm_section_map& map);

		QgsVectorLayer* create_SectionMap_HoleLocateLine(const std::string& fullPathFile);	// ���涨λ�켣��ͼ��
		gm_section_holes read_SectionMap_HoleLocateLine(const std::string& fullPathFile);
		gm_section_holes read_SectionMap_HoleLocateLine(QgsVectorLayer* layer);
		gm_section_holes add_SectionMap_HoleLocateLine(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_section_holes add_SectionMap_HoleLocateLine(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_SectionMap_GeoReg(const std::string& fullPathFile);			// �ز���ͼ��
		gm_section_rgns read_SectionMap_GeoReg(const std::string& fullPathFile);
		gm_section_rgns read_SectionMap_GeoReg(QgsVectorLayer* layer);
		gm_section_rgns add_SectionMap_GeoReg(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_section_rgns add_SectionMap_GeoReg(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_SectionMap_GeoPnt(const std::string& fullPathFile);			// ���ʵ�ͼ��
		gmeGeoPnts read_SectionMap_GeoPnt(const std::string& fullPathFile);
		gmeGeoPnts read_SectionMap_GeoPnt(QgsVectorLayer* layer);
		gmeGeoPnts add_SectionMap_GeoPnt(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gmeGeoPnts add_SectionMap_GeoPnt(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_SectionMap_OriPnt(const std::string& fullPathFile);			// ��״��ͼ��
		gmeGeoOriPnts read_SectionMap_OriPnt(const std::string& fullPathFile);
		gmeGeoOriPnts read_SectionMap_OriPnt(QgsVectorLayer* layer);
		gmeGeoOriPnts add_SectionMap_OriPnt(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gmeGeoOriPnts add_SectionMap_OriPnt(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_SectionMap_GeoLine(const std::string& fullPathFile);			// ���ʽ���ͼ��
		gm_section_lines read_SectionMap_GeoLine(const std::string& fullPathFile);
		gm_section_lines read_SectionMap_GeoLine(QgsVectorLayer* layer);
		gm_section_lines add_SectionMap_GeoLine(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_section_lines add_SectionMap_GeoLine(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_SectionMap_SectRoute(const std::string& fullPathFile);		// ���ʽ���ͼ��
		QgsVectorLayer* create_SectionMap_TerrainLine(const std::string& fullPathFile);		// ������ͼ��

		QgsVectorLayer* create_SectionMap_GeoFault(const std::string& fullPathFile);			// �ϲ���ͼ��
		gme_faults read_SectionMap_GeoFault(const std::string& fullPathFile);
		gme_faults read_SectionMap_GeoFault(QgsVectorLayer* layer);
		gme_faults add_SectionMap_GeoFault(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gme_faults add_SectionMap_GeoFault(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_SectionMap_Dyke(const std::string& fullPathFile);				// ������
		gm_geomap_lines read_SectionMap_Dyke(const std::string& fullPathFile);
		gm_geomap_lines read_SectionMap_Dyke(QgsVectorLayer* layer);
		gm_geomap_lines add_SectionMap_Dyke(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_geomap_lines add_SectionMap_Dyke(const std::string& newFullPathFile, QgsVectorLayer* layer);

		// �ز����ͼ
		QgsVectorLayer* create_BoundMap_StratReg(const std::string& fullPathFile);				// ����ͼ��
		gm_a_rgns read_BoundMap_StratReg(const std::string& fullPathFile);
		gm_a_rgns read_BoundMap_StratReg(QgsVectorLayer* layer);
		gm_a_rgns add_BoundMap_StratReg(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_a_rgns add_BoundMap_StratReg(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_BoundMap_StratLine(const std::string& fullPathFile);				// ������ͼ��

		// ����ͼ��
		QgsVectorLayer* create_AddrName_Pnt(const std::string& fullPathFile);
		addr_notes read_AddrName_Pnt(const std::string& fullPathFile);

		// ˮϵͼ��
		QgsVectorLayer* create_Water_Reg(const std::string& fullPathFile);
		water_rgns read_Water_Reg(const std::string& fullPathFile);

		// ��shp�ļ�
		QgsVectorLayer* getLayerFromShp(const std::string& fullPathFile);
		// ����ָ����ͼ�����ͺ�ͼ���ֶδ���shp�ļ�
		QgsVectorLayer* createShpFile(const std::string& fullPathFile, const QgsWkbTypes::Type& type, const vector<QgsField>& fields);

		QgsVectorLayer* creatEmptyLayer(const string & fullPathFile, const QgsWkbTypes::Type& type, vector<QgsField>& fields);
		
		// ��shp�ļ����������ƽ��
		void updateShpFileByOffset(const std::string& fullPathFile, double xOffset = 0.0, double yOffset = 0.0);
		// ��shp�ļ��������������
		void updateShpFileByScale(const std::string& fullPathFile, double xScale = 1.0, double yScale = 1.0);

		// ͼ���ֶι�����
		MapFieldMng *get_MapFieldMng() const;
		// ��ȡshp�ļ��������ֶ�����
		std::vector<std::string> getLayerFieldNames(const std::string& fullPathFile);
		// ��ȡshp�ļ��������ֶ�
		QgsFields getLayerQgsFields(const std::string& fullPathFile);
		// �޸�ͼ����ֶ� mp ��׼���ƣ��û�����
		void alterLayerField(const std::map<std::string, std::string>& mp, QgsVectorLayer* layer);
		QgsVectorLayer* createShpFile(const std::string& fullPathFile, const QgsWkbTypes::Type& type, const QgsFields& fields);
		// ��ȡshp�ļ�����\��\���������е������
		void getPointFromShp(const std::string& fullPathFile, vector<gme_vector2d>& vPnt2d);
		void getPointFromShp(const std::string& fullPathFile, QVector<QgsPointXY>& vPntXY);

		// �������ʵ�ͼ�㣬�ڴ漶
		QgsVectorLayer* fun1(const std::map<std::string, std::vector<gme_vector3d>>& data);
		QgsVectorLayer* fun1(const std::map<std::string, gme_vector2d>& data);
		// ������״��ͼ�㣬�ڴ漶
		QgsVectorLayer* fun2(const std::map<std::string, std::vector<StruOriPnt>>& data);
		QgsVectorLayer* fun2(const std::map<std::string, StruOriPnt>& data);
		// �����ز���ͼ��(����ͼ)���ڴ漶
		QgsVectorLayer* fun3(const std::map<std::string, std::vector<gm_geomap_line>>& data);
		// �����ز���ͼ��(����ͼ)���ڴ漶
		QgsVectorLayer* fun4(const std::vector<gm_section_line>& data);
		// �����ϲ���ͼ�㣬�ڴ漶
		QgsVectorLayer* fun5(const std::vector<std::vector<gme_vector2d>>& lines_2d, const std::vector<gme_fault>& faults);
		// �����ز���ͼ��(����ͼ), �ڴ漶
		QgsVectorLayer* fun6(const std::map<std::string, std::vector<gm_section_rgn>>& strat_rgns);
		// ����������ͼ��(����ͼ), �ڴ漶
		QgsVectorLayer* fun7(const std::vector<gme_vector2d>& formLine, const std::vector<std::string>& fieldNames);

		QString create_GeoMap_Prj(const QString& prjPath);
		QString create_MiningLevel_Prj(const QString& prjPath);
		bool create_SectionMap_Prj(const QString& prjPath);

		// ��shp�ļ��ж�ȡ�켣���ݣ�������ά�ĵ������ÿ������ٶ�
		void read_TrackData(const std::string& fullPathFile, std::vector<gme_vector3d>& pos, std::vector<double>& speed);

		// ��������ͼ��ע��ͼ��,��׵�ͼ��͵ز��ͼ��
		QgsVectorLayer* create_SectionNote_ofHole(const std::string& fullPathFile);
		QgsVectorLayer* create_SectionNote_ofStrat(const std::string& fullPathFile);
		QgsVectorLayer* create_Polygon_ofHolePillar(const std::string& fullPathFile);

		//��shp�ļ���ȡ��������
		void readPointDataByShp(const std::string url, std::vector<gme_point>& gpoints);
		void readPointDataByShp(const QgsVectorLayer* layer, std::vector<gme_point>& gpoints);
		void readLineDataByShp(const std::string url, std::vector<gme_line>& glines);
		void readLineDataByShp(const QgsVectorLayer* layer, std::vector<gme_line>& glines);
		void readRegDataByShp(const std::string url, std::vector<gme_region>& gregions);
		void readRegDataByShp(const QgsVectorLayer* layer, std::vector<gme_region>& gregions);

		QgsVectorLayer* createGeoRgnShp(std::map<int, std::vector<gmeSurface*>>& mapSurfs, std::map<int, std::string>& stratNoCodeMap, std::vector<s3d_BaseLayer>& stdlayerdatas, std::string strRgnShpPathFile);
		QgsVectorLayer* createGeoRgnShp(std::map<int, std::vector<gmeSurface*>>& mapSurfs, std::map<int, std::string>& stratNoCodeMap, std::vector<s3d_BaseLayer>& stdlayerdatas, QgsVectorLayer* layer);

		QgsVectorLayer* createStratRgnShp(std::vector<std::vector<gme_vector3d>>& vvLines, s3d_BaseLayer& stdLayer, std::string fullPathFile);
		QgsVectorLayer* createPointShp(const std::vector<s3d_BoreHole>& vBorehole, const std::string stratCode, const std::string filePathName);
		QgsVectorLayer* createLineShp(const std::vector<gme_line>& glines, std::string fullPathFile);

		//ȡ��gisɫ�����...
		__int64 getGISClrlib(std::string gisclrFilePath = "");

	public:
		// ����QgsProject��ά��ͼ�����ݿ��������µ�ͼ�����ر�����ĵ�ͼ�����ݿ��е�ID������ֵ��С��1��ʾ����ʧ�ܡ�
		int ExportMapToSpatialDB(QgsProject* qgsProject, GeoMapType mapType, const DB_CONN_INFO& dbInfo) const;
		// �����ݿ��д򿪶�ά��ͼ�����ص�QgsProject�����ɵ����߸���������
		QgsProject* LoadMapFromSpatialDB(const DB_CONN_INFO& dbInfo, int mapId) const;
		// �����״ͼ������׼����Ӧ����״ͼ��
		bool BindHoleAndColumnMap(int holeDBId, int holeId, int stratVersion, const DB_CONN_INFO& dbInfo, int mapId);

		QString getPrefixOfS3DMURL() const;
		QString genURLOfS3DMMap(int dbId, int mapId) const;
		void setMapURLToQgsProject(QgsProject* qgsProject, const QString& url) const;
		QString getMapURLWithinQgsProject(const QgsProject* qgsProject) const;

		// �����ݿ��Ӧ�����ݼ�
		GDALDataset* OpenDatasetFromSpatialDB(const DB_CONN_INFO& dbInfo) const;
		void CloseDatasetFromSpatialDB(GDALDataset* dataset) const;

		OGRwkbGeometryType QgsWkbTypeToOGRwkBType(QgsWkbTypes::Type wkbType) const;
		void QgsFieldToOGRField(const QgsField& field, OGRFieldDefn& ogrField) const;

	public:
		// �����ݼ��д�����ͼͼ�㡣
		// layerBaseName����ͼ���Ӧ����ʽ�����֡�
		// layerOrder����ͼ���ڵ�ͼ�е�˳�򣬴�1��ʼ����������С��ͼ��λ��ǰ�С�
		// dbObj�����ݼ����ڵĿռ����ݿ⣬������Ч�����ݿ����ӡ�
		QgsVectorLayer* CreateLayerInDataset(GDALDataset* dataset, int mapId, const QString& layerName, const QString& layerBaseName, QgsWkbTypes::Type geoType, const QgsFields& fields, const QgsCoordinateReferenceSystem* srs,
			int layerOrder, GME_LinkType linkType, s3dSpatialDB* dbObj) const;
		// ����TIFդ��ͼ�㡣
		bool InsertRasterLayerInDataset(int mapId, const QString& layerName, const QString& layerBaseName, const QgsCoordinateReferenceSystem* srs, int layerOrder, const QString& tifFilePath, const s3dSpatialDB::RasterTFW& tfw, s3dSpatialDB* dbObj) const;

	private:
		MapFieldMng* m_pFldMng;

		gmeGeoPnts read_geo_pnt(QgsVectorLayer* layer);
		gmeGeoOriPnts read_ori_pnt(QgsVectorLayer* layer);
		gm_geomap_lines read_geo_line(QgsVectorLayer* layer);
		gme_faults read_fault(QgsVectorLayer* layer);
		gm_section_holes read_sec_locus(QgsVectorLayer* layer);
		gm_section_lines read_sec_bound(QgsVectorLayer* layer);
		gm_section_rgns read_sec_rgn(QgsVectorLayer * layer);
		void merge_layer(const std::string& newFullPathFile, QgsVectorLayer* layer);
		void merge_layer(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);

		__int64			mGisClrlibMng;//GIS��ɫ������...
	};
}