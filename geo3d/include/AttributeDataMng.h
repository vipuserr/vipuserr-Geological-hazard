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

	// 获取土工试验所有的字段名称
	void get_FieldName(vector<string>& vFiledName);
	//为属性建模获取含有属性值的字段名称
	void get_AttValueFieldName(vector<string>& vFiled);

	/// \brief 给定内部标准表名，返回数值型的属性名称
	/// \param ATT_TABLE_NAME 入口，内部标准的属性表名，由DbTblFldDef.h文件定义
	/// \param vFiledName 出口，返回的数值型属性名称，即数据库中实际记录的属性名称
	/// \return 无
	/// \see get_FieldName()
	void get_FieldName(const string& ATT_TABLE_NAME, vector<string>& vFiledName);

	/// \brief 给定空间范围，查询指定表、指定属性的数据
	/// \param rect 入口，要查询的矩形空间范围
	/// \param ATT_TABLE_NAME 入口，内部标准的属性表名，由DbTblFldDef.h文件定义
	/// \param attFieldName 入口，属性名称，数据库中实际记录的属性名称，通过接口 get_FieldName 取得
	/// \param vAttrib 出口，取回的对应的属性值
	/// \return 无
	/// \see get_FieldName()
	void get_Attrib_byName(const G2D_RECT& rect, const string& ATT_TABLE_NAME, const string& attFieldName, vector<STRU_ATT2>& vAttrib);
	void get_Attrib_byName(const RegDots& rgn, const string& ATT_TABLE_NAME, const string& attFieldName, vector<STRU_ATT2>& vAttrib);

	/// \brief 给定空间范围，查询指定表、指定属性的数据
	/// \param rect 入口，要查询的矩形空间范围，
	/// \param depth 要查询的深度
	/// \param ATT_TABLE_NAME 入口，内部标准的属性表名，由DbTblFldDef.h文件定义
	/// \param attFieldName 入口，属性名称，数据库中实际记录的属性名称，通过接口 get_FieldName() 取得
	/// \param vAttrib 出口，取回的对应的属性值
	/// \return 无
	/// \see get_FieldName()
	void get_Attrib_byName(const G2D_RECT& rect, const double depth, const string& ATT_TABLE_NAME, const string& attFieldName, vector<STRU_ATT2>& vAttrib);
	void get_Attrib_byName(const RegDots& rgn, const double depth, const string& ATT_TABLE_NAME, const string& attFieldName, vector<STRU_ATT2>& vAttrib);

	// 获取矩形框或者多边形内，钻孔的所有属性数据
	void get_Attrib(const G2D_RECT& rect, vector<map<string, string>>& nameValueMap);
	void get_Attrib(const RegDots& rgn, vector<map<string, string>>& nameValueMap);

	// 获取所有钻孔的所有属性值
	void get_Attrib(vector<map<string, string>>& nameValueMap);

	// 通过字段名称获取钻孔的属性值
	void get_Attrib_byName(const G2D_RECT& rect, const string& fieldName, vector<STRU_ATT>& vAttrib);

	// 标贯数据
	void get_StdPenetrationAttrib(const G2D_RECT& rect, vector<map<string, string>>& nameValueMap);
	void get_StdPenetrationAttrib(const RegDots& rgn, vector<map<string, string>>& nameValueMap);

	map<string, string> getEgsoilDictionary();

private:
	SAConnection* mCon;
};