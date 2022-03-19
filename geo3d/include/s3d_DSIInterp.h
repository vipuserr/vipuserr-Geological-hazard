#pragma once

#include <vector>
#include <algorithm>
#include <string>

#include "s3d_KerInterpDSIDef.h"

#include "gmeMdl.h"
#include "s3d_SFI.h"



using namespace std;

namespace DSIInterpolate
{
	#define NODE_ALONE   0
	#define NODE_OTHER   1
	#define NODE_CONTROL 2
	#define  TRAGLE_NOMAL 0
	#define CIGMA 0.000000001
    #define DSI_PI       3.14159265358979323846//PI



	class  dm_node
	{
	public:
		long         ID;
		short         Type;
		gme_vector3d        Pnt;
		vector<long> PassTragles; //三角形的序号
		vector<long> NeiOnMesh;	//与该点邻近的其它顶点序号
	public:
		dm_node(void){};
		~dm_node(void){};
		void Init( long , double , double , double );
		bool IsExistsTragleID( long );
		bool IsExistsNeiID( long );
		void ADDPassTragles( long );
		void ADDNeiOnMesh( long );
		void Unique();
	};

	class  dm_tragle
	{
	public:
		long		  ID;			//有向三角形的ID号	
		short		  TYPE;		//有向边的类型，取值：0-外边界上三角形；1-内边界上三角形
		long		  NodeIDs[3];  //记录三角形三个结点
		vector<long>  ControlNodes;//拥有   模糊控制点（该控制点存在于一直网格结点上）    约束的点->所以现在这个插值函数是解决模糊控制点约束的插值函数
	public:
		dm_tragle(void){};
		~dm_tragle(void){};
		void Init( long , long , long , long );
		bool IsExistsNodeID( long );
		void ADDControlNodes( long );
		void Unique();
	};

	typedef sfiGeoOrientation SFIGeoOrientation;
	typedef sfiGeoNormal SFIGeoNormal;

	
	class  S3DKERINTERPDSI_EXP dm_dsi_Interpolate
	{
	public:
		vector<dm_node>    Nodes;
		vector<dm_tragle>  Tragles;
		vector<gme_vector3d> contourLine;//等高线参与何种约束
		gme_vector3d		pVertex[8];
		bool				m_xyMoveFlag;
	public:
		dm_dsi_Interpolate(void);
		~dm_dsi_Interpolate(void);
		void   setXYMoveFlag(bool bMoveXY = 1);
		void   setattitude(vector<SFIGeoOrientation> &out_attitude);//初始化所有产状点
		short  Copy( gmeSurface* );
		short  CopyAndTopology(gmeSurface*, gme_vector3d*, long, vector<gme_vector3d>& innerList);
		short  CreateTopology( gme_vector3d* , long );
		short  ReadData( const char* );
		short  WhirteData( const char* path );
		//eps为迭代两次的最小误差，可默认；step三角形控制点的影响程度（可以理解为断距），也可以默认
		void   DiscreteSmoothInterpolation(gme_vector3d* srcDlist, double eps = 0.001,double step=50.0);
		void   split( string s , string delim , vector<string>& ret);
		void   ToAnySurface( gmeSurface& );
		void   insert_boundary_Pnt(vector<gme_vector3d>& dm_dsi_node, double distance);//3维边界点加密
		//插值内部点的产状
		void   Dsi_insert_inner_atti(vector<gme_vector3d> &Boundary_point, vector<SFIGeoOrientation> &geoori_pnts, dm_node & point);
		//绑定产状点，绑定到距离该点最近的三角形上
		void   SetConstrainToTrgls(gmeSurface &surf, vector<gme_vector3d>& bound_point, vector<SFIGeoOrientation> &out_attitude);
		void   SetConstrainToTrgls_ToFault(gmeSurface &surf, vector<gme_vector3d> fault_line);//绑定断层线产状
		double DistancePntToTral(SFIGeoOrientation* nd, dm_tragle* Tragles);//点到三角形距离

		///外部函数接口
		//输入：已构成的面，边界上的原始控制点（可非加密），内部控制点，产状点；迭代容差
		//输出：重新更新输入的面
		void   Dsi_surf(gmeSurface& surf, vector<gme_vector3d>& Boundary_Point, vector<gme_vector3d>& InnerControl_Pnt, vector<SFIGeoOrientation> &out_attitude, double eps = 0.001);
		//输入：边界上的原始控制点（非加密），内部控制点，产状点，加密步长step；迭代容差
		//输出：插值好的光滑面
		void   Dsi_surf_Point(vector<gme_vector3d>& Boundary_Point, vector<gme_vector3d>& InnerControl_Pnt, vector<SFIGeoOrientation> out_attitude,double x_step, double y_step,gmeSurface& surf, double eps = 0.001);

	private:	
		vector<SFIGeoOrientation> attitude;//产状容器（x,y,z，倾角倾向）
		vector<SFIGeoNormal> m_sfiGeoOrientation;//梯度容器（x,y,z，dx,dy,dz）
	};

}

