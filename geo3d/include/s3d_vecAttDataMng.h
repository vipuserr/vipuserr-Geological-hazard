#ifndef _ZTYQ_PUB_ATTCLASSES_H_
#define _ZTYQ_PUB_ATTCLASSES_H_

#pragma pack(push, 1)


#include "s3d_KerGISAdapterDef.h"
#include "s3d_GisStru.h"

namespace Smart3dMap
{

	///{
	//���ֶ������ֶ�ռ�õĶ������ֽ���(STR_TYPE����ռ�õ��ֽ�������msk_leng��
	//���ֶ��ַ�����)
	#define BYTE_LEN		sizeof(char)
	#define SHORT_LEN		sizeof(short)
	#define LONG_LEN		sizeof(long)
	#define FLOAT_LEN		sizeof(float)
	#define DOUBLE_LEN		sizeof(double)
	#define DATE_LEN		sizeof(DATE_STRU)
	#define TIME_LEN		sizeof(TIME_STRU)
	#define BOOL_LEN		sizeof(BOOL_STRU)
	#define TEXT_LEN		sizeof(EXT_STRU)
	#define PICTURE_LEN     sizeof(EXT_STRU)
	#define MAP_LEN			sizeof(EXT_STRU)
	#define SOUND_LEN       sizeof(EXT_STRU)
	#define VIDEO_LEN       sizeof(EXT_STRU)
	#define EXT_LEN			sizeof(EXT_STRU)
	#define BIN_DATA_LEN    sizeof(BIN_DATA_STRU)
	#define TIMESTAMP_LEN	sizeof(TIMESTAMP_STRU)

	/*STR_TYPE���ͼ��ַ���������󳤶�	*/
	#define MAX_STR_LEN		512


	//��ʷ�¼���������(2002.8.20+)
	class CHisObj
	{
	public:
		CHisObj()
		{
			m_hisType = 0;
			m_des[0] = 0;
			m_actID0 = 0;
			memset(&m_hisTime, 0, sizeof(TIMESTAMP_STRU));
			m_hisOper[0] = 0;
		}
	public:
		short        	m_hisType;
		char       		m_des[128];
		long        	m_actID0;
		TIMESTAMP_STRU 	m_hisTime;
		char       	m_hisOper[64];
	};

	//��ʷ������Ϣ(2002.8.20+)
	class CActObj
	{
	public:
		CActObj()
		{
			m_actID0 = 0;
			m_objID = 0;
			m_objType = 0;
			m_actType = 0;
			memset(&m_actTime, 0, sizeof(TIMESTAMP_STRU));
			m_actOper[0] = 0;
		}
		long  		m_actID0;
		long    	m_objID;
		short   	m_objType;
		short   	m_actType;
		TIMESTAMP_STRU 	m_actTime;
		char     	m_actOper[64];
	};

	typedef struct
	{
		char ttl[32];
		char val[32];
	}ExtCombFLD;

		//�ֶ���̬����
	#define	  FLD_SHP_EDIT	  0   /*�༭��*/
	#define	  FLD_SHP_COMBO	  1   /*��Ͽ�*/
	#define	  FLD_SHP_CHECK	  2   /*��ѡ��*/
	#define	  FLD_SHP_BUTTON  3   /*��ť��*/



	class S3DKERGIS_ADAPTER_EXP CExtFIELD_HEAD
	{
	public:
		CExtFIELD_HEAD(char fieldType, short shapeInfoNum);
		virtual ~CExtFIELD_HEAD();
	public:
		short	HasDefVal();
		short	HasMaxVal();
		short	HasMinVal();
		short	SetDefVal(double val);
		short	SetMaxVal(double val);
		short	SetMinVal(double val);
		short	SetDefVal(char *val, short sValLen);
		short	SetMaxVal(char *val, short sValLen);
		short	SetMinVal(char *val, short sValLen);
		short	GetDefVal(char *valBuf, long valBufLen = 0);
		short	GetMaxVal(char *valBuf, long valBufLen = 0);
		short	GetMinVal(char *valBuf, long valBufLen = 0);
		short	SetShapeInfo(short seqNo, char *ttlStr, char *val);
		short	GetShapeInfo(short seqNo, char *ttlStr, long ttlLen, char *valBuf, long valBufLen = 0);
		short	GetShapeInfoNum();
		char	GetFieldType();

