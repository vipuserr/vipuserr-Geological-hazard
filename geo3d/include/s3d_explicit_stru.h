#ifndef _GM_EXPLICIT_STRU_H
#define _GM_EXPLICIT_STRU_H

#include <float.h>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <gmeMdl.h>

namespace Smart3dMap
{

	// 地质/地理图类型
	enum class GeoMapType {
		ANY = 0,
		DRILL_LOG = 1,					// 钻孔柱状图
		SECTION_MAP = 2,				// 剖面图
		STRATIGRAPHY_REGION_MAP = 3,	// 地层分区图
		ISOPLETH_MAP = 4,				// 等值线图
		PLAIN_MAP = 5					// 平面地质图
	};
	class GeoMapTypeKit {
	public:
		static std::string NameOfGeoMapType(GeoMapType mapType);
		static GeoMapType GeoMapTypeFromName(const std::string& name);
	};

	typedef struct gm_a_rgn2 //地层的一个区
	{
		std::vector<gme_vector2d>		strat_outer_rgn; //区的外边界
		std::vector<std::vector<gme_vector2d>>strat_inner_rgns; //区的内边界
	}gm_a_rgn2;
	typedef struct gm_a_rgn //地层的一个区
	{
		std::vector<gme_vector3d>		strat_outer_rgn; //区的外边界
		std::vector<std::vector<gme_vector3d>>strat_inner_rgns; //区的内边界
	}gm_a_rgn;

	typedef struct gm_iso_line //等高线
	{
		std::vector<gme_vector2d>	isolin;	//一条线
		double					dZ;		//高程值
	}gm_iso_line;
	
	//剖面图钻孔轨迹线
	typedef struct gm_section_hole
	{
		gme_vector2d holelin_pos[2]; //钻孔轨迹线的顶底平面坐标
		std::vector<gme_vector2d> strat_btm; //钻孔底板点的二维坐标...
		gme_vector3d hole_coord;//钻孔的坐标
		double		  hole_depth; //孔深
		std::string	  hole_code; //钻孔编码
		long		  holeid;	 //钻孔ID
	}gm_section_hole;

	//剖面图上单条地层线(2D)
	typedef struct gm_section_line 
	{
		std::string	upper_strat; //地层线的上部地层编码
		std::string	lower_strat; //地层线的下部地层编码

		std::vector<gme_vector2d> strat_lin2d; //二维剖面图上的地层线
		std::vector<gme_vector3d> strat_lin3d; //转化到三维空间的剖面图上的地层线

	}gm_section_line;

	typedef struct gm_section_rgn
	{
		std::vector<gme_vector2d>		strat_outer_rgn_2d; //区的外边界
		std::vector<std::vector<gme_vector2d>>strat_inner_rgns_2d; //区的内边界

		std::vector<gme_vector3d>		strat_outer_rgn_3d; //区的外边界
		std::vector<std::vector<gme_vector3d>>strat_inner_rgns_3d; //区的内边界

	}gm_section_rgn;

	//地质图上单条地层线(3D)
	typedef struct gm_geomap_line
	{
		std::string	upper_strat; //地层线的上部地层编码
		std::string	lower_strat; //地层线的下部地层编码
		std::vector<gme_vector3d> strat_lin; //地层线上的点坐标串
	}gm_geomap_line;

	//地质图数据，一般是1幅图 (包括基岩地质图)
	//地质图上单条地层线(3D)
	typedef struct gm_geomap
	{
		std::string			  mapname; //图名称
		std::vector<gmeGeoPnt> geo_pnts;		  //地质点
		std::vector<gmeGeoOriPnt>  geoori_pnts;//产状点
		std::vector<gm_geomap_line> strat_lins; //地层线上的点坐标串
		std::vector<gme_fault>	faults;//断层
		std::map<std::string, std::vector<gm_a_rgn>> strat_rgns;//地层区
	}gm_geomap;

	//剖面图数据
	typedef struct gm_section_map
	{
		std::string				mapname; //图名称
		double					dXScale, dYScale; // 水平垂直方向上的比例尺分母 -- LH.2022.03.08 11:24 added.
		std::vector<gmeGeoPnt>	geo_pnts;	 //地质点
		std::vector<gmeGeoOriPnt> geoori_pnts;//产状点
		std::vector<gm_section_hole> holes;	   //剖面图上的钻孔
		std::vector<gm_section_line> strat_lins;//剖面上的地层线...
		std::vector<gme_fault>		faults;//断层
		std::map<std::string, std::vector<gm_section_rgn>> strat_rgns;//地层区
	}gm_section_map;

	//中段图
	typedef struct gm_mininglevel_map
	{
		std::string			  mapname; //图名称
		std::vector<gmeGeoPnt>	geo_pnts;	 //地质点
		std::vector<gmeGeoOriPnt> geoori_pnts;//产状点
		std::vector<gm_geomap_line> strat_lins;//剖面上的地层线...
		std::vector<gme_fault>		faults;//断层
		std::map<std::string, std::vector<gm_a_rgn>> strat_rgns;
		double		zval;//中段图的深度
	}gm_mininglevel_map;

	//地层平面分布图
	typedef struct gm_strat_rgn_map
	{
		std::string						  mapname; //图名称
		std::map<std::string, std::vector<gm_a_rgn>> strat_rgns;
	}gm_strat_rgn_map;

	//相邻的两个地层,用于记录地层是否倒转..
	typedef struct gm_stdstrat_pair
	{
		std::string		strat1;
		std::string		strat2;
	}gm_stdstrat_pair;

}

#endif //_GM_EXPLICIT_STRU_H