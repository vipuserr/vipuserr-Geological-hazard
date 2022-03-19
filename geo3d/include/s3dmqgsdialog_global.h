#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(S3DMQGSDIALOG_LIB)
#  define S3DMQGSDIALOG_EXPORT Q_DECL_EXPORT
# else
#  define S3DMQGSDIALOG_EXPORT Q_DECL_IMPORT
# endif
#else
# define S3DMQGSDIALOG_EXPORT
#endif


#ifndef S3DMQGSDIALOG_LIB
#pragma comment(lib, "S3dAppQgsDialog.lib")
#endif
