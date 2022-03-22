#ifndef __ATTDBMNG_H__
#define __ATTDBMNG_H__

#include <string>
#include <vector>
#include <map>

#include <SQLAPI.h>

#include "s3dAttDBEngine_exp.h"
#include "AttrDBTool.h" // -- LH.2021.08.26 20:52 added. �����Ƴ�
#include "s3dSqlsBase.h"
#include "s3d_AttDbTblFldDef.h"
#include "gmeStru.h"
#include "s3d_AttrDBDef.h"
#include "DBToolBase.h"


using namespace std;
namespace Smart3dMap
{
	class S3D_ATT_DBENGINE_API AttrDBMng:public DBToolBase
	{
	public:


		typedef enum SQL_CONDITION
		{
			//��Χ
			gme_rect_2d,        //����
			G2D_POLYGON,        //�����
			G2D_PNTBUFF,        //�㻺��
			X,                  //������
			Y,                  //������
			PRJ_ID,             //��ĿID
			PRJ_NAME,           //��Ŀ����
			PRJ_CODE,           //��Ŀ����
			PNT_ID,				//��ID�������ID�൱��������ȡʵ�����ݡ� -- LH.2021.08.17 14:17 added.
			HOLE_ID,            //���ID
			HOLE_CODE,          //��ױ���
			HOLE_DEPTH,         //������
			HOLE_HEIGHT,        //��ױ��
			HOLE_TYPE,          //�������
			HOLE_LEVEL,         //��׼���
			STDSTRAT_ID,        //��׼�ز�ID
			STDSTRAT_CODE,      //��׼�ز���
			STDSTRAT_LEVELCODE, //�ز�ּ����루��1-1-1��
			Orgn_ID,			//��λID
			ID,					//ID�����ֱ������
			//����
			//EXP_TYPE, //��������

			//����
			ASC_ORDER,  //����
			DESC_ORDER, //����

			//...
			//���棺��ӵ�ʱ����Ҫ��Ӧ���SQL_CONDITION_STR
		} SQL_CONDITION;

		typedef struct SQL_CONDITION_VAL
		{
			double dbl;
			string str;
			int inter;
			Smart3dMap::gme_rect_2d rect;      //����
			std::vector<std::vector<gme_vector2d>> polygon; //�����
			Smart3dMap::gme_circle circle;     //�㻺��

			SQL_CONDITION_VAL(){}
			SQL_CONDITION_VAL(const SQL_CONDITION_VAL& val) { *this = val; }
			~SQL_CONDITION_VAL() {}


			SQL_CONDITION_VAL(double _dbl) { dbl = _dbl; }
			SQL_CONDITION_VAL(string _str) { str = _str; }
			SQL_CONDITION_VAL(int _inter) { inter = _inter; }
			SQL_CONDITION_VAL(Smart3dMap::gme_rect_2d _rect) { 	rect = _rect; }
			SQL_CONDITION_VAL(std::vector<std::vector<gme_vector2d>> _polygon) { polygon=_polygon; }
			SQL_CONDITION_VAL(Smart3dMap::gme_circle _circle) { circle= _circle; }


		} CONDITION_VAL;

		typedef struct CONDITION_INFO
		{
			SQL_CONDITION key;          //����
			COMPARISON_OPERATOR opType; //������
			SQL_CONDITION_VAL val;      //����ֵ

			CONDITION_INFO(const SQL_CONDITION& _key, const COMPARISON_OPERATOR& _opType, const SQL_CONDITION_VAL& _val)
			{
				key = _key;
				opType = _opType;
				val = _val;
			}

		} CONDITION_INFO;


		typedef struct TestColumnsData
		{
			int m_n_pnt_id;
			double m_d_x;
			double m_d_y;
			double m_d_z;
			std::vector<AutoDataType> m_column_info_list;
		}TestColumnsData;

		typedef std::pair<std::string, AutoDataType> UpdateInfo; // the first string value is the field macro. -- LH.2021.08.23 09:15 updated.

