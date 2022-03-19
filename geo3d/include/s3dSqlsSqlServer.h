#pragma once

#include "s3dSqlsBase.h"


namespace Smart3dMap
{

	class S3D_DBENGINE_AUX_API s3dSqlSqlserver : public s3dSqlBase
	{
	public:
		s3dSqlSqlserver();
		virtual ~s3dSqlSqlserver();

	public:
		//创建数据库
		__int64 openDb(GString url, GString user = "", GString psw = "");
		//创建数据库的表结构
		void createAllDbTbls(void* mConn);
		//获取sql语句
		GString getSql(GME_OBJ_TYPE objType, SQL_OPER_TYPE operType, ...);

		//获取查询所有表名的sql
		GString getUserTableNameSql();

		//创建字典表(表不存在的时候才会创建)
		void createDictTables(void* mCon);
		//判断表是否存在
		bool tableIsExist(SAConnection* Con, std::string TblName);
	public:
	};
}