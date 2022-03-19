#pragma once


#include <osg/vec3f>
#include <osg/vec3d>

#include <vector>
#include <set>
using namespace std;

#include "gmeMdl.h"
#include "s3d_KerDemOperDef.h"
#include "qgsRasterlayer.h"


namespace Smart3dMap
{
	class LIB_S3DKERDEMOPER_EXP TifDem
	{
	public:
		TifDem();
		TifDem(string demFile, bool readAllData = false);
		~TifDem();
	public:
		//读取时选择是否读取全部z数据，若否，则z值相关数据仅调用相关函数时才会读取（暂时提升读取文件的速度）
		int  TifRead(string pFile, bool readAllData);
		int  getzVal(double x, double y, double &z);
		int  getTiffBox(gme_rect_2d &box);
		int  getInterval(double &xInterval, double &yInterval);
		int  getTifWidHeight(int &width, int &height);
		int  getAllPoints(vector<gme_vector3d> &points);
		//int  resamplingTif();

	private:
		double getAveVal();
		double getNullVal();
	
	public:
		enum DataType
		{
			UnknownDataType = 0,
			Byte = 1, //uint8
			Int = 2, 
			Double = 3, //float64
			Float = 4 //!< Complex Float32
		};

	protected:
		void            * m_HeightField;
		float			m_xOri;
		float			m_yOri;
		float           m_xGap;
		float           m_yGap;
		long            m_width;
		long            m_length;

		double			m_dAveVal;
		double			m_dNullVal;

		float           m_xMax;
		float           m_yMax;
		float           m_zMin;
		float           m_zMax;
		DataType        m_qDataType;
		vector<gme_vector3d>    m_HeightPoints;
		QgsRasterLayer* m_RasterLayer;
	};

	class LIB_S3DKERDEMOPER_EXP GetZValFromDem : public CalDemZValBas
	{
	public:
		GetZValFromDem() {}
		GetZValFromDem(string demFile, bool readAllData);
		~GetZValFromDem();
	public:
		virtual int CalZVal(gme_vector3d * pDot);
		virtual int CalZValXYZ(double dx, double dy, double *pdz);
	public:
		TifDem  * m_pDemFile;
	};

}