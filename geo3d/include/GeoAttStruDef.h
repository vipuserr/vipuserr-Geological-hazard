#pragma once

#include <gm_KerAttMdlDef.h>
#include <gme_vector3.h>
#include <gme_vector4.h>
#include <gmeStru.h>
using namespace std;

namespace Smart3dMap
{
	const   double  g_Invalid = -999999; //��Чֵ���Ƿ��㣬�ṹ�⣬����ʾ
	const   double  g_Initval = -1;      //��Ч���ԣ��ṹ�ڣ�û�кϷ�������ֵ����Ҫ��ʾ

	//�������ݽṹ
	struct attDataStru
	{
		string        strlayer; //�ز����
		gme_vector4d  d4dot;    //����������
	public:
		attDataStru()
		{
			strlayer = "";
		}
	};

	//���Խ�ģ�����ṹ
	struct attMdlParam
	{
		double  dx; //x�����������
		double  dy; //y�����������
		double  dz; //z�����������
		char    ctype;   //��ֵ����
		double  radius;  //����Ӱ��뾶
		string  attName; //ģ������
	public:
		attMdlParam()
		{
			dx = 1.0; //x�����������
			dy = 1.0; //y�����������
			dz = 1.0; //z�����������
			ctype  = 1; //��ֵ����
			radius = 0; //����Ӱ��뾶
			attName = "";
		}
	};

	//  ���Ը�������
	struct  attIndex
	{
	public:
		attIndex()
		{
			RowNo = -1;
			ColNo = -1;
			DepNo = -1;
			StrNo = -1;
		}
		void reset()
		{
			RowNo = -1;
			ColNo = -1;
			DepNo = -1;
			StrNo = -1;
		}

	public:
		short	RowNo;    //��i
		short	ColNo;    //��j
		short	DepNo;    //��k
		short   StrNo;    //�ز����
	};
}