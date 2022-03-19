#ifndef _ZTYQ_PUB_ATTCLASSES_H_
#define _ZTYQ_PUB_ATTCLASSES_H_

#pragma pack(push, 1)


#include "s3d_KerGISAdapterDef.h"
#include "s3d_GisStru.h"

namespace Smart3dMap
{

	///{
	//各字段类型字段占用的二进制字节数(STR_TYPE类型占用的字节数等于msk_leng，
	//即字段字符长度)
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

	/*STR_TYPE类型即字符串类型最大长度	*/
	#define MAX_STR_LEN		512


	//历史事件描述对象(2002.8.20+)
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

	//历史动作信息(2002.8.20+)
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

		//字段形态定义
	#define	  FLD_SHP_EDIT	  0   /*编辑框*/
	#define	  FLD_SHP_COMBO	  1   /*组合框*/
	#define	  FLD_SHP_CHECK	  2   /*复选框*/
	#define	  FLD_SHP_BUTTON  3   /*按钮框*/



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
		short	IsSameExtFldVar(CExtFIELD_HEAD *ptExtFld); //完全相同返回1，否则返回0. 

	public:
		char		m_alias[40];  //字段别名
		char		m_IsNull;	  //是否允许为空,1/0=允许空/不许空
		short		m_shape;	  //字段形态---编辑框/组合框/复选框/按扭
	private:
		short        m_shapeInfoLen;	//shape信息数, 每条信息包括标题ttl和取值val
		ExtCombFLD  *m_shapeInfoBuf;	//字段形态信息--无效/ExtCombFLD表/标题/标题
		char		 m_fieldType;	//该扩展结构对应的字段类型
		char		*m_defVal;	//字段缺省值, 数值型,日期,时间,邮戳类型可有缺省值和最大最小值.
		char		*m_maxVal;	//最大值
		char		*m_minVal;	//最小值
	};


	class S3DKERGIS_ADAPTER_EXP CFIELD_HEAD
	{
	public:
		CFIELD_HEAD(CFIELD_HEAD *ptFld = NULL);
		virtual ~CFIELD_HEAD();

	public:
		char   fieldname[FLD_NAME_LEN];	//字段名称
		char   fieldtype;		//	字段类型
		long   fieldoffset;		//	字段偏移
		short  fieldlength;		//	字段字节长度
		short  msk_leng;			//	字段字符长度
		char   point_leng;		//	小数位数
		short  edit_enable;		//	编辑使能标志(0/1/2=不能/能/禁止)
		char   pt_flg;          	//	打印标志
		short  ptc_pos;			//	字段序号,依次为0,1,2...
								 //	设置属性结构，老字段序号为原字段序号(>=0)
								 //	新字段序号必须为-1,设置属性结构之后，
								 //	所有字段序号被依次设置为0,1,2...

	private:
		CExtFIELD_HEAD *m_ptExtFld;// 有扩展信息且仅有一项
	public:
		short  IsSameAttFieldVar(CFIELD_HEAD *ptFld0); //完全相同返回1，否则返回0. 
		short	 Set(CFIELD_HEAD *ptFld);
		short  CopyFldHead(CFIELD_HEAD *ptFld);

		CExtFIELD_HEAD * GetExtFIELD_HEAD();
		short	SetExtFIELD_HEAD(CExtFIELD_HEAD *ptCExtFld);
		short DelExtFIELD_HEAD();
		short HasExtFIELD_HEAD();

		long  CalSize();
		short Load(HFILE hdf, long off);	      //装入CFIELD_HEAD的内容(从文件句柄hdf的off偏移处)
		long  Save(HFILE hdf, long off);	      //保存CFIELD_HEAD的内容(到文件句柄hdf的off偏移处)
	};

	class S3DKERGIS_ADAPTER_EXP CINFO_HEAD
	{
	public:
		short  	numbfield;    //字段数
		long 	numbrecord;   //记录数
		long  	recordleng;   //记录长度
		CINFO_HEAD() {
			memset(this, 0, sizeof(CINFO_HEAD));
		};
		virtual ~CINFO_HEAD() {
			memset(this, 0, sizeof(CINFO_HEAD));
		};
	};

	//CFIELD_HEAD结构中edit_enable定义: (0-->0x00FF为MapGis系统保留)
#define    FLDEDT_NO      0x0000	//字段可编辑状态,不能
#define    FLDEDT_YES     0x0001	//字段可编辑状态,能
#define    FLDEDT_FORBID  0x0002	//字段可编辑状态,禁止
#define    FLDVIS			0x0004 	//字段可见状态(编辑或浏览时的临时状态)
#define    FLDMSK			0x0008	//字段屏蔽状态
#define    FLD_EXT	    0x0010	//该字段是扩展类型(TEXT_TYPE--EXT_TYPE)
#define    FLD_REPEL      0x0020	//该字段值互异
#define    FLD_DBSKEY     0x0040	//该字段是外挂数据库关键字段
#define    FLDEDT     (FLDEDT_NO|FLDEDT_YES|FLDEDT_FORBID)  //字段编辑状态

