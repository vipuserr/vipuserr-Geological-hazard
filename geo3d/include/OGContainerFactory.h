 // OGContainerFactory.h: interface for the OGContainerFactory class.
//
//////////////////////////////////////////////////////////////////////

#pragma once 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGContainer.h"
#include "OgFactoryObj.h"
#include "OGManagerWrappers.h"

namespace Smart3dMap {

	class OG_FRAME_DLL ContainerSupportFilter : public PtrMapManager<OGGUID, OGObject>
	{
	public:
		enum ContainerSupportType
		{
			LST_None = 0,			// 所有都不支持
			LST_List = 1,			// 支持列表
			LST_All = 2,			// 支持所有
			LST_FORCE_DWORD = 0x7fffFFFF,
		};
	public:
		ContainerSupportFilter();
		~ContainerSupportFilter();
		
		void setContainerSupportType(ContainerSupportType type);
		ContainerSupportType getContainerSupportType(void);

		/*
		判断是否支持某种类型
		如果mType == LST_None 返回false
            mType == LST_All  返回true
			mType == LST_List 如果List中存在, 则返回true, 否则返回false
		*/
		bool isSupport(const OGGUID& guid);	
	protected:		
		ContainerSupportType mType;		
	};

	// 生成层类对象的类工厂基类
	class OG_FRAME_DLL ContainerFactory : public FactoryObj<Container>	
	{
	public:
		ContainerFactory();
		virtual ~ContainerFactory();

		// 说明信息	
		virtual const ContainerFunction& getContainerFunction(void) { 
			return mContainerFunction; };

		// 子容器类型支持信息
		virtual const ContainerSupportFilter* getContainerChildSupportFilter(void) { 
			return &mChildSupportFilter; }

		// 容器元素类型支持信息
		virtual const ContainerSupportFilter* getElementSupportFilter(void) { 
			return &mElementSupportFilter; }

		// 判断子容器类型是否支持
		bool isSupportContainerChildType(const OGGUID& guid) {
			return mChildSupportFilter.isSupport(guid);
		}

		// 判断容器元素类型是否支持
		bool isSupportElementType(const OGGUID& guid) {
			return mElementSupportFilter.isSupport(guid);
		}

		// 自定义对象
//		virtual void setUserObject(UserDefinedObject* obj) { mUserObject = obj; }
//        virtual UserDefinedObject* getUserObject(void) { return mUserObject; }

	protected:
		ContainerFunction mContainerFunction;
		ContainerSupportFilter mChildSupportFilter;
		ContainerSupportFilter mElementSupportFilter;
//		UserDefinedObject* mUserObject;
	};
}
