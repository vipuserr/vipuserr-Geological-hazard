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
		std::string		strResCode; //资源编码
		std::string		strResName; //资源名称
		std::string		strPlugName; //资源配置的功能插件
		std::string		strFuncName; //资源配置的功能插件的功能
		std::string     strParameter1; //参数1
		std::string     strParameter2; //参数2

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
		void setPreLoadNode(TiXmlElement* preLoadNode);																					//设置预加载节点
		void loadPreLoad();																																	//加载预加载信息
		void addPreLoad(std::string resCode, map<string, string> mapAttribute);													//添加预加载项
		void queryPreLoad(std::string resCode, std::string attributeName, std::string& attributeValue);					//查询预加载属性
		void alterPreLoad(std::string resCode, std::string attributeName, std::string attributeValue);						//修改预加载属性
		void deletePreLoad(std::string resCode);																									//删除预加载项

	private:
		void loadNode(TiXmlElement* pNode);																										//加载节点
		void getNodeInfo(TiXmlElement* pNode);																									//获取节点信息

	public:
		std::vector<PreLoadResInfo> mPreLoadResInfo;//预加载信息

	private:
		TiXmlElement* mPreLoadNode;//预加载节点
	};
}



