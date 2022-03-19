
// -----------------------------------------------------------------
//
// Copyright:	ZondySoft 2008
//
// File:		GsInciseLib.h
//
// Project:		GeoStatIncise
//
// Creator:		刘海英
//
// Time:		16:04 2008-2-28
//
// Description:	Geological Statistical Incise Library
//
// -----------------------------------------------------------------


#ifndef _GEO_STAT_INCISE_LIB_H
#define _GEO_STAT_INCISE_LIB_H

#include <math.h>
#include "GsStru.h"

#ifndef _GEO_STAT_INCISE_LIB
#define  _GEO_STAT_INCISE_DLL _declspec(dllimport)
#else
#define _GEO_STAT_INCISE_DLL _declspec(dllexport)
#endif


// typedef struct
// {
// 	double x;
// 	double y;
// } D_DOT;

typedef struct // 三角网中顶点结构.
	{
	double 	fDemX,fDemY,fDemZ; 	// 点的X、Y、Z值.
	short  	wCode;              // 地性特征码.
	char   	cExist;    			// 删除标志.
	char    null;				// 系统保留.
	} GsTinPntStruT;
//三角形
typedef struct GsInsTri
{
	GsTinPntStruT d3dDot1; 
	GsTinPntStruT d3dDot2;
	GsTinPntStruT d3dDot3;

	long		lNo;

	//在该三角形内的交点
	GSD_3DOT		InterDot[2];
	bool		beUse[2];
	bool		bEFlgOfInter;
	GsInsTri()
	{		
		bEFlgOfInter = FALSE;	//三角形是否存在交点
		beUse[0] = FALSE;		//交点是否被添加到线中过
		beUse[1] = FALSE;
		InterDot[0].x = -MAX_FLOAT;
		InterDot[0].y = -MAX_FLOAT;
		InterDot[0].z = -MAX_FLOAT;
		InterDot[1].x = -MAX_FLOAT;
		InterDot[1].y = -MAX_FLOAT;
		InterDot[1].z = -MAX_FLOAT;
	}
}GsInsTri;

//切割交线
typedef struct GsInsInciseLIne
{
	GSD_3DOT	*pd3dLineDot;
	long	lNum;

	GsInsInciseLIne()
	{
		pd3dLineDot = NULL;
		lNum = 0;
	}
	~GsInsInciseLIne()
	{
		SAFE_DELETE_ARRAY(pd3dLineDot);
		lNum = 0;
	}
}GsInsInciseLIne;
class _GEO_STAT_INCISE_DLL CGsInciseLib
{
public:
	CGsInciseLib();
	~CGsInciseLib();

	//该BLOCK中的构TIN的三角形
	GsInsTri		    *m_pTriangle;	
	long			     m_lTriaNum;

	//共有多少个有效三角形被切中
	long			     m_lValTriNum;
	
	//该BLOCK中与切割平面的切割交线（切割成果）
	GsInsInciseLIne		*m_pInciseLIne;		
	long		         m_InciseLIneNum;

	//切割平面
	double			*m_dTri1;
	double			*m_dTri2;
	double			*m_dTri3;	

private:		
	short	IsNoNeibor(GsInsTri TriaObj, int iTriaNO, short *spInterNO);
	long	GenLine(GsInsTri &TriaObj, int iTriaNO, short sInterNO);
	void	ContinueGenLine(GSD_3DOT InterDot, int iTriaNO);
	void	Add2InciseLInePnt(GsInsTri &TriaObj, short sInterNO);
	bool	CheckInterDot(GsInsTri TriaObj, GSD_3DOT d3dDot);
	bool	AddInterDot(GsInsTri *pTriaObj, double dDot[3], int iCnt);
	short	GenCirLines();

public:
	//设置切割平面
	void	SetTri(double *Tri1, double *Tri2, double *Tri3);
	//计算平面与体的交点
	short	CalInterdotWithTri();
	//检查交点的合理性
	short	CheckInterOfTrais();	
	//产生每个CZdtBlock中的切割线(递归方式)
	short	GenInciseLInes();	
	//请空成果切割线
	void	ClearRs();


	//工具函数
	void*	ReAllocBuf_D3(void* pBuf, long lOrgSize, long lAddSize);
};

#ifndef _GEO_STAT_INCISE_LIB
	#ifdef _DEBUG
		#pragma comment(lib, "GsInciseLibD.lib")
	#else
		#pragma comment(lib, "GsInciseLib.lib")
	#endif
#endif

#endif // _GEO_STAT_INCISE_LIB_H