#pragma once

#include "s3d_KerMathDef.h"
#include "gmeMdl.h"

namespace Smart3dMap
{
	//重复点处理宏:
	#define  SAME_AVE    100
	#define  SAME_SUM    101
	#define  SAME_DEL    102

	typedef struct // 网格高程数据信息结构.
	{
		long   nx, ny;
		double xmin, xmax;
		double ymin, ymax;
		double zmin, zmax;
	} DemInfoStrcT;

	// GridIdx: --------------------------- 网格化用数据四分索引类定义与实现 ---------------------------------- //
	//定义TIN工作区中无效标志值(GRD无效标志值):
#define INVALID_TINZVAL	 1.70141e+038 



	typedef struct
	{
		long   xn, yn;  //网格X、Y向点数.
		double xStart; //网格X向起点.
		double yStart; //网格Y向起点.
		double xEnd;   //网格X向终点.
		double yEnd;   //网格Y向终点.
	} GridingStrcT;

	typedef struct
	{
		double	dist;  //最近距离.
		long	kNo;   //对应点号.
	} DisDtStrcT;  //搜索距离点结构.

	// ------------------------ 离散数据网格化处理用结构及其函数 ------------------------ //
	typedef struct SearchDatStrcT// 网格化离散数据搜索结构.
	{
		short  nSeekWay;	// 搜索方式(1\2\3\4-->所有点\K-临近\四方向\八方向).
		short  nDotPerSec;  // 每扇区使用的最多点数.
		short  nMinAllDot;	// 允许最少使用的总点数(少于设定点数该点无效).
		short  nMaxNullSec; // 最多允许的空扇区(无效扇区)数.
		double fRadius;     // 最大搜索圆半径(缺省为数据点最小包围矩形对角线的一半长度).

		SearchDatStrcT()
		{
			nSeekWay = 4;
			nDotPerSec = 10;
			nMinAllDot = 3;
			nMaxNullSec = 7;
			fRadius = 0;
		}
	} SearchDatStrcT;

	typedef struct DistInsStrcT
	{
		short	nPower;		// 距离幂次数(缺省为2).
		double  fSmooth;	// 距离幂反比插值时的光滑参数(缺省为0).
		double	fRatio;     // 数据几何各向异性之长短轴比率(1). 
		double	fAngl;      // 数据几何各向异性之长轴与X轴向夹角(360度制、度为单位)(0).

		DistInsStrcT()
		{
			nPower = 2;
			fSmooth = 0;
			fRatio = 1;
			fAngl = 0;
		}
	} DistInsStrcT;

	typedef struct KringParmStrcT
	{
		short  nKringTyp;	//克立金插值模型(0/1/2:幂指数/线性/球状模型).
		short  nDrift;		//漂移次数(0/1/2/3有效)(缺省为0).
		double dfcValue;	//基台值(缺省设为高程数据的总变差即:(Z-Z均值)的平方和).
		double dferrValue;	//测量误差效应值(缺省为0).
		double dfmErrValue;	//微结构误差效应值(缺省为0).
		double dfRaudisA;   //变程数据值(A缺省设为数据点最小包围矩形对角线的一半长度).
		double dfRatio;     //数据各向几何异性之比率(缺省为1表示数据各向同性).
		double dfAngle;		//异向性参数:主轴与X轴向夹角(缺省为0).

		KringParmStrcT()
		{
			nKringTyp = 2;
			nDrift = 0;
			dfcValue = 0;
			dferrValue = 0;
			dfmErrValue = 0;
			dfRaudisA = 0;
			dfRatio = 1;
			dfAngle = 0;
		}
	} KringParmStrcT;

	class  LIB_GMKERMATH_EXP CDotGrdIdx	//离散点网格化索引类实现.
	{
	public:
		CDotGrdIdx();
		~CDotGrdIdx();		//构造及析构函数.
		void setParam(gme_vector3d* dtXYZPtr, long nDotAll, SearchDatStrcT *PtSdat, gme_D_RECT *fDotRc);

