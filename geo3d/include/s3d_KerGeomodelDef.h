#ifndef _S3D_KERGEOMDELDEF_H
#define _S3D_KERGEOMDELDEF_H

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

#include <osg/Vec3d>
#include <gme_Pointer.h>
#include <gme_vector2.h>
#include <gme_vector3.h>
#include <gme_vector4.h>
#include <s3d_Math.h>
#include <s3d_GeomDefine.h>
#include "s3d_AttrDBDef.h"



namespace Smart3dMap
{
	typedef unsigned long ulong;
	typedef unsigned int uint;
	typedef unsigned short ushort;

	typedef enum gm_hole_type //钻孔类型
	{
		GM_HOLE_TYPE_VIRTUAL = 0, //虚拟钻孔
		GM_HOLE_TYPE_REAL = 1,    //真实钻孔
	}gm_hole_type;

	typedef enum gm_strat_type //地层曲面类型
	{
		GM_STRAT_TYPE_NONE = 0,
		GM_STRAT_TYPE_STRAT = 1, //沉积地层
			GM_STRAT_TYPE_STRAT_LENTICLE = 2, //沉积地层(夹层)

		GM_STRAT_TYPE_INTRUDED_ROCK = 3, //侵入岩（岩体）
			GM_STRAT_TYPE_IR_BOULDER = 4,//岩体（孤石）
			GM_STRAT_TYPE_IR_VEIN = 5,	 //岩体（脉岩）
			GM_STRAT_TYPE_IR_TS = 6,	 //岩体（填石）

		GM_STRAT_TYPE_FAULT = 7, //断层
			GM_STRAT_TYPE_FAULT_NORMAL = 8, //正断层面
			GM_STRAT_TYPE_FAULT_INVERSE = 9, //逆断层面
			GM_STRAT_TYPE_FAULT_STRIKESLIP = 10, //走滑断层面
	}gm_strat_type;

	typedef enum gm_stdstrat_type //标准地层类型
	{
		GM_STD_STRAT_ORDER = 1, //有严格标准顺序
		GM_STD_STRAT_ORDER_WITH_OVERTURN = 2, //有标准顺序，但含有相邻层的倒转地层
		GM_STD_STRAT_UNORDER = 3, //没有有标准顺序（完全无序或存在跨层的倒转地层）
	}gm_stdstrat_type;

	typedef enum gm_mdling_order //地质体构建顺序
	{
		GM_MDO_FROM_TOP_TO_BTM = 1, //自上而下
		GM_MDO_FROM_BTM_TO_TOP = 2, //自下而上
	}gm_mdling_order;

	typedef enum gm_hole_ext_type //钻孔向下延展方式
	{
		GM_HET_EXT = 1,		//延展至建模深度
		GM_HET_NO_EXT = 2,	//不延展，但跨孔至建模深度
		GM_HET_NO_EXT_WITH_BTMSURF = 3, //不延展且直接将孔底作为底界面约束
	}gm_hole_ext_type;



	struct TmpStr //记录最小最大值的结构体，在对象排序中用
	{
		long  min;
		long  max;
	};
		
	struct s3d_TriEdg	// 三角边数据结构
	{
		int      PntMin;
		int      PntMax;
		s3d_TriEdg()
		{
			PntMin = -1;
			PntMax = -1;
		}
	};

		
	struct s3d_InsecLin	// 内部交线数据结构
	{
		gme_vector3d       d3Dot;
		int         TriNo;
		int         PntMin;
		int         PntMax;
		s3d_InsecLin()
		{
			TriNo = -1;
			PntMin = -1;
			PntMax = -1;
		}
	};

		
	struct s3d_TriTopos	// 三角形拓扑结构
	{
		gme_triangle       * pTris;   //三角形
		gme_triangle_top   * pTopos;  //三角形top
		int                  TriNum;  //三角形数目
		s3d_TriTopos()
		{
			pTris = NULL;
			pTopos = NULL;
			TriNum = 0;
		}
	};

		
	struct s3d_TopBtmEnty	// 临时地层体结构
	{
		gmeSurface   * pTemplSurf; // 三维面数据
		double       * pTopZ; // 长度为pTemplSurf->m_PntNum
		double       * pBtmZ; // 长度为pTemplSurf->m_PntNum
		s3d_TopBtmEnty()
		{
			pTemplSurf = NULL;
			pTopZ = NULL;
			pBtmZ = NULL;
		}
	};


