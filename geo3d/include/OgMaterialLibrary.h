 #pragma once
#include "OGMaterial.h"
#include "OgMaterialIO.h"
#include "OGBasDef.h"
#include <map>
using namespace std;
// 材质库
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

	//添加获取library的所有的内容材质的名字，
	//主要针对于两个，DefaultMat主要有两个
	//一个是材质类型，金属，水，木材等材质类型
	//一个是给还没有材质的数据集中的对象生成材质脚本
	void GetAllDefaultObjMaterialName(vector<std::string>& namelist);

	//获取所有*.material文件的所有材质名
	void GetAllMaterialName(vector<std::string>& namelist);
	
	void RemoveAllMaterial();

protected:
	typedef std::map<std::string, OGMaterial*> MaterialMap;
	MaterialMap m_materialsLib;

private:
	MaterialIO* m_matIO;
};