#pragma once
#include "s3d_geomodellib_global.h"
#include "G2DToolDef.h"

class S3D_GEOMODELLIB_EXPORT HoleModelProto {
public:
	enum DisplayType
	{
		DRILL_LINE = 0,    //线状模型
	    DRILL_CYLINER = 1 //柱状模型
	};

	int				hole_db_id;           //钻孔数据库id
	int             model_db_id;          //模型数据库id
	int             m_iStdVer;            //标准地层版本
	int				m_iSegNum;            //圆柱段数
	bool            m_bUseLayer;          //是否构建钻孔分层（一层一个geometry）
	double		    m_dRadius;            //建模孔径
	DisplayType		modelType;            //钻孔建模的模型类型
	vector<gme_vector2d> m_vHoleRange;    //边界范围
	

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
