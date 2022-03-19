#pragma once
#include <osg/Vec3d>
#include <s3d_Math.h>
#include "gme_vector2.h"
#include "gme_vector3.h"
#include "gme_vector4.h"

namespace Smart3dMap{

class Matrixf;
class Matrixd;

class LIB_GMKERMATH_EXP Quat
{

public:
    typedef double value_type;
    value_type     _v[4];

    inline Quat() { _v[0]=0.0; _v[1]=0.0; _v[2]=0.0; _v[3]=1.0; }
    inline Quat( value_type x, value_type y, value_type z, value_type w )
    {
        _v[0]=x;
        _v[1]=y;
        _v[2]=z;
        _v[3]=w;
    }

    inline Quat( const gme_vector4f& v )
    {
        _v[0]=v.x;
        _v[1]=v.y;
        _v[2]=v.z;
        _v[3]=v.w;
    }

    inline Quat( const gme_vector4d& v )
    {
        _v[0]=v.x;
        _v[1]=v.y;
        _v[2]=v.z;
        _v[3]=v.w;
    }

    inline Quat( value_type angle, const gme_vector3f& axis)
    {
        makeRotate(angle,axis);
    }
    inline Quat( value_type angle, const gme_vector3d& axis)
    {
        makeRotate(angle,axis);
    }

    inline Quat( value_type angle1, const gme_vector3f& axis1,
                 value_type angle2, const gme_vector3f& axis2,
                 value_type angle3, const gme_vector3f& axis3)
    {
        makeRotate(angle1,axis1,angle2,axis2,angle3,axis3);
    }

    inline Quat( value_type angle1, const gme_vector3d& axis1,
                 value_type angle2, const gme_vector3d& axis2,
                 value_type angle3, const gme_vector3d& axis3)
    {
        makeRotate(angle1,axis1,angle2,axis2,angle3,axis3);
    }

    inline Quat& operator = (const Quat& v) { _v[0]=v._v[0];  _v[1]=v._v[1]; _v[2]=v._v[2]; _v[3]=v._v[3]; return *this; }
    inline bool operator == (const Quat& v) const { return _v[0]==v._v[0] && _v[1]==v._v[1] && _v[2]==v._v[2] && _v[3]==v._v[3]; }
    inline bool operator != (const Quat& v) const { return _v[0]!=v._v[0] || _v[1]!=v._v[1] || _v[2]!=v._v[2] || _v[3]!=v._v[3]; }
    inline bool operator <  (const Quat& v) const
    {
        if (_v[0]<v._v[0]) return true;
        else if (_v[0]>v._v[0]) return false;
        else if (_v[1]<v._v[1]) return true;
        else if (_v[1]>v._v[1]) return false;
        else if (_v[2]<v._v[2]) return true;
        else if (_v[2]>v._v[2]) return false;
        else return (_v[3]<v._v[3]);
    }
    inline gme_vector4d asVec4() const
    {
        return gme_vector4d(_v[0], _v[1], _v[2], _v[3]);
    }
    inline gme_vector3d asVec3() const
    {
        return gme_vector3d(_v[0], _v[1], _v[2]);
    }
    inline void set(value_type x, value_type y, value_type z, value_type w)
    {
        _v[0]=x;
        _v[1]=y;
        _v[2]=z;
        _v[3]=w;
    }
    inline void set(const gme_vector4f& v)
    {
        _v[0]=v.x;
        _v[1]=v.y;
        _v[2]=v.z;
        _v[3]=v.w;
    }
    inline void set(const gme_vector4d& v)
    {
        _v[0]=v.x;
        _v[1]=v.y;
        _v[2]=v.z;
        _v[3]=v.w;
    }
    void set(const Matrixf& matrix);
    void set(const Matrixd& matrix);
    void get(Matrixf& matrix) const;
    void get(Matrixd& matrix) const;
    inline value_type & operator [] (int i) { return _v[i]; }
    inline value_type   operator [] (int i) const { return _v[i]; }

    inline value_type & x() { return _v[0]; }
    inline value_type & y() { return _v[1]; }
    inline value_type & z() { return _v[2]; }
    inline value_type & w() { return _v[3]; }

