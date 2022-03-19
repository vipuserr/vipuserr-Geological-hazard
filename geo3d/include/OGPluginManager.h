 // OGPluginManager.h: interface for the PluginLibManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OgDynLibManager.h"


namespace Smart3dMap {
	// ���������,��������ر�ж�ض�̬��
	class OG_FRAME_DLL PluginLibManager  
	{
	private:
		PluginLibManager();
		~PluginLibManager();
		
	public:
		static PluginLibManager& getSingleton(void);
		static PluginLibManager* getSingletonPtr(void);


		// ����Ŀ¼,��װ�ز��
		void loadPlugins(const string& pluginDirectory);
		
		// �ر������Ѿ�װ�صĲ��
		// �������еĲ���������ڱ�װ��״̬, ͬʱ��һЩ����
		void shutdownPlugins();
		
		// ж�ز��
		void unloadPlugins();
		
		// �ֶ�װ�ز��,����ȷ�������������Ķ�̬���Ѿ���װ��
		void loadPlugin(const string& pluginName);
		
		// �ֶ�ж�ز��,����ȷ�����������ǵĶ�̬���Ѿ���ж��
		void unloadPlugin(const string& pluginName);

	protected:
		OGDynLibManager* mDynLibManager;
		std::vector<DynLib*> mPluginLibs;		
	};
	
}


