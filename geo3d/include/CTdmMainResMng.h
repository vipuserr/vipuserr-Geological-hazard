#pragma once

#include "tdmfaceresmng_global.h"
#include "CTdmXmlDef.h"
#include "OGtinyxml.h"
#include "OGBasDef.h"
#include <vector>

namespace Smart3dMap
{
	typedef struct MainResInfo
	{
		std::string		strResCode; //��Դ����
		std::string		strResName; //��Դ����
		std::string		strSystemName; //ϵͳ����
		std::string		strSystemPath; //ϵͳ·��
		std::string		strSystemIconFile; //ϵͳͼ���ļ�
		std::string		strSystemSlashImageFile; //ϵͳSlash�ļ�
		std::string		strDataTreePath; //������·��
		std::string		strGmeDBPath;//���ݿ�·��
		std::string		strAccessDBPath;//���ݿ�·��
		std::string		strImagePath; //ͼƬ·��
		std::string		strTempPath; //��ʱ�ļ�·��
		std::string		strSymbolPath; //����·��
		std::string     strShortCutName; //�������

		MainResInfo()
		{
			strResCode = "";
			strResName = "";
			strSystemName = "";
			strSystemPath = "";
			strSystemIconFile = "";
			strSystemSlashImageFile = "";
			strDataTreePath = "";
			strGmeDBPath = "";
			strAccessDBPath = "";
			strImagePath = "";
			strTempPath = "";
			strSymbolPath = "";
			strShortCutName = "";
		}
	}MainResInfo;

	class TDMFACERESMNG_EXPORT CTdmMainResMng
	{
	public:
		CTdmMainResMng();
		virtual ~CTdmMainResMng();

	public:
		void setMainResNode(TiXmlElement* mainResNode);											//������Դ�ڵ�
		void loadMainRes();																										//������Դ��Ϣ
		void queryMainRes(std::string attributeName, std::string& attributeValue);		//��ѯ��Դ����
		void alterMainRes(std::string attributeName, std::string attributeValue);			//�޸���Դ����

	private:
		void getNodeInfo(TiXmlElement* pNode);																//��ȡ�ڵ���Ϣ

	public:
		MainResInfo mMainResInfo;//ϵͳ������Ϣ

	private:
		TiXmlElement* mMainResNode;//��Դ�ڵ�
	};
}



