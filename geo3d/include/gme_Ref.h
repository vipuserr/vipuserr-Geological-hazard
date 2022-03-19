#pragma once 

#include "gme_Pointer.h"

#define META_CLASSNAME(name) \
    virtual const char* className() const { return #name; }
using namespace std;

namespace Smart3dMap
{
class  OG_GME_API s3d_Ref
{
public:
    s3d_Ref() :m_refCount(0) {}
    s3d_Ref(const s3d_Ref&) :m_refCount(0) {}
    inline s3d_Ref& operator = (const s3d_Ref&) { return *this; }
    inline int Ref() const
    {
	return ++m_refCount;
    }
    inline int Unref() const
    {
	int newRef;
	bool needDelete = false;

	newRef = --m_refCount;
	needDelete = newRef==0;

	if (needDelete)
	{
	    delete this;
	}
	return newRef;
    }
    inline int Unref_nodelete() const
    {
	return --m_refCount;
    }
    inline int ReferenceCount() const { return m_refCount; }
protected:
    virtual ~s3d_Ref() {}
    mutable int  m_refCount;
};
}