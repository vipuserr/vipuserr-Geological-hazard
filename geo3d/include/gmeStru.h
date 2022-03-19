#pragma once

#include "s3dGMdlDBEngineExp.h"
#include "gmeDef.h"

//新增点的结构定义 
#include "gme_vector2.h"
#include "gme_vector3.h"
#include "gme_vector4.h"

#include <windows.h>

namespace Smart3dMap
{
	//==========================时间结构定义==============================================================
	typedef struct gme_date
	{
		short  year;//年
		char   mon;	//月
		char   day;	//日
	}gme_date;


	typedef struct gme_time
	{
		char   hour;//时
		char   min;	//分
		double sec;	//秒
	}gme_time;

	typedef struct	OG_GME_API gme_date_time
	{
		short          year ;
		unsigned short month : 4;
		unsigned short day : 6;
		unsigned short hour : 6;
		char  minute;
		char  second;
		long  fraction;
		gme_date_time()
		{
			year = 0;
			month = 0;
			day = 0;
			hour = 0;
		}
		gme_date_time& operator = (const gme_date_time& gme);
		gme_date_time& operator = (const SYSTEMTIME& gme);
	}gme_date_time;

	gme_date_time sastringToDate(std::string date);
	//2.1 空间参照系的结构:
	typedef struct gme_sref
	{
		GME_TYPE_OBJ_ID ID;		//空间参照系的ID号
		GString			name;	//空间参照系的名称
		short			srType;	//空间参照系的类型
	}gme_sref;


	//视图信息，参考Google
	typedef struct gme_lookat
	{	
	public:
		double 		m_dx;					//位置x
		double		m_dy;					//位置y
		double		m_Distance;			    //距离
		double		m_Heading;			    //方位
		double  	m_Tilt;				    //倾斜
	}gme_lookat;

	//海拔高度设置
	class gme_altitude
	{
	public:
		gme_altitude()
		{
			m_AltitudeMode =  GME_CLOSE_TO_GROUND;
			m_Height = 0;
			m_Extend = 0;
		}
		GME_GROUND_MODE		m_AltitudeMode;	//高度模式
		double				m_Height;		//高度，模式为 AM_CLOSE_TO_GROUND时不使用
		bool				m_Extend;		//预留：是否延伸至地面(为true当标注位于地面上则生成一条从标注到地面的连接线)
	};



	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// 角度定义与转换封装类

	class gme_degree;
	// 1、弧度的封装类，这个类包括了与度数类之关的自动转换
	class OG_GME_API gme_radian
	{
		GREAL m_Rad;
	public:
		explicit gme_radian(GREAL r = 0) : m_Rad(r) {}
		gme_radian (const gme_degree& d);

		const gme_radian& operator = (const GREAL& f) { m_Rad = f; return *this; }
		const gme_radian& operator = (const gme_radian& r) { m_Rad = r.m_Rad; return *this; }
		const gme_radian& operator = (const gme_degree& d);

		GREAL ValueDegrees() const { return GME_ToDegree(m_Rad); }
		GREAL ValueRadians() const { return m_Rad; }

		gme_radian	operator +	(const gme_radian& r) const { return gme_radian(m_Rad + r.m_Rad); }
		gme_radian	operator +	(const gme_degree& d) const;
		gme_radian& operator += (const gme_radian& r) { m_Rad += r.m_Rad; return *this; }
		gme_radian& operator += (const gme_degree& d);
		gme_radian	operator -	() { return gme_radian(-m_Rad); }
		gme_radian	operator -	(const gme_radian& r) const { return gme_radian(m_Rad - r.m_Rad); }
		gme_radian	operator -	(const gme_degree& d) const;
		gme_radian& operator -= (const gme_radian& r) { m_Rad -= r.m_Rad; return *this; }
		gme_radian& operator -= (const gme_degree& d) ;
		gme_radian	operator *	(GREAL f) const { return gme_radian(m_Rad * f); }
		gme_radian	operator *	(const gme_radian& f) const { return gme_radian(m_Rad * f.m_Rad); }
		gme_radian& operator *= (GREAL f) { m_Rad *= f; return *this; }
		gme_radian	operator /	(GREAL f) const { return gme_radian(m_Rad / f); }
		gme_radian& operator /= (GREAL f) { m_Rad /= f; return *this; }

		bool operator <  (const gme_radian& r) const { return m_Rad < r.m_Rad; }
		bool operator <= (const gme_radian& r) const { return m_Rad <= r.m_Rad; }
		bool operator == (const gme_radian& r) const { return m_Rad == r.m_Rad; }
		bool operator != (const gme_radian& r) const { return m_Rad != r.m_Rad; }
		bool operator >= (const gme_radian& r) const { return m_Rad >= r.m_Rad; }
		bool operator >  (const gme_radian& r) const { return m_Rad > r.m_Rad; }
	};


	// 2、度数的封装类，这个类包括了与弧度类之关的自动转换
	class OG_GME_API gme_degree
	{
		GREAL m_Deg; // if you get an error here - make sure to define/typedef 'GREAL' first

	public:
		explicit gme_degree(GREAL d = 0) : m_Deg(d) {}
		gme_degree(const gme_radian& r) : m_Deg(r.ValueDegrees()) {}

		const gme_degree& operator = (const GREAL& f) { m_Deg = f; return *this; }
		const gme_degree& operator = (const gme_degree& d) { m_Deg = d.m_Deg; return *this; }
		const gme_degree& operator = (const gme_radian& r) { m_Deg = r.ValueDegrees(); return *this; }

		GREAL ValueDegrees() const { return m_Deg; }
		GREAL ValueRadians() const { return GME_ToRadian(m_Deg); }

		gme_degree	operator +	(const gme_degree& d) const { return gme_degree(m_Deg + d.m_Deg); }
		gme_degree	operator +	(const gme_radian& r) const { return gme_degree(m_Deg + r.ValueDegrees()); }
		gme_degree& operator += (const gme_degree& d) { m_Deg += d.m_Deg; return *this; }
		gme_degree& operator += (const gme_radian& r) { m_Deg += r.ValueDegrees(); return *this; }
		gme_degree	operator -	() { return gme_degree(-m_Deg); }
		gme_degree	operator -	(const gme_degree& d) const { return gme_degree(m_Deg - d.m_Deg); }
		gme_degree	operator -	(const gme_radian& r) const { return gme_degree(m_Deg - r.ValueDegrees()); }
		gme_degree& operator -= (const gme_degree& d) { m_Deg -= d.m_Deg; return *this; }
		gme_degree& operator -= (const gme_radian& r) { m_Deg -= r.ValueDegrees(); return *this; }
		gme_degree	operator *	(GREAL f) const { return gme_degree(m_Deg * f); }
		gme_degree	operator *	(const gme_degree& f) const { return gme_degree(m_Deg * f.m_Deg); }
		gme_degree& operator *= (GREAL f) { m_Deg *= f; return *this; }
		gme_degree	operator /	(GREAL f) const { return gme_degree(m_Deg / f); }
		gme_degree& operator /= (GREAL f) { m_Deg /= f; return *this; }

		bool operator <  (const gme_degree& d) const { return m_Deg < d.m_Deg; }
		bool operator <= (const gme_degree& d) const { return m_Deg <= d.m_Deg; }
		bool operator == (const gme_degree& d) const { return m_Deg == d.m_Deg; }
		bool operator != (const gme_degree& d) const { return m_Deg != d.m_Deg; }
		bool operator >= (const gme_degree& d) const { return m_Deg >= d.m_Deg; }
		bool operator >  (const gme_degree& d) const { return m_Deg > d.m_Deg; }
	};
	
	//====================================double型==================

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// 角度定义与转换封装类

	class gme_degree_d;
	// 弧度的封装类，这个类包括了与度数类之关的自动转换
	class OG_GME_API gme_radian_d
	{
		GDOUBLE m_Rad;
	public:
		explicit gme_radian_d(GDOUBLE r = 0) : m_Rad(r) {}
		gme_radian_d(const gme_degree_d& d);

		const gme_radian_d& operator = (const GDOUBLE& f) { m_Rad = f; return *this; }
		const gme_radian_d& operator = (const gme_radian_d& r) { m_Rad = r.m_Rad; return *this; }
		const gme_radian_d& operator = (const gme_degree_d& d);

		GDOUBLE ValueDegrees() const { return GME_ToDegree(m_Rad); }
		GDOUBLE ValueRadians() const { return m_Rad; }

		gme_radian_d	operator +	(const gme_radian_d& r) const { return gme_radian_d(m_Rad + r.m_Rad); }
		gme_radian_d	operator +	(const gme_degree_d& d) const;
		gme_radian_d& operator += (const gme_radian_d& r) { m_Rad += r.m_Rad; return *this; }
		gme_radian_d& operator += (const gme_degree_d& d);
		gme_radian_d	operator -	() { return gme_radian_d(-m_Rad); }
		gme_radian_d	operator -	(const gme_radian_d& r) const { return gme_radian_d(m_Rad - r.m_Rad); }
		gme_radian_d	operator -	(const gme_degree_d& d) const;
		gme_radian_d& operator -= (const gme_radian_d& r) { m_Rad -= r.m_Rad; return *this; }
		gme_radian_d& operator -= (const gme_degree_d& d);
		gme_radian_d	operator *	(GDOUBLE f) const { return gme_radian_d(m_Rad * f); }
		gme_radian_d	operator *	(const gme_radian_d& f) const { return gme_radian_d(m_Rad * f.m_Rad); }
		gme_radian_d& operator *= (GDOUBLE f) { m_Rad *= f; return *this; }
		gme_radian_d	operator /	(GDOUBLE f) const { return gme_radian_d(m_Rad / f); }
		gme_radian_d& operator /= (GDOUBLE f) { m_Rad /= f; return *this; }

		bool operator <  (const gme_radian_d& r) const { return m_Rad < r.m_Rad; }
		bool operator <= (const gme_radian_d& r) const { return m_Rad <= r.m_Rad; }
		bool operator == (const gme_radian_d& r) const { return m_Rad == r.m_Rad; }
		bool operator != (const gme_radian_d& r) const { return m_Rad != r.m_Rad; }
		bool operator >= (const gme_radian_d& r) const { return m_Rad >= r.m_Rad; }
		bool operator >  (const gme_radian_d& r) const { return m_Rad > r.m_Rad; }
	};


	// 度数的封装类，这个类包括了与弧度类之关的自动转换
	class OG_GME_API gme_degree_d
	{
		GDOUBLE m_Deg; // if you get an error here - make sure to define/typedef 'GDOUBLE' first

	public:
		explicit gme_degree_d(GDOUBLE d = 0) : m_Deg(d) {}
		gme_degree_d(const gme_radian_d& r) : m_Deg(r.ValueDegrees()) {}

		const gme_degree_d& operator = (const GDOUBLE& f) { m_Deg = f; return *this; }
		const gme_degree_d& operator = (const gme_degree_d& d) { m_Deg = d.m_Deg; return *this; }
		const gme_degree_d& operator = (const gme_radian_d& r) { m_Deg = r.ValueDegrees(); return *this; }

		GDOUBLE ValueDegrees() const { return m_Deg; }
		GDOUBLE ValueRadians() const { return GME_ToRadian(m_Deg); }

		gme_degree_d	operator +	(const gme_degree_d& d) const { return gme_degree_d(m_Deg + d.m_Deg); }
		gme_degree_d	operator +	(const gme_radian_d& r) const { return gme_degree_d(m_Deg + r.ValueDegrees()); }
		gme_degree_d& operator += (const gme_degree_d& d) { m_Deg += d.m_Deg; return *this; }
		gme_degree_d& operator += (const gme_radian_d& r) { m_Deg += r.ValueDegrees(); return *this; }
		gme_degree_d	operator -	() { return gme_degree_d(-m_Deg); }
		gme_degree_d	operator -	(const gme_degree_d& d) const { return gme_degree_d(m_Deg - d.m_Deg); }
		gme_degree_d	operator -	(const gme_radian_d& r) const { return gme_degree_d(m_Deg - r.ValueDegrees()); }
		gme_degree_d& operator -= (const gme_degree_d& d) { m_Deg -= d.m_Deg; return *this; }
		gme_degree_d& operator -= (const gme_radian_d& r) { m_Deg -= r.ValueDegrees(); return *this; }
		gme_degree_d	operator *	(GDOUBLE f) const { return gme_degree_d(m_Deg * f); }
		gme_degree_d	operator *	(const gme_degree_d& f) const { return gme_degree_d(m_Deg * f.m_Deg); }
		gme_degree_d& operator *= (GDOUBLE f) { m_Deg *= f; return *this; }
		gme_degree_d	operator /	(GDOUBLE f) const { return gme_degree_d(m_Deg / f); }
		gme_degree_d& operator /= (GDOUBLE f) { m_Deg /= f; return *this; }

