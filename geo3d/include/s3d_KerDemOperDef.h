#pragma once



#ifdef LIB_S3DKERDEMOPER
#define LIB_S3DKERDEMOPER_EXP __declspec(dllexport)
#else
#pragma comment(lib, "s3dKerDemMdl.lib")
#define LIB_S3DKERDEMOPER_EXP __declspec(dllimport)
#endif

#include "gme_vector3.h"
#include <string>

#include "gmeEntity.h"



namespace Smart3dMap
{
	class LIB_S3DKERDEMOPER_EXP CalDemZValBas
	{
	public:
		CalDemZValBas();
		CalDemZValBas(string demFile);
		CalDemZValBas(gmeSurface& demSurf);
		CalDemZValBas(vector<gme_vector3d>& disDots, vector<gme_vector3d>* rgn = nullptr);

		virtual ~CalDemZValBas();

	public:
		virtual int CalZVal(gme_vector3d * pDot) = 0;
		virtual int CalZValXYZ(double dx, double dy, double *pdz) = 0;
		virtual void getSurf(gmeSurface& surf);

	protected:
		std::string  m_demFile;
		gmeSurface	 m_demSurf;
		gme_rect_2d  m_rect;
	};
}