	public:
		// �������졢�������� -- LH.2021.08.26 20:15 changed.
		AttrDBMng();
		virtual ~AttrDBMng();

	protected:
		virtual void initBaseSqlConfiguration() override;

		virtual void sqlGenAddCond(s3dSqlBase* sql_generator_ptr,const BaseSqlConfig &sql_config, std::vector<std::pair<std::string, AutoDataType>> &param_list) override;


	public:
		// ���ݿ⵼��Ԥѡ���ִ��sqlǰ�Ĳ��� -- LH.2021.11.23 10:55 added.
		typedef enum PreOption
		{
			NoOption, // ֱ�Ӳ��룬ʲôҲ������
			PreDelete, // ɾ�������
			Append // ��ԭ�����ݺ�׷�ӡ�ע�⣺׷��ģʽ�ڵ�����������ϵ�ı�ʱ���ܴ���ʻ���������Ӧ��ϵ�ı�ĺ��
		} PreOption;
		// sqlִ�н�� -- LH.2021.11.23 10:55 added.
		typedef enum ExecuteStatus
		{
			Ok, // ִ�гɹ�������Ϊ����ֵ
			Unconnected, // ʧ�ܣ����ݿ�δ���ӣ���Ϊ����ֵ
			SyntaxError, // ʧ�ܣ�sql�﷨������Ϊ����ֵ
			AnotherError, // ʧ�ܣ�����ԭ����Ϊ����ֵ
			TableError, // ʧ�ܣ�����Ϊ�ջ��ֶ�ӳ����ϢΪ�գ���Ϊ����ֵ
			PK_Duplicate // ʧ�ܣ������ظ�
		}ExecuteStatus;
		// �������ݿ⵼����ֶ�ӳ����Ϣ -- LH.2021.11.19 11:50 added.
		typedef struct FieldReflection
		{
			std::string m_source_field_name;
			std::string m_target_field_name; // TODO: Ŀ����ֶε�������������ȷ��
			DataType m_data_type;
		} FieldReflection;
		// �������ݿ⵼��Ľ��������Ϣ -- LH.2021.11.19 14:35 added.
		typedef struct ExecuteResult
		{
			std::string m_table_name; // Ŀ�����
			std::vector<std::string> m_field_list; // Ŀ����ֶ��б�˳���Ӧֵ
			// first ==> m_field_list��Ӧ������ֵ��˳���Ӧ��ֵ��Դ��Դ��; second ==> ����ִ�н����ȡֵΪ { Ok, PK_Duplicate } ��.
			std::vector<std::pair<std::vector<AutoDataType>, ExecuteStatus>> m_item_value_list;
		}ExecuteResult;
	
	public:
		static AttrDBMng *getSingletonPtr();
		static AttrDBMng &getSingleton();

		// ԭ�ӿڣ�����������һ���ӿ������ -- LH.2021.11.23 11:23 recorded.
		static bool transferData(ExecuteResult &exe_result, SAConnection *source_db_ptr, const std::string &source_table_name, SAConnection *target_db_ptr, const std::string &target_table_name, const std::vector<FieldReflection> &field_reflection_list);
		/*
			\brief �������ݿ⵼�룬�����Ǵ�Դ���ݿ⽫��Ӧ��Ķ�Ӧ�ֶ����ݴ����Ŀ�����ݿ⡣
			
			\param exe_result ִ�еķ������
			\param source_db_ptr ����Դ���ݿ�����
			\param source_table_name Դ���ݱ�Ҫ�󣺲�Ϊ�մ�
			\param target_db_ptr Ŀ�����ݿ�����
			\param target_table_name Ŀ���Ҫ��Ϊ�մ�
			\param field_reflection_list ����Դ�ֶ���Ŀ����ֶεĶ�Ӧ��ϵ��Լ������Ϊ�գ���һ���ֶ�Ϊ����
			\param pre_option ���ݿ⵼��Ԥѡ��

			\return ����ֵpair<�������ͣ�����SAException���쳣��Ϣ�ַ���>��first�Ŀ���ֵΪ��{ Ok, Unconnected, SyntaxError, AnotherError, TableError }

			\note -- LH.2021.11.19 11:56 added.
				  -- LH.2021.11.23 11:38 changed.
		*/
		static std::pair<ExecuteStatus, std::string> transferData(ExecuteResult &exe_result, SAConnection *source_db_ptr, const std::string &source_table_name, SAConnection *target_db_ptr, const std::string &target_table_name, const std::vector<FieldReflection> &field_reflection_list, const PreOption pre_option = NoOption);


		
		//���õ�ǰ�����ݿ�����
		void setCurDbConn(SAConnection *sql_api_con);
		//��ȡ��ǰ�����ݿ�����
		SAConnection *getCurDbConn();
		
