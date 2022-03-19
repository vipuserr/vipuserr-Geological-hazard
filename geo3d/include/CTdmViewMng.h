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
		std::string		strResCode; //资源编码
		std::string		strResName; //资源名称
		std::string		strViewType; //视图类型
		std::string		strViewName; //视图名称
		std::string		strPluginType;//视图插件类型
		std::string		strPluginFile; //插件文件	
		std::string		strDataTreeXmlFile; //数据树文件
		std::string		strTreeNodeImageFile; //树节点图片

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
		void setViewNode(TiXmlElement* viewNode);																							//设置视图节点
		void loadView();																																		//加载视图信息
		void addView(std::string resCode, map<string, string> mapAttribute);														//添加视图项
		void queryView(std::string resCode, std::string attributeName, std::string& attributeValue);						//查询视图属性
		void alterView(std::string resCode, std::string attributeName, std::string attributeValue);							//修改视图属性
		void deleteView(std::string resCode);																											//删除视图项
			
	private:
		void loadNode(TiXmlElement* pNode);																										//加载节点
		void getNodeInfo(TiXmlElement* pNode);																									//获取节点信息

	public:
		std::vector<ViewResInfo> mLeftViewResInfo;//左视图信息
		std::vector<ViewResInfo> mRightViewResInfo;//右视图信息
		std::vector<ViewResInfo> mCenterViewResInfo;//中间视图信息
		std::vector<ViewResInfo> mBottomViewResInfo;//底部视图信息
		std::vector<ViewResInfo> mViewNodeInfo;//视图节点信息
		//ViewResInfo mViewNodeInfo;//视图节点信息

	private:
		TiXmlElement* mViewNode;//视图节点
	};
}



