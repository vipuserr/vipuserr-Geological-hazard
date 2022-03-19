#pragma once
#include "OG2DLayer.h"

#include "OGGme2DLayerGuid.h"
#include "ProjectManager.h"
#include "ogFrameWork.h"

#include "qgsvectorlayer.h"
#include "qgsmapcanvas.h"
#include <qgsproject.h>
#include "layerplugin_global.h"

#include "qgssettings.h"
#include "qgsexpressioncontextutils.h"
#include "qgsabstractgeopdfexporter.h"
#include "qgsmaprenderertask.h"
#include "qgsapplication.h"
#include "S3dmVectorLayer.h"

namespace Smart3dMap {

	class LAYERPLUGIN_GEO2D_EXPORT Layer_QgsLayer :public OG2DLayer
	{
	public:
		Layer_QgsLayer(const string& name, const OGGUID& guid,const char* mapCanvasName= STR_WINDOW_2D);
		virtual ~Layer_QgsLayer();

		virtual bool createAllChild();

		//needRelease标识QgsProject是否需要该树图层来释放
		void setQgsProject(QgsProject* prj, bool needRelease = true);
		QgsProject* getQgsProject() { return m_qgsProject; }


		void applyMapSettings(QgsMapSettings &mapSettings, QgsMapCanvas* p2DMapView, double dpi = 64);

		enum FileFormat
		{
			PDF = 0,
			IMAGE =1
		};

		void saveAsFile(QString file, FileFormat type,double dpi);

	public:
		//命令映射
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);
		virtual void registerFunctions(void);
		//消息响应
		virtual long	OnMessagePro(string nMsg, __int64 wParam, __int64 lParam);

		
		virtual long BeforeDelLayer();

		virtual bool load(DataElement* element);
		virtual bool save(DataElement* element);
		virtual void BeforeSave();

		void saveQgsFileToLocalOrDB(QString url);

	protected:
		virtual void afterLoadQgsProject();
		virtual std::string getLayerFolder();
		virtual Smart3dMap::GeoMapType getGeoMapType();

	protected:
		QgsMapCanvas *m_2DMapView; //当前视图
		QgsProject* m_qgsProject; //qgs工程指针
	private:
		bool		m_NeedRelease;
	};

	COMMON_LAYLER_FACTORY(Layer_QgsLayer, LAYER_QGSLAYER, "图层QGS基类文件")
}