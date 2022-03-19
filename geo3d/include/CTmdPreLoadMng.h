#pragma once

#include "tdmfaceresmng_global.h"
#include "CTdmXmlDef.h"
#include "OGtinyxml.h"
#include "OGBasDef.h"

#include <vector>

namespace Smart3dMap
{
	typedef struct PreLoadResInfo
	{
		std::string		strResCode; //��Դ����
		std::string		strResName; //��Դ����
		std::string		strPlugName; //��Դ���õĹ��ܲ��
		std::string		strFuncName; //��Դ���õĹ��ܲ���Ĺ���
		std::string     strParameter1; //����1
		std::string     strParameter2; //����2

		PreLoadResInfo()
		{
			strResCode = "";
			strResName = "";
			strPlugName = "";
			strFuncName = "";
			strParameter1 = "";
			strParameter2 = "";
		}
	}PreLoadResInfo;

	class TDMFACERESMNG_EXPORT CTmdPreLoadMng
	{
	public:
		CTmdPreLoadMng();
		virtual ~CTmdPreLoadMng();

	public:
		void setPreLoadNode(TiXmlElement* preLoadNode);																					//����Ԥ���ؽڵ�
		void loadPreLoad();																																	//����Ԥ������Ϣ
		void addPreLoad(std::string resCode, map<string, string> mapAttribute);													//���Ԥ������
		void queryPreLoad(std::string resCode, std::string attributeName, std::string& attributeValue);					//��ѯԤ��������
		void alterPreLoad(std::string resCode, std::string attributeName, std::string attributeValue);						//�޸�Ԥ��������
		void deletePreLoad(std::string resCode);																									//ɾ��Ԥ������

	private:
		void loadNode(TiXmlElement* pNode);																										//���ؽڵ�
		void getNodeInfo(TiXmlElement* pNode);																									//��ȡ�ڵ���Ϣ

	public:
		std::vector<PreLoadResInfo> mPreLoadResInfo;//Ԥ������Ϣ

	private:
		TiXmlElement* mPreLoadNode;//Ԥ���ؽڵ�
	};
}



