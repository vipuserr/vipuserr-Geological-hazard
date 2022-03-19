#pragma once

#include <vector>
#include "s3d_AttrDBDef.h"

#include "gme_vector3.h"
#include "s3d_geomodelanalylib_global.h"

//������׷������
class S3D_GEOMODELANALYLIB_EXPORT DummyHoleProto
{
public:
	int m_dummyHoleID;									//out -- ���ɵ��������ģ��id
	std::vector<Smart3dMap::HoleInfo> m_hole_list; // out -- ��������׵ķֲ���Ϣ -- LH.2021.12.06 15:34 added.

	int m_mdlID;										//in -- ģ��id
	int m_mdlDbID;										//in -- ģ�����ݿ�id
	int m_dummyHoleRadius;								//in -- ������װ뾶(��)
	double m_dummyHoleArcs;								//in -- ������׿׿ڻ�����(��)
	std::vector<gme_vector3d> m_vecDummyHolesPos;		//in -- ������׵�λ����
	
	DummyHoleProto() : m_dummyHoleID(0),
		m_hole_list({}),
		m_mdlID(0),
		m_mdlDbID(0),
		m_dummyHoleRadius(2),
		m_dummyHoleArcs(8)
	{
	}
};
