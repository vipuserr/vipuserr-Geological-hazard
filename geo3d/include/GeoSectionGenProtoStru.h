#pragma once

//#include "s3d_geommaplib_global.h"

#include <string>
#include <vector>

class /*S3D_GEOMMAPLIB_EXPORT*/ GeoSectionGenProtoStru
{
public:
	typedef enum RulerStyle
	{
		Column = 0,
		Line = 1
	}RulerStyle;
	typedef enum RulerMark
	{
		Val_1,
		Val_5,
		Val_10,
		Val_20,
		Val_25,
		Val_50,
		Val_100
	}RulerMark;

public:
	GeoSectionGenProtoStru()
	{
	}
	GeoSectionGenProtoStru(const GeoSectionGenProtoStru& val)
	{
		m_attr_db_id = val.m_attr_db_id;
		m_is_3d_map = val.m_is_3d_map;
		m_section_db_id = val.m_section_db_id;
		m_std_strat_ver = val.m_std_strat_ver;
		m_hole_id_list = val.m_hole_id_list;
		m_section_name = val.m_section_name;
		m_transverse_scale = val.m_transverse_scale;
		m_longitudinal_scale = val.m_longitudinal_scale;
		m_ruler_style = val.m_ruler_style;
		m_ruler_mark = val.m_ruler_mark;
		m_pinch_out_coefficient = val.m_pinch_out_coefficient;
		m_smoothing_coefficient = val.m_smoothing_coefficient; // unused.
		m_grid_gap = val.m_grid_gap;
	}

public:
	int m_attr_db_id;
	bool m_is_3d_map;
	int m_section_db_id;
	int m_std_strat_ver;
	std::vector<int> m_hole_id_list;
	std::string m_section_name;
	long m_transverse_scale;
	long m_longitudinal_scale;
	RulerStyle m_ruler_style;
	RulerMark m_ruler_mark;
	float m_pinch_out_coefficient;
	float m_smoothing_coefficient; // unused.
	float m_grid_gap;

};