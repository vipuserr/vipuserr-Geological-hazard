#pragma once

#include <vector>
#include <map>
#include <list>
#include <set>
using namespace std;

#include <s3d_KerGeoTopoExp.h>
#include <s3d_GeomDefine.h>


namespace Smart3dMap
{
	typedef vector<int>				s3d_PolyArc;//多边形包含的弧段列表
	typedef vector<s3d_PolyArc>		s3d_RgnArc; //区包括的多边形列表（多边形由弧段构成）
	typedef vector<gme_vector2d>         s3d_2DPoly;//多边形
	typedef vector<s3d_2DPoly>           s3d_2DRgn;//区（包含内外边界多边形）

	// 区与其边界线的拓扑关系类
	class _S3D_KERGEOTOPO_EXP s3d_2DRgnTopo
	{
	public:
		//s3d_2DPoly表示区的1个边界，vector<s3d_2DPoly>表示区的所有内外边界, vector<vector<s3d_2DPoly>>表示所有区的边界
		s3d_2DRgnTopo(vector<s3d_2DRgn>* RgnVecs, bool treatRegAsASingleSeg=true);
		~s3d_2DRgnTopo(void);

	public:
		//1.获得所有弧段的数目
		int   GetArcsNum();

		//2.获得所有区的数目
		int   GetRgnsNum();

		//3.获得区对应的弧段ID串 从0开始
		bool  RgnGetArcIDs2(int RgnID, vector<int>  &ArcIDs);//弧段号进行了排序
		bool  RgnGetArcIDs(int RgnID, vector<int>  &ArcIDs);//弧段号没有排序
		bool  RgnGetArcIDs2(int RgnID, vector<s3d_PolyArc>  &polyArcIDs);//每一个区的弧段号列表，按照圈来组织弧段
		bool  RgnGetArcIDs(int RgnID, vector<s3d_PolyArc>  &polyArcIDs);//每一个区的弧段号列表，按照圈来组织弧段

		//4.获得弧段关联的区ID串
		bool  ArcGetRgnIDs(int ArcID, vector<int>  &RgnIDs);

		//5.获得询弧段对应的点
		bool  ArcGetAnyLine(int ArcID, vector<gme_vector2d> &ArcLin);
		bool  ArcGetEndDots(int ArcID, vector<gme_vector2d> &endDots);
		//取出弧段上的点数
		long  ArcGetAnyLineDotNum(int ArcID);

		//6.获得所有弧段，vvlins为边界弧段，linsOver为公共弧段
		void  GetAllArcLins(vector<vector<gme_vector2d>> &vvlins, vector<vector<gme_vector2d>> &linsOver);
		void  GetAllArcLins(vector<vector<gme_vector2d>> &alllins);

		//7.根据单点的坐标获取其对应的弧段号串
		void GetArcNoByDot(gme_vector2d& dot, vector<int> &ArcIDs);

		//8. 更新弧段的点数据,如果是端點，則同時自動更新相鄰弧段的端點。
		void UpdateArcDot(int ArcID, long dotIndex, gme_vector2d &dot);//单点更新
		void UpdateArcDots(int ArcID, vector<gme_vector2d> &ArcLin); //整个弧段更新

		//9. 设置区的地层属性
		void SetRgnStratCode(vector<std::string>& stratCodeList);
		std::string GetRgnStratCode(int RgnID);

		//10. 取出区弧段中的结点列表
		void GetRegNodes(vector<gme_vector2d> &regNodes);

	private:
		// 构造top相关信息
		void ConstructRgnTopos();
		//直接整个区转化为弧段
		void Reg2Seg_simple();
		//对围成多边形的弧段进行排序
		void sortPolyArcs(s3d_PolyArc& ArcIDs);
		//计算出区弧段上的结点
		void calRegNodes();
	private:
		vector<s3d_2DRgn>*				  m_RgnVecs; //所有区的边界
		int                               m_ArcNum;     //弧段总数
		int                               m_RgnNum;     //区总数
		vector<s3d_2DRgn>                 m_RgnBndy;    //区多边形
		vector<vector<gme_vector2d>>      m_vvlins;     //非重叠弧段
		vector<vector<gme_vector2d>>      m_linsOver;   //重叠弧段
		vector<vector<gme_vector2d>>      m_allLines;   //所有弧段
		vector<gme_rect_2d>               m_RgnRect;    //区rect
		vector<gme_rect_2d>               m_ArcsRect;   //弧段rect
		vector<std::string>				  m_stratCodeList;//区的地层属性
		vector<vector<int>>	              m_arcRegs; //弧段对应的区列表
		vector<vector<int>>				  m_regArcs; //区包含的弧段列表
		vector<s3d_RgnArc>			  m_regArcs2; //区包含的弧段列表
		vector<gme_vector2d>		  m_regNodes;  //结点列表：构成区的弧段的两个端点列表，要去重...
		bool						  m_bTreatRegAsASingleSeg;
	};