		bool operator <  (const gme_degree_d& d) const { return m_Deg < d.m_Deg; }
		bool operator <= (const gme_degree_d& d) const { return m_Deg <= d.m_Deg; }
		bool operator == (const gme_degree_d& d) const { return m_Deg == d.m_Deg; }
		bool operator != (const gme_degree_d& d) const { return m_Deg != d.m_Deg; }
		bool operator >= (const gme_degree_d& d) const { return m_Deg >= d.m_Deg; }
		bool operator >  (const gme_degree_d& d) const { return m_Deg > d.m_Deg; }
	};



	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

	// 矩阵应用定义：
	// 乘法定义 ---- 设有点P, 矩阵M, 则相乘结果定义为 P' = P * M, 与普通图形学中定义不同(P' = M * P)
	// 连接定义 ---- 设当前矩阵为M, 有M1, M2, M3..., 则连乘结果定义为 C = M * M1 * M2 * M3 * ...
	//					与普通图形学中定义不同(C = ... * M3 * M2 * M1 * M)
	//				所有效果矩阵由左到右相乘，则效果相应的从M1开始到M2,依次...
	
	class gme_matrix3;
	class OG_GME_API gme_quaternion
	{
	public:
		union {
			struct {
				GREAL x, y, z, w;
			};
			GREAL _v[4];
		};

	public:
		inline gme_quaternion(GREAL fW = 1.0, GREAL fX = 0.0, GREAL fY = 0.0, GREAL fZ = 0.0);
		inline gme_quaternion(const gme_quaternion& rkQ);

		// 从旋转矩阵构造四元数
		inline gme_quaternion(const gme_matrix3& rot);

		// 从旋转轴和角度构造四元数
		inline gme_quaternion(const gme_radian& rfAngle, const gme_vector3f& rkAxis);

		// 从三个正交轴构造四元数
		inline gme_quaternion(const gme_vector3f& xaxis, const gme_vector3f& yaxis, const gme_vector3f& zaxis);

		// 从三个正交轴构造四元数,　由数组提供数据
		inline gme_quaternion(const gme_vector3f* akAxis);

		// 旋转矩阵与四元数之间的转化
		void FromRotationMatrix(const gme_matrix3& kRot);
		void ToRotationMatrix(gme_matrix3& kRot) const;

		// (旋转轴, 角度) 与四元数之间的转化
		void FromAngleAxis(const gme_radian& rfAngle, const gme_vector3f& rkAxis);
		void ToAngleAxis(gme_radian& rfAngle, gme_vector3f& rkAxis) const;
		void ToAngleAxis(gme_degree& dAngle, gme_vector3f& rkAxis) const;

		// 正交轴与四元数之间的转换,　可能由数组提供数据
		void FromAxes(const gme_vector3f* akAxis);
		void FromAxes(const gme_vector3f& xAxis, const gme_vector3f& yAxis, const gme_vector3f& zAxis);
		void ToAxes(gme_vector3f* akAxis) const;
		void ToAxes(gme_vector3f& xAxis, gme_vector3f& yAxis, gme_vector3f& zAxis) const;

		// 获取当前四元数所含的X轴
		gme_vector3f xAxis(void) const;
		// 获取当前四元数所含的Y轴
		gme_vector3f yAxis(void) const;
		// 获取当前四元数所含的z轴
		gme_vector3f zAxis(void) const;

		inline gme_quaternion& operator= (const gme_quaternion& rkQ);
		gme_quaternion operator+ (const gme_quaternion& rkQ) const;
		gme_quaternion operator- (const gme_quaternion& rkQ) const;
		gme_quaternion operator* (const gme_quaternion& rkQ) const;
		gme_quaternion operator* (GREAL fScalar) const;
		gme_quaternion operator- () const;

		OG_GME_API friend gme_quaternion operator* (GREAL fScalar, const gme_quaternion& rkQ);

		inline bool operator== (const gme_quaternion& rhs) const;
		inline bool operator!= (const gme_quaternion& rhs) const;

		// 四元数自身操作
		// 点积
		GREAL DotProduct(const gme_quaternion& rkQ) const;

		// 长度的平方
		GREAL SquaredLength() const;

		// 单位化，并返回原来的长度
		GREAL Normalise(void);
		gme_quaternion Inverse() const;		// apply to non-zero gme_quaternion
		gme_quaternion UnitInverse() const;	// apply to unit-length gme_quaternion
		gme_quaternion Exp() const;
		gme_quaternion Log() const;

		// 用当前四元数所包含的旋转，旋转一个向量
		gme_vector3f operator* (const gme_vector3f& rkVector) const;

		// 计算并取得 Roll角
		gme_radian GetRoll(void) const;
		// 计算并取得 Picth角
		gme_radian GetPitch(void) const;
		// 计算并取得 Yaw角
		gme_radian GetYaw(void) const;
		// 以 tolerance 的角度容差判断两个四元数是否相等
		bool Equals(const gme_quaternion& rhs, const gme_radian& tolerance) const;

		// 球线性插值
		static gme_quaternion Slerp(GREAL fT, const gme_quaternion& rkP,
			const gme_quaternion& rkQ, bool shortestPath = false);

		static gme_quaternion SlerpExtraSpins(GREAL fT,
			const gme_quaternion& rkP, const gme_quaternion& rkQ,
			int iExtraSpins);

		// setup for spherical quadratic interpolation
		static void Intermediate(const gme_quaternion& rkQ0,
			const gme_quaternion& rkQ1, const gme_quaternion& rkQ2,
			gme_quaternion& rkA, gme_quaternion& rkB);

		// spherical quadratic interpolation
		static gme_quaternion Squad(GREAL fT, const gme_quaternion& rkP,
			const gme_quaternion& rkA, const gme_quaternion& rkB,
			const gme_quaternion& rkQ, bool shortestPath = false);

		// normalised linear interpolation - faster but less accurate (non-constant rotation velocity)
		static gme_quaternion NLerp(GREAL fT, const gme_quaternion& rkP,
			const gme_quaternion& rkQ, bool shortestPath = false);

		// cutoff for sine near zero
		static const GREAL ms_fEpsilon;

		// special values
		static const gme_quaternion ZERO;
		static const gme_quaternion IDENTITY;

	};

	class OG_GME_API gme_matrix3
	{
	public:
		union {
			struct {
				GREAL        _11, _12, _13;
				GREAL        _21, _22, _23;
				GREAL        _31, _32, _33;
			};
			GREAL m[3][3];
			GREAL _m[9];
		};

	public:

		static const gme_matrix3 ZERO;
		static const gme_matrix3 IDENTITY;

		friend class gme_matrix4;

		inline gme_matrix3() { LoadIdentity(); }
		inline explicit	gme_matrix3(const GREAL arr[3][3]);
		inline gme_matrix3(const gme_matrix3& mat);
		inline gme_matrix3(GREAL _f11, GREAL _f12, GREAL _f13,
			GREAL _f21, GREAL _f22, GREAL _f23,
			GREAL _f31, GREAL _f32, GREAL _f33);

		// 行存取操作
		inline GREAL* operator[] (size_t nRow) const;
		gme_vector3f GetRow(size_t nRow) const;
		void	SetRow(size_t nRow, const gme_vector3f& vec);

		// 列存取操作
		gme_vector3f GetColumn(size_t nCol) const;
		void	SetColumn(size_t nCol, const gme_vector3f& vec);

		// 通过本地XYZ来生成
		void	FromAxis(const gme_vector3f& xAxis, const gme_vector3f& yAxis, const gme_vector3f& zAxis);

		// 赋值
		inline gme_matrix3& operator = (const gme_matrix3& mat);

		// 比较
		inline bool operator == (const gme_matrix3& mat) const;
		inline bool operator != (const gme_matrix3& mat) const;

		// 操作
		inline gme_matrix3 operator + (const gme_matrix3& mat) const;
		inline gme_matrix3 operator - (const gme_matrix3& mat) const;
		inline gme_matrix3 operator * (const gme_matrix3& mat) const;
		inline gme_matrix3 operator - () const;

		// 矢量相乘
		gme_vector3f operator * (const gme_vector3f& vec) const;
		OG_GME_API friend gme_vector3f operator * (const gme_vector3f& vec, const gme_matrix3& mat);

		// 标量相乘
		gme_matrix3 operator * (GREAL fScalar) const;
		OG_GME_API friend gme_matrix3 operator * (GREAL fScalar, const gme_matrix3& mat);

		// 取当前矩阵的转置矩阵
		gme_matrix3 TransposeCopy() const;

		// 设置当前矩阵为转置矩阵
		void	Transpose();

		// 取伴随矩阵
		gme_matrix3	GetAdjoint() const;

		// 取行列值
		GREAL GetDeterminant() const;

		// 取逆矩阵
		bool GetInverse(gme_matrix3& mat) const;

		// 设置当前矩阵为逆矩阵
		void	SetToInverse();

		// 设置当前矩阵为单位矩阵
		inline void LoadIdentity(void);

		// 矩阵相乘，自身保存结果
		inline gme_matrix3 Multiply(const gme_matrix3& mat);

		// 施密特正交化　
		void Orthonormalize();

		// 以下操作必须在正交化的基础上
		// 转化为轴和角度
		void ToAxisAngle(gme_vector3f& vAxis, gme_radian& rad) const;
		void ToAxisAngle(gme_vector3f& vAxis, gme_degree& deg) const;

		// 从轴和角度转化
		void FromAxisAngle(const gme_vector3f& vAxis, const gme_radian& rad);
		void FromAxisAngle(const gme_vector3f& vAxis, const gme_degree& deg);

		// 转化为欧拉角
		bool ToEulerAnglesXYZ(gme_radian& rfYAngle, gme_radian& rfPAngle, gme_radian& rfRAngle) const;
		bool ToEulerAnglesXZY(gme_radian& rfYAngle, gme_radian& rfPAngle, gme_radian& rfRAngle) const;
		bool ToEulerAnglesYXZ(gme_radian& rfYAngle, gme_radian& rfPAngle, gme_radian& rfRAngle) const;
		bool ToEulerAnglesYZX(gme_radian& rfYAngle, gme_radian& rfPAngle, gme_radian& rfRAngle) const;
		bool ToEulerAnglesZXY(gme_radian& rfYAngle, gme_radian& rfPAngle, gme_radian& rfRAngle) const;
		bool ToEulerAnglesZYX(gme_radian& rfYAngle, gme_radian& rfPAngle, gme_radian& rfRAngle) const;

		// 从欧拉角转换
		void FromEulerAnglesXYZ(const gme_radian& fYAngle, const gme_radian& fPAngle, const gme_radian& fRAngle);
		void FromEulerAnglesXZY(const gme_radian& fYAngle, const gme_radian& fPAngle, const gme_radian& fRAngle);
		void FromEulerAnglesYXZ(const gme_radian& fYAngle, const gme_radian& fPAngle, const gme_radian& fRAngle);
		void FromEulerAnglesYZX(const gme_radian& fYAngle, const gme_radian& fPAngle, const gme_radian& fRAngle);
		void FromEulerAnglesZXY(const gme_radian& fYAngle, const gme_radian& fPAngle, const gme_radian& fRAngle);
		void FromEulerAnglesZYX(const gme_radian& fYAngle, const gme_radian& fPAngle, const gme_radian& fRAngle);


	};

	////////////////////////////////////////////////////////////
	class OG_GME_API gme_matrix4
	{
	public:
		union {
			struct {
				GREAL        _11, _12, _13, _14;
				GREAL        _21, _22, _23, _24;
				GREAL        _31, _32, _33, _34;
				GREAL        _41, _42, _43, _44;
			};
			GREAL m[4][4];
			GREAL _m[16];
		};
	public:

		static const gme_matrix4 ZERO;
		static const gme_matrix4 IDENTITY;

		inline gme_matrix4();
		inline gme_matrix4(const gme_matrix3& m3x3);
		inline gme_matrix4(const gme_quaternion& rot);