		short   CopyExtFldHd(CExtFIELD_HEAD *ptExtFldHd);
		short	IsSameExtFldVar(CExtFIELD_HEAD *ptExtFld); //��ȫ��ͬ����1�����򷵻�0. 

	public:
		char		m_alias[40];  //�ֶα���
		char		m_IsNull;	  //�Ƿ�����Ϊ��,1/0=�����/�����
		short		m_shape;	  //�ֶ���̬---�༭��/��Ͽ�/��ѡ��/��Ť
	private:
		short        m_shapeInfoLen;	//shape��Ϣ��, ÿ����Ϣ��������ttl��ȡֵval
		ExtCombFLD  *m_shapeInfoBuf;	//�ֶ���̬��Ϣ--��Ч/ExtCombFLD��/����/����
		char		 m_fieldType;	//����չ�ṹ��Ӧ���ֶ�����
		char		*m_defVal;	//�ֶ�ȱʡֵ, ��ֵ��,����,ʱ��,�ʴ����Ϳ���ȱʡֵ�������Сֵ.
		char		*m_maxVal;	//���ֵ
		char		*m_minVal;	//��Сֵ
	};


	class S3DKERGIS_ADAPTER_EXP CFIELD_HEAD
	{
	public:
		CFIELD_HEAD(CFIELD_HEAD *ptFld = NULL);
		virtual ~CFIELD_HEAD();

	public:
		char   fieldname[FLD_NAME_LEN];	//�ֶ�����
		char   fieldtype;		//	�ֶ�����
		long   fieldoffset;		//	�ֶ�ƫ��
		short  fieldlength;		//	�ֶ��ֽڳ���
		short  msk_leng;			//	�ֶ��ַ�����
		char   point_leng;		//	С��λ��
		short  edit_enable;		//	�༭ʹ�ܱ�־(0/1/2=����/��/��ֹ)
		char   pt_flg;          	//	��ӡ��־
		short  ptc_pos;			//	�ֶ����,����Ϊ0,1,2...
								 //	�������Խṹ�����ֶ����Ϊԭ�ֶ����(>=0)
								 //	���ֶ���ű���Ϊ-1,�������Խṹ֮��
								 //	�����ֶ���ű���������Ϊ0,1,2...

	private:
		CExtFIELD_HEAD *m_ptExtFld;// ����չ��Ϣ�ҽ���һ��
	public:
		short  IsSameAttFieldVar(CFIELD_HEAD *ptFld0); //��ȫ��ͬ����1�����򷵻�0. 
		short	 Set(CFIELD_HEAD *ptFld);
		short  CopyFldHead(CFIELD_HEAD *ptFld);

		CExtFIELD_HEAD * GetExtFIELD_HEAD();
		short	SetExtFIELD_HEAD(CExtFIELD_HEAD *ptCExtFld);
		short DelExtFIELD_HEAD();
		short HasExtFIELD_HEAD();

		long  CalSize();
		short Load(HFILE hdf, long off);	      //װ��CFIELD_HEAD������(���ļ����hdf��offƫ�ƴ�)
		long  Save(HFILE hdf, long off);	      //����CFIELD_HEAD������(���ļ����hdf��offƫ�ƴ�)
	};

	class S3DKERGIS_ADAPTER_EXP CINFO_HEAD
	{
	public:
		short  	numbfield;    //�ֶ���
		long 	numbrecord;   //��¼��
		long  	recordleng;   //��¼����
		CINFO_HEAD() {
			memset(this, 0, sizeof(CINFO_HEAD));
		};
		virtual ~CINFO_HEAD() {
			memset(this, 0, sizeof(CINFO_HEAD));
		};
	};

