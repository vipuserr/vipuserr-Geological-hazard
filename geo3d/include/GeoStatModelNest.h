//==========================================================================
//      ��Ȩ:ZTYQ Tech. Co., Ltd.//��Ȩ
//      ������: GeoStatKrig��
//      ����: lhy��2007.05
//      ��������: ��ɱ������㼰��Ϲ���
//      �汾:  1.1��2007.05��
//      �޸ļ�¼:  �ޡ�
//      ��Ҫ�����б�: 
//      _mnLoadGsModelNest ---------------------------------------->��������
//      _mnSetExtrData ---------------------------------------->�������ݼ�ֵ
//      _mnSetGamvParam ------------------------------->���ñ����������
//      _mnCptExpVrg -------------------------------------->����ʵ�����
//      _mnComputerVM ----------------------------------->�����������ͼ
//      _mnAutoFitVrg ------------------------------->�Ե��������������
//      CptAllVrgFitDsp ------------------------------->�������������
//==========================================================================

#if !defined(AFX_GEOSTATMODELNEST_H__6B7DBAFB_3909_4DF7_9441_044F8CD47BBB__INCLUDED_)
#define AFX_GEOSTATMODELNEST_H__6B7DBAFB_3909_4DF7_9441_044F8CD47BBB__INCLUDED_

#include "GsStru.h"
#include "geostatlib.h"

#include "RSErrorOpr.h"			//������

#include   <vector> 
using   namespace   std;   

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _GEO_STAT_KRIG_LIB
#define  _GEO_STAT_KRIG_DLL _declspec(dllimport)
#else
#define _GEO_STAT_KRIG_DLL _declspec(dllexport)
#endif



class _GEO_STAT_KRIG_DLL CGeoStatModelNest  
{
public:
	CGeoStatModelNest();
	virtual ~CGeoStatModelNest();
	
	//================================================================================
    // �� �� ����_mnLoadGsModelNest
    // �����������ú���װ�������,���Ǳ������㼰��Ϲ����д��������
	// ���������pDiscPnts          �� ���ݵ�
	//           plpntNum           �� ������Ŀ
	//           bIsDim             �� TRUEΪ��ά���ݣ�FLASEΪ��ά����
	//           bIsDsp3D��         �� �Ƿ���ʾ��άͼ��
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================		
    void _mnLoadGsModelNest(GsDiscPnt *pDiscPnts, long plpntNum, BOOL bIsDim, BOOL bIsDsp3D);	

	//================================================================================
    // �� �� ����_mnSetExtrData
    // �������������ñ����������ݼ�ֵ
	// ���������fExtrMax           �� ���ݼ���ֵ
	//           fExtrMin           �� ���ݼ�Сֵ
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnSetExtrData(double fExtrMax, double fExtrMin);    

	//================================================================================
    // �� �� ����_mnSetVrgType
    // �������������ñ�����������
	// ���������ivType             �� ��������
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnSetVrgType(int ivType);	

	//================================================================================
    // �� �� ����_mnSetVrgAnis
    // ���������������Ƿ�Ϊ�������Դ���
	// ���������banisang           �� �Ƿ�Ϊ��������
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnSetVrgAnis(BOOL banisang);

	//================================================================================
    // �� �� ����_mnSetAnis
    // �������������ø������ԽǶ�
	// ���������anisang1           �� �������Է�λ��
	//           anisang1           �� �������������
	//           anisang1           �� �����������
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnSetAnis(double anisang1, double anisang2, double anisang3);

	//================================================================================
    // �� �� ����_mnSetVrgThre
    // ����������������ֵ
	// ���������vrg_num            �� ��������
	//           vrg_thre           �� ָʾ��ֵ
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnSetVrgThre(int vrg_num, double vrg_thre[]);	

	//================================================================================
    // �� �� ����_mnSetGamvParam
    // ��������������ʵ������������
	// ���������vrgdlag            �� ������С
	//           vrgltol            �� �����ݲ�
	//           vrgnlag            �� ������Ŀ
	//           vrg_azmtol         �� ��λ�ǽǶ��ݲ�
	//           vrg_bandwd         �� ˮƽ����
	//           vrg_bandwh         �� ��ֱ����
	//           vrg_diptol         �� ��ǽǶ��ݲ�
	//           vrg_azm            �� ��λ��
	//           vrg_dip            �� ���
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnSetGamvParam(double	vrgdlag, double vrgltol, long vrgnlag, double vrg_azmtol,
	         double	vrg_bandwh, double vrg_bandwd, double vrg_diptol, int vrg_azm, int vrg_dip);

