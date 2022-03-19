#pragma once

#include <map>
#include <vector>
using namespace std;


#include <s3d_KerGeoFaultExp.h>
#include <s3d_GeomDefine.h>
#include <s3d_KerGeomodelDef.h>
#include <s3d_KerDemOperDef.h>
#include "gmeEntity.h"


namespace Smart3dMap
{
	struct  FAULT_INNER
	{
	public:
		string     faultNo; //断层编号
		int        faulidx; //断层索引
		char       cflg;    //0头/1尾
		int        count;   //引用计数

	public:
		FAULT_INNER()
		{
			clear();
		}
		void clear()
		{
			faultNo = "";
			faulidx = -1;
			cflg = -1;
			count = 0;
		}
	};

	//断层面建模实现类
	class S3D_KERGEOFAULT_EXP s3d_FaultMdlingInner
	{
	public:
		s3d_FaultMdlingInner(void);
		~s3d_FaultMdlingInner(void);

	public:
		// 创建断层面模型
		int   CreateFaultSurfaces(vector<s3d_FaultLine>    &Fault, double depth, int num,
			unordered_map<string, s3d_Pointer<gmeSurface>> &outSurf);

		// 根据断层编号及连通性生成断层面
		int   CreateFaultSurfaces2(vector<s3d_FaultLine>  &Fault, double depth, int num,
			map<string, vector<vector<int>>>             &FaultNos,
			map<string, vector<vector<gme_vector3d>>>    &FaultDot,
			map<string, vector<s3d_FaultLine>>           &MapFault,
			map<string, vector<s3d_Pointer<gmeSurface>>> &outSurfs);

	public:
		// 倾角必须大于0,小于90.水平岩层不适用于这种方法
		int   CalSegMent(double ang, int num, double MaxEsp, vector<double> &Des);

		// 计算属性扩展...
		int   CalAttExtend(gme_vector3d &Ori, double Dir, double Ang, double dis, gme_vector3d &Des);

	public:
		// 重复点处理 
		int   RemoveRepeated(vector<s3d_FaultLine> &FaultVec);

		// 计算断层信息
		int   CalcuFaultInfo(vector<s3d_FaultLine> &FaultVec);

		// 结点信息处理
		void  CalculNodeInfo(s3d_FaultLine &FaultA, s3d_FaultLine &FaultB);

		// 创建一个断裂面
		int   CreateFaultSurf(s3d_FaultLine &Fault, double depth, gmeSurface &outSurf);

		// 创建一个断裂面
		int   CreateFaultSide(gme_vector3d  *pDotsTop, gme_vector3d *pDotBtm, int num, gmeSurface *pSurf);

		// 创建所有的断裂面
		int   CreateFaultSurface1(s3d_FaultLine &Fault, double depth, int num, gmeSurface &outSurf);

		// 创建所有的断裂面
		int   CreateFaultSurface2(s3d_FaultLine &Fault, double depth, int num, gmeSurface &outSurf);

		// 利用空间位置关系对断裂线进行重组
		int   GroupFaultByGeometry(vector<s3d_FaultLine> &FaultVec,
			vector<vector<int>>   &FaultNoVec,
			vector<vector<gme_vector3d>> &d3DotsVec);

		// 利用断裂编号对断裂线进行重组
		int   FaultGroupByNo(vector<s3d_FaultLine> &FaultVec, map<string, vector<s3d_FaultLine>> &MapFault);
	};

	//构建断层面框架模型...
	class S3D_KERGEOFAULT_EXP CFaultModeling
	{
	public:
		CFaultModeling();
		~CFaultModeling();

	public:
		/** 设置参数 */
		int  SetParam(CalDemZValBas *pDem, double dGap, double dzVal, int segnum);

		/** 初始化数据 */
		int  LoadFaultDatas(vector<s3d_Polygon*>   &outPolys,     //多边形格网
			vector<s3d_FaultLine*> &faultLines); //断层线数据...

		/** 创建初步框架模型 */
		int  CreateInitialModels(vector<gmeSurface*>   &TopSurfs,
			vector<gmeEntity*>    &outEnties,
			vector<gmeSurface*>   &SideSurfs,
			map<string, vector<vector<gmeSurface*>>> &FaultSurfs);

