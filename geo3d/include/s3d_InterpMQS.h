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
	//MQS插值
	short   setdata(double *tmpXPtr,double *tmpYPtr,double *tmpZPtr,long allDatNum,double dR=100);
	short   interpolate_a_pnt(long *pPntNo,long lPnt,double dX,double dY,double *dpResult);

	void	ReleaseMQSData();
private:
	//基于离散点插值的样本数据
	double *m_dpMqsX,*m_dpMqsY,*m_dpMqsZ;	//样本点数组
	long	m_lSwatchDotNum;				//样本点数目
	//MQS所需变量
	double	m_dR;						//影响半径
	double	*m_dMQSCoeArr;				//和MQS插值相关的所有样本点的系数数组


};