		//================================================================================
    // �� �� ����_mnSetGamvParam
    // ��������������ʵ������������
	// ���������vrgdlag[]          �� ������С
	//           vrgltol[]          �� �����ݲ�
	//           vrgnlag[]          �� ������Ŀ
	//           lParamNum          �� ��������
	//           vrg_azmtol         �� ��λ�ǽǶ��ݲ�
	//           vrg_bandwd         �� ˮƽ����
	//           vrg_bandwh         �� ��ֱ����
	//           vrg_diptol         �� ��ǽǶ��ݲ�
	//           vrg_azm            �� ��λ��
	//           vrg_dip            �� ���
    // ����ֵ  ����
    // �������ڣ�2009-08-26
    // �޸����ڣ�2009-08-26
    // ����˵����
    //================================================================================
	void _mnSetGamvParam(double	vrgdlag[], double vrgltol[], long vrgnlag[], long lParamNum, double vrg_azmtol,
	         double	vrg_bandwh, double vrg_bandwd, double vrg_diptol, int vrg_azm, int vrg_dip);

		//================================================================================
    // �� �� ����_mnSetGamvParam
    // ��������������ʵ������������
	// ���������vrgdlag            �� ������С
	//           vrgltol            �� �����ݲ�
	//           vrgnlag            �� ������Ŀ
	//           vrg_azmtol         �� ��λ�ǽǶ��ݲ�
	//           vrg_bandwd         �� ˮƽ����
	//           vrg_bandwh         �� ��ֱ����
	//           vrg_diptol         �� ��ǽǶ��ݲ�
	//           vrg_azm[]          �� ��λ��
	//           vrg_dip[]          �� ���
	//           lParamNum          �� ��������
    // ����ֵ  ����
    // �������ڣ�2009-08-26
    // �޸����ڣ�2009-08-26
    // ����˵����
    //================================================================================
	void _mnSetGamvParam(double	vrgdlag, double vrgltol, long vrgnlag, double vrg_azmtol[],
	         double	vrg_bandwh[], double vrg_bandwd[], double vrg_diptol[], int vrg_azm[], int vrg_dip[], long lParamNum);


	//================================================================================
    // �� �� ����_mnCptExpVrg
    // ��������������ʵ�����
	// ���������pVrgResult         �� ʵ�����ֵ
	//           fSill ��           �� ����
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnCptExpVrg(Variogram *pVrgResult, double &fSill);	

	//================================================================================
    // �� �� ����_mnCptAnisExpVrg
    // �����������������������ʵ�����
	// ���������pVrgResultMax      �� ���᷽�����ֵ
	//           pVrgResultMin      �� ���᷽�����ֵ
	//           pVrgResultVer      �� ��ֱ�᷽�����ֵ
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnCptAnisExpVrg(Variogram *pVrgResultMax, Variogram *pVrgResultMin, Variogram *pVrgResultVer);
	
	//================================================================================
    // �� �� ����_mnLoadResult
    // ��������������������
	// ���������pVrgResult         �� ����ֵ
	//           pVrgWeight         �� ����Ȩ��
	//           pVrgModel          �� ������Ͻ��
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	//����������
	void _mnLoadResult(Variogram *pVrgResult, double *pVrgWeight,
									  Kt3dIntp *pVrgModel);

	//================================================================================
    // �� �� ����_mnGetAnis
    // �����������õ��������ԽǶ�
	// ���������anisang1           �� �������Է�λ��
	//           anisang1           �� �������������
	//           anisang1           �� �����������
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnGetAnis(int &anisang1, int &anisang2, int &anisang3);

