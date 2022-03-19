#pragma once

#include "OGBasDef.h"
#include "s3d_SimpleMesh.h"
#include <osg/Geode>

#include "OG3DRenderEngine.h"


namespace Smart3dMap{


	class OG_FRAME_DLL OGPickCls
	{
	private:
		OGPickCls(void);
		virtual~OGPickCls(void);
	public:
		static void StartPickCoor(C3DRenderEngine* p3dRE);//需要穿一个参数...
		static void GetPickCoord(C3DRenderEngine* p3dRE, osg::Vec3d* pVec);
		static void EndPickCoor(C3DRenderEngine* p3dRE);
	};

	bool OG_FRAME_DLL getSceneNodeBoundBox(SceneNode* pScnenNode,AxisAlignedBox& pSceneBox);
	osg::ref_ptr<osg::Geode> OG_FRAME_DLL MeshCreateSurfaceGeode(OGSimpleMesh* pSimpleMesh,bool AppendCutSurf);
	osg::ref_ptr<osg::Geode> OG_FRAME_DLL MeshCreateSurfaceSkipGeode(OGSimpleMesh* pSimpleMesh,bool AppendCutSurf);
	osg::ref_ptr<osg::Geode> OG_FRAME_DLL MeshCreateCubeDotGeode(OGSimpleMesh* pSimpleMesh,double CubeLenght);
	osg::ref_ptr<osg::Geode> OG_FRAME_DLL MeshCreateSphereDotGeode(OGSimpleMesh* pSimpleMesh,double SphereRadius);
	osg::ref_ptr<osg::Geode> OG_FRAME_DLL MeshCreateLineSkipGeode(OGSimpleMesh* pSimpleMesh,double LineSkipLenght);
}

