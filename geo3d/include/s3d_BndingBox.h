#pragma once

#include <osg/Vec3d>
#include <s3d_Math.h>
#include "gme_vector2.h"
#include "gme_vector3.h"
#include "gme_vector4.h"
namespace Smart3dMap{

template<typename VT>
class BoundingSphereImpl;

template<typename VT>
class BoundingBoxImpl
{
    public:
        typedef VT vec_type;
        //typedef typename VT::value_type value_type;
		typedef typename double value_type;

        vec_type _min;
        vec_type _max;

        inline BoundingBoxImpl() :
            _min(FLT_MAX,
                 FLT_MAX,
                 FLT_MAX),
            _max(-FLT_MAX,
                 -FLT_MAX,
                 -FLT_MAX)
        {}

        template<typename BT>
        inline BoundingBoxImpl(const BoundingBoxImpl<BT>& bb) :
            _min(bb._min),
            _max(bb._max)
        {}

        /** Creates a bounding box initialized to the given extents. */
        inline BoundingBoxImpl(value_type xmin, value_type ymin, value_type zmin,
                           value_type xmax, value_type ymax, value_type zmax) :
                           _min(xmin,ymin,zmin),
                           _max(xmax,ymax,zmax) {}

        /** Creates a bounding box initialized to the given extents. */
        inline BoundingBoxImpl(const vec_type& min,const vec_type& max) :
                    _min(min),
                    _max(max) {}

        /** Clear the bounding box. Erases existing minimum and maximum extents. */
        inline void init()
        {
            _min.set(FLT_MAX,
                     FLT_MAX,
                     FLT_MAX);
            _max.set(-FLT_MAX,
                     -FLT_MAX,
                     -FLT_MAX);
        }

        inline bool operator == (const BoundingBoxImpl& rhs) const { return _min==rhs._min && _max==rhs._max; }
        inline bool operator != (const BoundingBoxImpl& rhs) const { return _min!=rhs._min || _max!=rhs._max; }

        /** Returns true if the bounding box extents are valid, false otherwise. */
        inline bool valid() const
        {
            return _max.x>=_min.x &&  _max.y>=_min.y &&  _max.z>=_min.z;
        }

        /** Sets the bounding box extents. */
        inline void set (value_type xmin, value_type ymin, value_type zmin,
                         value_type xmax, value_type ymax, value_type zmax)
        {
            _min.set(xmin,ymin,zmin);
            _max.set(xmax,ymax,zmax);
        }

        /** Sets the bounding box extents. */
        inline void set(const vec_type& min,const vec_type& max)
        {
            _min = min;
            _max = max;
        }
        inline value_type& xMin() { return _min.x; }
        inline value_type xMin() const { return _min.x; }

        inline value_type& yMin() { return _min.y; }
        inline value_type yMin() const { return _min.y; }

        inline value_type& zMin() { return _min.z; }
        inline value_type zMin() const { return _min.z; }

        inline value_type& xMax() { return _max.x; }
        inline value_type xMax() const { return _max.x; }

        inline value_type& yMax() { return _max.y; }
        inline value_type yMax() const { return _max.y; }

        inline value_type& zMax() { return _max.z; }
        inline value_type zMax() const { return _max.z; }

		inline const vec_type center() const
        {
            return (_min+_max)*0.5;
        }
        inline value_type radius() const
        {
            return sqrt(radius2());
        }

        inline value_type radius2() const
        {
            return 0.25*((_max-_min).length2());
        }

