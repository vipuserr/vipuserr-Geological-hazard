//==========================================================================
//      版权:ZTYQ Tech. Co., Ltd.//版权
//      工程名: GeoStatKrig。
//      作者: lhy，2007.05
//      功能描述: 完成交叉验证功能
//      版本:  1.1，2007.05。
//      修改记录:  无。
//      主要函数列表: 
//      _cvLoadGsCrosValid ---------------------------------------->导入数据
//      _cvSetExtrData ---------------------------------------->设置数据极值
//      _cvSetGridParam --------------------------------------->设置格网定义
//      _cvSetSrchParam ----------------------------------->设置搜索椭球定义
//      _cvCptcvKriging ------------------------------------->计算克里格估值
//      _cvCptcvIKriging -------------------------------->计算指示克里格估值
//      _cvCptcvInverse ----------------------------------->计算距离反比估值
//      CVBackTr ------------------------------------------>对数据进行逆变换
//==========================================================================

#if !defined(AFX_GEOSTATCROSVALID_H__DCF46D1F_2F3D_4846_908C_41EBFF177E57__INCLUDED_)
#define AFX_GEOSTATCROSVALID_H__DCF46D1F_2F3D_4846_908C_41EBFF177E57__INCLUDED_

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

class _GEO_STAT_KRIG_DLL CGeoStatCrosValid  
{
public:
	CGeoStatCrosValid();
	virtual ~CGeoStatCrosValid();

	//================================================================================
    // 函 数 名：_cvLoadGsCrosValid
    // 功能描述：该函数装入的数据,即是交叉验证功能中处理的数据. 
	// 输入参数：pDiscPnts          ： 数据点
	//           lDatNum            ： 数据数目
	//           pPreAttr           ： 原始数据属性值
	//           ptr_var            ： 正态变换对应表(正态变换中得到，正态逆变换中用到)
	//           ptr_vrg            ： 正态变换对应表(正态变换中得到，正态逆变换中用到)
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cvLoadGsCrosValid(GsDiscPnt *pDiscPnts, long lpntNum, double *PreAttr, double *ptr_var, double *ptr_vrg);
	
	//================================================================================
    // 函 数 名：_cvLoadGsCrosValid2
    // 功能描述：该函数装入辅助变量数据. 
	// 输入参数：pDiscPnts          ： 数据点
	//           lDatNum            ： 数据数目
    // 返回值  ：无
    // 创建日期：2008-09-23
    // 修改日期：2008-09-23
    // 附加说明：
    //================================================================================
	void _cvLoadGsCrosValid2(GsDiscPnt *pDiscPntsSec, long lPntNumSec);

	//================================================================================
    // 函 数 名：_cvSetExtrData
    // 功能描述：该函数用来设置进行交叉验证的数据属性的极值
	// 输入参数：fExtrMax           ： 数据极大值
	//           fExtrMin           ： 数据极小值
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cvSetExtrData(double fExtrMax, double fExtrMin);
	
	//================================================================================
    // 函 数 名：_cvSetGridParam
    // 功能描述：该函数用来设置交叉验证中用到的格网参数
	// 输入参数：cvxnum             ： X轴格网个数
	//           cvynum             ： Y轴格网个数
	//           cvznum             ： Z轴格网个数
	//           cvxmini            ： X轴格网起始坐标
	//           cvymini            ： Y轴格网起始坐标
	//           cvzmini            ： Z轴格网起始坐标
	//           cvxsize            ： X轴格网大小
	//           cvysize            ： Y轴格网大小
	//           cvzsize            ： Z轴格网大小
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cvSetGridParam(int cvxnum, int cvynum, int cvznum, 
		           double cvxmini, double cvymini, double cvzmini, 
				   double cvxsize, double cvysize, double cvzsize);
	//================================================================================
    // 函 数 名：_cvSetSrchParam
    // 功能描述：该函数用来设置交叉验证中用到的搜索椭球
	// 输入参数：cvmaxr_sec         ： 搜索椭球的长轴半径
	//           cvminr_sec         ： 搜索椭球的短轴半径
	//           cverr_sec          ： 搜索椭球的垂直轴半径
	//           cvang1_search      ： 搜索椭球旋转的方位角
	//           cvang2_search      ： 搜索椭球旋转的倾伏角
	//           cvang3_search      ： 搜索椭球旋转的倾角
	//           cvminnum_krg       ： 交叉验证过程中用到的最小样本点数
	//           cvmaxnum_krg       ： 交叉验证过程中用到的最大样本点数
	//           cvnumxblock        ： X方向上块段中离散点数
	//           cvnumyblock        ： Y方向上块段中离散点数
	//           cvnumzblock        ： Z方向上块段中离散点数
    // 返回值  ：无 
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cvSetSrchParam(double cvmaxr_sec, double cvminr_sec, double cvverr_sec, 
		             int cvang1_search, int cvang2_search, int cvang3_search, 
		             int cvminnum_krg, int cvmaxnum_krg, int cvnumxblock, int cvnumyblock, int cvnumzblock);
	
