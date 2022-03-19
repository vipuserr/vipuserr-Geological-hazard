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
	std::string					m_GenRgnName;//图名称
	PointColor					m_ValidColor;   //有效点颜色样式(地层分区图使用)
	PointColor					m_InValidColor;	//无效点颜色样式(地层分区图使用)
	PointColor					m_UnKnowColor;	//未知点颜色样式(地层分区图使用)
	bool						m_CreatePointIcon;//是否生成点位图(地层分区图使用)
	bool						m_MergeLayer;//是否合并成图(地层分区图使用)
	bool						m_ConvexHull;//是否使用凸包
	int							m_StdStratVer; //标准地层版
	int							m_CurrentLevel;//地层级别本
	int							m_DInst;//网格间距
	int							m_DbHoleId;//钻孔数据库ID
	int							m_DbMapId;//qgs存储数据库ID
	double						m_DLinSmoothCoef;//线光滑系数
	double						m_DPinchCoef;//尖灭系数
	Smart3dMap::RegDots			m_HoleRgnDots;//边界范围
	vector<string>				m_SelectLayerCodes;//选中地层的编码
	bool						m_IsThinning;//是否抽稀
	int							m_GridRows;//抽稀行数
	int							m_GridCols;//抽稀列数
	int							m_HolesPerGrid;//抽稀后每个网格钻孔的最大数量
	double                      m_HoleDepth;//距孔口深度(地质图使用)

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