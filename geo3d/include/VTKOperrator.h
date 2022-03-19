#pragma once

#include <string>
#include <gme_vector3.h>
#include "gmeMdl.h"
#include "s3d_baseapplib_global.h"

//����vtk�ļ�
namespace Smart3dMap
{
	//vtk��Ϣ
	struct vtkDataStr
	{
		std::string strVtkTitle;				//�ļ�����
		gme_vector3i iCellNum;					//������Ŀ
		gme_vector3d dCellDistance;				//��������
		gme_vector3d dOriginPntMin;				//��С������
		int iPointsNum;							//������
		std::vector<double> vecAllValue;		//����ֵ

		vtkDataStr(): strVtkTitle(""),
					  iCellNum(0,0,0),
					  dCellDistance(0.0, 0.0, 0.0),
					  dOriginPntMin(0.0, 0.0, 0.0),
					  iPointsNum(0)
		{
			vecAllValue.clear();
		}
	};

	//��Чֵ����ϵ㡢��ɫ
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
		/** vtk�ļ�����˵��
			# vtk DataFile Version 2.0			�汾
			Volume VTKtitle						�ļ�����
			ASCII								�ļ���ʽ��ASCII��BINARY����ASCII��Ͷ�����
			DATASET STRUCTURED_POINTS			���ݼ��ṹ��ʽ
			DIMENSIONS  xnum ynum znum			������Ŀ
			ASPECT_RATIO  xdis ydis zdis		��������
			ORIGIN  xmin ymin zmin				ԭ��(��С�����)
			POINT_DATA  pointNum				����
			SCALARS volume_scalars float 1		�������֣��������ͣ������Ƚ�һ��Ϊ1
			LOOKUP_TABLE default				����
			value...							����
		*/

		//��ȡvtk�ļ��е���Ϣ
		static void ReadVtkData(vtkDataStr& dataPara,const std::string &strFilePath);

		//���ص�gmeMdlδ���ͼ��
		static gmeModel* BuildVtkGmeModel(const vtkDataStr& dataPara, BreakAddColorStr& breakPara,const std::string& strMdlName, std::string& strErrorInfo);

	};

}