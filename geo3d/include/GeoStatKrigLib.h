//==========================================================================
//      版权:ZTYQ Tech. Co., Ltd.//版权
//      工程名: GeoStatKrig。
//      作者: lhy，2007.05
//      功能描述: 完成克里格品位估值功能
//      版本:  1.1，2007.05。
//      修改记录:  无。
//      主要函数列表: 
//      _gsKLoadGsKrigData ---------------------------------------->导入数据
//      _gsKSetExtrData --------------------------------------->设置数据极值
//      _gsKSetGridParam -------------------------------------->设置格网定义
//      _gsKSetSrchParam ---------------------------------->设置搜索椭球定义
//      _gsKCptKrigingVol ----------------------------------->计算克里格估值
//      _gsKCptIkrigingVol ------------------------------>计算指示克里格估值
//      _gsKCptInverseVol --------------------------------->计算距离反比估值
//      _gsKBackTr ---------------------------------------->对数据进行逆变换
//==========================================================================

#if !defined(AFX_GEOSTATKRIGLIB_H__614596C4_13C5_4CC1_B75B_AD7383089B49__INCLUDED_)
#define AFX_GEOSTATKRIGLIB_H__614596C4_13C5_4CC1_B75B_AD7383089B49__INCLUDED_

#include "GsStru.h"
#include "GeoStatLib.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _GEO_STAT_KRIG_LIB
#define  _GEO_STAT_KRIG_DLL _declspec(dllimport)
#else
#define _GEO_STAT_KRIG_DLL _declspec(dllexport)
#endif

class _GEO_STAT_KRIG_DLL CGeoStatKrigLib  
{
public:
	CGeoStatKrigLib();
	virtual ~CGeoStatKrigLib();

	//================================================================================
    // 函 数 名：_gsKLoadGsKrigData
    // 功能描述：该函数装入的数据,即是克里格估值功能中处理的数据. 
	// 输入参数：pDiscPnts          ： 数据点
	//           lpntNum            ： 数据数目
	//           ptr_var            ： 正态变换对应表(正态变换中得到，正态逆变换中用到)
	//           ptr_vrg            ： 正态变换对应表(正态变换中得到，正态逆变换中用到)
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _gsKLoadGsKrigData(GsDiscPnt *pDiscPnts, long lpntNum, double *ptr_var, double *ptr_vrg);
	void _gsKLoadGsKrigData1(GsDiscPnt1 *pDiscPnts, long lpntNum, double *ptr_var, double *ptr_vrg);


	//================================================================================
    // 函 数 名：_gsKLoadGsKrigData2
    // 功能描述：该函数装入次变量数据,即协克里格估值中用到的次变量数据
	// 输入参数：pDiscPnts          ： 数据点
	//           lPntNumSec         ： 数据数目
    // 返回值  ：无
    // 创建日期：2008-09-24
    // 修改日期：2008-09-24
    // 附加说明：
    //================================================================================
	void _gsKLoadGsKrigData2(GsDiscPnt *pDiscPntsSec, long lPntNumSec);
	void _gsKLoadGsKrigData2Simp(GsDiscPnt1 *pDiscPntsSec, long lPntNumSec);

	//================================================================================
    // 函 数 名：_gsKSetExtrData
    // 功能描述：该函数用来设置进行克里格估值的数据属性的极值
	// 输入参数：fExtrMax           ： 数据极大值(默认1.0e21,可设置为数据的最大值)
	//           fExtrMin           ： 数据极小值(默认-1.0e21，可设置为数据的最小值)
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _gsKSetExtrData(double fExtrMax, double fExtrMin);
	
