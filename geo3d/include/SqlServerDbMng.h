#pragma once

#include "s3dAttDBEngine_exp.h"
#include <string>
#include <SQLAPI.h>


using namespace std;
namespace Smart3dMap
{

	class S3D_ATT_DBENGINE_API SqlServerDbMng
	{
	private:
		SqlServerDbMng();
		~SqlServerDbMng();

	public:
		static SqlServerDbMng* getSingletonPtr();
		static SqlServerDbMng& getSingleton();

		void conToDatabase();
		SAConnection* GetGeoDbCon();

		void setServer(const string& ser);
		void setUser(const string& user);
		void setPasswd(const string& pswd);

	private:
		SAConnection m_dbCon;
		std::string m_sServer;
		std::string m_sUser;
		std::string m_sPasswd;
	};

}