#ifndef _S3D_GISSTRU_H
#define _S3D_GISSTRU_H

#pragma pack(push, 1)


#include <set>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <float.h>
#include <fstream>
using namespace std;

#define  FLD_NAME_LEN 	     20			/*字段名长度*/
#define  DBIMAXNAMELEN	     31


typedef struct _D_DOT
{
	double x, y;

	_D_DOT()
	{
		x = y = 0;
	}
}_D_DOT;
typedef struct _D_3DOT
{
	double x, y, z;

	_D_3DOT()
	{
		x = y = z = 0;
	}
}_D_3DOT;


//=======================基本参数及结构定义===========================//
	typedef enum GM_VECTOR_TYPE
	{
		GM_LIN = 0,
		GM_PNT = 1,
		GM_REG = 2,
	}GM_VECTOR_TYPE;

	//点数据类型定义
	typedef enum GM_PNT_TYPE
	{
		GM_PNT_NOTE	= 0,
		GM_PNT_SUB	= 1,
		GM_PNT_CIR	= 2,
		GM_PNT_ARC	= 3,
		GM_PNT_IMAGE= 4,
		GM_PNT_TEXT = 5,
	}GM_PNT_TYPE;

	//点类型实体图形信息结构
	typedef struct GM_PNT_INFO //93bytes
	{
		GM_PNT_INFO()
		{
			memset(this, 0, sizeof(GM_PNT_INFO));
			flag = 1;
		}

		//0-32（33bytes）
		char	flag; //标记
		short	strLen;//字符串长度
		long	strOffset;//字符偏移量
		_D_3DOT	coord;//坐标
		char	type;   //点类型（0-字符串  1-子图  2-圆  3-弧 4-图象 5-文本）
		char	ovprnt;	//透明输出

		union //33-72（40bytes）
		{
			struct //22bytes
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
			struct //40bytes
			{
				float  height;	//文本高
				float  width;   //文本宽
				float  space;   //字间距(横向间距)
				float  angle;   //以360度制度为单位表示
				short  ifnt;    //中文字体
				short  chnt;	//西文字体
				char   ifnx;    //字形
				float  lspace;	//行间距(纵向间距)
				float  dx, dy;	//版面长和宽
				char   hvpl;	//水平或垂直排列0=水平排列 1=垂直排列
				char	reserve[6]; //预留
			}text;
			struct //24bytes
			{
				long  subno;	//子图号
				float height;   //高度
				float width;    //宽度
				float angle;    //角度
				float penw;     //线宽(未用,6.0以前为short)
				long  fclr;		//辅助色(未用)  [short-->long]
			}sub;
			struct //17bytes
			{
				double radiu;	//radiu>0, <=0为非法  [float-->double]
				long   lcol;    //边线颜色，填充色为icol [short-->long]
				float  penw;	//线宽
				char   fflag;	//4.1版开始 1=填充圆 0=空心圆
			}circle;
			struct //20bytes
			{
				double radiu;    //radiu>0, <=0为非法  [float-->double]
				float  begang;	//起始角度
				float  endang;	//终止角度
				float  penw;	//线宽度(6.0以前为short)
			}arc;
			struct //20bytes
			{
				double width;	//图像宽
				double height;	//图像高
				float  angle;	//角度(未用)
			}image;
		}info;

		short   layer;  //图层
		int     iclr;	//点颜色
		char	reserve[14]; //预留字节
	}GM_PNT_INFO;


	//线类型实体图形信息结构
	typedef struct GM_LIN_INFO
	{
		GM_LIN_INFO()
		{
			memset(this, 0, sizeof(GM_LIN_INFO));
			unflag2 = 1;
			reserved[6] = 1;
			reserved[7] = 2;
		}

		char	unkFlag[8];//未知
		long	linDotsNum;//当前线上点数
		long	linDotsOffset;//当前线上点坐标的存储位置
		long	unflag2; //未知

		short   ltp;		//线型号
		char    fltp;       //辅助线型号
		char    ovprnt;		//覆盖方式
		long    lclr;       //线颜色号
		float   lw;         //线宽
		char    lclass;		//线种类，0=折线、1=贝塞尔曲线
		float   xscale;		//X系数
		float   yscale;     //Y系数
		long    fclr;		//辅助色
		long	layer;      //图层

		char	reserved[8];//保留
	}GM_LIN_INFO;


	
	typedef struct GM_REG_INFO //区类型实体图形信息结构 40 bytes
	{
		GM_REG_INFO()
		{
			memset(this, 0, sizeof(GM_REG_INFO));
			cExist = 1;
		}

		char	cExist;	//标记位
		long	segNum;	//区弧段数据项数（包括弧段的点数、弧段号以及弧段边界之间的间隔0)
		long	segNoOffset;//弧段号数据存储位置

		long    clr;	  //区域色
		short   patno;	  //图案号
		float   pathei;	  //图案高
		float   patwid;	  //图案宽
		long    patclr;	  //图案颜色
		short   basLN;	  //5.32版以前未用，必须=0；5.32版开始作为构成斜坡基线的弧段数
		char    fmode;	  //覆盖方式（是否透明）
		short   layer;    //图层

		char	reserved[8];
	}GM_REG_INFO;

	//地图参数定义:
	//1、坐标系类型(GM_MAP_PARA结构的type字段值)
	typedef enum GM_COORD_TYPE
	{
		GM_TYPE_NOPAR   = 0,	/*用户自定义坐标系*/
		GM_TYPE_JWD		= 1,	/*地理坐标系*/
		GM_TYPE_DD		= 2,	/*大地坐标系*/
		GM_TYPE_PRJ		= 3,	/*投影平面直角坐标系*/
		GM_TYPE_XYZ		= 4,	/*地心大地直角坐标系*/
	}GM_COORD_TYPE;


	//2、坐标单位(GM_MAP_PARA结构的unit字段值)
	typedef enum GM_UNIT_TYPE
	{
		//2.1 长度单位
		GM_UNIT_MM			= 0x00,   //毫米
		GM_UNIT_MilliMeter  = 0x01,   //毫米
		GM_UNIT_Meter		= 0x02,   //米
		GM_UNIT_Second		= 0x03,   //秒
		GM_UNIT_Degree		= 0x04,   //度
		GM_UNIT_DMS			= 0x05,   //度分秒,即±DDDMMSS.SSSS格式
		GM_UNIT_Foot		= 0x06,   //英尺
		GM_UNIT_Minute		= 0x07,   //分(60分之一度)
		GM_UNIT_Radian		= 0x08,   //弧度
		GM_UNIT_GRAD		= 0x09,   //梯度   1梯度=0.015707963267949弧度

		GM_UNIT_KM			= 0x0A,   //公里
		GM_UNIT_DM			= 0x0B,   //分米
		GM_UNIT_CM			= 0x0C,   //厘米

		GM_UNIT_Inch		= 0x0D,  //英寸
		GM_UNIT_Yard		= 0x0E,  //码
		GM_UNIT_SeaMile		= 0x0F,  //海里 
		GM_UNIT_Mile		= 0x10,  //英里 

	//2.2 面积单位
		GM_UNIT_SQ_MM		= 0x20,   //平方毫米(Square Millimeter)
		GM_UNIT_SQ_CM		= 0x21,   //平方厘米(Square Centimeter)
		GM_UNIT_SQ_DM		= 0x22,   //平方分米(Square Millimeter)
		GM_UNIT_SQ_M		= 0x23,   //平方米(Square DeciMeter)
		GM_UNIT_SQ_KM		= 0x24,   //平方公里(Square KiloMeter)
		GM_UNIT_SQ_Inch		= 0x25,   //平方英寸(Square Inch)
		GM_UNIT_SQ_Foot		= 0x26,   //平方英尺(Square Foot)
		GM_UNIT_SQ_Yard		= 0x27,   //平方码(Square Yard)
		GM_UNIT_Are			= 0x28,   //公亩(Are)
		GM_UNIT_Acre		= 0x29,   //英亩(Acre)
		GM_UNIT_Hectare		= 0x2A,   //公顷(Hectare)
		GM_UNIT_SQ_Mile		= 0x2B,   //平方英里(Square Mile)
	//2.3 体积单位
		GM_UNIT_CU_MM		= 0x40,   //立方毫米(Cubic Millimeter)
		GM_UNIT_CU_CM		= 0x41,   //立方厘米(Cubic Centimeter)
		GM_UNIT_CU_DM		= 0x42,   //立方分米(Cubic Millimeter)
		GM_UNIT_CU_M		= 0x43,   //立方米(Cubic DeciMeter)
		GM_UNIT_CU_Inch		= 0x45,   //立方英寸(Cubic Inch)
		GM_UNIT_CU_Foot		= 0x46,   //立方英尺(Cubic Foot)
		GM_UNIT_CU_Yard		= 0x47,   //立方码(Cubic Yard)
	}GM_UNIT_TYPE;

	//3、参考椭球体参数类型(GM_MAP_PARA结构的earthParam字段值)
	typedef enum GM_EP_TYPE
	{
		GM_EP_UnDefine		= 0,  //未指定"参考椭球体参数类型"
		GM_EP_Beijing54		= 1,  //" 1:北京54/克拉索夫斯基(1940年)椭球",  //"Krasovsky"
		GM_EP_Xian80		= 2,  //" 2:西安80/1975 年I.U.G.G推荐椭球 ", (GM_EP_IUGG1975)
		GM_EP_IUGG1979		= 3,  //" 3:1979 年I.U.G.G推荐椭球 ",
		GM_EP_IUGG1983		= 4,  //" 4:1983 年I.U.G.G推荐椭球",
		GM_EP_UserDefine	= 5,  //" 5:新的椭球参数(自定义)   ",
		GM_EP_IUGG1967		= 6,  //" 6:1967 年I.U.G.G推荐椭球",
		GM_EP_WGS84			= 7,  //" 7:WGS-84 ",
		GM_EP_GRS80			= 8,  //" 8:GRS-80 ",
		GM_EP_WGS72			= 9,  //" 9:WGS-72 ",
		GM_EP_Australia1965 = 10, //" 10:澳大利亚1965年椭球",
		GM_EP_11			= 11, //" 11:海福特1910年椭球",
		GM_EP_12			= 12, //" 12:克拉克1880年椭球",
		GM_EP_13			= 13, //" 13:克拉克1866年椭球",
		GM_EP_14			= 14, //" 14:白塞尔1841年椭球",
	}GM_EP_TYPE;

	//4、投影类型(GM_MAP_PARA结构的projType字段)
	typedef enum GM_PRJ_TYPE
	{
		GM_PRJ_LonLat					= 0,   //地理坐标系(经纬度)
		GM_PRJ_UTM						= 1,   //通用横向墨卡托投影坐标系(UTM)",
		GM_PRJ_Albers_Conical_EQ_Area	= 2,	//亚尔勃斯等积圆锥投影坐标系",ALBERS CONICAL EQUAL AREA
		GM_PRJ_Lambert_Conformal_Conic	= 3,   //兰伯特等角圆锥投影坐标系",LAMBERT CONFORMAL CONIC
		GM_PRJ_Mercator					= 4,   //墨卡托(正轴等角圆柱)投影坐标系",MERCATOR
		GM_PRJ_Gauss_Kruger				= 5,   //高斯-克吕格(横切椭圆柱等角)投影",GAUSS-KRUGER
		GM_PRJ_Polyconic				= 6,   //普通多圆锥投影坐标系",POLYCONIC
		GM_PRJ_EQ_Dist_Conic			= 7,   //等距圆锥投影坐标系",EQUIDISTANT  CONIC
		GM_PRJ_Transverse_Mecator		= 8,   //横向墨卡托(横切圆柱等角)投影",TRANSVERSE MECATOR
		GM_PRJ_StereoGraphic			= 9,   //球面投影(视点在球面)坐标系",STEREOGRAPHIC
		GM_PRJ_Lambert_Azimuthal_EQ_Area= 10, //兰伯特等积方位投影坐标系",LAMBERT  AZIMUTHAL EQUAL_AREA
		GM_PRJ_Azimuthal_EQ_Dist		= 11, //等距方位投影坐标系",AZIMUTHAL EQUIDISTANT
		GM_PRJ_Gnomonic					= 12, //心射切面(球心)投影坐标系",GNOMONIC
		GM_PRJ_Orthographic				= 13, //正射投影(视点无穷远)坐标系",ORTHOGRAPHIC
		GM_PRJ_General_VER_NS_Perspective= 14, //通用垂直近距透视(外心)投影",GENERAL VERTICAL NEAR_SIDE PERSPECTIVE
		GM_PRJ_Sinusoidal				= 15, //正弦投影(伪圆柱)坐标系",SINUSOIDAL
		GM_PRJ_Equirectangular			= 16, //等距离切圆柱(方格)投影坐标系",EQUIRECTANGULAR
		GM_PRJ_Miller_Cylindrical		= 17, //米勒圆柱(透视正圆柱)投影坐标系",MILLER CYLINDRICAL
		GM_PRJ_V_D_Grinten_I			= 18, //范德格林顿I投影坐标系",VAN DER  GRINTEN I
		GM_PRJ_Oblique_Mercator			= 19, //斜轴墨卡托投影坐标系",OBLIQUE MERCATOR (HOTINE)
		GM_PRJ_Polar_Srereographic		= 20, //极点球面投影坐标系",POLAR SREREOGRAPHIC
	}GM_PRJ_TYPE;

	typedef enum GM_ELEVT_TYPE //高程系类型
	{
		GM_ELEVT_1985		= 0,  //1985 国家高程基准  青岛原点高程72.260米 西安坐标系用
		GM_ELEVT_1956		= 1,  //1956年黄海平均海水面 青岛原点高程72.289米 北京坐标系用
		GM_ELEVT_1954		= 2,  //1954年黄海平均海水面
		GM_ELEVT_KANMEN		= 3,  //坎门平均海面
		GM_ELEVT_WUSONG		= 4,  //吴淞平均海面
		GM_ELEVT_DAGU		= 5,  //大沽平均海面
		GM_ELEVT_DALIAN		= 6,  //大连平均海面
		GM_ELEVT_LUOXTAZERO = 7,  //罗星塔零点
		GM_ELEVT_WUSONGZERO = 8,  //吴淞零点
		GM_ELEVT_FEIHHEZERO = 9,  //废黄河零点
		GM_ELEVT_DAGUZERO	= 10, //大沽零点
		GM_ELEVT_ZHUJIANG	= 11, //珠江基面
	}GM_ELEVT_TYPE;



