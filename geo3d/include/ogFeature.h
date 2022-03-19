#ifndef _og3DFEATURE_CLASS_
#define _og3DFEATURE_CLASS_

#include "ogResource.h"
#include "ogFeatureNode.h"
#include "gmeFeature.h"

namespace Smart3dMap
{
	typedef std::vector<ogFeature*> FeatureList;
	class _OG3D_RENDERENGINE_DLL ogFeature : public Resource
	{
	public:
		static OC::String ClassGUID;

		ogFeature(ResourceManager* creator, const OC::String& name, ResourceHandle handle,
			const OC::String& group, bool isManual = false, ManualResourceLoader* loader = 0);
		~ogFeature(void);

		bool load();

		virtual void loadImpl(void);
		virtual void unloadImpl(void){}

		virtual void preUnloadImpl(void) {}
		
		virtual void postUnloadImpl(void) {}

        virtual void prepareImpl(void);
       
        virtual void unprepareImpl(void) {}

		size_t calculateSize(void) const { return 0; }

		gmeFeature* getGmeFeature();
		void setGmeFeature(gmeFeature* gfeature);

        ogFeatureNode* getFeatureNode();

		ogMova* getMovable();
		ogMova* getOrCreateMovable();
		void removeMovable();
	private:
		bool							mLoaded;
		bool							mAttached;
		osg::ref_ptr<ogMova>			mMovable;
		osg::ref_ptr<ogFeatureNode>		mFeatureNode;
        gmeFeature*		                mFeatureRecord;
	};

	typedef SharedPtr<ogFeature> FeaturePtr;
}


#endif
