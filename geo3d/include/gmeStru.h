#pragma once

#include "s3dGMdlDBEngineExp.h"
#include "gmeDef.h"

//������Ľṹ���� 
#include "gme_vector2.h"
#include "gme_vector3.h"
#include "gme_vector4.h"

#include <windows.h>

namespace Smart3dMap
{
	//==========================ʱ��ṹ����==============================================================
	typedef struct gme_date
	{
		short  year;//��
		char   mon;	//��
		char   day;	//��
	}gme_date;


	typedef struct gme_time
	{
		char   hour;//ʱ
		char   min;	//��
		double sec;	//��
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
	//2.1 �ռ����ϵ�Ľṹ:
	typedef struct gme_sref
	{
		GME_TYPE_OBJ_ID ID;		//�ռ����ϵ��ID��
		GString			name;	//�ռ����ϵ������
		short			srType;	//�ռ����ϵ������
	}gme_sref;


	//��ͼ��Ϣ���ο�Google
	typedef struct gme_lookat
	{	
	public:
		double 		m_dx;					//λ��x
		double		m_dy;					//λ��y
		double		m_Distance;			    //����
		double		m_Heading;			    //��λ
		double  	m_Tilt;				    //��б
	}gme_lookat;

	//���θ߶�����
	class gme_altitude
	{
	public:
		gme_altitude()
		{
			m_AltitudeMode =  GME_CLOSE_TO_GROUND;
			m_Height = 0;
			m_Extend = 0;
		}
		GME_GROUND_MODE		m_AltitudeMode;	//�߶�ģʽ
		double				m_Height;		//�߶ȣ�ģʽΪ AM_CLOSE_TO_GROUNDʱ��ʹ��
		bool				m_Extend;		//Ԥ�����Ƿ�����������(Ϊtrue����עλ�ڵ�����������һ���ӱ�ע�������������)
	};



	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// �Ƕȶ�����ת����װ��

	class gme_degree;
	// 1�����ȵķ�װ�࣬�����������������֮�ص��Զ�ת��
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


	// 2�������ķ�װ�࣬�����������뻡����֮�ص��Զ�ת��
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
	
	//====================================double��==================

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// �Ƕȶ�����ת����װ��

	class gme_degree_d;
	// ���ȵķ�װ�࣬�����������������֮�ص��Զ�ת��
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


	// �����ķ�װ�࣬�����������뻡����֮�ص��Զ�ת��
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

	// ����Ӧ�ö��壺
	// �˷����� ---- ���е�P, ����M, ����˽������Ϊ P' = P * M, ����ͨͼ��ѧ�ж��岻ͬ(P' = M * P)
	// ���Ӷ��� ---- �赱ǰ����ΪM, ��M1, M2, M3..., �����˽������Ϊ C = M * M1 * M2 * M3 * ...
	//					����ͨͼ��ѧ�ж��岻ͬ(C = ... * M3 * M2 * M1 * M)
	//				����Ч��������������ˣ���Ч����Ӧ�Ĵ�M1��ʼ��M2,����...
	
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

		// ����ת��������Ԫ��
		inline gme_quaternion(const gme_matrix3& rot);

		// ����ת��ͽǶȹ�����Ԫ��
		inline gme_quaternion(const gme_radian& rfAngle, const gme_vector3f& rkAxis);

		// �����������ṹ����Ԫ��
		inline gme_quaternion(const gme_vector3f& xaxis, const gme_vector3f& yaxis, const gme_vector3f& zaxis);

		// �����������ṹ����Ԫ��,���������ṩ����
		inline gme_quaternion(const gme_vector3f* akAxis);

		// ��ת��������Ԫ��֮���ת��
		void FromRotationMatrix(const gme_matrix3& kRot);
		void ToRotationMatrix(gme_matrix3& kRot) const;

		// (��ת��, �Ƕ�) ����Ԫ��֮���ת��
		void FromAngleAxis(const gme_radian& rfAngle, const gme_vector3f& rkAxis);
		void ToAngleAxis(gme_radian& rfAngle, gme_vector3f& rkAxis) const;
		void ToAngleAxis(gme_degree& dAngle, gme_vector3f& rkAxis) const;

		// ����������Ԫ��֮���ת��,�������������ṩ����
		void FromAxes(const gme_vector3f* akAxis);
		void FromAxes(const gme_vector3f& xAxis, const gme_vector3f& yAxis, const gme_vector3f& zAxis);
		void ToAxes(gme_vector3f* akAxis) const;
		void ToAxes(gme_vector3f& xAxis, gme_vector3f& yAxis, gme_vector3f& zAxis) const;

		// ��ȡ��ǰ��Ԫ��������X��
		gme_vector3f xAxis(void) const;
		// ��ȡ��ǰ��Ԫ��������Y��
		gme_vector3f yAxis(void) const;
		// ��ȡ��ǰ��Ԫ��������z��
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

		// ��Ԫ���������
		// ���
		GREAL DotProduct(const gme_quaternion& rkQ) const;

		// ���ȵ�ƽ��
		GREAL SquaredLength() const;

		// ��λ����������ԭ���ĳ���
		GREAL Normalise(void);
		gme_quaternion Inverse() const;		// apply to non-zero gme_quaternion
		gme_quaternion UnitInverse() const;	// apply to unit-length gme_quaternion
		gme_quaternion Exp() const;
		gme_quaternion Log() const;

		// �õ�ǰ��Ԫ������������ת����תһ������
		gme_vector3f operator* (const gme_vector3f& rkVector) const;

		// ���㲢ȡ�� Roll��
		gme_radian GetRoll(void) const;
		// ���㲢ȡ�� Picth��
		gme_radian GetPitch(void) const;
		// ���㲢ȡ�� Yaw��
		gme_radian GetYaw(void) const;
		// �� tolerance �ĽǶ��ݲ��ж�������Ԫ���Ƿ����
		bool Equals(const gme_quaternion& rhs, const gme_radian& tolerance) const;

		// �����Բ�ֵ
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

		// �д�ȡ����
		inline GREAL* operator[] (size_t nRow) const;
		gme_vector3f GetRow(size_t nRow) const;
		void	SetRow(size_t nRow, const gme_vector3f& vec);

		// �д�ȡ����
		gme_vector3f GetColumn(size_t nCol) const;
		void	SetColumn(size_t nCol, const gme_vector3f& vec);

		// ͨ������XYZ������
		void	FromAxis(const gme_vector3f& xAxis, const gme_vector3f& yAxis, const gme_vector3f& zAxis);

		// ��ֵ
		inline gme_matrix3& operator = (const gme_matrix3& mat);

		// �Ƚ�
		inline bool operator == (const gme_matrix3& mat) const;
		inline bool operator != (const gme_matrix3& mat) const;

		// ����
		inline gme_matrix3 operator + (const gme_matrix3& mat) const;
		inline gme_matrix3 operator - (const gme_matrix3& mat) const;
		inline gme_matrix3 operator * (const gme_matrix3& mat) const;
		inline gme_matrix3 operator - () const;

		// ʸ�����
		gme_vector3f operator * (const gme_vector3f& vec) const;
		OG_GME_API friend gme_vector3f operator * (const gme_vector3f& vec, const gme_matrix3& mat);

		// �������
		gme_matrix3 operator * (GREAL fScalar) const;
		OG_GME_API friend gme_matrix3 operator * (GREAL fScalar, const gme_matrix3& mat);

		// ȡ��ǰ�����ת�þ���
		gme_matrix3 TransposeCopy() const;

		// ���õ�ǰ����Ϊת�þ���
		void	Transpose();

		// ȡ�������
		gme_matrix3	GetAdjoint() const;

		// ȡ����ֵ
		GREAL GetDeterminant() const;

		// ȡ�����
		bool GetInverse(gme_matrix3& mat) const;

		// ���õ�ǰ����Ϊ�����
		void	SetToInverse();

		// ���õ�ǰ����Ϊ��λ����
		inline void LoadIdentity(void);

		// ������ˣ���������
		inline gme_matrix3 Multiply(const gme_matrix3& mat);

		// ʩ������������
		void Orthonormalize();

		// ���²����������������Ļ�����
		// ת��Ϊ��ͽǶ�
		void ToAxisAngle(gme_vector3f& vAxis, gme_radian& rad) const;
		void ToAxisAngle(gme_vector3f& vAxis, gme_degree& deg) const;

		// ����ͽǶ�ת��
		void FromAxisAngle(const gme_vector3f& vAxis, const gme_radian& rad);
		void FromAxisAngle(const gme_vector3f& vAxis, const gme_degree& deg);

		// ת��Ϊŷ����
		bool ToEulerAnglesXYZ(gme_radian& rfYAngle, gme_radian& rfPAngle, gme_radian& rfRAngle) const;
		bool ToEulerAnglesXZY(gme_radian& rfYAngle, gme_radian& rfPAngle, gme_radian& rfRAngle) const;
		bool ToEulerAnglesYXZ(gme_radian& rfYAngle, gme_radian& rfPAngle, gme_radian& rfRAngle) const;
		bool ToEulerAnglesYZX(gme_radian& rfYAngle, gme_radian& rfPAngle, gme_radian& rfRAngle) const;
		bool ToEulerAnglesZXY(gme_radian& rfYAngle, gme_radian& rfPAngle, gme_radian& rfRAngle) const;
		bool ToEulerAnglesZYX(gme_radian& rfYAngle, gme_radian& rfPAngle, gme_radian& rfRAngle) const;

		// ��ŷ����ת��
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

		// ������ˣ���������
		inline gme_matrix4 Multiply(const gme_matrix4& mat);

		// ����һ������ C = M * M1 * M2 * M3 ........
		// M ����ǰ����, ֻ���ؽ��,���޸ĵ�ǰ����
		inline gme_matrix4 MultiplyCopy(const gme_matrix4& mat) const;

		// ȡ��ǰ�����ת�þ���
		inline gme_matrix4 TransposeCopy(void) const;

		// ���õ�ǰ����Ϊת�þ���
		inline void Transpose(void);

		// ���õ�ǰ����Ϊ��λ����
		inline void LoadIdentity(void);

		// ���õ�ǰ�����ƽ�Ʋ���
		inline void SetTransPart(const gme_vector3f& v);

		// ȡ��ǰ�����ƽ�Ʋ���
		inline gme_vector3f GetTransPart(void) const;

		// �ؽ�Ϊһ��ƽ�ƾ���
		inline void MakeTrans(const gme_vector3f& v);
		inline void MakeTrans(GREAL vx, GREAL vy, GREAL vz);

		// ����һ��ƽ�ƾ���
		inline static gme_matrix4 BuildTrans(const gme_vector3f& v);
		inline static gme_matrix4 BuildTrans(GREAL vx, GREAL vy, GREAL vz);

		//����ȡ��ǰ��������Ų���
		inline gme_vector3f	GetScalePart(void) const;
		inline void		SetScalePart(const gme_vector3f& v);

		// �������ž���
		inline static gme_matrix4 BuildScale(const gme_vector3f& v);
		inline static gme_matrix4 BuildScale(GREAL vx, GREAL vy, GREAL vz);

		//��������������
		inline gme_matrix4 operator * (GREAL scalar);

		// ȡ�������
		gme_matrix4	GetAdjoint() const;

		// ȡ����ֵ
		GREAL GetDeterminant() const;

		// ȡ�����
		gme_matrix4 GetInverse() const;

		// ���õ�ǰ����Ϊ�����
		void	SetToInverse();


		// ��ǰ����������һ���Ƕȵ���ת�������
		inline void RotationX(gme_radian rad);
		inline void RotationY(gme_radian rad);
		inline void RotationZ(gme_radian rad);

		// ������������ת����
		inline void SetRotationX(gme_radian rad);
		inline void SetRotationY(gme_radian rad);
		inline void SetRotationZ(gme_radian rad);

		// �����Կռ�ĳ��Ϊ��ת���ģ��ƿռ������ת����
		void SetRotationAboutCenter(gme_radian rad, const gme_vector3f& ptCenter, GME_SPACE_AXIS_DIR adType);

		// �����ƿռ���������ת�ľ���
		void SetRotationAboutVector(gme_radian rad, const gme_vector3f& v);

		// ��ȡ 3 X 3 ����
		inline void Extract3x3Matrix(gme_matrix3& m3x3) const;

		// ��ȡ��Ԫ��
		inline gme_quaternion ExtractQuaternion() const;// 

	};

