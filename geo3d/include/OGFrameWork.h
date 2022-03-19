 #pragma once


#include "OGEnvParamObj.h"
#include "OGWindowMsgManager.h"
#include "OGObject.h"
#include "OGContainerManagerEnumerator.h"
#include "OGApplicationListener.h"
#include "OGContainerManager.h"
#include "OG3DElement.h"
#include "OG2DRenderEngine.h"
#include "OG3DRenderEngine.h"





class CGeo2dBaseMsgObj;




namespace Smart3dMap {

	// --------------------- 视图窗口 ---------------------- //
	#define STR_WINDOW_2D "地图视图" //二维基础视图
	#define STR_WINDOW_THEME "专题视图" //专题视图
	#define STR_WINDOW_3D "3D视图"	 //三维模型视图
	#define STR_WINDOW_DB "数据库"		 //数据库视图
	#define STR_WINDOW_MAIN_WND "框架窗口"

class OGDbLayerManager;
class OGDbElementManager;
class DbLayerManagerFactory;

	class OG_FRAME_DLL OgFrameWork
	{
	private:
		OgFrameWork();
		~OgFrameWork();

	public:
		// 单键
		static OgFrameWork& getSingleton(void);
		static OgFrameWork* getSingletonPtr(void);


	public:
		//启动框架...
		bool setupFramework(const string& sysPath = "");
		//装载所有插件
		bool loadPlugins();

		BOOL	AddWindow(string strName, HWND hWnd, __int64 pWnd = NULL);
		BOOL	RemoveWindow(HWND hWnd);
		HWND	getActiveWindowHandle();
		HWND	getWindowHandle(string strWndName);
		__int64	getWindowPtr(string strWndName);
		string	getWindowName(HWND hWnd);

		// -------------------应用程序监听器 --------------- //
		void addApplicationListener(ApplicationListener* newListener);
		void removeApplicationListener(ApplicationListener* listener);


		// -------------- 插件管理器管理器对象 ------------- //
		PluginFuncManager* getPluginFuncManager(void);
		PluginLibManager*	 getPluginLibManager();		

		//  ---------------- 图层管理器 --------------------- //
		ContainerManager* createContainerManager(const string& typeName,  const string& instanceName = OC::StringUtil::BLANK);
		void destroyContainerManager(ContainerManager* sm);

		ContainerManager* getContainerManager(const string& instanceName) const;
		ContainerManagerEnumerator::ContainerManagerIterator getContainerManagerIterator(void);

		void addContainerManagerFactory(ContainerManagerFactory* fact);
		void removeContainerManagerFactory(ContainerManagerFactory* fact);

		const ContainerManagerMetaData* getContainerManagerMetaData(const string& typeName) const;
		ContainerManagerEnumerator::MetaDataIterator getContainerManagerMetaDataIterator(void) const;


		//  ------------------- 图层、元素管理器 ------------------ //
		ContainerManager*   getDefault2DLayerManager();			
		ElementManager*		getDefault2DElementManager();
		OG3DLayerManager*	getDefault3DLayerManager();
		OG3DElementManager* getDefault3DElementManager();
		OGDbLayerManager*	getDefaultDbLayerManager();
		OGDbElementManager* getDefaultDbElementManager();

		void set2DLayerMgr(HWND hWnd, ContainerManager* p2DLayerMgr);
		void set2DElementMgr(HWND hWnd, ElementManager* p2DElementMgr);
		void set2DRenderEngine(HWND hWnd, C2DRendEngine* p2dRenderEngine);
		void set3DLayerMgr(HWND hWnd, OG3DLayerManager*p3DLayerMgr);
		void set3DElementMgr(HWND hWnd, OG3DElementManager*p3DElementMgr);
		void set3DRenderEngine(HWND hWnd, C3DRenderEngine* p3DRenderEngine);//记录三维可视化引擎

		ContainerManager*	get2DLayerMgr(HWND hWnd);
		ElementManager*		get2DElementMgr(HWND hWnd);
		C2DRendEngine*  get2DRenderEngine(HWND hWnd);
		C3DRenderEngine*	get3DRenderEngine(HWND hWnd=NULL);//hWnd为空时，返回当前激活的三维视图引擎
		OG3DLayerManager*	get3DLayerMgr(HWND hWnd);
		OG3DElementManager*	get3DElementMgr(HWND hWnd);

		// ------------------- 自定义对象 --------------------- //
		size_t	getUserDefinedObjectNum() const;
		OGUserDefinedObject*	getUserDefinedObject(size_t index);
		OGUserDefinedObject*	getUserDefinedObject(const string& typeName);
		void	__addUserDefinedObject(OGUserDefinedObject* userObject);
		void	__removeUserDefinedObject(OGUserDefinedObject* userObject);

		// ----------------- 系统环境参数 ------------------ //
		COGEnvParamObj* getEnvParam(void);

		// ---------------------- 应用程序目录 ------------------ //
		void setSysDirectory(const string& SysDirectory);
		string getSysDirectory(void) const;

		void setMaterialPath(string& matPath);
		string getMaterialPath();



    private:
		// 启动
		void initialiseFramework(void);
		void shutdownFramework(void);		
		
	private:
		std::map<string, HWND> m_renderWndList;
		std::map<string, __int64> m_renderQtWndList;

		ContainerManager*	mContainerManager; // 数据层管理器
		ElementManager*		mElementManager;	 // 数据层元素管理器
		OG3DLayerManager*	m3DLayerManager;		 // 三维数据层管理器
		OG3DElementManager* m3DElementManager;// 三维数据层元素管理器
		OGDbLayerManager*	mDbLayerManager;		 // 数据库数据层管理器
		OGDbElementManager* mDbElementManager;// 数据库数据层元素管理器

		//工厂
		ContainerManagerEnumerator* mContainerManagerEnum;
		ContainerManagerFactory* mContainerManagerFactory;
		LayerManagerFactory* mLayerManagerFactory;
		DbLayerManagerFactory* mDbLayerManagerFactory;

		PluginFuncManager* mPluginFuncManager;   // 插件功能管理器		
		PluginLibManager* mPluginLibManager;         //插件库管理器
		BOOL	m_bLoadPlugin;

		//消息转发器...
		WindowMsgDispatcher* mWindowMsgDispatcher;

		typedef std::vector<ApplicationListener*> ApplicationListenerList;
		ApplicationListenerList mApplicationListenerList;

		typedef std::vector<OGUserDefinedObject*> OGUserDefinedObjectList;
		OGUserDefinedObjectList	mUserDefinedObjectList;

		//记录与窗口相关的参数
		typedef std::map<HWND, long long> WindowParamValueList;
		WindowParamValueList		m2DLayerMgrList;
		WindowParamValueList		m2DElementMgrList;	
		WindowParamValueList		m2DRenderEngineList; //2D渲染引擎
		WindowParamValueList		m3DRenderEngineList; //3D渲染引擎
		WindowParamValueList		m3DLayerMgrList;
		WindowParamValueList		m3DElementMgrList;

		string				mSysDirectory;
		bool				mIsSetup;
		CGeo2dBaseMsgObj*	mpMsgObj;
		string				m_materialPath;
	};
	
} // namespace Smart3dMap


