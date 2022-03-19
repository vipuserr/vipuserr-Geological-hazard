#pragma once

#include "s3dAttDBEngine_exp.h"

#include <string>
#include <vector>
#include "sqlapi.h"
#include <map>
#include <mutex>

#include "s3d_AttrDBDef.h"
#include "s3d_DbTblFldDef.h"

namespace Smart3dMap
{
	struct sysDict
	{
		int TBLID;
		std::string INNERNAME;
		std::string TBL_OR_FLD;
	};

	class S3D_ATT_DBENGINE_API G2DSysDbDict
	{
	public:
		G2DSysDbDict();
		~G2DSysDbDict();

		//初始化数据，系统启动时先调用
		//static void initSysDict(string mdbFile="", eSAClient dbType = SA_ODBC_Client);

		static void initSysDict(SAConnection* con);

		static std::string getTbl(SAConnection* con, const std::string& inTblName);
		static std::string getFld(SAConnection* con, const std::string& inTblName, const std::string& inFldName);


		static int	getTblId(SAConnection* con, const std::string& tableName);

		static std::string getTexMatName(SAConnection* con, const std::string& stratCode, char bUseLevelCode = 0, long lStdID = 0);
		static std::string getClrMatName(SAConnection* con, const std::string& stratCode, char bUseLevelCode = 0, long lStdID = 0);



		//static bool tableisExist(const string& tableName);

		//根据已有的映射关系获取数据库中表的名字
		//static string getTbl(const string& inTblName, const vector<string>& vec = vector<string>());
		//static QString getQTbl(const string& inTblName, const vector<string>& vec = vector<string>());
		//根据已有的映射关系获取数据库中字段的名字
		//static string getFld(const string& inTblName, const string& inFldName, const vector<string>& vec = vector<string>());
		//static QString getQFld(const string& inTblName, const string& inFldName, const vector<string>& vec = vector<string>());

		//static string getInnerTbl(const string& outerTblName);
		//static string getInnerFld(const string& outerTblName, const string& outerFldName);

		//static string getTblDictName() { return SYSDICT_TABLE; };
		//static string getTblFldDictName() { return SYSDICT_TABLEFLD; };


		//static string getMatch(const string& str1, const vector<string>& v_str);
		//static int LevenshteinDistance(string source, string target);

		//static vector<sysDict> getAllTable() { return m_TableDicts; };
		//static vector<sysDict> getAllField() { return m_FieldDicts; };

		//static map<eSAClient, map<std::string, std::string>>& getCreateSql();
		//static map<eSAClient, map<std::string, std::string>> ALL_TABLE_CREATE_SQL;

	private:
		static std::recursive_mutex dict_Mutex;

		//多个数据库进行多个连接
		static std::map<SAConnection*, std::vector<sysdict_MdlTbl>> m_S3dmDictTables;
		static std::map<SAConnection*, std::vector<sysdict_MdlTblFld>> m_S3dmDictFields;
	};


}