	//==============================double================================
			// ����Ӧ�ö��壺
		// �˷����� ---- ���е�P, ����M, ����˽������Ϊ P' = P * M, ����ͨͼ��ѧ�ж��岻ͬ(P' = M * P)
		// ���Ӷ��� ---- �赱ǰ����ΪM, ��M1, M2, M3..., �����˽������Ϊ C = M * M1 * M2 * M3 * ...
		//					����ͨͼ��ѧ�ж��岻ͬ(C = ... * M3 * M2 * M1 * M)
		//				����Ч��������������ˣ���Ч����Ӧ�Ĵ�M1��ʼ��M2,����...

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

		// ����ת��������Ԫ��
		inline gme_quaternion_d(const gme_matrix3_d& rot);

		// ����ת��ͽǶȹ�����Ԫ��
		inline gme_quaternion_d(const gme_radian_d& rfAngle, const gme_vector3d& rkAxis);

		// �����������ṹ����Ԫ��
		inline gme_quaternion_d(const gme_vector3d& xaxis, const gme_vector3d& yaxis, const gme_vector3d& zaxis);

		// �����������ṹ����Ԫ��,���������ṩ����
		inline gme_quaternion_d(const gme_vector3d* akAxis);

		// ��ת��������Ԫ��֮���ת��
		void FromRotationMatrix(const gme_matrix3_d& kRot);
		void ToRotationMatrix(gme_matrix3_d& kRot) const;

