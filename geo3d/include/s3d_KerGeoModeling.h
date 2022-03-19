#pragma once
 
#include <map>
#include <vector>
using namespace std;

#include <S3d_KerGeomdlingExp.h>
#include <s3d_KerGeomodelDef.h>
#include <s3d_GeomDefine.h>
#include "s3d_KerDemOperDef.h"
#include "s3d_Queue.h"

namespace Smart3dMap
{
	class s3d_BoreHoleAnalys;
	class s3d_CalGeoBoundary;

	//多源数据联合下的三维地质结构建模类
	class  _S3D_S3DKERGEOMDLING_EXP s3d_geo_gmdling
	{
	public:
		s3d_geo_gmdling();
		virtual ~s3d_geo_gmdling();

	public:
		//多源数据联合下的三维地质结构建模
		//outEntities: 返回地层结构模型的顶底侧面内存
		void Build3dGeoStruMdl(vector<vector<EnyRef>>* outEntities = NULL);
		//mdl,topSurfs,bottSurfs,sideSurfs: 返回gme格式的地层结构模型、顶面模型、底面模型、侧面模型
		void Build3dGeoStruMdl( gmeModel* mdl = NULL, gmeModel* topSurfs = NULL, gmeModel* bottSurfs = NULL, gmeModel* sideSurfs = NULL);

		//获取地质成果模型的地表面
		int get_top_surf(gmeSurface *pOutSurf);

	public:
		// ------------------- 设置建模数据 --------------------- //
		//设置/获取 三维要素类ID
		void set_mdl_fCls(GME_TYPE_OBJ_ID	mdlFClsID);
		GME_TYPE_OBJ_ID get_mdl_fCls();

		//设置标准地层数据
		void SetBasLayers(vector<s3d_BaseLayer> &basLayersVec);
		void GetBasLayers(vector<s3d_BaseLayer> &basLayersVec);

		//设置钻孔数据
		void SetHoles(vector<s3d_BoreHole> &boreHolesVec);
		void GetHoles(vector<s3d_BoreHole> &boreHolesVec);

		//设置剖面剖面地层数据...
		void setSectionMaps(vector<s3d_SectionMap>& secMaps);
		void getSectionMaps(vector<s3d_SectionMap>& secMaps);
		//根据剖面图, 按照采样间距gapX生成虚拟钻孔数据
		vector<s3d_BoreHole>& GenVHolesBySecMaps(vector<s3d_SectionMap>& secMaps, double gapX = 0);


		//设置特殊地层对象列表
		void setSpecialGeoObjData(vector<SpecialStrat>& specalObj);
		void getSpecialGeoObjData(vector<SpecialStrat>& specalObj);

		//设置建模边界
		void SetMdlingBdry(vector<gme_vector3d> &BdryPnts);
		void GetMdlingBdry(vector<gme_vector3d> &BdryPnts);

        //设置顶部DEM点
		void SetTopDemDots(vector<gme_vector3d> &vecDatas);
		void GetTopDemDots(vector<gme_vector3d> &vecDatas);

		//设置顶部DEM
		void SetTopDem(CalDemZValBas *pCalDem);
		void GetTopDem(CalDemZValBas **pCalDem);

		//设置底部DEM
		void SetBtmDem(CalDemZValBas *pCalDem);
		void GetBtmDem(CalDemZValBas **pCalDem);

		//设置各个地层(stratOrder)的层底dem约束(钻孔底板优先级更高)
		void SetStratBtmDem(map<string, CalDemZValBas*> &BtmTiffMap);
		void GetStratBtmDem(map<string, CalDemZValBas*> &BtmTiffMap);


		//设置分布约束：当其他数据与分区不一致的时候，以分区为准...string：m_strStratOrder
		//1.地层平面分布约束
		void SetStratBdary(map<string, vector<PolyRef>> &BdaryMap);
		void GetStratBdary(map<string, vector<PolyRef>> &BdaryMap);

		//2.地表地层分布约束：
		void SetTopStratBdary(map<string, vector<PolyRef>> &BdaryMap);
		void GetTopStratBdary(map<string, vector<PolyRef>> &BdaryMap);

		//3.地底的地层分布约束：
		void SetBtmStratBdary(map<string, vector<PolyRef>> &BdaryMap);
		void GetBtmStratBdary(map<string, vector<PolyRef>> &BdaryMap);

		//4.基岩面的地层分布约束
		void SetBrtopStratBdary(map<string, vector<PolyRef>> &BdaryMap);
		void GetBrtopStratBdary(map<string, vector<PolyRef>> &BdaryMap);

