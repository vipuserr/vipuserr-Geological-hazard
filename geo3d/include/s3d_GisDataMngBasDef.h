#pragma once

namespace Smart3dMap
{

	#define  EXTENT_BUFSIZE    512 //数据库的字节大小


		//=======================基本参数及结构定义===========================//
	#define	LIN		0x0000
	#define	PNT		0x0001
	#define	REG		0x0002
	#define	NOD		0x0003
	#define	NET		0x0004
	#define	ARC		0x0005
	#define	SEG		0x0006
	#define	TBL		0x0007
	#define	DBSTBL	0x0008
	#define	PRJ		0x0009
	#define	PATH	0x000A
	#define	MSIIMG	0x000B	  /*MSI图像文件*/
	#define	PUB		0x000C	  /*拚版文件*/


	//MapGis消息MapGisMessage:
	#define MGM_REDISPGRAPH	    (WM_USER+0x200)
	#define MGM_FLASH_GRAPH	    (WM_USER+0x201)
	#define MGM_LOCKRECORD	    (WM_USER+0x202)
	#define MGM_UPDATERCD	    (WM_USER+0x203) //更新当前记录显示
	#define MGM_DESTROY_WND     (WM_USER+0x204) /*撤消指定窗口窗口  wParam=hWnd*/
	#define MGM_DISPLAY_RCD     (WM_USER+0x205) /*显示某一个记录 lParam=*/


	#define  PI 			3.14159265358979323846
	#define  MIN_FLOAT		(-3.402823E+38)
	#define  ZERO_FLOAT		(+1.401298E-45)
	#define  MAX_FLOAT		(+3.402823E+38)

	#ifndef MIN_DOUBLE
	#define  MIN_DOUBLE	       (-1.797693134862E+307)
	#endif

	#ifndef MAX_DOUBLE
	#define  MAX_DOUBLE	       (+1.797693134862E+307)
	#endif

	#define  ZERO_MIN_DBL   (-4.94065645841247E-324)
	#define  ZERO_MAX_DBL   (+4.94065645841247E-324)
	#define  MIN_VALUE		(+1.000000E-20)		    //绝对值小于此值即认为=0


	#define  MIN_INT		-32768
	#define  MAX_INT		+32767

	#define  MIN_LONG		-2147483648
	#define  MAX_LONG       +2147483647

	#define  MAX_LAYNUM	     2048		/*最大层数，6.2版以前是256*/
	#define  SIZE_OF_LAYERPAD    (MAX_LAYNUM/8)	/*层板字节长度，每层一位*/
	#define  MAX_LAYER_NO	     (MAX_LAYNUM-1)  	/*最大层编号*/

	#define  ALIAS_LEN			32			/*文件别名长度*/
	#define  LAYER_NAME_LEN	    11			/*图层名长度*/


	#ifndef __MAPGIS_VERSION__
	#define __MAPGIS_VERSION__
	#define  VERSION_dos  0x3035		//dos版 版本号
	#define  VERSION4x 	0x3036		//win16版,4.0,4.1,4.2
	#define  VERSION50	0x4405		//win16版5.0  w32版5.32
	#define  VERSION60	0x4460		//新版本6.0版
	#define  VERSION70	0x4470		//新版本7.0版
	#define  VERSION80	0x4480		//新版本8.0版
	#define  VERSION81	0x4481		//新版本8.1版
	#define  VERSION82	0x4482		//新版本8.2版  USB版
	#define  VERSION83	0x4483		//新版本8.3版，USB版 6.6 2004版
	#endif


	#define  VERSION 	VERSION60	//当前版本号是6.0版

		typedef short       AREA_HINST;

		//矩形框
		typedef struct
		{
			float xmin; //leo 注意顺序
			float xmax;
			float ymin;
			float ymax;
		}F_RECT;

		typedef struct
		{
			double xmin; //leo 注意顺序
			double xmax;
			double ymin;
			double ymax;
		}D_RECT;

		//窗口参数
		typedef struct
		{
			double  x0, y0;  //视口左下角(原点)
			D_RECT  frc;    //显示范围
			double  r;      //显示比例
		}WIN_ORG;