		// (��ת��, �Ƕ�) ����Ԫ��֮���ת��
		void FromAngleAxis(const gme_radian_d& rfAngle, const gme_vector3d& rkAxis);
		void ToAngleAxis(gme_radian_d& rfAngle, gme_vector3d& rkAxis) const;
		void ToAngleAxis(gme_degree_d& dAngle, gme_vector3d& rkAxis) const;

		// ����������Ԫ��֮���ת��,�������������ṩ����
		void FromAxes(const gme_vector3d* akAxis);
		void FromAxes(const gme_vector3d& xAxis, const gme_vector3d& yAxis, const gme_vector3d& zAxis);
		void ToAxes(gme_vector3d* akAxis) const;
		void ToAxes(gme_vector3d& xAxis, gme_vector3d& yAxis, gme_vector3d& zAxis) const;

		// ��ȡ��ǰ��Ԫ��������X��
		gme_vector3d xAxis(void) const;
		// ��ȡ��ǰ��Ԫ��������Y��
		gme_vector3d yAxis(void) const;
		// ��ȡ��ǰ��Ԫ��������Z��
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

		// ��Ԫ���������
		// ���
		GDOUBLE DotProduct(const gme_quaternion_d& rkQ) const;

		// ���ȵ�ƽ��
		GDOUBLE SquaredLength() const;

		// ��λ����������ԭ���ĳ���
		GDOUBLE Normalise(void);
		gme_quaternion_d Inverse() const;		// apply to non-zero gme_quaternion_d
		gme_quaternion_d UnitInverse() const;	// apply to unit-length gme_quaternion_d
		gme_quaternion_d Exp() const;
		gme_quaternion_d Log() const;

		// �õ�ǰ��Ԫ������������ת����תһ������
		gme_vector3d operator* (const gme_vector3d& rkVector) const;

		// ���㲢ȡ�� Roll��
		gme_radian_d GetRoll(void) const;
		// ���㲢ȡ�� Picth��
		gme_radian_d GetPitch(void) const;
		// ���㲢ȡ�� Yaw��
		gme_radian_d GetYaw(void) const;
		// �� tolerance �ĽǶ��ݲ��ж�������Ԫ���Ƿ����
		bool Equals(const gme_quaternion_d& rhs, const gme_radian_d& tolerance) const;

		// �����Բ�ֵ
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

		// �д�ȡ����
		inline GDOUBLE* operator[] (size_t nRow) const;
		gme_vector3d GetRow(size_t nRow) const;
		void	SetRow(size_t nRow, const gme_vector3d& vec);

		// �д�ȡ����
		gme_vector3d GetColumn(size_t nCol) const;
		void	SetColumn(size_t nCol, const gme_vector3d& vec);

		// ͨ������XYZ������
		void	FromAxis(const gme_vector3d& xAxis, const gme_vector3d& yAxis, const gme_vector3d& zAxis);

		// ��ֵ
		inline gme_matrix3_d& operator = (const gme_matrix3_d& mat);

		// �Ƚ�
		inline bool operator == (const gme_matrix3_d& mat) const;
		inline bool operator != (const gme_matrix3_d& mat) const;

		// ����
		inline gme_matrix3_d operator + (const gme_matrix3_d& mat) const;
		inline gme_matrix3_d operator - (const gme_matrix3_d& mat) const;
		inline gme_matrix3_d operator * (const gme_matrix3_d& mat) const;
		inline gme_matrix3_d operator - () const;

		// ʸ�����
		gme_vector3d operator * (const gme_vector3d& vec) const;
		OG_GME_API friend gme_vector3d operator * (const gme_vector3d& vec, const gme_matrix3_d& mat);

		// �������
		gme_matrix3_d operator * (GDOUBLE fScalar) const;
		OG_GME_API friend gme_matrix3_d operator * (GDOUBLE fScalar, const gme_matrix3_d& mat);

		// ȡ��ǰ�����ת�þ���
		gme_matrix3_d TransposeCopy() const;

		// ���õ�ǰ����Ϊת�þ���
		void	Transpose();

		// ȡ�������
		gme_matrix3_d	GetAdjoint() const;

		// ȡ����ֵ
		GDOUBLE GetDeterminant() const;

		// ȡ�����
		bool GetInverse(gme_matrix3_d& mat) const;

		// ���õ�ǰ����Ϊ�����
		void	SetToInverse();

		// ���õ�ǰ����Ϊ��λ����
		inline void LoadIdentity(void);

		// ������ˣ���������
		inline gme_matrix3_d Multiply(const gme_matrix3_d& mat);

		// ʩ������������
		void Orthonormalize();

		// ���²����������������Ļ�����
		// ת��Ϊ��ͽǶ�
		void ToAxisAngle(gme_vector3d& vAxis, gme_radian_d& rad) const;
		void ToAxisAngle(gme_vector3d& vAxis, gme_degree_d& deg) const;

		// ����ͽǶ�ת��
		void FromAxisAngle(const gme_vector3d& vAxis, const gme_radian_d& rad);
		void FromAxisAngle(const gme_vector3d& vAxis, const gme_degree_d& deg);

		// ת��Ϊŷ����
		bool ToEulerAnglesXYZ(gme_radian_d& rfYAngle, gme_radian_d& rfPAngle, gme_radian_d& rfRAngle) const;
		bool ToEulerAnglesXZY(gme_radian_d& rfYAngle, gme_radian_d& rfPAngle, gme_radian_d& rfRAngle) const;
		bool ToEulerAnglesYXZ(gme_radian_d& rfYAngle, gme_radian_d& rfPAngle, gme_radian_d& rfRAngle) const;
		bool ToEulerAnglesYZX(gme_radian_d& rfYAngle, gme_radian_d& rfPAngle, gme_radian_d& rfRAngle) const;
		bool ToEulerAnglesZXY(gme_radian_d& rfYAngle, gme_radian_d& rfPAngle, gme_radian_d& rfRAngle) const;
		bool ToEulerAnglesZYX(gme_radian_d& rfYAngle, gme_radian_d& rfPAngle, gme_radian_d& rfRAngle) const;

		// ��ŷ����ת��
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

		// ������ˣ���������
		inline gme_matrix4_d Multiply(const gme_matrix4_d& mat);

		// ����һ������ C = M * M1 * M2 * M3 ........
		// M ����ǰ����, ֻ���ؽ��,���޸ĵ�ǰ����
		inline gme_matrix4_d MultiplyCopy(const gme_matrix4_d& mat) const;

		// ȡ��ǰ�����ת�þ���
		inline gme_matrix4_d TransposeCopy(void) const;

		// ���õ�ǰ����Ϊת�þ���
		inline void Transpose(void);

		// ���õ�ǰ����Ϊ��λ����
		inline void LoadIdentity(void);

