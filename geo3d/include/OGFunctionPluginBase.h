 
#pragma once


#include "OGPluginBase.h"


namespace Smart3dMap {	
	// 将参数转化为点
	inline POINT PARAM_TO_POINT(LPARAM lParam) {POINT pt; pt.x = LOWORD(lParam); pt.y = HIWORD(lParam); return pt; }

	class OG_FRAME_DLL FunctionPluginBase : public PluginBase
	{
	public:
		FunctionPluginBase();
		virtual ~FunctionPluginBase();

		virtual long onLButtonDown(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onLButtonUp(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onRButtonUp(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onMouseMove(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onKeyDown(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onMouseWheel(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onRButtonDblClk(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onRButtonDown(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onLButtonDblClk(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual long onCommond(OGWorkContext* pContext, WPARAM wParam, LPARAM lParam) { return 1; };

		virtual BOOL begin(LPARAM lParam = 1) { return 1; };

		virtual BOOL end(LPARAM lParam = 1) { return 1; };

		virtual BOOL defaultWndProc(OGWorkContext* pContext, UINT nMsg, __int64 wParam, __int64 lParam) { return 1; };
		
		virtual void renderGraph(OGWorkContext* pContext) { };

		virtual void renderGraph2D(OGWorkContext* pContext) { };

		virtual void setup() { };		
	};


	
	// 功能插件管理器
	class OG_FRAME_DLL PluginFuncManager
	{
	private:
		PluginFuncManager();
		virtual ~PluginFuncManager();		
			
	public:
		typedef std::map<string, FunctionPluginBase*> FunctionPluginList;		
		typedef MapIterator<FunctionPluginList> FunctionPluginIterator;		

		// 添加插件功能
		BOOL addFunctionPlugin(FunctionPluginBase* pFunctionPlugin);
		FunctionPluginBase*	getFunctionPlugin(const string& strName);
		// 删除插件功能
		void removeFunctionPlugin(FunctionPluginBase* pFunctionPlugin);
		void removeFunctionPlugin(const string& strName);
		// 取出编辑插件个数
		const size_t getNumFunctionPlugins(void);

		// 直接启动插件的功能项
		// 返回 0 成功 
		// 返回 1 失败
		// 返回 2 未找到对应的功能项
		long executePluginFunc(const string& strPluginsName, 
			UINT nFuncPosition, WPARAM wParam, LPARAM lParam);

		long executePluginFunc(FunctionPluginBase* pFunctionPlugin, 
			UINT nFuncPosition, WPARAM wParam, LPARAM lParam);	

		long executePluginFunc(const string& strPluginsName, 
			const string& funcName, WPARAM wParam, LPARAM lParam);

		// 返回编辑插件列表迭代器
        FunctionPluginIterator getFunctionPluginIterator(void) 
		{
            return FunctionPluginIterator(mFunctionPlugins.begin(), mFunctionPlugins.end());
        }
		
		static PluginFuncManager& getSingleton(void);
        static PluginFuncManager* getSingletonPtr(void);

	protected:

		FunctionPluginList mFunctionPlugins;	
	};
}