#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERINTERPSFI
	#define LIB_S3DKERINTERPSFI_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerInterpSFI.lib")
	#define LIB_S3DKERINTERPSFI_EXP __declspec(dllimport)
#endif

