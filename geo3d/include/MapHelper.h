#pragma once
#include "s3d_geommaplib_global.h"

namespace Smart3dMap {
	// 图件工具
	class S3D_GEOMMAPLIB_EXPORT MapHelper
	{
	public:
		/// 将数据库中的图件发布为在线图件。
		/// @param dbId		地图所在数据库的ID。
		/// @param mapId	拟被发布的地图的ID。
		static bool PublishMapOnWeb(int dbId, int mapId);
	};
}