	//================================================================================
    // �� �� ����_mnGetGamvParam
    // �����������õ�ʵ������������
	// ���������vrgdlag            �� ������С
	//           vrgltol            �� �����ݲ�
	//           vrgnlag            �� ������Ŀ
	//           vrg_azmtol         �� ��λ�ǽǶ��ݲ�
	//           vrg_bandwd         �� ˮƽ����
	//           vrg_bandwh         �� ��ֱ����
	//           vrg_diptol         �� ��ǽǶ��ݲ�
	//           vrg_azm            �� ��λ��
	//           vrg_dip            �� ���
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnGetGamvParam(double	&vrgdlag, double &vrgltol, long &vrgnlag, double &vrg_azmtol,
	         double	&vrg_bandwd, double &vrg_bandwh, double &vrg_diptol, int &vrg_azm, int &vrg_dip);

	//================================================================================
    // �� �� ����_mnGetGamvResult
    // ����������ȡ�ñ������
	// ���������pVrgResult         �� ʵ�������
	//           pVrgWeight         �� ʵ�����Ȩֵ
	//           pVrgPoint          �� ʵ�����������
	//           pbSelect           �� ʵ�����ѡ�б�־
	//           pVrgModel          �� ������Ͻ��
	//           pVrgModInd         �� ��Ϻ�ı�����
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnGetGamvResult(Variogram **pVrgResult, double **pVrgWeight, CPoint **pVrgPoint, BOOL **pbSelect,
		     Kt3dIntp **pVrgModel, ModIndVrg **pVrgModInd);

	//================================================================================
    // �� �� ����_mnGetVarMapPlant
    // ����������ȡ�ñ�������ͼ������������
	// ���������dX1                �� ��1X
	//           dY1                �� ��1Y
	//           dZ1                �� ��1Z
	//           dX2                �� ��2X
	//           dY2                �� ��2Y
	//           dZ2                �� ��2Z
	//           dX3                �� ��3X
	//           dY3                �� ��3Y
	//           dZ3                �� ��3Z
	//           dXvertical         �� �㴹ֱ��X
	//           dYvertical         �� �㴹ֱ��Y
	//           dZvertical         �� �㴹ֱ��Z
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnGetVarMapPlant(double &dX1, double &dY1, double &dZ1, double &dX2, double &dY2, double &dZ2,
		     double &dX3, double &dY3, double &dZ3, double &dXvertical, double &dYvertical, double &dZvertical);

	//================================================================================
    // �� �� ����_mnGetVrgMod
    // ����������ȡ�ñ���ģ����Ϣ��ά
	// ���������vrgmodX            �� x����ֵ
	//           vrgmodY            �� y����ֵ
	//           vrgmodZ            �� z����ֵ
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	//ȡ�ñ���ģ����Ϣ
	void _mnGetVrgMod(double vrgmodX[], double vrgmodY[], double vrgmodZ[]);

	//================================================================================
    // �� �� ����_mnSetVarMapAng
    // �������������ñ�������ͼ�Ƕ�
	// ���������vmazm              �� ��λ��
	//           vmdip              �� ���
	//           vmorg              �� �����
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnSetVarMapAng(double vmazm, double vmdip, double vmorg);

	//================================================================================
    // �� �� ����_mnSetVrgNug
    // �������������ÿ��ֵ
	// ���������vrgmodnugget       �� ���ֵ
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	//���ÿ��ֵ
	void _mnSetVrgNug(double  vrgmodnugget);

	//================================================================================
    // �� �� ����_mnGetVrgSill
    // ����������ȡ�û�ֵ̨
	// ���������vrgmodsill         �� ��ֵ̨
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnGetVrgSill(double &vrgmodsill);

	//================================================================================
    // �� �� ����_mnGetVrgAnis
    // ����������ȡ���Ƿ�Ϊ��������
	// ���������banisang           �� �Ƿ�Ϊ��������
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnGetVrgAnis(BOOL &banisang);

	//================================================================================
    // �� �� ����_mnSetVrgAnisAng
    // ����������������������Ƕ�
	// ���������azmmax��           �� ���᷽λ��
	//           dipmax��           �� �������
	//           azmmin��           �� ���᷽λ��
	//           dipmin��           �� �������
	//           azmver��           �� ��ֱ�᷽λ��
	//           dipver��           �� ��ֱ�����
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnSetVrgAnisAng(int azmmax, int dipmax, int azmmin, int dipmin,
		                  int azmver, int dipver);

