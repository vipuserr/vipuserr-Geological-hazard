#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(TDMFACERESMNG_LIB)
#  define TDMFACERESMNG_EXPORT Q_DECL_EXPORT
# else
#  define TDMFACERESMNG_EXPORT Q_DECL_IMPORT
# endif
#else
# define TDMFACERESMNG_EXPORT
#endif


#ifndef TDMFACERESMNG_LIB 
#pragma comment(lib, "S3dAppFaceResMng.lib")
#endif
