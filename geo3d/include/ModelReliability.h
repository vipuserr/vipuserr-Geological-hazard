#pragma once

#include <string>
#include <vector>
#include <map>

#include "s3d_AttrDBDef.h"
#include "VecSpatialAnalys.h"
#include "s3d_explicit_stru.h" // ����ͼ�ĵز����ṹ gm_section_rgn

#include "s3d_baseapplib_global.h"

namespace Smart3dMap
{
	class S3D_BASEAPPLIB_EXPORT ModelReliability
	{
	public: // �ⲿ�ṹ����
		// �Ƿ����ö��ֵ
		typedef enum IsReliable
		{
			False = 0, // �൱�ڲ���ֵ��false
			True = 1, // �൱�ڲ���ֵ��true
			Unknown = 2 // ��֪���ɲ����ţ�����û����ʵ���ݶԱ�
		} IsReliable;
		// ��׷ֲ��ÿ�ο��Ŷ���Ϣ
		typedef struct HoleLayerSegInfo
		{
			double m_top; // ���Ͻ�߳�
			double m_btm; // ���½�߳�
			IsReliable m_is_reliable; // ���Ƿ����
		} HoleLayerSegInfo;
		// ��׵�ÿ���ֲ�Ŀ��Ŷ���Ϣ
		typedef struct HoleLayerReliabilityInfo
		{
			std::string layer_code; // �ز����
			double m_layer_reliability; // ����Ŷ�
			std::vector<HoleLayerSegInfo> m_layer_seg_info_list; // ��Ķο��Ŷ���Ϣ�б�
		} HoleLayerReliabilityInfo;
		// ��׵Ŀ��Ŷ���Ϣ
		typedef struct HoleReliability
		{
			s3d_BoreHole m_real_hole_info; // ��ʵ����Ϣ
			s3d_BoreHole m_virtual_hole_info; // �������Ϣ
			double m_total_reliability; // �ܿ��Ŷ�
			std::vector<HoleLayerReliabilityInfo> m_hole_layer_reliability_info_list; // ����׷ֲ�Ŀ��Ŷ���Ϣ�б�
		} HoleReliability;
		
		// ��ά��������ĳ����ĵ������Ŀ��Ŷ���Ϣ
		typedef struct RegionReliabilityInfo
		{
			gm_section_rgn* m_original_rgn_ptr; // ָ���ά����ĳ���ĳ��ԭʼ���ĵ�ַ�����ڽṹ���ڲ���ַ���������������ͷ�
			std::vector<gm_section_rgn> m_union_rgn; // ����ʵ�����Ӧ����������Ľ�����
			std::vector<gm_section_rgn> m_difference_rgn; // ����ʵ�����Ӧ����������Ĳ��(������δ֪���Ŷ���)
			double m_rgn_reliability; // �����Ŀ��Ŷ�(�����������������)
		} RegionReliabilityInfo;
		// ��ά��������ĳ����Ŀ��Ŷ���Ϣ
		typedef struct SectionLayerReliabilityInfo
		{
			std::string m_layer_code; // �����
			double m_layer_reliability; // ����Ŷ�
			std::vector<RegionReliabilityInfo> m_region_reliability_info_list; // ����ÿ�����Ŀ��Ŷ���Ϣ�б�
		} SectionLayerReliabilityInfo;
		// ��ά����Ŀ��Ŷ���Ϣ
		typedef struct SectionMapReliability
		{
			std::map<std::string, std::vector<gm_section_rgn>> m_real_section_map; // ��ʵ����������Ϣ
			std::map<std::string, std::vector<gm_section_rgn>> m_virtual_section_map; // ��������������Ϣ
			double m_reliability; // ��������Ŀ��Ŷ�(�����������������������������)
			std::vector<SectionLayerReliabilityInfo> m_section_layer_reliability_info_list; // �������治ͬ�ز�Ŀ�������(��ʵ���������������ཻ����)
		} SectionMapReliability;
	public: // �ⲿ��������
		/*
			\brief ����һ����׵Ŀ��Ŷ�

			\param real_hole ��ʵ��ף�����
			\param virtual_hole Ҫ������Ŷȵ�����ף�����
			\param with_unknown �Ƿ����δ֪�Σ�trueʱ�ܿ��Ŷ�Ϊ���ܿ��Ŷγ�/��ʵ�׳���falseʱ�ܿ��Ŷ�Ϊ��(�ܿ��Ŷγ� + 0.5*δ֪�γ�)/����׳�

			\return ����׿��Ŷ���Ϣ
		*/
		HoleReliability calculateHoleReliability(const s3d_BoreHole &real_hole, const s3d_BoreHole &virtual_hole, const bool with_unknown = true);
		// ������Ŷ�
		SectionMapReliability calculateSectionMapReliability(const std::map<std::string, std::vector<gm_section_rgn>> &real_polygon, const std::map<std::string, std::vector<gm_section_rgn>> &virtual_polygon);
		/* 
			\brief ��������Ͱٷ����������
			
			\param res_selected_hole_list �����ѡ�е������Ϣ����Ӧÿ������˳���Ӧ // TODO: ���Ϊ���id�б������ã�
			\param res_unselected_hole_list  �����δѡ�е������Ϣ����Ӧÿ������˳���Ӧ // TODO: ���Ϊ���id�б������ã�
			\param hole_list_of_each_region ÿ�������Ӧ�������Ϣ�б�
			\param ratio ���ֱ��ʣ�����ÿ������ѡȡ������ף�ȡֵ��Χ��[0.0, 1.0]
		*/
		void divHoles(std::vector<std::vector<s3d_BoreHole>> &res_selected_hole_list, std::vector<std::vector<s3d_BoreHole>> &res_unselected_hole_list, const std::vector<std::vector<s3d_BoreHole>> &hole_list_of_each_region, const double ratio);
	private: // �ڲ���������
		// ��ʵ���������Ԥ����ʹ�ֲ�����
		void holePreProcess(s3d_BoreHole &hole);
		// �������������
		bool equalsDouble(double d1, double d2, double precision=10e-6);
		// �����ṹ��ת���õ���ָ�����ͷ�
		PolyRef transfer(const gm_section_rgn &rgn);
		// ���ṹ��ת������
		gm_section_rgn transfer(PolyRef& polygon);
		// �ͷ���Դ���������
		void free(vector<s3d_Polygon*> &resource);
		// �������������Ҫ���������
		double calculateRegionsArea(vector<s3d_Polygon*>& rgns);
		// ��׼��ϳ��� - �����������
		void linearRandomSampling(std::vector<s3d_BoreHole> &result_selected, std::vector<s3d_BoreHole> &result_unselected, const std::vector<s3d_BoreHole> &hole_list_per_region, const int selecting_size);
	};
}


