// -----------------------------------------------------------------
//
// Copyright:	ZondySoft 2004
//
// File:		GsProgrApi.h
//
// Project:		GeoStatProgr
//
// Creator:		����Ӣ
//
// Time:		09:22 2008-2-20
//
// Description:	Geological Statistical Library
//
// -----------------------------------------------------------------

#ifndef _GEOSTAT_PROGR_API_H
#define _GEOSTAT_PROGR_API_H


#ifndef _CGEOSTAT_PROGR_LIB
  #define GEOSTAT_PROGR_DLL  __declspec(dllimport)
#else
  #define GEOSTAT_PROGR_DLL  __declspec(dllexport)
#endif


#ifdef __cplusplus
extern "C" {
#endif

//��ʼ���̿���
//���ܣ�
//    ����������
//����:
//    WindowTitleName --------------->���ڱ���
//    TitleName --------------------->�ӱ���
long GEOSTAT_PROGR_DLL gsStartProgress(LPCTSTR WindowTitleName,LPCTSTR TitleName);
//�������̿���
//���ܣ�
//    ɾ��������
//������
//     hProgID ---------------------->��������ʶID
BOOL GEOSTAT_PROGR_DLL gsEndProgress(long hProgID);
//���ý��̿�������ָʾ��Χ.
//������
//     hProgID ---------------------->��������ʶID
//     nLower ----------------------->ָʾ���ֵ
//     nUpper ----------------------->ָʾ���ֵ
void GEOSTAT_PROGR_DLL gsSetRange(long hProgID,int nLower,int nUpper);
//���ý��̿���������ָʾλ��.
//������
//     hProgID ---------------------->��������ʶID
//     nPos ------------------------->��������λ��
//���أ���������ǰָʾλ��    
int  GEOSTAT_PROGR_DLL gsSetPos(long hProgID,int nPos);
//���ý��̿��������²���.
//����
//     hProgID ---------------------->��������ʶID
//     nStep ------------------------>�������²���
//���أ���������ǰ����
int  GEOSTAT_PROGR_DLL gsSetStep(long hProgID,int nStep);
//���������ӽ��̿�������ָʾ��.
//����
//     hProgID ---------------------->��������ʶID
//���أ���������ǰλ��
int  GEOSTAT_PROGR_DLL gsStepIt(long hProgID);
//���ý��̿���������ָʾλ�õ�ƫ����,���ؽ��̿�����ָʾ�ĵ�ǰλ��.
//������
//     hProgID ---------------------->��������ʶID
//     nPos ------------------------->������λ��ƫ����
//���أ���������ǰλ��
int  GEOSTAT_PROGR_DLL gsOffsetPos(long hProgID,int nPos);
//�Ƿ�ѡ��CANCEL.
BOOL IsUserBreak(HWND hWnd);
//�Ƿ���ֹ���̿���.
//������
//     hProgID ---------------------->��������ʶID
//���أ���ֹ���̱�ʶ
BOOL GEOSTAT_PROGR_DLL gsIsStopProgress(long hProgID);
#ifdef __cplusplus
}
#endif

#ifndef _CGEOSTAT_PROGR_LIB
	#pragma comment(lib, "S3dAppProgr.lib")
#endif


#endif //_GEOSTAT_LIB_H	  