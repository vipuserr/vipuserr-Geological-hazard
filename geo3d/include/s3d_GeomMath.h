#pragma once

#include <s3d_KerMathDef.h>
#include <s3d_GeomDefine.h>
#include "gmeMdl.h"
#include "s3d_GisStru.h"
#include "s3d_KerGeomodelDef.h"

namespace Smart3dMap {

	
	class LIB_GMKERMATH_EXP s3d_MathApp	//数学函数类...
	{
	public:
		s3d_MathApp();
		~s3d_MathApp();

	public:
		// ---------------------------- 建模类函数. --------------------------------- // 
		//根据圆生成多边形
		static long getRegByCircle(gme_vector2d oriPnt, double radius, vector<gme_vector2d>& reg, long cirSegNum = 50);

		//拓扑造区,inlines-弧段列表, outPolys-结果多边形
		static int doCreatePolygons(vector<vector<gme_vector2d>> &inlines, vector<PolyRef> &outPolys);
		//对相邻多边形拓扑不一致，补充交点，保证拓扑一致, rgns-多边形列表
		static void dealRgnsTopo(vector<vector<gme_vector2d>> &rgns);

		//造平行线(输入点列表，输出一侧平行线). 参数：dist：缓冲距离（正负表示方向），dir：方向（1——左边，-1——右边）
		static void gm_parallel_lin(vector<gme_vector2d>& linPnts, vector<gme_vector2d>& parallelLinPnts, double dist, char dir);
		//构建线的缓冲多边形,radius表示缓冲半径
		static void gm_lin_buffer_poly(vector<gme_vector2d>& linPnts, vector<gme_vector2d>& parallelPoly, double radius);

		//建球体
		//需要已知球中心，半径
		static void gm_build_sphere(gme_vector3d* sphere_cent, double radius);
		//计算包围盒
		static int _calulate_rect(gme_vector3d* pdots, int lnum, gme_rect_2d &rect);
		//建立圆柱体：一个圆柱曲面，上下底的两个圆心坐标，圆柱的半径;建立圆柱面的时候需要增加面上的结点
		//于是对柱面进行切片，xy方向个20片
		static void gm_build_cylinder(gmeSurface* surf, gme_vector3d* up_cycle_cents, gme_vector3d* down_cycle_cents, double radius, long gridx = 20, long gridy = 20);
		//建立圆锥体（cone）：一个锥面，一个底部圆；需要的参数应为：圆锥定点坐标，圆锥底部圆心，底部圆半径
		static void gm_build_cone(gmeSurface* surf, gme_vector3d* top_point, gme_vector3d* cycle_cent, double radius, long gridx = 20, long gridy = 20);
		//建立椭球体模型... 不常用，可以用CreateEspille函数
		static void gm_build_ellipsoid(gmeSurface* surf, gme_vector3d* centDot, gme_vector3d* radiusXYZ, long gridx = 20, long gridy = 20);
		//构建椭球体
		static int CreateEspille(gmeSurface * pSurf, gme_vector3d &CenterDot, double lenx, double leny, double lenz, long lnumSeg = 18);
		//构建侧面模型，点一一对应的情况
		static int CreateEnyByTopSur(gmeSurface * pSurf, double botZVal, gmeEntity *pOutEnty);
		static int CreateSideSurface(gme_vector3d *pDotsTop, gme_vector3d *pDotsBtm, int dotNum, gmeSurface *pOutSurf);
		//线对应拼接构建三维面
		static int CreateSurfaceBylines(vector<gme_vector3d> &lines1, vector<gme_vector3d> &lines2, gmeSurface &SurfOut);
		static void createSurf(gmeSurface& outSurf, gme_vector3d* disDots, long dotNum, vector<gme_vector3d>* rgn = nullptr);

		// ------------------------- 点/线/面/体处理变换类 -------------------------------- //
		//线上加点
		static long LineAddPoint(s3d_Polyline3D * pLine, gme_vector3d & d3dot);
		//线上删点
		static long LineDelPoint(s3d_Polyline3D * pLine, gme_vector3d & d3dot);
		//点将线分为两半
		static long Cut3DLine(s3d_Polyline3D  *pLine, gme_vector3d & d3dot, s3d_Polyline3D * pLineOut1, s3d_Polyline3D *pLineOut2);
		//合并线，结果放入pLine1
		static long Link3DLine(s3d_Polyline3D *pLine1, s3d_Polyline3D *pLine2);

		//计算三维面上各个顶点的平均法向量（默认曲面的绘制模式为BIND_PER_VERTEX）
		static void CalAverageNormal(gmeSurface &surf);
		//计算曲面中每个三角形的法向，并设置曲面的绘制模式为BIND_PER_PRIMITIVE_SET
		static void CalSurfTriangleNormal(gmeSurface &surf);

		//三维面标准化处理：去除重复点、0长度边、0面积三角形
		static void StandardSurface(gmeSurface &surf, double esp = 1e-4);
		//设置三维面拓扑信息，计算三角边对应的三角形编号
		static int  SetSurfaceTopo(gmeSurface &surf);
		//将三维面的方向调整一致
		static int  SetSurfaceOrder(gmeSurface &surf);

		//对三维面的三角边进行反向处理
		static int  ReverseOrder(gmeSurface &surf);
		//合并三维面:直接累加，不会去除重复的信息，如要标准化，可调用StandardSurface(*pOutSurf)
		static bool CombineSurface(gmeSurface ** ppSurfaces, int SurNum, gmeSurface * pOutSurf);

		// 三维多边形分解边界线. 参数：lins:边界线、linsOverly：重叠边界线
		static long CalcOverlapLin(vector<vector<gme_vector3d>> &vvPolys, vector<vector<gme_vector3d>> &vvlines, vector<vector<gme_vector3d>> &linsOver);
		// 二维多边形分解边界线 // 参数：lins:边界线、linsOverly：重叠边界线
		static long CalcOverlapLin(vector<vector<gme_vector2d>> &vvPolys, vector<vector<gme_vector2d>> &vvlines, vector<vector<gme_vector2d>> &linsOver);

		//计算三维面的边界线
		static int  GetSurfaceBorderLines(gmeSurface* pSurf, vector<vector<gme_vector3d>> &vvLines);
		//计算三维面的边界线
		static int  GetSurfaceBorderLines(gmeSurface* pSurf, vector<vector<int>> &IdxVecVec);

		//对三维面体直接进行顶点缩放
		static int UpdateSurface(gmeSurface& surf, double dx, double dy, double dz);
		static int UpdateEntity(gmeEntity& enty, double dx, double dy, double dz);
		//对三维面体进行顶点平移
		static int MoveSurface(gmeSurface& surf, double dx, double dy, double dz);
		static int MoveEntity(gmeEntity& enty, double dx, double dy, double dz);
		//对三维面体沿指定点缩放...
		static int ZoomSurface(gmeSurface& surf, double dx, double dy, double dz, gme_vector3d *pdots = NULL);
		static int ZoomEntity(gmeEntity& enty, double dx, double dy, double dz, gme_vector3d *pdots = NULL);

