#ifndef _G2DTOOL_DEF_H
#define _G2DTOOL_DEF_H

#include <windows.h>
#include <vector>
#include <string>
using namespace std;

#include "gmeStru.h"
#include "OGMessageListener.h"
#include "OGGeo3dMsgIDDef.h"

namespace Smart3dMap
{

	//创建\Tool
	#define G2DTOOL_CREATE			0xFFFFE010	//创建Tool, wParam为G2DToolParam *, lParam指定附加数据,也可以用下面的消息
	#define G2DTOOL_PIPE			0xFFFFE011	//创建消息管道工具, 参数同上
	#define G2DTOOL_PNTORECT		0xFFFFE012	//创建点/矩形工具, 参数同上
	#define G2DTOOL_LIN				0xFFFFE013	//创建线路工具, 参数同上
	#define G2DTOOL_REG				0xFFFFE014	//创建多边形工具, 参数同上
	#define G2DTOOL_CIRCLE			0xFFFFE015	//创建圆形工具, 参数同上
	#define G2DTOOL_MAPLAY			0xFFFFE016	//创建地理要素工具, 参数同上
	#define G2DTOOL_LINELAY			0xFFFFE019	//创建线路要素工具, 
	#define G2DTOOL_POINTLAY		0xFFFFE022	//创建点要素工具, 参数同上

	#define G2DTOOL_MAPLAY_DLG		0xFFFFE017	//地理要素工具，弹对话框供用户选择区；参数同上
	#define G2DTOOL_LIN_DLG			0xFFFFE018	//线路工具，弹对话框供用户选择线；参数同上
	#define G2DTOOL_PNT_DLG			0xFFFFE023	//点工具，弹对话框供用户选择线；参数同上
	#define G2DTOOL_RELEASE			0xFFFFE000	//通过消息释放当前Tool
	#define G2DTOOL_ACTIVE			0xFFFFE001	//内部消息，用于激活Tool工具 zj 2012.3.17

	//设置当前Tool参数
	#define G2DTOOL_PARAM			0xFFFFE020	//wParam为G2DToolParam *, lParam为DWORD
	#define G2DTOOL_PARAM_GET		0xFFFFE021	//wParam为G2DToolParam *, lParam为DWORD *

	//Tool绘制参数设置对话框
	#define G2DTOOL_CONFIG			0xFFFFE025	//弹出参数设置对话框, 无参数

	//获取当前Tool基本信息
	#define G2DTOOL_GETTOOL			0xFFFFE030	//wParam 为 CG2DBaseTool **, lParam不用

	//鼠标位置信息
	#define G2DTOOL_MOUSEMOVE_POS	0xFFFFE210	//鼠标移动时往外发送逻辑坐标,wParam为当前点序号, lParam为 gme_vector2d *
	#define G2DTOOL_LBTNDOWN_POS	0xFFFFE211	//点击鼠标时往外发送逻辑坐标,wParam为当前点序号, lParam为 gme_vector2d *

	//绘制多边形
	#define G2DTOOL_DRAWREGEAGE		0xFFFFE220	//绘制多边形,wParam为当前点序号, lParam为 gme_vector2d *
	#define G2DTOOL_DRAWREGEAGE2	0xFFFFE221	//绘制多边形(填充),wParam为当前点序号, lParam为 gme_vector2d *

	//闪烁消息
	#define G2DTOOL_FLASH_LAY		0xFFFFE222	//闪烁消息，wParam闪烁的标志（1表示区，2表示线，3表示点）, lParam为 DOT

	//Tool完成后返回消息号（具体参数使用方法附后）
	#define G2DTOOL_PIPE_INFO		0xFFFFE049	//管道消息, wParam 为 MsgParam *, lParam 为 DWORD

	//Tool取消时广播消息
	#define G2DTOOL_CANCEL			0xFFFFE060	//Tool取消时往外发出通知,wParam为Tool类型,lParam为lFuncID

