// -----------------------------------------------------------------
//
// Copyright:	ZondySoft 2005
//
// File:		GsStru.h
//
// Project:		GeoStatLib
//
// Creator:		������
//
// Time:		10:22 2004-01-27
//
// Description:	Definitions and Structions of Geological Statistical Library
//
// -----------------------------------------------------------------

#ifndef __GS_STRU_H__
#define __GS_STRU_H__

#define GS_MINVRGPNT    30

#define	GS_MAXNST		20		//���������Ŀ

#define GS_MAXTRIM		1.0e21	//���ݼ���
#define GS_MINTRIM		-1.0e21

#define GS_EPSLON20		1.0e-20	//dpowint
#define GS_EPSLON06		1.0e-6	//nscore
#define GS_EPSLON05		1.0e-5	//powint
#define GS_EPSLON04		1.0e-4	//powint
#define GS_EPSLON03		1.0e-3
#define GS_EPSLON02		1.0e-2	//powint

#define GS_EPSLON12		1.0e-12	//trans

#define GS_MAXINT		pow(2.0f,30) //acorni

#define GS_MAXCAT		24	//trans

#define	GS_PI08			3.141592654	//gamv kt3d	

#define GS_EI06         2.718282		

//bigaus
#define	GS_MLAG			500
#define	GS_MDIR			10

#define	GS_MAXROT		20
#define	GS_DEG2RAD		(GS_PI08/180)
#define	GS_NUM1			100

//kb2d
#define	GS_UNEST		-999
#define	GS_EPSLON10		1.0e-10
#define	GS_MAXDT		9
#define	GS_MAXROT1		(GS_MAXNST+1)

#define GS_MAXVAR		3
#define GS_MXVARG		(GS_MAXVAR*GS_MAXVAR)

#define GS_PMX			999.0

#define GS_MAXCUT		11

#define GS_MAXINTPNUM	max(GS_MAXCUT,GS_MXVARG)

#define GS_MAXCLS		30

#define GS_MAXDIR		5

#define GS_MAXSTA		100

#define GS_UNEST_SIM	(-99.0)
#define GS_MAXROT_SIM	(GS_MAXCUT*GS_MAXNST+1)	//��ת����������Ŀ

#define GS_MAXELP		25		//simulate

#define	GS_KORDEI		(12)
#define	GS_MAXOP1		(GS_KORDEI+1)

//sasim
#define GS_MAXSTOP		10
#define GS_BIGNUM		1.0e10
#define GS_MAXNST02		2
#define GS_MAXOBJ		8
#define GS_MAXPERT		1000
#define GS_KORDEI10		10

#define	GS_TINY			(1E-10)

//scatsmth
#define GS_MAXSMT		1000
#define GS_MAXSML		10
#define GS_MAXCLS1		1000
#define GS_MAXQUA		50
#define GS_MAXLIM		50

//����lhy���
#define GS_MAXVRG       20
#define GS_MV           500


#define  MIN_FLOAT	(-3.402823E+38)
#define  ZERO_FLOAT     (+1.401298E-45)
#define  MAX_FLOAT	(+3.402823E+38)
#define  MIN_DOUBLE	(-1.79769313486232E+307)
#define  ZERO_MIN_DBL   (-4.94065645841247E-324)
#define  ZERO_MAX_DBL   (+4.94065645841247E-324)
#define  MAX_DOUBLE	(+1.79769313486232E+307)

#define ZERO_5BIT 1E-5
#define ZERO_6BIT 1E-6
#define EQUAL_6BIT(a,b) ( fabs(a-b) < ZERO_6BIT )

#define GS_STRLEN       254
#define GS_STRSHORTLEN   20


#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
// --------- struction ---------- //
typedef struct GSD_3DOT
{
	double x;
	double y;
	double z;
}GSD_3DOT;

typedef struct GSD_DOT
{
	double x;
	double y;
}GSD_DOT;

typedef struct GSL_DOT
{
	long x;
	long y;
}GSL_DOT;

typedef struct GSL_3DOT
   {
     long x;
     long y;
     long z;
   }GSL_3DOT;

typedef struct GSD_RECT
{
	double xmin;
	double ymin;
	double xmax;
	double ymax;
}GSD_RECT;

//�Ծ�Ȩֵƽ����
typedef struct ClustSum
{
	double		dCellSiz;
	double		dClustMean;
} ClustSum;

//���ƿ��
typedef struct Block
{
	double	value;		//����ֵ
	double	variance;	//����
} Block;


