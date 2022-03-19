#pragma once

#include <vector>
#include "s3d_KernelAppDef.h"
#include <algorithm>

#include <fstream>
#include "gme_vector3.h"
using namespace std;


//����ͳ����������


typedef enum GME_Numeric_Operation_Code
{	//��ֵ��������
	GME_NUM_OPER_COMM = 0,//��ͨ��������
	GME_NUM_OPER_NONZ = 1,//�Ǹ���������
	GME_NUM_OPER_GRAD = 2,//�ּ���������
}GME_Numeric_OperationType;
class GM_KERNEL_APP_EXP JenksNaturalBreaks
{
public:
	JenksNaturalBreaks();
	~JenksNaturalBreaks();
	static bool getNaturalBreaks(vector<double> values, int classNum, vector<double>& breakValues);//��Ȼ�ϵ㷨���࣬���ؼ�ϵ㣬������Сֵ�����������ֵ
	static bool NaturalClassifyBreaks(vector<double> vecAttValues, int iLevelNum, int iDiscrete, vector<double>& breakValues);

};

class GM_KERNEL_APP_EXP QuantileBreaks
{
public:
	QuantileBreaks();
	~QuantileBreaks();
	static void getQuantileBreaks(vector<double> values, int classNum, vector<double>& breakValues);//��λ�����෨��������ֵ�İٷֱȵ�������
	//��λ����(����������)
	static bool QuantileGetBreaks(vector<double> vecAttValues, int iLevelNum, int iDiscrete, vector<double>& breakValues);
};

class GM_KERNEL_APP_EXP gm_statistic_algo
{
public:
	gm_statistic_algo();
	~gm_statistic_algo();

	//��ȼ����
	static bool EqualSpacingGetBreaks(vector<double> vecAttValues, int iLevelNum, int iDiscrete, vector<double>& breakValues);

	//��ȡ���ݾ��Ⱦ���ϵ�,�Ⱦ�����෨
	static void getAverageDistBreaks(vector<double> values, int classNum, vector<double>& breakValues);
	static bool VerifyDataValidity(vector<double> attvalues);
	//att����ֵ��Breakvalues��ϵ㼯�ϣ����༶����
	static int getLevelOfAtt(double att, vector<double> Breakvalues);
	static double getValueSum(vector<double> attvalues);
	static double getValueAvg(vector<double> attvalues);
	static double getValueMin(vector<double> attvalues);
	static double getValueMax(vector<double> attvalues);
	//ĸ�巽��
	static double getValueVari(vector<double> attvalues);
	//ĸ���׼��
	static double getValueStddev(vector<double> attvalues);
	//���������Ƶ���ֲ�
	static void getFreqOfUniInterv(vector<double>attvalues, int classNum, vector<double>&freqs);
	//�������Լ�ϵ������ֵ����䣬����ÿһ���ֶ������ƽ��ֵ
	static void getAvgOfBreaksSeg(vector<double> values, vector<double> breakValues, vector<double>&avgValues);
	static vector<int> getRandomDiffNumbers(int min, int max, int num);
	template<typename T>
	static vector<int>  sort_indexes(const vector<T>  & v, bool reverse = false)//���������������������������reverseΪfalse������true�ǽ���
	{
		// initialize original index locations
		vector<int>  idx(v.size());
		for (int i = 0; i != idx.size(); ++i) idx[i] = i;
		// sort indexes based on comparing values in v
		if (reverse)
		{
			sort(idx.begin(), idx.end(),
				[&v](int i1, int i2) {return v[i1] > v[i2]; });
		}
		else {
			sort(idx.begin(), idx.end(),
				[&v](int i1, int i2) {return v[i1] < v[i2]; });
		}
		return idx;
	}
};

class GM_KERNEL_APP_EXP KMeans
{
public:
	enum InitMode
	{
		InitRandom,
		InitManual,
		InitUniform,
	};

	KMeans(int dimNum = 1, int clusterNum = 1, int maxIterNum = 100);
	~KMeans();

	static void GenerateKMClusters(std::vector<gme_vector3d> pos, std::vector<int> &index, int clusterNum, int maxIterNum = 100);//���ɾ���������������index

	void SetMean(int i, const double* u) { memcpy(m_means[i], u, sizeof(double) * m_dimNum); }
	void SetInitMode(int i) { m_initMode = i; }
	void SetMaxIterNum(int i) { m_maxIterNum = i; }
	void SetEndError(double f) { m_endError = f; }

	double* GetMean(int i) { return m_means[i]; }
	int GetInitMode() { return m_initMode; }
	int GetMaxIterNum() { return m_maxIterNum; }
	double GetEndError() { return m_endError; }


	/*	SampleFile: <size><dim><data>...
		LabelFile:	<size><label>...
	*/
	void Cluster(const char* sampleFileName, const char* labelFileName);
	void Init(std::ifstream& sampleFile);
	void Init(double *data, int N);
	void Cluster(double *data, int N, int *Label);
	friend std::ostream& operator<<(std::ostream& out, KMeans& kmeans);

private:
	int m_dimNum;         // ����ά��
	int m_clusterNum;     //�㼯��Ŀ
	double** m_means;

	int m_initMode;
	// ����ֹͣ��׼
	int m_maxIterNum;		// The stopping criterion regarding the number of iterations
	double m_endError;		// The stopping criterion regarding the error

	double GetLabel(const double* x, int* label);
	double CalcDistance(const double* x, const double* u, int dimNum); //�������(ŷ�Ͼ���)
};