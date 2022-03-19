#pragma once
#include "s3d_dataprocesslib_global.h"

#include <vector>
#include <s3d_AttrDBDef.h>

namespace Smart3dMap
{
	class S3D_DATAPROCESSLIB_EXPORT HullToShp
	{
	public:
		static bool createHullAndWriteToShp(const std::vector<HoleInfo> &hole_list, const std::string &path_to_dir, const double dradius = 10);
	private:

	};

}
