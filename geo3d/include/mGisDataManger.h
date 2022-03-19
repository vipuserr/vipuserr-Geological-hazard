#ifndef __ZTYQ_memGisData_Manger_H_
#define __ZTYQ_memGisData_Manger_H_

#include <Windows.h>
#include <Sqltypes.h>
#include "basDefine.h"
#include "ztyqAttClasses.h"



#ifndef __ZTYQ_memGisData_Manger_H_
#define MGISDatManger_EXPORT_CLASS  __declspec(dllimport) 
#else
#define MGISDatManger_EXPORT_CLASS  __declspec(dllexport)
#endif



typedef struct PNTINFO_EXIST_STRUCT
	{
	PNT_INFO	pInfo;
	char		cExist;     //��Ԫ��Ч��־��1��Ч/-1��Ч
	} PNTINF_EXIST;

class mC2dPntDatManger      //Gis��ά�������ڴ�������.
	{
	public:	
		mC2dPntDatManger(); //���캯��
	   ~mC2dPntDatManger(); //��������

	public:			//��ά�����ݲ�������
		long		_AppendPnt(D_DOT *xy,char *dat,short len,PNT_INFO *inf);
		short		_UpdatePnt(long pi,D_DOT *xy,char *dat,short len,PNT_INFO *inf);
		short		_UpdatePntPos(long pi,D_DOT *xy);

		short		_GetPnt(long pi,D_DOT *xy,char **dat,short *len,PNT_INFO *inf);
		short		_GetPntPos(long pi,D_DOT *xy);

		short		_DelPnt(long li);
		short		_UnDelPnt(long li);

		char		_GetChangeFlag(void); //ȡ���ݸı��־
		short		_GetPntNum(long *logN, long *phyN);

					/*����ֵ:1/0/-1=����/������/��ɾ��*/
		short		_GetPntExistFlag(long pnti);   //ȡ����ڱ�־		
		short		_GetPntLayer(long pi, short *lay);
		short		_GetPntRect(long pi, D_RECT *rc);
		short		_GetPntRectLayer(long pi, D_RECT *rc, short *layer);	

		short		_GetAreaRect(D_RECT *rc);//��ȡ�����������ܷ�Χ

	public:		
		short		_GetPntAtt(long pi, CATT_STRU **stru, char **att);
		short		_UpdatePntAtt(long pi, CATT_STRU *stru, char *att);

	private:
		BOOL        m_IsAreaValid;    // ������Ч��־.
		BOOL        m_IsDirty;        // �����Ӧ�����Ƿ����޸�.

		D_RECT      m_AreaRc;         // �����ܵķ�Χ.
	private:
		CAttTBL_Manger *m_PntAttTbl;  // ��ʵ�����Ա�

	private:                          // �������ڴ�ָ��:
		D_DOT      *m_ptPntSet;	      // ���е����ݱ�ָ��.
		long        m_lPntSetBuf;     // �����������BUF��С.
		long        m_lPntPhyNum;     // ���������е������������
		long        m_lPntLogNum;     // ���������е������߼�����

		char      **m_ptPntStr;       // ������Str��ָ��.
        short      *m_ptPntStrLen;    // ������Str����ָ��.		
		PNTINF_EXIST   *m_ptPntInfo;  // ������Info������Ч�Լ�¼��ָ��.
	};


class mC3dPntDatManger                 //Gis��ά�������ڴ�������.
	{
	public:	
		mC3dPntDatManger(); //���캯��
	   ~mC3dPntDatManger(); //��������

	public:			//��ά�����ݲ�������
		long		_AppendPnt(D_3DOT *xyz,char *dat,short len,PNT_INFO *inf);
		short		_UpdatePnt(long pi,D_3DOT *xyz,char *dat,short slen,PNT_INFO *inf);
		short		_UpdatePntPos(long pi,D_3DOT *xyz);

		short		_GetPnt(long pi,D_3DOT *xyz,char **dat,short *len,PNT_INFO *inf);
		short		_GetPntPos(long pi,D_3DOT *xyz);

		short		_DelPnt(long pi);
		short		_UnDelPnt(long pi);
	
	private:
		BOOL        m_IsAreaValid;    // ������Ч��־.
		BOOL        m_IsDirty;        // �����Ӧ�����Ƿ����޸�.

		D_RECT      m_AreaRc;         // �����ܵķ�Χ.
	private:
		CAttTBL_Manger *m_PntAttTbl;  // ��ʵ�����Ա�
	
	private:                          // �������ڴ�ָ��:
		D_3DOT     *m_ptPntSet;	      // ���е����ݱ�ָ��.
		long        m_lPntSetBuf;     // �����������BUF��С.
		long        m_lPntPhyNum;     // ���������е������������
		long        m_lPntLogNum;     // ���������е������߼�����

        char      **m_ptPntStrDat;    // ������Str��ָ��.
        short      *m_ptPntStrLen;    // ������Str����ָ��.
		PNTINF_EXIST   *m_ptPntInfo;      // ������Info������Ч�Լ�¼��ָ��.
	};




