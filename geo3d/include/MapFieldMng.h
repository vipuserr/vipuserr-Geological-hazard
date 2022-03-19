#pragma once

#include <qgsfields.h>
#include <string>
#include "QString"
#include "s3dSpatialDBEngine_exp.h"
#include "FieldStructDef.h"

using namespace std;

class S3D_SPATIAL_DBENGINE_API MapFieldMng : public QObject
{
	Q_OBJECT

public:
	MapFieldMng();
	~MapFieldMng();

	vector<QgsField> AllFields;

	static QgsField FD_PntNo;
	static QgsField FD_LinNo;
	static QgsField FD_RegNo;

	static QgsField FD_HoleId;
	static QgsField FD_HoleCode;
	static QgsField FD_HoleDepth;

	static QgsField FD_CoordX;
	static QgsField FD_CoordY;
	static QgsField FD_CoordZ;

	static QgsField FD_OriDir;
	static QgsField FD_OriDip;

	static QgsField FD_TerrainCode;

	static QgsField FD_StratCode;
	static QgsField FD_UpStratCode;
	static QgsField FD_DownStratCode;

	static QgsField FD_StratLevel;
	static QgsField FD_UpStratLevel;
	static QgsField FD_DownStratLevel;

	static QgsField FD_StratVer;
	static QgsField FD_StratName;
	static QgsField FD_StratDesc;
	static QgsField FD_StratClr;
	static QgsField FD_StratSubNo;
	static QgsField FD_StratClrNo;

	static QgsField FD_DykeCode;
	static QgsField FD_DykeType;
	static QgsField FD_DykeWidth;

	static QgsField FD_FaultCode;
	static QgsField FD_FaultType;

	static QgsField FD_TopDepth;
	static QgsField FD_BotDepth;

	static QgsField FD_Name;

	// 获取所有的字段，不区分图层
	vector<QgsField>& get_AllFields();

	// 获取各个图层的字段
	const vector<QgsField> get_GM_Strat_FDS() const;
	const vector<QgsField> get_GM_GeoPnt_FDS() const;
	const vector<QgsField> get_GM_GeoLine_FDS() const;
	const vector<QgsField> get_GM_GeoFault_FDS() const;
	const vector<QgsField> get_GM_OriPnt_FDS() const;
	const vector<QgsField> get_GM_Dyke_FDS() const;

	const vector<QgsField> get_SM_Locus_FDS() const;
	const vector<QgsField> get_SM_HolePillar_FDS() const;
	const vector<QgsField> get_SM_GeoReg_FDS() const;
	const vector<QgsField> get_SM_GeoPnt_FDS() const;
	const vector<QgsField> get_SM_OriPnt_FDS() const;
	const vector<QgsField> get_SM_TerrainLine_FDS() const;
	const vector<QgsField> get_SM_GeoLine_FDS() const;
	const vector<QgsField> get_SM_SectRoute_FDS() const;
	const vector<QgsField> get_SM_Dyke_FDS() const;
	const vector<QgsField> get_SM_GeoFault_FDS() const;

	const vector<QgsField> get_BM_StratReg_FDS() const;
	const vector<QgsField> get_BM_StratLine_FDS() const;
	const vector<QgsField> get_Common_FDS() const;

	// 获取钻孔或地层的注记点文件的字段
	const vector<QgsField> get_SM_HoleNote_FDS() const;
	const vector<QgsField> get_SM_StratNote_FDS() const;

	// 获取各个图层的字段的英文名称和中文名称
	map<string, string> get_GM_Strat_FDS_Names();
	map<string, string> get_GM_GeoPnt_FDS_Names();
	map<string, string> get_GM_GeoLine_FDS_Names();
	map<string, string> get_GM_GeoFault_FDS_Names();
	map<string, string> get_GM_OriPnt_FDS_Names();
	map<string, string> get_GM_Dyke_FDS_Names();

	map<string, string> get_SM_Locus_FDS_Names();
	map<string, string> get_SM_GeoReg_FDS_Names();
	map<string, string> get_SM_GeoPnt_FDS_Names();
	map<string, string> get_SM_OriPnt_FDS_Names();
	map<string, string> get_SM_GeoLine_FDS_Names();
	map<string, string> get_SM_Dyke_FDS_Names();
	map<string, string> get_SM_GeoFault_FDS_Names();

	map<string, string> get_BM_StratLine_FDS_Names();

	map<string, string> get_Name_Alias( const vector<QgsField> &flds);
	// 通过图层名称获取字段
	QgsField get_Field_byName(const string& name);

};
