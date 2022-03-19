#pragma once

#include "s3dAttDBEngine_exp.h"
#include <QObject>
#include <OgSingleton.h>
#include <SQLAPI.h>
#include <string>

using namespace std;

enum CODING
{
	UNKOWN,
	GBK,
	UTF8
};

class S3D_ATT_DBENGINE_API DbTool : public QObject, public Smart3dMap::Singleton<DbTool>
{
	Q_OBJECT

public:
	virtual ~DbTool();

	static DbTool* getSingletonPtr();
	static DbTool& getSingleton();

	static string GbkToUtf8(const char* gbk);
	static string GbkToUtf8(const string& gbk);
	static string GbkToUtf8(const QString& gbk);
	static string GbkToUtf8(const SAString& gbk);
	static string Utf8ToGbk(const char* utf8);
	static string Utf8ToGbk(const SAString& utf8);
	static CODING GetCoding(const char* str);
	static CODING GetCoding(const string& str);
	static CODING GetCoding(const SAString& str);
	static eSAClient getDbType(string file);
	static SAConnection* ConnectSqlite(const string& strFullDbUrl);
	static SAConnection* ConnectAccess(const string& strFullDbUrl);

	static QMap<eSAClient, QMap<string, string>>& getCreateSql();
	static QMap<eSAClient, QMap<string, string>> ALL_TABLE_CREATE_SQL;

	__int64 getGeoDB(string strFullDbUrl = "");
	__int64 getGeoDB(const eSAClient &saClient,const string &sUserID, const string &sPassword,const string &sDBString);
private:
	DbTool();

	__int64	m_pCurGeoDbMng; //当前属性数据库管理器
	map<string, __int64> m_pGeoDbMng; //属性数据库管理器...

	static int preNum(const char byte);
	static bool isGbk(const char* data);
	static bool isUtf8(const char* data);
};
