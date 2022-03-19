#pragma once


#include <vector>
#include <xstring>


#include "OGTinyxml.h"
#include "ogbasdef.h"
using namespace OC;




#define MAX_XMLNODENAME_LEN 256//允许的XML文件结点名最大长度


namespace Smart3dMap {
class OG_FRAME_DLL  CGeo3dXMLOper
{
public:
	CGeo3dXMLOper();
    ~CGeo3dXMLOper();

public:
	//初始化XML对象，szPathFileName为带路径的文件名
	short InitXMLDom(char *szPathFileName);
	//新建XML
	short NewXmlDoc(const char*	szPathFileName,
					const char* szRootName,
					const char* _version = NULL,
					const char* _encoding = NULL,
					const char* _standalone = NULL);
	//保存文件
	void  SaveTheFile(char *szFileName);

	// zj 2012.3.1 获取子节点列表 strFNode=""时，获取根节点下全部子节点
	long GetSubNodeList(String strFNode, std::vector<String>& vecSNode);
	// zj 2012.3.2 删除配置文件下全部子节点(默认不删除自身节点)
	long DelSubNodeList(String strFNode, bool bDelSelf = false);

	//通过路径获取和写入节点值(如："APP\loc\node1" 或 "APP/loc/node1"均可)
	String ReadDataByXPathNodeName(char *NodeName);
	short   WriteDataByXPathNodeName(char *NodeName,char *cValue);

	String ReadDataByXPathNodeName(String NodeName, String& resVal);
	bool   ReadDataByXPathNodeName(String NodeName, bool& resVal);
	short  ReadDataByXPathNodeName(String NodeName, short& resVal);
	long   ReadDataByXPathNodeName(String NodeName, long& resVal);
	float  ReadDataByXPathNodeName(String NodeName, float& resVal);
	double ReadDataByXPathNodeName(String NodeName, double& resVal);

	short  WriteDataByXPathNodeName(String NodeName, String cValue);
	short  WriteDataByXPathNodeName(String NodeName, bool cValue);
	short  WriteDataByXPathNodeName(String NodeName, short cValue);
	short  WriteDataByXPathNodeName(String NodeName, long cValue);
	short  WriteDataByXPathNodeName(String NodeName, float cValue);
	short  WriteDataByXPathNodeName(String NodeName, double cValue);

	//根据节点路径和标签读写节点的标签内容(无法处理重名情况)
	String ReadDataByNodeLabelName(String NodeName, String labelName, String& resVal);
	bool   ReadDataByNodeLabelName(String NodeName, String labelName, bool& resVal);
	short  ReadDataByNodeLabelName(String NodeName, String labelName, short& resVal);
	long   ReadDataByNodeLabelName(String NodeName, String labelName, long& resVal);
	float  ReadDataByNodeLabelName(String NodeName, String labelName, float& resVal);
	double ReadDataByNodeLabelName(String NodeName, String labelName, double& resVal);

	short  WriteDataByNodeLabelName(String NodeName, String labelName, String cValue);
	short  WriteDataByNodeLabelName(String NodeName, String labelName, bool cValue);
	short  WriteDataByNodeLabelName(String NodeName, String labelName, short cValue);
	short  WriteDataByNodeLabelName(String NodeName, String labelName, long cValue);
	short  WriteDataByNodeLabelName(String NodeName, String labelName, float cValue);
	short  WriteDataByNodeLabelName(String NodeName, String labelName, double cValue);

private:
	//add by wj20090605
	//根据传入路径找到指定的节点
	//	bNewIfNotExist  没有发现指定节点时是否创建新节点
	TiXmlElement *GetElemByXPathNodeName(String NodeName, bool bNewIfNotExist = false);

public:
	static	CGeo3dXMLOper   *getSinglonPtr();
	static	CGeo3dXMLOper   &getSinglon();

private:
	TiXmlDocument	*m_pXMLDoc;
	TiXmlElement*   m_pRootNode;
};

//获取系统使用的XML zj 2012.03.01
String OG_FRAME_DLL GetSysCFGFile();

//打开系统配置文件(*.xml)，返回值：1/0 成功/失败 
long OG_FRAME_DLL OpenSysCFGFile(CGeo3dXMLOper** ppXMLOper);
//关闭系统配置文件(*.xml)，返回值：无
void OG_FRAME_DLL CloseSysCFGFile(CGeo3dXMLOper** ppXMLOper);

//打开用户配置文件(*.xml)，返回值：1/0 成功/失败 
long OG_FRAME_DLL OpenGeoCFGFile(CGeo3dXMLOper** ppXMLOper, char *szPathFileName);
//关闭用户配置文件(*.xml)，返回值：无
void OG_FRAME_DLL CloseGeoCFGFile(CGeo3dXMLOper** ppXMLOper, char *szPathFileName);

//将传入的字符串解析为字符串列表
void OG_FRAME_DLL getStringList(String strNodePath, std::vector<String>& strNameList, String strSeparator="/");
//将传入的字符串列表组装成字符串
void OG_FRAME_DLL setStringList(std::vector<String> strNameList, String& strNodePath, String strSeparator="/");


}