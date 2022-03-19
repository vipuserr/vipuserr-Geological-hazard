#pragma once

#include "s3dAttDBEngine_exp.h"

#include "SQLAPI.h"
#include "s3d_AttrDBDef.h"
#include "s3d_DbTblFldDef.h"
#include <string>
#include <map>
#include <vector>
#include <gmeStru.h>

#define CHINESE_TYPE_NULL "空"
#define CHINESE_TYPE_INT "整数型"
#define CHINESE_TYPE_DOUBLE "浮点型"
#define CHINESE_TYPE_STRING "文字型"
#define CHINESE_TYPE_DATATIME "日期型"

namespace Smart3dMap
{
	class S3D_ATT_DBENGINE_API DictDataMng
	{
	private:
		DictDataMng();
		DictDataMng(SAConnection* dbCon);

	public:
		~DictDataMng();

	public:
		// 访问单例对象。单例模式不适用于多线程环境。
		static DictDataMng* getSingletonPtr();
		static DictDataMng& getSingleton();

		// 构造新对象，便于多线程环境使用。
		static std::shared_ptr<DictDataMng> NewObject(SAConnection* dbCon);

		//设置当前的数据库连接
		virtual void setCurDbConn(__int64 conn);
		//获取当前的数据库连接
		virtual __int64 getCurDbConn();




		//取用户配置好的表(过滤未配置的)
		void getConfigedTablesByCate(std::string dataMdlName, std::vector<sysdict_MdlTbl>& tables);
		void getConfigedTablesByCate(std::string dataMdlName, s3d_TBLIDENTITY tblEntity, std::vector<sysdict_MdlTbl>& tables);
		void getConfigedTablesByType(s3d_TBLIDENTITY tblIdentity, std::vector<sysdict_MdlTbl>& tables);
		void getConfigedTables(std::vector<sysdict_MdlTbl>& tables);
		//取用户配置好的字段(过滤未配置的)
		void getConfigedFieldsByTable(std::string innerTblName, std::vector<sysdict_MdlTblFld>& fields);
		void getConfigedFieldsByTable(std::string innerTblName, s3d_FLDIDENTITY fldIdentity,std::vector<sysdict_MdlTblFld>& fields);
		void getConfigedFieldsByType(s3d_FLDIDENTITY fldIdentity, std::vector<sysdict_MdlTblFld>& fields);
		void getConfigedFields(std::vector<sysdict_MdlTblFld>& fields);



		//取字典表的类别
		void getSysDictTableCates(std::vector<sysdict_Mdl> & cates);
		//取所有字典表
		void getSysDictTables(std::vector<sysdict_MdlTbl>& tables, int categoryId = -1);
		//取所有字典字段
		void getSysDictTableFields(std::vector<sysdict_MdlTblFld>& flds);
		//获取所有用户表名
		void getAllUserTables(std::vector<std::string>& tables);
		// 根据表名获取所有字段名
		void getAllFldsByTableName(const std::string& tableName, std::vector<std::string>& flds);
		//根据表名获取所有字段名
		//开发人：wzj 检查人：zhuyh 上传人：zhuyh
		//上传时间：20210821
		void getAllFldsByTableName(std::string tableName, gmeFields & flds);

		// 根据表名获取所有字段：字段名及其对应的数据类型的名字。
		void getAllFldsByTableName(const std::string& tableName, std::list<std::pair<std::string, std::string>>& flds);
		// 取指定表的表字典信息
		bool getSysDictTable(const std::string& innerName, sysdict_MdlTbl& tblInfo);
		//取指定字段的字典信息
		bool getSysDictField(const std::string innerTblName, const std::string innerFldName, sysdict_MdlTblFld& fldInfo);
		// 取指定表的表字典信息
		bool getSysDictTable(int innerTblID, sysdict_MdlTbl& tblInfo);
		// 取指定表的字段映射信息
		bool getSysDictTableFields(int innerTblID, std::vector<sysdict_MdlTblFld>& fields);


		//设置用户的表名和字段名
		void setTablesAndFields(const std::vector<sysdict_MdlTbl>& tables, const std::vector<sysdict_MdlTblFld>& flds, bool updateAlias = true);

		//获取内部数据字典数据
		void getDefaultInenerData(std::vector<sysdict_Mdl>& cates, std::vector<sysdict_MdlTbl>& tbls, std::vector<sysdict_MdlTblFld>& flds);
		
		//插入内部数据字典数据（不插入用户表和用户字段）
		void insertDefaultInnerData();
		
		//插入默认的用户表和用户字段（只有在创建标准数据库的时候调用）
		void updateDefaultUserData();

		// 删除数据字典的三张表 -- LH.2021.10.08 14:38 added.
		bool deleteDataDictTables();

		static std::string DataTypeToText(const DataType& type, bool utf8Encoding = false);
		static DataType TextToDataType(const std::string& chineseType);
	private:
		void SysDictTableFromRow(sysdict_MdlTbl& table, SACommand& cmd);
		void SysDictTableFieldFromRow(sysdict_MdlTblFld& field, SACommand& cmd);

	private:
		SAConnection* mCon;
	};

}