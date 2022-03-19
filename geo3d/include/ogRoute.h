#ifndef _OGMROUTE_CLASS_H__
#define _OGMROUTE_CLASS_H__

#include "Og3DRE_Def.h"
#include "osg_headers.h"
#include "oe_headers.h"

namespace Smart3dMap
{
	typedef std::vector<ogRoute>	MovableRouteList;

	class _OG3D_RENDERENGINE_DLL ogRoute : public osg::Referenced
	{
	public:
		typedef std::vector<OC::CVector3>		MovePath;

		ogRoute();
		~ogRoute();

		void clear();

		void setPath(MovePath path);
		void setPath(const std::vector< osg::Vec3d > points);

		void addPoint(OC::CVector3 point);
		int getPointNum();
		OC::CVector3 getPoint(int i);

		double getSpeed();
		void setSpeed(double speed);

		double getStayTime();
		void setStayTime(double time);

		const OC::String getAnimeState();
		void setAnimeState(OC::String anime);

		const double getTimeBegin();
		void setTimeBegin(double timeBeg);

		const double getTimeEnd();
		void setTimeEnd(double timeEnd);

		TiXmlElement* toXmlElement();
		void fromXmlElement(TiXmlElement* element);
	private:
		double		mSpeed;
		double		mTimeBeg;
		double		mTimeEnd;
		double		mStayTime;
		OC::String		mAnimeState;
		MovePath	mPath;
	};
}



#endif

