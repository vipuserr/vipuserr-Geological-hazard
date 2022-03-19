#pragma once

#include "tdmfaceresmng_global.h"
#include "CTdmXmlDef.h"
#include "Ogtinyxml.h"
#include "OGBasDef.h"
#include <vector>

namespace Smart3dMap
{
	typedef struct AboutResInfo
	{
		std::string		strResCode; //��Դ����
		std::string		strResName; //��Դ����
		std::string		strViewName; //��ͼ����
		std::string		strWindowTitleName; //���ڱ���
		std::string		strSystemName; //ϵͳ��
		std::string		strVersionNo; //�汾��
		std::string		strAuthor; //����
		std::string		strSystemDescription; //ϵͳ����
		std::string		strAboutImageFile; //ͼƬ�ļ�

		AboutResInfo()
		{
			strResCode = "";
			strResName = "";
			strViewName = "";
			strWindowTitleName = "";
			strSystemName = "";
			strVersionNo = "";
			strAuthor = "";
			strSystemDescription = "";
			strAboutImageFile = "";
		}
	}AboutResInfo;

	class TDMFACERESMNG_EXPORT CTdmAboutInfoMng
	{
	public:
		CTdmAboutInfoMng();
		virtual ~CTdmAboutInfoMng();

	public:
		void setAboutNode(TiXmlElement* aboutNode);																						//���ù��ڽڵ�
		void loadAbout();																																		//���ع�����Ϣ
		void queryAbout(std::string attributeName, std::string& attributeValue);													//��ѯ��������
		void alterAbout(std::string attributeName, std::string attributeValue);														//�޸Ĺ�������

	private:
		void loadNode(TiXmlElement* pNode);																										//���ؽڵ�
		void getNodeInfo(TiXmlElement* pNode);																									//��ȡ�ڵ���Ϣ

	public:
		std::vector<AboutResInfo> mAboutResInfo;//������Ϣ

	private:
		TiXmlElement* mAboutNode;//���ڽڵ�
	};
}



