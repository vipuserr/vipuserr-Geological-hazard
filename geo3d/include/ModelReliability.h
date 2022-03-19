#pragma once

#include <string>
#include <vector>
#include <map>

#include "s3d_AttrDBDef.h"
#include "VecSpatialAnalys.h"
#include "s3d_explicit_stru.h" // 剖面图的地层区结构 gm_section_rgn

#include "s3d_baseapplib_global.h"

namespace Smart3dMap
{
	class S3D_BASEAPPLIB_EXPORT ModelReliability
	{
	public: // 外部结构定义
		// 是否可信枚举值
		typedef enum IsReliable
		{
			False = 0, // 相当于布尔值的false
			True = 1, // 相当于布尔值的true
			Unknown = 2 // 不知道可不可信，代表没有真实数据对比
		} IsReliable;
		// 钻孔分层的每段可信度信息
		typedef struct HoleLayerSegInfo
		{
			double m_top; // 段上界高程
			double m_btm; // 段下界高程
			IsReliable m_is_reliable; // 段是否可信
		} HoleLayerSegInfo;
		// 钻孔的每个分层的可信度信息
		typedef struct HoleLayerReliabilityInfo
		{
			std::string layer_code; // 地层编码
			double m_layer_reliability; // 层可信度
			std::vector<HoleLayerSegInfo> m_layer_seg_info_list; // 层的段可信度信息列表
		} HoleLayerReliabilityInfo;
		// 钻孔的可信度信息
		typedef struct HoleReliability
		{
			s3d_BoreHole m_real_hole_info; // 真实孔信息
			s3d_BoreHole m_virtual_hole_info; // 虚拟孔信息
			double m_total_reliability; // 总可信度
			std::vector<HoleLayerReliabilityInfo> m_hole_layer_reliability_info_list; // 虚拟孔分层的可信度信息列表
		} HoleReliability;
		
		// 二维虚拟剖面某个层的单个区的可信度信息
		typedef struct RegionReliabilityInfo
		{
			gm_section_rgn* m_original_rgn_ptr; // 指向二维剖面某层的某个原始区的地址，属于结构的内部地址，无需在意它的释放
			std::vector<gm_section_rgn> m_union_rgn; // 与真实剖面对应层的所有区的交集区
			std::vector<gm_section_rgn> m_difference_rgn; // 与真实剖面对应层的所有区的差集区(不包括未知可信度区)
			double m_rgn_reliability; // 该区的可信度(交集区与差集区的面积比)
		} RegionReliabilityInfo;
		// 二维虚拟剖面某个层的可信度信息
		typedef struct SectionLayerReliabilityInfo
		{
			std::string m_layer_code; // 层编码
			double m_layer_reliability; // 层可信度
			std::vector<RegionReliabilityInfo> m_region_reliability_info_list; // 层中每个区的可信度信息列表。
		} SectionLayerReliabilityInfo;
		// 二维剖面的可信度信息
		typedef struct SectionMapReliability
		{
			std::map<std::string, std::vector<gm_section_rgn>> m_real_section_map; // 真实剖面区集信息
			std::map<std::string, std::vector<gm_section_rgn>> m_virtual_section_map; // 虚拟剖面区集信息
			double m_reliability; // 虚拟剖面的可信度(可信区集与虚拟剖面区集的面积比)
			std::vector<SectionLayerReliabilityInfo> m_section_layer_reliability_info_list; // 虚拟剖面不同地层的可信区集(真实剖面与虚拟剖面相交部分)
		} SectionMapReliability;
	public: // 外部方法定义
		/*
			\brief 计算一个钻孔的可信度

			\param real_hole 真实钻孔，参照
			\param virtual_hole 要计算可信度的虚拟孔，依据
			\param with_unknown 是否计算未知段，true时总可信度为：总可信段长/真实孔长；false时总可信度为：(总可信段长 + 0.5*未知段长)/虚拟孔长

			\return 虚拟孔可信度信息
		*/
		HoleReliability calculateHoleReliability(const s3d_BoreHole &real_hole, const s3d_BoreHole &virtual_hole, const bool with_unknown = true);
		// 剖面可信度
		SectionMapReliability calculateSectionMapReliability(const std::map<std::string, std::vector<gm_section_rgn>> &real_polygon, const std::map<std::string, std::vector<gm_section_rgn>> &virtual_polygon);
		/* 
			\brief 根据区域和百分数划分钻孔
			
			\param res_selected_hole_list 结果，选中的钻孔信息，对应每个区，顺序对应 // TODO: 输出为钻孔id列表或许更好？
			\param res_unselected_hole_list  结果，未选中的钻孔信息，对应每个区，顺序对应 // TODO: 输出为钻孔id列表或许更好？
			\param hole_list_of_each_region 每个区域对应的钻孔信息列表
			\param ratio 划分比率，代表每个区中选取多少钻孔，取值范围：[0.0, 1.0]
		*/
		void divHoles(std::vector<std::vector<s3d_BoreHole>> &res_selected_hole_list, std::vector<std::vector<s3d_BoreHole>> &res_unselected_hole_list, const std::vector<std::vector<s3d_BoreHole>> &hole_list_of_each_region, const double ratio);
	private: // 内部方法定义
		// 真实、虚拟钻孔预处理，使分层连续
		void holePreProcess(s3d_BoreHole &hole);
		// 浮点数精度相等
		bool equalsDouble(double d1, double d2, double precision=10e-6);
		// 将区结构互转，得到的指针需释放
		PolyRef transfer(const gm_section_rgn &rgn);
		// 区结构互转，重载
		gm_section_rgn transfer(PolyRef& polygon);
		// 释放资源并清空容器
		void free(vector<s3d_Polygon*> &resource);
		// 计算区集面积，要求各区互斥
		double calculateRegionsArea(vector<s3d_Polygon*>& rgns);
		// 钻孔集合抽样 - 线性随机抽样
		void linearRandomSampling(std::vector<s3d_BoreHole> &result_selected, std::vector<s3d_BoreHole> &result_unselected, const std::vector<s3d_BoreHole> &hole_list_per_region, const int selecting_size);
	};
}


