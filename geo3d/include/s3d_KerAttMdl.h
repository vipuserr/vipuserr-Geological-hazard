#pragma once
#include <vector>
using namespace std;

#include <s3d_KerAttMdlExp.h>
#include <s3d_KerAttStruDef.h>
#include <gmeEntity.h>

namespace Smart3dMap 
{
	//属性数据分析类：对提取的原始数据进行分析过滤
	class LIB_S3DKERATTMDL_EXP attAnalyCls
	{
	public:
		attAnalyCls(void);
		~attAnalyCls(void);
	public:
		//加载样本数据：含地层属性+空间坐标
		int  loadSampleDots(vector<attDataStru>  &sampledots);

		//获取地层对应的样本数据
		int  GetLayerDatas(string &stratcode, vector<gme_vector4d> &sampledots);

		//获取地层对应的样本数据
		int  GetAllLayerDatas(map<string, vector<gme_vector4d>> &sampledots);

	private:
		//利用编码，对样本分类
		int  ClassifyDatasByLayer();

	private:
		vector<attDataStru>               *  m_pAllSampDots;   //输入的样本数据...
		map<string, vector<gme_vector4d>>    m_strToD4dotsMap; //地层对应的样本...
	};

	//属性数据创建
	class LIB_S3DKERATTMDL_EXP attCreateCls
	{
	public:
		attCreateCls();
		~attCreateCls();

	public:
		// 装载结构体模型：地层编码 映射 结构模型
		int setMdlParam(attMdlParam &param);
		//传入模型的box
		void setMdlBox(gme_rect_3d& mdlBox);

		//设置标准地层对应的序号
		void setStdStrat(map<string, int>& basLayersVec);

		// 装载样本数据
		int loadSampleDatas(map<string, vector<gme_vector4d>> &sampledots);

		// 一次装载所有地层体模型
		int loadGeoEntity(map<string, vector<gmeEntity*>> &allStratMdl);
		// 添加地层体模型
		int add1GeoEntity(string stratCode, vector<gmeEntity*>& stratMdl);

		// 创建三维格网模型
		int Create3dGridMdl();

		// 判断格网地层属性、计算格网属性值
		int Cal3dGridAttVal();

	public:
		//将结构模型栅格化后输出（含创建网格）
		void geoStruMdl2CSV(string &filepath, bool isOptInvalid = true);
		void geoStruMdl2VTK(string &filepath, bool isOptInvalid = true);

		//将计算结果输出为文件格式...XYZ、IJK、size(X)、size(Y)、size(Z)、attVal输出结构模型到csv文件，isOptInvalid:是否输出无效值
		//输出结构模型的网格...
		int GeoStruMdl2CSV(string &filepath, bool isOptInvalid = true);
		int GeoStruMdl2VTK(string &filepath, bool isOptInvalid = true);
		//输出属性模型到csv/vtk文件
		int GeoAttMdl2CSV(string &filepath, bool isOptInvalid = true);
		int GeoAttMdl2VTK(string &filepath, bool isOptInvalid = true);
		int GeoAttMdl2CSV(string& filePath, long * pXNum, long * pYNum, long * pZNum,
			gme_vector3d * pXYZGap, gme_vector3d  *  pMinPnt,
			vector<double>* pAttValues, bool isOptInvalid = true);
		int GeoAttMdl2VTK(string& filePath, long * pXNum, long * pYNum, long * pZNum,
			gme_vector3d * pXYZGap, gme_vector3d  *  pMinPnt,
			vector<double>* pAttValues, bool isOptInvalid = true);

		// 输出计算结果：内存数据级
		int OutPutAttMdlDatas( gme_rect_3d  * pMdlBox, long * pXNum, long * pYNum, long * pZNum,
			                     gme_vector3d * pXYZGap, gme_vector3d  *  pMinPnt, 
			                     gme_vector3d * pMaxPnt, vector<double>** pAttValues);

		//返回每个单元格对应的地层编码
		void getAttrValsCode(vector<string>& stratCodes);


	private:
		// 获取rect3d
		int   CalEntityRect3d();

		// 初始化格网参数
		int   init3dGridParam();

		// 对格网数据进行坐标变换...
		int   TransLateGridDatas();

		// 对格网数据进行坐标变换反变换...
		int   ReTransLateGridDatas();

		// 获取所有样本数据，合并成一个整体
		int   GetAllSampleDots();
		
		// 格网与实体位置关系判断
		int   CaluGridStrCode( short strcode, gmeEntity * pEnty, gme_vector3d &dot,
			                   double &dx, double &dy, bool &bdxy);

		// 计算变换系数
		int   CaluTransCof(gme_vector3d &centerdot, double &dx, double &dy, bool &bdxy);

		// 初始化数据表头
		void  initFileCSVHead(vector<string> &vec);

	private:
		vector<gme_vector4d>                    m_allSamples;  // 所有样本集合
		map<string, vector<gme_vector4d>>     * m_pSampleDots; // 样本数据集合...

		gme_rect_3d                             m_MdlBox;    // 结构模型三维外包矩形
		attMdlParam                             m_mdlParam;  // 三维属性格网建模参数
		vector<string>                          m_StrCode;   // 地层编码列表
		map<string, short>                      m_StrIndex;  // 地层编码索引，始于0
		map<short, string>                      m_ShortIdx;  // 地层编码索引，始于0
		map<gmeEntity*, gme_rect_3d>            m_EntyRect;  // 每个地层体对应的外包矩形
		map<string, vector<gmeEntity*>>         m_EntyModel; // 装载地层体模型

		int                                     m_xNum;        // X方向格网数目
		int                                     m_yNum;        // Y方向格网数目
		int                                     m_zNum;        // Z方向格网数目
		gme_vector3d                            m_dGap;        // xyz三个方向的步长
		gme_vector3d                            m_minPnt;      // 最小中心点
		gme_vector3d                            m_maxPnt;      // 最大中心点
		vector<char>                            m_attFlgs;     // XYZ方向索引集对应的点标记
		vector<double>                          m_attVals;     // XYZ方向索引集对应的点属性
		vector<string>							m_attValsCode; // XYZ方向索引集对应的点对应的地层编码
		vector<attIndex>                        m_vecIndex;    // XYZ方向索引集
		vector<gme_vector3d>                    m_vecDots;     // XYZ方向索引集对应的点坐标
		
		map<string, int>						m_basLayersVec; //标准地层序号

	};
}