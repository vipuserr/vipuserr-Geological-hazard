#pragma once

#include <osg/Vec3d>
#include <s3d_Math.h>
#include "gme_vector2.h"
#include "gme_vector3.h"
#include "gme_vector4.h"
#include <s3d_Quat.h>
namespace Smart3dMap
{
class LIB_GMKERMATH_EXP Matrixf
{
public:
    typedef float value_type;
    typedef double other_value_type;

    inline Matrixf() { makeIdentity(); }
    inline Matrixf(const Matrixf& mat) { set(mat.ptr()); }
    Matrixf(const Matrixd& mat);
    inline explicit Matrixf(float const * const ptr) { set(ptr); }
    inline explicit Matrixf(double const * const ptr) { set(ptr); }
    inline explicit Matrixf(const Quat& quat) { makeRotate(quat); }

    Matrixf(value_type a00, value_type a01, value_type a02, value_type a03,
            value_type a10, value_type a11, value_type a12, value_type a13,
            value_type a20, value_type a21, value_type a22, value_type a23,
            value_type a30, value_type a31, value_type a32, value_type a33);

    ~Matrixf() {}

    int compare(const Matrixf& m) const;

    bool operator < (const Matrixf& m) const { return compare(m) < 0; }
    bool operator == (const Matrixf& m) const { return compare(m) == 0; }
    bool operator != (const Matrixf& m) const { return compare(m) != 0; }

    inline value_type& operator()(int row, int col) { return _mat[row][col]; }
    inline value_type operator()(int row, int col) const { return _mat[row][col]; }

    inline bool valid() const { return !isNaN(); }
    inline bool isNaN() const {
        return Smart3dMap::isNaN(_mat[0][0]) || Smart3dMap::isNaN(_mat[0][1]) || Smart3dMap::isNaN(_mat[0][2]) || Smart3dMap::isNaN(_mat[0][3]) ||
                Smart3dMap::isNaN(_mat[1][0]) || Smart3dMap::isNaN(_mat[1][1]) || Smart3dMap::isNaN(_mat[1][2]) || Smart3dMap::isNaN(_mat[1][3]) ||
                Smart3dMap::isNaN(_mat[2][0]) || Smart3dMap::isNaN(_mat[2][1]) || Smart3dMap::isNaN(_mat[2][2]) || Smart3dMap::isNaN(_mat[2][3]) ||
                Smart3dMap::isNaN(_mat[3][0]) || Smart3dMap::isNaN(_mat[3][1]) || Smart3dMap::isNaN(_mat[3][2]) || Smart3dMap::isNaN(_mat[3][3]);
    }

    inline Matrixf& operator = (const Matrixf& rhs)
    {
        if (&rhs == this) return *this;
        set(rhs.ptr());
        return *this;
    }

    Matrixf& operator = (const Matrixd& other);

    inline void set(const Matrixf& rhs) { set(rhs.ptr()); }

    void set(const Matrixd& rhs);

    inline void set(float const * const ptr)
    {
        value_type* local_ptr = (value_type*)_mat;
        for (int i = 0; i < 16; ++i) local_ptr[i] = (value_type)ptr[i];
    }

    inline void set(double const * const ptr)
    {
        value_type* local_ptr = (value_type*)_mat;
        for (int i = 0; i < 16; ++i) local_ptr[i] = (value_type)ptr[i];
    }

    void set(value_type a00, value_type a01, value_type a02, value_type a03,
             value_type a10, value_type a11, value_type a12, value_type a13,
             value_type a20, value_type a21, value_type a22, value_type a23,
             value_type a30, value_type a31, value_type a32, value_type a33);

    value_type * ptr() { return (value_type*)_mat; }
    const value_type * ptr() const { return (const value_type *)_mat; }

    bool isIdentity() const
    {
        return _mat[0][0] == 1.0f && _mat[0][1] == 0.0f && _mat[0][2] == 0.0f &&  _mat[0][3] == 0.0f &&
                _mat[1][0] == 0.0f && _mat[1][1] == 1.0f && _mat[1][2] == 0.0f &&  _mat[1][3] == 0.0f &&
                _mat[2][0] == 0.0f && _mat[2][1] == 0.0f && _mat[2][2] == 1.0f &&  _mat[2][3] == 0.0f &&
                _mat[3][0] == 0.0f && _mat[3][1] == 0.0f && _mat[3][2] == 0.0f &&  _mat[3][3] == 1.0f;
    }

    void makeIdentity();

    void makeScale(const gme_vector3f&);
    void makeScale(const gme_vector3d&);
    void makeScale(value_type, value_type, value_type);

    void makeTranslate(const gme_vector3f&);
    void makeTranslate(const gme_vector3d&);
    void makeTranslate(value_type, value_type, value_type);

