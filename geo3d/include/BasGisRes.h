#pragma once
#include "G2DToolDef.h"	
#include "geo2dtools_global.h"
#include <QPainter> 


namespace Smart3dMap
{

	//保存参数的XML路径
	#define XPATH_LINWIDTH	"GEO3DCFG/G2DTool/LinWidth"
	#define XPATH_LINCOLOR	"GEO3DCFG/G2DTool/LinColor"
	#define XPATH_REGCOLOR	"GEO3DCFG/G2DTool/RegColor"
	#define XPATH_LINBUF	"GEO3DCFG/G2DTool/LinBuf"
	#define XPATH_SFCLSPATH	"GEO3DCFG/G2DTool/SfclsPath"
	#define XPATH_SFCLSFIELD "GEO3DCFG/G2DTool/SfclsField"
	#define XPATH_LINSFCLSPATH	"GEO3DCFG/G2DTool/LineSfclsPath"
	#define XPATH_LINSFCLSFIELD	"GEO3DCFG/G2DTool/LineSfclsField"
	//
	#define XPATH_PNTSFCLSPATH	"GEO3DCFG/G2DTool/PntSfclsPath"
	#define XPATH_PNTSFCLSFIELD	"GEO3DCFG/G2DTool/PntSfclsField"
	//自定义要素
	#define XPATH_TMPSFCLSPATH		"GEO3DCFG/G2DTool/TempSfclsPath"
	#define XPATH_TMPSFCLSFIELD		"GEO3DCFG/G2DTool/TempSfclsField"
	#define XPATH_TMPLINSFCLSPATH	"GEO3DCFG/G2DTool/TempLineSfclsPath"
	#define XPATH_TMPLINSFCLSFIELD	"GEO3DCFG/G2DTool/TempLineSfclsField"
	#define XPATH_TMPPNTSFCLSPATH	"GEO3DCFG/G2DTool/TempPntSfclsPath"
	#define XPATH_TMPPNTSFCLSFIELD	"GEO3DCFG/G2DTool/TempPntSfclsField"

	#define XPATH_PNTBUF			"GEO3DCFG/G2DTool/PntBuf"
	#define XPATH_PNTPARA			"GEO3DCFG/G2DTool/PntPara"

		class CG2DBaseTool;
		class GEO2DTOOLS_EXPORT CBasGisRes
		{
		public:
			CBasGisRes(CG2DBaseTool *pTool);
			virtual ~CBasGisRes();
		public:
			CG2DBaseTool *GetExtTool() { return m_pTool; }
			void SetExtTool(CG2DBaseTool *pTool);
			//坐标转换矩形映射
			void SetRectMapping(gme_rect_2i &WndRect, gme_rect_2i &LogRect);

			//点到点距离
			double	DistofPntToPnt(gme_vector2d *pnt0, gme_vector2d *pnt1);

			//虚函数
		public:
			// 设置/释放鼠标捕获
			virtual HWND SetCapture() { return NULL; }
			virtual bool ReleaseCapture() { return false; }

			//造平行线
			virtual long CalcParallel_l(gme_vector2d *pPntBuf, long lPntNum, double dist, int dire) = 0;

			//常用坐标转换
			virtual long LpToWp(gme_vector2d &logPnt, POINT &wndPnt) = 0;
			virtual long WpToLp(POINT &wndPnt, gme_vector2d &logPnt) = 0;
			virtual long DpToWp(POINT &DevPnt, POINT &wndPnt) = 0;
			virtual long WpToDp(POINT &wndPnt, POINT &DevPnt) = 0;
			virtual long LpToDp(gme_vector2d &logPnt, POINT &DevPnt) = 0;
			virtual long DpToLp(POINT &DevPnt, gme_vector2d &logPnt) = 0;
			virtual long WpToMp(POINT &wndPnt, gme_vector2d &logPnt) = 0;
			virtual long MpToWp(gme_vector2d &logPnt, POINT &wndPnt) = 0;
			// ---------- 绘制相关------------//
			//	gme_vector2d, double型的为逻辑坐标,  CPoint,	long型的为窗口坐标
			virtual void DrawXORLine(long x0, long y0, long x1, long y1) = 0;
			virtual void DrawXORRect(long x0, long y0, long x1, long y1) = 0;
			virtual void DrawXOREllipse(gme_rect_2i &rect) = 0;
			virtual void DrawXORCircle(long x0, long y0, long lCircleRad) = 0;
			virtual void DrawPolyGon(POINT *lxy, long ne, int na) = 0;
			virtual void DrawPolyLine(POINT *lxy, long ne, int na) = 0;
			virtual long DrawRegEage(vector<POINT> &regDots, BOOL bReg = FALSE) = 0;
			virtual void DrawPolygon(gme_vector2d* poly, long pntNum) = 0;

			virtual void InvalidateRect(CONST gme_rect_2i* lpRect = NULL, BOOL bErase = TRUE) { return; }
			virtual void UpdateWindow() { return; }
			virtual void Clear() { return; }
			virtual void RemoveLastPnt() { return; }

			virtual void setLinParam() { return; }
			virtual void setRegParam() { return; }
		

			virtual HWND GetGisView(void) = 0;

		public:
			bool			m_bXOR;

		protected:
			QPen *GetDefaultPen();
			QBrush *GetDefaultBrush();

			CG2DBaseTool*	m_pTool;

			gme_rect_2i		m_WndRect;	//窗口坐标矩形范围
			gme_rect_2i		m_LogRect;	//逻辑坐标矩形范围
			QPen		*m_pPen;	//画笔
			QBrush		*m_pBrush;	//画刷

			BOOL		m_bValid;	//标示当前资源是否为有效资源,  主要是"是否可以做坐标转换"
			HWND		m_hWnd;


			//设置的文件路径
			string	m_strRegSFCLSPath;//行政区简单要素类路径
			string	m_strRegSFCLSDield;//行政区简单要素类属性名

			string m_strLinSFclsPath;//线路简单要素类路径
			string m_strLinSFclsField;//线路简单要素类属性名

			string m_strPntSFclsPath;//点简单要素类路径
			string m_strPntSFclsField;//点简单要素类属性名


			//[12/24/2012 lt]自定义文件路径
			string	m_strTmpSFCLSPath;//行政区简单要素类路径
			string	m_strTmpSFCLSDield;//行政区简单要素类属性名

			string m_strTmpLinSFclsPath;//线路简单要素类路径
			string m_strTmpLinSFclsField;//线路简单要素类属性名

			string m_strTmpPntSFclsPath;//点简单要素类路径
			string m_strTmpPntSFclsField;//点简单要素类属性名

		};
}