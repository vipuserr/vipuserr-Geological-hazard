#pragma once

#include <gm_KerAttMdlDef.h>
#include <gme_vector3.h>
#include <gme_vector4.h>
#include <gmeStru.h>
using namespace std;

namespace Smart3dMap
{
	const   double  g_Invalid = -999999; //无效值，非法点，结构外，不显示
	const   double  g_Initval = -1;      //无效属性，结构内，没有合法的属性值，需要显示

	//样本数据结构
	struct attDataStru
	{
		string        strlayer; //地层编码
		gme_vector4d  d4dot;    //样本点数据
	public:
		attDataStru()
		{
			strlayer = "";
		}
	};

	//属性建模参数结构
	struct attMdlParam
	{
		double  dx; //x方向格网步长
		double  dy; //y方向格网步长
		double  dz; //z方向格网步长
		char    ctype;   //插值类型
		double  radius;  //样本影响半径
		string  attName; //模型名称
	public:
		attMdlParam()
		{
			dx = 1.0; //x方向格网步长
			dy = 1.0; //y方向格网步长
			dz = 1.0; //z方向格网步长
			ctype  = 1; //插值类型
			radius = 0; //样本影响半径
			attName = "";
		}
	};

	//  属性格网索引
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
		short	RowNo;    //行i
		short	ColNo;    //列j
		short	DepNo;    //深k
		short   StrNo;    //地层编码
	};
}