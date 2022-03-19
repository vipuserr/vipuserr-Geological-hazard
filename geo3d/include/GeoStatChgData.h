//==========================================================================
//      ��Ȩ:ZTYQ Tech. Co., Ltd.//��Ȩ
//      ������: GeoStatKrig��
//      ����: lhy��2007.12
//      ��������: ������ݱ任�ʹ�����
//      �汾:  1.1��2007.12��
//      �޸ļ�¼:  �ޡ�
//      ��Ҫ�����б�: 
//      _cdLoadGsChgData ------------------------------------------>��������
//      _cdSetExtrData ---------------------------------------->�������ݼ�ֵ
//      _cdSetReplaceData ------------------------------------->�����滻����
//      _cdCptSkmean ---------------------------------------->��������ƽ��ֵ
//      _cdCptDataInfo ---------------------------------------->�������ݷ�Χ
//      _cdCptGridDefine -------------------------------------->�����������
//      _cdCptTranData ------------------------------------>�������ݱ任����
//      _cdCptAxiOrg ---------------------------------------->�����ݽ�����ת
//==========================================================================

#if !defined(AFX_GEOSTATCHGDATA_H__B3A592CA_157B_4DB7_AFC7_4036291DED80__INCLUDED_)
#define AFX_GEOSTATCHGDATA_H__B3A592CA_157B_4DB7_AFC7_4036291DED80__INCLUDED_

#include "gsstru.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _GEO_STAT_KRIG_LIB
#define  _GEO_STAT_KRIG_DLL _declspec(dllimport)
#else
#define _GEO_STAT_KRIG_DLL _declspec(dllexport)
#endif

class _GEO_STAT_KRIG_DLL CGeoStatChgData  
{
public:
	CGeoStatChgData();
	virtual ~CGeoStatChgData();

	//================================================================================
    // �� �� ����_cdLoadGsChgData
    // �����������ú���װ�������,�������ݴ������д��������
	// ���������pDiscPnts          �� ���ݵ�
	//           lDatNum��          �� ������Ŀ
	//           pPreAttr��         �� ԭʼ��������ֵ
	//           bIsDim             �� TRUEΪ��ά���ݣ�FLASEΪ��ά����
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cdLoadGsChgData(GsDiscPnt *pDiscPnts, long lpntNum, double *pPreAttr, BOOL bIsDim);

	//================================================================================
    // �� �� ����_cdSetExtrData
    // �����������ú����������ý������ݱ任���������Եļ�ֵ
	// ���������fExtrMax           �� ���ݼ���ֵ
	//           fExtrMin           �� ���ݼ�Сֵ
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cdSetExtrData(double fExtrMax, double fExtrMin);

	//================================================================================
    // �� �� ����_cdSetReplaceData
    // �����������ú������������滻����
	// ���������fReplaceMax        �� �滻�������ֵ
	//           fReplaceMin        �� �滻������Сֵ
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cdSetReplaceData(double fReplaceMax, double fReplaceMin);

	//================================================================================
    // �� �� ����_cdCptSkmean
    // �����������ú������������������ݵ�ƽ��ֵ
	// ���������fSkMean            �� ����ƽ��ֵ
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	//����ƽ��ֵ
	//˵��: �ú������������������ݵ�ƽ��ֵ
	//����:
	//      fSkMean -----------------> ����ƽ��ֵ(����)
	void _cdCptSkmean(double &fSkMean);

	//================================================================================
    // �� �� ����_cdCptDataInfo
    // �����������ú����������㴫�����ݵ����ݷ�Χ��X��Y��Z����Լ����ݸ���
	// ���������xyzMinDist         �� ���ݷ�Χ����ʼֵ
	//           xyzMaxDist         �� ���ݷ�Χ����ֵֵ
	//           xadistance         �� X����
	//           yadistance         �� Y����
	//           zadistance         �� Z����
	//           lpntNum            �� ���ݸ���
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cdCptDataInfo(GSD_3DOT &xyzMinDist, GSD_3DOT &xyzMaxDist, 
					 double &xadistance, double &yadistance, 
					 double &zadistance, long &lpntNum);

