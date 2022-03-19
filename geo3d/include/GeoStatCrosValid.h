//==========================================================================
//      ��Ȩ:ZTYQ Tech. Co., Ltd.//��Ȩ
//      ������: GeoStatKrig��
//      ����: lhy��2007.05
//      ��������: ��ɽ�����֤����
//      �汾:  1.1��2007.05��
//      �޸ļ�¼:  �ޡ�
//      ��Ҫ�����б�: 
//      _cvLoadGsCrosValid ---------------------------------------->��������
//      _cvSetExtrData ---------------------------------------->�������ݼ�ֵ
//      _cvSetGridParam --------------------------------------->���ø�������
//      _cvSetSrchParam ----------------------------------->��������������
//      _cvCptcvKriging ------------------------------------->���������ֵ
//      _cvCptcvIKriging -------------------------------->����ָʾ������ֵ
//      _cvCptcvInverse ----------------------------------->������뷴�ȹ�ֵ
//      CVBackTr ------------------------------------------>�����ݽ�����任
//==========================================================================

#if !defined(AFX_GEOSTATCROSVALID_H__DCF46D1F_2F3D_4846_908C_41EBFF177E57__INCLUDED_)
#define AFX_GEOSTATCROSVALID_H__DCF46D1F_2F3D_4846_908C_41EBFF177E57__INCLUDED_

#include "GsStru.h"
#include "GeoStatLib.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _GEO_STAT_KRIG_LIB
#define  _GEO_STAT_KRIG_DLL _declspec(dllimport)
#else
#define _GEO_STAT_KRIG_DLL _declspec(dllexport)
#endif

class _GEO_STAT_KRIG_DLL CGeoStatCrosValid  
{
public:
	CGeoStatCrosValid();
	virtual ~CGeoStatCrosValid();

	//================================================================================
    // �� �� ����_cvLoadGsCrosValid
    // �����������ú���װ�������,���ǽ�����֤�����д���������. 
	// ���������pDiscPnts          �� ���ݵ�
	//           lDatNum            �� ������Ŀ
	//           pPreAttr           �� ԭʼ��������ֵ
	//           ptr_var            �� ��̬�任��Ӧ��(��̬�任�еõ�����̬��任���õ�)
	//           ptr_vrg            �� ��̬�任��Ӧ��(��̬�任�еõ�����̬��任���õ�)
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cvLoadGsCrosValid(GsDiscPnt *pDiscPnts, long lpntNum, double *PreAttr, double *ptr_var, double *ptr_vrg);
	
	//================================================================================
    // �� �� ����_cvLoadGsCrosValid2
    // �����������ú���װ�븨����������. 
	// ���������pDiscPnts          �� ���ݵ�
	//           lDatNum            �� ������Ŀ
    // ����ֵ  ����
    // �������ڣ�2008-09-23
    // �޸����ڣ�2008-09-23
    // ����˵����
    //================================================================================
	void _cvLoadGsCrosValid2(GsDiscPnt *pDiscPntsSec, long lPntNumSec);

	//================================================================================
    // �� �� ����_cvSetExtrData
    // �����������ú����������ý��н�����֤���������Եļ�ֵ
	// ���������fExtrMax           �� ���ݼ���ֵ
	//           fExtrMin           �� ���ݼ�Сֵ
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cvSetExtrData(double fExtrMax, double fExtrMin);
	