		// ------------------ 设置参数 ------------------------ //
		//设置建模参数...
		void setMdlParam(s3d_MdlParam &modelingParam);
		void getMdlParam(s3d_MdlParam &modelingParam);

		//建模边界是否已加密
		void setDensBdryFlag(bool bDensFlag = true);
		//取建模边界加密标记
		bool getDensBdryFlag();

		//外部设置模板地层面... 
		void SetTemplateSurf(gmeSurface *pSurface);
		void GetTemplateSurf(gmeSurface **pSurface);
		//计算每个模板点对应的地表多边形
		int CalPntToPolygon();
		//构建模板地层面... 
		void CreateTemplateSurf();

		//设置/获取 钻孔数据预处理标记
		void setPreProcessHoleFlag(bool bFlag = false);
		bool getPreProcessHoleFlag();

		//设置进度条显示标志
		void setProcessBarDispFlag(bool bDispFlag = true);
		bool getProcessBarDispFlag();

		//是否对特殊地层进行bool运算...
		void setBooleanOperFlag(bool bFlag = true);
		bool getBooleanOperFlag();

	public:
		//构建目标区域地表DEM面...计算顶面高程值
		void CreateTopSurf();
		//构建目标区域底部面
		void CreateBtmSurf();

		//钻孔数据预处理
		static void preProcessHoles(vector<s3d_BoreHole>& BoreHoleDatas, vector<s3d_BaseLayer> &BaseLayerDatas, s3d_MdlParam &modelingParam);
		//剔除建模多边形范围外的钻孔
		static void TickHolesByPoly(vector<s3d_BoreHole>& boreHolesVec, vector<gme_vector3d>& vecBoundary);
		//剔除建模矩形范围外的钻孔
		static void TickHolesByRect(vector<s3d_BoreHole>& boreHolesVec, vector<gme_vector3d>& vecBoundary);
		//将建模深度以下的钻孔分层去掉
		static void TickHoleLayersUnderADepth(vector<s3d_BoreHole>& boreHolesVec, double btmZval);
		//相邻钻孔层层序相同则合并处理
		static void CombineHoleDatas(vector<s3d_BoreHole> &boreHolesVec);


	private:
		//释放对象
		void ReleaseBuf();

		//初始化地层分布类...
		int SetTopStratBdary();
	
		//根据地层级别，构建对应的地层体结构面模型
		int CreateEntTopBtmByLevel(int nlevel,    //输入参数：地层级别
			vector<s3d_BaseLayer>  &basLayersVec,   //输出参数：该级别对应的层序
			vector<s3d_TopBtmEnty>   &EntityTmpVec); //输出参数：该级别对应的地层体结构面
		//三维面构建地层体算法
		int CreateEntityByTopBtm(s3d_TopBtmEnty* pEntTmp, vector<EnyRef> &EnyVec);


		//获取地层顶底面数据, 成功返回1，不成功返回0
		int GetStratSurface(string strLevel, s3d_TopBtmEnty &strEnty);

		//计算存在标记...
		int CalStratExistFlag(char * pFlag, s3d_TopBtmEnty &strEnty);

		//创建一级地层面
		int CreateFirstStratSurf(long curLevel, vector<s3d_TopBtmEnty> &EntityTmpVec);
		//创建二级、三级、等多级地层面
		int CreateOtherStratSurf(int curLevel, int maxLevel, vector<s3d_TopBtmEnty> &EntityTmpVec);

		//利用底部约束界限 对模型进行截断处理...2020-11-7 CEO
		int CutEntityByBtmRes(vector<s3d_TopBtmEnty>    &EntityTmpVec);


		//获取所有钻孔数据的孔口点位信息 
		int GetAllHoleTopDots(vector<gme_vector3d> &DotVec);

		//获取所有钻孔数据的底部点位信息 
		int GetAllHoleDatasBtm(vector<gme_vector3d> &DotVec);

	
	private:
		// 获取所有钻孔数据的孔口点位信息
		int GetHoleDatasXYZ(gme_vector3d** holePos);
		//边界点加密
		int InsertBoundaryPoints();
		//边界内部点加密
		int InsertLabelAreaPoints(vector<gme_vector3d>& mdllingBdryPnts, double xGap, double yGap, gme_vector3d** pInsertDots, long* dotNum);

		// 创建标准面数据:返回0则表示创建面失败
		int CreateStandardSurface();

		// 计算每个strcode对应的序号...
		int CalStrcodeToIndex(map<string, int> &mapstrcode);


		//调整z值
		void CalAdjustZVVal(long currentLayNo, s3d_TopBtmEnty &enty, double eps);
		void CalAdjustdZTBResVVal(long currentLayNo, s3d_TopBtmEnty &enty, double *dzp, double eps);