		inline gme_matrix4(GREAL m00, GREAL m01, GREAL m02, GREAL m03,
			GREAL m10, GREAL m11, GREAL m12, GREAL m13,
			GREAL m20, GREAL m21, GREAL m22, GREAL m23,
			GREAL m30, GREAL m31, GREAL m32, GREAL m33);

		//
		inline GREAL* operator [] (size_t nRow);
		inline const GREAL* operator [] (size_t nRow) const;

		//
		inline gme_matrix4& operator = (const gme_matrix4 &mat);
		inline gme_vector3f operator * (const gme_vector3f &v) const;
		inline gme_matrix4 operator * (const gme_matrix4 &mat) const;
		inline gme_matrix4 operator + (const gme_matrix4 &mat) const;
		inline gme_matrix4 operator - (const gme_matrix4 &mat) const;
		inline bool operator == (const gme_matrix4 &mat) const;
		inline bool operator != (const gme_matrix4 &mat) const;
		inline void operator = (const gme_matrix3& mat3);

		// 矩阵相乘，自身保存结果
		inline gme_matrix4 Multiply(const gme_matrix4& mat);

		// 连接一个矩阵 C = M * M1 * M2 * M3 ........
		// M 代表当前矩阵, 只返回结果,不修改当前矩阵
		inline gme_matrix4 MultiplyCopy(const gme_matrix4& mat) const;

		// 取当前矩阵的转置矩阵
		inline gme_matrix4 TransposeCopy(void) const;

		// 设置当前矩阵为转置矩阵
		inline void Transpose(void);

		// 设置当前矩阵为单位矩阵
		inline void LoadIdentity(void);

		// 设置当前矩阵的平移部分
		inline void SetTransPart(const gme_vector3f& v);

		// 取当前矩阵的平移部分
		inline gme_vector3f GetTransPart(void) const;

		// 重建为一个平移矩阵
		inline void MakeTrans(const gme_vector3f& v);
		inline void MakeTrans(GREAL vx, GREAL vy, GREAL vz);

		// 构造一个平移矩阵
		inline static gme_matrix4 BuildTrans(const gme_vector3f& v);
		inline static gme_matrix4 BuildTrans(GREAL vx, GREAL vy, GREAL vz);

		//　存取当前矩阵的缩放部分
		inline gme_vector3f	GetScalePart(void) const;
		inline void		SetScalePart(const gme_vector3f& v);

		// 建立缩放矩阵
		inline static gme_matrix4 BuildScale(const gme_vector3f& v);
		inline static gme_matrix4 BuildScale(GREAL vx, GREAL vy, GREAL vz);

		//　矩阵与标量相乘
		inline gme_matrix4 operator * (GREAL scalar);

		// 取伴随矩阵
		gme_matrix4	GetAdjoint() const;

		// 取行列值
		GREAL GetDeterminant() const;

		// 取逆矩阵
		gme_matrix4 GetInverse() const;

		// 设置当前矩阵为逆矩阵
		void	SetToInverse();


		// 当前矩阵与绕轴一定角度的旋转矩阵相乘
		inline void RotationX(gme_radian rad);
		inline void RotationY(gme_radian rad);
		inline void RotationZ(gme_radian rad);

		// 生成坐标轴旋转矩阵
		inline void SetRotationX(gme_radian rad);
		inline void SetRotationY(gme_radian rad);
		inline void SetRotationZ(gme_radian rad);

		// 生成以空间某点为旋转中心，绕空间轴的旋转矩阵
		void SetRotationAboutCenter(gme_radian rad, const gme_vector3f& ptCenter, GME_SPACE_AXIS_DIR adType);

		// 生成绕空间任意轴旋转的矩阵
		void SetRotationAboutVector(gme_radian rad, const gme_vector3f& v);

		// 抽取 3 X 3 矩阵
		inline void Extract3x3Matrix(gme_matrix3& m3x3) const;

		// 抽取四元数
		inline gme_quaternion ExtractQuaternion() const;// 

	};

	//==============================double================================
			// 矩阵应用定义：
		// 乘法定义 ---- 设有点P, 矩阵M, 则相乘结果定义为 P' = P * M, 与普通图形学中定义不同(P' = M * P)
		// 连接定义 ---- 设当前矩阵为M, 有M1, M2, M3..., 则连乘结果定义为 C = M * M1 * M2 * M3 * ...
		//					与普通图形学中定义不同(C = ... * M3 * M2 * M1 * M)
		//				所有效果矩阵由左到右相乘，则效果相应的从M1开始到M2,依次...

	class gme_matrix3_d;
	class OG_GME_API gme_quaternion_d
	{
	public:
		union {
			struct {
				GDOUBLE w, x, y, z;
			};
			GDOUBLE _v[4];
		};

	public:
		inline gme_quaternion_d(GDOUBLE fW = 1.0, GDOUBLE fX = 0.0, GDOUBLE fY = 0.0, GDOUBLE fZ = 0.0);
		inline gme_quaternion_d(const gme_quaternion_d& rkQ);

		gme_quaternion_d(const gme_matrix3 & rot);

		// 从旋转矩阵构造四元数
		inline gme_quaternion_d(const gme_matrix3_d& rot);

		// 从旋转轴和角度构造四元数
		inline gme_quaternion_d(const gme_radian_d& rfAngle, const gme_vector3d& rkAxis);

		// 从三个正交轴构造四元数
		inline gme_quaternion_d(const gme_vector3d& xaxis, const gme_vector3d& yaxis, const gme_vector3d& zaxis);

		// 从三个正交轴构造四元数,　由数组提供数据
		inline gme_quaternion_d(const gme_vector3d* akAxis);

		// 旋转矩阵与四元数之间的转化
		void FromRotationMatrix(const gme_matrix3_d& kRot);
		void ToRotationMatrix(gme_matrix3_d& kRot) const;

		// (旋转轴, 角度) 与四元数之间的转化
		void FromAngleAxis(const gme_radian_d& rfAngle, const gme_vector3d& rkAxis);
		void ToAngleAxis(gme_radian_d& rfAngle, gme_vector3d& rkAxis) const;
		void ToAngleAxis(gme_degree_d& dAngle, gme_vector3d& rkAxis) const;

		// 正交轴与四元数之间的转换,　可能由数组提供数据
		void FromAxes(const gme_vector3d* akAxis);
		void FromAxes(const gme_vector3d& xAxis, const gme_vector3d& yAxis, const gme_vector3d& zAxis);
		void ToAxes(gme_vector3d* akAxis) const;
		void ToAxes(gme_vector3d& xAxis, gme_vector3d& yAxis, gme_vector3d& zAxis) const;

		// 获取当前四元数所含的X轴
		gme_vector3d xAxis(void) const;
		// 获取当前四元数所含的Y轴
		gme_vector3d yAxis(void) const;
		// 获取当前四元数所含的Z轴
		gme_vector3d zAxis(void) const;

		inline gme_quaternion_d& operator= (const gme_quaternion_d& rkQ);
		gme_quaternion_d operator+ (const gme_quaternion_d& rkQ) const;
		gme_quaternion_d operator- (const gme_quaternion_d& rkQ) const;
		gme_quaternion_d operator* (const gme_quaternion_d& rkQ) const;
		gme_quaternion_d operator* (GDOUBLE fScalar) const;
		gme_quaternion_d operator- () const;

		OG_GME_API friend gme_quaternion_d operator* (GDOUBLE fScalar, const gme_quaternion_d& rkQ);

		inline bool operator== (const gme_quaternion_d& rhs) const;
		inline bool operator!= (const gme_quaternion_d& rhs) const;

		// 四元数自身操作
		// 点积
		GDOUBLE DotProduct(const gme_quaternion_d& rkQ) const;

		// 长度的平方
		GDOUBLE SquaredLength() const;

		// 单位化，并返回原来的长度
		GDOUBLE Normalise(void);
		gme_quaternion_d Inverse() const;		// apply to non-zero gme_quaternion_d
		gme_quaternion_d UnitInverse() const;	// apply to unit-length gme_quaternion_d
		gme_quaternion_d Exp() const;
		gme_quaternion_d Log() const;

		// 用当前四元数所包含的旋转，旋转一个向量
		gme_vector3d operator* (const gme_vector3d& rkVector) const;

		// 计算并取得 Roll角
		gme_radian_d GetRoll(void) const;
		// 计算并取得 Picth角
		gme_radian_d GetPitch(void) const;
		// 计算并取得 Yaw角
		gme_radian_d GetYaw(void) const;
		// 以 tolerance 的角度容差判断两个四元数是否相等
		bool Equals(const gme_quaternion_d& rhs, const gme_radian_d& tolerance) const;

		// 球线性插值
		static gme_quaternion_d Slerp(GDOUBLE fT, const gme_quaternion_d& rkP,
			const gme_quaternion_d& rkQ, bool shortestPath = false);

		static gme_quaternion_d SlerpExtraSpins(GDOUBLE fT,
			const gme_quaternion_d& rkP, const gme_quaternion_d& rkQ,
			int iExtraSpins);

		// setup for spherical quadratic interpolation
		static void Intermediate(const gme_quaternion_d& rkQ0,
			const gme_quaternion_d& rkQ1, const gme_quaternion_d& rkQ2,
			gme_quaternion_d& rkA, gme_quaternion_d& rkB);

		// spherical quadratic interpolation
		static gme_quaternion_d Squad(GDOUBLE fT, const gme_quaternion_d& rkP,
			const gme_quaternion_d& rkA, const gme_quaternion_d& rkB,
			const gme_quaternion_d& rkQ, bool shortestPath = false);

		// normalised linear interpolation - faster but less accurate (non-constant rotation velocity)
		static gme_quaternion_d NLerp(GDOUBLE fT, const gme_quaternion_d& rkP,
			const gme_quaternion_d& rkQ, bool shortestPath = false);

		// cutoff for sine near zero
		static const GDOUBLE ms_fEpsilon;

		// special values
		static const gme_quaternion_d ZERO;
		static const gme_quaternion_d IDENTITY;

	};

	class OG_GME_API gme_matrix3_d
	{
	public:
		union {
			struct {
				GDOUBLE        _11, _12, _13;
				GDOUBLE        _21, _22, _23;
				GDOUBLE        _31, _32, _33;
			};
			GDOUBLE m[3][3];
			GDOUBLE _m[9];
		};

	public:
		static const gme_matrix3_d ZERO;
		static const gme_matrix3_d IDENTITY;

		friend class gme_matrix4_d;

		inline gme_matrix3_d() { LoadIdentity(); }
		inline explicit	gme_matrix3_d(const GDOUBLE arr[3][3]);
		inline gme_matrix3_d(const gme_matrix3_d& mat);
		inline gme_matrix3_d(GDOUBLE _f11, GDOUBLE _f12, GDOUBLE _f13,
			GDOUBLE _f21, GDOUBLE _f22, GDOUBLE _f23,
			GDOUBLE _f31, GDOUBLE _f32, GDOUBLE _f33);

		// 行存取操作
		inline GDOUBLE* operator[] (size_t nRow) const;
		gme_vector3d GetRow(size_t nRow) const;
		void	SetRow(size_t nRow, const gme_vector3d& vec);

		// 列存取操作
		gme_vector3d GetColumn(size_t nCol) const;
		void	SetColumn(size_t nCol, const gme_vector3d& vec);

		// 通过本地XYZ来生成
		void	FromAxis(const gme_vector3d& xAxis, const gme_vector3d& yAxis, const gme_vector3d& zAxis);

		// 赋值
		inline gme_matrix3_d& operator = (const gme_matrix3_d& mat);

		// 比较
		inline bool operator == (const gme_matrix3_d& mat) const;
		inline bool operator != (const gme_matrix3_d& mat) const;

		// 操作
		inline gme_matrix3_d operator + (const gme_matrix3_d& mat) const;
		inline gme_matrix3_d operator - (const gme_matrix3_d& mat) const;
		inline gme_matrix3_d operator * (const gme_matrix3_d& mat) const;
		inline gme_matrix3_d operator - () const;

		// 矢量相乘
		gme_vector3d operator * (const gme_vector3d& vec) const;
		OG_GME_API friend gme_vector3d operator * (const gme_vector3d& vec, const gme_matrix3_d& mat);

		// 标量相乘
		gme_matrix3_d operator * (GDOUBLE fScalar) const;
		OG_GME_API friend gme_matrix3_d operator * (GDOUBLE fScalar, const gme_matrix3_d& mat);

		// 取当前矩阵的转置矩阵
		gme_matrix3_d TransposeCopy() const;

