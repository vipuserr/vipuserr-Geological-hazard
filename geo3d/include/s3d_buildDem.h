#pragma once

#include <vector>
#include <set>
using namespace std;

#include "s3d_KerDemOperDef.h"
#include "s3d_KerGeomodelDef.h"
#include "gmeEntity.h"

#include "s3d_explicit_stru.h"


namespace Smart3dMap
{
	class LIB_S3DKERDEMOPER_EXP s3d_build_dem
	{
	public:
		s3d_build_dem();
		~s3d_build_dem();

	public:
		//����dem���ȡ��ĸ߳�ֵ...
		static double get_z_val_by_dem(gme_vector2d* pos, gmeSurface* dem_surf = nullptr);
		//���õر�DEMԼ������������ݽ���Ԥ������������������ݣ�
		static void update_hole_by_dem(vector<s3d_BoreHole>* borehole_data = NULL, gmeSurface* dem_face = NULL);

		// ---------------- demģ�Ͳ����ӿ� ---------------- //
		//�߽����ܺͲ�ֵ...
		static void rgn_density_inpl(vector<gme_vector3d>& rgn, double xInsert, double yInsert, vector<gme_vector3d>& sampleDots);
		//��dem����ȡ�߽��ڵĵ�����...
		static void fetch_pnts_from_dem(vector<gme_vector3d>& rgn, vector<gme_vector3d>& gridDots, vector<gme_vector3d>& resDots);
		//����DEM�߳��������������
		static void get_dem_dots(gme_rect_3d& box, long nx, long ny, vector<double>& DemGridZ, vector<gme_vector3d>& demGridDots);

		//�����ر�DEM����
		//����tiff��ʽ�Ĺ���������dem
		static void build_3d_dem(gmeSurface& demsurf, vector<gme_vector3d>& height_dots, s3d_MdlParam& mdlparam, string rs_file = "");
		//������ɢ���ֵ����dem��������grid���ݻ���DemGridZ
		static void build_3d_dem(gmeSurface& demsurf, vector<gme_vector3d>& discreteDots, gme_rect_3d& box, long nx, long ny, vector<double>& DemGridZ);
		//���ݶ��������͹��������ݣ�����dem����,rgnspaceΪ�߽��ϼ��ܵ���(������Ǽ����Ժ�����򣬿�����rgn_density_inpl�����Ա߽����)
		static void build_3d_dem(gmeSurface& demsurf, vector<gme_vector3d>& rgn, vector<gme_vector3d>& gridDots, string rs_file = "");
		//��demsurf�Ĺ����������вó�һ������
		static void build_3d_dem(gmeSurface& demsurf, vector<gme_vector3d>& rgn, string rs_file = "");


		//���ݸ߳��ļ�/����ͼ�ز����ļ�/Ӱ���ļ����ݵ�, ������������Ϣ�ĵر����ģ��
		static void build_3d_poly_dem(  gmeSurface* outDemSurf,	//���������ģ��,
										s3d_MdlParam* mdlparam,	//��ģ����
										string poly_file = "",	//��ģ��Χ�ļ�(����Ѿ��з�Χ�ˣ��ɴ����ַ���)
										vector<s3d_BaseLayer>*stdStrat=nullptr,//��׼�ز�
										string dem_file="", string dem_fld_name = "",//�����ļ����ֶ�����GeoTiff��shp�ļ���wl�ļ�)
										string geopoly_file="", string geopoly_fld_name = "",//�ز����ļ����ֶ�����shp�ļ���wp�ļ�)
										string rs_file = "");	//ң��Ӱ���ļ�

		//���ݸ߳��ļ�/����ͼ�ز���/Ӱ���ļ����ݵ�, ������������Ϣ�ĵر����ģ��
		static void build_3d_poly_dem(gmeSurface* outDemSurf,	//���������ģ��,
			s3d_MdlParam* mdlparam,	//��ģ����
			string poly_file = "",	//��ģ��Χ�ļ�(����Ѿ��з�Χ�ˣ��ɴ����ַ���)
			vector<s3d_BaseLayer>*stdStrat = nullptr,//��׼�ز�
			string dem_file = "", string dem_fld_name = "",//�����ļ����ֶ�����GeoTiff��shp�ļ���wl�ļ�)
			gm_geomap* stratPolys = nullptr, //�ز����ڴ�ṹ
			string rs_file = "");	//ң��Ӱ���ļ�

		//��������ǻ�...
		static int PolygonTos3d_Surface(s3d_Polygon * pPoly, gmeSurface * pSurf);

	};

}