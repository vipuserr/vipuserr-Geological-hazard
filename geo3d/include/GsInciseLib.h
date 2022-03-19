
// -----------------------------------------------------------------
//
// Copyright:	ZondySoft 2008
//
// File:		GsInciseLib.h
//
// Project:		GeoStatIncise
//
// Creator:		����Ӣ
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

typedef struct // �������ж���ṹ.
	{
	double 	fDemX,fDemY,fDemZ; 	// ���X��Y��Zֵ.
	short  	wCode;              // ����������.
	char   	cExist;    			// ɾ����־.
	char    null;				// ϵͳ����.
	} GsTinPntStruT;
//������
typedef struct GsInsTri
{
	GsTinPntStruT d3dDot1; 
	GsTinPntStruT d3dDot2;
	GsTinPntStruT d3dDot3;

	long		lNo;

	//�ڸ��������ڵĽ���
	GSD_3DOT		InterDot[2];
	bool		beUse[2];
	bool		bEFlgOfInter;
	GsInsTri()
	{		
		bEFlgOfInter = FALSE;	//�������Ƿ���ڽ���
		beUse[0] = FALSE;		//�����Ƿ���ӵ����й�
		beUse[1] = FALSE;
		InterDot[0].x = -MAX_FLOAT;
		InterDot[0].y = -MAX_FLOAT;
		InterDot[0].z = -MAX_FLOAT;
		InterDot[1].x = -MAX_FLOAT;
		InterDot[1].y = -MAX_FLOAT;
		InterDot[1].z = -MAX_FLOAT;
	}
}GsInsTri;

//�и��
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

	//��BLOCK�еĹ�TIN��������
	GsInsTri		    *m_pTriangle;	
	long			     m_lTriaNum;

	//���ж��ٸ���Ч�����α�����
	long			     m_lValTriNum;
	
	//��BLOCK�����и�ƽ����и�ߣ��и�ɹ���
	GsInsInciseLIne		*m_pInciseLIne;		
	long		         m_InciseLIneNum;

	//�и�ƽ��
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
	//�����и�ƽ��
	void	SetTri(double *Tri1, double *Tri2, double *Tri3);
	//����ƽ������Ľ���
	short	CalInterdotWithTri();
	//��齻��ĺ�����
	short	CheckInterOfTrais();	
	//����ÿ��CZdtBlock�е��и���(�ݹ鷽ʽ)
	short	GenInciseLInes();	
	//��ճɹ��и���
	void	ClearRs();


	//���ߺ���
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