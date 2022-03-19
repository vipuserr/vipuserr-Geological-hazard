 #pragma once
#include <osg/Node>
#include <osg/StateSet>
#include "OGBasDef.h"

enum OG_FRAME_DLL MaterialType
{
	MT_TRADITION =0,
	MT_SHADER=1
};

class OG_FRAME_DLL OGMaterial
{
public:
	OGMaterial();
	~OGMaterial();

	void SetName(std::string name);
	std::string GetName();

	void SetType(MaterialType type){m_matType=type;}
	MaterialType GetType(){return m_matType;}

	virtual bool AttachMatToNode(osg::Node* node)=0;
	virtual bool AttachMatToStateSet(osg::StateSet* stateset)=0;
	
protected:
	std::string m_strName;
	MaterialType m_matType;
	
};