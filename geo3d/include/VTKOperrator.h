#pragma once

#include <string>
#include <gme_vector3.h>
#include "gmeMdl.h"
#include "s3d_baseapplib_global.h"

//读入vtk文件
namespace Smart3dMap
{
	//vtk信息
	struct vtkDataStr
	{
		std::string strVtkTitle;				//文件名称
		gme_vector3i iCellNum;					//格网数目
		gme_vector3d dCellDistance;				//格网距离
		gme_vector3d dOriginPntMin;				//最小点坐标
		int iPointsNum;							//点数量
		std::vector<double> vecAllValue;		//属性值

		vtkDataStr(): strVtkTitle(""),
					  iCellNum(0,0,0),
					  dCellDistance(0.0, 0.0, 0.0),
					  dOriginPntMin(0.0, 0.0, 0.0),
					  iPointsNum(0)
		{
			vecAllValue.clear();
		}
	};

	//无效值、间断点、颜色
	struct BreakAddColorStr
	{
		double dInvalidValue;
		std::vector<double> vecBreakVals;
		std::vector<gme_color4> vecColors;

		BreakAddColorStr() 
		{
			dInvalidValue = 0.0;
			vecBreakVals.clear();
			vecColors.clear();
		}
	};

	class S3D_BASEAPPLIB_EXPORT VTKOperrator
	{
	public:
		/** vtk文件内容说明
			# vtk DataFile Version 2.0			版本
			Volume VTKtitle						文件名称
			ASCII								文件格式（ASCII和BINARY）：ASCII码和二进制
			DATASET STRUCTURED_POINTS			数据集结构格式
			DIMENSIONS  xnum ynum znum			格网数目
			ASPECT_RATIO  xdis ydis zdis		格网距离
			ORIGIN  xmin ymin zmin				原点(最小坐标点)
			POINT_DATA  pointNum				点数
			SCALARS volume_scalars float 1		数据名字，数据类型，数量比较一般为1
			LOOKUP_TABLE default				表名
			value...							数据
		*/

		//获取vtk文件中的信息
		static void ReadVtkData(vtkDataStr& dataPara,const std::string &strFilePath);

		//返回的gmeMdl未添加图例
		static gmeModel* BuildVtkGmeModel(const vtkDataStr& dataPara, BreakAddColorStr& breakPara,const std::string& strMdlName, std::string& strErrorInfo);

	};

}