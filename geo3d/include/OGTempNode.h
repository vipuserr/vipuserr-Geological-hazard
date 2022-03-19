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
		//ͨ��SuperMesh����ʱ��������һ���µ�ʵ��
		 long AddGeode(OGSimpleMesh* superMesh,OGTempType name,string& materialName);
		 long AddGeode(OGSimpleMesh* superMesh,OGTempType name,string& materialName,double length);

		//ͨ��Entity����ʱ��������һ���µ�ʵ��
		 long appendGeode(osg::ref_ptr<osg::Geode> pgeode);

		//ɾ����ʱ����¹ҽӵ�ʵ�����
		long releaseSceneNodeData();

		//���ý�����ʾ����,��appendEntityǰ����
		void setScale(Real xScale , Real yScale , Real zScale);

		//���ý���Ƿ�ɼ�
		void setVisible(bool isVisible);

		//��ȡ��ʱ����¹ҽӵ�ʵ�����
		long getNumEntity();

	private:
		osg::ref_ptr<osg::Geode> createSurfaceGeode(OGSimpleMesh* mesh,const string& MaterialName);
		osg::ref_ptr<osg::Geode> createSurfaceSkipGeode(OGSimpleMesh* mesh,const string& MaterialName);
		osg::ref_ptr<osg::Geode> createCubeDotGeode(OGSimpleMesh* mesh,const string& MaterialName,double length=100.0);
		osg::ref_ptr<osg::Geode> createSphereDotGeode(OGSimpleMesh* mesh,const string& MaterialName,double length=100.0);
		osg::ref_ptr<osg::Geode> createLineSkipGeode(OGSimpleMesh* mesh,const string& MaterialName,double length=100.0);

	private:
		SceneManager	*m_pSceneMgr;		//����������	
		osg::ref_ptr<osg::Group>	m_pSceneNode;		//�������
		Real			m_scaleX, m_scaleY, m_scaleZ;
		osg::Group*		RootNode;
	};

}