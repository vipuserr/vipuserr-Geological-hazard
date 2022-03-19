#pragma once
#include <vector>
using namespace std;

#include "s3d_KerInterpMQSDef.h"

using namespace Smart3dMap;

class LIB_S3DKERINTERPMQS_EXP CInterp_MQS
{
public:
	CInterp_MQS();
	~CInterp_MQS();
	//MQS��ֵ
	short   setdata(double *tmpXPtr,double *tmpYPtr,double *tmpZPtr,long allDatNum,double dR=100);
	short   interpolate_a_pnt(long *pPntNo,long lPnt,double dX,double dY,double *dpResult);

	void	ReleaseMQSData();
private:
	//������ɢ���ֵ����������
	double *m_dpMqsX,*m_dpMqsY,*m_dpMqsZ;	//����������
	long	m_lSwatchDotNum;				//��������Ŀ
	//MQS�������
	double	m_dR;						//Ӱ��뾶
	double	*m_dMQSCoeArr;				//��MQS��ֵ��ص������������ϵ������


};

