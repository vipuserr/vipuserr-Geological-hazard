#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_GMKEROBBT
	#define LIB_GMKEROBBT_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerObbt.lib")
	#define LIB_GMKEROBBT_EXP __declspec(dllimport)
#endif

