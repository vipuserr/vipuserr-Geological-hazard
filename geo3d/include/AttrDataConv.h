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
		//ȡ����׼�ز�ļ�����
		static long GetStdStratLevelNum(vector<s3d_BaseLayer>& stdLayer);
		static long GetStdStratLevelNum(vector<hole_stdStratDesc>& stdLayer);
		// ���ݵز㼶�����õ��ز㼶���
		static long getStratLevelNoByLevelCode(const string& strLevelCode);
		//ȡ���ز㼶���Ӧ�ķֲ�
		static void GetStdStratDescByLevelNum(vector<s3d_BaseLayer>& inStdLayers, int inLevelNum, vector<s3d_BaseLayer>& outStdLayers);
		static void GetStdStratDescByLevelNum(vector<hole_stdStratDesc>& inStdLayers, int inLevelNum, vector<hole_stdStratDesc>& outStdLayers);
	};
}