//��ά���ݰ�Χ��
typedef struct GeoS_3DBOX
{
	double			xmin;
	double			ymin;
	double			zmin;
	double			xmax;
	double			ymax;
	double			zmax;
	
	GeoS_3DBOX() 
		{
		xmin=ymin=zmin=GS_MAXTRIM;
		xmax=ymax=zmax=GS_MINTRIM;
		}
} GS3D_BOX;

//��ɢ��ṹ
typedef struct GsDiscPnt
{
	double	fPosX;		//����
	double	fPosY;
	double	fPosZ;

	double	fAttr;		//����
	double	fSecAttr;
	double	fThiAttr;

	double	fWeight;	//Ȩֵ
	double	fSecWeight;
	double	fThiWeight;

	char    strEngCode[11];
	int     iEngType;
} GsDiscPnt;
//��ɢ��ṹ���򵥣�
typedef struct GsDiscPnt1
{
	double	fPosX;		//����
	double	fPosY;
	double	fPosZ;

	double	fAttr;		//����
	double	fWeight;	//Ȩֵ
	
} GsDiscPnt1;
//��ɢ��������Ч��־
//����ɢ�����ݽṹ��Աһһ��Ӧ. ��ЧΪ1,��ЧΪ0.
typedef struct GsPntFlag
{
	bool	bPosX;			//����
	bool	bPosY;
	bool	bPosZ;

	bool	bAttr;			//����
	bool	bSecAttr;
	bool	bThiAttr;

	bool	bWeight;		//Ȩֵ
	bool	bSecWeight;
	bool	bThiWeight;
} GsPntFlag;

//�������������
typedef struct GsGrid
{
	int		iGridNumX, iGridNumY, iGridNumZ;	//���������������Ŀ
	double	fGridOriX, fGridOriY, fGridOriZ;	//���������������ʼ����(��ʼ����ֱ�Ϊÿ���������С+�����С��һ��)
	double	fGridSizX, fGridSizY, fGridSizZ;	//���������������(Ĭ��Ϊ10)
} GsGrid;

//��������ɢ����������
typedef struct Kt3dSrch
{
	int		iDiscNumX, iDiscNumY, iDiscNumZ;	//��������ÿ���������ɢ�����Ŀ(Ĭ��Ϊ1)
	double	fSrchRadius, fSrchRadius1, fSrchRadius2;	//�����뾶(ȱʡ��Ϊ��ͬ,����Ϊ�Խ��ߵ�һ��)
	double	fSrchAngle1, fSrchAngle2, fSrchAngle3;		//������Բ�ĽǶ�(ȱʡ��Ϊ0)
	int		iMinSrchPntNum;	//��С��������(ȱʡΪ4)
	int		iMaxSrchPntNum;	//�����������(ȱʡΪ8)
} Kt3dSrch;

//ʵ������������
typedef struct GamvParam
{
	int    iLagNum;
	double fLagSize;
	double fLagTol;
	int    iAzm, iDip;
	double fAzmTol, fDipTol;
	double fBandWidthH, fBandWidthV;

}GamvParam;

//�������ֵ����
typedef struct Kt3dIntp
{
	int		iStrNum;				//�׺Ͻṹ����Ŀnst��Ĭ��Ϊ1��
	double	fNugConst;				//�����C0��Ĭ��Ϊ0��
	double	fArchValue[GS_MAXNST];		//����C(�����СΪlStrNum)��Ĭ��Ϊ1��
	int		iModelType[GS_MAXNST];		//����ģ������(�����СΪlStrNum)��Ĭ��Ϊ0��
	double	fChgRang[GS_MAXNST];		//���(�����СΪlStrNum)��Ĭ��������ζԽ���һ�룩
	double	fChgRang1[GS_MAXNST];		
	double	fChgRang2[GS_MAXNST];		
	double	fAnisAng1[GS_MAXNST];		//�������ԵĽǶ�(ȱʡΪ0)
	double	fAnisAng2[GS_MAXNST];
	double	fAnisAng3[GS_MAXNST];
} Kt3dIntp;




//����
typedef struct Variogram
{
	int		lagno;	//�ͺ���
	double	dis;	//�ͺ����
	double	gam;	//����ֵ
	int		nump;	//���ݶ���Ŀ
	double	hm;		//��������ƽ��ֵ
	double	tm;		//�ײ�����ƽ��ֵ
	double	hv;		//��������
	double	tv;		//�ײ�����
} Variogram;