	//================================================================================
    // �� �� ����_cvSetGridParam
    // �����������ú����������ý�����֤���õ��ĸ�������
	// ���������cvxnum             �� X���������
	//           cvynum             �� Y���������
	//           cvznum             �� Z���������
	//           cvxmini            �� X�������ʼ����
	//           cvymini            �� Y�������ʼ����
	//           cvzmini            �� Z�������ʼ����
	//           cvxsize            �� X�������С
	//           cvysize            �� Y�������С
	//           cvzsize            �� Z�������С
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cvSetGridParam(int cvxnum, int cvynum, int cvznum, 
		           double cvxmini, double cvymini, double cvzmini, 
				   double cvxsize, double cvysize, double cvzsize);
	//================================================================================
    // �� �� ����_cvSetSrchParam
    // �����������ú����������ý�����֤���õ�����������
	// ���������cvmaxr_sec         �� ��������ĳ���뾶
	//           cvminr_sec         �� ��������Ķ���뾶
	//           cverr_sec          �� ��������Ĵ�ֱ��뾶
	//           cvang1_search      �� ����������ת�ķ�λ��
	//           cvang2_search      �� ����������ת�������
	//           cvang3_search      �� ����������ת�����
	//           cvminnum_krg       �� ������֤�������õ�����С��������
	//           cvmaxnum_krg       �� ������֤�������õ��������������
	//           cvnumxblock        �� X�����Ͽ������ɢ����
	//           cvnumyblock        �� Y�����Ͽ������ɢ����
	//           cvnumzblock        �� Z�����Ͽ������ɢ����
    // ����ֵ  ���� 
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cvSetSrchParam(double cvmaxr_sec, double cvminr_sec, double cvverr_sec, 
		             int cvang1_search, int cvang2_search, int cvang3_search, 
		             int cvminnum_krg, int cvmaxnum_krg, int cvnumxblock, int cvnumyblock, int cvnumzblock);
	
	//================================================================================
    // �� �� ����_cvSetSecSrchParam
    // �����������ú����������ý�����֤���õ�����������
	// ���������iMaxSrchNum        �� �α�����ֵ������
	//           maxr_sec           �� ��������ĳ���뾶
	//           minr_sec           �� ��������Ķ���뾶
	//           verr_sec           �� ��������Ĵ�ֱ��뾶
    // ����ֵ  ���� 
    // �������ڣ�2008-09-23
    // �޸����ڣ�2008-09-23
    // ����˵����
    //================================================================================
	void _cvSetSecSrchParam( int iMaxSrchNum, double maxr_sec, double minr_sec, double verr_sec);		
	
	//================================================================================
    // �� �� ����_cvSetSrchOct
    // �����������ú����������ý�����֤�������õ��������������ʽ
	// ���������cvoct              �� 0Ϊ��ͨ������������Ϊ�˷�Բ������ÿһ������������������
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
    void _cvSetSrchOct(int cvnoct);

	//================================================================================
    // �� �� ����_cvSetDisPower
    // �����������ú����������ý�����֤�������õ��ľ��뷴���ݴ�
	// ���������cviDisPower �� ���뷴���ݴ�
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cvSetDisPower(int cviDisPower);

	//================================================================================
    // �� �� ����_cvSetKrigType
    // �����������ú����������ý�����֤�����еĿ�����ֵ����
	// ���������cvktype            �� 0Ϊ�򵥿����1Ϊ��ͨ�����2Ϊ�������3Ϊָʾ����� 
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _cvSetKrigType(int cvktype);

	//================================================================================
    // �� �� ����_cvSetCoKrigType
    // �����������ú����������ý�����֤�����е�Э������ֵ����
	// ���������cvCoKtype          �� 0��ͳ��ͨЭ�����1Ϊ��׼��ͨЭ�����2Ϊ��Э�����
    // ����ֵ  ����
    // �������ڣ�2008-09-23
    // �޸����ڣ�2008-09-23
    // ����˵����
    //================================================================================	
	void _cvSetCoKrigType(int cvCoKtype);
	
	//================================================================================
    // �� �� ����_cvSetSkMean
    // �����������ú����������ü򵥿�����ֵ�������õ�����Ʒƽ��ֵ
	// ���������cvmeansk           �� ��ֵ�������ݵ�ƽ��ֵ
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _cvSetSkMean(double cvmeansk);
	
	//================================================================================
    // �� �� ����_cvSetCokMean
    // �����������ú�����������Э������ֵ�������õ�����Ʒƽ��ֵ
	// ���������pfVMeanVal         �� ��ֵ��������ݵ�ƽ��ֵ
    // ����ֵ  ����
    // �������ڣ�2008-09-23
    // �޸����ڣ�2008-09-23
    // ����˵����
    //================================================================================
	void _cvSetCokMean(double pfVMeanVal[]);

	//================================================================================
    // �� �� ����_cvSetIntpPara
    // �����������ú����������ÿ�����ֵ���õ��ı�������
	// ���������cvnst              �� ����ģ�͸���
	//           cvc0               �� ���ֵ
	//           cvcc               �� ����ֵ
	//           cvit               �� ��������
	//           cvaa               �� ����������
	//           cvaa1              �� ����������
	//           cvaa2              �� ������ֱ����
	//           cvang1             �� �����������ԽǶȷ�λ��
	//           cvang2             �� �����������ԽǶ������
	//           cvang3             �� �����������ԽǶ����
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _cvSetIntpPara(int cvnst, double cvc0, double cvcc[], int cvit[], double cvaa[], double cvaa1[],
		double cvaa2[], double cvang1[], double cvang2[], double cvang3[]);
    
