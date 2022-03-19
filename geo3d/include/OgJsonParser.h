#ifndef _OG_JSON_HELPER_CLASS_H_
#define _OG_JSON_HELPER_CLASS_H_

#include "Og3DRE_Def.h"
#include "oe_headers.h"

namespace Smart3dMap
{
    typedef std::map<OC::String, OC::String> NameValuePairList;
    class _OG3D_RENDERENGINE_DLL OgJsonParser
	{
	public:
		OgJsonParser(void);
		~OgJsonParser(void);

        static int getInt(osgEarth::Json::Value& obj, OC::String key, int defaultVal = 1);
        static bool getBool(osgEarth::Json::Value& obj, OC::String key, bool defaultVal = false);
        static double getDouble(osgEarth::Json::Value& obj, OC::String key, double defaultVal = 0.0);
        static uint32 getUInt(osgEarth::Json::Value& obj, OC::String key, uint32 defaultVal = 1);
        static OC::String getString(osgEarth::Json::Value& obj, OC::String key, OC::String defaultVal = OC::StringUtil::BLANK);

		static std::vector<std::pair<OC::String,OC::String> > parseStringPairList(OC::String jsonStr);
		static NameValuePairList parseNameValuePairList(OC::String jsonStr);

		static OC::StringMap parseStyleString(OC::String styleStr);

        static bool parseStringParam(OC::String jsonStr, OC::StringMap& stringMap);
        static osg::MixinVector<osg::Vec3d> parseGeometryJson(OC::String jsonStr);
		
		
	};
	
}


#endif



