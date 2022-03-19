//==========================================================================
//      版权:ZTYQ Tech. Co., Ltd.//版权
//      工程名: GeoStatKrig。
//      作者: lhy，2007.05
//      功能描述: 完成变差函数计算及拟合功能
//      版本:  1.1，2007.05。
//      修改记录:  无。
//      主要函数列表: 
//      _mnLoadGsModelNest ---------------------------------------->导入数据
//      _mnSetExtrData ---------------------------------------->设置数据极值
//      _mnSetGamvParam ------------------------------->设置变差函数计算参数
//      _mnCptExpVrg -------------------------------------->计算实验变差函数
//      _mnComputerVM ----------------------------------->计算变差函数表面图
//      _mnAutoFitVrg ------------------------------->对单个变差函数进行拟合
//      CptAllVrgFitDsp ------------------------------->计算多个方向变差函数
//==========================================================================

#if !defined(AFX_GEOSTATMODELNEST_H__6B7DBAFB_3909_4DF7_9441_044F8CD47BBB__INCLUDED_)
#define AFX_GEOSTATMODELNEST_H__6B7DBAFB_3909_4DF7_9441_044F8CD47BBB__INCLUDED_

#include "GsStru.h"
#include "geostatlib.h"

#include "RSErrorOpr.h"			//错误码

#include   <vector> 
using   namespace   std;   

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _GEO_STAT_KRIG_LIB
#define  _GEO_STAT_KRIG_DLL _declspec(dllimport)
#else
#define _GEO_STAT_KRIG_DLL _declspec(dllexport)
#endif



class _GEO_STAT_KRIG_DLL CGeoStatModelNest  
{
public:
	CGeoStatModelNest();
	virtual ~CGeoStatModelNest();
	
	//================================================================================
    // 函 数 名：_mnLoadGsModelNest
    // 功能描述：该函数装入的数据,即是变差函数计算及拟合功能中处理的数据
	// 输入参数：pDiscPnts          ： 数据点
	//           plpntNum           ： 数据数目
	//           bIsDim             ： TRUE为三维数据，FLASE为二维数据
	//           bIsDsp3D　         ： 是否显示三维图形
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================		
    void _mnLoadGsModelNest(GsDiscPnt *pDiscPnts, long plpntNum, BOOL bIsDim, BOOL bIsDsp3D);	

	//================================================================================
    // 函 数 名：_mnSetExtrData
    // 功能描述：设置变差函数计算数据极值
	// 输入参数：fExtrMax           ： 数据极大值
	//           fExtrMin           ： 数据极小值
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnSetExtrData(double fExtrMax, double fExtrMin);    

	//================================================================================
    // 函 数 名：_mnSetVrgType
    // 功能描述：设置变差函数计算类型
	// 输入参数：ivType             ： 变差函数类型
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnSetVrgType(int ivType);	

	//================================================================================
    // 函 数 名：_mnSetVrgAnis
    // 功能描述：设置是否为各向异性处理
	// 输入参数：banisang           ： 是否为各向异性
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnSetVrgAnis(BOOL banisang);

	//================================================================================
    // 函 数 名：_mnSetAnis
    // 功能描述：设置各向异性角度
	// 输入参数：anisang1           ： 各向异性方位角
	//           anisang1           ： 各向异性倾伏角
	//           anisang1           ： 各向异性倾角
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnSetAnis(double anisang1, double anisang2, double anisang3);

	//================================================================================
    // 函 数 名：_mnSetVrgThre
    // 功能描述：设置阈值
	// 输入参数：vrg_num            ： 变差函数个数
	//           vrg_thre           ： 指示阈值
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnSetVrgThre(int vrg_num, double vrg_thre[]);	

	//================================================================================
    // 函 数 名：_mnSetGamvParam
    // 功能描述：设置实验变差函数计算参数
	// 输入参数：vrgdlag            ： 步长大小
	//           vrgltol            ： 步长容差
	//           vrgnlag            ： 步长数目
	//           vrg_azmtol         ： 方位角角度容差
	//           vrg_bandwd         ： 水平带宽
	//           vrg_bandwh         ： 垂直带宽
	//           vrg_diptol         ： 倾角角度容差
	//           vrg_azm            ： 方位角
	//           vrg_dip            ： 倾角
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnSetGamvParam(double	vrgdlag, double vrgltol, long vrgnlag, double vrg_azmtol,
	         double	vrg_bandwh, double vrg_bandwd, double vrg_diptol, int vrg_azm, int vrg_dip);

