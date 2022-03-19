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
	void LoadData();//��ȡ�����Ͳ�״��
	void LoadDatadxdydz();//��ȡ�����Ͳ�״��
	void DataNormalized();//�������ݵĹ�һ��
	void incrementDeal();//����������ݣ�����incrementSymbolRange3D��
	void computeRangeA(int type);
	void computeC(int type);
	short constructKFMatrix(int type);//����K F����
	void solveEquation();//���㷽��
	void GenerateGridData();//������������,�Լ�����
	void GenerateAttributeField(int type);//��ֵ�������Գ� ֻ֧��
	double SimplePointAttribute(double x, double y, double z, int type);
	double DataAntiNormalized();//�������ݷ���һ��
	void outputVTKData();//���vtk��ʽ
	void outputGMEData();//���gme��ʽ

	void outputGMEEntity();//����ṹ���ݵ�GME��

	//Э�����
	Eigen::MatrixXd NdivergentSpline(int type, Eigen::MatrixXd r, Eigen::MatrixXd h1, Eigen::MatrixXd h2);//�Ƿ�ɢ����
	Eigen::MatrixXd CubicCovariance(int type, Eigen::MatrixXd r, Eigen::MatrixXd h1, Eigen::MatrixXd h2);//����Э���Ĭ��ʹ��

	//�����������
	void InputIncrement(vector<incrementPoint> incrementSet);//��������
	void InputGradient(vector<gradientPoint> gradientSet);//�����ݶȵ�
	void getOutData(vector<ValuePoint> &out);//�õ��������

	//������ز���
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
	vector<incrementSymbol3D> incrementSymbolVec;//��¼ÿһ����������е������
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
	//����KF�������
	bool construct_K11_K12_K21_K22_K13_K23_K33_K31_K32(int type);
	bool construct_K14_K24_K34(int type);
	bool construct_K41_K42_K43_K44(int type);
	bool spliceK();
	bool constructFMatrix();
};