	//================================================================================
    // �� �� ����_cvSetDrifTerm
    // �����������ú�����������Ư��
	// ���������cvidrif            �� 0��ʾ�÷����ϲ�����Ư�ƣ�1��ʾ����Ư��
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _cvSetDrifTerm(int cvidrif[]);
	
	//================================================================================
    // �� �� ����_cvSetTranModel
    // �����������ú���������������ת���ķ�ʽ
	// ���������cvtranslation      �� 0��ʾ�ޱ任��1��ʾ�����任��2��ʾ��̬�任
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _cvSetTranModel(int cvtranslation);
	
	//================================================================================
    // �� �� ����_cvSetMinAttrGzero
    // �����������ú����������ö����任�������õ���ƫ����
	// ���������cvfMinGzero        �� �����任���õ���ƫ����
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _cvSetMinAttrGzero(double cvfMinGzero);
    
	//================================================================================
    // �� �� ����_cvSetThresAndCdf
    // �����������ú�����������ָʾ�����������õ�����ֵ����
	// ���������pfThres            �� ��ֵ
	//           pfCdf              �� ����ֵ��Ӧ���ۻ�����
	//           lThresNum          �� ��ֵ����
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cvSetThresAndCdf(double pfThres[], double pfCdf[], long lThresNum);
    
	//================================================================================
    // �� �� ����_cvSetMeanThres
    // �����������ú�����������ָʾ��������ͣ���ֵ��ֵ
	// ���������cviktype           �� 0Ϊ��ͨ�����1Ϊ�򵥿����
	//           cvikCutOff         �� ��ֵ��ֵ
	//           cvktype_ik         �� 0Ϊ��ֵ�����1Ϊ��ȫ�����
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _cvSetMeanThres(int cviktype, double cvikCutOff, int cvktype_ik);
    
	//================================================================================
    // �� �� ����_cvSetIkIntpPara
    // �����������ú�����������ָʾ��������õ��ı�������
	// ���������cvIkIntpPara       �� ��������
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _cvSetIkIntpPara(Kt3dIntp cvIkIntpPara[]);
	
	//================================================================================
    // �� �� ����_cvSetCokIntpPara
    // �����������ú�����������Э��������õ��ı�������
	// ���������pCokIntpPara       �� ��������
	//           lCokIntpNum        �� ��������
    // ����ֵ  ����
    // �������ڣ�2008-09-23
    // �޸����ڣ�2008-09-23
    // ����˵����
    //================================================================================
	long _cvSetCokIntpPara(Kt3dIntp pCokIntpPara[], long lCokIntpNum=1);	

	//================================================================================
    // �� �� ����_cvCptcvKriging
    // �����������ú�������������ͨ�����
	// ���������cvpEstabPnts       �� ��ͨ������ֵ���
	//           cvlOutPntNum       �� ��ͨ������ֵ�������
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _cvCptcvKriging(EstabPnt *cvpEstabPnts, long &cvlOutPntNum);
	
	//================================================================================
    // �� �� ����_cvCptcvIKriging
    // �����������ú�����������ָʾ�����
	// ���������EstabVal           �� ָʾ������ֵ���
	//           EstabVari          �� ָʾ������ֵ����
	//           OriVal             �� ��ֵԭֵ
	//           TErr               �� ��ֵ���
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _cvCptcvIKriging(double *EstabVal, double *EstabVari, double *OriVal, double *TErr);
	
	//================================================================================
    // �� �� ����_cvCptcvInverse
    // �����������ú����������о��뷴�ȹ�ֵ
	// ���������cvpEstabPnts       �� ���뷴�ȹ�ֵ���
	//           cvlOutPntNum       �� ���뷴�ȹ�ֵ�������
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _cvCptcvInverse(EstabPnt *cvpEstabPnts, long &cvlOutPntNum);

