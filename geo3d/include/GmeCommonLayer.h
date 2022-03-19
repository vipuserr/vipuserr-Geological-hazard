#pragma once
#include "OG3DLayer.h"
#include "OGGme3DLayerGuid.h"
#include "layerplugin_geo3d_global.h"

class OSG_ChangeStateset;

namespace Smart3dMap
{
	
	class LAYERPLUGIN_GEO3D_EXPORT GmeCommonLayer :public OG3DLayer
	{
	public:
		GmeCommonLayer(const string& name, const OGGUID& guid);
		~GmeCommonLayer();

		//√¸¡Ó”≥…‰
		virtual void registerFunctions(void);
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);

		virtual void setVisible(bool visible, bool cascade = true);
	protected:
		osg::ref_ptr<osgViewer::Viewer> m_viewer;
		osg::ref_ptr<osg::Camera> m_camera;

		bool m_bFirstVisible;
		osg::Vec3 m_sacleFactor;

		C3DRenderEngine		*m_p3DRenderEngine;
		OSG_ChangeStateset  *m_changeStateset;  //_Vei

	};
	COMMON_LAYLER_FACTORY(GmeCommonLayer, GME_COMMON_LAYER_GUID, "GMEπ´π≤¿‡");
}