	//================================================================================
    // �� �� ����_mnGetVrgAnisAng
    // ����������ȡ����������Ƕ�
	// ���������azmmax��           �� ���᷽λ��
	//           dipmax��           �� �������
	//           azmmin��           �� ���᷽λ��
	//           dipmin��           �� �������
	//           azmver��           �� ��ֱ�᷽λ��
	//           dipver��           �� ��ֱ�����
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnGetVrgAnisAng(int &azmmax, int &dipmax, int &azmmin, int &dipmin,
		                  int &azmver, int &dipver);

	//================================================================================
    // �� �� ����_mnSetListVrgModel
    // �������������ñ�����Ͻ��
	// ���������pListVrgModel      �� ������Ͻ��
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnSetListVrgModel(Kt3dIntp *pListVrgModel);

	//================================================================================
    // �� �� ����_mnSetVrgStruChg
    // �������������ñ�����Ͻ���ɷ��޸�
	// ���������bIsVrgChg          �� ������Ͻ���ɷ��޸�
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnSetVrgStruChg(BOOL bIsVrgChg);

	//================================================================================
    // �� �� ����_mnSetIvCutOff
    // ����������������ֵ
	// ���������ivCutOff           �� ��ֵ
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	//������ֵ
	void _mnSetIvCutOff(int ivCutOff);

	//================================================================================
    // �� �� ����_mnSetSelectWeight
    // ��������������Ȩֵ
	// ���������bselect            �� �Ƿ�ѡ�б�־
	//           fweight            �� Ȩֵ
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnSetSelectWeight(BOOL *bselect, double *fweight);

	//================================================================================
    // �� �� ����_mnChgAngUpdatadsp
    // �����������޸ı���ͼ��ʾ�Ƕ�
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnChgAngUpdatadsp();

	//================================================================================
    // �� �� ����_mnCheckAnisang
    // �����������෽��������
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnCheckAnisang();

    //================================================================================
    // �� �� ����_mnChgAngAnisUpdatadsp
    // �����������޸ĸ������ԽǶ�
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnChgAngAnisUpdatadsp();

	//================================================================================
    // �� �� ����_mnChgVrgStruUpdatadsp
    // �����������޸ı����ṹ
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnChgVrgStruUpdatadsp();

	//================================================================================
    // �� �� ����_mnChgVrgParamUpdatadsp
    // �����������޸�ʵ���������
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnChgVrgParamUpdatadsp();

	//================================================================================
    // �� �� ����_mnDelVrgUpdatadsp
    // �����������޸�Ȩֵ
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnDelVrgUpdatadsp();

	//================================================================================
    // �� �� ����_mnSetDataInfo
    // �����������������ݱ任��Ϣ
	// ���������ktype ��           �� ������ֵ����
	//           tran  ��           �� ���ݱ任��ʽ
	//           tmindata           �� �任ǰ��Сֵ
	//           tmaxdata��         �� �任ǰ����ֵ
	//           bextrmode          �� ��Сֵ����ʽ
	//           bextrmodemax       �� ����ֵ����ʽ
	//           tfReplacemin       �� ��Сֵ�滻ֵ 
	//           tfReplacemax       �� ����ֵ�滻ֵ
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnSetDataInfo(int ktype, int tran,double tmindata, double tmaxdata, BOOL bextrmode, BOOL bextrmodemax,
		                double tfReplacemin, double tfReplacemax);

	//================================================================================
    // �� �� ����_mnSetIkType
    // ��������������ָʾ����
	// ���������ikType��           �� ָʾ����
	//           ikCutOff           �� ָʾ��ֵ
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnSetIkType(int ikType, double ikCutOff);

   	//��������ͼ

	//================================================================================
    // �� �� ����_mnSetVarmapParam
    // ������������ʼ����������ͼ����
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnSetVarmapParam();	

	//================================================================================
    // �� �� ����_mnSetVarMapParam
    // �������������ñ�������ͼ����
	// ���������vmdlag             �� ��������ͼ������С
	//           vmminnp            �� ��С���ݶ���
	//           vmnlag             �� ������Ŀ
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
    void _mnSetVarMapParam(double vmdlag, double vmminnp, double vmnlag);

	//================================================================================
    // �� �� ����_mnComputerVM
    // ���������������������ͼ��ֵ
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
    void _mnComputerVM();

