#pragma once
#include "OG2DLayer.h"
#include "Layer_QgsLayer.h"
#include "OGGme2DLayerGuid.h"
#include "layerplugin_global.h"



namespace Smart3dMap
{
	class LAYERPLUGIN_GEO2D_EXPORT HoleColumnMap_Layer :public Layer_QgsLayer
	{
	public:
		HoleColumnMap_Layer(const string& name, const OGGUID& guid);
		~HoleColumnMap_Layer();

		virtual std::string getLayerFolder() override;
		virtual Smart3dMap::GeoMapType getGeoMapType() override;
	public:
		//ÃüÁîÓ³Éä
		virtual void onExecute(const string& name, WPARAM wParam, LPARAM lParam);
		virtual void registerFunctions(void);
		//ÏûÏ¢ÏìÓ¦
		virtual long OnMessagePro(string nMsg, __int64 wParam, __int64 lParam);
		virtual void registerStrMsg();

	};
	COMMON_LAYLER_FACTORY(HoleColumnMap_Layer, LAYER_HOLECOLUMNMAP_GUID, "×ê¿×Öù×´Í¼");
}


