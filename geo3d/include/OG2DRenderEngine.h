#pragma once
#include "OGMessageListener.h"
#include "OGBasDef.h"

using namespace Smart3dMap;


//using namespace Geo3D;

struct StdStratInfoDLM;
struct WellData;

struct DelaminatOper;
typedef enum RenderEngineType
{
	RE_MAPGIS = 1,
	RE_ARCGIS = 2,
	RE_LAYEROUT = 3,
	RE_MAPGISHISVIEW = 4
}RenderEngineType;


typedef struct OG_D_RECT
{
	double xmin;
	double ymin;
	double xmax;
	double ymax;
}OG_D_RECT;

//窗口参数
typedef struct OG_WIN_ORG
{
	double  x0,y0;  //视口左下角(原点)
	OG_D_RECT  frc;    //显示范围
	double  r;      //显示比例
}OG_WIN_ORG;

typedef struct OG_ENTITY_MSG
{
	short ai;      //工作区
	short type;    //图元类型
	long  elmi;    //图元号
}OG_ENTITY_MSG;


typedef vector<gme_vector2d> OG_LINE;
typedef vector<gme_vector2d> OG_REG;

class CSubsectionInfo;
class OG_LIN_INFO;
class OG_REG_INFO;

class OG_FRAME_DLL C2DRendEngine :public Smart3dMap::COGListener
{
public:
	C2DRendEngine(void);
	virtual ~C2DRendEngine(void);

public:
	//消息注册函数
	virtual void registerIntMsg(){ } //int型
	virtual void registerStrMsg(){ } //字符串型
	//监听消息函数
	virtual long OnMessagePro(string msg, __int64 wParam, __int64 lParam) {return 1;} //int型
	virtual long OnMessagePro(long msg, WPARAM wParam, LPARAM lParam) {return 1;}	//字符串型

	//绘制窗口
	virtual void _setRenderWnd(HWND hWnd){m_hREWnd = hWnd;}
	virtual HWND _getRenderWnd() {return m_hREWnd;}

	//virtual void _setRenderCWnd(CWnd* pWnd){m_pWnd = pWnd;}
	//virtual CWnd* _getRenderCWnd() {return m_pWnd;}


	virtual void _setREType(RenderEngineType reType= RE_MAPGIS){m_lREType = reType;}
	virtual RenderEngineType _getREType(){return m_lREType;}

	//取出绘制对象
	virtual long _GetRenderObj(){return 0;}
	virtual void _DelRenderObj(long& lRenderObj){return;}

	virtual void _SetCrossCursorFlg(short flag){}
	virtual short _GetCrossCursorFlg(){return 0;}

	virtual void _SetCommandFlag(long cmdFlg){}  //1.保存cmdFlg,2.清除窗口操作状态,3.恢复光标。
	virtual long _GetCommandFlag(void){return 0;}

	//基本的窗口操作接口
	virtual void _OnDraw(){} //绘制
	virtual void _OpenWindow(){};	//开窗、放大
	virtual void _ReduceWindow(){};	//缩小
	virtual void _MoveWindow(){};	//移动
	virtual void _PrevWindow(){};	//上(前)级窗口
	virtual void _PostWindow(){};//下一视图窗口
	virtual void _AlwayOpenWindow(){};//固定比例放大
	virtual void _AlwayReduceWindow(){};//固定比例缩小
	virtual void _CenterAlig(){};//居中对齐
	virtual void _SelectFeature(){};//选择要素
	virtual void _Pick(){};//识别
	virtual void _RestoreWindow(){};	//复位窗口
	virtual void _UpdateWindow(){};	//更新窗口
	virtual void _CleanWindow(){};	//清窗口
	virtual void _2dViewParam(){};	//取窗口参数
	virtual void _CleanLayer(short lyrPtr){};//清除图层数据
	//修改背景颜色
	virtual void _EditWndBkFace(long lR, long lG,long lB) {}

