#pragma once

#include "s3d_dbmanagerlib_global.h"
#include "s3dSqlsBase.h"

class S3D_DBMANAGERLIB_EXPORT s3d_DBManagerLib
{
public:
	static s3d_DBManagerLib* getSingletonPtr();

	//���������ݿ�
	void excuteGenerateDefaultDb();

	//�������ݿ�Id��ȡ���ݿ���Ϣ
	static void getDBInfoById(const int& dbId, Smart3dMap::DB_CONN_INFO& dbConInfo);

private:
    s3d_DBManagerLib();
	~s3d_DBManagerLib();

	__int64 m_ParentWidget;
};
