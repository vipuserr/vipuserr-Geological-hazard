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
	// -------------------------- ��洢��ص���ά�������� -------------------------------------- //
#ifdef _MSC_VER
	typedef		__int64							int64;
	typedef     unsigned __int64				uint64;
#else
	typedef		long long				int64;
	typedef     unsigned long long		uint64;
#endif
	//���ݿ�Ҫ����ID����
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

	typedef		int32					GME_TYPE_OBJ_ID; //����ID


	//����Ҫ����ID����
	const GME_TYPE_OBJ_ID  GME_INVALID_FCLS_ID = -1;//��ЧҪ����ID
	const GME_TYPE_OBJ_ID  GME_ACTIVE_FCLS_ID = 0;//��̬Ҫ����

#define  GME_INVALID_OBJ_ID (-999999) //��Чֵ

#define	GME_TEXTURE_NUM   8 //���������ֵ
#define	GME_MAXLIGHT_NUM  8 //�������ƹ���

//��������
#define		GME_MC_ANGPER		(0.01745329251994f)//ÿһ�Ƕ��ж��ٻ���
#define		GME_MC_PIPER		(57.2957804904430f)//ÿһ�����ж��ٽǶ�
#define		GME_MC_PI			(3.14159265358979f)//PI
#define		GME_MC_PI2			(1.57079632679490f)//PI/2
#define		GME_MC_2PI			(6.28318530717959f)//2PI

//����
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




//�ǶȻ���ת��
#define GME_ToRadian( degree ) ((degree) * GME_MC_ANGPER)
#define GME_ToDegree( radian ) ((radian) * GME_MC_PIPER)

//��ɫת��(����ת���㣩
#define GME_COLORVALUE(color)  ((BYTE)(color*(float)255))// ��ɫת����[0.0,1.0]��[0,255]
#define GME_COLORVALUEREV(color)  ((float)(color/255.0f))// ��ɫת����[0,255]��[0.0,1.0]

//RGBA2ARGB
#define GME_COLOR_ARGB(a,r,g,b) ((DWORD)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
#define GME_GLTOD3D_COLOR_RGBA(r,g,b,a) GME_COLOR_ARGB((DWORD)((a)*255.f),(DWORD)((r)*255.f),(DWORD)((g)*255.f),(DWORD)((b)*255.f))
#define GME_GLTOD3D_COLOR_RGB(r,g,b) GME_COLOR_ARGB((DWORD)0xff,(DWORD)((r)*255.f),(DWORD)((g)*255.f),(DWORD)((b)*255.f))
	typedef unsigned int GME_RGBA;
	typedef unsigned int GME_ARGB;
	typedef unsigned int GME_ABGR;
	//�ͷ��ڴ�...
