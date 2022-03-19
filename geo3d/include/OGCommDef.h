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
	//	GME_TYPE_OBJ_ID	ClsID;//Ҫ����ID��
	//	GME_TYPE_OBJ_ID		DsID; //Ҫ�����ݼ���
	//	GME_TYPE_OBJ_ID	ObjID;//Ҫ�ػ򼸺ζ���ID
	//	short			nObjType;//��������

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
		GME_TYPE_OBJ_ID	FclsID;//Ҫ����ID��
		GME_TYPE_OBJ_ID	FeatID; //Ҫ�����ݼ���
		GME_TYPE_OBJ_ID	GeomID;//Ҫ�ػ򼸺ζ���ID
		GME_TYPE_OBJ_ID	GeomType;//��������

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
		GME_TYPE_OBJ_ID	ClsID;//Ҫ����ID��
		GME_TYPE_OBJ_ID		DsID; //Ҫ�����ݼ���
		GME_TYPE_OBJ_ID	ObjID;//Ҫ�ػ򼸺ζ���ID
		short			nObjType;//��������

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
		Viewport*		pViewport;						// ��ǰ�����ӿ�
		HWND            hWnd;							// ���ھ��
		SceneManager*   pSceneManager;       // ����������
		Camera*			pCamera;						// �����
		RenderWindow*	pRenderWindow;		// ���ƴ���
		void*			ptr;									// ����ʹ��

		OG_WORK_CONTEXT()
		{
			memset(this, 0, sizeof(OG_WORK_CONTEXT));
		}

	};



	//	����������������
	typedef OG_WORK_CONTEXT OGWorkContext;			// ������

	// Ӧ��״̬�������
	typedef DWORD StateHandle;



	// ��ͼ������Ϣ
	enum VIEW_TYPE
	{
		VT_NONE = 0,					// 
		VT_3DVIEW = 1,					// OG�е�3DView
		VT_2DVIEW_67 = 2,					// ��Mapgis67�м̳е���ͼ

		VT_ALL = 0x7FFFFFFF,			// ������ͼ����
	};





	// ����ֵ����, ��ParamterDef���ʹ�ã��洢������ֵ
	class OG_FRAME_DLL OGParameterValue
	{
	public:
		string			value;		// ֵ

		OGParameterValue() {};
		OGParameterValue(const string& newValue) :value(newValue) {}

		//// ���
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

		//// ����
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


#define NOTE_LENGTH	64	//ע�ǳ��ȣ�1�����Լ 600KB
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
		double			m_dX;					//������
		double			m_dY;					//������
		double			m_dValue;				//�����ֶ�ֵ�������ڷֶ�������ͼ������ָ���
		int				m_nFlag;				//�ֶ�����ͼ�����
		char			m_szNote[NOTE_LENGTH];	//��λע��
	};
	//��λ���ݼ���
	typedef std::vector<CSingOGDot>	 vecSubSingOGDot;

	//��ͼ����:
	//1������ϵ����(MAP_PARA�ṹ��type�ֶ�ֵ)
#define TYPE_NOPAR  0	/*�û��Զ�������ϵ*/
#define	TYPE_JWD    1	/*��������ϵ*/
#define TYPE_DD	    2	/*�������ϵ*/
#define TYPE_PRJ    3	/*ͶӰƽ��ֱ������ϵ*/
#define TYPE_XYZ    4	/*���Ĵ��ֱ������ϵ*/


//2�����굥λ(MAP_PARA�ṹ��unit�ֶ�ֵ)
//2.1 ���ȵ�λ
#define UNIT_MM	        0x00   //����
#define UNIT_MilliMeter 0x01   //����
#define UNIT_Meter      0x02   //��
#define UNIT_Second     0x03   //��
#define UNIT_Degree     0x04   //��
#define UNIT_DMS        0x05   //�ȷ���,����DDDMMSS.SSSS��ʽ
#define UNIT_Foot       0x06   //Ӣ��
#define UNIT_Minute     0x07   //��(60��֮һ��)
#define UNIT_Radian     0x08   //����
#define UNIT_GRAD       0x09   //�ݶ�   1�ݶ�=0.015707963267949����

#define UNIT_KM         0x0A   //����
#define UNIT_KiloMeter  0x0A   //����
#define UNIT_DM         0x0B   //����
#define UNIT_DeciMeter  0x0B   //����
#define UNIT_CM         0x0C   //����
#define UNIT_CentiMeter 0x0C   //����

#define UNIT_Inch       0x0D  //Ӣ��
#define UNIT_Yard       0x0E  //��
#define UNIT_SeaMile    0x0F  //���� 
#define UNIT_Mile       0x10  //Ӣ�� 

