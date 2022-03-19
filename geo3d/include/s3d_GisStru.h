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

#define  FLD_NAME_LEN 	     20			/*�ֶ�������*/
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


//=======================�����������ṹ����===========================//
	typedef enum GM_VECTOR_TYPE
	{
		GM_LIN = 0,
		GM_PNT = 1,
		GM_REG = 2,
	}GM_VECTOR_TYPE;

	//���������Ͷ���
	typedef enum GM_PNT_TYPE
	{
		GM_PNT_NOTE	= 0,
		GM_PNT_SUB	= 1,
		GM_PNT_CIR	= 2,
		GM_PNT_ARC	= 3,
		GM_PNT_IMAGE= 4,
		GM_PNT_TEXT = 5,
	}GM_PNT_TYPE;

	//������ʵ��ͼ����Ϣ�ṹ
	typedef struct GM_PNT_INFO //93bytes
	{
		GM_PNT_INFO()
		{
			memset(this, 0, sizeof(GM_PNT_INFO));
			flag = 1;
		}

		//0-32��33bytes��
		char	flag; //���
		short	strLen;//�ַ�������
		long	strOffset;//�ַ�ƫ����
		_D_3DOT	coord;//����
		char	type;   //�����ͣ�0-�ַ���  1-��ͼ  2-Բ  3-�� 4-ͼ�� 5-�ı���
		char	ovprnt;	//͸�����

		union //33-72��40bytes��
		{
			struct //22bytes
			{
				float  height;	//�߶�
				float  width;   //���
				float  space;   //���
				float  angle;   //�ַ����Ƕȣ���360����Ϊ��λ��ʾ
				short  ifnt;    //��������
				short  chnt;	//��������
				char   ifnx;	//����
				char   hvpl;	//ˮƽ��ֱ����0=ˮƽ���� 1=��ֱ����
			}ch;
			struct //40bytes
			{
				float  height;	//�ı���
				float  width;   //�ı���
				float  space;   //�ּ��(������)
				float  angle;   //��360���ƶ�Ϊ��λ��ʾ
				short  ifnt;    //��������
				short  chnt;	//��������
				char   ifnx;    //����
				float  lspace;	//�м��(������)
				float  dx, dy;	//���泤�Ϳ�
				char   hvpl;	//ˮƽ��ֱ����0=ˮƽ���� 1=��ֱ����
				char	reserve[6]; //Ԥ��
			}text;
			struct //24bytes
			{
				long  subno;	//��ͼ��
				float height;   //�߶�
				float width;    //���
				float angle;    //�Ƕ�
				float penw;     //�߿�(δ��,6.0��ǰΪshort)
				long  fclr;		//����ɫ(δ��)  [short-->long]
			}sub;
			struct //17bytes
			{
				double radiu;	//radiu>0, <=0Ϊ�Ƿ�  [float-->double]
				long   lcol;    //������ɫ�����ɫΪicol [short-->long]
				float  penw;	//�߿�
				char   fflag;	//4.1�濪ʼ 1=���Բ 0=����Բ
			}circle;
			struct //20bytes
			{
				double radiu;    //radiu>0, <=0Ϊ�Ƿ�  [float-->double]
				float  begang;	//��ʼ�Ƕ�
				float  endang;	//��ֹ�Ƕ�
				float  penw;	//�߿��(6.0��ǰΪshort)
			}arc;
			struct //20bytes
			{
				double width;	//ͼ���
				double height;	//ͼ���
				float  angle;	//�Ƕ�(δ��)
			}image;
		}info;

		short   layer;  //ͼ��
		int     iclr;	//����ɫ
		char	reserve[14]; //Ԥ���ֽ�
	}GM_PNT_INFO;


	//������ʵ��ͼ����Ϣ�ṹ
	typedef struct GM_LIN_INFO
	{
		GM_LIN_INFO()
		{
			memset(this, 0, sizeof(GM_LIN_INFO));
			unflag2 = 1;
			reserved[6] = 1;
			reserved[7] = 2;
		}

		char	unkFlag[8];//δ֪
		long	linDotsNum;//��ǰ���ϵ���
		long	linDotsOffset;//��ǰ���ϵ�����Ĵ洢λ��
		long	unflag2; //δ֪

		short   ltp;		//���ͺ�
		char    fltp;       //�������ͺ�
		char    ovprnt;		//���Ƿ�ʽ
		long    lclr;       //����ɫ��
		float   lw;         //�߿�
		char    lclass;		//�����࣬0=���ߡ�1=����������
		float   xscale;		//Xϵ��
		float   yscale;     //Yϵ��
		long    fclr;		//����ɫ
		long	layer;      //ͼ��

		char	reserved[8];//����
	}GM_LIN_INFO;


	
	typedef struct GM_REG_INFO //������ʵ��ͼ����Ϣ�ṹ 40 bytes
	{
		GM_REG_INFO()
		{
			memset(this, 0, sizeof(GM_REG_INFO));
			cExist = 1;
		}

		char	cExist;	//���λ
		long	segNum;	//�����������������������εĵ��������κ��Լ����α߽�֮��ļ��0)
		long	segNoOffset;//���κ����ݴ洢λ��

		long    clr;	  //����ɫ
		short   patno;	  //ͼ����
		float   pathei;	  //ͼ����
		float   patwid;	  //ͼ����
		long    patclr;	  //ͼ����ɫ
		short   basLN;	  //5.32����ǰδ�ã�����=0��5.32�濪ʼ��Ϊ����б�»��ߵĻ�����
		char    fmode;	  //���Ƿ�ʽ���Ƿ�͸����
		short   layer;    //ͼ��

		char	reserved[8];
	}GM_REG_INFO;

	//��ͼ��������:
	//1������ϵ����(GM_MAP_PARA�ṹ��type�ֶ�ֵ)
	typedef enum GM_COORD_TYPE
	{
		GM_TYPE_NOPAR   = 0,	/*�û��Զ�������ϵ*/
		GM_TYPE_JWD		= 1,	/*��������ϵ*/
		GM_TYPE_DD		= 2,	/*�������ϵ*/
		GM_TYPE_PRJ		= 3,	/*ͶӰƽ��ֱ������ϵ*/
		GM_TYPE_XYZ		= 4,	/*���Ĵ��ֱ������ϵ*/
	}GM_COORD_TYPE;


	//2�����굥λ(GM_MAP_PARA�ṹ��unit�ֶ�ֵ)
	typedef enum GM_UNIT_TYPE
	{
		//2.1 ���ȵ�λ
		GM_UNIT_MM			= 0x00,   //����
		GM_UNIT_MilliMeter  = 0x01,   //����
		GM_UNIT_Meter		= 0x02,   //��
		GM_UNIT_Second		= 0x03,   //��
		GM_UNIT_Degree		= 0x04,   //��
		GM_UNIT_DMS			= 0x05,   //�ȷ���,����DDDMMSS.SSSS��ʽ
		GM_UNIT_Foot		= 0x06,   //Ӣ��
		GM_UNIT_Minute		= 0x07,   //��(60��֮һ��)
		GM_UNIT_Radian		= 0x08,   //����
		GM_UNIT_GRAD		= 0x09,   //�ݶ�   1�ݶ�=0.015707963267949����

		GM_UNIT_KM			= 0x0A,   //����
		GM_UNIT_DM			= 0x0B,   //����
		GM_UNIT_CM			= 0x0C,   //����

		GM_UNIT_Inch		= 0x0D,  //Ӣ��
		GM_UNIT_Yard		= 0x0E,  //��
		GM_UNIT_SeaMile		= 0x0F,  //���� 
		GM_UNIT_Mile		= 0x10,  //Ӣ�� 

	//2.2 �����λ
		GM_UNIT_SQ_MM		= 0x20,   //ƽ������(Square Millimeter)
		GM_UNIT_SQ_CM		= 0x21,   //ƽ������(Square Centimeter)
		GM_UNIT_SQ_DM		= 0x22,   //ƽ������(Square Millimeter)
		GM_UNIT_SQ_M		= 0x23,   //ƽ����(Square DeciMeter)
		GM_UNIT_SQ_KM		= 0x24,   //ƽ������(Square KiloMeter)
		GM_UNIT_SQ_Inch		= 0x25,   //ƽ��Ӣ��(Square Inch)
		GM_UNIT_SQ_Foot		= 0x26,   //ƽ��Ӣ��(Square Foot)
		GM_UNIT_SQ_Yard		= 0x27,   //ƽ����(Square Yard)
		GM_UNIT_Are			= 0x28,   //��Ķ(Are)
		GM_UNIT_Acre		= 0x29,   //ӢĶ(Acre)
		GM_UNIT_Hectare		= 0x2A,   //����(Hectare)
		GM_UNIT_SQ_Mile		= 0x2B,   //ƽ��Ӣ��(Square Mile)
	//2.3 �����λ
		GM_UNIT_CU_MM		= 0x40,   //��������(Cubic Millimeter)
		GM_UNIT_CU_CM		= 0x41,   //��������(Cubic Centimeter)
		GM_UNIT_CU_DM		= 0x42,   //��������(Cubic Millimeter)
		GM_UNIT_CU_M		= 0x43,   //������(Cubic DeciMeter)
		GM_UNIT_CU_Inch		= 0x45,   //����Ӣ��(Cubic Inch)
		GM_UNIT_CU_Foot		= 0x46,   //����Ӣ��(Cubic Foot)
		GM_UNIT_CU_Yard		= 0x47,   //������(Cubic Yard)
	}GM_UNIT_TYPE;

	//3���ο��������������(GM_MAP_PARA�ṹ��earthParam�ֶ�ֵ)
	typedef enum GM_EP_TYPE
	{
		GM_EP_UnDefine		= 0,  //δָ��"�ο��������������"
		GM_EP_Beijing54		= 1,  //" 1:����54/��������˹��(1940��)����",  //"Krasovsky"
		GM_EP_Xian80		= 2,  //" 2:����80/1975 ��I.U.G.G�Ƽ����� ", (GM_EP_IUGG1975)
		GM_EP_IUGG1979		= 3,  //" 3:1979 ��I.U.G.G�Ƽ����� ",
		GM_EP_IUGG1983		= 4,  //" 4:1983 ��I.U.G.G�Ƽ�����",
		GM_EP_UserDefine	= 5,  //" 5:�µ��������(�Զ���)   ",
		GM_EP_IUGG1967		= 6,  //" 6:1967 ��I.U.G.G�Ƽ�����",
		GM_EP_WGS84			= 7,  //" 7:WGS-84 ",
		GM_EP_GRS80			= 8,  //" 8:GRS-80 ",
		GM_EP_WGS72			= 9,  //" 9:WGS-72 ",
		GM_EP_Australia1965 = 10, //" 10:�Ĵ�����1965������",
		GM_EP_11			= 11, //" 11:������1910������",
		GM_EP_12			= 12, //" 12:������1880������",
		GM_EP_13			= 13, //" 13:������1866������",
		GM_EP_14			= 14, //" 14:������1841������",
	}GM_EP_TYPE;

	//4��ͶӰ����(GM_MAP_PARA�ṹ��projType�ֶ�)
	typedef enum GM_PRJ_TYPE
	{
		GM_PRJ_LonLat					= 0,   //��������ϵ(��γ��)
		GM_PRJ_UTM						= 1,   //ͨ�ú���ī����ͶӰ����ϵ(UTM)",
		GM_PRJ_Albers_Conical_EQ_Area	= 2,	//�Ƕ���˹�Ȼ�Բ׶ͶӰ����ϵ",ALBERS CONICAL EQUAL AREA
		GM_PRJ_Lambert_Conformal_Conic	= 3,   //�����صȽ�Բ׶ͶӰ����ϵ",LAMBERT CONFORMAL CONIC
		GM_PRJ_Mercator					= 4,   //ī����(����Ƚ�Բ��)ͶӰ����ϵ",MERCATOR
		GM_PRJ_Gauss_Kruger				= 5,   //��˹-������(������Բ���Ƚ�)ͶӰ",GAUSS-KRUGER
		GM_PRJ_Polyconic				= 6,   //��ͨ��Բ׶ͶӰ����ϵ",POLYCONIC
		GM_PRJ_EQ_Dist_Conic			= 7,   //�Ⱦ�Բ׶ͶӰ����ϵ",EQUIDISTANT  CONIC
		GM_PRJ_Transverse_Mecator		= 8,   //����ī����(����Բ���Ƚ�)ͶӰ",TRANSVERSE MECATOR
		GM_PRJ_StereoGraphic			= 9,   //����ͶӰ(�ӵ�������)����ϵ",STEREOGRAPHIC
		GM_PRJ_Lambert_Azimuthal_EQ_Area= 10, //�����صȻ���λͶӰ����ϵ",LAMBERT  AZIMUTHAL EQUAL_AREA
		GM_PRJ_Azimuthal_EQ_Dist		= 11, //�Ⱦ෽λͶӰ����ϵ",AZIMUTHAL EQUIDISTANT
		GM_PRJ_Gnomonic					= 12, //��������(����)ͶӰ����ϵ",GNOMONIC
		GM_PRJ_Orthographic				= 13, //����ͶӰ(�ӵ�����Զ)����ϵ",ORTHOGRAPHIC
		GM_PRJ_General_VER_NS_Perspective= 14, //ͨ�ô�ֱ����͸��(����)ͶӰ",GENERAL VERTICAL NEAR_SIDE PERSPECTIVE
		GM_PRJ_Sinusoidal				= 15, //����ͶӰ(αԲ��)����ϵ",SINUSOIDAL
		GM_PRJ_Equirectangular			= 16, //�Ⱦ�����Բ��(����)ͶӰ����ϵ",EQUIRECTANGULAR
		GM_PRJ_Miller_Cylindrical		= 17, //����Բ��(͸����Բ��)ͶӰ����ϵ",MILLER CYLINDRICAL
		GM_PRJ_V_D_Grinten_I			= 18, //���¸��ֶ�IͶӰ����ϵ",VAN DER  GRINTEN I
		GM_PRJ_Oblique_Mercator			= 19, //б��ī����ͶӰ����ϵ",OBLIQUE MERCATOR (HOTINE)
		GM_PRJ_Polar_Srereographic		= 20, //��������ͶӰ����ϵ",POLAR SREREOGRAPHIC
	}GM_PRJ_TYPE;

	typedef enum GM_ELEVT_TYPE //�߳�ϵ����
	{
		GM_ELEVT_1985		= 0,  //1985 ���Ҹ̻߳�׼  �ൺԭ��߳�72.260�� ��������ϵ��
		GM_ELEVT_1956		= 1,  //1956��ƺ�ƽ����ˮ�� �ൺԭ��߳�72.289�� ��������ϵ��
		GM_ELEVT_1954		= 2,  //1954��ƺ�ƽ����ˮ��
		GM_ELEVT_KANMEN		= 3,  //����ƽ������
		GM_ELEVT_WUSONG		= 4,  //����ƽ������
		GM_ELEVT_DAGU		= 5,  //���ƽ������
		GM_ELEVT_DALIAN		= 6,  //����ƽ������
		GM_ELEVT_LUOXTAZERO = 7,  //���������
		GM_ELEVT_WUSONGZERO = 8,  //�������
		GM_ELEVT_FEIHHEZERO = 9,  //�ϻƺ����
		GM_ELEVT_DAGUZERO	= 10, //������
		GM_ELEVT_ZHUJIANG	= 11, //�齭����
	}GM_ELEVT_TYPE;



