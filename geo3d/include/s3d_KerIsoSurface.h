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

	void setVolumeData(int Dim[3], double Origin[3], double Spacing[3], vector<float> VolValue);//������Ҫ���������������
	bool hasSetVolumeData() { return !vecVolValue.empty(); }
	
	void setCalGradients(bool bCalGradients) { bNeedGradients = bCalGradients; }//�����Ƿ�����ݶ�
	bool getCalGradients() { return bNeedGradients; }

	
	void setHasBoundry(bool bHasBoundry) { bBccHasBoundry = bHasBoundry; }//�����Ƿ����߽��棨BCC�ָ
	bool getHasBoundry() { return bBccHasBoundry; }

	void setSurface(vector<_IsoSurface> IsoSurfaces);//��Ҫ׷�ٵĵ�ֵ��
	void getSurface(vector<_IsoSurface> &IsoSurfaces);

	void setIsoSurfaceType(IsoSurfaceType type) { IsoType = type; }// ��ֵ��׷�ٷ���
	IsoSurfaceType getIsoSurfaceType() { return IsoType; }

	void createDrawables();//�������е�ֵ�沢����
	void getTriangles(vector<GLvector> &Triangles);//�õ����������
private:
	void vMarchingCubes(float *values, int numValues);
	void vGetCubeGradients(int ndx, int ix, int j, int k, double gradients[8][3]);
	void vMarchCube1(float afCubeValue[8], double a2fVertexOffset[8][3], double gradients[8][3]);
	void vMarchCube2(float afCubeValue[8], double a2fVertexOffset[8][3], double gradients[8][3]);
	void vMarchTetrahedron(GLvector *pasTetrahedronPosition, float *pafTetrahedronValue, double gradients[4][3]);
private:
	int nDim[3];//��������������
	double dOrigin[3];//������������
	double dSpacing[3];//ԭ��
	vector<float> vecVolValue;//��������ֵ
	
	bool bNeedGradients;//�Ƿ���Ҫ�����ݶȺͷ���

	IsoSurfaceType IsoType;//��¼��ֵ��׷�ٷ���
	vector<_IsoSurface> vecIsoSurface;// ������Ƭλ�úͷ���ֵ
	float fTargetValue;//��ǰ׷������ֵ
	float min, max;//����ֵ�����Сֵ
	int sliceSize;//ÿ�α���x*y��С
	vector<GLvector> newTriangles;//׷�ٵõ���������
	vector<GLvector> newGradients;//�ݶ�
	vector<GLvector> newNormals;//����
		
	map<int, CubeCenter> map_cubeCenter;//����ÿ�����������ĵ��������ձ�
	map<int, CubeGradients> map_cubeGradients;//����ÿ���������ÿ������ķ�����ձ�
	
	bool bBccHasBoundry;//BCC������Ե������ָ��Ǳ߽�ֿ��Ƿ���
};