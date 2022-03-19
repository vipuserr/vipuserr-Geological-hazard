 // OGElementManager.h: interface for the ElementManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGElement.h"
#include "OGElementFactory.h"
#include "OGManagerWrappers.h"

namespace Smart3dMap { 
	typedef std::map<string, Element*> ElementList;

	class OG_FRAME_DLL ElementManager : public ProductManager<Element, ElementFactory>
	{
	public:
		ElementManager();
		virtual ~ElementManager();
		
		// ���ػ��ຯ��,�����˹���ע��
		Element* create(const string& name, const OGGUID& guid);
	};
}