		// ���õ�ǰ�����ƽ�Ʋ���
		inline void SetTransPart(const gme_vector3d& v);

		// ȡ��ǰ�����ƽ�Ʋ���
		inline gme_vector3d GetTransPart(void) const;

		// �ؽ�Ϊһ��ƽ�ƾ���
		inline void MakeTrans(const gme_vector3d& v);
		inline void MakeTrans(GDOUBLE vx, GDOUBLE vy, GDOUBLE vz);

		// ����һ��ƽ�ƾ���
		inline static gme_matrix4_d BuildTrans(const gme_vector3d& v);
		inline static gme_matrix4_d BuildTrans(GDOUBLE vx, GDOUBLE vy, GDOUBLE vz);

		//����ȡ��ǰ��������Ų���
		inline gme_vector3d	GetScalePart(void) const;
		inline void		SetScalePart(const gme_vector3d& v);

		// �������ž���
		inline static gme_matrix4_d BuildScale(const gme_vector3d& v);
		inline static gme_matrix4_d BuildScale(GDOUBLE vx, GDOUBLE vy, GDOUBLE vz);

		//��������������
		inline gme_matrix4_d operator * (GDOUBLE scalar);

		// ȡ�������
		gme_matrix4_d	GetAdjoint() const;

		// ȡ����ֵ
		GDOUBLE GetDeterminant() const;

		// ȡ�����
		gme_matrix4_d GetInverse() const;

		// ���õ�ǰ����Ϊ�����
		void	SetToInverse();


		// ��ǰ����������һ���Ƕȵ���ת�������
		inline void RotationX(gme_radian_d rad);
		inline void RotationY(gme_radian_d rad);
		inline void RotationZ(gme_radian_d rad);

		// ������������ת����
		inline void SetRotationX(gme_radian_d rad);
		inline void SetRotationY(gme_radian_d rad);
		inline void SetRotationZ(gme_radian_d rad);

		// �����Կռ�ĳ��Ϊ��ת���ģ��ƿռ������ת����
		void SetRotationAboutCenter(gme_radian_d rad, const gme_vector3d& ptCenter, GME_SPACE_AXIS_DIR adType);

		// �����ƿռ���������ת�ľ���
		void SetRotationAboutVector(gme_radian_d rad, const gme_vector3d& v);

		// ��ȡ 3 X 3 ����
		inline void Extract3x3Matrix(gme_matrix3_d& m3x3) const;

		// ��ȡ��Ԫ��
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


		// ����һ��RGBA��ʽ����
		GME_RGBA GetAsRGBA(void) const;

		// ����һ��ARGB��ʽ����
		GME_ARGB GetAsARGB(void) const;

		// ����һ��ABGR��ʽ����
		GME_ABGR GetAsABGR(void) const;

		// �����
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

  //	=========================double����=======================
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


		// ����һ��RGBA��ʽ����
		GME_RGBA GetAsRGBA(void) const;

		// ����һ��ARGB��ʽ����
		GME_ARGB GetAsARGB(void) const;

		// ����һ��ABGR��ʽ����
		GME_ABGR GetAsABGR(void) const;

		// �����
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

	//������
	class OG_GME_API gme_triangle
	{
	public:
		union {
			struct {
				GINT a, b, c;//�����ε����������
			};
			struct {
				GINT x, y, z;//�����ε����������
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


	//������������Ϣ
	class OG_GME_API gme_triangle_top
	{
	public:
		union {
			//ab,bc,ca�ߵ��ڽ�������
			struct {
				GINT nTriNo1, nTriNo2, nTriNo3;
			};
			struct {
				GINT tri_ab, tri_bc, tri_ca;
			};
			struct {
				GINT ab,bc,ca;       // ��ab,bc,ca���ڽ�����������
			};
			struct {
				GINT a, b, c;//�����ε����������
			};
			struct {
				GINT x, y, z;//�����ε����������
			};
			GINT _v[3];
		};

		gme_triangle_top();
		~gme_triangle_top();
		long operator=(const gme_triangle_top& rhs);
	};

	//��Χ����
	class OG_GME_API gme_3denvelope
	{
	public:
		long operator=( gme_3denvelope& envelop);
		gme_3denvelope();
		virtual ~gme_3denvelope();

	public:
		//��¡������
		long Clone(gme_3denvelope* pEnvelop);

		//�ϲ���Χ
		virtual long Union(gme_3denvelope* pEnvelope);

		//���÷�Χ
		long PutCoord(gme_vector3f* pPoint, long nPoint);


	private:
		//�����
		long m_nDotNum;
		GREAL* m_pDot;
	};
	//===================================double=========================================
	//��Χ����
	class OG_GME_API gme_3denvelope_d
	{
	public:
		gme_3denvelope_d& operator=(const gme_3denvelope_d& envelop);
		gme_3denvelope_d();
		virtual ~gme_3denvelope_d();

	public:
		//��¡������
		long Clone(gme_3denvelope_d* pEnvelop);
		//�ϲ���Χ
		virtual long Union(gme_3denvelope_d* pEnvelope);

		//���÷�Χ
		long PutCoord(gme_vector3d* pPoint, long nPoint);


	private:
		//�����
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
	
	//Բ
	typedef struct gme_circle
	{
		gme_vector2d		ddCenter;
		double				dRadius;
	}gme_circle;

	//BOX��Χ
	class OG_GME_API gme_rect_3f
	{
	public:
		gme_rect_3f();
		~gme_rect_3f();
		inline gme_rect_3f& operator= (const gme_rect_3f& rhs);

	public:
		//ȡ�߶�
		double GetHeight();

		//ȡ���ĵ�
		long GetCenter(gme_vector3f* pCenter);

		//�������� add by xsm
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

	//BOX��Χ-------------------------double����
	class OG_GME_API gme_rect_3d
	{
	public:
		gme_rect_3d();
		~gme_rect_3d();
		inline gme_rect_3d& operator = (const gme_rect_3d& rhs);

	public:
		//ȡ�߶�
		double GetHeight();

		//ȡ���ĵ�
		long GetCenter(gme_vector3d* pCenter);

		//��������
		long Set(gme_vector3d &MinPoint, gme_vector3d &MaxPoint);

		//Merge
		long Merge(gme_vector3d &point);
		long Merge(const gme_rect_3d& box);

		//���ÿ�
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

	//λ������
	class	OG_GME_API gme_bitset
	{
	private:
		unsigned char *	m_pBitSet;//λ����,ÿ�ֽڴ�������λ�������
		GINT			m_lSize;//λ�������ȣ���λ��bit��

	public:
		gme_bitset(const GINT size = 0);
		~gme_bitset();
		//����λ�����Ĵ�С
		GINT SetSize(const GINT &size);
		//����λ����ĳλ�Ƿ�Ϊ1
		bool Test(const GINT &pos);
		//��������λΪ1
		bool Set();
		//����ĳλΪ1
		bool Set(const GINT &pos);
		//��������λΪ0
		bool Reset();
		//����ĳλΪ0
		bool Reset(const GINT &pos);
		//�ͷ��ڴ�
		bool Release();
		//����ֵ
		bool operator = (const gme_bitset& rhs);
	};