    void makeRotate(const gme_vector3f& from, const gme_vector3f& to);
    void makeRotate(const gme_vector3d& from, const gme_vector3d& to);
    void makeRotate(value_type angle, const gme_vector3f& axis);
    void makeRotate(value_type angle, const gme_vector3d& axis);
    void makeRotate(value_type angle, value_type x, value_type y, value_type z);
    void makeRotate(const Quat&);
    void makeRotate(value_type angle1, const gme_vector3f& axis1,
                    value_type angle2, const gme_vector3f& axis2,
                    value_type angle3, const gme_vector3f& axis3);
    void makeRotate(value_type angle1, const gme_vector3d& axis1,
                    value_type angle2, const gme_vector3d& axis2,
                    value_type angle3, const gme_vector3d& axis3);


    /** decompose the matrix into translation, rotation, scale and scale orientation.*/
    void decompose(gme_vector3f& translation,
                   Smart3dMap::Quat& rotation,
		gme_vector3f& scale,
                   Smart3dMap::Quat& so) const;

    /** decompose the matrix into translation, rotation, scale and scale orientation.*/
    void decompose(gme_vector3d& translation,
                   Smart3dMap::Quat& rotation,
		gme_vector3d& scale,
                   Smart3dMap::Quat& so) const;


    /** set to an orthographic projection.
                * See glOrtho for further details.
                */
    void makeOrtho(double left, double right,
                   double bottom, double top,
                   double zNear, double zFar);

    /** Get the orthographic settings of the orthographic projection matrix.
                * Note, if matrix is not an orthographic matrix then invalid values
                * will be returned.
                */
    bool getOrtho(double& left, double& right,
                  double& bottom, double& top,
                  double& zNear, double& zFar) const;

    /** float version of getOrtho(..) */
    bool getOrtho(float& left, float& right,
                  float& bottom, float& top,
                  float& zNear, float& zFar) const;


    /** Set to a 2D orthographic projection.
                * See glOrtho2D for further details.
                */
    inline void makeOrtho2D(double left, double right,
                            double bottom, double top)
    {
        makeOrtho(left, right, bottom, top, -1.0, 1.0);
    }


    /** Set to a perspective projection.
                * See glFrustum for further details.
                */
    void makeFrustum(double left, double right,
                     double bottom, double top,
                     double zNear, double zFar);

    /** Get the frustum settings of a perspective projection matrix.
                * Note, if matrix is not a perspective matrix then invalid values
                * will be returned.
                */
    bool getFrustum(double& left, double& right,
                    double& bottom, double& top,
                    double& zNear, double& zFar) const;

    /** float version of getFrustum(..) */
    bool getFrustum(float& left, float& right,
                    float& bottom, float& top,
                    float& zNear, float& zFar) const;

    /** Set to a symmetrical perspective projection.
                * See gluPerspective for further details.
                * Aspect ratio is defined as width/height.
                */
    void makePerspective(double fovy, double aspectRatio,
                         double zNear, double zFar);

    bool getPerspective(double& fovy, double& aspectRatio,
                        double& zNear, double& zFar) const;

    /** float version of getPerspective(..) */
    bool getPerspective(float& fovy, float& aspectRatio,
                        float& zNear, float& zFar) const;

    /** Set the position and orientation to be a view matrix,
                * using the same convention as gluLookAt.
                */
    void makeLookAt(const gme_vector3d& eye, const gme_vector3d& center, const gme_vector3d& up);

    /** Get to the position and orientation of a modelview matrix,
                * using the same convention as gluLookAt.
                */
    void getLookAt(gme_vector3f& eye, gme_vector3f& center, gme_vector3f& up,
                   value_type lookDistance = 1.0f) const;

    /** Get to the position and orientation of a modelview matrix,
                * using the same convention as gluLookAt.
                */
    void getLookAt(gme_vector3d& eye, gme_vector3d& center, gme_vector3d& up,
                   value_type lookDistance = 1.0f) const;

    /** invert the matrix rhs, automatically select invert_4x3 or invert_4x4. */
    inline bool invert(const Matrixf& rhs)
    {
        bool is_4x3 = (rhs._mat[0][3] == 0.0f && rhs._mat[1][3] == 0.0f &&  rhs._mat[2][3] == 0.0f && rhs._mat[3][3] == 1.0f);
        return is_4x3 ? invert_4x3(rhs) : invert_4x4(rhs);
    }

    /** 4x3 matrix invert, not right hand column is assumed to be 0,0,0,1. */
    bool invert_4x3(const Matrixf& rhs);

    /** full 4x4 matrix invert. */
    bool invert_4x4(const Matrixf& rhs);

    /** ortho-normalize the 3x3 rotation & scale matrix */
    void orthoNormalize(const Matrixf& rhs);