		//点数据类型定义
	#define		PNT_TYPE_NUM	6	/*点类型数*/
	#define		PNT_NOTE	0
	#define		PNT_SUB		1
	#define		PNT_CIR		2
	#define		PNT_ARC		3
	#define		PNT_IMAGE	4
	#define		PNT_TEXT	5
	//点类型实体图形信息结构
		typedef struct PNT_INFOstruct
		{
			char  type;     //点类型
			char  ovprnt;	//覆盖方式
			union
			{
				struct
				{
					float  height;	//高度
					float  width;   //宽度
					float  space;   //间隔
					float  angle;   //字符串角度，以360度制为单位表示
					short  ifnt;    //中文字体
					short  chnt;	//西文字体
					char   ifnx;	//字形
					char   hvpl;	//水平或垂直排列0=水平排列 1=垂直排列
				}ch;
				struct
				{
					float  height;	//
					float  width;   //
					float  space;   //字间距(横向间距)
					float  angle;   //以360度制度为单位表示
					short  ifnt;    //中文字体
					short  chnt;	//西文字体
					char   ifnx;    //字形
					float  lspace;	//行间距(纵向间距)
					float  dx, dy;	//版面长和宽
					char   hvpl;	//水平或垂直排列0=水平排列 1=垂直排列
				}text;
				struct
				{
					long  subno;	//子图号
					float height;   //高度
					float width;    //宽度
					float angle;    //角度
					float penw;     //线宽(未用,6.0以前为short)
					long  fclr;	//辅助色(未用)  [short-->long]
				}sub;
				struct
				{
					double radiu;	//radiu>0, <=0为非法  [float-->double]
					long   lcol;    //边线颜色，填充色为icol [short-->long]
					float  penw;	//线宽(6.0以前为short)
					char   fflag;	//4.1版开始 1=填充圆 0=空心圆
				}circle;
				struct
				{
					double radiu;    //radiu>0, <=0为非法  [float-->double]
					float  begang;	//起始角度
					float  endang;	//终止角度
					float  penw;	//线宽度(6.0以前为short)
				}arc;
				struct
				{
					double width;	//  [float-->double]
					double height;	//  [float-->double]
					float  angle;	//角度(未用)
				}image;
			}info;
			float	 infoDx;    //	[new, 点参数偏移dx]
			float	 infoDy;    //  [new, 点参数偏移dy]
			long     iclr;	    //  [short-->long]
			long     linNo;	    //点所属的线号
			short    layer;     //图层
			long     res0;	    //保留, 必须赋0
			long     res1;	    //保留, 必须赋0		
			D_RECT   rect;	    //点元范围
		}PNT_INFO;

		//点参数字段开关
		typedef struct PNT_PADstruct
		{
			char type;       //点类型
			char ovprnt;	//覆盖方式
			union
			{
				struct
				{
					char height;
					char width;
					char space;
					char angle;
					char ifnt;
					char chnt;
					char ifnx;
					char hvpl;	//水平或垂直排列0=水平排列 1=垂直排列
				}ch;
				struct
				{
					char height;	//
					char width;    //
					char space;    //字间距
					char angle;    //以360度制度为单位表示
					char ifnt;    //
					char chnt;	//
					char ifnx;
					char lspace;	//行间距
					char dx;	//版面长和宽
					char dy;
					char hvpl;	//水平或垂直排列0=水平排列 1=垂直排列
				}text;
				struct
				{
					char subno;
					char height;
					char width;
					char angle;
					char penw;
					char fclr;	//辅助色
				}sub;
				struct
				{
					char radiu;  //97.1版之前 radiu<0为空心原 >0为实心圆
					char lcol;  //边线颜色
					char penw;
					char fflag;  //97.1版开始 1=填充 0=不填充
				} circle;
				struct
				{
					char radiu;
					char begang;
					char endang;
					char penw;
				}arc;
				struct
				{
					char width;
					char height;
					char angle;
				}image;
			}info;
			char infoDx;    //  [new, 点参数偏移dx]
			char infoDy;    //  [new, 点参数偏移dy]
			char iclr;
			char linNo;
			char layer;
			char res0;	    //保留, 必须赋0
			char res1;	    //保留, 必须赋0
			char rect;
		}PNT_PAD;

		typedef union PNT_INFO_UNIONunion
		{
			struct
			{
				float  height;	//高度
				float  width;   //宽度
				float  space;   //间隔
				float  angle;   //字符串角度，以360度制为单位表示
				short  ifnt;    //中文字体
				short  chnt;	//西文字体
				char   ifnx;	//字形
				char   hvpl;	//水平或垂直排列0=水平排列 1=垂直排列
			}ch;
			struct
			{
				float  height;	//
				float  width;   //
				float  space;   //字间距(横向间距)
				float  angle;   //以360度制度为单位表示
				short  ifnt;    //中文字体
				short  chnt;	//西文字体
				char   ifnx;    //字形
				float  lspace;	//行间距(纵向间距)
				float  dx, dy;	//版面长和宽
				char   hvpl;	//水平或垂直排列0=水平排列 1=垂直排列
			}text;
			struct
			{
				long  subno;	//子图号
				float height;   //高度
				float width;    //宽度
				float angle;    //角度
				float penw;     //线宽(未用)
				long  fclr;	//辅助色(未用)  [short-->long]
			}sub;
			struct
			{
				double radiu;	//radiu>0, <=0为非法  [float-->double]
				long   lcol;    //边线颜色，填充色为icol [short-->long]
				float  penw;	//线宽
				char   fflag;	//4.1版开始 1=填充圆 0=空心圆
			}circle;
			struct
			{
				double radiu;    //radiu>0, <=0为非法  [float-->double]
				float  begang;	//起始角度
				float  endang;	//终止角度
				float  penw;	//线宽
			}arc;
			struct
			{
				double width;	//  [float-->double]
				double height;	//  [float-->double]
				float  angle;	//角度(未用)
			}image;
		}PNT_INFO_UNION;
	#define PNT_INFO_UNION_LEN  (sizeof(PNT_INFO_UNION))
	#define PNT_IU_LEN	    (sizeof(PNT_INFO_UNION))


