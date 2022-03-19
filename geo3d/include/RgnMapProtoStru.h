#pragma once
#include "s3d_geommaplib_global.h"
#include "G2DToolDef.h"
#include "gmeStru.h"

struct PointColor {
	int red;
	int green;
	int blue;
	PointColor() {
		red = 0;
		green = 0;
		blue = 0;
	}
};
class S3D_GEOMMAPLIB_EXPORT RgnMapProto {
public:
	std::string					m_GenRgnName;//ͼ����
	PointColor					m_ValidColor;   //��Ч����ɫ��ʽ(�ز����ͼʹ��)
	PointColor					m_InValidColor;	//��Ч����ɫ��ʽ(�ز����ͼʹ��)
	PointColor					m_UnKnowColor;	//δ֪����ɫ��ʽ(�ز����ͼʹ��)
	bool						m_CreatePointIcon;//�Ƿ����ɵ�λͼ(�ز����ͼʹ��)
	bool						m_MergeLayer;//�Ƿ�ϲ���ͼ(�ز����ͼʹ��)
	bool						m_ConvexHull;//�Ƿ�ʹ��͹��
	int							m_StdStratVer; //��׼�ز��
	int							m_CurrentLevel;//�ز㼶��
	int							m_DInst;//������
	int							m_DbHoleId;//������ݿ�ID
	int							m_DbMapId;//qgs�洢���ݿ�ID
	double						m_DLinSmoothCoef;//�߹⻬ϵ��
	double						m_DPinchCoef;//����ϵ��
	Smart3dMap::RegDots			m_HoleRgnDots;//�߽緶Χ
	vector<string>				m_SelectLayerCodes;//ѡ�еز�ı���
	bool						m_IsThinning;//�Ƿ��ϡ
	int							m_GridRows;//��ϡ����
	int							m_GridCols;//��ϡ����
	int							m_HolesPerGrid;//��ϡ��ÿ��������׵��������
	double                      m_HoleDepth;//��׿����(����ͼʹ��)

	RgnMapProto()
	{
		m_GenRgnName = "";

		m_CreatePointIcon = true;
		m_MergeLayer = false;
		m_ConvexHull = false;

		m_StdStratVer = 1; 
		m_CurrentLevel = 1;
		m_DInst = 2000;
		m_DbHoleId = 0;
		m_DbMapId = 0;

		m_DLinSmoothCoef = 0.5;
		m_DPinchCoef = 0.5;

		m_IsThinning = false;
		m_GridRows = 10;
		m_GridCols = 10;
		m_HolesPerGrid = 1;

		m_HoleDepth = 2.0;
	}

};