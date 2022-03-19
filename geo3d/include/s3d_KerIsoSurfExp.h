#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERISOSURF
	#define LIB_S3DKERISOSURF_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerIsoSurf.lib")
	#define LIB_S3DKERISOSURF_EXP __declspec(dllimport)
#endif

