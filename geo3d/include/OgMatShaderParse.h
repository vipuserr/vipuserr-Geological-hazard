 #pragma once
#include "OgMatShaderScript.h"
#include <string>
#include <map>
#include "OGBasDef.h"
using namespace std;

// 材质解析类

class OG_FRAME_DLL ShaderParse
{
public:
	ShaderParse(void);
	~ShaderParse(void);

	ShaderScript* ParseMaterialScript(std::string filename);

	void ReadAllFile(std::string pathname);

	//------------------------------------------------------------
	//1、从文件夹中读取所有的vert文件名
	//------------------------------------------------------------
	void ReadAllVertFile(std::string pathname);

	//------------------------------------------------------------
	//1.1、获取vert文件数量以及指定位置的vert文件的文件名
	//------------------------------------------------------------
	int GetVertFileNums(){return m_FileListVert.size();}
	string GetFileNameFromFilesList(int i) {return m_FileListVert[i];}


	//------------------------------------------------------------
	//2、从文件夹中读取所有的frag文件名
	//------------------------------------------------------------
	void ReadAllFragFile(std::string pathname);

private:
   // ShaderScript* m_matScript;

	std::string m_FilePath;

	std::vector<std::string> m_FileListVert;
	std::vector<std::string> m_FileListFrag;

	std::map<std::string, ShaderScript*> m_VertScriptList;
	std::map<std::string, ShaderScript*> m_FragScriptList;


};
