//==========================================================================
//      ��Ȩ:ZTYQ Tech. Co., Ltd.//��Ȩ
//      ������: GeoStatKrig��
//      ����: lhy��2007.05
//      ��������: ��ɿ����Ʒλ��ֵ����
//      �汾:  1.1��2007.05��
//      �޸ļ�¼:  �ޡ�
//      ��Ҫ�����б�: 
//      _gsKLoadGsKrigData ---------------------------------------->��������
//      _gsKSetExtrData --------------------------------------->�������ݼ�ֵ
//      _gsKSetGridParam -------------------------------------->���ø�������
//      _gsKSetSrchParam ---------------------------------->��������������
//      _gsKCptKrigingVol ----------------------------------->���������ֵ
//      _gsKCptIkrigingVol ------------------------------>����ָʾ������ֵ
//      _gsKCptInverseVol --------------------------------->������뷴�ȹ�ֵ
//      _gsKBackTr ---------------------------------------->�����ݽ�����任
//==========================================================================

#if !defined(AFX_GEOSTATKRIGLIB_H__614596C4_13C5_4CC1_B75B_AD7383089B49__INCLUDED_)
#define AFX_GEOSTATKRIGLIB_H__614596C4_13C5_4CC1_B75B_AD7383089B49__INCLUDED_

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

class _GEO_STAT_KRIG_DLL CGeoStatKrigLib  
{
public:
	CGeoStatKrigLib();
	virtual ~CGeoStatKrigLib();

	//================================================================================
    // �� �� ����_gsKLoadGsKrigData
    // �����������ú���װ�������,���ǿ�����ֵ�����д��������. 
	// ���������pDiscPnts          �� ���ݵ�
	//           lpntNum            �� ������Ŀ
	//           ptr_var            �� ��̬�任��Ӧ��(��̬�任�еõ�����̬��任���õ�)
	//           ptr_vrg            �� ��̬�任��Ӧ��(��̬�任�еõ�����̬��任���õ�)
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _gsKLoadGsKrigData(GsDiscPnt *pDiscPnts, long lpntNum, double *ptr_var, double *ptr_vrg);
	void _gsKLoadGsKrigData1(GsDiscPnt1 *pDiscPnts, long lpntNum, double *ptr_var, double *ptr_vrg);


	//================================================================================
    // �� �� ����_gsKLoadGsKrigData2
    // �����������ú���װ��α�������,��Э������ֵ���õ��Ĵα�������
	// ���������pDiscPnts          �� ���ݵ�
	//           lPntNumSec         �� ������Ŀ
    // ����ֵ  ����
    // �������ڣ�2008-09-24
    // �޸����ڣ�2008-09-24
    // ����˵����
    //================================================================================
	void _gsKLoadGsKrigData2(GsDiscPnt *pDiscPntsSec, long lPntNumSec);
	void _gsKLoadGsKrigData2Simp(GsDiscPnt1 *pDiscPntsSec, long lPntNumSec);

	//================================================================================
    // �� �� ����_gsKSetExtrData
    // �����������ú����������ý��п�����ֵ���������Եļ�ֵ
	// ���������fExtrMax           �� ���ݼ���ֵ(Ĭ��1.0e21,������Ϊ���ݵ����ֵ)
	//           fExtrMin           �� ���ݼ�Сֵ(Ĭ��-1.0e21��������Ϊ���ݵ���Сֵ)
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _gsKSetExtrData(double fExtrMax, double fExtrMin);
	
