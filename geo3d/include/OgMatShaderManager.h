 #pragma once

#include <osg/Shader>
#include <string>
using namespace std;

class ShaderManager
{
private:
	ShaderManager(void);
	~ShaderManager(void);

public:
	osg::Shader* AddShader(std::string name);
	osg::Shader* AddShader(std::string name, osg::Shader::Type type);
	bool RemoveShader(std::string name);
	osg::Shader* GetShader(std::string name);

	// µ¥¼ü
	static ShaderManager& getSingleton(void);
	static ShaderManager* getSingletonPtr(void);
	

protected:
	osg::Shader* LoadShader(std::string name);
	osg::Shader* LoadShader(std::string name, osg::Shader::Type type);

private:
	typedef std::map<std::string, osg::Shader*> ShaderMap;
	ShaderMap m_shaderList;
};

