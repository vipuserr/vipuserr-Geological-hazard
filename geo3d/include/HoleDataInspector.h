// Copyright 2021 LH Per. All rights reserved.
/**
 *
 * 对所声明的类的功能和用法作简单说明
 * 
 *
 * Notice: 钻孔检查器类的任务只是把传进的数据检查，然后返回检查有异常的数据集合，不关心传进的数据之间在传入前的关联性。
 *
 */

#ifndef __LH__HOLE_DATA_INSPECTOR_H__
#define __LH__HOLE_DATA_INSPECTOR_H__

#include <string>
#include <list> // 用链表存储类的内部需要数据
#include <vector> // 用向量存储返回给外部的检查结果集
#include <map>
#include <algorithm>

#include "s3d_dataprocesslib_global.h"
#include "s3d_KerGeomodelDef.h"
#include "s3d_AttrDBDef.h"

namespace Smart3dMap
{
	/*!
		\brief The Inspector of the Hole data.


		\note It's properties will be improved.

		\sa none.

		\code
			none.
		\endcode
	*/
	class S3D_DATAPROCESSLIB_EXPORT HoleDataInspector
	{
	public:
		/*!
			\brief 构造函数

			\param selected_hole_list_without_layer 需要检查的、不带分层的钻孔数据集；引用类型
			\param selected_hole_layer 需要检查的钻孔分层数据集；引用类型
			\param selected_std_stratum_list 标准地层描述信息数据集，支持混合多种不同版本号；引用类型
		*/
		HoleDataInspector(const std::vector< HoleInfo> &selected_hole_list_without_layer, const std::vector<HoleLayer> &selected_hole_layer, const std::vector< hole_stdStratDesc > &selected_std_stratum_list);
		~HoleDataInspector();

		/*!
			\brief 用已构造的检查器检查新的钻孔数据集

			\param selected_hole_list_with_hole_layer 需要检查的、带分层的 新的 钻孔数据集；引用类型
			\param selected_std_stratum_list 新的 指定版本号的标准地层描述信息列表；引用类型
		*/
		// TODO: 还未完善，或者可以不需要 -- LH.2021.09.27 11:32 commented.
		void updateData(const std::vector< HoleInfo> &selected_hole_list_without_layer, const std::vector<HoleLayer> &selected_hole_layer, const std::vector< hole_stdStratDesc > &selected_std_stratum_list);

		// ***************** the function to check data *** begin ********************
		// 1. 钻孔数据错误检查...
		// 1.1 检查钻孔ID为空
		std::vector< HoleInfo > funcCheckHoleIdIsNull();

		// 1.2 检查钻孔编码为空
		std::vector< HoleInfo > funcCheckHoleCodeIsNull();

		// 1.3 检测钻孔孔深是否与分层对应，返回值 vector< pair< 异常钻孔, pair<标准地层版本, 对应标准地层版本下最深层钻孔分层的底板埋深> > >
		std::vector< std::pair< HoleInfo, std::pair<long, double> > > funcCheckHoleDepth(int64 sql_api_ptr_int = NULL, bool auto_repaire = false);

		// 1.4 检查钻孔Id重复，返回值 vector< pair<钻孔id, 相同id的钻孔列表> >
		std::vector< std::pair< int, std::vector< HoleInfo > > > funcCheckHoleIdRepeat();

		// 1.5 检测钻孔编码重复，返回值 ...
		std::vector< std::pair< std::string, std::vector< HoleInfo > > > funcCheckHoleCodeRepeat();

		// 1.6 检测钻孔坐标重复，返回值 vector< pair<(x, y), 相同坐标的钻孔列表> >
		std::vector< std::pair< std::pair<double, double>, std::vector< HoleInfo > > > funcCheckHoleCoordinateRepeat(int64 sql_api_ptr_int = NULL, bool auto_repaire = false);

		// 2. 钻孔分层数据错误检查

		// 2.01 检查钻孔有无分层数据，返回值 map<地层版本id, 指定版本下无分层的钻孔列表>
		std::map< int, std::vector<HoleInfo> > funcCheckHoleMissHoleLayer();

		// 2.02 钻孔分层缺少钻孔基本信息 // TODO: ????
		std::vector< s3d_BoreHoleLayer > funcCheckHoleLayerMissHole();

		// 2.03 钻孔的地层编码为空
		std::vector< HoleInfo > funcCheckHoleStratCodeIsNull();
		
		// 2.03.01 钻孔地层版本为空
		std::vector< HoleInfo > funcCheckHoleLayerStratumVerIsNull();
		
		// 2.04 钻孔地层编码在标准地层中找不到
		std::vector< HoleInfo > funcCheckStratCodeExist();

		// 2.05 钻孔地层底板埋深正确性检查（底板埋深皆大于0）。
		// 错误类型取值：0, 第一层层顶埋深不为0; 1, 非第一层层顶埋深不大于0; 2, 层底埋深不大于0
		std::vector< HoleInfo > funcCheckBottomDepthIsRight();

		// 2.05.02 钻孔地层底板埋深正确性检查 (钻孔分层非第一层的层顶埋深不大于0)
		// 返回值：vector< pair< 有问题的分层, pair<该分层的孔口标高, 期待的正确值> > >
		std::vector < std::pair< HoleLayer, std::pair<double, double> > > funcCheckTopDepthIsNULL(int64 sql_api_ptr_int = NULL, bool auto_repaire = false);

		// 2.06 顶板埋深>=底板埋深
		std::vector< HoleInfo > funcCheckTopUnderBottom();