//2.2 �����λ
#define UNIT_SQ_MM	0x20   //ƽ������(Square Millimeter)
#define UNIT_SQ_CM	0x21   //ƽ������(Square Centimeter)
#define UNIT_SQ_DM	0x22   //ƽ������(Square Millimeter)
#define UNIT_SQ_M	0x23   //ƽ����(Square DeciMeter)
#define UNIT_SQ_KM	0x24   //ƽ������(Square KiloMeter)
#define UNIT_SQ_Inch	0x25   //ƽ��Ӣ��(Square Inch)
#define UNIT_SQ_Foot	0x26   //ƽ��Ӣ��(Square Foot)
#define UNIT_SQ_Yard	0x27   //ƽ����(Square Yard)
#define UNIT_Are	0x28   //��Ķ(Are)
#define UNIT_Acre	0x29   //ӢĶ(Acre)
#define UNIT_Hectare	0x2A   //����(Hectare)
#define UNIT_SQ_Mile	0x2B   //ƽ��Ӣ��(Square Mile)
//2.3 �����λ
#define UNIT_CU_MM	0x40   //��������(Cubic Millimeter)
#define UNIT_CU_CM	0x41   //��������(Cubic Centimeter)
#define UNIT_CU_DM	0x42   //��������(Cubic Millimeter)
#define UNIT_CU_M	0x43   //������(Cubic DeciMeter)
#define UNIT_CU_Inch	0x45   //����Ӣ��(Cubic Inch)
#define UNIT_CU_Foot	0x46   //����Ӣ��(Cubic Foot)
#define UNIT_CU_Yard	0x47   //������(Cubic Yard)


//3���ο��������������(MAP_PARA�ṹ��earthParam�ֶ�ֵ)
#define EP_UnDefine     0  //δָ��"�ο��������������"
#define EP_Beijing54    1  //" 1:����54/��������˹��(1940��)����",  //"Krasovsky"
#define EP_Krasovsky    1  //" 1:����54/��������˹��(1940��)����",  //"Krasovsky"
#define EP_Xian80       2  //" 2:����80/1975 ��I.U.G.G�Ƽ����� ",
#define EP_IUGG1975     2  //" 2:����80/1975 ��I.U.G.G�Ƽ����� ",
#define EP_IUGG1979     3  //" 3:1979 ��I.U.G.G�Ƽ����� ",
#define EP_IUGG1983	4  //" 4:1983 ��I.U.G.G�Ƽ�����",
#define EP_UserDefine   5  //" 5:�µ��������(�Զ���)   ",
#define EP_IUGG1967     6  //" 6:1967 ��I.U.G.G�Ƽ�����",
#define EP_WGS84        7  //" 7:WGS-84 ",
#define EP_GRS80        8  //" 8:GRS-80 ",
#define EP_WGS72        9  //" 9:WGS-72 ",
#define EP_Australia1965 10 //" 10:�Ĵ�����1965������",
//#define EP_     11 //" 11:������1910������",
//#define EP_	12 //" 12:������1880������",
//#define EP_	13 //" 13:������1866������",
//#define EP_	14 //" 14:������1841������",

