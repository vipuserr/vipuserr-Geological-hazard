#pragma once
#include <string>

#include "s3d_projectmanagerlib_global.h"

#include "OGContainerManager.h"
#include "OGFrameWork.h"
#include <vector>
#include "s3d_explicit_stru.h"
//#include "s3d_KerGeomodelDef.h"
#include "s3d_AttrDBDef.h"
#include "qgsmapcanvas.h"

namespace Smart3dMap
{
	struct S3D_PROJECTMANAGERLIB_EXPORT s3dMapLayer {
		bool isVisible;
		int featureType;//��0 ��1 ��2 δ֪-1
		int fileType;//ʸ��0 դ��1 δ֪-1
		QgsMapCanvas*  showCanvas;//��ͼ��ͼ ר����ͼ
	};

	class S3D_PROJECTMANAGERLIB_EXPORT ProjectLayer
	{
		friend class s3dProject;
		friend class s3dProjectForm;
		friend class ProjectManager;

	public:
		static QString getPrefixOfS3DMURL();
		static QString genURLOfS3DMMap(int dbId, int mapId);
		static void setMapURLToQgsProject(QgsProject* qgsProject, const QString& url);
		static QString getMapURLWithinQgsProject(const QgsProject* qgsProject);
		static QgsProject* loadQgsProject(const QString& urlOrFilePath);

	private:
		ProjectLayer();
		~ProjectLayer();
	
		bool save(const std::string& tree2DPath, const std::string& tree3DPath, const std::string& treeDBPath);
		bool saveTree2D(const std::string& tree2DPath);
		bool saveTree3D(const std::string& tree3DPath);
		bool saveTreeDB(const std::string& treeDBPath);
		bool saveToSysDB(int prjId);

		bool read(const std::string& tree2DPath, const std::string& tree3DPath, const std::string& treeDBPath);
		bool readTree2D(const string& tree2DPath);
		bool readTree3D(const string& tree3DPath);
		bool readTreeDB(const string& treeDBPath);
		bool readFromSysDB(int prjId);

	public:
		ContainerManager* mContainerManager2D;
		ContainerManager* mContainerManager3D;
		ContainerManager* mContainerManagerDB;
	private:
		std::vector<std::pair<__int64, s3dMapLayer>>	m_qgsLayers;

		//��ģ����Դ
		std::vector<gm_geomap> m_GeoMapData;//����ͼ�ͻ��ҵ���ͼ
		std::map<std::string, gm_section_map>  m_sectionmaps;//����ͼ
		std::map<std::string, gm_mininglevel_map> m_mininglevel_maps;//�ж�ͼ
		std::map<std::string, std::vector<gm_a_rgn>> m_strat_rgnmaps;//�ز����ͼ
		std::vector<s3d_BoreHole>	m_boreholes; //���
		std::vector<s3d_BaseLayer>	m_stdlayers; //��׼�ز�
	};
}

