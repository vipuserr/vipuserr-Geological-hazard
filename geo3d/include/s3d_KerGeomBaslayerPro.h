#pragma once
 
#include <map>
#include <vector>
using namespace std;

#include <s3d_KerGeomBaslayerProExp.h>
#include <s3d_KerGeomodelDef.h>


namespace Smart3dMap
{

	int _S3D_KERGEOM_BASLAYERPRO_EXP compare_holelayer(const void *p1, const void *p2);
	int _S3D_KERGEOM_BASLAYERPRO_EXP compare_stdlayer(const void *p1, const void *p2);

	// 标准层序处理类
	class _S3D_KERGEOM_BASLAYERPRO_EXP s3d_BaseLayerAnalys
	{
	public:
		s3d_BaseLayerAnalys() {}
		~s3d_BaseLayerAnalys() {}

	public:
		static void  CalcRoll(vector<s3d_BoreHole> &boreholedatas);
		static void  CalcGeoLayerRoll(vector<s3d_BoreHole> &boreholedatas, vector<s3d_BaseLayer> &stdlayer);
		static s3d_BaseLayer FindLayer(string code, vector<s3d_BaseLayer> &stdlayer);

		static void  InsertLostLayer(vector<s3d_BoreHole> &boreholedatas, vector<string> &codelist);
		static void  CombineHoleLayer(vector<s3d_BoreHole> &boreholedatas, vector<string> &codelist);

		//根据地层级别编码取地层编码...
		static string getStratCodeByLevelCode(string levelCode, vector<s3d_BaseLayer>& standlayer);
		static s3d_BaseLayer* getStandStratByLevelCode(string levelCode, vector<s3d_BaseLayer>& standlayer);
		//根据地层编码取地层级别编码...
		static string getLevelCodeByStratCode(string stratCode, vector<s3d_BaseLayer>& standlayer);
		static s3d_BaseLayer* getStandStratByStratCode(string stratCode, vector<s3d_BaseLayer>& standlayer);

	public:
		//得到地层级别编码的字符串值，前面补00.
		static void  StratCodeToLevel(string strcode, string &level);
		//返回地层级别编码的整数值，前面不补00.
		static int  StratCodeTointLevel(string &strcode, string &level);
		//地层编码到级别编码
		static void  HoleStratCodeToLevel(vector<s3d_BoreHole> &boreholedatas, vector<s3d_BaseLayer> &stdlayer);
		//地层编码到级别编码，直接赋值，不做转化
		static void  HoleStratCodeToLevel2(vector<s3d_BoreHole> &boreholedatas, vector<s3d_BaseLayer> &stdlayer);

		//地层编码转数字列表，含有0则返回0.不含0则返回1
		static int   StratCodeToDigit(string strcode, vector<int> &DigitVec);

		//检测基本层序://含有0则返回0.不含0则返回1
		static int   CheckBasLayer(vector<s3d_BaseLayer> *pStdlayer, int &idx);

		//地层体复制...
		static int   Copys3d_EntyTemp(s3d_TopBtmEnty &ori, s3d_TopBtmEnty &des);
	};

}