		//================================================================================
    // 函 数 名：_mnSetGamvParam
    // 功能描述：设置实验变差函数计算参数
	// 输入参数：vrgdlag[]          ： 步长大小
	//           vrgltol[]          ： 步长容差
	//           vrgnlag[]          ： 步长数目
	//           lParamNum          ： 参数个数
	//           vrg_azmtol         ： 方位角角度容差
	//           vrg_bandwd         ： 水平带宽
	//           vrg_bandwh         ： 垂直带宽
	//           vrg_diptol         ： 倾角角度容差
	//           vrg_azm            ： 方位角
	//           vrg_dip            ： 倾角
    // 返回值  ：无
    // 创建日期：2009-08-26
    // 修改日期：2009-08-26
    // 附加说明：
    //================================================================================
	void _mnSetGamvParam(double	vrgdlag[], double vrgltol[], long vrgnlag[], long lParamNum, double vrg_azmtol,
	         double	vrg_bandwh, double vrg_bandwd, double vrg_diptol, int vrg_azm, int vrg_dip);

		//================================================================================
    // 函 数 名：_mnSetGamvParam
    // 功能描述：设置实验变差函数计算参数
	// 输入参数：vrgdlag            ： 步长大小
	//           vrgltol            ： 步长容差
	//           vrgnlag            ： 步长数目
	//           vrg_azmtol         ： 方位角角度容差
	//           vrg_bandwd         ： 水平带宽
	//           vrg_bandwh         ： 垂直带宽
	//           vrg_diptol         ： 倾角角度容差
	//           vrg_azm[]          ： 方位角
	//           vrg_dip[]          ： 倾角
	//           lParamNum          ： 参数个数
    // 返回值  ：无
    // 创建日期：2009-08-26
    // 修改日期：2009-08-26
    // 附加说明：
    //================================================================================
	void _mnSetGamvParam(double	vrgdlag, double vrgltol, long vrgnlag, double vrg_azmtol[],
	         double	vrg_bandwh[], double vrg_bandwd[], double vrg_diptol[], int vrg_azm[], int vrg_dip[], long lParamNum);


	//================================================================================
    // 函 数 名：_mnCptExpVrg
    // 功能描述：计算实验变差函数
	// 输出参数：pVrgResult         ： 实验变差函数值
	//           fSill 　           ： 方差
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnCptExpVrg(Variogram *pVrgResult, double &fSill);	

	//================================================================================
    // 函 数 名：_mnCptAnisExpVrg
    // 功能描述：计算三个轴向的实验变差函数
	// 输入参数：pVrgResultMax      ： 主轴方向变差函数值
	//           pVrgResultMin      ： 次轴方向变差函数值
	//           pVrgResultVer      ： 垂直轴方向变差函数值
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnCptAnisExpVrg(Variogram *pVrgResultMax, Variogram *pVrgResultMin, Variogram *pVrgResultVer);
	
	//================================================================================
    // 函 数 名：_mnLoadResult
    // 功能描述：导入变差函数结果
	// 输入参数：pVrgResult         ： 变差函数值
	//           pVrgWeight         ： 变差函数权重
	//           pVrgModel          ： 变差函数拟合结果
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	//导入变差函数结果
	void _mnLoadResult(Variogram *pVrgResult, double *pVrgWeight,
									  Kt3dIntp *pVrgModel);

	//================================================================================
    // 函 数 名：_mnGetAnis
    // 功能描述：得到各向异性角度
	// 输出参数：anisang1           ： 各向异性方位角
	//           anisang1           ： 各向异性倾伏角
	//           anisang1           ： 各向异性倾角
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnGetAnis(int &anisang1, int &anisang2, int &anisang3);

