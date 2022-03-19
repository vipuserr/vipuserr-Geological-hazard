#pragma once

#include <vector>
using namespace std;

#include <s3d_KerSectmapExp.h>
#include <s3d_GeomDefine.h>
#include <s3d_KerGeomodelDef.h>


namespace Smart3dMap
{
	class s3d_BoreHoleAnalys;
	class s3d_GeoSectImport;
	class CalDemZValBas;

	//临时区数据
	typedef struct Sec_Reg
	{
		Sec_Reg()
		{
			pTopLines = NULL;
			pBotLines = NULL;
			pResLines = NULL;
		}
		~Sec_Reg()
		{			
		}

		//采用智能指针定义，内存自动释放...
		PolyLinRef           pTopLines;//地层层顶线
		PolyLinRef           pBotLines;//地层层底线
		PolyLinRef           pResLines;//
	}Sec_Reg;

//=======================================================================================================================================
//=================================================   剖面分级建模  =====================================================================
// 每个孔 的每个分层对应的尖灭信息类...
// 尖灭信息分析计算类 	// 分布范围是一个区间... 存在区间、不存在区间、可能存在区间；灵活控制；
// 根据钻孔地层的实际分布，计算界限，然后根据三种区间对界线进行修正，然后根据修正后的结果，进行再次光滑...
	class _S3D_KER_GEOSECT_EXP s3d_LayPinchCls
	{
	public:
		s3d_LayPinchCls();
		~s3d_LayPinchCls();

	public:
		//判断点是否在边界内：2内 1上 0外
		static int isDotInLines(double x, vector<double> &dxMin, vector<double> &dxMax);

		// 初始化数据...传入指定层的厚度，数目...
		static int  CaluLayerBdry(gme_vector2d  *playerlens, int num, double pinch, vector<double> &dxMin, vector<double> &dxMax);

		// 计算基底范围... 2021-1-1 // y  -1父地层缺失/0非基底/1基底
		static int  CaluLayBotBdry(gme_vector2d  *playerlens, int num, double pinch, vector<double> &dxMin, vector<double> &dxMax);

	public:
		// 初始化数据 2020-11-28
		int inidatas(gme_vector2d  *dots, int num, double pinch = 0.5);

		// 计算平均孔距...和 最小最大值
        int CalHoleThickPara();

		// 设置智能计算模式 1\2\。。。
		void setCaluType(int type);

		// 计算尖灭线...
		int CalcuLayerBndary(vector<double> &dxMin, vector<double> &dxMax);

	public:
		// 智能计算尖灭点坐标
		int CalcHolePinchDot(gme_vector2d &yExist, gme_vector2d &yLack, gme_vector2d &out);
		double  CalcHolePinchCof(gme_vector2d &holeDot, gme_vector2d &lackDot);

		double  CalcHolePinchCof2(gme_vector2d &holeDot, gme_vector2d &lackDot);

	public:
		double                           m_zkDis; // 钻孔平均孔距...
		double                           m_tmin;  // 当前层最小厚度
		double                           m_tmax;  // 当前层最大厚度
		double                           m_taver; // 当前层平均厚度
		double                           m_tmid;  // 当前层厚中位数
		double                           m_ta;    // 中位平均较小值
		double                           m_tb;    // 中位平均较大值
		int                              m_type;  // 尖灭计算模式： 1默认/2优化
		vector<gme_vector2d>             m_vecHoles;

	public:
		double           m_dPinch;    //0.1-0.9
		int              m_segNum;    //分段数目 第一段的最小值为边界点 最后一段的最大值为边界点 其余为尖灭点...
		vector<double>   m_dxMin;     //每段的最小值
		vector<double>   m_dxMax;     //每段的最大值
	};

	//剖面自动生成算法 gme_vector3d中的xz表达图上坐标xy
	class _S3D_KER_GEOSECT_EXP GeoSectModeling
	{
	public:
		GeoSectModeling();
		~GeoSectModeling();

