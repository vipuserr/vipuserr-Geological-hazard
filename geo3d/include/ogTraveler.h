#ifndef _OGTRAVELER_H_
#define _OGTRAVELER_H_

#include "osg_headers.h"
#include "oe_headers.h"
#include "IScene.h"
#include "ogFeature.h"
#include "ogMova.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL ogTraveler : public osg::Referenced
	{
	public:
		ogTraveler(ogTracer* tracer, C3DRenderEngine* engine);
		~ogTraveler(void);

		void setRoute(ogRoute* route);
		ogRoute* getRoute();
		ogRoute* getOrCreateRoute();

		void start();

		void end();

		void reset();

		void setPath(const std::vector< osg::Vec3d > points);

		void setOffsetHeight(double offz);
		void setModelVisible(bool visible);
		void setRouteVisible(bool visible);

		void setSpeed(double speed);
		double getSpeed();

		void setRange(double range);

		void pause();
		void resume();

		void setRoleUrl(OC::String url);
		OC::String getRoleUrl();

		void setFollow(bool follow);

		void setPitch(double tilt);

		void loadParams();

		FeaturePtr getFeature(){return mFeature;}
	private:
		FeaturePtr											mFeature;
		osg::ref_ptr<ogRoute>							mRoute;
		osg::observer_ptr<ogMova>							mMovable;
		osg::observer_ptr<ogTracer>					    mTracer;
	private:
		bool												mFollow;
		bool												mModelVisible;
		bool												mRouteVisible;
		OC::String												mModelUrl;
		double												mConstantTilt;
		double												mRange;
		double												mOffsetHeight;
        C3DRenderEngine*								m3DEngine;
        osg::observer_ptr<IScene>						mScene;
	};

}

#endif