	//获取Tool的结果信息
	#define G2DTOOL_GET_DOTLIST		0xFFFFE080	//获取点列表, 
	#define G2DTOOL_GET_RECTLIST 	0xFFFFE081	//获取矩形列表
	#define G2DTOOL_GET_LINLIST		0xFFFFE082	//获取线列表
	#define G2DTOOL_GET_REGLIST		0xFFFFE083	//多边形数据(通用，推荐)
	#define G2DTOOL_GET_CIRLIST		0xFFFFE084	//圆形数据
	#define G2DTOOL_GET_MAPLAY		0xFFFFE085	//地理要素数据
	#define G2DTOOL_GET_REGLIST2	0xFFFFE086	//多边形数据,自动计算投影参数(通用，推荐)

	#define MSG_DRAW_INTERACTOR_RANGE		(WM_USER+0x20121010)	//交互圈定范围



		enum G2DQueryType
		{
			G2D_COMM_QUERY = 0,	//通用查询，通过鼠标交互的形式选择范围
			G2D_DIS_QUERY = 1,	//行政去查询
			G2D_MAPORRECT_QUERY = 2,	//范围或者图幅查询
			G2D_SYN_QUERY = 3,	//综合查询
		};

		//交互工具类型
		enum G2DToolType
		{
			G2DTT_PIPE = 0,		//Pipe只负责消息转发
			G2DTT_PNT_RECT = 1,	//点
			G2DTT_LIN = 2,		//线
			G2DTT_REG = 3,		//多边形
			G2DTT_CIR = 4,		//圆形
			G2DTT_MAPLAY = 5,	//地理要素
			G2DTT_MAPLAY_DLG = 6,//地理要素(弹对话框)
			G2DTT_LIN_DLG = 7,	//线路(弹对话框)
			G2DTT_LINELAY = 8,	//线路要素
			G2DTT_POINTLAY = 9,	//点要素
			G2DTT_PNTLAY_DLG = 10//点要素(弹对话框)
		};

		//交互工具模式
		enum G2DToolMode
		{
			G2DTM_SINGLE = 0,	//单次使用，交互完成后即释放Tool
			G2DTM_RETAIN = 1	//持续多次使用，表示在交互完成后还可以继续交互
		};

		//Tool基本参数
		typedef struct G2DTOOL_PARAM_STRUCT
		{
			G2DToolType	m_Type;			//必填，Tool类型
			G2DToolMode	m_Mode;			//可选，Tool模式，单次使用、持续多次使用，
			COGListener	*m_pListener;	//可选，指定监听对象（Tool完成后消息发送对象，如this），不指定则广播
			long		m_lFuncID;		//必填，指定回发消息号
			string		m_strFuncID;		//必填，指定回发消息号
			long		m_lFuncCurID;	//可选，鼠标左键单击实时消息
			BOOL		m_bCalcBuf;		//可选，线路工具可设置
			WPARAM		m_wParam;		//可选，含义由调用者解析
			LPARAM		m_lParam;		//可选，含义由调用者解析

			G2DTOOL_PARAM_STRUCT()
			{
				m_Type = G2DTT_PNT_RECT;
				m_Mode = G2DTM_SINGLE;
				m_pListener = 0;
				m_strFuncID = "";
				m_lFuncID = -1;
				m_lFuncCurID = 0;
				m_bCalcBuf = FALSE;
				m_wParam = 0;
				m_lParam = 0;
			}
		}G2DToolParam;



		//Tool内部数据类型定义
		typedef	std::vector<gme_vector2d>	LinDots;	//线
		typedef	std::vector<gme_vector2d>	RegDots;	//区
		typedef	std::vector<gme_vector2d>	DotList;	//点列表
		typedef	std::vector<gme_rect_2d>	RectList;	//矩形列表
		typedef	std::vector<LinDots>		LinList;	//线列表
		typedef	std::vector<RegDots>		RegList;	//多边形列表
		typedef	std::vector<gme_circle>		CircleList;	//圆列表
}
#endif	//_G2DTOOL_DEF_H