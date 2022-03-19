#pragma once
#include <vector>
using namespace std;

//体数据相关基本定义

#define  DEGREE2RAD    (4.0 * atan(1.0) / double(180))
#define  RAD2DEGREE	   (double(180) / (4.0 * atan(1.0)))

#define  ATTRIBUTE_TYPE			float
//#define  ATTRIBUTE_TYPE_PTR		(float*) 
#define  XYZDATA_TYPE				double
//#define  XYZDATA_TYPE_PTR			(double*)

/************************************************************************/
/*						地球物理数据-属性模型和剖面-类型说明              */
/************************************************************************/
#define VOL_VOLUME_DATA		"体数据"
#define VOL_LINE_DATA		"地球物理剖面"
//定义数据格式
enum VolumeDataFormat
{
	VOL_VOLUME,			//"体数据"
	VOL_LINE			//"地球物理剖面"
};

/************************************************************************/
/*						体数据不同数据类型说明                           */
/************************************************************************/
#define GRAVITY_DATA		"重力数据"
#define MAGNETIC_DATA		"磁法数据"
#define ELECTRICAL_DATA		"电法数据"
#define LOGGING_DATA		"测井数据"
#define EARTHQUAKE_DATA		"地震数据"
#define SOIL_DATA			"土壤地球化学数据"
#define WATER_DATA			"水地球化学数据"
#define COMMON_DATA			"通用体数据"

/************************************************************************/
/*						剖面数据不同数据类型说明                           */
/************************************************************************/
#define LINE_REGULAR_DATA			"规则剖面"
#define LINE_DENSITY_REG_DATA			"密度（规则）"
#define LINE_ELECTRICAL_REG_DATA		"电阻率（规则）"
#define LINE_MAGNETIC_LOG_REG_DATA		"磁化率对数（规则）"

/************************************************************************/
/*                       体数据可视化参数说明                            */
/************************************************************************/
#define VOL_COLORTABLE		"色表名称"

enum ShadingModel
{
	Standard,
	LightType,
	Isosurface,
	MaximumIntensityProjection,
	Cut,
	AnyCut
};

enum RescaleOperation
{
	NO_RESCALE,
	RESCALE_TO_ZERO_TO_ONE_RANGE,
	SHIFT_MIN_TO_ZERO
};

//定义球面点
class GeoPosition 
{
public:
	GeoPosition() 
		: mx(0)
		, my(0)
		, mz(0)
	{}
	GeoPosition(double x, double y, double z)
		: mx(x)
		, my(y)
		, mz(z)
	{
	}

	const GeoPosition& operator=(const GeoPosition& pos)
	{
		mx = pos.mx;
		my = pos.my;
		mz = pos.mz;

		return *this;
	}

	GeoPosition operator*(double scale)
	{
		GeoPosition r;
		r.mx = scale*mx;
		r.my = scale*my;
		r.mz = scale*mz;
		return r;
	}

	inline friend GeoPosition operator+(const GeoPosition& p1, const GeoPosition& p2)
	{
		GeoPosition r;
		r.mx = p1.mx + p2.mx;
		r.my = p1.my + p2.my;
		r.mz = p1.mz + p2.mz;
		return r;
	}

	inline friend GeoPosition operator-(const GeoPosition& p1, const GeoPosition& p2)
	{
		GeoPosition r;
		r.mx = p1.mx - p2.mx;
		r.my = p1.my - p2.my;
		r.mz = p1.mz - p2.mz;
		return r;
	}

	inline friend GeoPosition operator* (double scale, const GeoPosition& pos)
	{
		GeoPosition r;
		r.my = scale * pos.my;
		r.mx = scale * pos.mx;
		r.mz = scale * pos.mz;
		return r;
	}

	void operator*=(double scale)
	{
		my *= scale;
		mx *= scale;
		mz *= scale;
	}

	double mx;
	double my;
	double mz;
};

//定义球表面区域
class GeoRect
{
public:
	GeoRect()
		: mMinY(0)
		, mMaxY(0)
		, mMinX(0)
		, mMaxX(0)
	{
	}
	GeoRect(double minX, double maxX,
		double minY, double maxY)
		: mMinY(minY)
		, mMaxY(maxY)
		, mMinX(minX)
		, mMaxX(maxX)
	{
	}

