// Desc:    ���B������ɢ�����ݲ�ֵ
#pragma  once

#include "s3d_KerInterpMBSplineDef.h"
#include "gmestru.h"

#include <vector>
using namespace std;

using namespace Smart3dMap;

class	CBSplineInterpolateObj;

class LIB_S3DKERINTERPMBSPLINE_EXP CMutilBSplineObj
{
	public:
		CMutilBSplineObj();
		~CMutilBSplineObj();

		//////////////////////////////////////////////////////////////////////////
		//			MBA algorithm: �����в���Ƶ㺯��ֵ
		//			���:*ScatteredPnt(ɢ������),PntNum(���ݵ����),
		//				 lLayNum(����),M1(x�����������),N1(y�����������),
		//				 *rect(�������������)
		//				 bIsCalInValidCtrlPnt(�Ƿ������Ч�Ŀ��Ƶ�)
		//			����:
		//			����ֵ:�ɹ�/ʧ��  1/0
		//		
		//////////////////////////////////////////////////////////////////////////
		long    setdata(gme_vector3d * ScatteredPnt,long PntNum,
						long lLayNum=4,long M=8,long N=8,
						gme_rect_2d *pRect=NULL,
						bool bIsCalInValidCtrlPnt=0,long lCalM=0,long lCalN=0);

		
		/////////////////////////////////////MBA��ֵ///////////////////////////////////////
		//							��ֵ����
		//			���:*rect(�������������)
		//				 &Ix(��ֵ��x����),&Iy(��ֵ��y����)
		//			����:&Iz(���B������ֵ���,z����)
		//			����ֵ:0 //ʧ��
		//				   1 //����ֵ����Χ����Ч�����,����ֵΪ��Чֵ
		//				   2 //����ֵ����Χ������Ч�����,����Ч����Ϊ׼,����ֵ��Ч	
		//				   3 //���۴���ֵ����Χ�Ƿ������Ч�����,����ֵ��Ч(��bIsCalInValidCtrlPntΪ1)	
		//		
		////////////////////////////////////////////////////////////////////////////////////
		//ע��:���rect == NULL,��(Ix,Iy)����λ����������(ScatteredPnt)�İ�Χ�з�Χ��
		//	   ���rect != NULL,��(Ix,Iy)����λ��rect��Χ��
		long interpolate_a_pnt(double x,double y,double &z);

	private:
		long NewSampleDots(gme_vector3d * ScatteredPnt,long PntNum,
							bool bIsCalInValidCtrlPnt=0,long lCalM=0,long lCalN=0);
	private:
		vector<CBSplineInterpolateObj*> m_SingleBSplieObjVec; 
		long m_bIsCalInValidCtrlPnt;
		long m_lLayNum;
		long m_lM;
		long m_lN;
		gme_rect_2d	m_dataRect;
		gme_vector3d *m_pSampleDots;
		long m_lSampDotNum;
	};
