#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LAYERPLUGIN_GEO3D_LIB)
#  define LAYERPLUGIN_GEO3D_EXPORT Q_DECL_EXPORT
# else
#  define LAYERPLUGIN_GEO3D_EXPORT Q_DECL_IMPORT
# endif
#else
# define LAYERPLUGIN_GEO3D_EXPORT
#endif

#ifndef LAYERPLUGIN_GEO3D_LIB 
#pragma comment(lib, "LayerPlugin_geo3d.lib")
#endif