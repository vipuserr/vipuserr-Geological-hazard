#pragma once

#include <vector>

	template<class real>
	class  vector3
	{
	public:
		union {
			struct  {
				real x, y, z;//三角形的三个顶点号
			};
			real _v[3];
		};

		// special vectors
		static const vector3 s_zero;
		static const vector3 s_unit_x;
		static const vector3 s_unit_y;
		static const vector3 s_unit_z;

	public:
		vector3(void);

		~vector3(void);

	public:
		vector3( real v_x, real v_y, real v_z );

		vector3( float* p );

		vector3( double* p );

		vector3( const vector3& t );

	public:
		inline void set(real xx, real yy, real zz)
		{
			x = xx;
			y = yy;
			z = zz;
		}
		inline void set(const vector3& rhs)
		{
			x = rhs.x; y = rhs.y; z = rhs.z;
		}
		inline real& operator[] (int index)
		{
			if (index == 0)
				return x;
			else if (index == 1)
				return y;
			else // if (index == 2)
				return z;
		}
		inline real operator[] (int index) const 
		{
			if (index == 0)
				return x;
			else if (index == 1)
				return y;
			else // if (index == 2)
				return z;
		}

		bool operator<(const vector3& dotB) const
		{
			if (fabs(this->x - dotB.x) >= 1E-9)
			{
				return (this->x < dotB.x);
			}

			if (fabs(this->y - dotB.y) >= 1E-9)
			{
				return (this->y < dotB.y);
			}

			if (fabs(this->z - dotB.z) >= 1E-9)
			{
				return (this->z < dotB.z);
			}

			return false;
		}
		// Assigns the value of the other vector.or param
		vector3& operator = ( const vector3& vec );

		bool operator == ( const vector3& vec ) const;

		bool operator != ( const vector3& vec ) const;

		vector3 operator + ( const vector3& vec ) const;

		vector3 operator - ( const vector3& vec ) const;

		vector3 operator - () const;

		vector3 operator * ( real scale ) const;

		vector3 operator * ( vector3& vec ) const;

		vector3 operator / ( vector3& vec ) const;

		vector3 operator / ( real scale ) const;

		// overloaded operators to help vector2
		friend vector3 operator * ( real scalar, const vector3& vec )
		{
			vector3 v_ret_vec;

			v_ret_vec.x = scalar * vec.x;
			v_ret_vec.y = scalar * vec.y;
			v_ret_vec.z = scalar * vec.z;

			return v_ret_vec;
		}

		vector3& operator += ( const vector3& vec );

		vector3& operator -= ( const vector3& vec );

		vector3& operator *= ( const real scale_value );

		vector3& operator *= ( const vector3& vec );

		vector3& operator /= ( const real scale_value );

		void scale( const real scale_value );

		double length(void) const;

		double squared_length(void);

		void normalize(void);
		vector3 normalisedCopy(void);

		real dot( const vector3& vec ) const;

		vector3 cross( const vector3& vec ) const;
		vector3 operator^(vector3& v)
		{
			return this->cross(v);
		}
		friend vector3 operator^(const vector3& v1, const vector3& v2)
		{
			return v1.cross(v2);
		}

		static real dot( const vector3& vec1, const vector3& vec2 );

		static vector3 cross( const vector3& vec1, const vector3& vec2 );

		static vector3 normalize( const vector3& vec );

		static real length( const vector3& vec );

		// Calculates a reflection vector to the plane with the given normal .
		// and remarks NB assumes 'this' is pointing AWAY FROM the plane, invert if it is not
		static vector3 reflect( const vector3& src, const vector3& normal );


	}; // class vector3

	#include "gme_vector3.inl"

	typedef vector3<int>	gme_vector3i;
	typedef vector3<float>	gme_vector3f;
	typedef vector3<double>	gme_vector3d;
	typedef gme_vector3d	gme_D_3DOT;
	

	typedef std::vector<gme_vector3d> coordinates_array;
	typedef std::vector<coordinates_array> coordinates_part_array;

	typedef std::vector<double> double_value_array;

	typedef std::vector<gme_vector3f> coordinates_array_f;
	typedef std::vector<gme_vector3d> coordinates_array_d;

#ifdef WIN32
	template<> const vector3<float> vector3<float>::s_zero(0.0f, 0.0f, 0.0f);
	template<> const vector3<float> vector3<float>::s_unit_x(1.0f, 0.0f, 0.0f);
	template<> const vector3<float> vector3<float>::s_unit_y(0.0f, 1.0f, 0.0f);
	template<> const vector3<float> vector3<float>::s_unit_z(0.0f, 0.0f, 1.0f);

	template<> const vector3<double> vector3<double>::s_zero(0.0, 0.0, 0.0);
	template<> const vector3<double> vector3<double>::s_unit_x(1.0, 0.0, 0.0);
	template<> const vector3<double> vector3<double>::s_unit_y(0.0, 1.0, 0.0);
	template<> const vector3<double> vector3<double>::s_unit_z(0.0, 0.0, 1.0);
#endif //WIN32