	//================================================================================
    // �� �� ����_mnGetVarMapParam
    // �����������������ݱ任��Ϣ
	// ���������vmdlag             �� ��������ͼ������С
	//           vmminnp            �� ��С���ݶ���
	//           vmnlag             �� ������Ŀ
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	//��ȡ��������ͼ����
	void _mnGetVarMapParam(double &vmdlag, long &vmminnp, long &vmnlag);

	//================================================================================
    // �� �� ����_mnGetVarMapResult
    // ������������ȡ��������ͼ������
	// ���������vmresult��         �� ��������ͼ���
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	//��ȡ��������ͼ������
    void _mnGetVarMapResult(double **vmresult);

	//�ļ�����	
	//================================================================================
    // �� �� ����_mnGetVrgDataType
    // �����������õ��ļ�����
	// ���������strFileName ��     ���ļ�����
    // ����ֵ  ��                   ���ļ�����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	int  _mnGetVrgDataType(CString strFileName);

	//================================================================================
    // �� �� ����_mnLoadGamvFile
    // ������������������ļ�
	// ���������strFileName        �� �ļ�����
	//           bIsDsp3D  ��       �� �Ƿ���ʾ��άͼ��
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	int  _mnLoadGamvFile(CString strFileName, BOOL bIsDsp3D);

	//================================================================================
    // �� �� ����_mnLoadGamvFile1
    // ������������������ļ�
	// ���������strFileName        �� �ļ�����
	//           bIsDsp3D  ��       �� �Ƿ���ʾ��άͼ��
    // ����ֵ  ��1/0                �� �ɹ�/ʧ��
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	int  _mnLoadGamvFile1(CString strFileName, BOOL bIsDsp3D);

	//================================================================================
    // �� �� ����_mnLoadCoVarianceFile
    // ������������������ļ�
	// ���������strFileName        �� �ļ�����
	//           bIsDsp3D  ��       �� �Ƿ���ʾ��άͼ��
    // ����ֵ  ��1/0                �� �ɹ�/ʧ��
    // �������ڣ�2008-09-23
    // �޸����ڣ�2008-09-23
    // ����˵����
    //================================================================================
	int  _mnLoadCoVarianceFile(CString strFileName, BOOL bIsDsp3D);

	//================================================================================
    // �� �� ����_mnSaveGamvFile
    // ������������������ļ�
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	//��������ļ�
	void _mnSaveGamvFile();

	//================================================================================
    // �� �� ����_mnAutoFitVrg
    // �����������Զ���ϱ���
	// ���������pVrgResult         �� ʵ�������Ϣ 
	//           pVrgWeight  ��     �� ����Ȩ��
	//           nlag               �� ���������
	// ���������pVrgModel��        �� ������Ͻ��
    // ����ֵ  ����
    // �������ڣ�2007-08-03
    // �޸����ڣ�2007-08-03
    // ����˵����
    //================================================================================
	void _mnAutoFitVrg(Variogram *pVrgResult, double *pVrgWeight, int nlag, Kt3dIntp *pVrgModel);

	//-----------------------------------2008��8��22��lhy------------------------------------//
	//�����Ƿ���ʾ������
	void _mnSetIsShowProgr(BOOL bIsShowProgr);
	//�õ�������Ͻ��
	void _mnGetVrgModel(Kt3dIntp *pVrgModel);
	//----------------------------------------end--------------------------------------------//
	//-----------------------------------2008��8��27��lhy------------------------------------//

	void _mnSetVrgMapParam(double dLagX, double dLagY, double dLagZ, int nLagX, int nLagY, int nLagZ);
	void _mnSetVrgMapMinPairs(int iMinPairs);
	long _mnCptVrgMapValue(double *pVrgMapVal);

	double m_dLagX;
	double m_dLagY;
	double m_dLagZ;
	int    m_nLagX;
	int    m_nLagY;
	int    m_nLagZ;
	int    m_iMinPairs;
	//----------------------------------------end--------------------------------------------//
public:
	//��ʼ���Ի����еı���	
	void InitDlgParam();

	//��ʼ����������
	void InitGamvParam();
	
