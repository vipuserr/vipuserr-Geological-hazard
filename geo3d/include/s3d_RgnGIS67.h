#pragma once

#include "s3d_RgnBase.h"
#include<s3d_mapgisfile_slib.h>

namespace Smart3dMap
{
	class  GEO2DTOOLS_EXPORT s3d_RgnGIS67 : public s3d_RgnBase
	{
	public:
		s3d_RgnGIS67(const string& path, string fldName = "");
		virtual~s3d_RgnGIS67();


	private:
		void ReadingRegion(std::string urlPath);
		void ReadingLine(std::string urlPath);

	private:
		string							mGis67SlibPath;
		gm_mapgis_slib					m_gisSlib;
	};

}