	public:
		// 一键生成地质剖面图...2D
		int doCreateAllGeoSection(vector<s3d_BoreHole> &BoreHolesVec, vector<s3d_BaseLayer> &BaseLayersVec,
			s3d_SectParam &SectParam, vector<vector<PolyRef>> &outPolygon);

		// 一键生成地质剖面图...3D
		int doCreateAllGeoSection3D(vector<s3d_BoreHole> &BoreHolesVec, vector<s3d_BaseLayer> &BaseLayersVec,
			s3d_SectParam &SectParam, vector<vector<SurRef>> &outSurface);

		// 多约束条件...++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		// 1.设置顶面dem
		int SetTopDemRes(CalDemZValBas *pCalDem);

		// 2.设置底面dem
		int SetBtmDemRes(CalDemZValBas *pCalDem);

		// 3.设置任意层底的dem: 1-2-1,1-1,1 
		int SetIdxBtmRes(string &strOrder, CalDemZValBas*pCalDem);

		// 4.添加tif约束...当钻孔与tif不吻合的时候，以tif为准 :m_strStratOrder
		int SetStratBtmDem(map<string, CalDemZValBas*> &BtmTiffMap);

		// 多约束条件...  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//5. 添加地表地质图约束
		int AddTopStratBdary(map<string, vector<PolyRef>> &BdaryMap);//约束地表所有地层分区
		int AddTopStratBdary(string stratCode, vector<PolyRef> &BdaryMap);//约束地表一个地层的分区

		//6. 添加基岩地质图约束
		int AddBRStratBdary(map<string, vector<PolyRef>> &BdaryMap);//约束基岩面上的所有地层分区
		int AddBRStratBdary(string stratCode, vector<PolyRef> &BdaryMap);//约束一个基岩面上的一个基岩地层分区

		//7. 添加地理要素标注约束
		//添加注记要素
		int AddTopGeoNote(vector<gme_vector2d>& noteDots, vector<string> strNotes);
		//添加河流要素
		int AddTopRivers(vector<PolyRef> &riverRgnMap, vector<string> strRiverNames);

		//根据地表约束图，叠加分析，计算地表顶层约束交线
		int CalTopResLins();

		//二维平面计算：二维折线与地质图求交...
		int CalInterLines(vector<gme_vector2d>              &zklines,   //输入：钻孔平面布置线
			map<string, vector<PolyRef>>      &TopPoly,   //输入：地质图
			map<string, vector<PolyLinRef>>   &OutLines);//输出：分段布置线

	public:
		// 生成剖面图
		int  CreateGeoSection();

		// 构建所有的地层线
		int  CreateAllStrateLines();

		// 构建所有的地层多边形
		int  CreateAllStratePolygons();

		// 地层线相交处理
		int  CalLayerTinSectLines(Sec_Reg & lines);
		int  CalLayerTinSect_Light(Sec_Reg & lines);

		// 创建剖面多边形
		int  secRegToPolygon(Sec_Reg &lines, vector<PolyRef> &outPoly);
	public:
		// 加密地层线
		int  InsertLines();

		// 计算钻孔分层信息的底板高程值
		int  CalBoreHoleLayerBot();

		// 调整地层分层信息
		int  AdjustBoreHoleLayZVal();

		// 简化层序~去除冗余层序
		void SimpleSecBaseLayer();

		// 生成定位点信息
		void CreateAnchorPntVec();

		// 将钻孔数据转换为二维数据
		void HoleDatasTo2D();

		// 补齐钻孔分层信息
		int  FillHoleLackLayers();

		// 获取钻孔顶部坐标串
		int  GetHoleTops(vector<gme_vector3d> &vecOut);
		// 获取钻孔底部坐标串
		int  GetHoleBots(vector<gme_vector3d> &vecOut);

		// 计算剖面指定层的平均厚度
		int  GetLayerThick(int index, double &val);

