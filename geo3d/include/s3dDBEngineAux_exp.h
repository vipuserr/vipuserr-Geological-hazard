#pragma once


#ifdef S3D_DBENGINE_AUX_LIB
#define S3D_DBENGINE_AUX_API __declspec(dllexport)
#else
#define S3D_DBENGINE_AUX_API __declspec(dllimport)
#endif

#ifndef S3D_DBENGINE_AUX_LIB
#pragma comment(lib, "s3dDBEngineAux.lib")
#endif