	//================================================================================
    // 函 数 名：_mnGetGamvParam
    // 功能描述：得到实验变差函数计算参数
	// 输出参数：vrgdlag            ： 步长大小
	//           vrgltol            ： 步长容差
	//           vrgnlag            ： 步长数目
	//           vrg_azmtol         ： 方位角角度容差
	//           vrg_bandwd         ： 水平带宽
	//           vrg_bandwh         ： 垂直带宽
	//           vrg_diptol         ： 倾角角度容差
	//           vrg_azm            ： 方位角
	//           vrg_dip            ： 倾角
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnGetGamvParam(double	&vrgdlag, double &vrgltol, long &vrgnlag, double &vrg_azmtol,
	         double	&vrg_bandwd, double &vrg_bandwh, double &vrg_diptol, int &vrg_azm, int &vrg_dip);

	//================================================================================
    // 函 数 名：_mnGetGamvResult
    // 功能描述：取得变差函数结果
	// 输出参数：pVrgResult         ： 实验变差函数点
	//           pVrgWeight         ： 实验变差函数权值
	//           pVrgPoint          ： 实验变差函数点坐标
	//           pbSelect           ： 实验变差函数选中标志
	//           pVrgModel          ： 变差函数拟合结果
	//           pVrgModInd         ： 拟合后的变差函数点
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnGetGamvResult(Variogram **pVrgResult, double **pVrgWeight, CPoint **pVrgPoint, BOOL **pbSelect,
		     Kt3dIntp **pVrgModel, ModIndVrg **pVrgModInd);

	//================================================================================
    // 函 数 名：_mnGetVarMapPlant
    // 功能描述：取得变差函数表面图表面三个坐标
	// 输出参数：dX1                ： 点1X
	//           dY1                ： 点1Y
	//           dZ1                ： 点1Z
	//           dX2                ： 点2X
	//           dY2                ： 点2Y
	//           dZ2                ： 点2Z
	//           dX3                ： 点3X
	//           dY3                ： 点3Y
	//           dZ3                ： 点3Z
	//           dXvertical         ： 点垂直轴X
	//           dYvertical         ： 点垂直轴Y
	//           dZvertical         ： 点垂直轴Z
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnGetVarMapPlant(double &dX1, double &dY1, double &dZ1, double &dX2, double &dY2, double &dZ2,
		     double &dX3, double &dY3, double &dZ3, double &dXvertical, double &dYvertical, double &dZvertical);

	//================================================================================
    // 函 数 名：_mnGetVrgMod
    // 功能描述：取得变差函数模型信息三维
	// 输入参数：vrgmodX            ： x坐标值
	//           vrgmodY            ： y坐标值
	//           vrgmodZ            ： z坐标值
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	//取得变差函数模型信息
	void _mnGetVrgMod(double vrgmodX[], double vrgmodY[], double vrgmodZ[]);

	//================================================================================
    // 函 数 名：_mnSetVarMapAng
    // 功能描述：设置变差函数表面图角度
	// 输入参数：vmazm              ： 方位角
	//           vmdip              ： 倾角
	//           vmorg              ： 倾伏角
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnSetVarMapAng(double vmazm, double vmdip, double vmorg);

	//================================================================================
    // 函 数 名：_mnSetVrgNug
    // 功能描述：设置块金值
	// 输入参数：vrgmodnugget       ： 块金值
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	//设置块金值
	void _mnSetVrgNug(double  vrgmodnugget);

	//================================================================================
    // 函 数 名：_mnGetVrgSill
    // 功能描述：取得基台值
	// 输出参数：vrgmodsill         ： 基台值
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnGetVrgSill(double &vrgmodsill);

	//================================================================================
    // 函 数 名：_mnGetVrgAnis
    // 功能描述：取得是否为各向异性
	// 输入参数：banisang           ： 是否为各向异性
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnGetVrgAnis(BOOL &banisang);

	//================================================================================
    // 函 数 名：_mnSetVrgAnisAng
    // 功能描述：设置三个轴向角度
	// 输入参数：azmmax　           ： 主轴方位角
	//           dipmax　           ： 主轴倾角
	//           azmmin　           ： 次轴方位角
	//           dipmin　           ： 次轴倾角
	//           azmver　           ： 垂直轴方位角
	//           dipver　           ： 垂直轴倾角
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnSetVrgAnisAng(int azmmax, int dipmax, int azmmin, int dipmin,
		                  int azmver, int dipver);