    //basic utility functions to create new matrices
    inline static Matrixf identity(void);
    inline static Matrixf scale(const gme_vector3f& sv);
    inline static Matrixf scale(const gme_vector3d& sv);
    inline static Matrixf scale(value_type sx, value_type sy, value_type sz);
    inline static Matrixf translate(const gme_vector3f& dv);
    inline static Matrixf translate(const gme_vector3d& dv);
    inline static Matrixf translate(value_type x, value_type y, value_type z);
    inline static Matrixf rotate(const gme_vector3f& from, const gme_vector3f& to);
    inline static Matrixf rotate(const gme_vector3d& from, const gme_vector3d& to);
    inline static Matrixf rotate(value_type angle, value_type x, value_type y, value_type z);
    inline static Matrixf rotate(value_type angle, const gme_vector3f& axis);
    inline static Matrixf rotate(value_type angle, const gme_vector3d& axis);
    inline static Matrixf rotate(value_type angle1, const gme_vector3f& axis1,
                                 value_type angle2, const gme_vector3f& axis2,
                                 value_type angle3, const gme_vector3f& axis3);
    inline static Matrixf rotate(value_type angle1, const gme_vector3d& axis1,
                                 value_type angle2, const gme_vector3d& axis2,
                                 value_type angle3, const gme_vector3d& axis3);
    inline static Matrixf rotate(const Quat& quat);
    inline static Matrixf inverse(const Matrixf& matrix);
    inline static Matrixf orthoNormal(const Matrixf& matrix);

    /** Create an orthographic projection matrix.
                * See glOrtho for further details.
                */
    inline static Matrixf ortho(double left, double right,
                                double bottom, double top,
                                double zNear, double zFar);

    /** Create a 2D orthographic projection.
                * See glOrtho for further details.
                */
    inline static Matrixf ortho2D(double left, double right,
                                  double bottom, double top);

    /** Create a perspective projection.
                * See glFrustum for further details.
                */
    inline static Matrixf frustum(double left, double right,
                                  double bottom, double top,
                                  double zNear, double zFar);

    /** Create a symmetrical perspective projection.
                * See gluPerspective for further details.
                * Aspect ratio is defined as width/height.
                */
    inline static Matrixf perspective(double fovy, double aspectRatio,
                                      double zNear, double zFar);

    /** Create the position and orientation as per a camera,
                * using the same convention as gluLookAt.
                */
    inline static Matrixf lookAt(const gme_vector3f& eye,
                                 const gme_vector3f& center,
                                 const gme_vector3f& up);

    /** Create the position and orientation as per a camera,
                * using the same convention as gluLookAt.
                */
    inline static Matrixf lookAt(const gme_vector3d& eye,
                                 const gme_vector3d& center,
                                 const gme_vector3d& up);

    inline gme_vector3f preMult(const gme_vector3f& v) const;
    inline gme_vector3d preMult(const gme_vector3d& v) const;
    inline gme_vector3f postMult(const gme_vector3f& v) const;
    inline gme_vector3d postMult(const gme_vector3d& v) const;
    inline gme_vector3f operator* (const gme_vector3f& v) const;
    inline gme_vector3d operator* (const gme_vector3d& v) const;
    inline gme_vector4f preMult(const gme_vector4f& v) const;
    inline gme_vector4d preMult(const gme_vector4d& v) const;
    inline gme_vector4f postMult(const gme_vector4f& v) const;
    inline gme_vector4d postMult(const gme_vector4d& v) const;
    inline gme_vector4f operator* (const gme_vector4f& v) const;
    inline gme_vector4d operator* (const gme_vector4d& v) const;

#ifdef USE_DEPRECATED_API
    inline void set(const Quat& q) { makeRotate(q); }
    inline void get(Quat& q) const { q = getRotate(); }
#endif

    void setRotate(const Quat& q);
    /** Get the matrix rotation as a Quat. Note that this function
                * assumes a non-scaled matrix and will return incorrect results
                * for scaled matrixces. Consider decompose() instead.
                */
    Quat getRotate() const;


    void setTrans(value_type tx, value_type ty, value_type tz);
    void setTrans(const gme_vector3f& v);
    void setTrans(const gme_vector3d& v);

    inline gme_vector3d getTrans() const { return gme_vector3d(_mat[3][0], _mat[3][1], _mat[3][2]); }

    inline gme_vector3d getScale() const {
        gme_vector3d x_vec(_mat[0][0], _mat[1][0], _mat[2][0]);
        gme_vector3d y_vec(_mat[0][1], _mat[1][1], _mat[2][1]);
        gme_vector3d z_vec(_mat[0][2], _mat[1][2], _mat[2][2]);
        return gme_vector3d(x_vec.length(), y_vec.length(), z_vec.length());
    }

    /** apply a 3x3 transform of v*M[0..2,0..2]. */
    inline static gme_vector3f transform3x3(const gme_vector3f& v, const Matrixf& m);

    /** apply a 3x3 transform of v*M[0..2,0..2]. */
    inline static gme_vector3d transform3x3(const gme_vector3d& v, const Matrixf& m);

    /** apply a 3x3 transform of M[0..2,0..2]*v. */
    inline static gme_vector3f transform3x3(const Matrixf& m, const gme_vector3f& v);

    /** apply a 3x3 transform of M[0..2,0..2]*v. */
    inline static gme_vector3d transform3x3(const Matrixf& m, const gme_vector3d& v);

