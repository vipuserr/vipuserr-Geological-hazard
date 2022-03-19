#ifndef _OGFEATURENODE_H__
#define _OGFEATURENODE_H__

#include "SceneNode.h"
//#include "FeatureRecord.h"
//#include "FeatureEffect.h"
#include "ogPagedLod.h"

namespace Smart3dMap
{
	class _OG3D_RENDERENGINE_DLL ogFeatureNode : public CSceneNode
	{
	public:
		ogFeatureNode(ogFeature* owner);
		virtual	~ogFeatureNode(void);

		virtual ogFeatureNode* asFeatureNode(){return static_cast<ogFeatureNode*>(this);}
		virtual const char* className() const;
		virtual void update(osg::NodeVisitor* nv);
        ogPagedLod * getPageLOD();
		virtual	void setMatrix(osg::Matrixd matrix);
		virtual bool add(osg::Node* child);
		virtual bool remove(osg::Node* child);

		static OC::String ClassGUID;
        void updateFeatureUrl(OC::String url);

		void loadMatrix();

		//void setRecord(FeatureRecord* record);
		//FeatureRecord* getRecord();

		//CQuaternion getRotate();

        CSceneNode*				getSecondOffsetNode();
        osg::MatrixTransform*	getFirstOffsetNode();
        ogRoleNode* getRoleNode();
        void setFeatureMode(FetureMode mode);
        FetureMode getFeatureMode();

		bool init();

		osg::Matrix getMatrix();

		ogFeature* getOwner();

		void showBoundBox(bool visible);

        void setPosition(OC::CVector3 position){mPosition = position;}
        OC::CVector3 getPosition(){return mPosition;}

        void setFeaturUrl(OC::String url){mFeatureUrl = url;}
        OC::String getFeatureUrl(){return mFeatureUrl;}

        void setScale(OC::CVector3 scale);
        OC::CVector3 getScale();

        double getVisibleDistance(){return mVisibleDistance;}
        void setVisibleDistance(double distance){mVisibleDistance = distance;}

	protected:
		//osg::ref_ptr<FeatureRecord>				mFeatureRecord;
	private:
        OC::String                              mFeatureUrl;
        double  mVisibleDistance;
		bool									mReload;
		OC::CVector3							mPosition;
		OC::CVector3							mScale;
        ogFeature*								mOwner;
		osg::Vec3i								mOffsetPosition;
		FetureMode							    mFeatureMode;
		FetureMode							    mToFeatureMode;
		OC::CQuaternion							mQuaternion;
		osg::ref_ptr<osg::Node>					mBoundBoxNode;
        osg::ref_ptr<ogRoleNode>				mRoleNode;
        osg::ref_ptr<CSceneNode>				mSecondOffsetNode;
		osg::ref_ptr<ogPagedLod>				mFeatureLodNode;
		osg::ref_ptr<osg::MatrixTransform>		mFirstOffsetNode;
	private:
		ogFeatureNode(const ogFeatureNode&);
		ogFeatureNode& operator =(const ogFeatureNode& rks);
		CORE_AUTO_MUTEX
	};
}

#endif
