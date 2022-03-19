 #pragma once
#include "OGMaterial.h"
#include "OgMaterialIO.h"
#include "OGBasDef.h"
#include <map>
using namespace std;
// ���ʿ�
class OG_FRAME_DLL MaterialLibrary
{
private:
	MaterialLibrary(void);
	~MaterialLibrary(void);

public:
	// singleton
	static MaterialLibrary& getSingleton(void);
	static MaterialLibrary* getSingletonPtr(void);

	MaterialIO* GetMaterialIO();

	OGMaterial* CreateMaterial(std::string matName, MaterialType type);

	OGMaterial* GetMaterial(std::string matName);

	void AddMaterial(std::string name, OGMaterial* mat);
	
	void RemoveMaterial(OGMaterial* mat);
	void RemoveMaterial(std::string name);

	//��ӻ�ȡlibrary�����е����ݲ��ʵ����֣�
	//��Ҫ�����������DefaultMat��Ҫ������
	//һ���ǲ������ͣ�������ˮ��ľ�ĵȲ�������
	//һ���Ǹ���û�в��ʵ����ݼ��еĶ������ɲ��ʽű�
	void GetAllDefaultObjMaterialName(vector<std::string>& namelist);

	//��ȡ����*.material�ļ������в�����
	void GetAllMaterialName(vector<std::string>& namelist);
	
	void RemoveAllMaterial();

protected:
	typedef std::map<std::string, OGMaterial*> MaterialMap;
	MaterialMap m_materialsLib;

private:
	MaterialIO* m_matIO;
};