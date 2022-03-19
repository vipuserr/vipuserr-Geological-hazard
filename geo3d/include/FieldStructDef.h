#pragma once

#include "s3d_explicit_stru.h"


#include <map>
#include <QMap>
#include <QString>

using namespace std;
using namespace Smart3dMap;

using gmeGeoPnts 				 = vector<gmeGeoPnt>;					// ���ʵ�
using gmeGeoOriPnts 			 = vector<gmeGeoOriPnt>;				// ��״��
using gme_faults 				 = vector<gme_fault>;					// �ϲ�
using gm_geomap_lines 			 = vector<gm_geomap_line>;				// �ز����ϵĵ����괮
using gm_a_rgns 				 = map<string, vector<gm_a_rgn>>;		// �ز���
using gm_section_holes 			 = vector<gm_section_hole>;				// ����ͼ�ϵ����
using gm_section_lines 			 = vector<gm_section_line>;				// �����ϵĵز���...
using gm_section_rgns 			 = map<string, vector<gm_section_rgn>>;	// �ز���

using addr_notes				 = vector<gmeGeoPnt>;					// ����ע�ǵ�
using water_rgns				 = map<string, vector<gm_a_rgn>>;		// ˮϵ��

using gme_point		= gme_vector2d;			// ��
using gme_line		= vector<gme_point>;	// ��
using gme_region	= vector<gme_line>;		// ����֧�ִ�����������һ������������߽磬��������Ƕ��ı߽硣���ж���ֻ��һ����

/// shpͼ�����ơ�����������Ӣ�Ķ���
/// shp�ļ��ֶ����Ʋ��ܳ���10���ַ���5�����֣�������ᱻ�ضϡ�ͳһʹ��Сд�ַ������ݿ�����������ִ�Сд��
///
/// Begin *********************** �������� ***************************
const auto PNT_NO 			 = make_pair(QStringLiteral("pnt_no"),		 QStringLiteral("����"));
const auto LIN_NO 			 = make_pair(QStringLiteral("lin_no"),		 QStringLiteral("�߱��"));
const auto REG_NO 			 = make_pair(QStringLiteral("reg_no"),		 QStringLiteral("�����"));
const auto HOLE_ID 			 = make_pair(QStringLiteral("hole_id"),		 QStringLiteral("���ID"));
const auto HOLE_CODE 		 = make_pair(QStringLiteral("hole_code"),	 QStringLiteral("��ױ��"));
const auto HOLE_DEPTH 		 = make_pair(QStringLiteral("hole_depth"),	 QStringLiteral("������"));
const auto STRAT_VER 		 = make_pair(QStringLiteral("strat_ver"),	 QStringLiteral("��׼�汾"));
const auto STRAT_CLR 		 = make_pair(QStringLiteral("strat_clr"),	 QStringLiteral("�ز���ɫ"));
const auto STRAT_SUBN 		 = make_pair(QStringLiteral("strat_subn"),	 QStringLiteral("�ز�ͼ����"));
const auto STRAT_CLRN 		 = make_pair(QStringLiteral("strat_clrn"),	 QStringLiteral("�ز���ɫ��"));
const auto COORD_X 			 = make_pair(QStringLiteral("coord_x"),		 QStringLiteral("������"));
const auto COORD_Y 			 = make_pair(QStringLiteral("coord_y"),		 QStringLiteral("������"));
const auto COORD_Z 			 = make_pair(QStringLiteral("coord_z"),		 QStringLiteral("�߳�"));
const auto ORI_DIR 			 = make_pair(QStringLiteral("ori_dir"),		 QStringLiteral("����"));
const auto ORI_DIP 			 = make_pair(QStringLiteral("ori_dip"),		 QStringLiteral("���"));
const auto TERR_CODE 		 = make_pair(QStringLiteral("terr_code"),	 QStringLiteral("������"));
const auto STRAT_CODE 		 = make_pair(QStringLiteral("strat_code"),	 QStringLiteral("�ز����"));
const auto UP_STRAT_CODE 	 = make_pair(QStringLiteral("up_strat"),	 QStringLiteral("�ϲ��ز����"));
const auto DW_STRAT_CODE 	 = make_pair(QStringLiteral("dw_strat"),	 QStringLiteral("�²��ز����"));
const auto STRAT_LEV 		 = make_pair(QStringLiteral("strat_lev"),	 QStringLiteral("�ز㼶��"));
const auto UP_STRAT_LEV = make_pair(QStringLiteral("up_lev"),	 QStringLiteral("�ϲ��ز㼶��"));
const auto DW_STRAT_LEV = make_pair(QStringLiteral("dw_lev"),	 QStringLiteral("�²��ز㼶��"));
const auto STRAT_NAME 		 = make_pair(QStringLiteral("strat_name"),	 QStringLiteral("�ز�����"));
const auto STRAT_DESC 		 = make_pair(QStringLiteral("strat_desc"),	 QStringLiteral("�ز�����"));
const auto FAULT_CODE 		 = make_pair(QStringLiteral("fault_code"),	 QStringLiteral("�ϲ����"));
const auto FAULT_TYPE 		 = make_pair(QStringLiteral("fault_type"),	 QStringLiteral("�ϲ�����"));
const auto DYKE_CODE 		 = make_pair(QStringLiteral("dyke_code"),	 QStringLiteral("��������"));
const auto DYKE_TYPE 		 = make_pair(QStringLiteral("dyke_type"),	 QStringLiteral("��������"));
const auto DYKE_WIDTH 		 = make_pair(QStringLiteral("dyke_width"),	 QStringLiteral("�������"));
const auto TOP_DEPTH 		 = make_pair(QStringLiteral("top_depth"),	 QStringLiteral("��������"));
const auto BOTTOM_DEPTH 	 = make_pair(QStringLiteral("bot_depth"),	 QStringLiteral("�װ�����"));
const auto NAME 			 = make_pair(QStringLiteral("name"),	 QStringLiteral("����"));
/// End *********************** �������� ***************************