//Model Indicator Variogram
typedef struct ModIndVrg
{
	int		nlagno;	//�ͺ���
	double	h;		//�ͺ����
	double	rop;	//����ֵ
	int		ldir;	//������
	double	ci;
	double	ri;
} ModIndVrg;

//ƽ��ֵ
typedef struct Smooth
{
	double	zvalue;
	double	logzvalue;
	double	pvalue;
} Smooth;

//ͳ����
typedef struct Statistic
{
	double		fAver;
	double		fVari;
	double		fMin;
	double		fMax;	
} Statistic;

//�������ֵ������ݵ�ṹ
typedef struct EstabPnt
{
	double		fPosX;				//x����
	double		fPosY;				//y����
	double		fPosZ;				//z����
	double		dOriVal;			//ԭʼֵ
	double		dEstabVal;			//����ֵ
	double		dEstabVari;			//���Ʒ���
	double		dErr;				//���	
	long        lPntNum;            //�����
	double      fMeanDis;           //��ֵ�㵽�������ƽ������
	int        *piEngType;           //��������
	long       *plEngNum;            //���̸���

} EstabPnt;
typedef struct EstabPnt1
{
	double		fPosX;				//x����
	double		fPosY;				//y����
	double		fPosZ;				//z����
	double		dOriVal;			//ԭʼֵ
 	double		dEstabVal;			//����ֵ
// 	double		dEstabVari;			//���Ʒ���
// 	double		dErr;				//���	
// 	long        lPntNum;            //�����
// 	double      fMeanDis;           //��ֵ�㵽�������ƽ������

} EstabPnt1;
//loacal proportion(using in gtsim)
typedef struct LocalProp
{
	double		*pfLocalProp;
	bool		bUseFlag;
} LocalProp;

//smooth result
typedef struct SmoothResult
{
	double	fValueZ;	//Z-value
	double	fValueP;	//P-value
} SmoothResult;

typedef struct TargActDistr
{
	double		fValue;			//Value
	double		fTargProb;		//Target Probability
	double		fActProb;		//Actual Probability
} TargActDistr;

//�ּ���Ϣ
typedef struct TradOreClasInfo
{
	char  szOreClasName[20];
	long  lPntNum;
	long  lEngNum;
	long  lSrchNum;
}TradOreClasInfo;

typedef struct KrigOreClasInfo
{
	char  szOreClasName[20];
	double fVariVal;
}KrigOreClasInfo;

typedef struct KrigEngNumInfo
{
	int *piEngType;//0���1̽��2�ӵ�3ǳ��
	long *plEngNum;//�������Ͷ�Ӧ�����ݸ���
}KrigEngNumInfo;
//2011.8.25
typedef struct KringParam
{
	double     dMaxData; //���ݼ���ֵ��Ĭ��Ϊ���ֵ��
	double     dMinData; //���ݼ�Сֵ��Ĭ��Ϊ��Сֵ��
    double     fGridSizX;//����Ĵ�С��Ĭ��Ϊ10��
	double     fGridSizY;//����Ĵ�С��Ĭ��Ϊ10��

	Kt3dSrch   gsSrchParam;
	int        noct;     //0Ϊ��ͨ������������Ϊ�˷�Բ������ÿһ������������������
	Kt3dIntp  gsGamvParam;
	KringParam() 
	{
		dMinData = dMaxData = 0;
		fGridSizX = fGridSizY = 10;
		noct = 0;
       
		gsSrchParam.fSrchAngle1 = gsSrchParam.fSrchAngle2= gsSrchParam.fSrchAngle3 = 0;
		gsSrchParam.iDiscNumX = 1;
		gsSrchParam.iDiscNumY = 1;
		gsSrchParam.iDiscNumZ = 1;
		gsSrchParam.iMaxSrchPntNum =8;
		gsSrchParam.iMinSrchPntNum =4;
		gsSrchParam.fSrchRadius = gsSrchParam.fSrchRadius1 =gsSrchParam.fSrchRadius2 = 0;

		gsGamvParam.fAnisAng1[0] = gsGamvParam.fAnisAng2[0] = gsGamvParam.fAnisAng3[0] = 0;
		gsGamvParam.fArchValue[0] = 1;
		gsGamvParam.fNugConst = 0;
		gsGamvParam.fChgRang[0] = gsGamvParam.fChgRang1[0] = gsGamvParam.fChgRang2[0] = 0;
		gsGamvParam.iStrNum = 1;
		gsGamvParam.iModelType[0] = 0;
	}
};
#endif //__GS_STRU_H__