    // basic Matrixf multiplication, our workhorse methods.
    void mult(const Matrixf&, const Matrixf&);
    void preMult(const Matrixf&);
    void postMult(const Matrixf&);

    /** Optimized version of preMult(translate(v)); */
    inline void preMultTranslate(const gme_vector3d& v);
    inline void preMultTranslate(const gme_vector3f& v);
    /** Optimized version of postMult(translate(v)); */
    inline void postMultTranslate(const gme_vector3d& v);
    inline void postMultTranslate(const gme_vector3f& v);

    /** Optimized version of preMult(scale(v)); */
    inline void preMultScale(const gme_vector3d& v);
    inline void preMultScale(const gme_vector3f& v);
    /** Optimized version of postMult(scale(v)); */
    inline void postMultScale(const gme_vector3d& v);
    inline void postMultScale(const gme_vector3f& v);

    /** Optimized version of preMult(rotate(q)); */
    inline void preMultRotate(const Quat& q);
    /** Optimized version of postMult(rotate(q)); */
    inline void postMultRotate(const Quat& q);

    inline void operator *= (const Matrixf& other)
    {
        if (this == &other) {
            Matrixf temp(other);
            postMult(temp);
        }
        else postMult(other);
    }

    inline Matrixf operator * (const Matrixf &m) const
    {
        Smart3dMap::Matrixf r;
        r.mult(*this, m);
        return  r;
    }

    /** Multiply by scalar. */
    inline Matrixf operator * (value_type rhs) const
    {
        return Matrixf(
                    _mat[0][0] * rhs, _mat[0][1] * rhs, _mat[0][2] * rhs, _mat[0][3] * rhs,
                _mat[1][0] * rhs, _mat[1][1] * rhs, _mat[1][2] * rhs, _mat[1][3] * rhs,
                _mat[2][0] * rhs, _mat[2][1] * rhs, _mat[2][2] * rhs, _mat[2][3] * rhs,
                _mat[3][0] * rhs, _mat[3][1] * rhs, _mat[3][2] * rhs, _mat[3][3] * rhs);
    }

    /** Unary multiply by scalar. */
    inline Matrixf& operator *= (value_type rhs)
    {
        _mat[0][0] *= rhs;
        _mat[0][1] *= rhs;
        _mat[0][2] *= rhs;
        _mat[0][3] *= rhs;
        _mat[1][0] *= rhs;
        _mat[1][1] *= rhs;
        _mat[1][2] *= rhs;
        _mat[1][3] *= rhs;
        _mat[2][0] *= rhs;
        _mat[2][1] *= rhs;
        _mat[2][2] *= rhs;
        _mat[2][3] *= rhs;
        _mat[3][0] *= rhs;
        _mat[3][1] *= rhs;
        _mat[3][2] *= rhs;
        _mat[3][3] *= rhs;
        return *this;
    }

    /** Divide by scalar. */
    inline Matrixf operator / (value_type rhs) const
    {
        return Matrixf(
                    _mat[0][0] / rhs, _mat[0][1] / rhs, _mat[0][2] / rhs, _mat[0][3] / rhs,
                _mat[1][0] / rhs, _mat[1][1] / rhs, _mat[1][2] / rhs, _mat[1][3] / rhs,
                _mat[2][0] / rhs, _mat[2][1] / rhs, _mat[2][2] / rhs, _mat[2][3] / rhs,
                _mat[3][0] / rhs, _mat[3][1] / rhs, _mat[3][2] / rhs, _mat[3][3] / rhs);
    }

    /** Unary divide by scalar. */
    inline Matrixf& operator /= (value_type rhs)
    {
        _mat[0][0] /= rhs;
        _mat[0][1] /= rhs;
        _mat[0][2] /= rhs;
        _mat[0][3] /= rhs;
        _mat[1][0] /= rhs;
        _mat[1][1] /= rhs;
        _mat[1][2] /= rhs;
        _mat[1][3] /= rhs;
        _mat[2][0] /= rhs;
        _mat[2][1] /= rhs;
        _mat[2][2] /= rhs;
        _mat[2][3] /= rhs;
        _mat[3][0] /= rhs;
        _mat[3][1] /= rhs;
        _mat[3][2] /= rhs;
        _mat[3][3] /= rhs;
        return *this;
    }

    /** Binary vector add. */
    inline Matrixf operator + (const Matrixf& rhs) const
    {
        return Matrixf(
                    _mat[0][0] + rhs._mat[0][0],
                _mat[0][1] + rhs._mat[0][1],
                _mat[0][2] + rhs._mat[0][2],
                _mat[0][3] + rhs._mat[0][3],
                _mat[1][0] + rhs._mat[1][0],
                _mat[1][1] + rhs._mat[1][1],
                _mat[1][2] + rhs._mat[1][2],
                _mat[1][3] + rhs._mat[1][3],
                _mat[2][0] + rhs._mat[2][0],
                _mat[2][1] + rhs._mat[2][1],
                _mat[2][2] + rhs._mat[2][2],
                _mat[2][3] + rhs._mat[2][3],
                _mat[3][0] + rhs._mat[3][0],
                _mat[3][1] + rhs._mat[3][1],
                _mat[3][2] + rhs._mat[3][2],
                _mat[3][3] + rhs._mat[3][3]);
    }