	//================================================================================
    // �� �� ����_cdCptGridDefine
    // �����������ú���������ʼ�������Ĳ���
	// ���������grid_numx          �� X���������
	//           grid_numy          �� Y���������
	//           grid_numz          �� Z���������
	//           grid_sizex         �� X�������С
	//           grid_sizey         �� Y�������С
	//           grid_sizez         �� Z�������С
	//           grid_minix         �� X�������ʼ������
	//           grid_miniy         �� Y�������ʼ������
	//           grid_miniz         �� Z�������ʼ������
	//           grid_maxx          �� X�������ֹ������
	//           grid_maxy          �� Y�������ֹ������
	//           grid_maxz          �� Z�������ֹ������
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cdCptGridDefine(int &grid_numx, int &grid_numy, int &grid_numz,
									double &grid_sizex, double &grid_sizey, double &grid_sizez,
									double &grid_minix, double &grid_miniy, double &grid_miniz,
									double &grid_maxx, double &grid_maxy, double &grid_maxz);	
    
	//================================================================================
    // �� �� ����_cdCptTranData
    // �����������ú��������Դ�������ݽ������ݱ任
	// ���������bExtrModeMin       �� �任ǰ���ݼ���ֵ
	//           bExtrModeMax       �� �任ǰ���ݼ�Сֵ
	//           iTranType          �� ���ݱ任��ʽ: 1�����任��2��̬�任
	//           fMinGzero          �� С��0����Сֵ
	//           tr_var             �� ��̬�任��Ӧ��(��任���õ�)
	//           tr_vrg             �� ��̬�任��Ӧ��(��任���õ�)
	// ���������TranMax            �� �任���������ֵ
	//           TranMin            �� �任��������Сֵ
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cdCptTranData(BOOL bExtrModeMin, BOOL bExtrModeMax, int iTranType, double fMinGzero,
		                double *tr_var, double *tr_vrg, double &TranMax, double &TranMin);
	
	//================================================================================
    // �� �� ����_cdCptAxiOrg
    // �����������ú������ڽ��п���ģ�͵���ת
	// ���������azm                �� ��ת��λ��
	//           dip                �� ��ת���
	//           Org                �� ��ת�����
	//           OrigXYZ            �� ��ת����
	//           pPreXyz            �� ԭʼ��XYZ����
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================	
	void _cdCptAxiOrg(int azm, int dip, int org, GSD_3DOT OrigXYZ, GSD_3DOT *pPreXyz);
	

	//-----------------------------------2008��8��21��------------------------------------------//
	//װ������
	//˵��:	�ú���װ�������,�������ݴ������д��������. 
	//����:	
	//		pDiscPnts[] -------------> ���ݵ�
	//		lDatNum -----------------> ������Ŀ
	//      pPreAttr[] --------------> ԭʼ��������ֵ
	//      bIsDim ------------------> TRUEΪ��ά���ݣ�FLASEΪ��ά����
	void _cdLoadGsChgData2(GsDiscPnt *pDiscPnts, long lpntNum, double *pPreAttr);

	GsDiscPnt  *m_pDiscPntsSec;
	long        m_lpntNumSec;
	double     *m_pPreAttrSec;

	//--------------------------------------end------------------------------------------------//
	
private:
	//ԭʼ������Ϣ
	GsDiscPnt  *m_pDiscPnts;
	long        m_lpntNum;
	double     *m_pPreAttr;
	BOOL        m_bIsDim;
    //���ݼ�ֵ
	double      m_fExtrMax;
	double      m_fExtrMin;

	//�滻����
	double      m_fReplaceMax;
	double      m_fReplaceMin;

    //��Χ��
	GSD_3DOT      m_xyzMinDist;
	GSD_3DOT      m_xyzMaxDist;
    //���ݼ��
	double      m_xadistance;
	double      m_yadistance;
	double      m_zadistance;

};

#ifndef _GEO_STAT_KRIG_LIB
	#ifdef _DEBUG
		#pragma comment(lib, "GeoStatKrigLibD.lib")
	#else
		#pragma comment(lib, "GeoStatKrigLib.lib")
	#endif
#endif
#endif // !defined(AFX_GEOSTATCHGDATA_H__B3A592CA_157B_4DB7_AFC7_4036291DED80__INCLUDED_)
