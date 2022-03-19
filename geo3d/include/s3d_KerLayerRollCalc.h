#pragma once

#include <s3d_KerGeomBaslayerProExp.h>
#include <s3d_KerGeomodelDef.h>

namespace Smart3dMap
{
	class _S3D_KERGEOM_BASLAYERPRO_EXP s3d_KerLayerRollCalc
	{
	public:
		s3d_KerLayerRollCalc();
		~s3d_KerLayerRollCalc();


		struct LayerIndex
		{
			int startIndex;
			int endIndex;
			int currentIndex;
		};
		//计算倒转，对地层进行重新编码，添加零厚度层
		void CalcRoll(std::vector<s3d_BoreHole>& boreHoles, bool isExtend = false);

		//补齐短钻孔，使其高度和最深的钻孔一致(该方法保证传入的钻孔所有层一致，即含有零厚度层)
		void ExtendShortHoles(std::vector<s3d_BoreHole>& boreHoles);


		//将级别编码转化为20位，每4位代表一个级别，前面补0
		std::string stratLevel2Code(std::string stratOrder, string stratCodeIndex);


		//获取到年轻的地层
		s3d_BoreHoleLayer getYoungLayer(std::vector<std::pair<LayerIndex, s3d_BoreHole*>>& boreHoles);
		//获取到最多的地层，如果都是一样多的话，返回最年轻的地层
		s3d_BoreHoleLayer getMostLayer(std::vector<std::pair<LayerIndex, s3d_BoreHole*>>& boreHoles);


		//更新地层连接编码
		void updateStratCode(std::vector<std::pair<LayerIndex, s3d_BoreHole*>>& boreHoles, std::string newLevelCode);
		//根据插值得到的高程，寻找地层，如果找到，修改钻孔的当前层,返回true
		bool findStratCodeIndex(std::pair<LayerIndex, s3d_BoreHole*>& boreHoles, double z, s3d_BoreHoleLayer& findLayer);
		//获取下一个级别编码
		std::string getNextLevelCode(std::string levelCode);

		//获取标准的地层层序（包括零厚度层）
		void getStdStratOrder(std::vector<s3d_BoreHole>& boreHoles, std::vector<std::pair<std::string, s3d_BoreHoleLayer>>& orders);
		//补充钻孔分层完整，保证所有孔的分层一致(添加零厚度层)
		void addZeroDepthStrat(std::vector<s3d_BoreHole>& boreHoles, std::vector<std::pair<std::string, s3d_BoreHoleLayer>>& orders);
		//移除零厚度层
		void removeZeroDepthStrat(std::vector<s3d_BoreHole>& boreHoles);
		//将所有的标准的地层层序处理成从1开始
		void postProcessStratCode(std::vector<s3d_BoreHole>& boreHolse);

		//更新当前级别编码
		void updateCurrentLevelCode(std::pair<LayerIndex, s3d_BoreHole*> boreHoles, std::string newLevelCode);

	};
}


