#pragma once
#include "Geo2DTools.h"
#include "geo2dtools_global.h"

namespace Smart3dMap
{
	class GEO2DTOOLS_EXPORT G2DToolMng
	{
	public:
		static G2DToolMng *getSinglonPtr();
		static G2DToolMng &getSinglon();

	private:
		G2DToolMng();
		virtual ~G2DToolMng();
	public:
		//创建、获取Tool
		CG2DBaseTool *Create2DTool(G2DToolParam *pToolParam, DWORD dwData = 0);
		CG2DBaseTool *Create2DTool(G2DToolType toolType, G2DToolParam *pToolParam, DWORD dwData = 0);
		CG2DBaseTool *Get2DTool();

		//Tool参数设置、获取
		long SetToolParam(G2DToolParam *pToolParam, DWORD dwData);
		long GetToolParam(G2DToolParam *pToolParam, DWORD *pdwData);

		//Tool参数设置、获取
		long SetToolParam(G2DToolParam *pToolParam);
		long GetToolParam(G2DToolParam *pToolParam);

		//附加数据设置、获取
		long SetToolData(DWORD dwData);
		DWORD GetToolData(DWORD *pdwData = NULL);

		//命令ID设置、获取
		long SetFuncID(long lFuncID);
		long GetFuncID();
		string SetFuncID(string lFuncID);
		string GetStrFuncID();
		//释放当前Tool
		void ReleaseTool();

		//获取Tool的结果信息
		long GetDotList(DotList *pdotList);
		long GetRectList(RectList *prectList);
		long GetLinList(LinList *plinList, double *pdBufR = NULL);
		long GetLinBufferPolyList(RegDots*linBufferPoly, RegList *linBufferPolyList, double *pdBufR = NULL);
		long GetRegList(RegList *pregList);
		long GetRegList(vector<PolyRef>& polyList);
		//long getAllRegions(vector<vector<vector<gme_vector2d>>>& polygons);
		long GetCircleList(CircleList *pcircleList);

		// 绘制区边界
		long DrawRegEage(DotList *regDots);

		//绘制线
		long DrawLine(DotList* linDots);

		// 绘制区(是否填充)
		long DrawReg(DotList *regDots, BOOL bFill = TRUE);

		//[12/5/2012]闪烁效果，将view中的闪烁移到这里
		void FlashArea(long flag, gme_vector2d *dot);


	private:
		CG2DBaseTool	*m_pBasTool;//当前Tool
		__int64			m_pGisRes;	//Tool需要的绘图、坐标转换资源
		static int      m_ResCount;	//记录当前创建的App实例数目





	};
}