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
		//���㵹ת���Եز�������±��룬������Ȳ�
		void CalcRoll(std::vector<s3d_BoreHole>& boreHoles, bool isExtend = false);

		//�������ף�ʹ��߶Ⱥ���������һ��(�÷�����֤�����������в�һ�£����������Ȳ�)
		void ExtendShortHoles(std::vector<s3d_BoreHole>& boreHoles);


		//���������ת��Ϊ20λ��ÿ4λ����һ������ǰ�油0
		std::string stratLevel2Code(std::string stratOrder, string stratCodeIndex);


		//��ȡ������ĵز�
		s3d_BoreHoleLayer getYoungLayer(std::vector<std::pair<LayerIndex, s3d_BoreHole*>>& boreHoles);
		//��ȡ�����ĵز㣬�������һ����Ļ�������������ĵز�
		s3d_BoreHoleLayer getMostLayer(std::vector<std::pair<LayerIndex, s3d_BoreHole*>>& boreHoles);


		//���µز����ӱ���
		void updateStratCode(std::vector<std::pair<LayerIndex, s3d_BoreHole*>>& boreHoles, std::string newLevelCode);
		//���ݲ�ֵ�õ��ĸ̣߳�Ѱ�ҵز㣬����ҵ����޸���׵ĵ�ǰ��,����true
		bool findStratCodeIndex(std::pair<LayerIndex, s3d_BoreHole*>& boreHoles, double z, s3d_BoreHoleLayer& findLayer);
		//��ȡ��һ���������
		std::string getNextLevelCode(std::string levelCode);

		//��ȡ��׼�ĵز���򣨰������Ȳ㣩
		void getStdStratOrder(std::vector<s3d_BoreHole>& boreHoles, std::vector<std::pair<std::string, s3d_BoreHoleLayer>>& orders);
		//������׷ֲ���������֤���п׵ķֲ�һ��(������Ȳ�)
		void addZeroDepthStrat(std::vector<s3d_BoreHole>& boreHoles, std::vector<std::pair<std::string, s3d_BoreHoleLayer>>& orders);
		//�Ƴ����Ȳ�
		void removeZeroDepthStrat(std::vector<s3d_BoreHole>& boreHoles);
		//�����еı�׼�ĵز������ɴ�1��ʼ
		void postProcessStratCode(std::vector<s3d_BoreHole>& boreHolse);

		//���µ�ǰ�������
		void updateCurrentLevelCode(std::pair<LayerIndex, s3d_BoreHole*> boreHoles, std::string newLevelCode);

	};
}


