#pragma once

#pragma pack(push, 1)

#include "s3d_KerGISAdapterDef.h"
#include "s3d_vecAttDataMng.h"


namespace Smart3dMap
{

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
		long		_AppendPnt(_D_DOT *xy, char *dat, short len, PNT_INFO *inf);
		short		_UpdatePnt(long pi, _D_DOT *xy, char *dat, short len, PNT_INFO *inf);
		short		_UpdatePntPos(long pi, _D_DOT *xy);

		short		_GetPnt(long pi, _D_DOT *xy, char **dat, short *len, PNT_INFO *inf);
		short		_GetPntPos(long pi, _D_DOT *xy);

		short		_GetPntInfo(long pi, PNT_INFO *inf);
		short		_UpdatePntInfo(long pi, PNT_INFO *inf);

		short		_DelPnt(long li);
		short		_UnDelPnt(long li);

		char		_GetChangeFlag(void); //ȡ���ݸı��־
		short		_GetPntNum(long *logN, long *phyN);

		/*����ֵ:1/0/-1=����/������/��ɾ��*/
		short		_GetPntExistFlag(long pnti);   //ȡ����ڱ�־		
		short		_GetPntLayer(long pi, short *lay);
		short		_GetPntRect(long pi, _D_RECT *rc);
		short		_GetPntRectLayer(long pi, _D_RECT *rc, short *layer);

		//����ָ����Ԫ�ı߽緶Χ
		short		_CalPntRect(long pi, _D_RECT *dfRc);

		short		_GetAreaRect(_D_RECT *rc);//��ȡ�����������ܷ�Χ
		short       _Transform(TRAN_PAR *tp);//�仯�����е�����
	public:
		short		_GetPntAttStru(CATT_STRU **stru);
		short		_SetPntAttStru(CATT_STRU *stru);

		short		_GetPntAtt(long pi, CATT_STRU **stru, char **att);
		short		_UpdatePntAtt(long pi, CATT_STRU *stru, char *att);

	private:
		BOOL        m_IsAreaValid;    // ������Ч��־.
		BOOL        m_IsDirty;        // �����Ӧ�����Ƿ����޸�.

		_D_RECT      m_AreaRc;         // �����ܵķ�Χ.
	private:
		CAttTBL_Manger *m_PntAttTbl;  // ��ʵ�����Ա�

	private:                          // �������ڴ�ָ��:
		_D_DOT      *m_ptPntSet;	  // ���е����ݱ�ָ��.
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
		long		_AppendPnt(_D_3DOT *xyz, char *dat, short len, PNT_INFO *inf);
		short		_UpdatePnt(long pi, _D_3DOT *xyz, char *dat, short slen, PNT_INFO *inf);
		short		_UpdatePntPos(long pi, _D_3DOT *xyz);

		short		_GetPnt(long pi, _D_3DOT *xyz, char **dat, short *len, PNT_INFO *inf);
		short		_GetPntPos(long pi, _D_3DOT *xyz);

		short		_DelPnt(long pi);
		short		_UnDelPnt(long pi);

	private:
		BOOL        m_IsAreaValid;    // ������Ч��־.
		BOOL        m_IsDirty;        // �����Ӧ�����Ƿ����޸�.

		_D_RECT      m_AreaRc;         // �����ܵķ�Χ.
	private:
		CAttTBL_Manger *m_PntAttTbl;  // ��ʵ�����Ա�

	private:                          // �������ڴ�ָ��:
		_D_3DOT     *m_ptPntSet;	  // ���е����ݱ�ָ��.
		long        m_lPntSetBuf;     // �����������BUF��С.
		long        m_lPntPhyNum;     // ���������е������������
		long        m_lPntLogNum;     // ���������е������߼�����

		char      **m_ptPntStrDat;    // ������Str��ָ��.
		short      *m_ptPntStrLen;    // ������Str����ָ��.
		PNTINF_EXIST   *m_ptPntInfo;  // ������Info������Ч�Լ�¼��ָ��.
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
		long		_AppendLin(_D_DOT *dat, long len, LIN_INFO *inf);
		short		_UpdateLin(long li, _D_DOT *dat, long len, LIN_INFO *inf);

		short		_GetLin(long li, _D_DOT **dat, long *len, LIN_INFO *inf);
		short		_GetLinInfo(long li, LIN_INFO *inf);
		short		_UpdateLinInfo(long li, LIN_INFO *inf);