	//================================================================================
    // 函 数 名：_cvSetSecSrchParam
    // 功能描述：该函数用来设置交叉验证中用到的搜索椭球
	// 输入参数：iMaxSrchNum        ： 次变量估值最大个数
	//           maxr_sec           ： 搜索椭球的长轴半径
	//           minr_sec           ： 搜索椭球的短轴半径
	//           verr_sec           ： 搜索椭球的垂直轴半径
    // 返回值  ：无 
    // 创建日期：2008-09-23
    // 修改日期：2008-09-23
    // 附加说明：
    //================================================================================
	void _cvSetSecSrchParam( int iMaxSrchNum, double maxr_sec, double minr_sec, double verr_sec);		
	
	//================================================================================
    // 函 数 名：_cvSetSrchOct
    // 功能描述：该函数用来设置交叉验证过程中用到的椭球的搜索方式
	// 输入参数：cvoct              ： 0为普通搜索，其他数为八分圆搜索中每一份中搜索的样本点数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
    void _cvSetSrchOct(int cvnoct);

	//================================================================================
    // 函 数 名：_cvSetDisPower
    // 功能描述：该函数用来设置交叉验证过程中用到的距离反比幂次
	// 输入参数：cviDisPower ： 距离反比幂次
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cvSetDisPower(int cviDisPower);

	//================================================================================
    // 函 数 名：_cvSetKrigType
    // 功能描述：该函数用来设置交叉验证过程中的克里格估值类型
	// 输入参数：cvktype            ： 0为简单克里格，1为普通克里格，2为泛克里格，3为指示克里格 
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _cvSetKrigType(int cvktype);

	//================================================================================
    // 函 数 名：_cvSetCoKrigType
    // 功能描述：该函数用来设置交叉验证过程中的协克里格估值类型
	// 输入参数：cvCoKtype          ： 0传统普通协克里格，1为标准普通协克里格，2为简单协克里格
    // 返回值  ：无
    // 创建日期：2008-09-23
    // 修改日期：2008-09-23
    // 附加说明：
    //================================================================================	
	void _cvSetCoKrigType(int cvCoKtype);
	
	//================================================================================
    // 函 数 名：_cvSetSkMean
    // 功能描述：该函数用来设置简单克里格估值过程中用到的样品平均值
	// 输入参数：cvmeansk           ： 估值区域数据的平均值
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _cvSetSkMean(double cvmeansk);
	
	//================================================================================
    // 函 数 名：_cvSetCokMean
    // 功能描述：该函数用来设置协克里格估值过程中用到的样品平均值
	// 输入参数：pfVMeanVal         ： 估值区域各数据的平均值
    // 返回值  ：无
    // 创建日期：2008-09-23
    // 修改日期：2008-09-23
    // 附加说明：
    //================================================================================
	void _cvSetCokMean(double pfVMeanVal[]);

	//================================================================================
    // 函 数 名：_cvSetIntpPara
    // 功能描述：该函数用来设置克里格估值中用到的变差函数参数
	// 输入参数：cvnst              ： 变差函数模型个数
	//           cvc0               ： 块金值
	//           cvcc               ： 拱高值
	//           cvit               ： 变差函数类型
	//           cvaa               ： 变差函数主轴变程
	//           cvaa1              ： 变差函数次轴变程
	//           cvaa2              ： 变差函数垂直轴变程
	//           cvang1             ： 变差函数各向异性角度方位角
	//           cvang2             ： 变差函数各向异性角度倾伏角
	//           cvang3             ： 变差函数各向异性角度倾角
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _cvSetIntpPara(int cvnst, double cvc0, double cvcc[], int cvit[], double cvaa[], double cvaa1[],
		double cvaa2[], double cvang1[], double cvang2[], double cvang3[]);
    
