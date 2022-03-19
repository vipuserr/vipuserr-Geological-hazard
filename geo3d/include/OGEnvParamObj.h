
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
		string strAppName;         //系统名称
		string strAppPath;

		//记录不同方位的界面视图插件列表
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
		long   l3DInteractiveType;// 0: 平面3D / 1: 球面3D交互

		string strSysDataMainPath; //数据主目录（存放基础地理、基础地质和三维模型三种数据库）
			string strGeograohyPath; //基础地理数据库路径（不同比例尺的地理地图）
			string strGeologyPath;   //基础地质数据库路径（不同比例尺的地质图）
			string str3DMdlPath;	 //三维模型路径

		string strSysParamMainPath;//系统参数文件主目录（存放以下几种参数文件）
			string strMapGridPath; //地图分幅网格存放路径
			string strClrTblPath;  //色表路径
			string strMatPath;	   //材质路径
			string strEarthPath;   //地球数据存放路径.

		GdeParam mGdeParam;	 //三维模型参数...

		//交互参数...
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


	//三维场景参数...
	//灯光
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
		//名称
		string mName;
		//类型
		Smart3dMap::Light::LightTypes mType;
		//位置
		Vector3 mPos;
		//方向
		Vector3 mDir;
		//漫反射光颜色
		ColourValue mDifColor;
		//镜面高光颜色
		ColourValue mSpColor;
		//作用范围
		Real mAttenuationRange;
		//恒定因子
		Real mAttenuationConstant;
		//线性因子
		Real mAttenuationLinear;
		//二次因子
		Real mAttenuationQuadric;
		//过度系数
		Real mFalloff;
		//外圈张角
		Radian mOuterAngle;
		//内圈张角
		Radian mInnerAngle;
	}LightParam;

	//环境光
	typedef struct ENVLIGHTPARAM
	{
		ENVLIGHTPARAM()
		{
			color = ColourValue(0.3 , 0.3 , 0.3);
		}
		//颜色
		ColourValue color;
	}EnvLightParam;

	//相机
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
		//名称
		string mName;
		//填充模式
		Smart3dMap::PolygonMode mDetailType;
		//是否实体裁剪
		bool mIsCutOut;
		//投影模式
		ProjectionType mProjectionTyp;
		//背景光
		ColourValue mBGLightColor;
		//近,远平面
		float mNearClip;
		float mFarClip;
		//FOV角
		float mFov;
	}CameraParam;

	//天空
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
		//是否启用
		bool mIsStart;
		//最先绘制
		bool mFirstDraw;
		//材质名称
		string	mMaterName;
		//距离
		float	mDistance;
		//x，y，z转角
		float mXRotate;
		float mYRotate;
		float mZRotate;
	}SkyParam;

	//雾效
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
		//类型
		FogMode	mFogMode;
		//颜色
		ColourValue mFogColor;
		//浓度系数
		float	mFogDensity;
		//开始
		float	mFogStart;
		//结束
		float	mFogEnd;
	}FogParam;



	class OG_FRAME_DLL COGEnvParamObj
	{
	public:
		COGEnvParamObj(void);
		~COGEnvParamObj(void);

	public:
		//注意：使用Common标签的时候，ItemName值要唯一
		long setCommonParam(std::string ItemName,std::string TypeName,std::string pValue);

		std::vector<CommonParam> getCommonParam(std::string ItemName);
		std::string getCommonParam(std::string ItemName,std::string TypeName);


	public:
		AppResParam mResFileParam; //系统资源参数
		AppSysParam mSysFileParam; //系统常用参数
		std::map<std::string,std::vector<CommonParam>>mCommonParam;//用户自定义标签参数,在<COMMON>下定义

		//三维场景的现实参数
		std::vector<LightParam>	mLightList;		//灯光列表,支持多束灯光
		EnvLightParam		mEnvLightParam;		//场景中的环境光
		CameraParam			mCameraParam;		//场景中的相机
		SkyParam			mSkyParam;			//场景中的天空盒
		FogParam			mFogParam;			//场景中的雾效

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
		void setCurAppName(string strAppName); //设置系统方案名称，切换xml资源文件
		void UpdateAppName(string strAppName); //设置系统方案名称，切换xml资源文件
		string getCurAppName(); //取出执行程序名称...
		void getAppPath(string &appPath);

		//将环境参数保存到xml树中,正确保存返回--1,保存错误返回--0
		long writeSysFaceInfoToXml();
		long writeSysParamToXml();
		//将xml树中的环境参数读取出来,正确读取返回--1,读取错误返回--0
		long readSysFaceInfoToXml();
		long readSysParamToXml();

		COGEnvParamObj* getEnvParam(void);

	private:
		//创建xml文件
		long OpenOrCreatSysFaceXmlFile(string strXmlFileName);
		long OpenOrCreatSysParamXmlFile(string strXmlFileName);

		//写入界面资源配置信息
		void writeAppResParam(TiXmlElement *pRootElem);
		//读取界面资源配置信息
		void readAppResParam(TiXmlElement *pElem);

		//写入系统配置信息
		void writeAppSysParam(TiXmlElement *pRootElem);
		//读取系统配置信息
		void readAppSysParam(TiXmlElement *pElem);

		//写入通用配置信息
		void writeCommonInfo(TiXmlElement *pRootElem);
		//读取通用配置信息
		void readCommonInfo(TiXmlElement *pElem);

		//写灯光信息
		void writeLightInfo(TiXmlElement *pRootElem);
		//读灯光信息
		void readLightInfo(TiXmlElement *pElem );

		//写环境光信息
		void writeEnvLightInfo(TiXmlElement *pRootElem );
		//读环境光信息
		void readEnvLightInfo(TiXmlElement *pElem );

		//写相机信息
		void writeCameraInfo(TiXmlElement *pRootElem );
		//读相机信息
		void readCameraInfo(TiXmlElement *pElem );

		//写天空信息
		void writeSkyInfo(TiXmlElement *pRootElem );
		//读天空信息
		void readSkyInfo(TiXmlElement *pElem );

		//写雾效信息
		void writeFogInfo(TiXmlElement *pRootElem );
		//读雾效信息
		void readFogInfo(TiXmlElement *pElem );


	private:
		COGEnvParamObj mEnvParamObj; //系统参数表

		TiXmlDocument*	m_pSysFaceXMLDoc; //系统界面方案的xml资源文件（OGSysFaceCfg.xml）
		TiXmlElement*   m_pSysFaceRootNode;

		TiXmlDocument*	m_pSysParamXMLDoc;  //系统参数配置的xml文件（OGSysParamCfg.xml）
		TiXmlElement*   m_pSysParamRootNode;
	};



}
