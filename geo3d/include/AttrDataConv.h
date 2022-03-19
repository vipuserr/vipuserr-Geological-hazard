#pragma once
#include <string>
#include <vector>

#include "s3dAttDBEngine_exp.h"
#include "s3d_AttrDBDef.h"

using namespace std;
namespace Smart3dMap
{

	class S3D_ATT_DBENGINE_API AttrDataConv
	{
	public:
		//取出标准地层的级别数
		static long GetStdStratLevelNum(vector<s3d_BaseLayer>& stdLayer);
		static long GetStdStratLevelNum(vector<hole_stdStratDesc>& stdLayer);
		// 根据地层级别编码得到地层级别号
		static long getStratLevelNoByLevelCode(const string& strLevelCode);
		//取出地层级别对应的分层
		static void GetStdStratDescByLevelNum(vector<s3d_BaseLayer>& inStdLayers, int inLevelNum, vector<s3d_BaseLayer>& outStdLayers);
		static void GetStdStratDescByLevelNum(vector<hole_stdStratDesc>& inStdLayers, int inLevelNum, vector<hole_stdStratDesc>& outStdLayers);
	};
}