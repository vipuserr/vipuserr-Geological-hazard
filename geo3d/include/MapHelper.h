#pragma once
#include "s3d_geommaplib_global.h"

namespace Smart3dMap {
	// ͼ������
	class S3D_GEOMMAPLIB_EXPORT MapHelper
	{
	public:
		/// �����ݿ��е�ͼ������Ϊ����ͼ����
		/// @param dbId		��ͼ�������ݿ��ID��
		/// @param mapId	�ⱻ�����ĵ�ͼ��ID��
		static bool PublishMapOnWeb(int dbId, int mapId);
	};
}

