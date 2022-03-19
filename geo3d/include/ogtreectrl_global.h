#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(OGTREECTRL_LIB)
#  define OGTREECTRL_EXPORT Q_DECL_EXPORT
# else
#  define OGTREECTRL_EXPORT Q_DECL_IMPORT
# endif
#else
# define OGTREECTRL_EXPORT
#endif

#ifndef OGTREECTRL_LIB 
#pragma comment(lib, "S3dAppFaceTreeCtrl.lib")
#endif
