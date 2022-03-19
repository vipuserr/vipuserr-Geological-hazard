#ifndef GME_DEF_H
#define GME_DEF_H


#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <queue>

#pragma warning(disable:4101)
#pragma warning(disable:4244)
#pragma warning(disable:4251) 
#pragma warning(disable:4267) 
#pragma warning(disable:4717)

namespace Smart3dMap
{
	// -------------------------- 与存储相关的三维基础定义 -------------------------------------- //
#ifdef _MSC_VER
	typedef		__int64							int64;
	typedef     unsigned __int64				uint64;
#else
	typedef		long long				int64;
	typedef     unsigned long long		uint64;
#endif
	//数据库要素类ID定义
	typedef		short							int16;
	typedef		unsigned short					uint16;
	typedef		__int32							int32;
	typedef		int32							GINT;
	typedef		unsigned __int32				uint32;
	typedef		__int64							int64;
	typedef		unsigned __int64				uint64;
	typedef		long							GLONG;
	typedef		unsigned long					GULONG;
	typedef		float							GFLOAT;
	typedef		float							GREAL;
	typedef     double							GDOUBLE;
	typedef		std::string						GString;
	typedef		std::string						GGUID;
	typedef		std::vector<GString>			GStringVector;
	typedef		std::map<GString, GString>		GStringMap;

	typedef		int32					GME_TYPE_OBJ_ID; //对象ID


	//特殊要素类ID定义
	const GME_TYPE_OBJ_ID  GME_INVALID_FCLS_ID = -1;//无效要素类ID
	const GME_TYPE_OBJ_ID  GME_ACTIVE_FCLS_ID = 0;//动态要素类

#define  GME_INVALID_OBJ_ID (-999999) //无效值

#define	GME_TEXTURE_NUM   8 //纹理数最大值
#define	GME_MAXLIGHT_NUM  8 //场景最大灯光数

//常量定义
#define		GME_MC_ANGPER		(0.01745329251994f)//每一角度有多少弧度
#define		GME_MC_PIPER		(57.2957804904430f)//每一弧度有多少角度
#define		GME_MC_PI			(3.14159265358979f)//PI
#define		GME_MC_PI2			(1.57079632679490f)//PI/2
#define		GME_MC_2PI			(6.28318530717959f)//2PI

//精度
#define		GME_MIN_FLOAT		(-3.402823E+38)
#define		GME_MAX_FLOAT		(3.402823E+38)
#define		GME_MIN_DOUBLE		(-1.79769313486232E+307)
#define		GME_MAX_DOUBLE		(1.79769313486232E+307)

//0
#define		GME_ZERO_FLOAT		(1.401298E-45)
#define		GME_ZERO_MAX_DBL	(+4.94065645841247E-324)	
#define GME_ZERO_1BIT 1E-1
#define GME_ZERO_2BIT 1E-2
#define GME_ZERO_3BIT 1E-3
#define GME_ZERO_4BIT 1E-4
#define GME_ZERO_5BIT 1E-5
#define GME_ZERO_6BIT 1E-6
#define GME_ZERO_7BIT 1E-7
#define GME_ZERO_8BIT 1E-8
#define GME_ZERO_9BIT 1E-9
#define GME_ZERO_10BIT 1E-10
#define GME_EQUAL_1BIT(a,b)     ( fabs(a-b) < GME_ZERO_1BIT )
#define GME_EQUAL_2BIT(a,b)     ( fabs(a-b) < GME_ZERO_2BIT )
#define GME_EQUAL_3BIT(a,b)     ( fabs(a-b) < GME_ZERO_3BIT )
#define GME_EQUAL_4BIT(a,b)     ( fabs(a-b) < GME_ZERO_4BIT )
#define GME_EQUAL_5BIT(a,b)     ( fabs(a-b) < GME_ZERO_5BIT )
#define GME_EQUAL_6BIT(a,b)     ( fabs(a-b) < GME_ZERO_6BIT )
#define GME_EQUAL_7BIT(a,b)     ( fabs(a-b) < GME_ZERO_7BIT )
#define	GME_EQUAL_8BIT(a,b)		( fabs(a-b) < GME_ZERO_8BIT )
#define	GME_EQUAL_9BIT(a,b)		( fabs(a-b) < GME_ZERO_9BIT )
#define	GME_EQUAL_10BIT(a,b)	( fabs(a-b) < GME_ZERO_10BIT )
#ifndef	GME_EQUAL
#define	GME_EQUAL(x,y) ( fabs( (x) - (y))<GME_ZERO_6BIT ? 1 : 0 )
#endif

#define GME_FABS(x) (((x)<0)?-(x):(x))




//角度弧度转换
#define GME_ToRadian( degree ) ((degree) * GME_MC_ANGPER)
#define GME_ToDegree( radian ) ((radian) * GME_MC_PIPER)

//颜色转换(整数转浮点）
#define GME_COLORVALUE(color)  ((BYTE)(color*(float)255))// 颜色转换宏[0.0,1.0]到[0,255]
#define GME_COLORVALUEREV(color)  ((float)(color/255.0f))// 颜色转换宏[0,255]到[0.0,1.0]

//RGBA2ARGB
#define GME_COLOR_ARGB(a,r,g,b) ((DWORD)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
#define GME_GLTOD3D_COLOR_RGBA(r,g,b,a) GME_COLOR_ARGB((DWORD)((a)*255.f),(DWORD)((r)*255.f),(DWORD)((g)*255.f),(DWORD)((b)*255.f))
#define GME_GLTOD3D_COLOR_RGB(r,g,b) GME_COLOR_ARGB((DWORD)0xff,(DWORD)((r)*255.f),(DWORD)((g)*255.f),(DWORD)((b)*255.f))
	typedef unsigned int GME_RGBA;
	typedef unsigned int GME_ARGB;
	typedef unsigned int GME_ABGR;
	//释放内存...
#define GME_SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define GME_SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#define GME_SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }

