#pragma once

#include "s3dAttDBEngine_exp.h"

#include <QObject>
#include "map"
#include "string"
#include "vector"
#include "SQLAPI.h"

#include "G2DToolDef.h"
#include "gmeEntity.h"

using namespace std;
using namespace Smart3dMap;

struct STRU_ATT_VAL
{
	double startDepth;
	double endDepth;
	double value;

	STRU_ATT_VAL()
	{
		ZeroMemory(this, sizeof(STRU_ATT_VAL));
	}
};

struct STRU_ATT2
{
	long holeId;
	string holeCode;
	gme_vector3d holeTopCoord;
	string attName;
	vector<STRU_ATT_VAL> attValues;

	STRU_ATT2()
	{
		holeId = 0;
		holeCode = "";
		holeTopCoord = {0.0,0.0,0.0};
		attName = "";
		attValues.reserve(0);
	}
};

struct STRU_ATT
{
	long holeId;
	string holeCode;
	gme_vector3d pos;
	string name;
	double value;

	STRU_ATT()
	{
		holeId = 0;
		holeCode = "";
		pos = { 0.0,0.0,0.0 };
		name = "";
		value = 0.0;
	}
};

class S3D_ATT_DBENGINE_API AttributeDataMng
{
private:
	AttributeDataMng();
	~AttributeDataMng();

public:
	static AttributeDataMng* getSingletonPtr();
	static AttributeDataMng& getSingleton();

	// ��ȡ�����������е��ֶ�����
	void get_FieldName(vector<string>& vFiledName);
	//Ϊ���Խ�ģ��ȡ��������ֵ���ֶ�����
	void get_AttValueFieldName(vector<string>& vFiled);

	/// \brief �����ڲ���׼������������ֵ�͵���������
	/// \param ATT_TABLE_NAME ��ڣ��ڲ���׼�����Ա�������DbTblFldDef.h�ļ�����
	/// \param vFiledName ���ڣ����ص���ֵ���������ƣ������ݿ���ʵ�ʼ�¼����������
	/// \return ��
	/// \see get_FieldName()
	void get_FieldName(const string& ATT_TABLE_NAME, vector<string>& vFiledName);

	/// \brief �����ռ䷶Χ����ѯָ����ָ�����Ե�����
	/// \param rect ��ڣ�Ҫ��ѯ�ľ��οռ䷶Χ
	/// \param ATT_TABLE_NAME ��ڣ��ڲ���׼�����Ա�������DbTblFldDef.h�ļ�����
	/// \param attFieldName ��ڣ��������ƣ����ݿ���ʵ�ʼ�¼���������ƣ�ͨ���ӿ� get_FieldName ȡ��
	/// \param vAttrib ���ڣ�ȡ�صĶ�Ӧ������ֵ
	/// \return ��
	/// \see get_FieldName()
	void get_Attrib_byName(const G2D_RECT& rect, const string& ATT_TABLE_NAME, const string& attFieldName, vector<STRU_ATT2>& vAttrib);
	void get_Attrib_byName(const RegDots& rgn, const string& ATT_TABLE_NAME, const string& attFieldName, vector<STRU_ATT2>& vAttrib);

	/// \brief �����ռ䷶Χ����ѯָ����ָ�����Ե�����
	/// \param rect ��ڣ�Ҫ��ѯ�ľ��οռ䷶Χ��
	/// \param depth Ҫ��ѯ�����
	/// \param ATT_TABLE_NAME ��ڣ��ڲ���׼�����Ա�������DbTblFldDef.h�ļ�����
	/// \param attFieldName ��ڣ��������ƣ����ݿ���ʵ�ʼ�¼���������ƣ�ͨ���ӿ� get_FieldName() ȡ��
	/// \param vAttrib ���ڣ�ȡ�صĶ�Ӧ������ֵ
	/// \return ��
	/// \see get_FieldName()
	void get_Attrib_byName(const G2D_RECT& rect, const double depth, const string& ATT_TABLE_NAME, const string& attFieldName, vector<STRU_ATT2>& vAttrib);
	void get_Attrib_byName(const RegDots& rgn, const double depth, const string& ATT_TABLE_NAME, const string& attFieldName, vector<STRU_ATT2>& vAttrib);

	// ��ȡ���ο���߶�����ڣ���׵�������������
	void get_Attrib(const G2D_RECT& rect, vector<map<string, string>>& nameValueMap);
	void get_Attrib(const RegDots& rgn, vector<map<string, string>>& nameValueMap);

	// ��ȡ������׵���������ֵ
	void get_Attrib(vector<map<string, string>>& nameValueMap);

	// ͨ���ֶ����ƻ�ȡ��׵�����ֵ
	void get_Attrib_byName(const G2D_RECT& rect, const string& fieldName, vector<STRU_ATT>& vAttrib);

	// �������
	void get_StdPenetrationAttrib(const G2D_RECT& rect, vector<map<string, string>>& nameValueMap);
	void get_StdPenetrationAttrib(const RegDots& rgn, vector<map<string, string>>& nameValueMap);

	map<string, string> getEgsoilDictionary();

private:
	SAConnection* mCon;
};