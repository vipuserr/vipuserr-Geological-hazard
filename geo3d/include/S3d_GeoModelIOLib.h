#pragma once


#include "s3d_geomodeliolib_global.h"
#include "MdlExportProtoStru.h"
#include <string>

class S3D_GEOMODELIOLIB_EXPORT S3d_GeoModelIOLib
{
public:
	static S3d_GeoModelIOLib* getSingletonPtr();

	//����TSurfģ��
	void excuteImportTSurfMdl();
	//ģ�ͺϲ�
	void excuteMdlMerge();
	//OBJģ�͵���
	void excuteImportObj();
	//OBJģ�͵���
	void excuteOutputObj();
	//ͼ��ü����
	void excuteLayerClipExport();
	//ģ���ļ�����
	void excuteMdlFileImport();
	//ģ���ļ�����
	void excuteMdlFileOuput();
	//osgbRest�������
	void excuteOsgbRestImp();
	//OSG�ļ���ʽת��
	void excuteOSGConvet();
	//OSGתGME
	void excuteOsgToGme();
	//�������ݵ���
	void excuteImportGKData();
	//ģ�ͳ������
	void excuteOutputSceneImg();
	//��б��Ӱ���ݼ���
	void excuteLoadObliqueData();

	//grpc -- ����0-3dtiles��1-obj
	void excuteProtoExport3DMdl(const std::string& strExportDir, const Export3DMdlProto& exportProto);

private:
	S3d_GeoModelIOLib();
	~S3d_GeoModelIOLib();

	__int64 m_parentWidget;
};
