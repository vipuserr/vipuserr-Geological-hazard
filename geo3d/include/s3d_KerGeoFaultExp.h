#pragma once

#ifdef S3D_KERGEOFAULT_LIB
	#define S3D_KERGEOFAULT_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerGeoFault.lib")
	#define S3D_KERGEOFAULT_EXP __declspec(dllimport)
#endif