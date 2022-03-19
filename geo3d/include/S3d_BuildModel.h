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
		//��׽�ģ
		//���ص�gmeModel*��Ҫ�������ͷ�
		//isLayered��ʶ�Ƿ񹹽���׷ֲ㣬��������������ÿһ���ز�Ϊһ��geometry������ÿһ�������Ϊһ��geometry
		//dispType;	//��ʾ����(0-��״ 1-��״) segNum������
		Smart3dMap::gmeModel* buildHoleModel(const std::vector<s3d_BoreHole>& holes,int segNum, double radius, int dispType, bool isLayered = false);

		Smart3dMap::gmeModel* buildHoleModel(const std::vector<s3d_BoreHole>& holes, int segNum, std::vector<double> radius, int dispType, bool isLayered = false);

		/*
			\brief ������ά���潨�������ģ��

			\param dummy_hole_model �����֮ǰ��ֵ�������ǡ�

		*/
		bool buildDummyHoleModelBy3dSection(gmeModel* &dummy_hole_model, const gmeModel *section_model, const std::vector< gme_vector3d > &points, const int seg_num = 8, const double radius = 2);
	};

}


