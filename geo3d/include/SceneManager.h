#ifndef _OG_SCENEMANAGER_H__
#define _OG_SCENEMANAGER_H__

#include "IScene.h"
//#include "OCBase/BaseEvents.h"
#include "Og3DRE_Def.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL CSceneManager
	{
	public:
		CSceneManager(C3DRenderEngine* engine);
		~CSceneManager(void);
		
		void setScene(IScene* scene);
		IScene* getScene(OC::String type);
		IScene* getCurrentScene();
		
		void registerScene(IScene* scene);

		void onChangeScene();
		bool changeScene(OC::String type);
		void closeScene();

		//void setSceneChangeEvent(CSceneChangeListener* sceneEvent);
		//CSceneChangeListener* getSceneChangeEvent();

		/*
		* Ìø×ª
		*/
		void setViewInfo(ViewInfo viewinfo);
		ViewInfo getViewInfo();

		typedef std::map<OC::String,osg::ref_ptr<IScene> > SceneMap;

        ogTraveler* createTravel();
	private:
		bool															mOnChanging;
		IScene*														mCurrentScene;
		SceneMap												mScenes;
		C3DRenderEngine*								m3DEngine;
		//CSceneChangeListener*							mSceneChangeEvent;
		//std::pair<bool,ViewInfo>							mJumpingViewPoint;
	};

}

#endif
