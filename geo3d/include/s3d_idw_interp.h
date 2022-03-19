#ifndef _GM_IDW_INTERP_H
#define _GM_IDW_INTERP_H

#include "s3d_KerInterpIDWDef.h"
#include "gmeMdl.h"
#include "s3d_MeshIdxTbl.h"

using namespace Smart3dMap;

namespace Smart3dMap
{
	typedef struct Interp2SampDotDist
	{
		gme_vector3d*	sampleDot;//样本点
		double			distSqure; //待插点与样本点的距离方
	}Interp2SampDotDist;

	typedef struct IdxBlockInfo //索引块的数据
	{
		vector<gme_vector3d*>	sampleDot; //索引数据库中的样本点
	}IdxBlockInfo;

	//插值类，为了提交计算效率，会备份中间变量
	class LIB_S3DKERINTERPIDW_EXP gm_idw_interp
	{
	public:
		gm_idw_interp();
		~gm_idw_interp();

	public:
		//设置插值参数, adjPntCls--三角形插值法中的邻接三角形级别.
		void setInterpParam(long searchDotNum = 3, vector<gme_vector3d>* interpRgn=nullptr, double insertX=100, double insertY=100, char distPower = 2, char adjPntCls=1);
		//设置用于样本点
		void setSampDots(gme_vector3d* sampDots, long sampDotsNum);

		//单点插值 interpType标志插值方法类型，0--普通IDW插值法，1--三角形插值法;
		double interpolate1Dot(gme_vector3d* interpDot, char interpType = 0);
		//全部点插值
		vector<gme_vector3d>* interpolateAllDots(vector<gme_vector3d>* interpDots=nullptr, char interpType = 0, gmeSurface* interpSurf = nullptr, vector<gme_vector3d>* surfBound=nullptr);
		//取出包围盒
		gme_rect_3d* getInterpBox();
		//取出边界
		vector<gme_vector3d>* getInterpRgn();
		//清空缓冲
		void clearBuffer();

	private:
		//设置插值点
		void setInterpDots(vector<gme_vector3d>* interpDots, char interpType);

		//构建插值的模板面...
		void createTmplateSurf();

		//计算待插点的索引...
		void calInterpDotsIdx();

		//方法1：直接根据idw比来进行插值
		//根据待插点的坐标计算其所在的索引块号.
		void calInterpDotIdxBlockNo(gme_vector2d* interpDot, long& idxBlockXNo, long& idxBlockYNo);
		//构建样本数据的索引块表
		void buildIndexTbl();
		//在索引块中搜索样本点，返回当前收到的点数
		long searchSampIn_A_Block(gme_vector2d& curInterpDots, double idxNoX, double idxNoY, vector<Interp2SampDotDist>& distList);
		//根据搜索的样本点进行Z插值
		void interpSampDot(gme_vector2d& curInterpDots, vector<Interp2SampDotDist>& distList, double& dZ);

		//方法2：先将离散样本点进行三角剖分，然后在根据n-级三角形来进行idw插值


	private:
		double			m_insertX, m_insertY;//网格点的间距
		char			m_adjPntCls; //领域三角形搜索的级别
		long			m_searchDotNum;//最大的总搜索点数
		char			m_distPower;   //IDW幂指数,默认2次
		vector<gme_vector3d>* m_oriInterpRgn;//插值的多边形范围
		vector<gme_vector3d> m_interpRgn;//插值的多边形范围
		gme_rect_3d		m_dotsBox; //数据的包围盒

		gme_vector2d		m_idxBlockStep;	//索引块的大小
		gme_vector2i		m_idxBlockNum;	//XY方向上的索引块数目

		vector<gme_vector3d> m_SampDots;      //样本点
		vector<gme_vector3d> m_interpDots;	 //待插点
		vector<vector<IdxBlockInfo>> m_blockIdxTbl;//块数据的索引表
		gmeSurface			m_idwSurf; //初始样本点构建的曲面三角形...
		long				m_gridXNum, m_gridYNum; //x/y方向上的网格数
		s3d_TriMeshIdxTbl*	m_triIdxTbl; //三角网的索引表...
	};
}

#endif _GM_IDW_INTERP_H