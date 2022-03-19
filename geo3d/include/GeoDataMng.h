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

		// 地质图(一区两点三线)
		QgsVectorLayer* create_GeoMap_GeoReg(const std::string& fullPathFile);			// 地层区图层
		gm_a_rgns read_GeoMap_GeoReg(const std::string& fullPathFile);
		gm_a_rgns read_GeoMap_GeoReg(QgsVectorLayer* layer);
		gm_a_rgns add_GeoMap_GeoReg(const std::string& newFullPathFile, QgsVectorLayer* layer);
		gm_a_rgns add_GeoMap_GeoReg(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);

		QgsVectorLayer* create_GeoMap_GeoPnt(const std::string& fullPathFile);			// 地质点图层
		gmeGeoPnts read_GeoMap_GeoPnt(const std::string& fullPathFile);
		gmeGeoPnts read_GeoMap_GeoPnt(QgsVectorLayer* layer);
		gmeGeoPnts add_GeoMap_GeoPnt(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gmeGeoPnts add_GeoMap_GeoPnt(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_GeoMap_OriPnt(const std::string& fullPathFile);			// 产状点图层
		gmeGeoOriPnts read_GeoMap_OriPnt(const std::string& fullPathFile);
		gmeGeoOriPnts read_GeoMap_OriPnt(QgsVectorLayer* layer);
		gmeGeoOriPnts add_GeoMap_OriPnt(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gmeGeoOriPnts add_GeoMap_OriPnt(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_GeoMap_GeoLine(const std::string& fullPathFile);			// 地质界线图层
		gm_geomap_lines read_GeoMap_GeoLine(const std::string& fullPathFile);
		gm_geomap_lines read_GeoMap_GeoLine(QgsVectorLayer* layer);
		gm_geomap_lines add_GeoMap_GeoLine(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_geomap_lines add_GeoMap_GeoLine(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_GeoMap_GeoFault(const std::string& fullPathFile);			// 断层线图层
		gme_faults read_GeoMap_GeoFault(const std::string& fullPathFile);
		gme_faults read_GeoMap_GeoFault(QgsVectorLayer* layer);
		gme_faults add_GeoMap_GeoFault(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gme_faults add_GeoMap_GeoFault(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_GeoMap_Dyke(const std::string& fullPathFile);				// 岩脉线图层
		gm_geomap_lines read_GeoMap_Dyke(const std::string& fullPathFile);
		gm_geomap_lines read_GeoMap_Dyke(QgsVectorLayer* layer);
		gm_geomap_lines add_GeoMap_Dyke(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_geomap_lines add_GeoMap_Dyke(const std::string& newFullPathFile, QgsVectorLayer* layer);

		// 中段图(一区两点三线)(中段图图层与地质图图层一致，且属性字段也一致)
		QgsVectorLayer* create_MiningLevel_GeoReg(const std::string& fullPathFile);		// 地层区图层
		gm_a_rgns read_MiningLevel_GeoReg(const std::string& fullPathFile);
		gm_a_rgns read_MiningLevel_GeoReg(QgsVectorLayer* layer);
		gm_a_rgns add_MiningLevel_GeoReg(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_a_rgns add_MiningLevel_GeoReg(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_MiningLevel_GeoPnt(const std::string& fullPathFile);		// 地质点图层
		gmeGeoPnts read_MiningLevel_GeoPnt(const std::string& fullPathFile);
		gmeGeoPnts read_MiningLevel_GeoPnt(QgsVectorLayer* layer);
		gmeGeoPnts add_MiningLevel_GeoPnt(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gmeGeoPnts add_MiningLevel_GeoPnt(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_MiningLevel_OriPnt(const std::string& fullPathFile);		// 产状点图层
		gmeGeoOriPnts read_MiningLevel_OriPnt(const std::string& fullPathFile);
		gmeGeoOriPnts read_MiningLevel_OriPnt(QgsVectorLayer* layer);
		gmeGeoOriPnts add_MiningLevel_OriPnt(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gmeGeoOriPnts add_MiningLevel_OriPnt(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_MiningLevel_GeoLine(const std::string& fullPathFile);		// 地质界线图层
		gm_geomap_lines read_MiningLevel_GeoLine(const std::string& fullPathFile);
		gm_geomap_lines read_MiningLevel_GeoLine(QgsVectorLayer* layer);
		gm_geomap_lines add_MiningLevel_GeoLine(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_geomap_lines add_MiningLevel_GeoLine(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_MiningLevel_GeoFault(const std::string& fullPathFile);		// 断层线图层
		gme_faults read_MiningLevel_GeoFault(const std::string& fullPathFile);
		gme_faults read_MiningLevel_GeoFault(QgsVectorLayer* layer);
		gme_faults add_MiningLevel_GeoFault(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gme_faults add_MiningLevel_GeoFault(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_MiningLevel_Dyke(const std::string& fullPathFile);			// 岩脉线图层
		gm_geomap_lines read_MiningLevel_Dyke(const std::string& fullPathFile);
		gm_geomap_lines read_MiningLevel_Dyke(QgsVectorLayer* layer);
		gm_geomap_lines add_MiningLevel_Dyke(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_geomap_lines add_MiningLevel_Dyke(const std::string& newFullPathFile, QgsVectorLayer* layer);

		// 剖面图(一区两点四线)
		bool read_SectionMap(const QgsProject* qgsPrj, gm_section_map& map);

		QgsVectorLayer* create_SectionMap_HoleLocateLine(const std::string& fullPathFile);	// 剖面定位轨迹线图层
		gm_section_holes read_SectionMap_HoleLocateLine(const std::string& fullPathFile);
		gm_section_holes read_SectionMap_HoleLocateLine(QgsVectorLayer* layer);
		gm_section_holes add_SectionMap_HoleLocateLine(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_section_holes add_SectionMap_HoleLocateLine(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_SectionMap_GeoReg(const std::string& fullPathFile);			// 地层区图层
		gm_section_rgns read_SectionMap_GeoReg(const std::string& fullPathFile);
		gm_section_rgns read_SectionMap_GeoReg(QgsVectorLayer* layer);
		gm_section_rgns add_SectionMap_GeoReg(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_section_rgns add_SectionMap_GeoReg(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_SectionMap_GeoPnt(const std::string& fullPathFile);			// 地质点图层
		gmeGeoPnts read_SectionMap_GeoPnt(const std::string& fullPathFile);
		gmeGeoPnts read_SectionMap_GeoPnt(QgsVectorLayer* layer);
		gmeGeoPnts add_SectionMap_GeoPnt(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gmeGeoPnts add_SectionMap_GeoPnt(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_SectionMap_OriPnt(const std::string& fullPathFile);			// 产状点图层
		gmeGeoOriPnts read_SectionMap_OriPnt(const std::string& fullPathFile);
		gmeGeoOriPnts read_SectionMap_OriPnt(QgsVectorLayer* layer);
		gmeGeoOriPnts add_SectionMap_OriPnt(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gmeGeoOriPnts add_SectionMap_OriPnt(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_SectionMap_GeoLine(const std::string& fullPathFile);			// 地质界线图层
		gm_section_lines read_SectionMap_GeoLine(const std::string& fullPathFile);
		gm_section_lines read_SectionMap_GeoLine(QgsVectorLayer* layer);
		gm_section_lines add_SectionMap_GeoLine(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_section_lines add_SectionMap_GeoLine(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_SectionMap_SectRoute(const std::string& fullPathFile);		// 地质界线图层
		QgsVectorLayer* create_SectionMap_TerrainLine(const std::string& fullPathFile);		// 地形线图层

		QgsVectorLayer* create_SectionMap_GeoFault(const std::string& fullPathFile);			// 断层线图层
		gme_faults read_SectionMap_GeoFault(const std::string& fullPathFile);
		gme_faults read_SectionMap_GeoFault(QgsVectorLayer* layer);
		gme_faults add_SectionMap_GeoFault(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gme_faults add_SectionMap_GeoFault(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_SectionMap_Dyke(const std::string& fullPathFile);				// 岩脉线
		gm_geomap_lines read_SectionMap_Dyke(const std::string& fullPathFile);
		gm_geomap_lines read_SectionMap_Dyke(QgsVectorLayer* layer);
		gm_geomap_lines add_SectionMap_Dyke(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_geomap_lines add_SectionMap_Dyke(const std::string& newFullPathFile, QgsVectorLayer* layer);

		// 地层分区图
		QgsVectorLayer* create_BoundMap_StratReg(const std::string& fullPathFile);				// 分区图层
		gm_a_rgns read_BoundMap_StratReg(const std::string& fullPathFile);
		gm_a_rgns read_BoundMap_StratReg(QgsVectorLayer* layer);
		gm_a_rgns add_BoundMap_StratReg(std::vector<std::string>& newFullPathFiles, QgsVectorLayer* layer);
		gm_a_rgns add_BoundMap_StratReg(const std::string& newFullPathFile, QgsVectorLayer* layer);

		QgsVectorLayer* create_BoundMap_StratLine(const std::string& fullPathFile);				// 分区线图层

		// 地名图层
		QgsVectorLayer* create_AddrName_Pnt(const std::string& fullPathFile);
		addr_notes read_AddrName_Pnt(const std::string& fullPathFile);

		// 水系图层
		QgsVectorLayer* create_Water_Reg(const std::string& fullPathFile);
		water_rgns read_Water_Reg(const std::string& fullPathFile);

		// 打开shp文件
		QgsVectorLayer* getLayerFromShp(const std::string& fullPathFile);
		// 根据指定的图层类型和图层字段创建shp文件
		QgsVectorLayer* createShpFile(const std::string& fullPathFile, const QgsWkbTypes::Type& type, const vector<QgsField>& fields);

		QgsVectorLayer* creatEmptyLayer(const string & fullPathFile, const QgsWkbTypes::Type& type, vector<QgsField>& fields);
		
		// 对shp文件的坐标进行平移
		void updateShpFileByOffset(const std::string& fullPathFile, double xOffset = 0.0, double yOffset = 0.0);
		// 对shp文件的坐标进行缩放
		void updateShpFileByScale(const std::string& fullPathFile, double xScale = 1.0, double yScale = 1.0);

		// 图层字段管理器
		MapFieldMng *get_MapFieldMng() const;
		// 获取shp文件的所有字段名称
		std::vector<std::string> getLayerFieldNames(const std::string& fullPathFile);
		// 获取shp文件的所有字段
		QgsFields getLayerQgsFields(const std::string& fullPathFile);
		// 修改图层的字段 mp 标准名称：用户名称
		void alterLayerField(const std::map<std::string, std::string>& mp, QgsVectorLayer* layer);
		QgsVectorLayer* createShpFile(const std::string& fullPathFile, const QgsWkbTypes::Type& type, const QgsFields& fields);
		// 获取shp文件（点\线\区）中所有点的坐标
		void getPointFromShp(const std::string& fullPathFile, vector<gme_vector2d>& vPnt2d);
		void getPointFromShp(const std::string& fullPathFile, QVector<QgsPointXY>& vPntXY);

		// 创建地质点图层，内存级
		QgsVectorLayer* fun1(const std::map<std::string, std::vector<gme_vector3d>>& data);
		QgsVectorLayer* fun1(const std::map<std::string, gme_vector2d>& data);
		// 创建产状点图层，内存级
		QgsVectorLayer* fun2(const std::map<std::string, std::vector<StruOriPnt>>& data);
		QgsVectorLayer* fun2(const std::map<std::string, StruOriPnt>& data);
		// 创建地层线图层(地质图)，内存级
		QgsVectorLayer* fun3(const std::map<std::string, std::vector<gm_geomap_line>>& data);
		// 创建地层线图层(剖面图)，内存级
		QgsVectorLayer* fun4(const std::vector<gm_section_line>& data);
		// 创建断层线图层，内存级
		QgsVectorLayer* fun5(const std::vector<std::vector<gme_vector2d>>& lines_2d, const std::vector<gme_fault>& faults);
		// 创建地层区图层(剖面图), 内存级
		QgsVectorLayer* fun6(const std::map<std::string, std::vector<gm_section_rgn>>& strat_rgns);
		// 创建地形线图层(剖面图), 内存级
		QgsVectorLayer* fun7(const std::vector<gme_vector2d>& formLine, const std::vector<std::string>& fieldNames);

		QString create_GeoMap_Prj(const QString& prjPath);
		QString create_MiningLevel_Prj(const QString& prjPath);
		bool create_SectionMap_Prj(const QString& prjPath);

		// 从shp文件中读取轨迹数据，包括三维的点坐标和每个点的速度
		void read_TrackData(const std::string& fullPathFile, std::vector<gme_vector3d>& pos, std::vector<double>& speed);

		// 创建剖面图的注记图层,钻孔的图层和地层的图层
		QgsVectorLayer* create_SectionNote_ofHole(const std::string& fullPathFile);
		QgsVectorLayer* create_SectionNote_ofStrat(const std::string& fullPathFile);
		QgsVectorLayer* create_Polygon_ofHolePillar(const std::string& fullPathFile);

		//从shp文件获取坐标数据
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

		//取出gis色表对象...
		__int64 getGISClrlib(std::string gisclrFilePath = "");

	public:
		// 导出QgsProject二维地图到数据库中生成新地图。返回被导入的地图在数据库中的ID。返回值如小于1表示导入失败。
		int ExportMapToSpatialDB(QgsProject* qgsProject, GeoMapType mapType, const DB_CONN_INFO& dbInfo) const;
		// 从数据库中打开二维地图。返回的QgsProject对象由调用者负责析构。
		QgsProject* LoadMapFromSpatialDB(const DB_CONN_INFO& dbInfo, int mapId) const;
		// 钻孔柱状图：绑定钻孔及其对应的柱状图。
		bool BindHoleAndColumnMap(int holeDBId, int holeId, int stratVersion, const DB_CONN_INFO& dbInfo, int mapId);

		QString getPrefixOfS3DMURL() const;
		QString genURLOfS3DMMap(int dbId, int mapId) const;
		void setMapURLToQgsProject(QgsProject* qgsProject, const QString& url) const;
		QString getMapURLWithinQgsProject(const QgsProject* qgsProject) const;

		// 打开数据库对应的数据集
		GDALDataset* OpenDatasetFromSpatialDB(const DB_CONN_INFO& dbInfo) const;
		void CloseDatasetFromSpatialDB(GDALDataset* dataset) const;

		OGRwkbGeometryType QgsWkbTypeToOGRwkBType(QgsWkbTypes::Type wkbType) const;
		void QgsFieldToOGRField(const QgsField& field, OGRFieldDefn& ogrField) const;

	public:
		// 在数据集中创建地图图层。
		// layerBaseName：是图层对应的样式的名字。
		// layerOrder：是图层在地图中的顺序，从1开始计数。数字小的图层位于前列。
		// dbObj：数据集所在的空间数据库，包含有效的数据库连接。
		QgsVectorLayer* CreateLayerInDataset(GDALDataset* dataset, int mapId, const QString& layerName, const QString& layerBaseName, QgsWkbTypes::Type geoType, const QgsFields& fields, const QgsCoordinateReferenceSystem* srs,
			int layerOrder, GME_LinkType linkType, s3dSpatialDB* dbObj) const;
		// 增加TIF栅格图层。
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

		__int64			mGisClrlibMng;//GIS颜色管理器...
	};
}