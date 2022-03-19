#pragma once 

#ifdef	OG_FRAME_EXPORT
#define	OG_FRAME_DLL	__declspec(dllexport)
#else
#define	OG_FRAME_DLL	__declspec(dllimport)
#endif 



#include <vector>
#include <stack>
#include <string>
#include <map>
#include <sstream>
#include <osg/switch>

//#include "Geo3DSpace.h"
#include "gmestru.h"
#ifndef G3D_Color
	#include <osg/vec2>
	#include <osg/vec3>
	#include <osg/vec3d>
	#include <osg/vec4>
	using namespace osg;
	typedef Vec3 Vector3 ;
	typedef Vec2 Vector2 ;
	typedef Vec4	Vector4;
#endif



namespace OG 
{
	typedef std::string string;
	typedef std::vector<string> StringVector;
	//	typedef map<string, string> NameValuePairList;

	typedef unsigned int uint32;
	typedef unsigned short uint16;
	typedef unsigned char uint8;
	typedef int int32;
	typedef short int16;
	typedef char int8;

	typedef float Real;



	// delete [10/25/2013 zcc]
	//const OG_FRAME_DLL string& getUniqueNameByTime(const string& baseName);



#define OG_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define OG_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }

	typedef std::string OGGUID;
	typedef std::vector<OGGUID>			OGGuidList;

	typedef struct Trianlge16
	{
		uint16 a;
		uint16 b;
		uint16 c;
	}Triangle16;

	typedef struct Triangle32
	{
		uint32 a;
		uint32 b;
		uint32 c;
	}Triangle32;
	typedef Triangle32 tcTDETriangle;

	typedef struct tcTDETriangleTop
	{
		int32 a;
		int32 b;
		int32 c;
	}tcTDETriangleTop;

	typedef struct ColourValue
	{
		Real r, g, b, a;
	public:
		ColourValue() {}
		ColourValue(Real rv, Real gv, Real bv, Real av = 0) { r = rv; g = gv; b = bv; a = av; }


	}ColourValue;
	class  Matrix3
	{
	public:
		union {
			Real m[3][3];
			Real _m[9];
		};
	};
	class  Matrix4
	{
	public:
		union {
			Real m[4][4];
			Real _m[16];
		};
	};

	

	
	class  Quaternion
	{
	public:
		Real w, x, y, z;

		inline Quaternion(Real fW = 1.0,Real fX = 0.0, Real fY = 0.0, Real fZ = 0.0)
		{
			w = fW;
			x = fX;
			y = fY;
			z = fZ;
		}
		inline Quaternion(const Quaternion& rkQ)
		{
			w = rkQ.w;
			x = rkQ.x;
			y = rkQ.y;
			z = rkQ.z;
		}

	public:

	};
	class Angle
	{
	public:
		Real mAngle;

		explicit Angle(Real angle) : mAngle(angle) {}
	};

	enum ProjectionType
	{
		PT_ORTHOGRAPHIC,
		PT_PERSPECTIVE
	};

	class AxisAlignedBox
	{
	public:
		Vector3 mMinimum;
		Vector3 mMaximum;
	};

	class RenderWindow
	{
	public:
		bool mIsFullScreen;
		bool mIsPrimary;
		bool mAutoDeactivatedOnFocusChange;
		int mLeft;
		int mTop;
	};

	typedef enum OG_GEO_TYPE
	{
		OG_GEO_TYPE_VOLUME = 0,
		OG_GEO_TYPE_SURFACE = 1,
		OG_GEO_TYPE_LINE = 2,
		OG_GEO_TYPE_PNT = 3,
	}OG_GEO_TYPE;

	//typedef struct  OG_Mdl_ID
	//{
	//	GME_TYPE_OBJ_ID	ClsID;//要素类ID或
	//	GME_TYPE_OBJ_ID		DsID; //要素数据集集
	//	GME_TYPE_OBJ_ID	ObjID;//要素或几何对象ID
	//	short			nObjType;//对象类型

	//	OG_Mdl_ID()
	//	{
	//		ClsID = 0;
	//		DsID = 0;
	//		ObjID = 0;
	//		nObjType = 0;
	//	}
	//}OG_Mdl_ID;

