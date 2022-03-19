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
		//���á���ȡ������ʾ����
		static long setSceneScale(); //���漶�ӿ�
		static void setSceneScale(Real x, Real y, Real z); //�ڴ漶�ӿ�
		static void getSceneScale(Real& x, Real& y, Real& z);
	};

	//���������
	void OG_FRAME_DLL splitMatNameToTexcodeAndColor(const string& matName, int& TexCode, int& Color);
	//����ң��Ӱ������һ��������
	void OG_FRAME_DLL getMatNameByRsImage(string& strRsImage, string& strRsMatName);

	long OG_FRAME_DLL OGBroadcastMessage(long nMsg, __int64 wParam, __int64 lParam);
	void OG_FRAME_DLL OGUpdateActiveView();

	//ȡ����ά��������ǰ�򿪵�����Ԫ��
	BOOL OG_FRAME_DLL OGGetOpenElementList(std::vector<Element*> &elemList);

	//������Ϣ���������������ʽ����sprintf��
	void OG_FRAME_DLL OGReleaseTrace(LPCSTR format, ...);//���������Ϣ����������ڡ�
	void OG_FRAME_DLL OGReleaseTraceLog(LPCSTR format, ...);//���������Ϣ����������ڡ�+��Ĭ����־��

	string OG_FRAME_DLL IntToString(int n);
	osg::Vec3d OG_FRAME_DLL calNormal(osg::Vec3d &v1, osg::Vec3d &v2, osg::Vec3d &v3);
	//��Ҫ��ID�����ַ�������ͽ���
	void OG_FRAME_DLL cvtFID2String(OG_Mdl_ID& fID, string& strUrl);
	void OG_FRAME_DLL cvtString2FID(string& strUrl, OG_Mdl_ID& fID);
	//ģ�͸�λ��ʾ
	void OG_FRAME_DLL ResetDisplay();
	//������ת���ƿ���
	void OG_FRAME_DLL ViewRoatateSwitch(bool isChecked = false);

	/* ��ȡ��λʱģ�͵����(�ӵ�)�ľ��� = ģ�ͳߴ磬
	 * ��ģ�������С��������֮��ľ��� / ����� fov����Ұ��������ֵ
	 * distance = dMaxMinRange / sin(viewAngle); */
	OG_FRAME_DLL double GetResetViewAngle();

	OG_FRAME_DLL wchar_t* cvtChar2Wchar(const char* chr);

	/** �򻯼���ͼ��, ͬʱ�����ؼ��㲻���޸�.
	 * @param pOutSurf ���������
	 * @param pOriSurf ԭʼ��
	 * @param protectedPoints �ؼ��������б�
	 * @param dSampleRatio ��ֵ [0,1] */	 
	OG_FRAME_DLL void SimplifySurface(gmeSurface* pOutSurf,gmeSurface* pOriSurf,
									  const std::vector<unsigned int>& protectedPoints = vector<unsigned int>(), 
									  double dSampleRatio = 0.5, double dMaximumError = 4.0, bool bTriStrip = true, bool bSmoothing = true);

	//gme��ɫתosg��ɫ
	OG_FRAME_DLL void GmeClr2OsgClr(osg::Vec4& osgClr,gme_color4& gmeClr);

	//��Ļ����ת��������  ��Ļ����screenPoint(x,y,0)
	osg::Vec3d screen2World(osg::Camera* camera, osg::Vec3d screenPoint);
	
	//��������ת��Ļ����
	osg::Vec3d world2Screen(osg::Camera* camera, osg::Vec3d worldPoint);
	
	class CSceneNode;
	OG_FRAME_DLL CSceneNode* apiHandleGmeFeature(Smart3dMap::gmeFeature* feat, Smart3dMap::OG3DLayer* layer, osg::Vec3 offset = osg::Vec3(0.0f,0.0f,0.0f));//cvtMdl23DLayer�ĸ�������
	OG_FRAME_DLL Smart3dMap::Container* cvtMdl23DLayer(__in Smart3dMap::gmeModel* model, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);
	OG_FRAME_DLL Smart3dMap::Container* cvtMdl23DLayer2(__in Smart3dMap::gmeModel* model,  __in const std::string& guid, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	OG_FRAME_DLL osg::ref_ptr<osg::Group> apiHandleGmeFeatureGroup(Smart3dMap::gmeFeature* feat, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));//cvtMdl23DGroup�ĸ�������
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
	OG_FRAME_DLL void cvtGmeEntity2Geometry(__in Smart3dMap::gmeEntity* entity, __inout std::vector<osg::ref_ptr<osg::Geometry>>& entityGeom, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));//û�е���merge��������

	OG_FRAME_DLL void cvtGmeEntity2Geometry(__in Smart3dMap::gmeEntity* entity, __inout std::vector<osg::ref_ptr<osg::Geometry>>& entityGeom, __inout std::vector<osg::ref_ptr<ogPagedLod>>& vecEntityLod, __in osg::Vec3 offset, __in vector<string> geometryEtcNo);

	OG_FRAME_DLL Smart3dMap::Container* cvtGmeEntity23DLayer(__in Smart3dMap::gmeEntity* entity, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);
	OG_FRAME_DLL Smart3dMap::Container* cvtGmeEntity23DLayerNoMerge(__in Smart3dMap::gmeEntity* entity, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);//û�е���merge��������

	OG_FRAME_DLL osg::ref_ptr<osg::Drawable> cvtGmeGeoPnt2Geometry(__in Smart3dMap::gmeGeoPnt* geopnt, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));
	OG_FRAME_DLL Smart3dMap::Container* cvtGmeGeoPnt23DLayer(__in Smart3dMap::gmeGeoPnt* geopnt, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);

	OG_FRAME_DLL osg::ref_ptr<osg::Drawable> cvtGmeGeoOriPnt2Geometry(__in Smart3dMap::gmeGeoOriPnt* geoOriPnt, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));//����ʽ��ʾ
	OG_FRAME_DLL osg::ref_ptr<osg::Geode> cvtGmeGeoOriPntNew23Geode(osg::Vec4 geoOriPntColor,float lineLength);
	OG_FRAME_DLL CSceneNode* cvtGmeGeoOriPntNewGeometry(__in Smart3dMap::gmeGeoOriPnt* geoOriPnt, osg::Vec3 offset = osg::Vec3(0.0f, 0.0f, 0.0f));//ͼ����ʽ��ʾ
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

	//legendͼ��ָ�룬typeͼ�����ͣ�standardCode�ز���룬standardName�ز����ƣ�materialName���������/��ɫ������
	OG_FRAME_DLL void cvtStandardCode2GmeLegend(__inout Smart3dMap::gmeLegend* legend, __in GME_LEGEND_TYPE type, __in std::vector<std::string>& standardCode,
		__in std::vector<std::string>& standardName, __in std::vector<std::string> materialName);
	OG_FRAME_DLL osg::ref_ptr<osg::Geode> cvtGmeNote2Geode(__in Smart3dMap::gmeNote* note);
	OG_FRAME_DLL osg::ref_ptr<osg::Group> cvtGmeLegend2Group(__in Smart3dMap::gmeLegend* legend);

	OG_FRAME_DLL osg::Vec4 getMaterialDiffuseColor(__in std::string materialName);
	OG_FRAME_DLL std::vector<std::string> getMaterialTexturePath(__in std::string materialName);

	OG_FRAME_DLL Smart3dMap::Container* attachANode23DLayer(__in osg::ref_ptr<osg::Node> node, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL);
	//sysmodelIs false:�ⲿ�ļ���true��ϵͳ�ļ�
	OG_FRAME_DLL Smart3dMap::Container* attachAObjModel23DLayer(__in const std::string& modelPath, __in const std::string& layerName = "", __inout Smart3dMap::Container* parentContiner = NULL, __in bool sysmodelIs = false);

	//isMapGISPrjΪ1��ʾMapGIS�����ļ���Ϊ0��ʾQGIS�����ļ�
	OG_FRAME_DLL Smart3dMap::Container* cvtVectFile2Layer(__in const std::string& prjFilePath, __in const std::string& layerName = "", char isMapGIS = 0, __inout Smart3dMap::Container* parentContiner = NULL);
	//isMapGISEleΪ1��ʾMapGISʸ���ļ�,Ϊ0��ʾshp�ļ�
	OG_FRAME_DLL Smart3dMap::Element* cvtVectFile2Element(__in const std::string& eleFilePath, __in const std::string& eleName = "", char isMapGIS=0, __inout Smart3dMap::Container* parentContiner = NULL);

} // namespace Smart3dMap