		//面/体平移缩放变换, positive-正变换或反变换， offset-偏移， scale-缩放比例
		static void transformPnts(gme_vector2d* dots, long dotNum, bool positive = true, gme_vector2d* offset = nullptr, gme_vector2d* scale = nullptr);
		static void transformPnts(gme_vector3d* dots, long dotNum, bool positive = true, gme_vector3d* offset = nullptr, gme_vector3d* scale = nullptr);
		static void transformSurf(gmeSurface& surf, bool positive = true, gme_vector3d* offset = nullptr, gme_vector3d* scale = nullptr);
		static void transformEnt(gmeEntity& ent, bool positive = true, gme_vector3d* offset = nullptr, gme_vector3d* scale=nullptr);

		//计算1.几何对象的中心点作为偏移点，2.可能的缩放比例。返回值：是否需要缩放
		static bool calMeshOffset(gmeGeometry& mesh, gme_vector3d* offset = nullptr, gme_vector3d* scale = nullptr, double lenLimit = 0);

		//向面中添加三角形
		static int AddTrianglesToSurface(gmeSurface& surf, vector<gme_vector3d> &addTriPnts, vector<gme_triangle> &addTris, bool bReomoveRepeatedDots=false);
		//删除三角形
		static int RemoveTrianglesInSurface(gmeSurface& surf, vector<long>& delTriNos);
		//剔除点集中未被使用的点集合
		static int RemoveUnusedDotsInSurface(gmeSurface& surf);
		//非边界边，添加中点，然后重构
		static int SmoothSurface(gmeSurface& surf, gme_vector3d * pHoles = NULL, int num = 0);
		//调整两个相邻面
		static bool AdjustTwoSurface(gmeSurface& surf, gmeSurface & Adjsur);

		//2D点转换到3D点(需要两队控制点（五元组))，d2_p0是待转换的点
		static gme_vector3d base_2d_to_3d(const gme_vector2d& d2_p1, const gme_vector3d& d3_p1, // 第一对控制点
										const gme_vector2d& d2_p2, const gme_vector3d& d3_p2, // 第二对控制点
										const gme_vector2d& d2_p0);

		
		// ----------------------------------- 计算凸包函数 ---------------------------------- //
		//求3d离散点凸包函数
		static void gm_convexhull(vector<gme_vector3d>& inputDots, vector<gme_vector3d>& convexHull);
		//求2d离散点凸包函数
		static void gm_convexhull(vector<gme_vector2d>& inputDots, vector<gme_vector2d>& convexHull);
		static short gm_convexhull(gme_vector2d *dtPtr, long *dn);
		//求多边形凸包
		static short cmGetPloygonConvexHull(gme_vector2d *xyPt, long *nLn, short nDir);
		// 计算三维离散点的2d包围盒
		static int GetBox(gme_vector2d *pDots, int num, gme_rect_2d &rect);
		static int GetBox(gme_vector3d *pDots, int num, gme_rect_2d &rect);
		static int GetBox(gme_vector3d *pDots, int num, gme_rect_3d &rect);

		//计算点集的凹多边形边界
		static int gm_concaveHull(vector<gme_vector2d>& inputDots, vector<gme_vector2d>& hull, long NeighborDotNum = 4);

		//计算点集的Meanshift聚类算法
		static int gm_Cluster_Meanshift(vector<gme_vector2d>& inputDots, vector<vector<gme_vector2d>>& clusters, double bandwidth = 0);
		static int gm_Cluster_Meanshift(vector<gme_vector3d>& inputDots, vector<vector<gme_vector3d>>& clusters, double bandwidth = 0);


		// --------------------------------- 向量计算函数 ---------------------------------- //
		//向量相减
		static void PtSub(const gme_vector3d &p1, const gme_vector3d &p2, gme_vector3d &v_out);
		static void Vec3dSub(double out[3], double v1[3], double v2[3]);
		// 三维向量的单位化
		static void Normalise2D(double dNv[2]);
		static bool Normalise2DV(gme_vector2d  *pV);
		static bool Normalise3DV(gme_vector3d  *pV);
		// 计算三角形的平均法向量
		static void GetTriangleNormal(double v1[3], double v2[3], double v3[3], double nv[3]);
		static void GM_GetTriNormalV(gme_vector3d *pNormal, gme_vector3d *pV1, gme_vector3d *pV2, gme_vector3d *pV3);
		static gme_vector3d cal_normal_tmp_algo(const gme_vector3d& a, const gme_vector3d& b, const gme_vector3d& c);
		// 矢量方向判断
		static double get_vec_dir(gme_vector2d &a, gme_vector2d &b, gme_vector2d &c);
		// 计算三维向量的点乘
		static bool _S3D_3DDot(double *pOut, gme_vector3d *pV1, gme_vector3d *pV2);
		static double Vec3dDot(double v1[3], double v2[3]);
		static double PtDot(const gme_vector3d &p1, const gme_vector3d &p2);//点乘
		// 计算三维向量的叉积
		static bool _S3D_3DCross(gme_vector3d *pOut, gme_vector3d *pV1, gme_vector3d *pV2);
		static void Vec3dCross(double out[3], double v1[3], double v2[3]);//叉积
		static void VectCross(const gme_vector3d &v1, const gme_vector3d &v2, gme_vector3d &n);
		// 计算三角形法向量（单位法向量）
		static gme_vector3d CalTriNormal(gme_vector3d &a, gme_vector3d &b, gme_vector3d &c);
		static void Normalise3D(double nv[3]);
		// 计算两个三维向量的夹角，失败返回-1
		static double s3d_CalVec3Angle(gme_vector3d *pV1, gme_vector3d *pV2);
		// 根据三点计算平面方程，返回方程系数pP[4]
		static bool s3d_GetPlanByPnt(double pP[4], gme_vector3d *p1, gme_vector3d *p2, gme_vector3d *p3);
		//2.8 向量操作 图形方程
		//向量与X轴正向的角度
		static double calc_vector_angle(gme_vector2d *pder);
		//计算两个三维向量的夹角，结果为返回值:弧度制
		static double calc_angle_of_3d_vec(gme_vector3d *pv1, gme_vector3d *pv2);
		//计算直线方程的系数：直线方程：ax + by + c = 0.
		//输出：三个系数：pa，pb，pc
		static int get_coefofline(gme_vector2d *pdot_top, gme_vector2d *pdot_end, double *pa, double *pb, double *pc);
		//计算垂足
		static long calc_vertical_of_line(gme_vector2d &pnt, gme_vector2d lindot0, gme_vector2d lindot1, gme_vector2d *res_pnt);
		//根据斜率和已知点，求二维直线方程
		static void get_line_by_pnt_and_slope(double slope, gme_vector2d &dot, double &a, double &b, double &c);
		//计算三角形重心
		static void GetBaryOfTri(double TriPnt1[3], double TriPnt2[3], double TriPnt3[3], double dBaryPnt[3]);
		//将四元组转化为4X4的矩阵
		static double* MatrixRotationQuaternion(double pOut[4][4], double* pQ);
		//对点做矩阵变换
		static gme_vector3d* TransformCoor(gme_vector3d* pOut, gme_vector3d *v, double mtrx[4][4]);
		//根据射线确定一个三角形
		static long GetTriByRadial(gme_vector3d* RayOrg, gme_vector3d* RayDir, gme_vector3d* RadSecPnt, gme_vector3d* RadThiPnt);
		static long Check3dPntAndSeg(gme_vector3d *pOri, gme_vector3d *pEndPnt, gme_vector3d *pTryPnt);

