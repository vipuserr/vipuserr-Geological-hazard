#pragma once

#include "s3d_KerPosCheckDef.h"
#include "s3d_MeshIdxTbl.h"

namespace Smart3dMap
{

	class  S3DKER_POSCHECK_EXP s3d_PosCheckBase
	{
	public:
		s3d_PosCheckBase() {}
		virtual ~s3d_PosCheckBase() {}
	public:
		virtual int CheckPos(gme_vector3d *pdot) = 0;
		virtual int CheckSurfPos(gmeSurface * pSurf);

	public:
		gme_vector3d getDotInSurf(gmeSurface* surf);
	};

	//位置关系判断类... 点与曲线的位置关系判断...
	class  S3DKER_POSCHECK_EXP s3d_PosCheckCurv : public s3d_PosCheckBase
	{
	public:
		s3d_PosCheckCurv(vector<gme_vector2d>* polylin);
		virtual  ~s3d_PosCheckCurv();
	public:
		//位置关系 1在参考点同侧，-1在异侧，0在表面上...
		int CheckPos(gme_vector3d *pdot);

	public:
		vector<gme_vector2d> m_polylin;
	};

	//位置关系判断类... 点与平面的位置关系判断...
	class  S3DKER_POSCHECK_EXP s3d_PosCheckPlan : public s3d_PosCheckBase
	{
	public:
		s3d_PosCheckPlan(gmeSurface *pSurf);
		s3d_PosCheckPlan(gme_vector3d planDot[3]);
		s3d_PosCheckPlan(double planCoef[4]);

		virtual  ~s3d_PosCheckPlan();
	public:
		//位置关系 1在参考点同侧，-1在异侧，0在表面上...
		int  CheckPos(gme_vector3d *pdot);

	private:
		int  CalInitdatas();

	public:
		gmeSurface  * m_surf;
		double        m_plan[4];
	};

	//位置关系判断类... 点与体的位置关系判断...
	class  S3DKER_POSCHECK_EXP s3d_PosCheckEntity : public s3d_PosCheckBase
	{
	public:
		s3d_PosCheckEntity(gmeEntity *pEnty);
		~s3d_PosCheckEntity();

	public:
		//位置关系 1在体内，-1在体外，0在体的表面上...
		int  CheckPos(gme_vector3d *pdot);

	private:
		// 创建每个层面三角形与网格的索引表
		int  createIdxTbl();

	public:
		bool               m_bFlag;
		gme_rect_2d        m_2Rect;
		gme_rect_3d        m_3Rect;
		gmeEntity        * m_pEnty;

		vector<double>       m_dzVec;
		vector<gme_rect_2d>  m_RectVec;
		vector<s3d_TriMeshIdxTbl*>    m_dzClsVec;
	};


}