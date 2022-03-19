#ifndef _OG_IFEATUREEFFECT_CLASS__
#define _OG_IFEATUREEFFECT_CLASS__

#include "osg_headers.h"
#include "Og3DRE_Def.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL IFeatureEffect : public osg::Object
	{
	public:
		IFeatureEffect();
		virtual ~IFeatureEffect();
		IFeatureEffect(const IFeatureEffect& eh,const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY){}

		META_Object(Smart3dMap,IFeatureEffect);

		virtual void update(osg::NodeVisitor* nv);
		virtual void setEffectNode(CSceneNode* sceneNode);

		void stop();
		bool isRunning();
		void setRenderBin(int bin) { mRenderBin = bin; }

		void setLoopNumber(long num);
		long getLoopNumber();

		virtual void setOpacity(double opacity){}

		virtual void onInit(){}
	protected:
		int								mRenderBin;
		bool							mFirstFrame;
		bool							mRunning;
		long							mLoopCount;
		long							mLoopNumber;
		CSceneNode*						mOwner;
		osg::ref_ptr<osg::StateSet>		mEffectStateSet;
		osg::observer_ptr<osg::Node>	mEffectNode;
	};
}
#endif


