#pragma once
 
#include <map>
#include <vector>
using namespace std;

#include <s3d_KerGeomSubsurfExp.h>
#include <s3d_KerGeomodelDef.h>
#include <s3d_Queue.h>

namespace Smart3dMap
{
	//子面分割处理类...
	class _S3D_KERGEOM_SUBSURF_EXP s3d_subSurface
	{
	public:
		s3d_subSurface();
		~s3d_subSurface();
	public:
		static int  SplitStdSurfToEnty(gmeSurface *pSurf, gmeEntity * pEnty);

		static int  SplitStdSurf(gmeSurface *pSurf, vector<gmeSurface*> &pSurfVec);
		static void ReleaseDatas(vector<gmeSurface*> &pSurfVec);
	public:
		static int  GetConnectedSurf(char *pTriFlg, gme_triangle_top *pTopos, s3d_QueueCls *pQueue, int Index, char *pVisit);
		static void ReleaseTriDatas(vector<s3d_TriTopos> &VecObj);
		static int  CreateSubSurface(char *pFlag, s3d_TriTopos *pTriTopos, vector<s3d_TriTopos> &AllVec);
		static int  TransformPntIdx(int num, gme_vector3d *pDots, s3d_TriTopos &SurfObj, vector<gme_vector3d> &VecDots);
		static int  GetConnectSurf(char *pFlag, gme_triangle_top *pTopos, s3d_QueueCls *pQueObj, int headIndex, char *pUsed);
	public:
		static void s3dLinkLines(vector<vector<int>> &vec);
		static void CalDotXY(gme_vector3d &a, gme_vector3d &b, gme_vector3d &out, double cof);
		static void CalDotXY_Com(gme_vector3d &a, gme_vector3d &b, gme_vector3d &out, double cof);
		static void PreReatedPnts(vector<gme_vector3d> &DotsVec, vector<int> &SegIdx);
		static int  Sub3dSurface(gmeSurface &surf, double gap, double cof = 0.4);
		static void s3dSearchLines(vector<vector<int>> &vecObj, char *pFlag, int idx, vector<int> &OutVec);


	public:
		// 对三角形进分割处理... 三个顶点的值可能都不一样...
		static int  SubComSurface( gmeSurface &surf,   //传出的交线信息
			                       vector<vector<gme_vector3d>> &vecObj, 
			                       double gap, double cof = 0.4);

		// 对三维边界线进行排序
		static void QsortLines(vector<vector<int>> &vec, vector<TmpStr> &AllSects);

		// 连接所有的三维线数据
		static void s3dLinkAllLines( vector<vector<int>> &vec, 
			                         vector<TmpStr> &AllSects,
			                         vector<int> &straNo );

		// 搜索所有的线数据...
		static void SearchAllLines(vector<vector<int>> &vecObj, vector<TmpStr> &AllSects,
			                       char *pFlag, int idx, vector<int> &OutVec);

		// 利用重构后的三维面、交线，重组得到子面片
		static int  GetSplitSurface(gmeSurface &surf, vector<vector<gme_vector3d>> &vecObj, vector<gmeSurface*> &surfVec);
		
	};

}
