#pragma once
 
#include <map>
#include <vector>
using namespace std;

#include <s3d_KerGeomTileMdlingExp.h>
#include "s3d_KerGeoModeling.h"
#include "s3d_GeomDefine.h"


namespace Smart3dMap
{

	//分块建模参数
	class s3d_tile_geom_param
	{
	public:
		long			m_lXTileNum; //X方向的块数
		long			m_lYTileNum; //Y方向的块数
		double			m_dXTileGap;//X方向的块间距
		double			m_dYTileGap;//X方向的块间距
		double			m_dXSurfTmplGap;//模板面的X方向的间距
		double			m_dYSurfTmplGap;//模板面的Y方向的间距
		double			m_dLinTmplGap;//模板线的间距（按长度）
		long			m_nLodNum; //LOD级数
		double			m_dLodRat;//模型的相邻两个LOD之间的分辨率比值
		bool			m_bSurfThining;//地层面是否抽稀
		bool			m_bBorderThining;//边界是否抽稀

		s3d_tile_geom_param()
		{
			m_lXTileNum = 1; //X方向的块数
			m_lYTileNum = 1; //Y方向的块数

			m_dXTileGap = 500;
			m_dYTileGap = 500;

			m_dXSurfTmplGap = 15;
			m_dYSurfTmplGap = 15;

			m_dLinTmplGap = 20;
			m_nLodNum = 10;
			m_dLodRat = 0.5;

			m_bSurfThining = false;
			m_bBorderThining = false;
		}
	};

	typedef enum TileLinType //分块的线类型
	{
		BORDER_LIN, //边界线
		ROW_LIN,	//行网格线
		COL_LIN		//列网格线
	}TileLinType;

	typedef enum LinDotType//线上的点类型
	{
		INTERCROSS_DOT, //块网格线交叉点，用于形成交叉钻孔
		INNER_DOT,		//线内部的点
	}LinDotType;

	//剖面线分段类
	class s3d_SecSeg
	{
	public:
		TileLinType				m_LinType;//剖面段所属的线类型
		long					m_lLinNo;//边界线为-1，>0表示行或列的线号
		bool					m_bIsAdj;//是否相邻边
		vector<gme_vector2d>	m_segLinDots;//分段线的点坐标，首尾表示端点
		vector<gme_vector3d>	m_insertSgLinDots;//线段加密后的点
	public:
		s3d_SecSeg()
		{
			m_lLinNo = -1;
			m_LinType = BORDER_LIN;
			m_bIsAdj = false;
		}
	};

	//剖面线类
	class s3d_SecLin
	{
	public:
		vector<s3d_SecSeg>	m_secSegs; //剖面段的集合
	public:
		s3d_SecLin()
		{
		}
	};

	//剖面围成的单元格
	class s3d_crossGrid
	{
	public:
		gme_rect_2d				m_rect;		//单元格的矩形范围
		vector<gme_vector2d>	m_tileRgn;	//单元格的多边形边界
		vector<s3d_SecSeg>		m_secSegs; //分段集合
	public:
		s3d_crossGrid()
		{
		}
	};



	//分块三维地质建模类
	class  _S3D_KERGEOMTILEMDLING_EXP s3d_geo_tile_mdling
	{
	public:
		s3d_geo_tile_mdling();
		~s3d_geo_tile_mdling();

	public:
		//分块建模
		void buildTiledMdl(gmeModel* gmeMdl);

		//构建一块的模型
		void buildOneTileMdl(long rowTileNo, long colTileNo, vector<vector<EnyRef>>& outEntities);

		//设置模型要素类
		void set_db_fcls(GME_TYPE_OBJ_ID mdlFClsID);

		//设置特殊地质体对象信息...
		void setSpecialGeoObjData(vector<SpecialStrat>& specalObj);


		//设置建模参数
		void setTileMdlParam(s3d_tile_geom_param& tileMdlParam);
		void getTileMdlParam(s3d_tile_geom_param& tileMdlParam);

		void setMdlingParam(s3d_MdlParam& mdldlParam);

