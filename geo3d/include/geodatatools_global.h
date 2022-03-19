#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(GEODATATOOLS_LIB)
#  define GEODATATOOLS_EXPORT Q_DECL_EXPORT
# else
#  define GEODATATOOLS_EXPORT Q_DECL_IMPORT
# endif
#else
# define GEODATATOOLS_EXPORT 
#endif

#ifndef GEODATATOOLS_LIB
#pragma comment(lib, "GeoDataTools.lib")
#endif
