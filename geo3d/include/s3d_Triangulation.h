#pragma once
#include <vector>
using namespace std;

#include <s3d_KerTrigDef.h>
#include <gme_vector3.h>
#include <gmeStru.h>

namespace Smart3dMap{

class LIB_S3DKERINTERPIDW_EXP DelaunayTriCls
{
public:
    DelaunayTriCls(void);
    ~DelaunayTriCls(void);
public:
    //全局三角化算法
    void DoTriangulation( vector<gme_vector3d>         * pOutBdary,     //输入参数:外边界（闭合线）
                          vector<vector<gme_vector3d>> * pCtrlLines,    //输入参数:控制线（闭合或非闭合折线）
                          vector<vector<gme_vector3d>> * pInnerBodary,  //输入参数:内边界（闭合线）
                          vector<gme_vector3d>         * pHoleVec,      //输入参数:空洞点（没有则传空）
                          vector<gme_vector3d>         * pCtrlDots,     //输入参数:离散点（没有则传空）
                          vector<gme_vector3d>         & outPntsVec,    //输出参数:三角网顶点
                          vector<gme_triangle>       & outTrisVec,    //输出参数:三角网顶点
                          vector<gme_triangle_top>   & outToposVec,   //输出参数:三角网顶点
                          double * pMaxArea = NULL, double * pMinAngle= NULL); //输入参数：三角形最大面积/三角形最小角度

    //全局三角化算法
    void DoTriangulation( vector<gme_vector3d> * pOuterBoundary,        //输入参数:外边界（闭合线）
                          vector<vector<gme_vector3d>>* pCtrlLines,     //输入参数:控制线（闭合或非闭合折线）
                          vector<vector<gme_vector3d>>* pInnerBoundary, //输入参数:内边界（闭合线）
                          gme_vector3d * pHoleDots, int nHoleNum,       //输入参数:空洞点
                          gme_vector3d * pCtrlDots, int nCtrlDotsNum,   //输入参数:离散点
                          int& nDotNum, gme_vector3d **ppDots,          //输出参数:三角网顶点
                          int& nTriNum, gme_triangle **ppTris, gme_triangle_top**ppTopos,  //输出参数:三角网三角形结构
                          double * pMaxArea = NULL, double * pMinAngle= NULL);   //输入参数：三角形最大面积/三角形最小角度

    //对分配的内存进行释放
    void ReleaseDatas(gme_vector3d* pDots, gme_triangle* pTris, gme_triangle_top* pTriTopos);
};

}
