#pragma once

#ifdef _S3D_KERGEOM_BASLAYERPRO_LIB
	#define _S3D_KERGEOM_BASLAYERPRO_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerGeomBaslayerPro.lib")
	#define _S3D_KERGEOM_BASLAYERPRO_EXP __declspec(dllimport)
#endif

#include <vector>
#include <map>
#include <list>
#include <set>
#include <fstream>
using namespace std;