	//================================================================================
    // �� �� ����_cvCptcvCoKrig
    // �����������ú�����������Э�����
	// ���������EstabVal           �� ָʾ������ֵ���
	//           EstabVari          �� ָʾ������ֵ����
	//           OriVal             �� ��ֵԭֵ
	//           TErr               �� ��ֵ���
    // ����ֵ  ����
    // �������ڣ�2008-09-23
    // �޸����ڣ�2007-09-23
    // ����˵����
    //================================================================================	
	void _cvCptcvCoKrig(double *EstabVal, double *EstabVari, double *OriVal, double *TErr);

	//================================================================================
    // �� �� ����CVBackTr
    // �����������ú��������Թ�ֵ���������任
	// ���������cvpEstabPnts       �� ��ֵ���
	//           cvlOutPntNum       �� ��ֵ�������
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	//������任
	//˵��: �ú��������Թ�ֵ���������任
	//����:
	//      cvpEstabPnts ------------> ��ֵ���
	//      cvlOutPntNum ------------> ��ֵ�������
	void CVBackTr(EstabPnt *cvpEstabPnts, long &cvlOutPntNum);
	
private:
	//ԭʼ������Ϣ
	GsDiscPnt			*m_pDiscPnts;
	long				m_lpntNum;
	double				*m_pPreAttr;
	double				*m_cvtr_var;
	double				*m_cvtr_vrg;

	//�α�������2008-9-23
	GsDiscPnt			*m_pDiscPntsSec;
	long				m_lPntNumSec;
	
	//���ݼ�ֵ
	double				m_fExtrMax;
	double				m_fExtrMin;

	//��������
	CGeoStat			*m_cvKrigObj;

	//������Ϣ
	int					m_cvxnum;
	int					m_cvynum;
	int					m_cvznum;
    double				m_cvxmini;
	double				m_cvymini;
	double				m_cvzmini;
    double				m_cvxsize;
	double				m_cvysize;
	double				m_cvzsize;

	//����������Ϣ
    double				m_cvmaxr_sec;
	double				m_cvminr_sec;
	double				m_cvverr_sec; 	             
	int					m_cvang1_search;
	int					m_cvang2_search;
	int					m_cvang3_search;
    int					m_cvminnum_krg;
	int					m_cvmaxnum_krg;
	int					m_cvnumxblock;
	int					m_cvnumyblock;
	int					m_cvnumzblock;
    //�α�������������Ϣ
	long				m_iMaxSrchSecNum;
	double				m_fSecMaxR;
	double				m_fSecMinR;
	double				m_fSecVerR;

	//������Ͻ��	
	int					m_cvnst[1];
	double				m_cvc0[1];
	int					m_cvit[GS_MAXNST];
	double				m_cvcc[GS_MAXNST]; 
	double				m_cvang1[GS_MAXNST];
	double				m_cvang2[GS_MAXNST];
	double				m_cvang3[GS_MAXNST];
	double 				m_cvaa[GS_MAXNST];
	double				m_cvaa1[GS_MAXNST];
	double				m_cvaa2[GS_MAXNST];	
    Kt3dIntp			m_cvCokIntpPara[GS_MXVARG];
	int					m_cvnoct;

	//�������Ϣ
	int					m_cvktype;
	double				m_cvmeansk;
	int					m_cvidrif[9];
	int					m_cvtranslation;
	double				m_cvfMinGzero;
	int                 m_cviDisPower;

    int                 m_cvCoKtype;
	double              m_pfMeanVal[GS_MAXVAR];
	
	//����ָʾ��������	
	double				m_cvikfThres[GS_MAXCUT];
	double				m_cvikfCdf[GS_MAXCUT];
	int					m_cvikCutNum;
    double				m_cvikCutOff;

	Kt3dIntp			m_cvIkIntpPara[GS_MAXCUT];

	long				m_cvlIkCcdfNum;

	int					m_cviktype;
	int					m_cvktype_ik;

	BOOL				m_bIsShowProgr;
};

#ifndef _GEO_STAT_KRIG_LIB
	#ifdef _DEBUG
		#pragma comment(lib, "GeoStatKrigLibD.lib")
	#else
		#pragma comment(lib, "GeoStatKrigLib.lib")
	#endif
#endif
#endif // !defined(AFX_GEOSTATCROSVALID_H__DCF46D1F_2F3D_4846_908C_41EBFF177E57__INCLUDED_)