		//线类型实体图形信息结构
		typedef struct LIN_INFOstruct
		{
			short   ltp;		//线型号
			char    fltp;           //辅助线型号
			char    ovprnt;		//覆盖方式
			long    lclr;           //线颜色号  [short-->long]
			float   lw;             //线宽(6.0以前为char)
			char    lclass;		//线种类，0=折线、1=贝塞尔曲线
			float   xscale;		//X系数
			float   yscale;         //Y系数
			long    fclr;		//辅助色  [short-->long]
			short   layer;          //图层
			long    res0;		//保留, 必须赋0
			long    res1;		//保留, 必须赋0
			D_RECT  rect;		//线元范围
		}LIN_INFO;

		//线参数字段开关
		typedef struct LIN_PADstruct
		{
			char ltp;
			char fltp;
			char ovprnt;	//覆盖方式
			char lclr;
			char lw;
			char lclass;
			char xscale;
			char yscale;
			char fclr;
			char layer;    //图层
			char res0;	    //保留, 必须赋0
			char res1;	    //保留, 必须赋0
			char rect;
		}LIN_PAD;

		//线类型实体拓扑结构
		typedef struct LIN_TOPstruct
		{
			long   stNod;    //起始结点
			long   endNod;   //终止结点
			long   lPoly;    //弧段左多边形, 网段所属网号
			long   rPoly;    //弧段右多边形, 对于网络数据, rPoly无效, 设为0.
			float  lWeigh;   //左权
			float  rWeigh;   //右权
		}LIN_TOP;

		//网络弧段分配信息
		typedef struct
		{
			float   demand;	     //需求
			float   demandMeet;    //被满足的需求
			long    allocCenter;   //分配中心(是一个NOD_CENTER类型结点)
			float   cumuImped;     //累积阻碍
			long    preArc;        //前一弧段
			char    allocDirect;   //分配方向
		} ARC_ALLOC_INFO;


		//区类型实体图形信息结构
		typedef struct REG_INFOstruct
		{
			long    clr;	  //区域填充色  [short-->long]
			short   patno;	  //
			float   pathei;	  //
			float   patwid;	  //
			long    patclr;	  //  [short-->long]
			short   basLN;	  //5.32版以前未用，必须=0；5.32版开始作为构成斜坡基线的弧段数。
			char    fmode;	  //覆盖方式
			short   layer;    //图层
			long    res0;	  //保留, 必须赋0
			long    res1;	  //保留, 必须赋0
			D_RECT  rect;	  //区域范围
		}REG_INFO;

		//区参数字段开关
		typedef struct REG_PADstruct
		{
			char clr;
			char patno;
			char pathei;
			char patwid;
			char patclr;
			char basLN;
			char fmode;
			char layer;
			char res0;	    //保留, 必须赋0
			char res1;	    //保留, 必须赋0
			char rect;
		}REG_PAD;


		//网络类型实体图形信息结构
		typedef struct NET_INFOstruct
		{
			short   ltp;		//线型号
			char    fltp;           //辅助线型号
			char    ovprnt;		//覆盖方式
			long    lclr;           //颜色号  [short-->long]
			float   lw;             //线宽(6.0以前为char)
			char    lclass;		//线种类，0=折线、1=贝塞尔曲线
			float   xscale;		//X系数
			float   yscale;         //Y系数
			long    fclr;		//辅助色  [short-->long]
			short   layer;          //图层
			long    res0;		//保留, 必须赋0
			long    res1;		//保留, 必须赋0
			D_RECT  rect;		//网络范围
		}NET_INFO;
		//网络参数字段开关
		typedef struct NET_PADstruct
		{
			char ltp;	//线型号
			char fltp;    //辅助线型号
			char ovprnt;	//覆盖方式
			char lclr;    //颜色号
			char lw;    //线宽
			char lclass;
			char xscale;	//X系数
			char yscale;    //Y系数
			char fclr;	//辅助色
			char layer;    //图层
			char res0;	//保留, 必须赋0
			char res1;	//保留, 必须赋0
			char rect;	//网络范围
		}NET_PAD;