/// Begin *********************** ͼ������ ***************************
// *����ͼ *�ж�ͼ *����ͼ
const auto GEOREG 			 = make_pair(QStringLiteral("GeoReg"),		 QStringLiteral("�ز���"));
const auto GEOPNT 			 = make_pair(QStringLiteral("GeoPnt"),		 QStringLiteral("���ʵ�"));
const auto ORIPNT 			 = make_pair(QStringLiteral("OriPnt"),		 QStringLiteral("��״��"));
const auto GEOLIN 			 = make_pair(QStringLiteral("GeoLin"),		 QStringLiteral("���ʽ���"));
const auto FAULT 			 = make_pair(QStringLiteral("Fault"),		 QStringLiteral("�ϲ�"));
const auto DYKE 			 = make_pair(QStringLiteral("Dyke"),		 QStringLiteral("����"));
// *����ͼ
const auto HOLELIN 			 = make_pair(QStringLiteral("HoleLine"),	 QStringLiteral("��׹켣��"));
const auto HOLEREG 			 = make_pair(QStringLiteral("HoleReg"),	 QStringLiteral("�����"));
const auto BASENOTE 		 = make_pair(QStringLiteral("BaseNote"),	 QStringLiteral("������ͼ��"));
const auto BASELIN 			 = make_pair(QStringLiteral("BaseLine"),	 QStringLiteral("������ͼ��"));
const auto BASEREG 			 = make_pair(QStringLiteral("BaseReg"),		 QStringLiteral("������ͼ��"));
const auto LEGENDNOTE 		 = make_pair(QStringLiteral("LegendNote"),	 QStringLiteral("ͼ��ע��"));
const auto LEGENDLINE 		 = make_pair(QStringLiteral("LegendLine"),	 QStringLiteral("ͼ�����"));
const auto LEGENDREG 		 = make_pair(QStringLiteral("LegendReg"),	 QStringLiteral("ͼ��"));
const auto SCALENOTE 		 = make_pair(QStringLiteral("ScaleNote"),	 QStringLiteral("������ע��"));
const auto DISTLINE 		 = make_pair(QStringLiteral("DistLine"),	 QStringLiteral("������"));
const auto RULERNOTE 		 = make_pair(QStringLiteral("RulerNote"),	 QStringLiteral("��߿̶�ֵ"));
const auto RULERLIN 		 = make_pair(QStringLiteral("RulerLine"),	 QStringLiteral("��״���"));
const auto RULERREG 		 = make_pair(QStringLiteral("RulerReg"),	 QStringLiteral("��״���"));
const auto SIGNNOTE 		 = make_pair(QStringLiteral("SignNote"),	 QStringLiteral("ͼǩע��"));
const auto SIGNLINE 		 = make_pair(QStringLiteral("SignLine"),	 QStringLiteral("ͼǩ��"));
const auto SECTROUTE		 = make_pair(QStringLiteral("SectRoute"),	 QStringLiteral("������·��"));
/// End *********************** ͼ������ ***************************

const QMap<QString, QString> LayerNameEnMapCn =
{
	GEOREG,
	GEOPNT,
	GEOLIN,
	ORIPNT,
	FAULT,
	DYKE,

	HOLELIN,
	HOLEREG,
	BASENOTE,
	BASELIN,
	BASEREG,
	LEGENDNOTE,
	LEGENDLINE,
	LEGENDREG,
	SCALENOTE,
	DISTLINE,
	RULERNOTE,
	RULERLIN,
	RULERREG,
	SIGNNOTE,
	SIGNLINE,

	SECTROUTE
};
