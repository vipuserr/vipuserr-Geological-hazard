#pragma once

#pragma warning(disable:4251)
#pragma warning(disable:4244) 

#include "s3d_KerInterpSFIDef.h"

#include<vector>
#include <Eigen/Dense> 

using Eigen::MatrixXd;
using std::vector;

struct sfinode//����
{
	double value;
	int index;

	bool operator<(const sfinode& s)
	{
		return value < s.value;
	}
};

typedef struct StrusfiGeoOrientation//ʵ���״��
{
	double x, y, z;
	double dip, azimuth;//��ǡ�����
	int overturn;//�ز��Ƿ�ת

	StrusfiGeoOrientation()
	{
		memset(this, 0, sizeof(StrusfiGeoOrientation));
		overturn = -1;//(-1,0,1)(unknown,upright,overturned younging direction)
	}
}sfiGeoOrientation;

typedef struct StruGeoOri_interp//����ֵ��
{
	double x, y, z;
	double dx;
	double dy;
	double dz;

	StruGeoOri_interp()
	{
		memset(this, 0, sizeof(StruGeoOri_interp));
	}
}GeoOri_interp;

typedef struct StruGeoAttribute//��״�����Բ���
{

	Eigen::Vector3d dip_vector;//�������
	Eigen::Vector3d younging_vector;//��������
	Eigen::Vector3d plunge_vector;//�������
	Eigen::Matrix3d eigenvector_matrix;//������������
	vector<double> eigenvalue;//����ֵ
	Eigen::Matrix3d scaling_matrix;//���ž���
	double K;//Wockcock parameter
	bool Flag;//flag for data points not having younging direction.if Flag=1 data point is associated with a girdle distribution,oherwise it is not
	StruGeoAttribute()
	{
		dip_vector.setZero();
		younging_vector.setZero();
		plunge_vector.setZero();
		eigenvector_matrix.setZero();
		eigenvalue.clear();
		scaling_matrix.setZero();
		K = 0;
		Flag = 0;
	}
}GeoAttribute;

typedef struct StrusfiGeoNormal//ʵ���״��׼��ʽ
{
	double x;
	double y;
	double z;
	double dx;
	double dy;
	double dz;
	int overturn;//�ز��Ƿ�ת
	StrusfiGeoNormal()
	{
		memset(this, 0, sizeof(StrusfiGeoNormal));
		overturn = -1;//(-1,0,1)(unknown,upright,overturned younging direction)
	}
}sfiGeoNormal;

typedef struct StruBoundingBox//��ֵ��Χ��
{
	double XMAX, YMAX, ZMAX, XMIN, YMIN, ZMIN;//��Χ
	int nx, ny, nz;//xyz��������
	StruBoundingBox()
	{
		memset(this, 0, sizeof(StruBoundingBox));
	}
}Bounding_Box;

class LIB_S3DKERINTERPSFI_EXP Stuctural_field_interpplation
{
public:
	Stuctural_field_interpplation();
	~Stuctural_field_interpplation();
	vector<sfiGeoOrientation> MSD;//ԭʼ��״
	vector<sfiGeoNormal> M_SD;//ʸ������״
					   
	//��������
	void create_grid_cell(Bounding_Box& box);

	//��״��ʸ����
	//��sfiGeoOrientation��dip��azimuth��������ת��ΪsfiGeoNormal��dxdydz����
	void vectorization(vector<sfiGeoOrientation>& attitude, vector<sfiGeoNormal>& m_sfiGeoOrientation);

    //����ȫ�����������ȫ�ֲο�����
	void compute_G_GP();

	//��ֵǰ׼��
	//ori:ԭʼ��״����
	//att:��״������
	//�������״�����
	void setup_for_interpolation(vector<sfiGeoOrientation>& Ori,vector<GeoAttribute>& att, int interp_IDW_select_num = 7);

	//���Է���
	void polarity_assignment(vector<sfiGeoOrientation>& Ori, vector<GeoAttribute>& att);

	//��ת�������
	void rotate_dip_vector(vector<GeoAttribute>& att, vector<Eigen::Vector3d>& rotated_dip_vector);

	Eigen::Vector3d global_plunge_reference_vector;//ȫ���������
	Eigen::Vector3d global_reference_vector;//ȫ�ֲο�����

	//������������֮��ļн�
	double angle_between_two_vectors(Eigen::Vector3d a, Eigen::Vector3d b);

	//�������Ȩ��ֵ
	//ori����״��
	//att����״����
	//x������ֵ��
	//interp_IDW_select_num����������
	void rotate_dip_vector_IDW_interpolate(vector<sfiGeoOrientation>& Ori, vector<GeoAttribute>& att, GeoOri_interp& x, int interp_IDW_select_num = 7);
	
	//��ֵ�������
	Eigen::MatrixXd interpdata;

	//���ղ�ֵ����ȫ�ռ��ֵ
	//
	void IDW_Interpolate(vector<sfiGeoOrientation>& Ori, Bounding_Box & box, int interp_IDW_select_num = 7);
    
	//������ʽ�߲�ֵ
	void Structural_formal_line_IDW_Interpolate(vector<sfiGeoOrientation>& Ori, Bounding_Box & box, int interp_IDW_select_num = 7);
private:

};

