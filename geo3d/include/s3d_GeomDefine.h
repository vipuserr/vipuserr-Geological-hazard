#ifndef _S3D_GEOMDEFINE_H
#define _S3D_GEOMDEFINE_H

#include <gme_Ref.h>
#include <osg/Vec3d>
#include <s3d_Math.h>
#include "gme_vector2.h"
#include "gme_vector3.h"
#include "gme_vector4.h"
#include <s3d_KerMathDef.h>
#include "gmeMdl.h"

#include <vector>
using namespace std;

#define S3D_QUOTE(x) #x
#define S3D_QUOTE2(x) QTN_QUOTE_(x)
#define S3D_UNUSED(x) (void)x;

typedef enum enumTpGeoType
{
	enumTP_GEOM_UNKNOWN = 0			//未知类型
	, enumTP_GEOM_TABLE = 1			//表格
	, enumTP_GEOM_PNT = 2			//点
	, enumTP_GEOM_LIN = 3			//线
	, enumTP_GEOM_REG = 4			//多边形
	, enumTP_GEOM_TEXT = 5			//注记
	, enumTP_GEOM_GROUP = 6			//混合
	, enumTP_GEOM_Blk = 7			//组合块
	, enumTP_GEOM_MPNT = 8			//多点
	, enumTP_GEOM_MLIN = 9			//多线
	, enumTP_GEOM_MREG = 10			//多面
	, enumTP_GEOM_PNT3D = 11	    //三维点
	, enumTP_GEOM_LIN3D = 12		//三维线
	, enumTP_GEOM_REG3D = 13		//三维多边形
	, enumTP_GEOM_SURFACE3D = 14	//三维面
	, enumTP_GEOM_ENTITY3D = 15		//三维实体
}enumTpGeoType;

namespace Smart3dMap 
{

	typedef unsigned long  s_unlong;

	template <class T>
	using s3d_Vector = std::vector<T>;

	class sm3d_Entity;
	class sm3d_Surface;
	class s3d_Polygon;
	class s3d_Polygon3D;
	class s3d_Polyline;
	class s3d_Polyline3D;

	typedef s3d_Pointer<gmeEntity>      EnyRef;
	typedef s3d_Pointer<gmeSurface>     SurRef;
	typedef s3d_Pointer<s3d_Polygon>    PolyRef;
	typedef s3d_Pointer<s3d_Polygon3D>  Poly3DRef;
	typedef s3d_Pointer<s3d_Polyline>   PolyLinRef;
	typedef s3d_Pointer<s3d_Polyline3D> PolyLin3DRef;

	//class s3d_Rect;
	class s3d_Point;




	// 几何基类
	class LIB_GMKERMATH_EXP s3d_GeomBase: public s3d_Ref
	{
	public:
		s3d_GeomBase();
		virtual ~s3d_GeomBase();
		s3d_GeomBase( const s3d_GeomBase &geom );
		s3d_GeomBase &operator=( const s3d_GeomBase &geom );
		virtual enumTpGeoType GetType() const;
		virtual void Clear() = 0;
		virtual bool isEmpty() const;
		//virtual s3d_Rect boundingBox() const;
	};

	// 二维点
	class LIB_GMKERMATH_EXP s3d_Point : public s3d_GeomBase
	{
	public:
		s3d_Point(double x = 0.0, double y = 0.0, double z = 0.0);
		explicit s3d_Point(const gme_vector2d &pt);
		~s3d_Point();

		bool operator==( const s3d_GeomBase &other ) const;
		bool operator!=( const s3d_GeomBase &other ) const;

		double x() const { return mX; }
		double y() const { return mY; }
		double z() const { return mZ; }

		void setX( double x ) {mX = x;}
		void setY( double y ) {mY = y;}
		void setZ( double z ) {mZ = z;}
		void Clear();

		string   geometryType() const;

	private:
	   double mX;
	   double mY;
	   double mZ;
	};

	//二维折线
	class LIB_GMKERMATH_EXP s3d_Polyline: public s3d_GeomBase
	{
	public:
		s3d_Polyline();
		virtual ~s3d_Polyline();

	public:
		void New(s_unlong dotNum, gme_vector2d **pXY);
		int set(gme_vector2d *pXY, s_unlong dotNum);
		gme_vector2d *xy() const;
		s_unlong  dotNum() const;

	public:
		s3d_Polyline & operator =(s3d_Polyline &PolylineObj);
		bool operator==( const s3d_GeomBase &other ) const;
		bool operator!=( const s3d_GeomBase &other ) const;
		bool equals( const s3d_GeomBase &other ) const;
		bool isEmpty() const;
		void Clear();

		string geometryType() const;
		enumTpGeoType GetType() const;

		inline const s3d_Polyline *cast( const s3d_GeomBase *geom ) const;

