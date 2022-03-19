#ifndef _OG_FEATURE_EFFECT_CLASS__
#define _OG_FEATURE_EFFECT_CLASS__

#include "IFeatureEffect.h"
#include "ogstl_headers.h"
#include "s3d_KerAuxDef.h"
#include "ogColourValue.h"

namespace Smart3dMap
{
	//HighLight
	class CFeatureEffect_Flash : public IFeatureEffect
	{
	public:
		CFeatureEffect_Flash(OC::ColourValue color1, OC::ColourValue color2);
		~CFeatureEffect_Flash();
		virtual void update(osg::NodeVisitor* nv);

		static bool isKind(OC::String script);
		void setMaterial(osg::Vec4 color);
		osg::Vec4 getMaterial();

		void setColor1(OC::ColourValue color);
		void setColor2(OC::ColourValue color);

		void setInterval(double interval);
		double getInterval();
	private:
		bool							m1or2;
		double							mInterval;//ms
		OC::ColourValue						mColor1;
		OC::ColourValue						mColor2;
		mutable osg::Timer_t			mTickLastUpdated;
		osg::ref_ptr<osg::Material>		mMaterial;
	};

	//Transparent
	class CFeatureEffect_Transparent : public IFeatureEffect
	{
	public:
		CFeatureEffect_Transparent();
		~CFeatureEffect_Transparent();

		void setMaterial(osg::Vec4 color);
		osg::Vec4 getMaterial();

		void setTextureEnable(bool isEnable);
		void setCull(bool cull);
		static bool isKind(OC::String script);
	private:
		osg::ref_ptr<osg::Material>			mMaterial;
	};

	//Transparent
	class _OG3D_RENDERENGINE_DLL CFeatureEffect_Blend : public IFeatureEffect
	{
	public:
		CFeatureEffect_Blend();
		~CFeatureEffect_Blend();

		static bool isKind(OC::String script);
		
		virtual void setOpacity(double opacity);
	private:
		osg::BlendColor*					mBlendColor;
		osg::ref_ptr<osg::Material>			mMaterial;
	};

	class _OG3D_RENDERENGINE_DLL CFeatureEffectFactory
	{
	public:
		CFeatureEffectFactory();
		~CFeatureEffectFactory();

		static OC::String Effect_HighLight;
		static OC::String Effect_ScaleAnime;
		static OC::String Effect_AttachNode;
		static OC::String Effect_Transparent;
		static OC::String Effect_TextureAnime;
		static OC::String Effect_Moving;
		static OC::String Effect_Blend;

		static IFeatureEffect* create(OC::String effectStyle);
	};
}
#endif


