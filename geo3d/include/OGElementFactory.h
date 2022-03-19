 // OGElementFactory.h: interface for the ElementFactory class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGFactoryObj.h"

namespace Smart3dMap {

	// 生成层元素对象的类工厂基类
	class OG_FRAME_DLL ElementFactory : public FactoryObj<Element>   
	{
	public:
		ElementFactory();
		virtual ~ElementFactory();

		// 说明信息
		virtual const ContainerFunction& getContainerFunction(void) { 
			return mContainerFunction; };

	protected:
		ContainerFunction mContainerFunction;
	};

}


