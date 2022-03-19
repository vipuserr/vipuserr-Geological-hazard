#pragma once

#ifdef _S3D_S3DKERGEOMDLING_LIB
	#define _S3D_S3DKERGEOMDLING_EXP __declspec(dllexport)
#else
	#pragma comment(lib, "s3dKerGeomdling.lib")
	#define _S3D_S3DKERGEOMDLING_EXP __declspec(dllimport)
#endif

#include <vector>
#include <map>
#include <list>
#include <set>
#include <fstream>
using namespace std;