#ifndef _OGROUTEMANAGER_CLASS_H__
#define _OGROUTEMANAGER_CLASS_H__

#include "ThreadDefine.h"
#include "ogRoute.h"
#include "OGTinyxml.h"

namespace Smart3dMap
{
    enum MovableFinishState
    {
        Stay_Feature_Position,
        Stay_Start_Point,
        Stay_End_Point,
        Wait_For_Next_Point,
        Disappear
    };

	struct ogMovableFrame
	{
		bool		    Finished;
		OC::String		AnimeState;
		OC::CVector3	Offset;
		OC::CVector3	Position;
		OC::CVector3	Direction;

		inline ogMovableFrame& operator = ( const ogMovableFrame& frame )
		{
			Offset	   = frame.Offset;
			Position   = frame.Position;
			Finished   = frame.Finished;
			Direction  = frame.Direction;
			AnimeState = frame.AnimeState;
			return *this;
		}
	};

	class _OG3D_RENDERENGINE_DLL ogRouteManager : public osg::Referenced
	{
	public:
		ogRouteManager();
		~ogRouteManager();

		//
		void setDirty();
		void update();

		void setSampler(osgAnimation::Vec3LinearSampler* sampler);
		osgAnimation::Vec3LinearSampler* getSampler();

		bool initRoute();

		ogMovableFrame getFrameAt(double time,bool getState = false);
		ogRoute* getRouteAtTime(double time);

		ogMovableFrame getFirstFrame();
		ogMovableFrame getFinalFrame();
		ogMovableFrame getFinishFrame();

		void addRoute(ogRoute route);
		void clearRoute();
		void setRouteList(MovableRouteList routeList);
		int getNumRoute();
		ogRoute getRoute(int index);

		void setDefaultSpeed(double speed);
		double getDefaultSpeed();

		double getDuration();

		void setLoopNum(int num);
		int getLoopNum();

		void setOffsetHeight(double offset);
		double getOffsetHeight();

		void setFinishState(MovableFinishState state);
		MovableFinishState getFinishState();

		void fromXmlFile(OC::String filename);
		void toXmlFile(OC::String filename);

		void fromXmlString(OC::String xmlString);
		OC::String toXmlString();
	private:
		void parse(TiXmlDocument& doc);
		void serialize(TiXmlDocument& doc);
	private:
		int												mLoop;
		bool											mDirty;
		double											mOffsetHeight;
		double											mDefaultSpeed;
		OC::CVector3										mOffset;
		OC::CVector3										mStartDirection;
		ogMovableFrame									mFirstFrame;
		ogMovableFrame									mFinalFrame;
		MovableRouteList								mRouteList;
		MovableFinishState								mFinishState;
		osg::ref_ptr<osgAnimation::Vec3StepSampler>		mDirectionSampler;
		osg::ref_ptr<osgAnimation::Vec3LinearSampler>	mPositionSampler;

		CORE_AUTO_MUTEX
	};
}

#endif