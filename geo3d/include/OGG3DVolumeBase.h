#pragma once

#include <osg/TransferFunction>
#include <osg/ImageUtils>

#include "gmeStorage.h"
#include "OgVolumeDefine.h"

using namespace OG;

typedef struct  OG_VOL_Mdl_ID
{
	GME_TYPE_OBJ_ID	ClsID;//要素类ID或
	GME_TYPE_OBJ_ID		DsID; //要素数据集集
	GME_TYPE_OBJ_ID	ObjID;//要素或几何对象ID
	short			nObjType;//对象类型

	OG_VOL_Mdl_ID()
	{
		ClsID = 0;
		DsID = 0;
		ObjID = 0;
		nObjType = 0;
	}
}OG_VOL_Mdl_ID;

//_体数据基本信息
class G3DVolumeInfoStru
{
public:
	G3DVolumeInfoStru()
	{
		strVolName = "Volume";
		strColortableName = "";
		strDataFormat = VOL_VOLUME;	//默认为体数据
		strVolType = COMMON_DATA;		//默认为通用数据-体数据
		bIsRegular = TRUE;				//默认为规则数据
		strDescribtion = "属性数据";
		fAttMax = fAttMin = fInvalid = 0;
	}
	~G3DVolumeInfoStru(){}

public:
	long	operator = (const G3DVolumeInfoStru &regInfo)
	{
		fID	= regInfo.fID;			

		strVolName = regInfo.strVolName; //_体数据的名称
		strColortableName = regInfo.strColortableName;
		strDataFormat = regInfo.strDataFormat;

		bIsRegular = regInfo.bIsRegular;			//_体数据标识	0-不规则体 1-规则体
		strVolType = regInfo.strVolType;

		if (bIsRegular)
		{
			d3Start = regInfo.d3Start;
			d3Step = regInfo.d3Step;
			l3VolSize = regInfo.l3VolSize;
			l3BlockSize = regInfo.l3BlockSize;
		} 
		else
		{
			box = regInfo.box;
			//nBlockSize = regInfo.nBlockSize;
			d3Start = regInfo.d3Start;
			d3Step = regInfo.d3Step;
			l3VolSize = regInfo.l3VolSize;
			l3BlockSize = regInfo.l3BlockSize;
		}

		attStru = regInfo.attStru;
		vec_xData = regInfo.vec_xData;
		vec_yData = regInfo.vec_yData;
		vec_zData = regInfo.vec_zData;

		//最大最小属性值，无效值
		fAttMax = regInfo.fAttMax;
		fAttMin = regInfo.fAttMin;
		fInvalid = regInfo.fInvalid;

		return 1;
	}

	long	GetMaxMinInvaValue(float &fAttMaxValue,float &fAttMinValue,float &fInvalidValue)
	{
		if (fAttMax == 0 && fAttMin == 0 && fInvalid == 0)
		{
			if (attStru.size() == 0)
			{
				return 0;			//当前体数据未获取到信息
			}
			calAttMinMax();
		}
		fAttMaxValue = fAttMax;
		fAttMinValue = fAttMin;
		fInvalidValue = fInvalid;
		return 1;
	}

public:
	OG_VOL_Mdl_ID			fID;
	std::string				strVolName;	//_体数据的名称
	std::string				strColortableName;	//体数据对应色表名称
	VolumeDataFormat		strDataFormat;		//属性数据类型 体数据/剖面
	BOOL					bIsRegular;			//_体数据标识	0-不规则体 1-规则体
	std::string				strVolType;		//体数据数据类型
	std::string				strDescribtion;		//体数据描述信息

	//_几何信息
	union
	{
		//_规则体
		struct 
		{
			gme_vector3_d	d3Start;		//_体数据的起始位置
			gme_vector3_d	d3Step;			//_体数据点的间隔
			gl_3dot	l3VolSize;		//_体数据的大小
			gl_3dot	l3BlockSize;	//_内部分块大小
		};

		//_不规则体  ps：待扩充
		struct
		{
			gme_box_d	box;			//_体数据的空间范围
		};
	};

	std::vector<float>		attStru;		//_体数据属性结构

	//体数据剖面（变相规则）
	//剖面走向 按照xy方向变化，z一层一层增加
	std::vector<double>	vec_xData;	//剖面上x值
	std::vector<double>	vec_yData;	//剖面上y值数据
	std::vector<double>	vec_zData;	//剖面上z值数据

	//旋转中心
	gme_vector3_d mCenter;

	//_缩放值
	gme_vector3_d mZoom;

private:
	//计算属性值的最大最小值
	void calAttMinMax()
	{
		if (attStru.size() == 0)
		{
			return;			//不能计算
		}
		fAttMin = fAttMax = attStru[0];
		for (int i = 1; i < attStru.size(); i++)
		{
			//统计最值
			if (fAttMin > attStru[i]) fAttMin = attStru[i];
			if (fAttMax < attStru[i]) fAttMax = attStru[i];
		}
	}
private:
	//最大最小属性值，无效值
	float fAttMax,fAttMin,fInvalid;
};

//体数据可视化参数
class VolumeRenderParameter
{
public:
	VolumeRenderParameter(void){initialize();}
	~VolumeRenderParameter(void) {}

	void initialize()
	{
		//默认色表
		transferFunction = new osg::TransferFunction1D;
		transferFunction->setColor(0.0, osg::Vec4(1.0,0.0,0.0,0.0));
		transferFunction->setColor(0.5, osg::Vec4(1.0,1.0,0.0,0.5));
		transferFunction->setColor(1.0, osg::Vec4(0.0,0.0,1.0,1.0));

		//xyz可视化比例，初始均为1.0f
		xMultiplier = 1.0f;
		yMultiplier = 1.0f;
		zMultiplier = 1.0f;

		//Alpha功能，初始值为0.0f
		alphaFunc = 0.02f;

		//可视化模式，默认为标准显示
		shadingModel = Standard;

		//颜色模式
		colourSpaceOperation = osg::NO_COLOR_SPACE_OPERATION;
		osg::Vec4 colourModulatevalue(0.25f,0.25f,0.25f,0.25f);
		colourModulate = colourModulatevalue;

		//属性值转换
		rescaleOperation = RESCALE_TO_ZERO_TO_ONE_RANGE;

		//gpu映射功能，开启
		gpuTransferFunction = false;

		//是否着色
		useShader = false;

		//多通道显示
		useMultipass = FALSE;

		sampleDensityWhenMoving = 0.0;
		//sampleRatioWhenMoving = 0.0;
		sequenceLength = 10.0;
	}

public:
	//映射色表
	osg::ref_ptr<osg::TransferFunction1D> transferFunction;

	//xyz可视化比例
	float xMultiplier;
	float yMultiplier;
	float zMultiplier;

	//Alpha功能
	float alphaFunc;

	//可视化模式
	ShadingModel shadingModel;

	//颜色模式
	osg::ColorSpaceOperation colourSpaceOperation;
	osg::Vec4 colourModulate;

	//属性值转换
	RescaleOperation rescaleOperation;

	//gpu映射功能
	bool gpuTransferFunction;

	//是否着色
	bool useShader;

	//多通道
	bool useMultipass;


	double sampleDensityWhenMoving;
	//double sampleRatioWhenMoving;
	double sequenceLength;
};