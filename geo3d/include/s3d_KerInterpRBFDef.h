#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERINTERPRBF
	#define LIB_S3DKERINTERPRBF_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerInterpRBF.lib")
	#define LIB_S3DKERINTERPRBF_EXP __declspec(dllimport)
#endif

