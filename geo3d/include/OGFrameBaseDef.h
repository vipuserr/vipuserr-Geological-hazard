#pragma once

#include <string>

namespace Smart3dMap
{
	//ģ��ʰȡ�������
#define INTERACT_NULL 0            //�޲���
#define INTERACT_PICK 1            //ʰȡ����
#define INTERACT_LAYER_PICK 2      //��׷ֲ�ʰȡ����

    //xml,���ƶ���CTdmXmlDef.h
	const std::string STR_MAP_FILE			= "RoamingMapFile";
	const std::string STR_PROJECTED_FILE	= "ProjectedFile";
	const std::string STR_GEOCENTRIC_FILE	= "GeocentricFile";
	const std::string VIEW_ROATATE_TREND	= "RotatingTrendSwitch";

	//Ҫ����ͼ������
	const std::string FCLSTYPE_COMM_LAYERNAME		= "��ͨҪ����";
	const std::string FCLSTYPE_GEOPNT_LAYERNAME		= "���ʵ�";
	const std::string FCLSTYPE_GEOORIPNT_LAYERNAME	= "��״��";
	const std::string FCLSTYPE_GEOLIN_LAYERNAME		= "������";
	const std::string FCLSTYPE_GEOSURF_LAYERNAME	= "������";
	const std::string FCLSTYPE_GEOENT_LAYERNAME		= "������";
	const std::string FCLSTYPE_GEOHOLE_LAYERNAME	= "���";
	const std::string FCLSTYPE_GEOFAULT_LAYERNAME	= "�ϲ�";
	const std::string FCLSTYPE_DEM_LAYERNAME		= "����";
	const std::string FCLSTYPE_FIELD_LAYERNAME		= "���Գ�";
	const std::string FCLSTYPE_BOLT_LAYERNAME		= "ê��";
	const std::string FCLSTYPE_PILE_LAYERNAME		= "׮��";
	const std::string FCLSTYPE_BUILD_LAYERNAME		= "������";

	//osg��������
	const std::string strLineDrillHoleGeode		= "strLineDrillHoleGeode";//ʰȡ��״�����
	const std::string strCylinerDrillHoleGeode	= "strCylinerDrillHoleGeode";//ʰȡ��״���
	const std::string strInteractHandleName		= "strInteractHandleName";//��������eventhandler������
	const std::string strPickHandleName			= "strPickHandleName";//ģ��ʰȡ����eventhandler������
	const std::string strEditingHandleName		= "strEditingHandleName";//ģ�ͱ༭����eventhandler������

	//��Ϣ����
	const std::string msg_strSendLineHoleID		= "msg_strSendLineHoleID";//�������id����Ϣ
	const std::string msg_strSendCylinerHoleID	= "msg_strSendCylinerHoleID";

	const std::string msg_strSendPickNews		= "msg_strSendPickNews";//����ʰȡģ�͵�Ҫ���뼸��ָ����Ϣ

	const std::string msg_strSendHoleNews		= "msg_strSendHoleNews";//����Ҫ���뼸��ָ�����Ϣ
	const std::string msg_strSendSurfaceNews	= "msg_strSendSurfaceNews";
	const std::string msg_strSendEntityNews		= "msg_strSendEntityNews";
	const std::string msg_strSendGeoSurfaceNews = "msg_strSendGeoSurfaceNews";
	const std::string msg_strSendGeoEntityNews	= "msg_strSendGeoEntityNews";
	const std::string msg_strSendHoleLayer		= "msg_strSendHoleLayer";

	const std::string msg_strSendGMELayerScaleFactorDialog	= "msg_strSendGMELayerScaleFactorDialog";//����������λ�����������ű�������Ϣ
	const std::string msg_strSendVertexArray				= "msg_strSendVertexArray";//�Ӷ�ά����������Ϣ��������
	const std::string msg_strSendClearVertexArray			= "msg_strSendClearVertexArray";//�Ӷ�ά���հ��ѻ��Ƶ������

	//ʰȡ����
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

	//���ν�����Ϣ
	const std::string strRoadmingHandleName = "strRoadmingHandleName";

}