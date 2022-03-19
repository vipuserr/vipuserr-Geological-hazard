#pragma once
#include "G2DToolDef.h"	
#include "geo2dtools_global.h"
#include <QPainter> 


namespace Smart3dMap
{

	//���������XML·��
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
	//�Զ���Ҫ��
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
			//����ת������ӳ��
			void SetRectMapping(gme_rect_2i &WndRect, gme_rect_2i &LogRect);

			//�㵽�����
			double	DistofPntToPnt(gme_vector2d *pnt0, gme_vector2d *pnt1);

			//�麯��
		public:
			// ����/�ͷ���겶��
			virtual HWND SetCapture() { return NULL; }
			virtual bool ReleaseCapture() { return false; }

			//��ƽ����
			virtual long CalcParallel_l(gme_vector2d *pPntBuf, long lPntNum, double dist, int dire) = 0;

			//��������ת��
			virtual long LpToWp(gme_vector2d &logPnt, POINT &wndPnt) = 0;
			virtual long WpToLp(POINT &wndPnt, gme_vector2d &logPnt) = 0;
			virtual long DpToWp(POINT &DevPnt, POINT &wndPnt) = 0;
			virtual long WpToDp(POINT &wndPnt, POINT &DevPnt) = 0;
			virtual long LpToDp(gme_vector2d &logPnt, POINT &DevPnt) = 0;
			virtual long DpToLp(POINT &DevPnt, gme_vector2d &logPnt) = 0;
			virtual long WpToMp(POINT &wndPnt, gme_vector2d &logPnt) = 0;
			virtual long MpToWp(gme_vector2d &logPnt, POINT &wndPnt) = 0;
			// ---------- �������------------//
			//	gme_vector2d, double�͵�Ϊ�߼�����,  CPoint,	long�͵�Ϊ��������
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

			gme_rect_2i		m_WndRect;	//����������η�Χ
			gme_rect_2i		m_LogRect;	//�߼�������η�Χ
			QPen		*m_pPen;	//����
			QBrush		*m_pBrush;	//��ˢ

			BOOL		m_bValid;	//��ʾ��ǰ��Դ�Ƿ�Ϊ��Ч��Դ,  ��Ҫ��"�Ƿ����������ת��"
			HWND		m_hWnd;


			//���õ��ļ�·��
			string	m_strRegSFCLSPath;//��������Ҫ����·��
			string	m_strRegSFCLSDield;//��������Ҫ����������

			string m_strLinSFclsPath;//��·��Ҫ����·��
			string m_strLinSFclsField;//��·��Ҫ����������

			string m_strPntSFclsPath;//���Ҫ����·��
			string m_strPntSFclsField;//���Ҫ����������


			//[12/24/2012 lt]�Զ����ļ�·��
			string	m_strTmpSFCLSPath;//��������Ҫ����·��
			string	m_strTmpSFCLSDield;//��������Ҫ����������

			string m_strTmpLinSFclsPath;//��·��Ҫ����·��
			string m_strTmpLinSFclsField;//��·��Ҫ����������

			string m_strTmpPntSFclsPath;//���Ҫ����·��
			string m_strTmpPntSFclsField;//���Ҫ����������

		};
}