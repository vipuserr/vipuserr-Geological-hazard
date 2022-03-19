#ifndef _FRAME_LISTENER__H_
#define _FRAME_LISTENER__H_

#include "Og3DRE_Def.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL FrameListener : public osg::Referenced
	{
	public:
		FrameListener(void);

		virtual ~FrameListener(void);

		//META_Object(OC,FrameListener);
		//FrameListener(const FrameListener& eh,const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY):
		//osg::Object(eh, copyop){}

		virtual void frameStarted(void) {}
		virtual void frameEnded(void) {}
	};
	typedef std::set<osg::observer_ptr<FrameListener> > FrameListenerSet;
	typedef std::vector<osg::observer_ptr<FrameListener> > FrameListenerList;
}

#endif
