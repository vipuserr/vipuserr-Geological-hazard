// -----------------------------------------------------------------
//
// Copyright:	ZondySoft 2005
//
// File:		GsStru.h
//
// Project:		GeoStatLib
//
// Creator:		黄铁兰
//
// Time:		10:22 2004-01-27
//
// Description:	Definitions and Structions of Geological Statistical Library
//
// -----------------------------------------------------------------

#ifndef __GS_STRU_H__
#define __GS_STRU_H__

#define GS_MINVRGPNT    30

#define	GS_MAXNST		20		//变差函数最大数目

#define GS_MAXTRIM		1.0e21	//数据极限
#define GS_MINTRIM		-1.0e21

#define GS_EPSLON20		1.0e-20	//dpowint
#define GS_EPSLON06		1.0e-6	//nscore
#define GS_EPSLON05		1.0e-5	//powint
#define GS_EPSLON04		1.0e-4	//powint
#define GS_EPSLON03		1.0e-3
#define GS_EPSLON02		1.0e-2	//powint

#define GS_EPSLON12		1.0e-12	//trans

#define GS_MAXINT		pow(2.0f,30) //acorni

#define GS_MAXCAT		24	//trans

#define	GS_PI08			3.141592654	//gamv kt3d	

#define GS_EI06         2.718282		

//bigaus
#define	GS_MLAG			500
#define	GS_MDIR			10

#define	GS_MAXROT		20
#define	GS_DEG2RAD		(GS_PI08/180)
#define	GS_NUM1			100

//kb2d
#define	GS_UNEST		-999
#define	GS_EPSLON10		1.0e-10
#define	GS_MAXDT		9
#define	GS_MAXROT1		(GS_MAXNST+1)

#define GS_MAXVAR		3
#define GS_MXVARG		(GS_MAXVAR*GS_MAXVAR)

#define GS_PMX			999.0

#define GS_MAXCUT		11

#define GS_MAXINTPNUM	max(GS_MAXCUT,GS_MXVARG)

#define GS_MAXCLS		30

#define GS_MAXDIR		5

#define GS_MAXSTA		100

#define GS_UNEST_SIM	(-99.0)
#define GS_MAXROT_SIM	(GS_MAXCUT*GS_MAXNST+1)	//旋转矩阵的最大数目

#define GS_MAXELP		25		//simulate

#define	GS_KORDEI		(12)
#define	GS_MAXOP1		(GS_KORDEI+1)

//sasim
#define GS_MAXSTOP		10
#define GS_BIGNUM		1.0e10
#define GS_MAXNST02		2
#define GS_MAXOBJ		8
#define GS_MAXPERT		1000
#define GS_KORDEI10		10

#define	GS_TINY			(1E-10)

//scatsmth
#define GS_MAXSMT		1000
#define GS_MAXSML		10
#define GS_MAXCLS1		1000
#define GS_MAXQUA		50
#define GS_MAXLIM		50

//变差函数lhy添加
#define GS_MAXVRG       20
#define GS_MV           500


#define  MIN_FLOAT	(-3.402823E+38)
#define  ZERO_FLOAT     (+1.401298E-45)
#define  MAX_FLOAT	(+3.402823E+38)
#define  MIN_DOUBLE	(-1.79769313486232E+307)
#define  ZERO_MIN_DBL   (-4.94065645841247E-324)
#define  ZERO_MAX_DBL   (+4.94065645841247E-324)
#define  MAX_DOUBLE	(+1.79769313486232E+307)

#define ZERO_5BIT 1E-5
#define ZERO_6BIT 1E-6
#define EQUAL_6BIT(a,b) ( fabs(a-b) < ZERO_6BIT )

#define GS_STRLEN       254
#define GS_STRSHORTLEN   20


#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
// --------- struction ---------- //
typedef struct GSD_3DOT
{
	double x;
	double y;
	double z;
}GSD_3DOT;

typedef struct GSD_DOT
{
	double x;
	double y;
}GSD_DOT;

typedef struct GSL_DOT
{
	long x;
	long y;
}GSL_DOT;

typedef struct GSL_3DOT
   {
     long x;
     long y;
     long z;
   }GSL_3DOT;

typedef struct GSD_RECT
{
	double xmin;
	double ymin;
	double xmax;
	double ymax;
}GSD_RECT;

