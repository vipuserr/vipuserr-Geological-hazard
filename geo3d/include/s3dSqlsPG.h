#pragma once

#include "s3dsqlsBase.h"

namespace Smart3dMap
{
	class S3D_DBENGINE_AUX_API s3dSqlPG : public s3dSqlBase
	{
	public:
		s3dSqlPG();
		virtual ~s3dSqlPG();

	public:
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
	protected:
		// overwrite.
		/*std::string getComparisonOp(COMPARISON_OPERATOR op);
		std::string getLogicalOp(LOGICAL_OPERATOR op);*/
		virtual void generateSelectSql() override;

		virtual void generateInsertSql() override;

		virtual void generateUpdateSql() override;

	};
}