    /** Unary vector add. Slightly more efficient because no temporary
                * intermediate object.
                */
    inline Matrixf& operator += (const Matrixf& rhs)
    {
        _mat[0][0] += rhs._mat[0][0];
        _mat[0][1] += rhs._mat[0][1];
        _mat[0][2] += rhs._mat[0][2];
        _mat[0][3] += rhs._mat[0][3];
        _mat[1][0] += rhs._mat[1][0];
        _mat[1][1] += rhs._mat[1][1];
        _mat[1][2] += rhs._mat[1][2];
        _mat[1][3] += rhs._mat[1][3];
        _mat[2][0] += rhs._mat[2][0];
        _mat[2][1] += rhs._mat[2][1];
        _mat[2][2] += rhs._mat[2][2];
        _mat[2][3] += rhs._mat[2][3];
        _mat[3][0] += rhs._mat[3][0];
        _mat[3][1] += rhs._mat[3][1];
        _mat[3][2] += rhs._mat[3][2];
        _mat[3][3] += rhs._mat[3][3];
        return *this;
    }

protected:
    value_type _mat[4][4];

};

inline gme_vector3f operator* (const gme_vector3f& v, const Matrixf& m)
{
    return m.preMult(v);
}
inline gme_vector3d operator* (const gme_vector3d& v, const Matrixf& m)
{
    return m.preMult(v);
}
inline gme_vector4f operator* (const gme_vector4f& v, const Matrixf& m)
{
    return m.preMult(v);
}
inline gme_vector4d operator* (const gme_vector4d& v, const Matrixf& m)
{
    return m.preMult(v);
}

inline gme_vector3f Matrixf::operator* (const gme_vector3f& v) const
{
    return postMult(v);
}
inline gme_vector3d Matrixf::operator* (const gme_vector3d& v) const
{
    return postMult(v);
}
inline gme_vector4f Matrixf::operator* (const gme_vector4f& v) const
{
    return postMult(v);
}
inline gme_vector4d Matrixf::operator* (const gme_vector4d& v) const
{
    return postMult(v);
}

class LIB_GMKERMATH_EXP Matrixd
{
public:

    typedef double value_type;
    typedef float other_value_type;

    inline Matrixd() { makeIdentity(); }
    inline Matrixd(const Matrixd& mat) { set(mat.ptr()); }
    Matrixd(const Matrixf& mat);
    inline explicit Matrixd(float const * const ptr) { set(ptr); }
    inline explicit Matrixd(double const * const ptr) { set(ptr); }
    inline explicit Matrixd(const Quat& quat) { makeRotate(quat); }

    Matrixd(value_type a00, value_type a01, value_type a02, value_type a03,
            value_type a10, value_type a11, value_type a12, value_type a13,
            value_type a20, value_type a21, value_type a22, value_type a23,
            value_type a30, value_type a31, value_type a32, value_type a33);

    ~Matrixd() {}

    int compare(const Matrixd& m) const;

    bool operator < (const Matrixd& m) const { return compare(m) < 0; }
    bool operator == (const Matrixd& m) const { return compare(m) == 0; }
    bool operator != (const Matrixd& m) const { return compare(m) != 0; }

    inline value_type& operator()(int row, int col) { return _mat[row][col]; }
    inline value_type operator()(int row, int col) const { return _mat[row][col]; }

    inline bool valid() const { return !isNaN(); }
    inline bool isNaN() const {
        return Smart3dMap::isNaN(_mat[0][0]) || Smart3dMap::isNaN(_mat[0][1]) || Smart3dMap::isNaN(_mat[0][2]) || Smart3dMap::isNaN(_mat[0][3]) ||
                Smart3dMap::isNaN(_mat[1][0]) || Smart3dMap::isNaN(_mat[1][1]) || Smart3dMap::isNaN(_mat[1][2]) || Smart3dMap::isNaN(_mat[1][3]) ||
                Smart3dMap::isNaN(_mat[2][0]) || Smart3dMap::isNaN(_mat[2][1]) || Smart3dMap::isNaN(_mat[2][2]) || Smart3dMap::isNaN(_mat[2][3]) ||
                Smart3dMap::isNaN(_mat[3][0]) || Smart3dMap::isNaN(_mat[3][1]) || Smart3dMap::isNaN(_mat[3][2]) || Smart3dMap::isNaN(_mat[3][3]);
    }

    inline Matrixd& operator = (const Matrixd& rhs)
    {
        if (&rhs == this) return *this;
        set(rhs.ptr());
        return *this;
    }

    Matrixd& operator = (const Matrixf& other);

    inline void set(const Matrixd& rhs) { set(rhs.ptr()); }