	//��ʼ����������ͼ
	void InitVarView();
	//�������ĳ�ʼ��
	void CptAllVrgFitDsp(Variogram *resultmax, double *weightmax, int nlagmax, 
						 Variogram *resultmin, double *weightmin, int nlagmin,
						 Variogram *resultver, double *weightver, int nlagver, int icutoff);
private:
	GsDiscPnt *DiscPnts;
	long       lpntNum;
	BOOL       m_bIsDim;
	BOOL       m_bIsDsp3D;

	CRSErrorOpr *		m_pError;				//������
	CString				m_strErrorText;			//��������

public:	
	//���ݱ任��Ϣ
	int m_ktype;
	int m_tran;
	double m_tmindata;
	double m_tmaxdata;
	BOOL m_bextrmode;
	BOOL m_bextrmodemax;

	double m_fReplaceMin;
	double m_fReplaceMax;

//��������ͼ	
public:

   int		m_iPostPos[3];           //��¼ˮƽ������ǰһ��λ��
   int		m_iCurPos;               //��¼ˮƽ��������ǰλ��
   
   //������¼��������и�ƽ��
   double   m_dX1;                   
   double   m_dY1;
   double   m_dZ1;
   double   m_dX2;
   double   m_dY2;
   double   m_dZ2;
   double   m_dX3;
   double   m_dY3;
   double   m_dZ3;
   double   m_dXvertical;
   double   m_dYvertical;
   double   m_dZvertical;
   
   //��¼ʵ���������ģ����ʾ�İ˸�������
   double  m_vrgmodX[8];
   double  m_vrgmodY[8];
   double  m_vrgmodZ[8];
   
   //��¼�Ƿ���ʾ��ֱƽ��
   BOOL     m_bvertical;

   double   *vmvalue;                //��¼��������ͼ��ÿ��С�������ֵ
   
   //Dingle��ʼ��
   void InitRoot();

   //�������Ƕ��и�ƽ�������������
   void Computerplant(int azm, int dip, int org);
   //��ʵ�����ģ����ʾ����
   void Computervrgmod();
public:

	//��¼Ҫ����ı���
    vector< Variogram * > m_vector_result;
    vector< Kt3dIntp * > m_vector_model;
	vector< GamvParam > m_vector_param;
	vector< BOOL * > m_vector_bsel;
	vector< double * > m_vector_weight;

    Variogram *m_vrgresult_save;
	Kt3dIntp  *m_vrgmodel_save;
	GamvParam  m_gamvparam_save;
	BOOL      *m_bselect_save;
	double    *m_vrgweight_save;

	int        m_vector_ipos;
	
    //��������������浽�ڴ浱��
	BOOL PushVectorVrg(Variogram *vrg_result, double *vrg_weight, BOOL *bselect, 
					   Kt3dIntp *vrg_model,long vrgnlag, double vrgdlag, double vrgltol,int vrgazm,
					   int vrgdip, double azmtol, double diptol, double bandwh, double bandwd);
    //���ڴ��ж�ȡ����
	void ReadVectorVrg(int nt, Variogram **vrg_result, double **vrg_weight, CPoint **vrg_point, BOOL **bselect, 
					   long &vrgnlag, double &vrgdlag, double &vrgltol,int &vrgazm, int &vrgdip,
					   double &azmtol, double &diptol, double &bandwh, double &bandwd);
    //�޸ĺ�ı����ı���
	void ModifyVectorVrg(int nt, vector< Variogram * > &vector_result, vector< Kt3dIntp * > vector_model, 
						vector< GamvParam > &vector_param, vector< BOOL * > &vector_bsel,vector< double * > &vector_weight);
	//ɾ��Vector�еı���
	void DeletVectorVrg();

public:	
	//��¼Ҫ����ı���(�෽��)
	//����̷���
    vector< Variogram * > m_vector_resultmax;
	vector< GamvParam > m_vector_parammax;
	vector< BOOL * > m_vector_bselmax;
	vector< double * > m_vector_weightmax;

    Variogram *m_vrgresultmax_save;
	GamvParam  m_gamvparammax_save;
	BOOL      *m_bselectmax_save;
	double    *m_vrgweightmax_save;

	//��С��̷���    
	vector< Variogram * > m_vector_resultmin;
	vector< GamvParam > m_vector_parammin;
	vector< BOOL * > m_vector_bselmin;
	vector< double * > m_vector_weightmin;

