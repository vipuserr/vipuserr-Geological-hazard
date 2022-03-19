#pragma once

#include "s3d_KerMathDef.h"
#include "gmeMdl.h"

namespace Smart3dMap
{
	//�ظ��㴦���:
	#define  SAME_AVE    100
	#define  SAME_SUM    101
	#define  SAME_DEL    102

	typedef struct // ����߳�������Ϣ�ṹ.
	{
		long   nx, ny;
		double xmin, xmax;
		double ymin, ymax;
		double zmin, zmax;
	} DemInfoStrcT;

	// GridIdx: --------------------------- �����������ķ������ඨ����ʵ�� ---------------------------------- //
	//����TIN����������Ч��־ֵ(GRD��Ч��־ֵ):
#define INVALID_TINZVAL	 1.70141e+038 



	typedef struct
	{
		long   xn, yn;  //����X��Y�����.
		double xStart; //����X�����.
		double yStart; //����Y�����.
		double xEnd;   //����X���յ�.
		double yEnd;   //����Y���յ�.
	} GridingStrcT;

	typedef struct
	{
		double	dist;  //�������.
		long	kNo;   //��Ӧ���.
	} DisDtStrcT;  //���������ṹ.

	// ------------------------ ��ɢ�������񻯴����ýṹ���亯�� ------------------------ //
	typedef struct SearchDatStrcT// ������ɢ���������ṹ.
	{
		short  nSeekWay;	// ������ʽ(1\2\3\4-->���е�\K-�ٽ�\�ķ���\�˷���).
		short  nDotPerSec;  // ÿ����ʹ�õ�������.
		short  nMinAllDot;	// ��������ʹ�õ��ܵ���(�����趨�����õ���Ч).
		short  nMaxNullSec; // �������Ŀ�����(��Ч����)��.
		double fRadius;     // �������Բ�뾶(ȱʡΪ���ݵ���С��Χ���ζԽ��ߵ�һ�볤��).

		SearchDatStrcT()
		{
			nSeekWay = 4;
			nDotPerSec = 10;
			nMinAllDot = 3;
			nMaxNullSec = 7;
			fRadius = 0;
		}
	} SearchDatStrcT;

	typedef struct DistInsStrcT
	{
		short	nPower;		// �����ݴ���(ȱʡΪ2).
		double  fSmooth;	// �����ݷ��Ȳ�ֵʱ�Ĺ⻬����(ȱʡΪ0).
		double	fRatio;     // ���ݼ��θ�������֮���������(1). 
		double	fAngl;      // ���ݼ��θ�������֮������X����н�(360���ơ���Ϊ��λ)(0).

		DistInsStrcT()
		{
			nPower = 2;
			fSmooth = 0;
			fRatio = 1;
			fAngl = 0;
		}
	} DistInsStrcT;

	typedef struct KringParmStrcT
	{
		short  nKringTyp;	//�������ֵģ��(0/1/2:��ָ��/����/��״ģ��).
		short  nDrift;		//Ư�ƴ���(0/1/2/3��Ч)(ȱʡΪ0).
		double dfcValue;	//��ֵ̨(ȱʡ��Ϊ�߳����ݵ��ܱ�:(Z-Z��ֵ)��ƽ����).
		double dferrValue;	//�������ЧӦֵ(ȱʡΪ0).
		double dfmErrValue;	//΢�ṹ���ЧӦֵ(ȱʡΪ0).
		double dfRaudisA;   //�������ֵ(Aȱʡ��Ϊ���ݵ���С��Χ���ζԽ��ߵ�һ�볤��).
		double dfRatio;     //���ݸ��򼸺�����֮����(ȱʡΪ1��ʾ���ݸ���ͬ��).
		double dfAngle;		//�����Բ���:������X����н�(ȱʡΪ0).

		KringParmStrcT()
		{
			nKringTyp = 2;
			nDrift = 0;
			dfcValue = 0;
			dferrValue = 0;
			dfmErrValue = 0;
			dfRaudisA = 0;
			dfRatio = 1;
			dfAngle = 0;
		}
	} KringParmStrcT;