		// 获取第idx层钻孔分层信息的底板高程坐标（包含虚拟分层）
		int  GetLayerBotZ(int idx, vector<gme_vector3d> &vecOut);

		// 获取钻孔实际分层信息的顶板高程坐标
		int  GetActualHoleLayTopZVal(int idx, vector<gme_vector3d> &outdots);

		// 获取钻孔实际分层信息的底板高程坐标
		int  GetActualHoleLayBotZVal(int idx, vector<gme_vector3d> &outdots, bool bflg = true);

		// 剖面顶部折线加密点
		int  InsertDotsOfLine(vector<gme_vector2d> &polyObj, double disGap);

		// 简化层序~调整级别编码
		void SimpleDatas(vector<s3d_BoreHole>  &BoreHolesVec, vector<s3d_BaseLayer> &BasLayersVec);

		// 字符编码转换为数字化的级别编码
		void StratCodeToLevel(vector<s3d_BoreHole> &BoreHolesVec, vector<s3d_BaseLayer> &BasLayersVec);

	public:
		// 利用dem约束 生成约束曲线
		int  CreateResCurveByHole(vector<gme_vector3d> & dot, double dis,
			CalDemZValBas *pDem, vector<gme_vector3d> & dotvec);

		// 计算模板折线各个点的Y值（X值是等间距的...）
		int  CalLinesYValue(s3d_Polyline & polyLine, vector<gme_vector3d> & dot, double dis, CalDemZValBas *pDem = NULL);

		// 相交计算...
		int  CalLinesByLines(s3d_Polyline & polyLine, vector<gme_vector3d> & dotvec);

		//获取所有钻孔数据底部高程的那个最小值
		int  GetHoleBottomZVal(double &dMinZVal);

		//折线与区求交，保留区内的折线
		int cal_line_poly_intsect(vector<gme_vector2d>& foldLine,//输入：折线
			PolyRef &TopPoly,			    //输入：区
			vector<PolyLinRef>& OutLines);  //输出：分段折线

		//折线与折线求交，得到交点，并更新两条折线
		//vecout:交点列表， outvec1，outvec2: 更新后的折线， interPntNo1，interPntNo2:交点在新折线中的点号
		int cal_line_intsect(vector<gme_vector2d> &vec1, vector<gme_vector2d> &vec2,
			vector<gme_vector2d> &vecout, vector<gme_vector2d>* outvec1 = nullptr, vector<gme_vector2d>* outvec2 = nullptr,
			vector<long>* interPntNo1 = nullptr, vector<long>* interPntNo2 = nullptr);

	public:
		s3d_SectParam               m_SectParam;       // 剖面成图参数
		vector<s3d_BoreHole>      * m_pBoreHoles;      // 钻孔数据
		vector<s3d_BaseLayer>     * m_pBasLayers;      // 标准地层数据
		vector<vector<PolyRef>>   * m_pOutPolygon;     // 输出区文件多边形数据
		vector<s3d_AnchorPnt>       m_AnchorPntVec;    // 钻孔定位点
		vector<gme_vector2d>        m_BoreHoleTopsVec; // 钻孔孔口点位序列
		vector<gme_vector2d>        m_pSampleDotsVec;  // 模板折线点序列
		s3d_Polyline                m_pStdLines;       // 模板折线点序列
		s3d_Polyline                m_BotRes;          // 底部约束
		vector<double>              m_thickvec;        // 每层的平均厚度
		vector<Sec_Reg>             m_RegDatas;        // 区数据集合
		s3d_GeoSectImport         * m_pGeoSectImport;  // 二三维转换类...

	public:
		CalDemZValBas                   * m_pCalTop;         // DEM计算类
		CalDemZValBas                   * m_pCalBot;         // 底部DEM计算类
		map<string, CalDemZValBas*>       m_BtmTifMap;       // 地层编码 to 地层底部tiff约束