	//ID�б�
	class	OG_GME_API GLONGid_list
	{
	public:
		GLONGid_list();
		GLONGid_list(const GLONGid_list& src);
		virtual ~GLONGid_list();

	public:
		GLONGid_list& operator=(const GLONGid_list& rhs);

		//	ȡ��i��ID����
		GLONG operator[](int i) const;
		GINT Add(const GLONG &nID);

		//  Ψһ���
		GINT AddUnique(const GLONG &nID);
		GINT AddIDList(const GLONG *pIDList, const GINT &nIDNum);
		GINT UpdateID(const GINT &i, const GLONG &nID);
		GLONG *GetIDList();

		//��ȡ�������(=1)���ֽ���(=0)
		GINT GetCount(char IsObjorByteNum = 1);

		//����Buf��С,��λ��Byte
		short SetSize(GINT nByteSize);

		//��λ�������ڴ�
		short	Reset();

		//�ͷ��ڴ棬���˵���ʼ����״̬
		short	ReleaseMem();

	private:
		//���ID����
		GINT m_nObjNum;
		//Buf�ܴ�ŵ�ID����(��λ������)
		GINT m_nAllNum;
		//���ʵ��
		GLONG *m_pObject;

	};

	//Ҫ��ID����
	class	OG_GME_API gme_feature_id
	{
	public:
		GME_TYPE_OBJ_ID	ClsID;//Ҫ����ID��
		GME_TYPE_OBJ_ID		ObjID;//Ҫ�ػ򼸺ζ���ID
		short				nObjType;//��������

		gme_feature_id();
		//�жϵ�ǰʵ���Ƿ���Ч(true OR false)
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

		//��ֵ���������غ���
		gme_feature_id operator=(const gme_feature_id& r)
		{
			ClsID = r.ClsID; ObjID = r.ObjID; nObjType = r.nObjType;
			return *this;
		}
		//С�ڲ��������غ���
		bool operator<(const gme_feature_id& r)const
		{
			if (nObjType != r.nObjType)
				return nObjType < r.nObjType;
			else if (ClsID != r.ClsID)
				return ClsID < r.ClsID;
			else
				return ObjID < r.ObjID;
		}

		//���ڲ��������غ���
		bool operator>(const gme_feature_id& r)const
		{
			if (nObjType != r.nObjType)
				return nObjType > r.nObjType;
			
			else if (ClsID != r.ClsID)
				return ClsID > r.ClsID;
			else
				return ObjID > r.ObjID;
		}

		//���ڲ��������غ���
		bool operator==(const gme_feature_id &r)const
		{
			if (ClsID > -1 && r.ClsID > -1)
				return (ObjID == r.ObjID) && (ClsID == r.ClsID) && (nObjType == r.nObjType);
			else
				return (ObjID == r.ObjID) && (ClsID == r.ClsID) && (nObjType == r.nObjType);
		}
	};


	//Ҫ���б�
	class	OG_GME_API gme_feature_list
	{
	public:
		gme_feature_list();
		gme_feature_list(gme_feature_list& rhs);
		~gme_feature_list();
		gme_feature_list& operator [](long i);
		gme_feature_list&	operator=(gme_feature_list& rhs);

	public:
		//��ȡֵ (0<=i<m_nFeatureNum)
		gme_feature_id  GetAt(long i);

		//��Ӷ���ID(����Ԫ��ʹ��)
		long		AddObject(gme_feature_id &FeatureID);

		//���һ��
		long		AddObjectListData(gme_feature_id *pFeatureList, long nFeatureNum);

		//�趨���б�
		long		SetFeaIDList(gme_feature_id *idList, long nNum);


		//ɾ������ID
		long		DeleteObject(gme_feature_id FeatureID);

		//ɾ������ID (0<=i<m_nFeatureNum)
		long		DeleteObject(long nPos);

		//���� (0<=i<m_nFeatureNum)
		long		UpdateObject(long nPos, gme_feature_id FeatureID);
		//���ô�С
		short		SetSize(long nFeatureNum);
		//��ȡ�������(=1)�����ж�����ֽ���(=0)
		long		GetCount(char IsObjorByteNum = 1);

		//��λ�������ڴ�
		short		Reset();

		//�ͷ��ڴ棬���˵���ʼ����״̬
		short		ReleaseMem();
		//		(0<=i<m_nFeatureNum)
		long		GetAt(long i, gme_feature_id &FID);

		//�õ����б�
		gme_feature_id* GetFeaIDList();

	public:
		gme_feature_id		*m_pFeatureID;

		//���ʵ���������λ��1��gme_feature_id
		long			m_nFeatureNum;

		//�ڴ�ռ���������λ��1��gme_feature_id
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
	
	

	typedef struct gme_grid_lin	//����������
	{
		long		lNum;
		gme_color4	fColor;//��ɫ
		long		lStyle;//���� (1---ʵ�� / 2---����)
		GREAL		fWidth;//�߿�
	}gme_grid_lin;

	typedef struct gme_font_info //��ע���塢��С����ɫ�����
	{
		GString		strFontName;
		long		lFontType;
		GREAL		fFontSize;
		GREAL		fFontWid, fFontLen;
	}gme_font_info;

	//���̶���
	typedef struct  gme_controls
	{
		WORD keyLeft;
		WORD keyRight; //���ơ�����
		WORD keyForward;
		WORD keyBackward;//ǰ��������
		WORD keyUp;
		WORD keyDown;//�������½�
		WORD keyLeftTurn;
		WORD keyRightTurn;//��ת����ת
		WORD keyHeadUp;
		WORD keyHeadDown;//����������
		//gme_controls()
		//{
		//	memset(this, 0, sizeof(gme_controls));
		//}
	}gme_controls;

	//�й����β����Ľṹ����
	typedef struct  gme_walk_params
	{
		GREAL		r;//�ӵ���ο���֮��ľ���
		GREAL		angz;//��Z����ת�ĽǶ�(���߷���������XOY���ϵ�ͶӰ֮��ļн�)
		GREAL   	angz_inc;//��Z����ת�ĽǶȵ�����
		GREAL		shift_inc;//����ƽ�ƵĲ���
		GREAL		speed;//ǰ�������˵Ĳ���
		GREAL		UpDown_inc;//���ϡ�����ʱ�ӵ�������ֵ
		GREAL   	look_up_ang;//���ӻ��ӵĽǶ�
		GREAL   	look_up_ang_inc;//���ӻ���ʱ�ĽǶ�����

		//gme_walk_params()
		//{
		//	memset(this, 0, sizeof(gme_walk_params));
		//}
	}gme_walk_params;


