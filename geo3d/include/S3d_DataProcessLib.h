#pragma once

#include "s3d_dataprocesslib_global.h"

class S3D_DATAPROCESSLIB_EXPORT S3d_DataProcessLib
{
public:
	static S3d_DataProcessLib* getSingletonPtr();

	//����DEM TIffӰ��
	void excuteCreateDEMTIFF();
	//����ͼ���ݼ��
	void excuteCheckGeoMap();
	//�ж�ͼ���ݼ��
	void excuteCheckMiningMap();
	//����ͼ���ݼ��
	void excuteCheckSectionMap();
	//�ز����ͼ���ݼ��
	void excuteCheckStratnMap();
	//������ݼ��
	void excuteCheckHoleData();
	//ˮ��������Ӹ�ˮ��
	void excuteHoleAddWaterResLayer();
	//������ݸ���
	void excuteUpdateHoleData();
	//osgDEM��Ƭ����
	void excuteOsgDemProcess();
	//MapGIS����תQGIS����
	void excuteMapGISPrj2QGISPrj();
	//MapGISͼ��תQGISͼ��
	void excuteMapGISLyr2QGISLyr();

	//�����ֵ�����
	void excuteSysDictSetting();
	//��׼�ز�༭
	void excuteEditStdStrat();
	void excuteNewStdStratId(__int64, int maxId);

	//��׼�ز�ѡ��
	void excuteSelectStdStrat();

	//������������
	//�������¼��
	void excuteInsertVHole();
	//������ײ�ѯ
	void excuteSelectVHole();
	//���������������
	void excuteVHoleGridSet();
	//����ϵͳ����
	void ShowConfigDlg();

	//������ݱ����
	void excuteDataTabImportDb();

	//Qgs�������
	void ShowQgsImportDlg();

	//MapGIS��ɫ�ⰴ���Ը�ɫshp
	void excuteAddColorInShp();
private:
    S3d_DataProcessLib();
	~S3d_DataProcessLib();

	__int64 m_parentWidget;
	
};
