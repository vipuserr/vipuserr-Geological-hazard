#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERTRIG
	#define LIB_S3DKERINTERPIDW_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerTrig.lib")
	#define LIB_S3DKERINTERPIDW_EXP __declspec(dllimport)
#endif