		//网络中心结点信息
		typedef struct
		{
			float   limit;	//限度
			float   delay;      //延迟
			float   maximped;   //最大阻抗
			float   averimped;  //平均阻抗
			float   capacity;   //容量
			float   perccap;    //容量分配百分比
			LIN_INFO linf;	//线信息
		}NOD_CENTER_INFO;

		//网络终止结点信息
		typedef struct
		{
			float demand;	//需求
		}NOD_STOP_INFO;

		//网络障碍结点信息
		typedef struct
		{
			long res;
		}NOD_BARRIER_INFO;

		//中心，终点，阻碍信息结构
		typedef struct
		{
			unsigned char cOK : 1;	//有中心信息标志
			unsigned char sOK : 1;	//有终点信息标志
			unsigned char bOK : 1;    //有阻碍信息标志
			unsigned char res : 5;
			NOD_CENTER_INFO  cInf;	//中心信息
			NOD_STOP_INFO    sInf;  //终点信息
			NOD_BARRIER_INFO bInf;  //阻碍信息
		}CSB_INF_STRU;

		/*取结点
			入口: ai    - 工作区编号
			  ni    - 结点编号
			  *xy   - 返回点位置
			  **dat - 返回结点数据
			  *len  - 返回结点数据项数
			返回: >0成功, =0失败 <0已被删除 。返回值!=0时为下列宏定义之一：*/
	#define NOD_COMM	0x0001	/*普通结点*/
	#define NOD_GRAPH	0x0002	/*图形结点*/
	#define NOD_LINK	0x0004	/*连通矩阵*/
	#define NOD_CENTER	0x0008	/*网络中心*/
	#define NOD_STOP	0x0010	/*网络站点*/
	#define NOD_BARRIER	0x0020	/*网络阻碍*/
	#define NOD_TURNANG	0x0040	/*转角巨阵*/

			//数值型联合
	#define BIT_TYPE	0

	//图元实体信息结构
		typedef struct
		{
			short ai;      //工作区
			short type;    //图元类型
			long  elmi;    //图元号
		}ENTITY_MSG;

		//图元重新显示信息结构
		typedef ENTITY_MSG MGMSG;
		typedef MGMSG    * LPMGMSG;

		//显示某一个属性记录信息结构，MGM_DISPLAY_RCD消息的lParam传递
		typedef struct
		{
			short ai;	//工作区
			short aType;	//属性类型
			long  rcdI;  //记录号
		} DISP_RCD_MSG;
		typedef DISP_RCD_MSG FAR * LPDISP_RCD_MSG;

	#define  FLD_NAME_LEN 	     20			/*字段名长度*/
	#define  DBIMAXNAMELEN	     31
		typedef struct DATE_STRUstruct
		{
			short  year;	//年
			char   mon;	//月
			char   day;	//日
		}DATE_STRU;
		typedef struct TIME_STRUstruct
		{
			char   hour;	//时
			char   min;	//分
			double sec;	//秒
		}TIME_STRU;

		typedef struct TIMESTAMPstruct
		{
			short year;
			short month;
			short day;
			short hour;
			short minute;
			short second;
			long  fraction;
		}TIMESTAMP_STRU;

	#define BOOL_STRU	char


		//属性数据域类型定义,0--8,0x10,0x11是常规类型，9--0xF,0x12是扩展类型
	#define DATA_TYPE_NUM	19
	#define STR_TYPE	0x0
	#define BYTE_TYPE	0x1
	#define SHORT_TYPE	0x2
	#define LONG_TYPE	0x3
	#define FLOAT_TYPE	0x4
	#define DOUBLE_TYPE	0x5
	#define DATE_TYPE	0x6
	#define TIME_TYPE	0x7
	#define BOOL_TYPE	0x8

	#define TEXT_TYPE	0x9
	#define PICTURE_TYPE	0xA
	#define MAP_TYPE	0xB
	#define SOUND_TYPE	0xC
	#define VIDEO_TYPE	0xD
	#define EXT_TYPE	0xE
	#define BIN_DATA_TYPE   0xF
	#define TIMESTAMP_TYPE  0x10
	#define NUMBERIC_TYPE   0x11
	#define TABLE_TYPE      0x12


