#pragma once

#include <vector>
#include "OGBasDef.h"

#pragma warning(disable : 4786) //去掉vector嵌套引出的警告
#pragma warning(disable : 4251) //去掉由结构派生引出的警告
#pragma warning(disable : 4275) //去掉由GRIDCTRL引出的警告
#pragma warning(disable : 4103)
#pragma warning(disable : 4244)
#pragma warning(disable : 4018)
 
class CDatDictOper;
typedef class CDatDictOper* CBaseInfoMngObj;
//----------------------------业务逻辑统计分析结构-----------------------------//
typedef struct StatParam_Stru {
	long				lNum;		//样本数
	double				dMax;		//最大值
	double				dMin;		//最小值
	double				dAvg;		//样本均值
	double				dVar;		//样本方差
	double				dMid;		//中位数
	double				dDif;		//变异系数
}StatParam,*LPSTATPARAM;

//控制点类型宏定义
#define CTRL_PNT_TYPE_STRAT				0					//地层界线上的控制点
#define CTRL_PNT_TYPE_HOLE				1					//钻孔轨迹线上的控制点
#define CTRL_PNT_TYPE_SECT				2					//剖面边界线上的控制点
#define CTRL_PNT_TYPE_FAULT				3					//断层上的控制点
#define CTRL_PNT_TYPE_PINCH				4					//地层尖灭的控制点

#define STRAT_CODE_LEN		(20+1)//地层编号长度

#define PROJ_STRIPNO_SH		21

//-----------------------------------------------------------------------------
// 释放资源的宏
//-----------------------------------------------------------------------------
#define GME_SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
#define SAFE_DELETE_BYTE_ARRAY(p) { if(p) { delete[] (char*)(p);   (p)=NULL; } }

//钻孔类型宏定义
#define ALL_BORE_HOLE					DZ			//所有钻孔类型
#define BR_BORE_HOLE					DJY			//岩体地质钻孔
#define Q_BORE_HOLE						DDS			//第四纪地质钻孔
#define HD_BORE_HOLE					DSW			//水文地质钻孔
#define RSEG_BORE_HOLE					DGC			//岩土工程地质钻孔
#define REG_BORE_HOLE					DGCQZK		//区域工程地质钻孔
//钻孔分层原始数据表通用字段长度
#define  LEN_DSAC                        (20+1)    //时代系
#define  LEN_DSAD                        (20+1)    //时代统
#define  LEN_DCDH                        (20+1)    //地层代号
#define  LEN_TKALA                       (20+1)  //孔号
#define  LEN_YXTZ                        (2048+1)//岩性特征

//----------------------------通用数据表字段长度-----------------------------//
#define LEN_BOREHOLE_CODE			16		//钻孔编码长度
#define LEN_TABLE_DEPT				16		//数据表中单位名称字段长度
#define LEN_TABLE_NOTE				128		//数据表中备注字段长度
#define LEN_STRAT_LEVEL				12		//地层级别编码长度
#define LEN_SAMPLE_CODE				16		//样品编码长度
#define LEN_SAMPLE_NAME				16		//样品名称长度
#define LEN_PERSON_NAME				16		//数据表中人名字段长度
#define LEN_FAULT_CODE				16		//断层编码长度
//--------------------------------钻孔属性数据表字段长度---------------------//
#define LEN_HOLEATT_SITE			64	//钻孔孔位
#define LEN_HOLEATT_DIST			32	//行政区域
#define LEN_HOLEATT_TOWN            32	//乡镇
#define LEN_HOLEATT_DATSRC          64	//资料来源


