#pragma once

#include "s3d_explicit_stru.h"


#include <map>
#include <QMap>
#include <QString>

using namespace std;
using namespace Smart3dMap;

using gmeGeoPnts 				 = vector<gmeGeoPnt>;					// 地质点
using gmeGeoOriPnts 			 = vector<gmeGeoOriPnt>;				// 产状点
using gme_faults 				 = vector<gme_fault>;					// 断层
using gm_geomap_lines 			 = vector<gm_geomap_line>;				// 地层线上的点坐标串
using gm_a_rgns 				 = map<string, vector<gm_a_rgn>>;		// 地层区
using gm_section_holes 			 = vector<gm_section_hole>;				// 剖面图上的钻孔
using gm_section_lines 			 = vector<gm_section_line>;				// 剖面上的地层线...
using gm_section_rgns 			 = map<string, vector<gm_section_rgn>>;	// 地层区

using addr_notes				 = vector<gmeGeoPnt>;					// 地名注记点
using water_rgns				 = map<string, vector<gm_a_rgn>>;		// 水系区

using gme_point		= gme_vector2d;			// 点
using gme_line		= vector<gme_point>;	// 线
using gme_region	= vector<gme_line>;		// 区，支持带洞的区，第一条线是区的外边界，其余的线是洞的边界。灭有洞则只有一条线

/// shp图层名称、属性名称中英文对照
/// shp文件字段名称不能超过10个字符（5个汉字），否则会被截断。统一使用小写字符。数据库服务器不区分大小写。
///
/// Begin *********************** 属性名称 ***************************
const auto PNT_NO 			 = make_pair(QStringLiteral("pnt_no"),		 QStringLiteral("点编号"));
const auto LIN_NO 			 = make_pair(QStringLiteral("lin_no"),		 QStringLiteral("线编号"));
const auto REG_NO 			 = make_pair(QStringLiteral("reg_no"),		 QStringLiteral("区编号"));
const auto HOLE_ID 			 = make_pair(QStringLiteral("hole_id"),		 QStringLiteral("钻孔ID"));
const auto HOLE_CODE 		 = make_pair(QStringLiteral("hole_code"),	 QStringLiteral("钻孔编号"));
const auto HOLE_DEPTH 		 = make_pair(QStringLiteral("hole_depth"),	 QStringLiteral("钻孔深度"));
const auto STRAT_VER 		 = make_pair(QStringLiteral("strat_ver"),	 QStringLiteral("标准版本"));
const auto STRAT_CLR 		 = make_pair(QStringLiteral("strat_clr"),	 QStringLiteral("地层颜色"));
const auto STRAT_SUBN 		 = make_pair(QStringLiteral("strat_subn"),	 QStringLiteral("地层图案号"));
const auto STRAT_CLRN 		 = make_pair(QStringLiteral("strat_clrn"),	 QStringLiteral("地层颜色号"));
const auto COORD_X 			 = make_pair(QStringLiteral("coord_x"),		 QStringLiteral("横坐标"));
const auto COORD_Y 			 = make_pair(QStringLiteral("coord_y"),		 QStringLiteral("纵坐标"));
const auto COORD_Z 			 = make_pair(QStringLiteral("coord_z"),		 QStringLiteral("高程"));
const auto ORI_DIR 			 = make_pair(QStringLiteral("ori_dir"),		 QStringLiteral("倾向"));
const auto ORI_DIP 			 = make_pair(QStringLiteral("ori_dip"),		 QStringLiteral("倾角"));
const auto TERR_CODE 		 = make_pair(QStringLiteral("terr_code"),	 QStringLiteral("地形线"));
const auto STRAT_CODE 		 = make_pair(QStringLiteral("strat_code"),	 QStringLiteral("地层代号"));
const auto UP_STRAT_CODE 	 = make_pair(QStringLiteral("up_strat"),	 QStringLiteral("上部地层代号"));
const auto DW_STRAT_CODE 	 = make_pair(QStringLiteral("dw_strat"),	 QStringLiteral("下部地层代号"));
const auto STRAT_LEV 		 = make_pair(QStringLiteral("strat_lev"),	 QStringLiteral("地层级别"));
const auto UP_STRAT_LEV = make_pair(QStringLiteral("up_lev"),	 QStringLiteral("上部地层级别"));
const auto DW_STRAT_LEV = make_pair(QStringLiteral("dw_lev"),	 QStringLiteral("下部地层级别"));
const auto STRAT_NAME 		 = make_pair(QStringLiteral("strat_name"),	 QStringLiteral("地层名称"));
const auto STRAT_DESC 		 = make_pair(QStringLiteral("strat_desc"),	 QStringLiteral("地层描述"));
const auto FAULT_CODE 		 = make_pair(QStringLiteral("fault_code"),	 QStringLiteral("断层代号"));
const auto FAULT_TYPE 		 = make_pair(QStringLiteral("fault_type"),	 QStringLiteral("断层类型"));
const auto DYKE_CODE 		 = make_pair(QStringLiteral("dyke_code"),	 QStringLiteral("岩脉代号"));
const auto DYKE_TYPE 		 = make_pair(QStringLiteral("dyke_type"),	 QStringLiteral("岩脉类型"));
const auto DYKE_WIDTH 		 = make_pair(QStringLiteral("dyke_width"),	 QStringLiteral("岩脉宽度"));
const auto TOP_DEPTH 		 = make_pair(QStringLiteral("top_depth"),	 QStringLiteral("顶板埋深"));
const auto BOTTOM_DEPTH 	 = make_pair(QStringLiteral("bot_depth"),	 QStringLiteral("底板埋深"));
const auto NAME 			 = make_pair(QStringLiteral("name"),	 QStringLiteral("名称"));
/// End *********************** 属性名称 ***************************