	typedef enum GME_DIM_TYPE
	{
		GME_DIM_2D = 1,	//二维
		GME_DIM_3D = 2,	//三维
	}GME_DIM_TYPE;

	typedef enum GME_ERROR_CODE
	{	//函数返回码类型
		GME_ERR_NO_ERROR = 1,	//返回成功
		GME_ERR_INVALID_ENUM = 2,		//枚举定义错误
		GME_ERR_INVALID_VALUE = 3,		//值错误
		GME_ERR_INVALID_OPERATION = 4,	//操作错误
		GME_ERR_STACK_OVERFLOW = 5,		//堆栈上溢
		GME_ERR_STACK_UNDERFLOW = 6,	//堆栈下溢
		GME_ERR_OUT_OF_MEMORY = 7,		//内存越界
		GME_ERR_MEM_NEWMEM_FALSE = 701,//内存申请失败NEW
		GME_ERR_INCOMPATIBLE_GL_VERSION = 8,//版本不兼容
		GME_ERR_PARAMETRIC_ERROR = 9, //参数错误
		GME_ERR_INPUT_PARAM_INVALID = 901,////输入参数不合法
		GME_ERR_DATA_IS_NOTEXIST = 10,//数据不存在
		GME_ERR_ARRAY_OVERFLOW = 11,  //数组越界
		GME_ERR_DB_CREATE_ERROR = 101,	//数据库打开失败
		GME_ERR_DB_OPEN_FAILED = 102,		//数据库打开失败
		GME_ERR_DB_HAS_EXIST = 103,		//数据库文件已存在
		GME_ERR_DB_TEMP_CREATE_ERROR = 104,//临时数据库创建失败
		GME_ERR_FCLS_CREATE_ERROR = 201,	//要素类创建失败
		GME_ERR_FCLS_HAS_EXIST = 202,		//要素类已存在
		GME_ERR_FCLS_ATT_CREAT_ERROR = 203,//要素类属性表创建失败
		GME_ERR_FEA_CREATE_ERROR = 301,	//要素添加失败
		GME_ERR_FEA_HAS_EXIST = 302,	//要素已存在
		GME_ERR_ENT_CREATE_ERROR = 401,	//实体添加失败
		GME_ERR_ENT_HAS_EXIST = 402,	//实体已存在
		GME_ERR_ENT_FIELD_OPER_ERROR = 403,	//属性场操作失败
		GME_ERR_LABEL_OPER_ERROR = 501,	//标注操作失败
		GME_ERR_DEM_OPER_ERROR = 601,	//操作地形失败
		GME_ERR_LEGEND_OPER_ERROR = 701,//操作图例失败
		GME_ERR_SERIES_OPER_ERROR = 801,//操作标准地层失败
		GME_ERR_GEOREF_OPER_ERROR = 901,//操作空间参考系失败
	}GME_ERROR_CODE;

	//　空间坐标轴定义
	typedef enum GME_SPACE_AXIS_DIR
	{
		GME_SAD_NONE = -1,		// 空;
		GME_SAD_ZERO = 0,		// 原点
		GME_SAD_X = 1,			// X正向轴
		GME_SAD_Y = 2,			// Y正向轴
		GME_SAD_Z = 3,			// Z正向轴
		GME_SAD_NX = 4,			// X负向轴
		GME_SAD_NY = 5,			// Y负向轴
		GME_SAD_NZ = 6,			// Z负向轴
	}GME_SPACE_AXIS_DIR;

