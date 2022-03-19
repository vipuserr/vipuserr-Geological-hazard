#pragma once

#include <vector>
#include "s3d_KernelAppDef.h"
#include <algorithm>

#include <fstream>
#include "gme_vector3.h"
using namespace std;


//数据统计与间隔划分


typedef enum GME_Numeric_Operation_Code
{	//数值操作类型
	GME_NUM_OPER_COMM = 0,//普通操作类型
	GME_NUM_OPER_NONZ = 1,//非负操作类型
	GME_NUM_OPER_GRAD = 2,//分级操作类型
}GME_Numeric_OperationType;
class GM_KERNEL_APP_EXP JenksNaturalBreaks
{
public:
	JenksNaturalBreaks();
	~JenksNaturalBreaks();
	static bool getNaturalBreaks(vector<double> values, int classNum, vector<double>& breakValues);//自然断点法分类，返回间断点，包含最小值，不包含最大值
	static bool NaturalClassifyBreaks(vector<double> vecAttValues, int iLevelNum, int iDiscrete, vector<double>& breakValues);

};

class GM_KERNEL_APP_EXP QuantileBreaks
{
public:
	QuantileBreaks();
	~QuantileBreaks();
	static void getQuantileBreaks(vector<double> values, int classNum, vector<double>& breakValues);//分位数分类法，按照数值的百分比等量分类
	//分位数法(等数量划分)
	static bool QuantileGetBreaks(vector<double> vecAttValues, int iLevelNum, int iDiscrete, vector<double>& breakValues);
};

class GM_KERNEL_APP_EXP gm_statistic_algo
{
public:
	gm_statistic_algo();
	~gm_statistic_algo();

	//相等间隔法
	static bool EqualSpacingGetBreaks(vector<double> vecAttValues, int iLevelNum, int iDiscrete, vector<double>& breakValues);

	//获取数据均匀距离断点,等距离分类法
	static void getAverageDistBreaks(vector<double> values, int classNum, vector<double>& breakValues);
	static bool VerifyDataValidity(vector<double> attvalues);
	//att属性值，Breakvalues间断点集合，分类级别数
	static int getLevelOfAtt(double att, vector<double> Breakvalues);
	static double getValueSum(vector<double> attvalues);
	static double getValueAvg(vector<double> attvalues);
	static double getValueMin(vector<double> attvalues);
	static double getValueMax(vector<double> attvalues);
	//母体方差
	static double getValueVari(vector<double> attvalues);
	//母体标准差
	static double getValueStddev(vector<double> attvalues);
	//均匀区间的频数分布
	static void getFreqOfUniInterv(vector<double>attvalues, int classNum, vector<double>&freqs);
	//根据属性间断点所划分的区间，返回每一个分段区间的平均值
	static void getAvgOfBreaksSeg(vector<double> values, vector<double> breakValues, vector<double>&avgValues);
	static vector<int> getRandomDiffNumbers(int min, int max, int num);
	template<typename T>
	static vector<int>  sort_indexes(const vector<T>  & v, bool reverse = false)//排序函数，返回排序数组的索引，reverse为false是升序，true是降序
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

	static void GenerateKMClusters(std::vector<gme_vector3d> pos, std::vector<int> &index, int clusterNum, int maxIterNum = 100);//生成聚类结果的索引数组index

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
	int m_dimNum;         // 数据维度
	int m_clusterNum;     //点集数目
	double** m_means;

	int m_initMode;
	// 迭代停止标准
	int m_maxIterNum;		// The stopping criterion regarding the number of iterations
	double m_endError;		// The stopping criterion regarding the error

	double GetLabel(const double* x, int* label);
	double CalcDistance(const double* x, const double* u, int dimNum); //计算距离(欧氏距离)
};