		//自动计算默认的分块建模参数
		void calDefTileMdlParam(s3d_tile_geom_param& tileMdlParam);

		//设置地表DEM
		void setTopDem(CalDemZValBas* dem);
		void setTopDem(vector<gme_vector3d> &vecDatas);
		void setBotDem(CalDemZValBas* dem);
		void setBotDem(vector<gme_vector3d> &vecDatas);
		//添加地表高程点约束数据... 
		//设置影像
		void setRsImage(string strRsImgUrl);
		//设置地表地层平面分布分布约束：当其他数据与地表分区不一致时，以地表分区为准
		void setTopStratBdary(map<string, vector<PolyRef>> &BdaryMap);
		//设置地层平面分布范围约束：当钻孔数据与地层分布范围不一致时，以地层分布范围约束为主
		void setStratBdary(map<string, vector<PolyRef>> &BdaryMap);
		//设置层底部dem约束，当钻孔层底与层底部dem不吻合时，以层底dem为准
		void setStratumBtmHei(map<string, CalDemZValBas*> &BtmDemMap);
		//外部设置模板地层面... 
		void setTmplSurf(gmeSurface *pSurface);
		//设置钻孔数据
		void setHoles(vector<s3d_BoreHole>& holes);//
		//设置剖面图数据
		void addSectMap(string& strSectMap);
		void addSectMap(vector<string>& strSectMaps);

		//设置标准地层数据
		void setStdStrat(vector<s3d_BaseLayer>& stdStrat);
		//设置建模范围...
		void setMdlRgn(vector<gme_vector2d>& BoundaryPoints);//
		void setMdlRgn(vector<gme_vector3d>& BoundaryPoints);//


		//获取单元格范围
		void getGrdRect(long row, long col, gme_rect_2d& rect);
		//获取单元格边界线.
		void getGrdSegs(long row, long col, vector<vector<gme_vector2d>>&rgnLins);
		//获取单元格多边形
		void getGrdRgn(long row, long col, vector<gme_vector2d>&rgn);

		//获取一个单元格内的建模数据源-钻孔
		void getHoles(long row, long col, vector<s3d_BoreHole>& holes);
		//计算每一个单元格包含的钻孔数据
		void getHoleIdxListInTile(long rowTileNo, long ColTileNo, vector<long>& holeIdxs);
		//获取一个单元格内的建模数据源-标准地层
		void getStdStrat(long row, long col, vector<s3d_BaseLayer>& stdstrat);

		//面生成lod
		void genLod(gmeSurface& surf, gmeSurface& outSurf);
		//面抽稀
		void thinSurf(bool bThinBdry=false);

		//根据网格间距对建模区域分块，计算出每一个分块网格信息
		void splitRgnToGridTiles(vector<gme_vector2d>& mdlRgn, double xTileGap, double yTileGap, map<gme_vector2i, s3d_crossGrid>& gridTile);

		//准备单元格内的所有钻孔数据,返回真实钻孔的个数...
		long prepareTileHoles(long rowTileNo, long ColTileNo, vector<s3d_BoreHole>& tileHoles);

		//模型全部合并
		void mergeMdl(vector<vector<EnyRef>>& allEntities, vector<vector<EnyRef>>& tileEntities);

		//将地质体写入到模型中...
		void ent2Mdl(vector<vector<EnyRef>>& allEntities, gmeModel& outMdl);

		//对地质体的顶底侧面进行处理...
		void postDealModelSurfs(vector<vector<EnyRef>>& allEntities);

	public:
		//根据点位生成虚拟钻孔... old
		void genVHole(gme_vector2d holePos, s3d_BoreHole& vHole);
		//根据点位生成虚拟钻孔... new
		void gen1VHole(gme_vector2d holePos, s3d_BoreHole& vHole);

		//对传入钻孔地层和标准地层进行预处理
		void dealOriHoleLayer(vector<s3d_BoreHole>& inHoles, vector<s3d_BaseLayer>& inStdStrat,
							  vector<s3d_BoreHole>& outHoles, vector<s3d_BaseLayer>& outStdStrat);

