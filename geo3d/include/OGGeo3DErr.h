#pragma once

//****************************系统错误代码***********************************//
#define GEO3D_SUCCESS				000000001L			//成功
#define INVALID_VALUE				1.70141e+038		//失败
 
//ER为Error的缩写
/*
错误代码为9位的数字，共分三段，其含义如下：
(1) 1-3位：表示系统共用错误类型，具体如下：
100－－－内存分配错误
200－－－数据库访问错误
300－－－函数执行错误
400－－－文件操作错误

(2) 4-6位为错误所属的专业类型(具体见DdPubDef.h)

(3) 7-9位为错误编号，从001－999递增
*/

//错误编码方式：100（错误类型）＋100（错误专业）＋001（错误码）

//---------------------------------错误宏定义--------------------------------//

//系统错误(100+000)
#define ER_MEM_NEWMEM						-100000001L			//内存分配失败
#define ERR_ALLOC_MEM						ER_MEM_NEWMEM		//分配内存错误
//系统错误(200+000)
#define ER_SQL								-200000001L			//SQL语句执行失败
#define ER_CONNECT							-200000002L			//数据源连接失败
#define ERR_GET_BLOB						-200000003L			//更新表中BLOB数据失败
//系统错误(300+000)
#define ER_PARAMETERIN						-300000001L			//函数参数非法
#define ER_RESULTOUT						-300000002L			//函数执行结果非法
#define ERR_INITDLG							-300000003L			//初始化对话框失败
#define ERR_DEBUG							-300000004L			//调试错误
#define ERR_GET_REG_NUM						-300000005L			//取区数目错误
#define ERR_GET_PNT_NUM						-300000006L			//取点数目错误
#define ERR_LIMIT_INVALID					-300000007L			//错误的limit condition
#define ERR_INPUT_PARAM						-300000008L			//错误的输入参数
#define ERR_OPER_CANCEL						-300000009L			//操作被用户取消

//基础模块错误(101+100)
#define ER_BASEGEO_NONAME					-200100001L			//表名没找到
#define ER_BASEGEO_NOOWNER					-200100002L			//用户名没找到
#define ER_BASEGEO_NODATA					-200100003L			//没有取到数据
#define ERR_EXECUTE_SQL						ER_SQL				//执行SQL命令失败
#define ERR_GET_TABLENAME					ER_BASEGEO_NONAME	//取表名称失败
#define ERR_GET_NODATA						ER_BASEGEO_NODATA	//没有取到数据
//各专业模块错误(200+300)
#define ERR_BOREHOLE_UNIQUECODE				-200300001L			//钻孔编码不唯一
#define ERR_SAMPLE_TYPE						-200300002L			//错误的样品类型
#define ERR_ENGNO_UNIQUECODE                -200300003L         //勘探工程编码不唯一

//各专业模块错误(300+310)
#define ERR_HOLETYPE						-300310001L			//错误的钻孔类型
#define ERR_GETHOLEMNG						-300310002L			//获得钻孔数据管理器失败
#define ERR_GETSTRATMNG						-300310003L			//获取分层标准管理器失败
#define ERR_NOT_ENOUGH_HOLE					-300310004L			//钻孔个数不够错误
#define ERR_GET_COMCHARTAPP					-300310005L			//获得通用图件应用对象失败
#define ERR_STRAT_VERSION					-300310006L			//错误的地层版本号
#define ERR_MAX_STRAT_LEVEL					-300310007L			//地层版本的最大地层级别错误
#define ERR_STRAT_INFO						-300310008L			//没有取到地层信息
#define ERR_CREATE_PRITIN_MODEL				-300310009L			//生成主TIN失败
#define ERR_MAPGIS_AREA_TYPE				-300310010L			//mapgis工作区类型不符
#define ERR_GET_ATTSTRU						-300310011L			//取工作区属性结构错误
#define ERR_GET_MAP_ELEMENT_NUM				-300310012L			//取工作区内图元个数错误
#define ERR_MAPGIS_AREA_TOPO				-300310013L			//mapgis工作区拓扑关系错误
#define ERR_APPEND_TIN_PNT					-300310014L			//向TIN工作区插入点错误
#define ERR_SET_TIN_AREA_MAP_PARAM			-300310015L			//设置TIN工作区地图参数错误
#define ERR_CREATE_TIN_NET					-300310016L			//TIN工作区构建三角网错误
#define ERR_GET_MAP_ELEMENT					-300310017L			//取图元错误
#define ERR_INTERP_TIN						-300310018L			//TIN网插值错误
#define ERR_COORD_TRANS						-300310019L			//坐标投影变换错误

//项目管理模块错误
#define ER_PRJ_INITFAIL						-300830001L			//没找到用户查找的工程的相关信息
#define ER_PRJ_NOFOUND						-200830002L			//没找到用户查找的工程的相关信息

//add by hws
//对话框信息
#define ER_ID_OK						IDOK
#define ER_ID_CANCEL					IDCANCEL
													
