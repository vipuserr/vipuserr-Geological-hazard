//==========================================================================
//      版权:ZTYQ Tech. Co., Ltd.//版权
//      工程名: GeoStatKrig。
//      作者: lhy，2007.12
//      功能描述: 完成数据变换和处理功能
//      版本:  1.1，2007.12。
//      修改记录:  无。
//      主要函数列表: 
//      _cdLoadGsChgData ------------------------------------------>导入数据
//      _cdSetExtrData ---------------------------------------->设置数据极值
//      _cdSetReplaceData ------------------------------------->设置替换数据
//      _cdCptSkmean ---------------------------------------->计算数据平均值
//      _cdCptDataInfo ---------------------------------------->计算数据范围
//      _cdCptGridDefine -------------------------------------->计算格网定义
//      _cdCptTranData ------------------------------------>进行数据变换处理
//      _cdCptAxiOrg ---------------------------------------->对数据进行旋转
//==========================================================================

#if !defined(AFX_GEOSTATCHGDATA_H__B3A592CA_157B_4DB7_AFC7_4036291DED80__INCLUDED_)
#define AFX_GEOSTATCHGDATA_H__B3A592CA_157B_4DB7_AFC7_4036291DED80__INCLUDED_

#include "gsstru.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _GEO_STAT_KRIG_LIB
#define  _GEO_STAT_KRIG_DLL _declspec(dllimport)
#else
#define _GEO_STAT_KRIG_DLL _declspec(dllexport)
#endif

class _GEO_STAT_KRIG_DLL CGeoStatChgData  
{
public:
	CGeoStatChgData();
	virtual ~CGeoStatChgData();

	//================================================================================
    // 函 数 名：_cdLoadGsChgData
    // 功能描述：该函数装入的数据,即是数据处理功能中处理的数据
	// 输入参数：pDiscPnts          ： 数据点
	//           lDatNum　          ： 数据数目
	//           pPreAttr　         ： 原始数据属性值
	//           bIsDim             ： TRUE为三维数据，FLASE为二维数据
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cdLoadGsChgData(GsDiscPnt *pDiscPnts, long lpntNum, double *pPreAttr, BOOL bIsDim);

	//================================================================================
    // 函 数 名：_cdSetExtrData
    // 功能描述：该函数用来设置进行数据变换的数据属性的极值
	// 输入参数：fExtrMax           ： 数据极大值
	//           fExtrMin           ： 数据极小值
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cdSetExtrData(double fExtrMax, double fExtrMin);

	//================================================================================
    // 函 数 名：_cdSetReplaceData
    // 功能描述：该函数用来设置替换数据
	// 输入参数：fReplaceMax        ： 替换数据最大值
	//           fReplaceMin        ： 替换数据最小值
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cdSetReplaceData(double fReplaceMax, double fReplaceMin);

	//================================================================================
    // 函 数 名：_cdCptSkmean
    // 功能描述：该函数用来计算输入数据的平均值
	// 输出参数：fSkMean            ： 数据平均值
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	//设置平均值
	//说明: 该函数用来计算输入数据的平均值
	//参数:
	//      fSkMean -----------------> 数据平均值(传出)
	void _cdCptSkmean(double &fSkMean);

	//================================================================================
    // 函 数 名：_cdCptDataInfo
    // 功能描述：该函数用来计算传入数据的数据范围，X，Y，Z间距以及数据个数
	// 输出参数：xyzMinDist         ： 数据范围的起始值
	//           xyzMaxDist         ： 数据范围的终值值
	//           xadistance         ： X轴间距
	//           yadistance         ： Y轴间距
	//           zadistance         ： Z轴间距
	//           lpntNum            ： 数据个数
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cdCptDataInfo(GSD_3DOT &xyzMinDist, GSD_3DOT &xyzMaxDist, 
					 double &xadistance, double &yadistance, 
					 double &zadistance, long &lpntNum);