	//要素类类型
	typedef enum GME_FCLS_TYPE
	{
		GME_FCLS_TYPE_COMM = 0,		//普通要素类（包括ID、Name），处理一般几何实体、地形、注记等

		GME_FCLS_TYPE_GEO_PNT = 1,	//地质点
		GME_FCLS_TYPE_GEO_ORI_PNT = 2,//产状点
		GME_FCLS_TYPE_GEO_LIN = 3,	  //地质线
		GME_FCLS_TYPE_GEO_SURF = 4,	  //地质面
		GME_FCLS_TYPE_GEO_ENT = 5,	  //地质体
		GME_FCLS_TYPE_GEO_HOLE = 6,	  //钻孔
		GME_FCLS_TYPE_GEO_FAULT = 7,  //断层

		GME_FCLS_TYPE_DEM = 8,	   //地形
		GME_FCLS_TYPE_FIELD = 9,	  //属性场
		GME_FCLS_TYPE_BOLT = 10,   //锚杆
		GME_FCLS_TYPE_PILE = 11, //桩基
		GME_FCLS_TYPE_BUILD = 12,  // 建筑物
	}GME_FCLS_TYPE;

	//数据库连接类型
	typedef enum GME_LinkType
	{
		GME_DB_LINK_MEM = 1,	//MEMORY
		GME_DB_LINK_SQLITE = 2, //SQLITE
		GME_DB_LINK_ORACLE = 3, //ORACLE
		GME_DB_LINK_SQLSERVER = 4, //SQLSERVER
		GME_DB_LINK_POSTGRESQL = 5, //POSTGRESQL
		GME_DB_LINK_MYSQL = 6, //MYSQLSQL
		GME_DB_LINK_HBASE = 7, //HBASE
		GME_DB_LINK_MONGODB = 8, //MONGODB
		GME_DB_LINK_BDB = 9, //BERKELEYDB
		GME_DB_LINE_WEBSERVICE = 10, //WebService
		GME_DB_LINK_ACCESS = 11, //ACCESS
	}GME_LinkType;


	//对象IO操作类型
	typedef enum GME_MDL_IO_TYPE
	{
		GME_MDL_IO_UNKNOWN = 0,
		GME_MDL_IO_DB = 1,
		GME_MDL_IO_TMP = 2,
	}GME_MDL_IO_TYPE;


	typedef enum GME_DATA_TYPE
	{
		//属性字段类型定义
		GME_BYTE_TYPE = 1,
		GME_STR_TYPE = 2,
		GME_SHORT_TYPE = 3,
		GME_LONG_TYPE = 4,
		GME_FLOAT_TYPE = 5,
		GME_DOUBLE_TYPE = 6,
		GME_BOOL_TYPE = 7,
		GME_DATE_TYPE = 8,
		GME_TIME_TYPE = 9,
		GME_TIMESTAMP_TYPE = 10,
		GME_BLOB_TYPE = 11,
		GME_PICTURE_TYPE = 12,
		GME_MAP_TYPE = 13,
		GME_SOUND_TYPE = 14,
		GME_VIDEO_TYPE = 15,
		GME_EXT_TYPE = 16,
		GME_TABLE_TYPE = 17,
		GME_NUMERIC_TYPE = 18,
		GME_INT64_TYPE = 19,
		GME_DATA_TYPE_TEXT = 21, //sqlite独有的数据类型.
		GME_DATA_TYPE_INT = 22,
		GME_DATA_TYPE_REAL = 23,
		GME_DATA_TYPE_BLOB = 24,
	}GME_DATA_TYPE;