	public:
		int  CreateComplexModel(CalDemZValBas *pDem, double dGap, //输入参数
			double dzVal, int segnum,  //输入参数
			vector<s3d_Polygon*>   &outPolys,   //输入参数
			vector<s3d_FaultLine*> &faultlins,  //输入参数
			vector<gmeSurface*>   &TopSurfs,   //输出参数
			vector<gmeEntity*>    &outEnties,  //输出参数
			vector<gmeSurface*>   &SideSurfs,  //输出参数
			map<string, vector<vector<gmeSurface*>>> &FaultSurfs);

	public:
		int  CalFaultZval();
		int  CalFaultPnts();
		int  ExtendToBoundary();
		int  CreateFaultIndex();
		int  ExtendToOtherFault();
		int  CreateTopSurfaces();
		int  CreateSideSurfaces();
		int  CreateFirstFaults();
		int  CreateFaultRelation();
		int  ExtendAllFaultlines();
		int  RebuildAllFaultSurfs();
		int  SideSurfCutFaultSurfs();
		int  CreateFaultEntity();

	public:
		int  getlines(vector<vector<gme_vector3d>> &linesvv);
		bool isOnLine(long * ne, long nelen, long lindexA, long lindexB);
		int  CreateFaultSurface(s3d_FaultLine &Fault, gmeSurface &outSurf);
		int  SelectSurfsDatas(FAULT_INNER * pFault, vector<gmeSurface*> &vec);
		void RemoveRepeatDots(gme_vector3d * pLine, long &lnum, double drec);
		int  Search3dPntDatas(vector<gme_vector3d> &AllLins, s3d_Polygon *pPoly);
		int  judgeSurfofBndry(gmeSurface * pSurf, vector<gme_vector3d> &SideLins);
		int  CalExtendline(FAULT_INNER &fal, double ExtDis, s3d_FaultLine &FaultLine);
		int  FaultPolyToSurf(s3d_Polygon * pPoly, gmeSurface * pSurf, double dgap);
		bool isPntInRect(gme_vector3d &dot, gme_rect_2d &rect, double dPrec = 1e-4);
		int  judgelineoflins(vector<gme_vector3d> &lin1, vector<gme_vector3d> &lin2);
		int  JudegRectByRect(gme_rect_2d &rect1, gme_rect_2d &rect2, double dPrec = 1e-4);
		int  PolyToBottomSurf(vector<gme_vector3d> &poly, gmeSurface * pSurf, double dgap);
		int  BtmToSur(vector<vector<gme_vector3d>> &poly, gmeSurface * pSurf, double dgap);
		int  judgeSurfofFault(gmeSurface * pSurf, gme_vector3d &faultdot, double esp = 1e-4);
		bool isPntOnLine(gme_vector3d &dot, vector<gme_vector3d> &d3dots, double dPrec = 1e-4);
		int  FaultLinsToPoly(vector<vector<gme_vector3d>> &inlines, vector<PolyRef> &outPolys);
		bool IsAnylineOnPolyEx(vector<gme_vector3d> &anylin, vector<vector<gme_vector3d>> &pPolyEx);
		int  linkLines(vector<s3d_FaultLine> &fauVec, vector<int> &idxVec, vector<gme_vector3d> &pntsVec);
		bool PntOn3DPoly(gme_vector3d *pdot, gme_vector3d *pEx, long *ne, long nelen, long &lindex, double dPrec = 1e-4);
	private:
		// 释放三维面数据
		void ReleaseDatas(vector<gmeEntity*>  &vec);
		void ReleaseDatas(vector<gmeSurface*> &vec);
		void ReleaseDatas(map<FAULT_INNER*, gmeSurface*> &vec);
		void ReleaseDatas(map<string, vector<vector<gmeSurface*>>> &vec);

		int  GetDotOfFault(FAULT_INNER &in, gme_vector3d &dot);
		int  GetFaultInfo1(FAULT_INNER *pIn, FAULT_INNER **ppOut);
		int  GetFaultInfo2(FAULT_INNER *pIn, vector<FAULT_INNER*> *pOut);
		int  FindSideSurfs(int idx, vector<gmeSurface*>  &SideSurfs);
		int  FindFaultSurfs(int idx, vector<gmeSurface*>  &FautSurfs);
		int  FindCombineFaultSurfs(gmeSurface *psf, vector<gmeSurface*> &sfs);