		//�����ݿ⣬���������ݿ����Ӷ�������Ѿ����ӣ���ֱ�ӷ������Ӷ���
		virtual __int64 Open(GME_LinkType linkType, std::string dbname, std::string servername = "", std::string portNo = "", const std::string user = "", const std::string psw = "");//�����ݿ�
		virtual	long Close(); //�ر����ݿ�
		virtual DB_CONN_INFO& getDbInfo();


		
		// Update. -- LH.2021.08.12 17:36 added.
		// Notice: ���и��º��������øú�����ʵ�֣��ɹ�����Ч�����͸����ֶΣ������뱣֤������һ��������Ч�Ż�ִ�и�����䡣 -- LH.2021.08.12 21:16 written.
		// Notice: �����ڲ����м���TODO����Ҫ���� -- LH.2021.08.13 16:42 written.
		bool update(std::string inner_table_name, std::vector<UpdateInfo> &update_info_list, std::vector< CONDITION_INFO> * conds, std::string &err_text);
		
		// Update HoleLayer. -- LH.2021.08.12 17:00 updated.
		bool updateHoleLayer(std::vector<UpdateInfo>& update_info_list, std::vector< CONDITION_INFO> * conds, std::string &err_text);
		// Update hole_stdStratVer. -- LH.2021.08.16 14:08 added.
		bool updateStratVer(std::vector<UpdateInfo>& update_info_list, std::vector< CONDITION_INFO> * conds, std::string &err_text);
		// Update hole_stdStratDesc. -- LH.2021.08.12 17:20 added.
		bool updateStratDesc(std::vector<UpdateInfo>& update_info_list, std::vector< CONDITION_INFO> * conds, std::string &err_text);

		// Insert.  -- LH.2021.08.13 09:14 added.
		bool insert(std::string inner_table_name, std::vector<UpdateInfo> &update_info_list, std::string &err_text);
		
		// Insert HoleInfo. -- LH.2021.08.13 09:17 added.
		// ˵����x, y, z �����ᱻ���롣 -- LH.2021.08.23 09:44 written.
		bool insertHoleInfo(const HoleInfo &hole_info, std::string &err_text);
		// Insert HoleLayer. -- LH.2021.08.13 09:17 added.
		// ˵����ԭ���洢�߳����ݵĳ�Ա���Խ��������������ݴ���-- LH.2021.08.25 15:36 written.
		bool insertHoleLayer(const HoleLayer &hole_layer, std::string &err_text); // waiting to complete. -- LH.2021.08.23 09:57 commented.
		// Insert hole_stdStratVer. -- LH.2021.08.16 14:10 added.
		bool insertStratVer(const hole_stdStratVer &std_strat_ver, std::string &err_text);
		// Insert hole_stdStratDesc. -- LH.2021.08.13 09:19 added.
		bool insertStratDesc(const hole_stdStratDesc &std_strat_desc, std::string &err_text);