	typedef	enum GME_OBJ_TYPE
	{
		//基本存储结构信息
		GME_OT_INVALID_TYPE = 0,

		//几何实体
		GME_OT_CORNER = 101, //结点
		GME_OT_LINE = 102,   //线
		GME_OT_SURFACE = 103,//面
		GME_OT_ENTITY = 104,//体
		GME_OT_FIELD = 105, //属性场
		GME_OT_DEM = 106,   //DEM
		GME_OT_NOTE = 107,  //注记
		GME_OT_SERIES = 108,//标准地层
		GME_OT_MATLIB = 109,//材质
		GME_OT_GEOREF = 110,//参考系
		GME_OT_OCTFIELD = 111,//八叉树属性场

		//地质实体
		GME_OT_GEO_POINT = 201,
		GME_OT_GEO_ORI_POINT = 202,
		GME_OT_GEO_LINE = 203,
		GME_OT_GEO_SURFACE = 204,
		GME_OT_GEO_ENTITY = 205,
		GME_OT_GEO_FAULT = 206,
		GME_OT_GEO_HOLE = 207,

		//几何网格里的元素
		GME_OT_POINT = 301,  //顶点
		GME_OT_EDGE = 302,  //边
		GME_OT_FACET = 303,  //面片（三角形）
		GME_OT_VOLCELL = 304, //体元

		//点线面修饰信息
		GME_OT_VEX_DECORATION = 401,   //顶点修饰
		GME_OT_VEX_NORMAL = 402,   //顶点法向量
		GME_OT_VEX_DIFFCOLOR = 403,//顶点颜色
		GME_OT_VEX_TEXCOORD1 = 404,//顶点第一层纹理坐标系列
		GME_OT_VEX_TEXCOORD2 = 405,
		GME_OT_VEX_TEXCOORD3 = 406,
		GME_OT_VEX_TEXCOORD4 = 407,
		GME_OT_VEX_TEXCOORD5 = 408,
		GME_OT_VEX_TEXCOORD6 = 409,
		GME_OT_VEX_TEXCOORD7 = 410,
		GME_OT_VEX_TEXCOORD8 = 411,//顶点第八层纹理坐标系列

		GME_OT_SUR_DECORATION = 420, //面修饰信息
		GME_OT_TRI_MTLLIST = 421,//面的三角面材质
		GME_OT_TRI_TEXLIST1 = 422,//面的第一层三角面纹理号1
		GME_OT_TRI_TEXLIST2 = 423,
		GME_OT_TRI_TEXLIST3 = 424,
		GME_OT_TRI_TEXLIST4 = 425,
		GME_OT_TRI_TEXLIST5 = 426,
		GME_OT_TRI_TEXLIST6 = 427,
		GME_OT_TRI_TEXLIST7 = 428,
		GME_OT_TRI_TEXLIST8 = 429,

		GME_OT_TYPE_MTL = 430,

		//要素
		GME_OT_FCLS = 501,//要素类
		GME_OT_FEATURE = 502,//要素
		GME_OT_RELATION = 503,//要素之间的关系
		GME_OT_ATT_TBL = 504,//要素属性表

		//参数存储
		GME_OT_SYS_PARAM = 601,
		GME_OT_USER_PARAM = 602,
		GME_OT_TEMP_PARAM = 603,
		GME_OT_IDX = 604,
	}GME_OBJ_TYPE;

	typedef enum GME_SURF_TYPE//面类型
	{
		SUR_TYPE_INIT = 0x0000, //未知
		SUR_TYPE_TOP = 0x0001,//顶面
		SUR_TYPE_BTM = 0x0002,//底面
		SUR_TYPE_SIDE = 0x0004, //侧面
		SUR_TYPE_OUTSIDE = 0x0008, //外表面
	}GME_SURF_TYPE;

	typedef enum GME_GROUND_MODE//地面操作模式
	{
		GME_CLOSE_TO_GROUND = 1,		//贴近地面
		GME_RALETIVE_TO_GROUND = 2,	//相对于地面
		GME_ABSOLUTE = 3,				//绝对
	}GME_GROUND_MODE;

	typedef enum GME_VOLUME_TYPE //属性场种类
	{
		GME_NONE = 0,   //不定义
		GME_SCALAR = 1, //标量场
		GME_VECTOR = 2, //矢量场
		GME_TENSOR = 3,  //张量场
	}GME_VOLUME_TYPE;

	typedef enum GME_VOLUME_CELL_TYPE //体元类型
	{
		GME_CT_TET = 1,	 //规则（六面体）
		GME_CT_CUBE = 2, //不规则（四面体）
	}GME_VOLUME_CELL_TYPE;

	typedef enum GME_MATERIAL_TYPE //材质类型
	{
		GME_MT_NONE = 0, //无
		GME_MT_COLOR = 1,//颜色材质
		GME_MT_TEXTURE = 2,//纹理材质
	}GME_MATERIAL_TYPE;

	typedef enum GME_MATERIAL_SIDE //材质贴图表面
	{
		GME_MS_POSITIVE = 1, //正面材质
		GME_MS_NEGATIVE = 2, //反面材质
	}GME_MATERIAL_SIDE;

	typedef enum GME_LEGEND_TYPE //图例类型
	{
		GME_LT_SYMBOL = 1,	//符号型
		GME_LT_COLOR = 2,	//颜色材质
		GME_LT_COLORTBL = 3,//色表
	}GME_LEGEND_TYPE;

	typedef enum GME_MODEL_TYPE //模型类型
	{
		GME_MT_GEO_UNKNOWN_MDL = 0,	//普通模型
		GME_MT_GEO_STRUCT_MDL = 1,	//结构模型
		GME_MT_GEO_FIELD_MDL = 2,	//属性模型
		GME_MT_GEO_HOLE_MDL = 3,	//钻孔模型
		GME_MT_GEO_SECTION_MDL = 4,	//剖面模型
		GME_MT_GEO_GEOMAP_MDL = 5,	//地质图模型
		GME_MT_GEO_FAULT_MDL = 6,	//断层模型
	}GME_MODEL_TYPE;

