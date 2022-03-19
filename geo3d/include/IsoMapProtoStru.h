#pragma once
#include "s3d_geommaplib_global.h"
#include "G2DToolDef.h"
#include "gmeStru.h"

class IsoMapProto {
public:
	enum IsoType {
		TOP_ELEVATION = 0,    //层顶标高等值线
		BOTTOM_ELEVATION = 1, //层底标高等值线
		THICK = 2,            //等厚线
		DEPTH_BOTTOM = 3,     //层底埋深等值线
		SAND_CONTENT = 4      //含砂率等值线
	};

	enum GridBoundary {
		REG_BOUNDARY = 0,     //依据画框做格网边界
		POINT_BOUNDARY = 1    //依据含选择地层的数据点最值做格网边界
	};

	enum GridMethod {
		IDW = 0               //反距离权重
	};

	int       m_iDbHoleId;                    //钻孔数据库ID
	int       m_iCurrentLevel;                //地层级别
	int		  m_iStdStratVer;                  //标准地层版本
	int       m_iSampleRow;                   //抽稀行数
	int       m_iSampleCol;                   //抽稀列数
	int       m_iSampleNum;                   //抽稀保留格网孔数
	int       m_iDbMapId;                     //用于保存生成的分区图的目标二维地图数据库的ID
	bool      m_bUseSample;                   //是否使用抽稀
	bool      m_bUseHull;                     //是否使用凸包
	bool      m_bUseWhite;                    //是否使用栅格白化
	bool      m_bUseZLimit;                   //格网插值后是否约束得到的值
	double    m_dZMin;                        //格网插值后用于约束生成值的最小值
	double    m_dZMax;                        //格网插值后用于约束生成值的最大值
	double    m_dIsoSpace;                    //生成等值线间隔
	IsoType  m_eIsoType;                     //等值线类型
	GridMethod          m_eGridMethod;       //生成格网的插值方法（后续可继续加入）
	GridBoundary        m_eGridBoundary;     //生成格网的边界
	std::string          m_sIsoMapName;       //生成等值线图名
	vector<string>	     m_vSelectLayerCodes; //选中地层的编码
	Smart3dMap::RegDots	 m_vHoleRgnDots;      //边界范围
	
	IsoMapProto() {
		m_iDbHoleId = 0;
		m_iCurrentLevel = 0;
		m_iSampleRow = 20;
		m_iSampleCol = 20;
		m_iSampleNum = 1;
		m_iDbMapId = 0;
		m_bUseSample = false;
		m_bUseHull = false;
		m_bUseWhite = false;
		m_bUseZLimit = false;
		m_dZMin = 0;
		m_dZMax = 0;
		m_dIsoSpace = 1.00;
		m_sIsoMapName = "等值线图";
		m_eIsoType = IsoType::BOTTOM_ELEVATION;
		m_eGridBoundary = GridBoundary::REG_BOUNDARY;
		m_eGridMethod = GridMethod::IDW;
	}
};