	//扩展属性
	//数据类型:
	#define	EAL_LIN		LIN
	#define	EAL_PNT		PNT
	#define	EAL_REG		REG
	#define	EAL_NET		NET
	#define	EAL_TBL		TBL
	#define	EAL_DBSTBL	DBSTBL
	#define	EAL_BMP		0x10
	#define	EAL_PCX		0x11
	#define	EAL_TIF		0x12
	#define	EAL_GIF		0x13
	#define	EAL_WAVE	0x14
	#define	EAL_MIDI	0x15
	#define	EAL_AVI		0x16
	#define	EAL_FLI		0x17
	#define	EAL_FLC		0x18
		short _GetFieldTypeName(short fieldtype, char *szName, short len);
		//扩充类型字段内容为如下结构：
		typedef struct EXT_STRUstruct
		{
			char   type;	  //字段类型 TEXT_TYPE/PICTURE_TYPE/MAP_TYPE/SOUND_TYPE/VIDEO_TYPE
			char   dtype;	  //数据类型 EAL_LIN ... EAL_FLC
			char   fName[254];//多媒体数据文件名
		}EXT_STRU;

		//扩充二进制数据类型字段内容为如下结构：
		typedef struct
		{
			long   len;	 //字段字节数
			long   off;	 //字段内容位置
		}BIN_DATA_STRU;

		//外挂数据库信息
		typedef struct
		{
			short keyFldType;			//外挂数据库关键字段类型
			char  keyFldName[DBIMAXNAMELEN + 1];	//外挂数据库关键字段名称
			char  dbsFName[144];	      	//外挂数据库关键字段所在数据库
		} EXT_LINK_DB_INFO;

		/*外挂数据库关键字段内容为如下结构：
			{
			  1.对应的常规字段内容，如LONG_KEY_TYPE字段对应的常规字段是LONG_TYPE字段，
			这部分占LONG_LEN个字节，保存关键字段值
			  2.short dbNo;  --外挂数据库编号，对应于_SetExtDbLinkInfo函数的返回值
			}
		*/

		typedef struct
		{
			char   fieldname[FLD_NAME_LEN + 1];	//字段名称
		}FIELD_NAME_STR;

		typedef struct
		{
			char clib[128];	//汉字库目录
			char sys[128];	//系统目录
			char cur[128];	//当前工作目录
			char temp[128];	//临时工作目录（工作区使用）
			char slib[128];	//系统库目录
		}GISENV;

		typedef struct
		{
			short x;
			short y;
		}I_DOT;

		typedef struct
		{
			float x;
			float y;
		}F_DOT;
		typedef struct
		{
			double x;
			double y;
		}D_DOT;

		typedef struct
		{
			long x;
			long y;
		}L_DOT;

		typedef struct
		{
			short x;
			short y;
			short z;
		}I_3DOT;

		typedef struct
		{
			float x;
			float y;
			float z;
		}F_3DOT;

		typedef struct
		{
			double x;
			double y;
			double z;
		}D_3DOT;

		typedef struct
		{
			long x;
			long y;
			long z;
		}L_3DOT;


	#define TRAN_NULL		0	//空变换,(不变换)
	#define TRAN_MOVE		1   //平移
	#define TRAN_ROTATE		2	//旋转
	#define TRAN_ENLARGE	3	//缩放
		//  图形变换参数结构
		typedef struct TRAN_PARstruct
		{
			char type[3];	//变换类型及变换顺序,即按type[0]-->type[1]-->type[2]的顺序变换
			char res[5];	//未用,保留
			struct
			{
				double dx;
				double dy;
			}move;
			struct
			{
				double ang;	//360度制度为单位表示
			}rotate;
			struct
			{
				double rx;
				double ry;
			}enlarge;
		}TRAN_PAR;

		//地图参数:
		//1、坐标系类型(MAP_PARA结构的type字段值)
	#define TYPE_NOPAR  0	/*用户自定义坐标系*/
	#define	TYPE_JWD    1	/*地理坐标系*/
	#define TYPE_DD	    2	/*大地坐标系*/
	#define TYPE_PRJ    3	/*投影平面直角坐标系*/
	#define TYPE_XYZ    4	/*地心大地直角坐标系*/


	//2、坐标单位(MAP_PARA结构的unit字段值)
	//2.1 长度单位
	#define UNIT_MM	        0x00   //毫米
	#define UNIT_MilliMeter 0x01   //毫米
	#define UNIT_Meter      0x02   //米
	#define UNIT_Second     0x03   //秒
	#define UNIT_Degree     0x04   //度
	#define UNIT_DMS        0x05   //度分秒,即±DDDMMSS.SSSS格式
	#define UNIT_Foot       0x06   //英尺
	#define UNIT_Minute     0x07   //分(60分之一度)
	#define UNIT_Radian     0x08   //弧度
	#define UNIT_GRAD       0x09   //梯度   1梯度=0.015707963267949弧度

