#pragma once

#include "s3d_dbmanagerlib_global.h"
#include "s3dSqlsBase.h"

class S3D_DBMANAGERLIB_EXPORT s3d_DBManagerLib
{
public:
	static s3d_DBManagerLib* getSingletonPtr();

	//创建空数据库
	void excuteGenerateDefaultDb();

	//根据数据库Id获取数据库信息
	static void getDBInfoById(const int& dbId, Smart3dMap::DB_CONN_INFO& dbConInfo);

private:
    s3d_DBManagerLib();
	~s3d_DBManagerLib();

	__int64 m_ParentWidget;
};
