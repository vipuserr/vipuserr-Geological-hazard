// -----------------------------------------------------------------
//
// Copyright:	ZondySoft 2004
//
// File:		GsProgrApi.h
//
// Project:		GeoStatProgr
//
// Creator:		刘海英
//
// Time:		09:22 2008-2-20
//
// Description:	Geological Statistical Library
//
// -----------------------------------------------------------------

#ifndef _GEOSTAT_PROGR_API_H
#define _GEOSTAT_PROGR_API_H


#ifndef _CGEOSTAT_PROGR_LIB
  #define GEOSTAT_PROGR_DLL  __declspec(dllimport)
#else
  #define GEOSTAT_PROGR_DLL  __declspec(dllexport)
#endif


#ifdef __cplusplus
extern "C" {
#endif

//开始进程控制
//功能：
//    创建进度条
//参数:
//    WindowTitleName --------------->窗口标题
//    TitleName --------------------->子标题
long GEOSTAT_PROGR_DLL gsStartProgress(LPCTSTR WindowTitleName,LPCTSTR TitleName);
//结束进程控制
//功能：
//    删除进度条
//参数：
//     hProgID ---------------------->进度条标识ID
BOOL GEOSTAT_PROGR_DLL gsEndProgress(long hProgID);
//设置进程控制条的指示范围.
//参数：
//     hProgID ---------------------->进度条标识ID
//     nLower ----------------------->指示最低值
//     nUpper ----------------------->指示最高值
void GEOSTAT_PROGR_DLL gsSetRange(long hProgID,int nLower,int nUpper);
//设置进程控制条的新指示位置.
//参数：
//     hProgID ---------------------->进度条标识ID
//     nPos ------------------------->进度条新位置
//返回：进度条当前指示位置    
int  GEOSTAT_PROGR_DLL gsSetPos(long hProgID,int nPos);
//设置进程控制条的新步长.
//参数
//     hProgID ---------------------->进度条标识ID
//     nStep ------------------------>进度条新步长
//返回：进度条当前步长
int  GEOSTAT_PROGR_DLL gsSetStep(long hProgID,int nStep);
//按步长增加进程控制条的指示量.
//参数
//     hProgID ---------------------->进度条标识ID
//返回：进度条当前位置
int  GEOSTAT_PROGR_DLL gsStepIt(long hProgID);
//设置进程控制条的新指示位置的偏移量,返回进程控制条指示的当前位置.
//参数：
//     hProgID ---------------------->进度条标识ID
//     nPos ------------------------->进度条位置偏移量
//返回：进度条当前位置
int  GEOSTAT_PROGR_DLL gsOffsetPos(long hProgID,int nPos);
//是否选中CANCEL.
BOOL IsUserBreak(HWND hWnd);
//是否终止进程控制.
//参数：
//     hProgID ---------------------->进度条标识ID
//返回：终止进程标识
BOOL GEOSTAT_PROGR_DLL gsIsStopProgress(long hProgID);
#ifdef __cplusplus
}
#endif

#ifndef _CGEOSTAT_PROGR_LIB
	#pragma comment(lib, "S3dAppProgr.lib")
#endif


#endif //_GEOSTAT_LIB_H	  