// Copyright 2021 LH Per. All rights reserved.
/**
 *
 * ������������Ĺ��ܺ��÷�����˵��
 * 
 *
 * Notice: ��׼�����������ֻ�ǰѴ��������ݼ�飬Ȼ�󷵻ؼ�����쳣�����ݼ��ϣ������Ĵ���������֮���ڴ���ǰ�Ĺ����ԡ�
 *
 */

#ifndef __LH__HOLE_DATA_INSPECTOR_H__
#define __LH__HOLE_DATA_INSPECTOR_H__

#include <string>
#include <list> // ������洢����ڲ���Ҫ����
#include <vector> // �������洢���ظ��ⲿ�ļ������
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
			\brief ���캯��

			\param selected_hole_list_without_layer ��Ҫ���ġ������ֲ��������ݼ�����������
			\param selected_hole_layer ��Ҫ������׷ֲ����ݼ�����������
			\param selected_std_stratum_list ��׼�ز�������Ϣ���ݼ���֧�ֻ�϶��ֲ�ͬ�汾�ţ���������
		*/
		HoleDataInspector(const std::vector< HoleInfo> &selected_hole_list_without_layer, const std::vector<HoleLayer> &selected_hole_layer, const std::vector< hole_stdStratDesc > &selected_std_stratum_list);
		~HoleDataInspector();

		/*!
			\brief ���ѹ���ļ��������µ�������ݼ�

			\param selected_hole_list_with_hole_layer ��Ҫ���ġ����ֲ�� �µ� ������ݼ�����������
			\param selected_std_stratum_list �µ� ָ���汾�ŵı�׼�ز�������Ϣ�б���������
		*/
		// TODO: ��δ���ƣ����߿��Բ���Ҫ -- LH.2021.09.27 11:32 commented.
		void updateData(const std::vector< HoleInfo> &selected_hole_list_without_layer, const std::vector<HoleLayer> &selected_hole_layer, const std::vector< hole_stdStratDesc > &selected_std_stratum_list);

		// ***************** the function to check data *** begin ********************
		// 1. ������ݴ�����...
		// 1.1 ������IDΪ��
		std::vector< HoleInfo > funcCheckHoleIdIsNull();

		// 1.2 �����ױ���Ϊ��
		std::vector< HoleInfo > funcCheckHoleCodeIsNull();

		// 1.3 �����׿����Ƿ���ֲ��Ӧ������ֵ vector< pair< �쳣���, pair<��׼�ز�汾, ��Ӧ��׼�ز�汾���������׷ֲ�ĵװ�����> > >
		std::vector< std::pair< HoleInfo, std::pair<long, double> > > funcCheckHoleDepth(int64 sql_api_ptr_int = NULL, bool auto_repaire = false);

		// 1.4 ������Id�ظ�������ֵ vector< pair<���id, ��ͬid������б�> >
		std::vector< std::pair< int, std::vector< HoleInfo > > > funcCheckHoleIdRepeat();

		// 1.5 �����ױ����ظ�������ֵ ...
		std::vector< std::pair< std::string, std::vector< HoleInfo > > > funcCheckHoleCodeRepeat();

		// 1.6 �����������ظ�������ֵ vector< pair<(x, y), ��ͬ���������б�> >
		std::vector< std::pair< std::pair<double, double>, std::vector< HoleInfo > > > funcCheckHoleCoordinateRepeat(int64 sql_api_ptr_int = NULL, bool auto_repaire = false);

		// 2. ��׷ֲ����ݴ�����

		// 2.01 ���������޷ֲ����ݣ�����ֵ map<�ز�汾id, ָ���汾���޷ֲ������б�>
		std::map< int, std::vector<HoleInfo> > funcCheckHoleMissHoleLayer();

		// 2.02 ��׷ֲ�ȱ����׻�����Ϣ // TODO: ????
		std::vector< s3d_BoreHoleLayer > funcCheckHoleLayerMissHole();

		// 2.03 ��׵ĵز����Ϊ��
		std::vector< HoleInfo > funcCheckHoleStratCodeIsNull();
		
		// 2.03.01 ��׵ز�汾Ϊ��
		std::vector< HoleInfo > funcCheckHoleLayerStratumVerIsNull();
		
		// 2.04 ��׵ز�����ڱ�׼�ز����Ҳ���
		std::vector< HoleInfo > funcCheckStratCodeExist();

		// 2.05 ��׵ز�װ�������ȷ�Լ�飨�װ�����Դ���0����
		// ��������ȡֵ��0, ��һ��㶥���Ϊ0; 1, �ǵ�һ��㶥�������0; 2, ����������0
		std::vector< HoleInfo > funcCheckBottomDepthIsRight();

		// 2.05.02 ��׵ز�װ�������ȷ�Լ�� (��׷ֲ�ǵ�һ��Ĳ㶥�������0)
		// ����ֵ��vector< pair< ������ķֲ�, pair<�÷ֲ�Ŀ׿ڱ��, �ڴ�����ȷֵ> > >
		std::vector < std::pair< HoleLayer, std::pair<double, double> > > funcCheckTopDepthIsNULL(int64 sql_api_ptr_int = NULL, bool auto_repaire = false);

		// 2.06 ��������>=�װ�����
		std::vector< HoleInfo > funcCheckTopUnderBottom();

		// 2.07 �����׷ֲ㲻����������ֵ map<�ز�汾id, ָ���汾�·ֲ㲻����������б�>
		std::map< int, std::vector<HoleInfo> > funcCheckHoleLayerBreak();

		// 2.08 �����׷ֲ�ѵ�������ֵ map<�ز�汾id, ָ���汾�·ֲ�ѵ�������б�>
		std::map< int, std::vector<HoleInfo> > funcCheckHoleLayerOverlap();

		// 2.09 ��׻��Ҳ����ڵز�֮�ϣ�����ֵ map<�ز�汾id, ָ���汾�·ֲ��쳣������б�>
		// TODO: just keep it for time being, and wait to complete it.
		std::map< int, std::vector< HoleInfo > > funcCheckBedRockAboveLayer();

		// 2.10 ͬ�汾��׼�ز㲻���ظ�������ֵ map<�ز�汾id, vector< pair< ָ���汾id���ظ��ĵز㼶�����, ӵ���ظ��ز����ĵز���Ϣ�б� > > >
		std::map< int, std::vector< std::pair< std::string, std::vector< hole_stdStratDesc > > > > funcCheckStdStratOrderRepeat();

		// 2.11 ͬ�汾��׼�ز���벻���ظ�������ֵ map<�ز�汾id, vector< pair< ָ���汾id���ظ��ĵز����, ӵ���ظ��ز����ĵز���Ϣ�б� > > >
		std::map< int, std::vector< std::pair< std::string, std::vector< hole_stdStratDesc > > > > funcCheckStdStratCodeRepeat();

		// 2.12 ��׼�ز�Ҫ������
		std::vector< hole_stdStratDesc > funcCheckStdStratPossessType();

		// 2.13 ���ز㵹ת������ֵ map<�ز�汾id, ָ���汾�µز㵹ת������б�>
		// ��ͼ�鼶��1������߼�鼶��5��
		std::map< int, std::vector< HoleInfo > > funcCheckHoleLayerReverse(int check_level = 5);

		// 2.14 ��׷ֲ�����ֻ�ܴ�����ϸ�Ĳ㣬����ֵ map<�ز�汾id, ָ���汾�µز㵹ת������б�>
		std::map< int, std::vector< HoleInfo > > funcCheckHoleLayerOnlyInmost();

		// ***************** the function to check data *** end ********************

	private:
		// �ڲ��ṹ���������
		// ************** type defined *** begin **********************
		
		// ������ݱ�
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
		// ��׷ֲ����ݱ�
		typedef struct HoleLayerDataItem
		{
			int id; // �����޸����ݿ��е����ݵĿ������
			int m_hole_id;
			int m_stratum_id;
			std::string m_stratum_code;
			double m_top_depth;
			double m_bottom_depth;
		} HoleLayerDataItem;
		// ��׼�ز����ݱ�
		typedef struct StratumDataItem
		{
			int m_std_stratum_id;
			std::string m_stratum_order; // ���� 1-1-1 �ĵز㼶����� -- LH.2021.08.18 11:34 added.
			std::string m_stratum_level; // ���� 010101 �ĵز㼶�����
			std::string m_stratum_code;
			std::string m_stratum_name;
			int m_stratum_type;
		} StratumDataItem;

		typedef std::map< int, std::list< HoleLayerDataItem* > > MapOfHoleIdToHoleLayerList; // ���id -> ��׷ֲ㣻�ֲ�ĵز�汾���ܲ�ͬ
		typedef std::map< int, std::list<StratumDataItem*> > MapOfStratVerIdToStratum; // �ز�汾 -> �ز���Ϣ

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