	class  LIB_GMKERMATH_EXP CDotGrdIdx	//��ɢ������������ʵ��.
	{
	public:
		CDotGrdIdx();
		~CDotGrdIdx();		//���켰��������.
		void setParam(gme_vector3d* dtXYZPtr, long nDotAll, SearchDatStrcT *PtSdat, gme_D_RECT *fDotRc);

	public:
		short CreateDotGrdIdx(GridingStrcT *grdInfo, double sRadius, double repDotLimit, short repDotProc);
		//���ݵ�ǰ������ż����������б�...
		void getBlkPntNos(long idx, vector<long>& sampDotNos);

		//���˷����������������°˸�����:
		short       GetPointSet0By8Dir(void); //�����ҵ������ݵ���.
		short       GetPointSet1By8Dir(void); //�����ҵ������ݵ���.
		short       GetPointSet2By8Dir(void); //�����ҵ������ݵ���.
		short       GetPointSet3By8Dir(void); //�����ҵ������ݵ���.
		short       GetPointSet4By8Dir(void); //�����ҵ������ݵ���.
		short       GetPointSet5By8Dir(void); //�����ҵ������ݵ���.
		short       GetPointSet6By8Dir(void); //�����ҵ������ݵ���.
		short       GetPointSet7By8Dir(void); //�����ҵ������ݵ���.

					//���ķ������������������ĸ�����:
		short       GetPointSet0By4Dir(void); //�����ҵ������ݵ���.
		short       GetPointSet1By4Dir(void); //�����ҵ������ݵ���.
		short       GetPointSet2By4Dir(void); //�����ҵ������ݵ���.
		short       GetPointSet3By4Dir(void); //�����ҵ������ݵ���.

					//�����������ݵ���������������:
		short       GetPointSet0By1Dir(void); //�����ҵ������ݵ���.


	public:
		void		setDistParam(DistInsStrcT*PtDis);

		void        SetxCosxSinfRatio(double fRatio, double fAng);
		double		xKringGam(short k, short l);
		double		xKringGam(double h);
		void		SetCalxKringGamParam(KringParmStrcT *PtKparm);
		void		FreePtDbIdx(); //�ͷ���������ָ��.

	private:
		void        Insert_kNo(long kNo);

	public:
		gme_vector3d* m_dtXYZPtr;//����ĵ�XYZBUFָ��.
		long		m_lDotAll;	//������ܵ���.
		gme_D_RECT		m_fDotRc0;	//�������ݵķ�Χ.
		SearchDatStrcT *m_PtSdat;//���������ṹָ��.
		DistInsStrcT*   m_PtDistIns;
		KringParmStrcT* m_PtKparm;

	public:
		DisDtStrcT *m_PtDisDot; //������������...
		short       m_nDisDot;
	private:
		short       m_sDn;
		DisDtStrcT *m_cPtdsDt;
		DisDtStrcT  m_tmpDsDt;

	public:
		short       m_offxDn;	//�뾶��X�����������.
		short		m_offyDn;	//�뾶��Y�����������.
		short       m_offXyDn;  //����min(m_offxDn,m_offyDn);
		long		m_xwGdn;	//��ȡ����������. (�������ҷ�Χ������)
		long        m_yhGdn;	//��ȡ����������.
		double		m_xfRadiu; //ÿһ�����������x����
		double		m_yfRadiu; //ÿһ�����������y����

		long		m_CurKno;	//��ǰ������������.
		long		m_CurIx;	//��ǰ������X���±�.
		long		m_CurIy;	//��ǰ������Y���±�.
		double      m_dfCurX;	//��ǰ����Բ��Բ��X.
		double      m_dfCurY;	//��ǰ����Բ��Բ��Y.

	public:
		long       *m_PtPntIdx; //ÿ��֮ǰ������(��ʼ��Ϊ-1).
		long	   *m_PtDbIdx;	//��������ָ��(��ʼ��Ϊ-1). �������������m�������㣬���¼���һ�����������x������x = m_PtPntIdx[x],֪��x=-1Ϊֹ�ҳ���������
								//�����е��������ݺ�... leo
		gme_D_RECT		m_fDotRc;	//�������ݵķ�Χ. ����������η�Χ(����).

	private:
		double      m_fRatio;
		double      m_dx, m_dy;
		double      m_xCos, m_xSin;
	private:
		//Krig�Ĳ�ֵ����
		short       m_nKringTyp;
		double		m_C, m_C0;
		double		m_VarA;
		double		m_VarA2, m_VarA3;
	};