    void set(const Matrixf& rhs);

    inline void set(float const * const ptr)
    {
        value_type* local_ptr = (value_type*)_mat;
        for (int i = 0; i < 16; ++i) local_ptr[i] = (value_type)ptr[i];
    }

    inline void set(double const * const ptr)
    {
        value_type* local_ptr = (value_type*)_mat;
        for (int i = 0; i < 16; ++i) local_ptr[i] = (value_type)ptr[i];
    }

    void set(value_type a00, value_type a01, value_type a02, value_type a03,
             value_type a10, value_type a11, value_type a12, value_type a13,
             value_type a20, value_type a21, value_type a22, value_type a23,
             value_type a30, value_type a31, value_type a32, value_type a33);

    value_type * ptr() { return (value_type*)_mat; }
    const value_type * ptr() const { return (const value_type *)_mat; }

    bool isIdentity() const
    {
        return _mat[0][0] == 1.0 && _mat[0][1] == 0.0 && _mat[0][2] == 0.0 &&  _mat[0][3] == 0.0 &&
                _mat[1][0] == 0.0 && _mat[1][1] == 1.0 && _mat[1][2] == 0.0 &&  _mat[1][3] == 0.0 &&
                _mat[2][0] == 0.0 && _mat[2][1] == 0.0 && _mat[2][2] == 1.0 &&  _mat[2][3] == 0.0 &&
                _mat[3][0] == 0.0 && _mat[3][1] == 0.0 && _mat[3][2] == 0.0 &&  _mat[3][3] == 1.0;
    }

    void makeIdentity();

    void makeScale(const gme_vector3f&);
    void makeScale(const gme_vector3d&);
    void makeScale(value_type, value_type, value_type);

    void makeTranslate(const gme_vector3f&);
    void makeTranslate(const gme_vector3d&);
    void makeTranslate(value_type, value_type, value_type);

    void makeRotate(const gme_vector3f& from, const gme_vector3f& to);
    void makeRotate(const gme_vector3d& from, const gme_vector3d& to);
    void makeRotate(value_type angle, const gme_vector3f& axis);
    void makeRotate(value_type angle, const gme_vector3d& axis);
    void makeRotate(value_type angle, value_type x, value_type y, value_type z);
    void makeRotate(const Quat&);
    void makeRotate(value_type angle1, const gme_vector3f& axis1,
                    value_type angle2, const gme_vector3f& axis2,
                    value_type angle3, const gme_vector3f& axis3);
    void makeRotate(value_type angle1, const gme_vector3d& axis1,
                    value_type angle2, const gme_vector3d& axis2,
                    value_type angle3, const gme_vector3d& axis3);


    /** decompose the matrix into translation, rotation, scale and scale orientation.*/
    void decompose(gme_vector3f& translation,
                   Smart3dMap::Quat& rotation,
		gme_vector3f& scale,
                   Smart3dMap::Quat& so) const;

    /** decompose the matrix into translation, rotation, scale and scale orientation.*/
    void decompose(gme_vector3d& translation,
                   Smart3dMap::Quat& rotation,
		gme_vector3d& scale,
                   Smart3dMap::Quat& so) const;


    /** Set to an orthographic projection.
                 * See glOrtho for further details.
                */
    void makeOrtho(double left, double right,
                   double bottom, double top,
                   double zNear, double zFar);

    /** Get the orthographic settings of the orthographic projection matrix.
                  * Note, if matrix is not an orthographic matrix then invalid values
                  * will be returned.
                */
    bool getOrtho(double& left, double& right,
                  double& bottom, double& top,
                  double& zNear, double& zFar) const;

    /** float version of getOrtho(..) */
    bool getOrtho(float& left, float& right,
                  float& bottom, float& top,
                  float& zNear, float& zFar) const;


    /** Set to a 2D orthographic projection.
                  * See glOrtho2D for further details.
                */
    inline void makeOrtho2D(double left, double right,
                            double bottom, double top)
    {
        makeOrtho(left, right, bottom, top, -1.0, 1.0);
    }


    /** Set to a perspective projection.
                  * See glFrustum for further details.
                */
    void makeFrustum(double left, double right,
                     double bottom, double top,
                     double zNear, double zFar);

    /** Get the frustum settings of a perspective projection matrix.
                  * Note, if matrix is not a perspective matrix then invalid values
                  * will be returned.
                */
    bool getFrustum(double& left, double& right,
                    double& bottom, double& top,
                    double& zNear, double& zFar) const;

    /** float version of getFrustum(..) */
    bool getFrustum(float& left, float& right,
                    float& bottom, float& top,
                    float& zNear, float& zFar) const;

    /** Set to a symmetrical perspective projection.
                  * See gluPerspective for further details.
                  * Aspect ratio is defined as width/height.
                */
    void makePerspective(double fovy, double aspectRatio,
                         double zNear, double zFar);