//4��ͶӰ����(MAP_PARA�ṹ��projType�ֶ�)
#define PRJ_LonLat		    0   //��������ϵ(��γ��)
#define PRJ_UTM			    1   //ͨ�ú���ī����ͶӰ����ϵ(UTM)",
#define PRJ_Albers_Conical_EQ_Area  2	//�Ƕ���˹�Ȼ�Բ׶ͶӰ����ϵ",ALBERS CONICAL EQUAL AREA
#define PRJ_Lambert_Conformal_Conic 3   //�����صȽ�Բ׶ͶӰ����ϵ",LAMBERT CONFORMAL CONIC
#define PRJ_Mercator                4   //ī����(����Ƚ�Բ��)ͶӰ����ϵ",MERCATOR
#define PRJ_Gauss_Kruger	    5   //��˹-������(������Բ���Ƚ�)ͶӰ",GAUSS-KRUGER
#define PRJ_Polyconic		    6   //��ͨ��Բ׶ͶӰ����ϵ",POLYCONIC
#define PRJ_EQ_Dist_Conic	    7   //�Ⱦ�Բ׶ͶӰ����ϵ",EQUIDISTANT  CONIC
#define PRJ_Transverse_Mecator      8   //����ī����(����Բ���Ƚ�)ͶӰ",TRANSVERSE MECATOR
#define PRJ_StereoGraphic	    9   //����ͶӰ(�ӵ�������)����ϵ",STEREOGRAPHIC
#define PRJ_Lambert_Azimuthal_EQ_Area  10 //�����صȻ���λͶӰ����ϵ",LAMBERT  AZIMUTHAL EQUAL_AREA
#define PRJ_Azimuthal_EQ_Dist          11 //�Ⱦ෽λͶӰ����ϵ",AZIMUTHAL EQUIDISTANT
#define PRJ_Gnomonic  	               12 //��������(����)ͶӰ����ϵ",GNOMONIC
#define PRJ_Orthographic	       13 //����ͶӰ(�ӵ�����Զ)����ϵ",ORTHOGRAPHIC
#define PRJ_General_VER_NS_Perspective 14 //ͨ�ô�ֱ����͸��(����)ͶӰ",GENERAL VERTICAL NEAR_SIDE PERSPECTIVE
#define PRJ_Sinusoidal		       15 //����ͶӰ(αԲ��)����ϵ",SINUSOIDAL
#define PRJ_Equirectangular	       16 //�Ⱦ�����Բ��(����)ͶӰ����ϵ",EQUIRECTANGULAR
#define PRJ_Miller_Cylindrical         17 //����Բ��(͸����Բ��)ͶӰ����ϵ",MILLER CYLINDRICAL
#define PRJ_V_D_Grinten_I              18 //���¸��ֶ�IͶӰ����ϵ",VAN DER  GRINTEN I
#define PRJ_Oblique_Mercator           19 //б��ī����ͶӰ����ϵ",OBLIQUE MERCATOR (HOTINE)
#define PRJ_Polar_Srereographic        20 //��������ͶӰ����ϵ",POLAR SREREOGRAPHIC

	typedef struct OG_MAP_PARA
	{
		char   type;	//�ռ�����ˮƽ����ϵ����
		char   unit;	//�ռ�����ˮƽ���굥λ, 
		double mapw;	//�ռ�����ͼ�����ۿ�  type����ϵ,unit��λ.
		double maph;	//................��  type����ϵ,unit��λ.

		char   projType;	//�ռ�����ͶӰ����
		char   earthParam;  //�ռ����ݲο��������������
		double jd0;		//�ռ������������½Ǿ���  , ���ݵ�λͳһ����UNIT_DMS��ʽ
		double wd0;		//�ռ���������......γ��  , ���ݵ�λͳһ����UNIT_DMS��ʽ
		double djd;		//�ռ��������ݾ��ȿ��    , ���ݵ�λͳһ����UNIT_DMS��ʽ
		double dwd;		//�ռ���������γ�ȿ��    , ���ݵ�λͳһ����UNIT_DMS��ʽ
		double rate;	//�ռ���������ˮƽ�����ߵ���, �޵�λ

		double lon;		//�ռ��������뾭�߾���	, ���ݵ�λͳһ����UNIT_DMS��ʽ
		double lon1; 	//�ռ�����˫����1 ����	, ���ݵ�λͳһ����UNIT_DMS��ʽ
		double lon2;        //�ռ�����˫����2 ����	, ���ݵ�λͳһ����UNIT_DMS��ʽ
		double lat;		//�ռ�����ͶӰԭ��γ��	, ���ݵ�λͳһ����UNIT_DMS��ʽ
		double lat1; 	//�ռ�����˫γ��1 γ��	, ���ݵ�λͳһ����UNIT_DMS��ʽ
		double lat2;        //�ռ�����˫γ��2 γ��	, ���ݵ�λͳһ����UNIT_DMS��ʽ
		double dx;		//�ռ�����ͼֽ����ԭ����ͶӰ����ϵ�е�Xƫ��ֵ ,type����ϵ,unit��λ.
		double dy;		//....................................Yƫ��   ,type����ϵ,unit��λ.

		char   levelType;	//�ռ����ݴ��ˮ׼������
		double h;		//�ռ����ݴ��ˮ׼����ο�������֮��ĸ߲�, ��λΪ
		double H;		//�ռ�����ͶӰƽ������ˮ׼��ĸ߲�, ��λΪ

		double vRate;	//�ռ����ݴ�������ߵ���
		char   vUnit;	//�ռ����ݴ������ݵ�λ
		char   TICtype;	//TIC����������ϵ����
		char   TICunit;	//TIC���������굥λ
		char   infoUnit;	//ͼ����ʾ������λ
		double infoRatex;	//ͼ����ʾ������λֵ����ڵ�ǰ���ݵ�λֵ��x����ϵ��, ��ʼֵ���븳0��1
		double infoRatey;	//........................................y����ϵ��, ��ʼֵ���븳0��1
	}MAP_PARA;

	}


#ifndef OG_FRAME_EXPORT 
#pragma comment(lib, "OGFrame.lib")
#endif