	//================================================================================
    // �� �� ����_gsKSetGridParam
    // �����������ú����������ÿ�����ֵ���õ��ĸ�������
	// ���������xnum              �� X���������
	//           ynum              �� Y���������
	//           znum              �� Z���������
	//           xmini             �� X�������ʼ����
	//           ymini             �� Y�������ʼ����
	//           zmini             �� Z�������ʼ����
	//           xsize             �� X�������С
	//           ysize             �� Y�������С
	//           zsize             �� Z�������С
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _gsKSetGridParam(int xnum, int ynum, int znum, 
		           double xmini, double ymini, double zmini, 
				   double xsize, double ysize, double zsize);
	void _gsKSetGridParamEva(int xnum, int ynum, int znum, 
		double xmini, double ymini, double zmini, 
		double xsize, double ysize, double zsize);
	//================================================================================
    // �� �� ����_gsKSetSrchParam
    // �����������ú����������ÿ�����ֵ���õ�����������
	// ���������maxr_sec           �� ��������ĳ���뾶(����������ζԽ��ߵ�һ��)
	//           minr_sec           �� ��������Ķ���뾶(����������ζԽ��ߵ�һ��)
	//           err_sec            �� ��������Ĵ�ֱ��뾶(����������ζԽ��ߵ�һ��)
	//           ang1_search        �� ����������ת�ķ�λ��(0)
	//           ang2_search        �� ����������ת�������(0)
	//           ang3_search        �� ����������ת�����(0)
	//           minnum_krg         �� �����������õ�����С��������(3)
	//           maxnum_krg         �� �����������õ��������������(15)
	//           numxblock          �� X�����Ͽ������ɢ����(1)
	//           numyblock          �� Y�����Ͽ������ɢ����(1)
	//           numzblock          �� Z�����Ͽ������ɢ����(1)
    // ����ֵ  ���� 
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _gsKSetSrchParam(double maxr_sec, double minr_sec, double verr_sec, 
		             int ang1_search, int ang2_search, int ang3_search, 
		             int minnum_krg, int maxnum_krg, int numxblock, int numyblock, int numzblock);
    
	//��������������ز���
	//˵��: �ú����������ý�����֤���õ�����������
	//����:
	//      iMaxSrchNum -------------> �α�����ֵ������
	//      maxr_sec ----------------> ��������ĳ���뾶
	//      minr_sec ----------------> ��������Ķ���뾶
	//      err_sec -----------------> ��������Ĵ�ֱ��뾶
	void _gsKSetSecSrchParam( int iMaxSrchNumSec, double fSrchMaxr_Sec, double fSrchMinr_Sec, double fSrchVerr_Sec);

	//================================================================================
    // �� �� ����_gsKSetSrchOct
    // �����������ú����������ÿ�����ֵ�������õ��������������ʽ
	// ���������noct              �� 0Ϊ��ͨ������������Ϊ�˷�Բ������ÿһ������������������
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================		
	void _gsKSetSrchOct(int noct);

	//================================================================================
    // �� �� ����_gsKSetDisPower
    // �����������ú����������þ��뷴���ݴ�
	// ���������iDisPower�� ���뷴���ݴ�
    // ����ֵ  ����
    // �������ڣ�2009-11-03
    // �޸����ڣ�2009-11-03
    // ����˵����
    //================================================================================	
	void _gsKSetDisPower(int iDisPower);
	
    //================================================================================
    // �� �� ����_gsKSetKrigType
    // �����������ú����������ÿ��������еĿ�����ֵ����
	// ���������ktype            �� 0Ϊ�򵥿����1Ϊ��ͨ�����2Ϊ�������3Ϊָʾ����� 
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _gsKSetKrigType(int ktype);

    //================================================================================
    // �� �� ����_gsKSetCoKrigType
    // �����������ú�����������Э���������еĿ�����ֵ����
	// ���������iCoktype         �� 0��ͳ��ͨЭ�����1��׼��ͨЭ�����2�򵥿����
    // ����ֵ  ����
    // �������ڣ�2008-09-23
    // �޸����ڣ�2008-09-23
    // ����˵����
    //================================================================================
	void _gsKSetCoKrigType(int iCoktype);

    //================================================================================
    // �� �� ����_gsKSetKrigOption
    // �����������ú����������ÿ��������еĿ��������
	// ���������koption          �� �����ѡ��
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _gsKSetKrigOption(int koption);
	
	//================================================================================
    // �� �� ����_gsKSetSkMean
    // �����������ú����������ü򵥿�����ֵ�������õ�����Ʒƽ��ֵ
	// ���������meansk           �� ��ֵ�������ݵ�ƽ��ֵ
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _gsKSetSkMean(double meansk);

