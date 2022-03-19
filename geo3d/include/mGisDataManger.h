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
	char		cExist;     //点元有效标志：1有效/-1无效
	} PNTINF_EXIST;

class mC2dPntDatManger      //Gis二维点数据内存管理对象.
	{
	public:	
		mC2dPntDatManger(); //构造函数
	   ~mC2dPntDatManger(); //析构函数

	public:			//二维点数据操作函数
		long		_AppendPnt(D_DOT *xy,char *dat,short len,PNT_INFO *inf);
		short		_UpdatePnt(long pi,D_DOT *xy,char *dat,short len,PNT_INFO *inf);
		short		_UpdatePntPos(long pi,D_DOT *xy);

		short		_GetPnt(long pi,D_DOT *xy,char **dat,short *len,PNT_INFO *inf);
		short		_GetPntPos(long pi,D_DOT *xy);

		short		_DelPnt(long li);
		short		_UnDelPnt(long li);

		char		_GetChangeFlag(void); //取数据改变标志
		short		_GetPntNum(long *logN, long *phyN);

					/*返回值:1/0/-1=存在/不存在/被删除*/
		short		_GetPntExistFlag(long pnti);   //取点存在标志		
		short		_GetPntLayer(long pi, short *lay);
		short		_GetPntRect(long pi, D_RECT *rc);
		short		_GetPntRectLayer(long pi, D_RECT *rc, short *layer);	

		short		_GetAreaRect(D_RECT *rc);//获取工作区数据总范围

	public:		
		short		_GetPntAtt(long pi, CATT_STRU **stru, char **att);
		short		_UpdatePntAtt(long pi, CATT_STRU *stru, char *att);

	private:
		BOOL        m_IsAreaValid;    // 对象有效标志.
		BOOL        m_IsDirty;        // 对象对应数据是否已修改.

		D_RECT      m_AreaRc;         // 数据总的范围.
	private:
		CAttTBL_Manger *m_PntAttTbl;  // 点实体属性表

	private:                          // 对象用内存指针:
		D_DOT      *m_ptPntSet;	      // 所有点数据表指针.
		long        m_lPntSetBuf;     // 已申请点数据BUF大小.
		long        m_lPntPhyNum;     // 对象内已有点数据物理个数
		long        m_lPntLogNum;     // 对象内已有点数据逻辑个数

		char      **m_ptPntStr;       // 点数据Str表指针.
        short      *m_ptPntStrLen;    // 点数据Str长表指针.		
		PNTINF_EXIST   *m_ptPntInfo;  // 点数据Info及点有效性记录表指针.
	};


class mC3dPntDatManger                 //Gis三维点数据内存管理对象.
	{
	public:	
		mC3dPntDatManger(); //构造函数
	   ~mC3dPntDatManger(); //析构函数

	public:			//三维点数据操作函数
		long		_AppendPnt(D_3DOT *xyz,char *dat,short len,PNT_INFO *inf);
		short		_UpdatePnt(long pi,D_3DOT *xyz,char *dat,short slen,PNT_INFO *inf);
		short		_UpdatePntPos(long pi,D_3DOT *xyz);

		short		_GetPnt(long pi,D_3DOT *xyz,char **dat,short *len,PNT_INFO *inf);
		short		_GetPntPos(long pi,D_3DOT *xyz);

		short		_DelPnt(long pi);
		short		_UnDelPnt(long pi);
	
	private:
		BOOL        m_IsAreaValid;    // 对象有效标志.
		BOOL        m_IsDirty;        // 对象对应数据是否已修改.

		D_RECT      m_AreaRc;         // 数据总的范围.
	private:
		CAttTBL_Manger *m_PntAttTbl;  // 点实体属性表
	
	private:                          // 对象用内存指针:
		D_3DOT     *m_ptPntSet;	      // 所有点数据表指针.
		long        m_lPntSetBuf;     // 已申请点数据BUF大小.
		long        m_lPntPhyNum;     // 对象内已有点数据物理个数
		long        m_lPntLogNum;     // 对象内已有点数据逻辑个数

        char      **m_ptPntStrDat;    // 点数据Str表指针.
        short      *m_ptPntStrLen;    // 点数据Str长表指针.
		PNTINF_EXIST   *m_ptPntInfo;      // 点数据Info及点有效性记录表指针.
	};




typedef struct LININFO_EXIST_STRUCT
{
	LIN_INFO	lInfo;
	char		cExist;    //点元有效标志：1有效/-1无效
} LININF_EXIST;