	//��Դ��Ϣ�ṹ
	struct	gme_light_info
	{
		BYTE 			cType;//��Դ����

		GString			LightName; //��Դ����
		GREAL			Light_Diffuse[4];	//���������ɫ(�ڵƹ���ɫ����Ҫalphaͨ��)
		GREAL			Light_Specular[4];	//���淴����ɫ	
		GREAL 			Light_Ambient[4];	//��������ɫ

		gme_vector3f			vLight;//��Դλ��
		gme_vector3f			vDir;//��Դ�����䷽��
		GREAL			Range; //�����õķ�Χ
		GREAL           Falloff;
		GREAL           Attenuation0;
		GREAL           Attenuation1;
		GREAL           Attenuation2;
		GREAL           Theta;
		GREAL           Phi;
	};


	//����ͶӰ����ת��ƽ�ƾ���
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

	//������Ϣ����
	struct  gme_material
	{
		GREAL			fAmbient[4];   //������
		GREAL			fDiffuse[4];   //�������
		GREAL			fSpecular[4];  //���淴����ɫ
		GREAL			fEmission[4];  //�����
		GREAL			fShininess;    //���ϵ����Ȼ��淴��ļ���̶�
	};

	//����������Ϣ����
	struct gme_texture_info
	{
	public:
		//�������ݴ�С
		DWORD	nDataLen;
		//����ĳ���
		WORD	nx;
		//����Ŀ��
		WORD	ny;
		//�����ʽ
		GME_TEXTURE_FORMAT format;
	};

	union gme_tex_info_union
	{
	public:
		gme_material		Material;
		gme_texture_info	Texture;
	};

	//����������Ϣ
	struct gme_tex_info //����/������Ϣ
	{
		char					cflag;//1:����2:����
		GME_SCENE_TEXIDXNO		nTexNo;	//����ı��
		char					cModified;//1���޸Ĺ�,0δ���޸�
		gme_tex_info_union		info;
		gme_tex_info()
		{
			memset(this, 0, sizeof(gme_tex_info));
		}
	};

	//����Ϣ
	struct gme_fgme_info
	{
		GME_FOG_TYPE		fogType;	//������(��ֵ1��ʾ������,��ֵ2��ʾ������)
		GREAL			fStart; //��Χ����ʼֵ
		GREAL			fEnd;	//��Χ�Ľ���ֵ
		GREAL			pfColor[4];//����ɫ
		GREAL			fDensity;//���ܶ�
		BOOL			useRange;
		GME_FOG_MODE       fogMode;
		//range

		gme_fgme_info()
		{
			memset(this, 0, sizeof(gme_fgme_info));
		}
	};


	struct gme_tex_param		//�����������
	{
		GME_TEXTURE_FILTER		cMagFilter;		//������˷Ŵ���
		GME_TEXTURE_FILTER		cMinFilter;		//���������С����
		GME_TEXTURE_FILTER		cMipmapFilter;	//������ӳ����˺���
		//(��cMipmapFilterΪ0������Ⱦ����disabled mipmap filter)
		GME_TEXTURE_WRAPMODE	cWrapS;			//��������S�Ĳ��Ʋ���
		GME_TEXTURE_WRAPMODE	cWrapT;			//��������T�Ĳ��Ʋ���
		GME_TEXTUREENVMODE	cEnvMode;		//������ģʽ

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

	//�ںϲ���
	struct gme_blend_param
	{
		unsigned char   cSrcFactor;	//Դ�ں�����
		unsigned char   cDestFactor;//Ŀ���ں�����
		gme_blend_param()
		{
			memset(this, 0, sizeof(gme_blend_param));
		}
	};
	
	//
	struct gme_video_info	//¼����Ƶ��Ϣ
	{
		long		lWid;	//֡���
		long		lLen;	//֡����
		GREAL		fFps;	//��������
		long		lFrames;//֡��
		long		lBisCount;//��Ԫλ��
	};

	struct gme_img_info	//���泡��λͼ��Ϣ
	{
		long		lWid;	//֡���
		long		lLen;	//֡����
		long		lBisCount;//��Ԫλ��
		long		lCompressCoef; //ѹ��ϵ��
	};

	//����ϵͳ���������ṹ
	struct gme_particle_data_info
	{
	public:
		BYTE				type;				//����������(0����Ȫ, 1-����)
		BYTE				status;				//0���ر�����Ч����1����������Ч����2�����Ӿ�ֹ
		gme_vector3f			initPostion;		//��ʼλ��(����������Ƕ�ÿ�����͵������嶼����)
		GREAL				initVel;			//��ʼ�ٶ�
		GREAL				fAzimuth, fObliquity;//��ʼ�ٶȼ��䷽λ�Ǻ����
		GREAL				particleSize;		//���Ӵ�С
		GREAL				killHeight;			//�����߶�
		WORD				emitParticlesToNum;	//һ�η�������Ӹ���
		WORD				existTime;			//����ʱ��(��)
		WORD				curParticlNum;		//��ǰ���ڵ����Ӹ���
		WORD				particleMaxNum;		//����������
		GME_SCENE_TEXIDXNO	nTexNo;				//ʹ�õ������
		GREAL   			clrDiffuse[4];		//��ʼ��ɫ
		GREAL   			clrFade[4];			//��ʧ��ɫ
		DWORD				nParticleDataSize;	//���ݻ��峤��
		gme_particle_data_info()
		{
			memset(this, 0, sizeof(gme_particle_data_info));
		}
	};

	struct 	gme_particle
	{
	public:
		BYTE      	bDied;	//�Ƿ�������
		BYTE      	bSpark;	//�Ƿ���˸			
		gme_vector3f		vPos0;	//��ʼλ��
		gme_vector3f		vVel0;	//��ʼ�ٶ�
		GREAL		fTime0;	//����ʱ��
		GREAL		fFade;	//��ʧ

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
	
	// --------------------- �µ��ֶ������� ---------------------------- //
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
		static gmeType GemTypeOfName(const GString& name);	// name���ַ�Ӧ��ȫ�Ǵ�д�ġ�

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
		bool operator=(const GString &str);//�ַ���
		bool operator=(const char* str);//�ַ���
		bool operator=(const gmeByteArray* pBinary);//������
		bool operator=(const std::vector<char>* pBinary);//������
		bool setBlobValue(const void *pBinary, int len);//������

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
		//���¶������͵��ֶ�ֵֻ��ѡ��һ.
		bool	   bVal;
		char	   cVal;
		short	   sVal;
		int32	   iVal;
		int64	   llVal;
		float	   fVal;
		double	   dVal;
		GString	   mstrVal;//�ַ����͵��ֶ�ֵ
		gmeByteArray mBlobVal;//blob���ֶ�ֵ
	};
	typedef std::vector<gmeFieldValue>		gmeFieldValues;


