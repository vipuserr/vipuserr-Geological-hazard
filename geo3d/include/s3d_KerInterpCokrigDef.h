#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERINTERPCOKRIG
	#define LIB_S3DKERINTERPCOKRIG_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerInterpCokrig.lib")
	#define LIB_S3DKERINTERPCOKRIG_EXP __declspec(dllimport)
#endif

