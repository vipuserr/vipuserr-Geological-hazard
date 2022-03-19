 #pragma once
#include "OGFrameWork.h"

namespace Smart3dMap
{

	class OG_FRAME_DLL PickNode 
	{
	public:
		PickNode();
		~PickNode();
		
		osg::ref_ptr<osg::Node> pick(float x,float y,osg::Vec3 world_coord);
		osg::Vec3 cvtworld2screen(osg::Vec3& world_coord);
		//FMM≤‚ ‘ÃÌº”
		bool IsPick ;
	};

}