	typedef enum GME_FIELD_SPLIT_TYPE //属性场剖分类型
	{
		GME_FST_AVARAGE = 1, //均匀剖分
		GME_MT_NOAVARAGE = 2,//不均匀剖分
	}GME_FIELD_SPLIT_TYPE;

	typedef enum GME_FAULT_TYPE //断层类型
	{
		GME_FT_NORMAL_FAULT = 1, //正断层
		GME_FT_INVERSE_FAULT = 2, //逆断层
		GME_FT_STRIKESLIP_FAULT = 3, //走滑断层
	}GME_FAULT_TYPE;

	typedef enum GME_FEATURE_RELATION_TYPE //地质对象关系类型
	{
		GME_FRT_LAYER2LAYER = 1, //
		GME_FRT_LAYER2FAULT = 2, //
		GME_FRT_FAULT2FAULT = 3, //
		GME_FRT_INTRUSIVEBODY2LAYER = 4,
		//changchan
	}GME_FEATURE_RELATION_TYPE;
	typedef enum GME_FEATURE_RELATION_VALUE //地质对象关系
	{
		GME_FRV_NOT_TOUCH = 0, //
		GME_FRV_TOUCH = 10, //

		GME_FRV_CONFORMITY = 11, // L_L
		GME_FRV_UNCONFORMITY = 12,
		GME_FRV_UNCONFORMITY_ANGLE = 13,
		GME_FRV_UNCONFORMITY_PARALLEL = 14,

		GME_FRV_UPPER_PLATE = 31, //L_F
		GME_FRV_LOWER_PLATE = 32, //

		GME_FRV_NEWER = 41, //F_F
		GME_FRV_ELDER = 42, //
	}GME_FEATURE_RELATION_VALUE;


	typedef enum GME_GEO_DIP_TYPE //倾角类型
	{
		GME_GDT_REAL_DIP = 1,		//真倾角
		GME_GDT_REAL_APPARENT = 2,	//视倾角
	}GME_GEO_DIP_TYPE;

	typedef enum GME_NOTE_DISP_TYPE //注记显示方式
	{
		GME_NDT_RALETIVE_TO_GROUND = 1, //相对于地面
		GME_NDT_ABSOLUTE = 2,			//独立
	}GME_NOTE_DISP_TYPE;











	// ---------------------- 与场景可视化相关的enum定义 -------------------- //
	typedef		long				GME_SCENE_TEXIDXNO;
	//纹理通道
	typedef enum GME_TEXTURE_STAGE
	{
		GME_TSN_1 = 0,	    //第1纹理通道
		GME_TSN_2 = 1, 		//第2纹理通道
		GME_TSN_3 = 2,		//第3纹理通道
		GME_TSN_4 = 3,		//第4纹理通道
		GME_TSN_5 = 4,		//第5纹理通道
		GME_TSN_6 = 5,		//第6纹理通道
		GME_TSN_7 = 6,		//第7纹理通道
		GME_TSN_8 = 7,		//第8纹理通道
	}GME_TEXTURE_STAGE;

	//光照通道
	typedef enum GME_LIGHT_STAGE
	{
		GME_LSN_1 = 0,	    //第1光照通道
		GME_LSN_2 = 1, 		//第2光照通道
		GME_LSN_3 = 2,		//第3光照通道
		GME_LSN_4 = 3,		//第4光照通道
		GME_LSN_5 = 4,		//第5光照通道
		GME_LSN_6 = 5,		//第6光照通道
		GME_LSN_7 = 6,		//第7光照通道
		GME_LSN_8 = 7,		//第8光照通道
	}GME_LIGHT_STAGE;

	//参数类型
	typedef enum GME_ENUM_PARAM_TYPE
	{
		GME_PARAM_TYPE_SYS = 1,//系统参数
		GME_PARAM_TYPE_USER = 2,//用户参数
		GME_PARAM_TYPE_DYNAMIC = 3,//动态参数
	}GME_ENUM_PARAM_TYPE;

	typedef enum GME_ENGINE_TYPE //绘制引擎类型
	{
		GME_ET_NONE = -1,	//无
		GME_ET_OSG = 1,		//OSG引擎
		GME_ET_OPENGL = 2,	//OpenGL引擎
		GME_ET_D3D = 3,		//D3D引擎
	}GME_ENGINE_TYPE;