    Variogram *m_vrgresultmin_save;
	GamvParam  m_gamvparammin_save;
	BOOL      *m_bselectmin_save;
	double    *m_vrgweightmin_save;
		
	//��ֱ��̷���    
	vector< Variogram * > m_vector_resultver;	
	vector< GamvParam > m_vector_paramver;
	vector< BOOL * > m_vector_bselver;
	vector< double * > m_vector_weightver;

    Variogram *m_vrgresultver_save;
	GamvParam  m_gamvparamver_save;
	BOOL      *m_bselectver_save;
	double    *m_vrgweightver_save;

	//��������
    vector< Kt3dIntp * > m_vector_modelanis;
	Kt3dIntp   *m_vrgmodelanis_save;

	int        m_vector_iposanis;
	
	//���෽��������浽�ڴ浱��
	BOOL PushVectorVrgAnis();
	//ɾ���෽�����
	void DeletVectorVrgAnis();
	//���ڴ��ж�ȡ�෽�����
	void ReadVectorVrgAnis(int nt);

private:
	//���ݴ洢 
	CGeoStat	*VrgObj;             //�ܽṹ
	long        lattrNum;             //���Ը���
	CString     *attrname;            //��������
public:
	double       m_tmin;
	double       m_tmax;

public:
    //��Χ�еĴ�С
    GSD_3DOT   	xyzMinDist;             
	GSD_3DOT      xyzMaxDist;
	BOOL        m_dimension;        //TUREΪ3D��FALSEΪ2D��

//�б�ؼ�
public:
	Kt3dIntp    *VrgModel;             //��¼��Ϻ�ı����ṹ	
	CString     m_strText;               //��¼��ͷ��Ϣ

	Kt3dIntp    *ListVrgModel;
//����ͼ	
public:
    Variogram   *m_vrg_result;         //��¼���������ϵ�ʵ�����ֵ
	double      *m_vrg_weight;
	int          m_vrg_iWFun;
	
	//��¼���������ϵ�ʵ�����ֵ
	Variogram *m_resultmax;   
	Variogram *m_resultmin;
	Variogram *m_resultver;
    double    *m_weightmax;
	double    *m_weightmin;
	double    *m_weightver;
    int        m_iWFunmax;
	int        m_iWFunmin;
	int        m_iWFunver;

	ModIndVrg   *vrg_ModInd;         //��¼���������ϵ����۱���ֵ

	CWnd   *vrg_pWndDraw;            //��ͼ����Ĵ��ھ��

	CPoint *m_vrg_point;             //��¼����ͼ�е������(��Ļ����)
	BOOL   *m_bselect;    

	BOOL    m_bdspline;              //��¼�Ƿ���ʾʵ���������
	
	//��¼����ͼ�еĵ����꣨��Ļ���꣩
	CPoint *m_vrg_pointmax; 
	CPoint *m_vrg_pointmin;
	CPoint *m_vrg_pointver;
	//��¼ÿ�����ɾ�����
	BOOL   *m_bselectmax;
	BOOL   *m_bselectmin;
	BOOL   *m_bselectver;

	//��¼��������Ĳ�������������С�Ͳ�������ֵ
	long   m_vrg_nlagmax;
	long   m_vrg_nlagmin;
	long   m_vrg_nlagver;

	double m_vrg_dlagmax;
	double m_vrg_dlagmin;
	double m_vrg_dlagver;

	double m_vrg_ltolmax;
	double m_vrg_ltolmin;
	double m_vrg_ltolver;

	double m_vrg_azmtolmax;
	double m_vrg_azmtolmin;
	double m_vrg_azmtolver;
	double m_vrg_diptolmax;
	double m_vrg_diptolmin;
	double m_vrg_diptolver;

	double m_vrg_bandwhmax;
	double m_vrg_bandwhmin;
	double m_vrg_bandwhver;
	double m_vrg_bandwdmax;
	double m_vrg_bandwdmin;
	double m_vrg_bandwdver;

