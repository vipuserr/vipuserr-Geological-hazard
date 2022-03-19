#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERISOVOL
	#define LIB_S3DKERISOVOL_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerIsoVol.lib")
	#define LIB_S3DKERISOVOL_EXP __declspec(dllimport)
#endif

