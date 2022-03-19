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
		std::string		strPResCode; //父节点编码
		std::string		strResCode; //资源编码
		std::string		strResName; //资源名称
		std::string		strMenuMode; //菜单模式 
		std::string		strBindView; //绑定视图
		std::string		strMenuType; //菜单类型
		std::string		strControlType; //控制类型
		std::string		strImageFile; //图像文件
		std::string		strImageFileType; //图像文件类型
		std::string		strHotKey; //快捷键
		std::string		strPlugName; //资源配置的功能插件
		std::string		strFuncName; //资源配置的功能插件的功能
		std::string     strParameter1; //参数1
		std::string     strParameter2; //参数2
		std::string		strBmpFileName; //资源对应的位图
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
		void setMenuNode(TiXmlElement* menuNode);																								//设置菜单节点
		void loadMenu();																																						//加载菜单信息
		void addMenu(std::string pResCode, std::string resCode, map<string, string> mapAttribute);			//添加菜单项
		void queryMenu(std::string resCode, std::string attributeName, std::string& attributeValue);				//查询菜单属性
		void alterMenu(std::string resCode, std::string attributeName, std::string attributeValue);					//修改菜单属性
		void deleteMenu(std::string resCode);																												//删除菜单项
		void upMoveMenu(std::string resCode);																											//上移菜单项
		void downMoveMenu(std::string resCode);																										//下移菜单项

	private:
		void loadNode(TiXmlElement* pNode, std::string pResCode, std::string viewName);//加载节点
		void getNodeInfo(TiXmlElement* pNode, std::string pResCode, std::string viewName);//获取节点信息
		bool nodeExist(TiXmlElement* pNode, std::string resCode);//判断节点存在
		bool addNode(TiXmlElement* pNode, std::string pResCode, std::string resCode, map<string, string> mapAttribute);//添加节点
		bool queryNodeAttribute(TiXmlElement* pNode, std::string resCode, std::string attributeName, std::string& attributeValue);//查询节点属性
		bool alterNodeAttribute(TiXmlElement* pNode, std::string resCode, std::string attributeName, std::string attributeValue);//更新节点属性
		bool deleteNode(TiXmlElement* pNode, std::string resCode);//删除节点
		bool moveNode(TiXmlElement* pNode, std::string resCode, int moveType);//移动节点

	public:
		std::vector<MenuResInfo> mMenuResInfo;//菜单信息
		std::vector<std::string> mViewResInfo;//绑定视图信息
		std::map<std::string, std::vector<MenuResInfo*>> mViewMenuResInfo;//视图菜单表信息

	private:
		TiXmlElement* mMenuNode;//菜单节点
	};

}