		// 设置当前矩阵为转置矩阵
		void	Transpose();

		// 取伴随矩阵
		gme_matrix3_d	GetAdjoint() const;

		// 取行列值
		GDOUBLE GetDeterminant() const;

		// 取逆矩阵
		bool GetInverse(gme_matrix3_d& mat) const;

		// 设置当前矩阵为逆矩阵
		void	SetToInverse();

		// 设置当前矩阵为单位矩阵
		inline void LoadIdentity(void);

		// 矩阵相乘，自身保存结果
		inline gme_matrix3_d Multiply(const gme_matrix3_d& mat);

		// 施密特正交化　
		void Orthonormalize();

		// 以下操作必须在正交化的基础上
		// 转化为轴和角度
		void ToAxisAngle(gme_vector3d& vAxis, gme_radian_d& rad) const;
		void ToAxisAngle(gme_vector3d& vAxis, gme_degree_d& deg) const;

		// 从轴和角度转化
		void FromAxisAngle(const gme_vector3d& vAxis, const gme_radian_d& rad);
		void FromAxisAngle(const gme_vector3d& vAxis, const gme_degree_d& deg);

		// 转化为欧拉角
		bool ToEulerAnglesXYZ(gme_radian_d& rfYAngle, gme_radian_d& rfPAngle, gme_radian_d& rfRAngle) const;
		bool ToEulerAnglesXZY(gme_radian_d& rfYAngle, gme_radian_d& rfPAngle, gme_radian_d& rfRAngle) const;
		bool ToEulerAnglesYXZ(gme_radian_d& rfYAngle, gme_radian_d& rfPAngle, gme_radian_d& rfRAngle) const;
		bool ToEulerAnglesYZX(gme_radian_d& rfYAngle, gme_radian_d& rfPAngle, gme_radian_d& rfRAngle) const;
		bool ToEulerAnglesZXY(gme_radian_d& rfYAngle, gme_radian_d& rfPAngle, gme_radian_d& rfRAngle) const;
		bool ToEulerAnglesZYX(gme_radian_d& rfYAngle, gme_radian_d& rfPAngle, gme_radian_d& rfRAngle) const;

		// 从欧拉角转换
		void FromEulerAnglesXYZ(const gme_radian_d& fYAngle, const gme_radian_d& fPAngle, const gme_radian_d& fRAngle);
		void FromEulerAnglesXZY(const gme_radian_d& fYAngle, const gme_radian_d& fPAngle, const gme_radian_d& fRAngle);
		void FromEulerAnglesYXZ(const gme_radian_d& fYAngle, const gme_radian_d& fPAngle, const gme_radian_d& fRAngle);
		void FromEulerAnglesYZX(const gme_radian_d& fYAngle, const gme_radian_d& fPAngle, const gme_radian_d& fRAngle);
		void FromEulerAnglesZXY(const gme_radian_d& fYAngle, const gme_radian_d& fPAngle, const gme_radian_d& fRAngle);
		void FromEulerAnglesZYX(const gme_radian_d& fYAngle, const gme_radian_d& fPAngle, const gme_radian_d& fRAngle);
	};

	////////////////////////////////////////////////////////////
	/// gme_matrix4_d

	class OG_GME_API gme_matrix4_d
	{
	public:
		union {
			struct {
				GDOUBLE        _11, _12, _13, _14;
				GDOUBLE        _21, _22, _23, _24;
				GDOUBLE        _31, _32, _33, _34;
				GDOUBLE        _41, _42, _43, _44;
			};
			GDOUBLE m[4][4];
			GDOUBLE _m[16];
		};
	public:

		static const gme_matrix4_d ZERO;
		static const gme_matrix4_d IDENTITY;

		inline gme_matrix4_d();
		inline gme_matrix4_d(const gme_matrix3_d& m3x3);
		inline gme_matrix4_d(const gme_quaternion_d& rot);


		inline gme_matrix4_d(GDOUBLE m00, GDOUBLE m01, GDOUBLE m02, GDOUBLE m03,
			GDOUBLE m10, GDOUBLE m11, GDOUBLE m12, GDOUBLE m13,
			GDOUBLE m20, GDOUBLE m21, GDOUBLE m22, GDOUBLE m23,
			GDOUBLE m30, GDOUBLE m31, GDOUBLE m32, GDOUBLE m33);

		//
		inline GDOUBLE* operator [] (size_t nRow);
		inline const GDOUBLE* operator [] (size_t nRow) const;

		//
		inline gme_matrix4_d& operator = (const gme_matrix4_d &mat);
		inline gme_vector3d operator * (const gme_vector3d &v) const;
		inline gme_matrix4_d operator * (const gme_matrix4_d &mat) const;
		inline gme_matrix4_d operator + (const gme_matrix4_d &mat) const;
		inline gme_matrix4_d operator - (const gme_matrix4_d &mat) const;
		inline bool operator == (const gme_matrix4_d &mat) const;
		inline bool operator != (const gme_matrix4_d &mat) const;
		inline void operator = (const gme_matrix3_d& mat3);

		// 矩阵相乘，自身保存结果
		inline gme_matrix4_d Multiply(const gme_matrix4_d& mat);

		// 连接一个矩阵 C = M * M1 * M2 * M3 ........
		// M 代表当前矩阵, 只返回结果,不修改当前矩阵
		inline gme_matrix4_d MultiplyCopy(const gme_matrix4_d& mat) const;

		// 取当前矩阵的转置矩阵
		inline gme_matrix4_d TransposeCopy(void) const;

		// 设置当前矩阵为转置矩阵
		inline void Transpose(void);

		// 设置当前矩阵为单位矩阵
		inline void LoadIdentity(void);

		// 设置当前矩阵的平移部分
		inline void SetTransPart(const gme_vector3d& v);

		// 取当前矩阵的平移部分
		inline gme_vector3d GetTransPart(void) const;

		// 重建为一个平移矩阵
		inline void MakeTrans(const gme_vector3d& v);
		inline void MakeTrans(GDOUBLE vx, GDOUBLE vy, GDOUBLE vz);

		// 构造一个平移矩阵
		inline static gme_matrix4_d BuildTrans(const gme_vector3d& v);
		inline static gme_matrix4_d BuildTrans(GDOUBLE vx, GDOUBLE vy, GDOUBLE vz);

		//　存取当前矩阵的缩放部分
		inline gme_vector3d	GetScalePart(void) const;
		inline void		SetScalePart(const gme_vector3d& v);

		// 建立缩放矩阵
		inline static gme_matrix4_d BuildScale(const gme_vector3d& v);
		inline static gme_matrix4_d BuildScale(GDOUBLE vx, GDOUBLE vy, GDOUBLE vz);

		//　矩阵与标量相乘
		inline gme_matrix4_d operator * (GDOUBLE scalar);

		// 取伴随矩阵
		gme_matrix4_d	GetAdjoint() const;

		// 取行列值
		GDOUBLE GetDeterminant() const;

		// 取逆矩阵
		gme_matrix4_d GetInverse() const;

		// 设置当前矩阵为逆矩阵
		void	SetToInverse();


		// 当前矩阵与绕轴一定角度的旋转矩阵相乘
		inline void RotationX(gme_radian_d rad);
		inline void RotationY(gme_radian_d rad);
		inline void RotationZ(gme_radian_d rad);

		// 生成坐标轴旋转矩阵
		inline void SetRotationX(gme_radian_d rad);
		inline void SetRotationY(gme_radian_d rad);
		inline void SetRotationZ(gme_radian_d rad);

		// 生成以空间某点为旋转中心，绕空间轴的旋转矩阵
		void SetRotationAboutCenter(gme_radian_d rad, const gme_vector3d& ptCenter, GME_SPACE_AXIS_DIR adType);

		// 生成绕空间任意轴旋转的矩阵
		void SetRotationAboutVector(gme_radian_d rad, const gme_vector3d& v);

		// 抽取 3 X 3 矩阵
		inline void Extract3x3Matrix(gme_matrix3_d& m3x3) const;

		// 抽取四元数
		inline gme_quaternion_d ExtractQuaternion() const;// 

	};


	//==============================color=============================
	class OG_GME_API gme_color4
	{
	public:
		union {
			struct {
				GREAL r, g, b, a;
			};
			GREAL v[4];
		};
	public:


		gme_color4(GREAL red = 1.0f,
			GREAL green = 1.0f,
			GREAL blue = 1.0f,
			GREAL alpha = 1.0f) : r(red), g(green), b(blue), a(alpha)
		{ }

		gme_color4(const gme_color4& color)
		{
			operator=(color);
		}


		bool operator==(const gme_color4& color) const;
		bool operator!=(const gme_color4& color) const;


		// 返回一个RGBA形式的数
		GME_RGBA GetAsRGBA(void) const;

		// 返回一个ARGB形式的数
		GME_ARGB GetAsARGB(void) const;

		// 返回一个ABGR形式的数
		GME_ABGR GetAsABGR(void) const;

		// 运算符
		inline gme_color4 operator + (const gme_color4& color) const
		{
			gme_color4 out;

			out.r = r + color.r;
			out.g = g + color.g;
			out.b = b + color.b;
			out.a = a + color.a;

			return out;
		}

		inline gme_color4 operator - (const gme_color4& color) const
		{
			gme_color4 out;

			out.r = r - color.r;
			out.g = g - color.g;
			out.b = b - color.b;
			out.a = a - color.a;

			return out;
		}

		inline gme_color4 operator * (GREAL fScalar) const
		{
			gme_color4 out;

			out.r = fScalar * r;
			out.g = fScalar * g;
			out.b = fScalar * b;
			out.a = fScalar * a;

			return out;
		}

		inline gme_color4 operator * (const gme_color4& color) const
		{
			gme_color4 out;

			out.r = color.r * r;
			out.g = color.g * g;
			out.b = color.b * b;
			out.a = color.a * a;

			return out;
		}

		inline gme_color4 operator / (const gme_color4& color) const
		{
			gme_color4 out;

			out.r = color.r / r;
			out.g = color.g / g;
			out.b = color.b / b;
			out.a = color.a / a;

			return out;
		}

		inline gme_color4 operator / (GREAL fScalar) const
		{
			//assert(fScalar != 0.0);

			gme_color4 out;

			GREAL fInv = 1.0f / fScalar;
			out.r = r * fInv;
			out.g = g * fInv;
			out.b = b * fInv;
			out.a = a * fInv;

			return out;
		}

		inline friend gme_color4 operator * (GREAL fScalar, const gme_color4& color)
		{
			gme_color4 out;

			out.r = fScalar * color.r;
			out.g = fScalar * color.g;
			out.b = fScalar * color.b;
			out.a = fScalar * color.a;

			return out;
		}

		// arithmetic updates
		inline gme_color4& operator += (const gme_color4& color)
		{
			r += color.r;
			g += color.g;
			b += color.b;
			a += color.a;

			return *this;
		}

		inline gme_color4& operator -= (const gme_color4& color)
		{
			r -= color.r;
			g -= color.g;
			b -= color.b;
			a -= color.a;

			return *this;
		}

		inline gme_color4& operator *= (GREAL fScalar)
		{
			r *= fScalar;
			g *= fScalar;
			b *= fScalar;
			a *= fScalar;
			return *this;
		}

		inline gme_color4& operator /= (GREAL fScalar)
		{
			//assert(fScalar != 0.0);

			GREAL fInv = 1.0f / fScalar;

			r *= fInv;
			g *= fInv;
			b *= fInv;
			a *= fInv;

			return *this;
		}


		static gme_color4 Black;
		static gme_color4 White;
		static gme_color4 Red;
		static gme_color4 Green;
		static gme_color4 Blue;
	};

  //	=========================double类型=======================
	class OG_GME_API gme_color4_d
	{
	public:
		union {
			struct {
				GDOUBLE r, g, b, a;
			};
			GDOUBLE _v[4];
		};
	public:


		gme_color4_d(GDOUBLE red = 1.0f,
			GDOUBLE green = 1.0f,
			GDOUBLE blue = 1.0f,
			GDOUBLE alpha = 1.0f) : r(red), g(green), b(blue), a(alpha)
		{ }

		gme_color4_d(const gme_color4_d& color)
		{
			operator=(color);
		}


		bool operator==(const gme_color4_d& color) const;
		bool operator!=(const gme_color4_d& color) const;


		// 返回一个RGBA形式的数
		GME_RGBA GetAsRGBA(void) const;

		// 返回一个ARGB形式的数
		GME_ARGB GetAsARGB(void) const;

