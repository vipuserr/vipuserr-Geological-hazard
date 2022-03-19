#pragma once
//三维剖面图类
//zhuyh-20210419

#include "OG3DLayer.h"
#include "OGGme3DLayerGuid.h"
#include <S3d_KerGeoSect.h>
#include "qobject.h"
#include "OGFrameWork.h"
#include "ui_exportSectQgs.h"
#include "layerplugin_geo3d_global.h"

namespace Smart3dMap {
	class LAYERPLUGIN_GEO3D_EXPORT SectionMap_modelLayer:public QObject,public OG3DLayer
	{
	Q_OBJECT
		struct SectSurf {
			vector<gme_vector3d> pnts;
			std::string stratCode;
			std::string stratName;
		};
	public:
		SectionMap_modelLayer(const string& name, const OGGUID& guid);
		~SectionMap_modelLayer();

		//三维剖面转为二维剖面
		void saveAs2dSectionMap();

		//获取钻孔分层
		void getHoleLayer(vector<s3d_BoreHole>& outHoles);

		//获取剖面
		void getSectSurfs(gmeModel* model, vector<SectSurf>& surfs);

		//获取定位点（拐点）
		void getAnchorPnts(vector<s3d_AnchorPnt>& pnts);

		//将去文件写入shp
		//void WriteGeoReg2Shp(s3d_GeoSectImport& sectImport, vector<SectSurf>& surfs, QgsVectorLayer* layer);
	public:
		//命令映射
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);
		virtual void registerFunctions(void);
		//消息响应
		virtual long	OnMessagePro(long nMsg, __int64 wParam, __int64 lParam) { return 1; }

		//关联、删除关联
		virtual long ReltLayer();
		virtual long DelRelt();

		virtual bool load(DataElement* element);
		virtual bool save(DataElement* element);

		virtual void setVisible(bool visible, bool cascade = true);
		virtual bool isVisible();

	private:
		QWidget* m_exportWidget;
		Ui::exportSectQgs exportSectUI;
	};
	COMMON_LAYLER_FACTORY(SectionMap_modelLayer, SECTIONMAP_MODELLAYER_GUID, "三维剖面图文件");

}