	typedef enum GME_SCENE_COORD_TYPE
	{
		//坐标系类型定义
		GME_COORDTYPE_RH_XUP = 1,//x轴朝上的右手坐标系
		GME_COORDTYPE_RH_YUP = 2,//y轴朝上的右手坐标系
		GME_COORDTYPE_RH_ZUP = 3,//z轴朝上的右手坐标系(OpenGL\OSG默认)
		GME_COORDTYPE_LH_XUP = 4,//x轴朝上的左手坐标系
		GME_COORDTYPE_LH_YUP = 5,//y轴朝上的左手坐标系
		GME_COORDTYPE_LH_ZUP = 6,//z轴朝上的左手坐标系(D3D默认)
	}GME_SCENE_COORD_TYPE;

	typedef enum GME_RANK_TYPE
	{
		// 阶次类型
		GME_RANK_0 = 0,		//0阶次
		GME_RANK_1 = 1,		//1阶次
		GME_RANK_2 = 2,		//2阶次
	}GME_RANK_TYPE;

	typedef enum GME_ENABLE_VAR //开关控制量
	{
		GME_FOG = 1,		//雾
		GME_LIGHTING = 2,	//光照
		GME_TEXTURE_2D = 3,	//2D纹理
		GME_CULL_FACE = 4,	//反面三角形裁剪
		GME_ALPHA_TEST = 5,	//Alpha测试
		GME_BLEND = 6,			//融合
		GME_DITHER = 7,			//抖动
		GME_STENCIL_TEST = 8,	//模板测试
		GME_DEPTH_TEST = 9,		//深度测试
		GME_SCISSOR_TEST = 10,	//采集框测试
		GME_COLOR_MATERIAL = 11,//材质颜色跟踪当前颜色
		GME_STEREO = 12,		//立体模式
		GME_DETAIL_TEXTURE = 13,//细节纹理
	}GME_ENABLE_VAR;

	//测试函数类型
	typedef enum GME_TEST_FUNC
	{
		GME_NEVER = 1,	//不通过
		GME_LESS = 2,	//小于则通过
		GME_EQUAL = 3,	//等于则通过
		GME_LEQUAL = 4,	//小于等于则通过
		GME_GREATER = 5,	//大于则通过
		GME_NOTEQUAL = 6,	//不等则通过
		GME_GEQUAL = 7,	//大于等于则通过
		GME_ALWAYS = 8,	//总是通过
	}GME_TEST_FUNC;


	typedef enum GME_VERTEX_FORMAT //顶点缓冲区格式
	{
		//OpenGL格式.
		GME_VF_GL_MAP_FORMAT_V2F = 1,				//GL_V2F
		GME_VF_GL_MAP_FORMAT_V3F = 2,				//GL_V3F
		GME_VF_GL_MAP_FORMAT_C3F_V3F = 3,			//GL_C3F_V3F
		GME_VF_GL_MAP_FORMAT_N3F_V3F = 4,			//GL_N3F_V3F
		GME_VF_GL_MAP_FORMAT_C4F_N3F_V3F = 5,		//GL_C4F_N3F_V3F
		GME_VF_GL_TEX_FORMAT_T2F_V3F = 6,			//GL_T2F_V3F
		GME_VF_GL_TEX_FORMAT_T4F_V4F = 7,			//GL_T4F_V4F
		GME_VF_GL_TEX_FORMAT_T2F_C3F_V3F = 8,		//GL_T2F_C3F_V3F
		GME_VF_GL_TEX_FORMAT_T2F_N3F_V3F = 9,		//GL_T2F_N3F_V3F
		GME_VF_GL_TEX_FORMAT_T2F_C4F_N3F_V3F = 10,	//GL_T2F_C4F_N3F_V3F
		GME_VF_GL_TEX_FORMAT_T4F_C4F_N3F_V4F = 11,	//GL_T4F_C4F_N3F_V4F

		//D3D格式.		  
		GME_VF_D3D_XYZ = 12,
		GME_VF_D3D_XYZ_DIFFUSE = 13,
		GME_VF_D3D_XYZ_NORMAL = 14,
		GME_VF_D3D_XYZ_NORMAL_DIFFUSE = 15,
		GME_VF_D3D_XYZ_NORMAL_DIFFUSE_SPECULAR = 16,
		GME_VF_D3D_XYZ_TEX1 = 17,
		GME_VF_D3D_XYZ_DIFFUSE_TEX1 = 18,
		GME_VF_D3D_XYZ_NORMAL_TEX1 = 19,
		GME_VF_D3D_XYZ_NORMAL_DIFFUSE_TEX1 = 20,
	}GME_VERTEX_FORMAT;

