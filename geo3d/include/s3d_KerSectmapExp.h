#pragma once

#ifdef _S3D_KER_GEOSECT_LIB
	#define _S3D_KER_GEOSECT_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerGeoSect.lib")
	#define _S3D_KER_GEOSECT_EXP __declspec(dllimport)
#endif
