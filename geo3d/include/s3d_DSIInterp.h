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
		vector<long> PassTragles; //�����ε����
		vector<long> NeiOnMesh;	//��õ��ڽ��������������
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
		long		  ID;			//���������ε�ID��	
		short		  TYPE;		//����ߵ����ͣ�ȡֵ��0-��߽��������Σ�1-�ڱ߽���������
		long		  NodeIDs[3];  //��¼�������������
		vector<long>  ControlNodes;//ӵ��   ģ�����Ƶ㣨�ÿ��Ƶ������һֱ�������ϣ�    Լ���ĵ�->�������������ֵ�����ǽ��ģ�����Ƶ�Լ���Ĳ�ֵ����
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
		vector<gme_vector3d> contourLine;//�ȸ��߲������Լ��
		gme_vector3d		pVertex[8];
		bool				m_xyMoveFlag;
	public:
		dm_dsi_Interpolate(void);
		~dm_dsi_Interpolate(void);
		void   setXYMoveFlag(bool bMoveXY = 1);
		void   setattitude(vector<SFIGeoOrientation> &out_attitude);//��ʼ�����в�״��
		short  Copy( gmeSurface* );
		short  CopyAndTopology(gmeSurface*, gme_vector3d*, long, vector<gme_vector3d>& innerList);
		short  CreateTopology( gme_vector3d* , long );
		short  ReadData( const char* );
		short  WhirteData( const char* path );
		//epsΪ�������ε���С����Ĭ�ϣ�step�����ο��Ƶ��Ӱ��̶ȣ��������Ϊ�Ͼࣩ��Ҳ����Ĭ��
		void   DiscreteSmoothInterpolation(gme_vector3d* srcDlist, double eps = 0.001,double step=50.0);
		void   split( string s , string delim , vector<string>& ret);
		void   ToAnySurface( gmeSurface& );
		void   insert_boundary_Pnt(vector<gme_vector3d>& dm_dsi_node, double distance);//3ά�߽�����
		//��ֵ�ڲ���Ĳ�״
		void   Dsi_insert_inner_atti(vector<gme_vector3d> &Boundary_point, vector<SFIGeoOrientation> &geoori_pnts, dm_node & point);
		//�󶨲�״�㣬�󶨵�����õ��������������
		void   SetConstrainToTrgls(gmeSurface &surf, vector<gme_vector3d>& bound_point, vector<SFIGeoOrientation> &out_attitude);
		void   SetConstrainToTrgls_ToFault(gmeSurface &surf, vector<gme_vector3d> fault_line);//�󶨶ϲ��߲�״
		double DistancePntToTral(SFIGeoOrientation* nd, dm_tragle* Tragles);//�㵽�����ξ���

		///�ⲿ�����ӿ�
		//���룺�ѹ��ɵ��棬�߽��ϵ�ԭʼ���Ƶ㣨�ɷǼ��ܣ����ڲ����Ƶ㣬��״�㣻�����ݲ�
		//��������¸����������
		void   Dsi_surf(gmeSurface& surf, vector<gme_vector3d>& Boundary_Point, vector<gme_vector3d>& InnerControl_Pnt, vector<SFIGeoOrientation> &out_attitude, double eps = 0.001);
		//���룺�߽��ϵ�ԭʼ���Ƶ㣨�Ǽ��ܣ����ڲ����Ƶ㣬��״�㣬���ܲ���step�������ݲ�
		//�������ֵ�õĹ⻬��
		void   Dsi_surf_Point(vector<gme_vector3d>& Boundary_Point, vector<gme_vector3d>& InnerControl_Pnt, vector<SFIGeoOrientation> out_attitude,double x_step, double y_step,gmeSurface& surf, double eps = 0.001);

	private:	
		vector<SFIGeoOrientation> attitude;//��״������x,y,z���������
		vector<SFIGeoNormal> m_sfiGeoOrientation;//�ݶ�������x,y,z��dx,dy,dz��
	};

}

