#pragma once 


#pragma warning(disable:4244) 
#pragma warning(disable:4251) 
#pragma warning(disable:4267) 

#include <vector>
#include <stack>
#include <string>
#include <map>
#include <sstream>
using namespace std;

#include "gmestru.h"
#ifndef G3D_Color
	#include <osg/vec2>
	#include <osg/vec3>
	#include <osg/vec3d>
	#include <osg/vec4>
	#include <osg/switch>
	using namespace osg;
	typedef Vec3 Vector3 ;
	typedef Vec2 Vector2 ;
	typedef Vec4	Vector4;
#endif

	#include "gme_vector2.h"
	#include "gme_vector3.h"
	#include "gme_vector4.h"



namespace Smart3dMap 
{
	typedef std::string string;
	typedef std::vector<string> StringVector;

	typedef unsigned int uint32;
	typedef unsigned short uint16;
	typedef unsigned char uint8;
	typedef int int32;
	typedef short int16;
	typedef char int8;

	typedef float Real;

	typedef std::string OGGUID;
	typedef std::vector<OGGUID>			OGGuidList;



	#ifndef OG_DELETE
		#define OG_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
	#endif

	#ifndef OG_DELETE_ARRAY
		#define OG_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
	#endif
		//内存释放
	#ifndef SAFE_DELETE
		#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
	#endif

	#ifndef SAFE_DELETE_ARRAY
		#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
	#endif
	#ifndef SAFE_RELEASE
		#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
	#endif

	#ifndef MIN_FLOAT
	#define MIN_FLOAT	(-3.402823E+38)
	#endif

	#ifndef ZERO_FLOAT
	#define ZERO_FLOAT (+1.401298E-45)
	#endif

	#ifndef MAX_FLOAT
	#define MAX_FLOAT	(+3.402823E+38)
	#endif


	#ifndef MIN_DOUBLE
	#define  MIN_DOUBLE	(-1.79769313486232E+307)
	#endif
	#ifndef MAX_DOUBLE
	#define  MAX_DOUBLE	(+1.79769313486232E+307)
	#endif


	#ifndef ZERO_6BIT
	#define		ZERO_6BIT  1E-6
	#endif
	#ifndef EQUAL_6BIT
	#define		EQUAL_6BIT(a,b)		( fabs(a-b) < ZERO_6BIT )
	#endif

	#ifndef RTOD
	#define		RTOD	57.2957795131		// 由弧度向度数转化的系数
	#endif

	#ifndef EPS
	#define		EPS		0.0000001 		    // Tolerance for Line-Triangle intersection
	#endif

	#ifndef _PAI
	#define _PAI (3.14159265358979323846)
	#endif





	#define Non_Divergent_Spline 1//协方差函数：非发散样条
	#define Cubic_Covariance     2//三次协方差，cubic

	#define KG  1
	#define KZG 2
	#define KGG 3
	#define KZ  4
	struct incrementSymbol3D
	{
		int incrementNum;//界面号
		std::vector<int> incrementIndex;//界面索引
	};

	//每一个界面中的点，两两放在一起，不重复保存。如某界面有三个点123，保存结果为1.2 1.3 2.3 共3个vector.
	struct incrementSymbolRange3D
	{
		int incrementNum;//界面号
		std::vector<std::vector<int>> incrementIndex;//界面索引  
	};

	struct modelRatio
	{
		int nx, ny, nz;
		modelRatio()
		{
			memset(this, 0, sizeof(modelRatio));
		}
	};
	struct modelOrigin
	{
		double dx, dy, dz;
		modelOrigin()
		{
			memset(this, 0, sizeof(modelOrigin));
		}
	};
	struct incrementPoint
	{
		double x, y, z;
		int FormationNum;
		incrementPoint()
		{
			memset(this, 0, sizeof(incrementPoint));
		}
	};
	struct gradientPoint
	{
		double x, y, z;
		double dx, dy, dz;
		gradientPoint()
		{
			memset(this, 0, sizeof(gradientPoint));
		}
	};
	struct ValuePoint
	{
		double x, y, z;
		double value;
		ValuePoint()
		{
			memset(this, 0, sizeof(ValuePoint));
		}
	};






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

	class Degree;

	class  Radian
	{
		Real mRad;

	public:
		explicit Radian(Real r = 0) : mRad(r) {}
		Radian(const Degree& d);
		Radian& operator = (const Real& f) { mRad = f; return *this; }
		Radian& operator = (const Radian& r) { mRad = r.mRad; return *this; }
		Radian& operator = (const Degree& d);

		Real valueDegrees() const { return mRad * (Real(180.0) / (3.14159265358979323846)); }
		Real valueRadians() const { return mRad; }
		//Real valueAngleUnits() const;