	//================================================================================
    // 函 数 名：_cvSetDrifTerm
    // 功能描述：该函数用来设置漂移
	// 输入参数：cvidrif            ： 0表示该方向上不存在漂移，1表示存在漂移
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _cvSetDrifTerm(int cvidrif[]);
	
	//================================================================================
    // 函 数 名：_cvSetTranModel
    // 功能描述：该函数用来设置数据转换的方式
	// 输入参数：cvtranslation      ： 0表示无变换，1表示对数变换，2表示正态变换
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _cvSetTranModel(int cvtranslation);
	
	//================================================================================
    // 函 数 名：_cvSetMinAttrGzero
    // 功能描述：该函数用来设置对数变换过程中用到的偏移量
	// 输入参数：cvfMinGzero        ： 对数变换中用到的偏移量
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _cvSetMinAttrGzero(double cvfMinGzero);
    
	//================================================================================
    // 函 数 名：_cvSetThresAndCdf
    // 功能描述：该函数用来设置指示克里格过程中用到的阈值参数
	// 输入参数：pfThres            ： 阈值
	//           pfCdf              ： 与阈值对应的累积概率
	//           lThresNum          ： 阈值个数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cvSetThresAndCdf(double pfThres[], double pfCdf[], long lThresNum);
    
	//================================================================================
    // 函 数 名：_cvSetMeanThres
    // 功能描述：该函数用来设置指示克里格类型，中值阈值
	// 输入参数：cviktype           ： 0为普通克里格，1为简单克里格
	//           cvikCutOff         ： 中值阈值
	//           cvktype_ik         ： 0为中值克里格，1为完全克里格
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _cvSetMeanThres(int cviktype, double cvikCutOff, int cvktype_ik);
    
	//================================================================================
    // 函 数 名：_cvSetIkIntpPara
    // 功能描述：该函数用来设置指示克里格中用到的变差函数参数
	// 输入参数：cvIkIntpPara       ： 变差函数参数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _cvSetIkIntpPara(Kt3dIntp cvIkIntpPara[]);
	
	//================================================================================
    // 函 数 名：_cvSetCokIntpPara
    // 功能描述：该函数用来设置协克里格中用到的变差函数参数
	// 输入参数：pCokIntpPara       ： 变差函数参数
	//           lCokIntpNum        ： 变差函数个数
    // 返回值  ：无
    // 创建日期：2008-09-23
    // 修改日期：2008-09-23
    // 附加说明：
    //================================================================================
	long _cvSetCokIntpPara(Kt3dIntp pCokIntpPara[], long lCokIntpNum=1);	

	//================================================================================
    // 函 数 名：_cvCptcvKriging
    // 功能描述：该函数用来计算普通克里格
	// 输出参数：cvpEstabPnts       ： 普通克里格估值结果
	//           cvlOutPntNum       ： 普通克里格估值结果个数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _cvCptcvKriging(EstabPnt *cvpEstabPnts, long &cvlOutPntNum);
	
	//================================================================================
    // 函 数 名：_cvCptcvIKriging
    // 功能描述：该函数用来计算指示克里格
	// 输出参数：EstabVal           ： 指示克里格估值结果
	//           EstabVari          ： 指示克里格估值方差
	//           OriVal             ： 估值原值
	//           TErr               ： 估值误差
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _cvCptcvIKriging(double *EstabVal, double *EstabVari, double *OriVal, double *TErr);
	
	//================================================================================
    // 函 数 名：_cvCptcvInverse
    // 功能描述：该函数用来进行距离反比估值
	// 输入参数：cvpEstabPnts       ： 距离反比估值结果
	//           cvlOutPntNum       ： 距离反比估值结果个数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _cvCptcvInverse(EstabPnt *cvpEstabPnts, long &cvlOutPntNum);