    /** Get the frustum settings of a symmetric perspective projection
                  * matrix.
                  * Return false if matrix is not a perspective matrix,
                  * where parameter values are undefined.
                  * Note, if matrix is not a symmetric perspective matrix then the
                  * shear will be lost.
                  * Asymmetric matrices occur when stereo, power walls, caves and
                  * reality center display are used.
                  * In these configuration one should use the AsFrustum method instead.
                */
    bool getPerspective(double& fovy, double& aspectRatio,
                        double& zNear, double& zFar) const;

    /** float version of getPerspective(..) */
    bool getPerspective(float& fovy, float& aspectRatio,
                        float& zNear, float& zFar) const;

    /** Set the position and orientation to be a view matrix,
                  * using the same convention as gluLookAt.
                */
    void makeLookAt(const gme_vector3d& eye, const gme_vector3d& center, const gme_vector3d& up);

    /** Get to the position and orientation of a modelview matrix,
                  * using the same convention as gluLookAt.
                */
    void getLookAt(gme_vector3f& eye, gme_vector3f& center, gme_vector3f& up,
                   value_type lookDistance = 1.0f) const;

    /** Get to the position and orientation of a modelview matrix,
                  * using the same convention as gluLookAt.
                */
    void getLookAt(gme_vector3d& eye, gme_vector3d& center, gme_vector3d& up,
                   value_type lookDistance = 1.0f) const;

    /** invert the matrix rhs, automatically select invert_4x3 or invert_4x4. */
    inline bool invert(const Matrixd& rhs)
    {
        bool is_4x3 = (rhs._mat[0][3] == 0.0 && rhs._mat[1][3] == 0.0 &&  rhs._mat[2][3] == 0.0 && rhs._mat[3][3] == 1.0);
        return is_4x3 ? invert_4x3(rhs) : invert_4x4(rhs);
    }

    /** 4x3 matrix invert, not right hand column is assumed to be 0,0,0,1. */
    bool invert_4x3(const Matrixd& rhs);

    /** full 4x4 matrix invert. */
    bool invert_4x4(const Matrixd& rhs);

    /** ortho-normalize the 3x3 rotation & scale matrix */
    void orthoNormalize(const Matrixd& rhs);

    // basic utility functions to create new matrices
    inline static Matrixd identity(void);
    inline static Matrixd scale(const gme_vector3f& sv);
    inline static Matrixd scale(const gme_vector3d& sv);
    inline static Matrixd scale(value_type sx, value_type sy, value_type sz);
    inline static Matrixd translate(const gme_vector3f& dv);
    inline static Matrixd translate(const gme_vector3d& dv);
    inline static Matrixd translate(value_type x, value_type y, value_type z);
    inline static Matrixd rotate(const gme_vector3f& from, const gme_vector3f& to);
    inline static Matrixd rotate(const gme_vector3d& from, const gme_vector3d& to);
    inline static Matrixd rotate(value_type angle, value_type x, value_type y, value_type z);
    inline static Matrixd rotate(value_type angle, const gme_vector3f& axis);
    inline static Matrixd rotate(value_type angle, const gme_vector3d& axis);
    inline static Matrixd rotate(value_type angle1, const gme_vector3f& axis1,
                                 value_type angle2, const gme_vector3f& axis2,
                                 value_type angle3, const gme_vector3f& axis3);
    inline static Matrixd rotate(value_type angle1, const gme_vector3d& axis1,
                                 value_type angle2, const gme_vector3d& axis2,
                                 value_type angle3, const gme_vector3d& axis3);
    inline static Matrixd rotate(const Quat& quat);
    inline static Matrixd inverse(const Matrixd& matrix);
    inline static Matrixd orthoNormal(const Matrixd& matrix);
    /** Create an orthographic projection matrix.
                  * See glOrtho for further details.
                */
    inline static Matrixd ortho(double left, double right,
                                double bottom, double top,
                                double zNear, double zFar);

    /** Create a 2D orthographic projection.
                  * See glOrtho for further details.
                */
    inline static Matrixd ortho2D(double left, double right,
                                  double bottom, double top);

    /** Create a perspective projection.
                  * See glFrustum for further details.
                */
    inline static Matrixd frustum(double left, double right,
                                  double bottom, double top,
                                  double zNear, double zFar);

    /** Create a symmetrical perspective projection.
                  * See gluPerspective for further details.
                  * Aspect ratio is defined as width/height.
                */
    inline static Matrixd perspective(double fovy, double aspectRatio,
                                      double zNear, double zFar);

    /** Create the position and orientation as per a camera,
                  * using the same convention as gluLookAt.
                */
    inline static Matrixd lookAt(const gme_vector3f& eye,
                                 const gme_vector3f& center,
                                 const gme_vector3f& up);

    /** Create the position and orientation as per a camera,
                  * using the same convention as gluLookAt.
                */
    inline static Matrixd lookAt(const gme_vector3d& eye,
                                 const gme_vector3d& center,
                                 const gme_vector3d& up);

