 #pragma once

#include "OGBasDef.h"
#include "gmeEntity.h"
#include "gmeGeoEntity.h"
#include "gmeMdl.h"
#include "gmeOctGeoField.h"
#include "OGElement.h"

#include <vector>
#include <map>

#include "OG3DLayer.h"
#include "OGFrameBaseDef.h"

#include <wchar.h>


typedef std::map<std::string, Smart3dMap::Element*> ElementList;

namespace Smart3dMap {

	class OG_FRAME_DLL gmeMdlIdInfo:public osg::Referenced
	{
	public:
		gmeMdlIdInfo() :osg::Referenced()
		{
			m_gmeFeature = nullptr;
			m_gmeGeometry = nullptr;
		}
		gmeMdlIdInfo(Smart3dMap::gmeFeature* gmeFeature, Smart3dMap::gmeGeometry* gmeGeometry) :osg::Referenced()
		{
			m_gmeFeature = gmeFeature;
			m_gmeGeometry = gmeGeometry;
		}
		~gmeMdlIdInfo() {}

		Smart3dMap::gmeFeature* m_gmeFeature;
		Smart3dMap::gmeGeometry* m_gmeGeometry;
	};

	class OG_FRAME_DLL sceneScale
	{
	public:
		sceneScale(){}
		virtual ~sceneScale(){}

	public:
		//设置、获取场景显示比例
		static long setSceneScale(); //界面级接口
		static void setSceneScale(Real x, Real y, Real z); //内存级接口
		static void getSceneScale(Real& x, Real& y, Real& z);
	};

	//材质名拆分
	void OG_FRAME_DLL splitMatNameToTexcodeAndColor(const string& matName, int& TexCode, int& Color);
	//根据遥感影像生成一个材质名
	void OG_FRAME_DLL getMatNameByRsImage(string& strRsImage, string& strRsMatName);

	long OG_FRAME_DLL OGBroadcastMessage(long nMsg, __int64 wParam, __int64 lParam);
	void OG_FRAME_DLL OGUpdateActiveView();

	//取出二维数据树当前打开的所有元素
	BOOL OG_FRAME_DLL OGGetOpenElementList(std::vector<Element*> &elemList);

	//调试信息输出函数（参数格式参照sprintf）
	void OG_FRAME_DLL OGReleaseTrace(LPCSTR format, ...);//输出调试信息到“输出窗口”
	void OG_FRAME_DLL OGReleaseTraceLog(LPCSTR format, ...);//输出调试信息到“输出窗口”+“默认日志”

	string OG_FRAME_DLL IntToString(int n);
	osg::Vec3d OG_FRAME_DLL calNormal(osg::Vec3d &v1, osg::Vec3d &v2, osg::Vec3d &v3);
	//对要素ID进行字符串编码和解码
	void OG_FRAME_DLL cvtFID2String(OG_Mdl_ID& fID, string& strUrl);
	void OG_FRAME_DLL cvtString2FID(string& strUrl, OG_Mdl_ID& fID);
	//模型复位显示
	void OG_FRAME_DLL ResetDisplay();
	//场景旋转趋势控制
	void OG_FRAME_DLL ViewRoatateSwitch(bool isChecked = false);

	/* 获取复位时模型到相机(视点)的距离 = 模型尺寸，
	 * 即模型最大最小两点坐标之间的距离 / 相机的 fov（视野）的正弦值
	 * distance = dMaxMinRange / sin(viewAngle); */
	OG_FRAME_DLL double GetResetViewAngle();

	OG_FRAME_DLL wchar_t* cvtChar2Wchar(const char* chr);

	/** 简化几何图形, 同时保护关键点不被修改.
	 * @param pOutSurf 处理过的面
	 * @param pOriSurf 原始面
	 * @param protectedPoints 关键点索引列表
	 * @param dSampleRatio 简化值 [0,1] */	 
	OG_FRAME_DLL void SimplifySurface(gmeSurface* pOutSurf,gmeSurface* pOriSurf,
									  const std::vector<unsigned int>& protectedPoints = vector<unsigned int>(), 
									  double dSampleRatio = 0.5, double dMaximumError = 4.0, bool bTriStrip = true, bool bSmoothing = true);

	//gme颜色转osg颜色
	OG_FRAME_DLL void GmeClr2OsgClr(osg::Vec4& osgClr,gme_color4& gmeClr);

	//屏幕坐标转世界坐标  屏幕坐标screenPoint(x,y,0)
	osg::Vec3d screen2World(osg::Camera* camera, osg::Vec3d screenPoint);
	
	//世界坐标转屏幕坐标
	osg::Vec3d world2Screen(osg::Camera* camera, osg::Vec3d worldPoint);
	