		//找出面积最大的多边形作为外边界，返回其序号
		static long findMaxAreaPoly(vector<vector<gme_vector2d>>& polys);
		static long findMaxAreaPoly(vector<vector<gme_vector3d>>& polys);
		//判断一个多边形是否在另一个多边形里面
		static bool judgeSmallInBigPolygon(vector<gme_vector2d>& smallPolygon, vector<gme_vector2d>& bigPolygon);
		static bool judgeSmallInBigPolygon(vector<gme_vector3d>& smallPolygon, vector<gme_vector3d>& bigPolygon);
		//三维点集合转二维点集合
		static void d3Dots2d2Dots(vector<gme_vector3d>& d3Dots, vector<gme_vector2d>& d2Dots);
		static void d3Dots2d2Dots(s3d_Polygon3D& d3Dots, s3d_Polygon& d2Dots);
		//二维点转三维点集合
		static void d2Dots2d3Dots(vector<gme_vector2d>& d2Dots, vector<gme_vector3d>& d3Dots);
		static void d2Dots2d3Dots(s3d_Polygon& d2Dots, s3d_Polygon3D& d3Dots);
		//多边形排序，第一个是外边界，后面的是内边界
		static void sortPolygons(vector<vector<gme_vector2d>>& polys);
		static void sortPolygons(vector<vector<gme_vector3d>>& polys);


		// ------------------------------- 判断位置关系类函数 -------------------------------------- //
		//判断面是否封闭
		static bool isSurClose(gmeSurface& sur);
		//判断体是否封闭
		static bool check_ent(gmeEntity& ent);

		//点是否在矩形中,在矩形内返回true，否则返回false
		static bool isDotInRect(gme_vector3d* pdots, gme_rect_3d* prect, double esp=1e-6);
		static bool isDotInRect(gme_vector3d* pdots, gme_rect_2d* prect, double esp=1e-6);
		//点是否在矩形中,0-矩形外， 1-矩形边上， 2-矩形内
		static short cmPntInRect(gme_D_DOT *pnt, gme_D_RECT *rc);
		// 判断点与包围盒的位置关系 -1:在包围盒外, 0:包围盒上, 1:包围盒内
		static short CheckPntAndC3DBox(gme_rect_3d * pC3dBox, gme_vector3d &TryPnt);

		//判断点和多边形关系；-1:点在多边形外，1：点在多边形内，0：点在多边形上
		static int gm_dot_in_polygon_check(const gme_vector2d& dot, gme_vector2d * pdots, unsigned long polygon_size, double eps = 1e-5);
		static int gm_dot_in_polygon_check(const gme_vector3d& dot, gme_vector3d * pdots, unsigned long polygon_size, double eps = 1e-5);

		//带有内外边界的点和多边形关系；-1:点在多边形外，1：点在多边形内，0：点在多边形上
		//2D
		static int gm_dot_in_polygon_check(const gme_vector2d& dot, s3d_Polygon& strat_outer_rgn, double eps = 1e-6);
		static int gm_dot_in_polygon_check(const gme_vector2d& dot, vector<gme_vector2d>& strat_outer_rgn, vector<vector<gme_vector2d>>& strat_inner_rgns, double eps = 1e-6);
		//3D
		static int gm_dot_in_polygon_check(const gme_vector3d& dot, s3d_Polygon3D& strat_outer_rgn, double eps = 1e-6);
		static int gm_dot_in_polygon_check(const gme_vector3d& dot, vector<gme_vector3d>& strat_outer_rgn, vector<vector<gme_vector3d>>& strat_inner_rgns, double eps = 1e-6);

		//判断点是否在多边形内，支持含内外边界的多圈情况。 flg==1则严格套合，否则只检查第一圈.   返回值：2/1/0=内/边界/外.
		static short cmIsDotInReg(long regNum, gme_D_DOT  *xy, long *ne, gme_D_DOT *dot, short flg);
		//判断点是否在多边形内，返回值 1/0/-1：点在多边形的内部/边界上/外部，若函数返回0则*edgNo指示点所在的边段.
		static short cmCheckDotInPolygon(gme_D_DOT *pxy, long dn, gme_D_DOT *dPt, long *edgNo = NULL);
		//检测点是否在单圈多边形内，且可不要求多边形封闭.  返回值：2/1/0=内/边界/外.
		static short cmIsDotInPolygon(gme_D_DOT  *pxy, long dn, gme_D_DOT *dot);

		// 判断点在边的哪一边
		static int judge_dot_side(const gme_vector3d& point_judge, const gme_vector3d& section_point1, const gme_vector3d& section_point2);
		// ----------- 双邻点判断法快速判断曲线走向(顺/逆:1/-1) ----------- //
		//说明:1、若返回的结果为0则多边形无效(多边形所有点重合).
		//	   2、该方法比求面积法可大幅提高判别速度,但对自相交
		//		  多边形可能误判.
		static short cmGetPloygonDirWithDNPJM(gme_D_DOT *xy, long len);

		//根据待求点与有效线段判断待求点的位置-2:出错，-1:顺时针，1:逆时针
		static long CheckPntPosInSeg(gme_vector2d *pTryPnt, gme_vector2d *pCurvePnts, long lSegNo);
		//判断2d点与曲线的位置关系
		static long Check2dPntAndCurve(gme_vector2d *pTryPnt, gme_vector2d* pCurvePnts, long lCurPntNum);
		//判断线段所在直线上的点与线段的位置关系 返回值：-2：其他情况，－1：反向延长线，0：线段上，1：延长线上， 0：端点上 
		static long Check2dPntAndSeg(gme_vector2d *pOriPnt, gme_vector2d *pEndPnt, gme_vector2d *pTryPnt, double esp = 1e-6);
		static int Check2dPntAndSeg(double x1, double y1, double x2, double y2,double x, double y, double esp = 1e-6);


		//判断点与三角面片之间的关系
		static long  CheckPntToSurfPos(gme_vector3d *pTryPnt, gme_vector3d *pTriPnt1, gme_vector3d *pTriPnt2, gme_vector3d *pTriPnt3);
		static long  CheckSegAndOtherTdeSurf(long lCurTriNo, gme_vector3d *pOriPnt, gme_vector3d *pEndPnt, gme_vector3d *pTinPnt, long lPntNum, gme_triangle *pTinNet, long lNetNum);

		// 判断点与线段的位置：1：左边CCW；0 ：线上；-1：右边，CW；
		static int judge_side(const gme_vector3d& point_judge, const gme_vector3d& section_point1, const gme_vector3d& section_point2);
		// 判断点与线段的位置(通过构成的三角形面积判断)
		static int judge_side_by_area(const gme_vector3d& point_judge, const gme_vector3d& section_point1, const gme_vector3d& section_point2);
		// 判断点与线段的位置(通过夹角判断)
		static int judge_side_by_angle(const gme_vector3d& point_judge, const gme_vector3d& section_point1, const gme_vector3d& section_point2);