	class OG_GME_API gmeField //�����ֶ�
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
		int mLength;//��������λ��
		int mPrecision;//С������λ��
		GString mComment;
		GString mMinValue;
		GString	mMaxValue;
		GString mInvalidValue;
		int mBytes;//�ֽڳ���
	};



		
	class OG_GME_API gmeFields //�ֶμ�
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


	//��¼
	class OG_GME_API gmeRecord //���Լ�¼
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
		//���
		bool Clear();
		//���ýṹ
		bool SetStru(const gmeFields &fields);
		bool SetStru(gmeFields * pfields);
		//��ȡ�ṹ
		bool GetStru(gmeFields &stru);
		gmeFields*	GetStruPtr() ;

		//�����ֶ�ֵ(�����ֶ����)
		bool SetValue(short fldi, const gmeFieldValue& val);
		//�����ֶ�ֵ(�����ֶ�����)
		bool SetValue(const char *fldName, const gmeFieldValue& val);
		bool SetValue(const GString& fldName, const gmeFieldValue& val);
		//�����ֶ�ֵ(ȫ��) 20200111 zc
		bool SetValues(gmeFieldValues& val);
		//ȡ�ֶ�ֵ(ȫ��)
		bool GetValues(gmeFieldValues& val);
		//ȡ�ֶ�ֵ(�����ֶ����)
		bool GetValue(short fldi, gmeFieldValue& val);	
		bool GetValue(const char *fldName, gmeFieldValue& val);
		bool GetValue(const GString& fldName, gmeFieldValue& val);

		// ���һ���ֶκ�ֵ
		void append(const gmeField& gme_field, const gmeFieldValue value);

		//���������ֶ�ֵΪNULL
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





	//������Ĳ����ඨ��
	class OG_GME_API C3DBaseShapeStyle
	{
	public:
		long		m_lShpType;
	};
	class OG_GME_API CPointStyleParam : public C3DBaseShapeStyle
	{
	protected:
		//�ı����ݱ�־1--������  0--������(�Ѵ������ݿ�),2--�������޸�,
		char	m_NewData;
		//������--��ͼ(0)��ע��(1)
		int		m_nType;
		//����ɫ
		long	m_lPntColor; // ����RGBA�أ�����ARGB�أ�����ABGR�أ���Ҳ��Ҳ��(�ο���gme_color4)
		//��ͼ��
		long	m_lSubGraph;
		//��ߴ�-��
		float	m_fPntHeight;
		//��ߴ�-��
		float	m_fPntWidth;
		//ע��-�ַ���
		char    m_strNoteName[128];
		//ע��-�����ͺ�
		long    m_lNoteFont;
		//ע��-��ɫ��
		long    m_lNoteClr;
		//ע��-�ߴ�-��
		float   m_fNoteHeight;
		//ע��-�ߴ�-��
		float   m_fNoteWidth;
		//ע��-�Ƕ�
		float   m_fNoteAngle;
		//͸����
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
		//�ж϶����Ƿ�Ϊ��
		long	IsValid(void);
	};
	class OG_GME_API CLineStyleParam : public C3DBaseShapeStyle
	{
	protected:
		//�ı����ݱ�־1--������  0--������(�Ѵ������ݿ�),2--�������޸�,
		char	m_NewData;
		//����ɫ
		long	m_lColor;
		//���� (��·�ߡ���·�ߵ�)
		long	m_lStyle;
		//������
		long    m_lSubSty;
		//�߿�
		float	m_fWidth;
		//͸����
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
		//�ж϶����Ƿ�Ϊ��
		long	IsValid(void);
	};
	class OG_GME_API CSurfaceStyleParam : public C3DBaseShapeStyle
	{
	protected:
		//��ʾ��Ϣ��Ӧ����ID
		GME_TYPE_OBJ_ID	m_nSurfaceID;
		//�ı����ݱ�־1--������  0--������(�Ѵ������ݿ�),2--�������޸�,
		char			m_NewData;
		//ͼ����
		std::string 	m_lPatternNum;
		//ͼ����ɫ
		long	m_lPatternClr;
		//���
		float	m_fWidth;
		//���
		float   m_fHeight;
		//����ɫ
		long    m_lAreaClr;
		//͸����
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
		//�ж϶����Ƿ�Ϊ��
		long	IsValid(void);
	};


	typedef		std::vector<gmeRecord>	gmeRecordSet;//���Լ�¼����
	int getattname(long in, std::string &out);
	bool  boxinsphere(gme_rect_3d & box, const gme_vector3d * dot, double r);
	bool insphere(const gme_vector3d & p1, const gme_vector3d * p2, double r);
	typedef struct gme_mdl_db_info
	{
		GString		dbUrl;//���ݿ����ӵ�ַ
		GString		dbUser;//�û���
		GString		dbPsw; //����
		GME_LinkType	mLinkType;//���ݿ�����
		GME_TYPE_OBJ_ID dbID; //���ݿ�ID
	}gme_mdl_db_info;

	typedef struct OG_GME_API gme_mdl_featID  //Ҫ�����Ҫ��ID
	{
		GME_TYPE_OBJ_ID			fClsID;
		std::vector<GME_TYPE_OBJ_ID>	featID;

		gme_mdl_featID& operator = (const gme_mdl_featID& gme);
		bool operator == (const gme_mdl_featID& gme) const;
	}gme_mdl_fcls_ID;
	//=======================Ҫ�ص�ʵ���б�
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
	typedef struct gme_feature_relation //Ҫ�ع�ϵ
	{
		GME_TYPE_OBJ_ID				featID1;
		GME_TYPE_OBJ_ID				featID2;
		GME_FEATURE_RELATION_TYPE	relationType;
		GME_FEATURE_RELATION_VALUE	relationVal;
	}gme_feature_relation;

