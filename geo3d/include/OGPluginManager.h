 // OGPluginManager.h: interface for the PluginLibManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OgDynLibManager.h"


namespace Smart3dMap {
	// 插件管理器,负责载入关闭卸载动态库
	class OG_FRAME_DLL PluginLibManager  
	{
	private:
		PluginLibManager();
		~PluginLibManager();
		
	public:
		static PluginLibManager& getSingleton(void);
		static PluginLibManager* getSingletonPtr(void);


		// 搜索目录,并装载插件
		void loadPlugins(const string& pluginDirectory);
		
		// 关闭所有已经装载的插件
		// 允许所有的插件继续处于被装载状态, 同时做一些操作
		void shutdownPlugins();
		
		// 卸载插件
		void unloadPlugins();
		
		// 手动装载插件,必须确定他们所依赖的动态库已经被装载
		void loadPlugin(const string& pluginName);
		
		// 手动卸载插件,必须确定依赖于他们的动态库已经被卸载
		void unloadPlugin(const string& pluginName);

	protected:
		OGDynLibManager* mDynLibManager;
		std::vector<DynLib*> mPluginLibs;		
	};
	
}


