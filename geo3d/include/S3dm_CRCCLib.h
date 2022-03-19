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

		// �½����ݿ�
		static void DoCreateDatabase();
		// �������ƽ��ͼ
		static void DoImportGeologicMap();
		// ����ң�н���ͼ��
		static void DoImportRSInterpretationMap();
		// ��������ݶ���ͼ
		static void DoImportGeologicSectionMap();
		// ������ͨͼ��
		static void DoImportGenericMap();
	};
}
