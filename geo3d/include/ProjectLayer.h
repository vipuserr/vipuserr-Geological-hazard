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
		int featureType;//点0 线1 面2 未知-1
		int fileType;//矢量0 栅格1 未知-1
		QgsMapCanvas*  showCanvas;//地图视图 专题视图
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

		//建模数据源
		std::vector<gm_geomap> m_GeoMapData;//地质图和基岩地质图
		std::map<std::string, gm_section_map>  m_sectionmaps;//剖面图
		std::map<std::string, gm_mininglevel_map> m_mininglevel_maps;//中段图
		std::map<std::string, std::vector<gm_a_rgn>> m_strat_rgnmaps;//地层分区图
		std::vector<s3d_BoreHole>	m_boreholes; //钻孔
		std::vector<s3d_BaseLayer>	m_stdlayers; //标准地层
	};
}