class mC2dLinDatManger                 //Gis三维数据内存管理对象.
	{
	public:	
		mC2dLinDatManger(); //构造函数
	   ~mC2dLinDatManger(); //析构函数

	public:			//三维数据操作函数
		long		_AppendLin(D_DOT *dat,long len,LIN_INFO *inf);
		short		_UpdateLin(long li,D_DOT *dat,long len,LIN_INFO *inf);

		short		_GetLin(long li,D_DOT **dat,long *len,LIN_INFO *inf);

		short		_DelLin(long li);
		short		_UnDelLin(long li);

		char		_GetChangeFlag(void); //取数据改变标志
		short		_GetLinNum(long *logN, long *phyN);

					/*返回值:1/0/-1=存在/不存在/被删除*/
		short       _GetLinExistFlag(long lini);   //取线存在标志
		short		_GetLinLayer(long li, short *lay);
		short		_GetLinRect(long li, D_RECT *rc);
		short		_GetLinRectLayer(long li, D_RECT *rc, short *layer);
		
		short		_GetAreaRect(D_RECT *rc);//获取工作区数据总范围

	public:			// 读/写线元属性
		short		_GetLinAtt(long pi, CATT_STRU **stru, char **att);
		short		_UpdateLinAtt(long pi, CATT_STRU *stru, char *att);

	private:
		BOOL        m_IsAreaValid;    // 对象有效标志.
		BOOL        m_IsDirty;        // 对象对应数据是否已修改.

		D_RECT      m_AreaRc;         // 数据总的范围.
	private:
		CAttTBL_Manger *m_LinAttTbl;  // 线实体属性表
	
	private:                          // 对象用内存指针:
		long        m_lLinSetBuf;     // 已申请线数据BUF大小.
		long        m_lLinPhyNum;     // 对象内已有线数据物理个数
		long        m_lLinLogNum;     // 对象内已有线数据逻辑个数

        D_DOT     **m_ptLinDat;       // 线数据Dat表指针.
        long       *m_ptLinDatLen;    // 线数据Dat长表指针.
		LININF_EXIST   *m_ptLinInfo;  // 线数据Info及线有效性记录表指针.
	};


class mC3dLinDatManger                 //Gis三维线数据内存管理对象.
	{
	public:	
		mC3dLinDatManger(); //构造函数
	   ~mC3dLinDatManger(); //析构函数

	public:			//三维线数据操作函数
		long		_AppendLin(D_3DOT *dat,long len,LIN_INFO *inf);
		short		_UpdateLin(long li,D_3DOT *dat,long len,LIN_INFO *inf);

		short		_GetLin(long li,D_3DOT **dat,long *len,LIN_INFO *inf);

		short		_DelLin(long li);
		short		_UnDelLin(long li);
	
	private:
		BOOL        m_IsAreaValid;    // 对象有效标志.
		BOOL        m_IsDirty;        // 对象对应数据是否已修改.

		D_RECT      m_AreaRc;         // 数据总的范围.
	private:
		CAttTBL_Manger *m_LinAttTbl;  // 线实体属性表
	
	private:                          // 对象用内存指针:
		long        m_lLinSetBuf;     // 已申请线数据BUF大小.
		long        m_lLinPhyNum;     // 对象内已有线数据物理个数
		long        m_lLinLogNum;     // 对象内已有线数据逻辑个数

		D_3DOT    **m_ptLinDat;       // 线数据Dat表指针.
        long       *m_ptLinDatLen;    // 线数据Dat长表指针.
		LININF_EXIST   *m_ptLinInfo;  // 线数据Info及线有效性记录表指针.
	};



typedef struct REGINFO_EXIST_STRUCT
{
	REG_INFO	rInfo;
	char		cExist;    //面元有效标志：1有效/-1无效
} REGINF_EXIST;

class mC2dRegDatManger  //Gis二维数据面内存管理对象.
{
	public:	
		mC2dRegDatManger(); //构造函数
	   ~mC2dRegDatManger(); //析构函数


	public:			//面数据操作函数
		long		_AppendReg(long *rdat,long len,REG_INFO *inf);
		short		_UpdateReg(long ri,long *rdat,long len,REG_INFO *inf);
		
		short		_GetReg(long ri,long **rdat,long *len,REG_INFO *inf);
		short		_GetRegInfo(long ri,REG_INFO *inf);
		short		_UpdateRegInfo(long ri,REG_INFO *inf);
		
		short		_DelReg(long li);
		short		_UnDelReg(long li);

