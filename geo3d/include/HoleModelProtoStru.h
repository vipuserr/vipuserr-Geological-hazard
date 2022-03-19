#pragma once
#include "s3d_geomodellib_global.h"
#include "G2DToolDef.h"

class S3D_GEOMODELLIB_EXPORT HoleModelProto {
public:
	enum DisplayType
	{
		DRILL_LINE = 0,    //��״ģ��
	    DRILL_CYLINER = 1 //��״ģ��
	};

	int				hole_db_id;           //������ݿ�id
	int             model_db_id;          //ģ�����ݿ�id
	int             m_iStdVer;            //��׼�ز�汾
	int				m_iSegNum;            //Բ������
	bool            m_bUseLayer;          //�Ƿ񹹽���׷ֲ㣨һ��һ��geometry��
	double		    m_dRadius;            //��ģ�׾�
	DisplayType		modelType;            //��׽�ģ��ģ������
	vector<gme_vector2d> m_vHoleRange;    //�߽緶Χ
	

	HoleModelProto()
	{
		hole_db_id = 0;
		m_iStdVer = 1;
		m_bUseLayer = false;
		m_iSegNum = 8;
		m_dRadius = 20;
		modelType = DisplayType::DRILL_LINE;
	}

};
