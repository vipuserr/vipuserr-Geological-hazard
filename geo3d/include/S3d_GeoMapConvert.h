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
		// ִ��ǰ�������д���gmeModel -- LH.2021.11.01 09:59 commented.
		bool section_2d_to_3d(gmeModel* &gme_model, gm_section_map &section_map, int64 attr_db_conn);
		// �ɵز���(gm_section_map::strat_rgns)�õ��ز�������(gm_section_map::strat_lins)
		bool getStratLinesFromStratRgns(std::vector<gm_section_line> &strat_lins, const std::map<std::string, std::vector<gm_section_rgn>> &strat_rgns);
		// �õ��Ľ���� gm_section_map
		bool sectionmap_3d_to_2d(gmeModel* mdl, gm_section_map& map, int xScale, int yScale);

		void section_2d_to_3d(gm_section_map &section_map);

		//����ͼת�������
		void section2VHole(std::vector<s3d_BoreHole>& holes, gm_section_map& sectionmap, const int& interval);
		//����ͼ�ı�����
		void get2DSectionMapScale(gm_section_map& map, int& xScale, int& yScale);

	};
}