	//================================================================================
    // �� �� ����_gsKSetCokMean
    // �����������ú�����������Э������ֵ�������õ�����Ʒƽ��ֵ
	// ���������pfCokMean        �� ��ֵ�������ݵ�ƽ��ֵ
    // ����ֵ  ����
    // �������ڣ�2008-09-24
    // �޸����ڣ�2008-09-24
    // ����˵����
    //================================================================================
	void _gsKSetCokMean(double pfCokMean[]);

	//================================================================================
    // �� �� ����_gsKSetIntpPara
    // �����������ú����������ÿ�����ֵ���õ��ı�������
	// ���������nst                �� ����ģ�͸���(1)
	//           c0                 �� ���ֵ(0)
	//           cc                 �� ����ֵ(1)
	//           it                 �� ��������()
	//           aa                 �� ����������(����������ζԽ��ߵ�һ��)
	//           aa1                �� ����������(����������ζԽ��ߵ�һ��)
	//           aa2                �� ������ֱ����(����������ζԽ��ߵ�һ��)
	//           ang1               �� �����������ԽǶȷ�λ��(0)
	//           ang2               �� �����������ԽǶ������(0)
	//           ang3               �� �����������ԽǶ����(0)
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================		
	void _gsKSetIntpPara(int nst, double c0, double cc[], int it[], double aa[], double aa1[],
		double aa2[], double ang1[], double ang2[], double ang3[]);
    
	//================================================================================
    // �� �� ����_gsKSetDrifTerm
    // �����������ú�����������Ư��
	// ���������idrif              �� 0��ʾ�÷����ϲ�����Ư�ƣ�1��ʾ����Ư��
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _gsKSetDrifTerm(int idrif[]);
	
	//================================================================================
    // �� �� ����_gsKSetTranModel
    // �����������ú���������������ת���ķ�ʽ
	// ���������translation        �� 0��ʾ�ޱ任��1��ʾ�����任��2��ʾ��̬�任
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _gsKSetTranModel(int translation);

	//================================================================================
    // �� �� ����_gsKSetMinAttrGzero
    // �����������ú����������ö����任�������õ���ƫ����
	// ���������fMinGzero          �� �����任���õ���ƫ����
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _gsKSetMinAttrGzero(double fMinZero);

	//================================================================================
    // �� �� ����_gsKSetThresAndCdf
    // �����������ú�����������ָʾ�����������õ�����ֵ����
	// ���������pfThres            �� ��ֵ
	//           pfCdf              �� ����ֵ��Ӧ���ۻ�����
	//           lThresNum          �� ��ֵ����
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _gsKSetThresAndCdf(double pfThres[], double pfCdf[], long lThresNum);

	//================================================================================
    // �� �� ����_gsKSetPropThres
    // �����������ú����������������ͼ�������õ��ĸ�����ֵ
	// ���������fPropThres         �� ������ֵ
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _gsKSetPropThres(double fPropThres);

	//================================================================================
    // �� �� ����_gsKSetQuanThre
    // �����������ú��������������Ϊͼ�������õ��ķ�λ��ֵ
	// ���������fQuanThres         �� ��λ��ֵ
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _gsKSetQuanThre(double fQuanThres);
 
	//================================================================================
    // �� �� ����_gsKSetMeanThres
    // �����������ú�����������ָʾ��������ͣ���ֵ��ֵ
	// ���������iktype          �� �� 0Ϊ��ͨ�����1Ϊ�򵥿����
	//           ikCutOff        �� �� ��ֵ��ֵ
	//           ktype_ik         ���� 0Ϊ��ֵ�����1Ϊ��ȫ�����
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================    
	void _gsKSetMeanThres(int iktype, double ikCutOff, int ktype_ik);
    
	//================================================================================
    // �� �� ����_gsKSetIkIntpPara
    // �����������ú�����������ָʾ��������õ��ı�������
	// ���������IkIntpPara         �� ��������
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _gsKSetIkIntpPara(Kt3dIntp IkIntpPara[]);

	//================================================================================
    // �� �� ����_gsKSetCokIntpPara
    // �����������ú�����������Э��������õ��ı�������
	// ���������CokIntpPara         �� ��������
    // ����ֵ  ����
    // �������ڣ�2009-09-24
    // �޸����ڣ�2009-09-24
    // ����˵����
    //================================================================================
	void _gsKSetCokIntpPara(Kt3dIntp CokIntpPara[]);

