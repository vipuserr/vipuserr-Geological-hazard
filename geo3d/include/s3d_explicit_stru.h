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

	// ����/����ͼ����
	enum class GeoMapType {
		ANY = 0,
		DRILL_LOG = 1,					// �����״ͼ
		SECTION_MAP = 2,				// ����ͼ
		STRATIGRAPHY_REGION_MAP = 3,	// �ز����ͼ
		ISOPLETH_MAP = 4,				// ��ֵ��ͼ
		PLAIN_MAP = 5					// ƽ�����ͼ
	};
	class GeoMapTypeKit {
	public:
		static std::string NameOfGeoMapType(GeoMapType mapType);
		static GeoMapType GeoMapTypeFromName(const std::string& name);
	};

	typedef struct gm_a_rgn2 //�ز��һ����
	{
		std::vector<gme_vector2d>		strat_outer_rgn; //������߽�
		std::vector<std::vector<gme_vector2d>>strat_inner_rgns; //�����ڱ߽�
	}gm_a_rgn2;
	typedef struct gm_a_rgn //�ز��һ����
	{
		std::vector<gme_vector3d>		strat_outer_rgn; //������߽�
		std::vector<std::vector<gme_vector3d>>strat_inner_rgns; //�����ڱ߽�
	}gm_a_rgn;

	typedef struct gm_iso_line //�ȸ���
	{
		std::vector<gme_vector2d>	isolin;	//һ����
		double					dZ;		//�߳�ֵ
	}gm_iso_line;
	
	//����ͼ��׹켣��
	typedef struct gm_section_hole
	{
		gme_vector2d holelin_pos[2]; //��׹켣�ߵĶ���ƽ������
		std::vector<gme_vector2d> strat_btm; //��׵װ��Ķ�ά����...
		gme_vector3d hole_coord;//��׵�����
		double		  hole_depth; //����
		std::string	  hole_code; //��ױ���
		long		  holeid;	 //���ID
	}gm_section_hole;

	//����ͼ�ϵ����ز���(2D)
	typedef struct gm_section_line 
	{
		std::string	upper_strat; //�ز��ߵ��ϲ��ز����
		std::string	lower_strat; //�ز��ߵ��²��ز����

		std::vector<gme_vector2d> strat_lin2d; //��ά����ͼ�ϵĵز���
		std::vector<gme_vector3d> strat_lin3d; //ת������ά�ռ������ͼ�ϵĵز���

	}gm_section_line;

	typedef struct gm_section_rgn
	{
		std::vector<gme_vector2d>		strat_outer_rgn_2d; //������߽�
		std::vector<std::vector<gme_vector2d>>strat_inner_rgns_2d; //�����ڱ߽�

		std::vector<gme_vector3d>		strat_outer_rgn_3d; //������߽�
		std::vector<std::vector<gme_vector3d>>strat_inner_rgns_3d; //�����ڱ߽�

	}gm_section_rgn;

	//����ͼ�ϵ����ز���(3D)
	typedef struct gm_geomap_line
	{
		std::string	upper_strat; //�ز��ߵ��ϲ��ز����
		std::string	lower_strat; //�ز��ߵ��²��ز����
		std::vector<gme_vector3d> strat_lin; //�ز����ϵĵ����괮
	}gm_geomap_line;

	//����ͼ���ݣ�һ����1��ͼ (�������ҵ���ͼ)
	//����ͼ�ϵ����ز���(3D)
	typedef struct gm_geomap
	{
		std::string			  mapname; //ͼ����
		std::vector<gmeGeoPnt> geo_pnts;		  //���ʵ�
		std::vector<gmeGeoOriPnt>  geoori_pnts;//��״��
		std::vector<gm_geomap_line> strat_lins; //�ز����ϵĵ����괮
		std::vector<gme_fault>	faults;//�ϲ�
		std::map<std::string, std::vector<gm_a_rgn>> strat_rgns;//�ز���
	}gm_geomap;

	//����ͼ����
	typedef struct gm_section_map
	{
		std::string				mapname; //ͼ����
		double					dXScale, dYScale; // ˮƽ��ֱ�����ϵı����߷�ĸ -- LH.2022.03.08 11:24 added.
		std::vector<gmeGeoPnt>	geo_pnts;	 //���ʵ�
		std::vector<gmeGeoOriPnt> geoori_pnts;//��״��
		std::vector<gm_section_hole> holes;	   //����ͼ�ϵ����
		std::vector<gm_section_line> strat_lins;//�����ϵĵز���...
		std::vector<gme_fault>		faults;//�ϲ�
		std::map<std::string, std::vector<gm_section_rgn>> strat_rgns;//�ز���
	}gm_section_map;

	//�ж�ͼ
	typedef struct gm_mininglevel_map
	{
		std::string			  mapname; //ͼ����
		std::vector<gmeGeoPnt>	geo_pnts;	 //���ʵ�
		std::vector<gmeGeoOriPnt> geoori_pnts;//��״��
		std::vector<gm_geomap_line> strat_lins;//�����ϵĵز���...
		std::vector<gme_fault>		faults;//�ϲ�
		std::map<std::string, std::vector<gm_a_rgn>> strat_rgns;
		double		zval;//�ж�ͼ�����
	}gm_mininglevel_map;

	//�ز�ƽ��ֲ�ͼ
	typedef struct gm_strat_rgn_map
	{
		std::string						  mapname; //ͼ����
		std::map<std::string, std::vector<gm_a_rgn>> strat_rgns;
	}gm_strat_rgn_map;

	//���ڵ������ز�,���ڼ�¼�ز��Ƿ�ת..
	typedef struct gm_stdstrat_pair
	{
		std::string		strat1;
		std::string		strat2;
	}gm_stdstrat_pair;

}

#endif //_GM_EXPLICIT_STRU_H