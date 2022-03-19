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

	// ע�⣺����(Load)��Ĳ��ʶ���MaterialLibrary���м�¼

	// ���浥���ļ�matName��ָ���ļ�filename��
	void SaveMaterial(std::string filename, std::string matName);
	void SaveMaterial(std::string filename, OGMaterial* mat);

	// �������ļ�matName��ָ���ļ�filename��
	void SaveMaterial(std::string filename, vector<std::string>& matName);
	void SaveMaterial(std::string filename, vector<OGMaterial*>& ogmat);

	// ���ӵ����ļ�matName��ָ���ļ�fileName��
	void AppendMatInfo(std::string fileName, std::string matName);
	void AppendMatInfo(std::string fileName, OGMaterial* ogmat);

	// ���Ӷ���ļ�matName��ָ���ļ�fileName��
	void AppendMatInfo(std::string fileName, vector<std::string>& matName);
	void AppendMatInfo(std::string fileName, vector<OGMaterial*>& ogmat);

	// ���ص��������ļ�
	bool LoadMaterial(std::string fileName);

    //�����ļ���������Material
	bool LoadAllMaterial(std::string pathname);

	void getEnvPath(std::string &strEnvPath);
//private:
//	//�����ļ����е�����Material
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

	//��һ��ogmaterial��ŵ�һ���ļ���
	void SaveTraditonMat(std::string filename, TraditionMaterial* mat);
	void SaveShaderMat(std::string filename, ShaderMaterial* mat);
protected:
	// ����TraditionMaterial
//	bool SaveTraditonMat(CStdioFile file, TraditionMaterial* mat);
	// ����ShaderMaterial
//	bool SaveShaderMat(CStdioFile file, ShaderMaterial* mat);

	// ����TraditionMaterial
	//bool LoadTraditionMat(CStdioFile& file, TraditionMaterial* tradMat);
	bool LoadTraditionMat(std::string filename, TraditionMaterial* tradMat);
	// ����ShaderMaterial
 	//bool LoadShaderMat(CStdioFile& file, ShaderMaterial* shaderMat);
	bool LoadShaderMat(std::string filename, ShaderMaterial* shaderMat);
private:
	std::string mEnvPath;
};
