#pragma once

#ifndef BUILD_STATIC
# if defined(S3DM_CRCCLIB_LIB)
#  define S3DM_CRCCLIB_EXPORT __declspec(dllexport) 
# else
#  define S3DM_CRCCLIB_EXPORT __declspec(dllimport) 
#pragma comment(lib, "S3dAppCrcc.lib")
# endif
#else
# define S3DM_CRCCLIB_EXPORT
#endif

namespace Smart3dMap {

	class S3DM_CRCCLIB_EXPORT S3dm_CRCCLib
	{
	public:
		S3dm_CRCCLib();
		virtual ~S3dm_CRCCLib();

		// 新建数据库
		static void DoCreateDatabase();
		// 导入地质平面图
		static void DoImportGeologicMap();
		// 导入遥感解译图件
		static void DoImportRSInterpretationMap();
		// 导入地质纵断面图
		static void DoImportGeologicSectionMap();
		// 导入普通图件
		static void DoImportGenericMap();
	};
}