	private:
		friend class s3d_Polygon;

	private:
		gme_vector2d      * m_pXY; //点序列
		s_unlong            m_Num; //点数目
	};

	//三维折线
	class LIB_GMKERMATH_EXP s3d_Polyline3D: public s3d_GeomBase
	{
	public:
		s3d_Polyline3D();
		virtual ~s3d_Polyline3D();

	public:
		// 申请数据空间
		void New(s_unlong dotNum, gme_vector3d **pXYZ);

		// 设置折线数据
		int set(gme_vector3d *pXYZ, s_unlong dotNum);

		// 获取折线点序列
		gme_vector3d *xyz();

		// 折线点数目
		s_unlong dotNum();

	public:
		// 赋值=重载
		s3d_Polyline3D & operator =(s3d_Polyline3D &PolylineObj);

		// 获取二维矩形范围
		// int  GetBox(s3d_Rect &rect);

		// 获取二维矩形范围
		int  GetBox(gme_rect_3d &rect3d);

		// 返回几何类型
		virtual enumTpGeoType GetType() const override;

		// 清空对象
		void Clear();

	private:
		gme_vector3d     * m_pXYZ; //点序列
		s_unlong           m_Num;  //点数目
	};


	//二维多边形数据类定义 (约定第一个存外圈多边形，后面的是内圈多边形（可以没有内圈) )
	class LIB_GMKERMATH_EXP s3d_Polygon: public s3d_GeomBase
	{
	public:
		s3d_Polygon();
		s3d_Polygon(gme_vector2d *pXY, s_unlong *pNe, s_unlong neLen);
		s3d_Polygon(vector<vector<gme_vector2d>>& poly);
		virtual ~s3d_Polygon();

	public:
		// 设置多边形数据
		int set( gme_vector2d *pXY,  s_unlong *pNe, s_unlong neLen );
		int set(vector<vector<gme_vector2d>>& poly);

		int get(vector<vector<gme_vector2d>>& poly);

		// 获取多边形点序列
		gme_vector2d *xy() const;

		// 多边形每圈的点数目
		s_unlong *ne() const;

		// 多边形圈数
		s_unlong neLen() const;

		// 所有的点数目
		s_unlong BufLen() const;

	public:
		// 赋值=重载
		s3d_Polygon & operator =(s3d_Polygon &PolygonObj);

		// 获取二维矩形范围
		int  GetBox(gme_rect_2d &rect);

		bool operator==( const s3d_GeomBase &other ) const;
		bool operator!=( const s3d_GeomBase &other ) const;

		enumTpGeoType GetType() const;

		void Clear();

		string   geometryType() const;
		bool     isEmpty() const;

	private:
		gme_vector2d      * m_pXY;
		s_unlong          * m_pNe;
		s_unlong            m_neLen;
		s_unlong            m_allDotNum;
	};

	//三维多边形数据类定义 (约定第一个存外圈多边形，后面的是内圈多边形（可以没有内圈) )
	class LIB_GMKERMATH_EXP s3d_Polygon3D: public s3d_GeomBase
	{
	public:
		s3d_Polygon3D();
		s3d_Polygon3D(gme_vector3d *pXY, s_unlong *pNe, s_unlong neLen);
		s3d_Polygon3D(vector<vector<gme_vector3d>>& poly);

		virtual ~s3d_Polygon3D();
		// 设置多边形数据
		int set( gme_vector3d *pXYZ,  s_unlong *pNe, s_unlong neLen );
		int set(vector<vector<gme_vector3d>>& poly);

		int get(vector<vector<gme_vector3d>>& poly);

		// 获取多边形点序列
		gme_vector3d *xyz();

		// 多边形每圈的点数目
		s_unlong *ne();

		// 多边形圈数
		s_unlong neLen();

		// 所有的点数目
		s_unlong BufLen();

	public:
		// 赋值=重载
		s3d_Polygon3D & operator =(s3d_Polygon3D &PolygonObj);

		// 获取二维矩形范围
		int  GetBox(gme_rect_3d &rect3d);

	public:
		// 返回几何类型
		enumTpGeoType GetType() const override;

		// 清空对象
		void Clear();

	private:
		gme_vector3d     * m_pXYZ;
		s_unlong         * m_pNe;
		s_unlong           m_neLen;
		s_unlong           m_allDotNum;
	};

	//三维面数据类定义
	class LIB_GMKERMATH_EXP sm3d_Surface: public s3d_GeomBase
	{
	public:
		sm3d_Surface();
		sm3d_Surface(sm3d_Surface& copy);
		virtual ~sm3d_Surface();
	public:
		// 构造一个三维面
		int set(int PntNum, gme_vector3d * pPnts, int TriNum, gme_triangle * pTris,
				gme_triangle_top * pTriTopos = NULL,s_unlong * pColors = NULL,
				gme_vector3d * pNormals = NULL, gme_vector2d * pTextures = NULL, int TextLayerNum = 0  );
	public:
		int GetPointNum();
		//获取顶点数目

