#pragma once

#ifdef GEO2DTOOLS_LIB
	#define GEO2DTOOLS_EXPORT __declspec(dllexport)
#else
	#pragma comment(lib, "S3dApp2dTools.lib")
	#define GEO2DTOOLS_EXPORT __declspec(dllimport)
#endif
