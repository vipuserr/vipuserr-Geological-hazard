#pragma once
class DisaDBTool
{
};

#pragma once

#include <string>
#include <vector>
#include <map>

#include "s3d_DisaDbTblFldDef_exp.h"
#include "S3d_DisaDBDef.h"

namespace Smart3dMap
{

	class S3D_DIS_DBENGINE_API DisaDBTool
	{

	public:
		DisaDBTool();
		virtual ~DisaDBTool();

		//ÿ����һ������Ҫ��������setAttribute����

		//���¼����������
		static void setAttribute(long attri_name, long value, LandSliderHazard *result);
		static void setAttribute(long attri_name, double value, LandSliderHazard *result);
		static void setAttribute(long attri_name, std::string value, LandSliderHazard *result);

		//������



	};
}