//CATT_STRU 特别说明:
//1. CATT_STRU是ATT_STRU结构的替代类
//2. hd,fldEntry成员变量未添加前缀m_,且设计成公共成员变量,是为了减少程序移植的工作量.
//3. 但是:不允许直接赋类指针给fldEntry成员,如: CFIELD_HEAD  *ptFld; 	CATT_STRU   *ptStru;	...... 	ptStru->fldEntry=ptFld;	......
	class S3DKERGIS_ADAPTER_EXP CATT_STRU
	{
	public:
		CATT_STRU();
		CATT_STRU(CATT_STRU *ptStru0);
		virtual ~CATT_STRU();
	public:
		CINFO_HEAD    hd;
		CFIELD_HEAD  *fldEntry;	//字段说明入口	   

	public:
		short	AppendFld(short fldN, CFIELD_HEAD *fldEntry);            //添加字段
		short	InsertFld(short fldN, CFIELD_HEAD *fldEntry, short insTo);//insTo插入位置,从0开始
		short	DelFld(char *fldName);  //删除字段
		short	DelFld(short fldi);
		short	CalLengthOffset();    //计算各字段的二进制长度,字段偏移,检查合法性等.

		short	GetFieldNo(char *fieldname);//由属性字段名获取其字段序号

		short   IsSameAttStruVar(CATT_STRU *ptStru0); //完全相同返回1，否则返回0.
		short	CopyAttStru(CATT_STRU *ptAttStru);


		virtual long  CalSize();    //计算CATT_STRU类占用存储空间大小, 该函数首先调用CalLengthOffset()
		virtual short Load(HFILE hdf, long off);	      //装入CATT_STRU的内容(从文件句柄hdf的off偏移处)	
		virtual long  Save(HFILE hdf, long off);	      //保存CATT_STRU的内容(到文件句柄hdf的off偏移处)
	};

	class S3DKERGIS_ADAPTER_EXP ASK_DB_RCD	//查找数据库记录
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
		char *valPtr;	    //字段值指针
		short valType;	    //字段值类型
		int   valLen;	    //valPtr长度
		char  dbfldName[32];//数据库字段名
	};

	// ----------------- 定义属性表内存管理对象 ----------------- //
	typedef struct
	{
		void	 *ptNext;   //指向下一存储块指针
		long	 lStartEno; //该块存储的实体起始号
		long	 lEndEno;   //该块存储的实体终止号+1
		char	*attBuf;   //该块存储的实体属性BUF
	} AttMEMBLOCK_STRU;

	class S3DKERGIS_ADAPTER_EXP CAttTBL_Manger
	{
	public:
		CAttTBL_Manger(CATT_STRU *stru);
		~CAttTBL_Manger();

	public:		// 获取该属性表的缺省属性结构
		short	_GetAttStru(CATT_STRU **stru, char **att = NULL);
		short	_SetAttStru(CATT_STRU *stru);

		short	_GetAtt(long ti, CATT_STRU **stru, char **att);
		short	_UpdateAtt(long ti, CATT_STRU *stru, char *att);

		// 在属性表管理器尾部添加一条记录
		long	_AppendAtt(CATT_STRU *stru, char *att);

	private:
		AttMEMBLOCK_STRU*	GetPtAttBlockForRead(long ti);
		AttMEMBLOCK_STRU*	GetPtAttBlockForAppend(long ti);
	private:
		CATT_STRU			*m_PtAttStru; //该属性表结构
		char                *m_PtAttBuf;  //属性记录BUF

		AttMEMBLOCK_STRU	*m_PtAttBlock;//该属性表首内存块指针
	};




	// ----------------- 获取不同类型字段的字段长度 --------------------- //
	short  S3DKERGIS_ADAPTER_EXP _AttGetFieldTypeLen(char fieldType);
	short  S3DKERGIS_ADAPTER_EXP _AttGetFieldBufLenByFldEntry(CFIELD_HEAD *fldEntry);

		// 获取缺省字段结构
	#define    PNT_DEFAULT_ATTFILED     1	//点元缺省属性字段：ID
	#define    LIN_DEFAULT_ATTFILED     2	//线元缺省属性字段：ID，Length
	#define    REG_DEFAULT_ATTFILED		3	//面元缺省属性字段：ID，Length，Area
	#define    DEM_DEFAULT_ATTFILED		4 	//高程线元缺省属性字段：ID, Length，ContourVal

	S3DKERGIS_ADAPTER_EXP CFIELD_HEAD *	_AttGetDefaultField(char cType);

	// ------------------------------- 获取/设置属性域值 ------------------------------- //
	//根据字段名称取字段序号,成功返回字段序号(>=0),失败返回-1
	short  S3DKERGIS_ADAPTER_EXP _AttGetFldNo(CATT_STRU *stru, char *fldName);

	short  S3DKERGIS_ADAPTER_EXP _AttSetFldByNo(char *att, CATT_STRU *stru, short fldi, char *realVal);
	short  S3DKERGIS_ADAPTER_EXP _AttSetFldByName(char *att, CATT_STRU *stru, char *fldName, char *realVal);

	short  S3DKERGIS_ADAPTER_EXP _AttSetFldByNoFromStr(char *att, CATT_STRU *stru, short fldi, char *strVal, short valLen = 0);
	short  S3DKERGIS_ADAPTER_EXP _AttSetFldByNameFromStr(char *att, CATT_STRU *stru, char *fldName, char *strVal, short valLen = 0);

	//根据字段序号取数值型字段值
	short  S3DKERGIS_ADAPTER_EXP _AttGetFieldByNo(char *att, CATT_STRU *stru, short fldi, char *fldBuf, short bufLen, short *isBlank = NULL);

	//根据字段名称取数值型字段值
	short  S3DKERGIS_ADAPTER_EXP _AttGetFieldByName(char *att, CATT_STRU *stru, char *fldName, char *fldBuf, short bufLen, short *isBlank = NULL);






}

#pragma pack(pop)


#endif