	//================================================================================
    // 函 数 名：_cvCptcvCoKrig
    // 功能描述：该函数用来计算协克里格
	// 输出参数：EstabVal           ： 指示克里格估值结果
	//           EstabVari          ： 指示克里格估值方差
	//           OriVal             ： 估值原值
	//           TErr               ： 估值误差
    // 返回值  ：无
    // 创建日期：2008-09-23
    // 修改日期：2007-09-23
    // 附加说明：
    //================================================================================	
	void _cvCptcvCoKrig(double *EstabVal, double *EstabVari, double *OriVal, double *TErr);

	//================================================================================
    // 函 数 名：CVBackTr
    // 功能描述：该函数用来对估值结果进行逆变换
	// 输入参数：cvpEstabPnts       ： 估值结果
	//           cvlOutPntNum       ： 估值结果个数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	//数据逆变换
	//说明: 该函数用来对估值结果进行逆变换
	//参数:
	//      cvpEstabPnts ------------> 估值结果
	//      cvlOutPntNum ------------> 估值结果个数
	void CVBackTr(EstabPnt *cvpEstabPnts, long &cvlOutPntNum);
	
private:
	//原始数据信息
	GsDiscPnt			*m_pDiscPnts;
	long				m_lpntNum;
	double				*m_pPreAttr;
	double				*m_cvtr_var;
	double				*m_cvtr_vrg;

	//次变量数据2008-9-23
	GsDiscPnt			*m_pDiscPntsSec;
	long				m_lPntNumSec;
	
	//数据极值
	double				m_fExtrMax;
	double				m_fExtrMin;

	//克里格对象
	CGeoStat			*m_cvKrigObj;

	//格网信息
	int					m_cvxnum;
	int					m_cvynum;
	int					m_cvznum;
    double				m_cvxmini;
	double				m_cvymini;
	double				m_cvzmini;
    double				m_cvxsize;
	double				m_cvysize;
	double				m_cvzsize;

	//搜索椭球信息
    double				m_cvmaxr_sec;
	double				m_cvminr_sec;
	double				m_cvverr_sec; 	             
	int					m_cvang1_search;
	int					m_cvang2_search;
	int					m_cvang3_search;
    int					m_cvminnum_krg;
	int					m_cvmaxnum_krg;
	int					m_cvnumxblock;
	int					m_cvnumyblock;
	int					m_cvnumzblock;
    //次变量搜索椭球信息
	long				m_iMaxSrchSecNum;
	double				m_fSecMaxR;
	double				m_fSecMinR;
	double				m_fSecVerR;

	//变差函数拟合结果	
	int					m_cvnst[1];
	double				m_cvc0[1];
	int					m_cvit[GS_MAXNST];
	double				m_cvcc[GS_MAXNST]; 
	double				m_cvang1[GS_MAXNST];
	double				m_cvang2[GS_MAXNST];
	double				m_cvang3[GS_MAXNST];
	double 				m_cvaa[GS_MAXNST];
	double				m_cvaa1[GS_MAXNST];
	double				m_cvaa2[GS_MAXNST];	
    Kt3dIntp			m_cvCokIntpPara[GS_MXVARG];
	int					m_cvnoct;

	//克里格信息
	int					m_cvktype;
	double				m_cvmeansk;
	int					m_cvidrif[9];
	int					m_cvtranslation;
	double				m_cvfMinGzero;
	int                 m_cviDisPower;

    int                 m_cvCoKtype;
	double              m_pfMeanVal[GS_MAXVAR];
	
	//定义指示克里格变量	
	double				m_cvikfThres[GS_MAXCUT];
	double				m_cvikfCdf[GS_MAXCUT];
	int					m_cvikCutNum;
    double				m_cvikCutOff;

	Kt3dIntp			m_cvIkIntpPara[GS_MAXCUT];

	long				m_cvlIkCcdfNum;

	int					m_cviktype;
	int					m_cvktype_ik;

	BOOL				m_bIsShowProgr;
};

#ifndef _GEO_STAT_KRIG_LIB
	#ifdef _DEBUG
		#pragma comment(lib, "GeoStatKrigLibD.lib")
	#else
		#pragma comment(lib, "GeoStatKrigLib.lib")
	#endif
#endif
#endif // !defined(AFX_GEOSTATCROSVALID_H__DCF46D1F_2F3D_4846_908C_41EBFF177E57__INCLUDED_)
