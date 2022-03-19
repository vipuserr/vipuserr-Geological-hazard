 #pragma once
//#include <afx.h>
#include <xstring>
#include "OGMaterial.h"
#include "OgShaderMaterial.h"
#include "OgTraditionMaterial.h"

class OG_FRAME_DLL MaterialIO
{
public:
	MaterialIO(void);
	~MaterialIO(void);

	// 注意：加载(Load)后的材质都在MaterialLibrary中有记录

	// 保存单个文件matName到指定文件filename中
	void SaveMaterial(std::string filename, std::string matName);
	void SaveMaterial(std::string filename, OGMaterial* mat);

	// 保存多个文件matName到指定文件filename中
	void SaveMaterial(std::string filename, vector<std::string>& matName);
	void SaveMaterial(std::string filename, vector<OGMaterial*>& ogmat);

	// 附加单个文件matName到指定文件fileName中
	void AppendMatInfo(std::string fileName, std::string matName);
	void AppendMatInfo(std::string fileName, OGMaterial* ogmat);

	// 附加多个文件matName到指定文件fileName中
	void AppendMatInfo(std::string fileName, vector<std::string>& matName);
	void AppendMatInfo(std::string fileName, vector<OGMaterial*>& ogmat);

	// 加载单个材质文件
	bool LoadMaterial(std::string fileName);

    //加载文件夹中所有Material
	bool LoadAllMaterial(std::string pathname);

	void getEnvPath(std::string &strEnvPath);
//private:
//	//加载文件夹中单个的Material
//	void LoadSingleMaterial(std::string fileName);

private:
	osg::Texture::WrapMode StringToTextureAddressMode(std::string str);
	osg::CullFace::Mode StringToCullFaceMode(std::string str);
	bool StringNumToBool(std::string str);
	osg::BlendFunc::BlendFuncMode StringToBlendFuncMode(std::string str);
	osg::Vec4 StringToVec4(std::string str);
	osg::AlphaFunc::ComparisonFunction StringToComparisonFunc(std::string str);

	std::string TextureAddressModeToString(osg::Texture::WrapMode mode);
	std::string CullFaceModeToString(osg::CullFace::Mode mode);
	std::string BoolToString(bool mode);
	std::string BlendFuncModeToString(osg::BlendFunc::BlendFuncMode mode);
	std::string Vec4ToString(osg::Vec4 v4);
	std::string ComparisonFuncToString(osg::AlphaFunc::ComparisonFunction mode);

	//将一个ogmaterial存放到一个文件中
	void SaveTraditonMat(std::string filename, TraditionMaterial* mat);
	void SaveShaderMat(std::string filename, ShaderMaterial* mat);
protected:
	// 保存TraditionMaterial
//	bool SaveTraditonMat(CStdioFile file, TraditionMaterial* mat);
	// 保存ShaderMaterial
//	bool SaveShaderMat(CStdioFile file, ShaderMaterial* mat);

	// 加载TraditionMaterial
	//bool LoadTraditionMat(CStdioFile& file, TraditionMaterial* tradMat);
	bool LoadTraditionMat(std::string filename, TraditionMaterial* tradMat);
	// 加载ShaderMaterial
 	//bool LoadShaderMat(CStdioFile& file, ShaderMaterial* shaderMat);
	bool LoadShaderMat(std::string filename, ShaderMaterial* shaderMat);
private:
	std::string mEnvPath;
};
