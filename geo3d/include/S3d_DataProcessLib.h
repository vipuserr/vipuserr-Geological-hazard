#pragma once

#include "s3d_dataprocesslib_global.h"

class S3D_DATAPROCESSLIB_EXPORT S3d_DataProcessLib
{
public:
	static S3d_DataProcessLib* getSingletonPtr();

	//生成DEM TIff影像
	void excuteCreateDEMTIFF();
	//地质图数据检查
	void excuteCheckGeoMap();
	//中段图数据检查
	void excuteCheckMiningMap();
	//剖面图数据检查
	void excuteCheckSectionMap();
	//地层分区图数据检查
	void excuteCheckStratnMap();
	//钻孔数据检查
	void excuteCheckHoleData();
	//水文钻孔增加隔水层
	void excuteHoleAddWaterResLayer();
	//钻孔数据更新
	void excuteUpdateHoleData();
	//osgDEM切片处理
	void excuteOsgDemProcess();
	//MapGIS工程转QGIS工程
	void excuteMapGISPrj2QGISPrj();
	//MapGIS图层转QGIS图层
	void excuteMapGISLyr2QGISLyr();

	//数据字典配置
	void excuteSysDictSetting();
	//标准地层编辑
	void excuteEditStdStrat();
	void excuteNewStdStratId(__int64, int maxId);

	//标准地层选择
	void excuteSelectStdStrat();

	//海南特殊需求
	//虚拟钻孔录入
	void excuteInsertVHole();
	//虚拟钻孔查询
	void excuteSelectVHole();
	//虚拟钻孔网格设置
	void excuteVHoleGridSet();
	//配置系统参数
	void ShowConfigDlg();

	//钻孔数据表入库
	void excuteDataTabImportDb();

	//Qgs工程入库
	void ShowQgsImportDlg();

	//MapGIS颜色库按属性赋色shp
	void excuteAddColorInShp();
private:
    S3d_DataProcessLib();
	~S3d_DataProcessLib();

	__int64 m_parentWidget;
	
};
