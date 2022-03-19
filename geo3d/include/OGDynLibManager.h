 // OGDynLibManager.h: interface for the OGDynLibManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGDynLib.h"


namespace Smart3dMap{
    // Smart3dMap��̬�������
	class OG_FRAME_DLL OGDynLibManager
	{	
    public:        
        OGDynLibManager();
        ~OGDynLibManager();

        // ���붯̬��
        DynLib* load(const string& filename);

		// ж�ض�̬��
		void unload(DynLib* lib);
	protected:
		typedef std::map<string, DynLib*> DynLibList;
		DynLibList mLibList;
	};

} // namespace Smart3dMap

