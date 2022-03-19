#ifndef _S3D_DBE_AUX_H
#define _S3D_DBE_AUX_H


#include "s3dDBEngineAux_exp.h"
#include <string>
#include <map>
#include "s3dSqlsBase.h"


namespace Smart3dMap
{

	//�ַ�����
	typedef enum STRING_CODING
	{
		SC_UNKOWN,
		SC_GBK,
		SC_UTF8
	}STRING_CODING;

	class S3D_DBENGINE_AUX_API s3dDBEAux
	{
		friend class s3dSqlBase;

	private:
		s3dDBEAux();
		virtual ~s3dDBEAux();
	public:
		static s3dDBEAux* getSingletonPtr();
		static s3dDBEAux& getSingleton();

		// ���صĶ����ɵ����߸���������
		static s3dSqlBase* newSqlClsObj(GME_LinkType linkType);
		// ���صĶ����ɵ����߸���������
		static s3dSqlBase* newSqlClsObjByClientType(SAConnection* con);

	public:
		//ȡ�����ݿ������ַ���
		std::string getDBConnStr(std::string dbname, std::string servername="", std::string portNo = "");

		//�������ݿ⣬����ȡ���Ӷ�������Ѿ����ӣ���ֱ�ӷ��ض���
		//dbaType���ݿ����ͣ� dbUrlΪ����õ������ַ�����urlΪ��ȡ��ǰ�����ݿ�����
		__int64 openDb(DB_APP_TYPE dbaType, GME_LinkType linkType, std::string dbUrl, std::string user = "", std::string psw = "");
		//dbaType���ݿ����ͣ� dbUrlΪԭ���������ַ���
		__int64 openDb(DB_APP_TYPE dbaType, GME_LinkType linkType, std::string dbname, std::string servername, std::string portNo,const std::string user, const std::string psw);
		//ȡ��ǰ���ݿ�����Ӷ���
		__int64 getCurConn(DB_APP_TYPE dbaType);

		//�ر����ݿ�,���ͷ����Ӷ���
		void closeDb(__int64& conn);

		//��ȡsql���ݿ��������
		s3dSqlBase* getSqlClsObj(GME_LinkType linkType, std::string dbUrl="");
		//�������Ӷ���õ����ݿ�������Ϣ
		s3dSqlBase* getSqlClsObj(__int64 conn);
		//����dbUrl�õ����ݿ�������Ϣ
		DB_CONN_INFO& getDbInfo(std::string& dbUrl);
		//�������Ӷ���õ����ݿ�������Ϣ
		DB_CONN_INFO& getDbInfo(__int64 conn);


		//�����ļ����õ��ļ����ݿ������. ����ֵ��1����access��2����sqlite���ݿ⣬ 0����ʧ��
		int getFileDbType(const std::string file);




	public:
		int preNum(const char byte);
		//�ж��ַ����Ƿ�Ϊgbk����
		bool isGbk(const char* str);
		//�ж��ַ����Ƿ�Ϊutf8����
		bool isUtf8(const char* str);
		//��ȡ��������
		STRING_CODING GetCoding(const char* str);
		STRING_CODING GetCoding(const std::string& str);

		//�ַ�������ϵͳת��
		//Gbk2Utf8
		std::string GbkToUtf8(const char* gbk);
		std::string GbkToUtf8(const std::string& gbk);
		//utf8 --> gbk
		std::string Utf8ToGbk(const char* utf8);

		//�õ�Gbk�ַ�
		std::string getGBKChar(__int64 con, const char* ch);

	private:
		std::map<std::string, s3dSqlBase*> mDbConnMap; //ÿһ�����͵��������ݿ����Ӷ���
		__int64 mCurDbConn[3]; //ÿһ�����͵ĵ�ǰ���ݿ����Ӷ���
		int mDbLinkType[12];
	};

}

#endif