	typedef enum GME_TEXTURE_FORMAT //纹理像素格式
	{
		GME_PF_RGB8 = 1,//OpenGL.  3 Bytes.
		GME_PF_RGB5_A1 = 2,//OpenGL.  2 Bytes.
		GME_PF_RGBA8 = 3,//OpenGL.  4 Bytes.
		GME_PF_RGB_ARB = 4,//OpenGL压缩格式(24位).
		GME_PF_RGBA_ARB = 5,//OpenGL压缩格式(32位).

		GME_PF_R5G6B5 = 6,//D3D格式. 2 Bytes.
		GME_PF_A1_RGB5 = 7,//D3D格式. 2 Bytes.
		GME_PF_BGRA8 = 8,//D3D格式. 4 Bytes.
		GME_PF_ARGB8 = 9,//D3D格式. 4 Bytes.
		GME_PF_XRGB8 = 10,//D3D格式. 4 Bytes.
		GME_PF_DXT1_24 = 11,	//纹理压缩格式DXT1
		GME_PF_DXT1_32 = 12,	//纹理压缩格式DXT1
		GME_PF_DXT2 = 13,	//纹理压缩格式DXT2
		GME_PF_DXT3 = 14,	//纹理压缩格式DXT3
		GME_PF_DXT4 = 15,	//纹理压缩格式DXT4
		GME_PF_DXT5 = 16,	//纹理压缩格式DXT5
	}GME_TEXTURE_FORMAT;

	typedef enum GME_FOG_TYPE
	{	//雾的种类
		GME_FT_VERTEX_FOG = 1, //顶点雾
		GME_FT_PIXEL_FOG = 2,  //像素雾
	}GME_FOG_TYPE;
	typedef enum GME_FOG_MODE
	{	//雾的模式	
		GME_EXP = 1, //二次
		GME_EXP2 = 2, //三次
		GME_LINEAR = 3, //线形
	}GME_FOG_MODE;

	typedef enum GME_LIGHT_TYPE //光源类型
	{
		GME_LIGHT_POINT = 1,		//点光源
		GME_LIGHT_DIRECTIONAL = 2,	//方向光源
		GME_LIGHT_SPOT = 2,			//聚光灯（手电）
	}GME_LIGHT_TYPE;

	typedef enum GME_LIGHTING_DIR //光照方法
	{
		GME_LD_FRONT = 1,			//正面光照
		GME_LD_BACK = 2,			//背面光照
		GME_LD_FRONT_AND_BACK = 3, //双面光照
	}GME_LIGHTING_DIR;

	typedef enum GME_LIGHT_MODEL //光照模型
	{
		GME_LM_LAMBERT = 1,
		GME_LM_PHONE = 2,
		GME_LM_OTHERS = 3,
	}GME_LIGHT_MODEL;

	typedef enum GME_FILL_MODE//填充模式
	{
		GME_FILL_POINT = 1,		//点方式
		GME_FILL_WIREFRAME = 2,	//线方式
		GME_FILL_SOLID = 3,		//面方式
		GME_FILL_LIN_SOLID = 4, //线+面方式
		GME_FILL_PNT_LIN = 5, //点+线方式
		GME_FILL_PNT_SOLID = 6, //点+面方式
	}GME_FILL_MODE;

	typedef enum GME_CULL_MODE//反面拈选模式
	{
		GME_CULL_NONE = 1,	//无
		GME_CULL_CW = 2,	//顺时针
		GME_CULL_CCW = 3,	//逆时针
	}GME_CULLMODE;

	typedef enum GME_DRAW_TYPE //绘制图元类型
	{
		GME_DT_POINTS = 1,	//绘制点
		GME_DT_LINES = 2,		//绘制线段
		GME_DT_LINES_STRIP = 3,//绘制线段
		GME_DT_LINES_LOOP = 4,//绘制线环
		GME_DT_TRIANGLE = 5,	//绘制三角形
		GME_DT_TRIANGLE_STRIP = 6,//绘制三角形条带
		GME_DT_TRIANGLE_FAN = 7,//绘制三角形扇
		GME_DT_QUADS = 8,		//绘制四边形
		GME_DT_QUAD_STRIP = 9,	//绘制四边形带
		GME_DT_POLYGON = 10,	//绘制多边形
	}GME_DRAW_TYPE;

	typedef enum GME_SHADE_MODEL //着色处理模式
	{
		GME_SM_FLAT = 1,		//平坦处理模式
		GME_SM_SMOOTH = 2,		//光滑处理模式
	}GME_SHADE_MODEL;

	typedef enum GME_RENDERING_MODE //绘制模式
	{
		GME_RM_RENDER = 1,	//绘制
		GME_RM_FEEDBACK = 2,//反馈
		GME_RM_SELECT = 3,	//拾取
	}GME_RENDERING_MODE;