		int set_pnt_num(int nPntNum);
		//设置顶点数目

		gme_vector3d* GetPointsPtr();
		//获取顶点序列内容，长度为m_PntNum

		int set_pnts(gme_vector3d * pDots);
		//设置顶点序列内容，长度为m_PntNum

		int GetTriangleNum();
		//获取三角形数目

		int set_tri_num(int nTriNum);
		//设置三角形数目

		gme_triangle* getTrianglesPtr();
		//获取三角形顶点序列内容，长度为m_TriNum

		int set_tris(gme_triangle * pTris);
		//设置三角形顶点序列内容，长度为m_TriNum

		gme_triangle_top* getTriangleTopsPtr();
		//获取三角形各边对应的序列内容，长度为m_TriNum

		int set_tri_tops(gme_triangle_top * pTopos);
		//设置三角形各边对应的序列内容，长度为m_TriNum

		s_unlong* GetColors();
		//获取顶点颜色内容，长度为m_PntNum

		int set_colors(s_unlong* pColors);
		//设置顶点颜色内容，长度为m_PntNum

		gme_vector3d* GetNormalsPtr();
		//获取顶点法向量内容，长度为m_PntNum

		int set_normals(gme_vector3d * pNormals);
		//设置顶点法向量内容，长度为m_PntNum

		gme_vector2d* GetTexCoordsPtr();
		//获取顶点纹理坐标（u，v）内容，长度为m_PntNum

		int set_texcoords(gme_vector2d * pTextures);
		//设置顶点纹理坐标（u，v）内容，长度为m_PntNum

		int GetTexLayerNum();
		//获取纹理坐标层数

		int SetTextLayerNum(int nTextLayerNum);
		//设置纹理坐标层数

		s3d_GeomBase *clone() const;
		// s3d_Rect boundingBox() const;
		string geometryType() const;

	public:
		sm3d_Surface & operator =(sm3d_Surface &surfObj);
		// 赋值=重载

		bool operator==( const s3d_GeomBase &other ) const;
		bool operator!=( const s3d_GeomBase &other ) const;

		int  GetBox(gme_rect_2d &rect);
		// 获取二维矩形范围

		int  GetBox(gme_rect_3d &rect3d);
		// 获取三维矩形范围

	public:
		// 返回几何类型
		enumTpGeoType GetType() const override;

		// 清空对象
		void Clear();

	private:
		int                  m_PntNum;             //顶点数目
		gme_vector3d       * m_pPnts;              //顶点序列内容，长度为m_PntNum
		int                  m_TriNum;             //三角形数目
		gme_triangle       * m_pTris;              //三角形顶点序列内容，长度为m_TriNum
		gme_triangle_top   * m_pTriTopos;          //三角形各边对应的序列内容，长度为m_TriNum
		s_unlong           * m_pColors;            //顶点颜色内容，长度为m_PntNum
		gme_vector3d       * m_pNormals;           //顶点法向量内容，长度为m_PntNum
		gme_vector2d       * m_pTextures;          //顶点纹理坐标（u，v）内容，长度为m_PntNum
		int                  m_TextLayerNum;       //纹理坐标层数
	};

	//三维结构体数据类定义
	class LIB_GMKERMATH_EXP sm3d_Entity : public s3d_GeomBase
	{
	public:
		sm3d_Entity();
		sm3d_Entity(sm3d_Entity& eny);
		virtual ~sm3d_Entity();

	public:
		int GetSurfaceNum() const;
		// 获取体的面数据数目

		sm3d_Surface * GetSurface( int idx );
		// 获取第idx个面数据，其中idx = 0,1,2，...，

		sm3d_Surface * AddSurface();
		// 向体对象中添加面数据，申请一个空的三维面对象

		int AddSurface(sm3d_Surface * psurObj );
		int AddSurface(sm3d_Surface & surfObj );
		// 向体对象中添加面数据,返回面数据索引=0,1,2...

		int UpdateSurf( int idx, sm3d_Surface & surfObj );
		// 更新体对象的第idx个面数据

		int DeleteSurf( int idx );
		// 删除第idx个面数据

		sm3d_Entity & operator =(sm3d_Entity &entyObj);
		// 赋值=重载

		// int  GetBox(s3d_Rect &rect);
		// 获取二维矩形范围

		int  GetBox(gme_rect_3d &rect3d);
		// 获取三维矩形范围

	public:
		// 返回几何类型
		enumTpGeoType GetType() const override;

		// 清空对象
		void Clear();

	private:
		vector<sm3d_Surface*>    m_SurfaceList; //内部面列表
	};
}

#endif //_S3D_GEOMDEFINE_H