#pragma once
#include <map>
using namespace std;

#include "s3d_MeshIntersectDef.h"
#include "gme_vector3.h"
#include "gmeEntity.h"
#include "s3d_Queue.h"
#include "s3d_TriObbt.h"


namespace Smart3dMap
{

	typedef vector<long>	            s3d_DotNoList;
	typedef vector<s3d_DotNoList>	    s3d_CutTrisList;

	// 三角形相交结果
	struct s3d_InterLines
	{
		gme_vector3d   d3dt1;
		gme_vector3d   d3dt2;
	};

	struct s3d_TriEdge
	{
		int             nTriNo; //三角形序号
		char            nEdge;  //边序号：1、2、3
		gme_vector3d    d3dot;  //交点坐标
	};



	struct StruTopo
	{
		gme_triangle       * pTris;   //三角形
		gme_triangle_top   * pTopos;  //三角形top
		int                  TriNum;  //三角形数目
		StruTopo()
		{
			pTris = NULL;
			pTopos = NULL;
			TriNum = 0;
		}
	};


	//三角形相交计算
	class  S3DKER_MESH_INTERSECTION_EXP  s3d_MeshIntersect
	{
	public:
		s3d_MeshIntersect(s3d_ObbtImpact *pObbtImpact);
		virtual ~s3d_MeshIntersect();

	public:
		void SetSplitFlg(bool splitA = true, bool splitB = true);
		int  CalSectLines(double desp = 1e-5);
		int  GetIntersetcPntsFromTriPair(int lCutTriIdx, s3d_InterLines &inteDot, double desp = 1e-5);
		int  IntersetPntsAnalyse(gme_vector3d * pdots, int *pflg, int num, s3d_InterLines &inteDot, double desp = 1e-5);

	public:
		bool                 m_splitA;   //是否对A进行裁剪重构：B裁切A
		bool                 m_splitB;   //是否对B进行裁剪重构：A裁切B
		bool                 m_bCutA;    //是否对重构后的A进行分离
		bool                 m_bCutB;    //是否对重构后的B进行分离

		s3d_ObbtImpact     * m_pImpact;  //碰撞检测对象
		gmeSurface         * m_pOriSurfA;//原始面A
		gmeSurface         * m_pOriSurfB;//原始面B
		vector<int>          m_meshSegIdx;   //交线边的点索引（2倍的边数）
		vector<gme_vector3d> m_intersectDots;//交点序列
		vector<s3d_TriEdge>  m_TriEdgeA; //面A三角形边列表
		vector<s3d_TriEdge>  m_TriEdgeB; //面B三角形边列表
		map<int, vector<int>> m_lineTinA; //每个三角形对应的交线
		map<int, vector<int>> m_lineTinB; //每个三角形对应的交线
	};

	//分类
	class  S3DKER_MESH_INTERSECTION_EXP s3d_MeshClassify
	{
	public:
		s3d_MeshClassify(gmeSurface *psurf);
		~s3d_MeshClassify();
	public:
		void initdatas(gme_vector3d * pdots, vector<int> *lines);
		int  SplitSurface(vector<gmeSurface*> &vecOut);
		void ReleaseTriDatas(vector<StruTopo> &VecObj);
		int  SplitStdSurf(gmeSurface *pSurf, vector<gmeSurface *> &vecOut);
		int  CreateSubSurface(char *pFlag, StruTopo *pTriTopos, vector<StruTopo> &AllVec);
		int  TransformPntIdx(int num, gme_vector3d *pDots, StruTopo &SurfObj, vector<gme_vector3d> &VecDots);
		int  GetConnectSurf(char *pFlag, gme_triangle_top *pTopos, s3d_QueueCls *pQueObj, int headIndex, char *pUsed);

	public:
		vector<int>       * m_pLinIdx;
		gme_vector3d      * m_pInseDot;
		gmeSurface        * m_pCurSurf;
	};

	//相交面对象:
	class  S3DKER_MESH_INTERSECTION_EXP  s3d_InsectSurf
	{
	public:
		s3d_InsectSurf(gmeSurface * pSurf);
		~s3d_InsectSurf();
	public:
		static void CalRepeatedPoints(vector<gme_vector3d> &DotsVec,
			vector<int>   &SegIdx,
			int  * pIdx = NULL,
			double desp = 1e-5);
	public:
		bool isNeedRebuild();
		void setDatas(int  *pIdx, vector<int> *pSegIdx, vector<gme_vector3d> * pDotsVec);
		int  UpdateLineTinNo();
		void DealTriEdges();
		void DealRepeatedEdges();
		int  RebuildTinNets(double desp = 1e-5);
		int  GetSplitNewSurface(bool bSplit=true);

	public:
		void SortTriEdges(gme_vector3d *pA, gme_vector3d *pB, vector<int> &vNo,
			vector<s3d_TriEdge> &TriEdge, vector<gme_vector3d> &Tridots, vector<int> &segment);

		int  BuildTriTins(gme_vector3d *ptris, vector<gme_vector3d>  &TriEdgedots,
			vector<int> &EdgeSegment, vector<gme_vector3d> &ppTriPnt, vector<gme_triangle> &ppTrisNo);

		int  UpdateTriangles(gmeSurface           *pSurf,
			gmeSurface          **pOutSur,
			vector<s3d_TriEdge>  &TriEdge,
			vector<gme_vector3d> &AllDotsVec,
			map<int, vector<int>> &InnerLines, double desp = 1e-5);

		int  FindSameDots(gmeSurface *pSurf);

	public:
		int                  * m_pIdx;
		vector<int>          * m_pSegIdx;
		vector<gme_vector3d> * m_pDotsVec;
		vector<s3d_TriEdge>    m_TriEdge;
		map<int, vector<int>>   m_lineTin;

	public:
		s3d_MeshClassify     * m_pClassify;   //分类处理...
		gmeSurface           * m_pOriSurf;    //原始面
		gmeSurface           * m_pNewSurf;    //重构后新面:内部申请
		vector<gmeSurface*>    m_SplitSurf;   //分离后的面:内部申请
	};

}