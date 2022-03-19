#pragma once
#include "OG3DRenderEngine.h"

class CGMEPagedLodEvent :public osgGA::GUIEventHandler
{
public:
	CGMEPagedLodEvent();
	~CGMEPagedLodEvent();

	virtual bool handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);

private:
	bool m_bInitialized;  //≥ı ºªØ
	double m_dViewAngle;
	osg::ref_ptr<osgViewer::Viewer>	m_Viewer;
	osg::ref_ptr<SceneNode> m_SNode;
};

