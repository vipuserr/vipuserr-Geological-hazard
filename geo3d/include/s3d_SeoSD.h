#pragma once


#pragma warning(disable:4244) 
#pragma warning(disable:4251) 

#include "s3d_KerInterpSFIDef.h"


#include<vector>
#include<fstream>
#include<string>

//#define EIGEN_USE_MKL_ALL//eigenʹ��MKL����

#include <Eigen/Dense> 
#include<mutex>

using Eigen::MatrixXd;
using std::vector;

constexpr auto interp_IDW_anisot_rho = 3;//��������ǿ��
constexpr auto Coincidence_distance = 0.00001;//�غϵ�����Ϊ0.00001
constexpr auto arccosine_is_one = 0.99999999999999;//��������ֵ��Ϊ0.9999999999


struct node//����
{
	double value;
	int index;

	bool operator<(const node& s)
	{
		return value < s.value;
	}
};

typedef struct StruGeoOrientation//ʵ���״��
{
	double x, y, z;
	double dip, azimuth;
	double dWight;

	StruGeoOrientation()
	{
		memset(this, 0, sizeof(StruGeoOrientation));
		dWight = 1;
	}
}GeoOrientation;

typedef struct StruGeoTangent//ʵ�����ߵ�
{
	double x, y, z;
	double dx, dy, dz;
	double dWight;

	StruGeoTangent()
	{
		memset(this, 0, sizeof(StruGeoTangent));
		dWight = 1;
	}
}GeoTangent;

typedef struct StruGeoNormal//ʵ���״��׼��ʽ
{
	double x;
	double y;
	double z;
	double dx;
	double dy;
	double dz;
	double weight;
	StruGeoNormal()
	{
		x = 0;
		y = 0;
		z = 0;
		dx = 0;
		dy = 0;
		dz = 0;
		weight = 1;
	}
}GeoNormal;

struct Cross_validation//������֤data
{
	Eigen::MatrixXd cv_sum;
	Eigen::MatrixXd CV;
	Eigen::MatrixXd cv_vect;
	Eigen::MatrixXd LOOCV_Vector;
	Eigen::MatrixXd cv_sum_angle;
	Eigen::MatrixXd cv_sum_angle_V;
	Eigen::MatrixXd cv_sum_angle_T;
	Cross_validation()
	{
		cv_sum.setZero(1, 1);
	}
};



class LIB_S3DKERINTERPSFI_EXP SEOSD
{
public:
	SEOSD(int interp_num = 7);
	~SEOSD();

	vector<GeoNormal> MSD;//ԭʼʵ���״
	vector<GeoTangent> MSEO;//ԭʼ����

	Eigen::MatrixXd M_SD;//ԭʼʵ���״
	Eigen::MatrixXd M_SEO;//ԭʼ�������� 

	int interp_IDW_select_num;//��������;

	//IDW�������Լ�Ȩ��ֵ�㷨
	//SD��״���ݡ�SEO�������ݡ�InterpolateSEOSD���ߴ���ʼ��ֵ�������,type��ֵ��ͶӰ��0��1��
	bool InterpV_IDW_3D_anisot(vector<GeoNormal> &SD, vector<GeoTangent>& SEO, bool type, Eigen::MatrixXd& Interp_matrix);
	bool InterpV_IDW_3D_anisot(Eigen::MatrixXd &V, Eigen::MatrixXd& XYZ_interp, bool type, Eigen::MatrixXd& Interp_matrix);//�ٶ�����

	//��״��ʸ����
	//��GeoOrientation��dip��azimuth��������ת��ΪGeoNormal��dxdydz����
	void vectorization(vector<GeoOrientation>&attitude, vector<GeoNormal>& m_GeoOrientation);

	//���ݶ��½��Ż�
	//QGD_iterat_num����������
	long Optim_QuasiGradientDescent(Eigen::MatrixXd& FinSEOSD, int QGD_iterat_num);

	//Ŀ�꺯��
	void ObjectFunction(Eigen::MatrixXd &SD, Eigen::MatrixXd &SEO_vect, Cross_validation& m_Cross_validation);

	//װ������
	//SD��ʵ���״����
	//SEO��ԭʼ��������
	//���������ݴ�����Ա����M_SD��M_SEO��MSD��MSEO��
	void setdata(vector<GeoNormal>& SD, vector<GeoTangent>& SEO);

	//���ղ�ֵ����
	//SD��ʵ���״��
	//SEO��ʵ�����ߵ�
	//QGD_iterat_num�����ݶ��½���������
	//interp_IDW_select_num����ֵ��������
	bool SEOSD_interpolation(vector<GeoNormal>& SD, vector<GeoTangent>& SEO, Eigen::MatrixXd& Finmatrix, int QGD_iterat_num = 40, int interp_IDW_select_num = 7);

private:


	Eigen::MatrixXd one;//Ԫ��Ϊ1�ľ���
	Eigen::MatrixXd InterpolateSEOSD;//��ʼ��ֵ���ߴ���״(xyzdxdydz)
	Eigen::MatrixXd InitialSEOSD;//ͶӰ���ʼ��ֵ���ߴ���״��xyzdxdydzweight��

	Cross_validation m_Cross_validation;//������֤����

	//��ת
	Eigen::MatrixXd sub_rotate_theta(Eigen::MatrixXd& SEO, Eigen::MatrixXd& BeginSEOSD, Eigen::MatrixXd& SEOSD);
	Eigen::MatrixXd sub_rotate_intitial2new(Eigen::MatrixXd &SEO, Eigen::MatrixXd &BeginSEOSD, Eigen::MatrixXd &SEOSD);
	Eigen::MatrixXd sub_RotateMatrix(Eigen::MatrixXd e, Eigen::MatrixXd tha);

	//ά����ͬ�������ͬλ��Ԫ�رȽϣ�����ͬάbool����
	//����˵����������󣬱ȽϾ��󣬱Ƚ�Ԫ�أ��Ƚ�����==����=��>��<(0,1,2,3)
	Eigen::MatrixXd matrix_comparsion(Eigen::MatrixXd x, Eigen::MatrixXd y, int CmprType = 0);
	Eigen::MatrixXd matrix_comparsion(Eigen::MatrixXd x, double y, int CmprType = 0);

	//�����������Ԫ�ز�Ϊm��Ԫ������
	//����˵�����ȽϾ��󣬱Ƚ�Ԫ��
	//ֻ�����������col��1��
	Eigen::MatrixXd matrix_find(Eigen::MatrixXd x, double y = 0);

	//�������к�������Ԫ��
	//����˵����ԭʼ�����������б�,���������
	Eigen::MatrixXd Populate_matrix_ele(Eigen::MatrixXd org, Eigen::MatrixXd indexs, Eigen::MatrixXd& outmatrix);

	//�������������򣬴Ӵ�С
	//  vec: �����������
	//	sorted_vec: ����Ľ��
	//	ind: �������и���Ԫ����ԭʼ������λ��
	void sort_vec(const Eigen::VectorXd& vec, Eigen::VectorXd& sorted_vec, Eigen::VectorXi& ind);

	//С������
	double round(double number, unsigned int bits);

	//�߳�1
	void th_loocv(Eigen::MatrixXd SD, int star_num, int total_num);
	Eigen::MatrixXd tr_LOOCV_Vector;

	//��
	std::mutex mut;
};