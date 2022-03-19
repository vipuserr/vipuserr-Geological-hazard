#ifndef _OG_MOVABLE_CLASS_H_
#define _OG_MOVABLE_CLASS_H_

#include "ogFeatureNode.h"
#include "ogRouteManager.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL ogMova : public osg::Referenced
	{
	public:
		ogMova(ogFeature* feature);
		~ogMova(void);

		void start();
		void pause();
		void resume();
		void stop();

		void checkPlay();

		void setRouteManager(ogRouteManager* routeMgr);
        ogRouteManager* getRouteManager();
        ogRouteManager* getOrCreateRouteManager();

		void update();
		
		ogMovableFrame getCurrentFrame();
		ogMovableFrame getPreFrame();

		void setEventActive(bool active);
		bool getEventActive();

		void setFaceDirection(OC::CVector3 direction);
		OC::CVector3 getFaceDirection();

		bool isRunning();
		bool isPausing();

		void setOwner(ogFeature* feature);
        ogFeature* getOwner();
	protected:
		bool											mEventActive;
		double											mMultiple;
		OC::CVector3										mFaceDirection;
        ogFeature*										mOwnerFeature;
		ogMovableFrame									mCurrentFrame;
		ogMovableFrame									mPreviousFrame;
		//osg::ref_ptr<CRoleNode>							mRoleNode;
		osg::ref_ptr<ogFeatureNode>						mFeatureNode;
		//osg::observer_ptr<CEventLayer>					mEventLayer;
		osg::ref_ptr<ogRouteManager>				mRouteManager;
	private:
		bool setupAnimeRoute();
		void reset();
	private:
		bool											mPlaying;
		bool											mPause;
		osg::Timer_t									mStartTime;
		osg::Timer_t									mPauseTime;
		osg::Timer_t									mCurrentTime;
		osg::ref_ptr<osg::NodeCallback>					mNodeCallback;
	};
}


#endif


