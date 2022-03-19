#pragma once
#include "s3d_baseapplib_global.h"
#include <vector>
#include "s3d_AttrDBDef.h"
#include "gmeMdl.h"
namespace Smart3dMap
{
	class S3D_BASEAPPLIB_EXPORT S3d_BuildModel
	{
	public:
		//钻孔建模
		//返回的gmeModel*需要调用者释放
		//isLayered标识是否构建钻孔分层，如果构建，则钻孔每一个地层为一个geometry，否则每一个组钻孔为一个geometry
		//dispType;	//显示类型(0-线状 1-柱状) segNum：段数
		Smart3dMap::gmeModel* buildHoleModel(const std::vector<s3d_BoreHole>& holes,int segNum, double radius, int dispType, bool isLayered = false);

		Smart3dMap::gmeModel* buildHoleModel(const std::vector<s3d_BoreHole>& holes, int segNum, std::vector<double> radius, int dispType, bool isLayered = false);

		/*
			\brief 根据三维剖面建立虚拟孔模型

			\param dummy_hole_model 结果，之前的值将被覆盖。

		*/
		bool buildDummyHoleModelBy3dSection(gmeModel* &dummy_hole_model, const gmeModel *section_model, const std::vector< gme_vector3d > &points, const int seg_num = 8, const double radius = 2);
	};

}


