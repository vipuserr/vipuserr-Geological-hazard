#pragma once
 
#include <map>
#include <vector>
using namespace std;

#include <s3d_KerGeomBndmapExp.h>
#include <s3d_GeomDefine.h>
#include <s3d_KerGeomodelDef.h>


namespace Smart3dMap
{
	class s3d_BoreHoleAnalys;


	//1. 建模算法中计算地层平面分布边界：根据钻孔数据计算地层分布范围类,用于计算地层尖灭点...
	class _S3D_KERGEOM_BNDMAP_EXP s3d_CalGeoBoundary
	{
	public:
		s3d_CalGeoBoundary();
		virtual ~s3d_CalGeoBoundary();

	public:
		//初始化数据
		int InitDatas(gme_vector3d *pdots, int num, s3d_BoreHoleAnalys *pHoleCls,
			map<string, vector<PolyRef>> *pMap = NULL, char flag = 1);

		//计算某一层的分布范围// 默认3/4尖灭
		int Getpolygon(int idx, PolyRef& stratPoly, double cof = 0.6);
		int Getpolygon(int idx, Poly3DRef& stratPoly, double cof = 0.6);
		int GetPolygon(int idx, gmeSurface &surf, double cof = 0.6);

		//取点类型, 0缺失/ 1不确实/ 2未知
		void setDotType(char type);
		char getDotType();

		//判断当前模板点是否存在（1/存在即有厚度，0/不存在就是0厚度）
		int judgePntExist(double x, double y, int &flg);
	
		//利用外部输入的约束多边形构建gmeSurface
		int GetPolygon_ByPoly(vector<PolyRef> &polyVec, gmeSurface &surf);
		//利用内部数据计算分区,构建出gmeSurface
		int GetPolygon_ByCalu(int i, gmeSurface &surf, double cof = 0.6);
		//利用内部数据，计算地层的基底分区...
		int GetBotPoly_ByCalu(int i, gmeSurface &surf, double cof = 0.4);
		//多边形构造面
		int PolygonTos3d_Surface(s3d_Polygon * pPoly, gmeSurface * pSurf);

	private:
		// 构建内部索引
		int CalInnerDatas();

		// 构建内部索引
		int NewInnerIndexBuffer();

		// 设置一个曲面
		void SetExistSurface(gmeSurface &surf);

		// 获取样本数据点
		int  GetSampleDatas(double x, double y, vector<s_unlong> &pTriDatas);


		//根据边界进行计算  //0外 1内 2上
		int GetDotFlg(double x, double y, int &flg, double esp);

		//计算边界点的标记值...cof
		int CalBoundPntFlag(gme_vector3d &dot, gme_vector3d &dot_0, gme_vector3d &dot_1);
		int CalBoundPntFlag2(gme_vector3d &dot, gme_vector3d &dot_0, gme_vector3d &dot_1, double cof);




	private:
		s3d_BoreHoleAnalys                 * m_pHoleCls;    //钻孔数据处理类
		vector<gme_vector3d>                 m_BdaryPnts;   //边界点数据
		vector<gme_vector3d>                 m_BdaryOrder;  //边界点数据
		map<string, vector<PolyRef>>         m_BdaryMap;    //地层范围约束文件

		char                                 m_type; // 1/没有缺失 0/缺失
		char                                 m_PinchCalflg;  // 尖灭计算方式：1/按cof，2/智能计算...
		gmeSurface							 m_boundSurf;   //表达边界的三维面
		gme_rect_2d                          m_Rect;        //三维矩形范围
		s_unlong                             m_dotNum;      //约束点数目
		gme_vector3d                       * m_pResDatas;   //约束点...
		double                               m_dgapX;       //网格间距X
		double                               m_dgapY;       //网格间距Y
		s_unlong                             m_Xnum;        //X方向网格数
		s_unlong                             m_Ynum;        //Y方向网格数
		vector<s_unlong>                  ** m_ppIndex;     //每个网格对应的三角形索引
		vector<gme_vector3d>                 m_BdryLine;    //外圈边界线
		vector<vector<gme_vector3d>>         m_vvLines;     //三维面的边界线...
	};


	//2. 生成地层分区图：根据边界线、钻孔点位的存在标记、尖灭系数、计算一个地层的平面分布图
	class _S3D_KERGEOM_BNDMAP_EXP  CCalBdaryPoly
	{
		friend class s3d_CalGeoBoundary;
		friend class CCalStratumPoly;
	public:
		CCalBdaryPoly();
		virtual ~CCalBdaryPoly();

	public:
		// 初始化数据：dcof/尖灭系数、 dgap/格网间距
		// vecHoles/钻孔点位：Z坐标为厚度信息，0或大于0的数值
		void initdatas(vector<gme_vector3d> &vecHoles, 
			           vector<gme_vector3d> &vecBdarydots,
			           double dgap, double dcof = 0.5, double dkof = 0.4, char flg = 2);

		void Clear();
		void IsEmpty();

		//计算出地层的多边形范围
		void calStratPolys(vector<PolyRef>& polys);
		void calStratPolys(vector<Poly3DRef>& polys);

