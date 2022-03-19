 #pragma once
#include <osg/Program>
#include <map>
#include <string>
using namespace std;

class ProgramManager
{
private:
	ProgramManager(void);
	~ProgramManager(void);

public:
	void AddProgram(std::string name, osg::Program* prog);
	void RemoveProgram(std::string name);
	osg::Program* GetProgram(std::string name);

	static ProgramManager& getSingleton(void);
	static ProgramManager* getSingletonPtr(void);

private:
	typedef std::map<std::string, osg::Program*> ProgramList;
	ProgramList m_progList;
};
