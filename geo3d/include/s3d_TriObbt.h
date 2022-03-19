#pragma once

#include "s3d_KerPosCheckDef.h"
#include "gmeEntity.h"


namespace Smart3dMap
{
	struct s3d_TriCutPair
	{
		int		lTri1;
		int		lTri2;
	};

	//方向包围盒树
	class   S3DKER_POSCHECK_EXP  s3d_InnerObbt
	{
	public:
		s3d_InnerObbt();
		virtual ~s3d_InnerObbt();

	public:
		void Builds3d_MeshObbt(gmeSurface* pSurface);
		int  GetSubMeshNum() { return 0; }

		int  Builds3d_MeshObbt(const double *pTris, int lTriNum);
		int  Builds3d_MeshObbt(const double *pTrisDot1, const double *pTrisDot2, const double *pTrisDot3, int lTriNum);
		int  BuildDiscDotsObbt(const double *pDots, int lDotsNum);

		int  GetTriNumOfObbt();
		void GetTriDotOfObbt(gme_vector3d *pTriDots, int  lTriNo);
		void GetObbtOfModel(gme_vector3d* pBoxCenter, double *pAxisLen, gme_vector3d* pAxisXYZ);
		void Calcs3d_MeshAABB();

		int  CheckMesh();
		int  SetDataPrec(double dDataPrec);
		int  GetDataPrec(double &dDataPrec);

	private:
		int  BuildObbt();
		void CreateObbtObj();
		void DeleteObbtObj();
		int  Add1TriToObbt(const double *Pnt1, const double *Pnt2, const double *Pnt3, int lTriNo);

	public:
		void*				m_obbtObj;      //快速检测对象类
		gme_rect_3d		    m_meshBox;      //Smart3dMap对象的包围盒
		gme_vector3d		m_dOffset;      //内部偏移对象
		double				m_dDataPrec;    //内部容差
		gmeSurface*			m_pOriMesh;     //Smart3dMap对象装载的原始面数据，
	};
	
	//碰撞检测
	class  S3DKER_POSCHECK_EXP s3d_ObbtImpact
	{
	public:
		s3d_ObbtImpact();
		~s3d_ObbtImpact();

	public:
		//碰撞检测判断
		int  ObbImpact(s3d_InnerObbt*pObbt1, s3d_InnerObbt*pObbt2, double *pR1 = NULL, double *pR2 = NULL,
			double *pT1 = NULL, double *pT2 = NULL, double  dS1 = 1, double  dS2 = 1);

		int  GetImpactTriPair(s3d_TriCutPair **ppTriPairs, int *pPairNum);

	public:
		s3d_TriCutPair        * m_pTriPair;       //记录相交三角形对
		int			          m_TriPairNum;       //相交三角形对的数目

		s3d_InnerObbt          * m_pObbt1;          //obb1的相关数据
		s3d_InnerObbt          * m_pObbt2;          //obb2的相关数据
	};


}