	//层序自动建模参数
	class s3d_MdlParam
	{
	public:
		vector<gme_vector3d>  m_mdlBdry;

		bool              m_bMdlingByLevel;//是否分级别建模...
		bool			  m_bUseConvexHull;//是否使用凸包作为外边界
		bool			  m_bDenseMesh;    //是否对模型网格进行加密
		bool              m_bCalStratBary; //是否计算地层范围
		bool              m_bClipVectorMesh;//发生求交时，是否矢量裁剪
		bool              m_bForcedPassThrouth;//是否强行过点约束
		bool			  m_bMeshSmoothAgain;  //对EntityObj的底面进行再次光滑调整

		gm_strat_type	  m_mdlStratType;//地质体类型(1沉积层/ 3侵入岩/ 2特殊)
		gm_mdling_order   m_sMdlingOrder;//地质体构建顺序（1自上而下 / 2自下而上）
		gm_hole_ext_type  m_sHoleExtType;//钻孔延展方式: 1钻孔延至建模深度（延展）  2跨孔连至建模深度（不延展）  3孔底构建底界面（不延展）

		int               m_nMdlingLevelNo;//当前地层建模级别(1-n)
		double            m_dPinchCoef;    //尖灭系数(0-1)
		int               m_nSubsurfNum;   //网格细分次数(0-4)

		double            m_dxGap;    //X方向加密间距
		double            m_dyGap;    //Y方向加密间距
		double            m_texRateX; //X方向纹理缩放比例
		double            m_texRateY; //Y方向纹理缩放比例

		double            m_dSearchRadius; //距离反比影响半径（0表示全部样本点都要参与计算）
		double			  m_dExtBufferR;   //外扩缓冲半径， 默认不外扩（-1）
		double            m_dBotZval;      //建模深度（界面传入值：从地表最低处向下延展的深度，程序内部转化为实际标高）

	public:
		s3d_MdlParam()
		{
			m_bMdlingByLevel = false; //是否分级别建模
			m_bUseConvexHull = false;     //是否使用钻孔凸包作为外边界
			m_bDenseMesh = true;	//是否对网格进行加密
			m_bCalStratBary = false;//是否计算地层边界
			m_bClipVectorMesh = false;    //矢量裁剪
			m_bForcedPassThrouth = false; //强约束1/弱约束0
			m_bMeshSmoothAgain = false; //再次光滑调整
				
			m_mdlStratType = GM_STRAT_TYPE_STRAT;//地质体类型
			m_sMdlingOrder = GM_MDO_FROM_BTM_TO_TOP;//地质体构建顺序
			m_sHoleExtType = GM_HET_NO_EXT_WITH_BTMSURF;//钻孔延展方式: 1钻孔延展至建模深度  2钻孔不延展跨短钻孔连接至建模深度  3不延展直接用孔底构建模型底界面

			m_nMdlingLevelNo = 5;      //默认为最大级别
			m_dPinchCoef = 0.5;   //尖灭系数，取值0.0-1.0
			m_nSubsurfNum = 0;      //细分面的次数

			m_dxGap = 50.0;   //X方向加密间距
			m_dyGap = 50.0;   //Y方向加密间距
			m_texRateX = 1.0;      //X方向纹理缩放比例
			m_texRateY = 1.0;      //Y方向纹理缩放比例

			m_dSearchRadius = 0.0;//距离反比影响半径
			m_dBotZval = 100;     //建模深度
			m_dExtBufferR = -1;
		}
	};