		// 2.07 检查钻孔分层不连续，返回值 map<地层版本id, 指定版本下分层不连续的钻孔列表>
		std::map< int, std::vector<HoleInfo> > funcCheckHoleLayerBreak();

		// 2.08 检查钻孔分层堆叠，返回值 map<地层版本id, 指定版本下分层堆叠的钻孔列表>
		std::map< int, std::vector<HoleInfo> > funcCheckHoleLayerOverlap();

		// 2.09 钻孔基岩不能在地层之上，返回值 map<地层版本id, 指定版本下分层异常的钻孔列表>
		// TODO: just keep it for time being, and wait to complete it.
		std::map< int, std::vector< HoleInfo > > funcCheckBedRockAboveLayer();

		// 2.10 同版本标准地层不能重复，返回值 map<地层版本id, vector< pair< 指定版本id下重复的地层级别编码, 拥有重复地层编码的地层信息列表 > > >
		std::map< int, std::vector< std::pair< std::string, std::vector< hole_stdStratDesc > > > > funcCheckStdStratOrderRepeat();

		// 2.11 同版本标准地层编码不能重复，返回值 map<地层版本id, vector< pair< 指定版本id下重复的地层编码, 拥有重复地层编码的地层信息列表 > > >
		std::map< int, std::vector< std::pair< std::string, std::vector< hole_stdStratDesc > > > > funcCheckStdStratCodeRepeat();

		// 2.12 标准地层要有类型
		std::vector< hole_stdStratDesc > funcCheckStdStratPossessType();

		// 2.13 检查地层倒转，返回值 map<地层版本id, 指定版本下地层倒转的钻孔列表>
		// 最低检查级别1级，最高检查级别5级
		std::map< int, std::vector< HoleInfo > > funcCheckHoleLayerReverse(int check_level = 5);

		// 2.14 钻孔分层数据只能存在最细的层，返回值 map<地层版本id, 指定版本下地层倒转的钻孔列表>
		std::map< int, std::vector< HoleInfo > > funcCheckHoleLayerOnlyInmost();

		// ***************** the function to check data *** end ********************

	private:
		// 内部结构，降低耦合
		// ************** type defined *** begin **********************
		
		// 钻孔数据表
		typedef struct HoleDataItem
		{
			int m_hole_id;
			int m_prj_id;
			std::string m_hole_code;
			double m_depth;
			double m_x;
			double m_y;
			double m_z;
		} HoleDataItem;
		// 钻孔分层数据表
		typedef struct HoleLayerDataItem
		{
			int id; // 用于修复数据库中的数据的库表主键
			int m_hole_id;
			int m_stratum_id;
			std::string m_stratum_code;
			double m_top_depth;
			double m_bottom_depth;
		} HoleLayerDataItem;
		// 标准地层数据表
		typedef struct StratumDataItem
		{
			int m_std_stratum_id;
			std::string m_stratum_order; // 形如 1-1-1 的地层级别编码 -- LH.2021.08.18 11:34 added.
			std::string m_stratum_level; // 形如 010101 的地层级别编码
			std::string m_stratum_code;
			std::string m_stratum_name;
			int m_stratum_type;
		} StratumDataItem;

		typedef std::map< int, std::list< HoleLayerDataItem* > > MapOfHoleIdToHoleLayerList; // 钻孔id -> 钻孔分层；分层的地层版本可能不同
		typedef std::map< int, std::list<StratumDataItem*> > MapOfStratVerIdToStratum; // 地层版本 -> 地层信息

		// ************** type defined *** end **********************
		
	private:
		void init(const std::vector< HoleInfo> &selected_hole_list_without_layer, const std::vector<HoleLayer> &selected_hole_layer, const std::vector< hole_stdStratDesc > &selected_std_stratum_list);
		// ******************* tool functions *** begin *********************

		void copy(HoleDataItem &target, const HoleInfo &source);
		void copy(HoleInfo &target, const HoleDataItem &source);
		void copy(HoleLayerDataItem &target, const double hole_z, const s3d_BoreHoleLayer &source);
		void copy(s3d_BoreHoleLayer &target, const double hole_z, const HoleLayerDataItem &source);
		void copy(HoleLayerDataItem &target, const double hole_z, const HoleLayer &source);
		void copy(HoleLayer &target, const double hole_z, const HoleLayerDataItem &source);
		void copy(StratumDataItem &target, const s3d_BaseLayer &source);
		void copy(s3d_BaseLayer &target, const StratumDataItem &source);
		void copy(StratumDataItem &target, const hole_stdStratDesc &source);
		void copy(hole_stdStratDesc &target, const StratumDataItem &source);

		std::vector< StratumDataItem*> getStratumDataItemPtrList(int strat_ver_id, std::string strat_code);
		std::vector< std::string > getInmostLayers(int strat_ver_id);
		bool equals(const s3d_BoreHoleLayer &hole_layer, const double hole_z, const HoleLayerDataItem &hole_layer_data_item);

		// ******************* tool functions *** end *********************
	private:
		// **************** data *** begin *****************
	
		std::list< HoleDataItem > m_hole_list;
		std::list< HoleLayerDataItem > m_hole_layer_list;
		std::list< StratumDataItem > m_std_stratum_list;

		MapOfHoleIdToHoleLayerList m_hole_id_to_hole_layer_list;

		MapOfStratVerIdToStratum m_strat_ver_id_to_stratum;

		// **************** data *** end *****************
	};

}

#endif // __LH__HOLE_DATA_INSPECTOR_H__