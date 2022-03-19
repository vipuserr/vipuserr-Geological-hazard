#pragma once

#ifdef LIB_S3DKERATTMDL
	#define LIB_S3DKERATTMDL_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerAttMdl.lib")
	#define LIB_S3DKERATTMDL_EXP __declspec(dllimport)
#endif