	typedef struct gme_legend_cell //ͼ����
	{
		gme_vector3i leftUpPos;
		GString		strCellName;
		GString		strNote;
		gme_color4	bkCell;
		long		subNo; //ͼ�����еķ���
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


	//DEM��Ϣ��
	typedef struct gme_dem_info //dem������Ϣ
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


	typedef struct OG_GME_API gme_dem_level //dem����
	{
		GME_TYPE_OBJ_ID		lDemID;
		long				lLevelNo;
		long				lRowPntNum;
		long				lColPntNum;
		long				RowBlockNum;
		long				ColBlockNum;
		gme_dem_level& operator = (const gme_dem_level& gme);
	}gme_dem_level;

	typedef struct gme_dem_re_tile //dem������
	{
		GME_TYPE_OBJ_ID	 lDemID;
		long			 lLevelNo;
		long			 lRowNo;
		long			 lColNo;
		std::vector<double>	 demReTileData; //�ǹ�������

	}gme_dem_re_tile;


	typedef struct gme_IrreTileData //dem����������
	{
		std::vector<gme_vector3d> irPoint; //��ɢ������
		std::vector<long> tirNo;    //�����ζ����
		std::vector<long> nextNo;   //�ڽ������κ�
	} gme_IrreTileData;

	typedef struct gme_dem_irre_tile //dem������
	{
		GME_TYPE_OBJ_ID	 lDemID;
		long			 lLevelNo;
		long			 lRowNo;
		long			 lColNo;
		gme_IrreTileData	 demIrreTileData; //����������

	}gme_dem_irre_tile;

	//���Գ���Ϣ
	typedef struct gme_field_info //���Գ�������Ϣ
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
	
	typedef struct gme_field_level //���Գ�������Ϣ
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

	typedef struct gme_field_tile_reg //�����ʷֵ����Գ�������
	{
		GME_TYPE_OBJ_ID	lFieldID;
		long			lLevelNo;
		long			lRowNo;
		long			lColNo;
		long			lDepNo;
		//
		std::string          lStratNo;//�ز����
		bool            lVisible = true;//��Ԫ����ʾ��,trueΪ����ʾ
		//
		std::vector<double>  regTileData;
	}gme_field_tile_reg;

	typedef struct irreField_data          //��������Ԫ
	{
		long levelNo;
		long lTileRowNo;
		long lTileColNo;
		long lTileDepNo;
		std::vector<double> zTile;
		std::vector<gme_vector3d> verPoint;
	}irreField_data;

	typedef struct gme_field_cell_data_irreg //�������ʷֵ����Գ�������
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

	//vector<double> reFiele_data;    //������Ԫ

	
	
	

	typedef struct Gme_holeSampData //��Ʒ����blob
	{
		gme_vector3d holeSampPoint;
		std::string soilcode;
		std::vector<double> v;
	}Gme_holeSampData;


	//�߱��й���blob�ֶεĽṹ�嶨��
	typedef struct Gme_Line_LinBound //�߱�-�߽߱�
	{
		GME_TYPE_OBJ_ID	lFromPointID;
		GME_TYPE_OBJ_ID	lToPointID;
	
	}Gme_Line_LinBound;

	typedef struct Gme_Line_vertData //�߱�-�������� and ���-��������
	{
		long iPntNum;
		long iClrNum;
		long NormalNum;
		std::vector<gme_color4> vPntColor;
		//����8*������1ͨ�����е�...
		std::vector<gme_vector3d> vPntNormal;
		std::vector<gme_tex_coord> vTexcoordMap;
		std::vector<gme_vector3d> vPntData;

	}Gme_Line_vertData;

	typedef struct Gme_Line_LinEdgeData //�߱�-������
	{
		int iEdgNum;
		std::vector<long> vLinEdge;   //���ϵ��id 2*iEdgNum

	}Gme_Line_LinEdgeData;

	//����й���blob�ֶεĽṹ�嶨��
	typedef struct Gme_Surface_SurfBound //���-��߽�
	{
		long lLineNum;
		std::vector<GME_TYPE_OBJ_ID>  vSurfLins;   //��id

	}Gme_Surface_SurfBound;

	typedef struct Gme_Surface_Facetvertices //���-��Ƭ�������� and ���-�ڽ���Ƭ
	{
		long lFacetNum;
		std::vector<GME_TYPE_OBJ_ID> vCellPntNos;//����id��3*lFacetNum

	}Gme_Surface_Facetvertices;

	//����й���blob�ֶεĽṹ�嶨��
	typedef struct Gme_Region_CellVertData //���-��Ԫ������������
	{
		long lCellNum;//��Ԫ����
		long lFacetNumPerCell;//1����Ԫ����������
		std::vector<long>  vCellData;   //��Ԫ������������Ԫ����*1����Ԫ�Ķ�����
	}Gme_Region_CellVertData;

	typedef struct Gme_Region_AdjCellVertData //���-�ڽ���Ԫ����
	{
		long lAdjNum;//�ڽ���Ԫ�ĸ���
		std::vector<long>  vAdjCellIDs;   //�ڽ���Ԫ���
	}Gme_Region_AdjCellVertData;




	//typedef struct Gme_Contact_linData//��ID�б�
	//{
	//	long linesNum;//��ID����
	//	vector<GME_TYPE_OBJ_ID> linesID;//��ID�б�
	//}Gme_Contact_linData;


	///////////////////////////////////////��άģ�͵�blob�洢
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



	//��׷ֲ�����...
	typedef struct gme_holelayer
	{
		gme_holelayer()
		{
			stratCode = "";//�ز����
			topDepth = 0;	//�ز㶥������
			bottomDepth = 0;//�ز�ײ�����

			dip = 90;
			azimuth = 0; //��б���ݣ�ֱ�ײ���Ҫ��
			clr = 0; //��ɫ
		}
		std::string	stratCode;//�ز����
		double	topDepth;	//�ز㶥������
		double	bottomDepth;//�ز�ײ�����

		double  dip, azimuth; //��б���ݣ�ֱ�ײ���Ҫ��
		int		clr; //�ز���ɫ
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
		gme_vector3d	holePos;//���λ��
		std::string	holeCode;	//�ز����
		double	holeDepth;	//������

		int		holeType;	//������ͣ�0-ֱ�ף�1-б�ף�
		int		dispType;	//��ʾ����(0-��״ 1-��״)
		int		segNum;		//��׺�����������ģ�ã�
		double	radius;		//��׿׾�
		std::vector<gme_holelayer>	holeLayer;//�ֲ�����
		std::vector<Gme_holeSampData> mHoleSampData;// ��Ʒ����
	}gme_hole;

	typedef struct gme_fault
	{
		gme_fault()
		{
			mFaultType = GME_FT_NORMAL_FAULT;	//�ϲ�����
			mFaultName = ""; //�ϲ�����
			mFaultCode = ""; //�ϲ����
			mDipType = GME_GDT_REAL_DIP;	//�ϲ�������ͣ������ / ����ǣ�
			mDipDir = 0;	//�ϲ������
			mDip = 0;			//�ϲ�����
			mExtendDepth = 2000;//�ϲ����չ���
			mBlockBufferDist = 50;//��״ģ�ͺ��
			clr = 0;
			mDispType = 1; //�ϲ���ʾ���ͣ�0-��״ 1-��״
			mScale = 1;
		}
		GME_FAULT_TYPE	mFaultType;	//�ϲ�����
		GString			mFaultName; //�ϲ�����
		GString			mFaultCode;	//�ϲ����
		GME_GEO_DIP_TYPE mDipType;	//�ϲ�������ͣ�����ǡ�����ǣ�
		double			mDipDir;	//�ϲ������
		double			mDip;		//�ϲ�����
		std::vector<std::vector<gme_vector3d>> mFaultGeoData; //�ϲ㼸������
		double			mExtendDepth;//�ϲ����չ���
		double          mBlockBufferDist;//��״ģ�͵ĺ��
		int				clr; //�ϲ���ɫ
		int				mDispType; //�ϲ���ʾ���ͣ�0-��״ 1-��״
		double          mScale; //�ϲ���ݳ������õ����ű���ϵ��
	}gme_fault;
}

