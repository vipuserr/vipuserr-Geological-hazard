 #pragma once

#include<string>
#include <map>
#include <osg/Shader>
#include "OGBasDef.h"
#include "OgMatShaderParam.h"

using namespace std;
using namespace osg;

enum OG_FRAME_DLL ShaderScriptType{
	SST_VERTEX=0, 
	SST_FRAGMENT=1,
	SST_BOTH=2
};

class OG_FRAME_DLL ShaderScript
{
public:
	ShaderScript(void);
	ShaderScript(std::string name,ShaderScriptType type);
	~ShaderScript(void);

	void SetName(std::string name);
	void SetName(std::string name,ShaderScriptType type);
	std::string GetName();

	void SetType(ShaderScriptType type);
    ShaderScriptType GetType();

	bool LoadShader();
	osg::Shader* GetVertexShader();
	osg::Shader* GetFragmentShader();

	int GetMaterialParamNum();

	std::string GetMaterialParmName(int index);
	ShaderParam* GetMaterialParam(int index);
	ShaderParam* GetMaterialParam(std::string name);

	ShaderParamType GetMaterialParamType(int index);

	void SetMaterialParam(std::string& name, ShaderParam* param);

	void SetMaterialProName(std::string name);
	std::string GetMaterialProName(){return m_proname;}
private:
	//std::map<std::string, ShaderParam*> m_matParamList;
	typedef std::map<std::string, ShaderParam*> ShaderParamMap;
	ShaderParamMap m_matParamList;
	std::string m_name;
	ShaderScriptType m_type;

	osg::Shader* m_pVertShader;
	osg::Shader* m_pFragShader;

	osg::Program* m_pProgram;

	std::string m_proname; 
};
