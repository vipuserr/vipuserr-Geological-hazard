
#include "gme_math.h"


template <class real>
vector4<real>::vector4 ()
{

}

template <class real>
vector4<real>::vector4 (real fx, real fy, real fz, real fw)
{
	x = fx;
	y = fy;
	z = fz;
	w = fw;
}


template <class real>
vector4<real>::vector4 (const vector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
}


template <class real>
vector4<real>& vector4<real>::operator= (const vector4& v)
{
	x = v.x;
	y = v.y;
	z = v.z;
	w = v.w;
	return *this;
}



//
// compare
//
template <class real>
bool vector4<real>::operator== (const vector4& v) const
{
	real diff_x = x - v.x;
	real diff_y = y - v.y;
	real diff_z = z - v.z;
	real diff_w = w - v.w;

	return	(diff_x <= gmMath<real>::s_zero_tolerance ) &&
		(diff_y <= gmMath<real>::s_zero_tolerance) &&
		(diff_z <= gmMath<real>::s_zero_tolerance) &&
		(diff_w <= gmMath<real>::s_zero_tolerance);
}

template <class real>
bool vector4<real>::operator!= (const vector4& v) const
{
	real diff_x = x - v.x;
	real diff_y = y - v.y;
	real diff_z = z - v.z;
	real diff_w = w - v.w;

	return	(diff_x > gmMath<real>::s_zero_tolerance) ||
		(diff_y > gmMath<real>::s_zero_tolerance) ||
		(diff_z > gmMath<real>::s_zero_tolerance) ||
		(diff_w > gmMath<real>::s_zero_tolerance);
}


//
// arithmetic
//
template <class real>
vector4<real> vector4<real>::operator+ (const vector4& v) const
{
	return vector4(
		x + v.x,
		y + v.y,
		z + v.z,
		w + v.w);
}

template <class real>
vector4<real> vector4<real>::operator- (const vector4& v) const
{
	return vector4(
		x - v.x,
		y - v.y,
		z - v.z,
		w - v.w);
}

template <class real>
vector4<real> vector4<real>::operator* (real scalar) const
{
	return vector4(
		scalar * x,
		scalar * y,
		scalar * z,
		scalar * w);
}

template <class real>
vector4<real> vector4<real>::operator/ (real scalar) const
{
	vector4 quot;

	if ( scalar != (real)0.0 )
	{
		real inv_scalar = ((real)1.0)/scalar;
		quot.x = inv_scalar * x;
		quot.y = inv_scalar * y;
		quot.z = inv_scalar * z;
		quot.w = inv_scalar * w;
	}
	else
	{
		quot.x = gmMath<real>::s_max_real;
		quot.y = gmMath<real>::s_max_real;
		quot.z = gmMath<real>::s_max_real;
		quot.w = gmMath<real>::s_max_real;
	}

	return quot;
}

template <class real>
vector4<real> vector4<real>::operator- () const
{
	return vector4(
		-x,
		-y,
		-z,
		-w);
}

template <class real>
vector4<real> operator* (real scalar, const vector4<real>& v)
{
	return vector4<real>(
		scalar * v[0],
		scalar * v[1],
		scalar * v[2],
		scalar * v[3]);
}

template <class real>
vector4<real>& vector4<real>::operator+= (const vector4& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	w += v.w;
	return *this;
}

template <class real>
vector4<real>& vector4<real>::operator-= (const vector4& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	w -= v.w;
	return *this;
}

template <class real>
vector4<real>& vector4<real>::operator*= (real scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
	return *this;
}

template <class real>
vector4<real>& vector4<real>::operator/= (real scalar)
{
	if ( scalar != (real)0.0 )
	{
		real inv_scalar = ((real)1.0)/scalar;
		x *= inv_scalar;
		y *= inv_scalar;
		z *= inv_scalar;
		w *= inv_scalar;
	}
	else
	{
		x = gmMath<real>::s_max_real;
		y = gmMath<real>::s_max_real;
		z = gmMath<real>::s_max_real;
		w = gmMath<real>::s_max_real;
	}

	return *this;
}

template <class real>
real vector4<real>::length () const
{
	return gmMath<real>::sqrt_(
		x * x +
		y * y +
		z * z +
		w * w);
}
//----------------------------------------------------------------------------
template <class real>
real vector4<real>::squared_length () const
{
	return
		x * x +
		y * y +
		z * z +
		w * w;
}
//----------------------------------------------------------------------------
template <class real>
real vector4<real>::dot (const vector4& v) const
{
	return
		x * x +
		y * y +
		z * z +
		w * w;
}
//----------------------------------------------------------------------------
template <class real>
real vector4<real>::normalize ()
{
	real length_val = length();

	if ( length_val > gmMath<real>::s_zero_tolerance )
	{
		real inv_length = ((real)1.0)/length_val;
		x *= inv_length;
		y *= inv_length;
		z *= inv_length;
		w *= inv_length;
	}
	else
	{
		length_val = (real)0.0;
		x = (real)0.0;
		y = (real)0.0;
		z = (real)0.0;
		w = (real)0.0;
	}

	return length_val;
}