    inline value_type x() const { return _v[0]; }
    inline value_type y() const { return _v[1]; }
    inline value_type z() const { return _v[2]; }
    inline value_type w() const { return _v[3]; }

    /** return true if the Quat represents a zero rotation, and therefore can be ignored in computations.*/
    bool zeroRotation() const { return _v[0]==0.0 && _v[1]==0.0 && _v[2]==0.0 && _v[3]==1.0; }

    inline const Quat operator * (value_type rhs) const
    {
        return Quat(_v[0]*rhs, _v[1]*rhs, _v[2]*rhs, _v[3]*rhs);
    }

    inline Quat& operator *= (value_type rhs)
    {
        _v[0]*=rhs;
        _v[1]*=rhs;
        _v[2]*=rhs;
        _v[3]*=rhs;
        return *this;        // enable nesting
    }
    /// Binary multiply
    inline const Quat operator*(const Quat& rhs) const
    {
        return Quat( rhs._v[3]*_v[0] + rhs._v[0]*_v[3] + rhs._v[1]*_v[2] - rhs._v[2]*_v[1],
                rhs._v[3]*_v[1] - rhs._v[0]*_v[2] + rhs._v[1]*_v[3] + rhs._v[2]*_v[0],
                rhs._v[3]*_v[2] + rhs._v[0]*_v[1] - rhs._v[1]*_v[0] + rhs._v[2]*_v[3],
                rhs._v[3]*_v[3] - rhs._v[0]*_v[0] - rhs._v[1]*_v[1] - rhs._v[2]*_v[2] );
    }

    /// Unary multiply
    inline Quat& operator*=(const Quat& rhs)
    {
        value_type x = rhs._v[3]*_v[0] + rhs._v[0]*_v[3] + rhs._v[1]*_v[2] - rhs._v[2]*_v[1];
        value_type y = rhs._v[3]*_v[1] - rhs._v[0]*_v[2] + rhs._v[1]*_v[3] + rhs._v[2]*_v[0];
        value_type z = rhs._v[3]*_v[2] + rhs._v[0]*_v[1] - rhs._v[1]*_v[0] + rhs._v[2]*_v[3];
        _v[3]   = rhs._v[3]*_v[3] - rhs._v[0]*_v[0] - rhs._v[1]*_v[1] - rhs._v[2]*_v[2];

        _v[2] = z;
        _v[1] = y;
        _v[0] = x;

        return (*this);            // enable nesting
    }

    /// Divide by scalar
    inline Quat operator / (value_type rhs) const
    {
        value_type div = 1.0/rhs;
        return Quat(_v[0]*div, _v[1]*div, _v[2]*div, _v[3]*div);
    }

    /// Unary divide by scalar
    inline Quat& operator /= (value_type rhs)
    {
        value_type div = 1.0/rhs;
        _v[0]*=div;
        _v[1]*=div;
        _v[2]*=div;
        _v[3]*=div;
        return *this;
    }

    /// Binary divide
    inline const Quat operator/(const Quat& denom) const
    {
        return ( (*this) * denom.inverse() );
    }

    /// Unary divide
    inline Quat& operator/=(const Quat& denom)
    {
        (*this) = (*this) * denom.inverse();
        return (*this);            // enable nesting
    }

    /// Binary addition
    inline const Quat operator + (const Quat& rhs) const
    {
        return Quat(_v[0]+rhs._v[0], _v[1]+rhs._v[1],
                _v[2]+rhs._v[2], _v[3]+rhs._v[3]);
    }

    /// Unary addition
    inline Quat& operator += (const Quat& rhs)
    {
        _v[0] += rhs._v[0];
        _v[1] += rhs._v[1];
        _v[2] += rhs._v[2];
        _v[3] += rhs._v[3];
        return *this;            // enable nesting
    }

    /// Binary subtraction
    inline const Quat operator - (const Quat& rhs) const
    {
        return Quat(_v[0]-rhs._v[0], _v[1]-rhs._v[1],
                _v[2]-rhs._v[2], _v[3]-rhs._v[3] );
    }

