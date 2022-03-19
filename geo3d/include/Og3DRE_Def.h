#ifndef _OG3DRE_DEF_H__
#define _OG3DRE_DEF_H__

#ifdef _OG3D_RENDERENGINE_APP
#define _OG3D_RENDERENGINE_DLL __declspec(dllexport)
#else
#define _OG3D_RENDERENGINE_DLL __declspec(dllimport)
#endif

#ifndef _OG3D_RENDERENGINE_APP
#pragma comment(lib, "S3dRenderEngine.lib")
#endif

#include "osg_headers.h"
#include "ogVector3.h"
#include "ogColourValue.h"
#include "ThreadDefine.h"

namespace Smart3dMap
{
    class C3DRenderEngine;
    class FrameListener;
    class CSceneNode;
    class IScene;
    class ISceneImp;
    class osgEngine;
    class CSceneManager;
    class LayerManager;
	class ViewInfo;
	class WorkQueue;
	class EngineEventHandler;
    class PosterPrinter;
	class OgInformationUI;
	class OgGui;
    class ogArchive;
    class ogFeature;
    class ogTerrainEffect;
    class ogRoute;
    class ogMova;
    class ogRouteManager;
    class ogRoleNode;
    class ogTracer;
    class ogPagedLod;
    class ogFeatureNode;
    class ogFeatureManager;
    class ResourceGroupManager;
    class ogTraveler;

#define ColorToVec4(v) osg::Vec4(v.r,v.g,v.b,v.a)
#define OgSingleton(name) name::getSingleton()
#define SingletonPtr(name) name::getSingletonPtr()
}



#endif // !1