	public:
		short CreateDotGrdIdx(GridingStrcT *grdInfo, double sRadius, double repDotLimit, short repDotProc);
		//根据当前索引块号计算索引表列表...
		void getBlkPntNos(long idx, vector<long>& sampDotNos);

		//按八方向搜索数据有以下八个函数:
		short       GetPointSet0By8Dir(void); //返回找到的数据点数.
		short       GetPointSet1By8Dir(void); //返回找到的数据点数.
		short       GetPointSet2By8Dir(void); //返回找到的数据点数.
		short       GetPointSet3By8Dir(void); //返回找到的数据点数.
		short       GetPointSet4By8Dir(void); //返回找到的数据点数.
		short       GetPointSet5By8Dir(void); //返回找到的数据点数.
		short       GetPointSet6By8Dir(void); //返回找到的数据点数.
		short       GetPointSet7By8Dir(void); //返回找到的数据点数.

					//按四方向搜索数据有以下四个函数:
		short       GetPointSet0By4Dir(void); //返回找到的数据点数.
		short       GetPointSet1By4Dir(void); //返回找到的数据点数.
		short       GetPointSet2By4Dir(void); //返回找到的数据点数.
		short       GetPointSet3By4Dir(void); //返回找到的数据点数.

					//按简单搜索数据点有以下搜索函数:
		short       GetPointSet0By1Dir(void); //返回找到的数据点数.


	public:
		void		setDistParam(DistInsStrcT*PtDis);

		void        SetxCosxSinfRatio(double fRatio, double fAng);
		double		xKringGam(short k, short l);
		double		xKringGam(double h);
		void		SetCalxKringGamParam(KringParmStrcT *PtKparm);
		void		FreePtDbIdx(); //释放网格索引指针.

	private:
		void        Insert_kNo(long kNo);

	public:
		gme_vector3d* m_dtXYZPtr;//传入的点XYZBUF指针.
		long		m_lDotAll;	//传入的总点数.
		gme_D_RECT		m_fDotRc0;	//传入数据的范围.
		SearchDatStrcT *m_PtSdat;//搜索参数结构指针.
		DistInsStrcT*   m_PtDistIns;
		KringParmStrcT* m_PtKparm;

	public:
		DisDtStrcT *m_PtDisDot; //搜索的样本点...
		short       m_nDisDot;
	private:
		short       m_sDn;
		DisDtStrcT *m_cPtdsDt;
		DisDtStrcT  m_tmpDsDt;

	public:
		short       m_offxDn;	//半径在X方向的网格数.
		short		m_offyDn;	//半径在Y方向的网格数.
		short       m_offXyDn;  //等于min(m_offxDn,m_offyDn);
		long		m_xwGdn;	//获取横向网格数. (上下左右范围外扩后)
		long        m_yhGdn;	//获取纵向网格数.
		double		m_xfRadiu; //每一个索引网格的x长度
		double		m_yfRadiu; //每一个索引网格的y长度

		long		m_CurKno;	//当前搜索的网格点号.
		long		m_CurIx;	//当前搜索的X向下标.
		long		m_CurIy;	//当前搜索的Y向下标.
		double      m_dfCurX;	//当前搜索圆的圆心X.
		double      m_dfCurY;	//当前搜索圆的圆心Y.

	public:
		long       *m_PtPntIdx; //每点之前点索引(初始化为-1).
		long	   *m_PtDbIdx;	//网格索引指针(初始化为-1). 如果索引格中有m个样本点，则记录最后一个样本的序号x。利用x = m_PtPntIdx[x],知道x=-1为止找出此索引格
								//中所有的样本数据号... leo
		gme_D_RECT		m_fDotRc;	//传入数据的范围. 调整包络矩形范围(外扩).

	private:
		double      m_fRatio;
		double      m_dx, m_dy;
		double      m_xCos, m_xSin;
	private:
		//Krig的插值参数
		short       m_nKringTyp;
		double		m_C, m_C0;
		double		m_VarA;
		double		m_VarA2, m_VarA3;
	};



