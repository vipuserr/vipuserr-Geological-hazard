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
		void setXmlPathFile(std::string strXmlPathFile);//����XML�ļ�·��							
		void loadXml();	//����Xml�ļ���Ϣ
		void closeXML();//�رղ�����xml�ļ�...
		void saveXmlAs(std::string strSaveFileNam="");	//����XML�ļ���Ϣ
		void createXml(std::string strXmlPathFile, std::string sysName);		//����XML�ļ�
		std::string createResCode(std::string resName);           //������Դ����
		std::string getGmeDbUrl();		//��ȡDB·��
		void queryXml(std::string resNode, std::string resCode, std::string attributeName, std::string& attributeValue);//��ѯXML����

	

	public:
		CTdmMainResMng		mTdmMainResMng;			//����Դ����
		CTdmMenuMng			mTdmMenuMng;				//�˵�����
		CTdmToolBarMng			mTdmToolBarMng;			//����������
		CTdmViewMng				mTdmViewMng;				//��ͼ����
		CTdmStatusBarMng		mTdmStatusBarMng;		//״̬������
		CTdmAboutInfoMng		mTdmAboutInfoMng;		//���ڶ���
		CTmdPreLoadMng		mTmdPreLoadMng;			//Ԥ���ض���
	
	public:
		std::string		mstrXmlPathFile;								//XML·��+�ļ�
		std::string		mstrXmlPath;									//XML·��
		std::string		mstrXmlFile;										//XML�ļ���

	private:
		TiXmlDocument*	  mXMLDoc;								//XML�ļ�ָ��
		TiXmlElement*   mRootNode;								//XML���ڵ�ָ��
	};

}