typedef struct GM_MAP_PARA //投影参数 169byts
{
	GM_MAP_PARA()
	{
		memset(this, 0, sizeof(GM_MAP_PARA));
		earthParam = GM_EP_Beijing54;
		infoRatex = 1;
		infoRatey = 1;
	}

	char   type;	//空间数据水平坐标系类型 GM_COORD_TYPE
	char   unit;	//空间数据水平坐标单位,  GM_UNIT_TYPE
	double mapw;	//空间数据图幅理论宽  type坐标系,unit单位.
	double maph;	//................高  type坐标系,unit单位.

	char   projType;	//空间数据投影类型 GM_PRJ_TYPE
	char   earthParam;  //空间数据参考椭球体参数类型 GM_EP_TYPE
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

	char   levelType;	//空间数据大地水准面类型 GM_ELEVT_TYPE
	double h;		//空间数据大地水准面与参考椭球面之间的高差, 单位为
	double H;		//空间数据投影平面与大地水准面的高差, 单位为

	double vRate;	//空间数据垂向比例尺倒数
	char   vUnit;	//空间数据垂向数据单位 GM_UNIT_TYPE
	char   TICtype;	//TIC点理论坐标系类型 GM_UNIT_TYPE
	char   TICunit;	//TIC点理论坐标单位 GM_UNIT_TYPE
	char   infoUnit;	//图形显示参数单位 GM_UNIT_TYPE
	double infoRatex;	//图形显示参数单位值相对于当前数据单位值的x比例系数, 初始值必须赋0或1
	double infoRatey;	//........................................y比例系数, 初始值必须赋0或1
}GM_MAP_PARA;


