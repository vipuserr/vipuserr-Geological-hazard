 // OGPluginBase.h: interface for the OGPluginBase class.
#pragma once

#include "OGObject.h"
#include "OGFunctionItemManager.h"


namespace Smart3dMap {

	// Ӧ�ò���ײ����
	class OG_FRAME_DLL PluginBase : public OGObject, public FunctionItemManager
	{
	public:
		PluginBase();
		virtual ~PluginBase();		
		
		// ȡ�ò���汾��Ϣ
		const string& getVersion();
		const string& getOgpName();

	protected:		
		string				mVersion;	// �汾
		string				mOgpName;	// �汾
	};


}