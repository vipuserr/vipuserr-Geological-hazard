 // OGDynLibManager.h: interface for the OGDynLibManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGDynLib.h"


namespace Smart3dMap{
    // Smart3dMap动态库管理器
	class OG_FRAME_DLL OGDynLibManager
	{	
    public:        
        OGDynLibManager();
        ~OGDynLibManager();

        // 载入动态库
        DynLib* load(const string& filename);

		// 卸载动态库
		void unload(DynLib* lib);
	protected:
		typedef std::map<string, DynLib*> DynLibList;
		DynLibList mLibList;
	};

} // namespace Smart3dMap

