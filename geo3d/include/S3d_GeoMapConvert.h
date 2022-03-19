#pragma once
#include "s3d_baseapplib_global.h"

#include "s3d_explicit_stru.h"
#include "gmeStru.h"
#include "s3d_AttrDBDef.h"

namespace Smart3dMap
{
	class S3D_BASEAPPLIB_EXPORT S3d_GeoMapConvert
	{
	public:
		// 执行前无需自行创建gmeModel -- LH.2021.11.01 09:59 commented.
		bool section_2d_to_3d(gmeModel* &gme_model, gm_section_map &section_map, int64 attr_db_conn);
		// 由地层区(gm_section_map::strat_rgns)得到地层线数据(gm_section_map::strat_lins)
		bool getStratLinesFromStratRgns(std::vector<gm_section_line> &strat_lins, const std::map<std::string, std::vector<gm_section_rgn>> &strat_rgns);
		// 得到的结果是 gm_section_map
		bool sectionmap_3d_to_2d(gmeModel* mdl, gm_section_map& map, int xScale, int yScale);

		void section_2d_to_3d(gm_section_map &section_map);

		//剖面图转虚拟钻孔
		void section2VHole(std::vector<s3d_BoreHole>& holes, gm_section_map& sectionmap, const int& interval);
		//剖面图的比例尺
		void get2DSectionMapScale(gm_section_map& map, int& xScale, int& yScale);

	};
}