typedef struct GM_CLRLIB_RGB
{
	unsigned char	r, g, b;
}GM_CLRLIB_RGB;

typedef struct GM_CLRLIB_CMYK
{
	unsigned char	K, C, M, Y;
}GM_CLRLIB_CMYK;


typedef struct S3d_ColorLibHeader
{
	char fileFlag[8];
	short clrNum;
	short spClrNum;
	GM_CLRLIB_CMYK spClr[28];

public:
	S3d_ColorLibHeader()
	{
		memset(this, 0, sizeof(S3d_ColorLibHeader));
	}

}S3d_ColorLibHeader;//124bytes

typedef struct S3d_ACOLOR
{
	GM_CLRLIB_CMYK basClr;
	unsigned char clrExt[28];

public:
	S3d_ACOLOR()
	{
		memset(this, 0, sizeof(S3d_ACOLOR));
	}

}S3d_ACOLOR;


typedef enum
{
	UNKNOWN = -1,
	EXTERIOR,
	INTERIOR,
	VERTEX_A,
	VERTEX_B,
	VERTEX_C,
	BOUNDARY_AB,
	BOUNDARY_BC,
	BOUNDARY_AC
}point_triangle_ralationship;

typedef enum
{
	NOT_INTERSECT = 0,
	INTERSECT,
	INTERSECT_POINT_A,
	INTERSECT_POINT_B,
	INTERSECT_POINT_C,
	INTERSECT_POINT_D,
}line_line_ratationship;




