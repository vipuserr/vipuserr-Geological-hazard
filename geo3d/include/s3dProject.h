#pragma once

#include "s3d_projectmanagerlib_global.h"

#include "ProjectAttr.h"
#include "ProjectLayer.h"

#include "sqlapi.h"
#include "gmeMdl.h"

#define prjAttrName "smart3dProject.geo3d"
#define prjTree2DName "smart3dProject_dataTree2D.xml"
#define prjTree3DName "smart3dProject_dataTree3D.xml"
#define prjTreeDBName "smart3dProject_dataTreeDB.xml"

namespace Smart3dMap {

	class S3D_PROJECTMANAGERLIB_EXPORT s3dProject
	{
	public:
		s3dProject(bool inSysDB = false, int prjIdInSysDB = 0);
		~s3dProject();

		bool isSysProject();//是否是系统工程（本地工程）

		bool createPrjEmptyFolder();

		//layerTree
		void createPrjDefaultTree();
		void createPrjDefault2DTree();
		void createPrjDefault3DTree();
		void createPrjDefaultDBTree();
		void clearPrjTree();

		bool savePrjTree();
		bool readPrjTree();

		//layerAttr
		bool savePrjAttr();
		bool readPrjAttr();

		//数据库
		SAConnection* getGeoDB();
		SAConnection* getGmeDB();
		SAConnection* getSpaDB();
		const DB_CONN_INFO& getSpaDBInfo() const;
		const DB_CONN_INFO& getGmeDBInfo() const;
		const DB_CONN_INFO& getGeoDBInfo() const;

		//文件夹
		std::string getGeoMapFolderPath();
		std::string getSectionMapFolderPath();
		std::string getMiningLevelMapFolderPath();
		std::string getStratBoundMapFolderPath();
		std::string getBaseMapFolderPath();
		std::string getTempFolderPath();
		std::string getDBFolderPath();
		std::string getHoleColumnMapFolderPath();

	public:
		ProjectAttr m_AttrInfo;
		ProjectLayer m_LayerTree;

		string m_prjRootFolder;

	private:
		bool savePrjTreeToSysDB();
		bool readPrjTreeFromSysDB();
		bool savePrjAttrToSysDB();
		bool readPrjAttrFromSysDB();

	private:
		bool isInSysDB_;
		int prjIdInSysDB_;
	};

}