	public:
		CalDemZValBas        * m_pDem;        //DEM数据指针
		double                 m_dGap;        //中间加密格网间距
		double                 m_dzVal;       //建模底部高程，底部平推处理
		int                    m_segnum;      //断层分段数...
		vector<s3d_Polygon*>   m_outPolys;    //多边形格网...
		vector<s3d_FaultLine*> m_faultLines;  //断层线数据...
		s3d_FaultMdlingInner  m_GeoMapModel; //断层建模类...

	public:
		gme_rect_2d            m_allRect;     //全区rect
		gmeSurface             m_SideSurf;    //全区侧面模型
		vector<gme_vector3d>   m_SideLins;    //全区顶部边界
		vector<gme_rect_2d>    m_TopRects;    //顶部层面RECT
		vector<gmeSurface*>    m_TopSurfs;    //顶部层面格网 \需要在外面释放
		vector<gmeEntity*>     m_Entities;    //最终体模型,\需要在外面释放
		vector<gme_rect_2d>    m_SideRects;   //侧面模型RECT
		vector<gmeSurface*>    m_SideSurVec;  //侧面模型数据 \需要在外面释放

	public:
		vector<FAULT_INNER>                     m_allFaults; //所有断层数据
		map<FAULT_INNER*, gmeSurface*>         m_faultSurf; //辅断层对应的延伸面 析构时清空
		map<FAULT_INNER*, FAULT_INNER*>           m_faultMap1; //辅断层对应的主断层...
		map<FAULT_INNER*, vector<FAULT_INNER*>>   m_faultMap2; //主断层对应的辅断层...

	public:
		map<gmeSurface*, FAULT_INNER>                m_SurfFlag;  //侧面、断面对应的信息
		map<gmeSurface*, vector<gme_vector3d>>    m_SurfBdary; //顶面、侧面、断面对应的边界线数据...
		map<string, vector<gme_rect_2d>>          m_Rect2D;    //每个断层编号 对应的断层数据...
		map<string, vector<vector<int>>>          m_pFaultNos; //每个断层编号 对应的断层数据...
		map<string, vector<vector<gme_vector3d>>> m_pFaultDot; //每个断层编号 对应的断层数据...
		map<string, vector<s3d_FaultLine>>        m_pMapFault; //每个断层编号 对应的断层数据...

		map<string, vector<s3d_Pointer<gmeSurface>>> m_pOutSurfs;  //每个断层编号   对应的断层数据...
		map<string, vector<vector<gmeSurface*>>>     m_pLinkSurfs; //m_pLinkSurfs 剪切后的所有面\需要在外面释放
		map<string, vector<vector<gme_rect_2d>>>     m_pLinkRects; //m_pLinkSurfs 剪切后的所有面

	public:
		vector<vector<gme_vector3d>>                  m_linesvvTemp;
	};

	//含断层的地层面、地层体建模
	class S3D_KERGEOFAULT_EXP CStratumModeling
	{
	public:
		CStratumModeling();
		~CStratumModeling();

	public:
		int  SetParam(vector<gmeEntity*>      &FrameEntyVec,    // 输入数据：断层框架
			vector<s3d_BoreHole>    &BoreHolesVec,    // 输入数据：钻孔数据
			vector<s3d_BaseLayer>   &BasLayersVec,    // 输入数据：基本层序
			s3d_MdlParam            &GeoMdlingParam,  // 输入数据：建模参数
			vector<s3d_GeoPolygon>  *pResPolygon,     // 输入数据：地表约束多边形数据
			bool                     bFlg = false,    // 是否强约束断层边界线
			double                   buffer = 1000,   // 范围缓冲半径：大于0...
			CalDemZValBas           *pCalDem = NULL); // 输入数据：DEM对象

		int  CreateStratEntities(map<string, vector<EnyRef>> &OutEntitiesMap, vector<EnyRef> *pFaultCutBox);

