#ifndef _ISCENE__H_
#define _ISCENE__H_

#include "SceneNode.h"
#include "ViewInfo.h"
#include "SkyBox.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL IScene : public CSceneNode
	{
	public:
		const static OC::String SC_Default;
		const static OC::String SC_Geocentric;
		const static OC::String SC_Projected;

		IScene();
		virtual ~IScene();

		virtual bool init() { return false; }

		virtual void clear() {}
		virtual void onShow() {}

		virtual osgEarth::MapNode* getMapNode() { return NULL; }

		virtual ISceneImp* asSceneImp() { return NULL; }

		virtual const osgEarth::Profile* getProfile() { return NULL; }

		virtual osgEarth::ImageLayer* getMainImageLayer() { return NULL; }
		//virtual IDrawTool* startDrawVector(CVectorNode* vector,CVectorLayer* layer = NULL){return NULL;}
		//virtual IDrawTool* getDrawTool(){return NULL;}
		//virtual IPickTool* getPickTool(){return NULL;}
		virtual osgViewer::View* getView() { return NULL; }

		virtual bool getElevationAt(double coordX, double coordY, double& elevation);

		virtual void setViewInfo(ViewInfo viewinfo){}
		virtual ViewInfo getViewInfo() { return ViewInfo(); }
		//	/*
		//	* 矢量
		//	*/
		//	virtual void endDraw(){}

		/*
		* 天空盒
		*/
		virtual void setSkyBoxOn(){}
		virtual void setSkyBoxOff(){}

		//	/*
		//	* 拾取
		//	*/
		//	virtual void startPick(){}
		//	virtual void endPick(){}

		//	virtual void startTravel(){}
		//	virtual void endTravel(){}
		//	
		//	virtual void startHighlightZone(){}
		//	virtual void endHighlightZone(){}

		//	virtual void startTerrainGrub(){}
		//	virtual void endTerrainGrub(){}
		//	virtual void clearTerrainGrub(){}
		//	
		//	virtual void showTerrainBlendTool(){}

		virtual OC::String getSceneType();

		//	virtual ITool* getCaptureTool();

		//	CSkyBox* getSkyBox();
		virtual ogTracer* getTracer(){return NULL;}

		//	virtual IDrawTool* startDrawTool(OC::String toolclass){return NULL;}
		//	virtual void start_tool(OC::String tool_name){}

        virtual osgEarth::Layer* addTerrainHole(OC::String polygonWKT){return NULL;}
        virtual void removeLayer(osgEarth::Layer* layer){}
        virtual void setTransparent(float alpha) {}

	protected:
		double									query_resolution = 0.1; // 1/10th of a degree
		osg::ref_ptr<CSkyBox>					mSkyBox;
	};
}


#endif
