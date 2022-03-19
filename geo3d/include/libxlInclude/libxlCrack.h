#pragma once
#include "libxl.h"
using namespace libxl;

#ifndef _EXPORT_LIBXLCRACK_DLL_
	#define EXPORT_LIBXLCRACK  _declspec(dllimport)
#else
	#define EXPORT_LIBXLCRACK  _declspec(dllexport)
#endif

enum ExcelType
{
	dotXls=1, dotXlsx
};

#ifdef __cplusplus
extern "C"{
#endif

	EXPORT_LIBXLCRACK Book* xlCreateBookExt(ExcelType type);

#ifdef __cplusplus
}
#endif

#ifndef _EXPORT_LIBXLCRACK_DLL_
	#pragma comment(lib, "libxlCrack.lib")
#endif
