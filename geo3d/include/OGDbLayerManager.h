 // OGDbLayerManager.h: interface for the OGDbLayerManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGContainerManager.h"
#include "OGBasDef.h"

namespace Smart3dMap {
	
	
	class OG_FRAME_DLL OGDbLayerManager : public ContainerManager
	{
	public:
		OGDbLayerManager(const string& instanceName);
		~OGDbLayerManager();

		Container* create(const string& name, const OGGUID& guid);	

		void setSceneManager(SceneManager* sceneMgr);

		// ªÒ»°SceneManager
		SceneManager* getSceneManager(void) const;

		const string& getTypeName(void) const;

	private:
		SceneManager* mSceneManager;
	
	};

	/// Factory for OGDbLayerManager
	class OG_FRAME_DLL DbLayerManagerFactory : public ContainerManagerFactory
	{
	protected:
		void initMetaData(void) const;
	public:
		DbLayerManagerFactory() {}
		~DbLayerManagerFactory() {}
		/// Factory type name
		static const string FACTORY_TYPE_NAME;
		ContainerManager* createInstance(const string& instanceName);
		void destroyInstance(ContainerManager* instance);

	};
}
