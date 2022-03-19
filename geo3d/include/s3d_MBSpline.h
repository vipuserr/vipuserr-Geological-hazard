// Desc:    多层B样条的散乱数据插值
#pragma  once

#include "s3d_KerInterpMBSplineDef.h"
#include "gmestru.h"

#include <vector>
using namespace std;

using namespace Smart3dMap;

class	CBSplineInterpolateObj;

class LIB_S3DKERINTERPMBSPLINE_EXP CMutilBSplineObj
{
	public:
		CMutilBSplineObj();
		~CMutilBSplineObj();

		//////////////////////////////////////////////////////////////////////////
		//			MBA algorithm: 求所有层控制点函数值
		//			入口:*ScatteredPnt(散乱数据),PntNum(数据点个数),
		//				 lLayNum(层数),M1(x方向网格个数),N1(y方向网格个数),
		//				 *rect(控制网格矩形域)
		//				 bIsCalInValidCtrlPnt(是否计算无效的控制点)
		//			出口:
		//			返回值:成功/失败  1/0
		//		
		//////////////////////////////////////////////////////////////////////////
		long    setdata(gme_vector3d * ScatteredPnt,long PntNum,
						long lLayNum=4,long M=8,long N=8,
						gme_rect_2d *pRect=NULL,
						bool bIsCalInValidCtrlPnt=0,long lCalM=0,long lCalN=0);

		
		/////////////////////////////////////MBA插值///////////////////////////////////////
		//							插值函数
		//			入口:*rect(控制网格矩形域)
		//				 &Ix(插值点x坐标),&Iy(插值点y坐标)
		//			出口:&Iz(多层B样条插值结果,z坐标)
		//			返回值:0 //失败
		//				   1 //待插值点周围无有效网格点,返回值为无效值
		//				   2 //待插值点周围存在有效网格点,以有效网格为准,返回值有效	
		//				   3 //无论待插值点周围是否存在有效网格点,返回值有效(即bIsCalInValidCtrlPnt为1)	
		//		
		////////////////////////////////////////////////////////////////////////////////////
		//注意:如果rect == NULL,点(Ix,Iy)必须位于样本数据(ScatteredPnt)的包围盒范围内
		//	   如果rect != NULL,点(Ix,Iy)必须位于rect范围内
		long interpolate_a_pnt(double x,double y,double &z);

	private:
		long NewSampleDots(gme_vector3d * ScatteredPnt,long PntNum,
							bool bIsCalInValidCtrlPnt=0,long lCalM=0,long lCalN=0);
	private:
		vector<CBSplineInterpolateObj*> m_SingleBSplieObjVec; 
		long m_bIsCalInValidCtrlPnt;
		long m_lLayNum;
		long m_lM;
		long m_lN;
		gme_rect_2d	m_dataRect;
		gme_vector3d *m_pSampleDots;
		long m_lSampDotNum;
	};
