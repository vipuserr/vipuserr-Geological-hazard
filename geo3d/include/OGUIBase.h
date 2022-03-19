 #pragma once

#include "OGObject.h"
#include "OGFunctionItemManager.h"


namespace Smart3dMap {	

	
	//UI交互界面插件基类
	class OG_FRAME_DLL CUIBase
	{
	public:
		CUIBase(HWND hWnd);
		virtual ~CUIBase();		
		
		// 取得插件版本信息
		const string& getVersion();

		//基本消息函数，返回1表示已经处理成功，将不会再处理
		virtual long onLButtonDown(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onLButtonUp(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onRButtonUp(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onMouseMove(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onKeyDown(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onMouseWheel(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onRButtonDblClk(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onRButtonDown(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onLButtonDblClk(WPARAM wParam, LPARAM lParam) { return 0; };

		virtual long onCommond(WPARAM wParam, LPARAM lParam) { return 0; };
	protected:		
		string				mVersion;	// 版本		
		HWND				mhWnd;
	};

	//交互操作插件基类
	class OG_FRAME_DLL CInputBase : public OGObject
	{
		public:
			CInputBase();
			CInputBase(HWND hWnd,SceneManager* SceneMgr, Smart3dMap::Camera* Camera);
			virtual ~CInputBase();		
		public:
			//交互消息
			virtual long onKeyDown(WPARAM wParam, LPARAM lParam);
			virtual long onKeyUp(WPARAM wParam, LPARAM lParam);
			virtual long onLButtonDblClk(WPARAM wParam, LPARAM lParam);
			virtual long onLButtonDown(WPARAM wParam, LPARAM lParam);
			virtual long onLButtonUp(WPARAM wParam, LPARAM lParam);
			virtual long onMButtonDblClk(WPARAM wParam, LPARAM lParam);
			virtual long onMButtonDown(WPARAM wParam, LPARAM lParam);
			virtual long onMButtonUp(WPARAM wParam, LPARAM lParam);
			virtual long onMouseMove(WPARAM wParam, LPARAM lParam);
			virtual long onMouseWheel(WPARAM wParam, LPARAM lParam);
			virtual long onRButtonDblClk(WPARAM wParam, LPARAM lParam);
			virtual long onRButtonDown(WPARAM wParam, LPARAM lParam);
			virtual long onRButtonUp(WPARAM wParam, LPARAM lParam);

			virtual void onActive();
			virtual void onDisActive();
			virtual void onSetup();
			//通知相机位置已经改变
			virtual void notify(Vector3& Pos,Vector3& Dir);

			const string& getType() { return mType; }
			
			//获取说明
			const string& getDescription() { return mDescription; }
			//复位
			virtual void reset();
			//设置包围盒
			virtual void setBoundingBox(const AxisAlignedBox& aabb);
			virtual void setAutoMode(bool autoMode);
			//飞行跳转
			virtual void FlyTo(Vector3& Pos,DWORD dwFlyMode){};
			virtual void JumpTo(Vector3& Pos,DWORD dwFlyMode){};

			//窗口WM_SIZE消息
			virtual void onSize(WPARAM wParam, LPARAM lParam)
			{
				mClientWidth = LOWORD(lParam);
				mClientHeight = HIWORD(lParam);
			}
			
			void updateTargetWindow();

			//取参数
			SceneManager* getSceneManager() { return mSceneMgr; }
			Smart3dMap::Camera* getCamera() { return mCamera; }
			HWND getTargetWindowHandle() { return mTargetWindow; }

			//消息通知
			long _OnMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

		protected:
			int mClientWidth; //窗口大小
			int mClientHeight; 
			string mType; //交互类型
			//string mDescription; //交互描述
			//string mInputClsName; //交互名称,要求唯一
			AxisAlignedBox		mAABox;

		protected:
			SceneManager* mSceneMgr;
			Smart3dMap::Camera* mCamera;
			HWND mTargetWindow;
			string				mVersion;	// 版本		
		
		protected:
			POINT getPoint(LPARAM lParam)
			{
				POINT pt;

				pt.x = LOWORD(lParam);  // horizontal position of cursor 
				pt.y = HIWORD(lParam);  // vertical position of cursor 
				
				return pt;
			}
	};


}