		// 点是否在三角形内
		static short isDotInTriangle(gme_vector3d *A, gme_vector3d *B, gme_vector3d *C, gme_vector3d *P, double eps=1e-6);
		// 点与三角形位置关系快速粗略判断（利用三角形的AABB判断来快速过滤点）
		static int IsPntNotInTri(gme_vector3d *pnt, gme_vector3d *p1, gme_vector3d *p2, gme_vector3d *p3, double esp = 1e-6);
		// 判断点是否在三角形内,1：点在内，0：点在外
		static bool is_dot_in_triangle(const gme_vector3d& point_judge, const gme_vector3d& tri_point1, const gme_vector3d& tri_point2, const gme_vector3d& tri_point3);
		// 在XY平面内判断点与三角形关系
		static point_triangle_ralationship point_in_triangle(const gme_vector3d P, const gme_vector3d A, const gme_vector3d B, const gme_vector3d C);
		// 简要判断点是否在三角形内，与边角点重合的情况默认为true
		static bool point_in_triangle_simp(const gme_vector3d P, const gme_vector3d A, const gme_vector3d B, const gme_vector3d C);
		//判断点是否在三角形内 0外 1内 2边上
		static int IsPointInTringle(gme_vector3d &dot, gme_vector3d *p1, gme_vector3d *p2, gme_vector3d *p3, double esp = 1e-6);
	
		//以下这5个函数仅仅内部使用
		//判断点是否在多边形内, 0外 1内 2边上
		static int IsPointInPolygon(gme_vector2d &dot, gme_vector2d *pDots, s_unlong dotNum);
		static int IsPointInPolygon(gme_vector3d &dot, gme_vector3d *pDots, s_unlong dotNum);
		// 点是否在多边形内，0外 1内 2上
		static int IsDotInPolygon(s_unlong nelen, gme_vector2d *pXY, s_unlong * pNe, gme_vector2d * pDot);
		static int IsDotInPolygon(vector<vector<gme_vector3d>> &vvDots, gme_vector2d * pDot);
		static int IsDotInPolygon(vector<vector<gme_vector2d>> &vvDots, gme_vector2d * pDot);

		// --------------- 求点*xy3对线段(*xy1->2)的垂足、垂距及垂足是否在该线段上 ---------------- //
		// 出口参数: gme_D_DOT  *pose -----> 垂足坐标.
		//			 double *d --------> 垂距.
		// 函数返回: 1/2: 垂足是/否落在该线段上.
		static short cmCalVerticalPnt(gme_D_DOT *xy1, gme_D_DOT *xy2, gme_D_DOT *xy3, gme_D_DOT *pose, double *d);

		// --------- 若已知点*pnt近似(dfEps近似容忍度)为在折线(fxy,len)上,求其所在段号函数 --------- //
		// 函数引出参数: 点*pnt在折线(fxy,len)上的最近垂足(由*pnt返回)及垂距(由*dis返回).
		//     返回参数: 已知点*pnt对折线(fxy,len)上的最近垂足所在的折线段号(0下标开始).
		static long cmGetPntOnlinSegNo(gme_D_DOT *pnt, gme_D_DOT *fxy, long len, double dfEps, double *dis);

		// 判断点V在直线AB的左(>0),右(<0)或上(=0)函数:
		static double cmCheckFvBy2dAB(gme_D_DOT *ptA, gme_D_DOT *ptB, gme_D_DOT *ptV);

		// 判断点V与由三维点ABC构成平面之间的位置关系函数:
		// 说明:ABC的顺序要求为从平面上方看，ABC构成逆时针三角形.
		//      返回值>0则点V落在由三维点(a,b,c)定义平面的下方.
		//      返回值<0则点V落在由三维点(a,b,c)定义平面的上方.
		//      返回值=0则点V与由三维点(a,b,c)定义的平面共面.
		static double cmCheckFvBy3dABC(gme_D_3DOT *ptA, gme_D_3DOT *ptB, gme_D_3DOT *ptC, gme_D_3DOT *ptV);

		// 判断点*d是否在由二维点(*a,*b,*c)定义构成的外接圆内函数.
		// 返回:(>0)则点d落在由点a,b,c定义的外接圆内.
		//		(<0)则点d落在由点a,b,c定义的外接圆外.
		//		(=0)则点d落在由点a,b,c定义的外接圆边界上.
		static double cmIsInCircleBy2dABC(gme_D_DOT *a, gme_D_DOT *b, gme_D_DOT *c, gme_D_DOT *d);

		// 判断点e是否在由三维点(a,b,c,d)定义构成的外接球中:
		// 返回值>0则点E落在外接球内, <0则点E落在外接球外.
		// 返回值=0则点E落在外接球边界上.
		static double cmIsInSphereBy3dABCD(gme_D_3DOT *pa, gme_D_3DOT *pb, gme_D_3DOT *pc, gme_D_3DOT *pd, gme_D_3DOT *pe);

		// 简要判断是否相交
		static bool line_line_intersect_simp(const gme_vector3d v1, const gme_vector3d v2, const gme_vector3d p1, const gme_vector3d p2);
		// 在XY二维平面判断两线段相交关系，如果相交，给出p1p2上的交点；
		static line_line_ratationship line_line_intersect(const gme_vector3d v1, const gme_vector3d v2, const gme_vector3d p1, const gme_vector3d p2, gme_vector3d& intersect_point);
		//计算二维直线的交点
		static int inter_of_lines(double a1, double b1, double c1, double a2, double b2, double c2, gme_vector2d *pnt_out);
		//折线求交处理
		static int cal_line_intsect(vector<gme_vector2d> &vec1, vector<gme_vector2d> &vec2, vector<gme_vector2d> &vecout);
		//根据矢量，生成弧段
		static int create_line_by_pnt(gme_vector2d &center, gme_vector2d &dot1, gme_vector2d &dot2, double angle, vector<gme_vector2d> &vec);
		//返回值：－1：反向延长线，0：线段上，1：延长线上
		static int check_2d_pnt_and_seg(gme_vector2d *p_ori_pnt, gme_vector2d *p_end_pnt, gme_vector2d *p_try_pnt);
		// 自相交处理
		static int cal_line_intsect_self(vector<gme_vector2d> &vec1, vector<gme_vector2d> &vecout);
		//对缓冲线进行相交裁剪、圆弧连接处理
		static int cut_and_link_buffer(vector<vector<gme_vector2d>> &vecbuff, vector<gme_vector2d> &oriline, vector<gme_vector2d> &out_line, double angle);
		//对缓冲线进行相交裁剪、圆弧连接处理  2017-12-28
		static int cut_and_link_buffer2(vector<vector<gme_vector2d>> &vecbuff, vector<gme_vector2d> &oriline, vector<gme_vector2d> &out_line, double angle);
		//返回值：－2：没有交点，-1:交点在第一条线段反向延长线上，0：交点在第一条线段上，1：交点在第一条线段延长线上。
		static int intersect_of_2dlines(gme_vector2d *p_ori_1, gme_vector2d *p_end_1, gme_vector2d *p_ori_2, gme_vector2d *p_end_2, gme_vector2d *p_out_pnt);

