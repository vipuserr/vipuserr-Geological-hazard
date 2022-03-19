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
	/// @brief 地层面追踪等值线
	///
	//================================================================================
	class LIB_S3DKERISOLIN_EXP  gm_create_isoline
	{
	public:
		gm_create_isoline();
		virtual ~gm_create_isoline();

	public:

		//=====================================init()=====================================
		/// @brief 初始化三维面对象
		///
		/// @param [in] psurf 三维面对象
		///
		/// @return 
		//================================================================================
		void init(gmeSurface *psurf);

		//==================================getisolines()=================================
		/// @brief 生成等值线
		///
		/// @param [in]  dzvalue     三维面的高程值
		/// @param [out] outveclines 输出的等值线数据
		/// @param [in]  tole        计算容差
		///
		/// @return 成功1/失败0
		//================================================================================
		int  get_isolines(double dzvalue, vector<vector<gme_vector3d>> &outveclines, double tole = 1e-6);

	public:

		//================================get_insect_dot()================================
		/// @brief 计算指定Z平面与三角边的交点
		///
		/// @param [in]      dot1     端点1
		/// @param [in]      dot2     端点2
		/// @param [in]      dzvalue  指定Z平面
		/// @param [out]     outdot   计算结果:交点
		///
		/// @return 有交点返回1/没有交点返回0
		//================================================================================
		int  get_insect_dot(gme_vector3d *pdot1, gme_vector3d *pdot2, double dzvalue, gme_vector3d *outdot);
	private:

		double                  m_tole; //容差 
		gmeSurface            * m_surf; //三维面对象
	};


}