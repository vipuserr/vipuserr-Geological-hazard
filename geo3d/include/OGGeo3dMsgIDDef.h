#ifndef _OGGEO3DMSGIDDEF_H
#define _OGGEO3DMSGIDDEF_H

#include <string>
using namespace std;

//本头文件主要定义与框架操作相关消息ID号

//定义交互选择后发送回给按位置查询对话框的消息
//WPARAM wParam,  坐标串点的个数
//LPARAM lParam,  坐标串的指针
//坐标串构造方式如下：
//WPARAM wParam  = 1, 为按坐标点查询MSG_QUERY_BYPNT,传鼠标所选的最近钻孔的坐标
//WPARAM wParam  = 2, 为按圆形查询MSG_QUERY_BYCYCLE,第一个坐标为圆心坐标，
//					   第二个坐标的X与Y值都等于圆的半径
//WPARAM wParam  = n, (n>=3), 为其他几种查询方式,传所选择区域的边界坐标串
#define WM_TOOL_QUERY_COMMON	    (0x0400+0x9010)	//
#define WM_LAYER_QUERY_ADVANCED	    (0x0400+0x9006)	//
#define WM_GET_OPENEND_LAYERLIST	(0x0400+0x9007)	// ID不要修改



//////////////地理要素图层WM_USER + 1000 ~ WM_USER + 2000////////////////////////////////////////////
#define WM_SET_CURDBSNO	 (WM_USER + 1000)	//在视图上设置当前的缩放比列,wParam:当前的缩放比列，long型
#define WM_CHANGE_DBS	 (WM_USER + 1001)   //根据缩放比列设置当前底图,wParam:当前的缩放比列，long型
#define WM_ZOOM_DBS		 (WM_USER + 1002)   //缩放底图,wParam:缩小或放大，long型，1为放大，0为缩小
#define WM_RESTOR_DBS	 (WM_USER + 1003)   //复位底图
#define WM_PRE_WND		 (WM_USER + 1004)   //上一个窗口

#define WM_GET_DBSSTATE   (WM_USER + 1005)  //获得当前图层是否打开 wParam , BOOL型指针，TREU为打开，FALSE
											//为关闭或者其他情况
#define WM_SET_DBSVALUE   (WM_USER + 1006)  //设置底图的切换阀值   wParam , long型指针，存储切换阀值，lParam
											//阀值的个数
#define WM_GET_MSDSTATE   (WM_USER + 1007)  //

#define	WM_GET_PRODUCT_LIST (WM_USER + 1008)  //获取产品列表

#define WM_DISP_DBS			  (WM_USER + 6000)
#define WM_DISP				  (WM_USER + 4000)
#define WM_SET_RELTFILEPATH	  (WM_USER + 7000)
#define WM_GET_RELTFILEPATH	  (WM_USER + 7001)
#define WM_GET_PROJECT_PATH	  (WM_USER + 7002)			//获取项目路径

#define CMD_2D_TOOL_RECT_INFO	(WM_USER+0x9000)		//矩形TOOL
#define CMD_2D_TOOL_LIN_INFO	(WM_USER+0x9002)		//线路TOOL
#define CMD_2D_TOOL_REG_INFO	(WM_USER+0x9001)		//多边形TOOL
#define CMD_2D_TOOL_CIR_INFO	(WM_USER+0x9003)		//圆形TOOL
#define CMD_2D_TOOL_MAPLAY_INFO	(WM_USER+0x9004)		//地理要素TOOL

const string	CMD_CONTAINER_LBUTTON_UP_GET_CUR_SEL_LAYER = "获取当前选中图层";

#endif //_OGGEO3DMSGIDDEF_H