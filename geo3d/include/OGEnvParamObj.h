
//--------------------------------------------------------------------------------------------------------
// File:    OGEnvParamObj.h


#pragma once



#include "OGTinyxml.h"
#include "OGGenericUtils.h"


namespace Smart3dMap
{


	typedef struct GdeParam
	{
		GdeParam()
		{
			gdeType = 3; //GEO3D_DB_LINK_LOCAL
			strServerName = "";
			strGdbName = "";
			strUserName = "";
			strPswName = "";
		}
		long	gdeType;          //GEO3D_LinkType( 0x01-ORACLE, 0x03-local, 0x02-ODBC)
		string	strServerName;
		string  strGdbName;
		string	strUserName;
		string	strPswName;
	}GdeParam;

	typedef struct AppResParam
	{
		AppResParam()
		{
			strAppName = "";
			strAppPath = "";
		}
		string strAppName;         //ϵͳ����
		string strAppPath;

		//��¼��ͬ��λ�Ľ�����ͼ����б�
		std::vector<string> mLeftViewList; 
		std::vector<string> mMainViewList;
		std::vector<string> mRightViewList;
		std::vector<string> mBottomViewList;
	}AppResParam;

	typedef struct AppSysParam
	{
		AppSysParam()
		{
			lRenderEngineType = 0;
			l3DInteractiveType = 0;

			strSysDataMainPath = "";
				strGeograohyPath = "";
				strGeologyPath = "";
				str3DMdlPath = "";

			strSysParamMainPath = "";
				strMapGridPath = "";
				strClrTblPath = "";
				strMatPath = "";
				strEarthPath = "";

				lLinType = 1;
				dLinWid = 1;
				lLinClr = 1;
				lRgnClr = 2;
				dLinBuffer = 1;
				dRadius = 2;
		}

		long   lRenderEngineType; // 0: MapGIS / 1: ArcGIS
		long   l3DInteractiveType;// 0: ƽ��3D / 1: ����3D����

		string strSysDataMainPath; //������Ŀ¼����Ż��������������ʺ���άģ���������ݿ⣩
			string strGeograohyPath; //�����������ݿ�·������ͬ�����ߵĵ����ͼ��
			string strGeologyPath;   //�����������ݿ�·������ͬ�����ߵĵ���ͼ��
			string str3DMdlPath;	 //��άģ��·��

		string strSysParamMainPath;//ϵͳ�����ļ���Ŀ¼��������¼��ֲ����ļ���
			string strMapGridPath; //��ͼ�ַ�������·��
			string strClrTblPath;  //ɫ��·��
			string strMatPath;	   //����·��
			string strEarthPath;   //�������ݴ��·��.

		GdeParam mGdeParam;	 //��άģ�Ͳ���...

		//��������...
		long lLinType;
		double dLinWid;
		long lLinClr;
		long lRgnClr;
		double dLinBuffer;
		double dRadius;

	}AppSysParam;

	typedef struct CommonParam
	{
		CommonParam()
		{
			std::string	strTypeName="";
			std::string  strParamValue="";		
		}		
		std::string	strTypeName;
		std::string  strParamValue;
	}CommonParam;
typedef  std::map<std::string,std::vector<CommonParam>> MAP_COMMONPARAM;


	//��ά��������...
	//�ƹ�
	typedef struct LIGHTPARAM
	{
		LIGHTPARAM()
		{
			mName = "Default";
			mType = Smart3dMap::Light::LT_DIRECTIONAL;
			//mPos = Vector3::ZERO;
			//mDir = Vector3::UNIT_Z;
			//mDifColor = ColourValue::White;
			//mSpColor = ColourValue::Black;
			mAttenuationConstant = 0.0;
			mAttenuationLinear = 0.0;
			mAttenuationRange = 0.0;
			mAttenuationQuadric = 0.0;
			mFalloff = 0.0;
			mOuterAngle = 0.0;
			mInnerAngle = 0.0;
		}
		//����
		string mName;
		//����
		Smart3dMap::Light::LightTypes mType;
		//λ��
		Vector3 mPos;
		//����
		Vector3 mDir;
		//���������ɫ
		ColourValue mDifColor;
		//����߹���ɫ
		ColourValue mSpColor;
		//���÷�Χ
		Real mAttenuationRange;
		//�㶨����
		Real mAttenuationConstant;
		//��������
		Real mAttenuationLinear;
		//��������
		Real mAttenuationQuadric;
		//����ϵ��
		Real mFalloff;
		//��Ȧ�Ž�
		Radian mOuterAngle;
		//��Ȧ�Ž�
		Radian mInnerAngle;
	}LightParam;

	//������
	typedef struct ENVLIGHTPARAM
	{
		ENVLIGHTPARAM()
		{
			color = ColourValue(0.3 , 0.3 , 0.3);
		}
		//��ɫ
		ColourValue color;
	}EnvLightParam;

	//���
	typedef struct CAMERAPARAM 
	{
		CAMERAPARAM()
		{
			mName = "Default";
			mDetailType = PM_SOLID;
			mProjectionTyp = PT_PERSPECTIVE;
			mIsCutOut = true;
			//mBGLightColor = ColourValue::Black;
			mNearClip = 1;
			mFarClip = 100000;
			mFov = 45.0;
		}
		//����
		string mName;
		//���ģʽ
		Smart3dMap::PolygonMode mDetailType;
		//�Ƿ�ʵ��ü�
		bool mIsCutOut;
		//ͶӰģʽ
		ProjectionType mProjectionTyp;
		//������
		ColourValue mBGLightColor;
		//��,Զƽ��
		float mNearClip;
		float mFarClip;
		//FOV��
		float mFov;
	}CameraParam;

