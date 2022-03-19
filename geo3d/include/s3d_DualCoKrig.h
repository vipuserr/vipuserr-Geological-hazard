#pragma once
#include <vector>
#include <Eigen/Dense> 

#include "s3d_KerInterpCokrigDef.h"
#include "s3d_KerAuxDef.h"
#include "gmeStru.h"


using Eigen::MatrixXd;
using namespace std;
constexpr auto Pi = (3.14159265358979323846);

using namespace Smart3dMap;




class LIB_S3DKERINTERPCOKRIG_EXP C3DModelField
{
public:
	C3DModelField();
	~C3DModelField();
public:
	void LoadData();//读取界面点和产状点
	void LoadDatadxdydz();//读取界面点和产状点
	void DataNormalized();//坐标数据的归一化
	void incrementDeal();//处理界面数据，置于incrementSymbolRange3D中
	void computeRangeA(int type);
	void computeC(int type);
	short constructKFMatrix(int type);//创建K F矩阵
	void solveEquation();//计算方程
	void GenerateGridData();//生成网格数据,自己方法
	void GenerateAttributeField(int type);//插值生成属性场 只支持
	double SimplePointAttribute(double x, double y, double z, int type);
	double DataAntiNormalized();//坐标数据反归一化
	void outputVTKData();//输出vtk格式
	void outputGMEData();//输出gme格式

	void outputGMEEntity();//输出结构数据到GME中

	//协方差函数
	Eigen::MatrixXd NdivergentSpline(int type, Eigen::MatrixXd r, Eigen::MatrixXd h1, Eigen::MatrixXd h2);//非发散样条
	Eigen::MatrixXd CubicCovariance(int type, Eigen::MatrixXd r, Eigen::MatrixXd h1, Eigen::MatrixXd h2);//三次协方差，默认使用

	//输入输出数据
	void InputIncrement(vector<incrementPoint> incrementSet);//输入界面点
	void InputGradient(vector<gradientPoint> gradientSet);//输入梯度点
	void getOutData(vector<ValuePoint> &out);//得到输出数据

	//设置相关参数
	void setRange(Smart3dMap::gme_rect_3d range);
	void getRange(Smart3dMap::gme_rect_3d &range);
	void setRatio(modelRatio ratio);
	void getRatio(modelRatio &ratio); 
	void getOrigin(modelOrigin &origin);

	void setRangeA(double a);
	void getRangeA(double &a);
	void setInputData(string pathFoliations, string pathPoints);
	void getInputData(string &pathFoliations, string &pathPoints);
	void setVTKOut(string pathVTK);
	void getVTKOut(string &pathVTK);
public:
	double range_a;
	double c0;
	vector<incrementSymbol3D> incrementSymbolVec;//记录每一个界面的所有点的索引
	Eigen::MatrixXd incrementMatrix;
private:
	Eigen::MatrixXd gradientMatrix;
	
	std::vector<incrementSymbolRange3D> incrementSymbolRangeVec;
	double XMIN, XMAX, YMIN, YMAX, ZMIN, ZMAX;
	int nx, ny, nz;
	
	string url_Foliations;
	string url_Points;
	string url_VTKOut;
	Eigen::MatrixXd K11, K12, K21, K22, K13, K23, K31, K32, K33, K14, K24, K34, K41, K42, K43, K44;
	Eigen::MatrixXd K, F, FResult;
	Eigen::MatrixXd outData;
	Eigen::MatrixXd xx1d, yy1d, zz1d;
private:
	//创建KF矩阵相关
	bool construct_K11_K12_K21_K22_K13_K23_K33_K31_K32(int type);
	bool construct_K14_K24_K34(int type);
	bool construct_K41_K42_K43_K44(int type);
	bool spliceK();
	bool constructFMatrix();
};
