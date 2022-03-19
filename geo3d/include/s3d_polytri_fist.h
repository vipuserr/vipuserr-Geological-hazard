#pragma once

#pragma warning(disable:4005)

#include "s3d_KerTrigRgnDef.h"
#include "gme_vector2.h"
#include "gmeStru.h"

namespace Smart3dMap
{

	class LIB_S3DKERINTERPIDW_EXP gm_polytriangulation
	{
	public:
		gm_polytriangulation();
		~gm_polytriangulation();

		// ------------------------ 对多边形进行三角剖分处理函数 ------------------------ //
		//参数：gme_vector2d *pnts, long *pPolyPntNum, long nPolyNum, gme_vector2d **ppFinalPnt,long *plFinalPntNum, gme_triangle **ppFinalTri, long *pFinalTriNum
		//      (入  口) *pnts        多边形区域边界坐标数据空间地址,点坐标数组.
		//      (入  口) *pPolyPntNum 多边形区域边界封闭圈点数数组.
		//      (入  口) nPolyNum     多边形区域圈数.
		//
		//      (出  口)**ppFinalPnt,pPolyPntNum 整理后的多边形区域边界坐标数据空间地址,点坐标数组
		//      (出  口) **ppFinalTri  三角形的顶点序号(在*xy 中的序号).
		//      (出  口) *pFinalTriNum 三角形的个数.
		//返回值:-1、0、1、2、3   -1表示无多边形，0表示申请内存失败，1表示三角剖分成功；
		//						  2表示存有少于3个点的的轮廓线,但三角剖分成功；
		//						  3表示三角剖分完成且用了Multi-Phase Recovery Process.
		int  gm_polytri_TrianglateRgn(  gme_vector2d *pnts, long *pPolyPntNum, long nPolyNum,
										gme_vector2d **ppFinalPnt, long *plFinalPntNum,
										gme_triangle **ppFinalTri, long *pFinalTriNum);
	private:
		gme_vector2d *m_pFinalPnt;
		long			m_pFinalPntNum;

		gme_triangle *p_FinalTri;
		long		  m_pFinalTriNum;
	};
}