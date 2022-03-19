#pragma once

#ifndef BUILD_STATIC
# if defined(GEOGME23DTILES)
#  define GEOGME23DTILES_EXPORT __declspec(dllexport)
# else
#  define GEOGME23DTILES_EXPORT __declspec(dllimport)
# endif
#else
# define GEOGME23DTILES_EXPORT
#endif

#ifndef GEOGME23DTILES 
#pragma comment(lib, "S3dAppGme23DTiles.lib")
#endif
