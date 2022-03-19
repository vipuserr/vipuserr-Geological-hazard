#pragma once


#include <vector>
#include <xstring>


#include "OGTinyxml.h"
#include "ogbasdef.h"
using namespace OC;




#define MAX_XMLNODENAME_LEN 256//�����XML�ļ��������󳤶�


namespace Smart3dMap {
class OG_FRAME_DLL  CGeo3dXMLOper
{
public:
	CGeo3dXMLOper();
    ~CGeo3dXMLOper();

public:
	//��ʼ��XML����szPathFileNameΪ��·�����ļ���
	short InitXMLDom(char *szPathFileName);
	//�½�XML
	short NewXmlDoc(const char*	szPathFileName,
					const char* szRootName,
					const char* _version = NULL,
					const char* _encoding = NULL,
					const char* _standalone = NULL);
	//�����ļ�
	void  SaveTheFile(char *szFileName);

	// zj 2012.3.1 ��ȡ�ӽڵ��б� strFNode=""ʱ����ȡ���ڵ���ȫ���ӽڵ�
	long GetSubNodeList(String strFNode, std::vector<String>& vecSNode);
	// zj 2012.3.2 ɾ�������ļ���ȫ���ӽڵ�(Ĭ�ϲ�ɾ������ڵ�)
	long DelSubNodeList(String strFNode, bool bDelSelf = false);

	//ͨ��·����ȡ��д��ڵ�ֵ(�磺"APP\loc\node1" �� "APP/loc/node1"����)
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

	//���ݽڵ�·���ͱ�ǩ��д�ڵ�ı�ǩ����(�޷������������)
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
	//���ݴ���·���ҵ�ָ���Ľڵ�
	//	bNewIfNotExist  û�з���ָ���ڵ�ʱ�Ƿ񴴽��½ڵ�
	TiXmlElement *GetElemByXPathNodeName(String NodeName, bool bNewIfNotExist = false);

public:
	static	CGeo3dXMLOper   *getSinglonPtr();
	static	CGeo3dXMLOper   &getSinglon();

private:
	TiXmlDocument	*m_pXMLDoc;
	TiXmlElement*   m_pRootNode;
};

//��ȡϵͳʹ�õ�XML zj 2012.03.01
String OG_FRAME_DLL GetSysCFGFile();

//��ϵͳ�����ļ�(*.xml)������ֵ��1/0 �ɹ�/ʧ�� 
long OG_FRAME_DLL OpenSysCFGFile(CGeo3dXMLOper** ppXMLOper);
//�ر�ϵͳ�����ļ�(*.xml)������ֵ����
void OG_FRAME_DLL CloseSysCFGFile(CGeo3dXMLOper** ppXMLOper);

//���û������ļ�(*.xml)������ֵ��1/0 �ɹ�/ʧ�� 
long OG_FRAME_DLL OpenGeoCFGFile(CGeo3dXMLOper** ppXMLOper, char *szPathFileName);
//�ر��û������ļ�(*.xml)������ֵ����
void OG_FRAME_DLL CloseGeoCFGFile(CGeo3dXMLOper** ppXMLOper, char *szPathFileName);

//��������ַ�������Ϊ�ַ����б�
void OG_FRAME_DLL getStringList(String strNodePath, std::vector<String>& strNameList, String strSeparator="/");
//��������ַ����б���װ���ַ���
void OG_FRAME_DLL setStringList(std::vector<String> strNameList, String& strNodePath, String strSeparator="/");


}