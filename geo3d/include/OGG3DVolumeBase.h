#pragma once

#include <osg/TransferFunction>
#include <osg/ImageUtils>

#include "gmeStorage.h"
#include "OgVolumeDefine.h"

using namespace OG;

typedef struct  OG_VOL_Mdl_ID
{
	GME_TYPE_OBJ_ID	ClsID;//Ҫ����ID��
	GME_TYPE_OBJ_ID		DsID; //Ҫ�����ݼ���
	GME_TYPE_OBJ_ID	ObjID;//Ҫ�ػ򼸺ζ���ID
	short			nObjType;//��������

	OG_VOL_Mdl_ID()
	{
		ClsID = 0;
		DsID = 0;
		ObjID = 0;
		nObjType = 0;
	}
}OG_VOL_Mdl_ID;

//_�����ݻ�����Ϣ
class G3DVolumeInfoStru
{
public:
	G3DVolumeInfoStru()
	{
		strVolName = "Volume";
		strColortableName = "";
		strDataFormat = VOL_VOLUME;	//Ĭ��Ϊ������
		strVolType = COMMON_DATA;		//Ĭ��Ϊͨ������-������
		bIsRegular = TRUE;				//Ĭ��Ϊ��������
		strDescribtion = "��������";
		fAttMax = fAttMin = fInvalid = 0;
	}
	~G3DVolumeInfoStru(){}

public:
	long	operator = (const G3DVolumeInfoStru &regInfo)
	{
		fID	= regInfo.fID;			

		strVolName = regInfo.strVolName; //_�����ݵ�����
		strColortableName = regInfo.strColortableName;
		strDataFormat = regInfo.strDataFormat;

		bIsRegular = regInfo.bIsRegular;			//_�����ݱ�ʶ	0-�������� 1-������
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

		//�����С����ֵ����Чֵ
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
				return 0;			//��ǰ������δ��ȡ����Ϣ
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
	std::string				strVolName;	//_�����ݵ�����
	std::string				strColortableName;	//�����ݶ�Ӧɫ������
	VolumeDataFormat		strDataFormat;		//������������ ������/����
	BOOL					bIsRegular;			//_�����ݱ�ʶ	0-�������� 1-������
	std::string				strVolType;		//��������������
	std::string				strDescribtion;		//������������Ϣ

	//_������Ϣ
	union
	{
		//_������
		struct 
		{
			gme_vector3_d	d3Start;		//_�����ݵ���ʼλ��
			gme_vector3_d	d3Step;			//_�����ݵ�ļ��
			gl_3dot	l3VolSize;		//_�����ݵĴ�С
			gl_3dot	l3BlockSize;	//_�ڲ��ֿ��С
		};

		//_��������  ps��������
		struct
		{
			gme_box_d	box;			//_�����ݵĿռ䷶Χ
		};
	};

	std::vector<float>		attStru;		//_���������Խṹ

	//���������棨�������
	//�������� ����xy����仯��zһ��һ������
	std::vector<double>	vec_xData;	//������xֵ
	std::vector<double>	vec_yData;	//������yֵ����
	std::vector<double>	vec_zData;	//������zֵ����

	//��ת����
	gme_vector3_d mCenter;

	//_����ֵ
	gme_vector3_d mZoom;

private:
	//��������ֵ�������Сֵ
	void calAttMinMax()
	{
		if (attStru.size() == 0)
		{
			return;			//���ܼ���
		}
		fAttMin = fAttMax = attStru[0];
		for (int i = 1; i < attStru.size(); i++)
		{
			//ͳ����ֵ
			if (fAttMin > attStru[i]) fAttMin = attStru[i];
			if (fAttMax < attStru[i]) fAttMax = attStru[i];
		}
	}
private:
	//�����С����ֵ����Чֵ
	float fAttMax,fAttMin,fInvalid;
};

//�����ݿ��ӻ�����
class VolumeRenderParameter
{
public:
	VolumeRenderParameter(void){initialize();}
	~VolumeRenderParameter(void) {}

	void initialize()
	{
		//Ĭ��ɫ��
		transferFunction = new osg::TransferFunction1D;
		transferFunction->setColor(0.0, osg::Vec4(1.0,0.0,0.0,0.0));
		transferFunction->setColor(0.5, osg::Vec4(1.0,1.0,0.0,0.5));
		transferFunction->setColor(1.0, osg::Vec4(0.0,0.0,1.0,1.0));

		//xyz���ӻ���������ʼ��Ϊ1.0f
		xMultiplier = 1.0f;
		yMultiplier = 1.0f;
		zMultiplier = 1.0f;

		//Alpha���ܣ���ʼֵΪ0.0f
		alphaFunc = 0.02f;

		//���ӻ�ģʽ��Ĭ��Ϊ��׼��ʾ
		shadingModel = Standard;

		//��ɫģʽ
		colourSpaceOperation = osg::NO_COLOR_SPACE_OPERATION;
		osg::Vec4 colourModulatevalue(0.25f,0.25f,0.25f,0.25f);
		colourModulate = colourModulatevalue;

		//����ֵת��
		rescaleOperation = RESCALE_TO_ZERO_TO_ONE_RANGE;

		//gpuӳ�书�ܣ�����
		gpuTransferFunction = false;

		//�Ƿ���ɫ
		useShader = false;

		//��ͨ����ʾ
		useMultipass = FALSE;

		sampleDensityWhenMoving = 0.0;
		//sampleRatioWhenMoving = 0.0;
		sequenceLength = 10.0;
	}

public:
	//ӳ��ɫ��
	osg::ref_ptr<osg::TransferFunction1D> transferFunction;

	//xyz���ӻ�����
	float xMultiplier;
	float yMultiplier;
	float zMultiplier;

	//Alpha����
	float alphaFunc;

	//���ӻ�ģʽ
	ShadingModel shadingModel;

	//��ɫģʽ
	osg::ColorSpaceOperation colourSpaceOperation;
	osg::Vec4 colourModulate;

	//����ֵת��
	RescaleOperation rescaleOperation;

	//gpuӳ�书��
	bool gpuTransferFunction;

	//�Ƿ���ɫ
	bool useShader;

	//��ͨ��
	bool useMultipass;


	double sampleDensityWhenMoving;
	//double sampleRatioWhenMoving;
	double sequenceLength;
};