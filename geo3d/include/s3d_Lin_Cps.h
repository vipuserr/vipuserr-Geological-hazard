#pragma once


#include "s3d_KerMathDef.h"
#include "s3d_GisStru.h"
#include "gmeStru.h"




namespace Smart3dMap
{

class LIB_GMKERMATH_EXP CLinCpsProc //�����߹⻬������.
{
public:
	CLinCpsProc(double fwStep, double samErr, char cDoPack);
	CLinCpsProc();
	~CLinCpsProc();

public:
	//���������߼�Ȩƽ���⻬�������������:
	gme_D_DOT  *cmsAixsCbs(gme_D_DOT *lPtr,long ln,long *outln);
	//������α�Ҷ˹����⻬���������:
	gme_D_DOT  *cmDensityp5Cbs(gme_D_DOT *arc_buf,long arc_xy,long *outlen);
	//�������α�Ҷ˹����⻬���������:
	gme_D_DOT  *cmDensityp3Cbs(gme_D_DOT *arc_buf,long arc_xy,long *outlen);
	//���α�Ҷ˹������⻬���������:
	gme_D_DOT  *cmDensityCbs(gme_D_DOT *arc_buf,long arc_xy,long *outlen);
	//����B�������߹����ֵ�⻬��������ں���:
	gme_D_DOT  *cmInsertDensity(gme_D_DOT *arc_buf,long arc_xy,long *outlen);

	// ----------------------------- ���������⻬������ ---------------------------- //
	// ����:gme_D_DOT *pddpt ------------ �����Ĵ��⻬����������ݵ㼯;
	//		long lDnum	 ------------ ���⻬����������ݵ����;
	//      double dTention---------- ����ϵ��(0<-���ͬ������������->�������ֶ�����);
	//      long *lDn   ------------- �⻬��������Buf�е����ݵ���;
	//����: �������ع⻬���������Bufָ��(�ɺ������룬�������ͷ�); ΪNULL����ʧ��.
	gme_D_DOT  *cmTentionCps(gme_D_DOT *arc_buf,long arc_xy,double dTention,long *outlen);
	// ��������ֵ�������߲��ܲ����ز��ܺ�ĵ����꼰����:
	gme_D_DOT  *cmInsDensityLinByStep(gme_D_DOT *xy,long len,double dfStep,long *outlen);
	//ѹ����ͬ�����ڵ�:
	void	cmSetCpsRadius(double fStep, double samErr, char cDoPack);
	short	cmPackingLin(gme_D_DOT *lnptr, long *len, double delta);
	void    cmFreeCbsLinBuf(void);
	gme_D_DOT  *cmAllocCbsLinBuf(long linLn);

private:
	//���������߼�Ȩƽ���⻬��������
	double	_sAixs(long i, double *B, double t);
	//������α�Ҷ˹����⻬����
	double _p5Cbs(double *px, double *L_arc, double *dpx, double t);
	//�������α�Ҷ˹����⻬����:
	double	_p3Cbs(double *px, double *L_arc, double *dpx, double t, double dist);
	//���α�Ҷ˹������⻬����
	double	Cbs(long i, double *B, double t);
	//����B�������߹����ֵ�⻬������
	short	Cps_Trid(long n, double *a, double *b, double *c, double *f);
	short	Cpps(long n, double *p, double *L_arc, double *dp, short Boudary_type);
	double	GeneratePose(double *p, double *L_arc, double *dp, long i, double t);

	//������������⻬������:
	short	TraveV(gme_D_DOT *pddpt, long lDnum, double* pdA, double* pdB, double* pdC,
		double* pdx, double* pdy, double* pdSx, double* pdSy);
	short	CaculateDV(gme_D_DOT *pddpt, long lDnum, double* pdSx,
		double* pdSy, double* pdH, double*dTention);
	//����õ��⻬���������ϵ�����:
	gme_D_DOT  *DrawTention(gme_D_DOT *pddpt, long lDnum, double *pdSx, double *pdSy,
		double *pdH, double dTention, long *lDn);
private:
	gme_D_DOT  *m_PtCbsLine; //���ع⻬���������;
	long	m_CbsLinLn;//��ǰBUFFER��С.
	char    m_cDoPackProc; //�⻬ǰ��ͬ��ϲ�����.
	double  m_SameDErr, m_CpsRadius;//�⻬�������.
};


	//˵��: �߹⻬�����������ͬһ��������ָ�룬�ʸ��������ɴ���ʹ�ã����ɲ���.
	//���Բ�ֵ���Ƿ��⻬������:
	void LIB_GMKERMATH_EXP cmLinCbs2(gme_D_DOT *fXyIn, gme_D_DOT *fXyOut, long lDn);
}

