#pragma once

#include <vector>
#include <set>
using namespace std;

#include "gmeEntity.h"
#include "s3d_KerDemOperDef.h"



namespace Smart3dMap
{

	//算离散点与曲面求交计算交点z值
	class LIB_S3DKERDEMOPER_EXP  GetZValFromSurf : public CalDemZValBas
	{
	public:
		GetZValFromSurf(gmeSurface& demSurf);
		GetZValFromSurf(vector<gme_vector3d>& disDots, vector<gme_vector3d>* rgn = nullptr);
		virtual ~GetZValFromSurf(void);

	public:
		//根据DEM曲面计算z值
		virtual int CalZVal(gme_vector3d * pDot);
		virtual int CalZValXYZ(double dx, double dy, double *pdz);

	private:
		void get_elevation_value_by_discreatedots(gme_vector3d& v_point);
		bool get_elevation_value(gme_vector3d& v_point, int* intersect_index=nullptr);
		void initialize_information();
		void calculate_step_length(gme_vector3d* v_points, int* triangle_index, int triangle_count);
		//计算网格划分索引所包含的三角形
		void build_index(gme_rect_2d* boundary_box, int triangle_count);
		int calculate_z_value(gme_vector3d& vec_point, const gme_vector3d& v1, const gme_vector3d& v2, const gme_vector3d& v3);

	private:
		vector<int>**       m_xy_index;         // 划分的每个网格所包含的三角形索引
		vector<gme_rect_2d> m_triangle_rect;    // 三角形的矩形边界
		double              m_x_step_length;    // x方向上的步长
		double              m_y_step_length;    // y方向上的步长
		int                 m_x_tile_num;       // x方向划分的块数
		int                 m_y_tile_num;       // y方向划分的块数
		vector<gme_vector3d> m_discreteDots;	//离散点
	};

}