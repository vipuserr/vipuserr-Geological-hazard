#pragma once


#pragma warning(disable:4244) 
#pragma warning(disable:4251) 

#include "s3d_KerInterpSFIDef.h"


#include<vector>
#include<fstream>
#include<string>

//#define EIGEN_USE_MKL_ALL//eigen使用MKL加速

#include <Eigen/Dense> 
#include<mutex>

using Eigen::MatrixXd;
using std::vector;

constexpr auto interp_IDW_anisot_rho = 3;//各向异性强度
constexpr auto Coincidence_distance = 0.00001;//重合点距离改为0.00001
constexpr auto arccosine_is_one = 0.99999999999999;//将反余弦值改为0.9999999999


struct node//排序
{
	double value;
	int index;

	bool operator<(const node& s)
	{
		return value < s.value;
	}
};

typedef struct StruGeoOrientation//实测产状点
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

typedef struct StruGeoTangent//实测切线点
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

typedef struct StruGeoNormal//实测产状标准格式
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

struct Cross_validation//交叉验证data
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

	vector<GeoNormal> MSD;//原始实测产状
	vector<GeoTangent> MSEO;//原始切线

	Eigen::MatrixXd M_SD;//原始实测产状
	Eigen::MatrixXd M_SEO;//原始切线数据 

	int interp_IDW_select_num;//搜索个数;

	//IDW各向异性加权插值算法
	//SD产状数据、SEO切线数据、InterpolateSEOSD切线处初始插值结果数据,type插值、投影（0，1）
	bool InterpV_IDW_3D_anisot(vector<GeoNormal> &SD, vector<GeoTangent>& SEO, bool type, Eigen::MatrixXd& Interp_matrix);
	bool InterpV_IDW_3D_anisot(Eigen::MatrixXd &V, Eigen::MatrixXd& XYZ_interp, bool type, Eigen::MatrixXd& Interp_matrix);//速度稍慢

	//产状点矢量化
	//将GeoOrientation中dip及azimuth数据类型转化为GeoNormal中dxdydz类型
	void vectorization(vector<GeoOrientation>&attitude, vector<GeoNormal>& m_GeoOrientation);

	//拟梯度下降优化
	//QGD_iterat_num：迭代次数
	long Optim_QuasiGradientDescent(Eigen::MatrixXd& FinSEOSD, int QGD_iterat_num);

	//目标函数
	void ObjectFunction(Eigen::MatrixXd &SD, Eigen::MatrixXd &SEO_vect, Cross_validation& m_Cross_validation);

	//装载数据
	//SD：实测产状数据
	//SEO：原始切线数据
	//将输入数据传到成员变量M_SD、M_SEO、MSD、MSEO中
	void setdata(vector<GeoNormal>& SD, vector<GeoTangent>& SEO);

	//最终插值大函数
	//SD：实测产状点
	//SEO：实测切线点
	//QGD_iterat_num：拟梯度下降迭代次数
	//interp_IDW_select_num：插值搜索个数
	bool SEOSD_interpolation(vector<GeoNormal>& SD, vector<GeoTangent>& SEO, Eigen::MatrixXd& Finmatrix, int QGD_iterat_num = 40, int interp_IDW_select_num = 7);

private:


	Eigen::MatrixXd one;//元素为1的矩阵
	Eigen::MatrixXd InterpolateSEOSD;//初始插值切线处产状(xyzdxdydz)
	Eigen::MatrixXd InitialSEOSD;//投影后初始插值切线处产状（xyzdxdydzweight）

	Cross_validation m_Cross_validation;//交叉验证参数

	//旋转
	Eigen::MatrixXd sub_rotate_theta(Eigen::MatrixXd& SEO, Eigen::MatrixXd& BeginSEOSD, Eigen::MatrixXd& SEOSD);
	Eigen::MatrixXd sub_rotate_intitial2new(Eigen::MatrixXd &SEO, Eigen::MatrixXd &BeginSEOSD, Eigen::MatrixXd &SEOSD);
	Eigen::MatrixXd sub_RotateMatrix(Eigen::MatrixXd e, Eigen::MatrixXd tha);

	//维度相同矩阵的相同位置元素比较，返回同维bool矩阵
	//参数说明：输入矩阵，比较矩阵，比较元素，比较类型==，！=，>，<(0,1,2,3)
	Eigen::MatrixXd matrix_comparsion(Eigen::MatrixXd x, Eigen::MatrixXd y, int CmprType = 0);
	Eigen::MatrixXd matrix_comparsion(Eigen::MatrixXd x, double y, int CmprType = 0);

	//返回输入矩阵元素不为m的元素索引
	//参数说明：比较矩阵，比较元素
	//只针对列向量（col，1）
	Eigen::MatrixXd matrix_find(Eigen::MatrixXd x, double y = 0);

	//根据序列号填充矩阵元素
	//参数说明：原始矩阵，索引号列表,输出填充矩阵
	Eigen::MatrixXd Populate_matrix_ele(Eigen::MatrixXd org, Eigen::MatrixXd indexs, Eigen::MatrixXd& outmatrix);

	//对向量进行排序，从大到小
	//  vec: 待排序的向量
	//	sorted_vec: 排序的结果
	//	ind: 排序结果中各个元素在原始向量的位置
	void sort_vec(const Eigen::VectorXd& vec, Eigen::VectorXd& sorted_vec, Eigen::VectorXi& ind);

	//小数保留
	double round(double number, unsigned int bits);

	//线程1
	void th_loocv(Eigen::MatrixXd SD, int star_num, int total_num);
	Eigen::MatrixXd tr_LOOCV_Vector;

	//锁
	std::mutex mut;
};