	typedef enum GME_TEXTUREENV_MODE	//纹理环境模式
	{
		GME_TM_MODULATE = 1,//调制模式
		GME_TM_DECAL = 2,	//贴图
	}GME_TEXTUREENVMODE;
	typedef enum GME_TEXTUREGENMODE	//纹理坐标生成模式
	{
		GME_EYE_LINEAR = 1,	//
		GME_OBJECT_LINEAR = 2,//
		GME_SPHERE_MAP = 3,	//
	}GME_TEXTUREGENMODE;
	typedef enum GME_TEXTURE_FILTER		//纹理纹理过滤操作类型
	{
		GME_NEAREST_FILTER = 1,	//最近模式
		GME_LINEAR_FILTER = 2,	//线形模式
		GME_ANISOTROPIC_FILTER = 3,  // 各向异性模式
		GME_FLATCUBIC_FILTER = 4,    // cubic
		GME_GAUSSIANCUBIC_FILTER = 5,// different cubic kernel
	}GME_TEXTURE_FILTER;
	typedef enum GME_TEXTURE_WRAPMODE	//纹理缠绕模式
	{
		GME_CLAMP = 1,	// 紧缩
		GME_REPEAT = 2,	// 重复		   
		GME_MIRROR = 3,	// 镜像重复
		GME_BORDER = 4,	// 边框颜色延展
		GME_MIRRORONCE = 5,	//
	}GME_TEXTURE_WRAPMODE;

	typedef enum GME_BLEND_FACTOR	//融合因子
	{
		GME_ZERO = 1,
		GME_ONE = 2,
		GME_SRC_COLOR = 3,
		GME_ONE_MINUS_SRC_COLOR = 4,	  // OpenGL
		GME_SRC_ALPHA = 5,
		GME_ONE_MINUS_SRC_ALPHA = 6,	  // OpenGL
		GME_DST_ALPHA = 7,
		GME_ONE_MINUS_DST_ALPHA = 8,	  // OpenGL

		GME_INV_SRC_COLOR = 9,	  // D3D
		GME_INV_SRC_ALPHA = 10,	  // D3D
		GME_INV_DST_ALPHA = 11,	  // D3D
		GME_DST_COLOR = 12,	  // D3D
		GME_INV_DST_COLOR = 13,	  // D3D
		GME_SRC_ALPHA_SAT = 14,	  // D3D
		GME_BOTH_SRC_ALPHA = 15,	  // D3D
		GME_BOTH_INV_SRC_ALPHA = 16,	  // D3D
	}GME_BLEND_FACTOR;

	typedef enum GME_ANTI_ALIASING	//抗锯齿类型
	{
		// OpenGL
		GME_POINT_SMOOTH = 1,		//点光滑
		GME_LINE_SMOOTH = 2,		//线光滑
		GME_POLYGON_SMOOTH = 3,		//多边形光滑
		// D3D
		GME_EDGE_ANTIALIASING = 4,		//边缘反走样
		GME_FULLSCREEN_ANTIALIASING = 5,//全屏反走样

	}GME_ANTI_ALIASING;


	typedef enum GME_FONT_DRAW_TYPE	//字体绘制类型
	{
		GME_2D_FONT = 1,		//二维字体
		GME_3D_FONT = 2,		//三维字体
		GME_2D_VIEWSCALE_FONT = 3,//二维视口缩放字体
	}GME_FONT_DRAW_TYPE;

	typedef enum GME_SUPPORT_FILE_TYPE //系统支持的文件类型
	{
		GME_BMP = 1,
		GME_TIF = 2,
		GME_JPG = 3,
		GME_MSI = 4,
		GME_DDS = 5,
		GME_AVI = 6,
		GME_MPEG = 7,
		GME_HIS = 8,
		GME_PAT = 9,
		GME_TGA = 10,
	}GME_SUPPORT_FILE_TYPE;


	typedef enum GME_RENDER_BUFFER //系统支持的渲染缓冲
	{
		GME_RENDER_LEFT = 0,
		GME_RENDER_RIGHT = 1,
	}GME_RENDER_BUFFER;


	typedef enum GME_HINT_TARGET	//进行绘制控制提示的目标类型
	{
		GME_FOG_HINT = 1,	// 雾化计算操作的精确性
		GME_POINT_SMOOTH_HINT = 2,	// 线的反走样采样质量
		GME_LINE_SMOOTH_HINT = 3,	// 颜色和纹理坐标的插值的质量
		GME_POLYGON_SMOOTH_HINT = 4,	// 点的反走样采样质量
		GME_PERSPECTIVE_CORRECTION_HINT = 5,	// 多边形的反走样采样质量
	}GME_HINT_TARGET;

	typedef enum GME_HINT_MODE	// 进行绘制控制提示的目标行为
	{
		GME_FASTEST = 1,	// 绘图速度和效率优先
		GME_NICEST = 2,		// 选择最正确
		GME_DONT_CARE = 3,	// 不优先选择
	}GME_HINT_MODE;

}

#endif