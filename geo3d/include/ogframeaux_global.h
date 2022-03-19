#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(OGFRAMEAUX_LIB)
#  define OGFRAMEAUX_EXPORT Q_DECL_EXPORT
# else
#  define OGFRAMEAUX_EXPORT Q_DECL_IMPORT
# endif
#else
# define OGFRAMEAUX_EXPORT
#endif


#ifndef OGFRAMEAUX_LIB 
#pragma comment(lib, "S3dAppFaceFrameAux.lib")
#endif