	//================================================================================
    // 函 数 名：_gsKSetGridParam
    // 功能描述：该函数用来设置克里格估值中用到的格网参数
	// 输入参数：xnum              ： X轴格网个数
	//           ynum              ： Y轴格网个数
	//           znum              ： Z轴格网个数
	//           xmini             ： X轴格网起始坐标
	//           ymini             ： Y轴格网起始坐标
	//           zmini             ： Z轴格网起始坐标
	//           xsize             ： X轴格网大小
	//           ysize             ： Y轴格网大小
	//           zsize             ： Z轴格网大小
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _gsKSetGridParam(int xnum, int ynum, int znum, 
		           double xmini, double ymini, double zmini, 
				   double xsize, double ysize, double zsize);
	void _gsKSetGridParamEva(int xnum, int ynum, int znum, 
		double xmini, double ymini, double zmini, 
		double xsize, double ysize, double zsize);
	//================================================================================
    // 函 数 名：_gsKSetSrchParam
    // 功能描述：该函数用来设置克里格估值中用到的搜索椭球
	// 输入参数：maxr_sec           ： 搜索椭球的长轴半径(数据外包矩形对角线的一半)
	//           minr_sec           ： 搜索椭球的短轴半径(数据外包矩形对角线的一半)
	//           err_sec            ： 搜索椭球的垂直轴半径(数据外包矩形对角线的一半)
	//           ang1_search        ： 搜索椭球旋转的方位角(0)
	//           ang2_search        ： 搜索椭球旋转的倾伏角(0)
	//           ang3_search        ： 搜索椭球旋转的倾角(0)
	//           minnum_krg         ： 克里格过程中用到的最小样本点数(3)
	//           maxnum_krg         ： 克里格过程中用到的最大样本点数(15)
	//           numxblock          ： X方向上块段中离散点数(1)
	//           numyblock          ： Y方向上块段中离散点数(1)
	//           numzblock          ： Z方向上块段中离散点数(1)
    // 返回值  ：无 
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _gsKSetSrchParam(double maxr_sec, double minr_sec, double verr_sec, 
		             int ang1_search, int ang2_search, int ang3_search, 
		             int minnum_krg, int maxnum_krg, int numxblock, int numyblock, int numzblock);
    
	//设置搜索椭球相关参数
	//说明: 该函数用来设置交叉验证中用到的搜索椭球
	//参数:
	//      iMaxSrchNum -------------> 次变量估值最大个数
	//      maxr_sec ----------------> 搜索椭球的长轴半径
	//      minr_sec ----------------> 搜索椭球的短轴半径
	//      err_sec -----------------> 搜索椭球的垂直轴半径
	void _gsKSetSecSrchParam( int iMaxSrchNumSec, double fSrchMaxr_Sec, double fSrchMinr_Sec, double fSrchVerr_Sec);

	//================================================================================
    // 函 数 名：_gsKSetSrchOct
    // 功能描述：该函数用来设置克里格估值过程中用到的椭球的搜索方式
	// 输入参数：noct              ： 0为普通搜索，其他数为八分圆搜索中每一份中搜索的样本点数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================		
	void _gsKSetSrchOct(int noct);

	//================================================================================
    // 函 数 名：_gsKSetDisPower
    // 功能描述：该函数用来设置距离反比幂次
	// 输入参数：iDisPower： 距离反比幂次
    // 返回值  ：无
    // 创建日期：2009-11-03
    // 修改日期：2009-11-03
    // 附加说明：
    //================================================================================	
	void _gsKSetDisPower(int iDisPower);
	
    //================================================================================
    // 函 数 名：_gsKSetKrigType
    // 功能描述：该函数用来设置克里格过程中的克里格估值类型
	// 输入参数：ktype            ： 0为简单克里格，1为普通克里格，2为泛克里格，3为指示克里格 
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _gsKSetKrigType(int ktype);

    //================================================================================
    // 函 数 名：_gsKSetCoKrigType
    // 功能描述：该函数用来设置协克里格过程中的克里格估值类型
	// 输入参数：iCoktype         ： 0传统普通协克里格；1标准普通协克里格；2简单克里格
    // 返回值  ：无
    // 创建日期：2008-09-23
    // 修改日期：2008-09-23
    // 附加说明：
    //================================================================================
	void _gsKSetCoKrigType(int iCoktype);

    //================================================================================
    // 函 数 名：_gsKSetKrigOption
    // 功能描述：该函数用来设置克里格过程中的克里格类型
	// 输入参数：koption          ： 克里格选项
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _gsKSetKrigOption(int koption);
	
	//================================================================================
    // 函 数 名：_gsKSetSkMean
    // 功能描述：该函数用来设置简单克里格估值过程中用到的样品平均值
	// 输入参数：meansk           ： 估值区域数据的平均值
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _gsKSetSkMean(double meansk);

