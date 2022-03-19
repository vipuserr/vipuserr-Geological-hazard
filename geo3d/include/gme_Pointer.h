#pragma once

#include "gmeDef.h"
#include "s3dGMdlDBEngineExp.h"

 template<class T>
class  s3d_Pointer
{
public:
    typedef T element_type;

    s3d_Pointer() : _ptr(0) {}
    s3d_Pointer(T* ptr) : _ptr(ptr) { if (_ptr) _ptr->Ref(); }
    s3d_Pointer(const s3d_Pointer& rp) : _ptr(rp._ptr) { if (_ptr) _ptr->Ref(); }
    template<class Other> s3d_Pointer(const s3d_Pointer<Other>& rp) : _ptr(rp._ptr) { if (_ptr) _ptr->Ref(); }
    ~s3d_Pointer() { if (_ptr) _ptr->Unref();  _ptr = 0; }

    s3d_Pointer& operator = (const s3d_Pointer& rp)
    {
        assign(rp);
        return *this;
    }

    template<class Other> s3d_Pointer& operator = (const s3d_Pointer<Other>& rp)
    {
        assign(rp);
        return *this;
    }

    inline s3d_Pointer& operator = (T* ptr)
    {
        if (_ptr == ptr) return *this;
        T* tmp_ptr = _ptr;
        _ptr = ptr;
        if (_ptr) _ptr->Ref();

        if (tmp_ptr) tmp_ptr->Unref();
        return *this;
    }

    operator T*() const { return _ptr; }

    bool operator == (const s3d_Pointer& rp) const { return (_ptr == rp._ptr); }
    bool operator == (const T* ptr) const { return (_ptr == ptr); }

    bool operator != (const s3d_Pointer& rp) const { return (_ptr != rp._ptr); }
    bool operator != (const T* ptr) const { return (_ptr != ptr); }

    bool operator < (const s3d_Pointer& rp) const { return (_ptr < rp._ptr); }

private:
    typedef T* s3d_Pointer::*unspecified_bool_type;

public:
    operator unspecified_bool_type() const { return valid() ? &s3d_Pointer::_ptr : 0; }

    T& operator*() const { return *_ptr; }
    T* operator->() const { return _ptr; }
    T* get() const { return _ptr; }

    bool operator!() const { return _ptr == 0; } // not required
    bool valid() const { return _ptr != 0; }

    T* release() { T* tmp = _ptr; if (_ptr) _ptr->Unref_nodelete(); _ptr = 0; return tmp; }

    void swap(s3d_Pointer& rp) { T* tmp = _ptr; _ptr = rp._ptr; rp._ptr = tmp; }

private:
    template<class Other> void assign(const s3d_Pointer<Other>& rp)
    {
        if (_ptr == rp._ptr) return;
        T* tmp_ptr = _ptr;
        _ptr = rp._ptr;
        if (_ptr) _ptr->Ref();
        if (tmp_ptr) tmp_ptr->Unref();
    }

    template<class Other> friend class s3d_Pointer;

    T* _ptr;
};

template<class T>
class OG_GME_API s3d_AdaptPointer
{
public:
    s3d_AdaptPointer(void* p)
    {
        _ptr = (T*)(p);
    }

    s3d_AdaptPointer(T* p)
    {
        _ptr = p;
    }
    ~s3d_AdaptPointer(){_ptr = nullptr;}
    void destroy()
    {
        if(_ptr)
        {
            delete _ptr;
            _ptr = NULL;
        }
    }

    T* get(){return _ptr;}
    T& operator*() const { return *_ptr; }
    T* operator->() const { return _ptr; }

    bool operator!() const { return _ptr == 0; } // not required

    bool isNull()
    {
        return _ptr == 0;
    }

    bool valid()
    {
        return !isNull();
    }

private:
    T*  _ptr;
};