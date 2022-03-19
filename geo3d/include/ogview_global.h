#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(OGVIEW_LIB)
#  define OGVIEW_EXPORT Q_DECL_EXPORT
# else
#  define OGVIEW_EXPORT Q_DECL_IMPORT
# endif
#else
# define OGVIEW_EXPORT
#endif


#ifndef OGVIEW_LIB 
#pragma comment(lib, "S3dAppFaceView.lib")
#endif

