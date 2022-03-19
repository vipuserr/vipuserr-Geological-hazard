#pragma once

#include "tdmfaceresmng_global.h"
#include "CTdmXmlDef.h"
#include "OGtinyxml.h"
#include "OGBasDef.h"
#include <vector>

namespace Smart3dMap
{
	typedef struct StatusBarResInfo
	{
		std::string		strResCode; //��Դ����
		std::string		strResName; //��Դ����
		std::string		strControlType;//��������
		std::string		strDefaultValue;//Ĭ��ֵ
		std::string     strParameter1; //����1
		std::string     strParameter2; //����2
		std::string     strParameter3; //����3

		StatusBarResInfo()
		{
			strResCode = "";
			strResName = "";
			strControlType = "";
			strDefaultValue = "";
			strParameter1 = "";
			strParameter2 = "";
			strParameter3 = "";
		}
	}StatusBarResInfo;

	class TDMFACERESMNG_EXPORT CTdmStatusBarMng
	{
	public:
		CTdmStatusBarMng();
		~CTdmStatusBarMng();

	public:
		void setStatusBarNode(TiXmlElement* statusBarNode);																				//����״̬���ڵ�
		void loadStatusBar();																																			//����״̬����Ϣ
		void addStatusBar(std::string resCode, map<string, string> mapAttribute);											//���״̬��
		void queryStatusBar(std::string resCode, std::string attributeName, std::string& attributeValue);	//��ѯ״̬������
		void alterStatusBar(std::string resCode, std::string attributeName, std::string attributeValue);			//�޸�״̬������
		void deleteStatusBar(std::string resCode);																										//ɾ��״̬��

	private:
		void loadNode(TiXmlElement* pNode);																											//���ؽڵ�
		void getNodeInfo(TiXmlElement* pNode);																									//��ȡ�ڵ���Ϣ

	public:
		std::vector<StatusBarResInfo> mStatusBarResInfo;//״̬����Ϣ

	private:
		TiXmlElement* mStatusBarNode;//״̬���ڵ�
	};
}



