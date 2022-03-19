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
		//������ά���ʽṹģ��
		long set3DGeoModel(gmeModel *geomdl);

		//����������׵�λ��...����x,y������
		long calDummyHole(gme_vector3d* holePos, gmeHole* dummyHole, double esp = 1e-6);
		
	private:
		//�ж������Ƿ���ʵ���ཻ
		bool HitC3DFeature(gmeFeature* pStratFeat, double origin[3], double dir[3], gmeHole* dummyHole, double esp = 1e-6);

		//�ж��������Ƿ��������ཻ�������ؽ���
		BOOL Radial_Tri(double *orig, double *dir,
			double *TriPnt1, double *TriPnt2, double *TriPnt3,
			double *pnt, long *lpPntOnEdge);

		//�ж������Ƿ����Χ���ཻ�������ؽ���
		BOOL HitBoundingBox(double minB[3], double maxB[3], //box
			double origin[3], double dir[3],//ray
			double coord[3]);	//hit point
		//�ڲ��������ж�һ�����Ƿ����������ڲ�
		long IsPntInTriPanel(gme_vector3d *pTryPnt, gme_vector3d *pTriPnt1,
			gme_vector3d *pTriPnt2, gme_vector3d *pTriPnt3,
			long *plPntOnEdge);

		//�����Ĺ�����
		void Normalise3D(double *Vec);

		bool IsSame3DDot(gme_vector3d dot1, gme_vector3d dot2);

		//�ж�ģ���Ƿ���ڶ�ֵ��
		void calMultZValFlag();

	private:
		gmeModel *		m_geoStruMdl;
		gmeHole  *		m_dummyHole;
		gme_vector3d	m_HolePos;
		bool			m_bIsMultZValSurf; //��ֵ��ģ��
	};
}