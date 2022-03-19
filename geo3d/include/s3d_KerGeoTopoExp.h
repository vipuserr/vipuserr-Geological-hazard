#pragma once

#ifdef _S3D_KERGEOTOPO_LIB
	#define _S3D_KERGEOTOPO_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerGeoTopo.lib")
	#define _S3D_KERGEOTOPO_EXP __declspec(dllimport)
#endif