typedef struct LININFO_EXIST_STRUCT
{
	LIN_INFO	lInfo;
	char		cExist;    //��Ԫ��Ч��־��1��Ч/-1��Ч
} LININF_EXIST;

class mC2dLinDatManger                 //Gis��ά�����ڴ�������.
	{
	public:	
		mC2dLinDatManger(); //���캯��
	   ~mC2dLinDatManger(); //��������

	public:			//��ά���ݲ�������
		long		_AppendLin(D_DOT *dat,long len,LIN_INFO *inf);
		short		_UpdateLin(long li,D_DOT *dat,long len,LIN_INFO *inf);

		short		_GetLin(long li,D_DOT **dat,long *len,LIN_INFO *inf);

		short		_DelLin(long li);
		short		_UnDelLin(long li);

		char		_GetChangeFlag(void); //ȡ���ݸı��־
		short		_GetLinNum(long *logN, long *phyN);

					/*����ֵ:1/0/-1=����/������/��ɾ��*/
		short       _GetLinExistFlag(long lini);   //ȡ�ߴ��ڱ�־
		short		_GetLinLayer(long li, short *lay);
		short		_GetLinRect(long li, D_RECT *rc);
		short		_GetLinRectLayer(long li, D_RECT *rc, short *layer);
		
		short		_GetAreaRect(D_RECT *rc);//��ȡ�����������ܷ�Χ

	public:			// ��/д��Ԫ����
		short		_GetLinAtt(long pi, CATT_STRU **stru, char **att);
		short		_UpdateLinAtt(long pi, CATT_STRU *stru, char *att);

	private:
		BOOL        m_IsAreaValid;    // ������Ч��־.
		BOOL        m_IsDirty;        // �����Ӧ�����Ƿ����޸�.

		D_RECT      m_AreaRc;         // �����ܵķ�Χ.
	private:
		CAttTBL_Manger *m_LinAttTbl;  // ��ʵ�����Ա�
	
	private:                          // �������ڴ�ָ��:
		long        m_lLinSetBuf;     // ������������BUF��С.
		long        m_lLinPhyNum;     // �����������������������
		long        m_lLinLogNum;     // �����������������߼�����

        D_DOT     **m_ptLinDat;       // ������Dat��ָ��.
        long       *m_ptLinDatLen;    // ������Dat����ָ��.
		LININF_EXIST   *m_ptLinInfo;  // ������Info������Ч�Լ�¼��ָ��.
	};


class mC3dLinDatManger                 //Gis��ά�������ڴ�������.
	{
	public:	
		mC3dLinDatManger(); //���캯��
	   ~mC3dLinDatManger(); //��������

	public:			//��ά�����ݲ�������
		long		_AppendLin(D_3DOT *dat,long len,LIN_INFO *inf);
		short		_UpdateLin(long li,D_3DOT *dat,long len,LIN_INFO *inf);

		short		_GetLin(long li,D_3DOT **dat,long *len,LIN_INFO *inf);

		short		_DelLin(long li);
		short		_UnDelLin(long li);
	
	private:
		BOOL        m_IsAreaValid;    // ������Ч��־.
		BOOL        m_IsDirty;        // �����Ӧ�����Ƿ����޸�.

		D_RECT      m_AreaRc;         // �����ܵķ�Χ.
	private:
		CAttTBL_Manger *m_LinAttTbl;  // ��ʵ�����Ա�
	
	private:                          // �������ڴ�ָ��:
		long        m_lLinSetBuf;     // ������������BUF��С.
		long        m_lLinPhyNum;     // �����������������������
		long        m_lLinLogNum;     // �����������������߼�����

		D_3DOT    **m_ptLinDat;       // ������Dat��ָ��.
        long       *m_ptLinDatLen;    // ������Dat����ָ��.
		LININF_EXIST   *m_ptLinInfo;  // ������Info������Ч�Լ�¼��ָ��.
	};



typedef struct REGINFO_EXIST_STRUCT
{
	REG_INFO	rInfo;
	char		cExist;    //��Ԫ��Ч��־��1��Ч/-1��Ч
} REGINF_EXIST;

class mC2dRegDatManger  //Gis��ά�������ڴ�������.
{
	public:	
		mC2dRegDatManger(); //���캯��
	   ~mC2dRegDatManger(); //��������


	public:			//�����ݲ�������
		long		_AppendReg(long *rdat,long len,REG_INFO *inf);
		short		_UpdateReg(long ri,long *rdat,long len,REG_INFO *inf);
		
		short		_GetReg(long ri,long **rdat,long *len,REG_INFO *inf);
		short		_GetRegInfo(long ri,REG_INFO *inf);
		short		_UpdateRegInfo(long ri,REG_INFO *inf);
		
		short		_DelReg(long li);
		short		_UnDelReg(long li);

