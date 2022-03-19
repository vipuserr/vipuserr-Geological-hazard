#pragma once

namespace Smart3dMap
{

	#define  EXTENT_BUFSIZE    512 //���ݿ���ֽڴ�С


		//=======================�����������ṹ����===========================//
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
	#define	MSIIMG	0x000B	  /*MSIͼ���ļ�*/
	#define	PUB		0x000C	  /*�հ��ļ�*/


	//MapGis��ϢMapGisMessage:
	#define MGM_REDISPGRAPH	    (WM_USER+0x200)
	#define MGM_FLASH_GRAPH	    (WM_USER+0x201)
	#define MGM_LOCKRECORD	    (WM_USER+0x202)
	#define MGM_UPDATERCD	    (WM_USER+0x203) //���µ�ǰ��¼��ʾ
	#define MGM_DESTROY_WND     (WM_USER+0x204) /*����ָ�����ڴ���  wParam=hWnd*/
	#define MGM_DISPLAY_RCD     (WM_USER+0x205) /*��ʾĳһ����¼ lParam=*/


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
	#define  MIN_VALUE		(+1.000000E-20)		    //����ֵС�ڴ�ֵ����Ϊ=0


	#define  MIN_INT		-32768
	#define  MAX_INT		+32767

	#define  MIN_LONG		-2147483648
	#define  MAX_LONG       +2147483647

	#define  MAX_LAYNUM	     2048		/*��������6.2����ǰ��256*/
	#define  SIZE_OF_LAYERPAD    (MAX_LAYNUM/8)	/*����ֽڳ��ȣ�ÿ��һλ*/
	#define  MAX_LAYER_NO	     (MAX_LAYNUM-1)  	/*������*/

	#define  ALIAS_LEN			32			/*�ļ���������*/
	#define  LAYER_NAME_LEN	    11			/*ͼ��������*/


	#ifndef __MAPGIS_VERSION__
	#define __MAPGIS_VERSION__
	#define  VERSION_dos  0x3035		//dos�� �汾��
	#define  VERSION4x 	0x3036		//win16��,4.0,4.1,4.2
	#define  VERSION50	0x4405		//win16��5.0  w32��5.32
	#define  VERSION60	0x4460		//�°汾6.0��
	#define  VERSION70	0x4470		//�°汾7.0��
	#define  VERSION80	0x4480		//�°汾8.0��
	#define  VERSION81	0x4481		//�°汾8.1��
	#define  VERSION82	0x4482		//�°汾8.2��  USB��
	#define  VERSION83	0x4483		//�°汾8.3�棬USB�� 6.6 2004��
	#endif


	#define  VERSION 	VERSION60	//��ǰ�汾����6.0��

		typedef short       AREA_HINST;

		//���ο�
		typedef struct
		{
			float xmin; //leo ע��˳��
			float xmax;
			float ymin;
			float ymax;
		}F_RECT;

		typedef struct
		{
			double xmin; //leo ע��˳��
			double xmax;
			double ymin;
			double ymax;
		}D_RECT;

		//���ڲ���
		typedef struct
		{
			double  x0, y0;  //�ӿ����½�(ԭ��)
			D_RECT  frc;    //��ʾ��Χ
			double  r;      //��ʾ����
		}WIN_ORG;