    inline gme_vector3f preMult(const gme_vector3f& v) const;
    inline gme_vector3d preMult(const gme_vector3d& v) const;
    inline gme_vector3f postMult(const gme_vector3f& v) const;
    inline gme_vector3d postMult(const gme_vector3d& v) const;
    inline gme_vector3f operator* (const gme_vector3f& v) const;
    inline gme_vector3d operator* (const gme_vector3d& v) const;
    inline gme_vector4f preMult(const gme_vector4f& v) const;
    inline gme_vector4d preMult(const gme_vector4d& v) const;
    inline gme_vector4f postMult(const gme_vector4f& v) const;
    inline gme_vector4d postMult(const gme_vector4d& v) const;
    inline gme_vector4f operator* (const gme_vector4f& v) const;
    inline gme_vector4d operator* (const gme_vector4d& v) const;

#ifdef USE_DEPRECATED_API
    inline void set(const Quat& q) { makeRotate(q); }
    inline void get(Quat& q) const { q = getRotate(); }
#endif

    void setRotate(const Quat& q);
    /** Get the matrix rotation as a Quat. Note that this function
                  * assumes a non-scaled matrix and will return incorrect results
                  * for scaled matrixces. Consider decompose() instead.
                  */
    Quat getRotate() const;

    void setTrans(value_type tx, value_type ty, value_type tz);
    void setTrans(const gme_vector3f& v);
    void setTrans(const gme_vector3d& v);

    inline gme_vector3d getTrans() const { return gme_vector3d(_mat[3][0], _mat[3][1], _mat[3][2]); }

    inline gme_vector3d getScale() const {
        gme_vector3d x_vec(_mat[0][0], _mat[1][0], _mat[2][0]);
        gme_vector3d y_vec(_mat[0][1], _mat[1][1], _mat[2][1]);
        gme_vector3d z_vec(_mat[0][2], _mat[1][2], _mat[2][2]);
        return gme_vector3d(x_vec.length(), y_vec.length(), z_vec.length());
    }

    /** apply a 3x3 transform of v*M[0..2,0..2]. */
    inline static gme_vector3f transform3x3(const gme_vector3f& v, const Matrixd& m);

    /** apply a 3x3 transform of v*M[0..2,0..2]. */
    inline static gme_vector3d transform3x3(const gme_vector3d& v, const Matrixd& m);

    /** apply a 3x3 transform of M[0..2,0..2]*v. */
    inline static gme_vector3f transform3x3(const Matrixd& m, const gme_vector3f& v);

    /** apply a 3x3 transform of M[0..2,0..2]*v. */
    inline static gme_vector3d transform3x3(const Matrixd& m, const gme_vector3d& v);

    // basic Matrixd multiplication, our workhorse methods.
    void mult(const Matrixd&, const Matrixd&);
    void preMult(const Matrixd&);
    void postMult(const Matrixd&);

    /** Optimized version of preMult(translate(v)); */
    inline void preMultTranslate(const gme_vector3d& v);
    inline void preMultTranslate(const gme_vector3f& v);
    /** Optimized version of postMult(translate(v)); */
    inline void postMultTranslate(const gme_vector3d& v);
    inline void postMultTranslate(const gme_vector3f& v);

    /** Optimized version of preMult(scale(v)); */
    inline void preMultScale(const gme_vector3d& v);
    inline void preMultScale(const gme_vector3f& v);
    /** Optimized version of postMult(scale(v)); */
    inline void postMultScale(const gme_vector3d& v);
    inline void postMultScale(const gme_vector3f& v);

    /** Optimized version of preMult(rotate(q)); */
    inline void preMultRotate(const Quat& q);
    /** Optimized version of postMult(rotate(q)); */
    inline void postMultRotate(const Quat& q);

    inline void operator *= (const Matrixd& other)
    {
        if (this == &other) {
            Matrixd temp(other);
            postMult(temp);
        }
        else postMult(other);
    }

    inline Matrixd operator * (const Matrixd &m) const
    {
        Smart3dMap::Matrixd r;
        r.mult(*this, m);
        return  r;
    }

protected:
    value_type _mat[4][4];

};


inline gme_vector3f operator* (const gme_vector3f& v, const Matrixd& m)
{
    return m.preMult(v);
}

inline gme_vector3d operator* (const gme_vector3d& v, const Matrixd& m)
{
    return m.preMult(v);
}

inline gme_vector4f operator* (const gme_vector4f& v, const Matrixd& m)
{
    return m.preMult(v);
}

inline gme_vector4d operator* (const gme_vector4d& v, const Matrixd& m)
{
    return m.preMult(v);
}

inline gme_vector3f Matrixd::operator* (const gme_vector3f& v) const
{
    return postMult(v);
}

inline gme_vector3d Matrixd::operator* (const gme_vector3d& v) const
{
    return postMult(v);
}

inline gme_vector4f Matrixd::operator* (const gme_vector4f& v) const
{
    return postMult(v);
}

inline gme_vector4d Matrixd::operator* (const gme_vector4d& v) const
{
    return postMult(v);
}
typedef Matrixf Matrix;
}
