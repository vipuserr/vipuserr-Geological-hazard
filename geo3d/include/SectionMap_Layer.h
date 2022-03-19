#pragma once
#include "Layer_QgsLayer.h"

#include "OGGme2DLayerGuid.h"
#include "ProjectManager.h"

#include "qgsmaplayer.h"
#include "layerplugin_global.h"

namespace Smart3dMap {

	class LAYERPLUGIN_GEO2D_EXPORT SectionMap_Layer :public Layer_QgsLayer
	{
	public:
		SectionMap_Layer(const string& name, const OGGUID& guid);
		~SectionMap_Layer();
		
	public:
		//命令映射
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);
		virtual void registerFunctions(void);
		//消息响应
		virtual long	OnMessagePro(long nMsg, __int64 wParam, __int64 lParam) { return 1; }

		virtual __int64 getContainerData();

		void getSectionMap(gm_section_map& section) { section = mSectionMap; };

	protected:
		virtual void afterLoadQgsProject();
		virtual std::string getLayerFolder();
		virtual Smart3dMap::GeoMapType getGeoMapType();

	private:
		void onEditSectionMap(WPARAM wParam, LPARAM lParam);
		void onSaveSectionMap(WPARAM wParam, LPARAM lParam);

	private:
		ElementManager *mElementManager2D;
		gm_section_map mSectionMap;
		
	};

	COMMON_LAYLER_FACTORY(SectionMap_Layer, LYAER_SECTIONMAP_GUID, "剖面图文件");
}