	~GeoRect(){}

	int isInRect(double lon, double lat)
	{
		if (lon >= mMinX && lon <= mMaxX &&
			lat >= mMinY && lat <= mMaxY)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	double mMinX;
	double mMaxX;
	double mMinY;
	double mMaxY;
};

//范围空间信息
class GeoRange
{
public:
	GeoRange()
		: mMinY(0)
		, mMaxY(0)
		, mMinX(0)
		, mMaxX(0)
		, mMinZ(0)
		, mMaxZ(0)
	{
	}

	GeoRange(double minX,
		double maxX,
		double minY,
		double maxY,
		double minZ,
		double maxZ)
		: mMinY(minY)
		, mMaxY(maxY)
		, mMinX(minX)
		, mMaxX(maxX)
		, mMinZ(minZ)
		, mMaxZ(maxZ)
	{}

	const GeoRange& operator=(const GeoRange& range)
	{
		mMinZ = range.mMinZ;
		mMaxZ = range.mMaxZ;
		mMinX = range.mMinX;
		mMaxX = range.mMaxX;
		mMinY = range.mMinY;
		mMaxY = range.mMaxY;

		return *this;
	}

	bool operator==(const GeoRange& range)
	{
		bool eql = true;
		if ((mMinZ != range.mMinZ) ||
			(mMaxZ != range.mMaxZ) ||
			(mMinX != range.mMinX) ||
			(mMaxX != range.mMaxX) ||
			(mMinY != range.mMinY) ||
			(mMaxY != range.mMaxY))
			eql = false;
		return eql;
	}

	GeoRange friend operator*(double scale, const GeoRange& range)
	{
		GeoRange rg;
		rg.mMinY = scale * range.mMinY;
		rg.mMaxY = scale * range.mMaxY;
		rg.mMinX = scale * range.mMinX;
		rg.mMaxX = scale * range.mMaxX;
		rg.mMinZ = scale * range.mMinZ;
		rg.mMaxZ = scale * range.mMaxZ;

		return rg;
	}

	//设置空区域
	void setNull()
	{
		mMinY = mMaxY = mMinX = mMaxX = mMinZ = 1e+38;
	}

	bool isNull()
	{
		return (mMinY == 1e+38) && (mMaxY == 1e+38) && 
			(mMinX == 1e+38) && (mMaxX == 1e+38) &&
			(mMinZ == 1e+38) && (mMaxZ == 1e+38);
	}

	GeoPosition getCenter()
	{
		GeoPosition center;
		center.mx = (mMinX + mMaxX) * 0.5;
		center.my = (mMinY + mMaxY) * 0.5;
		center.mz = (mMinZ + mMaxZ) * 0.5;
		return center;
	}

public:
	double mMinX;
	double mMaxX;
	double mMinY;
	double mMaxY;
	double mMinZ;
	double mMaxZ;
};

class GeoSize
{
public:
	long mxSize;
	long mySize;
	long mzSize;

public:
	GeoSize(int xSize, int ySize, int zSize)
		: mxSize(xSize), mySize(ySize), mzSize(zSize){}
	~GeoSize(){}
};	


//绘制方法
enum VolumeRenderMode
{
	//切片绘制  : 常用于绘制规则格点数据
	VRM_SLICE = 0x000001,

	//体绘制   : 常用于绘制规则体
	VRM_VOLUME = 0x000002,

	//等值面绘制	：常用于绘制等值面追踪结果
	VRM_ISOSURFACE = 0x000003,

	//积木画法 : 常用于绘制不规则体
	VRM_BIRCKS = 0x000004,

	//点绘制   : 常用于绘制点云数据
	VRM_POINT_CLOUD = 0x000010,

	//绘制2D数据 : 常用于绘制带高度的面片数据或投影数据
	VRM_TEXTURE_2D = 0x000020,

	//绘制风矢量箭头
	VRM_WIND_ARROW = 0x000040,

	//动态	   : 动态绘制
	VRM_DNYMIC = 0xFF000000,

	//扩展
	VRM_EXTEND	= 0XFFFFFF
};

//数据模式
enum VolumeDataSourceMode
{
	//切片数据
	VDSM_SLICE = 0x00001,

	//体数据
	VDSM_VOLUME = 0x0003,

