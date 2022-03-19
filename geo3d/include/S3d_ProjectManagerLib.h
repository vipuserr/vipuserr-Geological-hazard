#pragma once

#include "s3d_projectmanagerlib_global.h"

namespace Smart3dMap {

	class S3D_PROJECTMANAGERLIB_EXPORT S3d_ProjectManagerLib
	{
	public:
		static S3d_ProjectManagerLib* getSingletonPtr();

		//�򿪹���
		void excuteOpenProject();
		//�½�����
		void excuteNewProject();
		//���湤��
		void excuteSaveProject();
		//�˳�����
		void excuteExitProject();
		//�رչ���
		bool excuteCloseProject();

		//����������
		void excuteServeConfig();

		//��ʱ����:��Ϊ���̼���qgsVectorLayer��Ч����Ҫ����QgsProject.read()��������Ч����ǰ��һ��
		//��ʱ��Ѱ��ԭ��
		void excuteOpenMap();

	private:
		S3d_ProjectManagerLib();
		~S3d_ProjectManagerLib();
	};
}