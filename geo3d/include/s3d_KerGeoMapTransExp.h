#pragma once

#ifdef _S3D_KER_GEOMAP_TRANS_LIB
	#define _S3D_KER_GEOMAP_TRANS_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerGeoMapTrans.lib")
	#define _S3D_KER_GEOMAP_TRANS_EXP __declspec(dllimport)
#endif