	#define UNIT_KM         0x0A   //公里
	#define UNIT_KiloMeter  0x0A   //公里
	#define UNIT_DM         0x0B   //分米
	#define UNIT_DeciMeter  0x0B   //分米
	#define UNIT_CM         0x0C   //厘米
	#define UNIT_CentiMeter 0x0C   //厘米

	#define UNIT_Inch       0x0D  //英寸
	#define UNIT_Yard       0x0E  //码
	#define UNIT_SeaMile    0x0F  //海里 
	#define UNIT_Mile       0x10  //英里 

	//2.2 面积单位
	#define UNIT_SQ_MM	0x20   //平方毫米(Square Millimeter)
	#define UNIT_SQ_CM	0x21   //平方厘米(Square Centimeter)
	#define UNIT_SQ_DM	0x22   //平方分米(Square Millimeter)
	#define UNIT_SQ_M	0x23   //平方米(Square DeciMeter)
	#define UNIT_SQ_KM	0x24   //平方公里(Square KiloMeter)
	#define UNIT_SQ_Inch	0x25   //平方英寸(Square Inch)
	#define UNIT_SQ_Foot	0x26   //平方英尺(Square Foot)
	#define UNIT_SQ_Yard	0x27   //平方码(Square Yard)
	#define UNIT_Are	0x28   //公亩(Are)
	#define UNIT_Acre	0x29   //英亩(Acre)
	#define UNIT_Hectare	0x2A   //公顷(Hectare)
	#define UNIT_SQ_Mile	0x2B   //平方英里(Square Mile)
	//2.3 体积单位
	#define UNIT_CU_MM	0x40   //立方毫米(Cubic Millimeter)
	#define UNIT_CU_CM	0x41   //立方厘米(Cubic Centimeter)
	#define UNIT_CU_DM	0x42   //立方分米(Cubic Millimeter)
	#define UNIT_CU_M	0x43   //立方米(Cubic DeciMeter)
	#define UNIT_CU_Inch	0x45   //立方英寸(Cubic Inch)
	#define UNIT_CU_Foot	0x46   //立方英尺(Cubic Foot)
	#define UNIT_CU_Yard	0x47   //立方码(Cubic Yard)


	//3、参考椭球体参数类型(MAP_PARA结构的earthParam字段值)
	#define EP_UnDefine     0  //未指定"参考椭球体参数类型"
	#define EP_Beijing54    1  //" 1:北京54/克拉索夫斯基(1940年)椭球",  //"Krasovsky"
	#define EP_Krasovsky    1  //" 1:北京54/克拉索夫斯基(1940年)椭球",  //"Krasovsky"
	#define EP_Xian80       2  //" 2:西安80/1975 年I.U.G.G推荐椭球 ",
	#define EP_IUGG1975     2  //" 2:西安80/1975 年I.U.G.G推荐椭球 ",
	#define EP_IUGG1979     3  //" 3:1979 年I.U.G.G推荐椭球 ",
	#define EP_IUGG1983	4  //" 4:1983 年I.U.G.G推荐椭球",
	#define EP_UserDefine   5  //" 5:新的椭球参数(自定义)   ",
	#define EP_IUGG1967     6  //" 6:1967 年I.U.G.G推荐椭球",
	#define EP_WGS84        7  //" 7:WGS-84 ",
	#define EP_GRS80        8  //" 8:GRS-80 ",
	#define EP_WGS72        9  //" 9:WGS-72 ",
	#define EP_Australia1965 10 //" 10:澳大利亚1965年椭球",
	//#define EP_     11 //" 11:海福特1910年椭球",
	//#define EP_	12 //" 12:克拉克1880年椭球",
	//#define EP_	13 //" 13:克拉克1866年椭球",
	//#define EP_	14 //" 14:白塞尔1841年椭球",

