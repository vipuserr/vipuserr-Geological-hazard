 #pragma once
#include <osg/Vec4>
//#include <osg/AlphaFunc>
#include <osg/BlendColor>
#include <osg/BlendFunc>
#include <osg/CullFace>
#include <vector>
#include <osg/ref_ptr>
#include <osg/Material>
#include <osg/AlphaFunc>
#include <osg/Texture2D>
#include <osg/Node>
#include <osg/Drawable>
#include "OGMaterial.h"
#include "OGBasDef.h"

using namespace std;
using namespace osg;

class OG_FRAME_DLL TraditionMaterial : public OGMaterial
{
public:
	TraditionMaterial(void);
	TraditionMaterial(std::string name);
	~TraditionMaterial(void);

	void SetAmbient(osg::Vec4 ambient);
	osg::Vec4 GetAmbient();

	void SetDiffuse(osg::Vec4 diffuse);
	osg::Vec4 GetDiffuse();

	void SetSpecular(osg::Vec4 spec);
	osg::Vec4 GetSpecular();

	void SetShininess(float shininess);
	float GetShininess();

	void SetEmission(osg::Vec4 emission);
	osg::Vec4 GetEmission();


	void AddTexture(std::string path, osg::Texture::WrapMode mode =osg::Texture::CLAMP);
	int GetTextureNum(){return m_TexturePathList.size();}
	std::string GetTexture(int index);
	

	void AddTextureMode(osg::Texture::WrapMode mode);
	int GetTextureModeNum(){return m_TextureAddList.size();}
	osg::Texture::WrapMode GetTextureMode(int index);

    void SetCullFace(bool cull);
	bool GetCullFace();
	void SetCullFaceMode(osg::CullFace::Mode mode);
	osg::CullFace::Mode GetCullFaceMode();

	void SetAlphaTest(bool enable);
	bool GetAlphaTest();
	void SetAlphaTestValue(float alphaValue);
	float GetAlphaTestValue();
	void SetAlphaTestComparisonFunction(osg::AlphaFunc::ComparisonFunction compFunc);
	osg::AlphaFunc::ComparisonFunction GetAlphaTestComparisonFunction();

	void SetAlphaBlend(bool enable);
	bool GetAlphaBlend();
	void SetAlphaBlendValue(osg::Vec4 blendParam);
	osg::Vec4 GetAlphaBlendValue();
	void SetSourceBlendFuncMode(osg::BlendFunc::BlendFuncMode sourceBFM);
	osg::BlendFunc::BlendFuncMode GetSourceBlendFuncMode();
	void SetDestBlendFuncMode(osg::BlendFunc::BlendFuncMode destBFM);
	osg::BlendFunc::BlendFuncMode GetDestBlendFuncMode();

	//void SaveDefaultMat();
	//void LoadDefaultMat();

	bool AttachMatToNode(osg::Node* node);
	bool AttachMatToNode(osg::Drawable* drawable);
    bool AttachMatToStateSet(osg::StateSet* stateset);

protected:
	void LoadTexture();

protected:
	osg::Vec4 m_ambient;
	osg::Vec4 m_diffuse;
	osg::Vec4 m_specular;
	osg::Vec4 m_emission;
	float m_shininess;
	
	std::vector<std::string> m_TexturePathList;
	std::vector<osg::Texture::WrapMode> m_TextureAddList;
	typedef std::vector<osg::ref_ptr<osg::Texture2D>> Texture2DMap;
	Texture2DMap m_TextureImageList;
	
	bool m_doubleFace;
	osg::CullFace::Mode m_cullFaceMode;
	osg::ref_ptr<osg::CullFace> m_pCullFace;
	
	bool m_alphaTest;
	osg::ref_ptr<osg::AlphaFunc> m_alphaTestFunc;
	osg::AlphaFunc::ComparisonFunction m_alphaCompFunc;
	float m_alphaTestValue;

	bool m_alphaBlend;
	//osg::AlphaFunc::ComparisonFunction m_alphaFunc;
	//float m_alphaFuncRef;
	osg::Vec4 m_alphaBlendCol;
	osg::ref_ptr<osg::BlendColor> m_pAlphaBlendColorObj;
	osg::ref_ptr<osg::BlendFunc> m_pAlphaBlendFun;
	osg::BlendFunc::BlendFuncMode m_sourceBFM;
	osg::BlendFunc::BlendFuncMode m_destBFM;

private:
	osg::ref_ptr<osg::Material> m_pMat;

};