	//================================================================================
    // 函 数 名：_cdCptGridDefine
    // 功能描述：该函数用来初始化格网的参数
	// 输出参数：grid_numx          ： X轴格网个数
	//           grid_numy          ： Y轴格网个数
	//           grid_numz          ： Z轴格网个数
	//           grid_sizex         ： X轴格网大小
	//           grid_sizey         ： Y轴格网大小
	//           grid_sizez         ： Z轴格网大小
	//           grid_minix         ： X轴格网起始点坐标
	//           grid_miniy         ： Y轴格网起始点坐标
	//           grid_miniz         ： Z轴格网起始点坐标
	//           grid_maxx          ： X轴格网终止点坐标
	//           grid_maxy          ： Y轴格网终止点坐标
	//           grid_maxz          ： Z轴格网终止点坐标
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cdCptGridDefine(int &grid_numx, int &grid_numy, int &grid_numz,
									double &grid_sizex, double &grid_sizey, double &grid_sizez,
									double &grid_minix, double &grid_miniy, double &grid_miniz,
									double &grid_maxx, double &grid_maxy, double &grid_maxz);	
    
	//================================================================================
    // 函 数 名：_cdCptTranData
    // 功能描述：该函数用来对传入的数据进行数据变换
	// 输入参数：bExtrModeMin       ： 变换前数据极大值
	//           bExtrModeMax       ： 变换前数据极小值
	//           iTranType          ： 数据变换方式: 1对数变换，2正态变换
	//           fMinGzero          ： 小于0的最小值
	//           tr_var             ： 正态变换对应表(逆变换中用到)
	//           tr_vrg             ： 正态变换对应表(逆变换中用到)
	// 输出参数：TranMax            ： 变换后数据最大值
	//           TranMin            ： 变换后数据最小值
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cdCptTranData(BOOL bExtrModeMin, BOOL bExtrModeMax, int iTranType, double fMinGzero,
		                double *tr_var, double *tr_vrg, double &TranMax, double &TranMin);
	
	//================================================================================
    // 函 数 名：_cdCptAxiOrg
    // 功能描述：该函数用于进行块体模型的旋转
	// 输入参数：azm                ： 旋转方位角
	//           dip                ： 旋转倾角
	//           Org                ： 旋转倾伏角
	//           OrigXYZ            ： 旋转中心
	//           pPreXyz            ： 原始的XYZ坐标
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================	
	void _cdCptAxiOrg(int azm, int dip, int org, GSD_3DOT OrigXYZ, GSD_3DOT *pPreXyz);
	

	//-----------------------------------2008年8月21日------------------------------------------//
	//装入数据
	//说明:	该函数装入的数据,即是数据处理功能中处理的数据. 
	//参数:	
	//		pDiscPnts[] -------------> 数据点
	//		lDatNum -----------------> 数据数目
	//      pPreAttr[] --------------> 原始数据属性值
	//      bIsDim ------------------> TRUE为三维数据，FLASE为二维数据
	void _cdLoadGsChgData2(GsDiscPnt *pDiscPnts, long lpntNum, double *pPreAttr);

	GsDiscPnt  *m_pDiscPntsSec;
	long        m_lpntNumSec;
	double     *m_pPreAttrSec;

	//--------------------------------------end------------------------------------------------//
	
private:
	//原始数据信息
	GsDiscPnt  *m_pDiscPnts;
	long        m_lpntNum;
	double     *m_pPreAttr;
	BOOL        m_bIsDim;
    //数据极值
	double      m_fExtrMax;
	double      m_fExtrMin;

	//替换数据
	double      m_fReplaceMax;
	double      m_fReplaceMin;

    //包围盒
	GSD_3DOT      m_xyzMinDist;
	GSD_3DOT      m_xyzMaxDist;
    //数据间距
	double      m_xadistance;
	double      m_yadistance;
	double      m_zadistance;

};

#ifndef _GEO_STAT_KRIG_LIB
	#ifdef _DEBUG
		#pragma comment(lib, "GeoStatKrigLibD.lib")
	#else
		#pragma comment(lib, "GeoStatKrigLib.lib")
	#endif
#endif
#endif // !defined(AFX_GEOSTATCHGDATA_H__B3A592CA_157B_4DB7_AFC7_4036291DED80__INCLUDED_)