		//二维线段相交
		//直线方程1:AX + BY + C = 0. 
		//直线方程2:p = p1 + t(p2-p1).
		//返回值：－2：没有交点，-1:交点在第一条线段反向延长线上，0：交点在第一条线段上，1：交点在第一条线段延长线上。
		static long InterOf2dLins(gme_vector2d *pOriPnt1, gme_vector2d *pEndPnt1, gme_vector2d *pOriPnt2, gme_vector2d *pEndPnt2, gme_vector2d *pInterPnt);
		//判断当前线段与其他线段有无交点
		//-2:没有交点 0:有交点
		static long CheckCurSegAndOtherSegs(gme_vector2d *pOriPnt, gme_vector2d *pEndPnt, gme_vector2d *pCurvePnt, long lCurPntNum, long lCurSegNo);
		//求二维三角形的法向
		static void  Get2dTriNorm(double v1[2], double v2[2], double v3[2], double *nv);
		//计算三角形和线段的交点
		static long cal_tri_lin_cross(gme_vector3d& crossDot, const gme_vector3d& triDotA, const gme_vector3d& triDotB, const gme_vector3d& triDotC, const gme_vector3d& linDotA, const gme_vector3d& linDotB);

		//线段与三角形求交
		static int	line_tri(double *LinPnt1, double *LinPnt2, double *TriPnt1, double *TriPnt2,
			double *TriPnt3, double *pnt, int *lpPntOnEdge = 0);
		static int	line_tri_new(double *LinPnt1, double *LinPnt2, double *TriPnt1, double *TriPnt2,
			double *TriPnt3, double *pnt, int *lpPntOnEdge = 0);
		//射线与三角形求交
		static bool Radial_Tri(double *orig, double *dir, double *TriPnt1, double *TriPnt2,
			double *TriPnt3, double *pnt, int *lpPntOnEdge = NULL);

		//判断点是否位于三角面内 plPntOnEdge：123、456
		static long IsPntInTriPanel(gme_vector3d *pTryPnt, gme_vector3d *pTriPnt1, gme_vector3d *pTriPnt2, gme_vector3d *pTriPnt3, int *plPntOnEdge = NULL);
		static long IsPntInTriPanel2(gme_vector3d *pTryPnt, gme_vector3d *pTriPnt1, gme_vector3d *pTriPnt2,gme_vector3d *pTriPnt3, int *plPntOnEdge = NULL, double esp = 1e-4);
		static long Check3dPntAndPanel(gme_vector3d *pPnt, double* pdPanelCoef);
		// 计算点与三角形所在平面的位置关系：法向同侧返回1，法向异侧返回-1，面上返回0  CEO
		static int GetDirOfPntToPanel(gme_vector3d *pdot, gme_vector3d *pdot1, gme_vector3d *pdot2, gme_vector3d *pdot3);

		//判断三角化时,是否需要进行坐标调整
		static bool IsNeedAdjust(gme_vector3d pDots[2]);
		static long GetRectOfTriangle(gme_vector3d *pTriDot, gme_vector3d *pRectDot);

		//判断两个三角形是否共面
		static bool IsOnOneSurf_Tri_Tri(gme_vector3d &A1, gme_vector3d &A2, gme_vector3d &A3, gme_vector3d &B1, gme_vector3d &B2, gme_vector3d &B3);

		static void ISECT(double VV0, double VV1, double VV2, double D0, double D1, double D2, double& isect0, double& isect1);


		//判断两个包围盒
		static long CheckTwoAABB(gme_rect_3d* box1, gme_rect_3d* box2);
		static void combineC3Box(gme_rect_3d* box1, gme_rect_3d* box2);
		//返回0，说明相离...
		static int  judgeAABB(gme_rect_3d* box1, gme_rect_3d* box2, double esp = 1e-6);
		//取出包围盒的顶点
		static long Get8VertexOfAABB(gme_vector3d pPnt[8], gme_rect_3d* box);
		//判断点是否在包围盒内 //-1:在外，0:在包围盒上, 1：在内
		static long CheckPntAndAABB(gme_vector3d* pnt, gme_rect_3d* box);//需要加容差...



		// ------------------------------------- 插值、抽稀、加密类函数 ---------------------------------- //
		//道格拉斯-普克法线抽稀处理函数
		static short cmReduceLinByDP(gme_D_DOT *f_dot, long *npoints, double eps);
		//变三角形滤波法线抽稀概括处理函数
		static short cmReduceLinByTV(gme_D_DOT *f_dot, long *npoints, double eps);

		//距离反比插值(x,y)->z
		static int    DisInverseInterp(gme_vector3d * pDots, s_unlong dotNum, gme_vector3d &dot, double dRdus);
		//距离反比插值(x,y,z)->w
		static int    DisInverseInterp_3D(gme_vector4d * pDots, s_unlong dotNum, gme_vector4d &dot, double dRdus, double xyWeight=1, double zWeight = 1);
		//Multi-B Spline插值法
		static void*    MBInterp_Init(gme_vector3d * pDots, s_unlong dotNum);
		static int		MBInterp(void* mbsp, gme_vector3d &dot);

		//生成抛物样条曲线，传入:pDotsIn,DotsNum,InsertDis(插值间距)，传出:vecOut
		static int InterpParabolaCurve(gme_vector3d * pDotsIn, int DotsNum, double InsertDis, vector<gme_vector3d> &vecOut);

		// B样条插值——在平面内构B样条曲线
		//2次B样条插值(不过点)
		static void gm_TwoOrderBSpline(gme_vector2d *&pt, int &Num, int *InsertNum);
		//3次B样条插值(不过点)
		static void gm_ThreeOrderBSpline(gme_vector2d *&pt, int &Num, int *InsertNum);
		//3次B样条插值(过点)
		static void gm_ThreeOrderBSpline1(vector<gme_vector2d>& arc_buf, double insert_step = 1.0);

		// 加密三维线
		static int Insert3DLine(vector<gme_vector3d> &polyObj, double distance);
		static int Insert3DLine(vector<gme_vector3d> &polyObj, int num);
		// 加密三维线
		static int InsertPoints(vector<gme_vector3d> &polyObj, int num);
		static int InsertPoints(vector<gme_vector3d> &polyObj, double distance);
		static int InsertPoints(vector<gme_vector3d> &polyObj, int lxNum, int lyNum, vector<gme_vector3d> &outDotsVec, double esp);
		static int InsertPoints(vector<gme_vector3d> &polyObj, double dx, double dy, vector<gme_vector3d> &outDotsVec, double esp);

