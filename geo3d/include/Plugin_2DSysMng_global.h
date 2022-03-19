#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PLUGIN_2DSYSMNG_LIB)
#  define PLUGIN_2DSYSMNG_EXPORT Q_DECL_EXPORT
# else
#  define PLUGIN_2DSYSMNG_EXPORT Q_DECL_IMPORT
# endif
#else
# define PLUGIN_2DSYSMNG_EXPORT
#endif

#ifndef PLUGIN_2DSYSMNG_LIB 
#pragma comment(lib, "Plugin_2DSysMng.lib")
#endif