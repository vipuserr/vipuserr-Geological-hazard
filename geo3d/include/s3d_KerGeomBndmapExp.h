#pragma once

#ifdef _S3D_KERGEOM_BNDMAP_LIB
	#define _S3D_KERGEOM_BNDMAP_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerGeomBndmap.lib")
	#define _S3D_KERGEOM_BNDMAP_EXP __declspec(dllimport)
#endif

#include <vector>
#include <map>
#include <list>
#include <set>
#include <fstream>
using namespace std;