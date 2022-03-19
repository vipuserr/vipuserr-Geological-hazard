#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERSURFOPER
	#define LIB_S3DKERSURFOPER_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerSurfOper.lib")
	#define LIB_S3DKERSURFOPER_EXP __declspec(dllimport)
#endif