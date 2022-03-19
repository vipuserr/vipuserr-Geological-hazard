 // OG3DLayerManager.h: interface for the OG3DLayerManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "OGContainerManager.h"


namespace Smart3dMap {
	
	
	class OG_FRAME_DLL OG3DLayerManager : public ContainerManager
	{
	public:
		OG3DLayerManager(const string& instanceName);
		~OG3DLayerManager();

		Container* create(const string& name, const OGGUID& guid);	

		void setSceneManager(SceneManager* sceneMgr);

		// ªÒ»°SceneManager
		SceneManager* getSceneManager(void) const;

		const string& getTypeName(void) const;

	private:
		SceneManager* mSceneManager;
		//SeachLight	*m_pSeachLight;
	};

	/// Factory for OG3DLayerManager
	class OG_FRAME_DLL LayerManagerFactory : public ContainerManagerFactory
	{
	protected:
		void initMetaData(void) const;
	public:
		LayerManagerFactory() {}
		~LayerManagerFactory() {}
		/// Factory type name
		static const string FACTORY_TYPE_NAME;
		ContainerManager* createInstance(const string& instanceName);
		void destroyInstance(ContainerManager* instance);

	};
}
