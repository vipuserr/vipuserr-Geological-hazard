#pragma once

#include "s3d_RgnBase.h"

namespace Smart3dMap
{
	class GEO2DTOOLS_EXPORT s3d_RgnShp : public s3d_RgnBase
	{
	public:
		s3d_RgnShp(const string& path, string fldName="");
		virtual~s3d_RgnShp();


	private:
		void ReadingRegion(__int64 qgsLayer);
		void ReadingLine(__int64 qgsLayer);
	};
}