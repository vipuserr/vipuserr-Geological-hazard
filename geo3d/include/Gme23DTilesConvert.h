#pragma once
#include "gmeMdl.h"
#include "GeoGme23DTiles.h"
namespace Smart3dMap
{
	class GEOGME23DTILES_EXPORT Gme23DTilesConvert
	{
	public:
		//outputPath:模型转换输出路径为模型根文件夹目录
		//boreholeNumOfABin:一个二进制文件包含多少个要素(钻孔)，为0则表示所有钻孔放在一个文件中

		//isTransFlag:是否需要转换为经纬度坐标，为false则模型所有坐标将不进行转换，为true则会按参数转换坐标
		//isAddZoneNo:坐标是否加带号，true为加带号，false为不加带号
		//zone_type: 分带类型，有两个值，为1表示3度分带，为2表示6度分带，默认为3度分带
		//proj_zone: 投影带的带号，不知道也可以不填，默认值-1表示不知道，带号将根据经度值进行计算
		//longitude: 模型所在的大致经度，若proj_zone不为-1，则以proj_zone参数为准，可以不填
		//注意：坐标仅在中国境内有效，3度带号范围为(24~46),6度分带带号范围为(13~23)，经度范围为73度~135度
		static void convert(gmeModel & geomdl, std::string outputPath,
			int boreholeNumOfABin = 0, int boreholeLodNum = 0,
			bool isTransFlag = true, int srcCoordSys = 0, bool isAddZoneNo = false,
			int zone_type = 1, int proj_zone = -1, double longitude = 114);
		static void combineTilesetFiles(std::vector<std::string> jsonpaths, std::string outputPath);//可以合并分块的模型json文件，以统一显式
	};
}


