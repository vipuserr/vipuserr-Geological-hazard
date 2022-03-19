#pragma once
#include "s3d_DisaDbTblFldDef_exp.h"
#include "S3d_DisaDBDef.h"
#include "DBToolBase.h"
#include <vector>


namespace Smart3dMap
{

	typedef std::pair<std::string, AutoDataType> UpdateInfo;//
	class S3D_DIS_DBENGINE_API DisaDBMng :public DBToolBase
	{
	public:
		static DisaDBMng* getSinglePtr();

		typedef enum SQL_CONDITION
		{
		mc,             //名称
		tybh,			//统一编号
		xsbh,			//县市编号
		ywbh,			//野外编号
		wwxcbh,			//五万详查编号
		wzs,			//省
		wzds,			//市
		wzx,			//县
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

			SQL_CONDITION_VAL() {}
			SQL_CONDITION_VAL(const SQL_CONDITION_VAL& val) { *this = val; }
			~SQL_CONDITION_VAL() {}


			SQL_CONDITION_VAL(double _dbl) { dbl = _dbl; }
			SQL_CONDITION_VAL(string _str) { str = _str; }
			SQL_CONDITION_VAL(int _inter) { inter = _inter; }
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
		

	public:
		DisaDBMng();
		~DisaDBMng();

		virtual void initBaseSqlConfiguration() override;
		//该函数负责添加查询条件（不包含联合查询条件）
		virtual void sqlGenAddCond(s3dSqlBase* sql_generator_ptr, const BaseSqlConfig &sql_config, std::vector<std::pair<std::string, AutoDataType>> &param_list) override;

	//数据库API开始
	public:
		//查询表全部信息
		void getLandSliderHazard(std::vector<LandSliderHazard>& results);


		//insert
		bool insert(std::string inner_table_name, std::vector<UpdateInfo> &update_info_list, std::string &err_text);
        //update
		bool update(std::string inner_table_name, std::vector<UpdateInfo> &update_info_list, std::vector< CONDITION_INFO> * conds, std::string &err_text);
		//delete
		bool Delete(std::string inner_table_name, std::vector< CONDITION_INFO> * conds, std::string &err_text);


		//增加记录
		bool insertLandSliderHazard(const LandSliderHazard &hole_info, std::string &err_text);

		//更新记录
		bool updateLandSliderHazard(std::vector<UpdateInfo>& update_info_list, std::vector<CONDITION_INFO> * conds, std::string &err_text);
	    
		//删除记录
		bool deleteLandSliderHazard(std::vector< CONDITION_INFO> * conds, std::string &err_text);

	private:
		SAConnection* m_Con = nullptr;
		std::vector<CONDITION_INFO> m_Conds;
		//void initConds(std::vector<CONDITION_INFO> *conditions = nullptr);
	};

}


