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
		std::string		strResCode; //资源编码
		std::string		strResName; //资源名称
		std::string		strControlType;//控制类型
		std::string		strDefaultValue;//默认值
		std::string     strParameter1; //参数1
		std::string     strParameter2; //参数2
		std::string     strParameter3; //参数3

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
		void setStatusBarNode(TiXmlElement* statusBarNode);																				//设置状态栏节点
		void loadStatusBar();																																			//加载状态栏信息
		void addStatusBar(std::string resCode, map<string, string> mapAttribute);											//添加状态栏
		void queryStatusBar(std::string resCode, std::string attributeName, std::string& attributeValue);	//查询状态栏属性
		void alterStatusBar(std::string resCode, std::string attributeName, std::string attributeValue);			//修改状态栏属性
		void deleteStatusBar(std::string resCode);																										//删除状态栏

	private:
		void loadNode(TiXmlElement* pNode);																											//加载节点
		void getNodeInfo(TiXmlElement* pNode);																									//获取节点信息

	public:
		std::vector<StatusBarResInfo> mStatusBarResInfo;//状态栏信息

	private:
		TiXmlElement* mStatusBarNode;//状态栏节点
	};
}



