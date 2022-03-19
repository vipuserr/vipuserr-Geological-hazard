//sql����������
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
	// �Զ����������࣬���ڹ���ͬ���͵����ݵĴ��� -- LH.2021.08.12 16:04 added.
	class S3D_DBENGINE_AUX_API AutoDataType
	{
	public:
		typedef enum DataType
		{
			None,    // NULL
			Integer, // int
			Double,  // double
			String,   // string
			Blob, // ����������
			DateTime  // date
		} DataType;
	public:
		AutoDataType();
		// �������죬���
		AutoDataType(const AutoDataType &data);
		AutoDataType(const int data);
		AutoDataType(const long data);
		AutoDataType(const double data);
		// �ַ���
		AutoDataType(const char* data);
		// �ַ���
		AutoDataType(const std::string &data);
		// ����������
		AutoDataType(const void *data_begin_ptr, size_t blob_length);
		AutoDataType(const time_t data);
		~AutoDataType();

		AutoDataType &operator=(const int data);
		AutoDataType &operator=(const long data);
		AutoDataType &operator=(const float data);
		AutoDataType &operator=(const double data);
		AutoDataType &operator=(const std::string &data);
		AutoDataType &operator=(const time_t data);

		// ���õ���toString����ʱstringֵ�Ƿ���Ҫ����(����std::string �� char* ��Ч)�� -- LH.2021.08.25 added.
		AutoDataType & changeStringConfig(bool need_quotation_mark = true);
		
		//AutoDataType::DataType getDataType();
		// �ú�������ֵʵ��Ϊ AutoDataType::DataType ���͵�ö��
		AutoDataType::DataType getDataType();


		void getData(int &data);
		void getData(long &data);
		void getData(float &data);
		void getData(double &data);
		void getData(std::string &data);
		// ��ȡ���������ݣ������ͷŸö�������Դ��
		void getData(void* &blob_begin_ptr, size_t &blob_length);
		//void getData(time_t &data);

		// TODO: ���Ż�������Ϊ���õ����ʱ���ס�ĩ�˶����ַ��� -- LH.2021.08.25 15:17 added.
		std::string toString(/*std::string quotation_mark = ""*/);

	private:
		void safeReleaseBlob();

	private:
		DataType m_data_type;
		bool m_string_need_quotation;

		int m_long_data;
		double m_double_data;
		std::string m_str_data;
		// �����������׵�ַ������ʱ����ռ䣬����ʱ�ͷſռ� -- LH.2021.12.14 11:35 added.
		void *m_blob_data_begin_ptr;
		// �����������ֽڳ��� -- LH.2021.12.14 11:35 added.
		size_t m_blob_length;
		tm *m_tm_data; // TODO: Who will release it? -- LH.2021.08.13 15:28 written.

	};

	typedef enum SQL_OPER_TYPE
	{
		SQL_UNDEF = 0,	//δ����
		SQL_PLUS = 1,	//��
		SQL_DEL = 2,	//ɾ
		SQL_GET = 3,	//��
		SQL_UPDAT = 4,	//��
		SQL_GET_NUM = 5,//ȡ����
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

	//���ݿ����ͣ���Ӧ�÷֣�
	typedef enum DB_APP_TYPE
	{
		DAT_UNKNOWN = 0,	// δ֪
		DAT_GEOATT_DB = 1,	//�����������ݿ�
		DAT_3DMDL_DB = 2,	//��άģ�����ݿ�
		DAT_2DSDE_DB = 3	//��ά�ռ����ݿ�
	}DB_APP_TYPE;

	//���ݿ�������Ϣ
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
		int sysDBId;	// ϵͳ���õ�Զ�����ݿ��ID����������ʾ��Ч�����ݿ⡣
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

	//����洢����
	class S3D_DBENGINE_AUX_API s3dSqlBase
	{
	public:
		s3dSqlBase();
		virtual ~s3dSqlBase();

	public:
		//�������ݿ�
		virtual __int64 openDb(GString url, GString user = "", GString psw = "");
		//�������ݿ�ı�ṹ
		virtual void createAllDbTbls(std::vector<std::string>& sqls);
		//��ȡsql���
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

		//// �����Ƿ���Ҫdistinct�ؼ��֡�TODO: ��������ʱȡ��ע�� -- LH.2021.09.08 14:53 added.
		//void setDistinctConfig(bool is_need = false);

		/*
			\brief ����sql���ı������ֶ�����ֵ(ֵ��ռλ�����)�������ȵ�����

			\param table ����
			\param column �ֶ���
			\param col_value_placeholder ֵ��ռλ������SACommand������ϣ�ռλ������Я����:��������͸���sql�����õ���
			\param alias ��������ѯsql������ʱ�����õ���
		*/
		void setTableColumn(const std::string &table, const std::string &column, const std::string &col_value_placeholder = "", const std::string &alias = "");

		void setTable(std::string table);
		// TODO: ɾ�� setTables(std::vector< std::string> tables) ���� -- LH.2021.09.29 11:12 commented.
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


		//��ȡ��ѯ���б�����sql
		virtual GString getUserTableNameSql();
		//��ȡ�ֶε����ƺ����� 
		//�����ˣ�wzj ����ˣ�zhuyh �ϴ��ˣ�zhuyh
		//�ϴ�ʱ�䣺20210821
		virtual GString getUserFldsInfoSql(std::string tblName);

		//�����ֵ��(�����ڵ�ʱ��Żᴴ��)
		virtual void createDictTables(void* mCon);

		//����sql����ļ��������е�sql���
		virtual std::vector<std::string> getAllSqlsFromFile(std::string sql);

		std::string getDBName(SAConnection* con) const;
	public:
		DB_CONN_INFO mDbConnInfo;
		__int64 mCurDbConn; //��ǰ�����ݿ����Ӷ���
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

		// �Ƿ���Ҫdistinct�ؼ��ֵ����á�TODO: ��������ʱȡ��ע�� -- LH.2021.09.08 14 : 53 added.
		//bool m_select_op_need_distinct; // Ĭ��false

		MapOfTableAndColumns m_map_of_table_cols;

		UnionConditionList m_union_condition_list;
		ConditionList m_condition_list;

		MapOfTableAndColumns m_sort_by_list;

		std::string m_conditional_clause;

		std::string m_sql;

	};

}

#endif 