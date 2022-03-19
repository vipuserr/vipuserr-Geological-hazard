#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKER_POSCHECK
	#define S3DKER_POSCHECK_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerPosCheck.lib")
	#define S3DKER_POSCHECK_EXP __declspec(dllimport)
#endif

