#pragma once

#pragma warning(disable:4251)
#pragma warning(disable:4244) 

#include "s3d_KerInterpSFIDef.h"

#include<vector>
#include <Eigen/Dense> 

using Eigen::MatrixXd;
using std::vector;

struct sfinode//排序
{
	double value;
	int index;

	bool operator<(const sfinode& s)
	{
		return value < s.value;
	}
};

typedef struct StrusfiGeoOrientation//实测产状点
{
	double x, y, z;
	double dip, azimuth;//倾角、倾向
	int overturn;//地层是否倒转

	StrusfiGeoOrientation()
	{
		memset(this, 0, sizeof(StrusfiGeoOrientation));
		overturn = -1;//(-1,0,1)(unknown,upright,overturned younging direction)
	}
}sfiGeoOrientation;

typedef struct StruGeoOri_interp//待插值点
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

typedef struct StruGeoAttribute//产状点属性参数
{

	Eigen::Vector3d dip_vector;//倾角向量
	Eigen::Vector3d younging_vector;//法向向量
	Eigen::Vector3d plunge_vector;//倾伏向量
	Eigen::Matrix3d eigenvector_matrix;//特征向量矩阵
	vector<double> eigenvalue;//特征值
	Eigen::Matrix3d scaling_matrix;//缩放矩阵
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

typedef struct StrusfiGeoNormal//实测产状标准格式
{
	double x;
	double y;
	double z;
	double dx;
	double dy;
	double dz;
	int overturn;//地层是否翻转
	StrusfiGeoNormal()
	{
		memset(this, 0, sizeof(StrusfiGeoNormal));
		overturn = -1;//(-1,0,1)(unknown,upright,overturned younging direction)
	}
}sfiGeoNormal;

typedef struct StruBoundingBox//插值包围盒
{
	double XMAX, YMAX, ZMAX, XMIN, YMIN, ZMIN;//范围
	int nx, ny, nz;//xyz方向数量
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
	vector<sfiGeoOrientation> MSD;//原始产状
	vector<sfiGeoNormal> M_SD;//矢量化产状
					   
	//创建网格
	void create_grid_cell(Bounding_Box& box);

	//产状点矢量化
	//将sfiGeoOrientation中dip及azimuth数据类型转化为sfiGeoNormal中dxdydz类型
	void vectorization(vector<sfiGeoOrientation>& attitude, vector<sfiGeoNormal>& m_sfiGeoOrientation);

    //计算全局倾伏向量和全局参考向量
	void compute_G_GP();

	//插值前准备
	//ori:原始产状数据
	//att:产状点属性
	//搜索域产状点个数
	void setup_for_interpolation(vector<sfiGeoOrientation>& Ori,vector<GeoAttribute>& att, int interp_IDW_select_num = 7);

	//极性分配
	void polarity_assignment(vector<sfiGeoOrientation>& Ori, vector<GeoAttribute>& att);

	//旋转倾角向量
	void rotate_dip_vector(vector<GeoAttribute>& att, vector<Eigen::Vector3d>& rotated_dip_vector);

	Eigen::Vector3d global_plunge_reference_vector;//全局倾伏向量
	Eigen::Vector3d global_reference_vector;//全局参考向量

	//计算两个向量之间的夹角
	double angle_between_two_vectors(Eigen::Vector3d a, Eigen::Vector3d b);

	//反距离加权插值
	//ori：产状点
	//att：产状属性
	//x：待插值点
	//interp_IDW_select_num：搜索个数
	void rotate_dip_vector_IDW_interpolate(vector<sfiGeoOrientation>& Ori, vector<GeoAttribute>& att, GeoOri_interp& x, int interp_IDW_select_num = 7);
	
	//插值结果矩阵
	Eigen::MatrixXd interpdata;

	//最终插值大函数全空间插值
	//
	void IDW_Interpolate(vector<sfiGeoOrientation>& Ori, Bounding_Box & box, int interp_IDW_select_num = 7);
    
	//构造形式线插值
	void Structural_formal_line_IDW_Interpolate(vector<sfiGeoOrientation>& Ori, Bounding_Box & box, int interp_IDW_select_num = 7);
private:

};

