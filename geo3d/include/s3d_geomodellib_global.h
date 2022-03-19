#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(S3D_GEOMODELLIB_LIB)
#  define S3D_GEOMODELLIB_EXPORT Q_DECL_EXPORT
# else
#  define S3D_GEOMODELLIB_EXPORT Q_DECL_IMPORT
# endif
#else
# define S3D_GEOMODELLIB_EXPORT
#endif

#ifndef S3D_GEOMODELLIB_LIB 
#pragma comment(lib, "S3dAppGeoModel.lib")
#endif