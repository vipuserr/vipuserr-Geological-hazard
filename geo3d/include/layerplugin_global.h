#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LAYERPLUGIN_GEO2D_LIB)
#  define LAYERPLUGIN_GEO2D_EXPORT Q_DECL_EXPORT
# else
#  define LAYERPLUGIN_GEO2D_EXPORT Q_DECL_IMPORT
# endif
#else
# define LAYERPLUGIN_GEO2D_EXPORT
#endif

#ifndef LAYERPLUGIN_GEO2D_LIB 
#pragma comment(lib, "LayerPlugin_geo2d.lib")
#endif