	int    m_preivType;
public:
	//���ñ�������
	void SetVrgParam(int azm, int dip);
	//���ñ����������
	void SetComputerVrg(long nlag, double xlag, double xltol, double azm, double atol, 
						            double bandwh, double dip, double dtol, double bandwd, long isill,
									int ivtype, double cutoff[], int itailhead, double nvarg);
	//���ñ����������
	//�޸ģ�2009-09-07
	void SetComputerVrg(long nlag[], double xlag[], double xltol[], long lParamNum, double azm[], double atol[], 
						            double bandwh[], double dip[], double dtol[], double bandwd[], long lDirNum, long isill,
									int ivtype, double cutoff[], int itailhead, double nvarg);
	//������������ı�������
    void SetAllVrgParam();
	//�������᷽���ϵ�ʵ�����ֵ
	void CptMaxVrg();
	//������᷽���ϵ�ʵ�����ֵ
	void CptMinVrg();
	//���㴹ֱ�᷽���ϵ�ʵ�����ֵ
	void CptVerVrg();
	//���������ϲ���
	void ComputerVrgPara(double *fC0, double *fC, double *fA,Variogram *resultmax, double *weightmax, int nlagmax, 
						 Variogram *resultmin, double *weightmin, int nlagmin,
						 Variogram *resultver, double *weightver, int nlagver, int icutoff);
	//�ɱ�����Ͻ������һ������ı���ֵ
	void ComputerVmodel();
	//����һ�������ϵı���ֵ���������,����ʾ
	void CptOneVrgFitDsp(Variogram *vrg_result, double *vrg_weight, int nlag, int icutoff);
	//����һ�������ϵı���
	void CptOneVrg(int azm, int dip, BOOL bCpt);

	//---------------------------------------2008��8��21��-----------------------------------//

	void _mnLoadGsModelNest2(GsDiscPnt *pDiscPnts, long plpntNum);
   
	void _mnSetParam(long lParam);

	GsDiscPnt *DiscPntsSec;
	long       lpntNumSec;
	//-------------------------------------------end------------------------------//

public:
	BOOL            m_bIsVrgChg;     //��¼��������Ƿ�Ϊ�ɱ༭״̬
	
public:
	int            m_ktypevrg;       //��¼���������
    int            m_vrg_num;        //��¼��ֵ����
	double         m_vrg_Thre[GS_MAXCUT];    //��¼��ֵ

	double	m_vmdlag;
	long	m_vmminnp;
	long	m_vmnlag;
	double	m_vrgdlag;
	double  m_pvrgdlag[GS_MAXVRG];
	double	m_vrgltol;
	double  m_pvrgltol[GS_MAXVRG];
	long    m_lParamNum;
	
	double	m_vrgmodnugget;
	double	m_vrgmodsill;
	long	m_vrgnlag;
	long    m_pvrgnlag[GS_MAXVRG];
	int		m_ivtype;
	int		m_vmorg;
	int		m_dipver;
	int		m_dipmin;
	int		m_dipmax;
	int		m_vmdip;
	int		m_azmver;
	int		m_azmmin;
	int		m_azmmax;
	int		m_vmazm;
	int		m_anisang3;
	int		m_anisang2;
	int		m_anisang1;
	double	m_vrg_azmtol;
	double	m_vrg_bandwd;
	double	m_vrg_bandwh;
	double	m_vrg_diptol;
	int		m_vrg_azm;
	int		m_vrg_dip;	
	double  m_pvrg_azm[GS_MAXVRG];
	double  m_pvrg_dip[GS_MAXVRG];
	double	m_pvrg_azmtol[GS_MAXVRG];
	double	m_pvrg_bandwd[GS_MAXVRG];
	double	m_pvrg_bandwh[GS_MAXVRG];
	double	m_pvrg_diptol[GS_MAXVRG];
	long    m_lDirNum;
	BOOL	m_banisang;
	int     m_ivcutoff;
	CString	m_IvTypeName;
	int     m_iSill;
	double  m_fSill;

	BOOL    m_bIsShowProgr;

	int     m_ikType;
	double  m_ikCutOff;
};

#ifndef _GEO_STAT_KRIG_LIB
	#ifdef _DEBUG
		#pragma comment(lib, "GeoStatKrigLibD.lib")
	#else
		#pragma comment(lib, "GeoStatKrigLib.lib")
	#endif
#endif
#endif // !defined(AFX_GEOSTATMODELNEST_H__6B7DBAFB_3909_4DF7_9441_044F8CD47BBB__INCLUDED_)
