#pragma once

#include <vector>
#include <string>
#include <map>
using namespace std;

#include "s3d_KerIsoSurfExp.h"
#include "s3d_KerIsoSurfDef.h"




class LIB_S3DKERISOSURF_EXP CIsoSurface
{
public:
	CIsoSurface();
	virtual ~CIsoSurface();

	void setVolumeData(int Dim[3], double Origin[3], double Spacing[3], vector<float> VolValue);//设置需要生成切面的体数据
	bool hasSetVolumeData() { return !vecVolValue.empty(); }
	
	void setCalGradients(bool bCalGradients) { bNeedGradients = bCalGradients; }//设置是否计算梯度
	bool getCalGradients() { return bNeedGradients; }

	
	void setHasBoundry(bool bHasBoundry) { bBccHasBoundry = bHasBoundry; }//设置是否保留边界面（BCC分割）
	bool getHasBoundry() { return bBccHasBoundry; }

	void setSurface(vector<_IsoSurface> IsoSurfaces);//需要追踪的等值面
	void getSurface(vector<_IsoSurface> &IsoSurfaces);

	void setIsoSurfaceType(IsoSurfaceType type) { IsoType = type; }// 等值面追踪方法
	IsoSurfaceType getIsoSurfaceType() { return IsoType; }

	void createDrawables();//生成所有等值面并绘制
	void getTriangles(vector<GLvector> &Triangles);//得到结果三角网
private:
	void vMarchingCubes(float *values, int numValues);
	void vGetCubeGradients(int ndx, int ix, int j, int k, double gradients[8][3]);
	void vMarchCube1(float afCubeValue[8], double a2fVertexOffset[8][3], double gradients[8][3]);
	void vMarchCube2(float afCubeValue[8], double a2fVertexOffset[8][3], double gradients[8][3]);
	void vMarchTetrahedron(GLvector *pasTetrahedronPosition, float *pafTetrahedronValue, double gradients[4][3]);
private:
	int nDim[3];//三个方向网格数
	double dOrigin[3];//三方向网格间距
	double dSpacing[3];//原点
	vector<float> vecVolValue;//所有属性值
	
	bool bNeedGradients;//是否需要计算梯度和法向

	IsoSurfaceType IsoType;//记录等值面追踪方法
	vector<_IsoSurface> vecIsoSurface;// 所有切片位置和方向值
	float fTargetValue;//当前追踪属性值
	float min, max;//属性值最大最小值
	int sliceSize;//每次遍历x*y大小
	vector<GLvector> newTriangles;//追踪得到的三角网
	vector<GLvector> newGradients;//梯度
	vector<GLvector> newNormals;//法向
		
	map<int, CubeCenter> map_cubeCenter;//构建每个立方体中心点和坐标对照表
	map<int, CubeGradients> map_cubeGradients;//构建每个立方体和每个顶点的法向对照表
	
	bool bBccHasBoundry;//BCC方法边缘立方体分割是边界分块是否保留
};