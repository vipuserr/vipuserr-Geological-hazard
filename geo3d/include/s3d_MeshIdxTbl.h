#pragma once
#include <map>
using namespace std;

#include "s3d_KerPosCheckDef.h"
#include "gme_vector3.h"
#include "gmeEntity.h"


namespace Smart3dMap
{

	class  S3DKER_POSCHECK_EXP s3d_TriMeshIdxTbl
	{
	public:
		s3d_TriMeshIdxTbl();
		~s3d_TriMeshIdxTbl();
	public:
		//设置约束数据
		long SetResSurfDatas(gmeSurface * pSurface, gme_rect_2d * pRect);

		//找出点所在的三角形...
		int getTriNoOfDot(gme_vector3d& pnt);
		int operator[](gme_vector3d& pnt);

		//计算交点，返回值为0，则没有交点
		int  CalZValue(gme_vector3d & pnt, double esp = 1e-5);
		//计算所有交点
		int  CalZValueAll(gme_vector3d & pnt, vector<double> &vecdz, double esp = 1e-5);

	private:
		long InitNet();
		void GetIdxNum();
		long CreateIndexMem();
		bool bSearch(gme_vector3d * pdot, long &i, long &j);

	private:
		gme_rect_2d           m_Rect;
		gme_vector3d        * m_pdots;
		gme_triangle        * m_ptris;
		gme_triangle_top    * m_ptops;
		gme_rect_2d         * m_TriRect;
		long            m_ldotnum;
		long            m_ltrinum;
		long            m_inner;
		double          m_Xgap;
		double          m_Ygap;
		bool            m_flag;
		long            m_idxNum;
		double          m_RectX;
		double          m_RectY;
		long            m_allNum;
		long            m_pos;
		double          m_dx;
		double          m_dy;
	private:
		long            m_XNum;
		long            m_YNum;
		long            m_XYNum;
		vector<long> ** m_pXY;
	};

}