	//================================================================================
    // 函 数 名：_gsKSetCokMean
    // 功能描述：该函数用来设置协克里格估值过程中用到的样品平均值
	// 输入参数：pfCokMean        ： 估值区域数据的平均值
    // 返回值  ：无
    // 创建日期：2008-09-24
    // 修改日期：2008-09-24
    // 附加说明：
    //================================================================================
	void _gsKSetCokMean(double pfCokMean[]);

	//================================================================================
    // 函 数 名：_gsKSetIntpPara
    // 功能描述：该函数用来设置克里格估值中用到的变差函数参数
	// 输入参数：nst                ： 变差函数模型个数(1)
	//           c0                 ： 块金值(0)
	//           cc                 ： 拱高值(1)
	//           it                 ： 变差函数类型()
	//           aa                 ： 变差函数主轴变程(数据外包矩形对角线的一半)
	//           aa1                ： 变差函数次轴变程(数据外包矩形对角线的一半)
	//           aa2                ： 变差函数垂直轴变程(数据外包矩形对角线的一半)
	//           ang1               ： 变差函数各向异性角度方位角(0)
	//           ang2               ： 变差函数各向异性角度倾伏角(0)
	//           ang3               ： 变差函数各向异性角度倾角(0)
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================		
	void _gsKSetIntpPara(int nst, double c0, double cc[], int it[], double aa[], double aa1[],
		double aa2[], double ang1[], double ang2[], double ang3[]);
    
	//================================================================================
    // 函 数 名：_gsKSetDrifTerm
    // 功能描述：该函数用来设置漂移
	// 输入参数：idrif              ： 0表示该方向上不存在漂移，1表示存在漂移
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _gsKSetDrifTerm(int idrif[]);
	
	//================================================================================
    // 函 数 名：_gsKSetTranModel
    // 功能描述：该函数用来设置数据转换的方式
	// 输入参数：translation        ： 0表示无变换，1表示对数变换，2表示正态变换
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _gsKSetTranModel(int translation);

	//================================================================================
    // 函 数 名：_gsKSetMinAttrGzero
    // 功能描述：该函数用来设置对数变换过程中用到的偏移量
	// 输入参数：fMinGzero          ： 对数变换中用到的偏移量
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _gsKSetMinAttrGzero(double fMinZero);

	//================================================================================
    // 函 数 名：_gsKSetThresAndCdf
    // 功能描述：该函数用来设置指示克里格过程中用到的阈值参数
	// 输入参数：pfThres            ： 阈值
	//           pfCdf              ： 与阈值对应的累积概率
	//           lThresNum          ： 阈值个数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _gsKSetThresAndCdf(double pfThres[], double pfCdf[], long lThresNum);

	//================================================================================
    // 函 数 名：_gsKSetPropThres
    // 功能描述：该函数用来设置求概率图过程中用到的概率阈值
	// 输入参数：fPropThres         ： 概率阈值
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _gsKSetPropThres(double fPropThres);

	//================================================================================
    // 函 数 名：_gsKSetQuanThre
    // 功能描述：该函数用来设置求分为图过程中用到的分位阈值
	// 输入参数：fQuanThres         ： 分位阈值
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _gsKSetQuanThre(double fQuanThres);
 
	//================================================================================
    // 函 数 名：_gsKSetMeanThres
    // 功能描述：该函数用来设置指示克里格类型，中值阈值
	// 输入参数：iktype          　 ： 0为普通克里格，1为简单克里格
	//           ikCutOff        　 ： 中值阈值
	//           ktype_ik         　： 0为中值克里格，1为完全克里格
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================    
	void _gsKSetMeanThres(int iktype, double ikCutOff, int ktype_ik);
    
	//================================================================================
    // 函 数 名：_gsKSetIkIntpPara
    // 功能描述：该函数用来设置指示克里格中用到的变差函数参数
	// 输入参数：IkIntpPara         ： 变差函数参数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _gsKSetIkIntpPara(Kt3dIntp IkIntpPara[]);

