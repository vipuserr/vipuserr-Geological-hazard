#pragma once

#include "geo2dtools_global.h"
#include "G2DToolDef.h"	
#include "BasGisRes.h"
#include "s3d_GeomDefine.h"
#include <windows.h>
namespace Smart3dMap
{
	//消息类型
	typedef enum G2DToolMsgType
	{
		TMT_LButtonDown = 1,
		TMT_LButtonUp,
		TMT_LButtonDblClk,
		TMT_RButtonDown,
		TMT_RButtonUp,
		TMT_MouseMove,
		TMT_MouseWheel,
		TMT_KeyDown,
		TMT_KeyUp,
		TMT_ContextMenu,
	}MsgType;

	//消息参数
	typedef union MSGPARAM_UNION
	{
		//消息类型
		MsgType	msgType;	//例如 TMT_LButtonDown

		//鼠标消息参数(具体含义参照Windows鼠标消息参数)
		struct _Mouse
		{
			UINT  nFlags;
			short zDelta;	//该参数仅滚轮消息有效
			POINT point;
		}Mouse;

		//键盘消息参数(具体含义参照Windows键盘消息参数)
		struct _Keyboard
		{
			UINT nChar;
			UINT nRepCnt;
			UINT nFlags;
		}Keyboard;

		//上下文菜单消息参数
		struct _ContextMenu
		{
			HWND hWnd;
			int  x;
			int  y;
		}ContextMenu;

		MSGPARAM_UNION()
		{
			memset(this, 0, sizeof(MSGPARAM_UNION));
		}
	}MsgParam;

	class GEO2DTOOLS_EXPORT CG2DBaseTool
	{
	public:
		CG2DBaseTool(__int64 pGisRes, const G2DToolParam& toolParam);
		virtual ~CG2DBaseTool();
	public:
		G2DToolType GetToolType()
		{
			return m_toolParam.m_Type;
		}

		//命令ID设置、获取
		long GetFuncID()
		{
			return m_toolParam.m_lFuncID;
		}
		void SetFuncID(long lFuncID)
		{
			m_toolParam.m_lFuncID = lFuncID;
		}
		string GetStrFuncID()
		{
			return m_toolParam.m_strFuncID;
		}
		void SetFuncID(string strFuncID)
		{
			m_toolParam.m_strFuncID = strFuncID;
		}

		//获取ToolMode
		G2DToolMode GetToolMode()
		{
			return m_toolParam.m_Mode;
		}

		//Tool参数设置、获取
		long GetToolParam(G2DToolParam *pToolParam)
		{
			if (pToolParam)
			{
				*pToolParam = m_toolParam;
			}

			return (pToolParam != NULL);
		}
		void SetToolParam(const G2DToolParam& toolParam)
		{
			m_toolParam = toolParam;
		}

		//附加数据设置、获取
		void SetToolData(DWORD dwData)
		{
			m_dwData = dwData;
		}
		DWORD GetToolData()
		{
			return m_dwData;
		}
	public:
		//鼠标消息响应
		virtual long onLButtonDown(UINT nFlags, POINT point) { return 0; };
		virtual long onLButtonUp(UINT nFlags, POINT point) { return 0; };
		virtual long onLButtonDblClk(UINT nFlags, POINT point) { return 0; };
		virtual long onRButtonDown(UINT nFlags, POINT point) { return 0; };
		virtual long onRButtonUp(UINT nFlags, POINT point);	//默认右键停止、取消当前Tool
		virtual long onMouseMove(UINT nFlags, POINT point);	//默认给监听对象发送逻辑坐标
		virtual long onMouseWheel(UINT nFlags, short zDelta, gme_vector2d pt) { return 0; }

		//键盘消息
		virtual long onKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) { return 0; };
		virtual long onKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) { return 0; };

		//菜单消息响应
		virtual	long OnContextMenu(HWND hWnd, int x, int y) { return 0; };
	public:
		gme_rect_2d& getRect();

		//获取Tool的结果信息
		virtual	long GetDotList(DotList *pdotList) { return 0; };
		virtual	long GetRectList(RectList *prectList) { return 0; };
		virtual	long GetLinList(LinList *plinList, double *pdBufR = NULL) { return 0; };
		virtual	long GetLinBufferPolyList(RegDots*linBufferPoly, RegList *linBufferPolyList, double *pdBufR = NULL) { return 0; };
		virtual	long GetRegList(RegList *pregList) { return 0; };
		virtual long GetRegList(vector<PolyRef>& polyList);
		//virtual long GetAllRegList(vector<PolyRef>& polys) { return 0; };
		virtual	long GetCircleList(CircleList *pcircleList) { return 0; };

		//设置缓冲区半径
		virtual	double GetBufR() { return 0; };
		virtual	long SetBufR(double dBufR) { return 0; };
	protected:
		//发送鼠标位置信息
		long MousePosMsg(POINT &point);
		long RecallFunc(WPARAM wParam, WPARAM lParam, bool bBroad = false);

	public:
		static double m_dLinWid;//线宽
		static double m_dLinRadius;	//线缓冲半径
		static long	  m_lLinClr;//线颜色
		static long	  m_lRegClr;//区颜色
		static double m_dPntRadius;//点缓冲半径 

	protected:
		HWND			m_pView;
		__int64			m_pGisRes;

		G2DToolParam	m_toolParam;//Tool参数
		DWORD			m_dwData;	//Tool附加数据
		long			m_lPntPara;	// 圆的分段数
		gme_rect_2d		mRect;

		RegList			m_resRegList;	//结果多边形
		LinDots			m_LinDotList;
		LinList			m_LinList;

		BOOL			m_ContiFlag;	//连续查询的标记
	};
}
