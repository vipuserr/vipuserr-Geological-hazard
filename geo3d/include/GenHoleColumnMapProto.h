#pragma once
#include "s3d_geommaplib_global.h"
#include <string>

class S3D_GEOMMAPLIB_EXPORT GenHoleColumnMapProto {
public:
	int				hole_db_id;//钻孔数据库id
	int				hole_id; //钻孔id
	int				std_ver;//标准地层版本id
	int				current_level;//地层级别
	int				map_db_id;//目标数据库Id
	int				paperType;//图幅大小
	int				scale;//比例尺
	bool			useDefaultScale;//使用默认比例尺，如为true，则scale无效
	std::string		mapName;//生成的柱状图图名 

	GenHoleColumnMapProto()
	{
		hole_db_id =0;
		hole_id = 0;
		std_ver =0;
		current_level =0; 
		map_db_id =0;
		paperType =0;
		scale =0;
		useDefaultScale =true;
		mapName = "钻孔柱状图";
	}

};