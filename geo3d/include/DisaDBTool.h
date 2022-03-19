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

		//每增加一个表需要增加三个setAttribute方法

		//滑坡及隐患调查表
		static void setAttribute(long attri_name, long value, LandSliderHazard *result);
		static void setAttribute(long attri_name, double value, LandSliderHazard *result);
		static void setAttribute(long attri_name, std::string value, LandSliderHazard *result);

		//其他表



	};
}

