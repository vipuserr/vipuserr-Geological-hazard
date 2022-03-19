#ifndef _GM_MATH_BASE_H_
#define _GM_MATH_BASE_H_


#ifdef _GM_MATH_BASE_LIB
	#define _GM_MATH_BASE_API __declspec(dllexport)
#else
	#define _GM_MATH_BASE_API __declspec(dllimport)
	#pragma comment(lib, "s3dKerMath.lib")
#endif

#include "gmeEntity.h"
using namespace Smart3dMap;

#include "gme_vector2.h"
#include "gme_vector3.h"
#include "gme_vector4.h"
#include "gm_quaternion.h"
#include "gm_matrix4.h"
#include "gm_MathDef.h"

namespace Smart3dMap
{
	class _GM_MATH_BASE_API gm_math_base
	{
	public:
		gm_math_base();
		~gm_math_base();


	};

}





#endif //_GM_MATH_BASE_H_