		// 返回一个ABGR形式的数
		GME_ABGR GetAsABGR(void) const;

		// 运算符
		inline gme_color4_d operator + (const gme_color4_d& color) const
		{
			gme_color4_d out;

			out.r = r + color.r;
			out.g = g + color.g;
			out.b = b + color.b;
			out.a = a + color.a;

			return out;
		}

		inline gme_color4_d operator - (const gme_color4_d& color) const
		{
			gme_color4_d out;

			out.r = r - color.r;
			out.g = g - color.g;
			out.b = b - color.b;
			out.a = a - color.a;

			return out;
		}

		inline gme_color4_d operator * (GDOUBLE fScalar) const
		{
			gme_color4_d out;

			out.r = fScalar * r;
			out.g = fScalar * g;
			out.b = fScalar * b;
			out.a = fScalar * a;

			return out;
		}

		inline gme_color4_d operator * (const gme_color4_d& color) const
		{
			gme_color4_d out;

			out.r = color.r * r;
			out.g = color.g * g;
			out.b = color.b * b;
			out.a = color.a * a;

			return out;
		}

		inline gme_color4_d operator / (const gme_color4_d& color) const
		{
			gme_color4_d out;

			out.r = color.r / r;
			out.g = color.g / g;
			out.b = color.b / b;
			out.a = color.a / a;

			return out;
		}

		inline gme_color4_d operator / (GDOUBLE fScalar) const
		{
			//assert(fScalar != 0.0);

			gme_color4_d out;

			GDOUBLE fInv = 1.0f / fScalar;
			out.r = r * fInv;
			out.g = g * fInv;
			out.b = b * fInv;
			out.a = a * fInv;

			return out;
		}

		inline friend gme_color4_d operator * (GDOUBLE fScalar, const gme_color4_d& color)
		{
			gme_color4_d out;

			out.r = fScalar * color.r;
			out.g = fScalar * color.g;
			out.b = fScalar * color.b;
			out.a = fScalar * color.a;

			return out;
		}

		// arithmetic updates
		inline gme_color4_d& operator += (const gme_color4_d& color)
		{
			r += color.r;
			g += color.g;
			b += color.b;
			a += color.a;

			return *this;
		}

		inline gme_color4_d& operator -= (const gme_color4_d& color)
		{
			r -= color.r;
			g -= color.g;
			b -= color.b;
			a -= color.a;

			return *this;
		}

		inline gme_color4_d& operator *= (GDOUBLE fScalar)
		{
			r *= fScalar;
			g *= fScalar;
			b *= fScalar;
			a *= fScalar;
			return *this;
		}

		inline gme_color4_d& operator /= (GDOUBLE fScalar)
		{
			//assert(fScalar != 0.0);

			GDOUBLE fInv = 1.0f / fScalar;

			r *= fInv;
			g *= fInv;
			b *= fInv;
			a *= fInv;

			return *this;
		}


		static gme_color4_d Black;
		static gme_color4_d White;
		static gme_color4_d Red;
		static gme_color4_d Green;
		static gme_color4_d Blue;
	};

	//三角形
	class OG_GME_API gme_triangle
	{
	public:
		union {
			struct {
				GINT a, b, c;//三角形的三个顶点号
			};
			struct {
				GINT x, y, z;//三角形的三个顶点号
			};
			GINT _v[3];
		};	

	public:
		gme_triangle();
		gme_triangle(GINT aa, GINT bb, GINT cc)
		{
			a = aa;
			b = bb;
			c = cc;
		}
		~gme_triangle();
		long operator=(const gme_triangle& rhs);
		bool operator<(const gme_triangle& dotB) const
		{
			if (fabs(this->x - dotB.x) >= 1E-6)
			{
				return this->x < dotB.x ? -1 : 1;
			}
			else if (fabs(this->y - dotB.y) >= 1E-6)
			{
				return this->y < dotB.y ? -1 : 1;
			}
			else if (fabs(this->z - dotB.z) >= 1E-6)
			{
				return this->z < dotB.z ? -1 : 1;
			}
			else
			{
				return 0;
			}
		}
	};


	//三角形拓扑信息
	class OG_GME_API gme_triangle_top
	{
	public:
		union {
			//ab,bc,ca边的邻接三角形
			struct {
				GINT nTriNo1, nTriNo2, nTriNo3;
			};
			struct {
				GINT tri_ab, tri_bc, tri_ca;
			};
			struct {
				GINT ab,bc,ca;       // 边ab,bc,ca的邻接三角形索引
			};
			struct {
				GINT a, b, c;//三角形的三个顶点号
			};
			struct {
				GINT x, y, z;//三角形的三个顶点号
			};
			GINT _v[3];
		};

		gme_triangle_top();
		~gme_triangle_top();
		long operator=(const gme_triangle_top& rhs);
	};

	//包围对象
	class OG_GME_API gme_3denvelope
	{
	public:
		long operator=( gme_3denvelope& envelop);
		gme_3denvelope();
		virtual ~gme_3denvelope();

	public:
		//克隆本对象
		long Clone(gme_3denvelope* pEnvelop);

		//合并范围
		virtual long Union(gme_3denvelope* pEnvelope);

		//设置范围
		long PutCoord(gme_vector3f* pPoint, long nPoint);


	private:
		//点个数
		long m_nDotNum;
		GREAL* m_pDot;
	};
	//===================================double=========================================
	//包围对象
	class OG_GME_API gme_3denvelope_d
	{
	public:
		gme_3denvelope_d& operator=(const gme_3denvelope_d& envelop);
		gme_3denvelope_d();
		virtual ~gme_3denvelope_d();

	public:
		//克隆本对象
		long Clone(gme_3denvelope_d* pEnvelop);
		//合并范围
		virtual long Union(gme_3denvelope_d* pEnvelope);

		//设置范围
		long PutCoord(gme_vector3d* pPoint, long nPoint);


	private:
		//点个数
		long m_nDotNum;
		double* m_pDot;
	};

	class OG_GME_API gme_3dball
	{
	public:
		inline gme_3dball& operator = (const gme_3dball& rhs)
		{
			Center = rhs.Center;
			Radius = rhs.Radius;
			return *this;
		}

	public:
		gme_vector3f Center;
		GREAL	  Radius;
	};
	//---------------------------------double---------ball----------

	class OG_GME_API gme_ball_d
	{
	public:
		inline gme_ball_d& operator = (const gme_ball_d& rhs)
		{
			Center = rhs.Center;
			Radius = rhs.Radius;
			return *this;
		}

	public:
		gme_vector3d Center;
		GDOUBLE		  Radius;
	};

	class OG_GME_API gme_rect_2i
	{
	public:

		union {
			struct {
				long xmin, xmax, ymin, ymax;
			};
			struct {
				long min_x, max_x, min_y, max_y;
			};
			struct {
				long left, right, top, bottom;
			};
			long _v[4];
		};
		gme_rect_2i()
		{
			xmin = ymin = LONG_MAX; // (long)GME_MAX_FLOAT;
			xmax = ymax = LONG_MIN; // (long)GME_MIN_FLOAT;
		}
	};
	class OG_GME_API gme_rect_3i
	{
	public:

		union {
			struct {
				long xmin, xmax, ymin, ymax, zmin, zmax;
			};
			struct {
				long min_x, max_x, min_y, max_y, min_z, max_z;
			};
			long _v[6];
		};
		gme_rect_3i()
		{
			xmin = ymin = zmin = LONG_MAX; // (long)GME_MAX_FLOAT;
			xmax = ymax = zmax = LONG_MIN; // (long)GME_MIN_FLOAT;
		}
	};


	class OG_GME_API gme_rect_2f
	{
	public:

		union {
			struct {
				float xmin, xmax, ymin, ymax;
			};
			struct {
				float min_x, max_x, min_y, max_y;
			};
			float _v[4];
		};
		gme_rect_2f()
		{
			xmin = ymin = (float)GME_MAX_FLOAT;
			xmax = ymax = (float)GME_MIN_FLOAT;
		}
	};
	class OG_GME_API gme_rect_2d
	{
	public:

		union {
			struct {
				double xmin, xmax, ymin, ymax;
			};
			struct {
				double min_x, max_x, min_y, max_y;
			};
			double _v[4];
		};
		gme_rect_2d()
		{
			xmin = ymin = GME_MAX_DOUBLE;
			xmax = ymax = GME_MIN_DOUBLE;
		}
	};
	
	typedef gme_rect_2d gme_D_RECT;
	
	//圆
	typedef struct gme_circle
	{
		gme_vector2d		ddCenter;
		double				dRadius;
	}gme_circle;

	//BOX范围
	class OG_GME_API gme_rect_3f
	{
	public:
		gme_rect_3f();
		~gme_rect_3f();
		inline gme_rect_3f& operator= (const gme_rect_3f& rhs);

	public:
		//取高度
		double GetHeight();

		//取中心点
		long GetCenter(gme_vector3f* pCenter);

		//设置数据 add by xsm
		long Set(gme_vector3f &MinPoint, gme_vector3f &MaxPoint);

		long SetNull();

	public:
		union {
			struct {
				GREAL xmin, xmax, ymin, ymax, zmin, zmax;
			};
			struct {
				GREAL min_x, max_x, min_y, max_y, min_z, max_z;
			};
			GREAL _v[6];
		};
	};

	//BOX范围-------------------------double类型
	class OG_GME_API gme_rect_3d
	{
	public:
		gme_rect_3d();
		~gme_rect_3d();
		inline gme_rect_3d& operator = (const gme_rect_3d& rhs);

	public:
		//取高度
		double GetHeight();

		//取中心点
		long GetCenter(gme_vector3d* pCenter);

		//设置数据
		long Set(gme_vector3d &MinPoint, gme_vector3d &MaxPoint);

		//Merge
		long Merge(gme_vector3d &point);
		long Merge(const gme_rect_3d& box);

		//设置空
		long SetNull();
		bool IsNull();

	public:
		union {
			struct {
				GDOUBLE xmin, xmax, ymin, ymax, zmin, zmax;
			};
			struct {
				GDOUBLE min_x, max_x, min_y, max_y, min_z, max_z;
			};

			GDOUBLE _v[6];
		};
	};

	//位向量类
	class	OG_GME_API gme_bitset
	{
	private:
		unsigned char *	m_pBitSet;//位向量,每字节从右向左位序号增加
		GINT			m_lSize;//位向量长度（单位：bit）

	public:
		gme_bitset(const GINT size = 0);
		~gme_bitset();
		//设置位向量的大小
		GINT SetSize(const GINT &size);
		//测试位向量某位是否为1
		bool Test(const GINT &pos);
		//设置所有位为1
		bool Set();
		//设置某位为1
		bool Set(const GINT &pos);
		//设置所有位为0
		bool Reset();
		//设置某位为0
		bool Reset(const GINT &pos);
		//释放内存
		bool Release();
		//对象赋值
		bool operator = (const gme_bitset& rhs);
	};

	//ID列表
	class	OG_GME_API GLONGid_list
	{
	public:
		GLONGid_list();
		GLONGid_list(const GLONGid_list& src);
		virtual ~GLONGid_list();

	public:
		GLONGid_list& operator=(const GLONGid_list& rhs);

		//	取第i个ID对象
		GLONG operator[](int i) const;
		GINT Add(const GLONG &nID);

		//  唯一添加
		GINT AddUnique(const GLONG &nID);
		GINT AddIDList(const GLONG *pIDList, const GINT &nIDNum);
		GINT UpdateID(const GINT &i, const GLONG &nID);
		GLONG *GetIDList();

		//获取对象个数(=1)或字节数(=0)
		GINT GetCount(char IsObjorByteNum = 1);

		//设置Buf大小,单位：Byte
		short SetSize(GINT nByteSize);

		//复位，保留内存
		short	Reset();

		//释放内存，回退到初始构造状态
		short	ReleaseMem();

	private:
		//组成ID个数
		GINT m_nObjNum;
		//Buf能存放的ID数量(单位：对象)
		GINT m_nAllNum;
		//组成实体
		GLONG *m_pObject;

	};

	//要素ID定义
	class	OG_GME_API gme_feature_id
	{
	public:
		GME_TYPE_OBJ_ID	ClsID;//要素类ID或
		GME_TYPE_OBJ_ID		ObjID;//要素或几何对象ID
		short				nObjType;//对象类型

