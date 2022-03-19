 // OGElementManager.h: interface for the ElementManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGDbElement.h"
#include "OGManagerWrappers.h"

namespace Smart3dMap { 
	class OG_FRAME_DLL OGDbElementManager : public ProductManager<OGDbElement, OGDbElementFactory>
	{
	public:
		OGDbElementManager();
		virtual ~OGDbElementManager();
		
		// ���ػ��ຯ��,�����˹���ע��
		OGDbElement* create(const string& name, const OGGUID& guid);
	};
}