#define GME_SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define GME_SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#define GME_SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }

	typedef enum GME_DIM_TYPE
	{
		GME_DIM_2D = 1,	//��ά
		GME_DIM_3D = 2,	//��ά
	}GME_DIM_TYPE;

	typedef enum GME_ERROR_CODE
	{	//��������������
		GME_ERR_NO_ERROR = 1,	//���سɹ�
		GME_ERR_INVALID_ENUM = 2,		//ö�ٶ������
		GME_ERR_INVALID_VALUE = 3,		//ֵ����
		GME_ERR_INVALID_OPERATION = 4,	//��������
		GME_ERR_STACK_OVERFLOW = 5,		//��ջ����
		GME_ERR_STACK_UNDERFLOW = 6,	//��ջ����
		GME_ERR_OUT_OF_MEMORY = 7,		//�ڴ�Խ��
		GME_ERR_MEM_NEWMEM_FALSE = 701,//�ڴ�����ʧ��NEW
		GME_ERR_INCOMPATIBLE_GL_VERSION = 8,//�汾������
		GME_ERR_PARAMETRIC_ERROR = 9, //��������
		GME_ERR_INPUT_PARAM_INVALID = 901,////����������Ϸ�
		GME_ERR_DATA_IS_NOTEXIST = 10,//���ݲ�����
		GME_ERR_ARRAY_OVERFLOW = 11,  //����Խ��
		GME_ERR_DB_CREATE_ERROR = 101,	//���ݿ��ʧ��
		GME_ERR_DB_OPEN_FAILED = 102,		//���ݿ��ʧ��
		GME_ERR_DB_HAS_EXIST = 103,		//���ݿ��ļ��Ѵ���
		GME_ERR_DB_TEMP_CREATE_ERROR = 104,//��ʱ���ݿⴴ��ʧ��
		GME_ERR_FCLS_CREATE_ERROR = 201,	//Ҫ���ഴ��ʧ��
		GME_ERR_FCLS_HAS_EXIST = 202,		//Ҫ�����Ѵ���
		GME_ERR_FCLS_ATT_CREAT_ERROR = 203,//Ҫ�������Ա���ʧ��
		GME_ERR_FEA_CREATE_ERROR = 301,	//Ҫ�����ʧ��
		GME_ERR_FEA_HAS_EXIST = 302,	//Ҫ���Ѵ���
		GME_ERR_ENT_CREATE_ERROR = 401,	//ʵ�����ʧ��
		GME_ERR_ENT_HAS_EXIST = 402,	//ʵ���Ѵ���
		GME_ERR_ENT_FIELD_OPER_ERROR = 403,	//���Գ�����ʧ��
		GME_ERR_LABEL_OPER_ERROR = 501,	//��ע����ʧ��
		GME_ERR_DEM_OPER_ERROR = 601,	//��������ʧ��
		GME_ERR_LEGEND_OPER_ERROR = 701,//����ͼ��ʧ��
		GME_ERR_SERIES_OPER_ERROR = 801,//������׼�ز�ʧ��
		GME_ERR_GEOREF_OPER_ERROR = 901,//�����ռ�ο�ϵʧ��
	}GME_ERROR_CODE;

	//���ռ������ᶨ��
	typedef enum GME_SPACE_AXIS_DIR
	{
		GME_SAD_NONE = -1,		// ��;
		GME_SAD_ZERO = 0,		// ԭ��
		GME_SAD_X = 1,			// X������
		GME_SAD_Y = 2,			// Y������
		GME_SAD_Z = 3,			// Z������
		GME_SAD_NX = 4,			// X������
		GME_SAD_NY = 5,			// Y������
		GME_SAD_NZ = 6,			// Z������
	}GME_SPACE_AXIS_DIR;

	//Ҫ��������
	typedef enum GME_FCLS_TYPE
	{
		GME_FCLS_TYPE_COMM = 0,		//��ͨҪ���ࣨ����ID��Name��������һ�㼸��ʵ�塢���Ρ�ע�ǵ�

		GME_FCLS_TYPE_GEO_PNT = 1,	//���ʵ�
		GME_FCLS_TYPE_GEO_ORI_PNT = 2,//��״��
		GME_FCLS_TYPE_GEO_LIN = 3,	  //������
		GME_FCLS_TYPE_GEO_SURF = 4,	  //������
		GME_FCLS_TYPE_GEO_ENT = 5,	  //������
		GME_FCLS_TYPE_GEO_HOLE = 6,	  //���
		GME_FCLS_TYPE_GEO_FAULT = 7,  //�ϲ�

		GME_FCLS_TYPE_DEM = 8,	   //����
		GME_FCLS_TYPE_FIELD = 9,	  //���Գ�
		GME_FCLS_TYPE_BOLT = 10,   //ê��
		GME_FCLS_TYPE_PILE = 11, //׮��
		GME_FCLS_TYPE_BUILD = 12,  // ������
	}GME_FCLS_TYPE;

	//���ݿ���������
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


	//����IO��������
	typedef enum GME_MDL_IO_TYPE
	{
		GME_MDL_IO_UNKNOWN = 0,
		GME_MDL_IO_DB = 1,
		GME_MDL_IO_TMP = 2,
	}GME_MDL_IO_TYPE;


	typedef enum GME_DATA_TYPE
	{
		//�����ֶ����Ͷ���
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
		GME_DATA_TYPE_TEXT = 21, //sqlite���е���������.
		GME_DATA_TYPE_INT = 22,
		GME_DATA_TYPE_REAL = 23,
		GME_DATA_TYPE_BLOB = 24,
	}GME_DATA_TYPE;


	typedef	enum GME_OBJ_TYPE
	{
		//�����洢�ṹ��Ϣ
		GME_OT_INVALID_TYPE = 0,

		//����ʵ��
		GME_OT_CORNER = 101, //���
		GME_OT_LINE = 102,   //��
		GME_OT_SURFACE = 103,//��
		GME_OT_ENTITY = 104,//��
		GME_OT_FIELD = 105, //���Գ�
		GME_OT_DEM = 106,   //DEM
		GME_OT_NOTE = 107,  //ע��
		GME_OT_SERIES = 108,//��׼�ز�
		GME_OT_MATLIB = 109,//����
		GME_OT_GEOREF = 110,//�ο�ϵ
		GME_OT_OCTFIELD = 111,//�˲������Գ�

		//����ʵ��
		GME_OT_GEO_POINT = 201,
		GME_OT_GEO_ORI_POINT = 202,
		GME_OT_GEO_LINE = 203,
		GME_OT_GEO_SURFACE = 204,
		GME_OT_GEO_ENTITY = 205,
		GME_OT_GEO_FAULT = 206,
		GME_OT_GEO_HOLE = 207,

		//�����������Ԫ��
		GME_OT_POINT = 301,  //����
		GME_OT_EDGE = 302,  //��
		GME_OT_FACET = 303,  //��Ƭ�������Σ�
		GME_OT_VOLCELL = 304, //��Ԫ

		//������������Ϣ
		GME_OT_VEX_DECORATION = 401,   //��������
		GME_OT_VEX_NORMAL = 402,   //���㷨����
		GME_OT_VEX_DIFFCOLOR = 403,//������ɫ
		GME_OT_VEX_TEXCOORD1 = 404,//�����һ����������ϵ��
		GME_OT_VEX_TEXCOORD2 = 405,
		GME_OT_VEX_TEXCOORD3 = 406,
		GME_OT_VEX_TEXCOORD4 = 407,
		GME_OT_VEX_TEXCOORD5 = 408,
		GME_OT_VEX_TEXCOORD6 = 409,
		GME_OT_VEX_TEXCOORD7 = 410,
		GME_OT_VEX_TEXCOORD8 = 411,//����ڰ˲���������ϵ��

		GME_OT_SUR_DECORATION = 420, //��������Ϣ
		GME_OT_TRI_MTLLIST = 421,//������������
		GME_OT_TRI_TEXLIST1 = 422,//��ĵ�һ�������������1
		GME_OT_TRI_TEXLIST2 = 423,
		GME_OT_TRI_TEXLIST3 = 424,
		GME_OT_TRI_TEXLIST4 = 425,
		GME_OT_TRI_TEXLIST5 = 426,
		GME_OT_TRI_TEXLIST6 = 427,
		GME_OT_TRI_TEXLIST7 = 428,
		GME_OT_TRI_TEXLIST8 = 429,

		GME_OT_TYPE_MTL = 430,

		//Ҫ��
		GME_OT_FCLS = 501,//Ҫ����
		GME_OT_FEATURE = 502,//Ҫ��
		GME_OT_RELATION = 503,//Ҫ��֮��Ĺ�ϵ
		GME_OT_ATT_TBL = 504,//Ҫ�����Ա�

		//�����洢
		GME_OT_SYS_PARAM = 601,
		GME_OT_USER_PARAM = 602,
		GME_OT_TEMP_PARAM = 603,
		GME_OT_IDX = 604,
	}GME_OBJ_TYPE;

	typedef enum GME_SURF_TYPE//������
	{
		SUR_TYPE_INIT = 0x0000, //δ֪
		SUR_TYPE_TOP = 0x0001,//����
		SUR_TYPE_BTM = 0x0002,//����
		SUR_TYPE_SIDE = 0x0004, //����
		SUR_TYPE_OUTSIDE = 0x0008, //�����
	}GME_SURF_TYPE;

	typedef enum GME_GROUND_MODE//�������ģʽ
	{
		GME_CLOSE_TO_GROUND = 1,		//��������
		GME_RALETIVE_TO_GROUND = 2,	//����ڵ���
		GME_ABSOLUTE = 3,				//����
	}GME_GROUND_MODE;

	typedef enum GME_VOLUME_TYPE //���Գ�����
	{
		GME_NONE = 0,   //������
		GME_SCALAR = 1, //������
		GME_VECTOR = 2, //ʸ����
		GME_TENSOR = 3,  //������
	}GME_VOLUME_TYPE;

	typedef enum GME_VOLUME_CELL_TYPE //��Ԫ����
	{
		GME_CT_TET = 1,	 //���������壩
		GME_CT_CUBE = 2, //�����������壩
	}GME_VOLUME_CELL_TYPE;

	typedef enum GME_MATERIAL_TYPE //��������
	{
		GME_MT_NONE = 0, //��
		GME_MT_COLOR = 1,//��ɫ����
		GME_MT_TEXTURE = 2,//�������
	}GME_MATERIAL_TYPE;

	typedef enum GME_MATERIAL_SIDE //������ͼ����
	{
		GME_MS_POSITIVE = 1, //�������
		GME_MS_NEGATIVE = 2, //�������
	}GME_MATERIAL_SIDE;

	typedef enum GME_LEGEND_TYPE //ͼ������
	{
		GME_LT_SYMBOL = 1,	//������
		GME_LT_COLOR = 2,	//��ɫ����
		GME_LT_COLORTBL = 3,//ɫ��
	}GME_LEGEND_TYPE;

	typedef enum GME_MODEL_TYPE //ģ������
	{
		GME_MT_GEO_UNKNOWN_MDL = 0,	//��ͨģ��
		GME_MT_GEO_STRUCT_MDL = 1,	//�ṹģ��
		GME_MT_GEO_FIELD_MDL = 2,	//����ģ��
		GME_MT_GEO_HOLE_MDL = 3,	//���ģ��
		GME_MT_GEO_SECTION_MDL = 4,	//����ģ��
		GME_MT_GEO_GEOMAP_MDL = 5,	//����ͼģ��
		GME_MT_GEO_FAULT_MDL = 6,	//�ϲ�ģ��
	}GME_MODEL_TYPE;

	typedef enum GME_FIELD_SPLIT_TYPE //���Գ��ʷ�����
	{
		GME_FST_AVARAGE = 1, //�����ʷ�
		GME_MT_NOAVARAGE = 2,//�������ʷ�
	}GME_FIELD_SPLIT_TYPE;

	typedef enum GME_FAULT_TYPE //�ϲ�����
	{
		GME_FT_NORMAL_FAULT = 1, //���ϲ�
		GME_FT_INVERSE_FAULT = 2, //��ϲ�
		GME_FT_STRIKESLIP_FAULT = 3, //�߻��ϲ�
	}GME_FAULT_TYPE;

	typedef enum GME_FEATURE_RELATION_TYPE //���ʶ����ϵ����
	{
		GME_FRT_LAYER2LAYER = 1, //
		GME_FRT_LAYER2FAULT = 2, //
		GME_FRT_FAULT2FAULT = 3, //
		GME_FRT_INTRUSIVEBODY2LAYER = 4,
		//changchan
	}GME_FEATURE_RELATION_TYPE;
	typedef enum GME_FEATURE_RELATION_VALUE //���ʶ����ϵ
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


	typedef enum GME_GEO_DIP_TYPE //�������
	{
		GME_GDT_REAL_DIP = 1,		//�����
		GME_GDT_REAL_APPARENT = 2,	//�����
	}GME_GEO_DIP_TYPE;

	typedef enum GME_NOTE_DISP_TYPE //ע����ʾ��ʽ
	{
		GME_NDT_RALETIVE_TO_GROUND = 1, //����ڵ���
		GME_NDT_ABSOLUTE = 2,			//����
	}GME_NOTE_DISP_TYPE;











	// ---------------------- �볡�����ӻ���ص�enum���� -------------------- //
	typedef		long				GME_SCENE_TEXIDXNO;
	//����ͨ��
	typedef enum GME_TEXTURE_STAGE
	{
		GME_TSN_1 = 0,	    //��1����ͨ��
		GME_TSN_2 = 1, 		//��2����ͨ��
		GME_TSN_3 = 2,		//��3����ͨ��
		GME_TSN_4 = 3,		//��4����ͨ��
		GME_TSN_5 = 4,		//��5����ͨ��
		GME_TSN_6 = 5,		//��6����ͨ��
		GME_TSN_7 = 6,		//��7����ͨ��
		GME_TSN_8 = 7,		//��8����ͨ��
	}GME_TEXTURE_STAGE;

	//����ͨ��
	typedef enum GME_LIGHT_STAGE
	{
		GME_LSN_1 = 0,	    //��1����ͨ��
		GME_LSN_2 = 1, 		//��2����ͨ��
		GME_LSN_3 = 2,		//��3����ͨ��
		GME_LSN_4 = 3,		//��4����ͨ��
		GME_LSN_5 = 4,		//��5����ͨ��
		GME_LSN_6 = 5,		//��6����ͨ��
		GME_LSN_7 = 6,		//��7����ͨ��
		GME_LSN_8 = 7,		//��8����ͨ��
	}GME_LIGHT_STAGE;

	//��������
	typedef enum GME_ENUM_PARAM_TYPE
	{
		GME_PARAM_TYPE_SYS = 1,//ϵͳ����
		GME_PARAM_TYPE_USER = 2,//�û�����
		GME_PARAM_TYPE_DYNAMIC = 3,//��̬����
	}GME_ENUM_PARAM_TYPE;

	typedef enum GME_ENGINE_TYPE //������������
	{
		GME_ET_NONE = -1,	//��
		GME_ET_OSG = 1,		//OSG����
		GME_ET_OPENGL = 2,	//OpenGL����
		GME_ET_D3D = 3,		//D3D����
	}GME_ENGINE_TYPE;

	typedef enum GME_SCENE_COORD_TYPE
	{
		//����ϵ���Ͷ���
		GME_COORDTYPE_RH_XUP = 1,//x�ᳯ�ϵ���������ϵ
		GME_COORDTYPE_RH_YUP = 2,//y�ᳯ�ϵ���������ϵ
		GME_COORDTYPE_RH_ZUP = 3,//z�ᳯ�ϵ���������ϵ(OpenGL\OSGĬ��)
		GME_COORDTYPE_LH_XUP = 4,//x�ᳯ�ϵ���������ϵ
		GME_COORDTYPE_LH_YUP = 5,//y�ᳯ�ϵ���������ϵ
		GME_COORDTYPE_LH_ZUP = 6,//z�ᳯ�ϵ���������ϵ(D3DĬ��)
	}GME_SCENE_COORD_TYPE;

	typedef enum GME_RANK_TYPE
	{
		// �״�����
		GME_RANK_0 = 0,		//0�״�
		GME_RANK_1 = 1,		//1�״�
		GME_RANK_2 = 2,		//2�״�
	}GME_RANK_TYPE;

	typedef enum GME_ENABLE_VAR //���ؿ�����
	{
		GME_FOG = 1,		//��
		GME_LIGHTING = 2,	//����
		GME_TEXTURE_2D = 3,	//2D����
		GME_CULL_FACE = 4,	//���������βü�
		GME_ALPHA_TEST = 5,	//Alpha����
		GME_BLEND = 6,			//�ں�
		GME_DITHER = 7,			//����
		GME_STENCIL_TEST = 8,	//ģ�����
		GME_DEPTH_TEST = 9,		//��Ȳ���
		GME_SCISSOR_TEST = 10,	//�ɼ������
		GME_COLOR_MATERIAL = 11,//������ɫ���ٵ�ǰ��ɫ
		GME_STEREO = 12,		//����ģʽ
		GME_DETAIL_TEXTURE = 13,//ϸ������
	}GME_ENABLE_VAR;

	//���Ժ�������
	typedef enum GME_TEST_FUNC
	{
		GME_NEVER = 1,	//��ͨ��
		GME_LESS = 2,	//С����ͨ��
		GME_EQUAL = 3,	//������ͨ��
		GME_LEQUAL = 4,	//С�ڵ�����ͨ��
		GME_GREATER = 5,	//������ͨ��
		GME_NOTEQUAL = 6,	//������ͨ��
		GME_GEQUAL = 7,	//���ڵ�����ͨ��
		GME_ALWAYS = 8,	//����ͨ��
	}GME_TEST_FUNC;


	typedef enum GME_VERTEX_FORMAT //���㻺������ʽ
	{
		//OpenGL��ʽ.
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

		//D3D��ʽ.		  
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

	typedef enum GME_TEXTURE_FORMAT //�������ظ�ʽ
	{
		GME_PF_RGB8 = 1,//OpenGL.  3 Bytes.
		GME_PF_RGB5_A1 = 2,//OpenGL.  2 Bytes.
		GME_PF_RGBA8 = 3,//OpenGL.  4 Bytes.
		GME_PF_RGB_ARB = 4,//OpenGLѹ����ʽ(24λ).
		GME_PF_RGBA_ARB = 5,//OpenGLѹ����ʽ(32λ).

		GME_PF_R5G6B5 = 6,//D3D��ʽ. 2 Bytes.
		GME_PF_A1_RGB5 = 7,//D3D��ʽ. 2 Bytes.
		GME_PF_BGRA8 = 8,//D3D��ʽ. 4 Bytes.
		GME_PF_ARGB8 = 9,//D3D��ʽ. 4 Bytes.
		GME_PF_XRGB8 = 10,//D3D��ʽ. 4 Bytes.
		GME_PF_DXT1_24 = 11,	//����ѹ����ʽDXT1
		GME_PF_DXT1_32 = 12,	//����ѹ����ʽDXT1
		GME_PF_DXT2 = 13,	//����ѹ����ʽDXT2
		GME_PF_DXT3 = 14,	//����ѹ����ʽDXT3
		GME_PF_DXT4 = 15,	//����ѹ����ʽDXT4
		GME_PF_DXT5 = 16,	//����ѹ����ʽDXT5
	}GME_TEXTURE_FORMAT;

	typedef enum GME_FOG_TYPE
	{	//�������
		GME_FT_VERTEX_FOG = 1, //������
		GME_FT_PIXEL_FOG = 2,  //������
	}GME_FOG_TYPE;
	typedef enum GME_FOG_MODE
	{	//���ģʽ	
		GME_EXP = 1, //����
		GME_EXP2 = 2, //����
		GME_LINEAR = 3, //����
	}GME_FOG_MODE;

	typedef enum GME_LIGHT_TYPE //��Դ����
	{
		GME_LIGHT_POINT = 1,		//���Դ
		GME_LIGHT_DIRECTIONAL = 2,	//�����Դ
		GME_LIGHT_SPOT = 2,			//�۹�ƣ��ֵ磩
	}GME_LIGHT_TYPE;

	typedef enum GME_LIGHTING_DIR //���շ���
	{
		GME_LD_FRONT = 1,			//�������
		GME_LD_BACK = 2,			//�������
		GME_LD_FRONT_AND_BACK = 3, //˫�����
	}GME_LIGHTING_DIR;

	typedef enum GME_LIGHT_MODEL //����ģ��
	{
		GME_LM_LAMBERT = 1,
		GME_LM_PHONE = 2,
		GME_LM_OTHERS = 3,
	}GME_LIGHT_MODEL;

	typedef enum GME_FILL_MODE//���ģʽ
	{
		GME_FILL_POINT = 1,		//�㷽ʽ
		GME_FILL_WIREFRAME = 2,	//�߷�ʽ
		GME_FILL_SOLID = 3,		//�淽ʽ
		GME_FILL_LIN_SOLID = 4, //��+�淽ʽ
		GME_FILL_PNT_LIN = 5, //��+�߷�ʽ
		GME_FILL_PNT_SOLID = 6, //��+�淽ʽ
	}GME_FILL_MODE;

	typedef enum GME_CULL_MODE//������ѡģʽ
	{
		GME_CULL_NONE = 1,	//��
		GME_CULL_CW = 2,	//˳ʱ��
		GME_CULL_CCW = 3,	//��ʱ��
	}GME_CULLMODE;

	typedef enum GME_DRAW_TYPE //����ͼԪ����
	{
		GME_DT_POINTS = 1,	//���Ƶ�
		GME_DT_LINES = 2,		//�����߶�
		GME_DT_LINES_STRIP = 3,//�����߶�
		GME_DT_LINES_LOOP = 4,//�����߻�
		GME_DT_TRIANGLE = 5,	//����������
		GME_DT_TRIANGLE_STRIP = 6,//��������������
		GME_DT_TRIANGLE_FAN = 7,//������������
		GME_DT_QUADS = 8,		//�����ı���
		GME_DT_QUAD_STRIP = 9,	//�����ı��δ�
		GME_DT_POLYGON = 10,	//���ƶ����
	}GME_DRAW_TYPE;

	typedef enum GME_SHADE_MODEL //��ɫ����ģʽ
	{
		GME_SM_FLAT = 1,		//ƽ̹����ģʽ
		GME_SM_SMOOTH = 2,		//�⻬����ģʽ
	}GME_SHADE_MODEL;

	typedef enum GME_RENDERING_MODE //����ģʽ
	{
		GME_RM_RENDER = 1,	//����
		GME_RM_FEEDBACK = 2,//����
		GME_RM_SELECT = 3,	//ʰȡ
	}GME_RENDERING_MODE;

	typedef enum GME_TEXTUREENV_MODE	//������ģʽ
	{
		GME_TM_MODULATE = 1,//����ģʽ
		GME_TM_DECAL = 2,	//��ͼ
	}GME_TEXTUREENVMODE;
	typedef enum GME_TEXTUREGENMODE	//������������ģʽ
	{
		GME_EYE_LINEAR = 1,	//
		GME_OBJECT_LINEAR = 2,//
		GME_SPHERE_MAP = 3,	//
	}GME_TEXTUREGENMODE;
	typedef enum GME_TEXTURE_FILTER		//����������˲�������
	{
		GME_NEAREST_FILTER = 1,	//���ģʽ
		GME_LINEAR_FILTER = 2,	//����ģʽ
		GME_ANISOTROPIC_FILTER = 3,  // ��������ģʽ
		GME_FLATCUBIC_FILTER = 4,    // cubic
		GME_GAUSSIANCUBIC_FILTER = 5,// different cubic kernel
	}GME_TEXTURE_FILTER;
	typedef enum GME_TEXTURE_WRAPMODE	//�������ģʽ
	{
		GME_CLAMP = 1,	// ����
		GME_REPEAT = 2,	// �ظ�		   
		GME_MIRROR = 3,	// �����ظ�
		GME_BORDER = 4,	// �߿���ɫ��չ
		GME_MIRRORONCE = 5,	//
	}GME_TEXTURE_WRAPMODE;

	typedef enum GME_BLEND_FACTOR	//�ں�����
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

	typedef enum GME_ANTI_ALIASING	//���������
	{
		// OpenGL
		GME_POINT_SMOOTH = 1,		//��⻬
		GME_LINE_SMOOTH = 2,		//�߹⻬
		GME_POLYGON_SMOOTH = 3,		//����ι⻬
		// D3D
		GME_EDGE_ANTIALIASING = 4,		//��Ե������
		GME_FULLSCREEN_ANTIALIASING = 5,//ȫ��������

	}GME_ANTI_ALIASING;


	typedef enum GME_FONT_DRAW_TYPE	//�����������
	{
		GME_2D_FONT = 1,		//��ά����
		GME_3D_FONT = 2,		//��ά����
		GME_2D_VIEWSCALE_FONT = 3,//��ά�ӿ���������
	}GME_FONT_DRAW_TYPE;

	typedef enum GME_SUPPORT_FILE_TYPE //ϵͳ֧�ֵ��ļ�����
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


	typedef enum GME_RENDER_BUFFER //ϵͳ֧�ֵ���Ⱦ����
	{
		GME_RENDER_LEFT = 0,
		GME_RENDER_RIGHT = 1,
	}GME_RENDER_BUFFER;


	typedef enum GME_HINT_TARGET	//���л��ƿ�����ʾ��Ŀ������
	{
		GME_FOG_HINT = 1,	// ����������ľ�ȷ��
		GME_POINT_SMOOTH_HINT = 2,	// �ߵķ�������������
		GME_LINE_SMOOTH_HINT = 3,	// ��ɫ����������Ĳ�ֵ������
		GME_POLYGON_SMOOTH_HINT = 4,	// ��ķ�������������
		GME_PERSPECTIVE_CORRECTION_HINT = 5,	// ����εķ�������������
	}GME_HINT_TARGET;

	typedef enum GME_HINT_MODE	// ���л��ƿ�����ʾ��Ŀ����Ϊ
	{
		GME_FASTEST = 1,	// ��ͼ�ٶȺ�Ч������
		GME_NICEST = 2,		// ѡ������ȷ
		GME_DONT_CARE = 3,	// ������ѡ��
	}GME_HINT_MODE;

}

#endif