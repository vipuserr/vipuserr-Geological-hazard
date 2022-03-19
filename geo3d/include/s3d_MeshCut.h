#pragma once

#include "s3d_KerMdlAnalysisDef.h"
#include "s3d_PosCheck.h"
#include "s3d_MeshIntersect.h"

namespace Smart3dMap
{

	class S3DKERMDLANALYSIS_EXP s3d_MeshCut
	{
	public:
		s3d_MeshCut();
		~s3d_MeshCut();

	public:
		// 面切体，生成剖切面 
		int CutMeshEntityByPlanSurf(gmeSurface *pSurf,//三维面
									gmeEntity *pEnty,//三维体
									vector<gmeSurface*> *pSurfVec);//结果剖面
		// 面切体，生成左右地层体模型
		int CutMeshEntityByPlanSurf(gmeSurface *pSurf, gmeEntity *pEnty,
									vector<gmeEntity*>   * pEntyOut1,  //法向同侧剩余体，可传NULL
									vector<gmeEntity*>   * pEntyOut2,
									vector<gme_vector2d>*  polylin=nullptr); //法向异侧剩余体，可传NULL
		// 面切体，生成剖切面-2021-5-7 针对第三方错乱模型 
		int CutMeshEntityByPlanSurf_1(gmeSurface *pSurf, gmeEntity *pEnty, vector<gmeSurface*> *pSurfVec);

		int CutMeshSurfaceBySurface(gmeSurface * pSurfA,//传入互切的三维面数据
									gmeSurface * pSurfB,//传入互切的三维面数据
									vector<gmeSurface*>    *pSurfAVec = NULL,//A被B切割后，剩余的面A1, A2,... An
									vector<gmeSurface*>    *pSurfBVec = NULL,//B被A切割后，剩余的面B1, B2,... Bn
									vector<vector<gme_vector3d>> *pInseLins = NULL);//面面交线

		int CutMeshSurfacesBySurfaces(vector<gmeSurface*>    &pSurfA,//传入互切的三维面数据
									  vector<gmeSurface*>    &pSurfB,//传入互切的三维面数据
									  vector<gmeSurface*>    *pSurfAVec = NULL,//A被B切割后，剩余的面A1, A2,... An
									  vector<gmeSurface*>    *pSurfBVec = NULL,//B被A切割后，剩余的面B1, B2,... Bn
									  vector<vector<gme_vector3d>>   *pInseLins = NULL);


		int CutMeshEntityBySurface( gmeSurface * pSurfA,//三维面
									gmeEntity  * pSurfB,//三维体
									vector<gmeSurface*>  *pSurfAInB,
									vector<gmeSurface*>  *pSurfAOutB,
									vector<gmeSurface*>  *pSurfBleft,
									vector<gmeSurface*>  *pSurfBright);

		long CutEntityByEntity( gmeEntity *pEntyA, gmeEntity *pEntyB,
								vector<gmeEntity*>   *pEntyAOutB,    //A-B
								vector<gmeEntity*>   *pEntyBOutA,    //B-A
								vector<gmeEntity*>   *pEntyABInters, //交集
								vector<gmeEntity*>   *pEntyABUnion); //并集

		int CutMeshEntityByEntity( gmeEntity  * pSurfA,
								   gmeEntity  * pEntyB,
								   vector<gmeSurface*>  *pSurfAInB,
								   vector<gmeSurface*>  *pSurfAOutB,
								   vector<gmeSurface*>  *pSurfBInA,
								   vector<gmeSurface*>  *pSurfBOutA);

		long GetSectlines(vector<vector<gme_vector3d>> &lines);

	public:
		// 设置容差
		void setToler(double esp = 1e-5);
		void clear();
		int  loadDatas(gmeSurface *pSurfA, gmeSurface *pSurfB);
		int  loadDatas(gmeSurface *pSurfA, gmeEntity  *pEntyB);
		int  loadDatas(gmeEntity  *pEntyA, gmeEntity  *pEntyB);
		int  loadDatas(vector<gmeSurface*> &sf1, vector<gmeSurface*> &sf2);

		int  SplitSurfs( vector<gmeSurface*>  *pSurfs,
						 vector<gmeSurface*>  *pSurfsIn, //同侧
						 vector<gmeSurface*>  *pSurfsOut,//异侧
						 PosCheckBase         *pCheck);

		//执行面面相交处理
		int SurfCutBySurf();
		int DoSurfCutBySurf(int idxA, int idxB);

		//执行面面重建处理
		int RebuildSurf( bool bA = true, 
						 bool rA = true, 
						 bool bB = true,
						 bool rB = true );

		int DoRebuildSurf(s3d_InsectSurf * surf, bool bSplit = true);

		//索引更新
		int IdxUpdate(int idx, s3d_InsectSurf *pIt, map<int, vector<int>> &mp);

		//释放数据
		void ReleaseDatas(vector<gmeSurface*>    *pSurfVec);
		void ReleaseDatas(vector<gmeEntity*>     *pEntyVec);
		int  CalInsetLins(vector<vector<gme_vector3d>> *pInseLins);
		int  CloseInsetLins(double esp = 1e-2);

	private:
		bool                 m_cutA;     //是否执行剪切重构
		bool                 m_cutB;     //是否执行剪切重构
		bool                 m_splitA;   //是否对重构后的面进行分离
		bool                 m_splitB;   //是否对重构后的面进行分离
		double               m_esp;      //容差  
		char                 m_type;     //1面面2面体3体体
		int                * m_pIdx;
		vector<int>          m_SegIdx;   //交点索引
		vector<gme_vector3d> m_DotsVec;  //交点集
		int                  m_numA;
		int                  m_numB;
		gme_rect_3d          m_BoxA;
		gme_rect_3d          m_BoxB;
		s3d_InnerObbt       * m_pObbtA;
		s3d_InnerObbt       * m_pObbtB;
		gmeSurface        ** m_pSurfA;
		gmeSurface        ** m_pSurfB;
		s3d_InsectSurf        ** m_pInsectA;
		s3d_InsectSurf        ** m_pInsectB;
		PosCheckBase       * m_EntyA;
		PosCheckBase       * m_EntyB;
	};

}