		// 获取分区范围面：三角形组合、未分割
		int  GetExistSurfs(gmeSurface &surf);
		// 三维面进行分离:针对未分割的面进行分离，surfVec需要在外面进行释放
		int  SplitSurfaces(gmeSurface &surf, vector<gmeSurface*> &surfVec);
		void ReleaseSurface(vector<gmeSurface*> &surfVec);

	public:
		// 计算点位的存在标记
		int  CalBoundPntFlag(gme_vector3d &dot, gme_vector3d &dot_0, gme_vector3d &dot_1);

		// 简化存在标记，以1、0区分：全部为0返回0\全部为1返回1\有0有1返回2
		int  SimpleExistFlag(vector<gme_vector3d> &vecHoles, vector<gme_vector3d> &vecdots);

	public:
		// 计算钻孔的平均孔距...
		double  CalAverHoleDista(vector<gme_vector3d> &vecHoles, vector<gme_vector3d> &vecBdarydots);

		// 钻孔厚度统计计算：
		int     CalHoleThickPara(vector<gme_vector3d> &vecHoles);

		// 智能计算尖灭系数：holeDot地层点、lackDot缺失点
		double  CalcHolePinchCof(gme_vector3d &holeDot, gme_vector3d &lackDot);

		// 智能计算尖灭点坐标
		int     CalcHolePinchDot(gme_vector3d &holeDot, gme_vector3d &lackDot, gme_vector3d &outDot);

		static void PreReatedPnts(vector<gme_vector3d> &DotsVec, vector<int> &SegIdx);
		static void s3dLinkLines(vector<vector<int>> &vec);
		static void s3dSearchLines(vector<vector<int>> &vecObj, char *pFlag, int idx, vector<int> &OutVec);
		static void CalDotXY(gme_vector3d &a, gme_vector3d &b, gme_vector3d &out, double cof);

		// 基于智能尖灭计算方式，追踪缺失边界范围
		int  autoSubSurface(gmeSurface &surf, double gap);

	private:
		double                           m_zkDis; // 钻孔平均孔距...

		double                           m_tmin;  // 当前层最小厚度
		double                           m_tmax;  // 当前层最大厚度
		double                           m_taver; // 当前层平均厚度
		double                           m_tmid;  // 当前层厚中位数
		double                           m_ta;    // 中位平均较小值
		double                           m_tb;    // 中位平均较大值

		char                             m_type; // 1/没有缺失 0/缺失
		char                             m_PinchCalflg;  // 尖灭计算方式：1/按cof，2/智能计算...
		double                           m_cof;  // 尖灭系数 0.05 - 0.95 
		double                           m_dgap; // 格网间距
		double                           m_kof;  // 分区边界光滑系数: m_kof*m_dgap 为分区光滑间距

		// 边界点数据,已经按照m_dgap加密处理过的...在自动建模过程中，
		// 所有层必须用相同的边界数据,所以边界数据的加密需要在外围实现...
		vector<gme_vector3d>             m_HolePnts;  //钻孔点位
		vector<gme_vector3d>             m_HoleFlgs;  //钻孔标记 0、1
		vector<gme_vector3d>             m_BdaryPnts; //边界点位
	};
	
	//3. 生成地质图：（某一个表面上所有地层的平面分布图。表面可以是地表、地底或地表以下指定深度或中段面）
	// 根据边界线、钻孔点位的存在标记、尖灭系数、计算地层分布范围 2020-11-14  基类中，vecHoles 的Z坐标给 对应的地层序号值；
	class _S3D_KERGEOM_BNDMAP_EXP  CCalStratumPoly : public CCalBdaryPoly
	{
	public:
		CCalStratumPoly();
		virtual ~CCalStratumPoly();

	public:
		//设置地层索引与stratOrder对应映射表
		void setStratIdOrderMap(map<int, string>& stratIdxMap);

		// 计算地层分布范围图:高程 1.0代表地层1,如为3.0代表地层3
		void GetStratPolys(map<string, vector<PolyRef>>& geomapPoly);
		void GetStratPolys(map<int, vector<PolyRef>>& geomapPoly);
		void GetSubSurfaces(map<int, vector<gmeSurface*>>& mapSurfs);

		void ReleaseDatas(map<int, vector<gmeSurface*>> &mapSurfs);
	
	private:
		// 计算 m_BdaryPnts 的高程值...
		int  CalBndryFlag();
		// 生成初步的三维面：边界+钻孔点位三角化
		int  CreatePreSurface();
		// 利用面上点的数值，对层面进行分类...
		int  DevideSurface(vector<gmeSurface*> &surfVec, map<int, vector<gmeSurface*>> &mapSurfs);

	private:
		gmeSurface             m_preSurf;   // 初步三维面
		gmeSurface             m_SubSurf;   // 重构后三维面
		vector<int>            m_LayersFlg; // 取值为1、2、3、4... 标准层序号
		map<int, string>	   m_stratIdxMap; //地层索引与stratOrder对应映射表
	};

}