	typedef struct SpecialStrat //钻孔中的特殊地质体的参数...
	{
		std::string strStratCode;
		std::string strStratName;
		std::string strStratOrder;
		std::string strMatName;
		gm_strat_type strattype;
		double	x, y;
		double  top, bott;
	}SpecialStrat;

	
	class s3d_AnchorPnt	//剖面定位点(或钻孔轨迹线)
	{
	public:
		double            dMapX; //定位点图上坐标
		double            dMapY; //
		double            dFacX; //定位点实际坐标
		double            dFacY; //
		double            dFacZ; //
		char              cFlg;  //是否交叉孔(可以表征其他)
		std::vector<gme_vector2d> strat_btm; //钻孔底板点的二维坐标... 编译通过后去掉leo
	public:
		s3d_AnchorPnt()
		{
			dMapX = 0.0;   
			dMapY = 0.0;   
			dFacX = 0.0;   
			dFacY = 0.0;   
			dFacZ = 0.0;   
			cFlg = 0;      
		}
	};

	//钻孔生成剖面图参数
	class s3d_SectParam
	{
	public:
		double         m_dxGap;     // 剖面上加密点的间距
		double         m_disPinch;  // 0-1之间
		char           m_cExtend;   // 是否扩展短钻孔
		long           m_lxScale;   // x方向比例尺（横向比例尺1：lxScale）
		long           m_lyScale;   // y方向比例尺（纵向比例尺1：lyScale）
		short          m_sCutType;  // 0平推/1底部曲线/2底部抹平+阶梯
		gm_hole_ext_type m_sHoleExtType;//钻孔延展方式: 1钻孔延展至建模深度  2钻孔不延展跨短钻孔连接至建模深度  3不延展直接用孔底构建模型底界面
		gm_mdling_order m_sMdlingOrder;	//地质体构建顺序
		bool           m_bMdlingByLevel;// 是否分级建模
	public:
		s3d_SectParam()
		{
			m_dxGap = 1.0;     // 剖面上加密点的间距
			m_disPinch = 0.5;  // 0-1之间 （默认为1/2尖灭）
			m_cExtend = 1;     // 是否延伸短钻孔 0否/1是（默认扩展）
			m_lxScale = 1000;  // x方向比例尺（横向比例尺1：lxScale）
			m_lyScale = 1000;  // y方向比例尺（纵向比例尺1：lyScale）
			m_sCutType = 0;    // 0平推/1底部曲线/2底部抹平+阶梯
			m_sHoleExtType = GM_HET_EXT;//钻孔延展方式: 1钻孔延展至建模深度  2钻孔不延展跨短钻孔连接至建模深度  3不延展直接用孔底构建模型底界面
			m_sMdlingOrder = GM_MDO_FROM_BTM_TO_TOP;//地质体构建顺序
			m_bMdlingByLevel = true;   // 是否分级建模
		}
	};

	//地质分区结构
	class s3d_GeoPolygon
	{
	public:
		s3d_Pointer<s3d_Polygon> pPoly;   //多边形结构
		string                   layerCode;  //地质代号
	public:
		s3d_GeoPolygon()
		{
			pPoly = NULL;    //多边形数据
			layerCode = "";     //地质代号
		}
	};


	//断层线结构:弧度制
	class s3d_FaultLine
	{
	public:
		s3d_Pointer<s3d_Polyline3D>    pline;   //断层线结构
		string                    strFaultNo;   //断层名称、编码
		double                    dTreDirMin;   //断层走向较小值：如断层走向为80-100度，则较小值为80，较大值为100
		double                    dTreDirMax;   //断层走向较大值：如断层走向为80度，则较小值为80，较大值为80
		double                    dDipDirMin;   //倾向（弧度制）区间：[0,360),正北为0，正东90，正南180，正西270
		double                    dDipDirMax;   //倾向（弧度制）区间：[0,360),正北为0，正东90，正南180，正西270
		double                    dDipAng;      //倾角（弧度制）区间：[0,90], 岩层与水平面夹角：水平为0，垂直90
		char                      sType;        //类型：0/1/2---虚拟/实测/推测
		short                     nLevel;       //断层级别：1/2/3/4/5
		int                       nindex;       //数据索引...
		vector<double>            dotAngVec;    //各个坐标点的倾角~~~~
		vector<double>            dotDipVec;    //各个坐标点的倾向~~~~
	public:
		s3d_FaultLine()
		{
			this->clear();
		}
		void clear()
		{
			pline = NULL;              //断层线结构
			strFaultNo = "";           //断层名称、编码
			dTreDirMin = MAX_DOUBLE;   //断层走向较小值
			dTreDirMax = MIN_DOUBLE;   //断层走向较大值
			dDipDirMin = MAX_DOUBLE;   //断层倾向较小值
			dDipDirMax = MIN_DOUBLE;   //断层倾向较大值
			dDipAng = MAX_DOUBLE;      //断层倾角
			nLevel = 1;                //断层级别
			sType = 1;                 //虚拟为0，默认为1，推测为2，倾向、倾角为空时，赋值2
			nindex = -1;               //数据索引，sType裁剪自动延伸为3
			dotAngVec.clear();
			dotDipVec.clear();
		}
	};



