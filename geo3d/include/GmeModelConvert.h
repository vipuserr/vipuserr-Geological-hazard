#pragma once
#include "gmeMdl.h"
#include "s3d_geomodeliolib_global.h"
namespace Smart3dMap
{
	class S3D_GEOMODELIOLIB_EXPORT GmeModelConvert
	{
	public:
		GmeModelConvert();
		~GmeModelConvert();
		static long Gme2ObjModel(gmeModel &model, std::string outputPath, int IsIntegrate = 1);
		static long TsurfModel2Gme(std::string inputPath, std::string mdlName, bool DSI_Smooth_Flag = false);//路径是文件夹
		static long Obj2GmeModel(std::vector<std::string> inputPathList, std::string mdlName, bool DSI_Smooth_Flag = false);
	};
}
