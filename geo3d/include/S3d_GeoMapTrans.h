#pragma once

#include <QList>
#include <map>
#include <vector>
using namespace std;

#include <s3d_KerGeoMapTransExp.h>
#include <s3d_GeomDefine.h>
#include <s3d_geomodelDef.h>


namespace Smart3dMap
{

	class _S3D_KER_GEOMAP_TRANS_EXP s3d_AttDataParse
	{
	public:
		s3d_AttDataParse();
		~s3d_AttDataParse();
	public:
		void SetDatas( QList<string>       &DcbmVec,
			           QList<gmeEntity*>   &EntyVec,
			           QList<gme_rect_3d*> &RectVec,
			           QList<gme_vector4d> &AttPnts,
			           QList<double>       &AttLens,
			           double              wMin );

		int  CalAttDatas(QList<QList<gme_vector4d>>   &AttTopAndBtm);
		bool bInRect2d(double dx, double dy, gme_rect_3d &RectObj);
		bool bInRect3d(double dx, double dy, double dz, gme_rect_3d &RectObj);
		int  GetSampleDatas(QList<gme_vector4d> &AttPnts, int segNum, QList<double> &segDatas);
		int  SplitData(gmeEntity *pEnty, vector<gme_vector4d> &ori, QList<gme_vector4d> &top, QList<gme_vector4d> &btm);

	public:
		double                m_wMin;
		QList<double>       * m_pAttLens;
		QList<gme_vector4d> * m_pAttPnts;
		QList<string>       * m_pDcbmVec;
		QList<gmeEntity*>   * m_pEntyVec;
		QList<gme_rect_3d*> * m_pRectVec;
	};
	
	//参数及属性...
	struct  s3d_ParaInfo
	{
		string        stratName;   //地层名称（例如：第四纪全新世）
		string        stratCode;   //地层编码（例如：Qh）
		string        stratLevel;  //地层级别编码（例如：010200）
		int           nLayerIndex; //该层对应的标准地层索引号：0,1,2，...
		int           nCount;      //该层重复出现的次数
		string        strYtmc;     //岩土名称
		string        Color;       //颜色
		string        strMapPath;  //岩芯照片
		int           nMapIdx;     //纹理类型
		gme_vector3f  vScale;      //缩放比例
		s3d_ParaInfo()
		{

		}
	};

	//三维剖面类  : 记录三维剖面数据的基本信息
	class _S3D_KER_GEOMAP_TRANS_EXP s3d_SectSurfCls : public s3d_Ref
	{
	public:
		s3d_SectSurfCls();
		~s3d_SectSurfCls();
	public:
		//初始化：至少2个定位点
		int SetAnchDatas(vector<s3d_AnchorPnt> &AnchList);
		int SetSect3dRegs(vector<gmeSurface*>  &SurfList, vector<s3d_ParaInfo> &SurfAtt);

		//获取定位点、三维面、属性
		int GetAnchDatas(vector<s3d_AnchorPnt> &AnchList);
		int GetSect3dRegs(vector<gmeSurface*>  &SurfList, vector<s3d_ParaInfo> &SurfAtt);

	public:
		string                         m_secType;  //剖面类型
		string                         m_sectNo;   //剖面编号
		vector<gme_rect_3d>            m_SurfRect; //剖面 三维面Rect
		vector<gmeSurface*>            m_SurfList; //剖面 三维面集合
		vector<s3d_ParaInfo>           m_SurfAtt;  //剖面 面属性集合
		vector<s3d_AnchorPnt>          m_AnchList; //剖面 定位点集合
	};

	// 三维剖面一致性调整类
	// 针对交叉折剖面，在交叉孔处
	// 进行地层界线一致性调整处理
	class _S3D_KER_GEOMAP_TRANS_EXP s3d_SectAdjustCls
	{
	public:
		s3d_SectAdjustCls();
		~s3d_SectAdjustCls();
	public:
		// 装载剖面数据:加载剖面数据...
		int SetTolerance(double esp); //设置容差，默认为1e-6
		int SetSectDatas(vector<s3d_SectSurfCls*> &secDatas);
	public:
		//检测剖面与obj之间是否有交叉孔
		bool CheckBCross(s3d_SectSurfCls  &obj1, s3d_SectSurfCls &obj2, int &idx1, int &idx2);

