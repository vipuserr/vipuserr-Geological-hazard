// -----------------------------------------------------------------
//
// Copyright:	ZondySoft 2004
//
// File:		GeoStatLib.h
//
// Project:		GeoStatLib
//
// Creator:		������
//
// Time:		09:42 2004-12-11
//
// Description:	Geological Statistical Library
//
// -----------------------------------------------------------------

#ifndef _GEOSTAT_LIB_H
#define _GEOSTAT_LIB_H


#include <windows.h>
#include "sqltypes.h"

//#pragma pack(push, 1)
#include "gsstru.h"
typedef class CGeoStat*		GeoStatObj;	//����ͳ�ƿ����

//����ͳ�ƿ��������
#define		GEO_BASE_OBJ		0	//����ͳ�ƻ�������
#define		GEO_DATA_ANAS_OBJ	1	//���ݴ������
#define		GEO_VRG_OBJ			2	//��������
#define		GEO_STAT_GRAPHY_OBJ	3	//ͳ��ͼ���ɶ���
#define		GEO_KRIG_OBJ		4	//�������ֵ����
#define		GEO_SIMULAT_OBJ		5	//ģ�����


#ifndef _CGEO_STAT_LIB
  #define GEOSTAT_DLL  __declspec(dllimport)
#else
  #define GEOSTAT_DLL  __declspec(dllexport)
#endif


