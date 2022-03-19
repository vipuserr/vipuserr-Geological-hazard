#pragma once

// TODO: 区文件的多区处理
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
		// 为何又要定义类型枚举？ 因为要降低耦合，这是值得的。 -- LH.2021.09.07 09:48 commented.
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
		// 解析范围条件
		void parseRegionCondition(const std::vector<gme_vector2d>& polygon);
		void parseRegionCondition(const gme_rect_2d& rect);
		void parseRegionCondition(gme_circle& circle);
		// 裁剪所有表
		void clipAllTables();
		// 裁剪某张表
		void clipTable(const std::pair< std::string, std::vector< FetchInfo> > &table_info, const BaseSqlConfig &sql_config);

	private:
		// 根据sql语句执行分割(通常)
		void exeClip(std::string sql_a_select, std::string sql_b_insert, std::vector<FetchInfo> &fetch_info_list);
		// 生成 select 语句, 通用, 与点位信息表联合
		void generateSelectSql(std::string &sql_a_select, std::vector<FetchInfo> &fetch_info_list, const std::pair< std::string, std::vector< FetchInfo> > &table_info, const BaseSqlConfig &sql_config);
		// 生成 select 语句, 特殊, 全表输出(标准地层版本与标准地层描述)
		void generateSelectSql(std::string &sql_a_select, std::vector<FetchInfo> &fetch_info_list, const std::pair< std::string, std::vector< FetchInfo> > &table_info);
		// 生成 insert 语句
		void generateInsertSql(std::string &sql_b_insert, const std::string &table_name, const std::vector<FetchInfo> &fetch_info_list);
		

	private :
		// 不允许直接使用，调用 getMSqlConfig 静态函数
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
