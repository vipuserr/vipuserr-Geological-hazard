#ifndef _GM_GEOMODELING_H
#define _GM_GEOMODELING_H

#include "gmeEntity.h"
using namespace Smart3dMap;


#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
using namespace std;



#include "s3d_KerAuxExp.h"
#include "gme_vector2.h"
#include "gme_vector3.h"
#include <float.h>

#include "s3d_idw_interp.h"
#include "s3d_KerGeomodelDef.h"



	typedef unsigned long ulong;
	typedef unsigned int uint;
	typedef unsigned short ushort;

namespace Smart3dMap
{

	const double g_geo_min_thick = 0.1;   // �ز���С���


	

	struct cuboid_temp
	{
		double min_x;
		double max_x;
		double min_y;
		double max_y;
		double min_z;
		double max_z;

		cuboid_temp()
		{
			init();
		}

		void init()
		{
			min_x = min_y = min_z = DBL_MAX;
			max_x = max_y = max_z = -DBL_MAX;
		}
	};

	//==================================gm_insectline=================================
	/// @brief �ཻ�߽ṹ
	//================================================================================
	struct gm_insectline
	{
		gme_vector3d    dot;    // ��������
		int          trino;
		int          pntmin; // �������ǱߵĽ�С����
		int          pntmax; // �������ǱߵĽϴ󶥵�
		gm_insectline()
		{
			trino = -1;
			pntmin = -1;
			pntmax = -1;
		}
	};
	//==================================gm_insectline=================================
	/// @brief �����εı߽ṹ
	//================================================================================
	struct gm_tri_edge
	{
		int pntmin; // ��С�����
		int pntmax; // �ϴ󶥵��
	};

	//==================================gm_tri_top_stru===============================
	/// @brief �����ζ��㼰top�ṹ
	//================================================================================
	struct gm_tri_top_stru
	{
		gm_tri_top_stru()
		{
			ptri = NULL;
			ptopo = NULL;
			trinum = 0;
		}
		gme_triangle       * ptri;
		gme_triangle_top   * ptopo;
		int                 trinum;
	};

	//=================================gm_entity_temp=================================
	/// @brief ��ά����ʱ�ڴ�ṹ
	//================================================================================
	struct gm_entity_temp
	{
		gm_entity_temp()
		{
			psurf = NULL;
			ptopz = NULL;
			pbtmz = NULL;
		}
		gmeSurface * psurf; // ��ά������
		double     * ptopz; // ����Ϊpsurf->GetPointNum()
		double     * pbtmz; // ����Ϊpsurf->GetPointNum()
	};


	//===================

	typedef struct
	{
		gme_vector3d   pdot;  //ԭʼ��¼�еĵ�ַ
		long     i;     //ԭʼ��¼�е�����
	}gm_d3dot;

	typedef struct tri_edge_3d
	{
		long mina; // �����α߶�Ӧ�Ķ������к�
		long maxb; // �����α߶�Ӧ�Ķ������к�
		char bcal; // �Ƿ�����е�
		tri_edge_3d()
		{
			bcal = 0;
		}

	}tri_edge_3d_;

	struct insect_line_3d
	{
		insect_line_3d()
		{
			ltrino = -1;
			lpntmin = -1;
			lpntmax = -1;
		}

		gme_vector3d    dot1;
		long      ltrino;
		long      lpntmin;
		long      lpntmax;
	};

	// ��׷ֲ�ṹ
	class   S3D_KERAUX_EXP inner_holelayer
	{
	public:
		inner_holelayer()
		{
			m_oriStratLevel = "";
			m_dTop = 0.0;
			m_dBottom = 0.0;
			m_flag = 1;
			m_nHoleID = 0;
		}
	public:
		string			m_oriStratLevel;//�ز㼶����
		double			m_dTop;	         //����߳�
		double			m_dBottom;	     //�װ�߳�
		char            m_flag;          //��־��0/1 ����ز�/��ʵ�ز�
		long			m_nHoleID;
	};

	// ��׻�����Ϣ�ṹ
	class S3D_KERAUX_EXP inner_borehole
	{
	public:
		inner_borehole()
		{
			m_dx = 0.0;		 //x����
			m_dy = 0.0;		 //y����
			m_dheight = 0.0; //�׿ڱ��
			m_flag = 1;
			m_nHoleID = 0;
		}
	public:
		long			m_nHoleID;
		double			m_dx;					//x����
		double			m_dy;					//y����
		double			m_dheight;				//�׿ڱ��
		vector<inner_holelayer> m_LayerList; //��׵ز��б�

