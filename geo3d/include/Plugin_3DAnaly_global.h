#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PLUGIN_3DINCISION_LIB)
#  define PLUGIN_3DINCISION_EXPORT Q_DECL_EXPORT
# else
#  define PLUGIN_3DINCISION_EXPORT Q_DECL_IMPORT
# endif
#else
# define PLUGIN_3DINCISION_EXPORT
#endif
