#ifndef _GM_APP_IMPLICIT_MDL_H
#define _GM_APP_IMPLICIT_MDL_H

#include "s3d_KernelAppDef.h"
#include <s3d_grbf_surfe_api.h>
#include <s3d_grbf_modelling_parameters.h>

#include "gmeMdl.h"

#include <QtCore/qstring.h>
#include <odbcinst.h>                


using namespace Smart3dMap;

#include <vtkPolyDataNormals.h>
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkPointSet.h>
#include <vtkPolyData.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkXMLImageDataWriter.h>
#include <vtkStructuredGrid.h>
#include <vtkImageData.h>
#include <vtkDoubleArray.h>
#include <vtkPointData.h>
#include <vtkCellArray.h>
#include <vtkVertex.h>
#include <vtkMarchingCubes.h>
#include <vtkNew.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkDataSetMapper.h>
#include <vtkPointGaussianMapper.h>
#include <vtkPolyDataMapper.h>
#include <vtkImageSliceMapper.h>
#include <vtkImageSlice.h>
#include <vtkImageMapToColors.h>
#include <vtkImageProperty.h>
#include <vtkImageActor.h>
#include <vtkLookupTable.h>
#include <vtkArrowSource.h>
#include <vtkAssignAttribute.h>
#include <vtkGlyph3D.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkCellPicker.h>
#include <vtkImagePlaneWidget.h>
#include<osgDB/ReadFile>
#include<osg/Node>
#include<osg/Geode>
#include<osg/ComputeBoundsVisitor>
#include<osg/BoundingBox>
#include<osg/ClipNode>
#include<osg/BlendColor>
#include<osg/BlendFunc>
#include<osg/AlphaFunc>
#include<osgGA/GUIEventHandler>

#define vtkRenderingCore_AUTOINIT2(vtkInteractionStyle,vtkRenderingOpenGL2)


class GM_KERNEL_APP_EXP Geo_Builder 
{
private:
	
	vtkSmartPointer<vtkImageData> grid_;
	InputParameters getGUIParameters();
	void progress(const float &progress_value);
	bool evaluation_completed_;
	void build_constraints_from_input_files();
	RECT m_rec;//范围
	Eigen::MatrixXd outsclardata;//属性场数据
	map<int, stdColor> stdColors;//level/颜色
	map<string, int> layerCode;//地层名称/level
	map<int, string> CodeLayer;//level/地层名称

	osg::ref_ptr<osg::Group> IncisionGroup;
	Extra_Model_Parameter ExModPara;//额外建模参数
public:
	Surfe_API *surfe;
	void CreateGRBFInterpolantFromGUIParameters();//界面
	void InitializeGRBFInterpolantObject(const int &mode) { surfe = new Surfe_API(mode); }//初始化
	void LoadConstraintsFromFiles();//从文件中读取数据

	void SetInterfaceDataFile(const char *interfaceFile);//读取界面点文件路径
	void SetPlanarDataFile(const char *planarFile);//读取产状点文件路径
	void SetTangentDataFile(const char *tangentFile);//读取切线点文件路径
	void SetInequalityDataFile(const char *inequalityFile);//读取不等式约束文件路径

	vtkSmartPointer<vtkImageData> GetEvaluatedGrid();
	vtkSmartPointer<vtkPolyData> GetIsoSurfaces();
	vtkSmartPointer<vtkPolyData> GetInterfaceConstraints();
	vtkSmartPointer<vtkPolyData> GetPlanarConstraints();
	vtkSmartPointer<vtkPolyData> GetTangentConstraints();
	vtkSmartPointer<vtkPolyData> GetInequalityConstraints();
	//写vtk
	void WriteVTKInterfaceConstraints(const char *filename);
	void WriteVTKPlanarConstraints(const char *filename);
	void WriteVTKTangentConstraints(const char *filename);
	void WriteVTKInequalityConstraints(const char *filename);
	void WriteVTKEvaluationGrid(const char *filename);
	void WriteVTKIsoSurfaces(const char *filename);

public:
	Geo_Builder() {
		surfe = nullptr;
		evaluation_completed_ = false;
	}
	~Geo_Builder();
	InputParameters input_;
	//读取数据库
	void readRBFData(QString m_FileName, InputConstraints& inputdata);

	bool ReadHoleAccess(QString m_FileName, InputConstraints& inputdata);

	void setrange(RECT rec);
	void SetExtraParameter(Extra_Model_Parameter& para);
	//写属性场
	void WriteGMEScalarField();

	//构建规则网格
	//分辨率 
	void BuildRegularGrid(const double &resolution, const double &xy_percent_padding = 0);
	void BuildRegularGrid(const double &xy_percent_padding = 0);
	void BuildRegularGrid(
		const double &zmin, const double &zmax,
		const double &resolution, const double &xy_percent_padding = 0
	);
	void BuildRegularGrid(
		const double &xmin, const double &xmax,
		const double &ymin, const double &ymax,
		const double &zmin, const double &zmax,
		const double &resolution);
	void BuildRegularGrid1(long nx, long ny, long nz, const double xyz_percent_padding);

	//inputdata:四类输入点的结构体
	//parameters：插值参数结构体
	//grid：网格化参数
	//scalar_field:属性场
	bool WriteGMEScalarFields(InputConstraints& inputdata, Parameters_ parameters, RegularGrid grid);

	bool BuildtoInoutdata(InputConstraints& inputdata);

	void Prepareforcut(InputConstraints & inputdata, Parameters_ parameters, RegularGrid grid, vector<Smart3dMap::gmeSurface>& InterSurfaces, vector<gmeSurface>& BoxSurface);

	void Buildlayer(gmeSurface& Topsurface, gmeSurface& Bottomsurface, gmeEntity& sidesurface, gmeEntity& outlayer);
	void CutSurface(InputConstraints & inputdata, Parameters_ parameters, RegularGrid grid, vector<Smart3dMap::gmeSurface>& InterSurfaces, vector<gmeSurface>& BoxSurface);
	void BuildEntity(InputConstraints & inputdata, Parameters_ parameters, RegularGrid grid, vector<Smart3dMap::gmeSurface>& InterSurfaces);
	//写等值面
	void WriteGMEIsoSruface();
	void WriteSurfacesToGme(InputConstraints & inputdata, Parameters_ parameters, RegularGrid grid);
	bool WriteGMEIsoSrufaces(Eigen::MatrixXd& scalar_field, RegularGrid grid, double value, Smart3dMap::gmeSurface& surface);
	long SurfacetoEntity(Smart3dMap::gmeSurface& TopSurface, Smart3dMap::gmeSurface& BottomSurface, vector<gmeSurface>& SideSurface, Smart3dMap::gmeEntity& SingleEntity);
	long SurfacetoEntity(vector<Smart3dMap::gmeSurface>& InterSurfaces, vector<gmeSurface>& BoxSurface);
	//写矢量场
	void WriteGMEVectorField();
	bool WriteGMEVectorFields(InputConstraints& inputdata, Parameters_ parameters, RegularGrid grid, Eigen::MatrixXd& vector_field);

	//可视化vtk数据
	void VisualizeVTKData();
};


#endif _GM_APP_IMPLICIT_MDL_H