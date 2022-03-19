#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERVHOLE
	#define LIB_S3DKERVHOLE_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerVHole.lib")
	#define LIB_S3DKERVHOLE_EXP __declspec(dllimport)
#endif

