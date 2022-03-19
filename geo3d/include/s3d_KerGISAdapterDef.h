#pragma once



namespace Smart3dMap
{

}

#ifdef S3DKERGIS_ADAPTER_LIB
	#define S3DKERGIS_ADAPTER_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerSymbolDataMng.lib")
	#define S3DKERGIS_ADAPTER_EXP __declspec(dllimport)
#endif