    /// Unary subtraction
    inline Quat& operator -= (const Quat& rhs)
    {
        _v[0]-=rhs._v[0];
        _v[1]-=rhs._v[1];
        _v[2]-=rhs._v[2];
        _v[3]-=rhs._v[3];
        return *this;            // enable nesting
    }

    inline const Quat operator - () const
    {
        return Quat (-_v[0], -_v[1], -_v[2], -_v[3]);
    }

    value_type length() const
    {
        return sqrt( _v[0]*_v[0] + _v[1]*_v[1] + _v[2]*_v[2] + _v[3]*_v[3]);
    }

    value_type length2() const
    {
        return _v[0]*_v[0] + _v[1]*_v[1] + _v[2]*_v[2] + _v[3]*_v[3];
    }

    /// Conjugate
    inline Quat conj () const
    {
        return Quat( -_v[0], -_v[1], -_v[2], _v[3] );
    }

    /// Multiplicative inverse method: q^(-1) = q^*/(q.q^*)
    inline const Quat inverse () const
    {
        return conj() / length2();
    }

    void makeRotate( value_type  angle,
                     value_type  x, value_type  y, value_type  z );
    void makeRotate ( value_type  angle, const gme_vector3f& vec );
    void makeRotate ( value_type  angle, const gme_vector3d& vec );

    void makeRotate ( value_type  angle1, const gme_vector3f& axis1,
                      value_type  angle2, const gme_vector3f& axis2,
                      value_type  angle3, const gme_vector3f& axis3);
    void makeRotate ( value_type  angle1, const gme_vector3d& axis1,
                      value_type  angle2, const gme_vector3d& axis2,
                      value_type  angle3, const gme_vector3d& axis3);

    /** Make a rotation Quat which will rotate vec1 to vec2.
            Generally take a dot product to get the angle between these
            and then use a cross product to get the rotation axis
            Watch out for the two special cases when the vectors
            are co-incident or opposite in direction.*/
    void makeRotate( const gme_vector3f& vec1, const gme_vector3f& vec2 );
    /** Make a rotation Quat which will rotate vec1 to vec2.
            Generally take a dot product to get the angle between these
            and then use a cross product to get the rotation axis
            Watch out for the two special cases of when the vectors
            are co-incident or opposite in direction.*/
    void makeRotate( const gme_vector3d& vec1, const gme_vector3d& vec2 );

    void makeRotate_original( const gme_vector3d& vec1, const gme_vector3d& vec2 );

    /** Return the angle and vector components represented by the quaternion.*/
    void getRotate ( value_type & angle, value_type & x, value_type & y, value_type & z ) const;

    /** Return the angle and vector represented by the quaternion.*/
    void getRotate ( value_type & angle, gme_vector3f& vec ) const;

    /** Return the angle and vector represented by the quaternion.*/
    void getRotate ( value_type & angle, gme_vector3d& vec ) const;

    /** Spherical Linear Interpolation.
        As t goes from 0 to 1, the Quat object goes from "from" to "to". */
    void slerp   ( value_type  t, const Quat& from, const Quat& to);

    /** Rotate a vector by this quaternion.*/
    gme_vector3f operator* (const gme_vector3f& v) const
    {
        // nVidia SDK implementation
        gme_vector3f uv, uuv;
        gme_vector3f qvec(_v[0], _v[1], _v[2]);
        uv = qvec.cross(v);
        uuv = qvec.cross(uv);
        uv *= ( 2.0f * _v[3] );
        uuv *= 2.0f;
        return v + uv + uuv;
    }

    /** Rotate a vector by this quaternion.*/
    gme_vector3d operator* (const gme_vector3d& v) const
    {
        // nVidia SDK implementation
        gme_vector3d uv, uuv;
        gme_vector3d qvec(_v[0], _v[1], _v[2]);
		uv = qvec.cross(v);
		uuv = qvec.cross(uv);
		uv *= ( 2.0f * _v[3] );
        uuv *= 2.0f;
        return v + uv + uuv;
    }
};
} 
