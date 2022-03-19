 // OGPluginBase.h: interface for the OGPluginBase class.
#pragma once

#include "OGObject.h"
#include "OGFunctionItemManager.h"


namespace Smart3dMap {

	// 应用插件底层基类
	class OG_FRAME_DLL PluginBase : public OGObject, public FunctionItemManager
	{
	public:
		PluginBase();
		virtual ~PluginBase();		
		
		// 取得插件版本信息
		const string& getVersion();
		const string& getOgpName();

	protected:		
		string				mVersion;	// 版本
		string				mOgpName;	// 版本
	};


}