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

//������Ϣ
#define ATTACH_LAYER_2_TREE "�ҽӶ�άͼ��"
#define ATTACH_FILE_2_TREE "�ҽ�ͼ���ļ�"

//������Ϣ
#define CREATE_SECTION2DMAP_QGS "���ܹ���-������ά����ͼ"

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
			UNKNOWN_LAYER, //δ֪
			GEOMAP_LAYER, //����ͼ
			SECTIONMAP_LAYER, //����ͼ
			MININGLEVLEMAP_LAYER, //�ж�ͼ
			STRTATBOUNDMAP_LAYER, //�ز����ͼ
			HOLECOLUMNMAP_LAYER, //�����״ͼ
			ISOLINEMAP_LAYER, //��ֵ��ͼ
			OTHER_LAYER, //����ͼ

			VECTORLAYER_ELEMENT, //ʸ��ͼ��
			RASTERLAYER_ELEMENT  //դ��ͼ��
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

		//��ȡ�����ļ��и�ͼ�ĸ�Ŀ¼
		std::string getGeoMapFolderPath();
		std::string getSectionMapFolderPath();
		std::string getMiningLevelMapFolderPath();
		std::string getStratBoundMapFolderPath();
		std::string getBaseMapFolderPath();
		std::string getTempFolderPath();
		std::string getDBFolderPath();
		std::string getHoleColumnMapFolderPath();

		//��ȡĿ¼���ϵĽڵ�
		//��ά
		Container* getosgEtcStructureNode();//osg���ļ��ṹ�ڵ�
		Container* getGeoBodyStructureNode();//������ṹ�ڵ�
		Container* getStratFaceNode();//�ز���ڵ�
		Container* getAttributeFieldNode();//���Գ��ڵ�


		//Ŀ¼���ϵ�ͼ�����
		void setLayerState(__int64 layer, bool bIsVisble, QgsMapCanvas* mapCanvas, int featureType = 0, int fileType = 0);
		void removeLayer(__int64 layer);
		//�Ƴ�����ͼ��
		void removeAllLayer();
		//��ȡ����ͼ��
		std::vector<pair<__int64, s3dMapLayer>>* getAllLayers();
		//��ȡ��ʾ��ͼ��
		void getShowLayer(std::vector<pair<__int64, s3dMapLayer>>& layers);
		//��ȡ����ͼ��ͼ��
		void getShowLayer(std::vector<pair<__int64, s3dMapLayer>>& layers, QgsMapCanvas* mapCanvas);
		//��ʾ��ʱͼ�㣬������  featType����0 ��1 ��2  fileType:ʸ��0 դ��1 mapCanvas:��ͼ��ͼ0 ר����ͼ1
		bool showTempLayer(QgsMapLayer * layer, QgsMapCanvas* mapCanvas, bool visible, int featType, int fileType = 0, bool isUpdateExtent = false);

		//����
		void attachQgsFile2Tree(LayerMapInfo layerInfo,const std::string& url);
		//layer����������ͷ�
		void attachQgsPrj2Tree(LayerMapInfo layerInfo, const QgsProject* layer);
		void attachQgsLayer2Tree(LayerMapInfo layerInfo, const QgsMapLayer* layer);

		Smart3dMap::OG2DElement* get2DElementByName(const std::string& name);
		Smart3dMap::Container* get2DContainerByName(const std::string& name);

		//��ȡ��ģ����Դ
		std::vector<gm_geomap>* getGeoMap();
		void GetContainer(Container* root, const std::string& GUID, std::vector<Container*>* layerContainers);//����GUIDȡ����

		std::map<std::string, gm_section_map>* getSectionMap();
		std::map<std::string, gm_mininglevel_map>* getMininglevelMap();
		std::map<std::string, std::vector<gm_a_rgn>>* getStratRgnMap();
		std::vector<s3d_BoreHole>* getBoreHole();
		const std::vector<s3d_BaseLayer>* getStandardLayers();
		std::string getDemUrl();
		std::string getRemoteImgUrl();

		std::string getPrjName();
		std::string getPrjDirectory();//��������Ŀ¼
		std::string getPrjRootFolderDirectory();//���̸�Ŀ¼
		std::string getAccessDBPath();

		//�������Խӿ�
		gme_rect_3d  getBox();

		//������ױ����ȡ��ɫ������
		std::string getClrMatNameByCode(const std::string& stratCode);
		//������ױ�Ż�ȡ���������
		std::string getTexMatNameByCode(const std::string& stratCode);

	private:
		int getStdStratVerLevel(std::vector<s3d_BaseLayer>& vStdLayers);//��ȡ��׼�ز㼶��Ϊ���ټ�

	private:
		//��������Դ��ģ����
		//vector<gm_geomap> m_GeoMapData;//����ͼ�ͻ��ҵ���ͼ
		//map<string, gm_section_map>  m_sectionmaps;//����ͼ
		//map<string, gm_mininglevel_map> m_mininglevel_maps;//�ж�ͼ
		//map<string, vector<gm_a_rgn>> m_strat_rgnmaps;//�ز����ͼ
		//vector<s3d_BoreHole>			m_boreholes; //���
		//vector<s3d_BaseLayer>	m_stdlayers; //��׼�ز�
	};
}