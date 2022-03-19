 #pragma once
#include "OGBasDef.h"
#include <osg/Geode>
#include <string>
#include <osg/Group>
#include <osg/ref_ptr>

class OG_FRAME_DLL Faces
{
public:
	Faces(void);
	~Faces(void);

	// √ÊÕº–Œ…Ë÷√
	void SetFaceGeo(osg::Geode* faceGeo);
	void SetFaceMaterial(std::string matName);
	osg::ref_ptr<osg::Group> Show();

protected:
	std::string m_faceMatName;
	osg::Geode* m_faceGeo;
};