		const Radian& operator + () const { return *this; }
		Radian operator + (const Radian& r) const { return Radian(mRad + r.mRad); }
		Radian operator + (const Degree& d) const;
		Radian& operator += (const Radian& r) { mRad += r.mRad; return *this; }
		Radian& operator += (const Degree& d);
		Radian operator - () const { return Radian(-mRad); }
		Radian operator - (const Radian& r) const { return Radian(mRad - r.mRad); }
		Radian operator - (const Degree& d) const;
		Radian& operator -= (const Radian& r) { mRad -= r.mRad; return *this; }
		Radian& operator -= (const Degree& d);
		Radian operator * (Real f) const { return Radian(mRad * f); }
		Radian operator * (const Radian& f) const { return Radian(mRad * f.mRad); }
		Radian& operator *= (Real f) { mRad *= f; return *this; }
		Radian operator / (Real f) const { return Radian(mRad / f); }
		Radian& operator /= (Real f) { mRad /= f; return *this; }

		bool operator <  (const Radian& r) const { return mRad < r.mRad; }
		bool operator <= (const Radian& r) const { return mRad <= r.mRad; }
		bool operator == (const Radian& r) const { return mRad == r.mRad; }
		bool operator != (const Radian& r) const { return mRad != r.mRad; }
		bool operator >= (const Radian& r) const { return mRad >= r.mRad; }
		bool operator >  (const Radian& r) const { return mRad > r.mRad; }

		inline  friend std::ostream& operator <<
			(std::ostream& o, const Radian& v)
		{
			o << "Radian(" << v.valueRadians() << ")";
			return o;
		}
	};

	class  Degree
	{
		Real mDeg; // if you get an error here - make sure to define/typedef 'Real' first

	public:
		explicit Degree(Real d = 0) : mDeg(d) {}
		Degree(const Radian& r) : mDeg(r.valueDegrees()) {}
		Degree& operator = (const Real& f) { mDeg = f; return *this; }
		Degree& operator = (const Degree& d) { mDeg = d.mDeg; return *this; }
		Degree& operator = (const Radian& r) { mDeg = r.valueDegrees(); return *this; }

		Real valueDegrees() const { return mDeg; }
		Real valueRadians() const { return mDeg * ((3.14159265358979323846) / Real(180.0)); }
		//Real valueAngleUnits() const;

		const Degree& operator + () const { return *this; }
		Degree operator + (const Degree& d) const { return Degree(mDeg + d.mDeg); }
		Degree operator + (const Radian& r) const { return Degree(mDeg + r.valueDegrees()); }
		Degree& operator += (const Degree& d) { mDeg += d.mDeg; return *this; }
		Degree& operator += (const Radian& r) { mDeg += r.valueDegrees(); return *this; }
		Degree operator - () const { return Degree(-mDeg); }
		Degree operator - (const Degree& d) const { return Degree(mDeg - d.mDeg); }
		Degree operator - (const Radian& r) const { return Degree(mDeg - r.valueDegrees()); }
		Degree& operator -= (const Degree& d) { mDeg -= d.mDeg; return *this; }
		Degree& operator -= (const Radian& r) { mDeg -= r.valueDegrees(); return *this; }
		Degree operator * (Real f) const { return Degree(mDeg * f); }
		Degree operator * (const Degree& f) const { return Degree(mDeg * f.mDeg); }
		Degree& operator *= (Real f) { mDeg *= f; return *this; }
		Degree operator / (Real f) const { return Degree(mDeg / f); }
		Degree& operator /= (Real f) { mDeg /= f; return *this; }

		bool operator <  (const Degree& d) const { return mDeg < d.mDeg; }
		bool operator <= (const Degree& d) const { return mDeg <= d.mDeg; }
		bool operator == (const Degree& d) const { return mDeg == d.mDeg; }
		bool operator != (const Degree& d) const { return mDeg != d.mDeg; }
		bool operator >= (const Degree& d) const { return mDeg >= d.mDeg; }
		bool operator >  (const Degree& d) const { return mDeg > d.mDeg; }

		inline  friend std::ostream& operator <<
			(std::ostream& o, const Degree& v)
		{
			o << "Degree(" << v.valueDegrees() << ")";
			return o;
		}
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
		VT_3DVIEW = 1,					// Smart3dMap中的3DView
		VT_2DVIEW_67 = 2,					// 从Mapgis67中继承的视图

		VT_ALL = 0x7FFFFFFF,			// 所有视图类型
	};





	// 参数值对象, 与ParamterDef配合使用，存储参数的值
	class  OGParameterValue
	{
	public:
		string			value;		// 值

		OGParameterValue() {};
		OGParameterValue(const string& newValue) :value(newValue) {}

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

}


