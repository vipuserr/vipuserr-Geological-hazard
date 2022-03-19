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
		//��������ȡTool
		CG2DBaseTool *Create2DTool(G2DToolParam *pToolParam, DWORD dwData = 0);
		CG2DBaseTool *Create2DTool(G2DToolType toolType, G2DToolParam *pToolParam, DWORD dwData = 0);
		CG2DBaseTool *Get2DTool();

		//Tool�������á���ȡ
		long SetToolParam(G2DToolParam *pToolParam, DWORD dwData);
		long GetToolParam(G2DToolParam *pToolParam, DWORD *pdwData);

		//Tool�������á���ȡ
		long SetToolParam(G2DToolParam *pToolParam);
		long GetToolParam(G2DToolParam *pToolParam);

		//�����������á���ȡ
		long SetToolData(DWORD dwData);
		DWORD GetToolData(DWORD *pdwData = NULL);

		//����ID���á���ȡ
		long SetFuncID(long lFuncID);
		long GetFuncID();
		string SetFuncID(string lFuncID);
		string GetStrFuncID();
		//�ͷŵ�ǰTool
		void ReleaseTool();

		//��ȡTool�Ľ����Ϣ
		long GetDotList(DotList *pdotList);
		long GetRectList(RectList *prectList);
		long GetLinList(LinList *plinList, double *pdBufR = NULL);
		long GetLinBufferPolyList(RegDots*linBufferPoly, RegList *linBufferPolyList, double *pdBufR = NULL);
		long GetRegList(RegList *pregList);
		long GetRegList(vector<PolyRef>& polyList);
		//long getAllRegions(vector<vector<vector<gme_vector2d>>>& polygons);
		long GetCircleList(CircleList *pcircleList);

		// �������߽�
		long DrawRegEage(DotList *regDots);

		//������
		long DrawLine(DotList* linDots);

		// ������(�Ƿ����)
		long DrawReg(DotList *regDots, BOOL bFill = TRUE);

		//[12/5/2012]��˸Ч������view�е���˸�Ƶ�����
		void FlashArea(long flag, gme_vector2d *dot);


	private:
		CG2DBaseTool	*m_pBasTool;//��ǰTool
		__int64			m_pGisRes;	//Tool��Ҫ�Ļ�ͼ������ת����Դ
		static int      m_ResCount;	//��¼��ǰ������Appʵ����Ŀ





	};
}