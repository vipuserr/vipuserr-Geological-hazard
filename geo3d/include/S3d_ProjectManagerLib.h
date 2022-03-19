#pragma once

#include "s3d_projectmanagerlib_global.h"

namespace Smart3dMap {

	class S3D_PROJECTMANAGERLIB_EXPORT S3d_ProjectManagerLib
	{
	public:
		static S3d_ProjectManagerLib* getSingletonPtr();

		//打开工程
		void excuteOpenProject();
		//新建工程
		void excuteNewProject();
		//保存工程
		void excuteSaveProject();
		//退出工程
		void excuteExitProject();
		//关闭工程
		bool excuteCloseProject();

		//服务器配置
		void excuteServeConfig();

		//临时函数:因为工程加载qgsVectorLayer无效，需要调用QgsProject.read()函数才有效，提前调一下
		//有时间寻找原因
		void excuteOpenMap();

	private:
		S3d_ProjectManagerLib();
		~S3d_ProjectManagerLib();
	};
}