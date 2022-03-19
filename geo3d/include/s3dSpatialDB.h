#pragma once

#include "s3dSpatialDBEngine_exp.h"
#include <gmeDef.h>
#include <ctime>
#include "s3d_explicit_stru.h"
#include <sqlapi/SQLAPI.h>

namespace Smart3dMap {

	// �ռ����ݿ��д�ӿڻ��ࡣ
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
			std::string crsCode;	// ��"EPSG:4326"��"WGS 84"�ȡ�
			std::string crsWKT;		// �������ϵ����ϸ������OGC WKT��ʽ����
			double minX, maxX, minY, maxY;
			std::string sld;	// ��ʽ����
			int layerOrder;		// ͼ���ڵ�ͼ�е�˳��š���1��ʼ����������С��ͼ��λ��ǰ�С�
			std::tm createdAt, updatedAt;
			std::string type;	// ͼ�����ͣ�vector��raster��

			LayerInfo();
		};

		class S3D_SPATIAL_DBENGINE_API MapInfo {
		public:
			int id;
			std::string name;
			GeoMapType type;
			std::string crsCode;	// ��"EPSG:4326"��"WGS 84"�ȡ�
			std::string crsWKT;		// �������ϵ����ϸ������OGC WKT��ʽ����
			double minX, maxX, minY, maxY;
			std::string qgsProject;
			std::tm createdAt, updatedAt;

			MapInfo();
		};

		// ��Ӧ��*.tfw�ļ�����Ϣ��
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
			SAString fileContent;	// �ļ���ԭʼ�������ֽ����ݡ�
			RasterTFW tfw;

			RasterLayerData();
		};

	public:
		s3dSpatialDB(SAConnection* dbCon);
		virtual ~s3dSpatialDB();

		SAConnection* GetDBCon() const;

		int CreateMap(const std::string& name, GeoMapType mapType, const std::string& crsCode, const std::string& crsWKT);
		/// @brief Ϊ��ͼ����ʸ��ͼ���¼��
		/// @param mapId
		/// @param name			ͼ�����ʾ���ơ�
		/// @param baseName		ͼ���Ӧ����ʽ�����֡�
		/// @param tableName	ͼ���������ڵ����ݱ�����֡�
		/// @param crsCode		ͼ����ʹ�õ�����ο�ϵ��ID����"EPSG:4326"��"WGS 84"�ȡ�
		/// @param crsWKT		ͼ����ʹ�õ�����ο�ϵ����ϸ������OGC WKT��ʽ����
		/// @param layerOrder	ͼ���ڵ�ͼ�е�˳��š���1��ʼ������
		/// @return				���ز�����״̬���ɹ���ʧ�ܡ�
		bool InsertLayerIntoMap(int mapId, const std::string& name, const std::string& baseName, const std::string& tableName, const std::string& crsCode, const std::string& crsWKT, int layerOrder);
		/// @brief Ϊ��ͼ����դ��ͼ��(*.tif)��¼��
		/// @param mapId
		/// @param name			ͼ�����ʾ���ơ�
		/// @param baseName		ͼ���Ӧ����ʽ�����֡�
		/// @param crsCode		ͼ����ʹ�õ�����ο�ϵ��ID����"EPSG:4326"��"WGS 84"�ȡ�
		/// @param crsWKT		ͼ����ʹ�õ�����ο�ϵ����ϸ������OGC WKT��ʽ����
		/// @param layerOrder	ͼ���ڵ�ͼ�е�˳��š���1��ʼ������
		/// @param filePath		դ�������ļ���·����
		bool InsertRasterLayerIntoMap(int mapId, const std::string& name, const std::string& baseName, const std::string& crsCode, const std::string& crsWKT, int layerOrder, const std::string& filePath, const RasterTFW& tfw);

		/// ��ȡ�ĵ�ͼ����QgsProject���ݡ�
		bool ListMaps(GeoMapType mapType, int pageNo, int pageSize, std::vector<MapInfo>& maps, int& totalCount, std::string* error = nullptr);

		/// @breif ��ȡ��ͼ��Ϣ��������ͼ�����ݡ�
		/// @param id			��ͼ��ID��
		/// @param includingQgsProject �Ƿ����Qgs Project���ݡ�
		/// @param mapInfo		�����ͼ��Ϣ��
		/// @param error		���������Ϣ��
		bool GetMap(int id, bool includingQgsProject, MapInfo& mapInfo, std::string* error = nullptr);
		/// @brief ɾ��ָ���ĵ�ͼ��ɾ����ͼ֮ǰӦ�ȴ� s3dm-map-service �г��������õ�ͼ��
		bool DeleteMap(int id, std::string* error = nullptr);
		/// @brief ��ȡ��ͼ��ͼ�����ݡ�
		bool ListLayersOfMap(int mapId, bool includingSLD, std::vector<LayerInfo>& layers);
		bool ListLayersOfMap(int mapId, int pageNo, int pageSize, bool includingSLD, std::vector<LayerInfo>& layers, int& totalCount);
		/// @brief ��ȡդ��ͼ������ݡ�
		bool GetRasterLayerData(int layerId, RasterLayerData& layerData);

		bool UpdateMapProject(int mapId, const std::string& qgsProjectUtf8Content);
		bool UpdateMapBound(int mapId, const gme_rect_2d& rect);
		/// layerOrder��ͼ���ڵ�ͼ�е�˳��š���1��ʼ������
		bool UpdateLayerSLD(int mapId, int layerOrder, const std::string& utf8SLD);
		/// layerOrder��ͼ���ڵ�ͼ�е�˳��š���1��ʼ������
		bool UpdateLayerBound(int mapId, int layerOrder, const gme_rect_2d& rect);

		/// @breif ����׺����Ӧ����״ͼ��
		/// @param mapId		�����״ͼ��ID��
		/// @param holeDBId		����������ݿ��ID��
		/// @param holeId		��׵�ID��
		/// @param stratVersionId	������״ͼ���õı�׼�ز�İ汾�š�
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
