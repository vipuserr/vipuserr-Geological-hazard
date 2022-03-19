#pragma once

#ifdef S3D_BASEAPPLIB_LIB
#define S3D_BASEAPPLIB_EXPORT __declspec(dllexport)
#else
#pragma comment(lib, "S3dAppBase.lib")
#define S3D_BASEAPPLIB_EXPORT __declspec(dllimport)
#endif

