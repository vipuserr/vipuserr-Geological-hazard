#ifndef _OC_FEATURELOD_CLASS_H__
#define _OC_FEATURELOD_CLASS_H__

#include "Og3DRE_Def.h"
#include "ogVector2.h"

namespace Smart3dMap
{
    enum FetureMode
    {
        NormalFeature,
        RoleFeature,
        EffectFeature
    };

    class _OG3D_RENDERENGINE_DLL ogPagedLod : public osg::PagedLOD
	{
	public:
		ogPagedLod(void);
		virtual ~ogPagedLod(void);

		ogPagedLod(const osg::PagedLOD&,const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY);

		virtual bool addChild(osg::Node *child);
		virtual bool removeExpiredChildren(double expiryTime, unsigned int expiryFrame, osg::NodeList& removedChildren);

		virtual void init(ogFeatureNode* featurenode);

		OC::CVector2 getVisibleRange();
		void setVisibleRange(OC::CVector2 range);

		void setAttachNode(osg::Node* node);
		osg::Node* getAttachNode();

		void update();

		void setDirty(){mDirty = true;}

		void setDirtyCustomBound(){mDirtyCustomBound = true;}

		ogRoleNode* updateRole(OC::String filename,FetureMode mode);

		void reload();

		void setChildBoundingBoxAndMatrix(
			int                     childNum,
			const osg::BoundingBox& bbox,
			const osg::Matrix&      world2local);

		void traverse(osg::NodeVisitor& nv);
	protected:
		bool								mDirty;
		bool								mDirtyCustomBound;
		OC::CVector2							mVisibleRange;
		osg::observer_ptr<osg::Node>		mAttachNode;
		bool								mInjectLodScale;
		std::vector<float>			mLodScaleRangeList;
		std::vector<osg::BoundingBox>  _childBBoxes;
		std::vector<osg::Matrix>       _childBBoxMatrices;
	};
}

#endif