	//================================================================================
    // 函 数 名：_mnGetVrgAnisAng
    // 功能描述：取得三个轴向角度
	// 输出参数：azmmax　           ： 主轴方位角
	//           dipmax　           ： 主轴倾角
	//           azmmin　           ： 次轴方位角
	//           dipmin　           ： 次轴倾角
	//           azmver　           ： 垂直轴方位角
	//           dipver　           ： 垂直轴倾角
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnGetVrgAnisAng(int &azmmax, int &dipmax, int &azmmin, int &dipmin,
		                  int &azmver, int &dipver);

	//================================================================================
    // 函 数 名：_mnSetListVrgModel
    // 功能描述：设置变差函数拟合结果
	// 输入参数：pListVrgModel      ： 变差函数拟合结果
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnSetListVrgModel(Kt3dIntp *pListVrgModel);

	//================================================================================
    // 函 数 名：_mnSetVrgStruChg
    // 功能描述：设置变差函数拟合结果可否修改
	// 输入参数：bIsVrgChg          ： 变差函数拟合结果可否修改
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnSetVrgStruChg(BOOL bIsVrgChg);

	//================================================================================
    // 函 数 名：_mnSetIvCutOff
    // 功能描述：设置阈值
	// 输入参数：ivCutOff           ： 阈值
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	//设置阈值
	void _mnSetIvCutOff(int ivCutOff);

	//================================================================================
    // 函 数 名：_mnSetSelectWeight
    // 功能描述：设置权值
	// 输入参数：bselect            ： 是否选中标志
	//           fweight            ： 权值
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnSetSelectWeight(BOOL *bselect, double *fweight);

	//================================================================================
    // 函 数 名：_mnChgAngUpdatadsp
    // 功能描述：修改变差函数图显示角度
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnChgAngUpdatadsp();

	//================================================================================
    // 函 数 名：_mnCheckAnisang
    // 功能描述：多方向变差函数拟合
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnCheckAnisang();

    //================================================================================
    // 函 数 名：_mnChgAngAnisUpdatadsp
    // 功能描述：修改各向异性角度
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnChgAngAnisUpdatadsp();

	//================================================================================
    // 函 数 名：_mnChgVrgStruUpdatadsp
    // 功能描述：修改变差函数结构
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnChgVrgStruUpdatadsp();

	//================================================================================
    // 函 数 名：_mnChgVrgParamUpdatadsp
    // 功能描述：修改实验变差函数参数
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnChgVrgParamUpdatadsp();

	//================================================================================
    // 函 数 名：_mnDelVrgUpdatadsp
    // 功能描述：修改权值
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnDelVrgUpdatadsp();

	//================================================================================
    // 函 数 名：_mnSetDataInfo
    // 功能描述：设置数据变换信息
	// 输入参数：ktype 　           ： 克里格估值类型
	//           tran  　           ： 数据变换方式
	//           tmindata           ： 变换前极小值
	//           tmaxdata　         ： 变换前极大值
	//           bextrmode          ： 极小值处理方式
	//           bextrmodemax       ： 极大值处理方式
	//           tfReplacemin       ： 极小值替换值 
	//           tfReplacemax       ： 极大值替换值
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnSetDataInfo(int ktype, int tran,double tmindata, double tmaxdata, BOOL bextrmode, BOOL bextrmodemax,
		                double tfReplacemin, double tfReplacemax);

	//================================================================================
    // 函 数 名：_mnSetIkType
    // 功能描述：设置指示类型
	// 输入参数：ikType　           ： 指示类型
	//           ikCutOff           ： 指示阈值
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnSetIkType(int ikType, double ikCutOff);

   	//变差函数表面图

	//================================================================================
    // 函 数 名：_mnSetVarmapParam
    // 功能描述：初始化变差函数表面图参数
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnSetVarmapParam();	

	//================================================================================
    // 函 数 名：_mnSetVarMapParam
    // 功能描述：设置变差函数表面图参数
	// 输入参数：vmdlag             ： 变差函数表面图步长大小
	//           vmminnp            ： 最小数据对数
	//           vmnlag             ： 步长数目
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
    void _mnSetVarMapParam(double vmdlag, double vmminnp, double vmnlag);

