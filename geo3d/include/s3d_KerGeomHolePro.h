#pragma once
 
#include <map>
#include <vector>
using namespace std;

#include <s3d_KerGeomHoleProExp.h>
#include <s3d_KerGeomodelDef.h>
#include "s3d_explicit_stru.h"

namespace Smart3dMap
{


	//样本点数据索引管理...
	class _S3D_KERGEOM_HOLEPRO_EXP s3d_SelectSampleDatas
	{
	public:
		s3d_SelectSampleDatas();
		~s3d_SelectSampleDatas();

	public:
		//初始化样本数据
		int InitDatas(gme_vector3d * pResDatas, s_unlong dotNum);
		//根据坐标计算出索引块号
		int GetIdx(double x, double y, s_unlong &xNo, s_unlong &yNo);
		// 获取指定位置(x，y)处的样本数据
		int GetSampleDatas(double x, double y, vector<gme_vector3d> &pResDatas, s_unlong &DotNum);

	private:
		// 构建内部索引
		int CalInnerDatas();
		// 计算网格间距及对应缓冲...
		int NewInnerIndexBuffer();

	private:
		gme_rect_2d          m_Rect;     //约束矩形范围
		s_unlong             m_dotNum;   //约束点数目
		gme_vector3d       * m_pResDatas;//约束数据信息
		s_unlong             m_Xnum;     //X方向网格数
		s_unlong             m_Ynum;     //Y方向网格数
		double               m_dgapX;    //网格间距X
		double               m_dgapY;    //网格间距Y
		vector<s_unlong>  ** m_ppIndex;  //每个网格对应的点索引
		s_unlong          ** m_ppdotNum; //每个网格的点数目
	};

	//钻孔数据处理类
	class _S3D_KERGEOM_HOLEPRO_EXP s3d_BoreHoleAnalys
	{
	public:
		s3d_BoreHoleAnalys();
		virtual ~s3d_BoreHoleAnalys();

	public:
		//数据初始化
		void InitBoreHoleDatas(vector<s3d_BoreHole> * pBoreHoles, vector<s3d_BaseLayer> * pBaseLayers, s3d_MdlParam & ModelingParam);

	public:
		//顶层信息
		int GetTopInfo();

		//获取钻孔孔口处的点位信息
		int GetHoleTopDatas();

		//简化层序
		void SimplifyBaseLayer();

		//填充钻孔分层信息
		int FillHoleLayers();

		// 计算钻孔分层信息的底板高程值
		int CalBoreHoleLayerBot();
		int CalBoreHoleLayerBotRock();

		// 调整钻孔分层的高程值:
		int AdjustBoreHoleLayZVal();
		int AdjustBoreHoleLayZValRock();

		// 短钻孔延展层处理
		int CalHoleLayExtend();

		//获取所有钻孔数据底部高程的最小值
		int GetHoleBottomZVal(double &minZVal);

		// 获取所有钻孔的孔口标高值
		int GetHoleTops(vector<gme_vector3d> &vecOut);

		// 获取第idx层钻孔分层信息的顶板高程坐标（包含虚拟分层）
		int GetLayerTopZ(int idx, vector<gme_vector3d> &vecOut);

		// 获取第idx层钻孔分层信息的底板高程坐标（包含虚拟分层）
		int GetLayerBotZ(  int idx, vector<gme_vector3d> &vecOut);
		int GetLayerThickZ(int idx, vector<gme_vector3d> &vecOut);

		// 获取第idx层钻孔分层信息的厚度，
		int GetLayerThickFlg(int idx, vector<gme_vector3d> &vecOut);

		// 获取第idx层钻孔分层信息的厚度，
		int GetLayerBotLayerFlg(int idx, vector<gme_vector3d> &vecOut);

		// 获取钻孔实际分层信息的顶板高程坐标
		int GetActualHoleLayTopZVal(int idx, vector<gme_vector3d> &vecOut);

		// 获取钻孔存在标记：存在Z值为1，不存在Z值为0； bthick为true，则存在的传出厚度
		int GetHoleLayExistFlg(int idx, vector<gme_vector3d> &vecOut);
		int GetHoleBotExistFlg(int idx, vector<gme_vector3d> &vecOut, int value = 2);
		int GetHoleBotExistFlg(int idx, vector<gme_vector3d> &vecOut, int value, vector<int> &CurlayerIdx);

