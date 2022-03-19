#ifndef _BASE_STATISTIC_QTY_EXP_H
#define _BASE_STATISTIC_QTY_EXP_H

#ifndef _BASE_STATISTIC_QTY_LIB
#define _BASE_STATISTIC_QTY_DLL __declspec(dllimport)
#else
#define _BASE_STATISTIC_QTY_DLL __declspec(dllexport)
#endif


#define MIN_DOUBLE_STAT (-1.79769313486232E+307)
#define MAX_DOUBLE_STAT (+1.79769313486232E+307)
#define DEFAULT_MIN_VALUE	-999 //�����ȱʡ��Сֵ
#define DEFAULT_MAX_VALUE	999  //�����ȱʡ���ֵ

typedef struct 
{
	double	dData;
	long	lDataID;
}ORDER_DATA;

typedef struct
{
	ORDER_DATA	*pOrderData;
	long	lDataNum;
}ORDER_STRU;



class _BASE_STATISTIC_QTY_DLL CBaseStatisticQty
{
public:
	CBaseStatisticQty(double *pdStatData, long lDataNum);
	~CBaseStatisticQty();

public:
	// **********************************��������**************************** //
	// ������ƽ����
	double SimpleArithAverNum();
	// ��Ȩ����ƽ����
	double PowerArithAverNum(BOOL bMode = FALSE);
	// ����ƽ����
	double GeometryAverNum();
	// ��λ��
	double MedianNum();
	// ����
	double NumerousNum();
	// ��λ��
	void SubSectionNum(double **ppdSubSecData, long lSubSecDataNum, long *plSubSecNum);
	
	// ***********************************��ɢ�̶�*************************** //
	// ���ֵ����Сֵ
	void ExtremumNum(double *pdMaxNum, double *pdMinNum);
	// ����
	double ExtreDifNum();
	// ���
	void DisDifNum(double *pdDisDifData);
	// ƽ�����
	double DisDifAverNum();
	// ���ƽ����
	double DisDifSqrSum();
	// ����
	double SqrDifNum();
    //������
    double SqraverDifNum();
	// ��׼��
	double StandDifNum();
	// ���ϵ��
	double AlterDifCoe();

	// ***********************************�ֲ���״*************************** //
	// ƫ��
	double DeflectDegree();
	// ���
	double ApexDegree();

	//////////////////////////////////////////////////////////////////////////
	/////////////////////////////����ͳ��/////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

	//------------------------�ȼ��ּ�------------------------//
	// ��������ͳ��
	long DataStatByArea(
		double dStartVal, double dEndVal,
		long **pplSmpIDList, long *plListNum);
	// ���ݷֶ�ͳ��(�����ֵ����Сֵ�ֶ�)
	long DataSecByMaxMin(
		long lSubSecNum,
		double **ppdSubSecPt, long *plSubSecPtNum,
		long **pplSmpIDList, long **pplListNum);
	/////////////////////////////////////huwah����/////////////////////////////////////
	//ָ����ʼֵ�Ͳ������еȼ��ּ�ͳ��
	long DataStatByStartAndStep(
		double dStartVal, double dStep,
		double **ppdSubSecPt, long *plSubSecPtNum,
		long **pplSmpIDList, long **pplListNum,
		double dEndVal = DEFAULT_MAX_VALUE);
	//ָ����ʼֵ�ͷ��������еȼ��ּ�ͳ��
	long DataStatByStartAndGroupNum(
		double dStartVal, long ldGroupNum,
		double **ppdSubSecPt, long *plSubSecPtNum,
		long **pplSmpIDList, long **pplListNum,
		double dEndVal = DEFAULT_MAX_VALUE);

	//------------------------��׼��ּ�------------------------//
	// ���ݷֶ�ͳ��(��ƽ��ֵ���׼��ֶ�)
	long DataSecByAverStd(
		long lStdMul, double dStepMul,
		double **ppdSubSecPt, long *plSubSecPtNum,
		long **pplSmpIDList, long **pplListNum);
	/////////////////////////////////huawh����///////////////////////////////////////////
	//ָ����ʼֵ����ֵֹ���б�׼��ּ�ͳ��
	long DataSecByAverStdAndMinMax(
		long lStdMul, double dStepMul,
		double **ppdSubSecPt, long *plSubSecPtNum,
		long **pplSmpIDList, long **pplListNum,
		double dMin=DEFAULT_MIN_VALUE, double dMax=DEFAULT_MAX_VALUE);


private:
	// ����Ƶ��
	BOOL FrequenceNum(double *pdOrigData, long *plFreqData);
	// ��������
	//	long	lType ���������㷨����     0 ��������(Ĭ��);    1 ð�ݷ�
	BOOL OrderData(long lType = 0);
	// �����㷨
	void QuickSort(ORDER_DATA x[], long low, long high);
	//void ShellSort(ORDER_DATA x[], long low, long high);
	void BubbleSort(ORDER_DATA x[], long low, long high);

	// ����ID����
	long DataIDSeach(ORDER_DATA s[], double key, long n);
	
private:
	double	*m_pdStatData;					//ԭʼ��������
	long	m_lDataNum;						//�����ܸ���
	ORDER_STRU m_OrderData;					//��������
	
	double	m_dAverVal;						//ƽ��ֵ
	double	m_dNumerousNum;					//����
	double	m_dMedianNum;					//��λ��
	double	m_dDisDifAverVal;				//ƽ�����
	double	m_dDifDisSqrSumVal;				//���ƽ����
	double	m_dSqrDifVal;					//����
	double  m_dStandDifVal;					//��׼��
	double	m_dAlterDifCoe;					//���ϵ��
    
    double  m_dAverDifVal;                  //�����NXX_2006_12_19
	
	double	*m_pdSubSecData;				//��λ��
	long	*m_plSmpIDList;					//��������ID
	double  *m_pdSecPtMaxMin;
	double	*m_pdSecPtAverStd;
	long	*m_plListNumMaxMin;
	long	*m_plSmpIDListMaxMin;
	long	*m_plListNumAverStd;
	long	*m_plSmpIDListAverStd;

	BOOL	m_bArithAverNumFlag;			//ƽ����������
	BOOL	m_bOrderDataFlag;				//�������ݼ�����	
	BOOL	m_bPowerAverNumFlag;			//��Ȩƽ����������
	BOOL	m_bDisDifNumFlag;				//��������
};

void _BASE_STATISTIC_QTY_DLL _ReadColorTable(char* clrLutFile, void* clrBuf, short& clrNum);


#ifndef _BASE_STATISTIC_QTY_LIB
	#pragma comment(lib, "s3dKerStatistics.lib")
#endif

#endif //_BASE_STATISTIC_QTY_EXP_H