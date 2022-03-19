#pragma once


#ifdef S3D_ATT_DBENGINE_LIB
#define S3D_ATT_DBENGINE_API __declspec(dllexport)
#else
#define S3D_ATT_DBENGINE_API __declspec(dllimport)
#endif

#ifndef S3D_ATT_DBENGINE_LIB
#pragma comment(lib, "S3dDBEngineAtt.lib")
#endif

