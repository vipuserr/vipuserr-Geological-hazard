#pragma once
#include "gmeMdl.h"
#include "GeoGme23DTiles.h"
namespace Smart3dMap
{
	class GEOGME23DTILES_EXPORT Gme23DTilesConvert
	{
	public:
		//outputPath:ģ��ת�����·��Ϊģ�͸��ļ���Ŀ¼
		//boreholeNumOfABin:һ���������ļ��������ٸ�Ҫ��(���)��Ϊ0���ʾ������׷���һ���ļ���

		//isTransFlag:�Ƿ���Ҫת��Ϊ��γ�����꣬Ϊfalse��ģ���������꽫������ת����Ϊtrue��ᰴ����ת������
		//isAddZoneNo:�����Ƿ�Ӵ��ţ�trueΪ�Ӵ��ţ�falseΪ���Ӵ���
		//zone_type: �ִ����ͣ�������ֵ��Ϊ1��ʾ3�ȷִ���Ϊ2��ʾ6�ȷִ���Ĭ��Ϊ3�ȷִ�
		//proj_zone: ͶӰ���Ĵ��ţ���֪��Ҳ���Բ��Ĭ��ֵ-1��ʾ��֪�������Ž����ݾ���ֵ���м���
		//longitude: ģ�����ڵĴ��¾��ȣ���proj_zone��Ϊ-1������proj_zone����Ϊ׼�����Բ���
		//ע�⣺��������й�������Ч��3�ȴ��ŷ�ΧΪ(24~46),6�ȷִ����ŷ�ΧΪ(13~23)�����ȷ�ΧΪ73��~135��
		static void convert(gmeModel & geomdl, std::string outputPath,
			int boreholeNumOfABin = 0, int boreholeLodNum = 0,
			bool isTransFlag = true, int srcCoordSys = 0, bool isAddZoneNo = false,
			int zone_type = 1, int proj_zone = -1, double longitude = 114);
		static void combineTilesetFiles(std::vector<std::string> jsonpaths, std::string outputPath);//���Ժϲ��ֿ��ģ��json�ļ�����ͳһ��ʽ
	};
}