typedef struct _GISENV //环境目录
{
	char clib[128];	//汉字库目录
	char sys[128];	//系统目录
	char cur[128];	//当前工作目录
	char temp[128];	//临时工作目录（工作区使用）
	char slib[128];	//系统库目录

	_GISENV()
	{
		memset(clib, 0, 128);
		memset(sys, 0, 128);
		memset(cur, 0, 128);
		memset(temp, 0, 128);
		memset(slib, 0, 128);
	}
}_GISENV;

typedef struct _D_RECT
{
	double xmin;
	double ymin;
	double xmax;
	double ymax;

	_D_RECT()
	{
		xmin = ymin = (+3.402823E+38);
		xmax = ymax = (-3.402823E+38);
	}
}_D_RECT;

typedef struct _CLNINFO
{
	char  CLNFileName[256];		//图例文件全路径名
	char  CLNFilePath[128];		//图例文件的路径
	char  CLNName[80];			//图例文件的文件名

	_CLNINFO()
	{
		memset(CLNFileName, 0, 256);
		memset(CLNFilePath, 0, 128);
		memset(CLNName, 0, 80);
	}
}_CLNINFO;




typedef struct _PROJECTHEAD //1112bytes
{
	char	prjFileTag[8];//文件标记
	int		prjFileType;   //文件类型
	short	FileNum;				//文件数
	_D_RECT Prj_Rect;			//文件的图形范围
	_GISENV Env;				//文件的环境
	char   Title[60];			//文件的标题
	long   lLayerDictOffset;    //图层字典位置
	long   lFirstFile;          //首文件存放指针 1113字节
	//输出页面及位置描述
	double  TranX, TranY;     	//位移
	double  ScaleX, ScaleY;   	//比例
	double  Angle;           	//旋转角度
	double  VerW, VerH;       	//版面宽高
	short  PrjType;
	long   lFirstCLN;			//首图例存放指针
	GM_MAP_PARA PrjMapParam;		//工程预设的地图参数
	char   UnUsed[128];

	_PROJECTHEAD()
	{
		memcpy(prjFileTag, "WMAP`D2:", 8);
		prjFileType = 9; //固定值
		FileNum = 0;
		memset(Title, 0, 60);
		lLayerDictOffset = 0;
		lFirstFile = 1113;
		TranX = TranY = 0;
		ScaleX = ScaleY = 1;
		Angle = 0;
		VerW = 1024;
		VerH = 768;
		PrjType = 0;
		lFirstCLN = 0;
		memset(UnUsed, 0, 128);
	}
}_PROJECTHEAD;