	//两者
	VDSM_DATA_EXP = 0x007,

	//扩展类型
	VDSM_DATA_UNKNOW = 0x00ff,
};

/************************************************************************/
/*             体数据文件读取时获得的信息——体数据结构体信息           */
/************************************************************************/
//体数据信息头
class VolumeDataHeadInfo
{
public:
	VolumeDataHeadInfo()
	{
		mXSize = 0;
		mYSize = 0;
		mZSize = 0;

		mDataSize = 0;
		mDataFormat = VOL_VOLUME;
		strVolumeName = "";
		bIsRegular = TRUE;
	}

	//数据尺寸
	unsigned long mXSize;
	unsigned long mYSize;
	unsigned long mZSize;

	unsigned long mDataSize;
	VolumeDataFormat mDataFormat;

	//数据间隔
	float mXStep;
	float mYStep;
	float mZStep;

	//模型名称
	char* strVolumeName;

	BOOL bIsRegular;

	//数据模式
	VolumeDataSourceMode mDataMode;

	//地理范围
	GeoRange mRange;
};

//体数据结构体信息
class VolumeDataInfo
{
public:
	VolumeDataInfo()
		: mpAttBuf(NULL)
		, mpPosBuf(NULL)
		, mpSizeBuf(NULL)
		, mpExtendBuf(NULL)
		, mAttrIndex(0)
		, mpXData(NULL)
		, mpYData(NULL)
		, mpZData(NULL)
		, dMinValue(0)
		, dMaxValue(0)
		, dInvalidateValue(0)
	{
	}

	~VolumeDataInfo()
	{
		delete[] mpAttBuf;
		mpAttBuf = NULL;

		delete[] mpPosBuf;
		mpPosBuf = NULL;

		delete[] mpSizeBuf;
		mpSizeBuf = NULL;

		delete[] mpExtendBuf;
		mpExtendBuf = NULL;

		delete[] mpXData;
		mpXData = NULL;

		delete[] mpYData;
		mpYData = NULL;

		delete[] mpZData;
		mpZData = NULL;
	}

	//信息头
	VolumeDataHeadInfo mHeadInfo;

	//属性值索引号
	int mAttrIndex;

	//单属性值-表属性模型
	float* mpAttBuf;

	//空间位置信息-表位置信息
	GeoPosition *mpPosBuf;	

	//空间长度信息-方位上属性信息 (或长度、或方位分量)
	GeoPosition	*mpSizeBuf;

	//扩展信息
	GeoPosition *mpExtendBuf;

	//最小值
	double dMinValue;

	//最大值
	double dMaxValue;

	//无效值
	double dInvalidateValue;

	//剖面数据信息
	double* mpXData;
	double* mpYData;
	double* mpZData;
};

/************************************************************************/
/*                 体数据交互相关定义——切片、等值面等                 */
/************************************************************************/
/** Comparison functions used for the depth/stencil buffer operations and 
	others. */
enum CompareFunction
{
    CMPF_ALWAYS_FAIL,
    CMPF_ALWAYS_PASS,
    CMPF_LESS,
    CMPF_LESS_EQUAL,
    CMPF_EQUAL,
    CMPF_NOT_EQUAL,
    CMPF_GREATER_EQUAL,
    CMPF_GREATER
};

//切片数据
struct SlicePos
{
	double position;	//切面位置
	int nDirection;		//切面方向
};

struct GLvector
{
	double dX;
	double dY;
	double dZ;     
};

enum IsoSurfaceType
{
	MC,		//Marching cubes 移动立方体
	MT,		//Marching tetrahedron 移动四面体（立方体标准划分为六个四面体）
	BCC,	//Body-centred cubic 中心点分割
	DC,		// DC
	DCMT,	//DC+MT
	OCDC	// octree DC
};


//四面体结构
struct Tetrahedron
{
	GLvector	tetPoint[4];
	float		tetValue[4];
	GLvector	tetGradients[4];
	int			nIdx;	// 是否为边界四面体
};

//立方体中心点坐标及值
struct CubeCenter
{
	GLvector	centerPoint;
	float		centerValue;
	GLvector	centerGradients;
};

struct CubeGradients
{
	int			ndx;
	GLvector	cubeGradients[8];
};