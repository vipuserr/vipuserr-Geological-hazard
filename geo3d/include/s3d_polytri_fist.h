#pragma once

#pragma warning(disable:4005)

#include "s3d_KerTrigRgnDef.h"
#include "gme_vector2.h"
#include "gmeStru.h"

namespace Smart3dMap
{

	class LIB_S3DKERINTERPIDW_EXP gm_polytriangulation
	{
	public:
		gm_polytriangulation();
		~gm_polytriangulation();

		// ------------------------ �Զ���ν��������ʷִ����� ------------------------ //
		//������gme_vector2d *pnts, long *pPolyPntNum, long nPolyNum, gme_vector2d **ppFinalPnt,long *plFinalPntNum, gme_triangle **ppFinalTri, long *pFinalTriNum
		//      (��  ��) *pnts        ���������߽��������ݿռ��ַ,����������.
		//      (��  ��) *pPolyPntNum ���������߽���Ȧ��������.
		//      (��  ��) nPolyNum     ���������Ȧ��.
		//
		//      (��  ��)**ppFinalPnt,pPolyPntNum �����Ķ��������߽��������ݿռ��ַ,����������
		//      (��  ��) **ppFinalTri  �����εĶ������(��*xy �е����).
		//      (��  ��) *pFinalTriNum �����εĸ���.
		//����ֵ:-1��0��1��2��3   -1��ʾ�޶���Σ�0��ʾ�����ڴ�ʧ�ܣ�1��ʾ�����ʷֳɹ���
		//						  2��ʾ��������3����ĵ�������,�������ʷֳɹ���
		//						  3��ʾ�����ʷ����������Multi-Phase Recovery Process.
		int  gm_polytri_TrianglateRgn(  gme_vector2d *pnts, long *pPolyPntNum, long nPolyNum,
										gme_vector2d **ppFinalPnt, long *plFinalPntNum,
										gme_triangle **ppFinalTri, long *pFinalTriNum);
	private:
		gme_vector2d *m_pFinalPnt;
		long			m_pFinalPntNum;

		gme_triangle *p_FinalTri;
		long		  m_pFinalTriNum;
	};
}