	typedef vector<gme_vector3d>         s3d_3DLine;
	typedef vector<s3d_3DLine>           s3d_3DPoly;
	// 三维面与其边界线的拓扑关系类
	class _S3D_KERGEOTOPO_EXP s3d_SurfTopoInner
	{
	public:
		s3d_SurfTopoInner(vector<gmeSurface*> &SurfVecs);
		~s3d_SurfTopoInner(void);

	public:
		//1.获取所有的边界线数目
		int   GetArcsNum();

		//2.获取所有面的数目
		int   GetSurfsNum();

		//3.查询三维面对应的边界线ID
		bool  SurfGetArcIDs(int SurfID, vector<int>  &ArcIDs);

		//4.查找边界线关联的三维面ID
		bool  ArcGetSurfIDs(int ArcID, vector<int>  &SurfIDs);

		//5.查询弧段对应的数据
		bool  ArcGetAnyLine(int ArcID, vector<gme_vector3d> &polylin);

		//6.获得所有边界线
		void  GetAllArcLins(vector<vector<gme_vector3d>> &vvlins,
			vector<vector<gme_vector3d>> &linsOver);

	private:
		// 构造top相关信息
		void  ConstructSurfTopos();

	private:
		int                               m_ArcNum;      //弧段总数
		int                               m_PolyNum;     //面的总数
		vector<gmeSurface*>               m_SurfVecs;    //面集合
		vector<s3d_3DPoly>                m_SurfBndy;    //面边界多边形
		vector<vector<gme_vector3d>>      m_vvlins;      //非重叠边
		vector<vector<gme_vector3d>>      m_linsOver;    //重叠边
		vector<vector<gme_vector3d>>      m_allLines;    //所有边界边
		vector<gme_rect_3d>               m_SurfRect;    //面rect
		vector<gme_rect_3d>               m_ArcsRect;    //弧段rect
	};


	class _S3D_KERGEOTOPO_EXP CCalZByDelauTin
	{
	public:
		CCalZByDelauTin();
		~CCalZByDelauTin();
	public:
		long CalZValue(gme_vector3d & pnt, double esp);
		long SetResSurfDatas(gmeSurface * pSurface, gme_rect_2d * pRect);

	private:
		long InitNet();
		void GetIdxNum();
		long CreateIndexMem();
		bool bSearch(gme_vector3d * pdot, long &i, long &j);

	private:
		gme_rect_2d        m_Rect;
		gme_vector3d     * m_pdots;
		gme_triangle     * m_ptris;
		gme_triangle_top * m_ptops;
		long               m_ldotnum;
		long               m_ltrinum;
		long               m_inner;
		double             m_Xgap;
		double             m_Ygap;
		gme_rect_2d      * m_TriRect;

	private:
		long               m_idxNum;
		double             m_RectX;
		double             m_RectY;
		long               m_allNum;
		long               m_pos;
		double             m_dx;
		double             m_dy;
		long               m_XNum;
		long               m_YNum;
		long               m_XYNum;
		vector<long>    ** m_pXY;
	};

	class _S3D_KERGEOTOPO_EXP CalEntityVolume //计算多面体的体积
	{
	public:
		CalEntityVolume();
		~CalEntityVolume();
	public:
		double CalSurfArea(gmeEntity * pEnty, s3d_Polygon * pPoly, double dx, double dy);
		double CalcuVolume(gmeEntity * pEnty, s3d_Polygon * pPoly, double dx, double dy,
			double * pTop, double * pBot, gmeSurface * pTopSurf, gmeSurface * pBopSurf);

	private:
		double   CalResult();
		double   CalResult_1();
		long     s3d_InitEntity();
		long     GetInsectDot1(gme_vector2d & pdot, double & dh, bool bcal = false);
		long     GetInsectDot2(gme_vector2d & pdot, double & dh);
		long     CalcuStrThick(gme_vector2d & pdot, vector<double> &vec, double &dh);

	private:
		long               m_lx;
		long               m_ly;
		double             m_dx;
		double             m_dy;
		double           * m_dDis;
		char             * m_bExist;
		long             * m_pTriNum;
		long               m_lsurNum;

		gme_rect_2d        m_rc;
		s3d_Polygon      * m_pPoly;
		gmeEntity        * m_pAnyEnty;
		gmeSurface      ** m_psurf;
		gme_rect_2d     ** m_ppRect;

	private:
		double           * m_pTop;
		double           * m_pBot;
		bool               m_bCalArea;
		gmeSurface       * m_pTopSurf;
		gmeSurface       * m_pBopSurf;
		CCalZByDelauTin  * m_pObjTinTop;
		CCalZByDelauTin  * m_pObjTinBot;
	};
}