		char		_GetChangeFlag(void); //ȡ���ݸı��־
		short		_GetRegNum(long *logN, long *phyN);

					/*����ֵ:1/0/-1=����/������/��ɾ��*/
		short		_GetRegExistFlag(long regi);   //ȡ�����ڱ�־
		short		_GetRegLayer(long ri, short *lay);
		short		_GetRegRect(long ri, D_RECT *rc);
		short		_GetRegRectLayer(long ri, D_RECT *rc, short *layer);

					// ------------------ ȡ��Ԫ����߽������ ------------------ // 
					// xy --- ���Ȳ�С��rdata[0]���ѷ���D_DOT�ڴ�ռ�
					// ne --- ���Ȳ�С�ڸ���Ԫ����Ȧ�����ѷ���long�ڴ�ռ�
		short 		_GetRegEdge(long *rdata, long len, D_DOT *xy, long *ne);

					// ---------------------- ����㵽��Ԫ��֮��ľ��� ---------------------- //
					/*��ڣ�pnt  -  �������ַ
							ri	 -  ����
							minDis- �㵽�������С���������ַ��������Ҫ����=NULL
							maxDis- �㵽����������������ַ��������Ҫ����=NULL
					  ���ڣ�minDis- ���ص㵽�������С����
							maxDis- ���ص㵽�����������
					  ���أ�1/0=�ɹ�/ʧ��*/
		short       _GetDistofPntToReg(D_DOT *pnt, long ri, double *minDis, double *maxDis);

					// --------------------- �����Ƿ�����Ԫ�����ں��� --------------------- //
					// flg==1���ϸ��׺ϣ�����ֻ����һȦ.
					// ����ֵ��2/1/0=��/�߽�/��.
		short		_IsDotInReg1(D_DOT *dot, long ri, short flg);

					// ����ָ����Ԫ����������ܳ�
					// ����0���ʾ��������1��ʾ��Ԫ��Ȧ˳ʱ���򡢷���-1��ʾ��Ԫ��Ȧ��ʱ����.
		short       _CalculateArea(long ri, double *area, double *par);
		short		_CalRegRect(long ri, D_RECT *dfRc); // ����ָ����Ԫ���ı߽緶Χ
				
		short		_GetAreaRect(D_RECT *rc);//��ȡ�����������ܷ�Χ

	public:			// ��/д��Ԫ����
		short		_GetRegAtt(long pi, CATT_STRU **stru, char **att);
		short		_UpdateRegAtt(long pi, CATT_STRU *stru, char *att);

	public:			//�������еĻ������ݲ�������
		long		_AppendLin(D_DOT *dat,long len,LIN_INFO *inf);
		short		_UpdateLin(long li,D_DOT *dat,long len,LIN_INFO *inf);

		short		_GetLin(long li,D_DOT **dat,long *len,LIN_INFO *inf);

		short		_DelLin(long li);
		short		_UnDelLin(long li);	

		short		_GetLinNum(long *logN, long *phyN);

		/*����ֵ:1/0/-1=����/������/��ɾ��*/
		short		_GetLinExistFlag(long li);   //ȡ�����ڱ�־
		short		_GetLinLayer(long li, short *lay);
		short		_GetLinRect(long li, D_RECT *rc);
		short		_GetLinRectLayer(long li, D_RECT *rc, short *layer);


		// ------------------- �����Ƿ��������ں��� ------------------- //
		// flg==1���ϸ��׺ϣ�����ֻ����һȦ.
		// ����ֵ��2/1/0=��/�߽�/��.
		short		cmIsDotInReg1(D_DOT *dot, long ri, short flg);

	public:			// ��/д��Ԫ��������ʵ������
		short		_GetLinAtt(long pi, CATT_STRU **stru, char **att);
		short		_UpdateLinAtt(long pi, CATT_STRU *stru, char *att);

	private:
		mC2dLinDatManger regArcDat;   // �������еĻ������ݶ���.

	private:
		BOOL        m_IsAreaValid;    // ������Ч��־.
		BOOL        m_IsDirty;        // �����Ӧ�����Ƿ����޸�.

		D_RECT      m_AreaRc;         // �����ܵķ�Χ.
	private:
		CAttTBL_Manger *m_RegAttTbl;  // ��ʵ�����Ա�
	
	private:                          // �������ڴ�ָ��:
		long        m_lRegSetBuf;     // �����뻡������BUF��С.
		long        m_lRegPhyNum;     // ���������л��������������
		long        m_lRegLogNum;     // ���������л��������߼�����

		long      **m_ptRegDat;       // ��¼����Ԫ�Ļ��κ����ݱ�ָ��.
        long       *m_ptRegDatLen;    // ����Ԫ�Ļ��κ����ݳ��ȱ�ָ��.
		REGINF_EXIST   *m_ptRegInfo;  // ������Info����Ԫ��Ч�Լ�¼��ָ��.
};


#endif /* #ifndef __ZTYQ_memGisData_Manger_H_ */

