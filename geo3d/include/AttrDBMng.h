#ifndef __ATTDBMNG_H__
#define __ATTDBMNG_H__

#include <string>
#include <vector>
#include <map>

#include <SQLAPI.h>

#include "s3dAttDBEngine_exp.h"
#include "AttrDBTool.h" // -- LH.2021.08.26 20:52 added. 将被移除
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
			//范围
			gme_rect_2d,        //矩形
			G2D_POLYGON,        //多边形
			G2D_PNTBUFF,        //点缓冲
			X,                  //横坐标
			Y,                  //纵坐标
			PRJ_ID,             //项目ID
			PRJ_NAME,           //项目名称
			PRJ_CODE,           //项目编码
			PNT_ID,				//点ID，与钻孔ID相当，主用于取实验数据。 -- LH.2021.08.17 14:17 added.
			HOLE_ID,            //钻孔ID
			HOLE_CODE,          //钻孔编码
			HOLE_DEPTH,         //钻孔深度
			HOLE_HEIGHT,        //钻孔标高
			HOLE_TYPE,          //钻孔类型
			HOLE_LEVEL,         //钻孔级别
			STDSTRAT_ID,        //标准地层ID
			STDSTRAT_CODE,      //标准地层编号
			STDSTRAT_LEVELCODE, //地层分级编码（如1-1-1）
			Orgn_ID,			//单位ID
			ID,					//ID，部分表的主键
			//类型
			//EXP_TYPE, //试验类型

			//排序
			ASC_ORDER,  //升序
			DESC_ORDER, //降序

			//...
			//警告：添加的时候需要对应添加SQL_CONDITION_STR
		} SQL_CONDITION;

		typedef struct SQL_CONDITION_VAL
		{
			double dbl;
			string str;
			int inter;
			Smart3dMap::gme_rect_2d rect;      //矩形
			std::vector<std::vector<gme_vector2d>> polygon; //多边形
			Smart3dMap::gme_circle circle;     //点缓冲

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
			SQL_CONDITION key;          //条件
			COMPARISON_OPERATOR opType; //操作符
			SQL_CONDITION_VAL val;      //条件值

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
		// 公开构造、析构函数 -- LH.2021.08.26 20:15 changed.
		AttrDBMng();
		virtual ~AttrDBMng();

	protected:
		virtual void initBaseSqlConfiguration() override;

		virtual void sqlGenAddCond(s3dSqlBase* sql_generator_ptr,const BaseSqlConfig &sql_config, std::vector<std::pair<std::string, AutoDataType>> &param_list) override;


	public:
		// 数据库导入预选项，在执行sql前的操作 -- LH.2021.11.23 10:55 added.
		typedef enum PreOption
		{
			NoOption, // 直接插入，什么也不做。
			PreDelete, // 删除后插入
			Append // 在原有数据后追加。注意：追加模式在导入具有外键关系的表时，很大机率会造成外键对应关系改变的后果
		} PreOption;
		// sql执行结果 -- LH.2021.11.23 10:55 added.
		typedef enum ExecuteStatus
		{
			Ok, // 执行成功，可作为返回值
			Unconnected, // 失败，数据库未连接，作为返回值
			SyntaxError, // 失败，sql语法错误，作为返回值
			AnotherError, // 失败，其他原因，作为返回值
			TableError, // 失败，表名为空或字段映射信息为空，作为返回值
			PK_Duplicate // 失败，主键重复
		}ExecuteStatus;
		// 用于数据库导入的字段映射信息 -- LH.2021.11.19 11:50 added.
		typedef struct FieldReflection
		{
			std::string m_source_field_name;
			std::string m_target_field_name; // TODO: 目标表字段的主键、外键身份确定
			DataType m_data_type;
		} FieldReflection;
		// 用于数据库导入的结果反馈信息 -- LH.2021.11.19 14:35 added.
		typedef struct ExecuteResult
		{
			std::string m_table_name; // 目标表名
			std::vector<std::string> m_field_list; // 目标表字段列表，顺序对应值
			// first ==> m_field_list对应的数据值，顺序对应，值来源于源表; second ==> 插入执行结果，取值为 { Ok, PK_Duplicate } 等.
			std::vector<std::pair<std::vector<AutoDataType>, ExecuteStatus>> m_item_value_list;
		}ExecuteResult;
	
	public:
		static AttrDBMng *getSingletonPtr();
		static AttrDBMng &getSingleton();

		// 原接口，废弃，用下一个接口替代。 -- LH.2021.11.23 11:23 recorded.
		static bool transferData(ExecuteResult &exe_result, SAConnection *source_db_ptr, const std::string &source_table_name, SAConnection *target_db_ptr, const std::string &target_table_name, const std::vector<FieldReflection> &field_reflection_list);
		/*
			\brief 用于数据库导入，功能是从源数据库将对应表的对应字段数据传输给目标数据库。
			
			\param exe_result 执行的反馈结果
			\param source_db_ptr 数据源数据库连接
			\param source_table_name 源数据表，要求：不为空串
			\param target_db_ptr 目标数据库连接
			\param target_table_name 目标表，要求不为空串
			\param field_reflection_list 数据源字段与目标库字段的对应关系，约定：不为空，第一个字段为主键
			\param pre_option 数据库导入预选项

			\return 返回值pair<错误类型，来自SAException的异常信息字符串>，first的可能值为：{ Ok, Unconnected, SyntaxError, AnotherError, TableError }

			\note -- LH.2021.11.19 11:56 added.
				  -- LH.2021.11.23 11:38 changed.
		*/
		static std::pair<ExecuteStatus, std::string> transferData(ExecuteResult &exe_result, SAConnection *source_db_ptr, const std::string &source_table_name, SAConnection *target_db_ptr, const std::string &target_table_name, const std::vector<FieldReflection> &field_reflection_list, const PreOption pre_option = NoOption);


		
		//设置当前的数据库连接
		void setCurDbConn(SAConnection *sql_api_con);
		//获取当前的数据库连接
		SAConnection *getCurDbConn();
		
		//打开数据库，并返回数据库连接对象（如果已经连接，则直接返回连接对象）
		virtual __int64 Open(GME_LinkType linkType, std::string dbname, std::string servername = "", std::string portNo = "", const std::string user = "", const std::string psw = "");//打开数据库
		virtual	long Close(); //关闭数据库
		virtual DB_CONN_INFO& getDbInfo();


		
		// Update. -- LH.2021.08.12 17:36 added.
		// Notice: 所有更新函数都调用该函数来实现，可过滤无效条件和更新字段，但必须保证至少有一个条件有效才会执行更新语句。 -- LH.2021.08.12 21:16 written.
		// Notice: 函数内部还有几个TODO工作要做。 -- LH.2021.08.13 16:42 written.
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
		// 说明：x, y, z 将不会被插入。 -- LH.2021.08.23 09:44 written.
		bool insertHoleInfo(const HoleInfo &hole_info, std::string &err_text);
		// Insert HoleLayer. -- LH.2021.08.13 09:17 added.
		// 说明：原来存储高程数据的成员属性将被当作埋深数据处理。-- LH.2021.08.25 15:36 written.
		bool insertHoleLayer(const HoleLayer &hole_layer, std::string &err_text); // waiting to complete. -- LH.2021.08.23 09:57 commented.
		// Insert hole_stdStratVer. -- LH.2021.08.16 14:10 added.
		bool insertStratVer(const hole_stdStratVer &std_strat_ver, std::string &err_text);
		// Insert hole_stdStratDesc. -- LH.2021.08.13 09:19 added.
		bool insertStratDesc(const hole_stdStratDesc &std_strat_desc, std::string &err_text);

		// Delete -- LH.2021.08.16 14:12 added.
		// Notice: 慎用，务必添加删除条件。 -- LH.2021.08.16 14:14 written.
		bool Delete(std::string inner_table_name, std::vector< CONDITION_INFO> * conds, std::string &err_text);
		
		// Delete hole_stdStratVer. -- LH.2021.08.16 14:20 added.
		bool deleteStratVer(std::vector< CONDITION_INFO> * conds, std::string &err_text);
		// Delete hole_stdStratDesc. -- LH.2021.08.16 14:20 added.
		bool deleteStratDesc(std::vector< CONDITION_INFO> * conds, std::string &err_text);

		// 根据内部表名与条件获取单表数据条数
		int getCount(std::string inner_table_name, std::vector<CONDITION_INFO>* conds = nullptr);
		
		// 获取数据库某张表的整数类型字段的最大值 -- LH.2021.10.20 17:34 added.
		// 返回值：-1为异常值；正常值为非负整数。
		long getMaxValueInFields(std::string inner_table_name, std::string inner_field_name);



		/*---------------------------------------基础信息表-------------------------------------------*/
		//档案来源单位表 
		void getBas_DocOrganization(vector<Bas_DocOrganization>& bas_doc_orgn, std::vector<CONDITION_INFO>* conds = nullptr);
		int getBas_DocOrganizationCount(std::vector<CONDITION_INFO>* conds = nullptr);
		
		//1.项目登记表
		void getPrjRegistration(std::vector<Bas_PrjRegistration> &result_list, std::vector<CONDITION_INFO> *conditions = nullptr);
		int getPrjRegistrationCount(std::vector<CONDITION_INFO>* conds = nullptr);
		
		//点位标准化信息表 *
		void getBas_PntStdInfo(vector<Bas_PntStdInfo>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getBas_PntStdInfoCount(std::vector<CONDITION_INFO>* conds = nullptr);
		//-------------------------------------------------
		/*----------------------------------------------------钻孔基本信息类------------------------------------------------*/
		//钻孔登记表 HoleRegister
		void getHoleRegister(vector<HoleRegister>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleRegisterCount(std::vector<CONDITION_INFO>* conds = nullptr);
		
		//2.钻孔类
			//钻孔基本信息表（不带分层）
		void getHole(std::vector<HoleInfo> &result_list, std::vector<CONDITION_INFO> *conditions = nullptr);
		int getHoleCount(std::vector<CONDITION_INFO>* conds = nullptr);
		//钻孔基本信息表+钻孔分层（带分层）
		void getHoleAndHoleLayer(std::vector<HoleInfo> &result_list, std::vector<CONDITION_INFO> *conditions = nullptr);
		
		//钻孔测斜表 HoleInclinat 
		void getHoleInclinat(vector<HoleInclinat>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleInclinatCount(std::vector<CONDITION_INFO>* conds = nullptr);
		//测井基本情况表 HoleLogging
		void getHoleLogging(vector<HoleLogging>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleLoggingCount(std::vector<CONDITION_INFO>* conds = nullptr);
		//-------------------------------------------------
		/*------------------------------------------虚拟钻孔st---------------------------------------------*/
		void getStdStrat_VHole(vector<StdStrat_VHole>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getStdStrat_VHoleCount(std::vector<CONDITION_INFO>* conds = nullptr);
		void getStdStrat_VHolelLayer(vector<StdStrat_VHolelLayer>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getStdStrat_VHolelLayerCount(std::vector<CONDITION_INFO>* conds = nullptr);
		/*------------------------------------------- 浅井探槽类--------------------------------------*/
		
		void getHoleWellSlotLayer(vector<HoleWellSlotLayer>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleWellSlotLayerCount(std::vector<CONDITION_INFO>* conds = nullptr);
		void getHoleDetect(vector<HoleDetect>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleDetectCount(std::vector<CONDITION_INFO>* conds = nullptr);
		/*----------------------------------------物探点线类--------------------------------*/
		void getPhyElecline(vector<PhyElecline>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getPhyEleclineCount(std::vector<CONDITION_INFO>* conds = nullptr);

		void getPhyEardeteline(vector<PhyEardeteline>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getPhyEardetelineCount(std::vector<CONDITION_INFO>* conds = nullptr);

		void getPhyStdPnt(vector<PhyStdPnt>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getPhyStdPntCount(std::vector<CONDITION_INFO>* conds = nullptr);
		/*----------------------------------------钻孔分层类-----------------------------------*/
		//4.标准地层版本表
		void getSysStdStratVer(vector<hole_stdStratVer>& baseLayer, std::vector<CONDITION_INFO> *conds = nullptr);
		int getSysStdStratVerCount(std::vector<CONDITION_INFO>* conds = nullptr);

		//3.标准地层描述表
		void getSysStdStratDesc(vector<hole_stdStratDesc>& baseLayer, std::vector<CONDITION_INFO> *conds = nullptr);
		int getSysStdStratDescCount(std::vector<CONDITION_INFO>* conds = nullptr);
		
		//钻孔分层
		void getHoleLayer(vector<HoleLayer>& holeLayers, std::vector<CONDITION_INFO>* conds = nullptr);
		// 临时，取单表数据(实际上还是联合了点位信息表)，不联合任何表(标准地层描述表)，为钻孔数据检查而设。 -- LH.2021.09.18 18:12 added.
		void getHoleLayerFromSingleTable(vector<HoleLayer>& holeLayers, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleLayerCount(std::vector<CONDITION_INFO>* conds = nullptr);

		void getHoleOrigLayer(vector<HoleOrigLayer>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleOrigLayerCount(std::vector<CONDITION_INFO>* conds = nullptr);
		/*----------------------------------------钻孔结构类-----------------------------------*/
		void getHoleWaterSeal(vector<HoleWaterSeal>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleWaterSealCount(std::vector<CONDITION_INFO>* conds = nullptr);

		void getHoleGravelPack(vector<HoleGravelPack>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleGravelPackCount(std::vector<CONDITION_INFO>* conds = nullptr);

		void getHoleWellPipe(vector<HoleWellPipe>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleWellPipeCount(std::vector<CONDITION_INFO>* conds = nullptr);

		void getHoleAperture(vector<HoleAperture>& prjs, std::vector<CONDITION_INFO>* conds = nullptr);
		int getHoleApertureCount(std::vector<CONDITION_INFO>* conds = nullptr);
		//------------------------------------------------

		//5.样品类
		
		// 通用实验表属性查询接口 -- LH.2021.08.18 14:46 added.
		void getTestColumnsInfo(std::vector< TestColumnsData > &result_list, std::string inner_table, std::vector<std::string> inner_columns, std::vector<CONDITION_INFO>* conds = nullptr);

		// 通用任意表属性查询接口，注意，条件为自写字符串。
		void getColumnsInfo(std::vector< std::vector<AutoDataType> > &result_list, std::string inner_table, std::vector<std::string> inner_columns, std::string conds_clause);

		/*----------------------------------------现场力学试验（原位测试）类-----------------------------------*/
		
		//标准贯入试验记录表 -- LH.2021.08.04 15:29 updated.
		void getEgStdPenetration(vector<EgStdPenetration>& eg_std_penetrat_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getEgStdPenetrationCount(std::vector<CONDITION_INFO>* conds = nullptr);

		//静力触探试验记录表
		void getEgStaticPenetration(vector<EgStaticPenetration>& eg_static_contact_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getEgStaticPenetrationCount(std::vector<CONDITION_INFO>* conds = nullptr);

		//动力触探实验记录表
		void getEgMotDetect(vector<EgMotDetect>& eg_mot_detect_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getEgMotDetectCount(std::vector<CONDITION_INFO>* conds = nullptr);

		//十字板剪切试验记录表
		void getEgShear(vector<EgShear>& eg_mot_detect_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getEgShearCount(std::vector<CONDITION_INFO>* conds = nullptr);

		//波速测试记录表
		void getEgWaveSpeed(vector<EgWaveSpeed>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getEgWaveSpeedCount(std::vector<CONDITION_INFO>* conds = nullptr);

		//旁压实验成果表
		void getEgPMT(vector<EgPMT>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getEgPMTCount(std::vector<CONDITION_INFO>* conds = nullptr);


		//载荷试验成果表 -- LH.2021.08.03 20:50 completed.
		void getEgLoadTest(vector<EgLoadTest>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getEgLoadTestCount(std::vector<CONDITION_INFO>* conds = nullptr);

		/*-----------------------------------现场水理物理实验类-------------------------------*/
		
		// 定义未测试，理论上基本sql正确则无误。  -- LH.2020.08.13 20:31 added.
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


		/*---------------------------------------------------------样品采集类-----------------------------------------------------------*/
		
		// 定义未测试，理论上基本sql正确则无误。  -- LH.2020.08.13 20:31 added.
		void getSCMixSampCompare(vector<SCMixSampCompare>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);

		// 定义未测试，理论上基本sql正确则无误。  -- LH.2020.08.13 20:47 added.
		void getSCRockSample(vector<SCRockSample>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getSCSoilSample(vector<SCSoilSample>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getSCWaterSediment(vector<SCWaterSediment>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getSCSedimentColumn(vector<SCSedimentColumn>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getSCAtmosSample(vector<SCAtmosSample>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getSCWaterSample(vector<SCWaterSample>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getSCWaterSuspend(vector<SCWaterSuspend>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getSCAnimalPlant(vector<SCAnimalPlant>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);


		/*------------------------------------------室内力学测试类---------------------------------------------*/
		
		//常规土工实验成果表 *
		void getINGeotechnicalExp(vector<INGeotechnicalExp>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getINGeotechnicalExpCount(std::vector<CONDITION_INFO>* conds = nullptr);

		//高压固结实验成果表 * -- LH.2021.08.04 14:10 completed.
		void getINConsolidatl(vector<INConsolidatl>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		int getINConsolidatlCount(std::vector<CONDITION_INFO>* conds = nullptr);

		// 定义未测试，理论上基本sql正确则无误。  -- LH.2020.08.13 20:47 added.
		void getINUnconfined(vector<INUnconfined>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINThreeaxis(vector<INThreeaxis>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINDirectShear(vector<INDirectShear>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		void getINDynamicThaxis(vector<INDynamicThaxis>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		
		/*------------------------------------------室内物理化学测试类---------------------------------------------*/

		// 定义未测试，理论上基本sql正确则无误。  -- LH.2020.08.13 20:47 added.
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

		/*------------------------------------------现场测试分析类---------------------------------------------*/

		// 定义未测试，理论上基本sql正确则无误。  -- LH.2020.08.13 20:47 added.
		void getINSceneExpIdent(vector<INSceneExpIdent>& result_list, std::vector<CONDITION_INFO>* conds = nullptr);
		
		/*------------------------------------------地质环境监测类---------------------------------------------*/
		
		// 定义未测试，理论上基本sql正确则无误。  -- LH.2020.08.13 20:47 added.
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
		// TODO: 有什么合适的办法把它作为一个只用调用一次的公共接口呢？ -- LH.2021.09.01 14:28 written.
		//void initMapOfDict();

		bool isSqlAPIConSet();
		void initConds(std::vector<CONDITION_INFO> *conditions = nullptr);

		// 获取实验数据的模板函数 -- LH.2021.08.16 09:40 added.
		template <class ClassName>
		void getTestData(std::string func_name, std::vector<ClassName> &result_list, std::vector<CONDITION_INFO> *conditions = nullptr);


		template<class T>
		void getDataAux(vector<T>& result_list, std::string funcName);

		// TODO: 此函数未实现，暂不使用。
		bool setCondsToSqlGen(std::vector<std::pair<std::string, AutoDataType>> &param_list, s3dSqlBase *sql_gen, std::vector<CONDITION_INFO> *conditions);
	private:
		SAConnection *mCon;

		

	private:
		
		//条件预处理：如果存在范围条件，则需要预处理
		void preProExtentCond(std::vector<CONDITION_INFO>* conds, vector<vector<gme_vector2d>>& polygon);// TODO: waiting to improve.
	
		Smart3dMap::gme_rect_2d getRectByRgn(const vector<vector<gme_vector2d>>& rgns);
		Smart3dMap::gme_rect_2d getRectByPntBuff(const gme_circle& circle);

		//辅助函数
		std::vector<std::string> split(std::string s, std::string delimiter);

		std::vector<CONDITION_INFO> m_Conds;
		vector<vector<gme_vector2d>> m_Polygon;

	
	};




}

#endif // !__ATTDBMNG_H__
