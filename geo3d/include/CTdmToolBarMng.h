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
		std::string		strPResCode; //父节点编码
		std::string		strResCode; //资源编码
		std::string		strResName; //资源名称
		std::string		strBindView; //绑定视图
		std::string		strDockPos; //悬浮窗口
		std::string		strImageFile; //图像文件
		std::string		strImageFileType; //图像文件类型
		std::string		strControlType; //控制类型
		std::string		strHotKey; //快捷键
		std::string		strPlugName; //资源配置的功能插件
		std::string		strFuncName; //资源配置的功能插件的功能
		std::string     strParameter1; //参数1
		std::string     strParameter2; //参数2
		std::string		strBmpFileName; //资源对应的位图
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
		void setToolBarNode(TiXmlElement* toolBarNode);																					//设置工具栏节点
		void loadToolBar();																																				//加载工具栏信息
		void addTool(std::string pResCode, std::string resCode, map<string, string> mapAttribute);			//添加工具项
		void queryTool(std::string resCode, std::string attributeName, std::string& attributeValue);			//查询工具属性
		void alterTool(std::string resCode, std::string attributeName, std::string attributeValue);					//修改工具属性
		void deleteTool(std::string resCode);																												//删除工具项
		void upMoveTool(std::string resCode);																											//上移工具项
		void downMoveTool(std::string resCode);																									//下移工具项

	private:
		void loadNode(TiXmlElement* pNode, std::string pResCode, std::string viewName);							//加载节点
		void getNodeInfo(TiXmlElement* pNode, std::string pResCode, std::string viewName);					//获取节点信息
		bool nodeExist(TiXmlElement* pNode, std::string resCode);																		//判断节点存在
		bool addNode(TiXmlElement* pNode, std::string pResCode, std::string resCode, map<string, string> mapAttribute);//添加节点
		bool queryNodeAttribute(TiXmlElement* pNode, std::string resCode, std::string attributeName, std::string& attributeValue);//查询节点属性
		bool alterNodeAttribute(TiXmlElement* pNode, std::string resCode, std::string attributeName, std::string attributeValue);//更新节点属性
		bool deleteNode(TiXmlElement* pNode, std::string resCode);																//删除节点
		bool moveNode(TiXmlElement* pNode, std::string resCode, int moveType);										//移动节点

	public:
		std::vector<ToolBarResInfo> mToolBarResInfo;//工具栏信息
		std::vector<std::string> mViewResInfo;//绑定视图信息
		std::map<std::string, std::vector<ToolBarResInfo*>> mViewToolResInfo;//视图工具表

	private:
		TiXmlElement* mToolBarNode;//工具栏节点
	};
}




