#pragma once
#pragma warning(disable : 4290)

#include "s3dSpatialDBEngine_exp.h"
#include "gmeDef.h"
#include <list>

class SAConnection;

namespace Smart3dMap {

	class S3D_SPATIAL_DBENGINE_API s3dSpatialDBSchema {
	public:
		static bool IsSupported(GME_LinkType linkType);

		/// @brief ��ʼ�����ݿ⣬ΪSDE���ݿⴴ�����б��
		/// @param linkType ���ݿ�����������͡�
		/// @param dbCon ��Ч�����ݿ����Ӷ���
		static bool CreateAllTables(GME_LinkType linkType, SAConnection* dbCon) throw (std::runtime_error);

	protected:
		/// @brief ȡ�������ݿ���SQL��䡣
		virtual std::list<std::string> GetSQLText() const = 0;

	private:
		static std::unique_ptr<s3dSpatialDBSchema> GetSchemaObject(GME_LinkType linkType);
	};
}
