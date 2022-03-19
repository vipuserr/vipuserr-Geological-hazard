#pragma once


#include "s3d_geomodeliolib_global.h"
#include "MdlExportProtoStru.h"
#include <string>

class S3D_GEOMODELIOLIB_EXPORT S3d_GeoModelIOLib
{
public:
	static S3d_GeoModelIOLib* getSingletonPtr();

	//导入TSurf模型
	void excuteImportTSurfMdl();
	//模型合并
	void excuteMdlMerge();
	//OBJ模型导入
	void excuteImportObj();
	//OBJ模型导出
	void excuteOutputObj();
	//图层裁剪输出
	void excuteLayerClipExport();
	//模型文件导入
	void excuteMdlFileImport();
	//模型文件导出
	void excuteMdlFileOuput();
	//osgbRest服务接入
	void excuteOsgbRestImp();
	//OSG文件格式转换
	void excuteOSGConvet();
	//OSG转GME
	void excuteOsgToGme();
	//工勘数据导入
	void excuteImportGKData();
	//模型场景输出
	void excuteOutputSceneImg();
	//倾斜摄影数据加载
	void excuteLoadObliqueData();

	//grpc -- 导出0-3dtiles、1-obj
	void excuteProtoExport3DMdl(const std::string& strExportDir, const Export3DMdlProto& exportProto);

private:
	S3d_GeoModelIOLib();
	~S3d_GeoModelIOLib();

	__int64 m_parentWidget;
};
