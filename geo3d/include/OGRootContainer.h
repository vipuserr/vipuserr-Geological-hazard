 
#pragma once

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGContainer.h"
#include "OGContainerFactory.h"

static string OG_ROOT_CONTAINER_GUID = "{90FC801B-47FA-4017-8DA3-CD841BBE474A}";
//  [10/23/2014 Feng]
static string OG_TOPROOT_CONTAINER_GUID = "{2A470068-7D43-4a60-A75B-B14ADDF55054}";
//  [10/23/2014 Feng]
namespace Smart3dMap {

	class OG_FRAME_DLL RootContainer : public Container
	{
	public:
		RootContainer(const string& name, const OGGUID& guid);
		~RootContainer();

		bool load(DataElement* element);
		bool save(DataElement* element);	
		
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);		
		virtual void registerFunctions(void);
	};

	class OG_FRAME_DLL RootContainerFactory : public ContainerFactory
	{
	public:
		RootContainerFactory() { }
		virtual ~RootContainerFactory() { }
		
        virtual const string& getType() const { 
			static OGGUID strGuid = OG_ROOT_CONTAINER_GUID;
			return strGuid;
		};
        
        virtual Container* createInstance( const string& name ) {			
			RootContainer* pContainer = new RootContainer(name, OG_ROOT_CONTAINER_GUID);			
			return (Container*)pContainer;
        }
        
        virtual void destroyInstance( Container* pContainer ) {			
			OG_DELETE(pContainer);
		}

		virtual const ContainerFunction& getContainerFunction(void){
			static ContainerFunction fContainerFunc;
			fContainerFunc.name = "根容器";
			fContainerFunc.desc = "管理子容器";
			return fContainerFunc;
		}
	};

}


