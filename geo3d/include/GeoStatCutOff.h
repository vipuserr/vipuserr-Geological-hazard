//==========================================================================
//      ��Ȩ:ZTYQ Tech. Co., Ltd.//��Ȩ
//      ������: GeoStatKrig��
//      ����: lhy��2007.05
//      ��������: ���Ʒλ��ֵ������
//      �汾:  1.1��2007.05��
//      �޸ļ�¼:  �ޡ�
//      ��Ҫ�����б�: 
//      _cLoadGsCutOff -------------------------------------------->��������
//      _cSetExtrData ----------------------------------------->�������ݼ�ֵ
//      _cCptIkCutOff ----------------------------------------->������ֵ��ֵ
//      _cCptCutOff ----------------------------------------------->������ֵ
//==========================================================================

#if !defined(AFX_GEOSTATCUTOFF_H__D5C63F0D_54F6_41FA_8A0F_FA4E810AD255__INCLUDED_)
#define AFX_GEOSTATCUTOFF_H__D5C63F0D_54F6_41FA_8A0F_FA4E810AD255__INCLUDED_

#include "GsStru.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _GEO_STAT_KRIG_LIB
#define  _GEO_STAT_KRIG_DLL _declspec(dllimport)
#else
#define _GEO_STAT_KRIG_DLL _declspec(dllexport)
#endif

class _GEO_STAT_KRIG_DLL CGeoStatCutOff  
{
public:
	CGeoStatCutOff();
	virtual ~CGeoStatCutOff();


	//================================================================================
    // �� �� ����_cLoadGsCutOff
    // �����������ú���װ�������,������ֵ�������д��������. 
	// ���������pDiscPnts          �� ���ݵ�
	//           lDatNum            �� ������Ŀ
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cLoadGsCutOff(GsDiscPnt *pDiscPnts, long lpntNum);
	
	//================================================================================
    // �� �� ����_cSetExtrData
    // �����������ú����������ý�����ֵ������������Եļ�ֵ
	// ���������fExtrMax ��        �� ���ݼ���ֵ
	//           fExtrMin           �� ���ݼ�Сֵ
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cSetExtrData(double fExtrMax, double fExtrMin);

	//================================================================================
    // �� �� ����_cCptIkCutOff
    // �����������ú�������ָʾ�������������ָʾ��������ֵ��ֵ
	// ���������fCutOff            �� ��ֵ��ֵ
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cCptIkCutOff(double &fCutOff);
	
	//================================================================================
    // �� �� ����_cCptCutOff
    // �����������ú����������ü�����ֵ�����еõ�����ֵ����
	// ���������iCutOffNum         �� ��ֵ����
	//           ikCfMethod         �� ��ֵ������
	// ���������fIkfThres          �� �õ�����ֵ����
	//           fIkfCdf            �� ����ֵ��Ӧ���ۻ�����
    // ����ֵ  ����
    // �������ڣ�2007-05-16
    // �޸����ڣ�2007-05-16
    // ����˵����
    //================================================================================
	void _cCptCutOff(int iCutOffNum, int ikCfMethod, double fIkfThres[], double fIkfCdf[]);

private:
	//ԭʼ������Ϣ
	GsDiscPnt    *m_pDiscPnts;
	long          m_lpntNum;
    
	//���ݼ�ֵ
	double        m_fExtrMax;
	double        m_fExtrMin;
};
#ifndef _GEO_STAT_KRIG_LIB
	#ifdef _DEBUG
		#pragma comment(lib, "GeoStatKrigLibD.lib")
	#else
		#pragma comment(lib, "GeoStatKrigLib.lib")
	#endif
#endif
#endif // !defined(AFX_GEOSTATCUTOFF_H__D5C63F0D_54F6_41FA_8A0F_FA4E810AD255__INCLUDED_)
