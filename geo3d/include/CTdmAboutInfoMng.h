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
		std::string		strResCode; //资源编码
		std::string		strResName; //资源名称
		std::string		strViewName; //视图名称
		std::string		strWindowTitleName; //窗口标题
		std::string		strSystemName; //系统名
		std::string		strVersionNo; //版本号
		std::string		strAuthor; //作者
		std::string		strSystemDescription; //系统描述
		std::string		strAboutImageFile; //图片文件

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
		void setAboutNode(TiXmlElement* aboutNode);																						//设置关于节点
		void loadAbout();																																		//加载关于信息
		void queryAbout(std::string attributeName, std::string& attributeValue);													//查询关于属性
		void alterAbout(std::string attributeName, std::string attributeValue);														//修改关于属性

	private:
		void loadNode(TiXmlElement* pNode);																										//加载节点
		void getNodeInfo(TiXmlElement* pNode);																									//获取节点信息

	public:
		std::vector<AboutResInfo> mAboutResInfo;//关于信息

	private:
		TiXmlElement* mAboutNode;//关于节点
	};
}



