#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_GMKERMATH
	#define LIB_GMKERMATH_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerMath.lib")
	#define LIB_GMKERMATH_EXP __declspec(dllimport)
#endif