	typedef struct  OG_Mdl_ID
	{
		GME_TYPE_OBJ_ID MdlID;
		GME_TYPE_OBJ_ID	FclsID;//要素类ID或
		GME_TYPE_OBJ_ID	FeatID; //要素数据集集
		GME_TYPE_OBJ_ID	GeomID;//要素或几何对象ID
		GME_TYPE_OBJ_ID	GeomType;//对象类型

		OG_Mdl_ID()
		{
			MdlID = 0;
			FclsID = 0;
			FeatID = 0;
			GeomID = 0;
			GeomType = 0;
		}
	}OG_Mdl_ID;

	typedef struct  OG_SubMdl_ID
	{
		GME_TYPE_OBJ_ID	ClsID;//要素类ID或
		GME_TYPE_OBJ_ID		DsID; //要素数据集集
		GME_TYPE_OBJ_ID	ObjID;//要素或几何对象ID
		short			nObjType;//对象类型

		long			SubMdlID;
		string			MatName;
		short			SubMdlType;

		OG_SubMdl_ID()
		{
			ClsID = 0;
			DsID = 0;
			ObjID = 0;
			nObjType = 0;
			SubMdlID = 0;
			MatName = "";
			SubMdlType = 0;
		}
	}OG_SubMdl_ID;

	class Camera
	{
	public:
		bool mYawFixed;
	};


	class Viewport
	{
	public:
		Camera* camera;
		Real left, top;
		Real width, height;
		int ZOrder;
	};
	class SceneManager
	{
	public:
		long ID;
	};





	class  Light
	{
	public:
		Real tempSquareDist;
		enum LightTypes
		{
			/// Point light sources give off light equally in all directions, so require only position not direction
			LT_POINT = 0,
			/// Directional lights simulate parallel light beams from a distant source, hence have direction but no position
			LT_DIRECTIONAL = 1,
			/// Spotlights simulate a cone of light from a source so require position and direction, plus extra values for falloff
			LT_SPOTLIGHT = 2
		};
	};

	struct OG_WORK_CONTEXT
	{
		Viewport*		pViewport;						// 当前工作视口
		HWND            hWnd;							// 窗口句柄
		SceneManager*   pSceneManager;       // 场景管理器
		Camera*			pCamera;						// 摄像机
		RenderWindow*	pRenderWindow;		// 绘制窗口
		void*			ptr;									// 保留使用

		OG_WORK_CONTEXT()
		{
			memset(this, 0, sizeof(OG_WORK_CONTEXT));
		}

	};



	//	工作环境上下文类
	typedef OG_WORK_CONTEXT OGWorkContext;			// 重声明

	// 应用状态句柄定义
	typedef DWORD StateHandle;



	// 视图类型信息
	enum VIEW_TYPE
	{
		VT_NONE = 0,					// 
		VT_3DVIEW = 1,					// OG中的3DView
		VT_2DVIEW_67 = 2,					// 从Mapgis67中继承的视图

		VT_ALL = 0x7FFFFFFF,			// 所有视图类型
	};





	// 参数值对象, 与ParamterDef配合使用，存储参数的值
	class OG_FRAME_DLL OGParameterValue
	{
	public:
		string			value;		// 值

		OGParameterValue() {};
		OGParameterValue(const string& newValue) :value(newValue) {}

		//// 输出
		//void operator >> (bool& val)				{ val = TStringConverter::ParseBool(value); }
		//void operator >> (float&  val)				{ val = TStringConverter::ParseReal(value); }
		//void operator >> (double&  val)				{ val = TStringConverter::ParseDouble(value); }
		//void operator >> (int&  val)				{ val = TStringConverter::ParseInt(value); }
		//void operator >> (unsigned int&  val)		{ val = TStringConverter::ParseUnsignedInt(value); }
		//void operator >> (short&  val)				{ val = TStringConverter::ParseShort(value); }
		//void operator >> (unsigned short&  val)		{ val = TStringConverter::ParseUnsignedShort(value); }
		//void operator >> (long&  val)				{ val = TStringConverter::ParseLong(value); }
		//void operator >> (unsigned long&  val)		{ val = TStringConverter::ParseUnsignedLong(value); }
		//void operator >> (string&  val)			{ val = value; }
		//void operator >> (Vector3&  val)			{ val = TStringConverter::ParseVector3(value); }
		//void operator >> (Matrix4&  val)			{ val = TStringConverter::ParseMatrix4(value); }
		//void operator >> (ColourValue&  val)				{ val = TStringConverter::ParseColourValue(value); }

