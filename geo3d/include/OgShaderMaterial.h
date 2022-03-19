 #pragma once

#include <osg/StateSet>
#include <osg/Program>
#include <osg/Node>
#include <osg/Drawable>

#include "OGMaterial.h"
#include"OgMatShaderScript.h"
#include "OGBasDef.h"
// 对OSG渲染对象材质信息的封装

class OG_FRAME_DLL ShaderMaterial : public OGMaterial
{
public:
	ShaderMaterial(void);
	ShaderMaterial(std::string name){m_strName=name;}
	~ShaderMaterial(void);

	void SetScript(ShaderScript* script);
	ShaderScript* GetScript();

	bool AttachMatToNode(osg::Node* node);
    bool AttachMatToStateSet(osg::StateSet* stateset);
	bool AttachMatToNode(osg::Drawable* drawable);

	bool SaveMaterial(std::string name);
	bool LoadMaterial(std::string name);

	bool UpdateParam(std::string name, ShaderParam* param);


	//设置材质文件名
	////string AppendAMatInfo(map<std::string, ShaderParam*> matParam);
	//void AppendAMatInfo(ShaderScript*);
	////void getAMatInfo(string strMatName, map<std::string, ShaderParam*>& matParam);
	//void getAMatInfo(string strMatProName, ShaderScript*& matScript);
	//bool save();

	// Default ShaderMaterial
	
protected:
	void AttachMatParamsToNode(osg::StateSet* pStateSet);

protected:
	ShaderScript* m_pScript;

private:
	osg::Program* m_pProgram;
	//std::string m_strName;
	typedef std::map<std::string, osg::Uniform*> UniformMap;
	UniformMap	m_matParamList;
	
};