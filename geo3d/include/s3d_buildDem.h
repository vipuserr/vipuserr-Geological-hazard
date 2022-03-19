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
		//根据dem面获取点的高程值...
		static double get_z_val_by_dem(gme_vector2d* pos, gmeSurface* dem_surf = nullptr);
		//利用地表DEM约束，对钻孔数据进行预处理（包括虚拟钻孔数据）
		static void update_hole_by_dem(vector<s3d_BoreHole>* borehole_data = NULL, gmeSurface* dem_face = NULL);

		// ---------------- dem模型操作接口 ---------------- //
		//边界点加密和插值...
		static void rgn_density_inpl(vector<gme_vector3d>& rgn, double xInsert, double yInsert, vector<gme_vector3d>& sampleDots);
		//从dem中提取边界内的点数据...
		static void fetch_pnts_from_dem(vector<gme_vector3d>& rgn, vector<gme_vector3d>& gridDots, vector<gme_vector3d>& resDots);
		//根据DEM高程数据生成网格点
		static void get_dem_dots(gme_rect_3d& box, long nx, long ny, vector<double>& DemGridZ, vector<gme_vector3d>& demGridDots);

		//构建地表DEM曲面
		//根据tiff格式的规则网构建dem
		static void build_3d_dem(gmeSurface& demsurf, vector<gme_vector3d>& height_dots, s3d_MdlParam& mdlparam, string rs_file = "");
		//根据离散点插值构建dem，并返回grid数据缓冲DemGridZ
		static void build_3d_dem(gmeSurface& demsurf, vector<gme_vector3d>& discreteDots, gme_rect_3d& box, long nx, long ny, vector<double>& DemGridZ);
		//根据多边形区域和规则网数据，构建dem曲面,rgnspace为边界上加密点间距(多边形是加密以后的区域，可以用rgn_density_inpl函数对边界加密)
		static void build_3d_dem(gmeSurface& demsurf, vector<gme_vector3d>& rgn, vector<gme_vector3d>& gridDots, string rs_file = "");
		//从demsurf的规则网曲面中裁出一个曲面
		static void build_3d_dem(gmeSurface& demsurf, vector<gme_vector3d>& rgn, string rs_file = "");


		//根据高程文件/地质图地层区文件/影像文件数据等, 构建含地质信息的地表地形模型
		static void build_3d_poly_dem(  gmeSurface* outDemSurf,	//输出的曲面模型,
										s3d_MdlParam* mdlparam,	//建模参数
										string poly_file = "",	//建模范围文件(如果已经有范围了，可传空字符串)
										vector<s3d_BaseLayer>*stdStrat=nullptr,//标准地层
										string dem_file="", string dem_fld_name = "",//地形文件与字段名（GeoTiff或shp文件或wl文件)
										string geopoly_file="", string geopoly_fld_name = "",//地层区文件与字段名（shp文件或wp文件)
										string rs_file = "");	//遥感影像文件

		//根据高程文件/地质图地层区/影像文件数据等, 构建含地质信息的地表地形模型
		static void build_3d_poly_dem(gmeSurface* outDemSurf,	//输出的曲面模型,
			s3d_MdlParam* mdlparam,	//建模参数
			string poly_file = "",	//建模范围文件(如果已经有范围了，可传空字符串)
			vector<s3d_BaseLayer>*stdStrat = nullptr,//标准地层
			string dem_file = "", string dem_fld_name = "",//地形文件与字段名（GeoTiff或shp文件或wl文件)
			gm_geomap* stratPolys = nullptr, //地层区内存结构
			string rs_file = "");	//遥感影像文件

		//多边形三角化...
		static int PolygonTos3d_Surface(s3d_Polygon * pPoly, gmeSurface * pSurf);

	};

}