		gme_feature_id();
		//判断当前实例是否有效(true OR false)
		bool IsValidID(void) const
		{
			return (0 != ObjID);//&&(INVALID_FCLS_ID != ClsID)
		}
		
		void SetID(gme_feature_id& fID)
		{
			*this = fID;
		}

		gme_feature_id GetID()
		{
			return *this;
		}

		void SetID(GME_TYPE_OBJ_ID clsID, GME_TYPE_OBJ_ID objID, char cInternalFlag)
		{
			ClsID = clsID;
			ObjID = objID;
		}

		void GetID(GME_TYPE_OBJ_ID& clsID, GME_TYPE_OBJ_ID& objID, char& cInternalFlag)
		{
			clsID = ClsID;
			objID = ObjID;
		}

		//赋值操作符重载函数
		gme_feature_id operator=(const gme_feature_id& r)
		{
			ClsID = r.ClsID; ObjID = r.ObjID; nObjType = r.nObjType;
			return *this;
		}
		//小于操作符重载函数
		bool operator<(const gme_feature_id& r)const
		{
			if (nObjType != r.nObjType)
				return nObjType < r.nObjType;
			else if (ClsID != r.ClsID)
				return ClsID < r.ClsID;
			else
				return ObjID < r.ObjID;
		}

		//大于操作符重载函数
		bool operator>(const gme_feature_id& r)const
		{
			if (nObjType != r.nObjType)
				return nObjType > r.nObjType;
			
			else if (ClsID != r.ClsID)
				return ClsID > r.ClsID;
			else
				return ObjID > r.ObjID;
		}

		//等于操作符重载函数
		bool operator==(const gme_feature_id &r)const
		{
			if (ClsID > -1 && r.ClsID > -1)
				return (ObjID == r.ObjID) && (ClsID == r.ClsID) && (nObjType == r.nObjType);
			else
				return (ObjID == r.ObjID) && (ClsID == r.ClsID) && (nObjType == r.nObjType);
		}
	};


	//要素列表
	class	OG_GME_API gme_feature_list
	{
	public:
		gme_feature_list();
		gme_feature_list(gme_feature_list& rhs);
		~gme_feature_list();
		gme_feature_list& operator [](long i);
		gme_feature_list&	operator=(gme_feature_list& rhs);

	public:
		//获取值 (0<=i<m_nFeatureNum)
		gme_feature_id  GetAt(long i);

		//添加对象ID(供友元类使用)
		long		AddObject(gme_feature_id &FeatureID);

		//添加一组
		long		AddObjectListData(gme_feature_id *pFeatureList, long nFeatureNum);

		//设定其列表
		long		SetFeaIDList(gme_feature_id *idList, long nNum);


		//删除对象ID
		long		DeleteObject(gme_feature_id FeatureID);

		//删除对象ID (0<=i<m_nFeatureNum)
		long		DeleteObject(long nPos);

		//更新 (0<=i<m_nFeatureNum)
		long		UpdateObject(long nPos, gme_feature_id FeatureID);
		//设置大小
		short		SetSize(long nFeatureNum);
		//获取对象个数(=1)或所有对象的字节数(=0)
		long		GetCount(char IsObjorByteNum = 1);

		//复位，保留内存
		short		Reset();

		//释放内存，回退到初始构造状态
		short		ReleaseMem();
		//		(0<=i<m_nFeatureNum)
		long		GetAt(long i, gme_feature_id &FID);

		//得到其列表
		gme_feature_id* GetFeaIDList();

	public:
		gme_feature_id		*m_pFeatureID;

		//组成实体个数，单位：1个gme_feature_id
		long			m_nFeatureNum;

		//内存空间数量，单位：1个gme_feature_id
		long			m_nAllNum;
	};


	struct	SCENE_3DBOX
	{
		GREAL			xmin;
		GREAL			ymin;
		GREAL			zmin;
		GREAL			xmax;
		GREAL			ymax;
		GREAL			zmax;
		SCENE_3DBOX()
		{
			xmin = ymin = zmin = (GREAL)GME_MAX_FLOAT;
			xmax = ymax = zmax = (GREAL)GME_MIN_FLOAT;
		}
	};
	
	

	typedef struct gme_grid_lin	//坐标网格线
	{
		long		lNum;
		gme_color4	fColor;//颜色
		long		lStyle;//线型 (1---实线 / 2---虚线)
		GREAL		fWidth;//线宽
	}gme_grid_lin;

	typedef struct gme_font_info //标注字体、大小、颜色、宽高
	{
		GString		strFontName;
		long		lFontType;
		GREAL		fFontSize;
		GREAL		fFontWid, fFontLen;
	}gme_font_info;

	//键盘定义
	typedef struct  gme_controls
	{
		WORD keyLeft;
		WORD keyRight; //左移、右移
		WORD keyForward;
		WORD keyBackward;//前进、后退
		WORD keyUp;
		WORD keyDown;//上升、下降
		WORD keyLeftTurn;
		WORD keyRightTurn;//左转、右转
		WORD keyHeadUp;
		WORD keyHeadDown;//上仰、俯视
		//gme_controls()
		//{
		//	memset(this, 0, sizeof(gme_controls));
		//}
	}gme_controls;

	//有关漫游参数的结构定义
	typedef struct  gme_walk_params
	{
		GREAL		r;//视点与参考点之间的距离
		GREAL		angz;//绕Z轴旋转的角度(视线方向与其在XOY面上的投影之间的夹角)
		GREAL   	angz_inc;//绕Z轴旋转的角度的增量
		GREAL		shift_inc;//左、右平移的步长
		GREAL		speed;//前进、后退的步长
		GREAL		UpDown_inc;//向上、向下时视点增减的值
		GREAL   	look_up_ang;//仰视或俯视的角度
		GREAL   	look_up_ang_inc;//仰视或俯视时的角度增量

		//gme_walk_params()
		//{
		//	memset(this, 0, sizeof(gme_walk_params));
		//}
	}gme_walk_params;


	//光源信息结构
	struct	gme_light_info
	{
		BYTE 			cType;//光源类型

		GString			LightName; //光源名称
		GREAL			Light_Diffuse[4];	//漫反射光颜色(在灯光颜色不需要alpha通道)
		GREAL			Light_Specular[4];	//镜面反射颜色	
		GREAL 			Light_Ambient[4];	//环境光颜色

		gme_vector3f			vLight;//光源位置
		gme_vector3f			vDir;//光源的照射方向
		GREAL			Range; //光作用的范围
		GREAL           Falloff;
		GREAL           Attenuation0;
		GREAL           Attenuation1;
		GREAL           Attenuation2;
		GREAL           Theta;
		GREAL           Phi;
	};


	//场景投影、旋转、平移矩阵
	struct gme_scene_matrix
	{
		gme_matrix4	TransMtrx;
		gme_matrix4	ProjMtrx;
		gme_matrix4	MouseQuat;

		gme_matrix4	RotateMtrx;
		gme_vector3f	EyeVec, LookAtVec;
		gme_scene_matrix* prev;
		gme_scene_matrix* next;
	};

	//材质信息描述
	struct  gme_material
	{
		GREAL			fAmbient[4];   //环境光
		GREAL			fDiffuse[4];   //漫反射光
		GREAL			fSpecular[4];  //镜面反射颜色
		GREAL			fEmission[4];  //辐射光
		GREAL			fShininess;    //材料的亮度或镜面反射的尖锐程度
	};

	//纹理数据信息描述
	struct gme_texture_info
	{
	public:
		//纹理数据大小
		DWORD	nDataLen;
		//纹理的长度
		WORD	nx;
		//纹理的宽度
		WORD	ny;
		//纹理格式
		GME_TEXTURE_FORMAT format;
	};

	union gme_tex_info_union
	{
	public:
		gme_material		Material;
		gme_texture_info	Texture;
	};

	//纹理、材质信息
	struct gme_tex_info //纹理/材质信息
	{
		char					cflag;//1:纹理，2:材质
		GME_SCENE_TEXIDXNO		nTexNo;	//纹理的编号
		char					cModified;//1被修改过,0未被修改
		gme_tex_info_union		info;
		gme_tex_info()
		{
			memset(this, 0, sizeof(gme_tex_info));
		}
	};

	//雾信息
	struct gme_fgme_info
	{
		GME_FOG_TYPE		fogType;	//雾类型(数值1表示顶点雾,数值2表示像素雾)
		GREAL			fStart; //雾范围的起始值
		GREAL			fEnd;	//雾范围的结束值
		GREAL			pfColor[4];//雾颜色
		GREAL			fDensity;//雾密度
		BOOL			useRange;
		GME_FOG_MODE       fogMode;
		//range

		gme_fgme_info()
		{
			memset(this, 0, sizeof(gme_fgme_info));
		}
	};


	struct gme_tex_param		//纹理调整参数
	{
		GME_TEXTURE_FILTER		cMagFilter;		//纹理过滤放大函数
		GME_TEXTURE_FILTER		cMinFilter;		//纹理过滤缩小函数
		GME_TEXTURE_FILTER		cMipmapFilter;	//多纹理映射过滤函数
		//(当cMipmapFilter为0表明渲染引擎disabled mipmap filter)
		GME_TEXTURE_WRAPMODE	cWrapS;			//纹理坐标S的缠绕参数
		GME_TEXTURE_WRAPMODE	cWrapT;			//纹理坐标T的缠绕参数
		GME_TEXTUREENVMODE	cEnvMode;		//纹理环境模式

		gme_tex_param()
		{
			cMagFilter = GME_LINEAR_FILTER;
			cMinFilter = GME_LINEAR_FILTER;
			cMipmapFilter = (GME_TEXTURE_FILTER)0;
			cWrapS = GME_REPEAT;
			cWrapT = GME_REPEAT;
			cEnvMode = GME_TM_MODULATE;
		}
	};

	//融合参数
	struct gme_blend_param
	{
		unsigned char   cSrcFactor;	//源融合因子
		unsigned char   cDestFactor;//目标融合因子
		gme_blend_param()
		{
			memset(this, 0, sizeof(gme_blend_param));
		}
	};
	
	//
	struct gme_video_info	//录制视频信息
	{
		long		lWid;	//帧宽度
		long		lLen;	//帧长度
		GREAL		fFps;	//播放速率
		long		lFrames;//帧数
		long		lBisCount;//像元位数
	};

	struct gme_img_info	//保存场景位图信息
	{
		long		lWid;	//帧宽度
		long		lLen;	//帧长度
		long		lBisCount;//像元位数
		long		lCompressCoef; //压缩系数
	};

	//粒子系统数据描述结构
	struct gme_particle_data_info
	{
	public:
		BYTE				type;				//粒子体类型(0－喷泉, 1-其他)
		BYTE				status;				//0－关闭粒子效果；1－启动粒子效果；2－粒子静止
		gme_vector3f			initPostion;		//初始位置(这个参数不是对每种类型的粒子体都有用)
		GREAL				initVel;			//初始速度
		GREAL				fAzimuth, fObliquity;//初始速度及其方位角和倾角
		GREAL				particleSize;		//粒子大小
		GREAL				killHeight;			//消亡高度
		WORD				emitParticlesToNum;	//一次发射的粒子个数
		WORD				existTime;			//存在时间(秒)
		WORD				curParticlNum;		//当前存在的粒子个数
		WORD				particleMaxNum;		//粒子最大个数
		GME_SCENE_TEXIDXNO	nTexNo;				//使用的纹理号
		GREAL   			clrDiffuse[4];		//初始颜色
		GREAL   			clrFade[4];			//消失颜色
		DWORD				nParticleDataSize;	//数据缓冲长度
		gme_particle_data_info()
		{
			memset(this, 0, sizeof(gme_particle_data_info));
		}
	};

	struct 	gme_particle
	{
	public:
		BYTE      	bDied;	//是否已消亡
		BYTE      	bSpark;	//是否闪烁			
		gme_vector3f		vPos0;	//初始位置
		gme_vector3f		vVel0;	//初始速度
		GREAL		fTime0;	//创建时间
		GREAL		fFade;	//消失

		gme_particle()
		{
			memset(this, 0, sizeof(gme_particle));
		}
	};

	struct  gme_hotkey_info
	{
		long lLookDown;
		long lLookUp;
		long lMoveDown;
		long lMoveUp;
		long lMoveflagXY;
		long lMoveflagXyz;
		long lMoveflagXZ;
		long lMoveflagYZ;
		long lMoveflagX[2];
		long lMoveflagY[2];
		long lMoveflagZ[2];
		long lReduceEyedis;
		long lTurnLeft;
		long lTurnRight;
		long lMoveBackward;
		long lMoveForward;
		long lAddEyedis;
		long lMoveLeft;
		long lMoveRight;

