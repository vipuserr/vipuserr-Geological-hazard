// -----------------------------------------------------------------
//
// Copyright:	ZondySoft 2004
//
// File:		GeoStatLib.h
//
// Project:		GeoStatLib
//
// Creator:		黄铁兰
//
// Time:		09:42 2004-12-11
//
// Description:	Geological Statistical Library
//
// -----------------------------------------------------------------

#ifndef _GEOSTAT_LIB_H
#define _GEOSTAT_LIB_H


#include <windows.h>
#include "sqltypes.h"

//#pragma pack(push, 1)
#include "gsstru.h"
typedef class CGeoStat*		GeoStatObj;	//地质统计库对象

//地质统计库对象类型
#define		GEO_BASE_OBJ		0	//地质统计基本对象
#define		GEO_DATA_ANAS_OBJ	1	//数据处理对象
#define		GEO_VRG_OBJ			2	//变差函数对象
#define		GEO_STAT_GRAPHY_OBJ	3	//统计图生成对象
#define		GEO_KRIG_OBJ		4	//克立金插值对象
#define		GEO_SIMULAT_OBJ		5	//模拟对象


#ifndef _CGEO_STAT_LIB
  #define GEOSTAT_DLL  __declspec(dllimport)
#else
  #define GEOSTAT_DLL  __declspec(dllexport)
#endif


