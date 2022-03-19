#pragma once

#include<vector>
#include "osgformatconv_global.h"


/**
 * 各种参数设置
 * @param iTextureMode (in) =0 使用图像数据格式 (默认), >0 启用压缩纹理的使用
 *							1 使用 OpenGL ARB 压缩纹理 (若启用，常用)；
 *							2 使用 S3TC DXT1 压缩纹理；
 *							3 使用 S3TC DXT3 压缩纹理；
 *							4 使用 S3TC DXT5 压缩纹理
 *
 * @param iTransparencyMode (in) =0 不透明，>0 修正不透明状态属性。
 *								 1 MAKE_OPAQUE_TEXTURE_STATESET_OPAQUE 模式(若启用，常用)；
 *								 2 MAKE_ALL_STATESET_OPAQUE 模式
 *								 
 * @param strSim (in) 参数必须是归一化的值，以减少百分比
 *					  例：0.5  将产生减少了50％的模型
 *
 * @param strOri (in) 将输入文件的几何体变换方位后转换到输出文件
 *					  定位方向的格式参数：X1,Y1,Z1-X2,Y2,Z2  or  degrees-A0,A1,A2
 *					  X1，Y1，Z1表示输入文件垂直轴的向量，X2，Y2，Z2表示输出文件垂直轴的向量；
 *					  degrees表示绕轴(A0，A1，A2)旋转的角度。
 *					  例：0,1,0-0,0,1  or  -90-1,0,0
 *					  将一个Y轴为垂直轴的坐标系统下的模型转换到Z轴为垂直轴的坐标系下
 *
 * @param strScale (in) 缩放模型的尺寸
 *						缩放的参数格式：SX，SY，SZ
 *						SX，SY，SZ表示缩放因子
 *						注：放缩是在目标文件的坐标系下完成的
 *
 * @param strTrans (in) 转换输出文件的空间位置信息
 *						平移的参数格式：X，Y，Z
 *						X，Y，Z表示世界空间下的绝对坐标
 *
  * @param strPrecision (in) 浮点数精度值设置
 *						   = -1 使用科学记数法格式输出数据(默认)
 *
 * @param smooth (in) 为每个Geometry生成顶点法向，使模型表面光滑
 * @param useWorldFrame (in) 在世界框架中执行转换，而不是相对于边界球体的中心执行转换
 * @param pruneStateSet (in) 例 生成*.obj文件时，去除纹理材质，*.mtl文件为空
 * @param addMissingColors  (in) 为没有颜色的Geometry添加颜色(白色)
 * @param do_overallNormal  (in) 用单一法向量替代所有法向量
 * @param enableObjectCache (in) 启用对象、图像等的缓存
 *
 * @author hxn
 */

struct OSGFORMATCONV_EXPORT sConvPara
{
	sConvPara()
	{
		iTextureMode = 0;
		iTransparencyMode = 0;

		strSim = "";
		strOri = "";
		strScale = "";
		strTrans = "";
		strPrecision = "";

		smooth = false;
		useWorldFrame = false;
		pruneStateSet = false;
		addMissingColors = false;
		do_overallNormal = false;
		enableObjectCache = false;
	}
	
	int iTextureMode;
	int iTransparencyMode;
	
	std::string strSim;
	std::string strOri;
	std::string strScale;
	std::string strTrans;
	std::string strPrecision;

	bool smooth;
	bool useWorldFrame;
	bool pruneStateSet;
	bool addMissingColors;
	bool do_overallNormal;
	bool enableObjectCache;
};

class OSGFORMATCONV_EXPORT OSGconv
{
public:
	OSGconv(void){}
	~OSGconv(){}

	/**
	 * osg格式数据转换与压缩
	 * @param fileNameList (in) 一或多 *.osg格式文件路径，最后一个为输出格式模型路径
	 * @param dataPara (in)  各种参数设置
	 * @author hxn
	 */
	static long OsgVarDataConv(std::vector<std::string> fileNameList, const sConvPara& dataPara);

	double GetLoadFilesTime();
	
private:
	static double m_LoadFilesTime;  //加载文件的时间,单位ms
};