	//================================================================================
    // 函 数 名：_mnComputerVM
    // 功能描述：计算变差函数表面图的值
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
    void _mnComputerVM();

	//================================================================================
    // 函 数 名：_mnGetVarMapParam
    // 功能描述：设置数据变换信息
	// 输出参数：vmdlag             ： 变差函数表面图步长大小
	//           vmminnp            ： 最小数据对数
	//           vmnlag             ： 步长数目
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	//获取变差函数表面图参数
	void _mnGetVarMapParam(double &vmdlag, long &vmminnp, long &vmnlag);

	//================================================================================
    // 函 数 名：_mnGetVarMapResult
    // 功能描述：获取变差函数表面图计算结果
	// 输出参数：vmresult　         ： 变差函数表面图结果
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	//获取变差函数表面图计算结果
    void _mnGetVarMapResult(double **vmresult);

	//文件操作	
	//================================================================================
    // 函 数 名：_mnGetVrgDataType
    // 功能描述：得到文件类型
	// 输出参数：strFileName 　     ：文件名称
    // 返回值  ：                   ：文件类型
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	int  _mnGetVrgDataType(CString strFileName);

	//================================================================================
    // 函 数 名：_mnLoadGamvFile
    // 功能描述：导入变差函数文件
	// 输出参数：strFileName        ： 文件名称
	//           bIsDsp3D  　       ： 是否显示三维图形
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	int  _mnLoadGamvFile(CString strFileName, BOOL bIsDsp3D);

	//================================================================================
    // 函 数 名：_mnLoadGamvFile1
    // 功能描述：导入变差函数文件
	// 输出参数：strFileName        ： 文件名称
	//           bIsDsp3D  　       ： 是否显示三维图形
    // 返回值  ：1/0                ： 成功/失败
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	int  _mnLoadGamvFile1(CString strFileName, BOOL bIsDsp3D);

	//================================================================================
    // 函 数 名：_mnLoadCoVarianceFile
    // 功能描述：导入变差函数文件
	// 输出参数：strFileName        ： 文件名称
	//           bIsDsp3D  　       ： 是否显示三维图形
    // 返回值  ：1/0                ： 成功/失败
    // 创建日期：2008-09-23
    // 修改日期：2008-09-23
    // 附加说明：
    //================================================================================
	int  _mnLoadCoVarianceFile(CString strFileName, BOOL bIsDsp3D);

	//================================================================================
    // 函 数 名：_mnSaveGamvFile
    // 功能描述：保存变差函数文件
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	//保存变差函数文件
	void _mnSaveGamvFile();

	//================================================================================
    // 函 数 名：_mnAutoFitVrg
    // 功能描述：自动拟合变差函数
	// 输入参数：pVrgResult         ： 实验变差函数信息 
	//           pVrgWeight  　     ： 变差函数权重
	//           nlag               ： 变差函数点个数
	// 输出参数：pVrgModel　        ： 变差函数拟合结果
    // 返回值  ：无
    // 创建日期：2007-08-03
    // 修改日期：2007-08-03
    // 附加说明：
    //================================================================================
	void _mnAutoFitVrg(Variogram *pVrgResult, double *pVrgWeight, int nlag, Kt3dIntp *pVrgModel);

	//-----------------------------------2008年8月22日lhy------------------------------------//
	//设置是否显示进度条
	void _mnSetIsShowProgr(BOOL bIsShowProgr);
	//得到变差函数拟合结果
	void _mnGetVrgModel(Kt3dIntp *pVrgModel);
	//----------------------------------------end--------------------------------------------//
	//-----------------------------------2008年8月27日lhy------------------------------------//

	void _mnSetVrgMapParam(double dLagX, double dLagY, double dLagZ, int nLagX, int nLagY, int nLagZ);
	void _mnSetVrgMapMinPairs(int iMinPairs);
	long _mnCptVrgMapValue(double *pVrgMapVal);

	double m_dLagX;
	double m_dLagY;
	double m_dLagZ;
	int    m_nLagX;
	int    m_nLagY;
	int    m_nLagZ;
	int    m_iMinPairs;
	//----------------------------------------end--------------------------------------------//
public:
	//初始化对话框中的变量	
	void InitDlgParam();