		//���������Ͷ���
	#define		PNT_TYPE_NUM	6	/*��������*/
	#define		PNT_NOTE	0
	#define		PNT_SUB		1
	#define		PNT_CIR		2
	#define		PNT_ARC		3
	#define		PNT_IMAGE	4
	#define		PNT_TEXT	5
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
			D_RECT   rect;	    //��Ԫ��Χ
		}PNT_INFO;

		//������ֶο���
		typedef struct PNT_PADstruct
		{
			char type;       //������
			char ovprnt;	//���Ƿ�ʽ
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
					char hvpl;	//ˮƽ��ֱ����0=ˮƽ���� 1=��ֱ����
				}ch;
				struct
				{
					char height;	//
					char width;    //
					char space;    //�ּ��
					char angle;    //��360���ƶ�Ϊ��λ��ʾ
					char ifnt;    //
					char chnt;	//
					char ifnx;
					char lspace;	//�м��
					char dx;	//���泤�Ϳ�
					char dy;
					char hvpl;	//ˮƽ��ֱ����0=ˮƽ���� 1=��ֱ����
				}text;
				struct
				{
					char subno;
					char height;
					char width;
					char angle;
					char penw;
					char fclr;	//����ɫ
				}sub;
				struct
				{
					char radiu;  //97.1��֮ǰ radiu<0Ϊ����ԭ >0Ϊʵ��Բ
					char lcol;  //������ɫ
					char penw;
					char fflag;  //97.1�濪ʼ 1=��� 0=�����
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
			char infoDx;    //  [new, �����ƫ��dx]
			char infoDy;    //  [new, �����ƫ��dy]
			char iclr;
			char linNo;
			char layer;
			char res0;	    //����, ���븳0
			char res1;	    //����, ���븳0
			char rect;
		}PNT_PAD;

		typedef union PNT_INFO_UNIONunion
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
				float penw;     //�߿�(δ��)
				long  fclr;	//����ɫ(δ��)  [short-->long]
			}sub;
			struct
			{
				double radiu;	//radiu>0, <=0Ϊ�Ƿ�  [float-->double]
				long   lcol;    //������ɫ�����ɫΪicol [short-->long]
				float  penw;	//�߿�
				char   fflag;	//4.1�濪ʼ 1=���Բ 0=����Բ
			}circle;
			struct
			{
				double radiu;    //radiu>0, <=0Ϊ�Ƿ�  [float-->double]
				float  begang;	//��ʼ�Ƕ�
				float  endang;	//��ֹ�Ƕ�
				float  penw;	//�߿�
			}arc;
			struct
			{
				double width;	//  [float-->double]
				double height;	//  [float-->double]
				float  angle;	//�Ƕ�(δ��)
			}image;
		}PNT_INFO_UNION;
	#define PNT_INFO_UNION_LEN  (sizeof(PNT_INFO_UNION))
	#define PNT_IU_LEN	    (sizeof(PNT_INFO_UNION))


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
			D_RECT  rect;		//��Ԫ��Χ
		}LIN_INFO;

		//�߲����ֶο���
		typedef struct LIN_PADstruct
		{
			char ltp;
			char fltp;
			char ovprnt;	//���Ƿ�ʽ
			char lclr;
			char lw;
			char lclass;
			char xscale;
			char yscale;
			char fclr;
			char layer;    //ͼ��
			char res0;	    //����, ���븳0
			char res1;	    //����, ���븳0
			char rect;
		}LIN_PAD;

		//������ʵ�����˽ṹ
		typedef struct LIN_TOPstruct
		{
			long   stNod;    //��ʼ���
			long   endNod;   //��ֹ���
			long   lPoly;    //����������, ������������
			long   rPoly;    //�����Ҷ����, ������������, rPoly��Ч, ��Ϊ0.
			float  lWeigh;   //��Ȩ
			float  rWeigh;   //��Ȩ
		}LIN_TOP;

		//���绡�η�����Ϣ
		typedef struct
		{
			float   demand;	     //����
			float   demandMeet;    //�����������
			long    allocCenter;   //��������(��һ��NOD_CENTER���ͽ��)
			float   cumuImped;     //�ۻ��谭
			long    preArc;        //ǰһ����
			char    allocDirect;   //���䷽��
		} ARC_ALLOC_INFO;


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
			D_RECT  rect;	  //����Χ
		}REG_INFO;

		//�������ֶο���
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
			char res0;	    //����, ���븳0
			char res1;	    //����, ���븳0
			char rect;
		}REG_PAD;


		//��������ʵ��ͼ����Ϣ�ṹ
		typedef struct NET_INFOstruct
		{
			short   ltp;		//���ͺ�
			char    fltp;           //�������ͺ�
			char    ovprnt;		//���Ƿ�ʽ
			long    lclr;           //��ɫ��  [short-->long]
			float   lw;             //�߿�(6.0��ǰΪchar)
			char    lclass;		//�����࣬0=���ߡ�1=����������
			float   xscale;		//Xϵ��
			float   yscale;         //Yϵ��
			long    fclr;		//����ɫ  [short-->long]
			short   layer;          //ͼ��
			long    res0;		//����, ���븳0
			long    res1;		//����, ���븳0
			D_RECT  rect;		//���緶Χ
		}NET_INFO;
		//��������ֶο���
		typedef struct NET_PADstruct
		{
			char ltp;	//���ͺ�
			char fltp;    //�������ͺ�
			char ovprnt;	//���Ƿ�ʽ
			char lclr;    //��ɫ��
			char lw;    //�߿�
			char lclass;
			char xscale;	//Xϵ��
			char yscale;    //Yϵ��
			char fclr;	//����ɫ
			char layer;    //ͼ��
			char res0;	//����, ���븳0
			char res1;	//����, ���븳0
			char rect;	//���緶Χ
		}NET_PAD;


		//�������Ľ����Ϣ
		typedef struct
		{
			float   limit;	//�޶�
			float   delay;      //�ӳ�
			float   maximped;   //����迹
			float   averimped;  //ƽ���迹
			float   capacity;   //����
			float   perccap;    //��������ٷֱ�
			LIN_INFO linf;	//����Ϣ
		}NOD_CENTER_INFO;

		//������ֹ�����Ϣ
		typedef struct
		{
			float demand;	//����
		}NOD_STOP_INFO;

		//�����ϰ������Ϣ
		typedef struct
		{
			long res;
		}NOD_BARRIER_INFO;

		//���ģ��յ㣬�谭��Ϣ�ṹ
		typedef struct
		{
			unsigned char cOK : 1;	//��������Ϣ��־
			unsigned char sOK : 1;	//���յ���Ϣ��־
			unsigned char bOK : 1;    //���谭��Ϣ��־
			unsigned char res : 5;
			NOD_CENTER_INFO  cInf;	//������Ϣ
			NOD_STOP_INFO    sInf;  //�յ���Ϣ
			NOD_BARRIER_INFO bInf;  //�谭��Ϣ
		}CSB_INF_STRU;

		/*ȡ���
			���: ai    - ���������
			  ni    - �����
			  *xy   - ���ص�λ��
			  **dat - ���ؽ������
			  *len  - ���ؽ����������
			����: >0�ɹ�, =0ʧ�� <0�ѱ�ɾ�� ������ֵ!=0ʱΪ���к궨��֮һ��*/
	#define NOD_COMM	0x0001	/*��ͨ���*/
	#define NOD_GRAPH	0x0002	/*ͼ�ν��*/
	#define NOD_LINK	0x0004	/*��ͨ����*/
	#define NOD_CENTER	0x0008	/*��������*/
	#define NOD_STOP	0x0010	/*����վ��*/
	#define NOD_BARRIER	0x0020	/*�����谭*/
	#define NOD_TURNANG	0x0040	/*ת�Ǿ���*/

			//��ֵ������
	#define BIT_TYPE	0

	//ͼԪʵ����Ϣ�ṹ
		typedef struct
		{
			short ai;      //������
			short type;    //ͼԪ����
			long  elmi;    //ͼԪ��
		}ENTITY_MSG;

		//ͼԪ������ʾ��Ϣ�ṹ
		typedef ENTITY_MSG MGMSG;
		typedef MGMSG    * LPMGMSG;

		//��ʾĳһ�����Լ�¼��Ϣ�ṹ��MGM_DISPLAY_RCD��Ϣ��lParam����
		typedef struct
		{
			short ai;	//������
			short aType;	//��������
			long  rcdI;  //��¼��
		} DISP_RCD_MSG;
		typedef DISP_RCD_MSG FAR * LPDISP_RCD_MSG;

	#define  FLD_NAME_LEN 	     20			/*�ֶ�������*/
	#define  DBIMAXNAMELEN	     31
		typedef struct DATE_STRUstruct
		{
			short  year;	//��
			char   mon;	//��
			char   day;	//��
		}DATE_STRU;
		typedef struct TIME_STRUstruct
		{
			char   hour;	//ʱ
			char   min;	//��
			double sec;	//��
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


		//�������������Ͷ���,0--8,0x10,0x11�ǳ������ͣ�9--0xF,0x12����չ����
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


	//��չ����
	//��������:
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
		//���������ֶ�����Ϊ���½ṹ��
		typedef struct EXT_STRUstruct
		{
			char   type;	  //�ֶ����� TEXT_TYPE/PICTURE_TYPE/MAP_TYPE/SOUND_TYPE/VIDEO_TYPE
			char   dtype;	  //�������� EAL_LIN ... EAL_FLC
			char   fName[254];//��ý�������ļ���
		}EXT_STRU;

		//������������������ֶ�����Ϊ���½ṹ��
		typedef struct
		{
			long   len;	 //�ֶ��ֽ���
			long   off;	 //�ֶ�����λ��
		}BIN_DATA_STRU;

		//������ݿ���Ϣ
		typedef struct
		{
			short keyFldType;			//������ݿ�ؼ��ֶ�����
			char  keyFldName[DBIMAXNAMELEN + 1];	//������ݿ�ؼ��ֶ�����
			char  dbsFName[144];	      	//������ݿ�ؼ��ֶ��������ݿ�
		} EXT_LINK_DB_INFO;

		/*������ݿ�ؼ��ֶ�����Ϊ���½ṹ��
			{
			  1.��Ӧ�ĳ����ֶ����ݣ���LONG_KEY_TYPE�ֶζ�Ӧ�ĳ����ֶ���LONG_TYPE�ֶΣ�
			�ⲿ��ռLONG_LEN���ֽڣ�����ؼ��ֶ�ֵ
			  2.short dbNo;  --������ݿ��ţ���Ӧ��_SetExtDbLinkInfo�����ķ���ֵ
			}
		*/

		typedef struct
		{
			char   fieldname[FLD_NAME_LEN + 1];	//�ֶ�����
		}FIELD_NAME_STR;

		typedef struct
		{
			char clib[128];	//���ֿ�Ŀ¼
			char sys[128];	//ϵͳĿ¼
			char cur[128];	//��ǰ����Ŀ¼
			char temp[128];	//��ʱ����Ŀ¼��������ʹ�ã�
			char slib[128];	//ϵͳ��Ŀ¼
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



		typedef struct MAP_PARAstruct
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

		//���Ƶ�ṹ
		typedef struct
		{
			D_DOT	xy0;	//ͼ������ֵ
			D_DOT	xy1;	//��������ֵ
		}TIC_DOT;

		//��������ṹ
		typedef struct
		{
			char  fldName[FLD_NAME_LEN];	//�ֶ�����
			char  flg;			//���򷽷�  0Ϊ����  1Ϊ����
		} ATT_SORT;
		typedef struct
		{
			short fldNo;	//�ֶκ�
			char  flg; 	//���򷽷�  0Ϊ����  1Ϊ����
		} ATT_SORT1;


		typedef struct
		{
			SQLSMALLINT valueCType;	      //����SQL_C_DOUBLE
			SQLSMALLINT parameterType;      //����SQL_FLOAT
			SQLPOINTER  parameterValuePtr;
		}SQL_BIND_PARAM;


	#define DSN_LEN        31   //SQL_MAX_DSN_LENGTH
	#define LOG_LEN        31
	#define PSW_LEN        31
	#define OWNER_NAME_LEN 31
		typedef struct
		{
			char grpName[31];               //ͼ����������
			char grpDes[129];               //ͼ��������������
			char owner[OWNER_NAME_LEN];     //ͼ�����ݵ�ӵ����
			char dtype;                     //ͼ����������(LIN,REG,PNT,NET)
		}DB_MAP_ITEM_STRU;

		//������Դ���ͣ�
	#define PC_GIS	   0
	#define NET_GIS	   1



	/*�Ƚ����Խṹ���������������ֽ�Ϊ�������ͣ�������ֽ�Ϊ�ֶ���š�
	�����÷����£�
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
	#define ERR_CMP_STRU_recordleng		0x00010000    /*��¼���Ȳ�ͬ*/
	#define ERR_CMP_STRU_numbfield		0x00020000    /*�ֶ�����ͬ*/
	#define ERR_CMP_STRU_fieldname		0x00030000    /*�ֶ�����ͬ*/
	#define ERR_CMP_STRU_fieldtype		0x00040000    /*�ֶ����Ͳ�ͬ*/
	#define ERR_CMP_STRU_fieldlength	0x00050000    /*�ֶγ��Ȳ�ͬ*/
	#define ERR_CMP_STRU_msk_leng		0x00060000    /*�ֶ���ʾ���Ȳ�ͬ*/
	#define ERR_CMP_STRU_point_leng		0x00070000    /*�ֶ�С��λ����ͬ*/
	#define ERR_CMP_STRU_edit_enable	0x00080000    /*�ֶα༭��־��ͬ*/
	#define ERR_CMP_STRU_alias			0x00090000    /*�ֶα�����ͬ*/
	#define ERR_CMP_STRU_IsNull			0x000A0000    /*�ֶ��Ƿ�����Ϊ�ձ�־��ͬ*/
	#define ERR_CMP_STRU_shape			0x000B0000    /*�ֶ���̬��ͬ*/
	#define ERR_CMP_STRU_shapeInfoNum	0x000C0000    /*�ֶ���̬��Ϣ������ͬ*/
	#define ERR_CMP_STRU_shapeInfo		0x000D0000    /*�ֶ���̬��Ϣ��ͬ*/
	#define ERR_CMP_STRU_defVal			0x000E0000    /*�ֶ�ȱʡֵ��ͬ*/
	#define ERR_CMP_STRU_minVal			0x000F0000    /*�ֶ���Сֵ��ͬ*/
	#define ERR_CMP_STRU_maxVal			0x00100000    /*�ֶ����ֵ��ͬ*/



	//ȡ��������������:
	#define COMM_AREA	    0
	#define FAST_AREA	    1
	#define READ_WRITE_AREA	    COMM_AREA
	#define READ_ONLY_AREA	    FAST_AREA


	//�����:
	#define NOT_SYS_FILE	    0	//�Ǳ�ϵͳ�ļ�
	#define NOT_ENOUGH_MEM	    1	//�ڴ治��,��ر����ý���
	#define ERROR_VER	    2	//����İ汾
	#define ERROR_FILE_TYPE	    3	//������ļ�����
	#define	ERROR_OPENFILE      4	//���ļ���
	#define	NOT_ENOUGH_FHANDLE  5   //��ϵͳ��ʱĿ¼�������û��дȨ��
	#define	NOT_ENOUGH_DISK	    6	//û���㹻�Ĵ��̿ռ�
	#define	LINATT_NOTSAME	    7	//�����ļ�  �����Խṹ����ͬ
	#define	PNTATT_NOTSAME	    8	//�����ļ�  �����Խṹ����ͬ
	#define	REGATT_NOTSAME	    9	//�����ļ�  �����Խṹ����ͬ
	#define	NODATT_NOTSAME	    10	//�����ļ�  ������Խṹ����ͬ
	#define	NETATT_NOTSAME      11	//�����ļ�  �������Խṹ����ͬ
	#define	CANNOT_OPEN_SUBGR   12  //���ܴ���ͼ��
	#define	CANNOT_OPEN_FILGR   13  //���ܴ�ͼ����
	#define	CANNOT_OPEN_LINSTY  14  //���ܴ����Ϳ�
	#define	CANNOT_OPEN_COLOR   15  //���ܴ���ɫ��
	#define	CANNOT_OPEN_CCLIB   16  //���ܴ򿪺��ֿ�


	//�ֿ�������Ϣ:
	#define MAPCADLIB    1
	#define WINTTFLIB    2

}