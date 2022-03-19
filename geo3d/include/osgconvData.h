#pragma once

#include<vector>
#include "osgformatconv_global.h"


/**
 * ���ֲ�������
 * @param iTextureMode (in) =0 ʹ��ͼ�����ݸ�ʽ (Ĭ��), >0 ����ѹ�������ʹ��
 *							1 ʹ�� OpenGL ARB ѹ������ (�����ã�����)��
 *							2 ʹ�� S3TC DXT1 ѹ������
 *							3 ʹ�� S3TC DXT3 ѹ������
 *							4 ʹ�� S3TC DXT5 ѹ������
 *
 * @param iTransparencyMode (in) =0 ��͸����>0 ������͸��״̬���ԡ�
 *								 1 MAKE_OPAQUE_TEXTURE_STATESET_OPAQUE ģʽ(�����ã�����)��
 *								 2 MAKE_ALL_STATESET_OPAQUE ģʽ
 *								 
 * @param strSim (in) ���������ǹ�һ����ֵ���Լ��ٰٷֱ�
 *					  ����0.5  ������������50����ģ��
 *
 * @param strOri (in) �������ļ��ļ�����任��λ��ת��������ļ�
 *					  ��λ����ĸ�ʽ������X1,Y1,Z1-X2,Y2,Z2  or  degrees-A0,A1,A2
 *					  X1��Y1��Z1��ʾ�����ļ���ֱ���������X2��Y2��Z2��ʾ����ļ���ֱ���������
 *					  degrees��ʾ����(A0��A1��A2)��ת�ĽǶȡ�
 *					  ����0,1,0-0,0,1  or  -90-1,0,0
 *					  ��һ��Y��Ϊ��ֱ�������ϵͳ�µ�ģ��ת����Z��Ϊ��ֱ�������ϵ��
 *
 * @param strScale (in) ����ģ�͵ĳߴ�
 *						���ŵĲ�����ʽ��SX��SY��SZ
 *						SX��SY��SZ��ʾ��������
 *						ע����������Ŀ���ļ�������ϵ����ɵ�
 *
 * @param strTrans (in) ת������ļ��Ŀռ�λ����Ϣ
 *						ƽ�ƵĲ�����ʽ��X��Y��Z
 *						X��Y��Z��ʾ����ռ��µľ�������
 *
  * @param strPrecision (in) ����������ֵ����
 *						   = -1 ʹ�ÿ�ѧ��������ʽ�������(Ĭ��)
 *
 * @param smooth (in) Ϊÿ��Geometry���ɶ��㷨��ʹģ�ͱ���⻬
 * @param useWorldFrame (in) ����������ִ��ת��������������ڱ߽����������ִ��ת��
 * @param pruneStateSet (in) �� ����*.obj�ļ�ʱ��ȥ��������ʣ�*.mtl�ļ�Ϊ��
 * @param addMissingColors  (in) Ϊû����ɫ��Geometry�����ɫ(��ɫ)
 * @param do_overallNormal  (in) �õ�һ������������з�����
 * @param enableObjectCache (in) ���ö���ͼ��ȵĻ���
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
	 * osg��ʽ����ת����ѹ��
	 * @param fileNameList (in) һ��� *.osg��ʽ�ļ�·�������һ��Ϊ�����ʽģ��·��
	 * @param dataPara (in)  ���ֲ�������
	 * @author hxn
	 */
	static long OsgVarDataConv(std::vector<std::string> fileNameList, const sConvPara& dataPara);

	double GetLoadFilesTime();
	
private:
	static double m_LoadFilesTime;  //�����ļ���ʱ��,��λms
};