		// Delete -- LH.2021.08.16 14:12 added.
		// Notice: ���ã�������ɾ�������� -- LH.2021.08.16 14:14 written.
		bool Delete(std::string inner_table_name, std::vector< CONDITION_INFO> * conds, std::string &err_text);
		
		// Delete hole_stdStratVer. -- LH.2021.08.16 14:20 added.
		bool deleteStratVer(std::vector< CONDITION_INFO> * conds, std::string &err_text);
		// Delete hole_stdStratDesc. -- LH.2021.08.16 14:20 added.
		bool deleteStratDesc(std::vector< CONDITION_INFO> * conds, std::string &err_text);

		// �����ڲ�������������ȡ������������
		int getCount(std::string inner_table_name, std::vector<CONDITION_INFO>* conds = nullptr);
		
		// ��ȡ���ݿ�ĳ�ű�����������ֶε����ֵ -- LH.2021.10.20 17:34 added.
		// ����ֵ��-1Ϊ�쳣ֵ������ֵΪ�Ǹ�������
		long getMaxValueInFields(std::string inner_table_name, std::string inner_field_name);



		/*---------------------------------------������Ϣ��-------------------------------------------*/
		//������Դ��λ�� 
		void getBas_DocOrganization(vector<Bas_DocOrganization>& bas_doc_orgn, std::vector<CONDITION_INFO>* conds = nullptr);
		int getBas_DocOrganizationCount(std::vector<CONDITION_INFO>* conds = nullptr);
		
		//1.��Ŀ�ǼǱ�
		void getPrjRegistration(std::vector<Bas_PrjRegistration> &result_list, std::vector<CONDITION_INFO> *conditions = nullptr);
		int getPrjRegistrationCount(std::vector<CONDITION_INFO>* conds = nullptr);
		
