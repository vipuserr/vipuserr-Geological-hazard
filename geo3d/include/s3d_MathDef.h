#pragma once

#include <string>
#include <vector>
using namespace std;

#include "gme_vector2.h"
#include "gme_vector3.h"
#include "gme_vector4.h"


//内存释放
#ifndef SAFE_DELETE
	#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#endif
#ifndef SAFE_DELETE_ARRAY
	#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#endif
#ifndef SAFE_RELEASE
	#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
#endif

#ifndef MIN_FLOAT
	#define MIN_FLOAT	(-3.402823E+38)
#endif

#ifndef ZERO_FLOAT
	#define ZERO_FLOAT (+1.401298E-45)
#endif

#ifndef MAX_FLOAT
	#define MAX_FLOAT	(+3.402823E+38)
#endif


#ifndef MIN_DOUBLE
	#define  MIN_DOUBLE	(-1.79769313486232E+307)
#endif
#ifndef MAX_DOUBLE
#define  MAX_DOUBLE	(+1.79769313486232E+307)
#endif


#ifndef ZERO_6BIT
#define		ZERO_6BIT  1E-6
#endif
#ifndef EQUAL_6BIT
#define		EQUAL_6BIT(a,b)		( fabs(a-b) < ZERO_6BIT )
#endif

#ifndef RTOD
#define		RTOD	57.2957795131		// 由弧度向度数转化的系数
#endif

#ifndef EPS
#define		EPS		0.0000001 		    // Tolerance for Line-Triangle intersection
#endif

#ifndef PI
	#define PI (3.14159265358979323846)
#endif