	//初始化变差函数参数
	void InitGamvParam();
	
	//初始化变差函数表面图
	void InitVarView();
	//多个方向的初始化
	void CptAllVrgFitDsp(Variogram *resultmax, double *weightmax, int nlagmax, 
						 Variogram *resultmin, double *weightmin, int nlagmin,
						 Variogram *resultver, double *weightver, int nlagver, int icutoff);
private:
	GsDiscPnt *DiscPnts;
	long       lpntNum;
	BOOL       m_bIsDim;
	BOOL       m_bIsDsp3D;

	CRSErrorOpr *		m_pError;				//错误码
	CString				m_strErrorText;			//标题名称

public:	
	//数据变换信息
	int m_ktype;
	int m_tran;
	double m_tmindata;
	double m_tmaxdata;
	BOOL m_bextrmode;
	BOOL m_bextrmodemax;

	double m_fReplaceMin;
	double m_fReplaceMax;

//变差函数表面图	
public:

   int		m_iPostPos[3];           //纪录水平滑动条前一个位置
   int		m_iCurPos;               //纪录水平滑动条当前位置
   
   //用来记录立方体的切割平面
   double   m_dX1;                   
   double   m_dY1;
   double   m_dZ1;
   double   m_dX2;
   double   m_dY2;
   double   m_dZ2;
   double   m_dX3;
   double   m_dY3;
   double   m_dZ3;
   double   m_dXvertical;
   double   m_dYvertical;
   double   m_dZvertical;
   
   //纪录实验变差函数计算模型显示的八个点坐标
   double  m_vrgmodX[8];
   double  m_vrgmodY[8];
   double  m_vrgmodZ[8];
   
   //纪录是否显示垂直平面
   BOOL     m_bvertical;

   double   *vmvalue;                //纪录变差函数表面图中每个小立方体的值
   
   //Dingle初始化
   void InitRoot();

   //将三个角度切割平面的三个点坐标
   void Computerplant(int azm, int dip, int org);
   //将实验变差函数模型显示出来
   void Computervrgmod();
public:

	//记录要保存的变量
    vector< Variogram * > m_vector_result;
    vector< Kt3dIntp * > m_vector_model;
	vector< GamvParam > m_vector_param;
	vector< BOOL * > m_vector_bsel;
	vector< double * > m_vector_weight;

    Variogram *m_vrgresult_save;
	Kt3dIntp  *m_vrgmodel_save;
	GamvParam  m_gamvparam_save;
	BOOL      *m_bselect_save;
	double    *m_vrgweight_save;

	int        m_vector_ipos;
	
    //将单方向变量保存到内存当中
	BOOL PushVectorVrg(Variogram *vrg_result, double *vrg_weight, BOOL *bselect, 
					   Kt3dIntp *vrg_model,long vrgnlag, double vrgdlag, double vrgltol,int vrgazm,
					   int vrgdip, double azmtol, double diptol, double bandwh, double bandwd);
    //从内存中读取变量
	void ReadVectorVrg(int nt, Variogram **vrg_result, double **vrg_weight, CPoint **vrg_point, BOOL **bselect, 
					   long &vrgnlag, double &vrgdlag, double &vrgltol,int &vrgazm, int &vrgdip,
					   double &azmtol, double &diptol, double &bandwh, double &bandwd);
    //修改后的变量的保存
	void ModifyVectorVrg(int nt, vector< Variogram * > &vector_result, vector< Kt3dIntp * > vector_model, 
						vector< GamvParam > &vector_param, vector< BOOL * > &vector_bsel,vector< double * > &vector_weight);
	//删除Vector中的变量
	void DeletVectorVrg();

public:	
	//记录要保存的变量(多方向)
	//最大变程方向
    vector< Variogram * > m_vector_resultmax;
	vector< GamvParam > m_vector_parammax;
	vector< BOOL * > m_vector_bselmax;
	vector< double * > m_vector_weightmax;

    Variogram *m_vrgresultmax_save;
	GamvParam  m_gamvparammax_save;
	BOOL      *m_bselectmax_save;
	double    *m_vrgweightmax_save;

	//最小变程方向    
	vector< Variogram * > m_vector_resultmin;
	vector< GamvParam > m_vector_parammin;
	vector< BOOL * > m_vector_bselmin;
	vector< double * > m_vector_weightmin;

