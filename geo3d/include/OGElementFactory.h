 // OGElementFactory.h: interface for the ElementFactory class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGFactoryObj.h"

namespace Smart3dMap {

	// ���ɲ�Ԫ�ض�����๤������
	class OG_FRAME_DLL ElementFactory : public FactoryObj<Element>   
	{
	public:
		ElementFactory();
		virtual ~ElementFactory();

		// ˵����Ϣ
		virtual const ContainerFunction& getContainerFunction(void) { 
			return mContainerFunction; };

	protected:
		ContainerFunction mContainerFunction;
	};

}