		char		_GetChangeFlag(void); //取数据改变标志
		short		_GetRegNum(long *logN, long *phyN);

					/*返回值:1/0/-1=存在/不存在/被删除*/
		short		_GetRegExistFlag(long regi);   //取区存在标志
		short		_GetRegLayer(long ri, short *lay);
		short		_GetRegRect(long ri, D_RECT *rc);
		short		_GetRegRectLayer(long ri, D_RECT *rc, short *layer);

					// ------------------ 取面元区域边界点坐标 ------------------ // 
					// xy --- 长度不小于rdata[0]的已分配D_DOT内存空间
					// ne --- 长度不小于该面元区域圈数的已分配long内存空间
		short 		_GetRegEdge(long *rdata, long len, D_DOT *xy, long *ne);

					// ---------------------- 计算点到面元区之间的距离 ---------------------- //
					/*入口：pnt  -  点坐标地址
							ri	 -  区号
							minDis- 点到区域的最小距离变量地址，若不需要，可=NULL
							maxDis- 点到区域的最大距离变量地址，若不需要，可=NULL
					  出口：minDis- 返回点到区域的最小距离
							maxDis- 返回点到区域的最大距离
					  返回：1/0=成功/失败*/
		short       _GetDistofPntToReg(D_DOT *pnt, long ri, double *minDis, double *maxDis);

					// --------------------- 检测点是否在面元区域内函数 --------------------- //
					// flg==1则严格套合，否则只检查第一圈.
					// 返回值：2/1/0=内/边界/外.
		short		_IsDotInReg1(D_DOT *dot, long ri, short flg);

					// 计算指定面元区的面积与周长
					// 返回0则表示出错；返回1表示面元外圈顺时走向、返回-1表示面元外圈逆时走向.
		short       _CalculateArea(long ri, double *area, double *par);
		short		_CalRegRect(long ri, D_RECT *dfRc); // 计算指定面元区的边界范围
				
		short		_GetAreaRect(D_RECT *rc);//获取工作区数据总范围

	public:			// 读/写面元属性
		short		_GetRegAtt(long pi, CATT_STRU **stru, char **att);
		short		_UpdateRegAtt(long pi, CATT_STRU *stru, char *att);

	public:			//面数据中的弧段数据操作函数
		long		_AppendLin(D_DOT *dat,long len,LIN_INFO *inf);
		short		_UpdateLin(long li,D_DOT *dat,long len,LIN_INFO *inf);

		short		_GetLin(long li,D_DOT **dat,long *len,LIN_INFO *inf);

		short		_DelLin(long li);
		short		_UnDelLin(long li);	

		short		_GetLinNum(long *logN, long *phyN);

		/*返回值:1/0/-1=存在/不存在/被删除*/
		short		_GetLinExistFlag(long li);   //取区存在标志
		short		_GetLinLayer(long li, short *lay);
		short		_GetLinRect(long li, D_RECT *rc);
		short		_GetLinRectLayer(long li, D_RECT *rc, short *layer);


		// ------------------- 检测点是否在区域内函数 ------------------- //
		// flg==1则严格套合，否则只检查第一圈.
		// 返回值：2/1/0=内/边界/外.
		short		cmIsDotInReg1(D_DOT *dot, long ri, short flg);

	public:			// 读/写面元数据中线实体属性
		short		_GetLinAtt(long pi, CATT_STRU **stru, char **att);
		short		_UpdateLinAtt(long pi, CATT_STRU *stru, char *att);

	private:
		mC2dLinDatManger regArcDat;   // 面数据中的弧段数据对象.

	private:
		BOOL        m_IsAreaValid;    // 对象有效标志.
		BOOL        m_IsDirty;        // 对象对应数据是否已修改.

		D_RECT      m_AreaRc;         // 数据总的范围.
	private:
		CAttTBL_Manger *m_RegAttTbl;  // 面实体属性表
	
	private:                          // 对象用内存指针:
		long        m_lRegSetBuf;     // 已申请弧段数据BUF大小.
		long        m_lRegPhyNum;     // 对象内已有弧段数据物理个数
		long        m_lRegLogNum;     // 对象内已有弧段数据逻辑个数

		long      **m_ptRegDat;       // 记录各面元的弧段号数据表指针.
        long       *m_ptRegDatLen;    // 各面元的弧段号数据长度表指针.
		REGINF_EXIST   *m_ptRegInfo;  // 面数据Info及面元有效性记录表指针.
};


#endif /* #ifndef __ZTYQ_memGisData_Manger_H_ */