		//加密、距离反比加权插值（单点插值、不考虑索引）. dradius<=0，认为没有距离约束
		//返回值：2-返回最近点的值；1-距离反比加权插值；0-失败
		static int inverse_distance(gme_vector3d * pd3dots, int num, gme_vector3d &dot, double& dradius);
		// 空间距离反比：dradius<=0，认为没有距离约束，属性插值
		static int inverse_distance_property(gme_vector3d * pd3dots, double * p_proty, int num, gme_vector3d &dot, double &out_p_proty, double dradius = 0, double xyWeight = 1, double zWeight = 1);
		// 查找点集中距离目标点距离最近的点，返回点序号
		static int get_nearestdot(vector<gme_vector3d> &vecdots, gme_vector3d& dot, gme_vector3d* outdot=nullptr);
		static void get_nearestdots(vector<gme_vector3d> &vecdots, gme_vector3d& dot, int num = 1, vector<gme_vector3d>* outdots = nullptr, vector<long>* dotIdx = nullptr);
		static void get_nearestdots(vector<gme_vector3d> &vecdots, gme_vector3d& dot, double radius=0, vector<gme_vector3d>* outdots = nullptr, vector<long>* dotIdx=nullptr);

		// 按照加密点间距进行加密
		//算法直接对 ground_polygon 进行修改和更新
		static int insert_dot(vector<gme_vector3d> &ground_polygon, int num);
		//算法直接对 ground_polygon 进行修改和更新
		static int insert_dot(vector<gme_vector3d> &ground_polygon, double distance);
		// 多边形内部加密：多边形必须是首尾闭合的... 算法直接对 ground_polygon 进行修改和更新 
		static int insert_dot(vector<gme_vector3d> &ground_polygon, double dx, double dy, vector<gme_vector3d> &insertdots, double esp = 1E-6);
		// 算法直接对 ground_polygon 进行修改和更新。  多边形内部加密：多边形必须是首尾闭合的...
		static int insert_dot(vector<gme_vector3d> &ground_polygon, int lx, int ly, vector<gme_vector3d> &insertdots, double esp = 1E-6);



		// ------------------------------------- 距离、角度、面积、体积等计算函数 ------------------------------------------- //
		//计算面的面积
		static double Cals3d_SurfaceArea(gmeSurface & sur);
		//计算体的体积
		static double Cals3d_EntityVolume(gmeEntity & eny);
		//重构体的拓扑
		static bool   SetEntityTop(gmeEntity & Enty, bool flg = true);
		//计算点与曲面构成的多面体的体积
		static double CalPntToSurVolume(gme_vector3d &Pnt, gmeSurface &surf);
		static int CutPolygonByMapY(s3d_Polygon &poly, vector<gme_vector2d> &lines1, vector<gme_vector2d> &lines2);

		//计算过pnt的垂线与三维面的交点
		static int GetPntByAnySurf(gme_vector3d &pnt, gmeSurface &surf, double esp = 1e-6, gme_vector3d *pDir = NULL);
		//计算过pnt的垂线与三维体的交点
		static int GetPntByAnyEnty(gme_vector3d &pnt, gmeEntity  &enty, double &dz, double esp = 1e-6);

		//多Z值曲面处理方法：传出多个交点... 2021-5-12
		static int GetPntsBy3dSurf(gme_vector3d &pnt, gmeSurface &surf, vector<double> &dzvec, double esp = 1e-6);
		static int GetPntsBy3dEnty(gme_vector3d &pnt, gmeEntity  &enty, double &dz, double esp = 1e-6);

		//计算二维空间两点p1与p2之间的距离
		static double  CalDist2dDot(gme_vector2d* p1, gme_vector2d* p2);
		static double  CalDist2dDot2(gme_vector2d& p1, gme_vector2d& p2);
		// 计算点与三维直线的距离
		static double cal_distance_dot_line(const gme_vector3d &dothead, const gme_vector3d &dotend, const gme_vector3d &d3dot);
		// 计算点到折线的距离
		static double cal_dis_dot_to_lines(vector<gme_vector3d> &linesvec, gme_vector3d &d3dot);
		//计算两点的距离平方
		static double DistancePOW(gme_vector3d* A, gme_vector3d* B);
		//三维空间中点到直线的距离
		static double CalDisOfDotToStLine(gme_vector3d &dotHead, gme_vector3d &dotEnd, gme_vector3d &dot);
		// 三维空间中点到折线的距离
		static double CalDisOfPntTolines(vector<gme_vector3d> &LineVec, gme_vector3d &dot);
		// 计算Label点（内部点）返回0失败，1成功
		static short  GetLabelPnt(gme_vector2d *pXY, s_unlong *pNe, s_unlong nelen, gme_rect_2d *pRect, gme_vector2d *pLabel);
		//计算两点之间的距离
		static double CalDistance(gme_vector3d *p1, gme_vector3d *p2);
		//计算三角形的面积
		static void GetTriArea(double pDot1[3], double pDot2[3], double pDot3[3], double *pdTriArea);
		static double GetTriArea( gme_vector3d *p1, gme_vector3d *p2, gme_vector3d *p3);
		static double cal_tri_area(gme_vector2d& dot1, gme_vector2d& dot2, gme_vector2d& dot3);
		static void GM_GetTriArea(double *pOut, gme_vector3d *p1, gme_vector3d *p2, gme_vector3d *p3);
		// 求四面体体积的带符号体积
		static double CalTetreVolume(gme_vector3d *p0, gme_vector3d *p1, gme_vector3d *p2, gme_vector3d *p3);
		static double GM_CalTetreVol(gme_vector3d* p0, gme_vector3d* p1, gme_vector3d* p2, gme_vector3d* p3);
		// 三维空间中，点到线段的距离
		static double CalDisOfDotToSeg(gme_vector3d &dotHead, gme_vector3d &dotEnd, gme_vector3d &dot);
		//近似计算多边形长轴: //输入参数：polyObj，输出参数: topA、  topB（长轴的两个顶点索引）
		static double CalPolygonLongAxis(vector<gme_vector3d> &polyObj, int &minNo, int &maxNo);


		// --------------- 计算两矢量夹角,从矢量p0p1到矢量p2p3 --------------- //
		// 返回: 角度单位是度，从-180到180((-180,180]区间).
		static double cmCalSectorsAngle2PI(gme_D_DOT* P0, gme_D_DOT* P1, gme_D_DOT* P2, gme_D_DOT* P3);

		// -------- 计算由起点(x0,y0)到终点(x1,y1)的有向线与正X轴的弧度 -------- //
		//说明:该函数可由函数模板来实现已针对任何数据类型.
		static double cmCal2PIAngle1(double x0, double y0, double x1, double y1);

		// ----------- 计算直线角度（-PI到+PI） ----------- //
		static double cmCalPIAngle(gme_D_DOT *xy0, gme_D_DOT *xy1);
		static double cmCalPIAngle1(float x0, float y0, float x1, float y1);

		// ------------ 计算直线角度（0到2PI） ------------ //
		static double cmCal2PIAngle(gme_D_DOT *xy0, gme_D_DOT *xy1);
		static double cmCal2PIAngle1(float x0, float y0, float x1, float y1);

		// --------------- 逆时针简单多边形中凸凹点的判断函数 --------------- //
		// 返回: >0、<=0 --> 当前点为凸、凹点(平点作凹点).
		static short cmCheckSVi(gme_D_DOT *ptXuPloygon, long preDn, long curDn, long nxtDn);

