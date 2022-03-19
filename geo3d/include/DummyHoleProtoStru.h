#pragma once

#include <vector>
#include "s3d_AttrDBDef.h"

#include "gme_vector3.h"
#include "s3d_geomodelanalylib_global.h"

//虚拟钻孔服务参数
class S3D_GEOMODELANALYLIB_EXPORT DummyHoleProto
{
public:
	int m_dummyHoleID;									//out -- 生成的虚拟钻孔模型id
	std::vector<Smart3dMap::HoleInfo> m_hole_list; // out -- 所有虚拟孔的分层信息 -- LH.2021.12.06 15:34 added.

	int m_mdlID;										//in -- 模型id
	int m_mdlDbID;										//in -- 模型数据库id
	int m_dummyHoleRadius;								//in -- 虚拟钻孔半径(米)
	double m_dummyHoleArcs;								//in -- 虚拟钻孔孔口弧段数(个)
	std::vector<gme_vector3d> m_vecDummyHolesPos;		//in -- 虚拟钻孔点位集合
	
	DummyHoleProto() : m_dummyHoleID(0),
		m_hole_list({}),
		m_mdlID(0),
		m_mdlDbID(0),
		m_dummyHoleRadius(2),
		m_dummyHoleArcs(8)
	{
	}
};