	//================================================================================
    // 函 数 名：_gsKSetCokIntpPara
    // 功能描述：该函数用来设置协克里格中用到的变差函数参数
	// 输入参数：CokIntpPara         ： 变差函数参数
    // 返回值  ：无
    // 创建日期：2009-09-24
    // 修改日期：2009-09-24
    // 附加说明：
    //================================================================================
	void _gsKSetCokIntpPara(Kt3dIntp CokIntpPara[]);

	//================================================================================
    // 函 数 名：_gsKCptInverseVol
    // 功能描述：该函数用来进行距离反比估值(体数据)
	// 输出参数：pdOutAttr          ： 距离反比估值结果
	//           plPntNum           ： 距离反比估值搜索到的点数
	//           pfMeanDis          ： 估值点到待估点的平均距离
	//           lEngTypeNum        ： 工程类型数
	//           pKrigEngNum        ： 工程个数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2009-01-15
    // 附加说明：
    //================================================================================	
	void _gsKCptInverseVol(double *pdOutAttr, long *plPntNum, double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL,BOOL bIsShowProgr=TRUE);
	void _gsKCptInverseVol1(double *pdOutAttr, long *plPntNum, double *pfMeanDis,BOOL bIsShowProgr=TRUE);
	//================================================================================
	// 函 数 名：_gsKCptInversePntSimp
	// 功能描述：该函数用来进行距离反比估值(所有点插值，无搜索)
	// 输出参数：pdOutAttr          ： 距离反比估值结果
	// 返回值  ：无
	// 创建日期：2010-04-12
	// 修改日期：2010-04-12
	// 附加说明：无搜索设置，使用所有点快速插值
	//================================================================================
	void _gsKCptInverseVolSimp(double *pdOutAttr,BOOL bIsShowProgr=TRUE);

	//================================================================================
    // 函 数 名：_gsKCptInversePnt
    // 功能描述：该函数用来进行距离反比估值(离散点数据)
	// 输入参数：pEstPnt            ： 待估值点坐标
	//           lEstPntNum         ： 待估值点个数
	// 输出参数：pdOutAttr          ： 距离反比估值结果
	//           plPntNum           ： 距离反比估值搜索到的点数
	//           pfMeanDis          ： 估值点到待估点的平均距离
	//           lEngTypeNum        ： 工程类型数
	//           pKrigEngNum        ： 工程个数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2009-01-15
    // 附加说明：
    //================================================================================
	void _gsKCptInversePnt(GsDiscPnt *pEstPnt, long lEstPntNum, double *pdOutAttr, long *plPntNum,
						   double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL,BOOL bIsShowProgr=TRUE);

	//================================================================================
    // 函 数 名：_gsKCptKrigingVol
    // 功能描述：该函数用来计算普通克里格(体数据)
	// 输出参数：pdOutAttr          ： 普通克里格估值结果
	//           pdOutVari          ： 普通克里格估值方差
	//           plPntNum           ： 普通克里格估值搜索到的点数
	//           pfMeanDis          ： 估值点到待估点的平均距离
	//           lEngTypeNum        ： 工程类型数
	//           pKrigEngNum        ： 工程个数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2009-01-15
    // 附加说明：
    //================================================================================	
	void _gsKCptKrigingVol(double *pdOutAttr, double *pdOutVari, long *plPntNum, 
						   double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL,BOOL bIsShowProgr=TRUE);
	void _gsKCptKrigingVol1(double *pdOutAttr, double *pdOutVari, long *plPntNum, double *pfMeanDis,BOOL bIsShowProgr=TRUE);

	//================================================================================
	// 函 数 名：_gsKCptKrigingVolSimp
	// 功能描述：该函数用来计算普通克里格(所有点插值，无搜索)
	// 输出参数：pdOutAttr          ： 普通克里格估值结果
	// 返回值  ：无
	// 创建日期：2010-04-12
	// 修改日期：2010-04-12
	// 附加说明：无搜索设置，使用所有点快速插值
	//================================================================================
	void _gsKCptKrigingVolSimp(double *pdOutAttr,BOOL bIsShowProgr=TRUE);

