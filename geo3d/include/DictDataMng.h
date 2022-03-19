#pragma once

#include "s3dAttDBEngine_exp.h"

#include "SQLAPI.h"
#include "s3d_AttrDBDef.h"
#include "s3d_DbTblFldDef.h"
#include <string>
#include <map>
#include <vector>
#include <gmeStru.h>

#define CHINESE_TYPE_NULL "��"
#define CHINESE_TYPE_INT "������"
#define CHINESE_TYPE_DOUBLE "������"
#define CHINESE_TYPE_STRING "������"
#define CHINESE_TYPE_DATATIME "������"

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
		// ���ʵ������󡣵���ģʽ�������ڶ��̻߳�����
		static DictDataMng* getSingletonPtr();
		static DictDataMng& getSingleton();

		// �����¶��󣬱��ڶ��̻߳���ʹ�á�
		static std::shared_ptr<DictDataMng> NewObject(SAConnection* dbCon);

		//���õ�ǰ�����ݿ�����
		virtual void setCurDbConn(__int64 conn);
		//��ȡ��ǰ�����ݿ�����
		virtual __int64 getCurDbConn();




		//ȡ�û����úõı�(����δ���õ�)
		void getConfigedTablesByCate(std::string dataMdlName, std::vector<sysdict_MdlTbl>& tables);
		void getConfigedTablesByCate(std::string dataMdlName, s3d_TBLIDENTITY tblEntity, std::vector<sysdict_MdlTbl>& tables);
		void getConfigedTablesByType(s3d_TBLIDENTITY tblIdentity, std::vector<sysdict_MdlTbl>& tables);
		void getConfigedTables(std::vector<sysdict_MdlTbl>& tables);
		//ȡ�û����úõ��ֶ�(����δ���õ�)
		void getConfigedFieldsByTable(std::string innerTblName, std::vector<sysdict_MdlTblFld>& fields);
		void getConfigedFieldsByTable(std::string innerTblName, s3d_FLDIDENTITY fldIdentity,std::vector<sysdict_MdlTblFld>& fields);
		void getConfigedFieldsByType(s3d_FLDIDENTITY fldIdentity, std::vector<sysdict_MdlTblFld>& fields);
		void getConfigedFields(std::vector<sysdict_MdlTblFld>& fields);



		//ȡ�ֵ������
		void getSysDictTableCates(std::vector<sysdict_Mdl> & cates);
		//ȡ�����ֵ��
		void getSysDictTables(std::vector<sysdict_MdlTbl>& tables, int categoryId = -1);
		//ȡ�����ֵ��ֶ�
		void getSysDictTableFields(std::vector<sysdict_MdlTblFld>& flds);
		//��ȡ�����û�����
		void getAllUserTables(std::vector<std::string>& tables);
		// ���ݱ�����ȡ�����ֶ���
		void getAllFldsByTableName(const std::string& tableName, std::vector<std::string>& flds);
		//���ݱ�����ȡ�����ֶ���
		//�����ˣ�wzj ����ˣ�zhuyh �ϴ��ˣ�zhuyh
		//�ϴ�ʱ�䣺20210821
		void getAllFldsByTableName(std::string tableName, gmeFields & flds);

		// ���ݱ�����ȡ�����ֶΣ��ֶ��������Ӧ���������͵����֡�
		void getAllFldsByTableName(const std::string& tableName, std::list<std::pair<std::string, std::string>>& flds);
		// ȡָ����ı��ֵ���Ϣ
		bool getSysDictTable(const std::string& innerName, sysdict_MdlTbl& tblInfo);
		//ȡָ���ֶε��ֵ���Ϣ
		bool getSysDictField(const std::string innerTblName, const std::string innerFldName, sysdict_MdlTblFld& fldInfo);
		// ȡָ����ı��ֵ���Ϣ
		bool getSysDictTable(int innerTblID, sysdict_MdlTbl& tblInfo);
		// ȡָ������ֶ�ӳ����Ϣ
		bool getSysDictTableFields(int innerTblID, std::vector<sysdict_MdlTblFld>& fields);


		//�����û��ı������ֶ���
		void setTablesAndFields(const std::vector<sysdict_MdlTbl>& tables, const std::vector<sysdict_MdlTblFld>& flds, bool updateAlias = true);

		//��ȡ�ڲ������ֵ�����
		void getDefaultInenerData(std::vector<sysdict_Mdl>& cates, std::vector<sysdict_MdlTbl>& tbls, std::vector<sysdict_MdlTblFld>& flds);
		
		//�����ڲ������ֵ����ݣ��������û�����û��ֶΣ�
		void insertDefaultInnerData();
		
		//����Ĭ�ϵ��û�����û��ֶΣ�ֻ���ڴ�����׼���ݿ��ʱ����ã�
		void updateDefaultUserData();

		// ɾ�������ֵ�����ű� -- LH.2021.10.08 14:38 added.
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