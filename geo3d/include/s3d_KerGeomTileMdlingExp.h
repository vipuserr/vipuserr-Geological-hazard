#pragma once

#ifdef _S3D_KERGEOMTILEMDLING_LIB
	#define _S3D_KERGEOMTILEMDLING_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerGeomTileMdling.lib")
	#define _S3D_KERGEOMTILEMDLING_EXP __declspec(dllimport)
#endif

#include <vector>
#include <map>
#include <list>
#include <set>
#include <fstream>
using namespace std;