	//CFIELD_HEAD�ṹ��edit_enable����: (0-->0x00FFΪMapGisϵͳ����)
#define    FLDEDT_NO      0x0000	//�ֶοɱ༭״̬,����
#define    FLDEDT_YES     0x0001	//�ֶοɱ༭״̬,��
#define    FLDEDT_FORBID  0x0002	//�ֶοɱ༭״̬,��ֹ
#define    FLDVIS			0x0004 	//�ֶοɼ�״̬(�༭�����ʱ����ʱ״̬)
#define    FLDMSK			0x0008	//�ֶ�����״̬
#define    FLD_EXT	    0x0010	//���ֶ�����չ����(TEXT_TYPE--EXT_TYPE)
#define    FLD_REPEL      0x0020	//���ֶ�ֵ����
#define    FLD_DBSKEY     0x0040	//���ֶ���������ݿ�ؼ��ֶ�
#define    FLDEDT     (FLDEDT_NO|FLDEDT_YES|FLDEDT_FORBID)  //�ֶα༭״̬

//CATT_STRU �ر�˵��:
//1. CATT_STRU��ATT_STRU�ṹ�������
//2. hd,fldEntry��Ա����δ���ǰ׺m_,����Ƴɹ�����Ա����,��Ϊ�˼��ٳ�����ֲ�Ĺ�����.
//3. ����:������ֱ�Ӹ���ָ���fldEntry��Ա,��: CFIELD_HEAD  *ptFld; 	CATT_STRU   *ptStru;	...... 	ptStru->fldEntry=ptFld;	......
	class S3DKERGIS_ADAPTER_EXP CATT_STRU
	{
	public:
		CATT_STRU();
		CATT_STRU(CATT_STRU *ptStru0);
		virtual ~CATT_STRU();
	public:
		CINFO_HEAD    hd;
		CFIELD_HEAD  *fldEntry;	//�ֶ�˵�����	   

	public:
		short	AppendFld(short fldN, CFIELD_HEAD *fldEntry);            //����ֶ�
		short	InsertFld(short fldN, CFIELD_HEAD *fldEntry, short insTo);//insTo����λ��,��0��ʼ
		short	DelFld(char *fldName);  //ɾ���ֶ�
		short	DelFld(short fldi);
		short	CalLengthOffset();    //������ֶεĶ����Ƴ���,�ֶ�ƫ��,���Ϸ��Ե�.

		short	GetFieldNo(char *fieldname);//�������ֶ�����ȡ���ֶ����

		short   IsSameAttStruVar(CATT_STRU *ptStru0); //��ȫ��ͬ����1�����򷵻�0.
		short	CopyAttStru(CATT_STRU *ptAttStru);


		virtual long  CalSize();    //����CATT_STRU��ռ�ô洢�ռ��С, �ú������ȵ���CalLengthOffset()
		virtual short Load(HFILE hdf, long off);	      //װ��CATT_STRU������(���ļ����hdf��offƫ�ƴ�)	
		virtual long  Save(HFILE hdf, long off);	      //����CATT_STRU������(���ļ����hdf��offƫ�ƴ�)
	};

	class S3DKERGIS_ADAPTER_EXP ASK_DB_RCD	//�������ݿ��¼
	{
	public:
		ASK_DB_RCD(int len) {
			memset(this, 0, sizeof(ASK_DB_RCD));
		};
		~ASK_DB_RCD(void) {
			if (valPtr) delete[] valPtr;
			memset(this, 0, sizeof(ASK_DB_RCD));
		};
	public:
		char *valPtr;	    //�ֶ�ֵָ��
		short valType;	    //�ֶ�ֵ����
		int   valLen;	    //valPtr����
		char  dbfldName[32];//���ݿ��ֶ���
	};

	// ----------------- �������Ա��ڴ������� ----------------- //
	typedef struct
	{
		void	 *ptNext;   //ָ����һ�洢��ָ��
		long	 lStartEno; //�ÿ�洢��ʵ����ʼ��
		long	 lEndEno;   //�ÿ�洢��ʵ����ֹ��+1
		char	*attBuf;   //�ÿ�洢��ʵ������BUF
	} AttMEMBLOCK_STRU;