		short		_DelLin(long li);
		short		_UnDelLin(long li);

		char		_GetChangeFlag(void); //ȡ���ݸı��־
		short		_GetLinNum(long *logN, long *phyN);

		/*����ֵ:1/0/-1=����/������/��ɾ��*/
		short       _GetLinExistFlag(long lini);   //ȡ�ߴ��ڱ�־
		short		_GetLinLayer(long li, short *lay);
		short		_GetLinRect(long li, _D_RECT *rc);
		short		_GetLinRectLayer(long li, _D_RECT *rc, short *layer);

		short		_CalLinRect(long li, _D_RECT *dfRc);

		short		_GetAreaRect(_D_RECT *rc);//��ȡ�����������ܷ�Χ
		short       _Transform(TRAN_PAR *tp);//�仯�����е�����
		short		_DensityLinByStep(double dfStep);//��Ԫ�������������ܴ�����

	public:			// ��/д��Ԫ����
		short		_GetLinAttStru(CATT_STRU **stru);
		short		_SetLinAttStru(CATT_STRU *stru);

		short		_GetLinAtt(long pi, CATT_STRU **stru, char **att);
		short		_UpdateLinAtt(long pi, CATT_STRU *stru, char *att);

	private:
		BOOL        m_IsAreaValid;    // ������Ч��־.
		BOOL        m_IsDirty;        // �����Ӧ�����Ƿ����޸�.

		_D_RECT      m_AreaRc;         // �����ܵķ�Χ.
	private:
		CAttTBL_Manger *m_LinAttTbl;  // ��ʵ�����Ա�

	private:                          // �������ڴ�ָ��:
		long        m_lLinSetBuf;     // ������������BUF��С.
		long        m_lLinPhyNum;     // �����������������������
		long        m_lLinLogNum;     // �����������������߼�����

