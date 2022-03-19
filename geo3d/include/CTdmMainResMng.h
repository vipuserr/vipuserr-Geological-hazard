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
		std::string		strResCode; //资源编码
		std::string		strResName; //资源名称
		std::string		strSystemName; //系统名称
		std::string		strSystemPath; //系统路径
		std::string		strSystemIconFile; //系统图标文件
		std::string		strSystemSlashImageFile; //系统Slash文件
		std::string		strDataTreePath; //数据树路径
		std::string		strGmeDBPath;//数据库路径
		std::string		strAccessDBPath;//数据库路径
		std::string		strImagePath; //图片路径
		std::string		strTempPath; //临时文件路径
		std::string		strSymbolPath; //符号路径
		std::string     strShortCutName; //快捷名称

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
		void setMainResNode(TiXmlElement* mainResNode);											//设置资源节点
		void loadMainRes();																										//加载资源信息
		void queryMainRes(std::string attributeName, std::string& attributeValue);		//查询资源属性
		void alterMainRes(std::string attributeName, std::string attributeValue);			//修改资源属性

	private:
		void getNodeInfo(TiXmlElement* pNode);																//获取节点信息

	public:
		MainResInfo mMainResInfo;//系统基本信息

	private:
		TiXmlElement* mMainResNode;//资源节点
	};
}



