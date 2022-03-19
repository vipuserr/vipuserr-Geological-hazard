#ifndef _BASE_STATISTIC_QTY_EXP_H
#define _BASE_STATISTIC_QTY_EXP_H

#ifndef _BASE_STATISTIC_QTY_LIB
#define _BASE_STATISTIC_QTY_DLL __declspec(dllimport)
#else
#define _BASE_STATISTIC_QTY_DLL __declspec(dllexport)
#endif


#define MIN_DOUBLE_STAT (-1.79769313486232E+307)
#define MAX_DOUBLE_STAT (+1.79769313486232E+307)
#define DEFAULT_MIN_VALUE	-999 //区间的缺省最小值
#define DEFAULT_MAX_VALUE	999  //区间的缺省最大值

typedef struct 
{
	double	dData;
	long	lDataID;
}ORDER_DATA;

typedef struct
{
	ORDER_DATA	*pOrderData;
	long	lDataNum;
}ORDER_STRU;



class _BASE_STATISTIC_QTY_DLL CBaseStatisticQty
{
public:
	CBaseStatisticQty(double *pdStatData, long lDataNum);
	~CBaseStatisticQty();

public:
	// **********************************集中趋势**************************** //
	// 简单算术平均数
	double SimpleArithAverNum();
	// 加权算术平均数
	double PowerArithAverNum(BOOL bMode = FALSE);
	// 几何平均数
	double GeometryAverNum();
	// 中位数
	double MedianNum();
	// 众数
	double NumerousNum();
	// 分位数
	void SubSectionNum(double **ppdSubSecData, long lSubSecDataNum, long *plSubSecNum);
	
	// ***********************************离散程度*************************** //
	// 最大值与最小值
	void ExtremumNum(double *pdMaxNum, double *pdMinNum);
	// 极差
	double ExtreDifNum();
	// 离差
	void DisDifNum(double *pdDisDifData);
	// 平均离差
	double DisDifAverNum();
	// 离差平方和
	double DisDifSqrSum();
	// 方差
	double SqrDifNum();
    //均方差
    double SqraverDifNum();
	// 标准差
	double StandDifNum();
	// 变差系数
	double AlterDifCoe();

	// ***********************************分布形状*************************** //
	// 偏度
	double DeflectDegree();
	// 峰度
	double ApexDegree();

	//////////////////////////////////////////////////////////////////////////
	/////////////////////////////分组统计/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

	//------------------------等间距分级------------------------//
	// 数据区间统计
	long DataStatByArea(
		double dStartVal, double dEndVal,
		long **pplSmpIDList, long *plListNum);
	// 数据分段统计(按最大值与最小值分段)
	long DataSecByMaxMin(
		long lSubSecNum,
		double **ppdSubSecPt, long *plSubSecPtNum,
		long **pplSmpIDList, long **pplListNum);
	/////////////////////////////////////huwah新增/////////////////////////////////////
	//指定起始值和步长进行等间距分级统计
	long DataStatByStartAndStep(
		double dStartVal, double dStep,
		double **ppdSubSecPt, long *plSubSecPtNum,
		long **pplSmpIDList, long **pplListNum,
		double dEndVal = DEFAULT_MAX_VALUE);
	//指定起始值和分组数进行等间距分级统计
	long DataStatByStartAndGroupNum(
		double dStartVal, long ldGroupNum,
		double **ppdSubSecPt, long *plSubSecPtNum,
		long **pplSmpIDList, long **pplListNum,
		double dEndVal = DEFAULT_MAX_VALUE);

	//------------------------标准差分级------------------------//
	// 数据分段统计(按平均值与标准差分段)
	long DataSecByAverStd(
		long lStdMul, double dStepMul,
		double **ppdSubSecPt, long *plSubSecPtNum,
		long **pplSmpIDList, long **pplListNum);
	/////////////////////////////////huawh新增///////////////////////////////////////////
	//指定起始值和终止值进行标准差分级统计
	long DataSecByAverStdAndMinMax(
		long lStdMul, double dStepMul,
		double **ppdSubSecPt, long *plSubSecPtNum,
		long **pplSmpIDList, long **pplListNum,
		double dMin=DEFAULT_MIN_VALUE, double dMax=DEFAULT_MAX_VALUE);


private:
	// 数据频数
	BOOL FrequenceNum(double *pdOrigData, long *plFreqData);
	// 数据排序
	//	long	lType 采用排序算法类型     0 快速排序(默认);    1 冒泡法
	BOOL OrderData(long lType = 0);
	// 排序算法
	void QuickSort(ORDER_DATA x[], long low, long high);
	//void ShellSort(ORDER_DATA x[], long low, long high);
	void BubbleSort(ORDER_DATA x[], long low, long high);

	// 数据ID查找
	long DataIDSeach(ORDER_DATA s[], double key, long n);
	
private:
	double	*m_pdStatData;					//原始数据数组
	long	m_lDataNum;						//数据总个数
	ORDER_STRU m_OrderData;					//排序数据
	
	double	m_dAverVal;						//平均值
	double	m_dNumerousNum;					//众数
	double	m_dMedianNum;					//中位数
	double	m_dDisDifAverVal;				//平均离差
	double	m_dDifDisSqrSumVal;				//离差平方和
	double	m_dSqrDifVal;					//方差
	double  m_dStandDifVal;					//标准差
	double	m_dAlterDifCoe;					//变差系数
    
    double  m_dAverDifVal;                  //均方差：NXX_2006_12_19
	
	double	*m_pdSubSecData;				//分位数
	long	*m_plSmpIDList;					//区间数据ID
	double  *m_pdSecPtMaxMin;
	double	*m_pdSecPtAverStd;
	long	*m_plListNumMaxMin;
	long	*m_plSmpIDListMaxMin;
	long	*m_plListNumAverStd;
	long	*m_plSmpIDListAverStd;

	BOOL	m_bArithAverNumFlag;			//平均数计算标记
	BOOL	m_bOrderDataFlag;				//排序数据计算标记	
	BOOL	m_bPowerAverNumFlag;			//加权平均数计算标记
	BOOL	m_bDisDifNumFlag;				//离差计算标记
};

void _BASE_STATISTIC_QTY_DLL _ReadColorTable(char* clrLutFile, void* clrBuf, short& clrNum);


#ifndef _BASE_STATISTIC_QTY_LIB
	#pragma comment(lib, "s3dKerStatistics.lib")
#endif

#endif //_BASE_STATISTIC_QTY_EXP_H