#pragma once

#include <string>
#include <vector>
#include <map>
#include <list>
#include <float.h>
using namespace std;

#include "s3d_KerIsolinDef.h"
#include "gmeMdl.h"

namespace Smart3dMap
{

	//==========================gm_create_isoline_by_surface==========================
	/// @brief �ز���׷�ٵ�ֵ��
	///
	//================================================================================
	class LIB_S3DKERISOLIN_EXP  gm_create_isoline
	{
	public:
		gm_create_isoline();
		virtual ~gm_create_isoline();

	public:

		//=====================================init()=====================================
		/// @brief ��ʼ����ά�����
		///
		/// @param [in] psurf ��ά�����
		///
		/// @return 
		//================================================================================
		void init(gmeSurface *psurf);

		//==================================getisolines()=================================
		/// @brief ���ɵ�ֵ��
		///
		/// @param [in]  dzvalue     ��ά��ĸ߳�ֵ
		/// @param [out] outveclines ����ĵ�ֵ������
		/// @param [in]  tole        �����ݲ�
		///
		/// @return �ɹ�1/ʧ��0
		//================================================================================
		int  get_isolines(double dzvalue, vector<vector<gme_vector3d>> &outveclines, double tole = 1e-6);

	public:

		//================================get_insect_dot()================================
		/// @brief ����ָ��Zƽ�������ǱߵĽ���
		///
		/// @param [in]      dot1     �˵�1
		/// @param [in]      dot2     �˵�2
		/// @param [in]      dzvalue  ָ��Zƽ��
		/// @param [out]     outdot   ������:����
		///
		/// @return �н��㷵��1/û�н��㷵��0
		//================================================================================
		int  get_insect_dot(gme_vector3d *pdot1, gme_vector3d *pdot2, double dzvalue, gme_vector3d *outdot);
	private:

		double                  m_tole; //�ݲ� 
		gmeSurface            * m_surf; //��ά�����
	};


}