		//对所有的剖面，在交叉处进行一致性平差处理...
		int  AdjustAllsectDatas();
	public:
		//获取剖面格网...通过定位轨迹线、分割、造区，获得格网多边形
		int  GetSectGrid(vector<s3d_Pointer<s3d_Polygon>> &GridPoly);
		int  Get3dSurfByPolygon(s3d_Polygon *poly, vector<s3d_ParaInfo> &SurfAtt, vector<gmeSurface*> &SurfList);
	private:
		int  GetSectRegDz(s3d_SectSurfCls *pSectCls, double FacX, double FacY, vector<double> &dzList, vector<int> &SurfIDs);
		int  UpdateSectDzVal(s3d_SectSurfCls *pSectCls, double FacX, double FacY, vector<int>   &SurfIDs, double dz, double dzNew);
		int  IsDotInRect(double FacX, double FacY, gme_rect_3d &rect);
		int  GetSectDzByHole(double FacX, double FacY, gmeSurface *pSur, vector<double> &dzList);
		int  AdjustSectByAnchor(s3d_SectSurfCls *pSect1, int idx1, s3d_SectSurfCls *pSect2, int idx2);
		int  UpdateAllCrossFlg();
		int  GetAllSegLines(vector<vector<gme_vector2d>> &InLines);
		int  Checks3d_Surface(gmeSurface *pSurf, gme_vector2d *pTracks, int num);
		int  UpdateCrossFlg(s3d_SectSurfCls  *pObj1, s3d_SectSurfCls *pObj2);
		int  GetSectSegLines(s3d_SectSurfCls *pSect, vector<vector<gme_vector2d>> &InLines);

	private:
		double                           m_esp;
		vector<s3d_SectSurfCls*>       * m_secDatas;
	};

	//剖面数据导入类：二维数据 转换成 三维数据
	class _S3D_KER_GEOMAP_TRANS_EXP s3d_GeoSectImport
	{
	public:
		s3d_GeoSectImport();
		~s3d_GeoSectImport();

	public:
		// 设置定位点信息yRate：纵向比例尺1：yRate，如果为1:3000，则传3000
		// 定位点的坐标必须齐全... 图上坐标可以进行计算.... bCal为计算标记
		// 图上坐标的单位：毫米，实际坐标的单位：米
		int SetAnchorDatas(s3d_AnchorPnt * pAncPnts, long AnchNum, long yRate,
			long xRate = 1000, bool bCut = false, bool bCalMap = false);

		// 二维多边形转换为三维剖面
		int SectPolygonToSurface(s3d_Polygon * pPoly, gmeSurface * pSurf);

		// 二维坐标点转换为三维坐标
		int Sect2dDotsTo3dDots(gme_vector2d *pInPnt, gme_vector3d *pOutPnt, long dotNum);

		// 三维坐标点转换为二维坐标
		int Sect3dDotsTo2dDots(gme_vector3d *pInPnt, gme_vector2d *pOutPnt, long dotNum);

	private:
		// 定位点排序，按照X坐标，从小到大排列
		void SortAnchors();

		// 三维转二维时，自行计算定位点的图上坐标
		int  CalAnchorPntVal();

		// 定位轨迹线与多边形相交后，对多边形进行更新
		int  UpdatePolyByCtrlLine(vector<gme_vector2d> &vecPoly, vector<gme_vector2d> &vecPolyOut);

		// 剖面区上，添加钻孔轨迹控制线
		int  AppendCtrlLines(vector<vector<gme_vector2d>> &vecPoly, vector<gme_vector2d> &dConsLinDotsVec);

	private:
		s3d_AnchorPnt * m_pAncPnts;  //定位点信息
		long            m_AnchNum;   //定位点数目
		long            m_xRate;     //横向比例尺
		long            m_yRate;     //纵向比例尺
		bool            m_bCalMap;   //是否计算定位点的图上坐标值
		double          m_dYMap;     //图上Y坐标偏移量
		bool            m_bCut;      //是否在定位点处裁剪
	};

	//平面地图数据导入类：将二维平面多边形，转换为三维面
	//高程计算方法：距离反比插值、等高线提取、
	class _S3D_KER_GEOMAP_TRANS_EXP s3d_GeoMapImport
	{
	public:
		s3d_GeoMapImport();
		~s3d_GeoMapImport();

