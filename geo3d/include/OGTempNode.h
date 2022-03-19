 #pragma once

#include <osg/Group>
#include <osg/Geode>
#include "OGBasDef.h"

class OGSimpleMesh;

namespace Smart3dMap
{
	enum OGTempType{
		OGTEMP_TYPE_SURFACE			=0,
		OGTEMP_TYPE_DOT_CUBE		=1,
		OGTEMP_TYPE_LINESKIP		=2,
		OGTEMP_TYPE_DOT_SPHERE		=3,
		OGTEMP_TYPE_SURFACESKIP		=4,

	};

	
	class OG_FRAME_DLL OGTempNode
	{
	public:
		OGTempNode(const string& name);
	public:
		~OGTempNode(void);

	public:
		//通过SuperMesh向临时结点中添加一个新的实体
		 long AddGeode(OGSimpleMesh* superMesh,OGTempType name,string& materialName);
		 long AddGeode(OGSimpleMesh* superMesh,OGTempType name,string& materialName,double length);

		//通过Entity向临时结点中添加一个新的实体
		 long appendGeode(osg::ref_ptr<osg::Geode> pgeode);

		//删除临时结点下挂接的实体对象
		long releaseSceneNodeData();

		//设置结点的显示比率,在appendEntity前调用
		void setScale(Real xScale , Real yScale , Real zScale);

		//设置结点是否可见
		void setVisible(bool isVisible);

		//获取临时结点下挂接的实体个数
		long getNumEntity();

	private:
		osg::ref_ptr<osg::Geode> createSurfaceGeode(OGSimpleMesh* mesh,const string& MaterialName);
		osg::ref_ptr<osg::Geode> createSurfaceSkipGeode(OGSimpleMesh* mesh,const string& MaterialName);
		osg::ref_ptr<osg::Geode> createCubeDotGeode(OGSimpleMesh* mesh,const string& MaterialName,double length=100.0);
		osg::ref_ptr<osg::Geode> createSphereDotGeode(OGSimpleMesh* mesh,const string& MaterialName,double length=100.0);
		osg::ref_ptr<osg::Geode> createLineSkipGeode(OGSimpleMesh* mesh,const string& MaterialName,double length=100.0);

	private:
		SceneManager	*m_pSceneMgr;		//场景管理器	
		osg::ref_ptr<osg::Group>	m_pSceneNode;		//场景结点
		Real			m_scaleX, m_scaleY, m_scaleZ;
		osg::Group*		RootNode;
	};

}