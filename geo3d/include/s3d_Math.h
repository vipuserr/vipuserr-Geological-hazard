#pragma once
#include <cmath>
#include <cfloat>

#include <s3d_KerMathDef.h>

namespace Smart3dMap {
#ifdef PI
#undef PI
#undef PI_2
#undef PI_4
#endif
const double PI   = 3.14159265358979323846;
const double PI_2 = 1.57079632679489661923;
const double PI_4 = 0.78539816339744830962;
const double LN_2 = 0.69314718055994530942;
const double INVLN_2 = 1.0 / LN_2;

const double RTOA = 57.2957795131;
const double ATOR = 0.01745329252;

#ifndef MIN_DOUBLE
	#define  MIN_DOUBLE	       (-1.797693134862E+307)
#endif

#ifndef MAX_DOUBLE
	#define  MAX_DOUBLE	       (+1.797693134862E+307)
#endif

#ifndef MIN_ZERO_DOUBLE
	#define  MIN_ZERO_DOUBLE   (-4.940656458412E-324)
#endif

#ifndef MAX_ZERO_DOUBLE
	#define  MAX_ZERO_DOUBLE   (+4.940656458412E-324)
#endif

#ifndef DOUBLE_EPS1
	#define DOUBLE_EPS1        1e-1
#endif
#ifndef DOUBLE_EPS2
	#define DOUBLE_EPS2        1e-2
#endif
#ifndef DOUBLE_EPS3
	#define DOUBLE_EPS3        1e-3
#endif
#ifndef DOUBLE_EPS4
	#define DOUBLE_EPS4        1e-4
#endif
#ifndef DOUBLE_EPS5
	#define DOUBLE_EPS5        1e-5
#endif
#ifndef DOUBLE_EPS6
	#define DOUBLE_EPS6        1e-6
#endif
#ifndef DOUBLE_EPS10
	#define DOUBLE_EPS10       1e-10
#endif

#ifndef SAFE_DELETE(x)
	#define SAFE_DELETE(x)       {if(x!=NULL) delete(x);   x=NULL;}
#endif

#ifndef SAFE_DELETE_ARRAY(x)
	#define SAFE_DELETE_ARRAY(x) {if(x!=NULL) delete[](x); x=NULL;}
#endif

template<typename T>
inline T absolute(T v) { return v<(T)0?-v:v; }

inline bool equivalent(float lhs,float rhs,float epsilon=1e-6)
{ float delta = rhs-lhs; return delta<0.0f?delta>=-epsilon:delta<=epsilon; }


inline bool equivalent(double lhs,double rhs,double epsilon=1e-6)
{ double delta = rhs-lhs; return delta<0.0?delta>=-epsilon:delta<=epsilon; }


template<typename T>
inline T minimum(T lhs,T rhs) { return lhs<rhs?lhs:rhs; }


template<typename T>
inline T maximum(T lhs,T rhs) { return lhs>rhs?lhs:rhs; }

template<typename T>
inline T clampTo(T v,T minimum,T maximum) { return v<minimum?minimum:v>maximum?maximum:v; }

template<typename T>
inline T clampAbove(T v,T minimum) { return v<minimum?minimum:v; }

template<typename T>
inline T clampBelow(T v,T maximum) { return v>maximum?maximum:v; }

template<typename T>
inline T clampBetween(T v,T minimum, T maximum)
{ return clampBelow(clampAbove(v,minimum),maximum); }

template<typename T>
inline T sign(T v) { return v<(T)0?(T)-1:(T)1; }

template<typename T>
inline T signOrZero(T v) { return v<(T)0 ? (T)-1 : ( v>(T)0 ? (T)1 : 0 ); }

template<typename T>
inline T square(T v) { return v*v; }

template<typename T>
inline T signedSquare(T v) { return v<(T)0?-v*v:v*v; }

inline float inDegrees(float angle) { return angle*(float)PI/180.0f; }
inline double inDegrees(double angle) { return angle*PI/180.0; }

template<typename T>
inline T inRadians(T angle) { return angle; }

inline float DegreesToRadians(float angle) { return angle*(float)PI/180.0f; }
inline double DegreesToRadians(double angle) { return angle*PI/180.0; }

inline float RadiansToDegrees(float angle) { return angle*180.0f/(float)PI; }
inline double RadiansToDegrees(double angle) { return angle*180.0/PI; }

inline float round(float v) { return v>=0.0f?floorf(v+0.5f):ceilf(v-0.5f); }
inline double round(double v) { return v>=0.0?floor(v+0.5):ceil(v-0.5); }

#if defined(_MSC_VER)
inline bool isNaN(double v) { return _isnan(v)!=0; }
#elif defined(__ANDROID__)
inline bool isNaN(float v) { return isnan(v); }
inline bool isNaN(double v) { return isnan(v); }
#else
inline bool isNaN(float v) { return std::isnan(v); }
inline bool isNaN(double v) { return std::isnan(v); }
#endif

}
