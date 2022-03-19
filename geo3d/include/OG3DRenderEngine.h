#ifndef _OG3DRENDERENGINE_CLASS_H__
#define _OG3DRENDERENGINE_CLASS_H__

#include <osg/MatrixTransform>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>
#include <osgViewer/api/win32/GraphicsWindowWin32>
#include <osgGA/TrackballManipulator>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgDB/DatabasePager>
#include <osgDB/Registry>
#include <osgDB/ReadFile>
#include <osgUtil/Optimizer>
#include <osg/LightModel>
#include <osg/View>
#include <osgFX/Scribe>
#include <osg/ComputeBoundsVisitor>

#include <map>
#include <string>
using namespace std;

#include "Og3DRE_Def.h"
#include "FrameListener.h"
#include "OGPosterPrinter.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL C3DRenderEngine
	{
	public:
		//构造函数获取上一级窗口句柄
		C3DRenderEngine();
		virtual ~C3DRenderEngine();

		/** Set of registered frame listeners */
		FrameListenerSet	mFrameListeners;

		/** Set of frame listeners marked for removal*/
		FrameListenerSet	mRemovedFrameListeners;
		WorkQueue*			mWorkQueue;
	public:
		void setWnd(HWND hWnd);

		bool renderOneFrame();
		WorkQueue* getWorkQueue() { return mWorkQueue; }
		osg::Camera* getCamera();

		//初始化渲染引擎
		void initRenderEngine();


		//即将去除的接口
		osg::MatrixTransform* getMatrixNode();

		//depracate
		void initSceneGraph() {}
		void setInputMode(short lInputMode = 0) {}
		osg::Group* getPlatRootNode() { return NULL; }
		osg::Group* getGlobeRootNode() { return NULL; }
		void setDone(bool value) {}
		bool getDone(void) { return true; }
		void preFrameUpdate() {}
		void postFrameUpdate() {}
		void ShowImageLayer(OC::String strImgLayer) {}
		void HideImageLayer(OC::String strImgLayer) {}
		void AddVetorData(OC::String strVectorPath) {}
		void StartRenderModle() {}
		void EndRenderModle() {}
		void setStartPick(bool pIsStartPcik) {}
		bool getStartPick() { return true; }
		void setPlatInputMode(short lInputMode) {}
		void setGlobalInputMode(short lInputMode) {}
		void addLabel() {}
		void releasePlatSceneNode() {}
		void releaseGlobalSceneNode() {}
		void setEarthFilePath(OC::String strEarthPath) {}
		void getEarthFilePath(OC::String& strEarthPath) {}
		void toogleInputMode() {}
		void setCovertCoord(bool pIsStartCovertCoord) {}
		void getCurrentCoord(osg::Vec3d* pVecd) {}
		bool getCovertCoord() { return true; }
		void setDoublePickMode(bool p_DoublePick) {}
		bool getDoublePickMode() { return true; }
		bool setModelTranSparent(osg::Node* pSceneNode, float mVaule);
		void initCameraConfig() {}
		long getInputMode(bool &IsGlobe, short &lInputMode) { return 1; }
		void ChangeDiffClrNew(osg::Vec4f diffclr) {}
		void ChangeDiffClr(float r, float g, float b, float a) {}
		void ChangeDiffClr(osg::Vec4f diffclr) {}
		void ChangeWirlClr(float r, float g, float b, float a) {}
		osg::Group* createLight(osg::Node*  pNode) { return NULL; }
		bool getOffsetFlag(){return true;}
		osg::Vec3 getOffset(){return osg::Vec3(0,0,0);}
		void setOffset(osg::Vec3 offset){}
	public:
		void setDisPlayScale(osg::Node* node, osg::Vec3 scale);
		void ChangeBlackCLr(float r, float g, float b, float a);
		osg::Vec3 getScaleFactor();
		void setScaleFactor(osg::Vec3 scale);
	private:
		osg::Vec4f m_blackclr;
		osg::Vec4f m_WirlFramclr;
		osg::Vec4f m_diffusemclr;
		osg::Vec3 m_offset;
		bool m_bIsOffset;
		osg::Vec3 m_scaleFactor;
	private:
		HWND m_hWnd;
		osg::GraphicsContext* mGraphicsContext;
		osgEngine* mEngine;
		OgGui*		   mGui;
		LayerManager*  mLayerManager;
		CSceneManager* mSceneManager;
		ogFeatureManager* mFeatureManager;
		EngineEventHandler* mEngineEventHandler;
		ResourceGroupManager* mResourceGroupManager;
		bool _fireFrameStarted();
		bool _fireFrameEnded();
	public:
		void changeScene(OC::String sceneType);
		LayerManager*  getLayerManager() { return mLayerManager; }
		CSceneManager* getSceneManager() { return mSceneManager; }
		ogFeatureManager* getFeatureManager() { return mFeatureManager; }
		OgGui*		   getGui() { return mGui; }
		//高分辨率图片输出
		void HighResolutionOutput(int posterHeight, int posterWidth, OC::String posterName);
		void addFrameListener(FrameListener* newListener);
		void removeFrameListener(FrameListener* oldListener);
		void setContext(osg::GraphicsContext* context);
        osg::ref_ptr<PosterPrinter>     mPrinter;
        osgViewer::Viewer* getViewer();
	};
}

#endif