	//================================================================================
    // 函 数 名：_gsKCptKrigingPnt
    // 功能描述：该函数用来计算普通克里格(离散点数据)
	// 输入参数：pEstPnt            ： 待估值点坐标
	//           lEstPntNum         ： 待估值点个数
	// 输出参数：pdOutAttr          ： 普通克里格估值结果
	//           plPntNum           ： 普通克里格估值搜索到的点数
	//           pfMeanDis          ： 估值点到待估点的平均距离
	//           lEngTypeNum        ： 工程类型数
	//           pKrigEngNum        ： 工程个数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2009-01-15
    // 附加说明：
    //================================================================================
	void _gsKCptKrigingPnt(GsDiscPnt *pEstPnt, long lEstPntNum, double *pdOutAttr, double *pdOutVari, long *plPntNum, 
						   double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL,BOOL bIsShowProgr=TRUE);

	//================================================================================
    // 函 数 名：_gsKCptIkrigingVol
    // 功能描述：该函数用来计算指示克里格(体数据)
	// 输出参数：pdOutAttr          ： 指示克里格估值结果
	//           pdOutVari          ： 指示克里格估值方差
	//           pfPropVal          ： 指示克里格概率值
	//           pfQuanVal          ： 指示克里格分位值
	//           plPntNum           ： 指示克里格估值搜索到的点数
	//           pfMeanDis          ： 估值点到待估点的平均距离
	//           lEngTypeNum        ： 工程类型数
	//           pKrigEngNum        ： 工程个数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2009-01-15
    // 附加说明：
    //================================================================================
	void _gsKCptIkrigingVol(double *pdOutAttr, double *pfOutVari, double *pfPropVal, double *pfQuanVal, long *plPntNum, 
						    double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL,BOOL bIsShowProgr=TRUE);	
	
	//================================================================================
    // 函 数 名：_gsKCptIkrigingPnt
    // 功能描述：该函数用来计算指示克里格(离散点数据)
	// 输入参数：pEstPnt            ： 待估值点坐标
	//           lEstPntNum         ： 待估值点个数
	// 输出参数：pdOutAttr          ： 指示克里格估值结果
    //           pfPropVal          ： 指示克里格概率值
	//           pfQuanVal          ： 指示克里格分位值
	//           plPntNum           ： 指示克里格估值搜索到的点数
	//           pfMeanDis          ： 估值点到待估点的平均距离
	//           lEngTypeNum        ： 工程类型数
	//           pKrigEngNum        ： 工程个数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2009-01-15
    // 附加说明：
    //================================================================================
	void _gsKCptIkrigingPnt(GsDiscPnt *pEstPnt, long lEstPntNum, double *pdOutAttr, double *pfOutVari, double *pfPropVal, double *pfQuanVal, long *plPntNum, 
						    double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL,BOOL bIsShowProgr=TRUE);	
	
	//================================================================================
    // 函 数 名：_gsKCptCoKrigVol
    // 功能描述：该函数用来计算协克里格(体数据)
	// 输出参数：pdOutAttr          ： 协克里格估值结果
	//           pdOutVari          ： 协克里格估值方差
	//           pfPropVal          ： 协克里格概率值
	//           pfQuanVal          ： 协克里格分位值
	//           plPntNum           ： 协克里格估值搜索到的点数
	//           pfMeanDis          ： 估值点到待估点的平均距离
	//           lEngTypeNum        ： 工程类型数
	//           pKrigEngNum        ： 工程个数
    // 返回值  ：无
    // 创建日期：2008-09-23
    // 修改日期：2009-01-15
    // 附加说明：
    //================================================================================
	void _gsKCptCoKrigVol(double *pdOutAttr, double *pdOutVari, long *plPntNum, 
		                  double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL,BOOL bIsShowProgr=TRUE);


	//================================================================================
    // 函 数 _gsKCptCoKrigPnt
    // 功能描述：该函数用来计算协克里格(离散点数据)
	// 输入参数：pEstPnt            ： 待估值点坐标
	//           lEstPntNum         ： 待估值点个数
	// 输出参数：pdOutAttr          ： 协克里格估值结果
    //           pfPropVal          ： 协克里格概率值
	//           pfQuanVal          ： 协克里格分位值
	//           plPntNum           ： 协克里格估值搜索到的点数
	//           pfMeanDis          ： 估值点到待估点的平均距离
	//           lEngTypeNum        ： 工程类型数
	//           pKrigEngNum        ： 工程个数
    // 返回值  ：无
    // 创建日期：2008-09-23
    // 修改日期：2009-01-15
    // 附加说明：
    //================================================================================
	void _gsKCptCoKrigPnt(GsDiscPnt *pEstPnt, long lEstPntNum, double *pdOutAttr, double *pdOutVari, long *plPntNum, 
	                      double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL);