//丛聚权值平均和
typedef struct ClustSum
{
	double		dCellSiz;
	double		dClustMean;
} ClustSum;

//估计块段
typedef struct Block
{
	double	value;		//估计值
	double	variance;	//方差
} Block;


//三维数据包围盒
typedef struct GeoS_3DBOX
{
	double			xmin;
	double			ymin;
	double			zmin;
	double			xmax;
	double			ymax;
	double			zmax;
	
	GeoS_3DBOX() 
		{
		xmin=ymin=zmin=GS_MAXTRIM;
		xmax=ymax=zmax=GS_MINTRIM;
		}
} GS3D_BOX;

//离散点结构
typedef struct GsDiscPnt
{
	double	fPosX;		//坐标
	double	fPosY;
	double	fPosZ;

	double	fAttr;		//属性
	double	fSecAttr;
	double	fThiAttr;

	double	fWeight;	//权值
	double	fSecWeight;
	double	fThiWeight;

	char    strEngCode[11];
	int     iEngType;
} GsDiscPnt;
//离散点结构（简单）
typedef struct GsDiscPnt1
{
	double	fPosX;		//坐标
	double	fPosY;
	double	fPosZ;

	double	fAttr;		//属性
	double	fWeight;	//权值
	
} GsDiscPnt1;
//离散点数据有效标志
//与离散点数据结构成员一一对应. 有效为1,无效为0.
typedef struct GsPntFlag
{
	bool	bPosX;			//坐标
	bool	bPosY;
	bool	bPosZ;

	bool	bAttr;			//属性
	bool	bSecAttr;
	bool	bThiAttr;

	bool	bWeight;		//权值
	bool	bSecWeight;
	bool	bThiWeight;
} GsPntFlag;

//克立金网格参数
typedef struct GsGrid
{
	int		iGridNumX, iGridNumY, iGridNumZ;	//三个方向的网格数目
	double	fGridOriX, fGridOriY, fGridOriZ;	//三个方向的网格起始坐标(起始坐标分别为每个方向的最小+网格大小的一半)
	double	fGridSizX, fGridSizY, fGridSizZ;	//三个方向的网格间距(默认为10)
} GsGrid;

//克立金离散点搜索参数
typedef struct Kt3dSrch
{
	int		iDiscNumX, iDiscNumY, iDiscNumZ;	//三个方向每个块段中离散点的数目(默认为1)
	double	fSrchRadius, fSrchRadius1, fSrchRadius2;	//搜索半径(缺省设为相同,可以为对角线的一半)
	double	fSrchAngle1, fSrchAngle2, fSrchAngle3;		//搜索椭圆的角度(缺省设为0)
	int		iMinSrchPntNum;	//最小搜索点数(缺省为4)
	int		iMaxSrchPntNum;	//最大搜索点数(缺省为8)
} Kt3dSrch;

//实验变差函数计算参数
typedef struct GamvParam
{
	int    iLagNum;
	double fLagSize;
	double fLagTol;
	int    iAzm, iDip;
	double fAzmTol, fDipTol;
	double fBandWidthH, fBandWidthV;

}GamvParam;

//克立金插值参数
typedef struct Kt3dIntp
{
	int		iStrNum;				//套合结构的数目nst（默认为1）
	double	fNugConst;				//块金常数C0（默认为0）
	double	fArchValue[GS_MAXNST];		//拱高C(数组大小为lStrNum)（默认为1）
	int		iModelType[GS_MAXNST];		//理论模型类型(数组大小为lStrNum)（默认为0）
	double	fChgRang[GS_MAXNST];		//变程(数组大小为lStrNum)（默认外包矩形对角线一半）
	double	fChgRang1[GS_MAXNST];		
	double	fChgRang2[GS_MAXNST];		
	double	fAnisAng1[GS_MAXNST];		//各向异性的角度(缺省为0)
	double	fAnisAng2[GS_MAXNST];
	double	fAnisAng3[GS_MAXNST];
} Kt3dIntp;




//变差函数
typedef struct Variogram
{
	int		lagno;	//滞后编号
	double	dis;	//滞后距离
	double	gam;	//变差函数值
	int		nump;	//数据对数目
	double	hm;		//顶部数据平均值
	double	tm;		//底部数据平均值
	double	hv;		//顶部变量
	double	tv;		//底部变量
} Variogram;

