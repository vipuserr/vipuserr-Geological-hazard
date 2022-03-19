#pragma once
#pragma warning(disable : 4290)

#include "s3dGMdlDBEngineExp.h"
#include <gmeDef.h>
#include <list>

class SAConnection;

namespace Smart3dMap {
	class OG_GME_API s3dGMdlSchema
	{
	public:
		static bool IsSupported(GME_LinkType linkType);

		/// @brief ��ʼ�����ݿ⣬ΪSDE���ݿⴴ�����б��
		/// @param linkType ���ݿ�����������͡�
		/// @param dbCon ��Ч�����ݿ����Ӷ���
		static bool CreateAllTables(GME_LinkType linkType, SAConnection* dbCon) throw (std::runtime_error);

		static std::list<std::string> GetSchema(GME_LinkType linkType);

	protected:
		/// @brief ȡ�������ݿ���SQL��䡣
		virtual std::list<std::string> GetSQLText() const = 0;

	private:
		static std::unique_ptr<s3dGMdlSchema> GetSchemaObject(GME_LinkType linkType);
	};
}