//工程文件内部数据结构
typedef struct _PROJECTITEM //400bytes
{
public:
	char   Filetype;		//文件类型(PNT/LIN/REG/MSIIMG)
	char   FileState;		//文件状态(0-关闭 / 1-打开 2-编辑 3-编辑并当前活动打开)
	char   Filename[128];   //文件名(全路径)
	char   Describe[128];   //文件的描述
	_D_RECT rect;			//图层范围...
	char   UserType;		//用户自定义类型
	char   GroupCode;		
	char   DataSource[32];  //网络数据的数据源(单机文件此项为空)
	double MinDispRate;		//最小显示比例(<MinDispRate,不显示)
	double MaxDispRate;		//最大显示比例(>MaxDispRate,不显示)
	char   NoteFlg;         //标志是否进行字段动态标注,以及是否跟随放大
	char   NoteField[21];   //标注字段名称
	float  NoteHeight;      //标注字高
	short  NoteColor;       //标注颜色
	char   NoteFont;		//标注字体
	unsigned char  CLNClassCode;	//图例分类信息
	char   UnUsed[30];		//保留

	_PROJECTITEM()
	{
		Filetype = 0;		//文件类型(PNT/LIN/REG/MSIIMG)
		FileState = 2;		//文件状态(0-关闭 / 1-打开 2-编辑 3-编辑并当前活动打开)
		memset(Filename, 0, 128);   //文件名(全路径)
		memset(Describe, 0, 128);   //文件的描述
		UserType = 0;		//用户自定义类型
		GroupCode = 0;
		memset(DataSource, 0, 32);  //网络数据的数据源(单机文件此项为空)
		MinDispRate = 0;		//最小显示比例(<MinDispRate,不显示)
		MaxDispRate = 0;		//最大显示比例(>MaxDispRate,不显示)
		NoteFlg = 0;         //标志是否进行字段动态标注,以及是否跟随放大
		memset(NoteField, 0, 21);   //标注字段名称
		NoteHeight = 0;      //标注字高
		NoteColor = 0;       //标注颜色
		NoteFont = 0;		//标注字体
		CLNClassCode = 0;	//图例分类信息
		memset(UnUsed, 0, 30);//保留
	}
}_PROJECTITEM;

