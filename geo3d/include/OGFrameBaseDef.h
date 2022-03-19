#pragma once

#include <string>

namespace Smart3dMap
{
	//模型拾取操作相关
#define INTERACT_NULL 0            //无操作
#define INTERACT_PICK 1            //拾取操作
#define INTERACT_LAYER_PICK 2      //钻孔分层拾取操作

    //xml,需移动至CTdmXmlDef.h
	const std::string STR_MAP_FILE			= "RoamingMapFile";
	const std::string STR_PROJECTED_FILE	= "ProjectedFile";
	const std::string STR_GEOCENTRIC_FILE	= "GeocentricFile";
	const std::string VIEW_ROATATE_TREND	= "RotatingTrendSwitch";

	//要素类图层名称
	const std::string FCLSTYPE_COMM_LAYERNAME		= "普通要素类";
	const std::string FCLSTYPE_GEOPNT_LAYERNAME		= "地质点";
	const std::string FCLSTYPE_GEOORIPNT_LAYERNAME	= "产状点";
	const std::string FCLSTYPE_GEOLIN_LAYERNAME		= "地质线";
	const std::string FCLSTYPE_GEOSURF_LAYERNAME	= "地质面";
	const std::string FCLSTYPE_GEOENT_LAYERNAME		= "地质体";
	const std::string FCLSTYPE_GEOHOLE_LAYERNAME	= "钻孔";
	const std::string FCLSTYPE_GEOFAULT_LAYERNAME	= "断层";
	const std::string FCLSTYPE_DEM_LAYERNAME		= "地形";
	const std::string FCLSTYPE_FIELD_LAYERNAME		= "属性场";
	const std::string FCLSTYPE_BOLT_LAYERNAME		= "锚杆";
	const std::string FCLSTYPE_PILE_LAYERNAME		= "桩基";
	const std::string FCLSTYPE_BUILD_LAYERNAME		= "建筑物";

	//osg对象名称
	const std::string strLineDrillHoleGeode		= "strLineDrillHoleGeode";//拾取线状的钻孔
	const std::string strCylinerDrillHoleGeode	= "strCylinerDrillHoleGeode";//拾取柱状钻孔
	const std::string strInteractHandleName		= "strInteractHandleName";//交互操作eventhandler的名称
	const std::string strPickHandleName			= "strPickHandleName";//模型拾取操作eventhandler的名称
	const std::string strEditingHandleName		= "strEditingHandleName";//模型编辑操作eventhandler的名称

	//消息名称
	const std::string msg_strSendLineHoleID		= "msg_strSendLineHoleID";//发送钻孔id的消息
	const std::string msg_strSendCylinerHoleID	= "msg_strSendCylinerHoleID";

	const std::string msg_strSendPickNews		= "msg_strSendPickNews";//发送拾取模型的要素与几何指针消息

	const std::string msg_strSendHoleNews		= "msg_strSendHoleNews";//发送要素与几何指针的消息
	const std::string msg_strSendSurfaceNews	= "msg_strSendSurfaceNews";
	const std::string msg_strSendEntityNews		= "msg_strSendEntityNews";
	const std::string msg_strSendGeoSurfaceNews = "msg_strSendGeoSurfaceNews";
	const std::string msg_strSendGeoEntityNews	= "msg_strSendGeoEntityNews";
	const std::string msg_strSendHoleLayer		= "msg_strSendHoleLayer";

	const std::string msg_strSendGMELayerScaleFactorDialog	= "msg_strSendGMELayerScaleFactorDialog";//设置整个三位数据树的缩放比例的消息
	const std::string msg_strSendVertexArray				= "msg_strSendVertexArray";//从二维接收数据消息来绘制线
	const std::string msg_strSendClearVertexArray			= "msg_strSendClearVertexArray";//从二维接收把已绘制的线清空

	//拾取名称
	const std::string osgPicked_gmeCornerGeode		= "osgPicked_gmeCornerGeode";
	const std::string osgPicked_gmeLineGeode		= "osgPicked_gmeLineGeode";
	const std::string osgPicked_gmeSurfaceGeode		= "osgPicked_gmeSurfaceGeode";
	const std::string osgPicked_gmeEntityGeode		= "osgPicked_gmeEntityGeode";
	const std::string osgPicked_gmeGeoPntGeode		= "osgPicked_gmeGeoPntGeode";
	const std::string osgPicked_gmeGeoOriPntGeode	= "osgPicked_gmeGeoOriPntGeode";
	const std::string osgPicked_gmeGeoLineGeode		= "osgPicked_gmeGeoLineGeode";
	const std::string osgPicked_gmeGeoSurfaceGeode	= "osgPicked_gmeGeoSurfaceGeode";
	const std::string osgPicked_gmeGeoEntityGeode	= "osgPicked_gmeGeoEntityGeode";
	const std::string osgPicked_gmeGeoHoleGeode		= "osgPicked_gmeGeoHoleGeode";
	const std::string osgPicked_gmeGeoFaultGeode	= "osgPicked_gmeGeoFaultGeode";
	const std::string osgPicked_gmeGeoFieldGeode	= "osgPicked_gmeGeoFieldGeode";
	const std::string osgPicked_gmeOctGeoFieldGeode = "osgPicked_gmeOctGeoFieldGeode";

	//漫游交互消息
	const std::string strRoadmingHandleName = "strRoadmingHandleName";

}