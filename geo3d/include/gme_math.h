#pragma once


	template <class real>
	class  gmMath
	{
	public:
		gmMath(void){}
		virtual ~gmMath(){}

	public:
		static real acos_ (real value);
		static real asin_ (real value);
		static real atan_ (real value);
		static real atan2_ (real fY, real fX);
		static real ceil_ (real value);
		static real cos_ (real value);
		static real exp_ (real value);
		static real fabs_ (real value);
		static real floor_ (real value);
		static real fmod_ (real fX, real fY);
		static real inv_sqrt_ (real value);
		static real log_ (real value);
		static real pow_ (real fBase, real fExponent);
		static real sin_ (real value);
		static real sqr_ (real value);
		static real sqrt_ (real value);
		static real tan_ (real value);
		static real cot_ (real value);
			
	public:
		static const real s_epsilon;
		static const real s_zero_tolerance;
		static const real s_max_real;
		static const real s_min_real;
		static const real s_pi;
		static const real s_two_pi;
		static const real s_half_pi;
		static const real s_deg_to_rad;
		static const real s_rad_to_deg;
	};
#include "gme_math.inl"