		//处理地层的顶底0厚度, 对三维面进行相交处理和更新
		int processStratSurface(long currentLayNo, gmeSurface *pSurf, double *pTop, double *pBtm, 
			gmeSurface  *pOutSurf, double **pOutTopZ, double **pOutBtmZ, double eps);
		// 多级模式、顶底约束， 没有多边形约束
		int processStratSurface4(long currentLayNo, gmeSurface *pSurf, double *pTop, double *pBtm, double *pCurZ, char *pFlg,
			gmeSurface  *pOutSurf, double **pOutTopZ, double **pOutBtmZ, double eps);
		// 多边形约束的多级模式...
		int processStratSurface5(long currentLayNo, gmeSurface *pSurf, double *pTop, double *pBtm, double* pCurZ, 
			gmeSurface  *pOutSurf, double **pOutTopZ, double **pOutBtmZ, double eps, char **ppExist, vector<int> &LayerVecN, int idxCur);

		// 根据缺失范围强行调整点坐标后，对其余点进行平滑校正 2020-12-21
		int SmoothGmeSurface_1(long currentLayNo, s3d_TopBtmEnty &entyTmp);
		// 根据缺失范围强行调整点坐标后，对其余点进行平滑校正 多级模式...
		int SmoothGmeSurface_n(long currentLayNo, double *pCurTopZ, double *pCurBtmZ, 
							   s3d_TopBtmEnty &entyTmp, char **ppExist, vector<int> &LayerVecN, int idxCur);
		// 缓冲调整校正... 2021-1-3 CEO
		int  Adjust_Buffer(long currentLayNo, s3d_TopBtmEnty &entyTmp, char **ppExist, vector<int> &LayVec, int idxCur);
		// 获取层位点的存在标记...
		int GetStratExistByParentRes(long currentLayNo, gmeSurface *pSurf, char *pFlg, char *pExist);

		// 计算该层的尖灭点位置...pinchNo为尖灭点在全局模板面中的序号
		int  CaluPinchDots(s3d_TopBtmEnty &entyTmp, char **ppExist,
			               vector<int> &LayVec, int idxCur, 
			               gme_rect_2d &rect, vector<int> &pinchNo);


	private:
		// 三角形的边排序
		void QsortTriEdge(s3d_TriEdg* pEdge);
		// 去除重复的三角边数据
		void RemoveRepeatedDatas(vector<s3d_TriEdg> &vecOut);
		void RemoveRepeatedDatas(vector<s3d_InsecLin> &vecOut);
		// 三角边进行大小判断
		int  EdgeLineCompare(s3d_TriEdg *pEdge, s3d_InsecLin *pInsecLin);
		// 取出所有的三角形边
		int  GetAllTinEdges(gmeSurface* pSurf, vector<s3d_TriEdg> &Edg1, vector<s3d_TriEdg> &Edg2, vector<int> &TriNo);
		// 获取需要更新的交线信息
		int  GetValidInsecLines(vector<s3d_InsecLin> &InsectVec, vector<s3d_InsecLin> &outLinVec, vector<int> &TriNoIdx);
		// 更新三角边数据?
		int  GetNewTriEdges( gmeSurface* pSurf, double *pTopZ,
							 vector<s3d_TriEdg> &Edge2, 
			                 vector<s3d_TriEdg> &EdgeVec,
			                 vector<s3d_InsecLin> &SectVec, 
			                 vector<vector<gme_vector3d>> &EdgeVecVec);
		// 设置交线信息
		void SetSectDatas( int idx, int dotNo, double *pZ, 
			               gme_vector3d *pDots, s3d_InsecLin & sectObj);
		// 计算交点信息
		void CalSectDatas( int idx, int dotNo1, int dotNo2, double *pDisZ,
			               double *pTopZ, gme_vector3d *pDots, s3d_InsecLin &sectObj);
		// 计算地层三角网的交线
		int  CalLayerTinSectLines(gmeSurface   * pSurf, double* pTopZ, double* pBtmZ, vector<s3d_InsecLin> &LineVecOut, double eps);

	private:
		//距离反比批量插值计算高程
		int CalSurfZVal(gme_vector3d *pDots, int dotNum, vector<gme_vector3d> &DotsVec, double radius = 0.0);
		int CalSurfZVal(double *pZValue, gme_vector3d *pDots, int dotNum, vector<gme_vector3d> &DotsVec);
		int CalSurfZVal_withIdx(double *pZValue, gme_vector3d *pDots, int dotNum, vector<gme_vector3d> &DotsVec);