	//================================================================================
    // �� �� ����_gsKCptInverseVol
    // �����������ú����������о��뷴�ȹ�ֵ(������)
	// ���������pdOutAttr          �� ���뷴�ȹ�ֵ���
	//           plPntNum           �� ���뷴�ȹ�ֵ�������ĵ���
	//           pfMeanDis          �� ��ֵ�㵽�������ƽ������
	//           lEngTypeNum        �� ����������
	//           pKrigEngNum        �� ���̸���
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2009-01-15
    // ����˵����
    //================================================================================	
	void _gsKCptInverseVol(double *pdOutAttr, long *plPntNum, double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL,BOOL bIsShowProgr=TRUE);
	void _gsKCptInverseVol1(double *pdOutAttr, long *plPntNum, double *pfMeanDis,BOOL bIsShowProgr=TRUE);
	//================================================================================
	// �� �� ����_gsKCptInversePntSimp
	// �����������ú����������о��뷴�ȹ�ֵ(���е��ֵ��������)
	// ���������pdOutAttr          �� ���뷴�ȹ�ֵ���
	// ����ֵ  ����
	// �������ڣ�2010-04-12
	// �޸����ڣ�2010-04-12
	// ����˵�������������ã�ʹ�����е���ٲ�ֵ
	//================================================================================
	void _gsKCptInverseVolSimp(double *pdOutAttr,BOOL bIsShowProgr=TRUE);

	//================================================================================
    // �� �� ����_gsKCptInversePnt
    // �����������ú����������о��뷴�ȹ�ֵ(��ɢ������)
	// ���������pEstPnt            �� ����ֵ������
	//           lEstPntNum         �� ����ֵ�����
	// ���������pdOutAttr          �� ���뷴�ȹ�ֵ���
	//           plPntNum           �� ���뷴�ȹ�ֵ�������ĵ���
	//           pfMeanDis          �� ��ֵ�㵽�������ƽ������
	//           lEngTypeNum        �� ����������
	//           pKrigEngNum        �� ���̸���
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2009-01-15
    // ����˵����
    //================================================================================
	void _gsKCptInversePnt(GsDiscPnt *pEstPnt, long lEstPntNum, double *pdOutAttr, long *plPntNum,
						   double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL,BOOL bIsShowProgr=TRUE);

	//================================================================================
    // �� �� ����_gsKCptKrigingVol
    // �����������ú�������������ͨ�����(������)
	// ���������pdOutAttr          �� ��ͨ������ֵ���
	//           pdOutVari          �� ��ͨ������ֵ����
	//           plPntNum           �� ��ͨ������ֵ�������ĵ���
	//           pfMeanDis          �� ��ֵ�㵽�������ƽ������
	//           lEngTypeNum        �� ����������
	//           pKrigEngNum        �� ���̸���
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2009-01-15
    // ����˵����
    //================================================================================	
	void _gsKCptKrigingVol(double *pdOutAttr, double *pdOutVari, long *plPntNum, 
						   double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL,BOOL bIsShowProgr=TRUE);
	void _gsKCptKrigingVol1(double *pdOutAttr, double *pdOutVari, long *plPntNum, double *pfMeanDis,BOOL bIsShowProgr=TRUE);

	//================================================================================
	// �� �� ����_gsKCptKrigingVolSimp
	// �����������ú�������������ͨ�����(���е��ֵ��������)
	// ���������pdOutAttr          �� ��ͨ������ֵ���
	// ����ֵ  ����
	// �������ڣ�2010-04-12
	// �޸����ڣ�2010-04-12
	// ����˵�������������ã�ʹ�����е���ٲ�ֵ
	//================================================================================
	void _gsKCptKrigingVolSimp(double *pdOutAttr,BOOL bIsShowProgr=TRUE);

