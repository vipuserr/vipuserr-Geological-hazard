 #pragma once


#include "OgBasDef.h"

namespace Smart3dMap 
{
    struct FrameEvent
    {
  
        Real timeSinceLastEvent;
        Real timeSinceLastFrame;
    };


    class OG_FRAME_DLL FrameListener
    {
    public:
        virtual bool frameStarted(const FrameEvent& evt)
        { (void)evt; return true; }

		virtual bool frameRenderingQueued(const FrameEvent& evt)
                { (void)evt; return true; }

        virtual bool frameEnded(const FrameEvent& evt)
        { (void)evt; return true; }

		virtual ~FrameListener() {}
		
    };
	/** @} */
	/** @} */
}