		// 多层B样条计算高程点，
		int CalSurfZ_MSpline(double *pZValue, gme_vector3d *pDots, int dotNum, vector<gme_vector3d> &DotsVec, gme_rect_2d *pRect = NULL);
		// 计算并调整高程值- 厚度模式
		int CalAdjustSurfZThick(double *pZValue, gme_vector3d *pDots, int dotNum, vector<gme_vector3d> &Vec, double *pTops);
		// 调整地层面高程值
		int CalAdjustSurfZDir(double *pZValue, gme_vector3d *pDots, int dotNum, vector<gme_vector3d> &Vec, double *pTops, double esp, double dir, double dAng = 0);

		// 基于基底DEM约束，计算基底坐标...
		int CalBotDEMSurfZVal(double *pZVal, gme_vector3d  *pDots, int nDotNum);
		int CalBotDEMSurfZVal(CalDemZValBas *pDem, double *pZVal, gme_vector3d  *pDots, int nDotNum);

	private:
		//级别解析=获取地层级别
		static int  GetLevels(vector<s3d_BaseLayer> &stdlayer);

		// 释放三角形数据
		void ReleaseTriDatas(vector<s3d_TriTopos> &AllTriVec);

		//数字级别转换成字符串编码
		string leveltostr(vector<string> &strLevelVec);

		//获取指定地层级别下的地层编码
		void GetStrByLevel(vector<string> &strvec, int level);

		//字符编码转换成数字
		static void strCodeToVecInt(string &strcode, vector<string> &vec);
		static void strToVecByLevel(string &strcode, vector<string> &vec, int level = 1);
		static void strToVecByLevel(string &strcode, string &straCombine, int level = 1);

		//计算地层面的高程值...
		int  CaldotZVal(gme_vector3d *pDot, vector<gme_vector3d> &holes, vector<gme_vector3d> &LackDots, double dz = 0.0);

		// 计算内部标记数组
		int  SetTriangleExist(gmeSurface *pSurf, double* pTopZ, double* pBtmZ, 
							  char *pDzFlag, char *pTriFlg, int &idx, double eps);

		// 计算子网, 获取一个子面
		int  GetConnectedSurf(char *pTriFlg, gme_triangle_top *pTopos, s3d_QueueCls *pQueue, int Index, char *pVisit);
		// 创建侧面模型，适用于顶底边界点数目一致，且一一对应的情况---需要进行分离
		int  CreateSideSurface(gme_vector3d *pSurfDotsTop, gme_vector3d *pSurfDotsBtm, int nDotNum, gmeEntity *pEnty);
		
		int  SplitStdSurf(gmeSurface *pSurf, gmeEntity * pEnty);
		int  SplitStdSurf(gmeSurface *pSurf, vector<gmeSurface*> &pSurfVec);

		// 索引变换
		int  TransformPntIdx(int num, gme_vector3d *pDots, s3d_TriTopos &SurfObj, vector<gme_vector3d> &VecDots);
		// 获取一片连通的三角形集合
		int  GetConnectSurf(char *pFlag, gme_triangle_top *pTopos, s3d_QueueCls *pQueObj, int headIndex, char *pUsed);
		// 点序列变换过程
		int  TransformPntIndex(gmeSurface *pSurf, double* pTopZ, double* pBtmZ, 
							   s3d_TriTopos &SurObj, vector<gme_vector3d> &VecDots, vector<double> &VecTopZ, vector<double> &VecBtmZ);




		//根据地层编码合并地质体
		static void UnitEnt(vector<Smart3dMap::s3d_BaseLayer>& stdlayerdatas, vector< vector<Smart3dMap::EnyRef> >& entslist);
		//根据地层级别编码取地层编码...
		static string getStratCodeByLevelCode(string levelCode, vector<s3d_BaseLayer>& standlayer);
		static s3d_BaseLayer* getStandStratByLevelCode(string levelCode, vector<s3d_BaseLayer>& standlayer);
		//根据地层编码取地层级别编码...
		static string getLevelCodeByStratCode(string stratCode, vector<s3d_BaseLayer>& standlayer);
		static s3d_BaseLayer* getStandStratByStratCode(string stratCode, vector<s3d_BaseLayer>& standlayer);
		//根据钻孔编码找到钻孔信息...
		static s3d_BoreHole* getHoleInfoByHoleCode(string holeCode, vector<s3d_BoreHole>& boreholedatas);

		//建立特殊地质体模型:透镜体\孤石\脉岩模型
		void BuildSpecialMdl(vector<s3d_BoreHole>& boreHoles, vector<s3d_BaseLayer>&stdlayerdatas, vector< vector<Smart3dMap::EnyRef> >& entslist);
		void BuildSpecialMdl(vector<SpecialStrat>& specialStrat, vector< vector<Smart3dMap::EnyRef> >& entslist);