#if defined(__cplusplus)
  extern "C" {
#endif 

	//��������
	//˵��:	�������͵Ĳ�ͬ������ͬ�Ķ���.
	//����:	lObjType -------------> ��������
	GeoStatObj GEOSTAT_DLL _gsCreateGeostatObj(long lObjType);
	//ɾ������
	void GEOSTAT_DLL _gsDeleteGeostatObj(GeoStatObj gsObj);
    
	// ========================== ���ú��� ========================== //
	//�����Ƿ���ʾ������
	//˵��:	�ú��������ڼ���������Ƿ���ʾ������
	//����:	
	//		IsShowProgr ----------> �Ƿ���ʾ������
    long GEOSTAT_DLL _gsSetIsShowProgr(GeoStatObj gsObj, BOOL IsShowProgr = TRUE);

	// ========================== ���ú��� ========================== //
	//�������ݼ���
	//˵��:	�ú������õ����ݼ���ֵ,������Ч���ݵķ�Χ. �����ݽ��д���ʱ,
	//		�����÷�Χ�����ݽ���Ϊ��Ч��������. (added by htl)
	//����:	
	//		fExtrMin ----------> ������С����
	//		fExtrMax ----------> ���������
	long GEOSTAT_DLL _gsSetDataExtr(GeoStatObj gsObj, 
									double fExtrMin=GS_MINTRIM, 
									double fExtrMax=GS_MAXTRIM);
	//װ������
	//˵��:	�ú���װ�������,���Ǹ������ͳ�ƹ����д��������. ��������1
	//		��ʾ���Ǵ�����������õ������ݱ���,������2����ĳЩ����(�絥��
	//		���任_dmTrans,Э������_krigCokb3d��)���õ��ĸ�������. �����
	//		Ҫ��������,���������װ������1,����2,�ֱ����ݱ�־lDatFlag��
	//		Ϊ1,2. (added by htl)
	//����:	
	//		pDiscPnts[] -------------> ���ݵ�
	//		lDatNum -----------------> ������Ŀ
	//		lDatFlag ----------------> ���ݱ�־(��ʱֻ֧��2������,1:����1,2:����2)	
	long GEOSTAT_DLL _gsLoadDiscPnts(GeoStatObj gsObj, 
									 GsDiscPnt *pDiscPnts, long lDatNum, 
									 long lDatFlag=1);
	long GEOSTAT_DLL _gsLoadDiscPnts1(GeoStatObj gsObj, 
		GsDiscPnt1 *pDiscPnts, long lDatNum, 
		long lDatFlag=1);

	//����Ȩֵʹ�ñ�־
	//˵��:	��ĳЩ���ݴ�����(�絥�����任_dmTrans,��Ҷ˹ģ���У׼_bicaBicalib��)��,
	//		�����ݽ��з�������ʱ,��ʱ��Ҫ��ÿ�����ݽ��м�Ȩ����. ������Ҫ����Ȩֵʹ��
	//		��־,���ж�ĳ��������Ƿ�ʹ������Ȩֵ. �������ݿ��Է�Ϊ��Ҫ�����͸�������,
	//		��ҲҪ�ֱ������������ݵ�Ȩֵʹ�ñ�־. (added by htl)
	//����:	
	//		lUseWtFlag --------------> ʹ��Ȩֵ��־(0:��ʹ��,1:ʹ��)
	//		lDatFlag ----------------> ���ݱ�־(��ʱֻ֧��2������,1:����1,2:����2)	
	long GEOSTAT_DLL _gsSetUseWtFlag(GeoStatObj gsObj, 
									long lUseWtFlag=0, long lDatFlag=1);

	//���ù����������
	//˵��:	�ڱ�������,�������ֵ,����ģ����,����Ҫ�õ����ݵ�����,������������
	//		�������. �ú����ֱ�����x,y,z���������������Ŀ,���,����(���). (added by htl)
	//����:
	//		lGridNumX,lGridNumY,lGridNumZ -------------> ������Ŀ
	//		fGridOriX,fGridOriY,fGridOriZ -------------> ������㣨������ڵ���С���꣩
	//		fGridSizX,fGridSizY,fGridSizZ -------------> ������
	long GEOSTAT_DLL _gsSetGridPara(GeoStatObj gsObj, 
									long lGridNumX, long lGridNumY, long lGridNumZ,
									double fGridOriX, double fGridOriY, double fGridOriZ,
									double fGridSizX, double fGridSizY, double fGridSizZ);
	//���ò�ֵ��Χ���������
	long GEOSTAT_DLL _gsSetGridParaEva(GeoStatObj gsObj, 
		long lGridNumX, long lGridNumY, long lGridNumZ,
		double fGridOriX, double fGridOriY, double fGridOriZ,
		double fGridSizX, double fGridSizY, double fGridSizZ);
	//���ò�ֵ����
	//˵��:	
	//����:	
	//		iStrNum ----------------> ������Ŀ
	//		fNugConst --------------> �����
	//		pfArchValue[] ----------> ����(��СΪMAXNST,��ͬ)
	//		piModelType[] ----------> ���۱���ģ������
	//		pfChgRang[],... --------> ���
	//		pfAnisAng1[],... -------> �������ԽǶ�
	long GEOSTAT_DLL _gsSetIntpPara(GeoStatObj gsObj, 
									int iStrNum, double fNugConst, 
									double *pfArchValue, int *piModelType, 
									double *pfChgRang, double *pfChgRang1, double *pfChgRang2, 
									double *pfAnisAng1, double *pfAnisAng2, double *pfAnisAng3);

	//�������������Сֵ
	//˵��:	����ĳЩ���Եļ�ֵ. Ŀ����Ϊ���ж����Ե���Ч��,�������������
	//		�Ĳ�ͬ����ͬ. (added by htl)
	//����:		
	//		fAttrMin -----------------> ��С����
	//		fAttrMax -----------------> �������
	//		lAttrFlag ----------------> ���Ա�־(1:��������,2:x����,3:y����)
	//		fLabSpace ----------------> ��ǩ���
	long GEOSTAT_DLL _gsSetAttrExtr(GeoStatObj gsObj, 
									double fAttrMin=GS_MINTRIM,  double fAttrMax=GS_MAXTRIM, 
									long lAttrFlag=1, double fLabSpace=5);

	//���ñ�������
	//˵��:	��. (added by htl)
	//����:	
	//		lVarType ---------> ��������(0:������,1:����)
	long GEOSTAT_DLL _gsSetVarType(GeoStatObj gsObj, long lVarType=0);


	//�����Ƿ�ʹ�þֲ����ݱ�־
	//����:	
	//		lLocFlag ----------> ʹ�þֲ����ݱ�־(0:��ʹ��,1:ʹ��)
	long GEOSTAT_DLL _gsSetUseLocFlag(GeoStatObj gsObj, long lLocFlag=0);


	//������ֵ
	//˵��:	Ϊ��Ҫ�����͸�������������ֵ. (added by htl)
	//����:	
	//		pfCutOff[] ------------> ��ֵ
	//		lCutNum ---------------> ��ֵ��Ŀ
	//		lCutFlag --------------> ������ֵ��־(1:U����/��Ҫ����,2:V����/��������)
	void GEOSTAT_DLL _gsSetCutOff(GeoStatObj gsObj, 
								  double *pfCutOff=NULL, long lCutNum=0, 
								  long lCutFlag=1);


	//��������ȡ������־
	//˵��:	������������ע��ȡ������ʾ. ��֮��Ӧ�����귽��������ڼ���ʱҲȡ����.
	//		(added by htl)
	//����:
	//		lLogFlag ---------> ʹ�ö�����߱�־(0:�������,1:����)
	//		lAxisFlag --------> �������־(1:������,2:x��,3:y��)
	long GEOSTAT_DLL _gsSetLogFlag(GeoStatObj gsObj, 
								  long lLogFlag=0, long lAxisFlag=1);

	//����������Ŀ(��״ͼ�������)
	//����:	
	//		lClassNum ----------> ������Ŀ(��״ͼ�������)
	long GEOSTAT_DLL _gsSetClassNum(GeoStatObj gsObj, long lClassNum=1);

	//���÷�λ����Ŀ
	//����:	
	//		lQuanNum -----------> ��λ����Ŀ(���ݶ���ķ�λ���ĸ���,ƽ��������۸���ֵ)
	void GEOSTAT_DLL _gsSetQuanNum(GeoStatObj gsObj, long lQuanNum);

	//װ����������ֵ
	//˵��:	װ��������ֵ�õ��Ĺ���ֵ,��ΪĳЩ��������ͳ�ƵĲ���(����ƽ�����֤���ͼ
	//		ʱ�����������ֵ��ԭʼֵ����õ����ֵ). (added by htl)
	//����:	
	//		pfKrigEstVal[] -----------> ����ֵ(�������Ի򷽲�)
	//		lEstNum ------------------> ����ֵ��Ŀ
	long GEOSTAT_DLL _gsLoadEstVal(GeoStatObj gsObj, 
								   double *pfKrigEstVal=NULL, 
								   long lEstNum=0);

	//����ָʾ������ֵ
	//˵��:	�ú������õ���ֵ,�ֲ�����������ָʾ�������ֵ�����й���ָʾ��.
	//		(added by htl)
	//����:	
	//		pfThres[] ----------> ��ֵ/���
	//		pfCdf[] ------------> ȫ�ֵ��ۻ��ֲ�����/���ʷֲ�����
	//		lThresNum ----------> ��ֵ��Ŀ
	long GEOSTAT_DLL _gsSetThresAndCdf(GeoStatObj gsObj, 
									   double *pfThres, double *pfCdf, 
									   long lThresNum);

	//����tail��Ϣ
	//˵��:	ָ���ݼ�(β��)/����(�ײ�)����Ļ���(���ת��)����. (added by htl)
	//����:	
	//		lTailNo ---------> �����ֵ����(1:�����Լ�ֵ�������Բ�ֵ,2:����
	//										�������ֵ�����Լ�ֵ����ָ��ģ��
	//										��ֵ,4:���������ֵ����˫�������Ʋ�ֵ)
	//		fTailVal --------> �������ֵ
	//		lTailFlag -------> ���ݶα�־(1:�ײ�,2:�м�,3:����)
	void GEOSTAT_DLL _gsSetTailInfo(GeoStatObj gsObj, 
									long lTailNo, double fTailVal, 
									long lTailFlag=1);

	//�����������
	//˵��:	���ڲ���һ�������. �����ӵ���Ϊ�������ĵ�һ����Ա. (added by htl)
	//����:	
	//		lSeed ---------> ���������(����ɢ����ת��Ϊ�ֲ�����ʱʹ�õ�)
	void GEOSTAT_DLL _gsSetRandomSeed(GeoStatObj gsObj, long lSeed=0);

	//���þ��뷴���ݴ�
	//˵��:	���þ��뷴���ݴ�
	//����:	
	//		iDisPower -----> ���뷴���ݴ�
	void GEOSTAT_DLL _gsSetDisPower(GeoStatObj gsObj, int iDisPower = 2);

	//���ð˷�Բ��������
	//˵��:	���ð˸���������ʱÿ�������������. ���ʹ�ð˷�Բ����,��ͨ���������
	//		�����õ�����������Ҫ�ְ˸����������Ч���ж�. (added by htl)
	//����:	
	//		lPntNum -----> �˷�Բ(���)��������(0:��ʹ�ð˷�Բ����, >0:ʹ��)
	void GEOSTAT_DLL _gsSetSrchOct(GeoStatObj gsObj, long lPntNum=0);

	//������������
	//����:
	//		fRadius ---------------------------> �����뾶(��������)
	//		fRadius1 --------------------------> �����뾶(�������)
	//		fRadius2 --------------------------> �����뾶(���������)
	//		fAng1 -----------------------------> ��������������ļн�
	//		fAng2 -----------------------------> ������ˮƽ����ļн�
	//		fAng3 -----------------------------> ��������ˮƽ����ļн�
	//		iMinNum, iMaxNum ------------------> ��С�����������
	//		iDiscNumX,... ---------------------> ÿ�����(ĳ������)����ɢ����
	void GEOSTAT_DLL _gsSetSrchPara(GeoStatObj gsObj, 
									double fRadius=-1, double fRadius1=-1, 
									double fRadius2=-1,
									double fAng1=0, double fAng2=0, 
									double fAng3=0,
									int iMinNum=4, int MaxNum=8,
									int iDiscNumX=1, int iDiscNumY=1, 
									int iDiscNumZ=1);

	//����ʵ�ִ���(set number of realizations)
	//����:	
	//		lRealNum ---------> ����/ʵ��/ģ�����
	void GEOSTAT_DLL _gsSetRealNum(GeoStatObj gsObj, long lRealNum);

	// ====================== ���ݴ����� ============================ //
	//˵��:	�ò��ֺ������һ�����ݵĴ���ͼ���.
	// -------------------------- ������ת ---------------------------- //
	//������
	//˵��:	��һ����ά�������תһ���Ƕ�,��һ����ת�������������ת��
	//		ԭʼ��λ��.
	//����:	
	//		pPreDot -------------> ԭʼ��(������תΪ��ת��ĵ�)
	//		pAftDot -------------> ��ת��ĵ�(������תΪԭʼ��)
	void GEOSTAT_DLL _gsRotCoord(GeoStatObj gsObj, 
								 GSD_DOT *pPreDot, GSD_DOT *pAftDot);

	//������ת
	void GEOSTAT_DLL _gsRotCoord1(GeoStatObj gsObj, 
								 GSD_DOT *pPreDots, GSD_DOT *pAftDots, 
								 long lDotsNum);
	//��������ԭ��
	//����:	
	//		pOriPnt -------------> ԭʼ����ϵ�е���תϵͳ��ԭ��
	void GEOSTAT_DLL _gsSetOriPnt(GeoStatObj gsObj, GSD_DOT *pOriPnt);

	//������ת�Ƕ�
	//����:	
	//		dRotAng --------> ��ת�Ƕ�(˳ʱ��Ϊ��)
	void GEOSTAT_DLL _gsSetRotAng(GeoStatObj gsObj, double dRotAng=0);
	
	//������ת��־
	//����:	
	//		bRotFlag -------> ��ת��־(0:��ת��Ŀ������ϵ,1:����ת��ԭʼ����ϵ)
	void GEOSTAT_DLL _gsSetRotFlag(GeoStatObj gsObj, bool bRotFlag=0);

	// ---------------------------- ���ݴԾ� --------------------------- //
	//������
	//����:	����ɢ����ָ���Ծ�Ȩֵ,��Щ����λ��ͬһ�Ծ۵�Ԫ��. �������Ե�
	//		��(�Ծ�)��Ԫ��������ά��,�����Ҫ�Ļ�,��ѵ�Ԫ�ߴ�����Զ�����
	//		����.
	//����:	
	//		pfDeclusWt[] ---------> ���ݴԾ�Ȩֵ(��С�����ݴ�С���)
	//		pClustSum[] ----------> �Ծ�Ȩֵƽ����
	void GEOSTAT_DLL _gsDeclus(GeoStatObj gsObj, 
							   double *pfDeclusWt=NULL, 
							   ClustSum *pClustSum=NULL);

	//���ø������Ա���
	//˵��:	���þ������ε�Ԫ��С�ĸ������Ա���.y,z����Ԫ�ߴ������x����ı���,
	//		ysiz=anisy*siz, zsiz=anisz*siz.
	//����:	
	//		fAnisY -----------> y����Ԫ�ߴ������x����ı���
	//		fAnisZ -----------> z����Ԫ�ߴ������x����ı���
	void GEOSTAT_DLL _gsSetAnisFactor(GeoStatObj gsObj, 
									  double fAnisY=1, double fAnisZ=1);
	//�����Ƿ����������Сƽ��ֵ��־
	//����:	
	//		lMinMaxFlag ------------> ������־(0;������Сֵ,1:���ֵ)
	void GEOSTAT_DLL _gsSetMinMaxFlag(GeoStatObj gsObj, long lMinMaxFlag=0);

	//���þ��൥Ԫ����
	//˵��:	��Щ�ߴ�ֱ��Ӧ�õ�x����,y,z����ĳߴ�ͨ���������Ա�����x����ߴ���˵õ�.
	//����:	
	//		lCellSizNum ------------> �Ծ۵�Ԫ��Ŀ
	//		fCellMinSiz ------------> ��С�ߴ�
	//		fCellMaxSiz ------------> ���ߴ�
	void GEOSTAT_DLL _gsSetCellPara(GeoStatObj gsObj, long lCellSizNum=1, 
									double fCellMinSiz=GS_MINTRIM, double fCellMaxSiz=GS_MAXTRIM);
	
	//����ԭ��ƫ��������Ŀ
	//˵��:	ÿһ����Ԫ�ߴ綼�Ǵ�ԭ��ƫ�Ʋ�ͬ��Ŀ��ƫ�����õ���.�������Ա��������ض�
	//		��Ԫ�е�����ֵ���²��ȶ��Ľ��. ��άһ����Ϊ4,��ά��Ϊ8.
	//����:	
	//		lOffSetNum --------> ԭ��ƫ�Ƶ���Ŀ
	void GEOSTAT_DLL _gsSetOffSet(GeoStatObj gsObj, long lOffSetNum=0);




	// --------------------------- ��̬�任 ----------------------- //
	//������
	//����:	�������ݵ���̬�ֲ�ֵ. �����������Ժ�Ȩֵ,����ÿ�����ݶ�Ӧ����̬
	//		�ֲ�ֵ.
	//˵��:	����ͳ��ģ�⾭��Ҫ�����ݷ�����̬���˹�ֲ�. ����ģ�������ģ��
	//		֮ǰ��Ҫ��������ת��,������Ҫ�ڱ�������֮ǰʹ�øú�������
	//		����ת��.
	//����:	
	//		pdPriNscore[] ------------> ������Ҫ������̬�ֲ�ֵ(��С��������ͬ,��ͬ)
	//		pdTranVar[] --------------> ��������(����trans�ļ���,��ͬ)
	//		pdTranVrg[] --------------> ������̬�ֲ�ֵ
	void GEOSTAT_DLL _gsNscore(GeoStatObj gsObj,
							   double *pdPriNscore=NULL, 
							   double *pdTranVar=NULL, 
							   double *pdTranVrg=NULL);
	//��������ƽ����־
	//˵��:	���øñ�־,����������̬�任������ʹ����ɢ���ݻ�ƽ������.
	//����:	
	//		lSmthFlag ---------> ����ƽ����־(0:��ʹ��ƽ������,1:ʹ��)
	void GEOSTAT_DLL _gsSetSmoothFlag(GeoStatObj gsObj, long lSmthFlag);
	//װ��ƽ������
	//����:	
	//		pSmooth[] ------------> ƽ������
	//		lSmthNum -------------> ƽ��������Ŀ
	void GEOSTAT_DLL _gsLoadSmooth(GeoStatObj gsObj, 
								   Smooth *pSmooth, long lSmthNum);



	// ----------------------- ��̬����任 ----------------------------- //
	//������	
	//����:	��ѯת�����е���̬�ֲ�ֵ,����ת��Ϊ���ݵ�ԭʼ����ֵ.
	//˵��:	�ú��������ڸ�˹ģ�������,һ�����ʹ��,���Ĺ������Զ���ģ��ֵ
	//		����任Ϊԭʼֵ. ��ʱ,������ģ����̬�ռ䲢�ұ���ģ����,�Ա�
	//		(��ģ��ֵ)���м���. Ȼ��,�ú�����������������任.
	//����:	
	//����:	pdPriNscore[] ---------> ������Ҫ������̬�ֲ�ֵ(��С��������ͬ,��ͬ)
	//		pdTranVar[] -----------> ��������(����trans�ļ���)
	//		pdTranVrg[] -----------> ������̬�ֲ�ֵ
	//		lDatNum ---------------> ������Ŀ
	//���: pfDataAttr[] ----------> ����ԭʼ����
	//����: ��.
	void GEOSTAT_DLL _gsBacktr(GeoStatObj gsObj,
							   double *pfPriNscore=NULL, double *pfTranVar=NULL, 
							   double *pfTranVrg=NULL, long lDatNum=0, long lTranNum=0,
							   double *pfDataAttr=NULL);

	// ------------------------ һ��(һԪ)�任 --------------------------- //
	//������
	//����:	��ԭʼ�ֲ��ķ�λ��ת��ΪĿ��ֲ��ķ�λ��.
	//˵��:	�ú�����ȡ��������ֲ�������,Ȼ����ת��Ϊ��������ֲ�. �ù���
	//		������ģ����������о�.
	//		��ȡһ���ο��ֲ���һϵ�������ֲ�,Ȼ�󽫵ڶ���ֲ��е�ÿһ���ֲ�
	//		��ֵ����ת��,��ʹ������״ͼ��ο��ֲ���(��״ͼ)��ƥ��.
	//����:	
	//		pfTranAttr[] -------> ת�������������(��СΪ���ݼ���Ŀ*������Ŀ)
	void GEOSTAT_DLL _gsTrans(GeoStatObj gsObj, double *pfTranAttr);
	
	//�������ݼ�����
	//����:	
	//		lDatSetNum --------------> ���ݼ���Ŀ(size to transform, number 
	//											  of realizations)
	//		lDatSetSiz --------------> ���ݼ���С(size to of continuous 
	//											  variable data set to transform)
	void GEOSTAT_DLL _gsSetDatSetPara(GeoStatObj gsObj, 
									  long lDatSetNum=1, long lDatSetSiz=1);
	//������άģ�ͳߴ�
	//˵��:	size of categorical variable realizations to transform.
	//����:	
	//		lModelSizX,... -------> ��άģ�͵ĳߴ�
	void GEOSTAT_DLL _gsSetModelSiz(GeoStatObj gsObj, 
								    long lModelSizX=1, 
									long lModelSizY=1, 
									long lModelSizZ=1);
	//���ô��ڳߴ�
	//˵��:	window size for breaking ties.
	//����:	
	//		lWinSizX,... ----------> ��ɢ�������ڵĳߴ�
	void GEOSTAT_DLL _gsSetWindowSize(GeoStatObj gsObj, 
									  long lWinSizX=1, 
									  long lWinSizY=1, 
									  long lWinSizZ=1);	
	//���ÿ��Ʋ���
	//˵��:	��������Ȩֵ����.
	//����:	
	//		dCtrlPara ------------> ���Ʋ���(����ԭʼ���ݵ�Ȩֵ,0.33-3.0)
	void GEOSTAT_DLL _gsSetCtrlPara(GeoStatObj gsObj, double dCtrlPara=0);

	// ---------------------- ��ɷ�-��Ҷ˹ģ��У׼ ----------------------- //
	//������
	//����:	����Ԥ�ȷֲ��ͱ�Ҷ˹У׼����. 
	//		�ú���У׼һ��������Ҫ�����͸������������ݼ�,�Ա�������Ϊ"mbsim"
	//		�Ĳ���. �������е���Ҫ�����͸���������Ϊ��������,���������������
	//		�ض�����Ļ�,�����Ϊ��Ҫ�����ֲ�Ԥ���ۻ��ֲ�����.
	//		��Markov-Bayesѡ��(���κ�������ָʾ��������ѡ��)ָʾ��ģ��֮ǰ��Ҫ
	//		���øó���,�����ݷֲ��������У׼������.�ó���ȷ����Щ�ֲ���
	//		Markov-Bayes�����B����.
	//����:
	//		plPairNum ----------> ���ݶ���
	//		pStat1,pStat2 ------> ����ͳ����
	//		pfIndMean[] --------> ָʾ��ƽ��ֵ(��СΪmxvcut=max(ncutu, ncutv))
	//		pfPdf[] ------------> pdfֵ(��СΪ(mxvcut+1)*(mxvcut+1))
	//		plTotNum[] ---------> ĳ��ֵ�ĵ���(��СΪmxvcut*2)
	//		pfEstMean[] --------> ����ƽ��ֵ(��СΪmxvcut*2)
	//		pfVariMean[] -------> ����ƽ��ֵ(��СΪmxvcut*2)
	//		pfLocCdf[] ---------> �ֲ�cdfֵ(��СΪ������Ŀ)
	//		pfBayes[] ----------> ��Ҷ˹ֵ(��СΪ��ֵ��Ŀ�Ľϴ���mxvcut)
	//		pfLocPriCdf[] ------> �ֲ�ԭʼcdfֵ(��СΪ��ֵ����Ŀ�ϴ���mxvcut��ƽ��)
	void GEOSTAT_DLL _gsBicalib(GeoStatObj gsObj, 
								long *plPairNum=NULL, 
								Statistic *pStat1=NULL, Statistic *pStat2=NULL, 
								double *pfIndMean=NULL, double *pfPdf=NULL, 
								long *plTotNum=NULL, 
								double *pfEstMean=NULL, double *pfVariMean=NULL, 
								double *pfLocCdf=NULL, double *pfLocPriCdf=NULL, 
								double *pfBayes=NULL);
	
	// ----------------------- ��״ͼƽ�� --------------------------- //
	//������
	//����:	����һ����ƽ��ֵ,����,��λ����ƽ��ϵ��Լ����ƽ���ֲ�ģ��.
	//����:	
	//		pSmooth[] -------------> pֵ(��С��������Ŀ���)
	void GEOSTAT_DLL _gsHistsmth(GeoStatObj gsObj, Smooth *pSmooth);

	//������״ͼ������Ŀ
	////set number for objective function(sasim)
	//����:	
	//	lHistNum -----------> ��״ͼ�ķ�����(number of quantiles for obj. func.,sasim)
	void GEOSTAT_DLL _gsSetHistNum(GeoStatObj gsObj, long lHistNum=1);
	
	//���ó����������
	//����:	
	//		lMaxPert -------------> ��ֵ�仯,��������
	//		lReportInterval ------> ������,��ֵ�ı�,���򱨸浱ǰ����ĺ���
	//		fMinObj --------------> ����׼���Ķ��������е���ֵʱ,����ֹͣ
	void GEOSTAT_DLL _gsSetProgStopPara(GeoStatObj gsObj, 
										long lMaxPert=1, long lReportInterval=1, 
										double fMinObj=0);

	//����Ŀ�꺯�����(��ӽ�ĳһ�ο�ָ��ı�־,1:��,0:��)
	//����:	
	//		lMeanFlag --------> �ӽ�Ŀ��ƽ����
	//		lVariFlag --------> �ӽ�Ŀ�귽��
	//		lSmthFlag --------> �⻬ϵ��
	//		lQuanFlag --------> �ӽ�ָ����λ���ı�־
	void GEOSTAT_DLL _gsSetFuncComp(GeoStatObj gsObj, 
									long lMeanFlag=0, long lVariFlag=0, 
									long lSmthFlag=0, long lQuanFlag=0);
	
	//����Ŀ�꺯��Ȩֵ(�û�ǿ�����õ�Ȩֵ,�����Զ������Ȩֵ)
	//����:	
	//		fMeanScal ----------> ƽ��ֵȨֵ
	//		fVariScal ----------> ����Ȩֵ
	//		fSmthScal ----------> �⻬ϵ��Ȩֵ
	//		fQuanScal ----------> ��λ��Ȩֵ
	void GEOSTAT_DLL _gsSetFuncScal(GeoStatObj gsObj, 
									double fMeanScal, double fVariScal, 
									double fSmthScal, double fQuanScal);
	//����ƽ��ֵ�ͷ���
	//����:
	//		fMean -------> ƽ��ֵ
	//		fVari -------> ����
	void GEOSTAT_DLL _gsSetMeanVari(GeoStatObj gsObj, 
									double fMean, double fVari);
	//�����û���λ������
	//����:	
	//		pfCdf[] ---------> cdf(�ۻ��ֲ�����)ֵ
	//		pfZ[] -----------> zֵ
	//		lUserQuanNum ----> �û��Զ���ķ�λ���ĸ���
	void GEOSTAT_DLL _gsSetUserQuan(GeoStatObj gsObj, 
									double *pfCdf=NULL, double *pfZ=NULL, 
									long lUserQuanNum=0);


	// ====================== �������� =========================== //
	// --------------------- ������ ----------------------------- //
	//�������ݵı�������
	//˵��:	�ú����Ĺ����ǶԶ�������(���Ե����ң��)���й��,����������
	//		ģ��Ľ��. (��񻯵�)����ͨ��������ĵ�λ������ָ��. �ú���
	//		�Ľ������GSLIB�����ݸ�ʽ,����һ�ֿ��������б�����ͼ�ĸ�ʽ.
	//����:	
	//		pVrg[] ---------------> ����(�����С=������*�ͺ����*������Ŀ)
	void GEOSTAT_DLL _gsGam(GeoStatObj gsObj, Variogram *pVrg);

	//��ɢ���ݵı�������
	//˵��:	ͨ��,��Ҫ�����������ڹ���������. �ú�����������������������. ��
	//		��������ͬʱ������������������������. Ȼ��,�ͺ����Ĺ淶,
	//		�ڶ����������ͬ��;���,��ʵ�ʲ�����,���ִ�иó����Ǳ�Ҫ��. �ú���
	//		�Ľ������GSLIB�����ݸ�ʽ,����һ�ֿ��������б�����ͼ�ĸ�ʽ.
	//����:	
	//pVrg[] ---------------> ����(�����С=������*(�ͺ����+2)*������Ŀ)
	void GEOSTAT_DLL _gsGamv(GeoStatObj gsObj, Variogram *pVrg, double &fSill);

	//lhy 2008-8-26
	//Э���������
	//˵��������������֮��ı����Լ�Э�����
	void GEOSTAT_DLL _gsCoVariance(GeoStatObj gsObj, Variogram *pVrg);

	//����ͼ����
	//˵��:	һ������ͼ�ھ��������Եķ������Ǻ����õ�. �ڼ������ʾ��һ�����
	//		�����Ժ�,ͨ����Ҫ��ͷ����gam��gamv���������������С�����Է���ı��
	//		����. ������������GSLIB���ݸ�ʽ,�Ա���pixelplt������ʹ��.
	//����:	
	//pVrg[] ---------------> ����(��С=������*(ÿ�������ͺ������2��+1))
	void GEOSTAT_DLL _gsVarMap(GeoStatObj gsObj, Variogram *pVrg);

	//Э�����ͼ����
	//˵��:	һ��Э�����ͼ�ھ��������Եķ������Ǻ����õ�. �ڼ������ʾ��һ�����
	//		�����Ժ�,ͨ����Ҫ��ͷ����gam��gamv���������������С�����Է���ı��
	//		����. ������������GSLIB���ݸ�ʽ,�Ա���pixelplt������ʹ��.
	//������
	//pVrg[] ---------------> ����(��С=������*(ÿ�������ͺ������2��+1))
	void GEOSTAT_DLL _gsCoVarMap(GeoStatObj gsObj, Variogram *pVrg);

	//��˹�ֲ��ı�������
	//˵��:	������ĵ���ͳ��ģ�ⶼ�ǻ��ڸ�˹ģ�͵�. ��ʱ���������ܲ�������,���Կ���
	//		ͨ����ʵ��ָʾ����������(�Ա�)����������ָʾ����������(���˹ģ��һ��).
	//		ָʾ�������������(bigaus)�������������ָʾ������,����ͨ�����
	//		������ͼ�������.
	//����:	
	//		pVrg[] ---------------> ����(��С=������*�ͺ����*������)
	void GEOSTAT_DLL _gsBigaus(GeoStatObj gsObj, ModIndVrg *pVrg);

	//ģ�͵ı���ͼ���
	//˵��:	�ó������һ��ָ���ͺ��İ����ģ�͵�ֵ. ������дΪһ����"vargplt"
	//		һ�µĸ�ʽ.
	//		����ģ�͵ı����ļ�(vmodel)�������ָ���ͺ��ͷ���ı���ֵ,��ֵ��
	//		ʵ��ֵһ�����(����ͼ),��ͼ������Ϻͼ������ģ��. �û�����ָ�����
	//		����ģ��,�ó���ֻ�Ǽ�����Ƶ�ֵ. ͨ����һ���������ļ���ִ�иó����vargplt
	//		����,�Ա��ڱ���ģ�Ͳ����ı��Ժ���Ƶ�ͼ����������ʾ����.
	//����:	
	//		pVrg[] ---------------> ����(��С=������*(�ͺ����+2))	
	void GEOSTAT_DLL _gsVmodel(GeoStatObj gsObj, ModIndVrg *pVrg);

	// ----------------------- ���ú��� ------------------------ //
	//���ñ�����Ŀ
	//����:	
	//		lVarNum -----------> ������Ŀ
	void GEOSTAT_DLL _gsSetVarNum(GeoStatObj gsObj, long lVarNum=1);	
	
	//���ñ�������
	//����:	
	//		piHeadVar[] --------> �������������ײ�����
	//		piTailVar[] --------> ������������β������
	//		piVrgType[] --------> ��������
	//		pfCutOff[] ---------> ָʾ������
	//		lVrgNum ------------> ������Ŀ
	void GEOSTAT_DLL _gsSetVarPara(GeoStatObj gsObj, 
								   int *piHeadVar=NULL, int *piTailVar=NULL, 
								   int *piVrgType=NULL, double *pfCutOff=NULL, 
								   long lVrgNum=1);
	//����ָʾ������
	//����:	
	//		piIndX[],piIndY[],piIndZ[] ------> ÿ������ȷ���ĵ�λƫ��
	//		lDirNum -------------------------> ������Ŀ
	void GEOSTAT_DLL _gsSetIndPara(GeoStatObj gsObj, 
								   int *piIndX=NULL, int *piIndY=NULL, int *piIndZ=NULL, 
								   long lDirNum=1);
	//�����ͺ����
	//����:	
	//		plLagNum[] ----------> ÿ�������ͺ���Ŀ
	//		pfLag[] -------------> �ͺ�
	//		pfLagTol[] ----------> �ͺ��ݲ�
	//		lDirNum -------------> ������Ŀ
	void GEOSTAT_DLL _gsSetLagPara(GeoStatObj gsObj, 
								   long *plLagNum=NULL, double *pfLag=NULL, double *pfLagTol=NULL, 
								   long lLagParamNum=1);
	//���ñ�׼����־
	//����:	
	//		lSillFlag ----------> ��׼����־(1:��׼��,�����ֵ�����Է���)
	void GEOSTAT_DLL _gsSetSillFlag(GeoStatObj gsObj, long lSillFlag=0);
	//������������Ǻͷ�λ��
	//����:	
	//		pfAzmAng[] ---------> ��λ��
	//		pfAzmTol[] ---------> ��λ�ݲ�
	//		pfAzmBand[] --------> ˮƽ����
	//		pfDipAng[] ---------> ���
	//		pfDipTol[] ---------> ����ݲ�
	//		pfDipBand[] --------> ��ֱ����
	//		lDirNum ------------> ������Ŀ
	void GEOSTAT_DLL _gsSetAzmDip(GeoStatObj gsObj, 
								  double *pfAzmAng=NULL, double *pfAzmTol=NULL, double *pfAzmBand=NULL, 
								  double *pfDipAng=NULL, double *pfDipTol=NULL, double *pfDipBand=NULL, 
								  long lDirNum=1);
	//������������
	//����:	
	//		lDatType --------> ��������(0:����,1:��ɢ)
	void GEOSTAT_DLL _gsSetDataType(GeoStatObj gsObj, long lDatType=0);
	//�������ݶ���Ŀ
	//����:	
	//		lPairNum --------> ���ݶ���
	void GEOSTAT_DLL _gsSetPairNum(GeoStatObj gsObj, long lPairNum=1);

    //////////////////////////lhy�������////////////////////////////////////
    void GEOSTAT_DLL _gsSetMaxMinAzmDip(GeoStatObj gsObj,
									double *pfMAzmAng, double *pfMAzmTol,double *pfMAzmBand,
									double *pfMDipAng, double *pfMDipTol,double *pfMDipBand,
									long lDirNum);
    void GEOSTAT_DLL gsSetMaxMinItype(GeoStatObj gsObj, long *iType);
 /*   void GEOSTAT_DLL _gsLoadVrgC(GeoStatObj gsObj, Variogram *Vrg, long lVrgNum);
    
	
	void GEOSTAT_DLL _gsVarComb(GeoStatObj gsObj, int ivtype,double *c0, double *cc, double *aa_h );

*/
	
	/////////////////////////////////////////////////////////////////////////////









	
	// =========================== ����ͳ��ͼ���� ============================== //
	// ----------------------------- ������ ---------------------------- //
	// ************ ��״ͼ ************** //
	//����:	�������ݵ���״ͼ��һЩͳ����.
	//����:	
	//		ai[] ---------> mapgis������	
	long GEOSTAT_DLL _gsDrawHistPlt(GeoStatObj gsObj);
	
	long GEOSTAT_DLL  _gsOutHistPltParam(GeoStatObj gsObj, 
									 long &lVarDatNum, long &InVarNum,
									 double &fDatMean, double &fStdDev,
									 double &fDatMax, double &xuqt,
									 double &xmed, double &xlqt, double &fDatMin,
									 double *fAttrFreq, double &fMaxFreq);
	// ************** ����ͼ **************** //
	//����:	����һ����̬�Ļ���һ��������̬�ĸ���ͼ.
	//����:	
	//		ai[] ---------> mapgis������
	long GEOSTAT_DLL _gsDrawProbPlt(GeoStatObj gsObj);
    long GEOSTAT_DLL _gsOutPropPltParam(GeoStatObj gsObj, double *fProbDot, GSD_DOT *fPntDot, long &lPntNum);	
	// **************** ɢ��ͼ **************** //
	//����:	����ɢ��ͼ��һЩͳ����.
	//����:	
	//		ai[] ---------> mapgis������
	long GEOSTAT_DLL _gsDrawScatPlt(GeoStatObj gsObj);
	long GEOSTAT_DLL _gsOutScatPltParam(GeoStatObj gsObj, long &slPltPntNum, double &sfRankCorr, double &sfStdDevX,
									double &sfStdDevY, long &slValDatNumX, long &slValDatNumY,
	                                double &sfDatMeanX, double &sfDatMeanY, double &sfCorrCoef);
	// ************** qq-ppͼ ************** //
	//����:	�����ֲ�ͬ�������ļ��л�ȡ��һ������������һ��Q-Qͼ��P-Pͼ.
	//����:	
	//		ai[] ---------> mapgis������
	long GEOSTAT_DLL _gsDrawQpPlt(GeoStatObj gsObj);
    long GEOSTAT_DLL _gsOutQpPltParam(GeoStatObj gsObj, GSD_DOT *pfQp, long &lValQpNum);	

	// ----------------------------- �Ӻ��� ---------------------------- //
	// ******* ������״ͼ ******* //
	//����Ƶ�����ֵ
	//����:
	//		fFreqExtr ----------> ���Ƶ��(<0������Զ������ֵ)
	long GEOSTAT_DLL _gsSetFreqExtr(GeoStatObj gsObj, double fFreqExtr);
	//����Ƶ�ʻ��ۻ�Ƶ����״ͼ
	//����:	
	//		lCumFlag ---------> ������״ͼ��־(0:Ƶ����״ͼ1:�ۻ���״ͼ)
	long GEOSTAT_DLL _gsSetCumHistFlag(GeoStatObj gsObj, long lCumFlag=0);
	//����С��λ��
	//����:	
	//		lDecNum --------> С��λ��
	long GEOSTAT_DLL _gsSetDecNum(GeoStatObj gsObj, long lDecNum=0);
	//�����漰������ֵ
	//����:	
	//		fRefVal -------> ����״ͼ������Ϊ��ʾͼ��Ĳο���ֵ.�����ֵ�����ݼ�����,
	//						 ����״ͼ��ˮƽ��x���ϵı�Ƚ�������,����ʾһ��ͼ��.
	long GEOSTAT_DLL _gsSetRefVal(GeoStatObj gsObj, double fRefVal=-1);

	// ******* ���Ƹ���ͼ ******* //
	//���ø���ͼ��ʾ����
	//����:	
	//		lPltPntNum ---------> ��ʾ����
	long GEOSTAT_DLL _gsSetProbPntNum(GeoStatObj gsObj, long lPltPntNum=1);
	//���ø���
	//����;	
	//		pfProbValue[] -------> ����
	//		lProbNum ------------> ������Ŀ
	long GEOSTAT_DLL _gsSetProbValue(GeoStatObj gsObj, 
									 double *pfProbValue=NULL, long lProbNum=0);
	
	// ******* ����ɢ��ͼ ******* //	
	//����ÿ����Ӽ���Ŀ
	//����:	
	//		lSubNum ----------> �Ӽ���Ŀ
	long GEOSTAT_DLL _gsSetSubNum(GeoStatObj gsObj, long lSubNum=1);
	//���õ��С
	//����:	
	//		fBullSize --------> ���С
	long GEOSTAT_DLL _gsSetBullSize(GeoStatObj gsObj, double fBullSize=0);

	// ******* ����qq-ppͼ ******* //
	//����qq��ppͼ���Ʊ�־
	//����:
	//		lQpFlag ---------> ����qq��ppͼ��־(0:qq,1:pp)
	long GEOSTAT_DLL _gsSetQqPpFlag(GeoStatObj gsObj, long lQpFlag=0);

	// ******* ���Ʊ���ͼ ******* //
	//װ�����ֵ
	//����:	
	//		pVrg[] ----------> ����ֵ
	//		lVrgNum ---------> ������Ŀ
	void GEOSTAT_DLL _gsLoadVrg(GeoStatObj gsObj, Variogram *pVrg=NULL, long lVrgNum=0);


	// ---------------------------- ���ú��� ----------------------------- //
	//װ������
	//����:	
	//		pDiscPnts[] -----> �����
	//		lXDatNum --------> x����������
	//		lYDatNum --------> y����������
	long GEOSTAT_DLL _gsLoadGridPnts(GeoStatObj gsObj,
									 GsDiscPnt *pDiscPnts,
									 long lXDatNum=1, long lYDatNum=1);
	//���ô���ʵ�ʷ�Χ
	//����:	
	//		fPractMinX -----------> x���򴰿�ʵ����Сֵ 
	//		fPractMinY -----------> y���򴰿�ʵ����Сֵ
	//		fPractMaxX -----------> x���򴰿�ʵ�����ֵ
	//		fPractMaxY -----------> y���򴰿�ʵ�����ֵ
	long GEOSTAT_DLL _gsSetPractWindow(GeoStatObj gsObj, 
									   double fPractMinX, double fPractMinY, 
									   double fPractMaxX, double fPractMaxY);
	//�����������۷�Χ
	//����:	
	//		fThoryMinX -----------> x�����������Сֵ
	//		fThoryMinY -----------> y�����������Сֵ
	//		fThoryMaxX -----------> x������������ֵ
	//		fThoryMaxY -----------> y������������ֵ
	long GEOSTAT_DLL _gsSetThoryData(GeoStatObj gsObj, 
									 double fThoryMinX, double fThoryMinY, 
									 double fThoryMaxX, double fThoryMaxY);	
	//�������ű���
	//����:	
	//		fScale ---------> ���ű���
	long GEOSTAT_DLL _gsSetScale(GeoStatObj gsObj, double fScale=1);	
	//����ͼ��ɫ�ʱ�־(��ɫ/�Ҷ�)
	//����:	
	//		bIsClrMap ---------> ɫ������(0:�Ҷ�,1:��ɫ)
	void GEOSTAT_DLL _gsSetMapColorStyle(GeoStatObj gsObj, bool bIsClrMap=1);
	//�������Ե�ע�ǻ��Ʊ�־
	//����:	
	//		bDrawDotLabel -------> �Ƿ�������Ե�(0:������,1:����)
	void GEOSTAT_DLL _gsSetMapLabelFlag(GeoStatObj gsObj, bool bDrawDotLabel=0);	
	//�Ƿ�ʹ�ø�������
	//����:	
	//		lUseSecFlag ---------> ʹ�ø������Ա�־(0:��ʹ��,1:ʹ��)
	//		lDatFlag ------------> ���ݱ�־(1:����1,2:����2)
	long GEOSTAT_DLL _gsSetUseSecAttrFlag(GeoStatObj gsObj, 
										  long lUseSecFlag=0, long lDatFlag=1);


	// =============================== �������� ================================= //
	// --------------------------------  ������ -------------------------------- //
	//��ά������
	//����:	�Ը�����������в�ֵ����Ը����ĵ���й�ֵ��
	//����:	
	//		pdOutAttt[] --------------> ��ֵ(��ֵ)������
	//		pdOutVari[] --------------> ��ֵ(��ֵ)�㷽��
	//		lOutPntNum ---------------> ��ֵ(��ֵ)����
	long GEOSTAT_DLL _gsKrig2D(GeoStatObj gsObj, 
							   double *pdOutAttr, long lOutPntNum, double *pdOutVari=NULL);

	//��ά������
	//����:	
	//		pdOutAttt[] --------------> ��ֵ(��ֵ)������
	//		pdOutVari[] --------------> ��ֵ(��ֵ)�㷽��
	//		lOutPntNum ---------------> ��ֵ(��ֵ)����
	//      plPntNum[] ---------------> ��ֵ���õ���
	//      pfMeanDis[] --------------> ��ֵ�㵽������ľ���
	//      plEngNum[] ---------------> ��ֵ���ù�����
	long GEOSTAT_DLL _gsKrig3D(GeoStatObj gsObj, 
							   double *pdOutAttr, long lOutPntNum, double *pdOutVari=NULL, long *plPntNum=NULL, 
							   double *pfMeanDis=NULL, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL);
	long GEOSTAT_DLL _gsKrig3D1(GeoStatObj gsObj, 
		double *pdOutAttr, long lOutPntNum, double *pdOutVari=NULL, long *plPntNum=NULL, double *pfMeanDis=NULL);
	//��ά������
	//pEstabPnts[] ----------> ��ֵ��ĵ�
	long GEOSTAT_DLL _gsKrig3D2(GeoStatObj gsObj, 
								EstabPnt *pEstabPnts, long lOutPntNum);

	//��ά�����(���������������е��ֵ(���ټ���))
	//		pdOutAttt[] --------------> ��ֵ(��ֵ)������
	//		lOutPntNum ---------------> ��ֵ(��ֵ)����
	long GEOSTAT_DLL _gsKrig3DSimp(GeoStatObj gsObj, 
		                           double *pdOutAttr, long lOutPntNum);

	//��ά���뷴��
	//����:
	//       pdOutAttr[] -------------> ��ֵ(��ֵ)������
	//       lOutPntNum --------------> ��ֵ(��ֵ)����
	//       plPntNum[] --------------> ��ֵ���õ���
	//       pfMeanDis[] -------------> ��ֵ�㵽������ľ���
	//       plEngNum[] --------------> ��ֵ���ù�����
	long GEOSTAT_DLL _gsInverse3D(GeoStatObj gsObj, 
							   double *pdOutAttr, long lOutPntNum, long *plPntNum = NULL, 
							   double *pfMeanDis = NULL, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL);
	long GEOSTAT_DLL _gsInverse3D1(GeoStatObj gsObj, 
		double *pdOutAttr, long lOutPntNum, long *plPntNum = NULL, 
		double *pfMeanDis = NULL);
	//��ά���뷴��
	//pEstabPnts[] ----------> ��ֵ��ĵ�
    long GEOSTAT_DLL _gsInverse3D2(GeoStatObj gsObj, 
								EstabPnt *pEstabPnts, long lOutPntNum);

	//��ά���뷴��(���������������е��ֵ(���ټ���))
	//		pdOutAttt[] --------------> ��ֵ(��ֵ)������
	//		lOutPntNum ---------------> ��ֵ(��ֵ)����
	long GEOSTAT_DLL _gsInverse3DSimp(GeoStatObj gsObj, 
		                           double *pdOutAttr, long lOutPntNum);

	//Э������
	//����:	
	//		pdOutAttt[] --------------> ��ֵ(��ֵ)������
	//		pdOutVari[] --------------> ��ֵ(��ֵ)�㷽��
	//		lOutPntNum ---------------> ��ֵ(��ֵ)����
	long GEOSTAT_DLL _gsCoKrig(GeoStatObj gsObj, 
							   double *pdOutAttr, long lOutPntNum, double *pdOutVari=NULL);
	
	//ָʾ��������
	//����:	
	//		pfIkCcdf[] ---------------> ָʾ��ֵ
	//		lIkCcdfNum ---------------> ָʾ��ֵ��Ŀ(������Ŀ*��ֵ��Ŀ)
	//      plPntNum[] ---------------> ��ֵ���õ���
	//      pfMeanDis[] --------------> ��ֵ�㵽������ľ���
	//      plEngNum[] ---------------> ��ֵ���ù�����
	long GEOSTAT_DLL _gsIkring(GeoStatObj gsObj, double *pfIkCcdf, long lIkCcdfNum,long *plPntNum = NULL, 
		                       double *pfMeanDis = NULL, long lEngTypeNum=0, KrigEngNumInfo *pKrigEngNum=NULL);

	//----------------------------------lhy���----------------------------------//
	//��������Ʒ����
	//����
	//      pSrchNum[] ---------------> ��Ʒ����
    long GEOSTAT_DLL _gsSrchData(GeoStatObj gsObj, double fScaleR, int *pSrchNum);
    
	//ָʾ���������
	//����:
	//      pfOutVal[] ---------------> ������
	long GEOSTAT_DLL _gsPostIk(GeoStatObj gsObj, double *pfOutVal, double *pfOutVari);
	//------------------------------------end------------------------------------//

	// -------------------------lhy���ָʾ�������Ӻ��� -------------------------//
    long GEOSTAT_DLL _gsLoadPostIkPnt(GeoStatObj gsObj, double *pfIkCcdf, long lIkCcdfNum);
	long GEOSTAT_DLL _gsSetPostIkExtr(GeoStatObj gsObj, int ivr, int iwt, double fExtrMin, double fExtrMax);
	long GEOSTAT_DLL _gsSetOutOption(GeoStatObj gsObj, int iOut, double fOutPar);
	long GEOSTAT_DLL _gsSetPostIkCutOff(GeoStatObj gsObj, double *pfCutOff, long lCutOffNum);
	long GEOSTAT_DLL _gsSetIsConsiderVol(GeoStatObj gsObj, int iVol);
	long GEOSTAT_DLL _gsSetPostIkType(GeoStatObj gsObj, int ivtyp);
	long GEOSTAT_DLL _gsSetVariFactor(GeoStatObj gsObj, double fVarred);
	long GEOSTAT_DLL _gsSetExtrZVal(GeoStatObj gsObj, double fZMin, double fZMax);
	long GEOSTAT_DLL _gsSetMaxDis(GeoStatObj gsObj, int iMaxDis);
	
    // -----------------------------------end------------------------------------//
	// --------------------------- ����������Ӻ��� ---------------------------- //	
	// ************* Э������ ************** //
	//���þֲ��仯ƽ��ֵ��ر�־
	//����:	
	//		lLvmFlag ----------> ʹ�þֲ��仯ƽ��ֵ��־(0:��ʹ��,1:ʹ��)
	void GEOSTAT_DLL _gsSetLvmFlag(GeoStatObj gsObj, long lLvmFlag);
	//���ø���������������
	//����:	
	//		iMaxSrchNum ----------> �������������������
	//		fSrchRadius ----------> ��������(��������)�����뾶
	//		fSrchRadius1 ---------> ��������(�������)�����뾶
	//		fSrchRadius2 ---------> ��������(���������)�����뾶
	long GEOSTAT_DLL _gsSetSecSrchPara(GeoStatObj gsObj, 
									   int iMaxSrchNum=0, double fSrchRadius=-1, 
									   double fSrchRadius1=-1, double fSrchRadius2=-1);
	//����ģ������
	//����:	
	//		iModelType --------> ģ������(1:MM1,2:MM2,3:LMC)
	long GEOSTAT_DLL _gsSetModelType(GeoStatObj gsObj, int iModelType=1);
	//�������ϵ��
	//����:	
	//		fColoCorr --------> ���ϵ��(for MM1,MM2)
	long GEOSTAT_DLL _gsSetColoCorr(GeoStatObj gsObj, double fColoCorr);

	// ************* ָʾ�������� ************//
	//������ֵ
	//����:	
	//		iIkMeanFlag ---------> ��ֵ
	//lhy��
	//long GEOSTAT_DLL _gsSetMeanThres(GeoStatObj gsObj, int iIkMeanFlag);
	//��Ϊ
	long GEOSTAT_DLL _gsSetMeanThres(GeoStatObj gsObj, int iIkMeanFlag, double cutmean);
	//����������
	//����:	
	//		lUseSoftFlag ----------> �Ƿ�ʹ��������(0:��ʹ��,1:ʹ��)
	//		pSoftPnts[] -----------> ������
	long GEOSTAT_DLL _gsSetSoftData(GeoStatObj gsObj, 
									long lUseSoftFlag, GsDiscPnt *pSoftPnts);


	// ----------------------------- ���ú��� ------------------------------ //	
	//�������۱�������(��������)
	//����:	
	//		fC0[] --------> �����ЧӦ(��СΪ3,��ͬ)
	//		fC[] ---------> ����
	//		fA[] ---------> ���
	long GEOSTAT_DLL _gsCalVrgParaAll(GeoStatObj gsObj, 
									  double *fC0, double *fC, double *fA);

	//�������۱�������(ĳһ����)
	//����:
	//����:
	//		fAzmAng --------------> ��λ��
	//		fAzmTol --------------> ��λ�ݲ�
	//		fAzmBand -------------> ˮƽ����
	//		fDipAng --------------> ���
	//		fDipTol --------------> ��б�ݲ�
	//		fDipBand -------------> ��ֱ����
	//		fLag -----------------> �ͺ��
	//		fLagTol --------------> �ͺ��ݲ�
	//		lLagNum --------------> �ͺ���Ŀ
	//���:	
	//		pfGodNugC0 -----------> �����
	//		pfArchC --------------> ����
	//		pfChgRangA -----------> ���
	long GEOSTAT_DLL _gsCalVrgParaDir(GeoStatObj gsObj, 
								      double fAzmAng, double fAzmTol, double fAzmBand, 
									  double fDipAng, double fDipTol, double fDipBand, 
									  double fLag, double flagTol, long lLagNum, 
									  double *pfGodNugC0, double *pfArchC, double *pfChgRangA);


	//����ʵ�����(ĳ������)
	//		fAzmAng --------------> ��λ��
	//		fAzmTol --------------> ��λ�ݲ�
	//		fAzmBand -------------> ˮƽ����
	//		fDipAng --------------> ���
	//		fDipTol --------------> ��б�ݲ�
	//		fDipBand -------------> ��ֱ����
	//		fLag -----------------> �ͺ��
	//		fLagTol --------------> �ͺ��ݲ�
	//		lLagNum --------------> �ͺ���Ŀ
	//		fVrg[] ---------------> �������ֵ(��СΪ�ͺ���Ŀ,��ͬ)
	//		lPntCoupNum[] --------> �����
	//		fDist[] --------------> �ͺ�
	long GEOSTAT_DLL _gsCalExpVrgDir(GeoStatObj gsObj, 
									 double fAzmAng, double fAzmTol, double fAzmBand, 
									 double fDipAng, double fDipTol, double fDipBand, 
									 double fLag, double flagTol, long *lLagNum, 
									 double *fVrg, long *lPntCoupNum, double *fDist);

	//������������
	//����:	
	//		pSrchPara ---------> ��������
	long GEOSTAT_DLL _gsSetSrchPara2(GeoStatObj gsObj, Kt3dSrch *pSrchPara);	
	//�����������
	//����:	
	//		pGridPara ---------> �������
	long GEOSTAT_DLL _gsSetGridPara2(GeoStatObj gsObj, GsGrid *pGridPara);
	//���ò�ֵ����
	//����:	
	//		pIntpPara[] ---------> ��ֵ����
	//		lIntpNum ------------> ������Ŀ
	long GEOSTAT_DLL _gsSetIntpPara2(GeoStatObj gsObj, 
									 Kt3dIntp *pIntpPara, long lIntpNum=1);	
	//���ÿ�����ѡ��
	//����:	
	//		iKrigOption -------> ������ѡ��(0:grid,1:cross,2:jackknife)
	long GEOSTAT_DLL _gsSetKrigOption(GeoStatObj gsObj, long lKrigOption=0);
	//���ü򵥿�����ƽ��ֵ
	//����:	
	//		fSkMean -------> ����ƽ��ֵ
	long GEOSTAT_DLL _gsSetSkMean(GeoStatObj gsObj, double fSkMean=0);

	//����Э������ƽ��ֵ
	//������
	//     pfSkMean -----------> �������ƽ��ֵ
	//     lSkMeanNum ---------> ƽ��ֵ����
	//�޸����ڣ�2008��9��11
    long GEOSTAT_DLL _gsSetCoKMean(GeoStatObj gsObj, double *pfSkMean, long lSkMeanNum);

	//���ù��Ʋ���
	//����:	
	//		iTrend ----------> ���Ʋ���(�������Ի�����)
	long GEOSTAT_DLL _gsSetTrend(GeoStatObj gsObj, long lTrend=0);
	//����Krig����
	//����:	
	//		lKrigType ---------> ����������(0:�򵥿�����,1:��ͨ������, 
	//										2:��ͳ�Ƽ򵥿�����,3:��Ư�ƵĿ�����)
	void GEOSTAT_DLL _gsSetKrigType(GeoStatObj gsObj, long lKrigType=0);
	//����Ư�Ƽ���
	//����:	
	//		iDrifTerm[] -----------> Ư�Ƽ���(��СΪ9)
	long GEOSTAT_DLL _gsSetDrifTerm(GeoStatObj gsObj, int *iDrifTerm=NULL);
	//�������ݱ任��ʽ
	//������
	//      
	long GEOSTAT_DLL _gsSetDataTran(GeoStatObj gsObj, int iTranMethod=0);
	
	//���ù�ֵ��־
	//����:	
	//		lEstFlag -----------> ���Ʊ�־(0:�����ֵ,1:�����ֵ)
	long GEOSTAT_DLL _gsSetEstFlag(GeoStatObj gsObj, long lEstFlag);
	//װ�����ֵ�ĵ�
	//����:	
	//		pEstPnt ----------> �����Ƶ�
	long GEOSTAT_DLL _gsLoadEstPnt(GeoStatObj gsObj, GsDiscPnt *pEstPnt, long lEstPntNum);



	// ============================== ����ģ�� ============================= //
	// ---------------------------- ������ ---------------------------- //
	//˳��ָʾģ��
	void GEOSTAT_DLL _gsSisim(GeoStatObj gsObj, double *pfSimValue=NULL);
	

	// ----------------- ���ú��� ------------------ //
	//����ѭ�����н���������(number of simulated nodes to use)
	void GEOSTAT_DLL _gsSetNodMax(GeoStatObj gsObj, int nNodMax, int iFlag=1);
	//������������
	void GEOSTAT_DLL _gsSetSearchStrategy(GeoStatObj gsObj, int nSearchstr);
	//���ö�������������־(multiple grid search flag)
	void GEOSTAT_DLL _gsSetMSearchFlag(GeoStatObj gsObj, long lNum, long lVal);
	//��������Э�����𿪹�(median IK switch)
	//	lMikFlag ---------> ����(0:full IK;1:median approx)
	//	fCutMik ----------> ��ֵ
	void GEOSTAT_DLL _gsSetMedianIkSwitch(GeoStatObj gsObj, long lMikFlag, double fCutMik);

	// ----------------- �Ӻ���-------------- //
	// ************ ��˹ģ�� ************* //
	//�������ݱ任��־
	//����:	
	//		bTrans ---------> ���ݱ任��־(0:���任,1:�任)
	void GEOSTAT_DLL _gsSetTransFlag(GeoStatObj gsObj, BOOL bTrans=0);
	//�������ݹ⻬��־
	//����:	
	//		bSmoothFlag --------> �⻬��־(0:�⻬,1:���⻬)
	void GEOSTAT_DLL _gsSetSmoothMark(GeoStatObj gsObj, BOOL bSmoothFlag=0);

	// *********************** Sisim *********************** //
	//Set Markov-Bayes simulation
	//������ɷ�-��Ҷ˹ģ��ֵ
	void GEOSTAT_DLL _gsSetMakovBayes(GeoStatObj gsObj, int iMakovBayes);
	//set calibration B(z) values
	//���ñ�׼bֵ
	void GEOSTAT_DLL _gsSetBeezValue(GeoStatObj gsObj, double *fBeezValue);
	//set size of covariance lookup
	//����Щ����������Χ
	void GEOSTAT_DLL _gsSetCovarSize(GeoStatObj gsObj, int mxctx, int mxcty, int mxctz);

	// *********************** Sgsim *********************** //
	//��˹ģ��
	void GEOSTAT_DLL _gsSgsim(GeoStatObj gsObj, double *pfSimValue);
	//set min and max original data for sim
	//���ò���ģ���ԭʼ���ݵ������С����
	void GEOSTAT_DLL _gsSetMinMaxOrigData(GeoStatObj gsObj, int iMinData, int iMaxData);

	
	// ************************* Ellipsim ************************** //
	//������Ĳ���ģ��
	void GEOSTAT_DLL _gsEllipSim(GeoStatObj gsObj, double *pfSimValue);

	//����Ŀ�����
	void GEOSTAT_DLL _gsSetTargProp(GeoStatObj gsObj, double dTargProp);

	//�����������һЩ����(�뾶,�Ƕ�,Ȩֵ)
	void GEOSTAT_DLL _gsSetEllipParam(GeoStatObj gsObj, 
								      double *pfRadius, double *pfRadius1, double *pfRadius2, 
								      double *pfAng1, double *pfAng2, double *pfAng3, 
								      double *pfWeight, int iEllipNum);

	

	// ******************************** Anneal ********************************* //
	//�˻�ģ��
	//����:	pfSimVal[] ------------> ģ��ֵ(�����СΪnsim*nx*ny*nz)
	void GEOSTAT_DLL _gsAnneal(GeoStatObj gsObj, double *pfSimVal);

	//װ������ͼ������(Load Input Imag Data)
	//����:	pfInputData[] ----------> file with input image(�����СΪiDataNum,
	//														�ļ���Ϊsisim.out)
	//		iDataNum ---------------> ������Ŀ
	void GEOSTAT_DLL _gsLoadInputImag(GeoStatObj gsObj, 
									  double *pfInputData, int iDataNum);

	//װ��ѵ��ͼ������(Load Training Imag Data)
	//����:	pfTrainData[] ---------> file with training image(�����СΪiDataNum,
	//														�ļ���Ϊellipsim.out)
	//		iDataNum ---------------> ������Ŀ
	void GEOSTAT_DLL _gsLoadTrainImag(GeoStatObj gsObj, 
									  double *pfTrainData, int iDataNum);

	//���ñ�����(set report interval)
	//	fReport ----------> ��������Ŀ(after ``report'' loops the image 
	//									 is written to the output file)
	void GEOSTAT_DLL _gsSetReportInterv(GeoStatObj gsObj, double fReport);

	//����������Ŀ(set number of grid)
	//grid size for the input realizations and training image
	void GEOSTAT_DLL _gsSetGridNum(GeoStatObj gsObj, 
								   int iGridNumX, int iGridNumY, int iGridNumZ);

	//�������ķ�����Ŀ(set maximum iterations)
	//	iMaxIterat ----------> ���ķ�����Ŀ(maximum number of iterations over all nodes)
	void GEOSTAT_DLL _gsSetMaxIterat(GeoStatObj gsObj, int iMaxIterat);

	//�����ݲ�(set tolerance)
	//	fObjTol ------------> �ݲ�(tolerance for the objective function)
	void GEOSTAT_DLL _gsSetObjTol(GeoStatObj gsObj, double fObjTol);

	//����ÿ�������ƫ�������ͺ���Ŀ(set offsets and lags for each direction)
	//	iOffsetX[] -------------> ƫ����(�����СΪiDirNum)
	//	iLags[] ----------------> �ͺ���Ŀ(�����СΪiDirNum)
	//	iDirNum ----------------> the number of directions to consider for the two-point 
	//							  histogram control
	void GEOSTAT_DLL _gsSetOffsetLag(GeoStatObj gsObj, 
									 int *iOffsetX, int *iOffsetY, int *iOffsetZ, 
									 int *iLags, int iDirNum);

	// ********************* draw ************************** //
	//�����ģ��
	//	pfSimVal[] --------> �����Ƶ�ģ���(�����СΪiDrawNum*iKeepColNum)
	void GEOSTAT_DLL _gsDraw(GeoStatObj gsObj, double *pfSimVal);

	//���ñ������к�(set variables to keep)
	//	iKeepColNo[] -----------> ��Ҫ������ļ��б�������������ɢ��ṹ�е����(�����СΪiKeepColNum)
	//	iKeepColNum ------------> ��������Ŀ
	void GEOSTAT_DLL _gsSetKeepVarNum(GeoStatObj gsObj, int *iKeepColNo, int iKeepColNum);

	//���ø��ʵ��к�(set column for probability,��������ɢ��ṹ�е����,1~9)
	void GEOSTAT_DLL _gsSetProbColNo(GeoStatObj gsObj, int iProbColNo);

	//���û��Ƶĵ���(number to draw)
	void GEOSTAT_DLL _gsSetDrawNum(GeoStatObj gsObj, int iDrawNum);

	// ******************* lusim ************************** //
	//��ά�������������ģ��
	//Conditional Simulation of a 3-D Rectangular Grid
	//	pfSimVal[] -----------> ģ��ֵ(�����Сnsim*nx*ny*nz)
	void GEOSTAT_DLL _gsLusim(GeoStatObj gsObj, double *pfSimVal);

	//���ñ������к�(�����СΪiVarNum)
	//	iVarColNos[] --------> ��������ɢ��ṹ�е����(�����СΪiVarNum)
	//	iVarNum -------------> ������Ŀ
	//	lDataFlag -----------> ���ݱ�־(1:var;2:cdf;3:hist;4:pair)
	void GEOSTAT_DLL _gsSetVarColNo(GeoStatObj gsObj, int *iVarColNos, int iVarNum, 
									long lDataFlag=1);

	// ***************** gtsim ***************** //
	//��˹ȥ��ģ��(Gaussian Truncated Simulation)
	//	pfSimVal[] -----------> ģ��ֵ(�����Сnsim*nx*ny*nz)
	void GEOSTAT_DLL _gsGtsim(GeoStatObj gsObj, double *pfSimVal);

	//�������(set categories)
	//	iCatNum -----------> �����Ŀ
	//	fCat[] ------------> ���(�����СΪiCatNum)
	//	fGlobProp[] -------> ȫ�ֱ���(�����СΪiCatNum)
	void GEOSTAT_DLL _gsSetCat(GeoStatObj gsObj, 
							   int iCatNum, double *fCat, double *fGlobProp);

	//����ʹ�þֲ������ļ���־(set proportion curves)
	//bPropCurv ----------> �Ƿ�ʹ�þֲ������ļ�(whether to use the local proportion curve files)
	void GEOSTAT_DLL _gsSetPropCurv(GeoStatObj gsObj, bool bPropCurv);

	//װ���˹ʵ������(load sgsim realizations)
	//	pfSgsimReal[] -------> ��˹ʵ������(file with input Gaussian realizations,
	//										�����СΪiRealNum)
	//	iRealNum ------------> ��˹ʵ�����ݵ���Ŀ
	void GEOSTAT_DLL _gsLoadSgsimReal(GeoStatObj gsObj, 
									  double *pfSgsimReal, int iRealNum);
	//װ��ֲ���������(load local proportion)
	//	pblocalpropflag[] ------> ʹ�þֲ������ļ��ı�־(�����СΪ3. 0:ʹ��,1:��ʹ��)
	//	pfLocalProp01[] --------> �ֲ������ļ�����(�����СΪiPropNum)
	//	iPropNum ---------------> �ֲ������ļ����ݵ���Ŀ
	void GEOSTAT_DLL _gsLoadLocalProp(GeoStatObj gsObj, 
									  bool pbLocalPropFlag[3], 
									  double *pfLocalProp01, 
									  double *pfLocalProp02, 
									  double *pfLocalProp03, 
									  int iPropNum);

	// ********************** pfsim ******************** //
	//�����ֳ�����(Probability Field Simulation)
	//	pfSimVal[] -----------> ģ��ֵ(�����Сnsim*nx*ny*nz)
	void GEOSTAT_DLL _gsPfsim(GeoStatObj gsObj, double *pfSimVal);
	//set cdf type
	//	iCdfType ----------> �ۻ��ֲ���������
	void GEOSTAT_DLL _gsSetCdfType(GeoStatObj gsObj, int iCdfType);

	//���ø�˹��־(0=Gaussian, 1=uniform)
	void GEOSTAT_DLL _gsSetGausFlag(GeoStatObj gsObj, int iGausFlag=0);

	// ********************* sasim ********************** //
	//�����˻��ģ��(Annealing-Based Simulation)
	//	pfSimVal[] -----------> ģ��ֵ(�����Сnsim*nx*ny*nz)
	//	pfSecVar[] -----------> �ڶ�������ֵ(�����Сnsim*nx*ny*nz)
	//	pfVertAvg[] ----------> ��ֱƽ��(vertically averaged output, �����Сnsim*nx*ny*nz)
	void GEOSTAT_DLL _gsSasim(GeoStatObj gsObj, double *pfSimVal, 
							  double *pfSecVar=NULL, double *pfVertAvg=NULL);

	//����Ŀ�꺯�����(set objective function components)
	//	fObjHist ----------> Considering a histogram
	//	fObjVarg ----------> Considering a variogram
	//	fObjIvar ----------> Considering indicator variogram
	//	fObjCorr ----------> Considering a correlation coefficient
	//	fObjCpdf ----------> Considering conditional distributions
	//	iObjFlag ----------> Ŀ�꺯����־(0:The objective function components;
	//									  1:user scaling factor)
	void GEOSTAT_DLL _gsSetObjComp(GeoStatObj gsObj, 
								   double fObjHist, double fObjVarg, double fObjIvar, 
								   double fObjCorr, double fObjCpdf, int iObjFlag=0);

	//���ñ��뼶��(set debug level)
	void GEOSTAT_DLL _gsSetDebugLevel(GeoStatObj gsObj, int iDebugLevel=0);

	//�����Զ����ȱ�־(set automatic schedule)
	//	iSchedFlag ---------> �Զ����ȱ�־(0:automatic,1:set below)
	void GEOSTAT_DLL _gsSetSchedFlag(GeoStatObj gsObj, int iSchedFlag=0);

	//�û����ý���(user set schedule)
	void GEOSTAT_DLL _gsSetAutoSched(GeoStatObj gsObj, 
									 double fT0, double fRedfac, int iKasas, 
									 int iKsas, int iNum, double fOmin);

	//���������Ŷ���Ŀ(maximum number of perturbations)
	void GEOSTAT_DLL _gsSetMaxPert(GeoStatObj gsObj, int iMaxPertNum);

	//���ò���������Ŀ(set maximum without a change)
	void GEOSTAT_DLL _gsSetMaxChange(GeoStatObj gsObj, int iMaxChange);

	//�����Ƿ��������ֲ���־(set consider conditioning)
	//	iCondFlag ----------> �Ƿ��������ֲ�(0:������;1:����)
	void GEOSTAT_DLL _gsSetCondFlag(GeoStatObj gsObj, int iCondFlag=0);

	//�����Ƿ�����״ͼ�ֲ���־(set consider file with distribution)
	//	iHistFlag ---------> �Ƿ�����״ͼ�ֲ�(0:������;1:����)
	void GEOSTAT_DLL _gsSetHistFlag(GeoStatObj gsObj, int iHistFlag=0);

	//�����Ƿ�Ӧ�ô�ֱ�ֲ�ƽ��ֵ��־(applies to a vertical average)
	//	bVertAvgFlag ---------> �Ƿ�Ӧ�ô�ֱƽ��ֵ(0:��Ӧ��;1:Ӧ��)
	void GEOSTAT_DLL _gsSetVertAvgFlag(GeoStatObj gsObj, bool bVertAvgFlag=0);

	//�������ϵ��(correlation coefficient)
	//	fCorrCoef -----------> ���ϵ��
	void GEOSTAT_DLL _gsSetCorrCoef(GeoStatObj gsObj, double fCorrCoef);

	//������ֵ��־(set number of cutoffs)
	//	iCutFlag -----------> ��ֵ��־(1:pricut,2:seccut)
	void GEOSTAT_DLL _gsSetCutNum(GeoStatObj gsObj, int iCutNum, int iCutFlag=1);

	//�����ͺ����Ŀ(set number of lags)
	//	iLagNum -----------> �ͺ���Ŀ
	void GEOSTAT_DLL _gsSetLagNum(GeoStatObj gsObj, int iLagNum);

	//set Indicator variogram information
	//����ָʾ��������Ϣ
	//	iFlag ---------> ��ֵ������־(1:ָʾ��������;2:һ�������)
	void GEOSTAT_DLL _gsSetIndVargInfo(GeoStatObj gsObj, int iMaxNstNum, 
									   int *piStrNum, double *pfNugConst, 
									   double *pfArchValue, int *piModelType, 
									   double *pfChgRang, double *pfChgRang1, double *pfChgRang2, 
									   double *pfAnisAng1, double *pfAnisAng2, double *pfAnisAng3, 
									   int iFlag=1);

	//���ߺ���
	//��ʽ�������״ģ�͵ı���
	int GEOSTAT_DLL FitSphVargFormula(const Variogram *Variog, const double *weight, const int iLagNum,  double *fC0, double *fC, double *fA);
	void GEOSTAT_DLL GetAver(Variogram *pfGam, int iLagNum,  double *pfAver);
	void GEOSTAT_DLL GetVari(Variogram *pfGam, int iLagNum, double fAver, double *pfVari);

	//ֱ�ӷ������״ģ�ͱ���
	int GEOSTAT_DLL FitSphVargDirect(const Variogram *Variog, const int iLagNum, double fVari, double *fC0, double *fC, double *fA);

	//�ö���ʽ�ع��㷨���ָ��ģ��
	int GEOSTAT_DLL FitExpVarg(const Variogram *Variog, const double *weight, const int iLagNum, double *fC0, double *fC, double *fA);
	//�ö���ʽ�ع��㷨��ϸ�˹ģ��
	int GEOSTAT_DLL FitGaussVarg(const Variogram *Variog, const double *weight, const int iLagNum, double *fC0, double *fC, double *fA);
	//�����ģ��
	int GEOSTAT_DLL FitPowVarg(const Variogram *Variog, const double *weight, const int iLagNum, double *fC0, double *fC, double *fA );
	//�������ģ��
	int GEOSTAT_DLL FitLinearVarg(const Variogram *Variog, const double *weight, const int iLagNum, double *fC0, double *fC, double *fA );

	int GEOSTAT_DLL Fit_Regress_AddWeight(int N, int P, double **matLeft,double *matRight,  double *w, double *pb,double *pyfit, int b0_has);
	int GEOSTAT_DLL Fit_GaussAxb(double *a, double *b, int n);	
    
	//��������㷨
	long GEOSTAT_DLL pofitho(double *dx,//�Ա���
		                	 double *dy,//����ֵ
			                 double *b,//��ϵó��Ķ���ʽϵ��
			                 long m,   //��������Ŀ
			                 long n);   //����ʽά��
	//�����λֵ
	double GEOSTAT_DLL CalEachQuan(double *pattr, long lpntNum, double fValue);

#ifdef __cplusplus
 }
#endif

#ifndef _CGEO_STAT_LIB
	#ifdef _DEBUG
		#pragma comment(lib, "GeoStatLibD.lib")
	#else
		#pragma comment(lib, "GeoStatLib.lib")
	#endif
#endif

//#pragma pack(pop)

#endif //_GEOSTAT_LIB_H