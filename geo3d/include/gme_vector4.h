#pragma once

#include <vector>


	template <class real>
	class  vector4
	{
	public:
		union 
		{
			struct
			{
				real        x,y,z,w;
			};
			real _v[4];
		};

	public:
		// construction
		vector4 ();  // uninitialized

		vector4 (real x, real y, real z, real w);

		vector4 (const vector4& v);

		void set(real xx, real yy, real zz, real ww)
		{
			x = xx;
			y = yy;
			z = zz;
			w = ww;
		}

		const real operator[](int index)
		{
			if (index == 0)
				return x;
			else if (index == 1)
				return y;
			else if (index == 2)
				return z;
			else if (index == 3)
				return w;
		}


		bool operator<(const vector4& dotB) const
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
			if (fabs(this->w - dotB.w) >= 1E-9)
			{
				return (this->w < dotB.w);
			}
			return false;
		}

		//
		// assignment
		//
		vector4& operator= (const vector4& v);

		//
		// comparison
		//
		bool operator== (const vector4& v) const;

		bool operator!= (const vector4& v) const;


		//
		// arithmetic operations
		//
		vector4 operator+ (const vector4& v) const;

		vector4 operator- (const vector4& v) const;

		vector4 operator* (real scalar) const;

		friend vector4 operator* (real scalar, const vector4& v);

		vector4 operator/ (real scalar) const;

		vector4 operator- () const;


		//
		// arithmetic updates
		//
		vector4& operator+= (const vector4& v);

		vector4& operator-= (const vector4& v);

		vector4& operator*= (real scalar);

		vector4& operator/= (real scalar);

		//
		// vector operations
		//
		real length () const;

		real squared_length () const;

		real dot (const vector4& v) const;

		real normalize ();

		// special vectors
		static const vector4 s_zero;

		static const vector4 s_unit_x;

		static const vector4 s_unit_y;

		static const vector4 s_unit_z;

		static const vector4 s_unit_w;
	};

#include "gme_vector4.inl"

	typedef vector4<float> gme_vector4f;
	typedef vector4<double> gme_vector4d;

#ifdef WIN32
	template<> const vector4<float> vector4<float>::s_zero(0.0f,0.0f,0.0f,0.0f);
	template<> const vector4<float> vector4<float>::s_unit_x(1.0f,0.0f,0.0f,0.0f);
	template<> const vector4<float> vector4<float>::s_unit_y(0.0f,1.0f,0.0f,0.0f);
	template<> const vector4<float> vector4<float>::s_unit_z(0.0f,0.0f,1.0f,0.0f);
	template<> const vector4<float> vector4<float>::s_unit_w(0.0f,0.0f,0.0f,1.0f);

	template<> const vector4<double> vector4<double>::s_zero(0.0,0.0,0.0,0.0);
	template<> const vector4<double> vector4<double>::s_unit_x(1.0,0.0,0.0,0.0);
	template<> const vector4<double> vector4<double>::s_unit_y(0.0,1.0,0.0,0.0);
	template<> const vector4<double> vector4<double>::s_unit_z(0.0,0.0,1.0,0.0);
	template<> const vector4<double> vector4<double>::s_unit_w(0.0,0.0,0.0,1.0);
#endif //WIN32

