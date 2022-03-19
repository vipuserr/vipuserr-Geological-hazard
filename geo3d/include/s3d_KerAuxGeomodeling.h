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

	const double g_geo_min_thick = 0.1;   // 地层最小厚度


	

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
	/// @brief 相交线结构
	//================================================================================
	struct gm_insectline
	{
		gme_vector3d    dot;    // 交点坐标
		int          trino;
		int          pntmin; // 所在三角边的较小顶点
		int          pntmax; // 所在三角边的较大顶点
		gm_insectline()
		{
			trino = -1;
			pntmin = -1;
			pntmax = -1;
		}
	};
	//==================================gm_insectline=================================
	/// @brief 三角形的边结构
	//================================================================================
	struct gm_tri_edge
	{
		int pntmin; // 较小顶点号
		int pntmax; // 较大顶点号
	};

	//==================================gm_tri_top_stru===============================
	/// @brief 三角形顶点及top结构
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
	/// @brief 三维体临时内存结构
	//================================================================================
	struct gm_entity_temp
	{
		gm_entity_temp()
		{
			psurf = NULL;
			ptopz = NULL;
			pbtmz = NULL;
		}
		gmeSurface * psurf; // 三维面数据
		double     * ptopz; // 长度为psurf->GetPointNum()
		double     * pbtmz; // 长度为psurf->GetPointNum()
	};


	//===================

	typedef struct
	{
		gme_vector3d   pdot;  //原始记录中的地址
		long     i;     //原始记录中的索引
	}gm_d3dot;

	typedef struct tri_edge_3d
	{
		long mina; // 三角形边对应的顶点序列号
		long maxb; // 三角形边对应的顶点序列号
		char bcal; // 是否计算中点
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

	// 钻孔分层结构
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
		string			m_oriStratLevel;//地层级别编号
		double			m_dTop;	         //顶板高程
		double			m_dBottom;	     //底板高程
		char            m_flag;          //标志：0/1 虚拟地层/真实地层
		long			m_nHoleID;
	};

	// 钻孔基本信息结构
	class S3D_KERAUX_EXP inner_borehole
	{
	public:
		inner_borehole()
		{
			m_dx = 0.0;		 //x坐标
			m_dy = 0.0;		 //y坐标
			m_dheight = 0.0; //孔口标高
			m_flag = 1;
			m_nHoleID = 0;
		}
	public:
		long			m_nHoleID;
		double			m_dx;					//x坐标
		double			m_dy;					//y坐标
		double			m_dheight;				//孔口标高
		vector<inner_holelayer> m_LayerList; //钻孔地层列表

		char            m_flag;          //标志：0/1 虚拟钻孔/真实钻孔
	};

	//===========================================gm_stratsurface===========================================
	/// @brief 地层面数据
	///        钻孔数据缺失处理、三维地层面生成
	//=====================================================================================================
	class S3D_KERAUX_EXP gm_stratsurface
	{
	public:
		gm_stratsurface();
		virtual ~gm_stratsurface();
	public:
		int create_std_surface2(vector<gme_vector3d>& plabel_dots, gmeSurface &out_surf);
		// 获取钻孔孔口坐标
		int getborehole_xyz();
		//计算平均层厚
		int getlayerthick(int index, double &val);
	public:
		s3d_MdlParam                * m_param;           // 建模参数
		vector<s3d_BoreHole>              * m_pboreholedatas;  // 钻孔数据
		vector<s3d_BaseLayer>         * m_pstdlayerdatas;  // 标准地层

		int                                m_holenum;         // 钻孔数目
		gme_vector3d                        * m_pholexyz;        // 钻孔点位
		gmeSurface                       * m_dem;             // 地表dem
		double                             m_adjust_dis;      // 调整系数
		vector<double>                     m_thickvec;        // 每层的平均厚度
		long                               m_level_num;         // 地层级别：1/2/3/4 :一级/二级/三级/四级
	};

	// 相交处理类
	class S3D_KERAUX_EXP gm_surface_intersection
	{
	public:
		gm_surface_intersection(bool bclip);
		virtual ~gm_surface_intersection();
	public:
		//设置模板和顶底高程
		void set_surface_top_botm_dots(gmeSurface *porisurf, double  *ptop, double  *pbtm);
		//地层的顶底曲面求交
		int  get_intersect_surface_new_top_botm_dots(gmeSurface *poutsurf, double ** pouttop, double ** poutbtm, double eps = 0.1);
		//将求交转化为0厚度进行处理
		int  get_intersect_surface_new_top_botm_dots2(gmeSurface *poutsurf, double ** pouttop, double ** poutbtm, double eps = 0.1);

	public:
		// 取出模板面的所有三角边数据
		long surf_to_edge(vector<tri_edge_3d> &vecedge, gmeSurface &orisurf, const vector<long>& triIDList);
		void sort_edge(tri_edge_3d& edge);
		int  solve_insect_line(const vector<insect_line_3d>& Insect_dotsvec, vector<insect_line_3d>& temp_out);

	public:
		//顶底板约束情况下，处理层面相交、模板重构更新
		long solve_insect_by_top_btmctrl(gmeSurface * pori_surf, double *  ptop, double *  pbtm, double *  pcurz,
			gmeSurface * pout_surf, double ** pout_top, double ** pout_btm, double ** pout_cur);

		// 计算交线对
		long cal_insect_dots_pairs(gmeSurface *pori_surf, double * ptop, double * pbtm, vector<long> &vectri,
			double **ppdz, vector<insect_line_3d> &insectdotsvec);

		// 根据所有的三角形边、边上交点序列，进行匹配，更新三角边
		long get_all_tri_edge(vector<vector<gme_vector3d>> &triedges, gmeSurface &ori_surf,
			vector<tri_edge_3d> &vecedge, vector<insect_line_3d> &temp_outvec);

		// 根据所有的三角形边、边上交点序列，进行匹配，更新三角
		long update_all_tri_edge(vector<vector<gme_vector3d>> &all_tri_edge, gmeSurface &ori_surf,
			vector<tri_edge_3d> &vecedge, vector<insect_line_3d> &outvec);

		// 计算相交线
		long cal_insect_dots(insect_line_3d & insect, gmeSurface * psurf, double * pdz);
			
		// 三角边对比
		int  compare_edge_line_tri(tri_edge_3d * pedge, insect_line_3d * pp2);

		// 更新三角边数据
		long update_tri_edge_line(vector<gme_vector3d> &vec_line, gme_vector3d &dot);

	private:
		//取出主TIN模板中所有三角形的边，去除重复边
		int  get_surface_edges(vector<gm_tri_edge> &edgevec);
		//计算交点，包含上下重复的顶点
		int  get_intersect_lines(double **ppdzdiffer, vector<gm_insectline> & insect_vec, double eps);
		//取出交点，仅仅包含边上的交点，不包括上下重复的顶点
		int  get_online_insec_lines(const vector<gm_insectline> &instvec, vector<gm_insectline> &tempvec);
		//将交点所在的边更新，并加到列表中
		int  update_all_tri_edges(vector<gm_tri_edge> &edge_vec, vector<gm_insectline> &insectvec, vector<vector<gme_vector3d>> &alledges);
		void gm_qsort_edge(gm_tri_edge* edge);
		int  update_bottom_zvalue(gmeSurface * p_new_surf, double * ptopz, double * pbtmz, double eps);

	private:
		bool                      m_clip;//是否相交处理
		double                  * m_ptop;//顶面点高程
		double                  * m_pbtm;//底面点高程
		gmeSurface              * m_porisurf;//原始曲面模板
		double                    m_depthgeo;//地层最小厚度
		set<gme_vector3d>			  m_dotSet;//?
	};

	//==========================================gm_surfacetoentity=======================================
	/// @brief 三维面构建地质体
	/// 负责将三维地层面构建成最终的地质体模型
	//===================================================================================================

	//===================================gm_queue=====================================
	/// @brief 队列操作类
	///
	//================================================================================
	class S3D_KERAUX_EXP  gm_queue
	{
	public:
		gm_queue(int num);
		virtual ~gm_queue();
	public:
		//初始化
		int	 init_queue();

		//重置
		int	 reset_queue();

		//释放数据
		void releagm_queue();

		//添加
		int	 append(int i);

		//删除
		int	 delete_queue();

		//是否为空
		bool is_empty();

		//是否为满
		bool is_full();

		//取数目
		int	 get_queue_num();

		//取数据
		int	 get_data(int index);

		//取成员数目
		int  get_queue_member_num();
	private:
		int		* m_pdata; //数据指针
		int		  m_front; //头
		int		  m_end;   //尾
		int		  m_num;   //数目
	};
	class S3D_KERAUX_EXP gm_surface_to_entity //
	{
	public:
		gm_surface_to_entity();
		virtual ~gm_surface_to_entity();
	public:

		//==============================surface_to_entity()=============================
		/// @brief 三维面构建地层体模型
		/// @param [in]  poutsurf 三维面
		/// @param [in]  ptopz    顶面高程
		/// @param [in]  pbtmz    底面高程
		/// @param [out] enyvec   三维地层体
		//================================================================================
		int surface_to_entity(gmeSurface *psurf, double * ptopz, double * pbtmz, vector<gmeEntity*> &enyvec);


		// 释放数据
		void releagm_tri_datas(vector<gm_tri_top_stru> &all_surface_vec);

		// 将面分离成若干子面片
		int spilt_surface_to_sub_tins(gmeSurface* psurf, double* ptopz, double* pbtmz, vector<gm_tri_top_stru> &all_surface_vec);

	private:

		// 计算内部标记数组
		int  cal_triangle_flag(char *pdzdis, char *ptriflg, int &idxtri, int* ptriexclusion, bool bonlydot = true);

		// 获取一个子面
		void get_sub_tin(char *ptriflg, gme_triangle_top *ptop, gm_queue *p_queue, int first_idx, char * pvisit, int* ptriexclusion);

		// 获取所有子面
		int  get_all_tins(char *ptriflg, gm_tri_top_stru *ptritops, int* ptriexclusion, vector<gm_tri_top_stru>& all_surface_vec, char* pdiffdz = NULL);

		// 点序列变换过程
		int  update_pnt_index(gm_tri_top_stru &surf, vector<gme_vector3d> &vecdots, vector<double> & vectops, vector<double> & vecbtms);

		void create_sur_new(char* pdzflag, char* ptriflag, int validtrinum, vector<gmeEntity*> &enyvec);
	private:
		gmeSurface      * m_psurf; // 层面模板
		double          * m_topz;  // 顶板高程
		double          * m_btmz;  // 底板高程
	};


	class S3D_KERAUX_EXP gm_borehole_parse
	{
	public:
		gm_borehole_parse(void);
		virtual ~gm_borehole_parse(void);
	public:

		// 初始化钻孔数据:
		long initboreholedata(vector<s3d_BoreHole> * pholesvec, vector<s3d_BaseLayer> * pbaselayerordervec);

		// 根据基本层序，解析地层级别数目
		long getstratumlevelnum();

	public:

		// 根据地层级别，对地层进行一级、二级、三级、四级、合并处理 (一级地层不需要处理)
		// level_no:1/2/3/4/5/6 ... 标准层序处理合并
		long cal_lod_stratumlevel_list(long level_no, vector<string> &strlevelcodevec);

		// 根据地层级别对钻孔数据进行合并处理 === lod_hole_datas 使用完后，需自我清空处理
		long cal_lod_holedata(long level_no, vector<inner_borehole> & lod_hole_datas);

		// 根据层序编码，将分层标准向上合并
		long combinestratumpriorlevel(long levelnopri, vector<string> &strlevelstratum, vector<long> &sublayer_num_in_layer);

	public:
		// 将钻孔数据转化为内部结构
		long mdlboreholetoinner(vector<inner_borehole> & lod_hole_datas);

		// 对钻孔分层进行合并处理: 钻孔分层为从小到大的顺序
		long combineboreholelayer(vector<inner_holelayer> &layvec);
		long conbineboreholelayer(s3d_BoreHole& borehole);

		// 地层级别转换公式 "010203040506"：转化为一级编码，则结果为 010000000000 转化为二级编码，则结果为 010200000000
		//级别从1开始计数。
		long strlevelconvert(string &level, string &out, long level_no);

		// 根据级别，将钻孔结构合并为内部结构
		long boreholetoinner(s3d_BoreHole & borehole, inner_borehole &inhole, long level);

		// 对内部钻孔数据进行缺失补齐处理, 上凸、下凹、自适应缺失处理？ 三种选择 此处暂时上凸处理
		long fill_lack_holelayer_tofull(long level_no, vector<string> &strlevelcodevec, vector<inner_borehole> & lod_hole_datas);

		// 对钻孔缺失地层数据进行插值处理
		long interpolate_lacklayer_z(vector<inner_borehole> & lod_hole_datas, gm_idw_interp& interpObj);

		// 对插值虚拟出来的钻孔高程进行调整处理(缺失地层计算出来的厚度不能低于该地层的平均厚度)
		long adjustlacklayzvalue(inner_borehole & holelayer);		
		long adjust_interp_lacklayer_z(vector<inner_borehole> & lod_hole_datas);

		// 统计所有钻孔，计算每一个地层的平均厚度
		long getlayerthick(vector<inner_borehole> & lod_hole_datas, vector<double> & thickvec);

		//从所有钻孔中取出第idx地层的底板坐标
		long getlayerdata(long idx, bool top, const vector<inner_borehole>& lod_hole_datas, const vector<long>& lastlaynovec, vector<gme_vector3d>& vec);
		long get_surflayer_botm_dots(long idx, vector<inner_borehole> & lod_hole_datas, vector<gme_vector3d> &vec);

		// 提取钻孔数据的孔口坐标
		long get_hole_top_datas(vector<inner_borehole> & lod_hole_datas, vector<gme_vector3d> &vec);
		// 提取钻孔数据的孔底坐标
		long get_hole_btm_dots(vector<inner_borehole> & lod_hole_datas, vector<gme_vector3d> &vec, double &mindz);

		// 根据索引获取级别编码
		string getstrlevelbyindex(long idx, vector<inner_borehole> & lod_hole_datas);
		long getlayerthick(long index, double& thick);

	public:
		vector<double>               m_thickvec;
		vector<s3d_BoreHole>         *m_pholesvec;      // 钻孔分层信息
		vector<s3d_BoreHole>         *m_pnewholesvec;   // 钻孔分层信息
		vector<s3d_BaseLayer>        *m_pbaselayervec;  // 标准地层层序
		long                          m_level_num;       // 地层级别：1/2/3/4/5/... :一级/二级/三级/四级...
	};

}

#endif _GM_GEOMODELING_H