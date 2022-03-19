#pragma once

#include "geo2dtools_global.h"
#include "G2DToolDef.h"	
#include "BasGisRes.h"
#include "s3d_GeomDefine.h"
#include <windows.h>
namespace Smart3dMap
{
	//��Ϣ����
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

	//��Ϣ����
	typedef union MSGPARAM_UNION
	{
		//��Ϣ����
		MsgType	msgType;	//���� TMT_LButtonDown

		//�����Ϣ����(���庬�����Windows�����Ϣ����)
		struct _Mouse
		{
			UINT  nFlags;
			short zDelta;	//�ò�����������Ϣ��Ч
			POINT point;
		}Mouse;

		//������Ϣ����(���庬�����Windows������Ϣ����)
		struct _Keyboard
		{
			UINT nChar;
			UINT nRepCnt;
			UINT nFlags;
		}Keyboard;

		//�����Ĳ˵���Ϣ����
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

		//����ID���á���ȡ
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

		//��ȡToolMode
		G2DToolMode GetToolMode()
		{
			return m_toolParam.m_Mode;
		}

		//Tool�������á���ȡ
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

		//�����������á���ȡ
		void SetToolData(DWORD dwData)
		{
			m_dwData = dwData;
		}
		DWORD GetToolData()
		{
			return m_dwData;
		}
	public:
		//�����Ϣ��Ӧ
		virtual long onLButtonDown(UINT nFlags, POINT point) { return 0; };
		virtual long onLButtonUp(UINT nFlags, POINT point) { return 0; };
		virtual long onLButtonDblClk(UINT nFlags, POINT point) { return 0; };
		virtual long onRButtonDown(UINT nFlags, POINT point) { return 0; };
		virtual long onRButtonUp(UINT nFlags, POINT point);	//Ĭ���Ҽ�ֹͣ��ȡ����ǰTool
		virtual long onMouseMove(UINT nFlags, POINT point);	//Ĭ�ϸ������������߼�����
		virtual long onMouseWheel(UINT nFlags, short zDelta, gme_vector2d pt) { return 0; }

		//������Ϣ
		virtual long onKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) { return 0; };
		virtual long onKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) { return 0; };

		//�˵���Ϣ��Ӧ
		virtual	long OnContextMenu(HWND hWnd, int x, int y) { return 0; };
	public:
		gme_rect_2d& getRect();

		//��ȡTool�Ľ����Ϣ
		virtual	long GetDotList(DotList *pdotList) { return 0; };
		virtual	long GetRectList(RectList *prectList) { return 0; };
		virtual	long GetLinList(LinList *plinList, double *pdBufR = NULL) { return 0; };
		virtual	long GetLinBufferPolyList(RegDots*linBufferPoly, RegList *linBufferPolyList, double *pdBufR = NULL) { return 0; };
		virtual	long GetRegList(RegList *pregList) { return 0; };
		virtual long GetRegList(vector<PolyRef>& polyList);
		//virtual long GetAllRegList(vector<PolyRef>& polys) { return 0; };
		virtual	long GetCircleList(CircleList *pcircleList) { return 0; };

		//���û������뾶
		virtual	double GetBufR() { return 0; };
		virtual	long SetBufR(double dBufR) { return 0; };
	protected:
		//�������λ����Ϣ
		long MousePosMsg(POINT &point);
		long RecallFunc(WPARAM wParam, WPARAM lParam, bool bBroad = false);

	public:
		static double m_dLinWid;//�߿�
		static double m_dLinRadius;	//�߻���뾶
		static long	  m_lLinClr;//����ɫ
		static long	  m_lRegClr;//����ɫ
		static double m_dPntRadius;//�㻺��뾶 

	protected:
		HWND			m_pView;
		__int64			m_pGisRes;

		G2DToolParam	m_toolParam;//Tool����
		DWORD			m_dwData;	//Tool��������
		long			m_lPntPara;	// Բ�ķֶ���
		gme_rect_2d		mRect;

		RegList			m_resRegList;	//��������
		LinDots			m_LinDotList;
		LinList			m_LinList;

		BOOL			m_ContiFlag;	//������ѯ�ı��
	};
}
