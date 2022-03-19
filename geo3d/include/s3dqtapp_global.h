#pragma once

#ifndef BUILD_STATIC
# if defined(S3DQTAPP_LIB)
#  define S3DQTAPP_EXPORT __declspec(dllexport)
# else
#  define S3DQTAPP_EXPORT __declspec(dllimport)
# endif
#else
# define S3DQTAPP_EXPORT
#endif

#ifndef S3DQTAPP_LIB 
#pragma comment(lib, "S3dAppQt.lib")
#endif