/// Begin *********************** 图层名称 ***************************
// *地质图 *中段图 *剖面图
const auto GEOREG 			 = make_pair(QStringLiteral("GeoReg"),		 QStringLiteral("地层区"));
const auto GEOPNT 			 = make_pair(QStringLiteral("GeoPnt"),		 QStringLiteral("地质点"));
const auto ORIPNT 			 = make_pair(QStringLiteral("OriPnt"),		 QStringLiteral("产状点"));
const auto GEOLIN 			 = make_pair(QStringLiteral("GeoLin"),		 QStringLiteral("地质界线"));
const auto FAULT 			 = make_pair(QStringLiteral("Fault"),		 QStringLiteral("断层"));
const auto DYKE 			 = make_pair(QStringLiteral("Dyke"),		 QStringLiteral("岩脉"));
// *剖面图
const auto HOLELIN 			 = make_pair(QStringLiteral("HoleLine"),	 QStringLiteral("钻孔轨迹线"));
const auto HOLEREG 			 = make_pair(QStringLiteral("HoleReg"),	 QStringLiteral("钻孔柱"));
const auto BASENOTE 		 = make_pair(QStringLiteral("BaseNote"),	 QStringLiteral("辅助点图层"));
const auto BASELIN 			 = make_pair(QStringLiteral("BaseLine"),	 QStringLiteral("辅助线图层"));
const auto BASEREG 			 = make_pair(QStringLiteral("BaseReg"),		 QStringLiteral("辅助区图层"));
const auto LEGENDNOTE 		 = make_pair(QStringLiteral("LegendNote"),	 QStringLiteral("图例注记"));
const auto LEGENDLINE 		 = make_pair(QStringLiteral("LegendLine"),	 QStringLiteral("图例外框"));
const auto LEGENDREG 		 = make_pair(QStringLiteral("LegendReg"),	 QStringLiteral("图例"));
const auto SCALENOTE 		 = make_pair(QStringLiteral("ScaleNote"),	 QStringLiteral("比例尺注记"));
const auto DISTLINE 		 = make_pair(QStringLiteral("DistLine"),	 QStringLiteral("距离线"));
const auto RULERNOTE 		 = make_pair(QStringLiteral("RulerNote"),	 QStringLiteral("标尺刻度值"));
const auto RULERLIN 		 = make_pair(QStringLiteral("RulerLine"),	 QStringLiteral("线状标尺"));
const auto RULERREG 		 = make_pair(QStringLiteral("RulerReg"),	 QStringLiteral("柱状标尺"));
const auto SIGNNOTE 		 = make_pair(QStringLiteral("SignNote"),	 QStringLiteral("图签注记"));
const auto SIGNLINE 		 = make_pair(QStringLiteral("SignLine"),	 QStringLiteral("图签框"));
const auto SECTROUTE		 = make_pair(QStringLiteral("SectRoute"),	 QStringLiteral("剖面线路径"));
/// End *********************** 图层名称 ***************************

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
