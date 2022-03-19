#pragma once

#include <vector>
#include <string>
#include <map>

#include "s3dSqlsBase.h"


namespace Smart3dMap
{
	
	class S3D_DBENGINE_AUX_API s3dSqlMysql : public s3dSqlBase
	{
	public:
		s3dSqlMysql();
		virtual ~s3dSqlMysql();

	public:
		//�������ݿ�
		__int64 openDb(GString url, GString user = "", GString psw = "");
		//�������ݿ�ı�ṹ
		void createAllDbTbls(void* mConn);
		//��ȡsql���
		GString getSql(GME_OBJ_TYPE objType, SQL_OPER_TYPE operType, ...);


	public:
		//��ȡ��ѯ���б�����sql
		GString getUserTableNameSql();

		//�����ֵ��(�����ڵ�ʱ��Żᴴ��)
		void createDictTables(void* mCon);
		//�жϱ��Ƿ����
		bool tableIsExist(SAConnection* Con, std::string TblName);
	
	private:

		// overwrite.
		std::string getComparisonOp(COMPARISON_OPERATOR op);
		std::string getLogicalOp(LOGICAL_OPERATOR op);
	};
}