typedef struct _VECTOR_FILE_HEADER //矢量文件头... 336+321 = 657bytes
{
	char	fileTag[8];//文件头标识 WMAP`D21(WL) WMAP`D22（WT） WMAP`D23（WP）
	int		vecType; //矢量类型 0-LIN 1-PNT 2-REG
	int		dataHeaderAddr;	//数据区头的起始位置,从这个整数指向的字节位置存储数据区头信息
	int		reserveTag1;	//未知
	char	reserveMemo[71];//未知内容
	GM_MAP_PARA mapParam;	//图层文件的地图参数... 169字节
	int		totalNum[11]; //存储有11个整数，表示各种数据的总数,
							//0-点数或线数260-263   104h
							//2 - 节点数  268 - 271 10Ch
							//4 - 区数    276 - 279 114h
							//其余未知
	_D_RECT	rect;	//矢量图形范围
	char unknownData[321];//不知道的321字节
	_VECTOR_FILE_HEADER()
	{
		memset(fileTag, 0, 8);
		vecType = 1;//0-LIN 1-PNT 2-REG
		dataHeaderAddr = 657; //sizeof(_VECTOR_FILE_HEADER) + 321=657 bytes
		reserveTag1 = 16; //默认值
		memset(reserveMemo, 0, 240);
		memset(totalNum, 0, 11*sizeof(int));
		totalNum[8] = 1;
		memset(unknownData, 0, 321);
	}
}_VECTOR_FILE_HEADER;


