#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERPIPEMDL
	#define LIB_S3DKERPIPEMDL_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerPipeMdl.lib")
	#define LIB_S3DKERPIPEMDL_EXP __declspec(dllimport)
#endif