		//处理特殊地质体与地层模型的叠加关系，执行实体相减操作 2021-4-14 
		void ModelCutSpecial( vector< vector<Smart3dMap::EnyRef> >& entsA, 
			                  vector< vector<Smart3dMap::EnyRef> >& entsB );
		//更新地层的材质
		void UpdateOrdinaryLayerMat(vector<s3d_BaseLayer>& stdlayerdatas, vector< vector<Smart3dMap::EnyRef> >& entslist);
		void UpdateSpecialLayerMat(vector<s3d_BaseLayer>& stdlayerdatas, vector< vector<Smart3dMap::EnyRef> >& entslist);


	private:
		//1. 建模数据源

		//1.1 标准地层
		vector<s3d_BaseLayer>          *m_pBasLayers;      //标准地层数据
		vector<s3d_BaseLayer>           m_LevBasLayers;    //多级模式下的标准分层

		//1.2 Dem数据
		vector<gme_vector3d>           *m_pTopDemDots;     //地表离散点约束数据
		CalDemZValBas                  *m_pTopDemObj;      //地表DEM计算类
		CalDemZValBas                  *m_pBtmDemObj;      //底部DEM计算类
		map<string, CalDemZValBas*>     m_stratOrder2BtmDem;//地层编码to地层底部dem

		//1.3 钻孔
		s3d_BoreHoleAnalys             *m_pHolesObj;       //钻孔处理类对象
		vector<gme_vector3d>			m_holeDots;        //钻孔的点坐标
		vector<s3d_BoreHole>           *m_pBoreHoles;      //钻孔数据
		vector<s3d_BoreHole>            m_levHoles;        //多级模式下的钻孔
		vector<SpecialStrat>		   *m_specialStrat;    //特殊地质体

		//1.4 剖面图数据
		vector<s3d_SectionMap>*			m_secMaps;	//剖面图数据	
		vector<s3d_BoreHole>			m_vHoleData;//剖面图生成的虚拟钻孔数据...


		//1.5 地层分区数据约束:优先级最高的约束
		map<int, string>                m_tmplatePntIdx2PolyStratOrder;//模板点索引to地表地层分区
		map<string, vector<PolyRef>>    m_stratOrder2Bdry;    //1.地层编码to地层范围
		map<string, vector<PolyRef>>    m_stratOrder2TopBdry; //2.地层编码to地表地层范围；
		map<string, vector<PolyRef>>    m_stratOrder2BtmBdry; //3.地层编码to地底地层范围；
		map<string, vector<PolyRef>>    m_stratOrder2BrtopBdry;//4.地层编码to基岩面地层范围；

		map<string, string>             m_stratOrder2LevOrder;//地层order对应的级别Order
		s3d_CalGeoBoundary             *m_pStratBdryObj;//顶部地层分布计算对象


		//2. 参数

		//2.1 建模参数，边界等
		gme_rect_2d                     m_d2MdlingRect;    //全区2D建模范围
		gme_rect_3d						m_d3MdlingRect;    //全区3D建模范围
		s3d_MdlParam                    m_mdlingParam;     //建模参数

		vector<gme_vector3d>			m_denseBdryPnts;   //最终加密后的建模边界数据
		vector<gme_vector3d>            m_sortDenseBdryPnts;//排序后的加密建模边界离散点
		bool							m_bDensBdryFlag;   //建模边界是否已加密
		bool							m_bPreProcessHoleFlag; //是否对钻孔数据进行了预处理...
		bool							m_bDispProcessBarFlag; //是否显示进度条
		bool							m_bBooleanOperFlag;	   //是否对特殊地质体与地层bool运算

		//2.2 模板面相关参数
		bool                            m_bUseOuterTmplSurf;//使用外部标准面
		gmeSurface                     *m_pStdSurface;     //初始标准面数据
		gmeSurface                     *m_pBtmSurface;     //初始底部面数据


		//3. 建立的模型
		map<string, s3d_TopBtmEnty>     m_stratLevel2EntBuf;//级别编码 to 地层体面约束  //建模过程中的内部网格结构
		GME_TYPE_OBJ_ID				    m_3dMdlFClsID;     //要素类ID
		gmeModel                       *m_gmeMdl;          //模型
		gmeModel					   *m_gmeTopSurfs;     //模型顶面
		gmeModel                       *m_gmeBottSurfs;    //模型地面
		gmeModel                       *m_gmeSideSurfs;    //模型侧面
	};


}
