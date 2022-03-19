#pragma once

#include "s3dSqlsBase.h"

namespace Smart3dMap
{ 
	class S3D_DBENGINE_AUX_API s3dSqlAccess : public s3dSqlBase
	{
	public:
		s3dSqlAccess();
		virtual ~s3dSqlAccess();

	public:
		//�������ݿ�
		__int64 openDb(GString url, GString user = "", GString psw = "");
		//�������ݿ�ı�ṹ
		void createAllDbTbls(void* mConn);
		//��ȡsql���
		GString getSql(GME_OBJ_TYPE objType, SQL_OPER_TYPE operType,...);

		//��ȡ��ѯ���б�����sql
		GString getUserTableNameSql();

		//��ȡ�ֶε����ƺ����� 
		//�����ˣ�wzj ����ˣ�zhuyh �ϴ��ˣ�zhuyh
		//�ϴ�ʱ�䣺20210821
		GString getUserFldsInfoSql(std::string tblName);

		//�����ֵ��(�����ڵ�ʱ��Żᴴ��)
		void createDictTables(void* mCon);


		//�жϱ��Ƿ����
		bool tableIsExist(SAConnection* Con,std::string TblName);

	private:
		// overwrite.
		/*std::string getComparisonOp(COMPARISON_OPERATOR op);
		std::string getLogicalOp(LOGICAL_OPERATOR op);*/

		// ��д�̳���������麯�����Խ��access���ֶ��������⡣ -- LH.2021.08.05 09:06 added.
		virtual void generateSelectSql();
		virtual void generateInsertSql();
	};
}