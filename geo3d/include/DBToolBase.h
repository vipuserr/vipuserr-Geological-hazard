#pragma once

#include "s3dAttDBEngine_exp.h"
#include "s3d_DbTblFldDef.h"
#include <map>
#include <vector>
#include <string>
#include <SQLAPI.h>
#include <gmeDef.h>
#include "s3dSqlsBase.h"
using namespace std;

namespace Smart3dMap
{
	// base_sql的配置结构，试验中。。。 -- LH.2021.08.27 20:06 added.
	typedef struct BaseSqlConfig_AnotherTable
	{
		std::string m_table_name;
		bool m_all_fields;
		std::vector< std::string > field_list;
	} BaseSqlConfig_AnotherTable;
	typedef struct BaseSqlConfig_UnionCondition
	{
		std::pair<std::string, std::string> m_left_value;
		std::pair< std::string, std::string> m_right_value;
	} BaseSqlConfig_UnionCondition;
	typedef struct BaseSqlConfig
	{
		std::string m_main_table;
		std::vector<BaseSqlConfig_AnotherTable> m_another_tables;
		std::vector<BaseSqlConfig_UnionCondition> m_union_conditions;
	} BaseSqlConfig;








	class S3D_ATT_DBENGINE_API DBToolBase
	{
	protected:
		typedef struct FieldInfo
		{
			std::string m_inner_name;
			//std::string m_user_name; // might be used in the future. -- LH.2021.08.26 20:55 commented.
			long m_enum_field_macro;
			DataType m_data_type;
			std::string m_fetch_id;
		} FieldInfo;

		typedef FieldInfo FetchInfo;
		//typedef std::pair<std::string, SORT_BY> SortByInfoItem;

	protected:
		DBToolBase();
		virtual ~DBToolBase();
		virtual void initBaseSqlConfiguration() = 0;
		//该函数负责添加查询条件（不包含联合查询条件）
		virtual void sqlGenAddCond(s3dSqlBase* sql_generator_ptr,const BaseSqlConfig &sql_config, std::vector<std::pair<std::string, AutoDataType>> &param_list) = 0;

		//子类必须实现该方法
		template <class ClassName>
		void parseRSItem(SACommand &saCmd,const std::vector<FetchInfo> &fetch_info_list, ClassName &result);

	public:
		std::map<std::string, BaseSqlConfig>& GetBaseSqlConfig();
		



	protected:
		void initMapOfDict(std::vector<DbTblFldDef::s3dDbMdlInfo>& mdlInfos);
		//template <class ClassName>
		//void getData(std::string func_name, std::vector<ClassName> &result_list, vector<vector<gme_vector2d>>& polygon, std::vector<CONDITION_INFO> *conditions = nullptr);

		

		template <class ClassName>
		void getData(SAConnection* con , std::string sql, const std::vector<std::pair<std::string, AutoDataType>> &param_list, const std::map<std::string, std::vector<FetchInfo>>& fetch_info_list, std::vector<ClassName> &result_list);

		template <class ClassName>
		void parseResultSet(SACommand &saCmd, const std::map<std::string, std::vector<FetchInfo>> &fetch_info_list, std::vector<ClassName> &result_list);

		// 仅支持生成查询表各字段信息的sql语句
		bool generateSql(std::string &result_sql, SAConnection* con, std::map<std::string, std::vector<FetchInfo>> &fetch_info_list, std::vector<std::pair<std::string, AutoDataType>> &param_list, const BaseSqlConfig &sql_config);





	protected:
		// 使用该变量需要调用 initBaseSqlConfiguration 函数，而实际上它仅执行一次赋值。 -- LH.2021.08.27 20:42 added.
		std::map<std::string, BaseSqlConfig>			base_sql_config;
		std::map<std::string, std::vector<FieldInfo>>	m_inner_table_to_field;
	};

	template<class ClassName>
	void Smart3dMap::DBToolBase::getData(SAConnection * con, std::string sql, const std::vector<std::pair<std::string, AutoDataType>> &param_list, const std::map<std::string, std::vector<FetchInfo>>& fetch_info_list,std::vector<ClassName>& result_list)
	{
		if (con == nullptr || sql == "")
		{
			return;
		}
		// 用来给 SACommand 中的“值占位符”设置真实值。
		s3dSqlBase *sql_base_ptr = s3dDBEAux::newSqlClsObjByClientType(con);
		if (sql_base_ptr == nullptr)
		{
			return;
		}
		SACommand saCmd;
		try
		{
			saCmd.setConnection(con);
			saCmd.setCommandText(sql.c_str());

			sql_base_ptr->feedParams(saCmd, param_list).Execute();

			parseResultSet(saCmd, fetch_info_list, result_list);
		}
		catch (SAException &e)
		{
			std::string err_text = e.ErrText().GetMultiByteChars();
			OutputDebugString(err_text.c_str());
		}
		delete sql_base_ptr;
	}

	template <class ClassName>
	void DBToolBase::parseResultSet(SACommand &saCmd, const std::map<std::string, std::vector<FetchInfo>> &fetch_info_list, std::vector<ClassName> &result_list)
	{
		try
		{
			result_list.clear(); // 清空旧数据。 -- LH.2021.08.11 10:51 added.
			result_list.reserve(50); // 预分配50个数据存储空间。-- LH.2021.08.11 10:51 added.
			ClassName result;
			while (saCmd.FetchNext())
			{
				for (auto fetch_info_list_it = fetch_info_list.begin(); fetch_info_list_it != fetch_info_list.end(); ++fetch_info_list_it)
				{
					parseRSItem(saCmd, fetch_info_list_it->second, result);
				}

				result_list.push_back(result);
			}
		}
		catch (const SAException &e)
		{
			std::string err_text = e.ErrText().GetMultiByteChars();
		}
	}



}