	//================================================================================
    // �� �� ����_gsKCptKrigingPnt
    // �����������ú�������������ͨ�����(��ɢ������)
	// ���������pEstPnt            �� ����ֵ������
	//           lEstPntNum         �� ����ֵ�����
	// ���������pdOutAttr          �� ��ͨ������ֵ���
	//           plPntNum           �� ��ͨ������ֵ�������ĵ���
	//           pfMeanDis          �� ��ֵ�㵽�������ƽ������
	//           lEngTypeNum        �� ����������
	//           pKrigEngNum        �� ���̸���
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2009-01-15
    // ����˵����
    //================================================================================
	void _gsKCptKrigingPnt(GsDiscPnt *pEstPnt, long lEstPntNum, double *pdOutAttr, double *pdOutVari, long *plPntNum, 
						   double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL,BOOL bIsShowProgr=TRUE);

	//================================================================================
    // �� �� ����_gsKCptIkrigingVol
    // �����������ú�����������ָʾ�����(������)
	// ���������pdOutAttr          �� ָʾ������ֵ���
	//           pdOutVari          �� ָʾ������ֵ����
	//           pfPropVal          �� ָʾ��������ֵ
	//           pfQuanVal          �� ָʾ������λֵ
	//           plPntNum           �� ָʾ������ֵ�������ĵ���
	//           pfMeanDis          �� ��ֵ�㵽�������ƽ������
	//           lEngTypeNum        �� ����������
	//           pKrigEngNum        �� ���̸���
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2009-01-15
    // ����˵����
    //================================================================================
	void _gsKCptIkrigingVol(double *pdOutAttr, double *pfOutVari, double *pfPropVal, double *pfQuanVal, long *plPntNum, 
						    double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL,BOOL bIsShowProgr=TRUE);	
	
	//================================================================================
    // �� �� ����_gsKCptIkrigingPnt
    // �����������ú�����������ָʾ�����(��ɢ������)
	// ���������pEstPnt            �� ����ֵ������
	//           lEstPntNum         �� ����ֵ�����
	// ���������pdOutAttr          �� ָʾ������ֵ���
    //           pfPropVal          �� ָʾ��������ֵ
	//           pfQuanVal          �� ָʾ������λֵ
	//           plPntNum           �� ָʾ������ֵ�������ĵ���
	//           pfMeanDis          �� ��ֵ�㵽�������ƽ������
	//           lEngTypeNum        �� ����������
	//           pKrigEngNum        �� ���̸���
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2009-01-15
    // ����˵����
    //================================================================================
	void _gsKCptIkrigingPnt(GsDiscPnt *pEstPnt, long lEstPntNum, double *pdOutAttr, double *pfOutVari, double *pfPropVal, double *pfQuanVal, long *plPntNum, 
						    double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL,BOOL bIsShowProgr=TRUE);	
	
	//================================================================================
    // �� �� ����_gsKCptCoKrigVol
    // �����������ú�����������Э�����(������)
	// ���������pdOutAttr          �� Э������ֵ���
	//           pdOutVari          �� Э������ֵ����
	//           pfPropVal          �� Э��������ֵ
	//           pfQuanVal          �� Э������λֵ
	//           plPntNum           �� Э������ֵ�������ĵ���
	//           pfMeanDis          �� ��ֵ�㵽�������ƽ������
	//           lEngTypeNum        �� ����������
	//           pKrigEngNum        �� ���̸���
    // ����ֵ  ����
    // �������ڣ�2008-09-23
    // �޸����ڣ�2009-01-15
    // ����˵����
    //================================================================================
	void _gsKCptCoKrigVol(double *pdOutAttr, double *pdOutVari, long *plPntNum, 
		                  double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL,BOOL bIsShowProgr=TRUE);


	//================================================================================
    // �� �� _gsKCptCoKrigPnt
    // �����������ú�����������Э�����(��ɢ������)
	// ���������pEstPnt            �� ����ֵ������
	//           lEstPntNum         �� ����ֵ�����
	// ���������pdOutAttr          �� Э������ֵ���
    //           pfPropVal          �� Э��������ֵ
	//           pfQuanVal          �� Э������λֵ
	//           plPntNum           �� Э������ֵ�������ĵ���
	//           pfMeanDis          �� ��ֵ�㵽�������ƽ������
	//           lEngTypeNum        �� ����������
	//           pKrigEngNum        �� ���̸���
    // ����ֵ  ����
    // �������ڣ�2008-09-23
    // �޸����ڣ�2009-01-15
    // ����˵����
    //================================================================================
	void _gsKCptCoKrigPnt(GsDiscPnt *pEstPnt, long lEstPntNum, double *pdOutAttr, double *pdOutVari, long *plPntNum, 
	                      double *pfMeanDis, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL);

