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

	// --------------------- ��ͼ���� ---------------------- //
	#define STR_WINDOW_2D "��ͼ��ͼ" //��ά������ͼ
	#define STR_WINDOW_THEME "ר����ͼ" //ר����ͼ
	#define STR_WINDOW_3D "3D��ͼ"	 //��άģ����ͼ
	#define STR_WINDOW_DB "���ݿ�"		 //���ݿ���ͼ
	#define STR_WINDOW_MAIN_WND "��ܴ���"

class OGDbLayerManager;
class OGDbElementManager;
class DbLayerManagerFactory;

	class OG_FRAME_DLL OgFrameWork
	{
	private:
		OgFrameWork();
		~OgFrameWork();

	public:
		// ����
		static OgFrameWork& getSingleton(void);
		static OgFrameWork* getSingletonPtr(void);


	public:
		//�������...
		bool setupFramework(const string& sysPath = "");
		//װ�����в��
		bool loadPlugins();

		BOOL	AddWindow(string strName, HWND hWnd, __int64 pWnd = NULL);
		BOOL	RemoveWindow(HWND hWnd);
		HWND	getActiveWindowHandle();
		HWND	getWindowHandle(string strWndName);
		__int64	getWindowPtr(string strWndName);
		string	getWindowName(HWND hWnd);

		// -------------------Ӧ�ó�������� --------------- //
		void addApplicationListener(ApplicationListener* newListener);
		void removeApplicationListener(ApplicationListener* listener);


		// -------------- ������������������� ------------- //
		PluginFuncManager* getPluginFuncManager(void);
		PluginLibManager*	 getPluginLibManager();		

		//  ---------------- ͼ������� --------------------- //
		ContainerManager* createContainerManager(const string& typeName,  const string& instanceName = OC::StringUtil::BLANK);
		void destroyContainerManager(ContainerManager* sm);

		ContainerManager* getContainerManager(const string& instanceName) const;
		ContainerManagerEnumerator::ContainerManagerIterator getContainerManagerIterator(void);

		void addContainerManagerFactory(ContainerManagerFactory* fact);
		void removeContainerManagerFactory(ContainerManagerFactory* fact);

		const ContainerManagerMetaData* getContainerManagerMetaData(const string& typeName) const;
		ContainerManagerEnumerator::MetaDataIterator getContainerManagerMetaDataIterator(void) const;


		//  ------------------- ͼ�㡢Ԫ�ع����� ------------------ //
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
		void set3DRenderEngine(HWND hWnd, C3DRenderEngine* p3DRenderEngine);//��¼��ά���ӻ�����

		ContainerManager*	get2DLayerMgr(HWND hWnd);
		ElementManager*		get2DElementMgr(HWND hWnd);
		C2DRendEngine*  get2DRenderEngine(HWND hWnd);
		C3DRenderEngine*	get3DRenderEngine(HWND hWnd=NULL);//hWndΪ��ʱ�����ص�ǰ�������ά��ͼ����
		OG3DLayerManager*	get3DLayerMgr(HWND hWnd);
		OG3DElementManager*	get3DElementMgr(HWND hWnd);

		// ------------------- �Զ������ --------------------- //
		size_t	getUserDefinedObjectNum() const;
		OGUserDefinedObject*	getUserDefinedObject(size_t index);
		OGUserDefinedObject*	getUserDefinedObject(const string& typeName);
		void	__addUserDefinedObject(OGUserDefinedObject* userObject);
		void	__removeUserDefinedObject(OGUserDefinedObject* userObject);

		// ----------------- ϵͳ�������� ------------------ //
		COGEnvParamObj* getEnvParam(void);

		// ---------------------- Ӧ�ó���Ŀ¼ ------------------ //
		void setSysDirectory(const string& SysDirectory);
		string getSysDirectory(void) const;

		void setMaterialPath(string& matPath);
		string getMaterialPath();



    private:
		// ����
		void initialiseFramework(void);
		void shutdownFramework(void);		
		
	private:
		std::map<string, HWND> m_renderWndList;
		std::map<string, __int64> m_renderQtWndList;

		ContainerManager*	mContainerManager; // ���ݲ������
		ElementManager*		mElementManager;	 // ���ݲ�Ԫ�ع�����
		OG3DLayerManager*	m3DLayerManager;		 // ��ά���ݲ������
		OG3DElementManager* m3DElementManager;// ��ά���ݲ�Ԫ�ع�����
		OGDbLayerManager*	mDbLayerManager;		 // ���ݿ����ݲ������
		OGDbElementManager* mDbElementManager;// ���ݿ����ݲ�Ԫ�ع�����

		//����
		ContainerManagerEnumerator* mContainerManagerEnum;
		ContainerManagerFactory* mContainerManagerFactory;
		LayerManagerFactory* mLayerManagerFactory;
		DbLayerManagerFactory* mDbLayerManagerFactory;

		PluginFuncManager* mPluginFuncManager;   // ������ܹ�����		
		PluginLibManager* mPluginLibManager;         //����������
		BOOL	m_bLoadPlugin;

		//��Ϣת����...
		WindowMsgDispatcher* mWindowMsgDispatcher;

		typedef std::vector<ApplicationListener*> ApplicationListenerList;
		ApplicationListenerList mApplicationListenerList;

		typedef std::vector<OGUserDefinedObject*> OGUserDefinedObjectList;
		OGUserDefinedObjectList	mUserDefinedObjectList;

		//��¼�봰����صĲ���
		typedef std::map<HWND, long long> WindowParamValueList;
		WindowParamValueList		m2DLayerMgrList;
		WindowParamValueList		m2DElementMgrList;	
		WindowParamValueList		m2DRenderEngineList; //2D��Ⱦ����
		WindowParamValueList		m3DRenderEngineList; //3D��Ⱦ����
		WindowParamValueList		m3DLayerMgrList;
		WindowParamValueList		m3DElementMgrList;

		string				mSysDirectory;
		bool				mIsSetup;
		CGeo2dBaseMsgObj*	mpMsgObj;
		string				m_materialPath;
	};
	
} // namespace Smart3dMap


