#pragma once
#include "s3d_geommaplib_global.h"
#include <string>

class S3D_GEOMMAPLIB_EXPORT GenHoleColumnMapProto {
public:
	int				hole_db_id;//������ݿ�id
	int				hole_id; //���id
	int				std_ver;//��׼�ز�汾id
	int				current_level;//�ز㼶��
	int				map_db_id;//Ŀ�����ݿ�Id
	int				paperType;//ͼ����С
	int				scale;//������
	bool			useDefaultScale;//ʹ��Ĭ�ϱ����ߣ���Ϊtrue����scale��Ч
	std::string		mapName;//���ɵ���״ͼͼ�� 

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
		mapName = "�����״ͼ";
	}

};