		//计算当前层的尖灭距离和平均厚度
		int GetlayerThick(int index, double &val, double &thick);

		//  获取基底信息:bbot父地层是否为最后一层...
		int GetBotInfo(int indx, vector<int> &vec, vector<gme_vector3d> &vecOut, bool bbot);

		// 获取钻孔实际分层信息的底板高程坐标
		int GetActualHoleLayBotZVal(int idx, vector<gme_vector3d> &vecOut, bool bflg = false);
		int GetActualHoleLayBotZVal_2(int idx, vector<gme_vector3d> &vecOut); //取非零顶底板

		// 是否统计虚拟层厚度
		int GetHoleLayThick(int idx, vector<gme_vector3d> &vecOut, bool bflg = false);
		int GetHoleLayThick_true(int idx, vector<gme_vector3d> &vecOut, vector<int> *pvec=NULL);

	public:
		int  s3d_GetIdxOfLayer(s3d_BaseLayer &latt, vector<s3d_BaseLayer> &BaseLayerOrderVec);
		void s3d_UpdateLayerIdx(int &ipre, int &ipos, vector<s3d_BaseLayer> &BaseLayerOrderVec);
		void s3d_InsertLayerIdx( s3d_BaseLayer &latt, int ipos, vector<s3d_BaseLayer> &BaseLayerOrderVec);
		void s3d_ProBaselayerAtt(s3d_BaseLayer &prelatt, s3d_BaseLayer &poslatt,
			                     s3d_BaseLayer &lattObj, vector<s3d_BaseLayer> &BaseLayerOrderVec);

		long _s3d_GetProcessBoreLayer(vector<s3d_BoreHole>  &vecHoles, vector<s3d_BaseLayer> &BaseLayerOrderVec);

		int  CheckBasLayerAndBorehole();
		int  s3d_RecodeBasLayAndHoleLay();
		int  RestoreBasLayer();
		void CalStratOrderToIdx();

		// 针对基岩的特征、进行数据处理
		int  s3d_BedRockProcess();

	public:
		//根据标准地层中的地层类别对钻孔分层进行延展处理...
		static void extendHoleByLayerType(vector<s3d_BoreHole> &vecHoles, vector<s3d_BaseLayer> &BaseLayerOrderVec, double mdlBtm);




	// 钻孔分级建模处理...
	public:
		//设置地层级别（从1开始）
		void SetCurLevel(int level);
		//取出地层级别（从1开始）
		int  GetStratumLevel();
		//取出某一级的钻孔和层序
		int  GetBoreholesByLevNo(int nlev, vector<s3d_BoreHole> &holes, vector<s3d_BaseLayer> &basLayers);

		//地层编码转数字
		void strCodeToVeInt(string &strcode, vector<string> &vec);
		//按照地层级别进行地层编码简化
		string simplifyStrLevel(int idx, string &strLevel);
		//简化钻孔分层
		void CombineHoleLayers(vector<s3d_BoreHole>  &HolesVec);
		//简化标准层序
		void CombineBaseLayers(vector<s3d_BaseLayer> &BasLayVec);
		
		//将当前级别中的标准地层中没有用到的地层编码删除
		int DropHoleLackLayersInBaseLayer();
		//巨厚层发现与拆分算法
		int SplitHoleLayers_Top2Btm();//自上而下
		int SplitHoleLayers_Btm2Top();//自下而上

		//计算钻孔最后的真实层下的延展层的类型
		int AdjustBoreHoleExist();
		//调整钻孔分层的高程信息
		int AdjustBoreHoleLayerZVal();
		int AdjustBoreHoleLayerZVal(s3d_BoreHole &hole);

		//取父地层基本层序
		vector<s3d_BaseLayer>& getParentBasLays();
		//取父地层对应的子地层索引...
		vector<vector<int>>& getParentToSonIdx();