	virtual double _GetMaxDispRate(void) {return 0;}	    //取最大显示比例,若=0表示还没设置最大比例
	virtual double _GetMinDispRate(void) {return 0;}	    //取最小显示比例,若=0表示还没设置最小比例
	virtual double _SetMaxDispRate(double rate) {return 0;}  //设置最大显示比例,返回上次设置的最大比例(>0)
	virtual double _SetMinDispRate(double rate) {return 0;}  //设置最小显示比例,返回上次设置的最小比例(>0)

public:
	//设备坐标(窗口左下角为原点，右手坐标系)--->逻辑坐标(图形坐标)、窗口坐标
	virtual short _DpToLp(gme_vector2d *xy0, gme_vector2d *xy1) {return 0;}	//xy1可以等于xy0，
	virtual short _DpToLp(double x0, double y0, double *x1,double *y1) {return 0;}
	virtual short _DpToLp(long  x0, long  y0, double *x1,double *y1) {return 0;}
	virtual short _DpToLp(long  x0, long  y0, gme_vector2d *xy1) {return 0;}
	//virtual short _DpToLp(CPoint *xy0, double *x1,double *y1) {return 0;}

	//virtual short _DpToWp(gme_vector2d *xy0, CPoint *xy1) {return 0;}
	//virtual short _DpToWp(long x0,long y0, CPoint *xy1) {return 0;}
	//virtual short _DpToWp(CPoint *xy0, CPoint *xy1) {return 0;}
	//逻辑坐标(即图形坐标，左下角为原点，右手坐标系)--->设备坐标、窗口坐标
	virtual short _LpToDp(gme_vector2d *xy0, gme_vector2d *xy1) {return 0;}
	//virtual short _LpToDp(gme_vector2d *xy0,CPoint *xy1) {return 0;}		    //早期版本为_FactXY_WinXY1
	virtual short _LpToDp(gme_vector2d *xy0, double *x1, double *y1) {return 0;}
	virtual short _LpToDp(gme_vector2d *xy0, long  *x1, long  *y1) {return 0;}
	virtual short _LpToDp(double x0,double y0, double *x1, double *y1) {return 0;}
	virtual short _LpToDp(double x0,double y0, long  *x1, long  *y1) {return 0;} //早期版本为_FactXY_WinXY
	//virtual short _LpToDp(double x0,double y0, CPoint *xy1) {return 0;}

	virtual short _LpToWp(double x0,double y0,long *x1,long *y1) {return 0;}
	//virtual short _LpToWp(gme_vector2d *xy0,CPoint *xy1) {return 0;}
	virtual short _LpToWp(gme_vector2d *xy0,double *x1,double *y1) {return 0;}
	virtual short _LpToWp(gme_vector2d *xy0, long * x1, long * y1) {return 0;}
	//virtual short _LpToWp(double x0,double y0,CPoint *xy1) {return 0;}
	//窗口坐标(左上角为原点，左手坐标系)--->设备坐标、逻辑坐标
	//virtual short _WpToDp(CPoint *xy0, CPoint *xy1) {return 0;}
	//virtual short _WpToDp(CPoint *xy0, gme_vector2d  *xy1) {return 0;}
	//virtual short _WpToLp(CPoint *xy0, gme_vector2d  *xy1) {return 0;}	    //早期版本为_WinXY_FactXY1
	virtual short _WpToLp(long x0,long y0,double *x1,double *y1) {return 0;} //早期版本为_WinXY_FactXY
	//virtual short _WpToLp(CPoint *xy0, double *x1,double *y1) {return 0;}
	//virtual short _WpToDp(long x0,long y0, CPoint *xy1) {return 0;}

	//范围操作接口
	//取、设置图形范围
	virtual short _GetWinMapRange(OG_D_RECT *frc){return 0;}
	virtual short _SetWinMapRange(OG_D_RECT *frc){return 0;}
	//取、设置显示范围
	virtual short _GetWinDispRect(OG_D_RECT *frc){return 0;}
	virtual short _SetWinDispRect(OG_D_RECT *frc){return 0;}
	//取、设置视窗口参数
	virtual short  _GetWinDispParam(OG_WIN_ORG *wxy){return 0;}
	virtual short  _SetWinDispParam(OG_WIN_ORG *wxy){return 0;}
	virtual short  _SetWinDispRate(double rate){return 0;}
	virtual double _GetWinDispRate(void){return 0;}

	//图形、图像数据显示
	virtual long _GetRectToRect(OG_D_RECT rect1,OG_D_RECT& rect2){return 1;}

	virtual long _LoadSubGraph(BOOL bReLoad /*= FALSE*/,CSubsectionInfo*	m_pRESecInfo){return 0;}
	virtual long _LoadSubGraph(BOOL bReLoad /*= FALSE*/,CSubsectionInfo*	m_pRESecInfo,char* NoteString){return 0;}
	virtual void _ClearSubGraph(){}
	
