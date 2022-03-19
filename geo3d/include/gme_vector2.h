#pragma once

#include <vector>

	template<class real>
	class  vector2
	{
	public:
		union {
			struct {
				real x, y;//三角形的三个顶点号
			};
			real _v[2];
		};
		

		// special vectors
		static const vector2 s_zero;
		static const vector2 s_unit_x;
		static const vector2 s_unit_y;

	public:
		vector2(void);

		~vector2(void);

	public:
		vector2( real v_x, real v_y );

		vector2( const vector2& t );

	public:
		void set(real xx, real yy)
		{
			x = xx;
			y = yy;
		}
		const real operator[](int index)
		{
			if (index == 0)
				return x;
			else
				return y;
		}

		bool operator<(const vector2& dotB) const
		{
			if (fabs(this->x - dotB.x) >= 1E-9)
			{
				return (this->x < dotB.x);
			}
			if (fabs(this->y - dotB.y) >= 1E-9)
			{
				return (this->y < dotB.y);
			}
			return false;
		}

		// Assigns the value of the other vector.or param
		vector2& operator = ( const vector2& vec );

		bool operator == ( const vector2& vec ) const;

		bool operator != ( const vector2& vec ) const;

		vector2 operator + ( const vector2& vec ) const;

		vector2 operator - ( const vector2& vec ) const;

		vector2 operator - () const;

		vector2 operator * ( const real scale_value ) const;

		vector2 operator * ( const vector2& vec ) const;

		vector2 operator / ( const real scale_value ) const;

		// overloaded operators to help vector2
		friend vector2 operator * ( real scale_value, const vector2& vec )
		{
			vector2 v_ret_vec;

			v_ret_vec.x = scale_value * vec.x;
			v_ret_vec.y = scale_value * vec.y;

			return v_ret_vec;
		}

		vector2& operator += ( const vector2& vec );

		vector2& operator -= ( const vector2& vec );

		vector2& operator *= ( const real scale_value );

		vector2& operator *= ( const vector2& vec );

		vector2& operator /= ( const real scale_value );

		void scale( const real scale_value );

		double length(void);

		double squared_length(void);

		void normalize(void);

		static double dot( const vector2& vec1, const vector2& vec2 );

		static double cross( const vector2& vec1, const vector2& vec2 );


		static vector2 normalize( const vector2& vec );

		// Calculates a reflection vector to the plane with the given normal .
		// and remarks NB assumes 'this' is pointing AWAY FROM the plane, invert if it is not
		static vector2 reflect( const vector2& src, const vector2& normal );

	}; // class vector2


	#include "gme_vector2.inl"

	typedef vector2<int>	gme_vector2i;
	typedef vector2<float>	gme_vector2f;
	typedef vector2<double>	gme_vector2d;
	typedef gme_vector2d	gme_tex_coord; //纹理坐标

	typedef gme_vector2d	gme_D_DOT;



#ifdef WIN32
	template<> const vector2<int> vector2<int>::s_zero(0, 0);
	template<> const vector2<int> vector2<int>::s_unit_x(1, 0);
	template<> const vector2<int> vector2<int>::s_unit_y(0, 1);

	template<> const vector2<float> vector2<float>::s_zero(0.0f, 0.0f);
	template<> const vector2<float> vector2<float>::s_unit_x(1.0f, 0.0f);
	template<> const vector2<float> vector2<float>::s_unit_y(0.0f, 1.0f);

	template<> const vector2<double> vector2<double>::s_zero(0.0, 0.0);
	template<> const vector2<double> vector2<double>::s_unit_x(1.0, 0.0);
	template<> const vector2<double> vector2<double>::s_unit_y(0.0, 1.0);
#endif //WIN32

