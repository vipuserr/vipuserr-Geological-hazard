 #pragma once
#include "OgMatShaderScript.h"
#include <string>
#include <map>
#include "OGBasDef.h"
using namespace std;

// ���ʽ�����

class OG_FRAME_DLL ShaderParse
{
public:
	ShaderParse(void);
	~ShaderParse(void);

	ShaderScript* ParseMaterialScript(std::string filename);

	void ReadAllFile(std::string pathname);

	//------------------------------------------------------------
	//1�����ļ����ж�ȡ���е�vert�ļ���
	//------------------------------------------------------------
	void ReadAllVertFile(std::string pathname);

	//------------------------------------------------------------
	//1.1����ȡvert�ļ������Լ�ָ��λ�õ�vert�ļ����ļ���
	//------------------------------------------------------------
	int GetVertFileNums(){return m_FileListVert.size();}
	string GetFileNameFromFilesList(int i) {return m_FileListVert[i];}


	//------------------------------------------------------------
	//2�����ļ����ж�ȡ���е�frag�ļ���
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
