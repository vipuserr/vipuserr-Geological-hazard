#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(TDMFACELIB_LIB)
#  define TDMFACELIB_EXPORT Q_DECL_EXPORT
# else
#  define TDMFACELIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define TDMFACELIB_EXPORT
#endif

#ifndef TDMFACELIB_LIB 
#pragma comment(lib, "S3dAppFaceLib.lib")
#endif
