#pragma once

namespace Smart3dMap
{

}

#ifdef LIB_S3DKER_MESH_INTERSECTION
	#define S3DKER_MESH_INTERSECTION_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerClipMeshIntersect.lib")
	#define S3DKER_MESH_INTERSECTION_EXP __declspec(dllimport)
#endif

