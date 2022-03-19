#ifndef _S3D_DBE_AUX_H
#define _S3D_DBE_AUX_H


#include "s3dDBEngineAux_exp.h"
#include <string>
#include <map>
#include "s3dSqlsBase.h"


namespace Smart3dMap
{

	//字符编码
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

		// 返回的对象由调用者负责析构。
		static s3dSqlBase* newSqlClsObj(GME_LinkType linkType);
		// 返回的对象由调用者负责析构。
		static s3dSqlBase* newSqlClsObjByClientType(SAConnection* con);

	public:
		//取出数据库连接字符串
		std::string getDBConnStr(std::string dbname, std::string servername="", std::string portNo = "");

		//连接数据库，并获取连接对象。如果已经连接，则直接返回对象
		//dbaType数据库类型， dbUrl为整理好的连接字符串，url为空取当前的数据库连接
		__int64 openDb(DB_APP_TYPE dbaType, GME_LinkType linkType, std::string dbUrl, std::string user = "", std::string psw = "");
		//dbaType数据库类型， dbUrl为原生的连接字符串
		__int64 openDb(DB_APP_TYPE dbaType, GME_LinkType linkType, std::string dbname, std::string servername, std::string portNo,const std::string user, const std::string psw);
		//取当前数据库的连接对象
		__int64 getCurConn(DB_APP_TYPE dbaType);

		//关闭数据库,并释放连接对象
		void closeDb(__int64& conn);

		//获取sql数据库操作对象
		s3dSqlBase* getSqlClsObj(GME_LinkType linkType, std::string dbUrl="");
		//根据连接对象得到数据库连接信息
		s3dSqlBase* getSqlClsObj(__int64 conn);
		//根据dbUrl得到数据库连接信息
		DB_CONN_INFO& getDbInfo(std::string& dbUrl);
		//根据连接对象得到数据库连接信息
		DB_CONN_INFO& getDbInfo(__int64 conn);


		//根据文件，得到文件数据库的类型. 返回值：1——access，2——sqlite数据库， 0——失败
		int getFileDbType(const std::string file);




	public:
		int preNum(const char byte);
		//判断字符串是否为gbk编码
		bool isGbk(const char* str);
		//判断字符串是否为utf8编码
		bool isUtf8(const char* str);
		//获取编码类型
		STRING_CODING GetCoding(const char* str);
		STRING_CODING GetCoding(const std::string& str);

		//字符串编码系统转换
		//Gbk2Utf8
		std::string GbkToUtf8(const char* gbk);
		std::string GbkToUtf8(const std::string& gbk);
		//utf8 --> gbk
		std::string Utf8ToGbk(const char* utf8);

		//得到Gbk字符
		std::string getGBKChar(__int64 con, const char* ch);

	private:
		std::map<std::string, s3dSqlBase*> mDbConnMap; //每一种类型的所有数据库连接对象
		__int64 mCurDbConn[3]; //每一种类型的当前数据库连接对象
		int mDbLinkType[12];
	};

}

#endif