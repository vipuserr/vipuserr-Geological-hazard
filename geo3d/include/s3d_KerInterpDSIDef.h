#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERINTERPDSI
	#define S3DKERINTERPDSI_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerInterpDSI.lib")
	#define S3DKERINTERPDSI_EXP __declspec(dllimport)
#endif

