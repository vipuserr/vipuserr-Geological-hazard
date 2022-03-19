#pragma once

#include "s3d_KerSurfOperDef.h"

#include "gmeMdl.h"

namespace Smart3dMap 
{

	void LIB_S3DKERSURFOPER_EXP build_tense_surf(
					gmeSurface& outSurf, 
					vector<gme_vector3d>& distDots, vector<gme_vector2d>& outerBound, vector<vector<gme_vector2d>>& InnerBound,
					vector<vector<gme_vector2d>>& trendLin, vector<vector<gme_vector2d>>& terrainLin);

}
