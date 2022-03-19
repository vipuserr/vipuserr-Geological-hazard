#pragma once

#include "s3dAttDBEngine_exp.h"
#include <string>


#include <SQLAPI.h>


using namespace std;
namespace Smart3dMap
{

	class S3D_ATT_DBENGINE_API OracleDbMng
	{
	private:
		OracleDbMng();
		~OracleDbMng();


	public:
		static OracleDbMng* getSingletonPtr();
		static OracleDbMng& getSingleton();

		SAConnection* GetGeoDbCon();
		void conToDatabase();


	private:
		SAConnection m_dbCon;
		std::string m_sServer;
		std::string m_sUser;
		std::string m_sPasswd;
	};
}