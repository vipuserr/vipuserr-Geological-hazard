#pragma once

#include "s3dAttDBEngine_exp.h"
#include <gmeDef.h>

//创建标准数据库类
namespace Smart3dMap {

	class S3D_ATT_DBENGINE_API s3d_GenerateDB
	{
	public:
		static bool GenerateDB(GME_LinkType linkType, __int64 con);
		static bool GenerateMySQLDB(__int64 con);
		static bool GenerateOracleDB(__int64 con);
		static bool GeneratePgDB(__int64 con);
		static bool GenerateAccessDB(__int64 con);
		static bool GenerateSqliteDB(__int64 con);

		static bool generateSysDict(__int64 con, bool initDefaultUserData = false);
	};
}