		char            m_flag;          //��־��0/1 �������/��ʵ���
	};

	//===========================================gm_stratsurface===========================================
	/// @brief �ز�������
	///        �������ȱʧ������ά�ز�������
	//=====================================================================================================
	class S3D_KERAUX_EXP gm_stratsurface
	{
	public:
		gm_stratsurface();
		virtual ~gm_stratsurface();
	public:
		int create_std_surface2(vector<gme_vector3d>& plabel_dots, gmeSurface &out_surf);
		// ��ȡ��׿׿�����
		int getborehole_xyz();
		//����ƽ�����
		int getlayerthick(int index, double &val);
	public:
		s3d_MdlParam                * m_param;           // ��ģ����
		vector<s3d_BoreHole>              * m_pboreholedatas;  // �������
		vector<s3d_BaseLayer>         * m_pstdlayerdatas;  // ��׼�ز�

		int                                m_holenum;         // �����Ŀ
		gme_vector3d                        * m_pholexyz;        // ��׵�λ
		gmeSurface                       * m_dem;             // �ر�dem
		double                             m_adjust_dis;      // ����ϵ��
		vector<double>                     m_thickvec;        // ÿ���ƽ�����
		long                               m_level_num;         // �ز㼶��1/2/3/4 :һ��/����/����/�ļ�
	};

	// �ཻ������
	class S3D_KERAUX_EXP gm_surface_intersection
	{
	public:
		gm_surface_intersection(bool bclip);
		virtual ~gm_surface_intersection();
	public:
		//����ģ��Ͷ��׸߳�
		void set_surface_top_botm_dots(gmeSurface *porisurf, double  *ptop, double  *pbtm);
		//�ز�Ķ���������
		int  get_intersect_surface_new_top_botm_dots(gmeSurface *poutsurf, double ** pouttop, double ** poutbtm, double eps = 0.1);
		//����ת��Ϊ0��Ƚ��д���
		int  get_intersect_surface_new_top_botm_dots2(gmeSurface *poutsurf, double ** pouttop, double ** poutbtm, double eps = 0.1);

	public:
		// ȡ��ģ������������Ǳ�����
		long surf_to_edge(vector<tri_edge_3d> &vecedge, gmeSurface &orisurf, const vector<long>& triIDList);
		void sort_edge(tri_edge_3d& edge);
		int  solve_insect_line(const vector<insect_line_3d>& Insect_dotsvec, vector<insect_line_3d>& temp_out);

	public:
		//���װ�Լ������£���������ཻ��ģ���ع�����
		long solve_insect_by_top_btmctrl(gmeSurface * pori_surf, double *  ptop, double *  pbtm, double *  pcurz,
			gmeSurface * pout_surf, double ** pout_top, double ** pout_btm, double ** pout_cur);

		// ���㽻�߶�
		long cal_insect_dots_pairs(gmeSurface *pori_surf, double * ptop, double * pbtm, vector<long> &vectri,
			double **ppdz, vector<insect_line_3d> &insectdotsvec);

		// �������е������αߡ����Ͻ������У�����ƥ�䣬�������Ǳ�
		long get_all_tri_edge(vector<vector<gme_vector3d>> &triedges, gmeSurface &ori_surf,
			vector<tri_edge_3d> &vecedge, vector<insect_line_3d> &temp_outvec);

		// �������е������αߡ����Ͻ������У�����ƥ�䣬��������
		long update_all_tri_edge(vector<vector<gme_vector3d>> &all_tri_edge, gmeSurface &ori_surf,
			vector<tri_edge_3d> &vecedge, vector<insect_line_3d> &outvec);

		// �����ཻ��
		long cal_insect_dots(insect_line_3d & insect, gmeSurface * psurf, double * pdz);
			
		// ���Ǳ߶Ա�
		int  compare_edge_line_tri(tri_edge_3d * pedge, insect_line_3d * pp2);

		// �������Ǳ�����
		long update_tri_edge_line(vector<gme_vector3d> &vec_line, gme_vector3d &dot);