	//4、投影类型(MAP_PARA结构的projType字段)
	#define PRJ_LonLat		    0   //地理坐标系(经纬度)
	#define PRJ_UTM			    1   //通用横向墨卡托投影坐标系(UTM)",
	#define PRJ_Albers_Conical_EQ_Area  2	//亚尔勃斯等积圆锥投影坐标系",ALBERS CONICAL EQUAL AREA
	#define PRJ_Lambert_Conformal_Conic 3   //兰伯特等角圆锥投影坐标系",LAMBERT CONFORMAL CONIC
	#define PRJ_Mercator                4   //墨卡托(正轴等角圆柱)投影坐标系",MERCATOR
	#define PRJ_Gauss_Kruger	    5   //高斯-克吕格(横切椭圆柱等角)投影",GAUSS-KRUGER
	#define PRJ_Polyconic		    6   //普通多圆锥投影坐标系",POLYCONIC
	#define PRJ_EQ_Dist_Conic	    7   //等距圆锥投影坐标系",EQUIDISTANT  CONIC
	#define PRJ_Transverse_Mecator      8   //横向墨卡托(横切圆柱等角)投影",TRANSVERSE MECATOR
	#define PRJ_StereoGraphic	    9   //球面投影(视点在球面)坐标系",STEREOGRAPHIC
	#define PRJ_Lambert_Azimuthal_EQ_Area  10 //兰伯特等积方位投影坐标系",LAMBERT  AZIMUTHAL EQUAL_AREA
	#define PRJ_Azimuthal_EQ_Dist          11 //等距方位投影坐标系",AZIMUTHAL EQUIDISTANT
	#define PRJ_Gnomonic  	               12 //心射切面(球心)投影坐标系",GNOMONIC
	#define PRJ_Orthographic	       13 //正射投影(视点无穷远)坐标系",ORTHOGRAPHIC
	#define PRJ_General_VER_NS_Perspective 14 //通用垂直近距透视(外心)投影",GENERAL VERTICAL NEAR_SIDE PERSPECTIVE
	#define PRJ_Sinusoidal		       15 //正弦投影(伪圆柱)坐标系",SINUSOIDAL
	#define PRJ_Equirectangular	       16 //等距离切圆柱(方格)投影坐标系",EQUIRECTANGULAR
	#define PRJ_Miller_Cylindrical         17 //米勒圆柱(透视正圆柱)投影坐标系",MILLER CYLINDRICAL
	#define PRJ_V_D_Grinten_I              18 //范德格林顿I投影坐标系",VAN DER  GRINTEN I
	#define PRJ_Oblique_Mercator           19 //斜轴墨卡托投影坐标系",OBLIQUE MERCATOR (HOTINE)
	#define PRJ_Polar_Srereographic        20 //极点球面投影坐标系",POLAR SREREOGRAPHIC



		typedef struct MAP_PARAstruct
		{
			char   type;	//空间数据水平坐标系类型
			char   unit;	//空间数据水平坐标单位, 
			double mapw;	//空间数据图幅理论宽  type坐标系,unit单位.
			double maph;	//................高  type坐标系,unit单位.

			char   projType;	//空间数据投影类型
			char   earthParam;  //空间数据参考椭球体参数类型
			double jd0;		//空间数据数据左下角经度  , 数据单位统一采用UNIT_DMS格式
			double wd0;		//空间数据数据......纬度  , 数据单位统一采用UNIT_DMS格式
			double djd;		//空间数据数据经度跨度    , 数据单位统一采用UNIT_DMS格式
			double dwd;		//空间数据数据纬度跨度    , 数据单位统一采用UNIT_DMS格式
			double rate;	//空间数据数据水平比例尺倒数, 无单位

			double lon;		//空间数据中央经线经度	, 数据单位统一采用UNIT_DMS格式
			double lon1; 	//空间数据双经线1 经度	, 数据单位统一采用UNIT_DMS格式
			double lon2;        //空间数据双经线2 经度	, 数据单位统一采用UNIT_DMS格式
			double lat;		//空间数据投影原点纬度	, 数据单位统一采用UNIT_DMS格式
			double lat1; 	//空间数据双纬线1 纬度	, 数据单位统一采用UNIT_DMS格式
			double lat2;        //空间数据双纬线2 纬度	, 数据单位统一采用UNIT_DMS格式
			double dx;		//空间数据图纸坐标原点在投影坐标系中的X偏移值 ,type坐标系,unit单位.
			double dy;		//....................................Y偏移   ,type坐标系,unit单位.

			char   levelType;	//空间数据大地水准面类型
			double h;		//空间数据大地水准面与参考椭球面之间的高差, 单位为
			double H;		//空间数据投影平面与大地水准面的高差, 单位为

			double vRate;	//空间数据垂向比例尺倒数
			char   vUnit;	//空间数据垂向数据单位
			char   TICtype;	//TIC点理论坐标系类型
			char   TICunit;	//TIC点理论坐标单位
			char   infoUnit;	//图形显示参数单位
			double infoRatex;	//图形显示参数单位值相对于当前数据单位值的x比例系数, 初始值必须赋0或1
			double infoRatey;	//........................................y比例系数, 初始值必须赋0或1
		}MAP_PARA;

		//控制点结构
		typedef struct
		{
			D_DOT	xy0;	//图形坐标值
			D_DOT	xy1;	//理论坐标值
		}TIC_DOT;

		//属性排序结构
		typedef struct
		{
			char  fldName[FLD_NAME_LEN];	//字段名称
			char  flg;			//排序方法  0为升序  1为降序
		} ATT_SORT;
		typedef struct
		{
			short fldNo;	//字段号
			char  flg; 	//排序方法  0为升序  1为降序
		} ATT_SORT1;