	class CSceneNode;
	OG_FRAME_DLL CSceneNode* apiHandleGmeFeature(Smart3dMap::gmeFeature* feat, Smart3dMap::OG3DLayer* layer, osg::Vec3 offset = osg::Vec3(0.0f,0.0f,0.0f));//cvtMdl23DLayer的辅助函数
	OG_FRAME_DLL Smart3dMap::Container* cvtMdl23DLayer(__in Smart3dMap::gmeModel* model, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);
	OG_FRAME_DLL Smart3dMap::Container* cvtMdl23DLayer2(__in Smart3dMap::gmeModel* model,  __in const std::string& guid, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	OG_FRAME_DLL osg::ref_ptr<osg::Group> apiHandleGmeFeatureGroup(Smart3dMap::gmeFeature* feat, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));//cvtMdl23DGroup的辅助函数
	OG_FRAME_DLL osg::ref_ptr<osg::MatrixTransform> cvtMdl23DGroup(__in Smart3dMap::gmeModel* model);

	OG_FRAME_DLL Smart3dMap::Container* cvtFID23DLayer(__in OG_Mdl_ID& fID, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);
	OG_FRAME_DLL Smart3dMap::Container* cvtString23Layer(__in string& strUrl, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	OG_FRAME_DLL osg::ref_ptr<osg::Drawable> cvtGmeCorner2Geometry(__in Smart3dMap::gmeCorner* corner,osg::Vec3 offset = osg::Vec3(0.0f,0.0f,0.0f));
	OG_FRAME_DLL Smart3dMap::Container* cvtGmeCorner23DLayer(__in Smart3dMap::gmeCorner* corner, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	OG_FRAME_DLL osg::ref_ptr<osg::Geometry> cvtGmeLine2Geometry(__in Smart3dMap::gmeLine* line, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));
	OG_FRAME_DLL Smart3dMap::Container* cvtGmeLine23DLayer(__in Smart3dMap::gmeLine* line, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	OG_FRAME_DLL osg::ref_ptr<osg::Geometry> cvtGmeSurface2Geometry(__in Smart3dMap::gmeSurface* surface, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));
	OG_FRAME_DLL Smart3dMap::Container* cvtGmeSurface23DLayer(__in Smart3dMap::gmeSurface* surface, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	OG_FRAME_DLL osg::ref_ptr<osg::Geometry> cvtGmeEntity2Geometry(__in Smart3dMap::gmeEntity* entity);
	OG_FRAME_DLL void cvtGmeEntity2Geometry(__in Smart3dMap::gmeEntity* entity, __inout std::vector<osg::ref_ptr<osg::Geometry>>& entityGeom, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));//没有调用merge函数处理

	OG_FRAME_DLL void cvtGmeEntity2Geometry(__in Smart3dMap::gmeEntity* entity, __inout std::vector<osg::ref_ptr<osg::Geometry>>& entityGeom, __inout std::vector<osg::ref_ptr<ogPagedLod>>& vecEntityLod, __in osg::Vec3 offset, __in vector<string> geometryEtcNo);

	OG_FRAME_DLL Smart3dMap::Container* cvtGmeEntity23DLayer(__in Smart3dMap::gmeEntity* entity, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);
	OG_FRAME_DLL Smart3dMap::Container* cvtGmeEntity23DLayerNoMerge(__in Smart3dMap::gmeEntity* entity, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);//没有调用merge函数处理

	OG_FRAME_DLL osg::ref_ptr<osg::Drawable> cvtGmeGeoPnt2Geometry(__in Smart3dMap::gmeGeoPnt* geopnt, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));
	OG_FRAME_DLL Smart3dMap::Container* cvtGmeGeoPnt23DLayer(__in Smart3dMap::gmeGeoPnt* geopnt, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	OG_FRAME_DLL osg::ref_ptr<osg::Drawable> cvtGmeGeoOriPnt2Geometry(__in Smart3dMap::gmeGeoOriPnt* geoOriPnt, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));//点形式显示
	OG_FRAME_DLL osg::ref_ptr<osg::Geode> cvtGmeGeoOriPntNew23Geode(osg::Vec4 geoOriPntColor,float lineLength);
	OG_FRAME_DLL CSceneNode* cvtGmeGeoOriPntNewGeometry(__in Smart3dMap::gmeGeoOriPnt* geoOriPnt, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));//图形形式显示
	OG_FRAME_DLL Smart3dMap::Container* cvtGmeGeoOriPnt23DLayer(__in Smart3dMap::gmeGeoOriPnt* geoOriPnt, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	OG_FRAME_DLL void cvtGmeGeoLine2Geometry(__in Smart3dMap::gmeGeoLine* geoLine, __inout std::vector<osg::ref_ptr<osg::Geometry>>& geolineGeom, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));
	OG_FRAME_DLL Smart3dMap::Container* cvtGmeGeoLine23DLayer(__in Smart3dMap::gmeGeoLine* geoLine, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	OG_FRAME_DLL void cvtGmeGeoSurface2Geometry(__in Smart3dMap::gmeGeoSurface* geoSurface, __inout std::vector<osg::ref_ptr<osg::Geometry>>& geoSurfaceGeom);
	OG_FRAME_DLL Smart3dMap::Container* cvtGmeGeoSurface23DLayer(__in Smart3dMap::gmeGeoSurface* geoSurface, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	OG_FRAME_DLL osg::ref_ptr<osg::Geometry> cvtGmeSurface2TGeometry(std::vector<gme_vector3d>& polygonSingle, __in Smart3dMap::gme_color4& polygonSingleColor, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));
	OG_FRAME_DLL void cvtGmeGeoSurface2TGeometry(__in std::vector<std::vector<gme_vector3d>>& polygonPnts, __in std::vector<Smart3dMap::gme_color4>& polygonColors, __inout std::vector<osg::ref_ptr<osg::Geometry>>& geoSurfaceTGeom);
	OG_FRAME_DLL Smart3dMap::Container* cvtGmeGeoSurface23DTLayer(__in std::vector<std::vector<gme_vector3d>>& polygonPnts, __in std::vector<Smart3dMap::gme_color4>& polygonColors, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	OG_FRAME_DLL void cvtGmeGeoEntity2Geometry(__in Smart3dMap::gmeGeoEntity* geoEntity, __inout std::vector<osg::ref_ptr<osg::Geometry>>& geoEntityGeom);
	OG_FRAME_DLL Smart3dMap::Container* cvtGmeGeoEntity23DLayer(__in Smart3dMap::gmeGeoEntity* geoEntity, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	OG_FRAME_DLL CSceneNode* cvtGmeGeoField2Group(__in Smart3dMap::gmeGeoField* gmeGeofield,__in Smart3dMap::OG3DLayer* layer);
	OG_FRAME_DLL Smart3dMap::Container* cvtGmeGeoField23DLayer(__in Smart3dMap::gmeGeoField* geoField, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	OG_FRAME_DLL osg::ref_ptr<osg::Group> cvtGmeOctGeoField2Group(__in Smart3dMap::gmeOctGeoField* octGeoField, __in const std::string& attriName, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));
	OG_FRAME_DLL Smart3dMap::Container* cvtGmeOctGeoField23DLayer(__in Smart3dMap::gmeOctGeoField* octGeoField, __in const std::string& attriName, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	//legend图例指针，type图例类型，standardCode地层编码，standardName地层名称，materialName纹理材质名/颜色材质名
	OG_FRAME_DLL void cvtStandardCode2GmeLegend(__inout Smart3dMap::gmeLegend* legend, __in GME_LEGEND_TYPE type, __in std::vector<std::string>& standardCode,
		__in std::vector<std::string>& standardName, __in std::vector<std::string> materialName);
	OG_FRAME_DLL osg::ref_ptr<osg::Geode> cvtGmeNote2Geode(__in Smart3dMap::gmeNote* note);
	OG_FRAME_DLL osg::ref_ptr<osg::Group> cvtGmeLegend2Group(__in Smart3dMap::gmeLegend* legend);

	OG_FRAME_DLL osg::Vec4 getMaterialDiffuseColor(__in std::string materialName);
	OG_FRAME_DLL std::vector<std::string> getMaterialTexturePath(__in std::string materialName);

	OG_FRAME_DLL Smart3dMap::Container* attachANode23DLayer(__in osg::ref_ptr<osg::Node> node, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);
	//sysmodelIs false:外部文件；true：系统文件
	OG_FRAME_DLL Smart3dMap::Container* attachAObjModel23DLayer(__in const std::string& modelPath, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL, __in bool sysmodelIs = false);

	//isMapGISPrj为1表示MapGIS工程文件，为0表示QGIS工程文件
	OG_FRAME_DLL Smart3dMap::Container* cvtVectFile2Layer(__in const std::string& prjFilePath, __in const std::string& layerName = "", char isMapGIS = 0, __inout Smart3dMap::Container* parentContiner = NULL);
	//isMapGISEle为1表示MapGIS矢量文件,为0表示shp文件
	OG_FRAME_DLL Smart3dMap::Element* cvtVectFile2Element(__in const std::string& eleFilePath, __in const std::string& eleName = "", char isMapGIS=0, __inout Smart3dMap::Container* parentContiner = NULL);

} // namespace Smart3dMap