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
		//�������ݿ�
		__int64 openDb(GString url, GString user = "", GString psw = "");
		//�������ݿ�ı�ṹ
		void createAllDbTbls(void* mConn);
		//��ȡsql���
		GString getSql(GME_OBJ_TYPE objType, SQL_OPER_TYPE operType, ...);

		//��ȡ��ѯ���б�����sql
		GString getUserTableNameSql();

		//�����ֵ��(�����ڵ�ʱ��Żᴴ��)
		void createDictTables(void* mCon);
		//�жϱ��Ƿ����
		bool tableIsExist(SAConnection* Con, std::string TblName);
	public:
	};
}