typedef struct VecHeadInfo //矢量图层文件的数据区头信息 10字节
{
	unsigned long	lDataOffset;//数据区的起始位置
	unsigned long	lDataBytes; //数据区总字节数(n为图元物理个数)
	unsigned short	sEndRemark; //结束标记（0xFFFF）
	VecHeadInfo()
	{
		lDataOffset = 0;
		lDataBytes = 0;
		sEndRemark = 0xFFFF;
	}
}VecHeadInfo;

typedef struct GM_REG_SEG //区弧段信息
{
	long				 pntNum;		//区边界弧段封闭所需总点数。若有n条弧段，m圈边界，n条弧段上一共有d个点，则rdat[0]=d+m
	vector<vector<long>> segNoList;		//围成区的边界列表，每个边界由弧段列表构成
}GM_REG_SEG;




typedef struct GM_ATTRTBL_HEAD //属性表头 348 bytes
{
	char	name1;//0x60
	char	name2;//0x44
	char	date[4];//文件创建日期
	char	name3[6];//0x00
	int		attStruBytes;//属性定义区域的字节数
	int		objNum;	//对象数量
	char	name4[4];//0x00
	char	name5[128];//创建当前工作区文件时的路径
	char	name6[128];//工作区路径
	char	name7[40];	//未知
	char	name8;//0x60
	char	name9;//0x44
	short	fldNum;//字段数量
	int		rcdNum;//属性	记录条数
	short	rcdByts;//每条记录字节数
	char	name10[18];

	GM_ATTRTBL_HEAD()
	{
		memset(this, 0, sizeof(GM_ATTRTBL_HEAD));
		name1 = 0x60;
		name2 = 0x44;
		name8 = 0x60;
		name9 = 0x44;
	}
}GM_ATTRTBL_HEAD;

typedef struct GM_Fld_DEF //字段定义 39 bytes
{
	char	fldName[20];//字段名称
	char	fldType;	//字段类型
	int		fldOffset;//字段存储偏移量
	short	fldBytes;//字段字节长度
	short	fldLength;//字段字符长度
	char	decimalLength;//字段小数位数
	short	editFlag;//编辑标志(0/1/2=不能/能/禁止)
	char	printFlg;//打印标志 0x00
	short	fldNo;	 //字段编号，从0开始
	int		reserve;//0x00

	GM_Fld_DEF()
	{
		memset(this, 0, sizeof(GM_Fld_DEF));
		editFlag = 1;
	}
}GM_Fld_DEF;



typedef struct GM_LIN_TOP //区弧段拓扑信息
{
	long   stNod;    //起始结点
	long   endNod;   //终止结点
	long   lPoly;    //弧段左多边形, 网段所属网号
	long   rPoly;    //弧段右多边形, 对于网络数据, rPoly无效, 设为0.
	float  lWeigh;   //左权
	float  rWeigh;   //右权
}GM_LIN_TOP;

typedef struct GM_LIN_NODE
{
	_D_DOT	coord;		 //节点坐标
	vector<long>	nodeOnLinNos;//节点所在的线号列表.
}GM_LIN_NODE;

typedef struct GM_GRAPH_EXIST //图元存在标志...
{
	short layer;
	char exist;
	char reserve;

	GM_GRAPH_EXIST()
	{
		layer = 0;
		exist = 0;
		reserve = 0;
	}
}GM_GRAPH_EXIST;

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
	_D_RECT   rect;	    //点元范围
}PNT_INFO;

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
	_D_RECT  rect;		//线元范围
}LIN_INFO;

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
	_D_RECT  rect;	  //区域范围
}REG_INFO;

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

#pragma pack(pop)

#endif  // _S3D_GISSTRU_H