	virtual void _DrawOneVecLayer(string strURL,short& VecPtr) {return ;}
	virtual void _DrawOneVecLayer(long lLayerPtr,short& VecPtr) {return ;}
	virtual void _SetOneVecLayerRation(long lLayerPtr,short& VecPtr,double& MaxRation,double& MinRation) {return ;}
	virtual void _GetVecLayerRect(OG_D_RECT* p_rect,short& VecPtr){}

	virtual void _DrawOneRasLayer(string strURL,long& RasPtr) {return ;}
	virtual void _DrawOneRasLayer(long lLayerPtr,long& RasPtr) {return ;}
	virtual void _GetRasterLayerRect(OG_D_RECT* p_rect,long& RasPtr){}

	virtual void _DrawOnMap(string strURL ,long& mapPtr) {return ;}
	virtual void _DrawOnLayer(long lMapPtr,long& mapPtr) {return ;}
	virtual void _SetOneMapLayerRation(long lLayerPtr,long& mapPtr,double& MaxRation,double& MinRation) {return ;}
	virtual void _GetVecMapRect(OG_D_RECT* p_rect,long& mapPtr){}

	//内存数据显示
	virtual void _DrawDotsLayer(vecSubSingOGDot* pDots, long lDotParaPtr,OG_D_RECT& lRect,CSubsectionInfo*	m_pRESecInfo){return ;}
	virtual	void _DrawLinsLayer(vector<vecSubSingOGDot>*, long lLinParaPtr,OG_D_RECT& lRect,vector<OG_LIN_INFO*>m_pRELineInfo){return ;}
	virtual	void _DrawRegsLayer(vector<vecSubSingOGDot>*, long lRegParaPtr,OG_D_RECT& lRect,vector<OG_REG_INFO*>m_pRERegInfo){return ;}

	virtual void _DrawLinsLayer(vecSubSingOGDot* pLins, long lLinParaPtr){return ;}
	virtual void _DrawRegsLayer(vecSubSingOGDot* pRegs, long lRegParaPtr){return ;}

	//内存数据显示
	virtual void _DrawDotsLayer(vecSubSingOGDot* pDots, long& lDotParaPtr){return ;}


	virtual short _StopFlash(short type){return 0;}	    //type=-1/PNT/LIN/REG/NOD,分别表示停止全部闪烁/停止闪烁点/停止闪烁线/停止闪烁区/停止闪烁结点
	virtual short _StartFlash(short ai,long *ptNo, long num, short type){return 0;}; //开始(重新)闪烁某类图元
	virtual short _StartFlash(OG_ENTITY_MSG *pt, long num){return 0;};	 //开始(重新)闪烁图元

	///下列函数设置闪烁图元并开始闪烁, 或替换正在闪烁的同类图元
	virtual short _FlashPnt(short ai, long *ptNo, long num){return 0;}//设置(开始)闪烁点图元，ptNo[0]到ptNo[num-1]为图元号
	virtual short _FlashLin(short ai, long *ptNo, long num){return 0;} //设置(开始)闪烁线图元，ptNo[0]到ptNo[num-1]为图元号
	virtual short _FlashReg(short ai, long *ptNo, long num){return 0;} //设置(开始)闪烁区图元，ptNo[0]到ptNo[num-1]为图元号
	virtual short _FlashNod(short ai, long *ptNo, long num){return 0;} //设置(开始)闪烁结点图元，ptNo[0]到ptNo[num-1]为图元号
	virtual short _FlashDot(gme_vector2d *ptXY, long num){return 0;}          //设置(开始)闪烁坐标点，  ptXY[0]到ptXY[num-1]为点坐标值

	virtual void  _DrawXORLine(long x0,long y0,long x1,long y1){return;};
	virtual	short _AppendFlashDot(gme_vector2d *ptxy, long num){return 0;};          //添加闪烁坐标点，  ptXY[0]到ptXY[num-1]为点坐标值
	virtual void  _DrawXORRect(long x0,long y0,long x1,long y1){return;};
	virtual void _GetOGRange(short ai,OG_D_RECT *rect){return;};

