#pragma once


#include "s3d_KerMathDef.h"
#include "s3d_GisStru.h"
#include "gmeStru.h"




namespace Smart3dMap
{

class LIB_GMKERMATH_EXP CLinCpsProc //定义线光滑处理类.
{
public:
	CLinCpsProc(double fwStep, double samErr, char cDoPack);
	CLinCpsProc();
	~CLinCpsProc();

public:
	//正轴抛物线加权平均光滑处理主入口例程:
	gme_D_DOT  *cmsAixsCbs(gme_D_DOT *lPtr,long ln,long *outln);
	//五点三次贝叶斯过点光滑主入口例程:
	gme_D_DOT  *cmDensityp5Cbs(gme_D_DOT *arc_buf,long arc_xy,long *outlen);
	//三点三次贝叶斯过点光滑主入口例程:
	gme_D_DOT  *cmDensityp3Cbs(gme_D_DOT *arc_buf,long arc_xy,long *outlen);
	//三次贝叶斯不过点光滑主入口例程:
	gme_D_DOT  *cmDensityCbs(gme_D_DOT *arc_buf,long arc_xy,long *outlen);
	//三次B样条曲线过点插值光滑处理主入口函数:
	gme_D_DOT  *cmInsertDensity(gme_D_DOT *arc_buf,long arc_xy,long *outlen);

	// ----------------------------- 张力样条光滑处理函数 ---------------------------- //
	// 参数:gme_D_DOT *pddpt ------------ 给定的待光滑处理的线数据点集;
	//		long lDnum	 ------------ 待光滑处理的线数据点个数;
	//      double dTention---------- 张力系数(0<-则等同于三次样条，->无穷大则分段线性);
	//      long *lDn   ------------- 光滑后线数据Buf中的数据点数;
	//返回: 函数返回光滑后的线数据Buf指针(由函数申请，调用则释放); 为NULL则函数失败.
	gme_D_DOT  *cmTentionCps(gme_D_DOT *arc_buf,long arc_xy,double dTention,long *outlen);
	// 按给定插值步长将线插密并返回插密后的点坐标及点数:
	gme_D_DOT  *cmInsDensityLinByStep(gme_D_DOT *xy,long len,double dfStep,long *outlen);
	//压缩相同的相邻点:
	void	cmSetCpsRadius(double fStep, double samErr, char cDoPack);
	short	cmPackingLin(gme_D_DOT *lnptr, long *len, double delta);
	void    cmFreeCbsLinBuf(void);
	gme_D_DOT  *cmAllocCbsLinBuf(long linLn);

private:
	//正轴抛物线加权平均光滑处理例程
	double	_sAixs(long i, double *B, double t);
	//五点三次贝叶斯过点光滑例程
	double _p5Cbs(double *px, double *L_arc, double *dpx, double t);
	//三点三次贝叶斯过点光滑例程:
	double	_p3Cbs(double *px, double *L_arc, double *dpx, double t, double dist);
	//三次贝叶斯不过点光滑例程
	double	Cbs(long i, double *B, double t);
	//三次B样条曲线过点插值光滑处理函数
	short	Cps_Trid(long n, double *a, double *b, double *c, double *f);
	short	Cpps(long n, double *p, double *L_arc, double *dp, short Boudary_type);
	double	GeneratePose(double *p, double *L_arc, double *dp, long i, double t);

	//张力样条过点光滑处理函数:
	short	TraveV(gme_D_DOT *pddpt, long lDnum, double* pdA, double* pdB, double* pdC,
		double* pdx, double* pdy, double* pdSx, double* pdSy);
	short	CaculateDV(gme_D_DOT *pddpt, long lDnum, double* pdSx,
		double* pdSy, double* pdH, double*dTention);
	//计算得到光滑处理后的线上点数据:
	gme_D_DOT  *DrawTention(gme_D_DOT *pddpt, long lDnum, double *pdSx, double *pdSy,
		double *pdH, double dTention, long *lDn);
private:
	gme_D_DOT  *m_PtCbsLine; //返回光滑处理后数据;
	long	m_CbsLinLn;//当前BUFFER大小.
	char    m_cDoPackProc; //光滑前做同点合并处理.
	double  m_SameDErr, m_CpsRadius;//光滑处理参数.
};


	//说明: 线光滑类各函数公用同一返回数据指针，故各函数仅可串行使用，不可并行.
	//线性插值摸角法光滑处理函数:
	void LIB_GMKERMATH_EXP cmLinCbs2(gme_D_DOT *fXyIn, gme_D_DOT *fXyOut, long lDn);
}

