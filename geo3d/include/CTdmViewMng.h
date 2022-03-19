#pragma once

#include "tdmfaceresmng_global.h"
#include "CTdmXmlDef.h"
#include "OGtinyxml.h"
#include "OGBasDef.h"
#include <vector>

namespace Smart3dMap
{
	typedef struct ViewResInfo
	{
		std::string		strResCode; //��Դ����
		std::string		strResName; //��Դ����
		std::string		strViewType; //��ͼ����
		std::string		strViewName; //��ͼ����
		std::string		strPluginType;//��ͼ�������
		std::string		strPluginFile; //����ļ�	
		std::string		strDataTreeXmlFile; //�������ļ�
		std::string		strTreeNodeImageFile; //���ڵ�ͼƬ

		ViewResInfo()
		{
			strResCode = "";
			strResName = "";
			strViewName = "";
			strPluginType = "";
			strPluginFile = "";
			strDataTreeXmlFile = "";
			strTreeNodeImageFile = "";
		}
	}ViewResInfo;

	class TDMFACERESMNG_EXPORT CTdmViewMng
	{
	public:
		CTdmViewMng();
		virtual ~CTdmViewMng();

	public:
		void setViewNode(TiXmlElement* viewNode);																							//������ͼ�ڵ�
		void loadView();																																		//������ͼ��Ϣ
		void addView(std::string resCode, map<string, string> mapAttribute);														//�����ͼ��
		void queryView(std::string resCode, std::string attributeName, std::string& attributeValue);						//��ѯ��ͼ����
		void alterView(std::string resCode, std::string attributeName, std::string attributeValue);							//�޸���ͼ����
		void deleteView(std::string resCode);																											//ɾ����ͼ��
			
	private:
		void loadNode(TiXmlElement* pNode);																										//���ؽڵ�
		void getNodeInfo(TiXmlElement* pNode);																									//��ȡ�ڵ���Ϣ

	public:
		std::vector<ViewResInfo> mLeftViewResInfo;//����ͼ��Ϣ
		std::vector<ViewResInfo> mRightViewResInfo;//����ͼ��Ϣ
		std::vector<ViewResInfo> mCenterViewResInfo;//�м���ͼ��Ϣ
		std::vector<ViewResInfo> mBottomViewResInfo;//�ײ���ͼ��Ϣ
		std::vector<ViewResInfo> mViewNodeInfo;//��ͼ�ڵ���Ϣ
		//ViewResInfo mViewNodeInfo;//��ͼ�ڵ���Ϣ

	private:
		TiXmlElement* mViewNode;//��ͼ�ڵ�
	};
}