	//virtual void OnCreate(CWnd* parentWnd, int cx, int cy, int wid, int hei){} //
	virtual void OnSize(UINT nType, int cx, int cy){}
	virtual void OnTimer(UINT nIDEvent){}
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags){}
	/*virtual void OnLButtonDown(UINT nFlags, CPoint point){}
	virtual void OnLButtonUp(UINT nFlags, CPoint point){}
	virtual void OnMouseMove(UINT nFlags, CPoint point){}
	virtual void OnRButtonDown(UINT nFlags, CPoint point){}
	virtual void OnRButtonUp(UINT nFlags, CPoint point){}
	virtual void OnLButtonDblClick(UINT nFlags, CPoint point){}
	virtual void OnRButtonDblClick(UINT nFlags, CPoint point){}
	virtual void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags){}
	virtual BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint point){return TRUE;}*/

	//  [3/9/2015 Feng]
	virtual void _DrawOnWebLayer(string strURL ,long& webPtr){return ;}
	virtual void _DrawOnWebLayer(long lLayerPtr,long& webPtr){return ;}
	virtual void _GetWebLayerRect(OG_D_RECT* p_rect,long& webPtr){return ;}

	virtual void _DrawOnMosaicLayer(string strURL,long& MosaicPtr){return ;}
	virtual void _DrawOnMosaicLayer(long lLayerPtr,long& MosaicPtr){return ;}
	virtual void _GetMosaicLayerRect(OG_D_RECT* p_rect,long& MosaicPtr){return ;}

	virtual short CreateHistogram(){return 0;}
	virtual BOOL OpenHistm(char* szFileName,double	dStaDepth=0,double dEndDepth=0){return true;}
	virtual long CreateTblHead(){return 0;}
	virtual long CreateTblTail(){return 0;}
	virtual void SaveHistm(){return ;}
	//关闭柱状图
	virtual void	CloseHistm(){return ;}
	virtual BOOL	SaveToGisFile(char* strParthName=NULL){return true;}
	//设置选中m_pSelTrace图道参数,由图道自己弹对话框
	virtual void SetTraceParam(){return;}
	//取消当前合并
	virtual void DisUnite(){return;}
	//左组合
	virtual void UnionLeft(){return;}

	virtual void	UnionRight(){return;}

	//删除选中图道-多选
	virtual void DeleteSelTraces(){return;}

	//设置整个页面信息
	virtual void SetPageParam(){return;}

	//插入图道
	//说明:调用对话框,再调用上面函数实现
	virtual void InsertTrace(){return;}

	//清除选中图道数据	
	virtual BOOL  ClearTraceDat(){return TRUE;}

	//设置组合属性==================================
	virtual void	SetUnionParam(){return;}

	//修改表头表尾单元格属性
	virtual void OnPopGridPro(){return;}

	virtual void OnPoptraceAdjData() {return;}

	virtual void OnPopLayProperty() {return;}

	virtual void OnPopLayDelLay(){return;}

	virtual void OnPopLayNextMerge(){return;}

	virtual void OnPopLayPreMerge(){return;}

	virtual void OnPopTextPro(){return;}

	virtual void OnPopGridAverWidth(){return;}

	virtual void OnPopGridDelGrid(){return;}

	virtual void OnPopGridDelRow(){return;}

	virtual void OnPopGridSplit(){return;}

	virtual void OnPopGridInsertRow(){return;}

	virtual void OnPopTextgridDel(){return;}

	virtual void OnPopTextgridPro(){return;}

	virtual void OnPopSetgridborder(){return;}

	virtual void OnPopSetgridrow(){return;}

	virtual void OnPopSetgridtext(){return;}

	virtual void OnPoptraceSetdelam(){return;}
	
	//test,设置解释分层状态,一般应该在在加载数据之后设置,
	//现在测试,调用了SetDelamination(); 和 AutoAddTraceBind();
	//并且把解释分层标准设入BasFrmView
	virtual void SetDelaminationAuto(){return;}
	
	//设置-当前分层标准下的标准分层--
	virtual void SetStdStratInfo(std::vector<StdStratInfoDLM> *pStdStratList){return;}
	
	//设置-当前柱状图的实际地层
	virtual void SetStratInfo(std::vector<StdStratInfoDLM> *pStratList){return;}
	
	//清楚柱状图图道的所有数据
	virtual void	CleanAllTraceData(){return;}
	
	//获取专业类型
	virtual long	GetHistmProType(){return 0;}
	
	//获取绘图比例
	virtual double	GetScale(){return 0;}
	
	//设置柱状图起始和终止深度和比例
	//dStaDepth	in	柱状图起始深度设定值
	//dEndDepth	in	柱状图终止深度设定值,若小于等于0,则不修改原深度设定
	virtual void SetPageDepth(double	dStaDepth=0,double dEndDepth=0,double dScale =0){return;}
	
	//取出图道数目
	virtual long GetTraceNum(){return 0;}
	
	//获取道头/尾表格基础单元格数量
	virtual long	GetHeadGridNum(){return 0;}
	virtual long	GetTailGridNum(){return 0;}
	//根据索引获取单元格Mac宏,
	//入口:	Idx			索引号
	//出口:	lGridMac	返回单元格的宏
	//返回:成功1,否则0
	virtual long	GetHeadGridMac(long Idx,long& lGridMac){return 0;}
	virtual long	GetTailGridMac(long Idx,long& lGridMac){return 0;}
	//根据索引设置单元格标题
	virtual void	SetHeadGridTitle(long Idx,char* strTitle){return ;}
	virtual void	SetTailGridTitle(long Idx,char* strTitle){return ;}
	
	virtual long	GetTraceType(long lIndex){return 0;}
	
	//获取图道的ID,名称等信息=========================================================
	//说明:图道序号指柱状图从左到右,从上到下的顺序,从0开始的图道序号,以下同
	//参数:	lIndex			in	图道序号
	//		lTraceMac		out	图道ID,	失败返回-1
	//		strTraceTitle	out	图道名称,失败返回Null
	virtual void	GetTraceInfo(long	lIndex,long &lTraceMac,char* strTraceTitle=NULL){return ;}
	
	//加载数据==========================================================
	//参数说明: lIndex	in	图道的索引号,从左往右数,从0开始
	//pFirData		in	第一个数据指针
	//pFirData		in	第一个数据长度
	//pSecData		in	第二个数据指针
	//pSecData		in	第二个数据长度
	//lFlag=0		in	保留标志位
	virtual void	SetTraceData(long	lIndex,
						WellData* pFirData, 
						long	lFstDatelen,
						WellData* pSecData=NULL,
						long	lSecDatalen=0,
						long	lFlag=0){return ;}
						
