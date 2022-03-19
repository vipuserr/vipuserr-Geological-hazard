#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERINTERPMBSPLINE
	#define LIB_S3DKERINTERPMBSPLINE_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerInterpMBSpline.lib")
	#define LIB_S3DKERINTERPMBSPLINE_EXP __declspec(dllimport)
#endif