		//��λ��׼����Ϣ�� *
		void getBas_PntStdInfo(vector<Bas_PntStdInfo>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getBas_PntStdInfoCount(std::vector<CONDITION_INFO>* conds = nullptr);
		//-------------------------------------------------
		/*----------------------------------------------------��׻�����Ϣ��------------------------------------------------*/
		//��׵ǼǱ� HoleRegister
		void getHoleRegister(vector<HoleRegister>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleRegisterCount(std::vector<CONDITION_INFO>* conds = nullptr);
		
		//2.�����
			//��׻�����Ϣ�������ֲ㣩
		void getHole(std::vector<HoleInfo> &result_list, std::vector<CONDITION_INFO> *conditions = nullptr);
		int getHoleCount(std::vector<CONDITION_INFO>* conds = nullptr);
		//��׻�����Ϣ��+��׷ֲ㣨���ֲ㣩
		void getHoleAndHoleLayer(std::vector<HoleInfo> &result_list, std::vector<CONDITION_INFO> *conditions = nullptr);
		
		//��ײ�б�� HoleInclinat 
		void getHoleInclinat(vector<HoleInclinat>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleInclinatCount(std::vector<CONDITION_INFO>* conds = nullptr);
		//�⾮��������� HoleLogging
		void getHoleLogging(vector<HoleLogging>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleLoggingCount(std::vector<CONDITION_INFO>* conds = nullptr);
		//-------------------------------------------------
		/*------------------------------------------�������st---------------------------------------------*/
		void getStdStrat_VHole(vector<StdStrat_VHole>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getStdStrat_VHoleCount(std::vector<CONDITION_INFO>* conds = nullptr);
		void getStdStrat_VHolelLayer(vector<StdStrat_VHolelLayer>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getStdStrat_VHolelLayerCount(std::vector<CONDITION_INFO>* conds = nullptr);
		/*------------------------------------------- ǳ��̽����--------------------------------------*/
		
		void getHoleWellSlotLayer(vector<HoleWellSlotLayer>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleWellSlotLayerCount(std::vector<CONDITION_INFO>* conds = nullptr);
		void getHoleDetect(vector<HoleDetect>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleDetectCount(std::vector<CONDITION_INFO>* conds = nullptr);
		/*----------------------------------------��̽������--------------------------------*/
		void getPhyElecline(vector<PhyElecline>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getPhyEleclineCount(std::vector<CONDITION_INFO>* conds = nullptr);

		void getPhyEardeteline(vector<PhyEardeteline>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getPhyEardetelineCount(std::vector<CONDITION_INFO>* conds = nullptr);

		void getPhyStdPnt(vector<PhyStdPnt>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getPhyStdPntCount(std::vector<CONDITION_INFO>* conds = nullptr);
		/*----------------------------------------��׷ֲ���-----------------------------------*/
		//4.��׼�ز�汾��
		void getSysStdStratVer(vector<hole_stdStratVer>& baseLayer, std::vector<CONDITION_INFO> *conds = nullptr);
		int getSysStdStratVerCount(std::vector<CONDITION_INFO>* conds = nullptr);

		//3.��׼�ز�������
		void getSysStdStratDesc(vector<hole_stdStratDesc>& baseLayer, std::vector<CONDITION_INFO> *conds = nullptr);
		int getSysStdStratDescCount(std::vector<CONDITION_INFO>* conds = nullptr);
		
		//��׷ֲ�
		void getHoleLayer(vector<HoleLayer>& holeLayers, std::vector<CONDITION_INFO>* conds = nullptr);
		// ��ʱ��ȡ��������(ʵ���ϻ��������˵�λ��Ϣ��)���������κα�(��׼�ز�������)��Ϊ������ݼ����衣 -- LH.2021.09.18 18:12 added.
		void getHoleLayerFromSingleTable(vector<HoleLayer>& holeLayers, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleLayerCount(std::vector<CONDITION_INFO>* conds = nullptr);

		void getHoleOrigLayer(vector<HoleOrigLayer>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleOrigLayerCount(std::vector<CONDITION_INFO>* conds = nullptr);
		/*----------------------------------------��׽ṹ��-----------------------------------*/
		void getHoleWaterSeal(vector<HoleWaterSeal>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleWaterSealCount(std::vector<CONDITION_INFO>* conds = nullptr);

		void getHoleGravelPack(vector<HoleGravelPack>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleGravelPackCount(std::vector<CONDITION_INFO>* conds = nullptr);

		void getHoleWellPipe(vector<HoleWellPipe>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleWellPipeCount(std::vector<CONDITION_INFO>* conds = nullptr);

		void getHoleAperture(vector<HoleAperture>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleApertureCount(std::vector<CONDITION_INFO>* conds = nullptr);
		//------------------------------------------------

		//5.��Ʒ��
		
		// ͨ��ʵ������Բ�ѯ�ӿ� -- LH.2021.08.18 14:46 added.
		void getTestColumnsInfo(std::vector< TestColumnsData > &result_list, std::string inner_table, std::vector<std::string> inner_columns, std::vector<CONDITION_INFO>* conds = nullptr);

		// ͨ����������Բ�ѯ�ӿڣ�ע�⣬����Ϊ��д�ַ�����
		void getColumnsInfo(std::vector< std::vector<AutoDataType> > &result_list, std::string inner_table, std::vector<std::string> inner_columns, std::string conds_clause);

		/*----------------------------------------�ֳ���ѧ���飨ԭλ���ԣ���-----------------------------------*/
		
		//��׼���������¼�� -- LH.2021.08.04 15:29 updated.
		void getEgStdPenetration(vector<EgStdPenetration>& eg_std_penetrat_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getEgStdPenetrationCount(std::vector<CONDITION_INFO>* conds = nullptr);

		//������̽�����¼��
		void getEgStaticPenetration(vector<EgStaticPenetration>& eg_static_contact_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getEgStaticPenetrationCount(std::vector<CONDITION_INFO>* conds = nullptr);

		//������̽ʵ���¼��
		void getEgMotDetect(vector<EgMotDetect>& eg_mot_detect_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getEgMotDetectCount(std::vector<CONDITION_INFO>* conds = nullptr);

		//ʮ�ְ���������¼��
		void getEgShear(vector<EgShear>& eg_mot_detect_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getEgShearCount(std::vector<CONDITION_INFO>* conds = nullptr);

		//���ٲ��Լ�¼��
		void getEgWaveSpeed(vector<EgWaveSpeed>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getEgWaveSpeedCount(std::vector<CONDITION_INFO>* conds = nullptr);

		//��ѹʵ��ɹ���
		void getEgPMT(vector<EgPMT>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getEgPMTCount(std::vector<CONDITION_INFO>* conds = nullptr);


		//�غ�����ɹ��� -- LH.2021.08.03 20:50 completed.
		void getEgLoadTest(vector<EgLoadTest>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getEgLoadTestCount(std::vector<CONDITION_INFO>* conds = nullptr);

		/*-----------------------------------�ֳ�ˮ������ʵ����-------------------------------*/
		
		// ����δ���ԣ������ϻ���sql��ȷ������  -- LH.2020.08.13 20:31 added.
		void getHYPumpExp(vector<HYPumpExp>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getHYPumpExpSec(vector<HYPumpExpSec>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getHYPumpDropOff(vector<HYPumpDropOff>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getHYPumpLevelOb(vector<HYPumpLevelOb>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getHYStaticWaterLevel(vector<HYStaticWaterLevel>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getHYRevieWaterLevel(vector<HYRevieWaterLevel>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getHYWaterInjectOb(vector<HYWaterInjectOb>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getHYRechargeExp(vector<HYRechargeExp>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getHYRechargeExpSect(vector<HYRechargeExpSect>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getHYRechargeExpLift(vector<HYRechargeExpLift>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getHYRechargeExpOb(vector<HYRechargeExpOb>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getHYThermalRes(vector<HYThermalRes>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getHYThernakResOb(vector<HYThernakResOb>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getHYWaterSeepageExp(vector<HYWaterSeepageExp>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getHYWaterSeepageExpOb(vector<HYWaterSeepageExpOb>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);


		/*---------------------------------------------------------��Ʒ�ɼ���-----------------------------------------------------------*/
		
		// ����δ���ԣ������ϻ���sql��ȷ������  -- LH.2020.08.13 20:31 added.
		void getSCMixSampCompare(vector<SCMixSampCompare>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);

		// ����δ���ԣ������ϻ���sql��ȷ������  -- LH.2020.08.13 20:47 added.
		void getSCRockSample(vector<SCRockSample>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getSCSoilSample(vector<SCSoilSample>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getSCWaterSediment(vector<SCWaterSediment>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getSCSedimentColumn(vector<SCSedimentColumn>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getSCAtmosSample(vector<SCAtmosSample>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getSCWaterSample(vector<SCWaterSample>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getSCWaterSuspend(vector<SCWaterSuspend>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getSCAnimalPlant(vector<SCAnimalPlant>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);


		/*------------------------------------------������ѧ������---------------------------------------------*/
		
		//��������ʵ��ɹ��� *
		void getINGeotechnicalExp(vector<INGeotechnicalExp>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getINGeotechnicalExpCount(std::vector<CONDITION_INFO>* conds = nullptr);

		//��ѹ�̽�ʵ��ɹ��� * -- LH.2021.08.04 14:10 completed.
		void getINConsolidatl(vector<INConsolidatl>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getINConsolidatlCount(std::vector<CONDITION_INFO>* conds = nullptr);

		// ����δ���ԣ������ϻ���sql��ȷ������  -- LH.2020.08.13 20:47 added.
		void getINUnconfined(vector<INUnconfined>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINThreeaxis(vector<INThreeaxis>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINDirectShear(vector<INDirectShear>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINDynamicThaxis(vector<INDynamicThaxis>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		
		/*------------------------------------------��������ѧ������---------------------------------------------*/

		// ����δ���ԣ������ϻ���sql��ȷ������  -- LH.2020.08.13 20:47 added.
		void getINRockMineIdent(vector<INRockMineIdent>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINClayMineralIdent(vector<INClayMineralIdent>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINGranularityIdent(vector<INGranularityIdent>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINThermophysical(vector<INThermophysical>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINIsotope(vector<INIsotope>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINLuminescence(vector<INLuminescence>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINPollenCombinat(vector<INPollenCombinat>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINFossilCombinat(vector<INFossilCombinat>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINFossilIdent(vector<INFossilIdent>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINPaleomagnetic(vector<INPaleomagnetic>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINWaterCausticity(vector<INWaterCausticity>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINSoilCausticity(vector<INSoilCausticity>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINGeochemicalIdent(vector<INGeochemicalIdent>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);

		/*------------------------------------------�ֳ����Է�����---------------------------------------------*/

		// ����δ���ԣ������ϻ���sql��ȷ������  -- LH.2020.08.13 20:47 added.
		void getINSceneExpIdent(vector<INSceneExpIdent>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		
		/*------------------------------------------���ʻ��������---------------------------------------------*/
		
		// ����δ���ԣ������ϻ���sql��ȷ������  -- LH.2020.08.13 20:47 added.
		void getGeoEnvMonitorDivice(vector<GeoEnvMonitorDivice>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getGeoEnvMonitoLevelTemp(vector<GeoEnvMonitoLevelTemp>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getGeoEnvWeirMonitoFlow(vector<GeoEnvWeirMonitoFlow>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getGeoEnvMonitoSectPnt(vector<GeoEnvMonitoSectPnt>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getGeoEnvWaterExtract(vector<GeoEnvWaterExtract>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getGeoEnvLandSubsidence(vector<GeoEnvLandSubsidence>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getGeoEnvPoreWater(vector<GeoEnvPoreWater>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getGeoEnvGroundStress(vector<GeoEnvGroundStress>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getGeoEnvRainFall(vector<GeoEnvRainFall>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getGeoEnvEvaporation(vector<GeoEnvEvaporation>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);

		/*----------------------------------------------- END ---------------------------------------------*/

	private:


	
	private:
		// TODO: ��ʲô���ʵİ취������Ϊһ��ֻ�õ���һ�εĹ����ӿ��أ� -- LH.2021.09.01 14:28 written.
		//void initMapOfDict();

		bool isSqlAPIConSet();
		void initConds(std::vector<CONDITION_INFO> *conditions = nullptr);

		// ��ȡʵ�����ݵ�ģ�庯�� -- LH.2021.08.16 09:40 added.
		template <class ClassName>
		void getTestData(std::string func_name, std::vector<ClassName> &result_list, std::vector<CONDITION_INFO> *conditions = nullptr);


		template<class T>
		void getDataAux(vector<T>& result_list, std::string funcName);

		// TODO: �˺���δʵ�֣��ݲ�ʹ�á�
		bool setCondsToSqlGen(std::vector<std::pair<std::string, AutoDataType>> &param_list, s3dSqlBase *sql_gen, std::vector<CONDITION_INFO> *conditions);
	private:
		SAConnection *mCon;

		

	private:
		
		//����Ԥ����������ڷ�Χ����������ҪԤ����
		void preProExtentCond(std::vector<CONDITION_INFO>* conds, vector<vector<gme_vector2d>>& polygon);// TODO: waiting to improve.
	
		Smart3dMap::gme_rect_2d getRectByRgn(const vector<vector<gme_vector2d>>& rgns);
		Smart3dMap::gme_rect_2d getRectByPntBuff(const gme_circle& circle);

		//��������
		std::vector<std::string> split(std::string s, std::string delimiter);

		std::vector<CONDITION_INFO> m_Conds;
		vector<vector<gme_vector2d>> m_Polygon;

	
	};




}

#endif // !__ATTDBMNG_H__
