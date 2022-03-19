//sql语句操作基类
#ifndef _S3D_SQLS_BASE_H
#define _S3D_SQLS_BASE_H

#include "gmeDef.h"
#include <time.h>
#include "s3dDBEngineAux_exp.h"

class SAConnection;
class SACommand;

#define DICT_TBL_CATE "sysdict_Mdl"
#define DICT_TBL_NAME "sysdict_MdlTbl"
#define DICT_FLD_NAME "sysdict_MdlTblFld"


namespace Smart3dMap
{
	// 自动数据类型类，用于管理不同类型的数据的处理。 -- LH.2021.08.12 16:04 added.
	class S3D_DBENGINE_AUX_API AutoDataType
	{
	public:
		typedef enum DataType
		{
			None,    // NULL
			Integer, // int
			Double,  // double
			String,   // string
			Blob, // 二进制数据
			DateTime  // date
		} DataType;
	public:
		AutoDataType();
		// 拷贝构造，深拷贝
		AutoDataType(const AutoDataType &data);
		AutoDataType(const int data);
		AutoDataType(const long data);
		AutoDataType(const double data);
		// 字符串
		AutoDataType(const char* data);
		// 字符串
		AutoDataType(const std::string &data);
		// 二进制数据
		AutoDataType(const void *data_begin_ptr, size_t blob_length);
		AutoDataType(const time_t data);
		~AutoDataType();

		AutoDataType &operator=(const int data);
		AutoDataType &operator=(const long data);
		AutoDataType &operator=(const float data);
		AutoDataType &operator=(const double data);
		AutoDataType &operator=(const std::string &data);
		AutoDataType &operator=(const time_t data);

		// 设置调用toString方法时string值是否需要引号(仅对std::string 和 char* 有效)。 -- LH.2021.08.25 added.
		AutoDataType & changeStringConfig(bool need_quotation_mark = true);
		
		//AutoDataType::DataType getDataType();
		// 该函数返回值实际为 AutoDataType::DataType 类型的枚举
		AutoDataType::DataType getDataType();


		void getData(int &data);
		void getData(long &data);
		void getData(float &data);
		void getData(double &data);
		void getData(std::string &data);
		// 获取二进制数据，无需释放该二进制资源。
		void getData(void* &blob_begin_ptr, size_t &blob_length);
		//void getData(time_t &data);

		// TODO: 想优化，参数为，得到结果时的首、末端额外字符。 -- LH.2021.08.25 15:17 added.
		std::string toString(/*std::string quotation_mark = ""*/);

	private:
		void safeReleaseBlob();

	private:
		DataType m_data_type;
		bool m_string_need_quotation;

		int m_long_data;
		double m_double_data;
		std::string m_str_data;
		// 二进制数据首地址，构造时申请空间，析构时释放空间 -- LH.2021.12.14 11:35 added.
		void *m_blob_data_begin_ptr;
		// 二进制数据字节长度 -- LH.2021.12.14 11:35 added.
		size_t m_blob_length;
		tm *m_tm_data; // TODO: Who will release it? -- LH.2021.08.13 15:28 written.

	};

	typedef enum SQL_OPER_TYPE
	{
		SQL_UNDEF = 0,	//未定义
		SQL_PLUS = 1,	//增
		SQL_DEL = 2,	//删
		SQL_GET = 3,	//查
		SQL_UPDAT = 4,	//改
		SQL_GET_NUM = 5,//取个数
	}SQL_OPER_TYPE;

	// the comparison operator.
	typedef enum COMPARISON_OPERATOR
	{
		LESS,              // <
		LESS_AND_EQUAL,    // <=
		EQUAL,             // ==
		NOT_EQUAL,         // !=
		GREATER,           // >
		GREATER_AND_EQUAL, // >=
		LIKE,              // like
		NOT_LIKE,          // not like
		IS_NULL,           // is null
		NOT_NULL           // not is null
	} COMPARISON_OPERATOR;

	// the logical operator.
	typedef enum LOGICAL_OPERATOR
	{
		AND, // and
		OR,  // or
		// NOT, // not
		END  // no operation
	} LOGICAL_OPERATOR;
	
	// sort by.
	typedef enum SORT_BY
	{
		UP,     // from smaller to bigger.
		DOWN   // from bigger to smaller.
		//DEFAULT // no set.
	} SORT_BY;

	//数据库类型（按应用分）
	typedef enum DB_APP_TYPE
	{
		DAT_UNKNOWN = 0,	// 未知
		DAT_GEOATT_DB = 1,	//地质属性数据库
		DAT_3DMDL_DB = 2,	//三维模型数据库
		DAT_2DSDE_DB = 3	//二维空间数据库
	}DB_APP_TYPE;

	//数据库连接信息
	typedef struct DB_CONN_INFO
	{
		DB_APP_TYPE dbAppType;
		GME_LinkType dbLinkType;
		std::string dbUrl;
		std::string server;
		std::string port;
		std::string dbname;
		std::string user;
		std::string psw;
		int sysDBId;	// 系统配置的远程数据库的ID。正整数表示有效的数据库。
		__int64 conn;

		DB_CONN_INFO()
		{
			dbAppType = DAT_UNKNOWN;
			dbLinkType = GME_DB_LINK_MEM;
			dbUrl = "";
			server = "";
			port = "";
			dbname = "";
			user = "";
			psw = "";
			sysDBId = 0;
			conn = 0;
		}
	}DB_CONN_INFO;

