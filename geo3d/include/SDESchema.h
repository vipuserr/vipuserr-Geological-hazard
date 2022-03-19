#pragma once

#include "s3dSpatialDBEngine_exp.h"
#include "gmeDef.h"
#include <list>

class SAConnection;

namespace Smart3dMap {

	class S3D_SPATIAL_DBENGINE_API SDESchema {
	public:
		static bool IsSupported(GME_LinkType linkType);

		/// @brief 初始化数据库，为SDE数据库创建所有表格。
		/// @param linkType 数据库服务器的类型。
		/// @param dbCon 有效的数据库连接对象。
		static bool CreateAllTables(GME_LinkType linkType, SAConnection* dbCon) throw (std::runtime_error);

	public:
		/// @brief 取创建数据库表的SQL语句。
		virtual std::list<std::string> GetSQLText() const = 0;

	private:
		static std::unique_ptr<SDESchema> GetSchemaObject(GME_LinkType linkType);
	};
}