	private:
		//ȡ����TINģ�������������εıߣ�ȥ���ظ���
		int  get_surface_edges(vector<gm_tri_edge> &edgevec);
		//���㽻�㣬���������ظ��Ķ���
		int  get_intersect_lines(double **ppdzdiffer, vector<gm_insectline> & insect_vec, double eps);
		//ȡ�����㣬�����������ϵĽ��㣬�����������ظ��Ķ���
		int  get_online_insec_lines(const vector<gm_insectline> &instvec, vector<gm_insectline> &tempvec);
		//���������ڵı߸��£����ӵ��б���
		int  update_all_tri_edges(vector<gm_tri_edge> &edge_vec, vector<gm_insectline> &insectvec, vector<vector<gme_vector3d>> &alledges);
		void gm_qsort_edge(gm_tri_edge* edge);
		int  update_bottom_zvalue(gmeSurface * p_new_surf, double * ptopz, double * pbtmz, double eps);

	private:
		bool                      m_clip;//�Ƿ��ཻ����
		double                  * m_ptop;//�����߳�
		double                  * m_pbtm;//�����߳�
		gmeSurface              * m_porisurf;//ԭʼ����ģ��
		double                    m_depthgeo;//�ز���С���
		set<gme_vector3d>			  m_dotSet;//?
	};

	//==========================================gm_surfacetoentity=======================================
	/// @brief ��ά�湹��������
	/// ������ά�ز��湹�������յĵ�����ģ��
	//===================================================================================================

	//===================================gm_queue=====================================
	/// @brief ���в�����
	///
	//================================================================================
	class S3D_KERAUX_EXP  gm_queue
	{
	public:
		gm_queue(int num);
		virtual ~gm_queue();
	public:
		//��ʼ��
		int	 init_queue();

		//����
		int	 reset_queue();

		//�ͷ�����
		void releagm_queue();

		//���
		int	 append(int i);

		//ɾ��
		int	 delete_queue();

		//�Ƿ�Ϊ��
		bool is_empty();

		//�Ƿ�Ϊ��
		bool is_full();

		//ȡ��Ŀ
		int	 get_queue_num();

		//ȡ����
		int	 get_data(int index);

		//ȡ��Ա��Ŀ
		int  get_queue_member_num();
	private:
		int		* m_pdata; //����ָ��
		int		  m_front; //ͷ
		int		  m_end;   //β
		int		  m_num;   //��Ŀ
	};
	class S3D_KERAUX_EXP gm_surface_to_entity //
	{
	public:
		gm_surface_to_entity();
		virtual ~gm_surface_to_entity();
	public:

		//==============================surface_to_entity()=============================
		/// @brief ��ά�湹���ز���ģ��
		/// @param [in]  poutsurf ��ά��
		/// @param [in]  ptopz    ����߳�
		/// @param [in]  pbtmz    ����߳�
		/// @param [out] enyvec   ��ά�ز���
		//================================================================================
		int surface_to_entity(gmeSurface *psurf, double * ptopz, double * pbtmz, vector<gmeEntity*> &enyvec);


		// �ͷ�����
		void releagm_tri_datas(vector<gm_tri_top_stru> &all_surface_vec);

		// ����������������Ƭ
		int spilt_surface_to_sub_tins(gmeSurface* psurf, double* ptopz, double* pbtmz, vector<gm_tri_top_stru> &all_surface_vec);

	private:

		// �����ڲ��������
		int  cal_triangle_flag(char *pdzdis, char *ptriflg, int &idxtri, int* ptriexclusion, bool bonlydot = true);

		// ��ȡһ������
		void get_sub_tin(char *ptriflg, gme_triangle_top *ptop, gm_queue *p_queue, int first_idx, char * pvisit, int* ptriexclusion);

		// ��ȡ��������
		int  get_all_tins(char *ptriflg, gm_tri_top_stru *ptritops, int* ptriexclusion, vector<gm_tri_top_stru>& all_surface_vec, char* pdiffdz = NULL);

		// �����б任����
		int  update_pnt_index(gm_tri_top_stru &surf, vector<gme_vector3d> &vecdots, vector<double> & vectops, vector<double> & vecbtms);

		void create_sur_new(char* pdzflag, char* ptriflag, int validtrinum, vector<gmeEntity*> &enyvec);
	private:
		gmeSurface      * m_psurf; // ����ģ��
		double          * m_topz;  // ����߳�
		double          * m_btmz;  // �װ�߳�
	};


	class S3D_KERAUX_EXP gm_borehole_parse
	{
	public:
		gm_borehole_parse(void);
		virtual ~gm_borehole_parse(void);
	public:

