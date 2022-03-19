#ifndef _OGTRACER_CLASS_H__
#define _OGTRACER_CLASS_H__

#include "FrameListener.h"
#include "oe_headers.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL ogTracer : public FrameListener
	{
	public:
		ogTracer(osgEarth::Util::EarthManipulator* manipulator,const osgEarth::SpatialReference* srs);
		~ogTracer(void);

		virtual void frameStarted(void);
		virtual void frameEnded(void);

		void onMove(OC::CVector3 position);

		ogMova* getTarget();
		void setTarget(ogMova* node);

		void setRange(double range,bool valid = true);
		double getRange();

		void setPitch(double pitch,bool valid = true);
		double getPitch();

		void setHead(bool head,bool valid = true);
		double getHead();

		void reset();

		void setFreeControl(bool isFree);
		bool getFreeControl();

		void setHeadFollow(bool isFollow);
		bool getHeadFollow();

		//CEventLayer* getEventLayer();
		//CEventLayer* getOrCreateEventLayer();
		//void removeEventLayer();

		//void setEventListening();

		void setFixVR(bool vr){mVRMode = true;}
	protected:
		typedef std::pair<double,bool> TraceParam;
		bool												mVRMode;
		bool												mEventActive;
		bool												mIsFollowHead;
		bool												mFirstFrame;
		bool												mFreeControl;
		OC::CVector3											mDirection;
		OC::CVector3											mLastPosition;
		TraceParam											mRange;
		TraceParam											mPitch;
		TraceParam											mHead;
	private:
		bool												mRunning;
		osgEarth::Viewpoint									mLastViewpoint;
		//osg::ref_ptr<CEventLayer>							mEventLayer;
		osg::observer_ptr<ogMova>					mTraceNode;
		const osgEarth::SpatialReference*				mSpatialReference;
		osg::observer_ptr<osgEarth::Util::EarthManipulator>	mEarthManipulator;
	};
}


#endif

