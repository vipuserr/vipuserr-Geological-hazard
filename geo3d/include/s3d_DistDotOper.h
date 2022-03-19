#pragma once

#include <vector>
#include <set>
using namespace std;

#include "gmeEntity.h"
#include "s3d_KerDemOperDef.h"



namespace Smart3dMap
{

	//����ɢ���������󽻼��㽻��zֵ
	class LIB_S3DKERDEMOPER_EXP  GetZValFromSurf : public CalDemZValBas
	{
	public:
		GetZValFromSurf(gmeSurface& demSurf);
		GetZValFromSurf(vector<gme_vector3d>& disDots, vector<gme_vector3d>* rgn = nullptr);
		virtual ~GetZValFromSurf(void);

	public:
		//����DEM�������zֵ
		virtual int CalZVal(gme_vector3d * pDot);
		virtual int CalZValXYZ(double dx, double dy, double *pdz);

	private:
		void get_elevation_value_by_discreatedots(gme_vector3d& v_point);
		bool get_elevation_value(gme_vector3d& v_point, int* intersect_index=nullptr);
		void initialize_information();
		void calculate_step_length(gme_vector3d* v_points, int* triangle_index, int triangle_count);
		//�������񻮷�������������������
		void build_index(gme_rect_2d* boundary_box, int triangle_count);
		int calculate_z_value(gme_vector3d& vec_point, const gme_vector3d& v1, const gme_vector3d& v2, const gme_vector3d& v3);

	private:
		vector<int>**       m_xy_index;         // ���ֵ�ÿ������������������������
		vector<gme_rect_2d> m_triangle_rect;    // �����εľ��α߽�
		double              m_x_step_length;    // x�����ϵĲ���
		double              m_y_step_length;    // y�����ϵĲ���
		int                 m_x_tile_num;       // x���򻮷ֵĿ���
		int                 m_y_tile_num;       // y���򻮷ֵĿ���
		vector<gme_vector3d> m_discreteDots;	//��ɢ��
	};

}