#pragma once

#include "CTdmXmlDef.h"
#include "tdmfaceresmng_global.h"
#include "CTdmMainResMng.h"
#include "CTdmMenuMng.h"
#include "CTdmToolBarMng.h"
#include "CTdmViewMng.h"
#include "CTdmStatusBarMng.h"
#include "CTdmAboutInfoMng.h"
#include "CTmdPreLoadMng.h"
#include "OGtinyxml.h"


namespace Smart3dMap
{

	class TDMFACERESMNG_EXPORT TdmFaceResMng
	{
	private:
		TdmFaceResMng();
		~TdmFaceResMng();

	public:
		static TdmFaceResMng* getSingletonPtr(void);
		static TdmFaceResMng& getSingleton(void);

	public:
		void setXmlPathFile(std::string strXmlPathFile);//设置XML文件路径							
		void loadXml();	//加载Xml文件信息
		void closeXML();//关闭并保存xml文件...
		void saveXmlAs(std::string strSaveFileNam="");	//保存XML文件信息
		void createXml(std::string strXmlPathFile, std::string sysName);		//创建XML文件
		std::string createResCode(std::string resName);           //生成资源编码
		std::string getGmeDbUrl();		//获取DB路径
		void queryXml(std::string resNode, std::string resCode, std::string attributeName, std::string& attributeValue);//查询XML属性

	

	public:
		CTdmMainResMng		mTdmMainResMng;			//主资源对象
		CTdmMenuMng			mTdmMenuMng;				//菜单对象
		CTdmToolBarMng			mTdmToolBarMng;			//工具栏对象
		CTdmViewMng				mTdmViewMng;				//视图对象
		CTdmStatusBarMng		mTdmStatusBarMng;		//状态栏对象
		CTdmAboutInfoMng		mTdmAboutInfoMng;		//关于对象
		CTmdPreLoadMng		mTmdPreLoadMng;			//预加载对象
	
	public:
		std::string		mstrXmlPathFile;								//XML路径+文件
		std::string		mstrXmlPath;									//XML路径
		std::string		mstrXmlFile;										//XML文件名

	private:
		TiXmlDocument*	  mXMLDoc;								//XML文件指针
		TiXmlElement*   mRootNode;								//XML根节点指针
	};

}