		// -------------------- 按X分量递增快速排序 -------------------- //
		static void cmCnhlQk_Sort_ppByXInc(gme_D_DOT *pp, long i, long j);

		// 按X分量递减快速排序
		static void cmCnhlQk_Sort_ppByXDec(gme_D_DOT *pp, long i, long j);

		// -------------------- 实体之间的空间距离关系 -------------------- //
		// 计算线段长度函数:
		static double  cmSegmentLength(gme_D_DOT *xy0, gme_D_DOT *xy1);
		static double  cmSegmentLength1(double x0, double y0, double x1, double y1);
		static double  cmCalculateLength(gme_D_DOT  *xy, long len);

		// ---------------- 计算一闭合区面积函数 ---------------- // 
		static double cmCalculateOneArea(gme_D_DOT  *xy, long len);

		// --------------- 计算点、点间的距离函数 --------------- //
		static double cmDistofPntToPnt(gme_D_DOT *pnt0, gme_D_DOT *pnt1);

		// --- 计算点到线之间的距离:若直线方程为:ax+by+c=0,则点(x,y)到该直线的  --- //
		// 垂足(x0,y0)为: x0=(bbx-aby-ac)/(aa+bb) 
		//				  y0=(aay-abx-bc)/(aa+bb).
		static double cmDistofPntToLin(gme_D_DOT *pnt, gme_D_DOT *lxy, long len);

		// ------------------ 计算点到区之间的最小距离/最大距离 ------------------ //
		//检测点是否在单圈多边形内, 返回值：2/1/0=内/边界/外
		//若在多边形内或在多边形边界上，则点到多边形的最小距离为0
		static double cmMaxDistofPntToReg0(gme_D_DOT *pnt, gme_D_DOT *polxy, long len);
		static double cmMinDistofPntToReg0(gme_D_DOT *pnt, gme_D_DOT *polxy, long len);
		//计算点到区之间的距离
		static short cmDistofPntToReg0(gme_D_DOT *pnt, gme_D_DOT *polxy, long len, double *minDis, double *maxDis);


		// --------------------------------- 取面元区域圈数 ---------------------------------- //
		// rdata[0] --- 该面元各圈边界总点数
		// rdata[1..len) --- 取值为0时表示该圈弧段结束； 大于0/小于0：顺/逆去点形成边界。
		static long cmGetRegCircleNum(long *rdata, long len);

		// ------------------- 计算线数据范围==>dfRc ------------------- //
		static short cmCalLinDatRect(gme_D_DOT *xy, long len, gme_D_RECT *dfRc);

		//计算点到平面的有符号距离
		static float CalcSignedDistPntPlane(const double pdPnt[3], double pPanelDots1[3], double pPanelDots2[3], double pPanelDots3[3]);
		static double CalcSignedDistPntPlane(const double pdPnt[3], const double *pdPanelCoef);

		static 	double CalcDist(const gme_vector3d* pA, const gme_vector3d* pB);
		//计算角度
		static double get_angle(double *x1, double *x2, double *x3, double esp = 0.0000001);
		//计算体积
		static double cal_std_sur_volume(gme_vector3d* pdots, int dotnum, int* ptris, int trinum);
		static double cal_std_sur_volume(gme_vector3d* pdots, int dotnum, vector3<unsigned int>* ptris, int trinum);
		//计算一圈封闭线的面积
		static double cal_area(gme_vector2d* pdots, int dotnum);
		static  double cal_len(double x, double y);
		static  double cal_len(double x, double y, double z);
		static  double cal_dist_square(double x, double y);
		static  double cal_dist_square(double x, double y, double z);
		//计算坐标网格间距
		static void cal_val_spacing(double& min_val, double& max_val, double& dval);
		static void cal_coordinate_grid_spacing(gme_vector3d& min_dot, gme_vector3d& max_dot, double& dx, double& dy, double& dz);

		//多边形合并功能;
		static void MergePolygon(vector<PolyRef>& outPolygon);

		// distoOri 调整点到中心点的距离  radius: 影响半径
		// 指数调整函数
		static double exp_adjust(double distoOri, double radius);
		// 线性调整函数 
		static double line_adjust(double distoOri, double radius);
		// 高斯调整函数
		static double gauss_adjust(double distoOri, double radius);
		// 球状调整函数
		static double sphere_adjust(double distoOri, double radius);

		// 计算闭合多边形缓冲区
		static int cal_polygon_buffer(vector<gme_vector2d> &linesvec,vector<gme_vector2d> &poly_out,vector<gme_vector2d> &poly_in,double dradius, int toptype = 0, int num = 36);
		static bool line_line_intsect(gme_vector2d &pline1_dot1, gme_vector2d &pline1_dot2, gme_vector2d &pline2_dot1, gme_vector2d &pline2_dot2, gme_vector2d *pdinsect_dot_out);
		static void set_sur_order(queue<int>& que_obj, gme_triangle* ptri, gme_triangle_top* ptop,bool* b_order, bool* b_used);
		static bool init_vector_3i(int a, int b, int c, gme_triangle& tri);
		//对点坐标进行归一化处理
		static void deal_dots_by_esp(gme_vector3d* pDots, int dot_num, double esp);

		// 根据索引获取点数据
		static void set_datas(gmeSurface* v_face, vector< vector<int> >& vec, vector< vector<gme_vector3d> >& vv_polygon);

		// 将线段连接成折线
		static void get_lines(vector<vector<gme_vector3d>> &vec);
		// 查找连通线
		static void get_connected_lines(vector<vector<gme_vector3d>> &p_vec, char * pflg, int index, vector<gme_vector3d> &out_line);

		// GIS空间分析
		static long  GetRectof3DTri(double *p0, double *p1, double *p2, gme_vector3d *pRectDot);
		static long  GetVolToImgCoor(gme_vector3d pd3RectPnts[4], gme_vector3d* pd3Pnt, gme_vector2d* pd2Pnt);
		static long  GetImgToVolCoor(gme_vector3d pd3RectPnts[4], gme_vector2d* pd2Pnt, gme_vector3d* pd3Pnt);

		//计算直线方程的系数
		//直线方程1:AX + BY + C = 0. 
		//返回值：三个系数：A，B，C
		static long GetCoefOfLin(gme_vector2d *pOriPnt, gme_vector2d *pEndPnt, double *A, double *B, double *C);
		//计算平面方程系数
		static long  GetPanelCoef(double pPanelDots1[3], double pPanelDots2[3], double pPanelDots3[3], double pdCoef[4]);
		//将线段的两端延长
		static void  ExtendALinSeg(gme_vector2d *pLinDot, long lLinDotNum);

		//将点插入到线中...
		static void insert_pnt_to_lin(vector<gme_vector3d>& lin, gme_vector3d& dot);
		//计算顶面或底面的纹理坐标...
		static void calTopSurfTexCoord(gme_tex_coord* surfTexCoords, gme_vector3d* surfPnts, long lPntNum, gme_rect_2d* rsImageBox, double texRateX = 1, double texRateY = 1);
		//计算侧面的纹理坐标
		static void calSideSurfTexCoord(gme_tex_coord* surfTexCoords, gme_vector3d* surfPnts, long lPntNum, vector<vector<gme_vector3d>>* poly = nullptr, double texRateX = 50, double texRateY = 2);


