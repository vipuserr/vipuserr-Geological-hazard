#ifndef _OG_LAYER_MANAGER__H_
#define _OG_LAYER_MANAGER__H_

//#include "ILayer.h"
#include "Og3DRE_Def.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL LayerManager
	{
	public:
		LayerManager(void);
		~LayerManager(void);


		osgFX::Scribe* getScribeRoot();
		CSceneNode* getFeatureRoot();
		CSceneNode* getVectorRoot();
		CSceneNode* getNode();

		IScene* getScene();
		void onChangeScene(IScene* scene);

		OC::String getApplicationDir() { return mApplicaionDir; }
		void setApplicationDir(OC::String dir) { mApplicaionDir = dir; }

		OC::String getProjectDir() { return mProjectDir; }
		void setProjectDir(OC::String dir) { mProjectDir = dir; }

		CORE_AUTO_MUTEX
	private:
		OC::String mApplicaionDir;
		OC::String mProjectDir;
		osg::ref_ptr<CSceneNode>		mLayerGroup;
		osg::ref_ptr<CSceneNode>		mFeatureRoot;
		osg::ref_ptr<CSceneNode>		mVectorRoot;
		osg::observer_ptr<IScene>	    mObCurrentScene;

		osg::ref_ptr<osgFX::Scribe>		m_pScribe;
	};
}

#endif
