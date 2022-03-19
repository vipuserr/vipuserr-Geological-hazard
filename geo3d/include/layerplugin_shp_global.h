#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(LAYERPLUGIN_SHP_LIB)
#  define LAYERPLUGIN_SHP_EXPORT Q_DECL_EXPORT
# else
#  define LAYERPLUGIN_SHP_EXPORT Q_DECL_IMPORT
# endif
#else
# define LAYERPLUGIN_SHP_EXPORT
#endif