		map<string, vector<PolyRef>>      m_TopResMap;       // 地表分区约束...
		map<string, vector<PolyLinRef>>   m_TopLineMap;      // 地表分区约束界线
	};

	//  二维钻孔数据x对应mapX，y为0，z对应图上的mapY
	class _S3D_KER_GEOSECT_EXP SectLevelModeling: public GeoSectModeling
	{
	public:
		SectLevelModeling();
		~SectLevelModeling();

	public:
		// 生成地质剖面图 2D
		int doCreateLevelGeoSection(vector<s3d_BoreHole> &BoreHolesVec, vector<s3d_BaseLayer> &BaseLayersVec,
			s3d_SectParam &SectParam, vector<vector<PolyRef>> &outPolygon,int method =0, bool holeExtend = false);

		// 生成地质剖面图 3D
		int doCreateLevelGeoSection3D(vector<s3d_BoreHole> &BoreHolesVec, vector<s3d_BaseLayer> &BaseLayersVec,
			s3d_SectParam &SectParam, vector<vector<SurRef>> &outSurface);
	public:
		// 获取地层级别
		int   GetLevels(vector<s3d_BaseLayer> &stdlayer);

		// 解析地层级别编码
		void  strCodeToVecInt(string &strcode, vector<string> &vec);

		// 合并相邻地层
		void  CombineHoleDatas(vector<s3d_BoreHole>  &BoreHolesVec);

		// 建模数据预处理
		void  preHoleDatas(vector<s3d_BoreHole> &BoreHolesVec, vector<s3d_BaseLayer> &BaseLayersVec);

		// 层序处理、编码解析处理
		void  SimplifyDatas(vector<s3d_BoreHole> &BoreHolesVec, vector<s3d_BaseLayer> &BasLayersVec);
		
		// 构造建模参数
		void  transforParam(vector<s3d_BoreHole> &BoreHolesVec, vector<s3d_BaseLayer> &BaseLayersVec);

	public:

		//根据地层级别，获取各个级别的地层模型 //如果一共有5个级别，则nlevel取值为1、2、3、4、5
		int CreateEntityByLevel(int nlevel,         //输入参数：地层级别...
			vector<s3d_BaseLayer>    &BasLayersVec, //输出参数：该级别对应的层序
			vector<vector<PolyRef>>  &outEntities); //输出参数：该级别对应的地层体模型

        //根据地层级别，构建对应的地层体结构面模型...
		int CreateEntTopBtmByLevel(int nlevel,   //输入参数：地层级别
			vector<s3d_BaseLayer> &BasLayersVec,  //输出参数：该级别对应的层序
			vector<Sec_Reg>       &EntityTmpVec); //输出参数：该级别对应的地层体结构面

        //构建所有层面数据
		int CreateAllStratSurf(int nlevel, int maxLevel, vector<Sec_Reg> &EntityTmpVec);

		//创建一级地层面
		int CreateFirstStratSurf(vector<Sec_Reg> &EntityTmpVec);

		//创建二级、三级、等多级地层面
		int CreateOtherStratSurf(int nlevel, int maxLevel, vector<Sec_Reg> &EntityTmpVec);

		//一次生成所有地层面
		int CreateGeoSection();
		
		int CreateGeoSection2();//zhuyh-2022-1-1 16:39
		
		//找到每个钻孔位于模板中的位置
		int GetHoleIndexInTemp(vector<int>& indexs);
		//判断钻孔第i层是否是零厚度层
		bool IsZeroDepthStrat(s3d_BoreHole& hole, int index);
		//根据地层厚度计算当前层的尖灭点位置（保证该层的其中一个钻孔为零厚度，一个不为零厚度）,最后一个参数为最大的尖灭比例
		double calcDotThickPos(s3d_BoreHole& hole1,s3d_BoreHole& hole2,int index, double MaxScale = 1.0);
		//查找下一个有效的地层
		int GetNextValidStrat(s3d_BoreHole& hole,int index);
		//寻找尖灭点落在哪个模板点上
		int FindThickPosInTemp(double pos, int startIndex,int endIndex);
		//如果底部高于顶部，则进行调整
		void AdjustStrat(Sec_Reg& reg, std::vector<std::pair<int, int>>& flagTrueRange);
		void AdjustSingleStrat(Sec_Reg& reg, std::pair<int,int>& range);

