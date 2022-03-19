#pragma once

#ifdef _S3D_KERGEOM_SUBSURF_LIB
	#define _S3D_KERGEOM_SUBSURF_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerGeomSubsurf.lib")
	#define _S3D_KERGEOM_SUBSURF_EXP __declspec(dllimport)
#endif

#include <vector>
#include <map>
#include <list>
#include <set>
#include <fstream>
using namespace std;