		//// 输入
		//void operator << (const bool& val)				{ value = TStringConverter::ToString(val); }
		//void operator << (const float&  val)				{ value = TStringConverter::ToString(val); }
		//void operator << (const double&  val)				{ value = TStringConverter::ToString(val); }
		//void operator << (const int&  val)				{ value = TStringConverter::ToString(val); }
		//void operator << (const unsigned int&  val)		{ value = TStringConverter::ToString(val); }
		//void operator << (const short&  val)				{ value = TStringConverter::ToString(val); }
		//void operator << (const unsigned short&  val)		{ value = TStringConverter::ToString(val); }
		//void operator << (const long&  val)				{ value = TStringConverter::ToString(val); }
		//void operator << (const unsigned long&  val)		{ value = TStringConverter::ToString(val); }
		//void operator << (const string&  val)			{ value = val; }
		//void operator << (const Vector3&  val)			{ value = TStringConverter::ToString(val); }
		//void operator << (const Matrix4&  val)			{ value = TStringConverter::ToString(val); }
		//void operator << (const ColourValue&  val)				{ value = TStringConverter::ToString(val); }
	};
	enum PolygonMode
	{
		/// Only points are rendered.
		PM_POINTS = 1,
		/// Wireframe models are rendered.
		PM_WIREFRAME = 2,
		/// Solid polygons are rendered.
		PM_SOLID = 3
	};
	enum FogMode
	{
		/// No fog. Duh.
		FOG_NONE,
		/// Fog density increases  exponentially from the camera (fog = 1/e^(distance * density))
		FOG_EXP,
		/// Fog density increases at the square of FOG_EXP, i.e. even quicker (fog = 1/e^(distance * density)^2)
		FOG_EXP2,
		/// Fog density increases linearly between the start and end distances
		FOG_LINEAR
	};
	class MovableObject
	{
	public:
		string mName;
	};
	class  Root
	{
	public:
		string mName;

	};

	class Entity
	{
	public:
		string mName;
	};


	typedef osg::Node SceneNode;

	typedef enum OGInputMode
	{
		OG_INPUT_MODE_PLANE_DEFAULT = 1,
		OG_INPUT_MODE_PLANE_MAYA = 2,
		OG_INPUT_MODE_PLANE_3 = 3,
		OG_INPUT_MODE_PLANE_4 = 4,
		OG_INPUT_MODE_PLANE_5 = 5,
		OG_INPUT_MODE_PLANE_6 = 6,
		OG_INPUT_MODE_PLANE_7 = 7,
		OG_INPUT_MODE_PLANE_8 = 8,
		OG_INPUT_MODE_GLOBE_DEFAULT = 9
	}OGInputMode;


#define NOTE_LENGTH	64	//注记长度，1万个点约 600KB
	class CSingOGDot
	{
	public:
		CSingOGDot()
		{
			m_dX = 0;
			m_dY = 0;
			m_dValue = 0;
			m_nFlag = 0;
			memset(m_szNote, 0, NOTE_LENGTH);
		}
		double			m_dX;					//横坐标
		double			m_dY;					//纵坐标
		double			m_dValue;				//功能字段值，可用于分段设置子图、评价指标等
		int				m_nFlag;				//分段设子图的序号
		char			m_szNote[NOTE_LENGTH];	//点位注记
	};
	//点位数据集合
	typedef std::vector<CSingOGDot>	 vecSubSingOGDot;

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

	typedef struct OG_MAP_PARA
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

	}


#ifndef OG_FRAME_EXPORT 
#pragma comment(lib, "OGFrame.lib")
#endif