	// ------------------------------- ϡ�����������ܴ����ඨ���뺯�� ---------------------------- //
	// ������TIN�����������ú궨��:
#define  _16PIN		1	//16��˫���β�ֵ.
#define  _4PIN		0	//4 ��˫���Բ�ֵ.

	class LIB_GMKERMATH_EXP DemInsClass //���ܴ����ඨ��.
	{
	public:
		DemInsClass(DemInfoStrcT *demHeadInfo, double *ptDatPtr, short InsType, double *InValidVal = NULL);
		~DemInsClass();	//���졢��������.		
	public:		// ȡ��֪�������е�ǰ��Ĳ��ܸ߳�ֵ:
		double	_GetCurValResult(double x, double y);
		BOOL    _IsValidClass(void);

		// ���ܵ� WINDOWS��INS�ļ���:
		BOOL	_16_4PointInsertToIns(HFILE tpHfile, double dx, double dy);
		// 16��4�����ݼ��ܵ��ڴ滺����/GRD�ļ���:
		double *_16_4PointsInsertToBuf(long curNx, long curNy);



	private:	// ���ܺ���.
		double	CheckValidVal(long iRow, long jCol);
		void	Va(long i, long j);
	private:	//���ܱ���.	
		DemInfoStrcT m_DemHead;  //�������߳�����ͷ����.
		double  m_xDlt, m_yDlt;
		short	m_nInsType;		 //��������;
		double *m_demDatPtr;     //��������ܵĹ���߳�����.
	private:
		double  m_bCurCellValidVal;
		double  m_InValidVal;

		BOOL    m_IsValidFlg;
		BOOL    m_bCheckValidVal;

		double *m_tDemZptr;
		double	A00, A10, A20, A30, A01, A11, A21, A31;
		double	A02, A12, A22, A32, A03, A13, A23, A33;
	};
	typedef class DemInsClass* DemInsOBJ;

	//IDW��������ֵ
	short LIB_GMKERMATH_EXP  _tnDistInsGridingToBuf(gme_vector3d* tmpXyzPtr, long allDatNum, DemInfoStrcT *mHdInf, SearchDatStrcT *PtSdat, DistInsStrcT *PtDis, double *tZptr);
	//Kriging��������ֵ
	short LIB_GMKERMATH_EXP  _tnKringGridingToBuf(gme_vector3d* tmpXyzPtr, long allDatNum, DemInfoStrcT *mHdInf, SearchDatStrcT *PtSdat, KringParmStrcT *PtKparm, double *tZptr);

	//IDW�����ֵ, PtSdat-�������������� PtDis-��ֵ����.
	LIB_GMKERMATH_EXP  void* interp_idw_init(gme_vector3d * pDots, long dotNum, double dRadius=0, SearchDatStrcT *PtSdat = nullptr, DistInsStrcT *PtDis = nullptr);
	int	LIB_GMKERMATH_EXP  interp_idw_pnt(void* interpObj, gme_vector3d &dot);

	//��ͨKriging�����ֵ, PtSdat-�������������� PtKparm-��ֵ����.
	LIB_GMKERMATH_EXP  void* interp_krig_init(gme_vector3d * pDots, long dotNum, SearchDatStrcT *PtSdat = nullptr, KringParmStrcT *PtKparm = nullptr);
	int	LIB_GMKERMATH_EXP  interp_krig_pnt(void* interpObj, gme_vector3d &dot);


	DemInsOBJ LIB_GMKERMATH_EXP _tnGetDemInsOBJ(DemInfoStrcT *demHdInf, double *PtDemDat, short IType, double *InValidVal = NULL);
	short LIB_GMKERMATH_EXP _tnDeleteDemInsOBJ(DemInsOBJ insOBJ);
	// ȡ��֪�������е�ǰ��Ĳ��ܸ߳�ֵ:
	double LIB_GMKERMATH_EXP _tnGetCurPntDemVal(DemInsOBJ insOBJ, double x, double y);
	// 16��4�����ݼ��ܵ��ڴ滺������:
	LIB_GMKERMATH_EXP double* _tnInsDemDatToBuf(DemInsOBJ insOBJ, long curNx, long curNy);


}
