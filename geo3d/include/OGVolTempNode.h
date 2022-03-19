 #pragma once
#include <osg/Node>
#include "gmeStorage.h"

namespace OG
{
	class OG_FRAME_DLL OGVolTempNode
	{
	private:
		OGVolTempNode(void);
		~OGVolTempNode(void);
	public:
		static OGVolTempNode* getSingtonPtr();
		static OGVolTempNode& getSington();
		bool ShowVolTempMesh(String& strMeshPath);
		bool ShowVolTempMesh(gmeFeature& feat);
		bool ShowVolTempMesh(gmeFeatureCls& featcls);
		bool ClearVolTempMesh();
	private:
		osg::Node*	mVolTempSceneNode;		//�������
		osg::Group*		RootNode;
		bool			mIsStatic;

	};

}