		// ------------------ 获取点/线/面元缺省图形参数 ------------------- //
		static GM_REG_INFO * cmGetRegDefParam(void);
		static GM_LIN_INFO * cmGetLinDefParam(void); //点参数获取目前不够完善
		static GM_PNT_INFO * cmGetPntDefParam(char pntType);


		// ---------- 获取无损表示数据的小数点位数函数 ---------- //
		static short  cmGetDecimalDigitsByDat(double ztDat);
		// 由起点、终点数据获取注记有效步长
		static double cmGetStepNumb(double sfDat, double efDat, double *noteBeg = nullptr, vector<double>* noteVals = nullptr);


		// ------------------------------- 判断比较类函数 -------------------------------------- //
		// 重复点判断--
		static bool IsSameDOT(gme_vector2d *p1, gme_vector2d *p2, double pre = 1e-6);
		static bool IsSameD3DOT(gme_vector3d *p1, gme_vector3d *p2, double pre = 1e-6);
		static bool is_same_point(const gme_vector2d &point1, const gme_vector2d &point2, double esp = 1E-6);
		static bool is_same_point(const gme_vector3d &point1, const gme_vector3d &point2, double esp = 1E-6);
		static bool IsSame3DDot_Prec(gme_vector3d &dot1, gme_vector3d &dot2, double dPrec = 1E-6);
		static bool IsSame3DDot_Prec(double * pdot1, double * pdot2, double dPrec = 1E-6);
		static int compare_vector_3d(const gme_vector3d& dotA, const gme_vector3d& dotB, double esp = 1E-6);

		//坐标点比较.
		static long  IsSame2DDot(gme_vector2d *Pnt1, gme_vector2d *Pnt2);
		static int compare_vector2d(const void *p1, const void *p2);
		static int compare_vector3d(const void *p1, const void *p2);
		static int D_3DOTCompare(const void *p1, const void *p2, double esp = -1);
		static int compare_vector3d_idx(const void *p1, const void *p2);
		static int tri_topo_edge_compare(const void *p1, const void *p2);
		static bool is_same_dir(int& a, int& b, int& c, int& n1, int& n2);

		// 对相交线进行大小判断
		static int intCompare(const void *p1, const void *p2);
		static int longCompare(const void *p1, const void *p2);
		static bool IsEqual(double a, double b, double absError = 1E-4, double relError = 1E-6);

		//设置容差
		static void SetTolerance(double eps);
		static void SetDefTolerance();
		//添加点到点集
		static void add_dot_to_set(set<gme_vector3d>& valset, gme_vector3d& val);

		// 去除重复点
		static void remove_repeated_dots(vector<gme_vector3d> &vec);
		static void _remove_repeated_dots_2d(vector<gme_vector2d> &vec);

		//去除线上的重复点
		static void RemoveRepeatDots(vector<int>& lin, double drec = 1E-6);
		static void RemoveRepeatDots(vector<gme_vector2d>& lin, double drec = 1E-6);
		static void RemoveRepeatDots(vector<gme_vector3d>& lin, double drec = 1E-6);

		// 删除重复一维点
		static void RemoveSameDotsTemp(vector<double>  &DotVec);
		//判断三角形是否合法
		static bool IsLegalTri(gme_vector3d *pTriDot1, gme_vector3d *pTriDot2, gme_vector3d *pTriDot3);


		// ------------------------------- 各种排序方法 -------------------------------------- //
		static void  BubbleSort(long *pDatas, long lNum);
		static long  bin_search(long key, long *px, long n);
		static long  SearchFronFToB(long key, long *px, long n);
		static long  bin_search_byMap(long key, map<long, long>* px);
		static void  BubbleSortByVector(vector<long>* pDatas);
		static long  SearchFronFToBByVector(long key, vector<long>* pVec);
		//寻找三角化后的点数组中每个点在原来点数组中的位置
		static long FindTriPntPosInOldBuf(gme_vector3d &tinPnt, gme_vector3d *pPnt, long lPntNum);



	private:
		//点与多边形的位置关系判断算法,为处理交点在多边形上的情况
		static short  PtInPolygon(gme_vector2d* ptPolygon, long nCount, gme_vector2d& p);
		static short  LocalIsInPoly1(struct F_DOTNOD *pp, short type);
		static short  LocalOrderList(gme_D_DOT *xyin, long in, struct F_DOTNOD *xy, long nMaxY, long nMinY, long *nowNum, short nDir);

		static double m_xySPan;
	};


	//二三维数据转换
	class LIB_GMKERMATH_EXP s3d_CoordTrans
	{
	public:
		s3d_CoordTrans();
		~s3d_CoordTrans();

	public:
		//设置定位点和比例等参数（坐标转换前，此函数必须先调用）
		int setAnchorDatas(s3d_AnchorPnt * pAncPnts, long AnchNum, long yRate, long xRate = 1000, bool bCut = false, bool bCalMap = false);

		//计算侧面纹理坐标，计算之前，先要调用setAnchorData函数传入定位点和比例尺.
		//surfTexCoords: 纹理坐标缓冲； surfPnts：顶点坐标缓冲，lPntNum：顶点个数；zmin，zmax：模型z值的范围
		void calSideSurfTexCoord(gme_tex_coord* surfTexCoords, gme_vector3d* surfPnts, long lPntNum, double zmin, double zmax, double texScaleX=1, double texScaleY = 1);

		// 二维多边形转换为三维剖面
		int poly2Surf(s3d_Polygon * pPoly, gmeSurface * pSurf);

		// 二维坐标点转换为三维坐标
		int dots_2d_2_3d(gme_vector2d *pInPnt, gme_vector3d *pOutPnt, long dotNum);

		// 三维坐标点转换为二维坐标
		int dots_3d_2_2d(gme_vector3d *pInPnt, gme_vector2d *pOutPnt, long dotNum);



	private:
		// 定位点排序，按照X坐标，从小到大排列
		void SortAnchors();

		// 三维转二维时，自行计算定位点的图上坐标
		int  CalAnchorPntVal();

		// 定位轨迹线与多边形相交后，对多边形进行更新
		int  UpdatePolyByCtrlLine(vector<gme_vector2d> &vecPoly, vector<gme_vector2d> &vecPolyOut);

		// 添加钻孔轨迹控制线
		int  AppendCtrlLines(vector<vector<gme_vector2d>> &vecPoly, vector<gme_vector2d> &dConsLinDotsVec);

	private:
		s3d_AnchorPnt * m_pAncPnts;  //定位点信息
		long            m_AnchNum;   //定位点数目
		long            m_xRate;     //横向比例尺
		long            m_yRate;     //纵向比例尺
		bool            m_bCalMap;   //是否计算定位点的图上坐标值
		double          m_dYMap;     //2d图上Y坐标偏移量
		bool            m_bCut;      //是否在定位点处裁剪多边形
	};

}
