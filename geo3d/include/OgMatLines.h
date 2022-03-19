 #pragma once
#include <osg/Vec3>
#include <osg/Vec4>
#include <string>
#include <osg/ref_ptr>
#include <osg/Group>
#include "OGBasDef.h"
using namespace osg;
class OG_FRAME_DLL Lines
{
public:
	Lines(void);
	~Lines(void);

	void SetWidth(float width);
	void SetMaterial(std::string matName);

	void SetPosition(int num, Vec3* posList);
	osg::ref_ptr<osg::Geode> ShowLineGeo();
	osg::ref_ptr<osg::Geode> ShowConnectLineGeo();
	
    //osg::ref_ptr<osg::Group> ShowLineBB();
	osg::Drawable* createLineGeoRightDir(osg::Vec3& startPos, osg::Vec3& endPos, float& cordStart);
	osg::Drawable* createConnectLineGeo(osg::Vec3& startPos, osg::Vec3& endPos, float& cordStart);

	osg::Drawable* createLineGeoRight(osg::Vec3& startPos, osg::Vec3& endPos, float& cordStart);

protected:
    //osg::Drawable* createSquareLineGeo(osg::Vec3& startPos, osg::Vec3& center, osg::Vec3& endPos, float& cordStart);
	void GetMidSquareVector(osg::Vec3& startPos, osg::Vec3& center, osg::Vec3& endPos, osg::Vec3& upDir, osg::Vec3& rDir, float& coordValue);
	void GetStartEndSquareVector(osg::Vec3& startPos, osg::Vec3& endPos, osg::Vec3& upDir, osg::Vec3& rDir, float& coordValue);
protected:
	//osg::ref_ptr<osg::Group> ShowBillboardWithMat();
	//osg::Drawable* createSquareGeo(const osg::Vec3& corner);
	osg::Drawable* createLineGeo(osg::Vec3& startPos, osg::Vec3& endPos, float& cordStart);
protected:
	float m_width;
	int m_num;
	Vec3* m_posList;
	std::string m_matName;
};