		gme_hotkey_info()
		{
			lLookDown = VK_NEXT;
			lLookUp = VK_PRIOR;
			lMoveDown = VK_SUBTRACT;
			lMoveUp = VK_ADD;
			lMoveflagXY;
			lMoveflagXyz;
			lMoveflagXZ;
			lMoveflagYZ;
			lMoveflagX[2];
			lMoveflagY[2];
			lMoveflagZ[2];
			lReduceEyedis;
			lTurnLeft = VK_LEFT;
			lTurnRight = VK_RIGHT;
			lMoveBackward = VK_DOWN;
			lMoveForward = VK_UP;
			lAddEyedis;
			lMoveLeft = VK_LSHIFT;
			lMoveRight = VK_RSHIFT;
		}
	};
	
	// --------------------- 新的字段属性类 ---------------------------- //
	class OG_GME_API gmeByteArray
	{
	public:

		gmeByteArray();
		gmeByteArray(const void *copy, size_t len);		
		gmeByteArray(const gmeByteArray& other);
		gmeByteArray& operator=(const gmeByteArray& other);
		~gmeByteArray();

	public:
		void Clear();
		void setVal(const void *copy, size_t len);
	
	public:
		size_t mLength;
		void*  mpByte;
	};

	class OG_GME_API gmeFieldValue
	{
	public:
		enum gmeType
		{
			Type_Null = 0,
			Type_Bool = 1,
			Type_Char = 2,	
			Type_Int16 =3,
			Type_Int32 =4,//Type_INTEGER
			Type_Int64 =5,
			Type_Real32=6,
			Type_Real64=7,//TYPE_REAL
			Type_Text = 8,//Type_ZString
			Type_Blob = 9,//Type_ByteArray
		};

		static GString NameOfGemType(gmeType gType);
		static gmeType GemTypeOfName(const GString& name);	// name的字符应该全是大写的。

	public:
		gmeFieldValue();
		~gmeFieldValue();

		gmeFieldValue(gmeType type);
		gmeFieldValue(const gmeFieldValue &other);
		gmeFieldValue(bool b);
		gmeFieldValue(char c);
		gmeFieldValue(short s);
		gmeFieldValue(int32 i);
		gmeFieldValue(int64 ll);
		gmeFieldValue(float f);
		gmeFieldValue(double d);
		gmeFieldValue(const GString& str);
		gmeFieldValue(const void *blob, int len);

		gmeFieldValue& operator=(const gmeFieldValue &other);
		bool operator=(const bool &b);
		bool operator=(const char &c);
		bool operator=(const short &s);
		bool operator=(const int32 &i);
		bool operator=(const int64 &ll);
		bool operator=(const double &d);
		bool operator=(const float &f);
		bool operator=(const GString &str);//字符串
		bool operator=(const char* str);//字符串
		bool operator=(const gmeByteArray* pBinary);//二进制
		bool operator=(const std::vector<char>* pBinary);//二进制
		bool setBlobValue(const void *pBinary, int len);//二进制

		void Clear();
		gmeFieldValue::gmeType getType() const { return mType; }
		int getByteArrayLen();

		bool ToBool() const;
		char ToChar() const;
		short ToInt16() const;
		int32 ToInt32(bool *ok = 0) const;
		int64 ToInt64(bool *ok = 0) const;
		float ToReal32(bool *ok = 0) const;
		double ToReal64(bool *ok = 0) const;
		const char* ToString() const;
		const void* ToBlob(long* lBytes=NULL) const;

		inline void setNULL( );
		inline bool isNull()	{return (mType==Type_Null)?true:false;}

		void* GetValuePtr() const;

	private:
		gmeType	mType;
		//以下多种类型的字段值只能选其一.
		bool	   bVal;
		char	   cVal;
		short	   sVal;
		int32	   iVal;
		int64	   llVal;
		float	   fVal;
		double	   dVal;
		GString	   mstrVal;//字符串型的字段值
		gmeByteArray mBlobVal;//blob型字段值
	};
	typedef std::vector<gmeFieldValue>		gmeFieldValues;


	class OG_GME_API gmeField //属性字段
	{
	public:
		gmeField( const GString& name = GString(), gmeFieldValue::gmeType type = gmeFieldValue::Type_Null, int len = 0, int prec = 0, const GString& comment = GString(), int bytes = 0);
		~gmeField();

		bool operator==( const gmeField& other ) const;
		bool operator!=( const gmeField& other ) const;
		gmeField& operator=(const gmeField &other)  ;

		const GString & GetName() const;
		gmeFieldValue::gmeType GetType() const;
		int GetLength() const;
		int GetPrecision() const;
		const GString & GetComment() const;
		std::string GetTypename() const;
		void GetValueRange(GString& minValue,GString& maxValue,GString& invalidValue) const;
		const GString& GetInvalidValue() const;
		int GetBytes() const;

		void SetName(GString & name);
		void SetType( gmeFieldValue::gmeType type );
		void SetLength( int len );
		void SetPrecision( int prec );
		void SetComment( const GString & comment );
		void SetValueRange(const GString& minValue,const GString& maxValue,const GString& invalidValue);
		void SetInvalidValue(const GString& invalidValue);
		void SetBytes(int bytes);

	private:
		GString mName;
		gmeFieldValue::gmeType mType;
		int mLength;//整数部分位数
		int mPrecision;//小数部分位数
		GString mComment;
		GString mMinValue;
		GString	mMaxValue;
		GString mInvalidValue;
		int mBytes;//字节长度
	};



		
	class OG_GME_API gmeFields //字段集
	{
		friend class gmeStorageDB;
	public:
		gmeFields();
		gmeFields(const gmeFields& fields);
		~gmeFields();
		
	public:
		gmeFields& operator=(const gmeFields &other);
		void Clear();
		bool Append( const gmeField& field);
		void Remove( int fieldIdx );
		void Extend( gmeFields& other );
		inline bool IsEmpty() const { return mpFields.empty(); }

		inline int GetCount() const { return (int)mpFields.size(); }

		inline gmeField& operator[](int i);
		gmeField& operator[](const GString& name);
		int GetIndex( const GString& name ) const ;
		bool GetField(const GString& name, gmeField& field) const;
		const gmeField& GetField(int i) const;
		std::vector<gmeField> &GetFields();
		bool AppendFld(const gmeField& field);
		bool AppendFld(int fieldNum, gmeField *pField);

	public:
		std::vector<gmeField> mpFields;
	};


	//记录
	class OG_GME_API gmeRecord //属性记录
	{
	public:
		gmeRecord();
		gmeRecord( gmeFields& fields);
		gmeRecord( gmeFields* ptFields);
		virtual ~gmeRecord();

	public:
		gmeRecord* operator=(const gmeRecord &rcd);
		gmeFieldValue* operator[](int32 idx) const;

	public:
		//清空
		bool Clear();
		//设置结构
		bool SetStru(const gmeFields &fields);
		bool SetStru(gmeFields * pfields);
		//获取结构
		bool GetStru(gmeFields &stru);
		gmeFields*	GetStruPtr() ;

		//设置字段值(根据字段序号)
		bool SetValue(short fldi, const gmeFieldValue& val);
		//设置字段值(根据字段名称)
		bool SetValue(const char *fldName, const gmeFieldValue& val);
		bool SetValue(const GString& fldName, const gmeFieldValue& val);
		//设置字段值(全部) 20200111 zc
		bool SetValues(gmeFieldValues& val);
		//取字段值(全部)
		bool GetValues(gmeFieldValues& val);
		//取字段值(根据字段序号)
		bool GetValue(short fldi, gmeFieldValue& val);	
		bool GetValue(const char *fldName, gmeFieldValue& val);
		bool GetValue(const GString& fldName, gmeFieldValue& val);

		// 添加一个字段和值
		void append(const gmeField& gme_field, const gmeFieldValue value);

		//设置所有字段值为NULL
		void SetAllFldNull();
		bool SetFldNull(short fldi);
		bool SetFldNull(const char *fldName);
		bool SetField(const char *fldName, char *pBuf, int sizeOfBytes);
		int  GetFldPos(const char *fldName);
	protected:
		bool InitialAtt(gmeFields* ptFields);
		
	private: 
		gmeFields			mpFields;
		gmeFieldValues      mpAtt;
	};





	//点线面的参数类定义
	class OG_GME_API C3DBaseShapeStyle
	{
	public:
		long		m_lShpType;
	};
	class OG_GME_API CPointStyleParam : public C3DBaseShapeStyle
	{
	protected:
		//改变数据标志1--新数据  0--旧数据(已存入数据库),2--数据已修改,
		char	m_NewData;
		//点类型--子图(0)、注记(1)
		int		m_nType;
		//点颜色
		long	m_lPntColor; // 这是RGBA呢？还是ARGB呢？还是ABGR呢？奇也怪也。(参考自gme_color4)
		//子图号
		long	m_lSubGraph;
		//点尺寸-高
		float	m_fPntHeight;
		//点尺寸-宽
		float	m_fPntWidth;
		//注记-字符串
		char    m_strNoteName[128];
		//注记-字体型号
		long    m_lNoteFont;
		//注记-颜色号
		long    m_lNoteClr;
		//注记-尺寸-高
		float   m_fNoteHeight;
		//注记-尺寸-宽
		float   m_fNoteWidth;
		//注记-角度
		float   m_fNoteAngle;
		//透明度
		float   m_fPntAlpha;

	public:
		CPointStyleParam();
		~CPointStyleParam();
		void SetNewData(char NewData);
		char  GetNewData();
		void SetType(int nType);
		int  GetType();
		void SetPntColor(long lColor);
		long GetPntColor();
		void SetSubGraph(long lStyle);
		long GetSubGraph();
		void SetPntHeight(float fHeight);
		float GetPntHeight();
		void SetPntWidth(float fWidth);
		float GetPntWidth();
		void SetNoteName(std::string strNoteName);
		std::string GetNoteName();
		void SetNoteFont(long lNoteFont);
		long GetNoteFont();
		void SetNoteColor(long lColor);
		long GetNoteColor();
		void SetNoteHeight(float fHeight);
		float GetNoteHeight();
		void SetNoteWidth(float fWidth);
		float GetNoteWidth();
		void SetNoteAngle(float fAngle);
		float GetNoteAngle();
		void  SetAlpha(float fAlpha);
		float GetAlpha();
		//判断对象是否为空
		long	IsValid(void);
	};
	class OG_GME_API CLineStyleParam : public C3DBaseShapeStyle
	{
	protected:
		//改变数据标志1--新数据  0--旧数据(已存入数据库),2--数据已修改,
		char	m_NewData;
		//线颜色
		long	m_lColor;
		//线型 (公路线、铁路线等)
		long	m_lStyle;
		//副线型
		long    m_lSubSty;
		//线宽
		float	m_fWidth;
		//透明度
		float   m_fLineAlpha;

	public:
		CLineStyleParam();
		~CLineStyleParam();
		void SetNewData(char NewData);
		char  GetNewData();
		void SetColor(long lColor);
		long GetColor();
		void SetStyle(long lStyle);
		long GetStyle();
		void SetSubStyle(long lSubStyle);
		long GetSubStyle();
		void SetWidth(float fWidth);
		float GetWidth();
		void  SetAlpha(float fAlpha);
		float GetAlpha();
		//判断对象是否为空
		long	IsValid(void);
	};
	class OG_GME_API CSurfaceStyleParam : public C3DBaseShapeStyle
	{
	protected:
		//显示信息对应的线ID
		GME_TYPE_OBJ_ID	m_nSurfaceID;
		//改变数据标志1--新数据  0--旧数据(已存入数据库),2--数据已修改,
		char			m_NewData;
		//图案号
		std::string 	m_lPatternNum;
		//图案颜色
		long	m_lPatternClr;
		//面宽
		float	m_fWidth;
		//面高
		float   m_fHeight;
		//区颜色
		long    m_lAreaClr;
		//透明度
		float   m_fAlpha;