		_D_DOT     **m_ptLinDat;       // ������Dat��ָ��.
		long       *m_ptLinDatLen;    // ������Dat����ָ��.
		LININF_EXIST   *m_ptLinInfo;  // ������Info������Ч�Լ�¼��ָ��.
	};


	class mC3dLinDatManger                 //Gis��ά�������ڴ�������.
	{
	public:
		mC3dLinDatManger(); //���캯��
		~mC3dLinDatManger(); //��������

	public:			//��ά�����ݲ�������
		long		_AppendLin(_D_3DOT *dat, long len, LIN_INFO *inf);
		short		_UpdateLin(long li, _D_3DOT *dat, long len, LIN_INFO *inf);

		short		_GetLin(long li, _D_3DOT **dat, long *len, LIN_INFO *inf);

		short		_DelLin(long li);
		short		_UnDelLin(long li);

	private:
		BOOL        m_IsAreaValid;    // ������Ч��־.
		BOOL        m_IsDirty;        // �����Ӧ�����Ƿ����޸�.

		_D_RECT      m_AreaRc;         // �����ܵķ�Χ.
	private:
		CAttTBL_Manger *m_LinAttTbl;  // ��ʵ�����Ա�

	private:                          // �������ڴ�ָ��:
		long        m_lLinSetBuf;     // ������������BUF��С.
		long        m_lLinPhyNum;     // �����������������������
		long        m_lLinLogNum;     // �����������������߼�����

		_D_3DOT    **m_ptLinDat;       // ������Dat��ָ��.
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
		long		_AppendReg(long *rdat, long len, REG_INFO *inf);
		short		_UpdateReg(long ri, long *rdat, long len, REG_INFO *inf);

		short		_GetReg(long ri, long **rdat, long *len, REG_INFO *inf);
		short		_GetRegInfo(long ri, REG_INFO *inf);
		short		_UpdateRegInfo(long ri, REG_INFO *inf);

		short		_DelReg(long li);
		short		_UnDelReg(long li);
		//ɾ��΢С��������
		short		_DelMicroReg(double tinyArea);


		char		_GetChangeFlag(void); //ȡ���ݸı��־
		short		_GetRegNum(long *logN, long *phyN);

		/*����ֵ:1/0/-1=����/������/��ɾ��*/
		short		_GetRegExistFlag(long regi);   //ȡ�����ڱ�־
		short		_GetRegLayer(long ri, short *lay);
		short		_GetRegRect(long ri, _D_RECT *rc);
		short		_GetRegRectLayer(long ri, _D_RECT *rc, short *layer);

		// ------------------ ȡ��Ԫ����߽������ ------------------ // 
		// xy --- ���Ȳ�С��rdata[0]���ѷ���_D_DOT�ڴ�ռ�
		// ne --- ���Ȳ�С�ڸ���Ԫ����Ȧ�����ѷ���long�ڴ�ռ�
		short 		_GetRegEdge(long *rdata, long len, _D_DOT *xy, long *ne);

		// ---------------------- ����㵽��Ԫ��֮��ľ��� ---------------------- //
		/*��ڣ�pnt  -  �������ַ
				ri	 -  ����
				minDis- �㵽�������С���������ַ��������Ҫ����=NULL
				maxDis- �㵽����������������ַ��������Ҫ����=NULL
		  ���ڣ�minDis- ���ص㵽�������С����
				maxDis- ���ص㵽�����������
		  ���أ�1/0=�ɹ�/ʧ��*/
		short       _GetDistofPntToReg(_D_DOT *pnt, long ri, double *minDis, double *maxDis);



		// --------------------- �����Ƿ�����Ԫ�����ں��� --------------------- //
		// flg==1���ϸ��׺ϣ�����ֻ����һȦ.
		// ����ֵ��2/1/0=��/�߽�/��.
		short		_IsDotInReg1(_D_DOT *dot, long ri, short flg);

		// ����ָ����Ԫ����������ܳ�
		// ����0���ʾ��������1��ʾ��Ԫ��Ȧ˳ʱ���򡢷���-1��ʾ��Ԫ��Ȧ��ʱ����.
		short       _CalculateArea(long ri, double *area, double *par);
		short		_CalRegRect(long ri, _D_RECT *dfRc); // ����ָ����Ԫ���ı߽緶Χ

		short		_GetAreaRect(_D_RECT *rc);//��ȡ�����������ܷ�Χ
		short       _Transform(TRAN_PAR *tp);//�仯�����е�����
		short       _UpdateRegDat(char updateType);//��⻬�Ȼ������ݵ���Ҫ������Ԫ�������.

	public:			// ��/д��Ԫ����
		short		_GetRegAttStru(CATT_STRU **stru);
		short		_SetRegAttStru(CATT_STRU *stru);

		short		_GetRegAtt(long pi, CATT_STRU **stru, char **att);
		short		_UpdateRegAtt(long pi, CATT_STRU *stru, char *att);

	public:			//�������еĻ������ݲ�������
		long		_AppendLin(_D_DOT *dat, long len, LIN_INFO *inf);
		short		_UpdateLin(long li, _D_DOT *dat, long len, LIN_INFO *inf);

		short		_GetLin(long li, _D_DOT **dat, long *len, LIN_INFO *inf);
		short		_GetLinInfo(long li, LIN_INFO *inf);
		short		_UpdateLinInfo(long li, LIN_INFO *inf);

		short		_DelLin(long li);
		short		_UnDelLin(long li);

		short		_GetLinNum(long *logN, long *phyN);

		/*����ֵ:1/0/-1=����/������/��ɾ��*/
		short		_GetLinExistFlag(long li);   //ȡ�����ڱ�־
		short		_GetLinLayer(long li, short *lay);
		short		_GetLinRect(long li, _D_RECT *rc);
		short		_GetLinRectLayer(long li, _D_RECT *rc, short *layer);


		// ------------------- �����Ƿ��������ں��� ------------------- //
		// flg==1���ϸ��׺ϣ�����ֻ����һȦ.
		// ����ֵ��2/1/0=��/�߽�/��.
		short		cmIsDotInReg1(_D_DOT *dot, long ri, short flg);

	public:			// ��/д��Ԫ��������ʵ������
		short		_GetLinAttStru(CATT_STRU **stru);
		short		_SetLinAttStru(CATT_STRU *stru);

		short		_GetLinAtt(long pi, CATT_STRU **stru, char **att);
		short		_UpdateLinAtt(long pi, CATT_STRU *stru, char *att);

	private:
		mC2dLinDatManger regArcDat;   // �������еĻ������ݶ���.

	private:
		BOOL        m_IsAreaValid;    // ������Ч��־.
		BOOL        m_IsDirty;        // �����Ӧ�����Ƿ����޸�.

		_D_RECT      m_AreaRc;         // �����ܵķ�Χ.
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

}

#pragma pack(pop)