//Model Indicator Variogram
typedef struct ModIndVrg
{
	int		nlagno;	//滞后编号
	double	h;		//滞后距离
	double	rop;	//变差函数值
	int		ldir;	//方向编号
	double	ci;
	double	ri;
} ModIndVrg;

//平滑值
typedef struct Smooth
{
	double	zvalue;
	double	logzvalue;
	double	pvalue;
} Smooth;

//统计量
typedef struct Statistic
{
	double		fAver;
	double		fVari;
	double		fMin;
	double		fMax;	
} Statistic;

//克立金插值后的数据点结构
typedef struct EstabPnt
{
	double		fPosX;				//x坐标
	double		fPosY;				//y坐标
	double		fPosZ;				//z坐标
	double		dOriVal;			//原始值
	double		dEstabVal;			//估计值
	double		dEstabVari;			//估计方差
	double		dErr;				//误差	
	long        lPntNum;            //点对数
	double      fMeanDis;           //估值点到待估点的平均距离
	int        *piEngType;           //工程类型
	long       *plEngNum;            //工程个数

} EstabPnt;
typedef struct EstabPnt1
{
	double		fPosX;				//x坐标
	double		fPosY;				//y坐标
	double		fPosZ;				//z坐标
	double		dOriVal;			//原始值
 	double		dEstabVal;			//估计值
// 	double		dEstabVari;			//估计方差
// 	double		dErr;				//误差	
// 	long        lPntNum;            //点对数
// 	double      fMeanDis;           //估值点到待估点的平均距离

} EstabPnt1;
//loacal proportion(using in gtsim)
typedef struct LocalProp
{
	double		*pfLocalProp;
	bool		bUseFlag;
} LocalProp;

//smooth result
typedef struct SmoothResult
{
	double	fValueZ;	//Z-value
	double	fValueP;	//P-value
} SmoothResult;

typedef struct TargActDistr
{
	double		fValue;			//Value
	double		fTargProb;		//Target Probability
	double		fActProb;		//Actual Probability
} TargActDistr;

//分级信息
typedef struct TradOreClasInfo
{
	char  szOreClasName[20];
	long  lPntNum;
	long  lEngNum;
	long  lSrchNum;
}TradOreClasInfo;

typedef struct KrigOreClasInfo
{
	char  szOreClasName[20];
	double fVariVal;
}KrigOreClasInfo;

typedef struct KrigEngNumInfo
{
	int *piEngType;//0钻孔1探槽2坑道3浅井
	long *plEngNum;//储量类型对应的数据个数
}KrigEngNumInfo;
//2011.8.25
typedef struct KringParam
{
	double     dMaxData; //数据极大值（默认为最大值）
	double     dMinData; //数据极小值（默认为最小值）
    double     fGridSizX;//网格的大小（默认为10）
	double     fGridSizY;//网格的大小（默认为10）

	Kt3dSrch   gsSrchParam;
	int        noct;     //0为普通搜索，其他数为八分圆搜索中每一份中搜索的样本点数
	Kt3dIntp  gsGamvParam;
	KringParam() 
	{
		dMinData = dMaxData = 0;
		fGridSizX = fGridSizY = 10;
		noct = 0;
       
		gsSrchParam.fSrchAngle1 = gsSrchParam.fSrchAngle2= gsSrchParam.fSrchAngle3 = 0;
		gsSrchParam.iDiscNumX = 1;
		gsSrchParam.iDiscNumY = 1;
		gsSrchParam.iDiscNumZ = 1;
		gsSrchParam.iMaxSrchPntNum =8;
		gsSrchParam.iMinSrchPntNum =4;
		gsSrchParam.fSrchRadius = gsSrchParam.fSrchRadius1 =gsSrchParam.fSrchRadius2 = 0;

		gsGamvParam.fAnisAng1[0] = gsGamvParam.fAnisAng2[0] = gsGamvParam.fAnisAng3[0] = 0;
		gsGamvParam.fArchValue[0] = 1;
		gsGamvParam.fNugConst = 0;
		gsGamvParam.fChgRang[0] = gsGamvParam.fChgRang1[0] = gsGamvParam.fChgRang2[0] = 0;
		gsGamvParam.iStrNum = 1;
		gsGamvParam.iModelType[0] = 0;
	}
};
#endif //__GS_STRU_H__