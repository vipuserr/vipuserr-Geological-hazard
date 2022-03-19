#pragma once
//qgs
#include <string>
#include "s3d_projectmanagerlib_global.h"
#include "s3d_explicit_stru.h"
#include "OGContainer.h"
#include "s3dProject.h"
#include "OGMessageListener.h"
#include "OG2DElement.h"
#include "s3d_AttrDBDef.h"

//工程消息
#define ATTACH_LAYER_2_TREE "挂接二维图件"
#define ATTACH_FILE_2_TREE "挂接图件文件"

//功能消息
#define CREATE_SECTION2DMAP_QGS "功能管理-创建二维剖面图"

namespace Smart3dMap {
	
	class S3D_PROJECTMANAGERLIB_EXPORT ProjectManager
	{
	public:
		struct QgsContainerInfo
		{
			QgsVectorLayer* layer;
			std::string guidName;
			std::string displayName;

			QgsContainerInfo()
			{
				layer = nullptr;
				guidName = "";
				displayName = "";
			}
		};

		enum LayerMapType
		{
			UNKNOWN_LAYER, //未知
			GEOMAP_LAYER, //地质图
			SECTIONMAP_LAYER, //剖面图
			MININGLEVLEMAP_LAYER, //中段图
			STRTATBOUNDMAP_LAYER, //地层分区图
			HOLECOLUMNMAP_LAYER, //钻孔柱状图
			ISOLINEMAP_LAYER, //等值线图
			OTHER_LAYER, //其他图

			VECTORLAYER_ELEMENT, //矢量图层
			RASTERLAYER_ELEMENT  //栅格图层
		};

		struct LayerMapInfo
		{
			LayerMapType type = UNKNOWN_LAYER;
			std::string canvasName = STR_WINDOW_2D;
		};

		static ProjectManager* getSingletonPtr();

		const s3dProject* getCurrentProject() { return currentPrj; };
		void setCurrentProject(s3dProject* prj) { currentPrj = prj; }

		SAConnection* getCurrentGeoDB();

		gmeDataBase* getCurrentGmeDB();

		SAConnection* getCurrentSpaDB();


	private:
		ProjectManager();
		~ProjectManager();
	
	public:
		s3dProject* currentPrj;
		s3dProject* prePrj;
	public:
		//void setStratId(int stratid);
		int getStratId();

		void setStratVerName(const std::string& stratVerName);
		std::string getStratVerName();

		//获取工程文件夹各图的根目录
		std::string getGeoMapFolderPath();
		std::string getSectionMapFolderPath();
		std::string getMiningLevelMapFolderPath();
		std::string getStratBoundMapFolderPath();
		std::string getBaseMapFolderPath();
		std::string getTempFolderPath();
		std::string getDBFolderPath();
		std::string getHoleColumnMapFolderPath();

		//获取目录树上的节点
		//三维
		Container* getosgEtcStructureNode();//osg等文件结构节点
		Container* getGeoBodyStructureNode();//地质体结构节点
		Container* getStratFaceNode();//地层面节点
		Container* getAttributeFieldNode();//属性场节点


		//目录树上的图层管理
		void setLayerState(__int64 layer, bool bIsVisble, QgsMapCanvas* mapCanvas, int featureType = 0, int fileType = 0);
		void removeLayer(__int64 layer);
		//移除所有图层
		void removeAllLayer();
		//获取所有图层
		std::vector<pair<__int64, s3dMapLayer>>* getAllLayers();
		//获取显示的图层
		void getShowLayer(std::vector<pair<__int64, s3dMapLayer>>& layers);
		//获取各视图的图层
		void getShowLayer(std::vector<pair<__int64, s3dMapLayer>>& layers, QgsMapCanvas* mapCanvas);
		//显示临时图层，不挂树  featType：点0 线1 面2  fileType:矢量0 栅格1 mapCanvas:地图视图0 专题视图1
		bool showTempLayer(QgsMapLayer * layer, QgsMapCanvas* mapCanvas, bool visible, int featType, int fileType = 0, bool isUpdateExtent = false);

		//挂树
		void attachQgsFile2Tree(LayerMapInfo layerInfo,const std::string& url);
		//layer无须调用者释放
		void attachQgsPrj2Tree(LayerMapInfo layerInfo, const QgsProject* layer);
		void attachQgsLayer2Tree(LayerMapInfo layerInfo, const QgsMapLayer* layer);

		Smart3dMap::OG2DElement* get2DElementByName(const std::string& name);
		Smart3dMap::Container* get2DContainerByName(const std::string& name);

		//获取建模数据源
		std::vector<gm_geomap>* getGeoMap();
		void GetContainer(Container* root, const std::string& GUID, std::vector<Container*>* layerContainers);//根据GUID取类型

		std::map<std::string, gm_section_map>* getSectionMap();
		std::map<std::string, gm_mininglevel_map>* getMininglevelMap();
		std::map<std::string, std::vector<gm_a_rgn>>* getStratRgnMap();
		std::vector<s3d_BoreHole>* getBoreHole();
		const std::vector<s3d_BaseLayer>* getStandardLayers();
		std::string getDemUrl();
		std::string getRemoteImgUrl();

		std::string getPrjName();
		std::string getPrjDirectory();//工程所在目录
		std::string getPrjRootFolderDirectory();//工程根目录
		std::string getAccessDBPath();

		//工程属性接口
		gme_rect_3d  getBox();

		//根据钻孔编码获取颜色材质名
		std::string getClrMatNameByCode(const std::string& stratCode);
		//根据钻孔编号获取纹理材质名
		std::string getTexMatNameByCode(const std::string& stratCode);

	private:
		int getStdStratVerLevel(std::vector<s3d_BaseLayer>& vStdLayers);//获取标准地层级别为多少级

	private:
		//基础数据源建模数据
		//vector<gm_geomap> m_GeoMapData;//地质图和基岩地质图
		//map<string, gm_section_map>  m_sectionmaps;//剖面图
		//map<string, gm_mininglevel_map> m_mininglevel_maps;//中段图
		//map<string, vector<gm_a_rgn>> m_strat_rgnmaps;//地层分区图
		//vector<s3d_BoreHole>			m_boreholes; //钻孔
		//vector<s3d_BaseLayer>	m_stdlayers; //标准地层
	};
}