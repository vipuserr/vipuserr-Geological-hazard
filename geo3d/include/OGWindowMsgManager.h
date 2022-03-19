 
#pragma once

#include "OGPluginBase.h"




namespace Smart3dMap{

	class	CInputBase;
	class OG_FRAME_DLL WindowMsgDispatcher
	{
		friend class PluginFuncManager;
	private:
		WindowMsgDispatcher();
		virtual ~WindowMsgDispatcher();

	public:
		// 添加
		long addWnd(HWND hWnd, Smart3dMap::Viewport* pViewPort,bool b3DView);
		long addWnd(HWND hWnd, bool bHisView);
		void removeWnd(HWND hWnd);
		// 删除所有Frame
		void removeAllWnds(void);
		// 设置当前活动应用
		BOOL setActiveWnd(HWND hWnd);
		HWND getActiveWnd(void);	
		
		//添加删除交互对象
		long		AddInputBase(HWND hWnd,CInputBase* pUIBase);
		long		RemoveInputBase(HWND hWnd,const std::string& sInputClsName);
		long		ActiveInputCls(HWND hWnd,const std::string& sInputClsName);
		bool		ExistInputBase(HWND hWnd,const std::string& sInputClsName);
		CInputBase*		GetActiveInputCls(HWND hWnd);

		bool isEnabled() const { return mEnabled; }
		void setEnabled(bool enabled) { mEnabled = enabled; }
		long _routeMessage(OGWorkContext& context, UINT Msg, WPARAM wParam, LPARAM lParam);
		static WindowMsgDispatcher& getSingleton(void);
        static WindowMsgDispatcher* getSingletonPtr(void);		
		
		long  GetOGWorkContext(HWND hWnd,OGWorkContext& twcontext);
	public:		
		SubFrame* getSubFrame(HWND hWnd);
		SubFrame* getActiveSubFrame(void);	
		HWND mActiveWnd;
		bool mEnabled;		
	};

}