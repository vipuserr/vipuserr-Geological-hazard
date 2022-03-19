#pragma once

// TODO: ���ļ��Ķ�������
// -- LH.2021.09.10 finished.

#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "s3d_geomodeliolib_global.h"
#include "s3d_GeomMath.h"
#include "AttrDBTool.h"

namespace Smart3dMap
{
	class S3D_GEOMODELIOLIB_EXPORT LayerClipper
	{
	public:
		LayerClipper();
		~LayerClipper();

		// clipping the data.
		bool ClippingDataFromAToB(int64_t sa_con_A, int64_t sa_con_B, std::vector<gme_vector2d> polygon);
		bool ClippingDataFromAToB(int64_t sa_con_A, int64_t sa_con_B, gme_rect_2d rect);
		bool ClippingDataFromAToB(int64_t sa_con_A, int64_t sa_con_B, gme_circle circle);
	
	private:
		// Ϊ����Ҫ��������ö�٣� ��ΪҪ������ϣ�����ֵ�õġ� -- LH.2021.09.07 09:48 commented.
		typedef enum DataType
		{
			Long,
			Double,
			String
		}DataType;

		typedef struct FetchInfo
		{
			std::string m_inner_field_name;
			DataType m_type;
			std::string m_fetch_id;
		} FetchInfo;

	private:
		static std::map<std::string, BaseSqlConfig>& getMSqlConfig();
		static void initMSqlConfig();

	private:
		void init();
		void initMTableToFieldList();
	private:
		// ������Χ����
		void parseRegionCondition(const std::vector<gme_vector2d>& polygon);
		void parseRegionCondition(const gme_rect_2d& rect);
		void parseRegionCondition(gme_circle& circle);
		// �ü����б�
		void clipAllTables();
		// �ü�ĳ�ű�
		void clipTable(const std::pair< std::string, std::vector< FetchInfo> > &table_info, const BaseSqlConfig &sql_config);

	private:
		// ����sql���ִ�зָ�(ͨ��)
		void exeClip(std::string sql_a_select, std::string sql_b_insert, std::vector<FetchInfo> &fetch_info_list);
		// ���� select ���, ͨ��, ���λ��Ϣ������
		void generateSelectSql(std::string &sql_a_select, std::vector<FetchInfo> &fetch_info_list, const std::pair< std::string, std::vector< FetchInfo> > &table_info, const BaseSqlConfig &sql_config);
		// ���� select ���, ����, ȫ�����(��׼�ز�汾���׼�ز�����)
		void generateSelectSql(std::string &sql_a_select, std::vector<FetchInfo> &fetch_info_list, const std::pair< std::string, std::vector< FetchInfo> > &table_info);
		// ���� insert ���
		void generateInsertSql(std::string &sql_b_insert, const std::string &table_name, const std::vector<FetchInfo> &fetch_info_list);
		

	private :
		// ������ֱ��ʹ�ã����� getMSqlConfig ��̬����
		static std::map<std::string, BaseSqlConfig> sql_config_with_pnt_table;
		static bool isSqlConfigInited;

	private:
		std::vector< std::pair< std::string, std::vector< FetchInfo> > > m_table_to_field_list;

		int64_t m_sa_cmd_A;
		int64_t m_sa_cmd_B;

		gme_rect_2d m_rect;
		std::vector<gme_vector2d> m_polygon;
	};
}
