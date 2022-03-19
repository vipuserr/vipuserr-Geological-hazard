#pragma once

#include "s3d_geomodeliolib_global.h"

struct  Model3dtilesPara
{
	//1��ʾ3�ȷִ���2��ʾ6�ȷִ�
	enum ZoneType
	{
		ZONETYPE_OF_3DEGREE = 1,
		ZONETYPE_OF_6DEGREE = 2
	};

	//һ���������ļ��������ٸ�Ҫ��(���)��Ϊ0���ʾ������׷���һ���ļ���
	int			iBoreholeNumOfBinaryfile;
	//�Ƿ���Ҫת��Ϊ��γ�����꣬Ϊfalse��ģ���������꽫������ת����Ϊtrue��ᰴ����ת������
	bool		bIsTransLonlatCoord;
	//�����Ƿ�Ӵ��ţ�trueΪ�Ӵ��ţ�falseΪ���Ӵ���
	bool		bIsAddPlus;
	//�ִ����ͣ�������ֵ��Ϊ1��ʾ3�ȷִ���Ϊ2��ʾ6�ȷִ���Ĭ��Ϊ3�ȷִ�
	ZoneType	iZoneType;
	//ͶӰ���Ĵ��ţ���֪��Ҳ���Բ��Ĭ��ֵ-1��ʾ��֪�������Ž����ݾ���ֵ���м���
	int			iProjZone;
	//ģ�����ڵĴ��¾��ȣ���proj_zone��Ϊ-1������proj_zone����Ϊ׼�����Բ���
	//ע����������й�������Ч��3�ȴ��ŷ�ΧΪ(24~46),6�ȷִ����ŷ�ΧΪ(13~23)�����ȷ�ΧΪ73��~135��
	double		dLongitude;

	Model3dtilesPara()
	{
		iBoreholeNumOfBinaryfile = 0;
		bIsTransLonlatCoord = true;
		bIsAddPlus = false;
		iZoneType = ZONETYPE_OF_3DEGREE;
		iProjZone = -1;
		dLongitude = 114;
	}

};

//������άģ�� 3dtiles ��obj����
class S3D_GEOMODELIOLIB_EXPORT Export3DMdlProto
{
public:
	enum TargetFormat
	{
		UNKNOWN		= 0,
		TILES_3D	= 1,
		OBJ			= 2
	};

	int m_mdlID;					//ģ��id
	int m_mdlDbID;					//ģ�����ݿ�id
	TargetFormat m_format;			//��������
	Model3dtilesPara m_3dtilesPara; //����3dtiles�Ĳ���
	bool m_overwrite;
	
	Export3DMdlProto()
	{
		m_mdlID = 0;
		m_mdlDbID = 0;
		m_format = TargetFormat::UNKNOWN;
		m_overwrite = false;
	}
};