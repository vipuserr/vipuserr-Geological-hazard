#pragma once
#include <vector>
using namespace std;

//��������ػ�������

#define  DEGREE2RAD    (4.0 * atan(1.0) / double(180))
#define  RAD2DEGREE	   (double(180) / (4.0 * atan(1.0)))

#define  ATTRIBUTE_TYPE			float
//#define  ATTRIBUTE_TYPE_PTR		(float*) 
#define  XYZDATA_TYPE				double
//#define  XYZDATA_TYPE_PTR			(double*)

/************************************************************************/
/*						������������-����ģ�ͺ�����-����˵��              */
/************************************************************************/
#define VOL_VOLUME_DATA		"������"
#define VOL_LINE_DATA		"������������"
//�������ݸ�ʽ
enum VolumeDataFormat
{
	VOL_VOLUME,			//"������"
	VOL_LINE			//"������������"
};

/************************************************************************/
/*						�����ݲ�ͬ��������˵��                           */
/************************************************************************/
#define GRAVITY_DATA		"��������"
#define MAGNETIC_DATA		"�ŷ�����"
#define ELECTRICAL_DATA		"�編����"
#define LOGGING_DATA		"�⾮����"
#define EARTHQUAKE_DATA		"��������"
#define SOIL_DATA			"��������ѧ����"
#define WATER_DATA			"ˮ����ѧ����"
#define COMMON_DATA			"ͨ��������"

/************************************************************************/
/*						�������ݲ�ͬ��������˵��                           */
/************************************************************************/
#define LINE_REGULAR_DATA			"��������"
#define LINE_DENSITY_REG_DATA			"�ܶȣ�����"
#define LINE_ELECTRICAL_REG_DATA		"�����ʣ�����"
#define LINE_MAGNETIC_LOG_REG_DATA		"�Ż��ʶ���������"

/************************************************************************/
/*                       �����ݿ��ӻ�����˵��                            */
/************************************************************************/
#define VOL_COLORTABLE		"ɫ������"

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

//���������
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

//�������������
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

//��Χ�ռ���Ϣ
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

	//���ÿ�����
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


//���Ʒ���
enum VolumeRenderMode
{
	//��Ƭ����  : �����ڻ��ƹ���������
	VRM_SLICE = 0x000001,

	//�����   : �����ڻ��ƹ�����
	VRM_VOLUME = 0x000002,

	//��ֵ�����	�������ڻ��Ƶ�ֵ��׷�ٽ��
	VRM_ISOSURFACE = 0x000003,

	//��ľ���� : �����ڻ��Ʋ�������
	VRM_BIRCKS = 0x000004,

	//�����   : �����ڻ��Ƶ�������
	VRM_POINT_CLOUD = 0x000010,

	//����2D���� : �����ڻ��ƴ��߶ȵ���Ƭ���ݻ�ͶӰ����
	VRM_TEXTURE_2D = 0x000020,

	//���Ʒ�ʸ����ͷ
	VRM_WIND_ARROW = 0x000040,

	//��̬	   : ��̬����
	VRM_DNYMIC = 0xFF000000,

	//��չ
	VRM_EXTEND	= 0XFFFFFF
};

//����ģʽ
enum VolumeDataSourceMode
{
	//��Ƭ����
	VDSM_SLICE = 0x00001,

	//������
	VDSM_VOLUME = 0x0003,

	//����
	VDSM_DATA_EXP = 0x007,

	//��չ����
	VDSM_DATA_UNKNOW = 0x00ff,
};

/************************************************************************/
/*             �������ļ���ȡʱ��õ���Ϣ���������ݽṹ����Ϣ           */
/************************************************************************/
//��������Ϣͷ
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

	//���ݳߴ�
	unsigned long mXSize;
	unsigned long mYSize;
	unsigned long mZSize;

	unsigned long mDataSize;
	VolumeDataFormat mDataFormat;

	//���ݼ��
	float mXStep;
	float mYStep;
	float mZStep;

	//ģ������
	char* strVolumeName;

	BOOL bIsRegular;

	//����ģʽ
	VolumeDataSourceMode mDataMode;

	//����Χ
	GeoRange mRange;
};

//�����ݽṹ����Ϣ
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

	//��Ϣͷ
	VolumeDataHeadInfo mHeadInfo;

	//����ֵ������
	int mAttrIndex;

	//������ֵ-������ģ��
	float* mpAttBuf;

	//�ռ�λ����Ϣ-��λ����Ϣ
	GeoPosition *mpPosBuf;	

	//�ռ䳤����Ϣ-��λ��������Ϣ (�򳤶ȡ���λ����)
	GeoPosition	*mpSizeBuf;

	//��չ��Ϣ
	GeoPosition *mpExtendBuf;

	//��Сֵ
	double dMinValue;

	//���ֵ
	double dMaxValue;

	//��Чֵ
	double dInvalidateValue;

	//����������Ϣ
	double* mpXData;
	double* mpYData;
	double* mpZData;
};

/************************************************************************/
/*                 �����ݽ�����ض��塪����Ƭ����ֵ���                 */
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

//��Ƭ����
struct SlicePos
{
	double position;	//����λ��
	int nDirection;		//���淽��
};

struct GLvector
{
	double dX;
	double dY;
	double dZ;     
};

enum IsoSurfaceType
{
	MC,		//Marching cubes �ƶ�������
	MT,		//Marching tetrahedron �ƶ������壨�������׼����Ϊ���������壩
	BCC,	//Body-centred cubic ���ĵ�ָ�
	DC,		// DC
	DCMT,	//DC+MT
	OCDC	// octree DC
};


//������ṹ
struct Tetrahedron
{
	GLvector	tetPoint[4];
	float		tetValue[4];
	GLvector	tetGradients[4];
	int			nIdx;	// �Ƿ�Ϊ�߽�������
};

//���������ĵ����꼰ֵ
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