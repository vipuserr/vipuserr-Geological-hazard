#pragma once



#ifdef S3D_KERAUX_LIB
	#define S3D_KERAUX_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "S3dAppAux.lib")
	#define S3D_KERAUX_EXP __declspec(dllimport)
#endif