	//================================================================================
    // �� �� ����_gsKBackTr
    // �����������ú��������Թ�ֵ���������任
	// ���������dOutAttr           �� ��ֵ���
	//           dOutVari           �� ��ֵ����
	//           lOutPntNum         �� ��ֵ�������
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _gsKBackTr(double *dOutAttr, double *dOutVari, long &lOutPntNum);

private:
	//ԭʼ������Ϣ
	GsDiscPnt  *m_pDiscPnts;
	GsDiscPnt1 *m_pDiscPnts1;
	long        m_lpntNum;
	double     *tr_var;
	double     *tr_vrg;

	//2008-9-23
	GsDiscPnt  *m_pDiscPntsSec;
	GsDiscPnt1  *m_pDiscPntsSec1;
	long        m_lPntNumSec;

	//���ݼ�ֵ
	double      m_fExtrMax;
	double      m_fExtrMin;

	//��������
	CGeoStat   *m_KrigObj;

	//������Ϣ
	int         m_xnum;
	int         m_ynum;
	int         m_znum;
    double      m_xmini;
	double      m_ymini;
	double      m_zmini;
    double      m_xsize;
	double      m_ysize;
	double		m_zsize;

	int         m_xnum1;
	int         m_ynum1;
	int         m_znum1;
	double      m_xmini1;
	double      m_ymini1;
	double      m_zmini1;
	double      m_xsize1;
	double      m_ysize1;
	double		m_zsize1;

	//����������Ϣ
    double		m_maxr_sec;
	double		m_minr_sec;
	double		m_verr_sec; 	             
	int			m_ang1_search;
	int			m_ang2_search;
	int			m_ang3_search;
    int			m_minnum_krg;
	int			m_maxnum_krg;
	int			m_numxblock;
	int			m_numyblock;
	int			m_numzblock;

	//�α���������Ϣ2008-9-24
	int		    m_iMaxSrchNumSec;
	double		m_fSrchMaxr_Sec;
	double		m_fSrchMinr_Sec;
	double		m_fSrchVerr_Sec;

	//������Ͻ��	
	int			m_nst[1];
	double		m_c0[1];
	int			m_it[GS_MAXNST];
	double		m_cc[GS_MAXNST]; 
	double		m_ang1[GS_MAXNST];
	double		m_ang2[GS_MAXNST];
	double		m_ang3[GS_MAXNST];
	double 		m_aa[GS_MAXNST];
	double		m_aa1[GS_MAXNST];
	double		m_aa2[GS_MAXNST];	

	//2008-9-24
	Kt3dIntp    m_CokIntpPara[GS_MXVARG];
	
	//�������Ϣ
	int			m_noct;
	int			m_ktype;
	int			m_koption;
	double      m_meansk;
	int         m_idrif[9];
	int         m_translation;
	double      m_fMinZero;
	int         m_iDisPower;

	//2008-9-24
	int         m_iCoktype;
	double      m_pfMeanVal[GS_MAXVRG];
	
	//����ָʾ��������	
	double		m_ikfThres[GS_MAXCUT];
	double      m_ikfCdf[GS_MAXCUT];
	int         m_ikCutNum;
    double      m_ikCutOff;

	double      m_fPropThres;
	double      m_fQuanThres;

	Kt3dIntp    m_IkIntpPara[GS_MAXCUT];
	int         m_iktype;
	int         m_ktype_ik;

	//�Ƿ���ʾ������
	BOOL        m_bIsShowProgr;
};

#ifndef _GEO_STAT_KRIG_LIB
	#ifdef _DEBUG
		#pragma comment(lib, "GeoStatKrigLibD.lib")
	#else
		#pragma comment(lib, "GeoStatKrigLib.lib")
	#endif
#endif
#endif // !defined(AFX_GEOSTATKRIGLIB_H__614596C4_13C5_4CC1_B75B_AD7383089B49__INCLUDED_)
