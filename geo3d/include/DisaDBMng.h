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
		mc,             //����
		tybh,			//ͳһ���
		xsbh,			//���б��
		ywbh,			//Ұ����
		wwxcbh,			//���������
		wzs,			//ʡ
		wzds,			//��
		wzx,			//��
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

			SQL_CONDITION_VAL() {}
			SQL_CONDITION_VAL(const SQL_CONDITION_VAL& val) { *this = val; }
			~SQL_CONDITION_VAL() {}


			SQL_CONDITION_VAL(double _dbl) { dbl = _dbl; }
			SQL_CONDITION_VAL(string _str) { str = _str; }
			SQL_CONDITION_VAL(int _inter) { inter = _inter; }
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
		

	public:
		DisaDBMng();
		~DisaDBMng();

		virtual void initBaseSqlConfiguration() override;
		//�ú���������Ӳ�ѯ���������������ϲ�ѯ������
		virtual void sqlGenAddCond(s3dSqlBase* sql_generator_ptr, const BaseSqlConfig &sql_config, std::vector<std::pair<std::string, AutoDataType>> &param_list) override;

	//���ݿ�API��ʼ
	public:
		//��ѯ��ȫ����Ϣ
		void getLandSliderHazard(std::vector<LandSliderHazard>& results);


		//insert
		bool insert(std::string inner_table_name, std::vector<UpdateInfo> &update_info_list, std::string &err_text);
        //update
		bool update(std::string inner_table_name, std::vector<UpdateInfo> &update_info_list, std::vector< CONDITION_INFO> * conds, std::string &err_text);
		//delete
		bool Delete(std::string inner_table_name, std::vector< CONDITION_INFO> * conds, std::string &err_text);


		//���Ӽ�¼
		bool insertLandSliderHazard(const LandSliderHazard &hole_info, std::string &err_text);

		//���¼�¼
		bool updateLandSliderHazard(std::vector<UpdateInfo>& update_info_list, std::vector<CONDITION_INFO> * conds, std::string &err_text);
	    
		//ɾ����¼
		bool deleteLandSliderHazard(std::vector< CONDITION_INFO> * conds, std::string &err_text);

	private:
		SAConnection* m_Con = nullptr;
		std::vector<CONDITION_INFO> m_Conds;
		//void initConds(std::vector<CONDITION_INFO> *conditions = nullptr);
	};

}