	//���
	typedef struct SKYPARAM 
	{
		SKYPARAM()
		{
			mIsStart = false;
			mFirstDraw = false;
			mMaterName = "";
			mDistance = 0.f;
			mXRotate = 0.f;
			mYRotate = 0.f;
			mZRotate = 0.f;
		}
		//�Ƿ�����
		bool mIsStart;
		//���Ȼ���
		bool mFirstDraw;
		//��������
		string	mMaterName;
		//����
		float	mDistance;
		//x��y��zת��
		float mXRotate;
		float mYRotate;
		float mZRotate;
	}SkyParam;

	//��Ч
	typedef struct FOGPARAM 
	{
		FOGPARAM()
		{
			mFogMode = FOG_NONE;
			mFogColor = ColourValue(0.3 , 0.3 , 0.3);
			mFogDensity = 0.0;
			mFogStart = 0.0;
			mFogEnd = 0.0;
		}
		//����
		FogMode	mFogMode;
		//��ɫ
		ColourValue mFogColor;
		//Ũ��ϵ��
		float	mFogDensity;
		//��ʼ
		float	mFogStart;
		//����
		float	mFogEnd;
	}FogParam;



	class OG_FRAME_DLL COGEnvParamObj
	{
	public:
		COGEnvParamObj(void);
		~COGEnvParamObj(void);

	public:
		//ע�⣺ʹ��Common��ǩ��ʱ��ItemNameֵҪΨһ
		long setCommonParam(std::string ItemName,std::string TypeName,std::string pValue);

		std::vector<CommonParam> getCommonParam(std::string ItemName);
		std::string getCommonParam(std::string ItemName,std::string TypeName);


	public:
		AppResParam mResFileParam; //ϵͳ��Դ����
		AppSysParam mSysFileParam; //ϵͳ���ò���
		std::map<std::string,std::vector<CommonParam>>mCommonParam;//�û��Զ����ǩ����,��<COMMON>�¶���

		//��ά��������ʵ����
		std::vector<LightParam>	mLightList;		//�ƹ��б�,֧�ֶ����ƹ�
		EnvLightParam		mEnvLightParam;		//�����еĻ�����
		CameraParam			mCameraParam;		//�����е����
		SkyParam			mSkyParam;			//�����е���պ�
		FogParam			mFogParam;			//�����е���Ч

		//MAP_PARA			m_dispMapParam;
	};

	class OG_FRAME_DLL COGEnvParamManager
	{
	private:
		COGEnvParamManager();
		~COGEnvParamManager(void);

	public:
		static COGEnvParamManager& getSingleton(void);
		static COGEnvParamManager* getSingletonPtr(void);

	public:
		void setCurAppName(string strAppName); //����ϵͳ�������ƣ��л�xml��Դ�ļ�
		void UpdateAppName(string strAppName); //����ϵͳ�������ƣ��л�xml��Դ�ļ�
		string getCurAppName(); //ȡ��ִ�г�������...
		void getAppPath(string &appPath);

		//�������������浽xml����,��ȷ���淵��--1,������󷵻�--0
		long writeSysFaceInfoToXml();
		long writeSysParamToXml();
		//��xml���еĻ���������ȡ����,��ȷ��ȡ����--1,��ȡ���󷵻�--0
		long readSysFaceInfoToXml();
		long readSysParamToXml();

		COGEnvParamObj* getEnvParam(void);

	private:
		//����xml�ļ�
		long OpenOrCreatSysFaceXmlFile(string strXmlFileName);
		long OpenOrCreatSysParamXmlFile(string strXmlFileName);

		//д�������Դ������Ϣ
		void writeAppResParam(TiXmlElement *pRootElem);
		//��ȡ������Դ������Ϣ
		void readAppResParam(TiXmlElement *pElem);

		//д��ϵͳ������Ϣ
		void writeAppSysParam(TiXmlElement *pRootElem);
		//��ȡϵͳ������Ϣ
		void readAppSysParam(TiXmlElement *pElem);

		//д��ͨ��������Ϣ
		void writeCommonInfo(TiXmlElement *pRootElem);
		//��ȡͨ��������Ϣ
		void readCommonInfo(TiXmlElement *pElem);

		//д�ƹ���Ϣ
		void writeLightInfo(TiXmlElement *pRootElem);
		//���ƹ���Ϣ
		void readLightInfo(TiXmlElement *pElem );

		//д��������Ϣ
		void writeEnvLightInfo(TiXmlElement *pRootElem );
		//����������Ϣ
		void readEnvLightInfo(TiXmlElement *pElem );

		//д�����Ϣ
		void writeCameraInfo(TiXmlElement *pRootElem );
		//�������Ϣ
		void readCameraInfo(TiXmlElement *pElem );

		//д�����Ϣ
		void writeSkyInfo(TiXmlElement *pRootElem );
		//�������Ϣ
		void readSkyInfo(TiXmlElement *pElem );

		//д��Ч��Ϣ
		void writeFogInfo(TiXmlElement *pRootElem );
		//����Ч��Ϣ
		void readFogInfo(TiXmlElement *pElem );


	private:
		COGEnvParamObj mEnvParamObj; //ϵͳ������

		TiXmlDocument*	m_pSysFaceXMLDoc; //ϵͳ���淽����xml��Դ�ļ���OGSysFaceCfg.xml��
		TiXmlElement*   m_pSysFaceRootNode;

		TiXmlDocument*	m_pSysParamXMLDoc;  //ϵͳ�������õ�xml�ļ���OGSysParamCfg.xml��
		TiXmlElement*   m_pSysParamRootNode;
	};



}
