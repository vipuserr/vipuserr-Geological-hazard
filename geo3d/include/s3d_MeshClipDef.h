#pragma once



#ifdef LIB_S3DKERMESH_CLIP
	#define S3DKERMESH_CLIP_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerMeshClip.lib")
	#define S3DKERMESH_CLIP_EXP __declspec(dllimport)
#endif

