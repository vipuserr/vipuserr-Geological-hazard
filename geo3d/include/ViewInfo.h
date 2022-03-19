#ifndef LAYER_VIEW_INFO_CLASS_H__
#define LAYER_VIEW_INFO_CLASS_H__

#include "oe_headers.h"
#include "Og3DRE_Def.h"
#include "ogVector3.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL ViewInfo
	{
	public:
		ViewInfo(void);
		ViewInfo(OC::CVector3 position,double duration = 0.0f);
		ViewInfo(double x,double y,double z,double heading_deg,double pitch_deg,double range,double duration);
		ViewInfo(osgEarth::Viewpoint& viewpoint,double duration = 0.0f);
		~ViewInfo(void);

		OC::String toString();
		OC::String toJson();
		osgEarth::Viewpoint toViewpoint(const osgEarth::SpatialReference* srs= NULL);

		double Heading;
		double Pitching;
		double Range;
		double Duration;
		OC::CVector3 FocalPoint;
	};


}

#endif
