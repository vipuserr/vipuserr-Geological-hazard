


template<> const float gmMath<float>::s_epsilon = (1.192092896e-07F);
template<> const float gmMath<float>::s_zero_tolerance = 1e-06f;
template<> const float gmMath<float>::s_min_real = (1.175494351e-38F);
template<> const float gmMath<float>::s_max_real = (3.402823466e+38F);
template<> const float gmMath<float>::s_pi = (float)(3.14159265358979323846);
template<> const float gmMath<float>::s_two_pi = (float)((3.14159265358979323846) * 2.0);
template<> const float gmMath<float>::s_half_pi = (float)(3.14159265358979323846 * 0.5);
template<> const float gmMath<float>::s_deg_to_rad = (float)(3.14159265358979323846 / 180.0);
template<> const float gmMath<float>::s_rad_to_deg = (float)(180.0 / 3.14159265358979323846);


template<> const double gmMath<double>::s_epsilon = (2.2204460492503131e-016);
template<> const double gmMath<double>::s_zero_tolerance = 1e-06;
template<> const double gmMath<double>::s_min_real = (2.2250738585072014e-308);
template<> const double gmMath<double>::s_max_real = (1.7976931348623158e+308);
template<> const double gmMath<double>::s_pi = 3.14159265358979323846;
template<> const double gmMath<double>::s_two_pi = 3.14159265358979323846 * 2.0;
template<> const double gmMath<double>::s_half_pi = 3.14159265358979323846 * 0.5;
template<> const double gmMath<double>::s_deg_to_rad = 3.14159265358979323846 / 180.0;
template<> const double gmMath<double>::s_rad_to_deg = 180.0 / 3.14159265358979323846;



template <class real>
real gmMath<real>::acos_ (real value)
{
	if ( -(real)1.0 < value )
	{
		if ( value < (real)1.0 )
			return (real)acos((double)value);
		else
			return (real)0.0;
	}
	else
	{
		return s_pi;
	}
}

template <class real>
real gmMath<real>::asin_ (real value)
{
	if ( -(real)1.0 < value )
	{
		if ( value < (real)1.0 )
			return (real)asin((double)value);
		else
			return s_half_pi;
	}
	else
	{
		return -s_half_pi;
	}
}

template <class real>
real gmMath<real>::atan_ (real value)
{
	return (real)atan((double)value);
}

template <class real>
real gmMath<real>::atan2_ (real fY, real fX)
{
	return (real)atan2((double)fY,(double)fX);
}

template <class real>
real gmMath<real>::ceil_ (real value)
{
	return (real)ceil((double)value);
}

template <class real>
real gmMath<real>::cos_ (real value)
{
	return (real)cos((double)value);
}

template <class real>
real gmMath<real>::exp_ (real value)
{
	return (real)exp((double)value);
}

template <class real>
real gmMath<real>::fabs_ (real value)
{
	return (real)fabs((double)value);
}

template <class real>
real gmMath<real>::floor_ (real value)
{
	return (real)floor((double)value);
}

template <class real>
real gmMath<real>::fmod_ (real fX, real fY)
{
	return (real)fmod((double)fX,(double)fY);
}

template <class real>
real gmMath<real>::inv_sqrt_ (real value)
{
	return (real)(1.0/sqrt((double)value));
}

template <class real>
real gmMath<real>::log_ (real value)
{
	return (real)log((double)value);
}

template <class real>
real gmMath<real>::pow_ (real fBase, real fExponent)
{
	return (real)pow((double)fBase,(double)fExponent);
}

template <class real>
real gmMath<real>::sin_ (real value)
{
	return (real)sin((double)value);
}

template <class real>
real gmMath<real>::sqr_ (real value)
{
	return value*value;
}

template <class real>
real gmMath<real>::sqrt_ (real value)
{
	return (real)sqrt((double)value);
}

template <class real>
real gmMath<real>::tan_ (real value)
{
	return (real)tan((double)value);
}


template <class real>
real gmMath<real>::cot_ (real value)
{
	return (real)1.0/(real)tan((double)value);
}