		typedef struct
		{
			SQLSMALLINT valueCType;	      //例：SQL_C_DOUBLE
			SQLSMALLINT parameterType;      //例：SQL_FLOAT
			SQLPOINTER  parameterValuePtr;
		}SQL_BIND_PARAM;


	#define DSN_LEN        31   //SQL_MAX_DSN_LENGTH
	#define LOG_LEN        31
	#define PSW_LEN        31
	#define OWNER_NAME_LEN 31
		typedef struct
		{
			char grpName[31];               //图形数据名称
			char grpDes[129];               //图形数据描述内容
			char owner[OWNER_NAME_LEN];     //图形数据的拥有者
			char dtype;                     //图形数据类型(LIN,REG,PNT,NET)
		}DB_MAP_ITEM_STRU;

		//数据来源类型：
	#define PC_GIS	   0
	#define NET_GIS	   1



	/*比较属性结构返回误码的最高两字节为错误类型，最低两字节为字段序号。
	定义用法如下：
			switch(errNo&0x0FFF0000)
				{
				case ERR_CMP_STRU_recordleng:
			  ...
			case ERR_CMP_STRU_fieldtype:
				  fldi=errNo&0x0000FFFF;
			  ...
			  ...
			}
	--------------------------------------------------------*/
	#define ERR_CMP_STRU_recordleng		0x00010000    /*纪录长度不同*/
	#define ERR_CMP_STRU_numbfield		0x00020000    /*字段数不同*/
	#define ERR_CMP_STRU_fieldname		0x00030000    /*字段名不同*/
	#define ERR_CMP_STRU_fieldtype		0x00040000    /*字段类型不同*/
	#define ERR_CMP_STRU_fieldlength	0x00050000    /*字段长度不同*/
	#define ERR_CMP_STRU_msk_leng		0x00060000    /*字段显示长度不同*/
	#define ERR_CMP_STRU_point_leng		0x00070000    /*字段小数位数不同*/
	#define ERR_CMP_STRU_edit_enable	0x00080000    /*字段编辑标志不同*/
	#define ERR_CMP_STRU_alias			0x00090000    /*字段别名不同*/
	#define ERR_CMP_STRU_IsNull			0x000A0000    /*字段是否允许为空标志不同*/
	#define ERR_CMP_STRU_shape			0x000B0000    /*字段形态不同*/
	#define ERR_CMP_STRU_shapeInfoNum	0x000C0000    /*字段形态信息项数不同*/
	#define ERR_CMP_STRU_shapeInfo		0x000D0000    /*字段形态信息不同*/
	#define ERR_CMP_STRU_defVal			0x000E0000    /*字段缺省值不同*/
	#define ERR_CMP_STRU_minVal			0x000F0000    /*字段最小值不同*/
	#define ERR_CMP_STRU_maxVal			0x00100000    /*字段最大值不同*/



	//取工作区操作类型:
	#define COMM_AREA	    0
	#define FAST_AREA	    1
	#define READ_WRITE_AREA	    COMM_AREA
	#define READ_ONLY_AREA	    FAST_AREA


	//错误号:
	#define NOT_SYS_FILE	    0	//非本系统文件
	#define NOT_ENOUGH_MEM	    1	//内存不够,请关闭无用进程
	#define ERROR_VER	    2	//错误的版本
	#define ERROR_FILE_TYPE	    3	//错误的文件类型
	#define	ERROR_OPENFILE      4	//打开文件错
	#define	NOT_ENOUGH_FHANDLE  5   //“系统临时目录”错误或没有写权限
	#define	NOT_ENOUGH_DISK	    6	//没有足够的磁盘空间
	#define	LINATT_NOTSAME	    7	//两个文件  线属性结构不相同
	#define	PNTATT_NOTSAME	    8	//两个文件  点属性结构不相同
	#define	REGATT_NOTSAME	    9	//两个文件  区属性结构不相同
	#define	NODATT_NOTSAME	    10	//两个文件  结点属性结构不相同
	#define	NETATT_NOTSAME      11	//两个文件  网络属性结构不相同
	#define	CANNOT_OPEN_SUBGR   12  //不能打开子图库
	#define	CANNOT_OPEN_FILGR   13  //不能打开图案库
	#define	CANNOT_OPEN_LINSTY  14  //不能打开线型库
	#define	CANNOT_OPEN_COLOR   15  //不能打开颜色库
	#define	CANNOT_OPEN_CCLIB   16  //不能打开汉字库


	//字库配置信息:
	#define MAPCADLIB    1
	#define WINTTFLIB    2

}