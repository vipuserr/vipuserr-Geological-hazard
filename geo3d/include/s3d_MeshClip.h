#pragma once

#include "s3d_MeshClipDef.h"
#include "gmeEntity.h"


namespace Smart3dMap
{
	class s3d_InnerObbt;
	class s3d_InsectSurf;
	class s3d_PosCheckBase;

	enum MeshClipType
	{
		UNKNOWN_CLIP = 1,	//1面切面
		SURF_CLIP_SURF = 1,	//1面切面
		SURF_CLIP_ENT = 2,	//2面切体
		ENT_CLIP_ENT = 3,	//3体切体
		ENT_CLIP_SURF = 4,	//4体切面
	};

	class S3DKERMESH_CLIP_EXP s3d_MeshCut
	{
	public:
		s3d_MeshCut();
		~s3d_MeshCut();

	public:
		// 面切体，只生成剖切面 
		int CutEntityBySurf(gmeSurface* pSurf,	//输入的面
							gmeEntity* pEnty,	//输入的体
							vector<gmeSurface*>* pSurfVec);//裁剪结果剖面

		// 面切体，生成左右地层体模型
		int CutEntityBySurf(gmeSurface* pSurf, gmeEntity* pEnty,//输入的面和体
							vector<gmeEntity*>* pEntyOut1,//裁剪结果法向同侧剩余体, 可传NULL
							vector<gmeEntity*>* pEntyOut2,//裁剪结果法向异侧剩余体, 可传NULL
							vector<gme_vector2d>* polylin=nullptr);//用于分边的折线, 可传NULL

		//面切面,生成左右两部分面
		int CutSurfaceBySurface(gmeSurface * pSurfA,//传入互切的三维面数据
								gmeSurface * pSurfB,//传入互切的三维面数据
								vector<gmeSurface*>* pSurfAVec = NULL,//A被B切割后，剩余的面A1, A2,... An
								vector<gmeSurface*>* pSurfBVec = NULL,//B被A切割后，剩余的面B1, B2,... Bn
								vector<vector<gme_vector3d>>* pInseLins = NULL);//面面交线
		//面列表切面列表
		int CutSurfacesBySurfaces(vector<gmeSurface*>    &pSurfA,//传入互切的三维面数据
								  vector<gmeSurface*>    &pSurfB,//传入互切的三维面数据
								  vector<gmeSurface*>    *pSurfAVec = NULL,//A被B切割后，剩余的面A1, A2,... An
								  vector<gmeSurface*>    *pSurfBVec = NULL,//B被A切割后，剩余的面B1, B2,... Bn
								  vector<vector<gme_vector3d>>   *pInseLins = NULL);//切割后交线

		//体切体
		int CutEntityByEntity(gmeEntity* entA, gmeEntity* entB,//传入互切的三维体
							  vector<gmeSurface*>  *pSurfAInB,	//A-B
							  vector<gmeSurface*>  *pSurfAOutB,	//B-A
							  vector<gmeSurface*>  *pSurfBInA,	//交集
							  vector<gmeSurface*>  *pSurfBOutA);//并集

		//体切体
		long CutEntityByEntity( gmeEntity* entA, gmeEntity* entB,//传入互切的三维体
								vector<gmeEntity*>   *pEntyAOutB,    //A-B
								vector<gmeEntity*>   *pEntyBOutA,    //B-A
								vector<gmeEntity*>   *pEntyABInters, //交集
								vector<gmeEntity*>   *pEntyABUnion); //并集

	public:
		//设置模型变换标志
		void setMeshTransFlag(bool meshTransFlag = true);
		void getMeshTransFlag(bool &meshTransFlag);

		//设置容差
		void setTolerance(double esp = 1e-5);
		void getTolerance(double& esp);

		//设置剖面分边方法
		void setSlpitMethod(bool useIntersectPolylin = 1);
		void getSlpitMethod(bool& useIntersectPolylin);


		//加载网格数据
		int loadClipMesh(gmeSurface *pSurfA, gmeSurface *pSurfB);
		int loadClipMesh(gmeSurface *pSurfA, gmeEntity  *pEntyB);
		int loadClipMesh(gmeEntity  *pEntyA, gmeEntity  *pEntyB);
		int loadClipMesh(vector<gmeSurface*> &sf1, vector<gmeSurface*> &sf2);

		//释放数据
		void ReleaseDatas(vector<gmeSurface*>    *pSurfVec);
		void ReleaseDatas(vector<gmeEntity*>     *pEntyVec);

	private:
		//网格分割为两部分(子面整体分边)
		int SplitSurfs(vector<gmeSurface*>* pSurfs, vector<gmeSurface*>* pSurfsIn, vector<gmeSurface*>* pSurfsOut, s3d_PosCheckBase *pCheck);
		//网格分割为两部分（子面按三角形进行分边)
		int SplitSurfs2(vector<gmeSurface*>* pSurfs, vector<gmeSurface*>* pSurfsIn, vector<gmeSurface*>* pSurfsOut, s3d_PosCheckBase *pCheck);

		//索引更新
		int meshIdxUpdate(int idx, s3d_InsectSurf *pIt, map<int, vector<int>> &mp);

		//面面相交处理
		int clipSurfBySurf(int surfIdxA, int surfIdxB);
		int clipSurfsBySurfs();

		//面面重建处理
		int rebuildSurf(s3d_InsectSurf* surf, bool bSplit = true);
		int rebuildSurfs(bool bRebuildMeshA = true, bool bSpiltMeshA = true, bool bRebuildMeshB = true, bool bSpiltMeshB = true);

		int  CalInsetLins(vector<vector<gme_vector3d>> *pInseLins);

		//补齐缺口，将线段封闭为多边形（列表）
		int  CloseInsetLins(double esp = 1e-2);
		int  CloseInsetLins2(double esp = 1e-2);

		//清除切割中的缓冲
		void clearClipBuffer();

	private:
		//网格A的数据与参数
		bool                m_bCutMeshA; //是否执行剪切重构
		bool                m_splitMeshA;//是否对重构后的面进行分离
		gme_rect_3d         m_meshBoxA;	//网格包围盒
		s3d_InnerObbt*		m_pObbtA;	//网格obb树
		int                 m_surfNumA;	//网格内曲面数量
		gmeSurface**		m_surfsMeshA; //网格曲面指针列表
		s3d_InsectSurf**	m_insectMeshA;//网格相交处理对象
		s3d_PosCheckBase*	m_posCheckA;  //网格分边对象	

		//网格B的数据与参数
		bool                m_bCutMeshB; //是否执行剪切重构
		bool                m_splitMeshB;//是否对重构后的面进行分离
		gme_rect_3d         m_meshBoxB;	//网格包围盒
		s3d_InnerObbt*		m_pObbtB;	//网格obb树
		int                 m_surfNumB;	//网格内曲面数量
		gmeSurface**		m_surfsMeshB; //网格曲面指针列表
		s3d_InsectSurf**	m_insectMeshB;//网格相交处理对象
		s3d_PosCheckBase*	m_posCheckB;  //网格分边对象

		double              m_meshPrec;//数据容差
		MeshClipType        m_meshClipType;//1面面2面体3体体
		vector<gme_vector3d> m_intersectDots; //交点集
		int*				m_meshDotIdx;//网格顶点索引?
		vector<int>         m_meshSegIdx;//网格交点索引?
		bool				m_meshTransFlag; //网格是否进行平移缩放变换

		bool				m_useIntersectPolylin;//使用闭合交线进行分边
	};

}