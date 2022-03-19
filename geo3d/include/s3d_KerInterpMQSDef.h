#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERINTERPMQS
	#define LIB_S3DKERINTERPMQS_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerInterpMQS.lib")
	#define LIB_S3DKERINTERPMQS_EXP __declspec(dllimport)
#endif