	public:
		CSurfaceStyleParam();
		~CSurfaceStyleParam();
		void SetSurfaceID(GME_TYPE_OBJ_ID nSurfaceID);
		GME_TYPE_OBJ_ID GetSurfaceID();
		void SetNewData(char NewData);
		char  GetNewData();
		void  SetPatternNum(std::string lPatternNum);
		std::string  GetPatternNum();
		void  SetPatternClr(long lPatternClr);
		long  GetPatternClr();
		void  SetWidth(float fWidth);
		float GetWidth();
		void  SetHeight(float fHeight);
		float GetHeight();
		void  SetAreaClr(long lAreaClr);
		long  GetAreaClr();
		void  SetAlpha(float fAlpha);
		float GetAlpha();
		//判断对象是否为空
		long	IsValid(void);
	};


	typedef		std::vector<gmeRecord>	gmeRecordSet;//属性记录集合
	int getattname(long in, std::string &out);
	bool  boxinsphere(gme_rect_3d & box, const gme_vector3d * dot, double r);
	bool insphere(const gme_vector3d & p1, const gme_vector3d * p2, double r);
	typedef struct gme_mdl_db_info
	{
		GString		dbUrl;//数据库连接地址
		GString		dbUser;//用户名
		GString		dbPsw; //密码
		GME_LinkType	mLinkType;//数据库类型
		GME_TYPE_OBJ_ID dbID; //数据库ID
	}gme_mdl_db_info;

	typedef struct OG_GME_API gme_mdl_featID  //要素类和要素ID
	{
		GME_TYPE_OBJ_ID			fClsID;
		std::vector<GME_TYPE_OBJ_ID>	featID;

		gme_mdl_featID& operator = (const gme_mdl_featID& gme);
		bool operator == (const gme_mdl_featID& gme) const;
	}gme_mdl_fcls_ID;
	//=======================要素的实体列表
	typedef struct Gme_Feature_GeoEntData
	{
		long GeoEntNum;
		std::vector<GME_TYPE_OBJ_ID>	GeoEnryList;
	}Gme_Feature_GeoEntData;
	typedef struct GME_Geometry_ID
	{
		GME_TYPE_OBJ_ID GeometryID;
		GME_OBJ_TYPE	GeometryType;
		
	}GME_Geometry_ID;
	typedef struct gme_feature_relation //要素关系
	{
		GME_TYPE_OBJ_ID				featID1;
		GME_TYPE_OBJ_ID				featID2;
		GME_FEATURE_RELATION_TYPE	relationType;
		GME_FEATURE_RELATION_VALUE	relationVal;
	}gme_feature_relation;

	typedef struct gme_legend_cell //图例块
	{
		gme_vector3i leftUpPos;
		GString		strCellName;
		GString		strNote;
		gme_color4	bkCell;
		long		subNo; //图例块中的符号
	}gme_legend_cell;

	typedef struct gme_note_info
	{
		double height;
		double width;
		double angle1;
		double angle2;
		long chFont;
		long enFont;
		gme_color4 color;
		GME_NOTE_DISP_TYPE noteDispType;
	}gme_note_info;

	typedef struct gme_note_content
	{
		gme_vector3d	notePos;
		GString			strNote;
	}gme_note_content;


	//DEM信息表
	typedef struct gme_dem_info //dem基本信息
	{
		GME_TYPE_OBJ_ID		lDemID;
		GString				strDemName;
		gme_date_time		demDate;
		bool				bIsExist;
		gme_rect_3d			demBox;
		GME_TYPE_OBJ_ID		boundEntID;
		long				lLevelNum;
		GME_VOLUME_CELL_TYPE demDataType;
		gme_vector3d		demLeftLowerPos;
		GString				strDemDesc;
	}gme_dem_info;


	typedef struct OG_GME_API gme_dem_level //dem级别
	{
		GME_TYPE_OBJ_ID		lDemID;
		long				lLevelNo;
		long				lRowPntNum;
		long				lColPntNum;
		long				RowBlockNum;
		long				ColBlockNum;
		gme_dem_level& operator = (const gme_dem_level& gme);
	}gme_dem_level;

	typedef struct gme_dem_re_tile //dem块数据
	{
		GME_TYPE_OBJ_ID	 lDemID;
		long			 lLevelNo;
		long			 lRowNo;
		long			 lColNo;
		std::vector<double>	 demReTileData; //是规则数据

	}gme_dem_re_tile;


	typedef struct gme_IrreTileData //dem不规则数据
	{
		std::vector<gme_vector3d> irPoint; //离散点坐标
		std::vector<long> tirNo;    //三角形顶点号
		std::vector<long> nextNo;   //邻接三角形号
	} gme_IrreTileData;

	typedef struct gme_dem_irre_tile //dem块数据
	{
		GME_TYPE_OBJ_ID	 lDemID;
		long			 lLevelNo;
		long			 lRowNo;
		long			 lColNo;
		gme_IrreTileData	 demIrreTileData; //不规则数据

	}gme_dem_irre_tile;

	//属性场信息
	typedef struct gme_field_info //属性场基本信息
	{
		long				lFieldID;
		GString				strFieldName;
		GME_TYPE_OBJ_ID		boundEntID;
		GME_VOLUME_CELL_TYPE fieldDataType;
		long				lLevelNum;
		GString				strFieldDesc;
		GME_FIELD_SPLIT_TYPE splitType;
		gme_vector3d		transFactor;
		gme_vector3d		scaleFactor;
		gme_vector3d		rotateFactor;
	}gme_field_info;
	
	typedef struct gme_field_level //属性场级别信息
	{
		GME_TYPE_OBJ_ID		lFieldID;
		long				lLevelNo;
		long				lRowNum;
		long				lColNum;
		long				lDepNum;
		double				TileSizeX;
		double				TileSizeY;
		double				TileSizeZ;
	}gme_field_level;

	typedef struct gme_field_tile_reg //均匀剖分的属性场块数据
	{
		GME_TYPE_OBJ_ID	lFieldID;
		long			lLevelNo;
		long			lRowNo;
		long			lColNo;
		long			lDepNo;
		//
		std::string          lStratNo;//地层编码
		bool            lVisible = true;//体元可显示性,true为可显示
		//
		std::vector<double>  regTileData;
	}gme_field_tile_reg;

	typedef struct irreField_data          //不规则体元
	{
		long levelNo;
		long lTileRowNo;
		long lTileColNo;
		long lTileDepNo;
		std::vector<double> zTile;
		std::vector<gme_vector3d> verPoint;
	}irreField_data;

	typedef struct gme_field_cell_data_irreg //不均匀剖分的属性场块数据
	{
		GME_TYPE_OBJ_ID			lFieldID;
		//long					lLevelNo;
		//long					lTileRowNo;
		//long					lTileColNo;
		//long					lTileDepNo;
		long					lRowNo;
		long					lColNo;
		long					lDepNo;
		std::vector<irreField_data>	irRegTileData;
	}gme_field_cell_data_irreg;

	//vector<double> reFiele_data;    //规则体元

	
	
	

	typedef struct Gme_holeSampData //样品数据blob
	{
		gme_vector3d holeSampPoint;
		std::string soilcode;
		std::vector<double> v;
	}Gme_holeSampData;


	//线表中关于blob字段的结构体定义
	typedef struct Gme_Line_LinBound //线表-线边界
	{
		GME_TYPE_OBJ_ID	lFromPointID;
		GME_TYPE_OBJ_ID	lToPointID;
	
	}Gme_Line_LinBound;

	typedef struct Gme_Line_vertData //线表-顶点数据 and 面表-顶点数据
	{
		long iPntNum;
		long iClrNum;
		long NormalNum;
		std::vector<gme_color4> vPntColor;
		//纹理，8*点数，1通道所有点...
		std::vector<gme_vector3d> vPntNormal;
		std::vector<gme_tex_coord> vTexcoordMap;
		std::vector<gme_vector3d> vPntData;

	}Gme_Line_vertData;

	typedef struct Gme_Line_LinEdgeData //线表-边数据
	{
		int iEdgNum;
		std::vector<long> vLinEdge;   //边上点的id 2*iEdgNum

	}Gme_Line_LinEdgeData;

	//面表中关于blob字段的结构体定义
	typedef struct Gme_Surface_SurfBound //面表-面边界
	{
		long lLineNum;
		std::vector<GME_TYPE_OBJ_ID>  vSurfLins;   //线id

	}Gme_Surface_SurfBound;

	typedef struct Gme_Surface_Facetvertices //面表-面片顶点数据 and 面表-邻接面片
	{
		long lFacetNum;
		std::vector<GME_TYPE_OBJ_ID> vCellPntNos;//顶点id，3*lFacetNum

	}Gme_Surface_Facetvertices;

	//体表中关于blob字段的结构体定义
	typedef struct Gme_Region_CellVertData //体表-体元顶点索引数据
	{
		long lCellNum;//体元个数
		long lFacetNumPerCell;//1个体元的三角形数
		std::vector<long>  vCellData;   //体元顶点索引，体元个数*1个体元的顶点数
	}Gme_Region_CellVertData;

	typedef struct Gme_Region_AdjCellVertData //体表-邻接体元数据
	{
		long lAdjNum;//邻接体元的个数
		std::vector<long>  vAdjCellIDs;   //邻接体元编号
	}Gme_Region_AdjCellVertData;




	//typedef struct Gme_Contact_linData//线ID列表
	//{
	//	long linesNum;//线ID数量
	//	vector<GME_TYPE_OBJ_ID> linesID;//线ID列表
	//}Gme_Contact_linData;


	///////////////////////////////////////三维模型的blob存储
	typedef struct blob_Mdl_SubMdlData
	{
		long SubMdlNum;
		std::vector<GME_TYPE_OBJ_ID> mdlSubMdldata;
	}Gme_Mdl_SubMdlData;

	typedef struct blob_Mdl_MdlData
	{
		long MdlFlsNum;
		std::vector<gme_mdl_featID> mdlFls;
	}Gme_Mdl_MdlData;
	/////////////////////////////////////////////////////////



	//钻孔分层数据...
	typedef struct gme_holelayer
	{
		gme_holelayer()
		{
			stratCode = "";//地层编码
			topDepth = 0;	//地层顶部埋深
			bottomDepth = 0;//地层底部埋深

			dip = 90;
			azimuth = 0; //测斜数据（直孔不需要）
			clr = 0; //颜色
		}
		std::string	stratCode;//地层编码
		double	topDepth;	//地层顶部埋深
		double	bottomDepth;//地层底部埋深

		double  dip, azimuth; //测斜数据（直孔不需要）
		int		clr; //地层颜色
	}gme_holelayer;
	typedef struct gme_hole
	{
		gme_hole()
		{
			holePos.x= holePos.y = holePos.z = 0;
			holeCode = "";
			holeDepth = 0;
			holeType = 0;
			dispType = 1;
			segNum = 5;
			radius = 5.0;
		}
		gme_vector3d	holePos;//钻孔位置
		std::string	holeCode;	//地层编码
		double	holeDepth;	//钻孔深度

		int		holeType;	//钻孔类型（0-直孔，1-斜孔）
		int		dispType;	//显示类型(0-线状 1-柱状)
		int		segNum;		//钻孔横截面段数（建模用）
		double	radius;		//钻孔孔径
		std::vector<gme_holelayer>	holeLayer;//分层数据
		std::vector<Gme_holeSampData> mHoleSampData;// 样品数据
	}gme_hole;

	typedef struct gme_fault
	{
		gme_fault()
		{
			mFaultType = GME_FT_NORMAL_FAULT;	//断层类型
			mFaultName = ""; //断层名称
			mFaultCode = ""; //断层编码
			mDipType = GME_GDT_REAL_DIP;	//断层倾角类型（真倾角 / 视倾角）
			mDipDir = 0;	//断层的倾向
			mDip = 0;			//断层的倾角
			mExtendDepth = 2000;//断层的延展深度
			mBlockBufferDist = 50;//块状模型厚度
			clr = 0;
			mDispType = 1; //断层显示类型，0-面状 1-块状
			mScale = 1;
		}
		GME_FAULT_TYPE	mFaultType;	//断层类型
		GString			mFaultName; //断层名称
		GString			mFaultCode;	//断层编码
		GME_GEO_DIP_TYPE mDipType;	//断层倾角类型（真倾角、视倾角）
		double			mDipDir;	//断层的倾向
		double			mDip;		//断层的倾角
		std::vector<std::vector<gme_vector3d>> mFaultGeoData; //断层几何数据
		double			mExtendDepth;//断层的延展深度
		double          mBlockBufferDist;//块状模型的厚度
		int				clr; //断层颜色
		int				mDispType; //断层显示类型，0-面状 1-块状
		double          mScale; //断层根据长度所得的缩放比例系数
	}gme_fault;
}