    Variogram *m_vrgresultmin_save;
	GamvParam  m_gamvparammin_save;
	BOOL      *m_bselectmin_save;
	double    *m_vrgweightmin_save;
		
	//垂直变程方向    
	vector< Variogram * > m_vector_resultver;	
	vector< GamvParam > m_vector_paramver;
	vector< BOOL * > m_vector_bselver;
	vector< double * > m_vector_weightver;

    Variogram *m_vrgresultver_save;
	GamvParam  m_gamvparamver_save;
	BOOL      *m_bselectver_save;
	double    *m_vrgweightver_save;

	//公共变量
    vector< Kt3dIntp * > m_vector_modelanis;
	Kt3dIntp   *m_vrgmodelanis_save;

	int        m_vector_iposanis;
	
	//将多方向变量保存到内存当中
	BOOL PushVectorVrgAnis();
	//删除多方向变量
	void DeletVectorVrgAnis();
	//从内存中读取多方向变量
	void ReadVectorVrgAnis(int nt);

private:
	//数据存储 
	CGeoStat	*VrgObj;             //总结构
	long        lattrNum;             //属性个数
	CString     *attrname;            //属性名称
public:
	double       m_tmin;
	double       m_tmax;

public:
    //包围盒的大小
    GSD_3DOT   	xyzMinDist;             
	GSD_3DOT      xyzMaxDist;
	BOOL        m_dimension;        //TURE为3D，FALSE为2D。

//列表控件
public:
	Kt3dIntp    *VrgModel;             //纪录拟合后的变差函数结构	
	CString     m_strText;               //纪录表头信息

	Kt3dIntp    *ListVrgModel;
//变差函数图	
public:
    Variogram   *m_vrg_result;         //纪录单个方向上的实验变差函数值
	double      *m_vrg_weight;
	int          m_vrg_iWFun;
	
	//纪录三个轴向上的实验变差函数值
	Variogram *m_resultmax;   
	Variogram *m_resultmin;
	Variogram *m_resultver;
    double    *m_weightmax;
	double    *m_weightmin;
	double    *m_weightver;
    int        m_iWFunmax;
	int        m_iWFunmin;
	int        m_iWFunver;

	ModIndVrg   *vrg_ModInd;         //纪录单个方向上的理论变差函数值

	CWnd   *vrg_pWndDraw;            //绘图区域的窗口句柄

	CPoint *m_vrg_point;             //纪录变差函数图中点的坐标(屏幕坐标)
	BOOL   *m_bselect;    

	BOOL    m_bdspline;              //纪录是否显示实验变差函数连线
	
	//纪录变差函数图中的点坐标（屏幕坐标）
	CPoint *m_vrg_pointmax; 
	CPoint *m_vrg_pointmin;
	CPoint *m_vrg_pointver;
	//纪录每个点的删除情况
	BOOL   *m_bselectmax;
	BOOL   *m_bselectmin;
	BOOL   *m_bselectver;

	//纪录三个轴向的步长数，步长大小和步长容忍值
	long   m_vrg_nlagmax;
	long   m_vrg_nlagmin;
	long   m_vrg_nlagver;

	double m_vrg_dlagmax;
	double m_vrg_dlagmin;
	double m_vrg_dlagver;

	double m_vrg_ltolmax;
	double m_vrg_ltolmin;
	double m_vrg_ltolver;

	double m_vrg_azmtolmax;
	double m_vrg_azmtolmin;
	double m_vrg_azmtolver;
	double m_vrg_diptolmax;
	double m_vrg_diptolmin;
	double m_vrg_diptolver;

	double m_vrg_bandwhmax;
	double m_vrg_bandwhmin;
	double m_vrg_bandwhver;
	double m_vrg_bandwdmax;
	double m_vrg_bandwdmin;
	double m_vrg_bandwdver;

