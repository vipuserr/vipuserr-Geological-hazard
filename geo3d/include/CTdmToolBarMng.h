#pragma once

#include "tdmfaceresmng_global.h"
#include "CTdmXmlDef.h"
#include "OGtinyxml.h"
#include "OGBasDef.h"
#include <vector>

class QObject;

namespace Smart3dMap
{
	typedef struct ToolBarResInfo
	{
		std::string		strPResCode; //���ڵ����
		std::string		strResCode; //��Դ����
		std::string		strResName; //��Դ����
		std::string		strBindView; //����ͼ
		std::string		strDockPos; //��������
		std::string		strImageFile; //ͼ���ļ�
		std::string		strImageFileType; //ͼ���ļ�����
		std::string		strControlType; //��������
		std::string		strHotKey; //��ݼ�
		std::string		strPlugName; //��Դ���õĹ��ܲ��
		std::string		strFuncName; //��Դ���õĹ��ܲ���Ĺ���
		std::string     strParameter1; //����1
		std::string     strParameter2; //����2
		std::string		strBmpFileName; //��Դ��Ӧ��λͼ
		QObject *       toolPtr;

		ToolBarResInfo()
		{
			strPResCode = "";
			strResCode = "";
			strResName = "";
			strBindView = "";
			strDockPos = "";
			strImageFile = "";
			strImageFileType = "";
			strControlType = "";
			strHotKey = "";
			strPlugName = "";
			strFuncName = "";
			strParameter1 = "";
			strParameter2 = "";
			strBmpFileName = "";
			toolPtr = NULL;
		}
	}ToolBarResInfo;

	class TDMFACERESMNG_EXPORT CTdmToolBarMng
	{
	public:
		CTdmToolBarMng();
		virtual ~CTdmToolBarMng();

	public:
		void setToolBarNode(TiXmlElement* toolBarNode);																					//���ù������ڵ�
		void loadToolBar();																																				//���ع�������Ϣ
		void addTool(std::string pResCode, std::string resCode, map<string, string> mapAttribute);			//��ӹ�����
		void queryTool(std::string resCode, std::string attributeName, std::string& attributeValue);			//��ѯ��������
		void alterTool(std::string resCode, std::string attributeName, std::string attributeValue);					//�޸Ĺ�������
		void deleteTool(std::string resCode);																												//ɾ��������
		void upMoveTool(std::string resCode);																											//���ƹ�����
		void downMoveTool(std::string resCode);																									//���ƹ�����

	private:
		void loadNode(TiXmlElement* pNode, std::string pResCode, std::string viewName);							//���ؽڵ�
		void getNodeInfo(TiXmlElement* pNode, std::string pResCode, std::string viewName);					//��ȡ�ڵ���Ϣ
		bool nodeExist(TiXmlElement* pNode, std::string resCode);																		//�жϽڵ����
		bool addNode(TiXmlElement* pNode, std::string pResCode, std::string resCode, map<string, string> mapAttribute);//��ӽڵ�
		bool queryNodeAttribute(TiXmlElement* pNode, std::string resCode, std::string attributeName, std::string& attributeValue);//��ѯ�ڵ�����
		bool alterNodeAttribute(TiXmlElement* pNode, std::string resCode, std::string attributeName, std::string attributeValue);//���½ڵ�����
		bool deleteNode(TiXmlElement* pNode, std::string resCode);																//ɾ���ڵ�
		bool moveNode(TiXmlElement* pNode, std::string resCode, int moveType);										//�ƶ��ڵ�

	public:
		std::vector<ToolBarResInfo> mToolBarResInfo;//��������Ϣ
		std::vector<std::string> mViewResInfo;//����ͼ��Ϣ
		std::map<std::string, std::vector<ToolBarResInfo*>> mViewToolResInfo;//��ͼ���߱�

	private:
		TiXmlElement* mToolBarNode;//�������ڵ�
	};
}




