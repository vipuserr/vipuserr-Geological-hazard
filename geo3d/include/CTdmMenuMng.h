#pragma once

#include "tdmfaceresmng_global.h"
#include "CTdmXmlDef.h"
#include "OGtinyxml.h"
#include "OGBasDef.h"
#include <vector>

class QObject;
class QStandardItem;

namespace Smart3dMap 
{
	typedef struct MenuResInfo
	{
		std::string		strPResCode; //���ڵ����
		std::string		strResCode; //��Դ����
		std::string		strResName; //��Դ����
		std::string		strMenuMode; //�˵�ģʽ 
		std::string		strBindView; //����ͼ
		std::string		strMenuType; //�˵�����
		std::string		strControlType; //��������
		std::string		strImageFile; //ͼ���ļ�
		std::string		strImageFileType; //ͼ���ļ�����
		std::string		strHotKey; //��ݼ�
		std::string		strPlugName; //��Դ���õĹ��ܲ��
		std::string		strFuncName; //��Դ���õĹ��ܲ���Ĺ���
		std::string     strParameter1; //����1
		std::string     strParameter2; //����2
		std::string		strBmpFileName; //��Դ��Ӧ��λͼ
		QObject*		menuPtr;
		QStandardItem*  menuItemPtr;
		MenuResInfo()
		{
			strPResCode = "";
			strResCode = "";
			strResName = "";
			strMenuMode = "";
			strBindView = "";
			strMenuType = "";
			strControlType = "";
			strImageFile = "";
			strImageFileType = "";
			strHotKey = "";
			strPlugName = "";
			strFuncName = "";
			strParameter1 = "";
			strParameter2 = "";
			strBmpFileName = "";

			menuPtr = NULL;
			menuItemPtr = NULL;
		}
	}MenuResInfo;

	class TDMFACERESMNG_EXPORT CTdmMenuMng
	{
	public:
		CTdmMenuMng();
		virtual ~CTdmMenuMng();

	public:
		void setMenuNode(TiXmlElement* menuNode);																								//���ò˵��ڵ�
		void loadMenu();																																						//���ز˵���Ϣ
		void addMenu(std::string pResCode, std::string resCode, map<string, string> mapAttribute);			//��Ӳ˵���
		void queryMenu(std::string resCode, std::string attributeName, std::string& attributeValue);				//��ѯ�˵�����
		void alterMenu(std::string resCode, std::string attributeName, std::string attributeValue);					//�޸Ĳ˵�����
		void deleteMenu(std::string resCode);																												//ɾ���˵���
		void upMoveMenu(std::string resCode);																											//���Ʋ˵���
		void downMoveMenu(std::string resCode);																										//���Ʋ˵���

	private:
		void loadNode(TiXmlElement* pNode, std::string pResCode, std::string viewName);//���ؽڵ�
		void getNodeInfo(TiXmlElement* pNode, std::string pResCode, std::string viewName);//��ȡ�ڵ���Ϣ
		bool nodeExist(TiXmlElement* pNode, std::string resCode);//�жϽڵ����
		bool addNode(TiXmlElement* pNode, std::string pResCode, std::string resCode, map<string, string> mapAttribute);//��ӽڵ�
		bool queryNodeAttribute(TiXmlElement* pNode, std::string resCode, std::string attributeName, std::string& attributeValue);//��ѯ�ڵ�����
		bool alterNodeAttribute(TiXmlElement* pNode, std::string resCode, std::string attributeName, std::string attributeValue);//���½ڵ�����
		bool deleteNode(TiXmlElement* pNode, std::string resCode);//ɾ���ڵ�
		bool moveNode(TiXmlElement* pNode, std::string resCode, int moveType);//�ƶ��ڵ�

	public:
		std::vector<MenuResInfo> mMenuResInfo;//�˵���Ϣ
		std::vector<std::string> mViewResInfo;//����ͼ��Ϣ
		std::map<std::string, std::vector<MenuResInfo*>> mViewMenuResInfo;//��ͼ�˵�����Ϣ

	private:
		TiXmlElement* mMenuNode;//�˵��ڵ�
	};

}