	//================================================================================
    // 函 数 名：_gsKBackTr
    // 功能描述：该函数用来对估值结果进行逆变换
	// 输出参数：dOutAttr           ： 估值结果
	//           dOutVari           ： 估值方差
	//           lOutPntNum         ： 估值结果个数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _gsKBackTr(double *dOutAttr, double *dOutVari, long &lOutPntNum);

private:
	//原始数据信息
	GsDiscPnt  *m_pDiscPnts;
	GsDiscPnt1 *m_pDiscPnts1;
	long        m_lpntNum;
	double     *tr_var;
	double     *tr_vrg;

	//2008-9-23
	GsDiscPnt  *m_pDiscPntsSec;
	GsDiscPnt1  *m_pDiscPntsSec1;
	long        m_lPntNumSec;

	//数据极值
	double      m_fExtrMax;
	double      m_fExtrMin;

	//克里格对象
	CGeoStat   *m_KrigObj;

	//格网信息
	int         m_xnum;
	int         m_ynum;
	int         m_znum;
    double      m_xmini;
	double      m_ymini;
	double      m_zmini;
    double      m_xsize;
	double      m_ysize;
	double		m_zsize;

	int         m_xnum1;
	int         m_ynum1;
	int         m_znum1;
	double      m_xmini1;
	double      m_ymini1;
	double      m_zmini1;
	double      m_xsize1;
	double      m_ysize1;
	double		m_zsize1;

	//搜索椭球信息
    double		m_maxr_sec;
	double		m_minr_sec;
	double		m_verr_sec; 	             
	int			m_ang1_search;
	int			m_ang2_search;
	int			m_ang3_search;
    int			m_minnum_krg;
	int			m_maxnum_krg;
	int			m_numxblock;
	int			m_numyblock;
	int			m_numzblock;

	//次变量搜索信息2008-9-24
	int		    m_iMaxSrchNumSec;
	double		m_fSrchMaxr_Sec;
	double		m_fSrchMinr_Sec;
	double		m_fSrchVerr_Sec;

	//变差函数拟合结果	
	int			m_nst[1];
	double		m_c0[1];
	int			m_it[GS_MAXNST];
	double		m_cc[GS_MAXNST]; 
	double		m_ang1[GS_MAXNST];
	double		m_ang2[GS_MAXNST];
	double		m_ang3[GS_MAXNST];
	double 		m_aa[GS_MAXNST];
	double		m_aa1[GS_MAXNST];
	double		m_aa2[GS_MAXNST];	

	//2008-9-24
	Kt3dIntp    m_CokIntpPara[GS_MXVARG];
	
	//克里格信息
	int			m_noct;
	int			m_ktype;
	int			m_koption;
	double      m_meansk;
	int         m_idrif[9];
	int         m_translation;
	double      m_fMinZero;
	int         m_iDisPower;

	//2008-9-24
	int         m_iCoktype;
	double      m_pfMeanVal[GS_MAXVRG];
	
	//定义指示克里格变量	
	double		m_ikfThres[GS_MAXCUT];
	double      m_ikfCdf[GS_MAXCUT];
	int         m_ikCutNum;
    double      m_ikCutOff;

	double      m_fPropThres;
	double      m_fQuanThres;

	Kt3dIntp    m_IkIntpPara[GS_MAXCUT];
	int         m_iktype;
	int         m_ktype_ik;

	//是否显示进度条
	BOOL        m_bIsShowProgr;
};

#ifndef _GEO_STAT_KRIG_LIB
	#ifdef _DEBUG
		#pragma comment(lib, "GeoStatKrigLibD.lib")
	#else
		#pragma comment(lib, "GeoStatKrigLib.lib")
	#endif
#endif
#endif // !defined(AFX_GEOSTATKRIGLIB_H__614596C4_13C5_4CC1_B75B_AD7383089B49__INCLUDED_)