	//typedef struct s3d_Rgn2d //区边界， 相当于s3d_Polygon
	//{
	//	std::vector<gme_vector2d>		strat_outer_rgn; //区的外边界
	//	std::vector<std::vector<gme_vector2d>>strat_inner_rgns; //区的内边界
	//}s3d_Rgn2d;
	//typedef struct s3d_Rgn3d //区边界， 相当于s3d_Polygon3D
	//{
	//	std::vector<gme_vector3d>		strat_outer_rgn; //区的外边界
	//	std::vector<std::vector<gme_vector3d>>strat_inner_rgns; //区的内边界
	//}s3d_Rgn3d;


	typedef struct s3d_Isoline //等高线
	{
		s3d_Polyline3D	isolin;	//一条线
		double			isoVal;	//高程值
	}s3d_Isoline;

	typedef struct s3d_GeoLine//地层线
	{
		std::string	layerCode, layerCode2; //地层编码
		s3d_Polyline3D geoLine; //地层线
	}s3d_GeoLine;

	typedef struct s3d_GeoRgn //地层区
	{
		string			layerCode;//地层编码
		s3d_Polygon3D	geoRgn3d; //地层区，如果有内外边界，则第一个表示外边界，后面的表示内边界
	}s3d_GeoRgn;


	typedef struct s3d_GeoMap //地质图
	{
		std::string					mapname;//图名
		double						scale; //比例尺分母
		std::vector<gmeGeoPnt>		geo_pnts;	//地质点
		std::vector<gmeGeoOriPnt>	geoori_pnts;//产状点
		std::vector<gme_fault>		faults;		//断层
		std::map<string, std::vector<PolyLinRef>> strat_lins;//地层线
		std::map<string, std::vector<PolyRef>> strat_rgns; //地层区
	}s3d_GeoMap;

	typedef struct s3d_SectionMap//剖面图
	{
		std::string					mapname; //图名
		double						xscale, yscale; //纵横比例尺分母
		std::vector<s3d_AnchorPnt>	holes;		//剖面图上的钻孔
		std::vector<gmeGeoPnt>		geo_pnts;	//地质点
		std::vector<gmeGeoOriPnt>	geoori_pnts;//产状点
		std::vector<gme_fault>		faults;		//断层
		std::map<string, std::vector<PolyLinRef>> strat_lins;//地层线
		std::map<string, std::vector<PolyRef>> strat_rgns; //地层区
	}s3d_SectionMap;

	//中段图
	typedef struct s3d_MininglevelMap
	{
		std::string					mapname;//图名
		double						zval;//中段深度
		double						scale; //比例尺分母
		std::vector<gmeGeoPnt>		geo_pnts;	//地质点
		std::vector<gmeGeoOriPnt>	geoori_pnts;//产状点
		std::vector<gme_fault>		faults;		//断层
		std::map<string, std::vector<PolyLinRef>> strat_lins;//地层线
		std::map<string, std::vector<PolyRef>> strat_rgns; //地层区
	}s3d_MininglevelMap;

	//地层平面分布图
	typedef struct s3d_StratRgnMap
	{
		std::string		mapname; //图名
		double			scale; //比例尺分母
		std::map<string, std::vector<PolyRef>> strat_rgns;//地层区
	}s3d_StratRgnMap;

}

#endif //_S3D_KERGEOMDELDEF_H
