#pragma once

#include "s3dSqlsBase.h"


namespace Smart3dMap
{ 

	//����洢����
	class S3D_DBENGINE_AUX_API s3dSqlSqlite : public s3dSqlBase
	{
	public:
		s3dSqlSqlite();
		virtual ~s3dSqlSqlite();

	public:
		//�������ݿ⣬�������ݿ����Ӷ���...
		__int64 openDb(GString url="", GString user="", GString psw="");
		//�������ݿ�ı�ṹ
		void createAllDbTbls(std::vector<std::string>& sqls);
		//��ȡsql���
		GString getSql(GME_OBJ_TYPE objType, SQL_OPER_TYPE operType, ...);

		//��ȡ��ѯ���б�����sql
		GString getUserTableNameSql();

		//�����ֵ��(�����ڵ�ʱ��Żᴴ��)
		void createDictTables(void* mCon);
		//�жϱ��Ƿ����
		bool tableIsExist(SAConnection* Con, std::string TblName);
	private:

	};
}