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
		//创建数据库
		__int64 openDb(GString url, GString user = "", GString psw = "");
		//创建数据库的表结构
		void createAllDbTbls(void* mConn);
		//获取sql语句
		GString getSql(GME_OBJ_TYPE objType, SQL_OPER_TYPE operType,...);

		//获取查询所有表名的sql
		GString getUserTableNameSql();

		//获取字段的名称和类型 
		//开发人：wzj 检查人：zhuyh 上传人：zhuyh
		//上传时间：20210821
		GString getUserFldsInfoSql(std::string tblName);

		//创建字典表(表不存在的时候才会创建)
		void createDictTables(void* mCon);


		//判断表是否存在
		bool tableIsExist(SAConnection* Con,std::string TblName);

	private:
		// overwrite.
		/*std::string getComparisonOp(COMPARISON_OPERATOR op);
		std::string getLogicalOp(LOGICAL_OPERATOR op);*/

		// 重写继承至父类的虚函数，以解决access的字段引号问题。 -- LH.2021.08.05 09:06 added.
		virtual void generateSelectSql();
		virtual void generateInsertSql();
	};
}