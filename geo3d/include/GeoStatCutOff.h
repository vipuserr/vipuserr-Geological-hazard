//==========================================================================
//      版权:ZTYQ Tech. Co., Ltd.//版权
//      工程名: GeoStatKrig。
//      作者: lhy，2007.05
//      功能描述: 完成品位阈值的设置
//      版本:  1.1，2007.05。
//      修改记录:  无。
//      主要函数列表: 
//      _cLoadGsCutOff -------------------------------------------->导入数据
//      _cSetExtrData ----------------------------------------->设置数据极值
//      _cCptIkCutOff ----------------------------------------->计算中值阈值
//      _cCptCutOff ----------------------------------------------->计算阈值
//==========================================================================

#if !defined(AFX_GEOSTATCUTOFF_H__D5C63F0D_54F6_41FA_8A0F_FA4E810AD255__INCLUDED_)
#define AFX_GEOSTATCUTOFF_H__D5C63F0D_54F6_41FA_8A0F_FA4E810AD255__INCLUDED_

#include "GsStru.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _GEO_STAT_KRIG_LIB
#define  _GEO_STAT_KRIG_DLL _declspec(dllimport)
#else
#define _GEO_STAT_KRIG_DLL _declspec(dllexport)
#endif

class _GEO_STAT_KRIG_DLL CGeoStatCutOff  
{
public:
	CGeoStatCutOff();
	virtual ~CGeoStatCutOff();


	//================================================================================
    // 函 数 名：_cLoadGsCutOff
    // 功能描述：该函数装入的数据,即是阈值处理功能中处理的数据. 
	// 输入参数：pDiscPnts          ： 数据点
	//           lDatNum            ： 数据数目
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cLoadGsCutOff(GsDiscPnt *pDiscPnts, long lpntNum);
	
	//================================================================================
    // 函 数 名：_cSetExtrData
    // 功能描述：该函数用来设置进行阈值处理的数据属性的极值
	// 输入参数：fExtrMax 　        ： 数据极大值
	//           fExtrMin           ： 数据极小值
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cSetExtrData(double fExtrMax, double fExtrMin);

	//================================================================================
    // 函 数 名：_cCptIkCutOff
    // 功能描述：该函数用作指示克里格，用来计算指示克里格的中值阈值
	// 输出参数：fCutOff            ： 中值阈值
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cCptIkCutOff(double &fCutOff);
	
	//================================================================================
    // 函 数 名：_cCptCutOff
    // 功能描述：该函数用来设置计算阈值处理中得到的阈值参数
	// 输入参数：iCutOffNum         ： 阈值个数
	//           ikCfMethod         ： 阈值处理方法
	// 输出参数：fIkfThres          ： 得到的阈值参数
	//           fIkfCdf            ： 与阈值对应的累积概率
    // 返回值  ：无
    // 创建日期：2007-05-16
    // 修改日期：2007-05-16
    // 附加说明：
    //================================================================================
	void _cCptCutOff(int iCutOffNum, int ikCfMethod, double fIkfThres[], double fIkfCdf[]);

private:
	//原始数据信息
	GsDiscPnt    *m_pDiscPnts;
	long          m_lpntNum;
    
	//数据极值
	double        m_fExtrMax;
	double        m_fExtrMin;
};
#ifndef _GEO_STAT_KRIG_LIB
	#ifdef _DEBUG
		#pragma comment(lib, "GeoStatKrigLibD.lib")
	#else
		#pragma comment(lib, "GeoStatKrigLib.lib")
	#endif
#endif
#endif // !defined(AFX_GEOSTATCUTOFF_H__D5C63F0D_54F6_41FA_8A0F_FA4E810AD255__INCLUDED_)