#if defined(__cplusplus)
  extern "C" {
#endif 

	//创建对象
	//说明:	根据类型的不同创建不同的对象.
	//参数:	lObjType -------------> 对象类型
	GeoStatObj GEOSTAT_DLL _gsCreateGeostatObj(long lObjType);
	//删除对象
	void GEOSTAT_DLL _gsDeleteGeostatObj(GeoStatObj gsObj);
    
	// ========================== 公用函数 ========================== //
	//设置是否显示进度条
	//说明:	该函数设置在计算过程中是否显示进度条
	//参数:	
	//		IsShowProgr ----------> 是否显示进度条
    long GEOSTAT_DLL _gsSetIsShowProgr(GeoStatObj gsObj, BOOL IsShowProgr = TRUE);

	// ========================== 公用函数 ========================== //
	//设置数据极限
	//说明:	该函数设置的数据极限值,即是有效数据的范围. 对数据进行处理时,
	//		超出该范围的数据将作为无效数据舍弃. (added by htl)
	//参数:	
	//		fExtrMin ----------> 数据最小极限
	//		fExtrMax ----------> 数据最大极限
	long GEOSTAT_DLL _gsSetDataExtr(GeoStatObj gsObj, 
									double fExtrMin=GS_MINTRIM, 
									double fExtrMax=GS_MAXTRIM);
	//装入数据
	//说明:	该函数装入的数据,即是各类地质统计功能中处理的数据. 其中数据1
	//		表示的是大多数功能中用到的数据变量,而数据2则是某些功能(如单变
	//		量变换_dmTrans,协克立金_krigCokb3d等)中用到的辅助变量. 如果需
	//		要辅助变量,则需分两次装入数据1,数据2,分别将数据标志lDatFlag设
	//		为1,2. (added by htl)
	//参数:	
	//		pDiscPnts[] -------------> 数据点
	//		lDatNum -----------------> 数据数目
	//		lDatFlag ----------------> 数据标志(暂时只支持2个数据,1:数据1,2:数据2)	
	long GEOSTAT_DLL _gsLoadDiscPnts(GeoStatObj gsObj, 
									 GsDiscPnt *pDiscPnts, long lDatNum, 
									 long lDatFlag=1);
	long GEOSTAT_DLL _gsLoadDiscPnts1(GeoStatObj gsObj, 
		GsDiscPnt1 *pDiscPnts, long lDatNum, 
		long lDatFlag=1);

	//设置权值使用标志
	//说明:	在某些数据处理功能(如单变量变换_dmTrans,贝叶斯模拟的校准_bicaBicalib等)中,
	//		对数据进行分析处理时,有时需要对每个数据进行加权计算. 所以需要设置权值使用
	//		标志,以判断某种情况下是否使用数据权值. 由于数据可以分为主要变量和辅助变量,
	//		故也要分别设置两类数据的权值使用标志. (added by htl)
	//参数:	
	//		lUseWtFlag --------------> 使用权值标志(0:不使用,1:使用)
	//		lDatFlag ----------------> 数据标志(暂时只支持2个数据,1:数据1,2:数据2)	
	long GEOSTAT_DLL _gsSetUseWtFlag(GeoStatObj gsObj, 
									long lUseWtFlag=0, long lDatFlag=1);

	//设置规则网格参数
	//说明:	在变差函数计算,克立金插值,数据模拟中,均需要用到数据的网格化,故需首先设置
	//		网格参数. 该函数分别设置x,y,z三个方向的网格数目,起点,步长(间距). (added by htl)
	//参数:
	//		lGridNumX,lGridNumY,lGridNumZ -------------> 网格数目
	//		fGridOriX,fGridOriY,fGridOriZ -------------> 网格起点（是网格节点最小坐标）
	//		fGridSizX,fGridSizY,fGridSizZ -------------> 网格间距
	long GEOSTAT_DLL _gsSetGridPara(GeoStatObj gsObj, 
									long lGridNumX, long lGridNumY, long lGridNumZ,
									double fGridOriX, double fGridOriY, double fGridOriZ,
									double fGridSizX, double fGridSizY, double fGridSizZ);
	//设置插值范围的网格参数
	long GEOSTAT_DLL _gsSetGridParaEva(GeoStatObj gsObj, 
		long lGridNumX, long lGridNumY, long lGridNumZ,
		double fGridOriX, double fGridOriY, double fGridOriZ,
		double fGridSizX, double fGridSizY, double fGridSizZ);
	//设置插值参数
	//说明:	
	//参数:	
	//		iStrNum ----------------> 变差函数数目
	//		fNugConst --------------> 块金常数
	//		pfArchValue[] ----------> 拱高(大小为MAXNST,下同)
	//		piModelType[] ----------> 理论变差函数模型类型
	//		pfChgRang[],... --------> 变程
	//		pfAnisAng1[],... -------> 各向异性角度
	long GEOSTAT_DLL _gsSetIntpPara(GeoStatObj gsObj, 
									int iStrNum, double fNugConst, 
									double *pfArchValue, int *piModelType, 
									double *pfChgRang, double *pfChgRang1, double *pfChgRang2, 
									double *pfAnisAng1, double *pfAnisAng2, double *pfAnisAng3);

	//设置属性最大最小值
	//说明:	设置某些属性的极值. 目的是为了判断属性的有效性,具体情况因属性
	//		的不同而不同. (added by htl)
	//参数:		
	//		fAttrMin -----------------> 最小属性
	//		fAttrMax -----------------> 最大属性
	//		lAttrFlag ----------------> 属性标志(1:任意属性,2:x属性,3:y属性)
	//		fLabSpace ----------------> 标签间距
	long GEOSTAT_DLL _gsSetAttrExtr(GeoStatObj gsObj, 
									double fAttrMin=GS_MINTRIM,  double fAttrMax=GS_MAXTRIM, 
									long lAttrFlag=1, double fLabSpace=5);

	//设置变量类型
	//说明:	无. (added by htl)
	//参数:	
	//		lVarType ---------> 变量类型(0:无条件,1:连续)
	long GEOSTAT_DLL _gsSetVarType(GeoStatObj gsObj, long lVarType=0);


	//设置是否使用局部数据标志
	//参数:	
	//		lLocFlag ----------> 使用局部数据标志(0:不使用,1:使用)
	long GEOSTAT_DLL _gsSetUseLocFlag(GeoStatObj gsObj, long lLocFlag=0);


	//设置阈值
	//说明:	为主要变量和辅助变量设置阈值. (added by htl)
	//参数:	
	//		pfCutOff[] ------------> 阈值
	//		lCutNum ---------------> 阈值数目
	//		lCutFlag --------------> 设置阈值标志(1:U方向/主要变量,2:V方向/辅助变量)
	void GEOSTAT_DLL _gsSetCutOff(GeoStatObj gsObj, 
								  double *pfCutOff=NULL, long lCutNum=0, 
								  long lCutFlag=1);


	//设置数据取对数标志
	//说明:	对数据坐标轴注记取对数显示. 与之对应的坐标方向的数据在计算时也取对数.
	//		(added by htl)
	//参数:
	//		lLogFlag ---------> 使用对数标尺标志(0:算术标尺,1:对数)
	//		lAxisFlag --------> 坐标轴标志(1:两个轴,2:x轴,3:y轴)
	long GEOSTAT_DLL _gsSetLogFlag(GeoStatObj gsObj, 
								  long lLogFlag=0, long lAxisFlag=1);

	//设置种类数目(柱状图方块个数)
	//参数:	
	//		lClassNum ----------> 种类数目(柱状图方块个数)
	long GEOSTAT_DLL _gsSetClassNum(GeoStatObj gsObj, long lClassNum=1);

	//设置分位数数目
	//参数:	
	//		lQuanNum -----------> 分位数数目(数据定义的分位数的个数,平均间隔积累概率值)
	void GEOSTAT_DLL _gsSetQuanNum(GeoStatObj gsObj, long lQuanNum);

	//装入克立金估计值
	//说明:	装入克立金插值得到的估计值,作为某些其他地质统计的参数(如绘制交叉验证误差图
	//		时将克立金估计值与原始值相减得到误差值). (added by htl)
	//参数:	
	//		pfKrigEstVal[] -----------> 估计值(估计属性或方差)
	//		lEstNum ------------------> 估计值数目
	long GEOSTAT_DLL _gsLoadEstVal(GeoStatObj gsObj, 
								   double *pfKrigEstVal=NULL, 
								   long lEstNum=0);

	//设置指示器的阈值
	//说明:	该函数设置的阈值,分布函数可用于指示克立金插值功能中构建指示器.
	//		(added by htl)
	//参数:	
	//		pfThres[] ----------> 阈值/类别
	//		pfCdf[] ------------> 全局的累积分布函数/概率分布函数
	//		lThresNum ----------> 阈值数目
	long GEOSTAT_DLL _gsSetThresAndCdf(GeoStatObj gsObj, 
									   double *pfThres, double *pfCdf, 
									   long lThresNum);

	//设置tail信息
	//说明:	指定递减(尾部)/递增(首部)区间的回推(向后转换)方法. (added by htl)
	//参数:	
	//		lTailNo ---------> 区间插值方法(1:向属性极值进行线性插值,2:基于
	//										区间参数值向属性极值进行指数模型
	//										插值,4:对区间参数值进行双曲线外推插值)
	//		fTailVal --------> 区间参数值
	//		lTailFlag -------> 数据段标志(1:底部,2:中间,3:顶部)
	void GEOSTAT_DLL _gsSetTailInfo(GeoStatObj gsObj, 
									long lTailNo, double fTailVal, 
									long lTailFlag=1);

	//设置随机种子
	//说明:	用于产生一个随机数. 该种子点作为随机数组的第一个成员. (added by htl)
	//参数:	
	//		lSeed ---------> 随机种子数(将离散变量转换为局部数据时使用的)
	void GEOSTAT_DLL _gsSetRandomSeed(GeoStatObj gsObj, long lSeed=0);

	//设置距离反比幂次
	//说明:	设置距离反比幂次
	//参数:	
	//		iDisPower -----> 距离反比幂次
	void GEOSTAT_DLL _gsSetDisPower(GeoStatObj gsObj, int iDisPower = 2);

	//设置八分圆搜索点数
	//说明:	设置八个方向搜索时每个方向的最大点数. 如果使用八分圆搜索,则通过超级块段
	//		搜索得到的样本点需要分八个方向进行有效性判断. (added by htl)
	//参数:	
	//		lPntNum -----> 八分圆(最大)搜索点数(0:不使用八分圆搜索, >0:使用)
	void GEOSTAT_DLL _gsSetSrchOct(GeoStatObj gsObj, long lPntNum=0);

	//设置搜索参数
	//参数:
	//		fRadius ---------------------------> 搜索半径(椭球主轴)
	//		fRadius1 --------------------------> 搜索半径(椭球次轴)
	//		fRadius2 --------------------------> 搜索半径(椭球第三轴)
	//		fAng1 -----------------------------> 主轴与正东方向的夹角
	//		fAng2 -----------------------------> 主轴与水平方向的夹角
	//		fAng3 -----------------------------> 第三轴与水平方向的夹角
	//		iMinNum, iMaxNum ------------------> 最小最大搜索点数
	//		iDiscNumX,... ---------------------> 每个块段(某个方向)的离散点数
	void GEOSTAT_DLL _gsSetSrchPara(GeoStatObj gsObj, 
									double fRadius=-1, double fRadius1=-1, 
									double fRadius2=-1,
									double fAng1=0, double fAng2=0, 
									double fAng3=0,
									int iMinNum=4, int MaxNum=8,
									int iDiscNumX=1, int iDiscNumY=1, 
									int iDiscNumZ=1);

	//设置实现次数(set number of realizations)
	//参数:	
	//		lRealNum ---------> 网格/实现/模拟次数
	void GEOSTAT_DLL _gsSetRealNum(GeoStatObj gsObj, long lRealNum);

	// ====================== 数据处理部分 ============================ //
	//说明:	该部分函数针对一般数据的处理和计算.
	// -------------------------- 坐标旋转 ---------------------------- //
	//主函数
	//说明:	将一个二维坐标点旋转一个角度,或将一个旋转过的坐标点逆旋转到
	//		原始的位置.
	//参数:	
	//		pPreDot -------------> 原始点(逆向旋转为旋转后的点)
	//		pAftDot -------------> 旋转后的点(逆向旋转为原始点)
	void GEOSTAT_DLL _gsRotCoord(GeoStatObj gsObj, 
								 GSD_DOT *pPreDot, GSD_DOT *pAftDot);

	//坐标旋转
	void GEOSTAT_DLL _gsRotCoord1(GeoStatObj gsObj, 
								 GSD_DOT *pPreDots, GSD_DOT *pAftDots, 
								 long lDotsNum);
	//设置坐标原点
	//参数:	
	//		pOriPnt -------------> 原始坐标系中的旋转系统的原点
	void GEOSTAT_DLL _gsSetOriPnt(GeoStatObj gsObj, GSD_DOT *pOriPnt);

	//设置旋转角度
	//参数:	
	//		dRotAng --------> 旋转角度(顺时针为正)
	void GEOSTAT_DLL _gsSetRotAng(GeoStatObj gsObj, double dRotAng=0);
	
	//设置旋转标志
	//参数:	
	//		bRotFlag -------> 旋转标志(0:旋转到目标坐标系,1:逆旋转到原始坐标系)
	void GEOSTAT_DLL _gsSetRotFlag(GeoStatObj gsObj, bool bRotFlag=0);

	// ---------------------------- 数据丛聚 --------------------------- //
	//主函数
	//功能:	给离散数据指定丛聚权值,这些数据位于同一丛聚单元中. 各向异性的
	//		的(丛聚)单元可能是三维的,如果需要的话,最佳单元尺寸可以自动计算
	//		出来.
	//参数:	
	//		pfDeclusWt[] ---------> 数据丛聚权值(大小与数据大小相等)
	//		pClustSum[] ----------> 丛聚权值平均和
	void GEOSTAT_DLL _gsDeclus(GeoStatObj gsObj, 
							   double *pfDeclusWt=NULL, 
							   ClustSum *pClustSum=NULL);

	//设置各向异性比例
	//说明:	设置决定矩形单元大小的各向异性比例.y,z方向单元尺寸相对于x方向的比例,
	//		ysiz=anisy*siz, zsiz=anisz*siz.
	//参数:	
	//		fAnisY -----------> y方向单元尺寸相对于x方向的比例
	//		fAnisZ -----------> z方向单元尺寸相对于x方向的比例
	void GEOSTAT_DLL _gsSetAnisFactor(GeoStatObj gsObj, 
									  double fAnisY=1, double fAnisZ=1);
	//设置是否搜索最大最小平均值标志
	//参数:	
	//		lMinMaxFlag ------------> 搜索标志(0;搜索最小值,1:最大值)
	void GEOSTAT_DLL _gsSetMinMaxFlag(GeoStatObj gsObj, long lMinMaxFlag=0);

	//设置聚类单元参数
	//说明:	这些尺寸直接应用到x方向,y,z方向的尺寸通过各向异性比例与x方向尺寸相乘得到.
	//参数:	
	//		lCellSizNum ------------> 丛聚单元数目
	//		fCellMinSiz ------------> 最小尺寸
	//		fCellMaxSiz ------------> 最大尺寸
	void GEOSTAT_DLL _gsSetCellPara(GeoStatObj gsObj, long lCellSizNum=1, 
									double fCellMinSiz=GS_MINTRIM, double fCellMaxSiz=GS_MAXTRIM);
	
	//设置原点偏移量的数目
	//说明:	每一个单元尺寸都是从原点偏移不同数目的偏移量得到的.这样可以避免落在特定
	//		单元中的特异值导致不稳定的结果. 二维一般设为4,三维设为8.
	//参数:	
	//		lOffSetNum --------> 原点偏移的数目
	void GEOSTAT_DLL _gsSetOffSet(GeoStatObj gsObj, long lOffSetNum=0);




	// --------------------------- 正态变换 ----------------------- //
	//主函数
	//功能:	计算数据的正态分布值. 根据数据属性和权值,计算每个数据对应的正态
	//		分布值.
	//说明:	地质统计模拟经常要求数据服从正态或高斯分布. 尽管模拟程序在模拟
	//		之前先要进行数据转换,但还是要在变差函数计算之前使用该函数进行
	//		数据转换.
	//参数:	
	//		pdPriNscore[] ------------> 数据主要属性正态分布值(大小与数据相同,下同)
	//		pdTranVar[] --------------> 数据属性(存于trans文件中,下同)
	//		pdTranVrg[] --------------> 数据正态分布值
	void GEOSTAT_DLL _gsNscore(GeoStatObj gsObj,
							   double *pdPriNscore=NULL, 
							   double *pdTranVar=NULL, 
							   double *pdTranVrg=NULL);
	//设置数据平滑标志
	//说明:	设置该标志,以区分在正态变换函数中使用离散数据或平滑数据.
	//参数:	
	//		lSmthFlag ---------> 数据平滑标志(0:不使用平滑数据,1:使用)
	void GEOSTAT_DLL _gsSetSmoothFlag(GeoStatObj gsObj, long lSmthFlag);
	//装入平滑数据
	//参数:	
	//		pSmooth[] ------------> 平滑数据
	//		lSmthNum -------------> 平滑数据数目
	void GEOSTAT_DLL _gsLoadSmooth(GeoStatObj gsObj, 
								   Smooth *pSmooth, long lSmthNum);



	// ----------------------- 正态逆向变换 ----------------------------- //
	//主函数	
	//功能:	查询转换表中的正态分布值,逆向转换为数据的原始属性值.
	//说明:	该函数除了在高斯模拟程序中,一般很少使用,它的功能是自动将模拟值
	//		逆向变换为原始值. 有时,它可以模拟正态空间并且保存模拟结果,以便
	//		(对模拟值)进行检验. 然后,该函数被用来进行逆向变换.
	//参数:	
	//输入:	pdPriNscore[] ---------> 数据主要属性正态分布值(大小与数据相同,下同)
	//		pdTranVar[] -----------> 数据属性(存于trans文件中)
	//		pdTranVrg[] -----------> 数据正态分布值
	//		lDatNum ---------------> 数据数目
	//输出: pfDataAttr[] ----------> 数据原始属性
	//返回: 无.
	void GEOSTAT_DLL _gsBacktr(GeoStatObj gsObj,
							   double *pfPriNscore=NULL, double *pfTranVar=NULL, 
							   double *pfTranVrg=NULL, long lDatNum=0, long lTranNum=0,
							   double *pfDataAttr=NULL);

	// ------------------------ 一般(一元)变换 --------------------------- //
	//主函数
	//功能:	将原始分布的分位数转换为目标分布的分位数.
	//说明:	该函数读取服从任意分布的数据,然后将其转换为其他任意分布. 该功能
	//		可用于模拟或灵敏性研究.
	//		读取一个参考分布和一系列其他分布,然后将第二类分布中的每一个分布
	//		的值进行转换,以使它的柱状图与参考分布的(柱状图)相匹配.
	//参数:	
	//		pfTranAttr[] -------> 转换后的数据属性(大小为数据集数目*数据数目)
	void GEOSTAT_DLL _gsTrans(GeoStatObj gsObj, double *pfTranAttr);
	
	//设置数据集参数
	//参数:	
	//		lDatSetNum --------------> 数据集数目(size to transform, number 
	//											  of realizations)
	//		lDatSetSiz --------------> 数据集大小(size to of continuous 
	//											  variable data set to transform)
	void GEOSTAT_DLL _gsSetDatSetPara(GeoStatObj gsObj, 
									  long lDatSetNum=1, long lDatSetSiz=1);
	//设置三维模型尺寸
	//说明:	size of categorical variable realizations to transform.
	//参数:	
	//		lModelSizX,... -------> 三维模型的尺寸
	void GEOSTAT_DLL _gsSetModelSiz(GeoStatObj gsObj, 
								    long lModelSizX=1, 
									long lModelSizY=1, 
									long lModelSizZ=1);
	//设置窗口尺寸
	//说明:	window size for breaking ties.
	//参数:	
	//		lWinSizX,... ----------> 离散变量窗口的尺寸
	void GEOSTAT_DLL _gsSetWindowSize(GeoStatObj gsObj, 
									  long lWinSizX=1, 
									  long lWinSizY=1, 
									  long lWinSizZ=1);	
	//设置控制参数
	//说明:	用于数据权值计算.
	//参数:	
	//		dCtrlPara ------------> 控制参数(控制原始数据的权值,0.33-3.0)
	void GEOSTAT_DLL _gsSetCtrlPara(GeoStatObj gsObj, double dCtrlPara=0);

	// ---------------------- 马可夫-贝叶斯模拟校准 ----------------------- //
	//主函数
	//功能:	计算预先分布和贝叶斯校准参数. 
	//		该函数校准一个包含主要变量和辅助变量的数据集,以便输入作为"mbsim"
	//		的参数. 并行排列的主要变量和辅助变量作为输入数据,如果辅助变量属于
	//		特定的类的话,则输出为主要变量局部预先累积分布函数.
	//		在Markov-Bayes选项(或任何其他软指示器克立金选项)指示器模拟之前需要
	//		调用该程序,软数据分布必须基于校准的数据.该程序确定那些分布和
	//		Markov-Bayes所需的B参数.
	//参数:
	//		plPairNum ----------> 数据对数
	//		pStat1,pStat2 ------> 数据统计量
	//		pfIndMean[] --------> 指示器平均值(大小为mxvcut=max(ncutu, ncutv))
	//		pfPdf[] ------------> pdf值(大小为(mxvcut+1)*(mxvcut+1))
	//		plTotNum[] ---------> 某阈值的点数(大小为mxvcut*2)
	//		pfEstMean[] --------> 估计平均值(大小为mxvcut*2)
	//		pfVariMean[] -------> 方差平均值(大小为mxvcut*2)
	//		pfLocCdf[] ---------> 局部cdf值(大小为种类数目)
	//		pfBayes[] ----------> 贝叶斯值(大小为阈值数目的较大者mxvcut)
	//		pfLocPriCdf[] ------> 局部原始cdf值(大小为阈值的数目较大者mxvcut的平方)
	void GEOSTAT_DLL _gsBicalib(GeoStatObj gsObj, 
								long *plPairNum=NULL, 
								Statistic *pStat1=NULL, Statistic *pStat2=NULL, 
								double *pfIndMean=NULL, double *pfPdf=NULL, 
								long *plTotNum=NULL, 
								double *pfEstMean=NULL, double *pfVariMean=NULL, 
								double *pfLocCdf=NULL, double *pfLocPriCdf=NULL, 
								double *pfBayes=NULL);
	
	// ----------------------- 柱状图平滑 --------------------------- //
	//主函数
	//功能:	创建一个由平均值,方差,分位数和平滑系数约束的平滑分布模型.
	//参数:	
	//		pSmooth[] -------------> p值(大小与种类数目相等)
	void GEOSTAT_DLL _gsHistsmth(GeoStatObj gsObj, Smooth *pSmooth);

	//设置柱状图方块数目
	////set number for objective function(sasim)
	//参数:	
	//	lHistNum -----------> 柱状图的方块数(number of quantiles for obj. func.,sasim)
	void GEOSTAT_DLL _gsSetHistNum(GeoStatObj gsObj, long lHistNum=1);
	
	//设置程序结束参数
	//参数:	
	//		lMaxPert -------------> 该值变化,则程序结束
	//		lReportInterval ------> 报告间距,该值改变,程序报告当前对象的函数
	//		fMinObj --------------> 当标准化的对象函数运行到该值时,程序停止
	void GEOSTAT_DLL _gsSetProgStopPara(GeoStatObj gsObj, 
										long lMaxPert=1, long lReportInterval=1, 
										double fMinObj=0);

	//设置目标函数组件(否接近某一参考指标的标志,1:是,0:否)
	//参数:	
	//		lMeanFlag --------> 接近目标平均数
	//		lVariFlag --------> 接近目标方差
	//		lSmthFlag --------> 光滑系数
	//		lQuanFlag --------> 接近指定分位数的标志
	void GEOSTAT_DLL _gsSetFuncComp(GeoStatObj gsObj, 
									long lMeanFlag=0, long lVariFlag=0, 
									long lSmthFlag=0, long lQuanFlag=0);
	
	//设置目标函数权值(用户强行设置的权值,代替自动计算的权值)
	//参数:	
	//		fMeanScal ----------> 平均值权值
	//		fVariScal ----------> 方差权值
	//		fSmthScal ----------> 光滑系数权值
	//		fQuanScal ----------> 分位数权值
	void GEOSTAT_DLL _gsSetFuncScal(GeoStatObj gsObj, 
									double fMeanScal, double fVariScal, 
									double fSmthScal, double fQuanScal);
	//设置平均值和方差
	//参数:
	//		fMean -------> 平均值
	//		fVari -------> 方差
	void GEOSTAT_DLL _gsSetMeanVari(GeoStatObj gsObj, 
									double fMean, double fVari);
	//设置用户分位数参数
	//参数:	
	//		pfCdf[] ---------> cdf(累积分布函数)值
	//		pfZ[] -----------> z值
	//		lUserQuanNum ----> 用户自定义的分位数的个数
	void GEOSTAT_DLL _gsSetUserQuan(GeoStatObj gsObj, 
									double *pfCdf=NULL, double *pfZ=NULL, 
									long lUserQuanNum=0);


	// ====================== 变差函数部分 =========================== //
	// --------------------- 主函数 ----------------------------- //
	//规则数据的变差函数计算
	//说明:	该函数的功能是对二次数据(来自地震或遥感)进行规格化,或用来检验
	//		模拟的结果. (规格化的)方向通过网格方向的单位增量来指定. 该函数
	//		的结果不是GSLIB的数据格式,而是一种可用来进行变差函数绘图的格式.
	//参数:	
	//		pVrg[] ---------------> 变差函数(数组大小=方向数*滞后距数*变差函数数目)
	void GEOSTAT_DLL _gsGam(GeoStatObj gsObj, Variogram *pVrg);

	//离散数据的变差函数计算
	//说明:	通常,主要变量并不落在规则网格中. 该函数就是用来处理这类数据. 该
	//		函数可以同时计算任意多个方向任意多个变差函数. 然而,滞后距离的规范,
	//		在多个方向是相同的;因此,在实际操作中,多次执行该程序是必要的. 该函数
	//		的结果不是GSLIB的数据格式,而是一种可用来进行变差函数绘图的格式.
	//参数:	
	//pVrg[] ---------------> 变差函数(数组大小=方向数*(滞后距数+2)*变差函数数目)
	void GEOSTAT_DLL _gsGamv(GeoStatObj gsObj, Variogram *pVrg, double &fSill);

	//lhy 2008-8-26
	//协方差函数计算
	//说明：计算多个变量之间的变差函数以及协方差函数
	void GEOSTAT_DLL _gsCoVariance(GeoStatObj gsObj, Variogram *pVrg);

	//变差函数图生成
	//说明:	一个变差函数图在决定连续性的方向上是很有用的. 在计算和显示完一个变差
	//		函数以后,通常需要回头调用gam或gamv程序来计算最大最小连续性方向的变差
	//		函数. 程序的输出采用GSLIB数据格式,以便在pixelplt程序中使用.
	//参数:	
	//pVrg[] ---------------> 变差函数(大小=变差函数数*(每个方向滞后距数的2倍+1))
	void GEOSTAT_DLL _gsVarMap(GeoStatObj gsObj, Variogram *pVrg);

	//协方差函数图生成
	//说明:	一个协方差函数图在决定连续性的方向上是很有用的. 在计算和显示完一个变差
	//		函数以后,通常需要回头调用gam或gamv程序来计算最大最小连续性方向的变差
	//		函数. 程序的输出采用GSLIB数据格式,以便在pixelplt程序中使用.
	//参数：
	//pVrg[] ---------------> 变差函数(大小=变差函数数*(每个方向滞后距数的2倍+1))
	void GEOSTAT_DLL _gsCoVarMap(GeoStatObj gsObj, Variogram *pVrg);

	//高斯分布的变差函数计算
	//说明:	大多数的地质统计模拟都是基于高斯模型的. 有时这样做可能并不合适,所以可以
	//		通过与实际指示器变量函数(对比)来检验理论指示器变量函数(与高斯模型一致).
	//		指示器变差函数计算程序(bigaus)计算出来的理论指示器变差函数,可以通过变差
	//		函数绘图程序绘制.
	//参数:	
	//		pVrg[] ---------------> 变差函数(大小=方向数*滞后距数*变差函数数)
	void GEOSTAT_DLL _gsBigaus(GeoStatObj gsObj, ModIndVrg *pVrg);

	//模型的变量图输出
	//说明:	该程序计算一个指定滞后距的半变差函数模型的值. 输出结果写为一个与"vargplt"
	//		一致的格式.
	//		来自模型的变差函数文件(vmodel)程序计算指定滞后距和方向的变差函数值,该值与
	//		实验值一起绘制(变差函数图),该图用来拟合和检验变差函数模型. 用户必须指定变差
	//		函数模型,该程序只是计算绘制的值. 通常在一个批处理文件中执行该程序和vargplt
	//		程序,以便在变差函数模型参数改变以后绘制的图形能立刻显示出来.
	//参数:	
	//		pVrg[] ---------------> 变差函数(大小=方向数*(滞后距数+2))	
	void GEOSTAT_DLL _gsVmodel(GeoStatObj gsObj, ModIndVrg *pVrg);

	// ----------------------- 公用函数 ------------------------ //
	//设置变量数目
	//参数:	
	//		lVarNum -----------> 变量数目
	void GEOSTAT_DLL _gsSetVarNum(GeoStatObj gsObj, long lVarNum=1);	
	
	//设置变量参数
	//参数:	
	//		piHeadVar[] --------> 参与变差函数计算的首部变量
	//		piTailVar[] --------> 参与变差函数计算的尾部变量
	//		piVrgType[] --------> 变差函数类型
	//		pfCutOff[] ---------> 指示器变量
	//		lVrgNum ------------> 变差函数数目
	void GEOSTAT_DLL _gsSetVarPara(GeoStatObj gsObj, 
								   int *piHeadVar=NULL, int *piTailVar=NULL, 
								   int *piVrgType=NULL, double *pfCutOff=NULL, 
								   long lVrgNum=1);
	//设置指示器参数
	//参数:	
	//		piIndX[],piIndY[],piIndZ[] ------> 每个方向确定的单位偏移
	//		lDirNum -------------------------> 方向数目
	void GEOSTAT_DLL _gsSetIndPara(GeoStatObj gsObj, 
								   int *piIndX=NULL, int *piIndY=NULL, int *piIndZ=NULL, 
								   long lDirNum=1);
	//设置滞后参数
	//参数:	
	//		plLagNum[] ----------> 每个方向滞后数目
	//		pfLag[] -------------> 滞后
	//		pfLagTol[] ----------> 滞后容差
	//		lDirNum -------------> 方向数目
	void GEOSTAT_DLL _gsSetLagPara(GeoStatObj gsObj, 
								   long *plLagNum=NULL, double *pfLag=NULL, double *pfLagTol=NULL, 
								   long lLagParamNum=1);
	//设置标准化标志
	//参数:	
	//		lSillFlag ----------> 标准化标志(1:标准化,半变差函数值将除以方差)
	void GEOSTAT_DLL _gsSetSillFlag(GeoStatObj gsObj, long lSillFlag=0);
	//按方向设置倾角和方位角
	//参数:	
	//		pfAzmAng[] ---------> 方位角
	//		pfAzmTol[] ---------> 方位容差
	//		pfAzmBand[] --------> 水平带宽
	//		pfDipAng[] ---------> 倾角
	//		pfDipTol[] ---------> 倾角容差
	//		pfDipBand[] --------> 垂直带宽
	//		lDirNum ------------> 方向数目
	void GEOSTAT_DLL _gsSetAzmDip(GeoStatObj gsObj, 
								  double *pfAzmAng=NULL, double *pfAzmTol=NULL, double *pfAzmBand=NULL, 
								  double *pfDipAng=NULL, double *pfDipTol=NULL, double *pfDipBand=NULL, 
								  long lDirNum=1);
	//设置数据类型
	//参数:	
	//		lDatType --------> 数据类型(0:规则,1:离散)
	void GEOSTAT_DLL _gsSetDataType(GeoStatObj gsObj, long lDatType=0);
	//设置数据对数目
	//参数:	
	//		lPairNum --------> 数据对数
	void GEOSTAT_DLL _gsSetPairNum(GeoStatObj gsObj, long lPairNum=1);

    //////////////////////////lhy变差函数拟合////////////////////////////////////
    void GEOSTAT_DLL _gsSetMaxMinAzmDip(GeoStatObj gsObj,
									double *pfMAzmAng, double *pfMAzmTol,double *pfMAzmBand,
									double *pfMDipAng, double *pfMDipTol,double *pfMDipBand,
									long lDirNum);
    void GEOSTAT_DLL gsSetMaxMinItype(GeoStatObj gsObj, long *iType);
 /*   void GEOSTAT_DLL _gsLoadVrgC(GeoStatObj gsObj, Variogram *Vrg, long lVrgNum);
    
	
	void GEOSTAT_DLL _gsVarComb(GeoStatObj gsObj, int ivtype,double *c0, double *cc, double *aa_h );

*/
	
	/////////////////////////////////////////////////////////////////////////////









	
	// =========================== 绘制统计图函数 ============================== //
	// ----------------------------- 主函数 ---------------------------- //
	// ************ 柱状图 ************** //
	//功能:	绘制数据的柱状图和一些统计量.
	//参数:	
	//		ai[] ---------> mapgis工作区	
	long GEOSTAT_DLL _gsDrawHistPlt(GeoStatObj gsObj);
	
	long GEOSTAT_DLL  _gsOutHistPltParam(GeoStatObj gsObj, 
									 long &lVarDatNum, long &InVarNum,
									 double &fDatMean, double &fStdDev,
									 double &fDatMax, double &xuqt,
									 double &xmed, double &xlqt, double &fDatMin,
									 double *fAttrFreq, double &fMaxFreq);
	// ************** 概率图 **************** //
	//功能:	绘制一个正态的或者一个对数正态的概率图.
	//参数:	
	//		ai[] ---------> mapgis工作区
	long GEOSTAT_DLL _gsDrawProbPlt(GeoStatObj gsObj);
    long GEOSTAT_DLL _gsOutPropPltParam(GeoStatObj gsObj, double *fProbDot, GSD_DOT *fPntDot, long &lPntNum);	
	// **************** 散点图 **************** //
	//功能:	绘制散点图和一些统计量.
	//参数:	
	//		ai[] ---------> mapgis工作区
	long GEOSTAT_DLL _gsDrawScatPlt(GeoStatObj gsObj);
	long GEOSTAT_DLL _gsOutScatPltParam(GeoStatObj gsObj, long &slPltPntNum, double &sfRankCorr, double &sfStdDevX,
									double &sfStdDevY, long &slValDatNumX, long &slValDatNumY,
	                                double &sfDatMeanX, double &sfDatMeanY, double &sfCorrCoef);
	// ************** qq-pp图 ************** //
	//功能:	从两种不同的数据文件中获取单一变量，并产生一个Q-Q图或P-P图.
	//参数:	
	//		ai[] ---------> mapgis工作区
	long GEOSTAT_DLL _gsDrawQpPlt(GeoStatObj gsObj);
    long GEOSTAT_DLL _gsOutQpPltParam(GeoStatObj gsObj, GSD_DOT *pfQp, long &lValQpNum);	

	// ----------------------------- 子函数 ---------------------------- //
	// ******* 绘制柱状图 ******* //
	//设置频率最大值
	//参数:
	//		fFreqExtr ----------> 最大频率(<0则采用自动计算的值)
	long GEOSTAT_DLL _gsSetFreqExtr(GeoStatObj gsObj, double fFreqExtr);
	//绘制频率或累积频率柱状图
	//参数:	
	//		lCumFlag ---------> 构造柱状图标志(0:频率柱状图1:累积柱状图)
	long GEOSTAT_DLL _gsSetCumHistFlag(GeoStatObj gsObj, long lCumFlag=0);
	//设置小数位数
	//参数:	
	//		lDecNum --------> 小数位数
	long GEOSTAT_DLL _gsSetDecNum(GeoStatObj gsObj, long lDecNum=0);
	//设置涉及的数据值
	//参数:	
	//		fRefVal -------> 在柱状图的下面为表示图块的参考数值.如果该值在数据极限内,
	//						 则柱状图的水平轴x轴上的标度将被化分,并显示一个图块.
	long GEOSTAT_DLL _gsSetRefVal(GeoStatObj gsObj, double fRefVal=-1);

	// ******* 绘制概率图 ******* //
	//设置概率图显示点数
	//参数:	
	//		lPltPntNum ---------> 显示点数
	long GEOSTAT_DLL _gsSetProbPntNum(GeoStatObj gsObj, long lPltPntNum=1);
	//设置概率
	//参数;	
	//		pfProbValue[] -------> 概率
	//		lProbNum ------------> 概率数目
	long GEOSTAT_DLL _gsSetProbValue(GeoStatObj gsObj, 
									 double *pfProbValue=NULL, long lProbNum=0);
	
	// ******* 绘制散点图 ******* //	
	//设置每类的子集数目
	//参数:	
	//		lSubNum ----------> 子集数目
	long GEOSTAT_DLL _gsSetSubNum(GeoStatObj gsObj, long lSubNum=1);
	//设置点大小
	//参数:	
	//		fBullSize --------> 点大小
	long GEOSTAT_DLL _gsSetBullSize(GeoStatObj gsObj, double fBullSize=0);

	// ******* 绘制qq-pp图 ******* //
	//设置qq或pp图绘制标志
	//参数:
	//		lQpFlag ---------> 绘制qq或pp图标志(0:qq,1:pp)
	long GEOSTAT_DLL _gsSetQqPpFlag(GeoStatObj gsObj, long lQpFlag=0);

	// ******* 绘制变差函数图 ******* //
	//装入变差函数值
	//参数:	
	//		pVrg[] ----------> 变差函数值
	//		lVrgNum ---------> 变差函数数目
	void GEOSTAT_DLL _gsLoadVrg(GeoStatObj gsObj, Variogram *pVrg=NULL, long lVrgNum=0);


	// ---------------------------- 公用函数 ----------------------------- //
	//装入规则点
	//参数:	
	//		pDiscPnts[] -----> 规则点
	//		lXDatNum --------> x方向网格数
	//		lYDatNum --------> y方向网格数
	long GEOSTAT_DLL _gsLoadGridPnts(GeoStatObj gsObj,
									 GsDiscPnt *pDiscPnts,
									 long lXDatNum=1, long lYDatNum=1);
	//设置窗口实际范围
	//参数:	
	//		fPractMinX -----------> x方向窗口实际最小值 
	//		fPractMinY -----------> y方向窗口实际最小值
	//		fPractMaxX -----------> x方向窗口实际最大值
	//		fPractMaxY -----------> y方向窗口实际最大值
	long GEOSTAT_DLL _gsSetPractWindow(GeoStatObj gsObj, 
									   double fPractMinX, double fPractMinY, 
									   double fPractMaxX, double fPractMaxY);
	//设置数据理论范围
	//参数:	
	//		fThoryMinX -----------> x方向的理论最小值
	//		fThoryMinY -----------> y方向的理论最小值
	//		fThoryMaxX -----------> x方向的理论最大值
	//		fThoryMaxY -----------> y方向的理论最大值
	long GEOSTAT_DLL _gsSetThoryData(GeoStatObj gsObj, 
									 double fThoryMinX, double fThoryMinY, 
									 double fThoryMaxX, double fThoryMaxY);	
	//设置缩放比例
	//参数:	
	//		fScale ---------> 缩放比例
	long GEOSTAT_DLL _gsSetScale(GeoStatObj gsObj, double fScale=1);	
	//设置图形色彩标志(彩色/灰度)
	//参数:	
	//		bIsClrMap ---------> 色彩类型(0:灰度,1:彩色)
	void GEOSTAT_DLL _gsSetMapColorStyle(GeoStatObj gsObj, bool bIsClrMap=1);
	//设置属性点注记绘制标志
	//参数:	
	//		bDrawDotLabel -------> 是否绘制属性点(0:不绘制,1:绘制)
	void GEOSTAT_DLL _gsSetMapLabelFlag(GeoStatObj gsObj, bool bDrawDotLabel=0);	
	//是否使用辅助属性
	//参数:	
	//		lUseSecFlag ---------> 使用辅助属性标志(0:不使用,1:使用)
	//		lDatFlag ------------> 数据标志(1:数据1,2:数据2)
	long GEOSTAT_DLL _gsSetUseSecAttrFlag(GeoStatObj gsObj, 
										  long lUseSecFlag=0, long lDatFlag=1);


	// =============================== 克立金函数 ================================= //
	// --------------------------------  主函数 -------------------------------- //
	//二维克立金
	//功能:	对给定的网格进行插值，或对给定的点进行估值。
	//参数:	
	//		pdOutAttt[] --------------> 插值(估值)点属性
	//		pdOutVari[] --------------> 插值(估值)点方差
	//		lOutPntNum ---------------> 插值(估值)点数
	long GEOSTAT_DLL _gsKrig2D(GeoStatObj gsObj, 
							   double *pdOutAttr, long lOutPntNum, double *pdOutVari=NULL);

	//三维克立金
	//参数:	
	//		pdOutAttt[] --------------> 插值(估值)点属性
	//		pdOutVari[] --------------> 插值(估值)点方差
	//		lOutPntNum ---------------> 插值(估值)点数
	//      plPntNum[] ---------------> 插值所用点数
	//      pfMeanDis[] --------------> 估值点到待估点的距离
	//      plEngNum[] ---------------> 插值所用工程数
	long GEOSTAT_DLL _gsKrig3D(GeoStatObj gsObj, 
							   double *pdOutAttr, long lOutPntNum, double *pdOutVari=NULL, long *plPntNum=NULL, 
							   double *pfMeanDis=NULL, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL);
	long GEOSTAT_DLL _gsKrig3D1(GeoStatObj gsObj, 
		double *pdOutAttr, long lOutPntNum, double *pdOutVari=NULL, long *plPntNum=NULL, double *pfMeanDis=NULL);
	//三维克立金
	//pEstabPnts[] ----------> 插值后的点
	long GEOSTAT_DLL _gsKrig3D2(GeoStatObj gsObj, 
								EstabPnt *pEstabPnts, long lOutPntNum);

	//三维克里格(无搜索设置用所有点估值(快速计算))
	//		pdOutAttt[] --------------> 插值(估值)点属性
	//		lOutPntNum ---------------> 插值(估值)点数
	long GEOSTAT_DLL _gsKrig3DSimp(GeoStatObj gsObj, 
		                           double *pdOutAttr, long lOutPntNum);

	//三维距离反比
	//参数:
	//       pdOutAttr[] -------------> 插值(估值)点属性
	//       lOutPntNum --------------> 插值(估值)点数
	//       plPntNum[] --------------> 插值所用点数
	//       pfMeanDis[] -------------> 估值点到待估点的距离
	//       plEngNum[] --------------> 插值所用工程数
	long GEOSTAT_DLL _gsInverse3D(GeoStatObj gsObj, 
							   double *pdOutAttr, long lOutPntNum, long *plPntNum = NULL, 
							   double *pfMeanDis = NULL, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL);
	long GEOSTAT_DLL _gsInverse3D1(GeoStatObj gsObj, 
		double *pdOutAttr, long lOutPntNum, long *plPntNum = NULL, 
		double *pfMeanDis = NULL);
	//三维距离反比
	//pEstabPnts[] ----------> 插值后的点
    long GEOSTAT_DLL _gsInverse3D2(GeoStatObj gsObj, 
								EstabPnt *pEstabPnts, long lOutPntNum);

	//三维距离反比(无搜索设置用所有点估值(快速计算))
	//		pdOutAttt[] --------------> 插值(估值)点属性
	//		lOutPntNum ---------------> 插值(估值)点数
	long GEOSTAT_DLL _gsInverse3DSimp(GeoStatObj gsObj, 
		                           double *pdOutAttr, long lOutPntNum);

	//协克立金
	//参数:	
	//		pdOutAttt[] --------------> 插值(估值)点属性
	//		pdOutVari[] --------------> 插值(估值)点方差
	//		lOutPntNum ---------------> 插值(估值)点数
	long GEOSTAT_DLL _gsCoKrig(GeoStatObj gsObj, 
							   double *pdOutAttr, long lOutPntNum, double *pdOutVari=NULL);
	
	//指示器克立金
	//参数:	
	//		pfIkCcdf[] ---------------> 指示器值
	//		lIkCcdfNum ---------------> 指示器值数目(数据数目*阈值数目)
	//      plPntNum[] ---------------> 插值所用点数
	//      pfMeanDis[] --------------> 估值点到待估点的距离
	//      plEngNum[] ---------------> 插值所用工程数
	long GEOSTAT_DLL _gsIkring(GeoStatObj gsObj, double *pfIkCcdf, long lIkCcdfNum,long *plPntNum = NULL, 
		                       double *pfMeanDis = NULL, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL);

	//----------------------------------lhy添加----------------------------------//
	//输出块段样品个数
	//参数
	//      pSrchNum[] ---------------> 样品个数
    long GEOSTAT_DLL _gsSrchData(GeoStatObj gsObj, double fScaleR, int *pSrchNum);
    
	//指示克立金后处理
	//参数:
	//      pfOutVal[] ---------------> 输出结果
	long GEOSTAT_DLL _gsPostIk(GeoStatObj gsObj, double *pfOutVal, double *pfOutVari);
	//------------------------------------end------------------------------------//

	// -------------------------lhy添加指示克立金子函数 -------------------------//
    long GEOSTAT_DLL _gsLoadPostIkPnt(GeoStatObj gsObj, double *pfIkCcdf, long lIkCcdfNum);
	long GEOSTAT_DLL _gsSetPostIkExtr(GeoStatObj gsObj, int ivr, int iwt, double fExtrMin, double fExtrMax);
	long GEOSTAT_DLL _gsSetOutOption(GeoStatObj gsObj, int iOut, double fOutPar);
	long GEOSTAT_DLL _gsSetPostIkCutOff(GeoStatObj gsObj, double *pfCutOff, long lCutOffNum);
	long GEOSTAT_DLL _gsSetIsConsiderVol(GeoStatObj gsObj, int iVol);
	long GEOSTAT_DLL _gsSetPostIkType(GeoStatObj gsObj, int ivtyp);
	long GEOSTAT_DLL _gsSetVariFactor(GeoStatObj gsObj, double fVarred);
	long GEOSTAT_DLL _gsSetExtrZVal(GeoStatObj gsObj, double fZMin, double fZMax);
	long GEOSTAT_DLL _gsSetMaxDis(GeoStatObj gsObj, int iMaxDis);
	
    // -----------------------------------end------------------------------------//
	// --------------------------- 各类克立金子函数 ---------------------------- //	
	// ************* 协克立金 ************** //
	//设置局部变化平均值相关标志
	//参数:	
	//		lLvmFlag ----------> 使用局部变化平均值标志(0:不使用,1:使用)
	void GEOSTAT_DLL _gsSetLvmFlag(GeoStatObj gsObj, long lLvmFlag);
	//设置辅助变量搜索参数
	//参数:	
	//		iMaxSrchNum ----------> 辅助变量最大搜索点数
	//		fSrchRadius ----------> 辅助变量(椭球主轴)搜索半径
	//		fSrchRadius1 ---------> 辅助变量(椭球次轴)搜索半径
	//		fSrchRadius2 ---------> 辅助变量(椭球第三轴)搜索半径
	long GEOSTAT_DLL _gsSetSecSrchPara(GeoStatObj gsObj, 
									   int iMaxSrchNum=0, double fSrchRadius=-1, 
									   double fSrchRadius1=-1, double fSrchRadius2=-1);
	//设置模型类型
	//参数:	
	//		iModelType --------> 模型类型(1:MM1,2:MM2,3:LMC)
	long GEOSTAT_DLL _gsSetModelType(GeoStatObj gsObj, int iModelType=1);
	//设置相关系数
	//参数:	
	//		fColoCorr --------> 相关系数(for MM1,MM2)
	long GEOSTAT_DLL _gsSetColoCorr(GeoStatObj gsObj, double fColoCorr);

	// ************* 指示器克立金 ************//
	//设置中值
	//参数:	
	//		iIkMeanFlag ---------> 中值
	//lhy将
	//long GEOSTAT_DLL _gsSetMeanThres(GeoStatObj gsObj, int iIkMeanFlag);
	//改为
	long GEOSTAT_DLL _gsSetMeanThres(GeoStatObj gsObj, int iIkMeanFlag, double cutmean);
	//设置软数据
	//参数:	
	//		lUseSoftFlag ----------> 是否使用软数据(0:不使用,1:使用)
	//		pSoftPnts[] -----------> 软数据
	long GEOSTAT_DLL _gsSetSoftData(GeoStatObj gsObj, 
									long lUseSoftFlag, GsDiscPnt *pSoftPnts);


	// ----------------------------- 公用函数 ------------------------------ //	
	//计算理论变差函数参数(三个方向)
	//参数:	
	//		fC0[] --------> 纯块金效应(大小为3,下同)
	//		fC[] ---------> 拱高
	//		fA[] ---------> 变程
	long GEOSTAT_DLL _gsCalVrgParaAll(GeoStatObj gsObj, 
									  double *fC0, double *fC, double *fA);

	//计算理论变差函数参数(某一方向)
	//参数:
	//输入:
	//		fAzmAng --------------> 方位角
	//		fAzmTol --------------> 方位容差
	//		fAzmBand -------------> 水平带宽
	//		fDipAng --------------> 倾角
	//		fDipTol --------------> 倾斜容差
	//		fDipBand -------------> 竖直带宽
	//		fLag -----------------> 滞后距
	//		fLagTol --------------> 滞后容差
	//		lLagNum --------------> 滞后数目
	//输出:	
	//		pfGodNugC0 -----------> 块金常数
	//		pfArchC --------------> 拱高
	//		pfChgRangA -----------> 变程
	long GEOSTAT_DLL _gsCalVrgParaDir(GeoStatObj gsObj, 
								      double fAzmAng, double fAzmTol, double fAzmBand, 
									  double fDipAng, double fDipTol, double fDipBand, 
									  double fLag, double flagTol, long lLagNum, 
									  double *pfGodNugC0, double *pfArchC, double *pfChgRangA);


	//计算实验变差函数(某个方向)
	//		fAzmAng --------------> 方位角
	//		fAzmTol --------------> 方位容差
	//		fAzmBand -------------> 水平带宽
	//		fDipAng --------------> 倾角
	//		fDipTol --------------> 倾斜容差
	//		fDipBand -------------> 竖直带宽
	//		fLag -----------------> 滞后距
	//		fLagTol --------------> 滞后容差
	//		lLagNum --------------> 滞后数目
	//		fVrg[] ---------------> 试验变差函数值(大小为滞后数目,下同)
	//		lPntCoupNum[] --------> 点对数
	//		fDist[] --------------> 滞后
	long GEOSTAT_DLL _gsCalExpVrgDir(GeoStatObj gsObj, 
									 double fAzmAng, double fAzmTol, double fAzmBand, 
									 double fDipAng, double fDipTol, double fDipBand, 
									 double fLag, double flagTol, long *lLagNum, 
									 double *fVrg, long *lPntCoupNum, double *fDist);

	//设置搜索参数
	//参数:	
	//		pSrchPara ---------> 搜索参数
	long GEOSTAT_DLL _gsSetSrchPara2(GeoStatObj gsObj, Kt3dSrch *pSrchPara);	
	//设置网格参数
	//参数:	
	//		pGridPara ---------> 网格参数
	long GEOSTAT_DLL _gsSetGridPara2(GeoStatObj gsObj, GsGrid *pGridPara);
	//设置插值参数
	//参数:	
	//		pIntpPara[] ---------> 插值参数
	//		lIntpNum ------------> 变差函数数目
	long GEOSTAT_DLL _gsSetIntpPara2(GeoStatObj gsObj, 
									 Kt3dIntp *pIntpPara, long lIntpNum=1);	
	//设置克立金选项
	//参数:	
	//		iKrigOption -------> 克立金选项(0:grid,1:cross,2:jackknife)
	long GEOSTAT_DLL _gsSetKrigOption(GeoStatObj gsObj, long lKrigOption=0);
	//设置简单克立金平均值
	//参数:	
	//		fSkMean -------> 变量平均值
	long GEOSTAT_DLL _gsSetSkMean(GeoStatObj gsObj, double fSkMean=0);

	//设置协克立金平均值
	//参数：
	//     pfSkMean -----------> 多个变量平均值
	//     lSkMeanNum ---------> 平均值个数
	//修改日期：2008，9，11
    long GEOSTAT_DLL _gsSetCoKMean(GeoStatObj gsObj, double *pfSkMean, long lSkMeanNum);

	//设置估计参数
	//参数:	
	//		iTrend ----------> 估计参数(估计属性或趋势)
	long GEOSTAT_DLL _gsSetTrend(GeoStatObj gsObj, long lTrend=0);
	//设置Krig类型
	//参数:	
	//		lKrigType ---------> 克立金类型(0:简单克立金,1:普通克立金, 
	//										2:非统计简单克立金,3:带漂移的克立金)
	void GEOSTAT_DLL _gsSetKrigType(GeoStatObj gsObj, long lKrigType=0);
	//设置漂移极限
	//参数:	
	//		iDrifTerm[] -----------> 漂移极限(大小为9)
	long GEOSTAT_DLL _gsSetDrifTerm(GeoStatObj gsObj, int *iDrifTerm=NULL);
	//设置数据变换方式
	//参数：
	//      
	long GEOSTAT_DLL _gsSetDataTran(GeoStatObj gsObj, int iTranMethod=0);
	
	//设置估值标志
	//参数:	
	//		lEstFlag -----------> 估计标志(0:网格插值,1:单点估值)
	long GEOSTAT_DLL _gsSetEstFlag(GeoStatObj gsObj, long lEstFlag);
	//装入待估值的点
	//参数:	
	//		pEstPnt ----------> 待估计点
	long GEOSTAT_DLL _gsLoadEstPnt(GeoStatObj gsObj, GsDiscPnt *pEstPnt, long lEstPntNum);



	// ============================== 数据模拟 ============================= //
	// ---------------------------- 主函数 ---------------------------- //
	//顺序指示模拟
	void GEOSTAT_DLL _gsSisim(GeoStatObj gsObj, double *pfSimValue=NULL);
	

	// ----------------- 公用函数 ------------------ //
	//设置循环所有结点的最大次数(number of simulated nodes to use)
	void GEOSTAT_DLL _gsSetNodMax(GeoStatObj gsObj, int nNodMax, int iFlag=1);
	//设置搜索策略
	void GEOSTAT_DLL _gsSetSearchStrategy(GeoStatObj gsObj, int nSearchstr);
	//设置多重网格搜索标志(multiple grid search flag)
	void GEOSTAT_DLL _gsSetMSearchFlag(GeoStatObj gsObj, long lNum, long lVal);
	//设置中央协克立金开关(median IK switch)
	//	lMikFlag ---------> 开关(0:full IK;1:median approx)
	//	fCutMik ----------> 阈值
	void GEOSTAT_DLL _gsSetMedianIkSwitch(GeoStatObj gsObj, long lMikFlag, double fCutMik);

	// ----------------- 子函数-------------- //
	// ************ 高斯模拟 ************* //
	//设置数据变换标志
	//参数:	
	//		bTrans ---------> 数据变换标志(0:不变换,1:变换)
	void GEOSTAT_DLL _gsSetTransFlag(GeoStatObj gsObj, BOOL bTrans=0);
	//设置数据光滑标志
	//参数:	
	//		bSmoothFlag --------> 光滑标志(0:光滑,1:不光滑)
	void GEOSTAT_DLL _gsSetSmoothMark(GeoStatObj gsObj, BOOL bSmoothFlag=0);

	// *********************** Sisim *********************** //
	//Set Markov-Bayes simulation
	//设置马可夫-贝叶斯模拟值
	void GEOSTAT_DLL _gsSetMakovBayes(GeoStatObj gsObj, int iMakovBayes);
	//set calibration B(z) values
	//设置标准b值
	void GEOSTAT_DLL _gsSetBeezValue(GeoStatObj gsObj, double *fBeezValue);
	//set size of covariance lookup
	//设置些方差搜索范围
	void GEOSTAT_DLL _gsSetCovarSize(GeoStatObj gsObj, int mxctx, int mxcty, int mxctz);

	// *********************** Sgsim *********************** //
	//高斯模拟
	void GEOSTAT_DLL _gsSgsim(GeoStatObj gsObj, double *pfSimValue);
	//set min and max original data for sim
	//设置参与模拟的原始数据的最大最小点数
	void GEOSTAT_DLL _gsSetMinMaxOrigData(GeoStatObj gsObj, int iMinData, int iMaxData);

	
	// ************************* Ellipsim ************************** //
	//椭球体的布尔模拟
	void GEOSTAT_DLL _gsEllipSim(GeoStatObj gsObj, double *pfSimValue);

	//设置目标比例
	void GEOSTAT_DLL _gsSetTargProp(GeoStatObj gsObj, double dTargProp);

	//设置椭球体的一些参数(半径,角度,权值)
	void GEOSTAT_DLL _gsSetEllipParam(GeoStatObj gsObj, 
								      double *pfRadius, double *pfRadius1, double *pfRadius2, 
								      double *pfAng1, double *pfAng2, double *pfAng3, 
								      double *pfWeight, int iEllipNum);

	

	// ******************************** Anneal ********************************* //
	//退火模拟
	//参数:	pfSimVal[] ------------> 模拟值(数组大小为nsim*nx*ny*nz)
	void GEOSTAT_DLL _gsAnneal(GeoStatObj gsObj, double *pfSimVal);

	//装入输入图形数据(Load Input Imag Data)
	//参数:	pfInputData[] ----------> file with input image(数组大小为iDataNum,
	//														文件名为sisim.out)
	//		iDataNum ---------------> 数据数目
	void GEOSTAT_DLL _gsLoadInputImag(GeoStatObj gsObj, 
									  double *pfInputData, int iDataNum);

	//装入训练图形数据(Load Training Imag Data)
	//参数:	pfTrainData[] ---------> file with training image(数组大小为iDataNum,
	//														文件名为ellipsim.out)
	//		iDataNum ---------------> 数据数目
	void GEOSTAT_DLL _gsLoadTrainImag(GeoStatObj gsObj, 
									  double *pfTrainData, int iDataNum);

	//设置报告间隔(set report interval)
	//	fReport ----------> 报告间隔数目(after ``report'' loops the image 
	//									 is written to the output file)
	void GEOSTAT_DLL _gsSetReportInterv(GeoStatObj gsObj, double fReport);

	//设置网格数目(set number of grid)
	//grid size for the input realizations and training image
	void GEOSTAT_DLL _gsSetGridNum(GeoStatObj gsObj, 
								   int iGridNumX, int iGridNumY, int iGridNumZ);

	//设置最大的反复数目(set maximum iterations)
	//	iMaxIterat ----------> 最大的反复数目(maximum number of iterations over all nodes)
	void GEOSTAT_DLL _gsSetMaxIterat(GeoStatObj gsObj, int iMaxIterat);

	//设置容差(set tolerance)
	//	fObjTol ------------> 容差(tolerance for the objective function)
	void GEOSTAT_DLL _gsSetObjTol(GeoStatObj gsObj, double fObjTol);

	//设置每个方向的偏移量和滞后数目(set offsets and lags for each direction)
	//	iOffsetX[] -------------> 偏移量(数组大小为iDirNum)
	//	iLags[] ----------------> 滞后数目(数组大小为iDirNum)
	//	iDirNum ----------------> the number of directions to consider for the two-point 
	//							  histogram control
	void GEOSTAT_DLL _gsSetOffsetLag(GeoStatObj gsObj, 
									 int *iOffsetX, int *iOffsetY, int *iOffsetZ, 
									 int *iLags, int iDirNum);

	// ********************* draw ************************** //
	//简单随机模拟
	//	pfSimVal[] --------> 待绘制的模拟点(数组大小为iDrawNum*iKeepColNum)
	void GEOSTAT_DLL _gsDraw(GeoStatObj gsObj, double *pfSimVal);

	//设置变量的列号(set variables to keep)
	//	iKeepColNo[] -----------> 需要在输出文件中保留的数据在离散点结构中的序号(数组大小为iKeepColNum)
	//	iKeepColNum ------------> 数据列数目
	void GEOSTAT_DLL _gsSetKeepVarNum(GeoStatObj gsObj, int *iKeepColNo, int iKeepColNum);

	//设置概率的列号(set column for probability,概率在离散点结构中的序号,1~9)
	void GEOSTAT_DLL _gsSetProbColNo(GeoStatObj gsObj, int iProbColNo);

	//设置绘制的点数(number to draw)
	void GEOSTAT_DLL _gsSetDrawNum(GeoStatObj gsObj, int iDrawNum);

	// ******************* lusim ************************** //
	//三维规则网格的条件模拟
	//Conditional Simulation of a 3-D Rectangular Grid
	//	pfSimVal[] -----------> 模拟值(数组大小nsim*nx*ny*nz)
	void GEOSTAT_DLL _gsLusim(GeoStatObj gsObj, double *pfSimVal);

	//设置变量的列号(数组大小为iVarNum)
	//	iVarColNos[] --------> 变量在离散点结构中的序号(数组大小为iVarNum)
	//	iVarNum -------------> 变量数目
	//	lDataFlag -----------> 数据标志(1:var;2:cdf;3:hist;4:pair)
	void GEOSTAT_DLL _gsSetVarColNo(GeoStatObj gsObj, int *iVarColNos, int iVarNum, 
									long lDataFlag=1);

	// ***************** gtsim ***************** //
	//高斯去顶模拟(Gaussian Truncated Simulation)
	//	pfSimVal[] -----------> 模拟值(数组大小nsim*nx*ny*nz)
	void GEOSTAT_DLL _gsGtsim(GeoStatObj gsObj, double *pfSimVal);

	//设置类别(set categories)
	//	iCatNum -----------> 类别数目
	//	fCat[] ------------> 类别(数组大小为iCatNum)
	//	fGlobProp[] -------> 全局比例(数组大小为iCatNum)
	void GEOSTAT_DLL _gsSetCat(GeoStatObj gsObj, 
							   int iCatNum, double *fCat, double *fGlobProp);

	//设置使用局部比例文件标志(set proportion curves)
	//bPropCurv ----------> 是否使用局部比例文件(whether to use the local proportion curve files)
	void GEOSTAT_DLL _gsSetPropCurv(GeoStatObj gsObj, bool bPropCurv);

	//装入高斯实现数据(load sgsim realizations)
	//	pfSgsimReal[] -------> 高斯实现数据(file with input Gaussian realizations,
	//										数组大小为iRealNum)
	//	iRealNum ------------> 高斯实现数据的数目
	void GEOSTAT_DLL _gsLoadSgsimReal(GeoStatObj gsObj, 
									  double *pfSgsimReal, int iRealNum);
	//装入局部比例数据(load local proportion)
	//	pblocalpropflag[] ------> 使用局部比例文件的标志(数组大小为3. 0:使用,1:不使用)
	//	pfLocalProp01[] --------> 局部比例文件数据(数组大小为iPropNum)
	//	iPropNum ---------------> 局部比例文件数据的数目
	void GEOSTAT_DLL _gsLoadLocalProp(GeoStatObj gsObj, 
									  bool pbLocalPropFlag[3], 
									  double *pfLocalProp01, 
									  double *pfLocalProp02, 
									  double *pfLocalProp03, 
									  int iPropNum);

	// ********************** pfsim ******************** //
	//概率现场仿真(Probability Field Simulation)
	//	pfSimVal[] -----------> 模拟值(数组大小nsim*nx*ny*nz)
	void GEOSTAT_DLL _gsPfsim(GeoStatObj gsObj, double *pfSimVal);
	//set cdf type
	//	iCdfType ----------> 累积分布函数类型
	void GEOSTAT_DLL _gsSetCdfType(GeoStatObj gsObj, int iCdfType);

	//设置高斯标志(0=Gaussian, 1=uniform)
	void GEOSTAT_DLL _gsSetGausFlag(GeoStatObj gsObj, int iGausFlag=0);

	// ********************* sasim ********************** //
	//基于退火的模拟(Annealing-Based Simulation)
	//	pfSimVal[] -----------> 模拟值(数组大小nsim*nx*ny*nz)
	//	pfSecVar[] -----------> 第二变量的值(数组大小nsim*nx*ny*nz)
	//	pfVertAvg[] ----------> 垂直平均(vertically averaged output, 数组大小nsim*nx*ny*nz)
	void GEOSTAT_DLL _gsSasim(GeoStatObj gsObj, double *pfSimVal, 
							  double *pfSecVar=NULL, double *pfVertAvg=NULL);

	//设置目标函数组件(set objective function components)
	//	fObjHist ----------> Considering a histogram
	//	fObjVarg ----------> Considering a variogram
	//	fObjIvar ----------> Considering indicator variogram
	//	fObjCorr ----------> Considering a correlation coefficient
	//	fObjCpdf ----------> Considering conditional distributions
	//	iObjFlag ----------> 目标函数标志(0:The objective function components;
	//									  1:user scaling factor)
	void GEOSTAT_DLL _gsSetObjComp(GeoStatObj gsObj, 
								   double fObjHist, double fObjVarg, double fObjIvar, 
								   double fObjCorr, double fObjCpdf, int iObjFlag=0);

	//设置编译级别(set debug level)
	void GEOSTAT_DLL _gsSetDebugLevel(GeoStatObj gsObj, int iDebugLevel=0);

	//设置自动进度标志(set automatic schedule)
	//	iSchedFlag ---------> 自动进度标志(0:automatic,1:set below)
	void GEOSTAT_DLL _gsSetSchedFlag(GeoStatObj gsObj, int iSchedFlag=0);

	//用户设置进度(user set schedule)
	void GEOSTAT_DLL _gsSetAutoSched(GeoStatObj gsObj, 
									 double fT0, double fRedfac, int iKasas, 
									 int iKsas, int iNum, double fOmin);

	//设置最大的扰动数目(maximum number of perturbations)
	void GEOSTAT_DLL _gsSetMaxPert(GeoStatObj gsObj, int iMaxPertNum);

	//设置不变的最大数目(set maximum without a change)
	void GEOSTAT_DLL _gsSetMaxChange(GeoStatObj gsObj, int iMaxChange);

	//设置是否考虑条件分布标志(set consider conditioning)
	//	iCondFlag ----------> 是否考虑条件分布(0:不考虑;1:考虑)
	void GEOSTAT_DLL _gsSetCondFlag(GeoStatObj gsObj, int iCondFlag=0);

	//设置是否考虑柱状图分布标志(set consider file with distribution)
	//	iHistFlag ---------> 是否考虑柱状图分布(0:不考虑;1:考虑)
	void GEOSTAT_DLL _gsSetHistFlag(GeoStatObj gsObj, int iHistFlag=0);

	//设置是否应用垂直分布平均值标志(applies to a vertical average)
	//	bVertAvgFlag ---------> 是否应用垂直平均值(0:不应用;1:应用)
	void GEOSTAT_DLL _gsSetVertAvgFlag(GeoStatObj gsObj, bool bVertAvgFlag=0);

	//设置相关系数(correlation coefficient)
	//	fCorrCoef -----------> 相关系数
	void GEOSTAT_DLL _gsSetCorrCoef(GeoStatObj gsObj, double fCorrCoef);

	//设置阈值标志(set number of cutoffs)
	//	iCutFlag -----------> 阀值标志(1:pricut,2:seccut)
	void GEOSTAT_DLL _gsSetCutNum(GeoStatObj gsObj, int iCutNum, int iCutFlag=1);

	//设置滞后的数目(set number of lags)
	//	iLagNum -----------> 滞后数目
	void GEOSTAT_DLL _gsSetLagNum(GeoStatObj gsObj, int iLagNum);

	//set Indicator variogram information
	//设置指示器变差函数信息
	//	iFlag ---------> 插值参数标志(1:指示器克立金;2:一般克立金)
	void GEOSTAT_DLL _gsSetIndVargInfo(GeoStatObj gsObj, int iMaxNstNum, 
									   int *piStrNum, double *pfNugConst, 
									   double *pfArchValue, int *piModelType, 
									   double *pfChgRang, double *pfChgRang1, double *pfChgRang2, 
									   double *pfAnisAng1, double *pfAnisAng2, double *pfAnisAng3, 
									   int iFlag=1);

	//工具函数
	//公式法拟合球状模型的变差函数
	int GEOSTAT_DLL FitSphVargFormula(const Variogram *Variog, const double *weight, const int iLagNum,  double *fC0, double *fC, double *fA);
	void GEOSTAT_DLL GetAver(Variogram *pfGam, int iLagNum,  double *pfAver);
	void GEOSTAT_DLL GetVari(Variogram *pfGam, int iLagNum, double fAver, double *pfVari);

	//直接法拟合球状模型变差函数
	int GEOSTAT_DLL FitSphVargDirect(const Variogram *Variog, const int iLagNum, double fVari, double *fC0, double *fC, double *fA);

	//用多项式回归算法拟合指数模型
	int GEOSTAT_DLL FitExpVarg(const Variogram *Variog, const double *weight, const int iLagNum, double *fC0, double *fC, double *fA);
	//用多项式回归算法拟合高斯模型
	int GEOSTAT_DLL FitGaussVarg(const Variogram *Variog, const double *weight, const int iLagNum, double *fC0, double *fC, double *fA);
	//拟合幂模型
	int GEOSTAT_DLL FitPowVarg(const Variogram *Variog, const double *weight, const int iLagNum, double *fC0, double *fC, double *fA );
	//拟合线性模型
	int GEOSTAT_DLL FitLinearVarg(const Variogram *Variog, const double *weight, const int iLagNum, double *fC0, double *fC, double *fA );

	int GEOSTAT_DLL Fit_Regress_AddWeight(int N, int P, double **matLeft,double *matRight,  double *w, double *pb,double *pyfit, int b0_has);
	int GEOSTAT_DLL Fit_GaussAxb(double *a, double *b, int n);	
    
	//线形拟合算法
	long GEOSTAT_DLL pofitho(double *dx,//自变量
		                	 double *dy,//函数值
			                 double *b,//拟合得出的多项式系数
			                 long m,   //样本点数目
			                 long n);   //多项式维数
	//计算分位值
	double GEOSTAT_DLL CalEachQuan(double *pattr, long lpntNum, double fValue);

#ifdef __cplusplus
 }
#endif

#ifndef _CGEO_STAT_LIB
	#ifdef _DEBUG
		#pragma comment(lib, "GeoStatLibD.lib")
	#else
		#pragma comment(lib, "GeoStatLib.lib")
	#endif
#endif

//#pragma pack(pop)

#endif //_GEOSTAT_LIB_H