	//物理存储基类
	class S3D_DBENGINE_AUX_API s3dSqlBase
	{
	public:
		s3dSqlBase();
		virtual ~s3dSqlBase();

	public:
		//创建数据库
		virtual __int64 openDb(GString url, GString user = "", GString psw = "");
		//创建数据库的表结构
		virtual void createAllDbTbls(std::vector<std::string>& sqls);
		//获取sql语句
		virtual GString getSql(GME_OBJ_TYPE objType, SQL_OPER_TYPE operType, ...);
		// For testing. --- created on 2021.07.21 16:13
		//virtual GString getSql(SQL_OPER_TYPE operType, std::vector< std::string >& columns, )

		virtual bool tableIsExist(SAConnection* Con, std::string TblName);

	public:

		// ******************* config *** begin ********************

		// clear all configurations and data resources.
		void clear();

		// sql type.
		void setOpType(SQL_OPER_TYPE op_type);

		//// 设置是否需要distinct关键字。TODO: 将来有用时取消注释 -- LH.2021.09.08 14:53 added.
		//void setDistinctConfig(bool is_need = false);

		/*
			\brief 设置sql语句的表名、字段名、值(值用占位符替代)、别名等的配置

			\param table 表名
			\param column 字段名
			\param col_value_placeholder 值的占位符，与SACommand对象配合，占位符无需携带“:”。插入和更新sql可能用到。
			\param alias 别名。查询sql的配置时可能用到。
		*/
		void setTableColumn(const std::string &table, const std::string &column, const std::string &col_value_placeholder = "", const std::string &alias = "");

		void setTable(std::string table);
		// TODO: 删除 setTables(std::vector< std::string> tables) 函数 -- LH.2021.09.29 11:12 commented.
		void setTables(std::vector< std::string> tables);

		// union conditions.
		void setCondition(std::string table, std::string column, std::string table1, std::string column1);
		// another conditions.
		void setCondition(const std::string &table, const std::string &column, const COMPARISON_OPERATOR cmp_op, const std::string &col_value_placeholder, const LOGICAL_OPERATOR logical_op);

		// TODO: shoundn't depend the table name for mysql. -- LH.2021.08.10 17:24 written.
		void setSortWay(std::string table_name, std::string col_name, std::string alias, SORT_BY sort_by = SORT_BY::UP);


		// ******************* config *** end ********************

		// generating sql.
		std::string generateSql();

		// feeding params for SACommand.
		SACommand& feedParams(SACommand &sa_cmd, const std::vector<std::pair<std::string, AutoDataType>> &param_list);

	public:


		//获取查询所有表名的sql
		virtual GString getUserTableNameSql();
		//获取字段的名称和类型 
		//开发人：wzj 检查人：zhuyh 上传人：zhuyh
		//上传时间：20210821
		virtual GString getUserFldsInfoSql(std::string tblName);

		//创建字典表(表不存在的时候才会创建)
		virtual void createDictTables(void* mCon);

		//根据sql语句文件读出所有的sql语句
		virtual std::vector<std::string> getAllSqlsFromFile(std::string sql);

		std::string getDBName(SAConnection* con) const;
	public:
		DB_CONN_INFO mDbConnInfo;
		__int64 mCurDbConn; //当前的数据库连接对象
		GString		mSqlClause;
		GString		mSqlFileName;


	protected:

		// will be overwritten in the subclass.
		virtual std::string getComparisonOp(COMPARISON_OPERATOR op);
		virtual std::string getLogicalOp(LOGICAL_OPERATOR op);
		virtual std::string getSortWayKey(SORT_BY sort_by);

		typedef struct ColumnInfo
		{
			std::string m_name;
			std::string m_alias;
			std::string m_value_placeholder;
			SORT_BY sort_by;
		} ColumnInfo;

		typedef struct Condition
		{
			std::string m_table_name;
			std::string m_col_name;
			COMPARISON_OPERATOR m_comparison_op;
			std::string m_value_placeholder;
			LOGICAL_OPERATOR m_logical_op;
		} Condition;

		typedef struct UnionCondition
		{
			std::string m_table_name;
			std::string m_col_name;
			std::string m_table1_name;
			std::string m_col1_name;
		} UnionCondition;

		typedef std::map<std::string, std::vector<ColumnInfo>> MapOfTableAndColumns;
		
		typedef std::vector<UnionCondition> UnionConditionList;
		typedef std::vector<Condition> ConditionList;

		const std::string kInsertHead = "insert into ";
		const std::string kDeleteHead = "delete from ";
		const std::string kSelectHead = "select ";
		const std::string kUpdateHead = "update ";

		// Tool function.
		void exceptRepeatColumns();

		void generateConditionalClause();
		
		// Reading operations.
		virtual void generateSelectSql();
		// Writing operations.
		virtual void generateInsertSql();
		virtual void generateDeleteSql();
		virtual void generateUpdateSql();


		SQL_OPER_TYPE m_op_type;

		// 是否需要distinct关键字的配置。TODO: 将来有用时取消注释 -- LH.2021.09.08 14 : 53 added.
		//bool m_select_op_need_distinct; // 默认false

		MapOfTableAndColumns m_map_of_table_cols;

		UnionConditionList m_union_condition_list;
		ConditionList m_condition_list;

		MapOfTableAndColumns m_sort_by_list;

		std::string m_conditional_clause;

		std::string m_sql;

	};

}

#endif 