	class S3DKERGIS_ADAPTER_EXP CAttTBL_Manger
	{
	public:
		CAttTBL_Manger(CATT_STRU *stru);
		~CAttTBL_Manger();

	public:		// ��ȡ�����Ա��ȱʡ���Խṹ
		short	_GetAttStru(CATT_STRU **stru, char **att = NULL);
		short	_SetAttStru(CATT_STRU *stru);

		short	_GetAtt(long ti, CATT_STRU **stru, char **att);
		short	_UpdateAtt(long ti, CATT_STRU *stru, char *att);

		// �����Ա������β�����һ����¼
		long	_AppendAtt(CATT_STRU *stru, char *att);

	private:
		AttMEMBLOCK_STRU*	GetPtAttBlockForRead(long ti);
		AttMEMBLOCK_STRU*	GetPtAttBlockForAppend(long ti);
	private:
		CATT_STRU			*m_PtAttStru; //�����Ա�ṹ
		char                *m_PtAttBuf;  //���Լ�¼BUF

		AttMEMBLOCK_STRU	*m_PtAttBlock;//�����Ա����ڴ��ָ��
	};




	// ----------------- ��ȡ��ͬ�����ֶε��ֶγ��� --------------------- //
	short  S3DKERGIS_ADAPTER_EXP _AttGetFieldTypeLen(char fieldType);
	short  S3DKERGIS_ADAPTER_EXP _AttGetFieldBufLenByFldEntry(CFIELD_HEAD *fldEntry);

		// ��ȡȱʡ�ֶνṹ
	#define    PNT_DEFAULT_ATTFILED     1	//��Ԫȱʡ�����ֶΣ�ID
	#define    LIN_DEFAULT_ATTFILED     2	//��Ԫȱʡ�����ֶΣ�ID��Length
	#define    REG_DEFAULT_ATTFILED		3	//��Ԫȱʡ�����ֶΣ�ID��Length��Area
	#define    DEM_DEFAULT_ATTFILED		4 	//�߳���Ԫȱʡ�����ֶΣ�ID, Length��ContourVal

	S3DKERGIS_ADAPTER_EXP CFIELD_HEAD *	_AttGetDefaultField(char cType);

	// ------------------------------- ��ȡ/����������ֵ ------------------------------- //
	//�����ֶ�����ȡ�ֶ����,�ɹ������ֶ����(>=0),ʧ�ܷ���-1
	short  S3DKERGIS_ADAPTER_EXP _AttGetFldNo(CATT_STRU *stru, char *fldName);

	short  S3DKERGIS_ADAPTER_EXP _AttSetFldByNo(char *att, CATT_STRU *stru, short fldi, char *realVal);
	short  S3DKERGIS_ADAPTER_EXP _AttSetFldByName(char *att, CATT_STRU *stru, char *fldName, char *realVal);

	short  S3DKERGIS_ADAPTER_EXP _AttSetFldByNoFromStr(char *att, CATT_STRU *stru, short fldi, char *strVal, short valLen = 0);
	short  S3DKERGIS_ADAPTER_EXP _AttSetFldByNameFromStr(char *att, CATT_STRU *stru, char *fldName, char *strVal, short valLen = 0);

	//�����ֶ����ȡ��ֵ���ֶ�ֵ
	short  S3DKERGIS_ADAPTER_EXP _AttGetFieldByNo(char *att, CATT_STRU *stru, short fldi, char *fldBuf, short bufLen, short *isBlank = NULL);

	//�����ֶ�����ȡ��ֵ���ֶ�ֵ
	short  S3DKERGIS_ADAPTER_EXP _AttGetFieldByName(char *att, CATT_STRU *stru, char *fldName, char *fldBuf, short bufLen, short *isBlank = NULL);






}

#pragma pack(pop)


#endif
