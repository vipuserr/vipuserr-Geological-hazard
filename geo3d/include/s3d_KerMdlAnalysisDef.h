#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKERMDLANALYSIS
	#define S3DKERMDLANALYSIS_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerMdlAnalysis.lib")
	#define S3DKERMDLANALYSIS_EXP __declspec(dllimport)
#endif