		// ��ʼ���������:
		long initboreholedata(vector<s3d_BoreHole> * pholesvec, vector<s3d_BaseLayer> * pbaselayerordervec);

		// ���ݻ������򣬽����ز㼶����Ŀ
		long getstratumlevelnum();

	public:

		// ���ݵز㼶�𣬶Եز����һ�����������������ļ����ϲ����� (һ���ز㲻��Ҫ����)
		// level_no:1/2/3/4/5/6 ... ��׼������ϲ�
		long cal_lod_stratumlevel_list(long level_no, vector<string> &strlevelcodevec);

		// ���ݵز㼶���������ݽ��кϲ����� === lod_hole_datas ʹ�������������մ���
		long cal_lod_holedata(long level_no, vector<inner_borehole> & lod_hole_datas);

		// ���ݲ�����룬���ֲ��׼���Ϻϲ�
		long combinestratumpriorlevel(long levelnopri, vector<string> &strlevelstratum, vector<long> &sublayer_num_in_layer);

	public:
		// ���������ת��Ϊ�ڲ��ṹ
		long mdlboreholetoinner(vector<inner_borehole> & lod_hole_datas);

		// ����׷ֲ���кϲ�����: ��׷ֲ�Ϊ��С�����˳��
		long combineboreholelayer(vector<inner_holelayer> &layvec);
		long conbineboreholelayer(s3d_BoreHole& borehole);

		// �ز㼶��ת����ʽ "010203040506"��ת��Ϊһ�����룬����Ϊ 010000000000 ת��Ϊ�������룬����Ϊ 010200000000
		//�����1��ʼ������
		long strlevelconvert(string &level, string &out, long level_no);

		// ���ݼ��𣬽���׽ṹ�ϲ�Ϊ�ڲ��ṹ
		long boreholetoinner(s3d_BoreHole & borehole, inner_borehole &inhole, long level);

		// ���ڲ�������ݽ���ȱʧ���봦��, ��͹���°�������Ӧȱʧ���� ����ѡ�� �˴���ʱ��͹����
		long fill_lack_holelayer_tofull(long level_no, vector<string> &strlevelcodevec, vector<inner_borehole> & lod_hole_datas);

		// �����ȱʧ�ز����ݽ��в�ֵ����
		long interpolate_lacklayer_z(vector<inner_borehole> & lod_hole_datas, gm_idw_interp& interpObj);

		// �Բ�ֵ�����������׸߳̽��е�������(ȱʧ�ز��������ĺ�Ȳ��ܵ��ڸõز��ƽ�����)
		long adjustlacklayzvalue(inner_borehole & holelayer);		
		long adjust_interp_lacklayer_z(vector<inner_borehole> & lod_hole_datas);

		// ͳ��������ף�����ÿһ���ز��ƽ�����
		long getlayerthick(vector<inner_borehole> & lod_hole_datas, vector<double> & thickvec);

		//�����������ȡ����idx�ز�ĵװ�����
		long getlayerdata(long idx, bool top, const vector<inner_borehole>& lod_hole_datas, const vector<long>& lastlaynovec, vector<gme_vector3d>& vec);
		long get_surflayer_botm_dots(long idx, vector<inner_borehole> & lod_hole_datas, vector<gme_vector3d> &vec);

		// ��ȡ������ݵĿ׿�����
		long get_hole_top_datas(vector<inner_borehole> & lod_hole_datas, vector<gme_vector3d> &vec);
		// ��ȡ������ݵĿ׵�����
		long get_hole_btm_dots(vector<inner_borehole> & lod_hole_datas, vector<gme_vector3d> &vec, double &mindz);

		// ����������ȡ�������
		string getstrlevelbyindex(long idx, vector<inner_borehole> & lod_hole_datas);
		long getlayerthick(long index, double& thick);

	public:
		vector<double>               m_thickvec;
		vector<s3d_BoreHole>         *m_pholesvec;      // ��׷ֲ���Ϣ
		vector<s3d_BoreHole>         *m_pnewholesvec;   // ��׷ֲ���Ϣ
		vector<s3d_BaseLayer>        *m_pbaselayervec;  // ��׼�ز����
		long                          m_level_num;       // �ز㼶��1/2/3/4/5/... :һ��/����/����/�ļ�...
	};

}

#endif _GM_GEOMODELING_H