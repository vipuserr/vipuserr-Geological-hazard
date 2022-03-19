#pragma once

#ifdef _S3D_KERGEOM_HOLEPRO_LIB
	#define _S3D_KERGEOM_HOLEPRO_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerGeomHolePro.lib")
	#define _S3D_KERGEOM_HOLEPRO_EXP __declspec(dllimport)
#endif

#include <vector>
#include <map>
#include <list>
#include <set>
#include <fstream>
using namespace std;