		//生成框架线... 整个剖面的顶部界限、底部界限; 可考虑多约束
		int CreateFrameSection();

		//对顶底数据的坐标进行调整
		int AdjustBotYVal(Sec_Reg &sect);

		//计算存在标记...
		int  CalStratExistFlag(char * pFlag, Sec_Reg &strEnty);

		//计算钻孔存在标记...
		int  CalHoleExistFlag(vector<gme_vector2d> & holedots,char * pFlag, Sec_Reg &strEnty);

		//根据父地层的约束，计算子地层的存在标记...
		int  GetStratExistByParentRes(char *pFlg, char *pExist);

	public:
		// 获取指定点关联的左右孔:如果在孔上，则返回孔序号：0开始，不在孔上，则返回-1
		int  GetHolesByDot(double x, int &left, int &right);

		// 计算当前层的分布范围...
		int  CalLayerBdary(int idx, vector<double> &dxMin, vector<double> &dxMax);

		// 计算当前层的基底范围...
		int  CalLayerBtmBdary(int idx, vector<int> &layNo, vector<double> &dxMin, vector<double> &dxMax);

		// 调整当前层的Z坐标
		int  AdjustdZVal(vector<gme_vector3d> & dotv, vector<gme_vector2d> & bots,
			             Sec_Reg &lines, char* pflg, vector<int> &layNo, double dis);

		// 获取2d钻孔数据...
		int  GetHoles(vector<gme_vector2d> & holedots);

		// 计算当前层的基底信息：是否属于其父地层的基底
		int  GetHolesInfo(vector<gme_vector2d> & holedots, int layNo, vector<int> &layvec);

		// 信息转换...
		int  TranInfo(vector<gme_vector2d> & holedots, vector<gme_vector3d> & holes);

		// 根据钻孔信息及尖灭位置，计算任意点的厚度
		int  CalcDotThick(vector<gme_vector3d> &thickvec, gme_vector3d &dot, double cof = 0.3);

		int  CalcDotValue(gme_vector3d &dot1, gme_vector3d &dot2, gme_vector3d &dotOut, double cof = 0.3);

	private:
		static s3d_BaseLayer FindLayer(string code, vector<s3d_BaseLayer> &stdlayer);
		//计算地层反复出现次数,并对地层重新编码
		static void CalcRoll(vector<s3d_BoreHole> &boreholedatas);
		//重新计算层序
		static void CalcGeoLayerRoll(vector<s3d_BoreHole> &boreholedatas, vector<s3d_BaseLayer> &stdlayer);

	public:
		int                               m_CurrentLayNo;    // 当前层号

	public:
		Sec_Reg                           m_SectFrame;       // 剖面框架约束线
		s3d_MdlParam                      m_GeoMdlParam;     // 建模参数
		s3d_BoreHoleAnalys              * m_pHolesObj;       // 钻孔处理类对象

		vector<s3d_BoreHole>              m_holes;           // 多级模式下，当前级别钻孔数据存储对象
		vector<s3d_BaseLayer>             m_basLayers;       // 多级模式下，当前级别钻孔层序存储对象

		map<string, Sec_Reg>              m_strToEnty;       // 级别编码 to 地层体面约束
		map<string, vector<PolyRef>>      m_strToEnyRef;     // 级别编码 to 地层体结构模型

		static int					      m_ConnectMethod;    //地层编码方法：0老方法 1新方法
		static bool						  m_HoleExtend;		  //短钻孔是否延展
	};

}