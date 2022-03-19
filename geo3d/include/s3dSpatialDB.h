#pragma once

#include "s3dSpatialDBEngine_exp.h"
#include <gmeDef.h>
#include <ctime>
#include "s3d_explicit_stru.h"
#include <sqlapi/SQLAPI.h>

namespace Smart3dMap {

	// 空间数据库读写接口基类。
	class S3D_SPATIAL_DBENGINE_API s3dSpatialDB {
	public:
		static bool IsSupported(GME_LinkType linkType);
		static std::unique_ptr<s3dSpatialDB> GetDBObject(GME_LinkType linkType, SAConnection* dbCon);

		static SAString CompressString(const std::string& str);
		static std::string UncompressString(const SAString& str);

	public:
		class S3D_SPATIAL_DBENGINE_API LayerInfo {
		public:
			int id;
			int mapId;
			std::string name, baseName, tableName;
			std::string crsCode;	// 如"EPSG:4326"、"WGS 84"等。
			std::string crsWKT;		// 坐标参照系的详细参数（OGC WKT格式）。
			double minX, maxX, minY, maxY;
			std::string sld;	// 样式数据
			int layerOrder;		// 图层在地图中的顺序号。从1开始计数。数字小的图层位于前列。
			std::tm createdAt, updatedAt;
			std::string type;	// 图层类型：vector，raster。

			LayerInfo();
		};

		class S3D_SPATIAL_DBENGINE_API MapInfo {
		public:
			int id;
			std::string name;
			GeoMapType type;
			std::string crsCode;	// 如"EPSG:4326"、"WGS 84"等。
			std::string crsWKT;		// 坐标参照系的详细参数（OGC WKT格式）。
			double minX, maxX, minY, maxY;
			std::string qgsProject;
			std::tm createdAt, updatedAt;

			MapInfo();
		};

		// 对应于*.tfw文件的信息。
		class S3D_SPATIAL_DBENGINE_API RasterTFW {
		public:
			double stepX, stepY;
			double rotationCoefX, rotationCoefY;
			double topLeftX, topLeftY;

			RasterTFW();

		};

		class S3D_SPATIAL_DBENGINE_API RasterLayerData {
		public:
			int id, mapId, layerOrder;
			std::string fileName, layerType;
			SAString fileContent;	// 文件的原始二进制字节内容。
			RasterTFW tfw;

			RasterLayerData();
		};

	public:
		s3dSpatialDB(SAConnection* dbCon);
		virtual ~s3dSpatialDB();

		SAConnection* GetDBCon() const;

		int CreateMap(const std::string& name, GeoMapType mapType, const std::string& crsCode, const std::string& crsWKT);
		/// @brief 为地图增加矢量图层记录。
		/// @param mapId
		/// @param name			图层的显示名称。
		/// @param baseName		图层对应的样式的名字。
		/// @param tableName	图层数据所在的数据表的名字。
		/// @param crsCode		图层所使用的坐标参考系的ID，如"EPSG:4326"、"WGS 84"等。
		/// @param crsWKT		图层所使用的坐标参考系的详细参数（OGC WKT格式）。
		/// @param layerOrder	图层在地图中的顺序号。从1开始计数。
		/// @return				返回操作的状态，成功或失败。
		bool InsertLayerIntoMap(int mapId, const std::string& name, const std::string& baseName, const std::string& tableName, const std::string& crsCode, const std::string& crsWKT, int layerOrder);
		/// @brief 为地图增加栅格图层(*.tif)记录。
		/// @param mapId
		/// @param name			图层的显示名称。
		/// @param baseName		图层对应的样式的名字。
		/// @param crsCode		图层所使用的坐标参考系的ID，如"EPSG:4326"、"WGS 84"等。
		/// @param crsWKT		图层所使用的坐标参考系的详细参数（OGC WKT格式）。
		/// @param layerOrder	图层在地图中的顺序号。从1开始计数。
		/// @param filePath		栅格数据文件的路径。
		bool InsertRasterLayerIntoMap(int mapId, const std::string& name, const std::string& baseName, const std::string& crsCode, const std::string& crsWKT, int layerOrder, const std::string& filePath, const RasterTFW& tfw);

		/// 获取的地图不含QgsProject数据。
		bool ListMaps(GeoMapType mapType, int pageNo, int pageSize, std::vector<MapInfo>& maps, int& totalCount, std::string* error = nullptr);

		/// @breif 获取地图信息。不包含图层数据。
		/// @param id			地图的ID。
		/// @param includingQgsProject 是否输出Qgs Project数据。
		/// @param mapInfo		输出地图信息。
		/// @param error		输出错误信息。
		bool GetMap(int id, bool includingQgsProject, MapInfo& mapInfo, std::string* error = nullptr);
		/// @brief 删除指定的地图。删除地图之前应先从 s3dm-map-service 中撤销发布该地图。
		bool DeleteMap(int id, std::string* error = nullptr);
		/// @brief 获取地图的图层数据。
		bool ListLayersOfMap(int mapId, bool includingSLD, std::vector<LayerInfo>& layers);
		bool ListLayersOfMap(int mapId, int pageNo, int pageSize, bool includingSLD, std::vector<LayerInfo>& layers, int& totalCount);
		/// @brief 获取栅格图层的数据。
		bool GetRasterLayerData(int layerId, RasterLayerData& layerData);

		bool UpdateMapProject(int mapId, const std::string& qgsProjectUtf8Content);
		bool UpdateMapBound(int mapId, const gme_rect_2d& rect);
		/// layerOrder是图层在地图中的顺序号。从1开始计数。
		bool UpdateLayerSLD(int mapId, int layerOrder, const std::string& utf8SLD);
		/// layerOrder是图层在地图中的顺序号。从1开始计数。
		bool UpdateLayerBound(int mapId, int layerOrder, const gme_rect_2d& rect);

		/// @breif 绑定钻孔和其对应的柱状图。
		/// @param mapId		钻孔柱状图的ID。
		/// @param holeDBId		钻孔所在数据库的ID。
		/// @param holeId		钻孔的ID。
		/// @param stratVersionId	生成柱状图所用的标准地层的版本号。
		bool BindHoleAndColumnMap(int mapId, int holeDBId, int holeId, int stratVersionId);

	protected:
		static const std::string Table_Maps;
		static const std::string Table_Map_Layers;
		static const std::string Table_Map_Raster_Layers;
		static const std::string Table_Hole_Column_Maps;

	protected:
		virtual std::string GetSQLOfLastInsertId(const std::string& nameOfIdField) = 0;

	private:
		void MapInfoFromRow(MapInfo& mapInfo, SACommand& cmd, bool includingQgsProject);
		void LayerInfoFromRow(LayerInfo& layerInfo, SACommand& cmd, bool includingSLD);
		
	private:
		SAConnection* dbCon_;
	};
}
