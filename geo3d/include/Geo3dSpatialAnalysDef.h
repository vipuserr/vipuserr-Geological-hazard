#pragma once




#ifdef VECSPATIALANALYS_LIB
	#define VECSPATIALANALYS_EXPORT __declspec(dllexport)
#else
	#define VECSPATIALANALYS_EXPORT __declspec(dllimport)
#endif

#ifndef VECSPATIALANALYS_LIB
	#pragma comment(lib, "S3dKerSpatialAna.lib")
#endif
