#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERTRIGRGN
	#define LIB_S3DKERINTERPIDW_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerTrigRgn.lib")
	#define LIB_S3DKERINTERPIDW_EXP __declspec(dllimport)
#endif