	public:
		// 设置高程约束数据
		// TriLen:  边长,Ang: 最小角
		// dRadius: 距离反比影响半径
		int  SetInitDatas(vector<gme_vector3d>         *pDots,
			vector<vector<gme_vector3d>> *pVec,
			double TriLen, double Ang,
			double dRadius, double *pDZ = NULL);

		// 二维多边形转换为三维剖面
		int  MapPolygonToSurface(s3d_Polygon * pPoly, gmeSurface * pSurf);

	public:
		// 计算高程值...对pDots的Z值进行修改
		int  CalDotsElevs(gme_vector3d * pDots, int nDotNum);

		// 获取多边形内部的约束点
		int  GetLabelDots(s3d_Polygon *pPoly, vector<gme_vector3d> &DotVec);

	private:
		double                            * m_pDZ;     //Z值：统一赋值
		double                              m_Ang;     //最小角
		double                              m_TriLen;  //网格边长...
		double                              m_dRadius; //适合距离反比的插值半径
		vector<gme_vector3d>              * m_pDotVec; //高程点约束数据
		vector<vector<gme_vector3d>>      * m_pResVec; //等高线约束数据
		vector<gme_vector3d>                m_TopDatasVec; //所有约束数据
	};

	// 根据二维剖面生成三维虚拟孔 2020-11-17 leo
	class _S3D_KER_GEOMAP_TRANS_EXP CreateVirtualHoles
	{
	public:
		CreateVirtualHoles();
		~CreateVirtualHoles();

	public:
		// 设置定位点信息yRate：纵向比例尺1：yRate，如果为1:3000，则传3000
		// 定位点的坐标必须齐全... 图上坐标可以进行计算.... bCal为计算标记
		// 图上坐标的单位：毫米，实际坐标的单位：米
		int  setdatas(vector<string>        &strVec,    //传入：地层编码，与PolyVec等长度
			vector<s3d_Polygon*>  &PolyVec,   //传入：多边形，  与strVec 等长度
			vector<gme_rect_2d>   &dRects,    //传入：rect
			s3d_AnchorPnt         *pAncPnts,  //传入：定位点信息
			int                    AnchNum,   //传入：定位点信息
			int                    yRate = 1000,  //必须得传
			int                    xRate = 1000,  //可不传
			double                 esp = 1e-3);  //容差

// 在指定的 dMapX 处生成 虚拟钻孔
		int  GetVirtHole(double dMapX, s3d_BoreHole  &holeObj);

		// 根据指定的 位置，批量生成holeVec，id、编码外部处理...
		int  GetVirtHoles(vector<double> &dMapXvec, vector<s3d_BoreHole> &holeVec);

	public:
		// 数据转换，将多边形转换为vector
		void  polyToVVec(s3d_Polygon *pPoly, vector<vector<gme_vector2d>> &dotVV);

		// 在图上dMapX处与单个多边形求交
		int   CalVirtualHole(string                       strcode,  //地层编码
			gme_rect_2d                  &rect,    //传入多边形的rect
			vector<vector<gme_vector2d>> &PolyVV,  //传入多边形
			vector<s3d_BoreHoleLayer>    &laylist, //传出地层序列
			double     dMapX, double esp = 1e-3);  //图上X，容差

// 在图上dMapX处与所有多边形求交，算出三维钻孔坐标
		int   CalVirHoles(double                dMapX,      //传入：图上X坐标
			vector<string>        &strVec,    //传入：等长度
			vector<gme_rect_2d>   &dRects,    //传入：rect
			vector<s3d_Polygon*>  &PolyVec,   //传入：等长度
			s3d_BoreHole          &holeObj,   //传出：等长度
			double                esp = 1e-3);  //传入：容差

	public:
		double                   m_esp;
		s3d_GeoSectImport      * m_pImpot;
		vector<string>         * m_strVec;    //传入：地层编码，与PolyVec等长度
		vector<s3d_Polygon*>   * m_PolyVec;   //传入：多边形，  与strVec 等长度
		vector<gme_rect_2d>    * m_dRects;    //传入：rect
	};
}
