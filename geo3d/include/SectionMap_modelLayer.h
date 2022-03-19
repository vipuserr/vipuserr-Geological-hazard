#pragma once
//��ά����ͼ��
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

		//��ά����תΪ��ά����
		void saveAs2dSectionMap();

		//��ȡ��׷ֲ�
		void getHoleLayer(vector<s3d_BoreHole>& outHoles);

		//��ȡ����
		void getSectSurfs(gmeModel* model, vector<SectSurf>& surfs);

		//��ȡ��λ�㣨�յ㣩
		void getAnchorPnts(vector<s3d_AnchorPnt>& pnts);

		//��ȥ�ļ�д��shp
		//void WriteGeoReg2Shp(s3d_GeoSectImport& sectImport, vector<SectSurf>& surfs, QgsVectorLayer* layer);
	public:
		//����ӳ��
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);
		virtual void registerFunctions(void);
		//��Ϣ��Ӧ
		virtual long	OnMessagePro(long nMsg, __int64 wParam, __int64 lParam) { return 1; }

		//������ɾ������
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
	COMMON_LAYLER_FACTORY(SectionMap_modelLayer, SECTIONMAP_MODELLAYER_GUID, "��ά����ͼ�ļ�");

}
