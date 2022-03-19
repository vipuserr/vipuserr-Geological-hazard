#pragma once

#include "s3d_AttrDBDef.h"

#include "s3d_baseapplib_global.h"
#include "gmeStru.h"
#include <map>

namespace Smart3dMap
{
	class S3D_BASEAPPLIB_EXPORT S3d_GmeModelField
	{
	public:
		//ת�������
		void getHoleModelAttrs(const Smart3dMap::HoleInfo& holeInfo, gmeRecord& record);
		
		//ת��׷ֲ�����
		void getStratCodeAttrs(const std::string& holeCode, const double& holeTopZ, Smart3dMap::s3d_BoreHoleLayer& holeLayer, gmeRecord& record);
		void getAllStratType(std::map<int, std::string>& stratTypes);
	
		//ת�ز�ֲ�����
		void getStratLayerAttrs(const Smart3dMap::hole_stdStratDesc& baseLayer, gmeRecord& record);

	};
}
