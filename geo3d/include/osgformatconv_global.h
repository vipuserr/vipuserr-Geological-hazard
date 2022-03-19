#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(OSGFORMATCONV_LIB)
#  define OSGFORMATCONV_EXPORT Q_DECL_EXPORT
# else
#  define OSGFORMATCONV_EXPORT Q_DECL_IMPORT
# endif
#else
# define OSGFORMATCONV_EXPORT
#endif

#ifndef OSGFORMATCONV_LIB
#pragma comment(lib, "S3dAppOsgFmtCvt.lib")
#endif