		//相邻相同的钻孔分层进行合并处理...
		static void merge_same_holestrat(vector<s3d_BoreHole>* borehole_data = nullptr, vector<s3d_BaseLayer>* stdlayer = nullptr, vector<SpecialStrat>* specialStrat = nullptr);
		//将钻孔中的特殊地层向上或向下合并到其他相邻的地层中
		static long merge_special_layer(vector<s3d_BoreHole>* borehole_data = nullptr, vector<s3d_BaseLayer>* stdlayer = nullptr, vector<SpecialStrat>* specialStrat = nullptr);
		//根据修改后的钻孔数据更新标准地层,保证标准地层中没有多余的地层...
		static void update_stdlayer_by_borehole(vector<s3d_BoreHole>* boreholedatas = nullptr, vector<s3d_BaseLayer>* stdlayer = nullptr);

		//根据地层级别编码取地层编码...
		static string getStratCodeByLevelCode(string levelCode, vector<s3d_BaseLayer>& standlayer);
		static s3d_BaseLayer* getStandStratByLevelCode(string levelCode, vector<s3d_BaseLayer>& standlayer);
		static s3d_BaseLayer* getStandStratByNewLevelCode(string levelCode, vector<s3d_BaseLayer>& standlayer);
		//根据地层编码取地层级别编码...
		static string getLevelCodeByStratCode(string stratCode, vector<s3d_BaseLayer>& standlayer);
		static s3d_BaseLayer* getStandStratByStratCode(string stratCode, vector<s3d_BaseLayer>& standlayer);
		//根据钻孔编码找到钻孔信息...
		static s3d_BoreHole* getHoleInfoByHoleCode(string holeCode, vector<s3d_BoreHole>& boreholedatas);
		//合并当前钻孔地层
		static long conbineboreholelayer(s3d_BoreHole& borehole);

		//根据钻孔数据计算凸包，并将其更新到多边形范围中去...
		static void cal_convex_hull(vector<s3d_BoreHole>& boreholedatas, vector<gme_vector3d>& convexHull);

		//利用地质图和模型延展深度，对钻孔数据进行预处理（包括虚拟钻孔数据）
		static void update_hole_by_brmap(vector<s3d_BoreHole>* borehole_data, vector<s3d_BaseLayer>& standlayer, gm_geomap* br_geomap, double dExtendZ);

		//更新地层的材质
		static void UpdateOrdinaryLayerMat(vector<gme_vector3d>& poly, vector<s3d_BaseLayer>& stdlayerdatas, vector< vector<gmeEntity*> >& entslist);
		static void UpdateSpecialLayerMat(vector<s3d_BaseLayer>& stdlayerdatas, vector< vector<gmeEntity*> >& entslist);



	public:
		int                          m_nLevel;          // 如果是8-0，则m_nLevel取值为8
		int                          m_idxFrom;         // m_pBoreHoles_old中，合并体起始索引\m_pBasLayers中合并体索引位置
		int                          m_idxTo;           // m_pBoreHoles_old中，合并体终止索引
		bool                         m_bExtBot;         // 底部扩展标记
		s_unlong                     m_HoleNum;         // 钻孔数目
		gme_vector3d               * m_pHoleDotsXYZ;    // 钻孔孔口点位数据
		s3d_MdlParam               * m_pGeoMdlParam;    // 建模参数
		vector<double>               m_valThick;        // 每层的尖灭距离
		vector<double>               m_valdhi;          // 每层的平均厚度
		vector<s3d_BoreHole>        * m_pBoreHoles;     // 钻孔数据
		vector<s3d_BaseLayer>       * m_pBasLayers;     // 标准地层数据
		vector<s3d_BoreHole>          m_pBoreHoles_old; // 钻孔数据：记录原始的数据
		vector<s3d_BaseLayer>         m_pBasLayers_old; // 标准地层：记录原始的数据
		vector<s3d_BoreHole>          m_pBoreHoles_new; // 钻孔数据：记录重编码后的数据
		vector<s3d_BaseLayer>         m_pBasLayers_new; // 标准地层：记录重编码后的数据
		map<string, int>              m_orderToIdx;     // m_pBasLayers


	private:
		int                      m_levelNum;      // 地层级别数目：1、2、3、4、5...
		int                      m_FillType;      // 填充类型
		int                      m_curLevel;      // 当前地层级别
		vector<s3d_BaseLayer>    m_ParentBasLays; // 父地层基本层序
		vector<vector<int>>      m_ParToSonIdx;   // 父地层对应的子地层索引...
	};

}