	// ------------------------------- 稀疏规则网格插密处理类定义与函数 ---------------------------- //
	// 规则网TIN工作区插密用宏定义:
#define  _16PIN		1	//16点双三次插值.
#define  _4PIN		0	//4 点双线性插值.

	class LIB_GMKERMATH_EXP DemInsClass //插密处理类定义.
	{
	public:
		DemInsClass(DemInfoStrcT *demHeadInfo, double *ptDatPtr, short InsType, double *InValidVal = NULL);
		~DemInsClass();	//构造、析构函数.		
	public:		// 取已知规则网中当前点的插密高程值:
		double	_GetCurValResult(double x, double y);
		BOOL    _IsValidClass(void);

		// 插密到 WINDOWS的INS文件中:
		BOOL	_16_4PointInsertToIns(HFILE tpHfile, double dx, double dy);
		// 16或4点数据加密到内存缓冲区/GRD文件中:
		double *_16_4PointsInsertToBuf(long curNx, long curNy);



	private:	// 插密函数.
		double	CheckValidVal(long iRow, long jCol);
		void	Va(long i, long j);
	private:	//插密变量.	
		DemInfoStrcT m_DemHead;  //规则网高程数据头描述.
		double  m_xDlt, m_yDlt;
		short	m_nInsType;		 //插密类型;
		double *m_demDatPtr;     //保存待插密的规则高程数据.
	private:
		double  m_bCurCellValidVal;
		double  m_InValidVal;

		BOOL    m_IsValidFlg;
		BOOL    m_bCheckValidVal;

		double *m_tDemZptr;
		double	A00, A10, A20, A30, A01, A11, A21, A31;
		double	A02, A12, A22, A32, A03, A13, A23, A33;
	};
	typedef class DemInsClass* DemInsOBJ;

	//IDW规则网插值
	short LIB_GMKERMATH_EXP  _tnDistInsGridingToBuf(gme_vector3d* tmpXyzPtr, long allDatNum, DemInfoStrcT *mHdInf, SearchDatStrcT *PtSdat, DistInsStrcT *PtDis, double *tZptr);
	//Kriging规则网插值
	short LIB_GMKERMATH_EXP  _tnKringGridingToBuf(gme_vector3d* tmpXyzPtr, long allDatNum, DemInfoStrcT *mHdInf, SearchDatStrcT *PtSdat, KringParmStrcT *PtKparm, double *tZptr);

	//IDW单点插值, PtSdat-样本搜索参数， PtDis-插值参数.
	LIB_GMKERMATH_EXP  void* interp_idw_init(gme_vector3d * pDots, long dotNum, double dRadius=0, SearchDatStrcT *PtSdat = nullptr, DistInsStrcT *PtDis = nullptr);
	int	LIB_GMKERMATH_EXP  interp_idw_pnt(void* interpObj, gme_vector3d &dot);

	//普通Kriging单点插值, PtSdat-样本搜索参数， PtKparm-插值参数.
	LIB_GMKERMATH_EXP  void* interp_krig_init(gme_vector3d * pDots, long dotNum, SearchDatStrcT *PtSdat = nullptr, KringParmStrcT *PtKparm = nullptr);
	int	LIB_GMKERMATH_EXP  interp_krig_pnt(void* interpObj, gme_vector3d &dot);


	DemInsOBJ LIB_GMKERMATH_EXP _tnGetDemInsOBJ(DemInfoStrcT *demHdInf, double *PtDemDat, short IType, double *InValidVal = NULL);
	short LIB_GMKERMATH_EXP _tnDeleteDemInsOBJ(DemInsOBJ insOBJ);
	// 取已知规则网中当前点的插密高程值:
	double LIB_GMKERMATH_EXP _tnGetCurPntDemVal(DemInsOBJ insOBJ, double x, double y);
	// 16或4点数据加密到内存缓冲区中:
	LIB_GMKERMATH_EXP double* _tnInsDemDatToBuf(DemInsOBJ insOBJ, long curNx, long curNy);


}