		int  CreateStratumModel(vector<gmeEntity*>       &FrameEntyVec,    // 输入数据：断层框架
			vector<s3d_BoreHole>     &BoreHolesVec,    // 输入数据：钻孔数据
			vector<s3d_BaseLayer>    &BasLayersVec,    // 输入数据：基本层序
			s3d_MdlParam             &GeoMdlingParam,  // 输入数据：建模参数
			CalDemZValBas            *pCalDem,         // 输入数据：DEM
			vector<s3d_GeoPolygon>   *pResPolygon,     // 输入数据：地表约束多边形数据
			vector<EnyRef>           *pFaultCutBox,    // 输出数据：断层裁切体
			bool                      bFlg,            // 是否强约束断层边界线
			double                    buffer,          // 范围缓冲半径：大于0...
			map<string, vector<EnyRef>> &OutEntitiesMap); //地层编码 对应的 地层

		int  CreateFrameEntity(gmeEntity *pFrame, gmeEntity &CutFrame, double    extend=500);

		int  getlines(vector<vector<gme_vector3d>> &linesvv);
	public:
		int  CreateAllCutEntity();
		int  CreateFrameEntity(gmeEntity * pFrame);
		int  CreateCutEntity(gmeEntity * pFrame, gmeEntity * pCutFrame, char *pflg);
		int  CreateCutEntityByTopSurf(gmeEntity * pFrame, gmeEntity * pCutFrame);

	private:
		int  SetSurfaceValue(gmeSurface * pSurf, double dz);
		int  CombineEntySurf(gmeEntity * pFrame);
		int  MoveLines(vector<vector<gme_vector3d>> &linesvv, gme_vector3d &pnt3d);
		int  JudegRectByRect(gme_rect_2d &rect1, gme_rect_3d &rect2, double dPrec = 1e-2);

		int  CreateTempSurf(gmeSurface     * pSurf,
			vector<gme_vector3d>   & bdyVec,
			vector<gme_vector3d>   & linVec,
			double  dgap, gmeEntity * pFrame);

		int  CreateGeoModel(gmeEntity      * pFrame,
			gmeSurface     * pTmpSurf,
			vector<gme_vector3d> & bdyVec,
			map<string, vector<EnyRef>> & EnyVec);

		int  CutGeoEntities(gmeEntity      * pFrame,
			map<string, vector<EnyRef>> & EnyVec);

		int  GetResLinesByPoly(vector<s3d_GeoPolygon>  &geoPoly,
			vector<vector<gme_vector3d>>   &vvlines,
			vector<vector<gme_vector3d>>   &linsOver);

		int  CreateTopResPoly(vector<s3d_GeoPolygon>          &geoPoly,
			map<string, vector<PolyRef>>   &BdaryMap);

		int  GetResMapPolyDatas();
		bool IsValidEntity(gmeEntity *pEnty);
		int  DealResLinesV(vector<vector<gme_vector3d>>  &linsOver, double exdis);
		int  ExtendLinDots(gme_vector3d &dotA, gme_vector3d &dotB, double exdis);

	public:
		bool                                      m_bFlg;            // 是否强约束断层边界线
		double                                    m_buffer;          // 范围缓冲半径：大于0...
		double                                    m_esp;             // 容差
		vector<gmeEntity*>                        m_FrameEntyVec;    // 断层框架体模型
		map<gmeEntity*, gmeEntity*>              m_MapEntyToEnty;   // 对应的裁剪体
		map<gmeEntity*, gme_rect_3d*>            m_MapEntyToRect;   // 对应的DRect
		map<gmeEntity*, s3d_Polygon*>            m_MapEntyToPoly;   // 对应的范围
		map<gmeEntity*, vector<s3d_GeoPolygon>>  m_MapEntyToRes;    // 对应的约束多边形
		map<gmeEntity*, vector<s3d_BoreHole*>>   m_MapEntyToHole;   // 对应的钻孔
	public:
		CalDemZValBas                         * m_pDem;            // 顶部DEM数据指针
		vector<s3d_BoreHole>                  * m_pBoreHolesVec;   // 输入数据：钻孔数据
		vector<s3d_BaseLayer>                 * m_pBasLayersVec;   // 输入数据：基本层序
		vector<s3d_GeoPolygon>                * m_pResPolygonVec;  // 输入数据：地表约束多边形/strDSO
		s3d_MdlParam                          * m_pGeoMdlingParam; // 输入数据：建模参数
		map<string, vector<EnyRef>>            m_OutEntitiesMap;  // 最终输出的地层体模型

	public:
		vector<EnyRef>                          m_FaultCutBox;     // 断层剪切框
		vector<vector<gme_vector3d>>            m_linesTvv;        // 三维边界线...
	};

}
