
#include "gme_math.h"

template<class real>
vector3<real>::vector3(void)
{
	x = real(0);
	y = real(0);
	z = real(0);
}

template<class real>
vector3<real>::~vector3(void)
{
}


template<class real>
vector3<real>::vector3(real v_x, real v_y, real v_z)
{
	x = v_x;
	y = v_y;
	z = v_z;
}

template<class real>
vector3<real>::vector3(float* p)
{
	x = p[0];
	y = p[1];
	z = p[2];
}

template<class real>
vector3<real>::vector3(double* p)
{
	x = p[0];
	y = p[1];
	z = p[2];
}


template<class real>
vector3<real>::vector3(const vector3& t)
{
	x = real(t.x);
	y = real(t.y);
	z = real(t.z);
}

// Assigns the value of the other vector.or param
template<class real>
vector3<real>& vector3<real>::operator = (const vector3& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;

	return *this;
}

template<class real>
bool vector3<real>::operator == (const vector3& vec) const
{
	return !(*this != vec);
}

template<class real>
bool vector3<real>::operator != (const vector3& vec) const
{
	return (gmMath<real>::fabs_(x - vec.x) > gmMath<real>::s_zero_tolerance ||
		gmMath<real>::fabs_(y - vec.y) > gmMath<real>::s_zero_tolerance ||
		gmMath<real>::fabs_(z - vec.z) > gmMath<real>::s_zero_tolerance);
}

template<class real>
vector3<real> vector3<real>::operator + (const vector3& vec) const
{
	vector3 v_vec(x + vec.x, y + vec.y, z + vec.z);
	return v_vec;
}

template<class real>
vector3<real> vector3<real>::operator - (const vector3& vec) const
{
	vector3 v_vec(x - vec.x, y - vec.y, z - vec.z);
	return v_vec;
}

template<class real>
vector3<real> vector3<real>::operator - () const
{
	vector3 v_ret(-x, -y, -z);
	return v_ret;
}

template<class real>
vector3<real> vector3<real>::operator * (real scale_value) const
{
	vector3 v_vec(x * scale_value, y * scale_value, z * scale_value);
	return v_vec;
}


template<class real>
vector3<real> vector3<real>::operator * (vector3& vec) const
{
	vector3 v_vec(vec.x * x, vec.y * y, vec.z * z);
	return v_vec;
}

template<class real>
vector3<real> vector3<real>::operator / (vector3& vec) const
{
	//assert( vec.x != real(0) );
	//assert( vec.y != real(0) );
	//assert( vec.z != real(0) );

	vector3 v_vec(x / vec.x, y / vec.y, z / vec.z);

	return v_vec;
}

template<class real>
vector3<real> vector3<real>::operator / (real scale_value) const
{
	//assert( scale_value != real(0) );

	real r = real(1.0) / scale_value;
	vector3 v_vec(x * r, y * r, z * r);
	return v_vec;
}

template<class real>
vector3<real>& vector3<real>::operator += (const vector3& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}

template<class real>
vector3<real>& vector3<real>::operator -= (const vector3& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}

template<class real>
vector3<real>& vector3<real>::operator *= (const real scale_value)
{
	x *= scale_value;
	y *= scale_value;
	z *= scale_value;
	return *this;
}

template<class real>
vector3<real>& vector3<real>::operator *= (const vector3& vec)
{
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
	return *this;
}

template<class real>
vector3<real>& vector3<real>::operator /= (const real scale_value)
{
	//assert( scale_value != real(0) );

	real r = real(1.0) / scale_value;
	x *= r;
	y *= r;
	z *= r;
	return *this;
}

template<class real>
void vector3<real>::scale(const real scale_value)
{
	x *= scale_value;
	y *= scale_value;
	z *= scale_value;
}

template<class real>
double vector3<real>::length(void) const
{
	return sqrt(x * x + y * y + z * z);
}

template<class real>
double vector3<real>::squared_length(void)
{
	return double(x * x + y * y + z * z);
}

template<class real>
void vector3<real>::normalize(void)
{
	double v_length = length();
	if (v_length > gmMath<real>::s_epsilon)
	{
		real r = real(1.0) / v_length;
		x *= r;
		y *= r;
		z *= r;
	}
}

template<class real>
vector3<real> vector3<real>::normalisedCopy(void)
{
	vector3 v_ret = *this;
	v_ret.normalize();
	return v_ret;
}

template<class real>
real vector3<real>::dot(const vector3& vec) const
{
	return vec.x * x + vec.y * y + vec.z * z;
}

template<class real>
real vector3<real>::dot(const vector3& vec1, const vector3& vec2)
{
	return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

template<class real>
vector3<real> vector3<real>::cross(const vector3& vec) const
{
	return vector3(y * vec.z - z * vec.y,
		z * vec.x - x * vec.z,
		x * vec.y - y * vec.x);
}

template<class real>
vector3<real> vector3<real>::cross(const vector3& vec1, const vector3& vec2)
{
	return vector3(vec1.y * vec2.z - vec1.z * vec2.y,
		vec1.z * vec2.x - vec1.x * vec2.z,
		vec1.x * vec2.y - vec1.y * vec2.x);
}

template<class real>
vector3<real> vector3<real>::normalize(const vector3& vec)
{
	vector3 v_ret = vec;
	v_ret.normalize();
	return v_ret;
}

template<class real>
real vector3<real>::length(const vector3& vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

// Calculates a reflection vector to the plane with the given normal .
// and remarks NB assumes 'this' is pointing AWAY FROM the plane, invert if it is not
template<class real>
vector3<real> vector3<real>::reflect(const vector3& src, const vector3& normal)
{
	return vector3(src - (2 * vector3::dot(src, normal) * normal));
}