//----------------------------分层属性数据表字段长度-------------------------//
#define LEN_LAYERATT_ROCK_TYPE		64		//分层属性岩石类型
#define LEN_LAYERATT_ROCK_DESC		512		//分层属性岩石描述
#define LEN_LAYERATT_STRU			32		//层理构造
#define LEN_LAYERATT_SEDI			16		//沉积相
#define LEN_LAYERATT_SEDI_NAME      16		//沉积学定名
#define LEN_LAYERATT_SOIL_NAME		16		//土质学定名
//----------------------------通用字段名称宏定义-----------------------------//
#define FLD_HOLE_ID                  "HoleID"   //钻孔ID号
#define FLD_HOLE_CODE				 "HoleCode" //钻孔编码
#define FLD_HOLE_X                   "X"        //X坐标
#define FLD_HOLE_Y                   "Y"        //Y坐标
#define FLD_HOLE_HEIGHT				 "Height"	//钻孔标高
#define FLD_HOLE_DEPTH				 "Depth"	//钻孔深度
#define FLD_HOLE_TYPE                "Type"		//钻孔类型
#define FLD_HOLE_FLAG				 "KNumber"	//是否是解释数据，>0解释数据
#define FLD_HOLE_FILE_NO             "FileNo"	//档案号


#define FLDCH_HOLE_ID                "钻孔ID号"
#define FLDCH_HOLE_CODE				 "钻孔编码"
#define FLDCH_HOLE_X                 "X坐标"
#define FLDCH_HOLE_Y                 "Y坐标"
#define FLDCH_HOLE_HEIGHT			 "钻孔标高"
#define FLDCH_HOLE_DEPTH			 "钻孔深度"
#define FLDCH_HOLE_TYPE				 "钻孔类型"
#define FLDCH_HOLE_FLAG				 "是否解释"

#define FLD_HOLE_LEVEL               "HoleLevel" //钻孔级别
#define FLD_HOLE_WATER_LEVEL         "WATERLEVEL"//钻孔水位
#define FLD_HOLE_START_DATE          "STARTDATE" //钻孔开工日期
#define FLD_HOLE_END_DATE			 "ENDDATE"   //钻孔完工日期
#define FLD_HOLE_ENGINEER	         "Engineer"  //钻孔工程师
#define FLD_HOLE_ATTRIBUTE			 "ATTRIBUTE" //钻孔属性
#define FLD_HOLE_NOTE				 "Note"      //钻孔备注
#define FLD_HOLE_NO                  "HoleNo"    //钻孔编号
#define FLD_LAYER_NO                 "LayerNo"   //分层编号
#define FLD_SOIL_NO                  "SoilNo"    //土样编号
#define FLD_HOLE_LONGITUDE           "Longitude" //经度
#define FLD_HOLE_LATITUDE            "Latitude"  //纬度
#define FLDCH_HOLE_LEVEL             "钻孔级别" 
#define FLDCH_HOLE_WATER_LEVEL       "钻孔水位" 
#define FLDCH_HOLE_START_DATE        "钻孔开工日期" 
#define FLDCH_HOLE_END_DATE			 "钻孔完工日期" 
#define FLDCH_HOLE_ENGINEER	         "钻孔工程师" 
#define FLDCH_HOLE_ATTRIBUTE		 "钻孔属性" 
#define FLDCH_HOLE_NOTE				 "钻孔备注" 
#define FLDCH_HOLE_NO                "钻孔编号"  
#define FLDCH_LAYER_NO               "分层编号" 
#define FLDCH_SOIL_NO                "土样编号"  
#define FLDCH_HOLE_LONGITUDE         "经度" 
#define FLDCH_HOLE_LATITUDE          "纬度" 

#define FLD_STRATVER_ID				 "StdStratID"//标准地层版本号
#define FLD_STRATDESC_LEVEL			 "StratLevel"//标准地层地层级别编码
#define FLD_STRATDESC_TOPDEPTH		 "TopDepth" //地层顶板深度
#define FLD_STRATDESC_BTMDEPTH		 "BtmDepth" //地层底板深度
#define FLD_STRATDESC_THICKNESS		 "Thickness"//地层厚度
#define FLD_SOIL_ID                  "SoilID"   //土样ID号
#define FLD_PRO_ID                   "ProID"     //专业编码
#define FLD_ROCK_TYPE                "RockType"  //岩石类型
#define FLD_ROCK_DESC                "RockDesc"  //岩石描述