	int    m_preivType;
public:
	//设置变差函数参数
	void SetVrgParam(int azm, int dip);
	//设置变差函数计算参数
	void SetComputerVrg(long nlag, double xlag, double xltol, double azm, double atol, 
						            double bandwh, double dip, double dtol, double bandwd, long isill,
									int ivtype, double cutoff[], int itailhead, double nvarg);
	//设置变差函数计算参数
	//修改：2009-09-07
	void SetComputerVrg(long nlag[], double xlag[], double xltol[], long lParamNum, double azm[], double atol[], 
						            double bandwh[], double dip[], double dtol[], double bandwd[], long lDirNum, long isill,
									int ivtype, double cutoff[], int itailhead, double nvarg);
	//设置三个方向的变差函数参数
    void SetAllVrgParam();
	//计算主轴方向上的实验变差函数值
	void CptMaxVrg();
	//计算次轴方向上的实验变差函数值
	void CptMinVrg();
	//计算垂直轴方向上的实验变差函数值
	void CptVerVrg();
	//计算变差函数拟合参数
	void ComputerVrgPara(double *fC0, double *fC, double *fA,Variogram *resultmax, double *weightmax, int nlagmax, 
						 Variogram *resultmin, double *weightmin, int nlagmin,
						 Variogram *resultver, double *weightver, int nlagver, int icutoff);
	//由变差函数拟合结果计算一个方向的变差函数值
	void ComputerVmodel();
	//计算一个方向上的变差函数值并进行拟合,并显示
	void CptOneVrgFitDsp(Variogram *vrg_result, double *vrg_weight, int nlag, int icutoff);
	//计算一个方向上的变差函数
	void CptOneVrg(int azm, int dip, BOOL bCpt);

	//---------------------------------------2008年8月21日-----------------------------------//

	void _mnLoadGsModelNest2(GsDiscPnt *pDiscPnts, long plpntNum);
   
	void _mnSetParam(long lParam);

	GsDiscPnt *DiscPntsSec;
	long       lpntNumSec;
	//-------------------------------------------end------------------------------//

public:
	BOOL            m_bIsVrgChg;     //记录变差函数结果是否为可编辑状态
	
public:
	int            m_ktypevrg;       //记录克里格类型
    int            m_vrg_num;        //记录阈值个数
	double         m_vrg_Thre[GS_MAXCUT];    //记录阈值

	double	m_vmdlag;
	long	m_vmminnp;
	long	m_vmnlag;
	double	m_vrgdlag;
	double  m_pvrgdlag[GS_MAXVRG];
	double	m_vrgltol;
	double  m_pvrgltol[GS_MAXVRG];
	long    m_lParamNum;
	
	double	m_vrgmodnugget;
	double	m_vrgmodsill;
	long	m_vrgnlag;
	long    m_pvrgnlag[GS_MAXVRG];
	int		m_ivtype;
	int		m_vmorg;
	int		m_dipver;
	int		m_dipmin;
	int		m_dipmax;
	int		m_vmdip;
	int		m_azmver;
	int		m_azmmin;
	int		m_azmmax;
	int		m_vmazm;
	int		m_anisang3;
	int		m_anisang2;
	int		m_anisang1;
	double	m_vrg_azmtol;
	double	m_vrg_bandwd;
	double	m_vrg_bandwh;
	double	m_vrg_diptol;
	int		m_vrg_azm;
	int		m_vrg_dip;	
	double  m_pvrg_azm[GS_MAXVRG];
	double  m_pvrg_dip[GS_MAXVRG];
	double	m_pvrg_azmtol[GS_MAXVRG];
	double	m_pvrg_bandwd[GS_MAXVRG];
	double	m_pvrg_bandwh[GS_MAXVRG];
	double	m_pvrg_diptol[GS_MAXVRG];
	long    m_lDirNum;
	BOOL	m_banisang;
	int     m_ivcutoff;
	CString	m_IvTypeName;
	int     m_iSill;
	double  m_fSill;

	BOOL    m_bIsShowProgr;

	int     m_ikType;
	double  m_ikCutOff;
};

#ifndef _GEO_STAT_KRIG_LIB
	#ifdef _DEBUG
		#pragma comment(lib, "GeoStatKrigLibD.lib")
	#else
		#pragma comment(lib, "GeoStatKrigLib.lib")
	#endif
#endif
#endif // !defined(AFX_GEOSTATMODELNEST_H__6B7DBAFB_3909_4DF7_9441_044F8CD47BBB__INCLUDED_)