/*----COM 专用函数,不使用窗口相关函数,在没有窗口的情况下打开柱状图,转换柱状图成MapGis工程
 *生成柱状图等工作.-------------------------------*/
	//打开柱状图
	//szFileName in 包含完整的路径,文件名,和后缀名
	//dStaDepth	in	柱状图起始深度设定值
	//dEndDepth	in	柱状图终止深度设定值,若小于等于0,则不修改原文件内的深度设定
	//返回：成功1,失败0
	virtual BOOL ComOpenHistm(char* szFileName,double	dStaDepth=0,double dEndDepth=0){return 0;}
	
	//设置柱状图起始和终止深度--原ComSetPageDepth()修改
	//dStaDepth	in	柱状图起始深度设定值
	//dEndDepth	in	柱状图终止深度设定值,若小于等于0,则不修改原深度设定
	virtual void ComSetPageDepth(double	dStaDepth,double dEndDepth,double dScale){return ;}
//------COM 专用函数----------------------------------------------------------------------//

	//根据宏获取图道数据，在获取解释分层描述文本时使用，
	//说明:;内存由图道申请和释放
	//参数:	lMac		in  图道宏
	//		pData		out	数据数组;
	//		DataLength	out	pWellData数组长度;
	//返回:成功返回1,否则返回0; 
	virtual bool GetTraceDataByMac(long lMac,WellData* &pWellData,long &lDataLen){return 0;}
	
	//获取操作序列及长度,内存由内部自动释放
	virtual bool GetDelamOper(DelaminatOper* &pDelamOper,long &lDelamOperLen){return 0;}

	virtual void SetHoleTile(string str_holeTitle){return ;}
	virtual	void SaveAsHistm(char* szFileName,long	lFlag = 1){return ;}

	virtual short		GetAreaInst(){return 0;}
	virtual short		SetEditArea(short ai){return 0;}
	virtual short		GetEditArea(short aitype){return 0;}
	virtual short		ClearEditArea(short aitype){return 0;}


	virtual long _GetProject(){return 0;}
	virtual long _SetProject(long new_prj){return 0;}
	virtual long _ClearProject(){return 0;}

	virtual void CloseArea(short& pAI){}
	virtual void PRJDeleteProject(long& prj){}
	virtual void CloseRasterArea(long& rasterAi){}

	virtual char _SetOriginalDispFlag(char flag){return 1;} //还原显示

private:
	HWND m_hREWnd;
	//CWnd*	m_pWnd;
	RenderEngineType m_lREType;
};