		//利用矩形对多边形进行裁剪，保留多边形剩下的部分. 若矩形全部在多边形内，则保留矩形作为结果；若多边形全部在矩形内，则保留多边形作为结果；否则进行裁剪。
		void clipRgnByRect(vector<gme_vector2d>& rgn, gme_rect_2d& rect, vector<gme_vector2d>& outRgn);

	private:
		//根据钻孔分层与初始标准地层数据构建统一编码后的新标准地层
		void calNewStdStrat();

		//根据钻孔数据计算顶底dem
		void calTopDem();
		void calBtmDem();

		//根据钻孔数据计算顶地层分布
		void calTopStratBdary();
		//根据钻孔数据计算底地层分布
		void calBtmStratBdary();
		//计算每个地层的地层分区
		void calStratBdary();

		//根据钻孔位置和顶底地层分布图确定虚拟孔给的顶底地层编码
		void calStratLevelByBdry(string& stratLevel, gme_vector2d& vHolePos, map<string, vector<PolyRef>>& bdyMap);

	private:
		s3d_MdlParam			m_mdlingParam;//建模参数
		s3d_tile_geom_param		m_tileMdlParam;//分块建模参数
		GME_TYPE_OBJ_ID			m_3dMdlFClsID; //要素类ID
		vector<gme_vector3d>    m_mdl3dRgn;	 //建模边界
		vector<gme_vector2d>    m_mdl2dRgn;	 //建模边界
		gme_rect_3d             m_3dRect;    //3D建模矩形
		gme_rect_2d             m_2dRect;    //2D建模矩形
		gme_rect_2d             m_2dRectBig; //扩展后范围2D建模矩形
		map<gme_vector2i, gme_rect_2d> m_tileRect;//块矩形边界
		map<gme_vector2i, vector<gme_vector2d>> m_tileRgn;//块多边形边界
		map<gme_vector2i, vector<vector<gme_vector2d>>> m_tileBdyLins;//块边界线列表

		vector<s3d_BaseLayer>	m_oriStdStrat; //传入的标准层序
		vector<s3d_BaseLayer>	m_newStdStrat; //传入的标准层序
		vector<SpecialStrat>	*m_specialStrat; // 特殊地质体数据
		vector<s3d_BoreHole>*   m_holeData; //传入的钻孔
		vector<gme_vector3d>    m_holePos;	//钻孔点位
		gmeSurface				m_tmplSurf;//地层面模板

		//顶底的DEM，dem文件或离散点传入一种即可,如果都不传，则根据钻孔点的空口标高来插值计算任意一点的高程
		std::string				m_strRsImgUrl;//地表栅格影像文件...
		CalDemZValBas           *m_pTopDem;//地表DEM
		vector<gme_vector3d>    m_pTopDemDots;//地表DEM点
		CalDemZValBas           *m_pBtmDem;//底部DEM
		vector<gme_vector3d>    m_pBotDemDots;//底部DEM点
		map<string, CalDemZValBas*> m_BtmDemMap;//每个地层的底板DEM
		map<string, vector<PolyRef>>	m_TopBdyMap;//地表地层分布，stratLevel to地表地层约束范围,优先级最高的约束
		map<string, vector<PolyRef>>    m_BtmBdyMap;//地底地层分布，stratLevel to地表地层约束范围,优先级最高的约束
		map<string, vector<PolyRef>>    m_BdaryMap; //每个地层的地层分布，地层编码to地层约束范围

		vector<string>			m_sectMapUrls;//剖面图列表
		vector<s3d_BoreHole>	m_tileSecVHoles;//分块边界线上所有的虚拟钻孔数据
		s3d_SecLin				m_SecBdryLin;//边界线
		vector<s3d_SecLin>		m_SecRowLin;//行方向的线
		vector<s3d_SecLin>		m_SecColLin;//列方向的线
		map<gme_vector2i, s3d_crossGrid>	m_secGrids;//分块线形成的单元格
	};


}