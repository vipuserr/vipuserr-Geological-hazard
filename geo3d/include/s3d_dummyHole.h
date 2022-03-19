#pragma once

#include "s3d_KerVHoleDef.h"
#include "s3d_KerGeomodelDef.h"
#include "s3d_KerAuxDef.h"
#include "gmeMdl.h"

using namespace Smart3dMap;


namespace Smart3dMap
{
	class LIB_S3DKERVHOLE_EXP  gm_DummyHole
	{
	public:
		gm_DummyHole();
		~gm_DummyHole();

	public:
		//设置三维地质结构模型
		long set3DGeoModel(gmeModel *geomdl);

		//设置虚拟钻孔的位置...根据x,y来计算
		long calDummyHole(gme_vector3d* holePos, gmeHole* dummyHole, double esp = 1e-6);
		
	private:
		//判断射线是否与实体相交
		bool HitC3DFeature(gmeFeature* pStratFeat, double origin[3], double dir[3], gmeHole* dummyHole, double esp = 1e-6);

		//判断三角形是否与射线相交，并返回交点
		BOOL Radial_Tri(double *orig, double *dir,
			double *TriPnt1, double *TriPnt2, double *TriPnt3,
			double *pnt, long *lpPntOnEdge);

		//判断射线是否与包围盒相交，并返回交点
		BOOL HitBoundingBox(double minB[3], double maxB[3], //box
			double origin[3], double dir[3],//ray
			double coord[3]);	//hit point
		//内部方法，判断一个点是否在三角形内部
		long IsPntInTriPanel(gme_vector3d *pTryPnt, gme_vector3d *pTriPnt1,
			gme_vector3d *pTriPnt2, gme_vector3d *pTriPnt3,
			long *plPntOnEdge);

		//向量的规正化
		void Normalise3D(double *Vec);

		bool IsSame3DDot(gme_vector3d dot1, gme_vector3d dot2);

		//判断模型是否存在多值面
		void calMultZValFlag();

	private:
		gmeModel *		m_geoStruMdl;
		gmeHole  *		m_dummyHole;
		gme_vector3d	m_HolePos;
		bool			m_bIsMultZValSurf; //多值面模型
	};
}