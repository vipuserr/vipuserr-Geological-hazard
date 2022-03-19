#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERISOLIN
	#define LIB_S3DKERISOLIN_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerIsolin.lib")
	#define LIB_S3DKERISOLIN_EXP __declspec(dllimport)
#endif

