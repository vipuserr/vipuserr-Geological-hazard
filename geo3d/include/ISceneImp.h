#ifndef _OG_ISCNE_IMP_H__
#define _OG_ISCNE_IMP_H__

#include "oe_headers.h"
#include "IScene.h"
#include "BaseNodeMask.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL ISceneImp : public IScene
	{
	public:
		typedef std::vector<osg::ref_ptr<osg::Light> > SceneLights;
		static OC::String BaseLayerName;

		ISceneImp(C3DRenderEngine* engine);
		virtual ~ISceneImp(void);

		virtual ISceneImp* asSceneImp(){return static_cast<ISceneImp*>(this);}
		virtual OC::String getSceneType(){return ISceneImp::SC_Default;}

		virtual	bool init();

		virtual	void clear();
		virtual	void onShow();

		virtual osgEarth::MapNode* getMapNode();
		virtual void setViewInfo(ViewInfo viewinfo);
		virtual ViewInfo getViewInfo();
		//virtual void endDraw();

		//virtual IDrawTool* startDrawVector(CVectorNode* vector,CVectorLayer* layer = NULL);

		virtual void setSkyBoxOn();
		virtual void setSkyBoxOff();

		//virtual void startPick();
		//virtual void startPickTerrain();
		//virtual void endPick();

		//virtual void startTravel();
		//virtual void endTravel();

		//virtual void startHighlightZone();
		//virtual void endHighlightZone();
		//
		//virtual void startTerrainGrub();
		//virtual void endTerrainGrub();
		//virtual void clearTerrainGrub();

		//virtual void showTerrainBlendTool();

		//virtual void startFirstRole();
		//virtual void endFirstRole();

		//virtual void start_tool(OC::String tool_name);

		//virtual void setViewInfo(ViewInfo viewinfo);
		//virtual ViewInfo getViewInfo();

		//virtual ITool*					getCaptureTool();
		//virtual ITool*					getCurrentTool();
		//virtual IPickTool*				getPickTool();
		//virtual IDrawTool*				getDrawTool();
		//virtual TerrainGrubTool*		getTerrainGrubTool();
		//virtual CFirstPersonContrl*		getFirstPersonContrl();
		//virtual TerrainEffectBlender*	getTerrainEffectBlender();
		virtual osgViewer::View* getView();

		osg::ref_ptr<osgEarth::Util::EarthManipulator>		mEarthManipulator;

        virtual ogTracer* getTracer();
		//
		//virtual IDrawTool* startDrawTool(OC::String toolclass);

		virtual void setAmient(OC::ColourValue color);
		virtual void setDiffuse(OC::ColourValue color);
		virtual void setSpecular(OC::ColourValue color);
		SceneLights getSceneLight(){return mSceneLights;}
	protected:
		bool									mInitialized;
		//osg::ref_ptr<ITool>						mCurrentTool;
		//osg::ref_ptr<IPickTool>					mPickTool;
		//osg::ref_ptr<IDrawTool>					mMouseDrawTool;
		//osg::ref_ptr<CCaptureTool>				mCaptureTool;
		osg::ref_ptr<ogTracer>			mOGTracer;
		//osg::ref_ptr<TerrainGrubTool>			mTerrainGrubTool;
		//osg::ref_ptr<ZoneHighlightTool>			mZoneHighlightTool;
		//osg::ref_ptr<PathTravelEditor>			mPathTravelEditor;
		osg::ref_ptr<osgEarth::MapNode>			mMapNode;
		//osg::ref_ptr<TerrainBlenderTool>		mTerrainBlenderTool;
		//osg::ref_ptr<CFirstPersonContrl>		mFirstPersonContrl;
		//osg::ref_ptr<TerrainEffectBlender>		mTerrainEffectBlender;
		osg::observer_ptr<osgViewer::Viewer>		mView;
		osg::ref_ptr<const osgEarth::Profile>	mProfile;

		osg::Light* createDefaultLight();
		void setHome(OC::CVector3 position);
		void setHome(OC::CVector3 position,double range,double heading,double pitching);
		
		SceneLights	mSceneLights;

		C3DRenderEngine* m3DEngine;
	};
}
#endif
