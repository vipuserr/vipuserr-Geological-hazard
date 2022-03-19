#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
	#if defined(GEODATAMNG_LIB)
		#define GEODATAMNG_EXPORT Q_DECL_EXPORT
	#else
#define GEODATAMNG_EXPORT Q_DECL_IMPORT
	#endif
#else
	#define GEODATAMNG_EXPORT
#endif

#ifndef GEODATAMNG_LIB
	#pragma comment(lib, "GeoDataMng.lib")
#endif