typedef struct GM_MAP_PARA //ͶӰ���� 169byts
{
	GM_MAP_PARA()
	{
		memset(this, 0, sizeof(GM_MAP_PARA));
		earthParam = GM_EP_Beijing54;
		infoRatex = 1;
		infoRatey = 1;
	}

	char   type;	//�ռ�����ˮƽ����ϵ���� GM_COORD_TYPE
	char   unit;	//�ռ�����ˮƽ���굥λ,  GM_UNIT_TYPE
	double mapw;	//�ռ�����ͼ�����ۿ�  type����ϵ,unit��λ.
	double maph;	//................��  type����ϵ,unit��λ.

	char   projType;	//�ռ�����ͶӰ���� GM_PRJ_TYPE
	char   earthParam;  //�ռ����ݲο�������������� GM_EP_TYPE
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

	char   levelType;	//�ռ����ݴ��ˮ׼������ GM_ELEVT_TYPE
	double h;		//�ռ����ݴ��ˮ׼����ο�������֮��ĸ߲�, ��λΪ
	double H;		//�ռ�����ͶӰƽ������ˮ׼��ĸ߲�, ��λΪ

	double vRate;	//�ռ����ݴ�������ߵ���
	char   vUnit;	//�ռ����ݴ������ݵ�λ GM_UNIT_TYPE
	char   TICtype;	//TIC����������ϵ���� GM_UNIT_TYPE
	char   TICunit;	//TIC���������굥λ GM_UNIT_TYPE
	char   infoUnit;	//ͼ����ʾ������λ GM_UNIT_TYPE
	double infoRatex;	//ͼ����ʾ������λֵ����ڵ�ǰ���ݵ�λֵ��x����ϵ��, ��ʼֵ���븳0��1
	double infoRatey;	//........................................y����ϵ��, ��ʼֵ���븳0��1
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




typedef struct _GISENV //����Ŀ¼
{
	char clib[128];	//���ֿ�Ŀ¼
	char sys[128];	//ϵͳĿ¼
	char cur[128];	//��ǰ����Ŀ¼
	char temp[128];	//��ʱ����Ŀ¼��������ʹ�ã�
	char slib[128];	//ϵͳ��Ŀ¼

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
	char  CLNFileName[256];		//ͼ���ļ�ȫ·����
	char  CLNFilePath[128];		//ͼ���ļ���·��
	char  CLNName[80];			//ͼ���ļ����ļ���

	_CLNINFO()
	{
		memset(CLNFileName, 0, 256);
		memset(CLNFilePath, 0, 128);
		memset(CLNName, 0, 80);
	}
}_CLNINFO;




typedef struct _PROJECTHEAD //1112bytes
{
	char	prjFileTag[8];//�ļ����
	int		prjFileType;   //�ļ�����
	short	FileNum;				//�ļ���
	_D_RECT Prj_Rect;			//�ļ���ͼ�η�Χ
	_GISENV Env;				//�ļ��Ļ���
	char   Title[60];			//�ļ��ı���
	long   lLayerDictOffset;    //ͼ���ֵ�λ��
	long   lFirstFile;          //���ļ����ָ�� 1113�ֽ�
	//���ҳ�漰λ������
	double  TranX, TranY;     	//λ��
	double  ScaleX, ScaleY;   	//����
	double  Angle;           	//��ת�Ƕ�
	double  VerW, VerH;       	//������
	short  PrjType;
	long   lFirstCLN;			//��ͼ�����ָ��
	GM_MAP_PARA PrjMapParam;		//����Ԥ��ĵ�ͼ����
	char   UnUsed[128];

	_PROJECTHEAD()
	{
		memcpy(prjFileTag, "WMAP`D2:", 8);
		prjFileType = 9; //�̶�ֵ
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

//�����ļ��ڲ����ݽṹ
typedef struct _PROJECTITEM //400bytes
{
public:
	char   Filetype;		//�ļ�����(PNT/LIN/REG/MSIIMG)
	char   FileState;		//�ļ�״̬(0-�ر� / 1-�� 2-�༭ 3-�༭����ǰ���)
	char   Filename[128];   //�ļ���(ȫ·��)
	char   Describe[128];   //�ļ�������
	_D_RECT rect;			//ͼ�㷶Χ...
	char   UserType;		//�û��Զ�������
	char   GroupCode;		
	char   DataSource[32];  //�������ݵ�����Դ(�����ļ�����Ϊ��)
	double MinDispRate;		//��С��ʾ����(<MinDispRate,����ʾ)
	double MaxDispRate;		//�����ʾ����(>MaxDispRate,����ʾ)
	char   NoteFlg;         //��־�Ƿ�����ֶζ�̬��ע,�Լ��Ƿ����Ŵ�
	char   NoteField[21];   //��ע�ֶ�����
	float  NoteHeight;      //��ע�ָ�
	short  NoteColor;       //��ע��ɫ
	char   NoteFont;		//��ע����
	unsigned char  CLNClassCode;	//ͼ��������Ϣ
	char   UnUsed[30];		//����

	_PROJECTITEM()
	{
		Filetype = 0;		//�ļ�����(PNT/LIN/REG/MSIIMG)
		FileState = 2;		//�ļ�״̬(0-�ر� / 1-�� 2-�༭ 3-�༭����ǰ���)
		memset(Filename, 0, 128);   //�ļ���(ȫ·��)
		memset(Describe, 0, 128);   //�ļ�������
		UserType = 0;		//�û��Զ�������
		GroupCode = 0;
		memset(DataSource, 0, 32);  //�������ݵ�����Դ(�����ļ�����Ϊ��)
		MinDispRate = 0;		//��С��ʾ����(<MinDispRate,����ʾ)
		MaxDispRate = 0;		//�����ʾ����(>MaxDispRate,����ʾ)
		NoteFlg = 0;         //��־�Ƿ�����ֶζ�̬��ע,�Լ��Ƿ����Ŵ�
		memset(NoteField, 0, 21);   //��ע�ֶ�����
		NoteHeight = 0;      //��ע�ָ�
		NoteColor = 0;       //��ע��ɫ
		NoteFont = 0;		//��ע����
		CLNClassCode = 0;	//ͼ��������Ϣ
		memset(UnUsed, 0, 30);//����
	}
}_PROJECTITEM;

typedef struct _VECTOR_FILE_HEADER //ʸ���ļ�ͷ... 336+321 = 657bytes
{
	char	fileTag[8];//�ļ�ͷ��ʶ WMAP`D21(WL) WMAP`D22��WT�� WMAP`D23��WP��
	int		vecType; //ʸ������ 0-LIN 1-PNT 2-REG
	int		dataHeaderAddr;	//������ͷ����ʼλ��,���������ָ����ֽ�λ�ô洢������ͷ��Ϣ
	int		reserveTag1;	//δ֪
	char	reserveMemo[71];//δ֪����
	GM_MAP_PARA mapParam;	//ͼ���ļ��ĵ�ͼ����... 169�ֽ�
	int		totalNum[11]; //�洢��11����������ʾ�������ݵ�����,
							//0-����������260-263   104h
							//2 - �ڵ���  268 - 271 10Ch
							//4 - ����    276 - 279 114h
							//����δ֪
	_D_RECT	rect;	//ʸ��ͼ�η�Χ
	char unknownData[321];//��֪����321�ֽ�
	_VECTOR_FILE_HEADER()
	{
		memset(fileTag, 0, 8);
		vecType = 1;//0-LIN 1-PNT 2-REG
		dataHeaderAddr = 657; //sizeof(_VECTOR_FILE_HEADER) + 321=657 bytes
		reserveTag1 = 16; //Ĭ��ֵ
		memset(reserveMemo, 0, 240);
		memset(totalNum, 0, 11*sizeof(int));
		totalNum[8] = 1;
		memset(unknownData, 0, 321);
	}
}_VECTOR_FILE_HEADER;


typedef struct VecHeadInfo //ʸ��ͼ���ļ���������ͷ��Ϣ 10�ֽ�
{
	unsigned long	lDataOffset;//����������ʼλ��
	unsigned long	lDataBytes; //���������ֽ���(nΪͼԪ�������)
	unsigned short	sEndRemark; //������ǣ�0xFFFF��
	VecHeadInfo()
	{
		lDataOffset = 0;
		lDataBytes = 0;
		sEndRemark = 0xFFFF;
	}
}VecHeadInfo;

typedef struct GM_REG_SEG //��������Ϣ
{
	long				 pntNum;		//���߽绡�η�������ܵ���������n�����Σ�mȦ�߽磬n��������һ����d���㣬��rdat[0]=d+m
	vector<vector<long>> segNoList;		//Χ�����ı߽��б�ÿ���߽��ɻ����б���
}GM_REG_SEG;




typedef struct GM_ATTRTBL_HEAD //���Ա�ͷ 348 bytes
{
	char	name1;//0x60
	char	name2;//0x44
	char	date[4];//�ļ���������
	char	name3[6];//0x00
	int		attStruBytes;//���Զ���������ֽ���
	int		objNum;	//��������
	char	name4[4];//0x00
	char	name5[128];//������ǰ�������ļ�ʱ��·��
	char	name6[128];//������·��
	char	name7[40];	//δ֪
	char	name8;//0x60
	char	name9;//0x44
	short	fldNum;//�ֶ�����
	int		rcdNum;//����	��¼����
	short	rcdByts;//ÿ����¼�ֽ���
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

typedef struct GM_Fld_DEF //�ֶζ��� 39 bytes
{
	char	fldName[20];//�ֶ�����
	char	fldType;	//�ֶ�����
	int		fldOffset;//�ֶδ洢ƫ����
	short	fldBytes;//�ֶ��ֽڳ���
	short	fldLength;//�ֶ��ַ�����
	char	decimalLength;//�ֶ�С��λ��
	short	editFlag;//�༭��־(0/1/2=����/��/��ֹ)
	char	printFlg;//��ӡ��־ 0x00
	short	fldNo;	 //�ֶα�ţ���0��ʼ
	int		reserve;//0x00

	GM_Fld_DEF()
	{
		memset(this, 0, sizeof(GM_Fld_DEF));
		editFlag = 1;
	}
}GM_Fld_DEF;



typedef struct GM_LIN_TOP //������������Ϣ
{
	long   stNod;    //��ʼ���
	long   endNod;   //��ֹ���
	long   lPoly;    //����������, ������������
	long   rPoly;    //�����Ҷ����, ������������, rPoly��Ч, ��Ϊ0.
	float  lWeigh;   //��Ȩ
	float  rWeigh;   //��Ȩ
}GM_LIN_TOP;

typedef struct GM_LIN_NODE
{
	_D_DOT	coord;		 //�ڵ�����
	vector<long>	nodeOnLinNos;//�ڵ����ڵ��ߺ��б�.
}GM_LIN_NODE;

typedef struct GM_GRAPH_EXIST //ͼԪ���ڱ�־...
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

//������ʵ��ͼ����Ϣ�ṹ
typedef struct PNT_INFOstruct
{
	char  type;     //������
	char  ovprnt;	//���Ƿ�ʽ
	union
	{
		struct
		{
			float  height;	//�߶�
			float  width;   //���
			float  space;   //���
			float  angle;   //�ַ����Ƕȣ���360����Ϊ��λ��ʾ
			short  ifnt;    //��������
			short  chnt;	//��������
			char   ifnx;	//����
			char   hvpl;	//ˮƽ��ֱ����0=ˮƽ���� 1=��ֱ����
		}ch;
		struct
		{
			float  height;	//
			float  width;   //
			float  space;   //�ּ��(������)
			float  angle;   //��360���ƶ�Ϊ��λ��ʾ
			short  ifnt;    //��������
			short  chnt;	//��������
			char   ifnx;    //����
			float  lspace;	//�м��(������)
			float  dx, dy;	//���泤�Ϳ�
			char   hvpl;	//ˮƽ��ֱ����0=ˮƽ���� 1=��ֱ����
		}text;
		struct
		{
			long  subno;	//��ͼ��
			float height;   //�߶�
			float width;    //���
			float angle;    //�Ƕ�
			float penw;     //�߿�(δ��,6.0��ǰΪshort)
			long  fclr;	//����ɫ(δ��)  [short-->long]
		}sub;
		struct
		{
			double radiu;	//radiu>0, <=0Ϊ�Ƿ�  [float-->double]
			long   lcol;    //������ɫ�����ɫΪicol [short-->long]
			float  penw;	//�߿�(6.0��ǰΪshort)
			char   fflag;	//4.1�濪ʼ 1=���Բ 0=����Բ
		}circle;
		struct
		{
			double radiu;    //radiu>0, <=0Ϊ�Ƿ�  [float-->double]
			float  begang;	//��ʼ�Ƕ�
			float  endang;	//��ֹ�Ƕ�
			float  penw;	//�߿��(6.0��ǰΪshort)
		}arc;
		struct
		{
			double width;	//  [float-->double]
			double height;	//  [float-->double]
			float  angle;	//�Ƕ�(δ��)
		}image;
	}info;
	float	 infoDx;    //	[new, �����ƫ��dx]
	float	 infoDy;    //  [new, �����ƫ��dy]
	long     iclr;	    //  [short-->long]
	long     linNo;	    //���������ߺ�
	short    layer;     //ͼ��
	long     res0;	    //����, ���븳0
	long     res1;	    //����, ���븳0		
	_D_RECT   rect;	    //��Ԫ��Χ
}PNT_INFO;

//������ʵ��ͼ����Ϣ�ṹ
typedef struct LIN_INFOstruct
{
	short   ltp;		//���ͺ�
	char    fltp;           //�������ͺ�
	char    ovprnt;		//���Ƿ�ʽ
	long    lclr;           //����ɫ��  [short-->long]
	float   lw;             //�߿�(6.0��ǰΪchar)
	char    lclass;		//�����࣬0=���ߡ�1=����������
	float   xscale;		//Xϵ��
	float   yscale;         //Yϵ��
	long    fclr;		//����ɫ  [short-->long]
	short   layer;          //ͼ��
	long    res0;		//����, ���븳0
	long    res1;		//����, ���븳0
	_D_RECT  rect;		//��Ԫ��Χ
}LIN_INFO;

//������ʵ��ͼ����Ϣ�ṹ
typedef struct REG_INFOstruct
{
	long    clr;	  //�������ɫ  [short-->long]
	short   patno;	  //
	float   pathei;	  //
	float   patwid;	  //
	long    patclr;	  //  [short-->long]
	short   basLN;	  //5.32����ǰδ�ã�����=0��5.32�濪ʼ��Ϊ����б�»��ߵĻ�������
	char    fmode;	  //���Ƿ�ʽ
	short   layer;    //ͼ��
	long    res0;	  //����, ���븳0
	long    res1;	  //����, ���븳0
	_D_RECT  rect;	  //����Χ
}REG_INFO;

#define TRAN_NULL		0	//�ձ任,(���任)
#define TRAN_MOVE		1   //ƽ��
#define TRAN_ROTATE		2	//��ת
#define TRAN_ENLARGE	3	//����
//  ͼ�α任�����ṹ
typedef struct TRAN_PARstruct
{
	char type[3];	//�任���ͼ��任˳��,����type[0]-->type[1]-->type[2]��˳��任
	char res[5];	//δ��,����
	struct
	{
		double dx;
		double dy;
	}move;
	struct
	{
		double ang;	//360���ƶ�Ϊ��λ��ʾ
	}rotate;
	struct
	{
		double rx;
		double ry;
	}enlarge;
}TRAN_PAR;

#pragma pack(pop)

#endif  // _S3D_GISSTRU_H