        inline const vec_type corner(unsigned int pos) const
        {
            return vec_type(pos&1?_max.x:_min.x,pos&2?_max.y:_min.y,pos&4?_max.z:_min.z);
        }
        inline void expandBy(const vec_type& v)
        {
            if(v.x<_min.x) _min.x = v.x;
            if(v.x>_max.x) _max.x = v.x;

            if(v.y<_min.y) _min.y = v.y;
            if(v.y>_max.y) _max.y = v.y;

            if(v.z<_min.z) _min.z = v.z;
            if(v.z>_max.z) _max.z = v.z;
        }
        inline void expandBy(value_type x,value_type y,value_type z)
        {
            if(x<_min.x) _min.x = x;
            if(x>_max.x) _max.x = x;

            if(y<_min.y) _min.y = y;
            if(y>_max.y) _max.y = y;

            if(z<_min.z) _min.z = z;
            if(z>_max.z) _max.z = z;
        }
        void expandBy(const BoundingBoxImpl& bb)
        {
            if (!bb.valid()) return;

            if(bb._min.x<_min.x) _min.x = bb._min.x;
            if(bb._max.x>_max.x) _max.x = bb._max.x;

            if(bb._min.y<_min.y) _min.y = bb._min.y;
            if(bb._max.y>_max.y) _max.y = bb._max.y;

            if(bb._min.z<_min.z) _min.z = bb._min.z;
            if(bb._max.z>_max.z) _max.z = bb._max.z;
        }
        template<typename BST>
        void expandBy(const BoundingSphereImpl<BST>& sh)
        {
            if (!sh.valid()) return;

            if(sh._center.x-sh._radius<_min.x) _min.x = sh._center.x-sh._radius;
            if(sh._center.x+sh._radius>_max.x) _max.x = sh._center.x+sh._radius;

            if(sh._center.y-sh._radius<_min.y) _min.y = sh._center.y-sh._radius;
            if(sh._center.y+sh._radius>_max.y) _max.y = sh._center.y+sh._radius;

            if(sh._center.z-sh._radius<_min.z) _min.z = sh._center.z-sh._radius;
            if(sh._center.z+sh._radius>_max.z) _max.z = sh._center.z+sh._radius;
        }
        BoundingBoxImpl intersect(const BoundingBoxImpl& bb) const
        {    return BoundingBoxImpl(maximum(xMin(),bb.xMin()),maximum(yMin(),bb.yMin()),maximum(zMin(),bb.zMin()),
                                     minimum(xMax(),bb.xMax()),minimum(yMax(),bb.yMax()),minimum(zMax(),bb.zMax()));

        }
        bool intersects(const BoundingBoxImpl& bb) const
        {    return maximum(xMin(),bb.xMin()) <= minimum(xMax(),bb.xMax()) &&
                    maximum(yMin(),bb.yMin()) <= minimum(yMax(),bb.yMax()) &&
                    maximum(zMin(),bb.zMin()) <= minimum(zMax(),bb.zMax());

        }
        inline bool contains(const vec_type& v) const
        {
            return valid() &&
                   (v.x>=_min.x && v.x<=_max.x) &&
                   (v.y>=_min.y && v.y<=_max.y) &&
                   (v.z>=_min.z && v.z<=_max.z);
        }

        inline bool contains(const vec_type& v, value_type epsilon) const
        {
            return valid() &&
                   ((v.x+epsilon)>=_min.x && (v.x-epsilon)<=_max.x) &&
                   ((v.y+epsilon)>=_min.y && (v.y-epsilon)<=_max.y) &&
                   ((v.z+epsilon)>=_min.z && (v.z-epsilon)<=_max.z);
        }
};

typedef BoundingBoxImpl<gme_vector3d> BoundingBoxd;

typedef BoundingBoxd BoundingBox;

typedef struct Extend
{
    double xMin;
    double xMax;
    double yMin;
    double yMax;
    double zMin;
    double zMax;
    double wMin;
    double wMax;

    //面积计算
    inline double Area()
    {
        return (xMax- xMin) * (yMax - yMin);
    }

    //体积计算
    inline double Volume()
    {
        return (xMax- xMin) * (yMax - yMin) * (zMax - zMin);
    }

    Extend()
    {
        xMin = 0;
        xMax = 0;
        yMin = 0;
        yMax = 0;
        zMin = 0;
        zMax = 0;
        wMin = 0;
        wMax = 0;
    }

}Extend;
}
