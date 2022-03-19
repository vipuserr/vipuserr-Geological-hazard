#pragma once

#include "s3d_geomodeliolib_global.h"

struct  Model3dtilesPara
{
	//1表示3度分带，2表示6度分带
	enum ZoneType
	{
		ZONETYPE_OF_3DEGREE = 1,
		ZONETYPE_OF_6DEGREE = 2
	};

	//一个二进制文件包含多少个要素(钻孔)，为0则表示所有钻孔放在一个文件中
	int			iBoreholeNumOfBinaryfile;
	//是否需要转换为经纬度坐标，为false则模型所有坐标将不进行转换，为true则会按参数转换坐标
	bool		bIsTransLonlatCoord;
	//坐标是否加带号，true为加带号，false为不加带号
	bool		bIsAddPlus;
	//分带类型，有两个值，为1表示3度分带，为2表示6度分带，默认为3度分带
	ZoneType	iZoneType;
	//投影带的带号，不知道也可以不填，默认值-1表示不知道，带号将根据经度值进行计算
	int			iProjZone;
	//模型所在的大致经度，若proj_zone不为-1，则以proj_zone参数为准，可以不填
	//注：坐标仅在中国境内有效，3度带号范围为(24~46),6度分带带号范围为(13~23)，经度范围为73度~135度
	double		dLongitude;

	Model3dtilesPara()
	{
		iBoreholeNumOfBinaryfile = 0;
		bIsTransLonlatCoord = true;
		bIsAddPlus = false;
		iZoneType = ZONETYPE_OF_3DEGREE;
		iProjZone = -1;
		dLongitude = 114;
	}

};

//导出三维模型 3dtiles 、obj参数
class S3D_GEOMODELIOLIB_EXPORT Export3DMdlProto
{
public:
	enum TargetFormat
	{
		UNKNOWN		= 0,
		TILES_3D	= 1,
		OBJ			= 2
	};

	int m_mdlID;					//模型id
	int m_mdlDbID;					//模型数据库id
	TargetFormat m_format;			//导出类型
	Model3dtilesPara m_3dtilesPara; //导出3dtiles的参数
	bool m_overwrite;
	
	Export3DMdlProto()
	{
		m_mdlID = 0;
		m_mdlDbID = 0;
		m_format = TargetFormat::UNKNOWN;
		m_overwrite = false;
	}
};