#define FLDCH_STRATVER_ID			 "标准地层版本号"
#define FLDCH_STRATDESC_LEVEL		 "标准地层地层级别编码"
#define FLDCH_STRATDESC_TOPDEPTH	 "地层顶板深度" 
#define FLDCH_STRATDESC_BTMDEPTH	 "地层底板深度" 
#define FLDCH_STRATDESC_THICKNESS	 "地层厚度"
#define FLDCH_SOIL_ID                "土样ID号"   
#define FLDCH_PRO_ID                 "专业编码"     
#define FLDCH_ROCK_TYPE              "岩石类型"  
#define FLDCH_ROCK_DESC              "岩石描述"  



#define FLD_SOIL_TYPE                "SoilType"		//土样类型
#define FLD_SAMP_STARTDEP            "StartDep"		//起始深度
#define FLD_SAMP_ENDDEP              "EndDep"		//中止深度
#define FLD_SOIL_COLOR               "SoilColor"	//土样颜色

#define FLDCH_SOIL_TYPE              "土样类型"		
#define FLDCH_SAMP_STARTDEP          "起始深度"		
#define FLDCH_SAMP_ENDDEP            "中止深度"		
#define FLDCH_SOIL_COLOR             "土样颜色"


//岩体地质钻孔分层属性
#define FLD_LAYERATT_ROCKLEN        "RockLen"   //岩矿芯长       
#define FLD_LAYERATT_ROCKRATIO      "RockRatio" //采样率
#define FLD_LAYERATT_ANGLE          "Angle"     //标志层与岩心轴夹角	        
#define FLD_LAYERATT_TOPINTER       "TopInter"  //上层接触关系
#define FLD_LAYERATT_BTMINTER       "BtmInter"  //下层接触关系
#define FLD_LAYERATT_DIR            "Dir"	    // 走向 
#define FLD_LAYERATT_TEND           "Tend"      // 倾向  
#define FLD_LAYERATT_OBLIQUITY      "Obliquity" //倾角

#define FLDCH_LAYERATT_ROCKLEN      "岩矿芯长"
#define FLDCH_LAYERATT_ROCKRATIO    "采样率" 
#define FLDCH_LAYERATT_ANGLE        "标志层与岩心轴夹角"
#define FLDCH_LAYERATT_TOPINTER     "上层接触关系"
#define FLDCH_LAYERATT_BTMINTER     "下层接触关系"
#define FLDCH_LAYERATT_DIR          "走向"
#define FLDCH_LAYERATT_TEND         "倾向"
#define FLDCH_LAYERATT_OBLIQUITY    "倾角" 


//-------------------------三维属性建模对话框--------------------//

#define ATT3D_BUILD_MODEL_DLG				0		//三维属性建模对话框
#define CREATE_ISOLINE_DLG					1		//追踪等值线对话框

//------------------------- 图件类型-------------------------------//
#define CREATE_VER_CHART                    0       //生成直方图
#define CREATE_PIE_CHART                    1       //生成饼图
#define CREATE_CURV_CHART                   2       //生成曲线图




//点位显示编码
#define HD_ESTAB_CODE_LEN		128						//设施编码长度
#define DISP_DOT_CODE_LEN		HD_ESTAB_CODE_LEN		//设施编码长度




typedef struct LinStrcT //线结构
{
	Vector2		*pLinDots;
	long		lDotNum;
}LinStrcT;

typedef struct CircleStrcT //圆结构
{
	Vector2		dOrgDot;
	double		dRadius;
}CircleStrcT;

typedef std::vector<Vector2> ToolRegDots;
typedef std::vector<Vector2> ToolLinDots;

 
#define STRAT_NAMELEN	40
#define STRAT_CODELEN	20
#define STRAT_NOLEN			 20    //地层序号长度

#define FLDNAME_STRATCODE			"StratCode"		//地层编号
#define FLDNAME_STRATNO				"StratNo"		//地层序号
#define FLDNAME_STRATNAME			"StratName"		//地层名称
